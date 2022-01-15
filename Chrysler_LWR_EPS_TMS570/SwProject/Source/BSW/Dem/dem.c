/* -----------------------------------------------------------------------------
  Filename:     dem.c
  Description:  Implementation of FRFM Wrapper with DEM functions.
                
                Manufacturer: Chrysler
 ----------------------------------------------------------------------------- */

/* -----------------------------------------------------------------------------
    &&&~ Includes
 ----------------------------------------------------------------------------- */
#include "RTE_GlobalData.h"
#include "CDD_Data.h"
#include "fixmath.h"
/* Get the configuration and the Vector standard types */
#include "v_cfg.h"
#include "v_def.h"

/* Get the DEM specific definitions and types */
#include "dem.h"
#include "Nvm.h"
#include "frfm.h"

#include "CalConstants.h"
#include "Ap_DiagMgr.h"


VAR(t_FrfmNonVolatileData, AP_DEMIF_VAR) Dem_NvData;
/* -----------------------------------------------------------------------------
    &&&~ Preprocessor constants (defines)
 ----------------------------------------------------------------------------- */

#if defined (V_ENABLE_USE_DUMMY_STATEMENT)
# define DEM_IGNORE_UNREF_PARAM(paramName)                           (paramName = paramName)
#else
# define DEM_IGNORE_UNREF_PARAM(paramName)                           /* do nothing */
#endif


/* -----------------------------------------------------------------------------
    &&&~ Function prototypes
 ----------------------------------------------------------------------------- */
#if 0
static t_FrfmVoltage DemFrfm_GetVoltage(uint8 *Buffer);
#endif

/* EPS_Curr */
#define D_SUPPLYCURROFFSET_ULS_F32	(50.0F)
#define D_EPSCURR_HILMT_AMP_F32		(203.0F)
#define D_EPSCURR_LOLMT_AMP_F32		(-50.0F)

/* Steering Column Torque */
#define D_STRCLMTRQLOLIMIT_HWNM_F32			(-8.0F)
#define D_STRCLMTRQHILIMIT_HWNM_F32			(7.9765625F)
#define D_STRCLMTRQOFFSET_HWNM_F32			(8.0F)
#define D_STRCLMTRQ_SIGNOTAVAL_CNTS_U16		(0x07FFU)


#define 	D_TESTFAILEDBIT_CNT_B8							0x01U
#define 	D_TESTFAILEDTHISOPCYCLEBIT_CNT_B8				0x02U
#define 	D_CONFIRMEDDTCBIT_CNT_B8						0x08U

#define 	D_NTCACTIVEBITS_CNT_B8							(D_TESTFAILEDBIT_CNT_B8 | D_TESTFAILEDTHISOPCYCLEBIT_CNT_B8 | D_CONFIRMEDDTCBIT_CNT_B8)
VAR(uint8, AUTOMATIC) CDD_DemIdSnapshot_Cnt_G_u8;




/* -----------------------------------------------------------------------------
    &&&~ ROM definitions
 ----------------------------------------------------------------------------- */


/* -----------------------------------------------------------------------------
    &&&~ Implementation
 ----------------------------------------------------------------------------- */

/*******************************************************************************
* NAME:             Dem_SetEventStatus
*
* CALLED BY:        Application  
* PRECONDITIONS:     
* REENTRANCY:       No
* SERVICE ID:       0x04
*
* DESCRIPTION:      Service for reporting the Event Status to the DEM. This service shall be used to
*                   report an Event Status as soon a new test result is available.
*                   This Service stores the event to the Event Memory.
*******************************************************************************/
FUNC(Std_ReturnType, DEM_CODE)
Dem_SetEventStatus(
  Dem_EventIdType       EventId,
  Dem_EventStatusType   EventStatus
  )
{
  Std_ReturnType        result = E_OK;
  t_FrfmSetEventStatus  frfmEventStatus;

  switch (EventStatus)
  {
  case DEM_EVENT_STATUS_PASSED:
    frfmEventStatus = testPassed;
    break;
  case DEM_EVENT_STATUS_FAILED:
    frfmEventStatus = testFailed;
    break;
#if defined (FRFM_ENABLE_DTC_DEBOUNCING)
  case DEM_EVENT_STATUS_PREPASSED:
    frfmEventStatus = monitorPrePassed;
    break;
  case DEM_EVENT_STATUS_PREFAILED:
    frfmEventStatus = monitorPreFailed;
    break;
#endif
  default:
    result = E_NOT_OK;
    break;
  }
  if (E_OK == result)
  {
    FrfmSetEventStatus( (t_FrfmDtcSfnType) EventId, frfmEventStatus );
  }
  #if (DEM_DEV_ERROR_DETECT == STD_ON)
  else
  {
    Dem_DetReportError(DEM_SETEVENTSTATUS_APIID, DEM_E_PARAM_DATA);
  }
  #endif

  return result;
}

