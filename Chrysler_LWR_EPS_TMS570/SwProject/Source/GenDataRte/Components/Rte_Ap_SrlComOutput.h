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
 *          File:  Components/Rte_Ap_SrlComOutput.h
 *     Workspace:  C:/Sankar/Chrysler/Synergy/CL/Temp_work/Chrysler_LWR_EPS_TMS570/Tools/AsrProject/Config/DCF/EPS.dcf
 *   ECU-Project:  EPS
 *  Generated at:  Mon Jul 18 14:56:54 2016
 *
 *     Generator:  MICROSAR RTE Generator Version 2.19.1
 *       License:  License CBD1010124 valid for CBD1010124 Nexteer  Package: BMW MSR SIP BAC3.0     Micro: TI TMS570 TMS570LS30306  Compiler: Code Composer Studio 4.9.0
 *
 *   Description:  Application header file for SW-C
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_AP_SRLCOMOUTPUT_H
# define _RTE_AP_SRLCOMOUTPUT_H

# ifndef RTE_CORE
#  ifdef RTE_APPLICATION_HEADER_FILE
#   error Multiple application header files included.
#  endif
#  define RTE_APPLICATION_HEADER_FILE
# endif

# ifdef __cplusplus
extern "C"
{
# endif /* __cplusplus */

/* include files */

# include "Rte_Type.h"

# ifndef RTE_CORE

#  define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#  include "MemMap.h"

/************************************************************************/
/* extern declaration of RTE buffers for optimized macro implementation */
/************************************************************************/
extern VAR(Boolean, RTE_VAR_INIT) Rte_VehPwrMd_ATermActive_Cnt_lgc;
extern VAR(UInt8, RTE_VAR_INIT) Rte_Ap_ArbLmt_ActiveFunctionBits_Cnt_u08;
extern VAR(UInt16, RTE_VAR_INIT) Rte_Ap_TuningSelAuth_ActiveTunSet_Cnt_u16;
extern VAR(Float, RTE_VAR_INIT) Rte_CtrldDisShtdn_CntDisMtrTrqCmdCRF_MtrNm_f32;
extern VAR(Boolean, RTE_VAR_INIT) Rte_VehPwrMd_CTermActive_Cnt_lgc;
extern VAR(Boolean, RTE_VAR_INIT) Rte_SrlComInput_CanMsgReceived_Cnt_lgc;
extern VAR(Boolean, RTE_VAR_INIT) Rte_SrlComInput_DSTEOLDisable_Cnt_lgc;
extern VAR(Boolean, RTE_VAR_INIT) Rte_SrlComInput_DSTExtSystemFltActive_Cnt_lgc;
extern VAR(UInt8, RTE_VAR_INIT) Rte_Ap_StbCTO_DSTState_Cnt_u08;
extern VAR(UInt16, RTE_VAR_INIT) Rte_SrlComInput_DesiredTunPers_Cnt_u16;
extern VAR(UInt8, RTE_VAR_INIT) Rte_SrlComInput_DesiredTunPersTypH_Cnt_u08;
extern VAR(Boolean, RTE_VAR_INIT) Rte_DiagMgr_DiagStsNonRecRmpToZeroFltPres_Cnt_lgc;
extern VAR(Boolean, RTE_VAR_INIT) Rte_DiagMgr_DiagStsRecRmpToZeroFltPres_Cnt_lgc;
extern VAR(UInt16, RTE_VAR_INIT) Rte_SrlComInput_EngRPM_Cnt_u16;
extern VAR(UInt8, RTE_VAR_INIT) Rte_Ap_HaLFTO_HaLFState_Cnt_u08;
extern VAR(Boolean, RTE_VAR_INIT) Rte_Ap_HaLFTO_HaLFSuspend_Cnt_lgc;
extern VAR(Boolean, RTE_VAR_INIT) Rte_Ap_PAwTO_HandsOnDetect_Cnt_lgc;
extern VAR(Float, RTE_VAR_INIT) Rte_HwTrq_AnaHwTorque_HwNm_f32;
extern VAR(Float, RTE_VAR_INIT) Rte_StOpCtrl_OutputRampMult_Uls_f32;
extern VAR(UInt8, RTE_VAR_INIT) Rte_Ap_PAwTO_PrkAssistState_Cnt_u08;
extern VAR(Boolean, RTE_VAR_INIT) Rte_Ap_PAwTO_PrkAssistSuspend_Cnt_lgc;
extern VAR(Boolean, RTE_VAR_INIT) Rte_StOpCtrl_RampDwnStatusComplete_Cnt_lgc;
extern VAR(Boolean, RTE_VAR_INIT) Rte_SrlComInput_SpStPrsnt_Cnt_lgc;
extern VAR(Boolean, RTE_VAR_INIT) Rte_HwTrq_SrlComHwTrqValid_Cnt_lgc;
extern VAR(Boolean, RTE_VAR_INIT) Rte_SrlComInput_SrlComVehSpdValid_Cnt_lgc;
extern VAR(Float, RTE_VAR_INIT) Rte_Ap_AstLmt_SumLimTrqCmd_MtrNm_f32;
extern VAR(Float, RTE_VAR_INIT) Rte_Ap_ElePwr_SupplyCurrent_Amp_f32;
extern VAR(Float, RTE_VAR_INIT) Rte_Ap_SignlCondn_VehicleSpeed_Kph_f32;

#  define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#  include "MemMap.h"

# endif /* !defined(RTE_CORE) */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

#  define Rte_InitValue_ATermActive_Cnt_lgc (TRUE)
#  define Rte_InitValue_ActiveFunctionBits_Cnt_u08 (0U)
#  define Rte_InitValue_ActiveTunSet_Cnt_u16 (0U)
#  define Rte_InitValue_CFG_STAT_RQ_Cnt_u08 (0U)
#  define Rte_InitValue_CRFMtrTrqCmd_MtrNm_f32 (0.0F)
#  define Rte_InitValue_CTermActive_Cnt_lgc (FALSE)
#  define Rte_InitValue_CanMsgReceived_Cnt_lgc (FALSE)
#  define Rte_InitValue_DSTEOLDisable_Cnt_lgc (FALSE)
#  define Rte_InitValue_DSTExtSystemFltActive_Cnt_lgc (FALSE)
#  define Rte_InitValue_DSTState_Cnt_u08 (0U)
#  define Rte_InitValue_DesiredTunPers_Cnt_u16 (0U)
#  define Rte_InitValue_DesiredTunPersTypH_Cnt_u08 (0U)
#  define Rte_InitValue_DiagStsNonRecRmpToZeroFltPres_Cnt_lgc (FALSE)
#  define Rte_InitValue_DiagStsRecRmpToZeroFltPres_Cnt_lgc (FALSE)
#  define Rte_InitValue_EPS_MODE_REQ_Cnt_u08 (0U)
#  define Rte_InitValue_EngRPM_Cnt_u16 (1U)
#  define Rte_InitValue_HaLFState_Cnt_u08 (0U)
#  define Rte_InitValue_HaLFSuspend_Cnt_lgc (FALSE)
#  define Rte_InitValue_HandsOnDetect_Cnt_lgc (FALSE)
#  define Rte_InitValue_HwTrq_HwNm_f32 (0.0F)
#  define Rte_InitValue_OutputRampMult_Uls_f32 (0.0F)
#  define Rte_InitValue_PrkAssistState_Cnt_u08 (0U)
#  define Rte_InitValue_PrkAssistSuspend_Cnt_lgc (FALSE)
#  define Rte_InitValue_RampDwnStatusComplete_Cnt_lgc (FALSE)
#  define Rte_InitValue_SpStPrsnt_Cnt_lgc (FALSE)
#  define Rte_InitValue_SrlComHwTrqValid_Cnt_lgc (FALSE)
#  define Rte_InitValue_SrlComVehSpdValid_Cnt_lgc (FALSE)
#  define Rte_InitValue_SumLmtTrqCmd_MtrNm_f32 (0.0F)
#  define Rte_InitValue_SupplyCurrent_Amp_f32 (0.0F)
#  define Rte_InitValue_VehicleSpeed_Kph_f32 (0.0F)
# endif


# ifndef RTE_CORE
#  define RTE_START_SEC_VAR_NOINIT_UNSPECIFIED
#  include "MemMap.h"

/**********************************************************************************************************************
 * Buffers for Mode Management
 *********************************************************************************************************************/
extern VAR(Rte_ModeType_StaMd_Mode, RTE_VAR_NOINIT) Rte_ModeMachine_Ap_StaMd9_SystemState9_Mode;

#  define RTE_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#  include "MemMap.h"
# endif /* !defined(RTE_CORE) */



# define RTE_START_SEC_CODE
# include "MemMap.h"

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/

# define RTE_STOP_SEC_CODE
# include "MemMap.h"


# ifndef RTE_CORE

/**********************************************************************************************************************
 * Rte_Read_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Read_ATermActive_Cnt_lgc Rte_Read_Ap_SrlComOutput_ATermActive_Cnt_lgc
#  define Rte_Read_Ap_SrlComOutput_ATermActive_Cnt_lgc(data) (*(data) = Rte_VehPwrMd_ATermActive_Cnt_lgc, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_ActiveFunctionBits_Cnt_u08 Rte_Read_Ap_SrlComOutput_ActiveFunctionBits_Cnt_u08
#  define Rte_Read_Ap_SrlComOutput_ActiveFunctionBits_Cnt_u08(data) (*(data) = Rte_Ap_ArbLmt_ActiveFunctionBits_Cnt_u08, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_ActiveTunSet_Cnt_u16 Rte_Read_Ap_SrlComOutput_ActiveTunSet_Cnt_u16
#  define Rte_Read_Ap_SrlComOutput_ActiveTunSet_Cnt_u16(data) (*(data) = Rte_Ap_TuningSelAuth_ActiveTunSet_Cnt_u16, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_CRFMtrTrqCmd_MtrNm_f32 Rte_Read_Ap_SrlComOutput_CRFMtrTrqCmd_MtrNm_f32
#  define Rte_Read_Ap_SrlComOutput_CRFMtrTrqCmd_MtrNm_f32(data) (*(data) = Rte_CtrldDisShtdn_CntDisMtrTrqCmdCRF_MtrNm_f32, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_CTermActive_Cnt_lgc Rte_Read_Ap_SrlComOutput_CTermActive_Cnt_lgc
#  define Rte_Read_Ap_SrlComOutput_CTermActive_Cnt_lgc(data) (*(data) = Rte_VehPwrMd_CTermActive_Cnt_lgc, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_CanMsgReceived_Cnt_lgc Rte_Read_Ap_SrlComOutput_CanMsgReceived_Cnt_lgc
#  define Rte_Read_Ap_SrlComOutput_CanMsgReceived_Cnt_lgc(data) (*(data) = Rte_SrlComInput_CanMsgReceived_Cnt_lgc, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_DSTEOLDisable_Cnt_lgc Rte_Read_Ap_SrlComOutput_DSTEOLDisable_Cnt_lgc
#  define Rte_Read_Ap_SrlComOutput_DSTEOLDisable_Cnt_lgc(data) (*(data) = Rte_SrlComInput_DSTEOLDisable_Cnt_lgc, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_DSTExtSystemFltActive_Cnt_lgc Rte_Read_Ap_SrlComOutput_DSTExtSystemFltActive_Cnt_lgc
#  define Rte_Read_Ap_SrlComOutput_DSTExtSystemFltActive_Cnt_lgc(data) (*(data) = Rte_SrlComInput_DSTExtSystemFltActive_Cnt_lgc, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_DSTState_Cnt_u08 Rte_Read_Ap_SrlComOutput_DSTState_Cnt_u08
#  define Rte_Read_Ap_SrlComOutput_DSTState_Cnt_u08(data) (*(data) = Rte_Ap_StbCTO_DSTState_Cnt_u08, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_DesiredTunPers_Cnt_u16 Rte_Read_Ap_SrlComOutput_DesiredTunPers_Cnt_u16
#  define Rte_Read_Ap_SrlComOutput_DesiredTunPers_Cnt_u16(data) (*(data) = Rte_SrlComInput_DesiredTunPers_Cnt_u16, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_DesiredTunPersTypH_Cnt_u08 Rte_Read_Ap_SrlComOutput_DesiredTunPersTypH_Cnt_u08
#  define Rte_Read_Ap_SrlComOutput_DesiredTunPersTypH_Cnt_u08(data) (*(data) = Rte_SrlComInput_DesiredTunPersTypH_Cnt_u08, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_DiagStsNonRecRmpToZeroFltPres_Cnt_lgc Rte_Read_Ap_SrlComOutput_DiagStsNonRecRmpToZeroFltPres_Cnt_lgc
#  define Rte_Read_Ap_SrlComOutput_DiagStsNonRecRmpToZeroFltPres_Cnt_lgc(data) (*(data) = Rte_DiagMgr_DiagStsNonRecRmpToZeroFltPres_Cnt_lgc, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_DiagStsRecRmpToZeroFltPres_Cnt_lgc Rte_Read_Ap_SrlComOutput_DiagStsRecRmpToZeroFltPres_Cnt_lgc
#  define Rte_Read_Ap_SrlComOutput_DiagStsRecRmpToZeroFltPres_Cnt_lgc(data) (*(data) = Rte_DiagMgr_DiagStsRecRmpToZeroFltPres_Cnt_lgc, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_EngRPM_Cnt_u16 Rte_Read_Ap_SrlComOutput_EngRPM_Cnt_u16
#  define Rte_Read_Ap_SrlComOutput_EngRPM_Cnt_u16(data) (*(data) = Rte_SrlComInput_EngRPM_Cnt_u16, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_HaLFState_Cnt_u08 Rte_Read_Ap_SrlComOutput_HaLFState_Cnt_u08
#  define Rte_Read_Ap_SrlComOutput_HaLFState_Cnt_u08(data) (*(data) = Rte_Ap_HaLFTO_HaLFState_Cnt_u08, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_HaLFSuspend_Cnt_lgc Rte_Read_Ap_SrlComOutput_HaLFSuspend_Cnt_lgc
#  define Rte_Read_Ap_SrlComOutput_HaLFSuspend_Cnt_lgc(data) (*(data) = Rte_Ap_HaLFTO_HaLFSuspend_Cnt_lgc, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_HandsOnDetect_Cnt_lgc Rte_Read_Ap_SrlComOutput_HandsOnDetect_Cnt_lgc
#  define Rte_Read_Ap_SrlComOutput_HandsOnDetect_Cnt_lgc(data) (*(data) = Rte_Ap_PAwTO_HandsOnDetect_Cnt_lgc, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_HwTrq_HwNm_f32 Rte_Read_Ap_SrlComOutput_HwTrq_HwNm_f32
#  define Rte_Read_Ap_SrlComOutput_HwTrq_HwNm_f32(data) (*(data) = Rte_HwTrq_AnaHwTorque_HwNm_f32, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_OutputRampMult_Uls_f32 Rte_Read_Ap_SrlComOutput_OutputRampMult_Uls_f32
#  define Rte_Read_Ap_SrlComOutput_OutputRampMult_Uls_f32(data) (*(data) = Rte_StOpCtrl_OutputRampMult_Uls_f32, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_PrkAssistState_Cnt_u08 Rte_Read_Ap_SrlComOutput_PrkAssistState_Cnt_u08
#  define Rte_Read_Ap_SrlComOutput_PrkAssistState_Cnt_u08(data) (*(data) = Rte_Ap_PAwTO_PrkAssistState_Cnt_u08, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_PrkAssistSuspend_Cnt_lgc Rte_Read_Ap_SrlComOutput_PrkAssistSuspend_Cnt_lgc
#  define Rte_Read_Ap_SrlComOutput_PrkAssistSuspend_Cnt_lgc(data) (*(data) = Rte_Ap_PAwTO_PrkAssistSuspend_Cnt_lgc, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_RampDwnStatusComplete_Cnt_lgc Rte_Read_Ap_SrlComOutput_RampDwnStatusComplete_Cnt_lgc
#  define Rte_Read_Ap_SrlComOutput_RampDwnStatusComplete_Cnt_lgc(data) (*(data) = Rte_StOpCtrl_RampDwnStatusComplete_Cnt_lgc, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_SpStPrsnt_Cnt_lgc Rte_Read_Ap_SrlComOutput_SpStPrsnt_Cnt_lgc
#  define Rte_Read_Ap_SrlComOutput_SpStPrsnt_Cnt_lgc(data) (*(data) = Rte_SrlComInput_SpStPrsnt_Cnt_lgc, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_SrlComHwTrqValid_Cnt_lgc Rte_Read_Ap_SrlComOutput_SrlComHwTrqValid_Cnt_lgc
#  define Rte_Read_Ap_SrlComOutput_SrlComHwTrqValid_Cnt_lgc(data) (*(data) = Rte_HwTrq_SrlComHwTrqValid_Cnt_lgc, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_SrlComVehSpdValid_Cnt_lgc Rte_Read_Ap_SrlComOutput_SrlComVehSpdValid_Cnt_lgc
#  define Rte_Read_Ap_SrlComOutput_SrlComVehSpdValid_Cnt_lgc(data) (*(data) = Rte_SrlComInput_SrlComVehSpdValid_Cnt_lgc, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_SumLmtTrqCmd_MtrNm_f32 Rte_Read_Ap_SrlComOutput_SumLmtTrqCmd_MtrNm_f32
#  define Rte_Read_Ap_SrlComOutput_SumLmtTrqCmd_MtrNm_f32(data) (*(data) = Rte_Ap_AstLmt_SumLimTrqCmd_MtrNm_f32, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_SupplyCurrent_Amp_f32 Rte_Read_Ap_SrlComOutput_SupplyCurrent_Amp_f32
#  define Rte_Read_Ap_SrlComOutput_SupplyCurrent_Amp_f32(data) (*(data) = Rte_Ap_ElePwr_SupplyCurrent_Amp_f32, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_VehicleSpeed_Kph_f32 Rte_Read_Ap_SrlComOutput_VehicleSpeed_Kph_f32
#  define Rte_Read_Ap_SrlComOutput_VehicleSpeed_Kph_f32(data) (*(data) = Rte_Ap_SignlCondn_VehicleSpeed_Kph_f32, ((Std_ReturnType)RTE_E_OK))


/**********************************************************************************************************************
 * Rte_Mode_<p>_<m>
 *********************************************************************************************************************/
#  define Rte_Mode_SystemState_Mode() Rte_ModeMachine_Ap_StaMd9_SystemState9_Mode


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (unmapped) for synchronous C/S communication
 *********************************************************************************************************************/
#  define RTE_START_SEC_AP_DIAGMGR9_APPL_CODE
#  include "MemMap.h"
FUNC(Std_ReturnType, RTE_AP_DIAGMGR9_APPL_CODE) NxtrDiagMgr9_GetNTCFailed(NTCNumber NTC_Cnt_T_enum, P2VAR(Boolean, AUTOMATIC, RTE_AP_DIAGMGR9_APPL_VAR) NTCFailed_Ptr_T_lgc);
#  define RTE_STOP_SEC_AP_DIAGMGR9_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_NxtrDiagMgr_GetNTCFailed NxtrDiagMgr9_GetNTCFailed
#  define RTE_START_SEC_NEXTEERLIBS_APPL_CODE
#  include "MemMap.h"
FUNC(void, RTE_NEXTEERLIBS_APPL_CODE) DtrmnElapsedTime_mS_u32(UInt32 InitialTime, P2VAR(UInt32, AUTOMATIC, RTE_NEXTEERLIBS_APPL_VAR) ElapsedTime);
#  define RTE_STOP_SEC_NEXTEERLIBS_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_SystemTime_DtrmnElapsedTime_mS_u32(arg1, arg2) (DtrmnElapsedTime_mS_u32(arg1, arg2), ((Std_ReturnType)RTE_E_OK))
#  define RTE_START_SEC_NEXTEERLIBS_APPL_CODE
#  include "MemMap.h"
FUNC(void, RTE_NEXTEERLIBS_APPL_CODE) GetSystemTime_mS_u32(P2VAR(UInt32, AUTOMATIC, RTE_NEXTEERLIBS_APPL_VAR) CurrentTime);
#  define RTE_STOP_SEC_NEXTEERLIBS_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_SystemTime_GetSystemTime_mS_u32(arg1) (GetSystemTime_mS_u32(arg1), ((Std_ReturnType)RTE_E_OK))


# endif /* !defined(RTE_CORE) */


# define RTE_START_SEC_AP_SRLCOMOUTPUT_APPL_CODE
# include "MemMap.h"

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

FUNC(void, RTE_AP_SRLCOMOUTPUT_APPL_CODE) SrlComOutput_Init1(void);

FUNC(void, RTE_AP_SRLCOMOUTPUT_APPL_CODE) SrlComOutput_Per1(void);

# define RTE_STOP_SEC_AP_SRLCOMOUTPUT_APPL_CODE
# include "MemMap.h"


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

#  define RTE_E_NxtrDiagMgr_E_NOT_OK (1U)
# endif /* !defined(RTE_CORE) */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

/* begin Fileversion check */
# ifndef SKIP_MAGIC_NUMBER
#  ifdef RTE_MAGIC_NUMBER
#   if RTE_MAGIC_NUMBER != 1468867288
#    error "The magic number of the generated file <C:/Sankar/Chrysler/Synergy/CL/Temp_work/Chrysler_LWR_EPS_TMS570/SwProject/Source/GenDataRte/Components/Rte_Ap_SrlComOutput.h> is different. Please check time and date of the generated RTE files!"
#   endif
#  else
#   define RTE_MAGIC_NUMBER 1468867288
#  endif  /* RTE_MAGIC_NUMBER */
# endif  /* SKIP_MAGIC_NUMBER */
/* end Fileversion check */

#endif /* _RTE_AP_SRLCOMOUTPUT_H */
