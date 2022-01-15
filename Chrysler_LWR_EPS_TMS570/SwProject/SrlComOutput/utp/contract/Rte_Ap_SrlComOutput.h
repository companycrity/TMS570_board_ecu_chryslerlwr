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
 *          File:  Rte_Ap_SrlComOutput.h
 *     Workspace:  C:/Users/sz1dx6/Documents/Synergy/ccm_wa/L/CL_01.00.04/Chrysler_LWR_EPS_TMS570/SwProject/SrlComOutput/autosar/Ap_SrlComOutput.dcf
 *     SW-C Type:  Ap_SrlComOutput
 *  Generated at:  Mon Nov  4 15:37:25 2013
 *
 *     Generator:  MICROSAR RTE Generator Version 2.19.1
 *       License:  License CBD1010124 valid for CBD1010124 Nexteer  Package: BMW MSR SIP BAC3.0     Micro: TI TMS570 TMS570LS30306  Compiler: Code Composer Studio 4.9.0
 *
 *   Description:  Application header file for SW-C <Ap_SrlComOutput> (Contract Phase)
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_AP_SRLCOMOUTPUT_H
# define _RTE_AP_SRLCOMOUTPUT_H

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

typedef P2CONST(struct Rte_CDS_Ap_SrlComOutput, TYPEDEF, RTE_CONST) Rte_Instance;


/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

# define Rte_InitValue_ATermActive_Cnt_lgc (TRUE)
# define Rte_InitValue_ActiveFunctionBits_Cnt_u08 (0U)
# define Rte_InitValue_ActiveTunSet_Cnt_u16 (0U)
# define Rte_InitValue_CFG_STAT_RQ_Cnt_u16 (0U)
# define Rte_InitValue_CRFMtrTrqCmd_MtrNm_f32 (0.0F)
# define Rte_InitValue_CTermActive_Cnt_lgc (FALSE)
# define Rte_InitValue_CanMsgReceived_Cnt_lgc (FALSE)
# define Rte_InitValue_DSTEOLDisable_Cnt_lgc (FALSE)
# define Rte_InitValue_DSTExtSystemFltActive_Cnt_lgc (FALSE)
# define Rte_InitValue_DSTState_Cnt_u08 (0U)
# define Rte_InitValue_DesiredTunPers_Cnt_u16 (0U)
# define Rte_InitValue_DesiredTunPersTypH_Cnt_u08 (0U)
# define Rte_InitValue_DiagStsNonRecRmpToZeroFltPres_Cnt_lgc (FALSE)
# define Rte_InitValue_DiagStsRecRmpToZeroFltPres_Cnt_lgc (FALSE)
# define Rte_InitValue_EPS_MODE_REQ_Cnt_u16 (0U)
# define Rte_InitValue_EngRPM_Cnt_u16 (1U)
# define Rte_InitValue_HaLFState_Cnt_u08 (0U)
# define Rte_InitValue_HaLFSuspend_Cnt_lgc (FALSE)
# define Rte_InitValue_HandsOnDetect_Cnt_lgc (FALSE)
# define Rte_InitValue_HwTrq_HwNm_f32 (0.0F)
# define Rte_InitValue_OutputRampMult_Uls_f32 (0.0F)
# define Rte_InitValue_PrkAssistState_Cnt_u08 (0U)
# define Rte_InitValue_PrkAssistSuspend_Cnt_lgc (FALSE)
# define Rte_InitValue_RampDwnStatusComplete_Cnt_lgc (FALSE)
# define Rte_InitValue_SpStPrsnt_Cnt_lgc (FALSE)
# define Rte_InitValue_SrlComHwTrqValid_Cnt_lgc (FALSE)
# define Rte_InitValue_SrlComVehSpdValid_Cnt_lgc (FALSE)
# define Rte_InitValue_SumLmtTrqCmd_MtrNm_f32 (0.0F)
# define Rte_InitValue_SupplyCurrent_Amp_f32 (0.0F)
# define Rte_InitValue_VehicleSpeed_Kph_f32 (0.0F)