/*******************************************************************************
* NAME:             Dem_GetEventStatus
*
* CALLED BY:        Application  
* PRECONDITIONS:     
* REENTRANCY:       No
* SERVICE ID:       0x0a
*
* DESCRIPTION:      This API shall be used to read the event status from the DEM. This API
*                   is provided to be used by SW-Components or other basic software modules e.g.
*                   FIM.
*******************************************************************************/
FUNC(Std_ReturnType, DEM_CODE)
Dem_GetEventStatus(
  Dem_EventIdType                                               EventId,
  P2VAR(Dem_EventStatusExtendedType, AUTOMATIC, DEM_APPL_DATA)  EventStatusExtended
  )
{
  Std_ReturnType        result = E_OK;
  t_FrfmDtcStatusByte   frfmDtcStatusByte;

  if (EventId < kFrfmNumDtc)
  {
    /* further checks are done by assertions in FrfmGetEventStatus() */
    frfmDtcStatusByte.s = FrfmGetEventStatus ((t_FrfmDtcSfnType) EventId );
#if defined (FRFM_ENABLE_PREFAILED_STATUS)
    /* FRFM Bit2 (0x04 preFailed) is set to zero, Clear it and never report PreFailed bit */
    frfmDtcStatusByte.s.preFailed = 0;
#endif
    *EventStatusExtended = (Dem_EventStatusExtendedType) frfmDtcStatusByte.c;
  }
  else
  {
    result = E_NOT_OK;
  }

  #if (DEM_DEV_ERROR_DETECT == STD_ON)
  if (E_NOT_OK == result)
  {
	  Dem_DetReportError(DEM_GETEVENTSTATUS_APIID, DEM_E_PARAM_DATA);
  }
  #endif

  return result;
}

/*******************************************************************************
* NAME:              ApplFrfmOnDtcStatusChange
*
* CALLED BY:         FrfmClearDTC, FrfmTask, FrfmSetEventStatus, FrfmDebounceEventFailed, FrfmDebounceEventPassed
* PRECONDITIONS:     -
*
* DESCRIPTION:       FRFM notifies the Application about a DTC change. A change occurs when
*                    - DTC status is changed
*                    - A DTC is removed from the ChronoStack
*                    - A DTC is cleared by external request
*                    No notifications are given, if the whole ChronoStack is initialized.
*******************************************************************************/
void ApplFrfmOnDtcStatusChange( t_FrfmDtcNumType dtcNum, t_FrfmDtcStatusByte oldDtcStatus, t_FrfmDtcStatusByte newDtcStatus )
{
  Dem_EventIdType       EventId = (Dem_EventIdType) FrfmGetDtcSFN(dtcNum);

#if defined (FRFM_ENABLE_PREFAILED_STATUS)
    /* FRFM Bit2 (0x04 preFailed) is set to zero before assigning to DEM:pendingDTC */
    oldDtcStatus.s.preFailed = 0;
    newDtcStatus.s.preFailed = 0;
#endif
#if 0
  (void) Xxx_DemTriggerOnDTCStatus(
    (Dem_DTCType) dtcNum,
    DemCfg_GetDTCKind(EventId),
    (Dem_DTCStatusMaskType) oldDtcStatus.c,
    (Dem_DTCStatusMaskType) newDtcStatus.c );
#endif
}

