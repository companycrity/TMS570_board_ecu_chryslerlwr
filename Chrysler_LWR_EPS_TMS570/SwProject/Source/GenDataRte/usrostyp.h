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
 *          File:  usrostyp.h
 *     Workspace:  C:/Sankar/Chrysler/Synergy/CL/Temp_work/Chrysler_LWR_EPS_TMS570/Tools/AsrProject/Config/DCF/EPS.dcf
 *   ECU-Project:  EPS
 *  Generated at:  Mon Jul 18 14:56:55 2016
 *
 *     Generator:  MICROSAR RTE Generator Version 2.19.1
 *       License:  License CBD1010124 valid for CBD1010124 Nexteer  Package: BMW MSR SIP BAC3.0     Micro: TI TMS570 TMS570LS30306  Compiler: Code Composer Studio 4.9.0
 *
 *   Description:  User Types header file (osCAN specific)
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _USROSTYP_H
# define _USROSTYP_H

# include "Rte_Type.h"

# define RTE_START_SEC_CODE
# include "MemMap.h"

FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Ap_ActivePull_SystemTime_DtrmnElapsedTime_mS_u32(UInt32 InitialTime, UInt32 *ElapsedTime);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Ap_ActivePull_SystemTime_GetSystemTime_mS_u32(UInt32 *CurrentTime);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Ap_ArbLmt_ArbLmt_Per1_CP1_CheckpointReached(void);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Ap_Assist_FltInjection_SCom_FltInjection(Float *SignalPath_Uls_f32, FltInjectionLocType LocationKey_Cnt_enum);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Ap_AstLmt_SteeringAsstDefeat_WriteBlock(const NvM_DestPtr *DstPtr);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Ap_AvgFricLrn_SystemTime_DtrmnElapsedTime_mS_u32(UInt32 InitialTime, UInt32 *ElapsedTime);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Ap_AvgFricLrn_SystemTime_GetSystemTime_mS_u32(UInt32 *CurrentTime);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Ap_BVDiag_SystemTime_DtrmnElapsedTime_mS_u16(UInt32 InitialTime, UInt16 *ElapsedTime);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Ap_BVDiag_SystemTime_GetSystemTime_mS_u32(UInt32 *CurrentTime);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Ap_CurrParamComp_EOLNomMtrParamBlk_WriteBlock(const NvM_DestPtr *DstPtr);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Ap_Damping_FltInjection_SCom_FltInjection(Float *SignalPath_Uls_f32, FltInjectionLocType LocationKey_Cnt_enum);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Ap_FrqDepDmpnInrtCmp_FltInjection_SCom_FltInjection(Float *SignalPath_Uls_f32, FltInjectionLocType LocationKey_Cnt_enum);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Ap_HaLFTO_HaLFState_SCom_Transition(UInt8 State_Cnt_T_u08);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Ap_HystComp_FltInjection_SCom_FltInjection(Float *SignalPath_Uls_f32, FltInjectionLocType LocationKey_Cnt_enum);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Ap_LrnEOT_SystemTime_DtrmnElapsedTime_mS_u16(UInt32 InitialTime, UInt16 *ElapsedTime);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Ap_LrnEOT_SystemTime_GetSystemTime_mS_u32(UInt32 *CurrentTime);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Ap_PAwTO_PAwTO_Per2_CP1_CheckpointReached(void);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Ap_PAwTO_PrkAssistState_SCom_Transition(UInt8 State_Cnt_T_u08);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Ap_Polarity_Polarity_WriteBlock(const NvM_DestPtr *DstPtr);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Ap_Return_FltInjection_SCom_FltInjection(Float *SignalPath_Uls_f32, FltInjectionLocType LocationKey_Cnt_enum);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Ap_SignlCondn_FaultInjection_SCom_FltInjection(Float *SignalPath_Uls_f32, FltInjectionLocType LocationKey_Cnt_enum);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Ap_SrlComInput_SystemTime_DtrmnElapsedTime_mS_u16(UInt32 InitialTime, UInt16 *ElapsedTime);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Ap_SrlComInput_SystemTime_DtrmnElapsedTime_mS_u32(UInt32 InitialTime, UInt32 *ElapsedTime);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Ap_SrlComInput_SystemTime_GetSystemTime_mS_u32(UInt32 *CurrentTime);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Ap_SrlComOutput_SystemTime_DtrmnElapsedTime_mS_u32(UInt32 InitialTime, UInt32 *ElapsedTime);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Ap_SrlComOutput_SystemTime_GetSystemTime_mS_u32(UInt32 *CurrentTime);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Ap_StaMd_CloseCheckData_GetErrorStatus(NvM_RequestResultType *ErrorStatus);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Ap_StaMd_CloseCheckData_WriteBlock(const NvM_DestPtr *DstPtr);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Ap_StaMd_StaMd_Per1_CP1_CheckpointReached(void);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Ap_StaMd_TOD_OP_SET(IoHwAb_BoolType signal);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Ap_StaMd_TypeHData_WriteBlock(const NvM_DestPtr *DstPtr);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Ap_StabilityComp_FaultInjection_SCom_FltInjection(Float *SignalPath_Uls_f32, FltInjectionLocType LocationKey_Cnt_enum);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Ap_TrqCanc_EOLCogTrqCanc_WriteBlock(const NvM_DestPtr *DstPtr);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Ap_TrqCanc_EOLCogTrqRplComp_WriteBlock(const NvM_DestPtr *DstPtr);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Ap_TrqCmdScl_TrqCmdScl_WriteBlock(const NvM_DestPtr *DstPtr);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Ap_TuningSelAuth_TuningSelAuth_Per1_CP0_CheckpointReached(void);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Cd_uDiag_uDiagLossOfExec_Per3_CP0_CheckpointReached(void);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Cd_uDiag_uDiagStaticRegs_Per_CP1_CheckpointReached(void);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_NtWrap_C_StaMd_SCom_EcuReset(void);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Sa_BkCpPc_SystemTime_DtrmnElapsedTime_mS_u16(UInt32 InitialTime, UInt16 *ElapsedTime);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Sa_BkCpPc_SystemTime_GetSystemTime_mS_u32(UInt32 *CurrentTime);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Sa_CDDInterface_CDDPorts_ApplyMtrElecMechPol(SInt8 MtrElecMechPol_Cnt_s8);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Sa_CDDInterface_CDDPorts_ClearPhsReasSum(UInt16 DataAccessBfr_Cnt_T_u16);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Sa_CmMtrCurr_EOLCurrTempOffset_WriteBlock(const NvM_DestPtr *DstPtr);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Sa_CmMtrCurr_EOLShCurrCal_SetRamBlockStatus(Boolean RamBlockStatus);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Sa_CmMtrCurr_EOLShCurrCal_WriteBlock(const NvM_DestPtr *DstPtr);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Sa_HwTrq2_HwTrq2_Per3_CP0_CheckpointReached(void);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Sa_HwTrq_EOLTrqStep_WriteBlock(const NvM_DestPtr *DstPtr);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Sa_HwTrq_HwTrqScale_WriteBlock(const NvM_DestPtr *DstPtr);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Sa_HwTrq_HwTrqTrim_GetErrorStatus(NvM_RequestResultType *ErrorStatus);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Sa_HwTrq_HwTrqTrim_WriteBlock(const NvM_DestPtr *DstPtr);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Sa_HwTrq_HwTrq_Per3_CP0_CheckpointReached(void);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Sa_MtrDrvDiag_FetDrvReset_OP_SET(IoHwAb_BoolType signal);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Sa_MtrDrvDiag_FetFlt1Data_OP_GET(IoHwAb_BoolType *signal);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Sa_MtrDrvDiag_FetFlt2Clk_OP_GET(IoHwAb_BoolType *signal);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Sa_MtrDrvDiag_FetFlt2Clk_OP_SET(IoHwAb_BoolType signal);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Sa_MtrDrvDiag_IoHwAbPortConfig_SetFetFlt2ToOutput(IoHwAb_BoolType signal);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Sa_MtrPos3_MtrPos3_Per2_CP1_CheckpointReached(void);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Sa_MtrPos_EOLMtrCals_WriteBlock(const NvM_DestPtr *DstPtr);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Sa_MtrVel2_MtrVel2_Per1_CP0_CheckpointReached(void);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Sa_MtrVel2_MtrVel2_Per2_CP0_CheckpointReached(void);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Sa_MtrVel_MtrVel_Per1_CP0_CheckpointReached(void);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Sa_OvrVoltMon_phyOvrVoltFdbk_OP_GET(IoHwAb_BoolType *signal);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Sa_ShtdnMech_FetDrvReset_OP_GET(IoHwAb_BoolType *signal);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Sa_ShtdnMech_SysFault2_OP_GET(IoHwAb_BoolType *signal);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Sa_ShtdnMech_SysFault3_OP_GET(IoHwAb_BoolType *signal);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Sa_TmprlMon2_TmprlMon2_Per1_CP1_CheckpointReached(void);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Sa_TmprlMon2_WdMonitor_OP_SET(IoHwAb_BoolType signal);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Sa_TmprlMon_FetDrvCntl_OP_GET(IoHwAb_BoolType *signal);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Sa_TmprlMon_PwrSwitchEn_OP_GET(IoHwAb_BoolType *signal);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Sa_TmprlMon_SysFault2_OP_GET(IoHwAb_BoolType *signal);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Sa_TmprlMon_SysFault2_OP_SET(IoHwAb_BoolType signal);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Sa_TmprlMon_SysFault3_OP_GET(IoHwAb_BoolType *signal);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Sa_TmprlMon_SysFault3_OP_SET(IoHwAb_BoolType signal);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Sa_TmprlMon_WdMonitor_OP_SET(IoHwAb_BoolType signal);
FUNC(Std_ReturnType, RTE_CODE) Rte_TrustedCall_Sa_TmprlMon_WdReset_OP_SET(IoHwAb_BoolType signal);

# define RTE_STOP_SEC_CODE
# include "MemMap.h"

/* begin Fileversion check */
# ifndef SKIP_MAGIC_NUMBER
#  ifdef RTE_MAGIC_NUMBER
#   if RTE_MAGIC_NUMBER != 1468867288
#    error "The magic number of the generated file <C:/Sankar/Chrysler/Synergy/CL/Temp_work/Chrysler_LWR_EPS_TMS570/SwProject/Source/GenDataRte/usrostyp.h> is different. Please check time and date of the generated RTE files!"
#   endif
#  else
#   define RTE_MAGIC_NUMBER 1468867288
#  endif  /* RTE_MAGIC_NUMBER */
# endif  /* SKIP_MAGIC_NUMBER */
/* end Fileversion check */

#endif /* _USROSTYP_H */