# define RTE_START_SEC_CODE
# include "MemMap.h"

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ap_SrlComOutput_ATermActive_Cnt_lgc(P2VAR(Boolean, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ap_SrlComOutput_ActiveFunctionBits_Cnt_u08(P2VAR(UInt8, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ap_SrlComOutput_ActiveTunSet_Cnt_u16(P2VAR(UInt16, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ap_SrlComOutput_CFG_STAT_RQ_Cnt_u16(P2VAR(UInt16, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ap_SrlComOutput_CRFMtrTrqCmd_MtrNm_f32(P2VAR(Float, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ap_SrlComOutput_CTermActive_Cnt_lgc(P2VAR(Boolean, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ap_SrlComOutput_CanMsgReceived_Cnt_lgc(P2VAR(Boolean, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ap_SrlComOutput_DSTEOLDisable_Cnt_lgc(P2VAR(Boolean, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ap_SrlComOutput_DSTExtSystemFltActive_Cnt_lgc(P2VAR(Boolean, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ap_SrlComOutput_DSTState_Cnt_u08(P2VAR(UInt8, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ap_SrlComOutput_DesiredTunPers_Cnt_u16(P2VAR(UInt16, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ap_SrlComOutput_DesiredTunPersTypH_Cnt_u08(P2VAR(UInt8, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ap_SrlComOutput_DiagStsNonRecRmpToZeroFltPres_Cnt_lgc(P2VAR(Boolean, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ap_SrlComOutput_DiagStsRecRmpToZeroFltPres_Cnt_lgc(P2VAR(Boolean, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ap_SrlComOutput_EPS_MODE_REQ_Cnt_u16(P2VAR(UInt16, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ap_SrlComOutput_EngRPM_Cnt_u16(P2VAR(UInt16, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ap_SrlComOutput_HaLFState_Cnt_u08(P2VAR(UInt8, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ap_SrlComOutput_HaLFSuspend_Cnt_lgc(P2VAR(Boolean, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ap_SrlComOutput_HandsOnDetect_Cnt_lgc(P2VAR(Boolean, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ap_SrlComOutput_HwTrq_HwNm_f32(P2VAR(Float, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ap_SrlComOutput_OutputRampMult_Uls_f32(P2VAR(Float, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ap_SrlComOutput_PrkAssistState_Cnt_u08(P2VAR(UInt8, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ap_SrlComOutput_PrkAssistSuspend_Cnt_lgc(P2VAR(Boolean, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ap_SrlComOutput_RampDwnStatusComplete_Cnt_lgc(P2VAR(Boolean, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ap_SrlComOutput_SpStPrsnt_Cnt_lgc(P2VAR(Boolean, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ap_SrlComOutput_SrlComHwTrqValid_Cnt_lgc(P2VAR(Boolean, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ap_SrlComOutput_SrlComVehSpdValid_Cnt_lgc(P2VAR(Boolean, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ap_SrlComOutput_SumLmtTrqCmd_MtrNm_f32(P2VAR(Float, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ap_SrlComOutput_SupplyCurrent_Amp_f32(P2VAR(Float, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ap_SrlComOutput_VehicleSpeed_Kph_f32(P2VAR(Float, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_VAR) data);
FUNC(Rte_ModeType_StaMd_Mode, RTE_CODE) Rte_Mode_Ap_SrlComOutput_SystemState_Mode(void);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ap_SrlComOutput_NxtrDiagMgr_GetNTCFailed(NTCNumber NTC_Cnt_T_enum, P2VAR(Boolean, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_VAR) NTCFailed_Ptr_T_lgc);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ap_SrlComOutput_SystemTime_DtrmnElapsedTime_mS_u32(UInt32 InitialTime, P2VAR(UInt32, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_VAR) ElapsedTime);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ap_SrlComOutput_SystemTime_GetSystemTime_mS_u32(P2VAR(UInt32, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_VAR) CurrentTime);

# define RTE_STOP_SEC_CODE
# include "MemMap.h"



/**********************************************************************************************************************
 * Rte_Read_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
# define Rte_Read_ATermActive_Cnt_lgc Rte_Read_Ap_SrlComOutput_ATermActive_Cnt_lgc
# define Rte_Read_ActiveFunctionBits_Cnt_u08 Rte_Read_Ap_SrlComOutput_ActiveFunctionBits_Cnt_u08
# define Rte_Read_ActiveTunSet_Cnt_u16 Rte_Read_Ap_SrlComOutput_ActiveTunSet_Cnt_u16
# define Rte_Read_CFG_STAT_RQ_Cnt_u16 Rte_Read_Ap_SrlComOutput_CFG_STAT_RQ_Cnt_u16
# define Rte_Read_CRFMtrTrqCmd_MtrNm_f32 Rte_Read_Ap_SrlComOutput_CRFMtrTrqCmd_MtrNm_f32
# define Rte_Read_CTermActive_Cnt_lgc Rte_Read_Ap_SrlComOutput_CTermActive_Cnt_lgc
# define Rte_Read_CanMsgReceived_Cnt_lgc Rte_Read_Ap_SrlComOutput_CanMsgReceived_Cnt_lgc
# define Rte_Read_DSTEOLDisable_Cnt_lgc Rte_Read_Ap_SrlComOutput_DSTEOLDisable_Cnt_lgc
# define Rte_Read_DSTExtSystemFltActive_Cnt_lgc Rte_Read_Ap_SrlComOutput_DSTExtSystemFltActive_Cnt_lgc
# define Rte_Read_DSTState_Cnt_u08 Rte_Read_Ap_SrlComOutput_DSTState_Cnt_u08
# define Rte_Read_DesiredTunPers_Cnt_u16 Rte_Read_Ap_SrlComOutput_DesiredTunPers_Cnt_u16
# define Rte_Read_DesiredTunPersTypH_Cnt_u08 Rte_Read_Ap_SrlComOutput_DesiredTunPersTypH_Cnt_u08
# define Rte_Read_DiagStsNonRecRmpToZeroFltPres_Cnt_lgc Rte_Read_Ap_SrlComOutput_DiagStsNonRecRmpToZeroFltPres_Cnt_lgc
# define Rte_Read_DiagStsRecRmpToZeroFltPres_Cnt_lgc Rte_Read_Ap_SrlComOutput_DiagStsRecRmpToZeroFltPres_Cnt_lgc
# define Rte_Read_EPS_MODE_REQ_Cnt_u16 Rte_Read_Ap_SrlComOutput_EPS_MODE_REQ_Cnt_u16
# define Rte_Read_EngRPM_Cnt_u16 Rte_Read_Ap_SrlComOutput_EngRPM_Cnt_u16
# define Rte_Read_HaLFState_Cnt_u08 Rte_Read_Ap_SrlComOutput_HaLFState_Cnt_u08
# define Rte_Read_HaLFSuspend_Cnt_lgc Rte_Read_Ap_SrlComOutput_HaLFSuspend_Cnt_lgc
# define Rte_Read_HandsOnDetect_Cnt_lgc Rte_Read_Ap_SrlComOutput_HandsOnDetect_Cnt_lgc
# define Rte_Read_HwTrq_HwNm_f32 Rte_Read_Ap_SrlComOutput_HwTrq_HwNm_f32
# define Rte_Read_OutputRampMult_Uls_f32 Rte_Read_Ap_SrlComOutput_OutputRampMult_Uls_f32
# define Rte_Read_PrkAssistState_Cnt_u08 Rte_Read_Ap_SrlComOutput_PrkAssistState_Cnt_u08
# define Rte_Read_PrkAssistSuspend_Cnt_lgc Rte_Read_Ap_SrlComOutput_PrkAssistSuspend_Cnt_lgc
# define Rte_Read_RampDwnStatusComplete_Cnt_lgc Rte_Read_Ap_SrlComOutput_RampDwnStatusComplete_Cnt_lgc
# define Rte_Read_SpStPrsnt_Cnt_lgc Rte_Read_Ap_SrlComOutput_SpStPrsnt_Cnt_lgc
# define Rte_Read_SrlComHwTrqValid_Cnt_lgc Rte_Read_Ap_SrlComOutput_SrlComHwTrqValid_Cnt_lgc
# define Rte_Read_SrlComVehSpdValid_Cnt_lgc Rte_Read_Ap_SrlComOutput_SrlComVehSpdValid_Cnt_lgc
# define Rte_Read_SumLmtTrqCmd_MtrNm_f32 Rte_Read_Ap_SrlComOutput_SumLmtTrqCmd_MtrNm_f32
# define Rte_Read_SupplyCurrent_Amp_f32 Rte_Read_Ap_SrlComOutput_SupplyCurrent_Amp_f32
# define Rte_Read_VehicleSpeed_Kph_f32 Rte_Read_Ap_SrlComOutput_VehicleSpeed_Kph_f32


/**********************************************************************************************************************
 * Rte_Mode_<p>_<m>
 *********************************************************************************************************************/
# define Rte_Mode_SystemState_Mode Rte_Mode_Ap_SrlComOutput_SystemState_Mode


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (C/S invocation)
 *********************************************************************************************************************/
# define Rte_Call_NxtrDiagMgr_GetNTCFailed Rte_Call_Ap_SrlComOutput_NxtrDiagMgr_GetNTCFailed
# define Rte_Call_SystemTime_DtrmnElapsedTime_mS_u32 Rte_Call_Ap_SrlComOutput_SystemTime_DtrmnElapsedTime_mS_u32
# define Rte_Call_SystemTime_GetSystemTime_mS_u32 Rte_Call_Ap_SrlComOutput_SystemTime_GetSystemTime_mS_u32




# define RTE_START_SEC_AP_SRLCOMOUTPUT_APPL_CODE
# include "MemMap.h"


/**********************************************************************************************************************
 *
 * Runnable Entity Name: SrlComOutput_Init1
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

FUNC(void, RTE_AP_SRLCOMOUTPUT_APPL_CODE) SrlComOutput_Init1(void);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: SrlComOutput_Per1
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
 *   Std_ReturnType Rte_Read_ATermActive_Cnt_lgc(Boolean *data)
 *   Std_ReturnType Rte_Read_ActiveFunctionBits_Cnt_u08(UInt8 *data)
 *   Std_ReturnType Rte_Read_ActiveTunSet_Cnt_u16(UInt16 *data)
 *   Std_ReturnType Rte_Read_CFG_STAT_RQ_Cnt_u16(UInt16 *data)
 *   Std_ReturnType Rte_Read_CRFMtrTrqCmd_MtrNm_f32(Float *data)
 *   Std_ReturnType Rte_Read_CTermActive_Cnt_lgc(Boolean *data)
 *   Std_ReturnType Rte_Read_CanMsgReceived_Cnt_lgc(Boolean *data)
 *   Std_ReturnType Rte_Read_DSTEOLDisable_Cnt_lgc(Boolean *data)
 *   Std_ReturnType Rte_Read_DSTExtSystemFltActive_Cnt_lgc(Boolean *data)
 *   Std_ReturnType Rte_Read_DSTState_Cnt_u08(UInt8 *data)
 *   Std_ReturnType Rte_Read_DesiredTunPers_Cnt_u16(UInt16 *data)
 *   Std_ReturnType Rte_Read_DesiredTunPersTypH_Cnt_u08(UInt8 *data)
 *   Std_ReturnType Rte_Read_DiagStsNonRecRmpToZeroFltPres_Cnt_lgc(Boolean *data)
 *   Std_ReturnType Rte_Read_DiagStsRecRmpToZeroFltPres_Cnt_lgc(Boolean *data)
 *   Std_ReturnType Rte_Read_EPS_MODE_REQ_Cnt_u16(UInt16 *data)
 *   Std_ReturnType Rte_Read_EngRPM_Cnt_u16(UInt16 *data)
 *   Std_ReturnType Rte_Read_HaLFState_Cnt_u08(UInt8 *data)
 *   Std_ReturnType Rte_Read_HaLFSuspend_Cnt_lgc(Boolean *data)
 *   Std_ReturnType Rte_Read_HandsOnDetect_Cnt_lgc(Boolean *data)
 *   Std_ReturnType Rte_Read_HwTrq_HwNm_f32(Float *data)
 *   Std_ReturnType Rte_Read_OutputRampMult_Uls_f32(Float *data)
 *   Std_ReturnType Rte_Read_PrkAssistState_Cnt_u08(UInt8 *data)
 *   Std_ReturnType Rte_Read_PrkAssistSuspend_Cnt_lgc(Boolean *data)
 *   Std_ReturnType Rte_Read_RampDwnStatusComplete_Cnt_lgc(Boolean *data)
 *   Std_ReturnType Rte_Read_SpStPrsnt_Cnt_lgc(Boolean *data)
 *   Std_ReturnType Rte_Read_SrlComHwTrqValid_Cnt_lgc(Boolean *data)
 *   Std_ReturnType Rte_Read_SrlComVehSpdValid_Cnt_lgc(Boolean *data)
 *   Std_ReturnType Rte_Read_SumLmtTrqCmd_MtrNm_f32(Float *data)
 *   Std_ReturnType Rte_Read_SupplyCurrent_Amp_f32(Float *data)
 *   Std_ReturnType Rte_Read_VehicleSpeed_Kph_f32(Float *data)
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
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_SystemTime_DtrmnElapsedTime_mS_u32(UInt32 InitialTime, UInt32 *ElapsedTime)
 *     Synchronous Service Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_SystemTime_GetSystemTime_mS_u32(UInt32 *CurrentTime)
 *     Synchronous Service Invocation. Timeout: None
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_SRLCOMOUTPUT_APPL_CODE) SrlComOutput_Per1(void);

# define RTE_STOP_SEC_AP_SRLCOMOUTPUT_APPL_CODE
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
#   if RTE_MAGIC_NUMBER != 1383596980
#    error "The magic number of the generated file <C:/Users/sz1dx6/Documents/Synergy/ccm_wa/L/CL_01.00.04/Chrysler_LWR_EPS_TMS570/SwProject/SrlComOutput/utp/Ap_SrlComOutput/Rte_Ap_SrlComOutput.h> is different. Please check time and date of the generated RTE files!"
#   endif
#  else
#   define RTE_MAGIC_NUMBER 1383596980
#  endif  /* RTE_MAGIC_NUMBER */
# endif  /* SKIP_MAGIC_NUMBER */
/* end Fileversion check */

#endif /* _RTE_AP_SRLCOMOUTPUT_H */