/*******************************************************************************
* NAME:             Dem_SetEnableCondition
*
* CALLED BY:        Application
* PRECONDITIONS:     
* REENTRANCY:       No
* SERVICE ID:       0x39
*
* DESCRIPTION:      This API shall be used to set the enable condition. For each event an enable
*                   condition value is assigned to. An enable condition specifies a certain number of
*                   checks (e.g. correct voltage range) for an event before the event can be qualified as
*                   confirmed.
*******************************************************************************/
FUNC(Std_ReturnType, DEM_CODE)
Dem_SetEnableCondition(
  uint8     EnableConditionID,
  boolean   ConditionFulfilled
  )
{
  Std_ReturnType result   = E_OK;
  t_FrfmBool     newState = (t_FrfmBool) ((FALSE==ConditionFulfilled) ? frfmFalse : frfmTrue);

  switch (EnableConditionID)
  {
  case DEM_ID_EC1_DTC_SETTING_STATUS:
	  FrfmServiceSetStorageState( (t_FrfmStorageState)newState );
	 break;
  case DEM_ID_EC5_IOD_FUSE_STATUS:
    FrfmSetIodFuseEnableCond( newState );
    break;
  case DEM_ID_EC6_NWCONFIG_STATUS:
	  FrfmSetNwConfigEnableCond( newState );
    break;
  case DEM_ID_EC7_BUS_PHYSICAL_STATUS:
	  FrfmSetBusPhysicEnableCond( newState );
    break;
  case DEM_ID_EC8_IODEVICE_CONFIG:
    FrfmSetIODevConfEnableCond( newState );
    break;
  default:
    result = E_NOT_OK;
  }

  return result;
}

/*******************************************************************************
* NAME:              Dem_SetOperationCycleState
*
* CALLED BY:         Application
* PRECONDITIONS:     
* REENTRANCY:        No
* SERVICE ID:        0x08
*
* DESCRIPTION:       DEM shall be called by the SW- Component as soon as it detects the
*                    status change of the CycleState for the Operation Cycle.
*                    Note: The FRFM uses an additional delay for the ignition cycle to
*                    start, when the DEM_CYCLE_STATE_START is called!
*******************************************************************************/
FUNC(Std_ReturnType, DEM_CODE)
Dem_SetOperationCycleState(
  Dem_OperationCycleIdType      OperationCycleId,
  Dem_OperationCycleStateType   CycleState
  )
{
  Std_ReturnType result = E_OK;

  if ( (Dem_OperationCycleIdType)DEM_ID_OPCYC_IGNITIONCYCLE == OperationCycleId )
  {
    if ( (Dem_OperationCycleStateType)DEM_CYCLE_STATE_START == CycleState )
    {
      FrfmSetIgnitionStatus( ignitionRun );
    }
    else if ( (Dem_OperationCycleStateType)DEM_CYCLE_STATE_END == CycleState )
    {
      FrfmSetIgnitionStatus( ignitionOff );
    }
    else
    {
      result = E_NOT_OK;
    }
  }
  else
  {
    result = E_NOT_OK;
  }

  return result;
}
#if 0
/*******************************************************************************
* NAME:              DemFrfm_GetVoltage
*
* CALLED BY:         internal
* PRECONDITIONS:     
* REENTRANCY:        Yes
*
* DESCRIPTION:       Read uint16 value from uint8* buffer pointer
*******************************************************************************/
static t_FrfmVoltage DemFrfm_GetVoltage(uint8 *Buffer)
{
  /* We cannot simply cast uint8* to uint16* as the buffer might be aligned incorrectly */
  vuint16 result;
#ifdef C_CPUTYPE_LITTLEENDIAN
  result = (vuint16)(((vuint16)(Buffer[1])<<8) | ((vuint16)(Buffer[0])));
#else
  result = (vuint16)(((vuint16)(Buffer[0])<<8) | ((vuint16)(Buffer[1])));
#endif
  return (t_FrfmVoltage)result;
}
#endif

/*******************************************************************************
* NAME:              Dem_SetVoltageValue
*
* CALLED BY:         Application
* PRECONDITIONS:     
* REENTRANCY:        No
* SERVICE ID:        0x38
*
* DESCRIPTION:       This API shall be used to set directly the local and system
*                     voltages
*******************************************************************************/
FUNC(Std_ReturnType, DEM_CODE)
Dem_SetVoltageValue(
  uint8   VoltageID,
  uint16  VoltageValue
  )
{
  Std_ReturnType result = E_NOT_OK;

  switch (VoltageID)
  {
  case DEM_LOCALVOLTAGE:
      FrfmSetLocalVoltage (VoltageValue);
      result = E_OK;
    break;
  case DEM_SYSTEMVOLTAGE:
      FrfmSetSystemVoltage (VoltageValue );
      result = E_OK;
    break;
  default:
    /*result = E_NOT_OK;*/
    break;
  }

  return result;
}

