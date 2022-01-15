/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  Copyright (c) 2006-2011 by Vector Informatik GmbH.                                             All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  Rte_Ap_SrlComInput.h
 *     Workspace:  C:/Users/sz1dx6/Documents/Synergy/ccm_wa/sz1dx62/sz1dx61/Chrysler_LWR_EPS_TMS570/SwProject/SrlComInput/autosar/Ap_SrlComInput.dcf
 *     SW-C Type:  Ap_SrlComInput
 *  Generated at:  Fri Jan 24 12:59:02 2014
 *
 *     Generator:  MICROSAR RTE Generator Version 2.19.1
 *       License:  License CBD1010124 valid for CBD1010124 Nexteer  Package: BMW MSR SIP BAC3.0     Micro: TI TMS570 TMS570LS30306  Compiler: Code Composer Studio 4.9.0
 *
 *   Description:  Application header file for SW-C <Ap_SrlComInput> (Contract Phase)
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_AP_SRLCOMINPUT_H
# define _RTE_AP_SRLCOMINPUT_H

# ifdef RTE_APPLICATION_HEADER_FILE
#  error Multiple application header files included.
# endif
# define RTE_APPLICATION_HEADER_FILE

# ifdef __cplusplus
extern "C"
{
# endif /* __cplusplus */

/* include files */

# include "Rte_Type.h"

typedef P2CONST(struct Rte_CDS_Ap_SrlComInput, TYPEDEF, RTE_CONST) Rte_Instance;


/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

# define Rte_InitValue_AirTempOutside_DegC_f32 (0.0F)
# define Rte_InitValue_AmbTempAvg_DegC_f32 (0.0F)
# define Rte_InitValue_AnaHwTorque_HwNm_f32 (0.0F)
# define Rte_InitValue_BattVolt_Volt_f32 (0.0F)
# define Rte_InitValue_CMDIgnStat_Cnt_u08 (0U)
# define Rte_InitValue_CanMsgReceived_Cnt_lgc (FALSE)
# define Rte_InitValue_CfgStatRQ_Cnt_u08 (0U)
# define Rte_InitValue_DSTEOLDisable_Cnt_lgc (FALSE)
# define Rte_InitValue_DSTEnableRqst_Cnt_lgc (FALSE)
# define Rte_InitValue_DSTErrCntrRecvLevel_Cnt_u08 (0U)
# define Rte_InitValue_DSTExtSystemFltActive_Cnt_lgc (FALSE)
# define Rte_InitValue_DSTFuncPresent_Cnt_lgc (FALSE)
# define Rte_InitValue_DSTRevGearValid_Cnt_lgc (FALSE)
# define Rte_InitValue_DSTSlewStart_Cnt_lgc (FALSE)
# define Rte_InitValue_DSTState_Cnt_u08 (0U)
# define Rte_InitValue_DSTTOCState_Uls_enum (0U)
# define Rte_InitValue_DSTTrqOvCmdRqst_HwNm_f32 (0.0F)
# define Rte_InitValue_DSTTrqOvRqstValid_Cnt_lgc (FALSE)
# define Rte_InitValue_DefaultVehSpd_Cnt_lgc (FALSE)
# define Rte_InitValue_DesiredTunPers_Cnt_u16 (0U)
# define Rte_InitValue_DesiredTunPersTypH_Cnt_u08 (0U)
# define Rte_InitValue_DesiredTunSet_Cnt_u16 (0U)
# define Rte_InitValue_EPS_Mode_Req_Cnt_u08 (0U)
# define Rte_InitValue_EngOilTemp_DegC_f32 (0.0F)
# define Rte_InitValue_EngRPM_Cnt_u16 (1U)
# define Rte_InitValue_EssEngStop_Cnt_lgc (TRUE)
# define Rte_InitValue_HaLFEnableRqst_Cnt_lgc (FALSE)
# define Rte_InitValue_HaLFErrInterfaceActive_Cnt_lgc (FALSE)
# define Rte_InitValue_HaLFExtSystemFltActive_Cnt_lgc (FALSE)
# define Rte_InitValue_HaLFFuncPresent_Cnt_lgc (FALSE)
# define Rte_InitValue_HaLFIntSystemFltActive_Cnt_lgc (FALSE)
# define Rte_InitValue_HaLFSWATrqFail_Cnt_lgc (FALSE)
# define Rte_InitValue_HaLFState_Cnt_u08 (0U)
# define Rte_InitValue_HaLFSuspend_Cnt_lgc (FALSE)
# define Rte_InitValue_HaLFTrqOvCmdRqst_MtrNm_f32 (0.0F)
# define Rte_InitValue_HalfTrqOvRvrsGearEngage_Cnt_lgc (FALSE)
# define Rte_InitValue_HandsOnDetect_Cnt_lgc (FALSE)
# define Rte_InitValue_IWSSCalcVspd_Kph_f32 (0.0F)
# define Rte_InitValue_MEC_Cnt_u08 (0U)
# define Rte_InitValue_NET_CFG_STAT_PT_Cnt_u16 (0U)
# define Rte_InitValue_ODO_HwNmSq_f32 (0.0F)
# define Rte_InitValue_PABoostCurveSwitch_Cnt_lgc (FALSE)
# define Rte_InitValue_PAEnableRqst_Cnt_lgc (FALSE)
# define Rte_InitValue_PAErrInterfaceActive_Cnt_lgc (FALSE)
# define Rte_InitValue_PAExtSystemFltActive_Cnt_lgc (FALSE)
# define Rte_InitValue_PAIntSystemFltActive_Cnt_lgc (FALSE)
# define Rte_InitValue_PAManoeuvrePhase_Cnt_u08 (0U)
# define Rte_InitValue_PATrqOvCmdRqst_HwNm_f32 (0.0F)
# define Rte_InitValue_PAWheelCriteriaMet_Cnt_lgc (FALSE)
# define Rte_InitValue_PAWhlDirRLStat_Cnt_u08 (3U)
# define Rte_InitValue_PAWhlDirRRStat_Cnt_u08 (3U)
# define Rte_InitValue_PAWhlPlsCntRLValid_Cnt_lgc (FALSE)
# define Rte_InitValue_PAWhlPlsCntRRValid_Cnt_lgc (FALSE)
# define Rte_InitValue_PrkAssistState_Cnt_u08 (0U)
# define Rte_InitValue_PrkAssistSuspend_Cnt_lgc (FALSE)
# define Rte_InitValue_PrkAsstFuncPresent_Cnt_lgc (FALSE)
# define Rte_InitValue_RxMsgsSrlComSvcDft_Cnt_lgc (FALSE)
# define Rte_InitValue_SpStPrsnt_Cnt_lgc (FALSE)
# define Rte_InitValue_SrlComLWhlSpd_Hz_f32 (0.0F)
# define Rte_InitValue_SrlComLWhlSpdVld_Cnt_lgc (FALSE)
# define Rte_InitValue_SrlComRWhlSpd_Hz_f32 (0.0F)
# define Rte_InitValue_SrlComRWhlSpdVld_Cnt_lgc (FALSE)
# define Rte_InitValue_SrlComVehSpd_Kph_f32 (0.0F)
# define Rte_InitValue_SrlComVehSpdValid_Cnt_lgc (FALSE)
# define Rte_InitValue_StrClmTrq_HwNm_f32 (0.0F)
# define Rte_InitValue_StrgWhlAngl_HwDeg_f32 (0.0F)
# define Rte_InitValue_StrgWhlAnglValid_Cnt_lgc (FALSE)
# define Rte_InitValue_TrqOvReverseGearEngage_Cnt_lgc (FALSE)
# define Rte_InitValue_VCBodyStyle_Cnt_u08 (0U)
# define Rte_InitValue_VCCountry_Cnt_u08 (0U)
# define Rte_InitValue_VCModelYear_Cnt_u08 (0U)
# define Rte_InitValue_VCVehLine_Cnt_u08 (0U)
# define Rte_InitValue_VehAccel_KphpS_f32 (0.0F)
# define Rte_InitValue_VehAccelX_KphpS_f32 (0.0F)


# define RTE_START_SEC_CODE
# include "MemMap.h"

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ap_SrlComInput_AnaHwTorque_HwNm_f32(P2VAR(Float, AUTOMATIC, RTE_AP_SRLCOMINPUT_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ap_SrlComInput_DSTSlewStart_Cnt_lgc(P2VAR(Boolean, AUTOMATIC, RTE_AP_SRLCOMINPUT_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ap_SrlComInput_DSTState_Cnt_u08(P2VAR(UInt8, AUTOMATIC, RTE_AP_SRLCOMINPUT_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ap_SrlComInput_DefaultVehSpd_Cnt_lgc(P2VAR(Boolean, AUTOMATIC, RTE_AP_SRLCOMINPUT_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ap_SrlComInput_HaLFState_Cnt_u08(P2VAR(UInt8, AUTOMATIC, RTE_AP_SRLCOMINPUT_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ap_SrlComInput_HaLFSuspend_Cnt_lgc(P2VAR(Boolean, AUTOMATIC, RTE_AP_SRLCOMINPUT_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ap_SrlComInput_HandsOnDetect_Cnt_lgc(P2VAR(Boolean, AUTOMATIC, RTE_AP_SRLCOMINPUT_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ap_SrlComInput_MEC_Cnt_u08(P2VAR(UInt8, AUTOMATIC, RTE_AP_SRLCOMINPUT_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ap_SrlComInput_PABoostCurveSwitch_Cnt_lgc(P2VAR(Boolean, AUTOMATIC, RTE_AP_SRLCOMINPUT_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ap_SrlComInput_PrkAssistState_Cnt_u08(P2VAR(UInt8, AUTOMATIC, RTE_AP_SRLCOMINPUT_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ap_SrlComInput_PrkAssistSuspend_Cnt_lgc(P2VAR(Boolean, AUTOMATIC, RTE_AP_SRLCOMINPUT_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ap_SrlComInput_RxMsgsSrlComSvcDft_Cnt_lgc(P2VAR(Boolean, AUTOMATIC, RTE_AP_SRLCOMINPUT_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ap_SrlComInput_StrClmTrq_HwNm_f32(P2VAR(Float, AUTOMATIC, RTE_AP_SRLCOMINPUT_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ap_SrlComInput_AirTempOutside_DegC_f32(Float data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ap_SrlComInput_AmbTempAvg_DegC_f32(Float data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ap_SrlComInput_BattVolt_Volt_f32(Float data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ap_SrlComInput_CMDIgnStat_Cnt_u08(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ap_SrlComInput_CanMsgReceived_Cnt_lgc(Boolean data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ap_SrlComInput_CfgStatRQ_Cnt_u08(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ap_SrlComInput_DSTEOLDisable_Cnt_lgc(Boolean data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ap_SrlComInput_DSTEnableRqst_Cnt_lgc(Boolean data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ap_SrlComInput_DSTErrCntrRecvLevel_Cnt_u08(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ap_SrlComInput_DSTExtSystemFltActive_Cnt_lgc(Boolean data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ap_SrlComInput_DSTFuncPresent_Cnt_lgc(Boolean data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ap_SrlComInput_DSTRevGearValid_Cnt_lgc(Boolean data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ap_SrlComInput_DSTTOCState_Uls_enum(TOC_STATE data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ap_SrlComInput_DSTTrqOvCmdRqst_HwNm_f32(Float data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ap_SrlComInput_DSTTrqOvRqstValid_Cnt_lgc(Boolean data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ap_SrlComInput_DesiredTunPers_Cnt_u16(UInt16 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ap_SrlComInput_DesiredTunPersTypH_Cnt_u08(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ap_SrlComInput_DesiredTunSet_Cnt_u16(UInt16 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ap_SrlComInput_EPS_Mode_Req_Cnt_u08(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ap_SrlComInput_EngOilTemp_DegC_f32(Float data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ap_SrlComInput_EngRPM_Cnt_u16(UInt16 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ap_SrlComInput_EssEngStop_Cnt_lgc(Boolean data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ap_SrlComInput_HaLFEnableRqst_Cnt_lgc(Boolean data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ap_SrlComInput_HaLFErrInterfaceActive_Cnt_lgc(Boolean data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ap_SrlComInput_HaLFExtSystemFltActive_Cnt_lgc(Boolean data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ap_SrlComInput_HaLFFuncPresent_Cnt_lgc(Boolean data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ap_SrlComInput_HaLFIntSystemFltActive_Cnt_lgc(Boolean data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ap_SrlComInput_HaLFSWATrqFail_Cnt_lgc(Boolean data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ap_SrlComInput_HaLFTrqOvCmdRqst_MtrNm_f32(Float data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ap_SrlComInput_HalfTrqOvRvrsGearEngage_Cnt_lgc(Boolean data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ap_SrlComInput_IWSSCalcVspd_Kph_f32(Float data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ap_SrlComInput_NET_CFG_STAT_PT_Cnt_u16(UInt16 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ap_SrlComInput_ODO_HwNmSq_f32(Float data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ap_SrlComInput_PAEnableRqst_Cnt_lgc(Boolean data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ap_SrlComInput_PAErrInterfaceActive_Cnt_lgc(Boolean data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ap_SrlComInput_PAExtSystemFltActive_Cnt_lgc(Boolean data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ap_SrlComInput_PAIntSystemFltActive_Cnt_lgc(Boolean data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ap_SrlComInput_PAManoeuvrePhase_Cnt_u08(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ap_SrlComInput_PATrqOvCmdRqst_HwNm_f32(Float data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ap_SrlComInput_PAWheelCriteriaMet_Cnt_lgc(Boolean data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ap_SrlComInput_PAWhlDirRLStat_Cnt_u08(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ap_SrlComInput_PAWhlDirRRStat_Cnt_u08(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ap_SrlComInput_PAWhlPlsCntRLValid_Cnt_lgc(Boolean data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ap_SrlComInput_PAWhlPlsCntRRValid_Cnt_lgc(Boolean data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ap_SrlComInput_PrkAsstFuncPresent_Cnt_lgc(Boolean data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ap_SrlComInput_SpStPrsnt_Cnt_lgc(Boolean data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ap_SrlComInput_SrlComLWhlSpd_Hz_f32(Float data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ap_SrlComInput_SrlComLWhlSpdVld_Cnt_lgc(Boolean data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ap_SrlComInput_SrlComRWhlSpd_Hz_f32(Float data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ap_SrlComInput_SrlComRWhlSpdVld_Cnt_lgc(Boolean data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ap_SrlComInput_SrlComVehSpd_Kph_f32(Float data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ap_SrlComInput_SrlComVehSpdValid_Cnt_lgc(Boolean data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ap_SrlComInput_StrgWhlAngl_HwDeg_f32(Float data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ap_SrlComInput_StrgWhlAnglValid_Cnt_lgc(Boolean data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ap_SrlComInput_TrqOvReverseGearEngage_Cnt_lgc(Boolean data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ap_SrlComInput_VCBodyStyle_Cnt_u08(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ap_SrlComInput_VCCountry_Cnt_u08(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ap_SrlComInput_VCModelYear_Cnt_u08(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ap_SrlComInput_VCVehLine_Cnt_u08(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ap_SrlComInput_VehAccel_KphpS_f32(Float data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ap_SrlComInput_VehAccelX_KphpS_f32(Float data);
FUNC(Rte_ModeType_StaMd_Mode, RTE_CODE) Rte_Mode_Ap_SrlComInput_SystemState_Mode(void);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ap_SrlComInput_NxtrDiagMgr_GetNTCFailed(NTCNumber NTC_Cnt_T_enum, P2VAR(Boolean, AUTOMATIC, RTE_AP_SRLCOMINPUT_APPL_VAR) NTCFailed_Ptr_T_lgc);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ap_SrlComInput_NxtrDiagMgr_GetNTCStatus(NTCNumber NTC_Cnt_T_enum, P2VAR(UInt8, AUTOMATIC, RTE_AP_SRLCOMINPUT_APPL_VAR) Status_Ptr_T_u08);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ap_SrlComInput_NxtrDiagMgr_SetNTCStatus(NTCNumber NTC_Cnt_T_enum, UInt8 Param_Cnt_T_u08, NxtrDiagMgrStatus Status_Cnt_T_enum);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ap_SrlComInput_SystemTime_DtrmnElapsedTime_mS_u16(UInt32 InitialTime, P2VAR(UInt16, AUTOMATIC, RTE_AP_SRLCOMINPUT_APPL_VAR) ElapsedTime);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ap_SrlComInput_SystemTime_DtrmnElapsedTime_mS_u32(UInt32 InitialTime, P2VAR(UInt32, AUTOMATIC, RTE_AP_SRLCOMINPUT_APPL_VAR) ElapsedTime);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ap_SrlComInput_SystemTime_GetSystemTime_mS_u32(P2VAR(UInt32, AUTOMATIC, RTE_AP_SRLCOMINPUT_APPL_VAR) CurrentTime);

# define RTE_STOP_SEC_CODE
# include "MemMap.h"



/**********************************************************************************************************************
 * Rte_Read_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
# define Rte_Read_AnaHwTorque_HwNm_f32 Rte_Read_Ap_SrlComInput_AnaHwTorque_HwNm_f32
# define Rte_Read_DSTSlewStart_Cnt_lgc Rte_Read_Ap_SrlComInput_DSTSlewStart_Cnt_lgc
# define Rte_Read_DSTState_Cnt_u08 Rte_Read_Ap_SrlComInput_DSTState_Cnt_u08
# define Rte_Read_DefaultVehSpd_Cnt_lgc Rte_Read_Ap_SrlComInput_DefaultVehSpd_Cnt_lgc
# define Rte_Read_HaLFState_Cnt_u08 Rte_Read_Ap_SrlComInput_HaLFState_Cnt_u08
# define Rte_Read_HaLFSuspend_Cnt_lgc Rte_Read_Ap_SrlComInput_HaLFSuspend_Cnt_lgc
# define Rte_Read_HandsOnDetect_Cnt_lgc Rte_Read_Ap_SrlComInput_HandsOnDetect_Cnt_lgc
# define Rte_Read_MEC_Cnt_u08 Rte_Read_Ap_SrlComInput_MEC_Cnt_u08
# define Rte_Read_PABoostCurveSwitch_Cnt_lgc Rte_Read_Ap_SrlComInput_PABoostCurveSwitch_Cnt_lgc
# define Rte_Read_PrkAssistState_Cnt_u08 Rte_Read_Ap_SrlComInput_PrkAssistState_Cnt_u08
# define Rte_Read_PrkAssistSuspend_Cnt_lgc Rte_Read_Ap_SrlComInput_PrkAssistSuspend_Cnt_lgc
# define Rte_Read_RxMsgsSrlComSvcDft_Cnt_lgc Rte_Read_Ap_SrlComInput_RxMsgsSrlComSvcDft_Cnt_lgc
# define Rte_Read_StrClmTrq_HwNm_f32 Rte_Read_Ap_SrlComInput_StrClmTrq_HwNm_f32


/**********************************************************************************************************************
 * Rte_Write_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
# define Rte_Write_AirTempOutside_DegC_f32 Rte_Write_Ap_SrlComInput_AirTempOutside_DegC_f32
# define Rte_Write_AmbTempAvg_DegC_f32 Rte_Write_Ap_SrlComInput_AmbTempAvg_DegC_f32
# define Rte_Write_BattVolt_Volt_f32 Rte_Write_Ap_SrlComInput_BattVolt_Volt_f32
# define Rte_Write_CMDIgnStat_Cnt_u08 Rte_Write_Ap_SrlComInput_CMDIgnStat_Cnt_u08
# define Rte_Write_CanMsgReceived_Cnt_lgc Rte_Write_Ap_SrlComInput_CanMsgReceived_Cnt_lgc
# define Rte_Write_CfgStatRQ_Cnt_u08 Rte_Write_Ap_SrlComInput_CfgStatRQ_Cnt_u08
# define Rte_Write_DSTEOLDisable_Cnt_lgc Rte_Write_Ap_SrlComInput_DSTEOLDisable_Cnt_lgc
# define Rte_Write_DSTEnableRqst_Cnt_lgc Rte_Write_Ap_SrlComInput_DSTEnableRqst_Cnt_lgc
# define Rte_Write_DSTErrCntrRecvLevel_Cnt_u08 Rte_Write_Ap_SrlComInput_DSTErrCntrRecvLevel_Cnt_u08
# define Rte_Write_DSTExtSystemFltActive_Cnt_lgc Rte_Write_Ap_SrlComInput_DSTExtSystemFltActive_Cnt_lgc
# define Rte_Write_DSTFuncPresent_Cnt_lgc Rte_Write_Ap_SrlComInput_DSTFuncPresent_Cnt_lgc
# define Rte_Write_DSTRevGearValid_Cnt_lgc Rte_Write_Ap_SrlComInput_DSTRevGearValid_Cnt_lgc
# define Rte_Write_DSTTOCState_Uls_enum Rte_Write_Ap_SrlComInput_DSTTOCState_Uls_enum
# define Rte_Write_DSTTrqOvCmdRqst_HwNm_f32 Rte_Write_Ap_SrlComInput_DSTTrqOvCmdRqst_HwNm_f32
# define Rte_Write_DSTTrqOvRqstValid_Cnt_lgc Rte_Write_Ap_SrlComInput_DSTTrqOvRqstValid_Cnt_lgc
# define Rte_Write_DesiredTunPers_Cnt_u16 Rte_Write_Ap_SrlComInput_DesiredTunPers_Cnt_u16
# define Rte_Write_DesiredTunPersTypH_Cnt_u08 Rte_Write_Ap_SrlComInput_DesiredTunPersTypH_Cnt_u08
# define Rte_Write_DesiredTunSet_Cnt_u16 Rte_Write_Ap_SrlComInput_DesiredTunSet_Cnt_u16
# define Rte_Write_EPS_Mode_Req_Cnt_u08 Rte_Write_Ap_SrlComInput_EPS_Mode_Req_Cnt_u08
# define Rte_Write_EngOilTemp_DegC_f32 Rte_Write_Ap_SrlComInput_EngOilTemp_DegC_f32
# define Rte_Write_EngRPM_Cnt_u16 Rte_Write_Ap_SrlComInput_EngRPM_Cnt_u16
# define Rte_Write_EssEngStop_Cnt_lgc Rte_Write_Ap_SrlComInput_EssEngStop_Cnt_lgc
# define Rte_Write_HaLFEnableRqst_Cnt_lgc Rte_Write_Ap_SrlComInput_HaLFEnableRqst_Cnt_lgc
# define Rte_Write_HaLFErrInterfaceActive_Cnt_lgc Rte_Write_Ap_SrlComInput_HaLFErrInterfaceActive_Cnt_lgc
# define Rte_Write_HaLFExtSystemFltActive_Cnt_lgc Rte_Write_Ap_SrlComInput_HaLFExtSystemFltActive_Cnt_lgc
# define Rte_Write_HaLFFuncPresent_Cnt_lgc Rte_Write_Ap_SrlComInput_HaLFFuncPresent_Cnt_lgc
# define Rte_Write_HaLFIntSystemFltActive_Cnt_lgc Rte_Write_Ap_SrlComInput_HaLFIntSystemFltActive_Cnt_lgc
# define Rte_Write_HaLFSWATrqFail_Cnt_lgc Rte_Write_Ap_SrlComInput_HaLFSWATrqFail_Cnt_lgc
# define Rte_Write_HaLFTrqOvCmdRqst_MtrNm_f32 Rte_Write_Ap_SrlComInput_HaLFTrqOvCmdRqst_MtrNm_f32
# define Rte_Write_HalfTrqOvRvrsGearEngage_Cnt_lgc Rte_Write_Ap_SrlComInput_HalfTrqOvRvrsGearEngage_Cnt_lgc
# define Rte_Write_IWSSCalcVspd_Kph_f32 Rte_Write_Ap_SrlComInput_IWSSCalcVspd_Kph_f32
# define Rte_Write_NET_CFG_STAT_PT_Cnt_u16 Rte_Write_Ap_SrlComInput_NET_CFG_STAT_PT_Cnt_u16
# define Rte_Write_ODO_HwNmSq_f32 Rte_Write_Ap_SrlComInput_ODO_HwNmSq_f32
# define Rte_Write_PAEnableRqst_Cnt_lgc Rte_Write_Ap_SrlComInput_PAEnableRqst_Cnt_lgc
# define Rte_Write_PAErrInterfaceActive_Cnt_lgc Rte_Write_Ap_SrlComInput_PAErrInterfaceActive_Cnt_lgc
# define Rte_Write_PAExtSystemFltActive_Cnt_lgc Rte_Write_Ap_SrlComInput_PAExtSystemFltActive_Cnt_lgc
# define Rte_Write_PAIntSystemFltActive_Cnt_lgc Rte_Write_Ap_SrlComInput_PAIntSystemFltActive_Cnt_lgc
# define Rte_Write_PAManoeuvrePhase_Cnt_u08 Rte_Write_Ap_SrlComInput_PAManoeuvrePhase_Cnt_u08
# define Rte_Write_PATrqOvCmdRqst_HwNm_f32 Rte_Write_Ap_SrlComInput_PATrqOvCmdRqst_HwNm_f32
# define Rte_Write_PAWheelCriteriaMet_Cnt_lgc Rte_Write_Ap_SrlComInput_PAWheelCriteriaMet_Cnt_lgc
# define Rte_Write_PAWhlDirRLStat_Cnt_u08 Rte_Write_Ap_SrlComInput_PAWhlDirRLStat_Cnt_u08
# define Rte_Write_PAWhlDirRRStat_Cnt_u08 Rte_Write_Ap_SrlComInput_PAWhlDirRRStat_Cnt_u08
# define Rte_Write_PAWhlPlsCntRLValid_Cnt_lgc Rte_Write_Ap_SrlComInput_PAWhlPlsCntRLValid_Cnt_lgc
# define Rte_Write_PAWhlPlsCntRRValid_Cnt_lgc Rte_Write_Ap_SrlComInput_PAWhlPlsCntRRValid_Cnt_lgc
# define Rte_Write_PrkAsstFuncPresent_Cnt_lgc Rte_Write_Ap_SrlComInput_PrkAsstFuncPresent_Cnt_lgc
# define Rte_Write_SpStPrsnt_Cnt_lgc Rte_Write_Ap_SrlComInput_SpStPrsnt_Cnt_lgc
# define Rte_Write_SrlComLWhlSpd_Hz_f32 Rte_Write_Ap_SrlComInput_SrlComLWhlSpd_Hz_f32
# define Rte_Write_SrlComLWhlSpdVld_Cnt_lgc Rte_Write_Ap_SrlComInput_SrlComLWhlSpdVld_Cnt_lgc
# define Rte_Write_SrlComRWhlSpd_Hz_f32 Rte_Write_Ap_SrlComInput_SrlComRWhlSpd_Hz_f32
# define Rte_Write_SrlComRWhlSpdVld_Cnt_lgc Rte_Write_Ap_SrlComInput_SrlComRWhlSpdVld_Cnt_lgc
# define Rte_Write_SrlComVehSpd_Kph_f32 Rte_Write_Ap_SrlComInput_SrlComVehSpd_Kph_f32
# define Rte_Write_SrlComVehSpdValid_Cnt_lgc Rte_Write_Ap_SrlComInput_SrlComVehSpdValid_Cnt_lgc
# define Rte_Write_StrgWhlAngl_HwDeg_f32 Rte_Write_Ap_SrlComInput_StrgWhlAngl_HwDeg_f32
# define Rte_Write_StrgWhlAnglValid_Cnt_lgc Rte_Write_Ap_SrlComInput_StrgWhlAnglValid_Cnt_lgc
# define Rte_Write_TrqOvReverseGearEngage_Cnt_lgc Rte_Write_Ap_SrlComInput_TrqOvReverseGearEngage_Cnt_lgc
# define Rte_Write_VCBodyStyle_Cnt_u08 Rte_Write_Ap_SrlComInput_VCBodyStyle_Cnt_u08
# define Rte_Write_VCCountry_Cnt_u08 Rte_Write_Ap_SrlComInput_VCCountry_Cnt_u08
# define Rte_Write_VCModelYear_Cnt_u08 Rte_Write_Ap_SrlComInput_VCModelYear_Cnt_u08
# define Rte_Write_VCVehLine_Cnt_u08 Rte_Write_Ap_SrlComInput_VCVehLine_Cnt_u08
# define Rte_Write_VehAccel_KphpS_f32 Rte_Write_Ap_SrlComInput_VehAccel_KphpS_f32
# define Rte_Write_VehAccelX_KphpS_f32 Rte_Write_Ap_SrlComInput_VehAccelX_KphpS_f32


/**********************************************************************************************************************
 * Rte_Mode_<p>_<m>
 *********************************************************************************************************************/
# define Rte_Mode_SystemState_Mode Rte_Mode_Ap_SrlComInput_SystemState_Mode


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (C/S invocation)
 *********************************************************************************************************************/
# define Rte_Call_NxtrDiagMgr_GetNTCFailed Rte_Call_Ap_SrlComInput_NxtrDiagMgr_GetNTCFailed
# define Rte_Call_NxtrDiagMgr_GetNTCStatus Rte_Call_Ap_SrlComInput_NxtrDiagMgr_GetNTCStatus
# define Rte_Call_NxtrDiagMgr_SetNTCStatus Rte_Call_Ap_SrlComInput_NxtrDiagMgr_SetNTCStatus
# define Rte_Call_SystemTime_DtrmnElapsedTime_mS_u16 Rte_Call_Ap_SrlComInput_SystemTime_DtrmnElapsedTime_mS_u16
# define Rte_Call_SystemTime_DtrmnElapsedTime_mS_u32 Rte_Call_Ap_SrlComInput_SystemTime_DtrmnElapsedTime_mS_u32
# define Rte_Call_SystemTime_GetSystemTime_mS_u32 Rte_Call_Ap_SrlComInput_SystemTime_GetSystemTime_mS_u32




# define RTE_START_SEC_AP_SRLCOMINPUT_APPL_CODE
# include "MemMap.h"


/**********************************************************************************************************************
 *
 * Runnable Entity Name: FaultInjection_FltInjection
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <FltInjection> of PortPrototype <FltInjection>
 *
 **********************************************************************************************************************
 *
 * Mode Interfaces:
 * ================
 *   Rte_ModeType_StaMd_Mode Rte_Mode_SystemState_Mode(void)
 *   Modes of Rte_ModeType_StaMd_Mode:
 *   - RTE_MODE_StaMd_Mode_DISABLE
 *   - RTE_MODE_StaMd_Mode_OFF
 *   - RTE_MODE_StaMd_Mode_OPERATE
 *   - RTE_MODE_StaMd_Mode_WARMINIT
 *   - RTE_TRANSITION_StaMd_Mode
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void FaultInjection_FltInjection(Float *SignalPath_Uls_f32, FltInjectionLocType LocationKey_Cnt_enum)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) FaultInjection_FltInjection(P2VAR(Float, AUTOMATIC, RTE_AP_SRLCOMINPUT_APPL_VAR) SignalPath_Uls_f32, FltInjectionLocType LocationKey_Cnt_enum);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: HaLFState_SCom_Transition
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Transition> of PortPrototype <HaLFState_SCom>
 *
 **********************************************************************************************************************
 *
 * Mode Interfaces:
 * ================
 *   Rte_ModeType_StaMd_Mode Rte_Mode_SystemState_Mode(void)
 *   Modes of Rte_ModeType_StaMd_Mode:
 *   - RTE_MODE_StaMd_Mode_DISABLE
 *   - RTE_MODE_StaMd_Mode_OFF
 *   - RTE_MODE_StaMd_Mode_OPERATE
 *   - RTE_MODE_StaMd_Mode_WARMINIT
 *   - RTE_TRANSITION_StaMd_Mode
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void HaLFState_SCom_Transition(UInt8 State_Cnt_T_u08)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) HaLFState_SCom_Transition(UInt8 State_Cnt_T_u08);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: PrkAssistState_SCom_Transition
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Transition> of PortPrototype <PrkAssistState_SCom>
 *
 **********************************************************************************************************************
 *
 * Mode Interfaces:
 * ================
 *   Rte_ModeType_StaMd_Mode Rte_Mode_SystemState_Mode(void)
 *   Modes of Rte_ModeType_StaMd_Mode:
 *   - RTE_MODE_StaMd_Mode_DISABLE
 *   - RTE_MODE_StaMd_Mode_OFF
 *   - RTE_MODE_StaMd_Mode_OPERATE
 *   - RTE_MODE_StaMd_Mode_WARMINIT
 *   - RTE_TRANSITION_StaMd_Mode
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void PrkAssistState_SCom_Transition(UInt8 State_Cnt_T_u08)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) PrkAssistState_SCom_Transition(UInt8 State_Cnt_T_u08);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: SrlComInput_Init
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 **********************************************************************************************************************
 *
 * Mode Interfaces:
 * ================
 *   Rte_ModeType_StaMd_Mode Rte_Mode_SystemState_Mode(void)
 *   Modes of Rte_ModeType_StaMd_Mode:
 *   - RTE_MODE_StaMd_Mode_DISABLE
 *   - RTE_MODE_StaMd_Mode_OFF
 *   - RTE_MODE_StaMd_Mode_OPERATE
 *   - RTE_MODE_StaMd_Mode_WARMINIT
 *   - RTE_TRANSITION_StaMd_Mode
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) SrlComInput_Init(void);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: SrlComInput_Per1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 10ms
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_AnaHwTorque_HwNm_f32(Float *data)
 *   Std_ReturnType Rte_Read_DSTSlewStart_Cnt_lgc(Boolean *data)
 *   Std_ReturnType Rte_Read_DSTState_Cnt_u08(UInt8 *data)
 *   Std_ReturnType Rte_Read_DefaultVehSpd_Cnt_lgc(Boolean *data)
 *   Std_ReturnType Rte_Read_HaLFState_Cnt_u08(UInt8 *data)
 *   Std_ReturnType Rte_Read_HaLFSuspend_Cnt_lgc(Boolean *data)
 *   Std_ReturnType Rte_Read_HandsOnDetect_Cnt_lgc(Boolean *data)
 *   Std_ReturnType Rte_Read_MEC_Cnt_u08(UInt8 *data)
 *   Std_ReturnType Rte_Read_PABoostCurveSwitch_Cnt_lgc(Boolean *data)
 *   Std_ReturnType Rte_Read_PrkAssistState_Cnt_u08(UInt8 *data)
 *   Std_ReturnType Rte_Read_PrkAssistSuspend_Cnt_lgc(Boolean *data)
 *   Std_ReturnType Rte_Read_RxMsgsSrlComSvcDft_Cnt_lgc(Boolean *data)
 *   Std_ReturnType Rte_Read_StrClmTrq_HwNm_f32(Float *data)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_AirTempOutside_DegC_f32(Float data)
 *   Std_ReturnType Rte_Write_AmbTempAvg_DegC_f32(Float data)
 *   Std_ReturnType Rte_Write_BattVolt_Volt_f32(Float data)
 *   Std_ReturnType Rte_Write_CMDIgnStat_Cnt_u08(UInt8 data)
 *   Std_ReturnType Rte_Write_CanMsgReceived_Cnt_lgc(Boolean data)
 *   Std_ReturnType Rte_Write_CfgStatRQ_Cnt_u08(UInt8 data)
 *   Std_ReturnType Rte_Write_DSTEOLDisable_Cnt_lgc(Boolean data)
 *   Std_ReturnType Rte_Write_DSTEnableRqst_Cnt_lgc(Boolean data)
 *   Std_ReturnType Rte_Write_DSTErrCntrRecvLevel_Cnt_u08(UInt8 data)
 *   Std_ReturnType Rte_Write_DSTExtSystemFltActive_Cnt_lgc(Boolean data)
 *   Std_ReturnType Rte_Write_DSTFuncPresent_Cnt_lgc(Boolean data)
 *   Std_ReturnType Rte_Write_DSTRevGearValid_Cnt_lgc(Boolean data)
 *   Std_ReturnType Rte_Write_DSTTOCState_Uls_enum(TOC_STATE data)
 *   Std_ReturnType Rte_Write_DSTTrqOvCmdRqst_HwNm_f32(Float data)
 *   Std_ReturnType Rte_Write_DSTTrqOvRqstValid_Cnt_lgc(Boolean data)
 *   Std_ReturnType Rte_Write_DesiredTunPers_Cnt_u16(UInt16 data)
 *   Std_ReturnType Rte_Write_DesiredTunPersTypH_Cnt_u08(UInt8 data)
 *   Std_ReturnType Rte_Write_DesiredTunSet_Cnt_u16(UInt16 data)
 *   Std_ReturnType Rte_Write_EPS_Mode_Req_Cnt_u08(UInt8 data)
 *   Std_ReturnType Rte_Write_EngOilTemp_DegC_f32(Float data)
 *   Std_ReturnType Rte_Write_EngRPM_Cnt_u16(UInt16 data)
 *   Std_ReturnType Rte_Write_EssEngStop_Cnt_lgc(Boolean data)
 *   Std_ReturnType Rte_Write_HaLFEnableRqst_Cnt_lgc(Boolean data)
 *   Std_ReturnType Rte_Write_HaLFErrInterfaceActive_Cnt_lgc(Boolean data)
 *   Std_ReturnType Rte_Write_HaLFExtSystemFltActive_Cnt_lgc(Boolean data)
 *   Std_ReturnType Rte_Write_HaLFFuncPresent_Cnt_lgc(Boolean data)
 *   Std_ReturnType Rte_Write_HaLFIntSystemFltActive_Cnt_lgc(Boolean data)
 *   Std_ReturnType Rte_Write_HaLFSWATrqFail_Cnt_lgc(Boolean data)
 *   Std_ReturnType Rte_Write_HaLFTrqOvCmdRqst_MtrNm_f32(Float data)
 *   Std_ReturnType Rte_Write_HalfTrqOvRvrsGearEngage_Cnt_lgc(Boolean data)
 *   Std_ReturnType Rte_Write_IWSSCalcVspd_Kph_f32(Float data)
 *   Std_ReturnType Rte_Write_NET_CFG_STAT_PT_Cnt_u16(UInt16 data)
 *   Std_ReturnType Rte_Write_ODO_HwNmSq_f32(Float data)
 *   Std_ReturnType Rte_Write_PAEnableRqst_Cnt_lgc(Boolean data)
 *   Std_ReturnType Rte_Write_PAErrInterfaceActive_Cnt_lgc(Boolean data)
 *   Std_ReturnType Rte_Write_PAExtSystemFltActive_Cnt_lgc(Boolean data)
 *   Std_ReturnType Rte_Write_PAIntSystemFltActive_Cnt_lgc(Boolean data)
 *   Std_ReturnType Rte_Write_PAManoeuvrePhase_Cnt_u08(UInt8 data)
 *   Std_ReturnType Rte_Write_PATrqOvCmdRqst_HwNm_f32(Float data)
 *   Std_ReturnType Rte_Write_PAWheelCriteriaMet_Cnt_lgc(Boolean data)
 *   Std_ReturnType Rte_Write_PAWhlDirRLStat_Cnt_u08(UInt8 data)
 *   Std_ReturnType Rte_Write_PAWhlDirRRStat_Cnt_u08(UInt8 data)
 *   Std_ReturnType Rte_Write_PAWhlPlsCntRLValid_Cnt_lgc(Boolean data)
 *   Std_ReturnType Rte_Write_PAWhlPlsCntRRValid_Cnt_lgc(Boolean data)
 *   Std_ReturnType Rte_Write_PrkAsstFuncPresent_Cnt_lgc(Boolean data)
 *   Std_ReturnType Rte_Write_SpStPrsnt_Cnt_lgc(Boolean data)
 *   Std_ReturnType Rte_Write_SrlComLWhlSpd_Hz_f32(Float data)
 *   Std_ReturnType Rte_Write_SrlComLWhlSpdVld_Cnt_lgc(Boolean data)
 *   Std_ReturnType Rte_Write_SrlComRWhlSpd_Hz_f32(Float data)
 *   Std_ReturnType Rte_Write_SrlComRWhlSpdVld_Cnt_lgc(Boolean data)
 *   Std_ReturnType Rte_Write_SrlComVehSpd_Kph_f32(Float data)
 *   Std_ReturnType Rte_Write_SrlComVehSpdValid_Cnt_lgc(Boolean data)
 *   Std_ReturnType Rte_Write_StrgWhlAngl_HwDeg_f32(Float data)
 *   Std_ReturnType Rte_Write_StrgWhlAnglValid_Cnt_lgc(Boolean data)
 *   Std_ReturnType Rte_Write_TrqOvReverseGearEngage_Cnt_lgc(Boolean data)
 *   Std_ReturnType Rte_Write_VCBodyStyle_Cnt_u08(UInt8 data)
 *   Std_ReturnType Rte_Write_VCCountry_Cnt_u08(UInt8 data)
 *   Std_ReturnType Rte_Write_VCModelYear_Cnt_u08(UInt8 data)
 *   Std_ReturnType Rte_Write_VCVehLine_Cnt_u08(UInt8 data)
 *   Std_ReturnType Rte_Write_VehAccel_KphpS_f32(Float data)
 *   Std_ReturnType Rte_Write_VehAccelX_KphpS_f32(Float data)
 *
 * Mode Interfaces:
 * ================
 *   Rte_ModeType_StaMd_Mode Rte_Mode_SystemState_Mode(void)
 *   Modes of Rte_ModeType_StaMd_Mode:
 *   - RTE_MODE_StaMd_Mode_DISABLE
 *   - RTE_MODE_StaMd_Mode_OFF
 *   - RTE_MODE_StaMd_Mode_OPERATE
 *   - RTE_MODE_StaMd_Mode_WARMINIT
 *   - RTE_TRANSITION_StaMd_Mode
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_NxtrDiagMgr_GetNTCFailed(NTCNumber NTC_Cnt_T_enum, Boolean *NTCFailed_Ptr_T_lgc)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NxtrDiagMgr_E_NOT_OK
 *   Std_ReturnType Rte_Call_NxtrDiagMgr_GetNTCStatus(NTCNumber NTC_Cnt_T_enum, UInt8 *Status_Ptr_T_u08)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NxtrDiagMgr_E_NOT_OK
 *   Std_ReturnType Rte_Call_NxtrDiagMgr_SetNTCStatus(NTCNumber NTC_Cnt_T_enum, UInt8 Param_Cnt_T_u08, NxtrDiagMgrStatus Status_Cnt_T_enum)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NxtrDiagMgr_E_NOT_OK
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_SystemTime_DtrmnElapsedTime_mS_u16(UInt32 InitialTime, UInt16 *ElapsedTime)
 *     Synchronous Service Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_SystemTime_DtrmnElapsedTime_mS_u32(UInt32 InitialTime, UInt32 *ElapsedTime)
 *     Synchronous Service Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_SystemTime_GetSystemTime_mS_u32(UInt32 *CurrentTime)
 *     Synchronous Service Invocation. Timeout: None
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) SrlComInput_Per1(void);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: SrlComInput_SCom_ManualVehSpd
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <SCom_ManualVehSpd> of PortPrototype <SCom_ManualVehSpd>
 *
 **********************************************************************************************************************
 *
 * Mode Interfaces:
 * ================
 *   Rte_ModeType_StaMd_Mode Rte_Mode_SystemState_Mode(void)
 *   Modes of Rte_ModeType_StaMd_Mode:
 *   - RTE_MODE_StaMd_Mode_DISABLE
 *   - RTE_MODE_StaMd_Mode_OFF
 *   - RTE_MODE_StaMd_Mode_OPERATE
 *   - RTE_MODE_StaMd_Mode_WARMINIT
 *   - RTE_TRANSITION_StaMd_Mode
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void SrlComInput_SCom_ManualVehSpd(Float VehSpd_Kph_f32)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) SrlComInput_SCom_ManualVehSpd(Float VehSpd_Kph_f32);

# define RTE_STOP_SEC_AP_SRLCOMINPUT_APPL_CODE
# include "MemMap.h"


/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

# define RTE_E_NxtrDiagMgr_E_NOT_OK (1U)

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

/* begin Fileversion check */
# ifndef SKIP_MAGIC_NUMBER
#  ifdef RTE_MAGIC_NUMBER
#   if RTE_MAGIC_NUMBER != 1390590196
#    error "The magic number of the generated file <C:/Users/sz1dx6/Documents/Synergy/ccm_wa/sz1dx62/sz1dx61/Chrysler_LWR_EPS_TMS570/SwProject/SrlComInput/utp/contract/Ap_SrlComInput/Ap_SrlComInput/Rte_Ap_SrlComInput.h> is different. Please check time and date of the generated RTE files!"
#   endif
#  else
#   define RTE_MAGIC_NUMBER 1390590196
#  endif  /* RTE_MAGIC_NUMBER */
# endif  /* SKIP_MAGIC_NUMBER */
/* end Fileversion check */

#endif /* _RTE_AP_SRLCOMINPUT_H */