#if 0 /* Can be used if needed*/
/*******************************************************************************
* NAME:              Dem_SetValueByOemId
*
* CALLED BY:         Application
* PRECONDITIONS:
* REENTRANCY:        No
* SERVICE ID:        0x38
*
* DESCRIPTION:       This API shall be used to set a data value assigned to a specific data identifier. The
*                    list of data identifiers is OEM specific and has to be fixed at configuration time. Only
*                    simple data types (uint8...uint32; sint8...sint32) are allowed. Structured data types
*                    (struct, array) are not allowed.
*******************************************************************************/
FUNC(Std_ReturnType, DEM_CODE)
Dem_SetValueByOemId(
  uint16                                  OemID,
  P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA)  DataValue,
  uint8                                   BufferLength
  )
{
  Std_ReturnType result = E_NOT_OK;

  switch (OemID)
  {
  case DEM_ID_OEM_LOCALVOLTAGE:
    if (2u == BufferLength)
    {
      /* Voltage is stored in uint16 variable, here transmitted by uint8 pointer */
      FrfmSetLocalVoltage ( DemFrfm_GetVoltage(DataValue) );
      result = E_OK;
    }
    break;
  case DEM_ID_OEM_SYSTEMVOLTAGE:
    if (2u == BufferLength)
    {
      /* Voltage is stored in uint16 variable, here transmitted by uint8 pointer */
      FrfmSetSystemVoltage ( DemFrfm_GetVoltage(DataValue) );
      result = E_OK;
    }
    break;
#if defined (FRFM_ENABLE_READINESS_GROUPS)
  case DEM_ID_OEM_RESET_READINESSGROUP:
    if (1u == BufferLength)
    {
      FrfmTestedThisOperationCycle(DataValue[0]);
      result = E_OK;
    }
    break;
#endif
  default:
    /*result = E_NOT_OK;*/
    break;
  }

  return result;
}
#endif

/*******************************************************************************
* NAME:              ApplFrfmGetAddEnvData
*
* CALLED BY:         FrfmSetEventStatus, FrfmDebounceEventFailed, FrfmDebounceEventPassed
* PRECONDITIONS:     -
*
* DESCRIPTION:       This function is called by the FRFM software module when additional data shall be stored with a
*                    fault record and needs therefore be implemented by the external application. This function shall
*                    copy the requested set of environmental data to the buffer defined by the
*                    chronoStackAddEnvData pointer.
*                    The supported sets of data have to be defined during system design and then implemented in this
*                    function. If an unsupported data set has been requested or the maximum size is too small for the
*                    requested set of environmental data the function shall return 'kFrfmFailed'.
*                    If the data has been copied successfully to the buffer, the function shall return 'kFrfmSuccess'.
*******************************************************************************/
vuint8          ApplFrfmGetAddEnvData(vuint16 recordNumber, vuint8* chronoStackAddEnvData, vuint8 envDataSize)
{
    vuint8          result  = kFrfmFailed;
    uint16     HwPos_HwDeg_T_u16;
   // sint16     HwTorque_HwNm_T_s11p4;
    int i;
	uint8 EPSCurr_Cnt_T_u08;
    float32 SupplyCurrent_Amp_T_f32;
    uint16 VehSpd_Kph_T_u16;
    uint16 Vecu_Volt_T_u16p0;
    boolean SrlComHwTrqVld_Cnt_T_lgc;
    uint16 StrClmTrq_Cnt_T_u16;
    float32 AnaHwTorque_HwNm_T_f32;
    sint16 FiltMeasTemp_DegC_T_s16;
    uint16 HwVel_HwRadpS_T_u16;
    uint16 NTCIndex_Cnt_T_u16;
	uint8 ParamData_Cnt_T_u8;
	uint8 Status_Cnt_T_u8;
	uint8 AgingCounter_Cnt_T_u8;
	uint16 NTCNum_Cnt_Ptr_u16;
	uint8 ParamData_Ptr_u8;
	//FiltMeasTemp_DegC_T_s16
    /* only one record is supported currently for all DTC's */
 //   if (envDataSize >= 11)
 //   {
		/* Below code is added to get NTC 3bytes of data - Incomplete */
    	for(NTCIndex_Cnt_T_u16 = 1;NTCIndex_Cnt_T_u16<TableSize_m(k_FltRspTbl_Cnt_str);NTCIndex_Cnt_T_u16++)
    	{
    		/* Corresponding CTCs */
    		if (CDD_DemIdSnapshot_Cnt_G_u8 == k_FltRspTbl_Cnt_str[NTCIndex_Cnt_T_u16].DEMEventID)
    		{
    			DiagMgr_SCom_GetNTCInfo( NTCIndex_Cnt_T_u16, &ParamData_Cnt_T_u8, &Status_Cnt_T_u8, &AgingCounter_Cnt_T_u8);
    			if ( D_NTCACTIVEBITS_CNT_B8 == (D_NTCACTIVEBITS_CNT_B8 & Status_Cnt_T_u8))
    			{
    				/* Update the value used in the Debug Frame with last NTC recorded to snapshot. SER 11C (3/Mar/13) still requires
    				 * the first NTC on the fault statck, instead giving them the last NTC recorded to snapshot. */
    			//	CDD_FirstActvNTC_Cnt_G_u16 = NTCIndex_Cnt_T_u16;

    				NTCNum_Cnt_Ptr_u16 = NTCIndex_Cnt_T_u16;
    				ParamData_Ptr_u8 = ParamData_Cnt_T_u8;
    				break; /*return */
    			}
    		}
    	 }

    	/*NTC Number & Param Value*/
    	chronoStackAddEnvData[1] = (uint8)(NTCNum_Cnt_Ptr_u16 & 0xFF);
    	chronoStackAddEnvData[0] = (uint8)((NTCNum_Cnt_Ptr_u16 >> 8) & 0xFF);
    	chronoStackAddEnvData[2] = ParamData_Ptr_u8;

    	/*Internal Filtered Vehicle Speed*/
    	VehSpd_Kph_T_u16 = FPM_FloatToFixed_m((Rte_SrlComInput_SrlComVehSpd_Kph_f32 / 0.0078125), u16p0_T);
    	chronoStackAddEnvData[4] = (uint8)(VehSpd_Kph_T_u16 & 0xFF); /* store MSB */
    	chronoStackAddEnvData[3] = (uint8)(VehSpd_Kph_T_u16 >> 8u);/* store LSB */

    	/*Internal Steering Wheel Angle */
    	HwPos_HwDeg_T_u16 =FPM_FloatToFixed_m(((Rte_Ap_AbsHwPosScom_HwPos_HwDeg_f32 + 1440.11f) / 0.04395f), u16p0_T);
    	chronoStackAddEnvData[6] = (HwPos_HwDeg_T_u16 & 0xFF) ;  /* store MSB */
       	chronoStackAddEnvData[5] = ((HwPos_HwDeg_T_u16 >> 8) & 0xFF) ; /* store LSB */

       	/*Internal Filtered Steering Rate*/
    	HwVel_HwRadpS_T_u16 = FPM_FloatToFixed_m(((Rte_MtrVel_SysCHandwheelVel_HwRadpS_f32 + 1440.11f) / 0.04395), u16p0_T);
    	chronoStackAddEnvData[8] = (HwVel_HwRadpS_T_u16 & 0xFF) ;  /* store MSB */
    	chronoStackAddEnvData[7] = ((HwVel_HwRadpS_T_u16 >> 8) & 0xFF) ; /* store LSB */


    	/*EPS System Current Draw*/
    	SupplyCurrent_Amp_T_f32 = Rte_Ap_ElePwr_SupplyCurrent_Amp_f32;
    	SupplyCurrent_Amp_T_f32 = Limit_m(SupplyCurrent_Amp_T_f32, D_EPSCURR_LOLMT_AMP_F32, D_EPSCURR_HILMT_AMP_F32);
    	SupplyCurrent_Amp_T_f32 = (SupplyCurrent_Amp_T_f32 + D_SUPPLYCURROFFSET_ULS_F32) * FLOATTOFIXED_s15p0_T;
    	EPSCurr_Cnt_T_u08 = FPM_FloatToFixed_m(SupplyCurrent_Amp_T_f32, u16p0_T);
    	chronoStackAddEnvData[9]= EPSCurr_Cnt_T_u08;


    	/*Measured Module Voltage*/
    	Vecu_Volt_T_u16p0 = FPM_FloatToFixed_m(((Rte_BatteryVoltage_Vecu_Volt_f32 - 5.0) / 0.004), u16p0_T);
    	chronoStackAddEnvData[11] = (Vecu_Volt_T_u16p0 & 0xFF) ;  /* store MSB */
    	chronoStackAddEnvData[10] = ((Vecu_Volt_T_u16p0 >> 8) & 0xFF) ; /* store LSB first */


    	/*Steering Wheel Torque*/
    	SrlComHwTrqVld_Cnt_T_lgc = Rte_HwTrq_SrlComHwTrqValid_Cnt_lgc;

    	if(SrlComHwTrqVld_Cnt_T_lgc == FALSE)
    	{
    		StrClmTrq_Cnt_T_u16 = D_STRCLMTRQ_SIGNOTAVAL_CNTS_U16;
    	}
    	else
    	{
    		AnaHwTorque_HwNm_T_f32 = Rte_HwTrq_AnaHwTorque_HwNm_f32;
    		AnaHwTorque_HwNm_T_f32 = (AnaHwTorque_HwNm_T_f32 * ((float32)k_StrClmTrqPolarity_Cnt_s08));

    		AnaHwTorque_HwNm_T_f32 = Limit_m(AnaHwTorque_HwNm_T_f32, D_STRCLMTRQLOLIMIT_HWNM_F32, D_STRCLMTRQHILIMIT_HWNM_F32);
    		AnaHwTorque_HwNm_T_f32 = (AnaHwTorque_HwNm_T_f32 + D_STRCLMTRQOFFSET_HWNM_F32) * FLOATTOFIXED_s8p7_T;
    		StrClmTrq_Cnt_T_u16 = (uint16)AnaHwTorque_HwNm_T_f32;
    	}

    	chronoStackAddEnvData[13] = (uint8)(StrClmTrq_Cnt_T_u16 & 0xFF) ;  /* store MSB */
    	chronoStackAddEnvData[12] = (uint8)((StrClmTrq_Cnt_T_u16 >> 8) & 0xFF) ; /* store LSB*/

    	/*Measured Module Temperature*/
    	FiltMeasTemp_DegC_T_s16 = FPM_FloatToFixed_m((Rte_CtrlTemp_FiltMeasTemp_DegC_f32 / 0.03125), s15p0_T);
    	chronoStackAddEnvData[15] = (uint8)FiltMeasTemp_DegC_T_s16;
    	chronoStackAddEnvData[14] = (uint8)(FiltMeasTemp_DegC_T_s16 >> 8u);

    	/*CAN Battery Voltage*/
    	chronoStackAddEnvData[16] = FPM_FloatToFixed_m(Rte_SrlComInput_BattVolt_Volt_f32/0.1f, u16p0_T);

    	for ( i= 17; i < envDataSize ; i++  )
    		chronoStackAddEnvData[i] = 0xFF ;
    	  result = kFrfmSuccess;

 //   }
  return result;

}
/*******************************************************************************
* NAME:              ApplFrfmGetOdometerValue
*
* CALLED BY:         FrfmSetEventStatus, FrfmDebounceEventFailed, FrfmDebounceEventPassed,
*                    FrfmUpdateInterrogationRecord, FrfmClearHistoricalData and all EnableCondition related functions
* PRECONDITIONS:     -
*
* DESCRIPTION:       Service of the application for updating the odometer value in the FRFM. This service is executed
*                    by the FRFM to retrieve the current value when this value is required by internal functionality.
*                    Return value t_FrfmOdometer:
*                    The current odometer value of the system. Resolution: 16km/bit.
*                      0 ... 0xFFFE   Set this odometer value.
*                      0xFFFF         No odometer value available (Default).
*******************************************************************************/
t_FrfmOdometer ApplFrfmGetOdometerValue( void )
{
  /* here we have no problem with buffer alignment so we simply cast uint16* to uint8* */

  return ((uint16)(CDD_Odometer_Cnt_u32/16U));

}

/*******************************************************************************
* NAME:             Dem_MainFunction
*
* CALLED BY:        Application
* PRECONDITIONS:     
* REENTRANCY:       No
* SERVICE ID:       0x55
*
* DESCRIPTION:      This function is used to process all not event based DEM internal
*                   functions. It shall be called periodically as cyclic task by the software system (e.g.
*                   by operating system).
*******************************************************************************/
FUNC(void, DEM_CODE)
Dem_MainFunction(
  void
  )
{
  FrfmTask();
}

/*******************************************************************************
* NAME:             Dem_GetDTCOfEvent
*
* CALLED BY:        Application  
* PRECONDITIONS:     
* REENTRANCY:       Yes
* SERVICE ID:       0x0d
*
* DESCRIPTION:      Gets the DTC which is mapped to EventId by FRFM Configuration.
*******************************************************************************/
FUNC(Std_ReturnType, DEM_CODE)
Dem_GetDTCOfEvent(
  Dem_EventIdType                               EventId,
  Dem_DTCKindType                               DTCKind,
  P2VAR(Dem_DTCType, AUTOMATIC, DEM_APPL_DATA)  DTCOfEvent
  )
{
  Std_ReturnType result = E_NOT_OK;

  if ((Dem_DTCKindType)DEM_DTC_KIND_ALL_DTCS != DTCKind )
  {
    result = DEM_GET_DTCOFEVENT_WRONG_DTCKIND;
  }
  else if (EventId >= kFrfmNumDtc)
  {
    result = DEM_GET_DTCOFEVENT_WRONG_EVENTID;
  }
  else
  {
    *DTCOfEvent       = (Dem_DTCType) FrfmGetDtcNum( (t_FrfmDtcSfnType)EventId );
    result = E_OK;
  }

  return result;
}

#if (DEM_VERSION_INFO_API == STD_ON)
/*******************************************************************************
* NAME:             Dem_GetVersionInfo
*
* CALLED BY:        Application  
* PRECONDITIONS:    Preprocessed
* REENTRANCY:       Yes
* SERVICE ID:       0x00
* INPUT PARAMETERS: Pointer to version structure
*
* DESCRIPTION:      Get the version of the DEM.
*******************************************************************************/
FUNC(void, DEM_CODE)
Dem_GetVersionInfo(
  P2VAR(Std_VersionInfoType, AUTOMATIC, DEM_APPL_DATA)  versioninfo
  )
{
  versioninfo->vendorID = DEM_VENDOR_ID;
  versioninfo->moduleID = DEM_MODULE_ID;
  versioninfo->sw_major_version = DEM_SW_MAJOR_VERSION;
  versioninfo->sw_minor_version = DEM_SW_MINOR_VERSION;
  versioninfo->sw_patch_version = DEM_SW_PATCH_VERSION;
}
#endif

/*******************************************************************************
* NAME:             Dem_GetEventFailed
*
* CALLED BY:        Application  
* PRECONDITIONS:     
* REENTRANCY:       Yes
* SERVICE ID:       0x0b
*
* DESCRIPTION:      This API shall be used to read Bit 0 of Dem_EventStatusExtendedType
*                   from the DEM.
*******************************************************************************/
FUNC(Std_ReturnType, DEM_CODE)
Dem_GetEventFailed(
  Dem_EventIdType                           EventId,
  P2VAR(boolean, AUTOMATIC, DEM_APPL_DATA)  EventFailed
  )
{
  Std_ReturnType        result = E_OK;
  t_FrfmGetEventStatus  frfmStatus;

  if (EventId < kFrfmNumDtc)
  {
    /* further checks are done by assertions in FrfmGetEventStatus() */
    frfmStatus = FrfmGetEventStatus ((t_FrfmDtcSfnType) EventId );
    *EventFailed = (boolean) (((vbittype)0 == frfmStatus.bTestFailed) ? FALSE : TRUE);
  }
  else
  {
    result = E_NOT_OK;
  }

  return result;
}

/*******************************************************************************
* NAME:             Dem_GetEventTested
*
* CALLED BY:        Application  
* PRECONDITIONS:     
* REENTRANCY:       Yes
* SERVICE ID:       0x0c
*
* DESCRIPTION:      This API shall be used to read negated Bit 6 of
*                   Dem_EventStatusExtendedType from the DEM.
*******************************************************************************/
FUNC(Std_ReturnType, DEM_CODE)
Dem_GetEventTested(
  Dem_EventIdType                           EventId,
  P2VAR(boolean, AUTOMATIC, DEM_APPL_DATA)  EventTested
  )
{
  Std_ReturnType        result = E_OK;
  t_FrfmGetEventStatus  frfmStatus;

  if (EventId < kFrfmNumDtc)
  {
    /* further checks are done by assertions in FrfmGetEventStatus() */
    frfmStatus = FrfmGetEventStatus ((t_FrfmDtcSfnType) EventId );
    *EventTested = (boolean) (((vbittype)0 == frfmStatus.bTestNotCompletedThisOperationCycle) ? TRUE : FALSE);
  }
  else
  {
    result = E_NOT_OK;
  }

  return result;
}

/*******************************************************************************
* NAME:              Dem_ResetEventStatus
*
* CALLED BY:         Application
* PRECONDITIONS:     
* REENTRANT:         yes
* SERVICE ID:        0x05
*
* DESCRIPTION:       This service shall be used to reset the Event Status stored in the Event Memory
*                    in the DEM, without the usage of API Dem_SetEventStatus(EventId, Passed),
*                    because no new test result is available at this time.
*                    With this API the status bit "Failed" defined by Dem_EventStatusExtendedType is
*                    set to 0. API is called by Monitor Function.
*******************************************************************************/
FUNC(Std_ReturnType, DEM_CODE)                                                                    
Dem_ResetEventStatus(
  Dem_EventIdType   EventId
  )
{
  DEM_IGNORE_UNREF_PARAM(EventId);
  /* Not supported, yet */
  return E_NOT_OK;
}

/*******************************************************************************
* NAME:              Dem_GetFaultDetectionCounter
*
* CALLED BY:         Application  
* PRECONDITIONS:     
* REENTRANT:         no
* SERVICE ID:        0x3e
*
* DESCRIPTION:       The API shall be used by SW-C to request the current Fault Detection Counter for a
*                    given EventID.
*******************************************************************************/
FUNC(Std_ReturnType, DEM_CODE)                                                                    
Dem_GetFaultDetectionCounter(
  Dem_EventIdType                                                 EventId,
  P2VAR(Dem_FaultDetectionCounterType, AUTOMATIC, DEM_APPL_DATA)  EventIdFaultDetectionCounter    
)
{
  DEM_IGNORE_UNREF_PARAM(EventId);
  DEM_IGNORE_UNREF_PARAM(EventIdFaultDetectionCounter);
  /* Not supported, yet */
  return E_NOT_OK;
}

/*******************************************************************************
* NAME:              Dem_GetIndicatorStatus
*
* CALLED BY:         Application  
* PRECONDITIONS:     
* REENTRANT:         no
* SERVICE ID:        0x29
*
* DESCRIPTION:       This function shall be used to read the indicator-status derived from the
*                    event status as a summary of all assigned events.
*******************************************************************************/
FUNC(Std_ReturnType, DEM_CODE)
Dem_GetIndicatorStatus(
  Dem_IndicatorIdType                                       Dem_IndicatorId,
  P2VAR(Dem_IndicatorStatusType, AUTOMATIC, DEM_APPL_DATA)  Dem_IndicatorStatus
  )
{
  DEM_IGNORE_UNREF_PARAM(Dem_IndicatorId);
  DEM_IGNORE_UNREF_PARAM(Dem_IndicatorStatus);
  /* Not supported, yet */
  return E_NOT_OK;
}
/*******************************************************************************
* NAME:              Dem_NvDataInit
*
* CALLED BY:         NVRAM-Manager Callback for initialization of non volatile memory.
*
* DESCRIPTION:      by NvM, if NVRAM is empty or invalid
*******************************************************************************/

FUNC(Std_ReturnType, DEM_CODE)
Dem_NvDataInit(
  void
  )
{

	return E_OK;
	/* Not supported, yet */
}

/* Copy NvM Buffer data into RAM buffer DEM uses */
FUNC(void, DEM_CODE) Dem_Init1(void)
{
	g_frfmNVData = Dem_NvData;
}

/* Get the NVM BLOCKS ID */
FUNC(void, DEM_CODE)Dem_Shutdown( void )
{

FrfmPowerDown();
Dem_NvData = g_frfmNVData;

NvM_SetRamBlockStatus(NvM_NVM_BLOCK_DEM, TRUE);
}
