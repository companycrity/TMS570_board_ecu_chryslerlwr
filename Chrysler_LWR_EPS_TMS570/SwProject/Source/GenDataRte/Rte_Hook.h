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
 *          File:  Rte_Hook.h
 *     Workspace:  C:/Sankar/Chrysler/Synergy/CL/Temp_work/Chrysler_LWR_EPS_TMS570/Tools/AsrProject/Config/DCF/EPS.dcf
 *   ECU-Project:  EPS
 *  Generated at:  Mon Jul 18 14:56:55 2016
 *
 *     Generator:  MICROSAR RTE Generator Version 2.19.1
 *       License:  License CBD1010124 valid for CBD1010124 Nexteer  Package: BMW MSR SIP BAC3.0     Micro: TI TMS570 TMS570LS30306  Compiler: Code Composer Studio 4.9.0
 *
 *   Description:  Header file containing definitions for VFB tracing
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * Names of available VFB-Trace-Hooks
 **********************************************************************************************************************
 *
 *  Rte_CallHook_Ap_AbsHwPosScom_NxtrDiagMgr_SetNTCStatus_Return
 *  Rte_CallHook_Ap_AbsHwPosScom_NxtrDiagMgr_SetNTCStatus_Start
 *  Rte_CallHook_Ap_AbsHwPosScom_SystemTime_DtrmnElapsedTime_mS_u16_Return
 *  Rte_CallHook_Ap_AbsHwPosScom_SystemTime_DtrmnElapsedTime_mS_u16_Start
 *  Rte_CallHook_Ap_AbsHwPosScom_SystemTime_GetSystemTime_mS_u32_Return
 *  Rte_CallHook_Ap_AbsHwPosScom_SystemTime_GetSystemTime_mS_u32_Start
 *  Rte_CallHook_Ap_ActivePull_SystemTime_DtrmnElapsedTime_mS_u32_Return
 *  Rte_CallHook_Ap_ActivePull_SystemTime_DtrmnElapsedTime_mS_u32_Start
 *  Rte_CallHook_Ap_ActivePull_SystemTime_GetSystemTime_mS_u32_Return
 *  Rte_CallHook_Ap_ActivePull_SystemTime_GetSystemTime_mS_u32_Start
 *  Rte_CallHook_Ap_ArbLmt_ArbLmt_Per1_CP1_CheckpointReached_Return
 *  Rte_CallHook_Ap_ArbLmt_ArbLmt_Per1_CP1_CheckpointReached_Start
 *  Rte_CallHook_Ap_AssistFirewall_NxtrDiagMgr_SetNTCStatus_Return
 *  Rte_CallHook_Ap_AssistFirewall_NxtrDiagMgr_SetNTCStatus_Start
 *  Rte_CallHook_Ap_Assist_FltInjection_SCom_FltInjection_Return
 *  Rte_CallHook_Ap_Assist_FltInjection_SCom_FltInjection_Start
 *  Rte_CallHook_Ap_AvgFricLrn_AvgFricLrnData_WriteBlock_Return
 *  Rte_CallHook_Ap_AvgFricLrn_AvgFricLrnData_WriteBlock_Start
 *  Rte_CallHook_Ap_AvgFricLrn_FltInjection_SCom_FltInjection_Return
 *  Rte_CallHook_Ap_AvgFricLrn_FltInjection_SCom_FltInjection_Start
 *  Rte_CallHook_Ap_AvgFricLrn_NxtrDiagMgr_SetNTCStatus_Return
 *  Rte_CallHook_Ap_AvgFricLrn_NxtrDiagMgr_SetNTCStatus_Start
 *  Rte_CallHook_Ap_AvgFricLrn_SystemTime_DtrmnElapsedTime_mS_u32_Return
 *  Rte_CallHook_Ap_AvgFricLrn_SystemTime_DtrmnElapsedTime_mS_u32_Start
 *  Rte_CallHook_Ap_AvgFricLrn_SystemTime_GetSystemTime_mS_u32_Return
 *  Rte_CallHook_Ap_AvgFricLrn_SystemTime_GetSystemTime_mS_u32_Start
 *  Rte_CallHook_Ap_BVDiag_BVDiag_Per1_CP1_CheckpointReached_Return
 *  Rte_CallHook_Ap_BVDiag_BVDiag_Per1_CP1_CheckpointReached_Start
 *  Rte_CallHook_Ap_BVDiag_NxtrDiagMgr_SetNTCStatus_Return
 *  Rte_CallHook_Ap_BVDiag_NxtrDiagMgr_SetNTCStatus_Start
 *  Rte_CallHook_Ap_BVDiag_SystemTime_DtrmnElapsedTime_mS_u16_Return
 *  Rte_CallHook_Ap_BVDiag_SystemTime_DtrmnElapsedTime_mS_u16_Start
 *  Rte_CallHook_Ap_BVDiag_SystemTime_GetSystemTime_mS_u32_Return
 *  Rte_CallHook_Ap_BVDiag_SystemTime_GetSystemTime_mS_u32_Start
 *  Rte_CallHook_Ap_BatteryVoltage_BatteryVoltage_Per1_CP0_CheckpointReached_Return
 *  Rte_CallHook_Ap_BatteryVoltage_BatteryVoltage_Per1_CP0_CheckpointReached_Start
 *  Rte_CallHook_Ap_BatteryVoltage_FltInjection_SCom_FltInjection_Return
 *  Rte_CallHook_Ap_BatteryVoltage_FltInjection_SCom_FltInjection_Start
 *  Rte_CallHook_Ap_BatteryVoltage_NxtrDiagMgr_SetNTCStatus_Return
 *  Rte_CallHook_Ap_BatteryVoltage_NxtrDiagMgr_SetNTCStatus_Start
 *  Rte_CallHook_Ap_CtrldDisShtdn_SystemTime_DtrmnElapsedTime_mS_u16_Return
 *  Rte_CallHook_Ap_CtrldDisShtdn_SystemTime_DtrmnElapsedTime_mS_u16_Start
 *  Rte_CallHook_Ap_CtrldDisShtdn_SystemTime_GetSystemTime_mS_u32_Return
 *  Rte_CallHook_Ap_CtrldDisShtdn_SystemTime_GetSystemTime_mS_u32_Start
 *  Rte_CallHook_Ap_DampingFirewall_NxtrDiagMgr_SetNTCStatus_Return
 *  Rte_CallHook_Ap_DampingFirewall_NxtrDiagMgr_SetNTCStatus_Start
 *  Rte_CallHook_Ap_Damping_FltInjection_SCom_FltInjection_Return
 *  Rte_CallHook_Ap_Damping_FltInjection_SCom_FltInjection_Start
 *  Rte_CallHook_Ap_DemIf_NxtrDiagMgr_GetNTCFailed_Return
 *  Rte_CallHook_Ap_DemIf_NxtrDiagMgr_GetNTCFailed_Start
 *  Rte_CallHook_Ap_DemIf_NxtrDiagMgr_GetNTCStatus_Return
 *  Rte_CallHook_Ap_DemIf_NxtrDiagMgr_GetNTCStatus_Start
 *  Rte_CallHook_Ap_DemIf_OperationCycle_SetOperationCycleState_Return
 *  Rte_CallHook_Ap_DemIf_OperationCycle_SetOperationCycleState_Start
 *  Rte_CallHook_Ap_DiagMgr9_DemIf_DemShutdown_Return
 *  Rte_CallHook_Ap_DiagMgr9_DemIf_DemShutdown_Start
 *  Rte_CallHook_Ap_DiagMgr9_DemIf_RestartDem_Return
 *  Rte_CallHook_Ap_DiagMgr9_DemIf_RestartDem_Start
 *  Rte_CallHook_Ap_DiagMgr9_DemIf_SetEventStatus_Return
 *  Rte_CallHook_Ap_DiagMgr9_DemIf_SetEventStatus_Start
 *  Rte_CallHook_Ap_DiagMgr9_DemIf_SetOperationCycleState_Return
 *  Rte_CallHook_Ap_DiagMgr9_DemIf_SetOperationCycleState_Start
 *  Rte_CallHook_Ap_DigPhsReasDiag_NxtrDiagMgr_SetNTCStatus_Return
 *  Rte_CallHook_Ap_DigPhsReasDiag_NxtrDiagMgr_SetNTCStatus_Start
 *  Rte_CallHook_Ap_FrqDepDmpnInrtCmp_FltInjection_SCom_FltInjection_Return
 *  Rte_CallHook_Ap_FrqDepDmpnInrtCmp_FltInjection_SCom_FltInjection_Start
 *  Rte_CallHook_Ap_Gsod_NxtrDiagMgr_SetNTCStatus_Return
 *  Rte_CallHook_Ap_Gsod_NxtrDiagMgr_SetNTCStatus_Start
 *  Rte_CallHook_Ap_HaLFTO_HaLFState_SCom_Transition_Return
 *  Rte_CallHook_Ap_HaLFTO_HaLFState_SCom_Transition_Start
 *  Rte_CallHook_Ap_HaLFTO_NxtrDiagMgr_GetNTCFailed_Return
 *  Rte_CallHook_Ap_HaLFTO_NxtrDiagMgr_GetNTCFailed_Start
 *  Rte_CallHook_Ap_HaLFTO_NxtrDiagMgr_SetNTCStatus_Return
 *  Rte_CallHook_Ap_HaLFTO_NxtrDiagMgr_SetNTCStatus_Start
 *  Rte_CallHook_Ap_HaLFTO_SystemTime_DtrmnElapsedTime_mS_u16_Return
 *  Rte_CallHook_Ap_HaLFTO_SystemTime_DtrmnElapsedTime_mS_u16_Start
 *  Rte_CallHook_Ap_HaLFTO_SystemTime_GetSystemTime_mS_u32_Return
 *  Rte_CallHook_Ap_HaLFTO_SystemTime_GetSystemTime_mS_u32_Start
 *  Rte_CallHook_Ap_HwPwUp_MilestoneRqst_WarmInitMilestoneComplete_Return
 *  Rte_CallHook_Ap_HwPwUp_MilestoneRqst_WarmInitMilestoneComplete_Start
 *  Rte_CallHook_Ap_HwPwUp_MilestoneRqst_WarmInitMilestoneNotComplete_Return
 *  Rte_CallHook_Ap_HwPwUp_MilestoneRqst_WarmInitMilestoneNotComplete_Start
 *  Rte_CallHook_Ap_HystComp_FltInjection_SCom_FltInjection_Return
 *  Rte_CallHook_Ap_HystComp_FltInjection_SCom_FltInjection_Start
 *  Rte_CallHook_Ap_LmtCod_FltInjection_SCom_FltInjection_Return
 *  Rte_CallHook_Ap_LmtCod_FltInjection_SCom_FltInjection_Start
 *  Rte_CallHook_Ap_LrnEOT_LearnedEOTData_SetRamBlockStatus_Return
 *  Rte_CallHook_Ap_LrnEOT_LearnedEOTData_SetRamBlockStatus_Start
 *  Rte_CallHook_Ap_LrnEOT_LearnedEOTData_WriteBlock_Return
 *  Rte_CallHook_Ap_LrnEOT_LearnedEOTData_WriteBlock_Start
 *  Rte_CallHook_Ap_LrnEOT_NxtrDiagMgr_GetNTCFailed_Return
 *  Rte_CallHook_Ap_LrnEOT_NxtrDiagMgr_GetNTCFailed_Start
 *  Rte_CallHook_Ap_LrnEOT_SystemTime_DtrmnElapsedTime_mS_u16_Return
 *  Rte_CallHook_Ap_LrnEOT_SystemTime_DtrmnElapsedTime_mS_u16_Start
 *  Rte_CallHook_Ap_LrnEOT_SystemTime_GetSystemTime_mS_u32_Return
 *  Rte_CallHook_Ap_LrnEOT_SystemTime_GetSystemTime_mS_u32_Start
 *  Rte_CallHook_Ap_PAwTO_NxtrDiagMgr_GetNTCActive_Return
 *  Rte_CallHook_Ap_PAwTO_NxtrDiagMgr_GetNTCActive_Start
 *  Rte_CallHook_Ap_PAwTO_NxtrDiagMgr_GetNTCFailed_Return
 *  Rte_CallHook_Ap_PAwTO_NxtrDiagMgr_GetNTCFailed_Start
 *  Rte_CallHook_Ap_PAwTO_NxtrDiagMgr_SetNTCStatus_Return
 *  Rte_CallHook_Ap_PAwTO_NxtrDiagMgr_SetNTCStatus_Start
 *  Rte_CallHook_Ap_PAwTO_PAwTO_Per2_CP1_CheckpointReached_Return
 *  Rte_CallHook_Ap_PAwTO_PAwTO_Per2_CP1_CheckpointReached_Start
 *  Rte_CallHook_Ap_PAwTO_PrkAssistState_SCom_Transition_Return
 *  Rte_CallHook_Ap_PAwTO_PrkAssistState_SCom_Transition_Start
 *  Rte_CallHook_Ap_PAwTO_SystemTime_DtrmnElapsedTime_mS_u16_Return
 *  Rte_CallHook_Ap_PAwTO_SystemTime_DtrmnElapsedTime_mS_u16_Start
 *  Rte_CallHook_Ap_PAwTO_SystemTime_GetSystemTime_mS_u32_Return
 *  Rte_CallHook_Ap_PAwTO_SystemTime_GetSystemTime_mS_u32_Start
 *  Rte_CallHook_Ap_Polarity_NxtrDiagMgr_SetNTCStatus_Return
 *  Rte_CallHook_Ap_Polarity_NxtrDiagMgr_SetNTCStatus_Start
 *  Rte_CallHook_Ap_PwrLmtFuncCr_NxtrDiagMgr_GetNTCStatus_Return
 *  Rte_CallHook_Ap_PwrLmtFuncCr_NxtrDiagMgr_GetNTCStatus_Start
 *  Rte_CallHook_Ap_PwrLmtFuncCr_NxtrDiagMgr_SetNTCStatus_Return
 *  Rte_CallHook_Ap_PwrLmtFuncCr_NxtrDiagMgr_SetNTCStatus_Start
 *  Rte_CallHook_Ap_PwrLmtFuncCr_SystemTime_DtrmnElapsedTime_mS_u16_Return
 *  Rte_CallHook_Ap_PwrLmtFuncCr_SystemTime_DtrmnElapsedTime_mS_u16_Start
 *  Rte_CallHook_Ap_PwrLmtFuncCr_SystemTime_GetSystemTime_mS_u32_Return
 *  Rte_CallHook_Ap_PwrLmtFuncCr_SystemTime_GetSystemTime_mS_u32_Start
 *  Rte_CallHook_Ap_ReturnFirewall_NxtrDiagMgr_SetNTCStatus_Return
 *  Rte_CallHook_Ap_ReturnFirewall_NxtrDiagMgr_SetNTCStatus_Start
 *  Rte_CallHook_Ap_Return_FltInjection_SCom_FltInjection_Return
 *  Rte_CallHook_Ap_Return_FltInjection_SCom_FltInjection_Start
 *  Rte_CallHook_Ap_SignlCondn_FaultInjection_SCom_FltInjection_Return
 *  Rte_CallHook_Ap_SignlCondn_FaultInjection_SCom_FltInjection_Start
 *  Rte_CallHook_Ap_SrlComInput_NxtrDiagMgr_GetNTCFailed_Return
 *  Rte_CallHook_Ap_SrlComInput_NxtrDiagMgr_GetNTCFailed_Start
 *  Rte_CallHook_Ap_SrlComInput_NxtrDiagMgr_GetNTCStatus_Return
 *  Rte_CallHook_Ap_SrlComInput_NxtrDiagMgr_GetNTCStatus_Start
 *  Rte_CallHook_Ap_SrlComInput_NxtrDiagMgr_SetNTCStatus_Return
 *  Rte_CallHook_Ap_SrlComInput_NxtrDiagMgr_SetNTCStatus_Start
 *  Rte_CallHook_Ap_SrlComInput_SrlComInput_Per1_CP0_CheckpointReached_Return
 *  Rte_CallHook_Ap_SrlComInput_SrlComInput_Per1_CP0_CheckpointReached_Start
 *  Rte_CallHook_Ap_SrlComInput_SystemTime_DtrmnElapsedTime_mS_u16_Return
 *  Rte_CallHook_Ap_SrlComInput_SystemTime_DtrmnElapsedTime_mS_u16_Start
 *  Rte_CallHook_Ap_SrlComInput_SystemTime_DtrmnElapsedTime_mS_u32_Return
 *  Rte_CallHook_Ap_SrlComInput_SystemTime_DtrmnElapsedTime_mS_u32_Start
 *  Rte_CallHook_Ap_SrlComInput_SystemTime_GetSystemTime_mS_u32_Return
 *  Rte_CallHook_Ap_SrlComInput_SystemTime_GetSystemTime_mS_u32_Start
 *  Rte_CallHook_Ap_SrlComOutput_NxtrDiagMgr_GetNTCFailed_Return
 *  Rte_CallHook_Ap_SrlComOutput_NxtrDiagMgr_GetNTCFailed_Start
 *  Rte_CallHook_Ap_SrlComOutput_SystemTime_DtrmnElapsedTime_mS_u32_Return
 *  Rte_CallHook_Ap_SrlComOutput_SystemTime_DtrmnElapsedTime_mS_u32_Start
 *  Rte_CallHook_Ap_SrlComOutput_SystemTime_GetSystemTime_mS_u32_Return
 *  Rte_CallHook_Ap_SrlComOutput_SystemTime_GetSystemTime_mS_u32_Start
 *  Rte_CallHook_Ap_StOpCtrl_SystemTime_DtrmnElapsedTime_mS_u32_Return
 *  Rte_CallHook_Ap_StOpCtrl_SystemTime_DtrmnElapsedTime_mS_u32_Start
 *  Rte_CallHook_Ap_StOpCtrl_SystemTime_GetSystemTime_mS_u32_Return
 *  Rte_CallHook_Ap_StOpCtrl_SystemTime_GetSystemTime_mS_u32_Start
 *  Rte_CallHook_Ap_StaMd9_DiagMgr_StaCtrl_Shutdown_Return
 *  Rte_CallHook_Ap_StaMd9_DiagMgr_StaCtrl_Shutdown_Start
 *  Rte_CallHook_Ap_StaMd_CloseCheckData_GetErrorStatus_Return
 *  Rte_CallHook_Ap_StaMd_CloseCheckData_GetErrorStatus_Start
 *  Rte_CallHook_Ap_StaMd_CloseCheckData_WriteBlock_Return
 *  Rte_CallHook_Ap_StaMd_CloseCheckData_WriteBlock_Start
 *  Rte_CallHook_Ap_StaMd_NxtrDiagMgr_SetNTCStatus_Return
 *  Rte_CallHook_Ap_StaMd_NxtrDiagMgr_SetNTCStatus_Start
 *  Rte_CallHook_Ap_StaMd_StaMd_Per1_CP1_CheckpointReached_Return
 *  Rte_CallHook_Ap_StaMd_StaMd_Per1_CP1_CheckpointReached_Start
 *  Rte_CallHook_Ap_StaMd_TOD_OP_SET_Return
 *  Rte_CallHook_Ap_StaMd_TOD_OP_SET_Start
 *  Rte_CallHook_Ap_StaMd_TypeHData_WriteBlock_Return
 *  Rte_CallHook_Ap_StaMd_TypeHData_WriteBlock_Start
 *  Rte_CallHook_Ap_StabilityComp_FaultInjection_SCom_FltInjection_Return
 *  Rte_CallHook_Ap_StabilityComp_FaultInjection_SCom_FltInjection_Start
 *  Rte_CallHook_Ap_StabilityComp_NxtrDiagMgr_SetNTCStatus_Return
 *  Rte_CallHook_Ap_StabilityComp_NxtrDiagMgr_SetNTCStatus_Start
 *  Rte_CallHook_Ap_StbCTO_NxtrDiagMgr_GetNTCActive_Return
 *  Rte_CallHook_Ap_StbCTO_NxtrDiagMgr_GetNTCActive_Start
 *  Rte_CallHook_Ap_StbCTO_NxtrDiagMgr_GetNTCFailed_Return
 *  Rte_CallHook_Ap_StbCTO_NxtrDiagMgr_GetNTCFailed_Start
 *  Rte_CallHook_Ap_StbCTO_NxtrDiagMgr_SetNTCStatus_Return
 *  Rte_CallHook_Ap_StbCTO_NxtrDiagMgr_SetNTCStatus_Start
 *  Rte_CallHook_Ap_StbCTO_SystemTime_DtrmnElapsedTime_mS_u16_Return
 *  Rte_CallHook_Ap_StbCTO_SystemTime_DtrmnElapsedTime_mS_u16_Start
 *  Rte_CallHook_Ap_StbCTO_SystemTime_GetSystemTime_mS_u32_Return
 *  Rte_CallHook_Ap_StbCTO_SystemTime_GetSystemTime_mS_u32_Start
 *  Rte_CallHook_Ap_ThrmlDutyCycle_NxtrDiagMgr_GetNTCFailed_Return
 *  Rte_CallHook_Ap_ThrmlDutyCycle_NxtrDiagMgr_GetNTCFailed_Start
 *  Rte_CallHook_Ap_ThrmlDutyCycle_NxtrDiagMgr_SetNTCStatus_Return
 *  Rte_CallHook_Ap_ThrmlDutyCycle_NxtrDiagMgr_SetNTCStatus_Start
 *  Rte_CallHook_Ap_ThrmlDutyCycle_ThrmlDutyCycle_Per1_CP1_CheckpointReached_Return
 *  Rte_CallHook_Ap_ThrmlDutyCycle_ThrmlDutyCycle_Per1_CP1_CheckpointReached_Start
 *  Rte_CallHook_Ap_TqRsDg_NxtrDiagMgr_SetNTCStatus_Return
 *  Rte_CallHook_Ap_TqRsDg_NxtrDiagMgr_SetNTCStatus_Start
 *  Rte_CallHook_Ap_TuningSelAuth_TuningSelAuth_Per1_CP0_CheckpointReached_Return
 *  Rte_CallHook_Ap_TuningSelAuth_TuningSelAuth_Per1_CP0_CheckpointReached_Start
 *  Rte_CallHook_Ap_VehPwrMd_EpsEn_OP_GET_Return
 *  Rte_CallHook_Ap_VehPwrMd_EpsEn_OP_GET_Start
 *  Rte_CallHook_Ap_VehPwrMd_VehPwrMd_Per1_CP1_CheckpointReached_Return
 *  Rte_CallHook_Ap_VehPwrMd_VehPwrMd_Per1_CP1_CheckpointReached_Start
 *  Rte_CallHook_Ap_WIRInputQual_SystemTime_DtrmnElapsedTime_mS_u16_Return
 *  Rte_CallHook_Ap_WIRInputQual_SystemTime_DtrmnElapsedTime_mS_u16_Start
 *  Rte_CallHook_Ap_WIRInputQual_SystemTime_GetSystemTime_mS_u32_Return
 *  Rte_CallHook_Ap_WIRInputQual_SystemTime_GetSystemTime_mS_u32_Start
 *  Rte_CallHook_Ap_WhlImbRej_NxtrDiagMgr_SetNTCStatus_Return
 *  Rte_CallHook_Ap_WhlImbRej_NxtrDiagMgr_SetNTCStatus_Start
 *  Rte_CallHook_Ap_WhlImbRej_SystemTime_DtrmnElapsedTime_mS_u16_Return
 *  Rte_CallHook_Ap_WhlImbRej_SystemTime_DtrmnElapsedTime_mS_u16_Start
 *  Rte_CallHook_Ap_WhlImbRej_SystemTime_DtrmnElapsedTime_mS_u32_Return
 *  Rte_CallHook_Ap_WhlImbRej_SystemTime_DtrmnElapsedTime_mS_u32_Start
 *  Rte_CallHook_Ap_WhlImbRej_SystemTime_GetSystemTime_mS_u32_Return
 *  Rte_CallHook_Ap_WhlImbRej_SystemTime_GetSystemTime_mS_u32_Start
 *  Rte_CallHook_Cd_uDiag_NxtrDiagMgr_SetNTCStatus_Return
 *  Rte_CallHook_Cd_uDiag_NxtrDiagMgr_SetNTCStatus_Start
 *  Rte_CallHook_Cd_uDiag_uDiagLossOfExec_Per3_CP0_CheckpointReached_Return
 *  Rte_CallHook_Cd_uDiag_uDiagLossOfExec_Per3_CP0_CheckpointReached_Start
 *  Rte_CallHook_Cd_uDiag_uDiagStaticRegs_Per_CP1_CheckpointReached_Return
 *  Rte_CallHook_Cd_uDiag_uDiagStaticRegs_Per_CP1_CheckpointReached_Start
 *  Rte_CallHook_IoHwAbstractionUsr_NxtrDiagMgr_SetNTCStatus_Return
 *  Rte_CallHook_IoHwAbstractionUsr_NxtrDiagMgr_SetNTCStatus_Start
 *  Rte_CallHook_IoHwAbstractionUsr_SystemTime_DtrmnElapsedTime_uS_u16_Return
 *  Rte_CallHook_IoHwAbstractionUsr_SystemTime_DtrmnElapsedTime_uS_u16_Start
 *  Rte_CallHook_IoHwAbstractionUsr_SystemTime_GetSystemTime_uS_u32_Return
 *  Rte_CallHook_IoHwAbstractionUsr_SystemTime_GetSystemTime_uS_u32_Start
 *  Rte_CallHook_Sa_BkCpPc_NxtrDiagMgr_SetNTCStatus_Return
 *  Rte_CallHook_Sa_BkCpPc_NxtrDiagMgr_SetNTCStatus_Start
 *  Rte_CallHook_Sa_BkCpPc_PhyCapDischarge_OP_SET_Return
 *  Rte_CallHook_Sa_BkCpPc_PhyCapDischarge_OP_SET_Start
 *  Rte_CallHook_Sa_BkCpPc_PhyCapPrecharge_OP_SET_Return
 *  Rte_CallHook_Sa_BkCpPc_PhyCapPrecharge_OP_SET_Start
 *  Rte_CallHook_Sa_BkCpPc_SystemTime_DtrmnElapsedTime_mS_u16_Return
 *  Rte_CallHook_Sa_BkCpPc_SystemTime_DtrmnElapsedTime_mS_u16_Start
 *  Rte_CallHook_Sa_BkCpPc_SystemTime_GetSystemTime_mS_u32_Return
 *  Rte_CallHook_Sa_BkCpPc_SystemTime_GetSystemTime_mS_u32_Start
 *  Rte_CallHook_Sa_CDDInterface_CDDPorts_ApplyMtrElecMechPol_Return
 *  Rte_CallHook_Sa_CDDInterface_CDDPorts_ApplyMtrElecMechPol_Start
 *  Rte_CallHook_Sa_CDDInterface_CDDPorts_ClearPhsReasSum_Return
 *  Rte_CallHook_Sa_CDDInterface_CDDPorts_ClearPhsReasSum_Start
 *  Rte_CallHook_Sa_CmMtrCurr_EOLShCurrCal_WriteBlock_Return
 *  Rte_CallHook_Sa_CmMtrCurr_EOLShCurrCal_WriteBlock_Start
 *  Rte_CallHook_Sa_CmMtrCurr_NxtrDiagMgr_SetNTCStatus_Return
 *  Rte_CallHook_Sa_CmMtrCurr_NxtrDiagMgr_SetNTCStatus_Start
 *  Rte_CallHook_Sa_CtrlTemp_CtrlTemp_Per2_CP0_CheckpointReached_Return
 *  Rte_CallHook_Sa_CtrlTemp_CtrlTemp_Per2_CP0_CheckpointReached_Start
 *  Rte_CallHook_Sa_CtrlTemp_NxtrDiagMgr_SetNTCStatus_Return
 *  Rte_CallHook_Sa_CtrlTemp_NxtrDiagMgr_SetNTCStatus_Start
 *  Rte_CallHook_Sa_HwTrq2_HwTrq2_Per3_CP0_CheckpointReached_Return
 *  Rte_CallHook_Sa_HwTrq2_HwTrq2_Per3_CP0_CheckpointReached_Start
 *  Rte_CallHook_Sa_HwTrq2_NxtrDiagMgr_SetNTCStatus_Return
 *  Rte_CallHook_Sa_HwTrq2_NxtrDiagMgr_SetNTCStatus_Start
 *  Rte_CallHook_Sa_HwTrq_HwTrqTrim_GetErrorStatus_Return
 *  Rte_CallHook_Sa_HwTrq_HwTrqTrim_GetErrorStatus_Start
 *  Rte_CallHook_Sa_HwTrq_HwTrq_Per3_CP0_CheckpointReached_Return
 *  Rte_CallHook_Sa_HwTrq_HwTrq_Per3_CP0_CheckpointReached_Start
 *  Rte_CallHook_Sa_HwTrq_NxtrDiagMgr_GetNTCFailed_Return
 *  Rte_CallHook_Sa_HwTrq_NxtrDiagMgr_GetNTCFailed_Start
 *  Rte_CallHook_Sa_HwTrq_NxtrDiagMgr_GetNTCStatus_Return
 *  Rte_CallHook_Sa_HwTrq_NxtrDiagMgr_GetNTCStatus_Start
 *  Rte_CallHook_Sa_HwTrq_NxtrDiagMgr_SetNTCStatus_Return
 *  Rte_CallHook_Sa_HwTrq_NxtrDiagMgr_SetNTCStatus_Start
 *  Rte_CallHook_Sa_MtrDrvDiag_FetDrvReset_OP_SET_Return
 *  Rte_CallHook_Sa_MtrDrvDiag_FetDrvReset_OP_SET_Start
 *  Rte_CallHook_Sa_MtrDrvDiag_FetFlt1Data_OP_GET_Return
 *  Rte_CallHook_Sa_MtrDrvDiag_FetFlt1Data_OP_GET_Start
 *  Rte_CallHook_Sa_MtrDrvDiag_FetFlt2Clk_OP_GET_Return
 *  Rte_CallHook_Sa_MtrDrvDiag_FetFlt2Clk_OP_GET_Start
 *  Rte_CallHook_Sa_MtrDrvDiag_FetFlt2Clk_OP_SET_Return
 *  Rte_CallHook_Sa_MtrDrvDiag_FetFlt2Clk_OP_SET_Start
 *  Rte_CallHook_Sa_MtrDrvDiag_IoHwAbPortConfig_SetFetFlt2ToOutput_Return
 *  Rte_CallHook_Sa_MtrDrvDiag_IoHwAbPortConfig_SetFetFlt2ToOutput_Start
 *  Rte_CallHook_Sa_MtrDrvDiag_NxtrDiagMgr_GetNTCFailed_Return
 *  Rte_CallHook_Sa_MtrDrvDiag_NxtrDiagMgr_GetNTCFailed_Start
 *  Rte_CallHook_Sa_MtrDrvDiag_NxtrDiagMgr_SetNTCStatus_Return
 *  Rte_CallHook_Sa_MtrDrvDiag_NxtrDiagMgr_SetNTCStatus_Start
 *  Rte_CallHook_Sa_MtrDrvDiag_SystemTime_DtrmnElapsedTime_mS_u16_Return
 *  Rte_CallHook_Sa_MtrDrvDiag_SystemTime_DtrmnElapsedTime_mS_u16_Start
 *  Rte_CallHook_Sa_MtrDrvDiag_SystemTime_DtrmnElapsedTime_uS_u16_Return
 *  Rte_CallHook_Sa_MtrDrvDiag_SystemTime_DtrmnElapsedTime_uS_u16_Start
 *  Rte_CallHook_Sa_MtrDrvDiag_SystemTime_GetSystemTime_mS_u32_Return
 *  Rte_CallHook_Sa_MtrDrvDiag_SystemTime_GetSystemTime_mS_u32_Start
 *  Rte_CallHook_Sa_MtrDrvDiag_SystemTime_GetSystemTime_uS_u32_Return
 *  Rte_CallHook_Sa_MtrDrvDiag_SystemTime_GetSystemTime_uS_u32_Start
 *  Rte_CallHook_Sa_MtrPos2_NxtrDiagMgr_GetNTCFailed_Return
 *  Rte_CallHook_Sa_MtrPos2_NxtrDiagMgr_GetNTCFailed_Start
 *  Rte_CallHook_Sa_MtrPos2_NxtrDiagMgr_SetNTCStatus_Return
 *  Rte_CallHook_Sa_MtrPos2_NxtrDiagMgr_SetNTCStatus_Start
 *  Rte_CallHook_Sa_MtrPos3_MtrPos3_Per2_CP1_CheckpointReached_Return
 *  Rte_CallHook_Sa_MtrPos3_MtrPos3_Per2_CP1_CheckpointReached_Start
 *  Rte_CallHook_Sa_MtrPos3_NxtrDiagMgr_SetNTCStatus_Return
 *  Rte_CallHook_Sa_MtrPos3_NxtrDiagMgr_SetNTCStatus_Start
 *  Rte_CallHook_Sa_MtrVel2_MtrVel2_Per1_CP0_CheckpointReached_Return
 *  Rte_CallHook_Sa_MtrVel2_MtrVel2_Per1_CP0_CheckpointReached_Start
 *  Rte_CallHook_Sa_MtrVel2_MtrVel2_Per2_CP0_CheckpointReached_Return
 *  Rte_CallHook_Sa_MtrVel2_MtrVel2_Per2_CP0_CheckpointReached_Start
 *  Rte_CallHook_Sa_MtrVel2_NxtrDiagMgr_SetNTCStatus_Return
 *  Rte_CallHook_Sa_MtrVel2_NxtrDiagMgr_SetNTCStatus_Start
 *  Rte_CallHook_Sa_MtrVel_MtrVel_Per1_CP0_CheckpointReached_Return
 *  Rte_CallHook_Sa_MtrVel_MtrVel_Per1_CP0_CheckpointReached_Start
 *  Rte_CallHook_Sa_MtrVel_NxtrDiagMgr_GetNTCFailed_Return
 *  Rte_CallHook_Sa_MtrVel_NxtrDiagMgr_GetNTCFailed_Start
 *  Rte_CallHook_Sa_MtrVel_NxtrDiagMgr_SetNTCStatus_Return
 *  Rte_CallHook_Sa_MtrVel_NxtrDiagMgr_SetNTCStatus_Start
 *  Rte_CallHook_Sa_OvrVoltMon_NxtrDiagMgr_SetNTCStatus_Return
 *  Rte_CallHook_Sa_OvrVoltMon_NxtrDiagMgr_SetNTCStatus_Start
 *  Rte_CallHook_Sa_OvrVoltMon_phyOvrVoltFdbk_OP_GET_Return
 *  Rte_CallHook_Sa_OvrVoltMon_phyOvrVoltFdbk_OP_GET_Start
 *  Rte_CallHook_Sa_ShtdnMech_FetDrvReset_OP_GET_Return
 *  Rte_CallHook_Sa_ShtdnMech_FetDrvReset_OP_GET_Start
 *  Rte_CallHook_Sa_ShtdnMech_SysFault2_OP_GET_Return
 *  Rte_CallHook_Sa_ShtdnMech_SysFault2_OP_GET_Start
 *  Rte_CallHook_Sa_ShtdnMech_SysFault3_OP_GET_Return
 *  Rte_CallHook_Sa_ShtdnMech_SysFault3_OP_GET_Start
 *  Rte_CallHook_Sa_TmprlMon2_TmprlMon2_Per1_CP1_CheckpointReached_Return
 *  Rte_CallHook_Sa_TmprlMon2_TmprlMon2_Per1_CP1_CheckpointReached_Start
 *  Rte_CallHook_Sa_TmprlMon2_WdMonitor_OP_SET_Return
 *  Rte_CallHook_Sa_TmprlMon2_WdMonitor_OP_SET_Start
 *  Rte_CallHook_Sa_TmprlMon_FetDrvCntl_OP_GET_Return
 *  Rte_CallHook_Sa_TmprlMon_FetDrvCntl_OP_GET_Start
 *  Rte_CallHook_Sa_TmprlMon_NxtrDiagMgr_SetNTCStatus_Return
 *  Rte_CallHook_Sa_TmprlMon_NxtrDiagMgr_SetNTCStatus_Start
 *  Rte_CallHook_Sa_TmprlMon_PwrSwitchEn_OP_GET_Return
 *  Rte_CallHook_Sa_TmprlMon_PwrSwitchEn_OP_GET_Start
 *  Rte_CallHook_Sa_TmprlMon_SysFault2_OP_GET_Return
 *  Rte_CallHook_Sa_TmprlMon_SysFault2_OP_GET_Start
 *  Rte_CallHook_Sa_TmprlMon_SysFault2_OP_SET_Return
 *  Rte_CallHook_Sa_TmprlMon_SysFault2_OP_SET_Start
 *  Rte_CallHook_Sa_TmprlMon_SysFault3_OP_GET_Return
 *  Rte_CallHook_Sa_TmprlMon_SysFault3_OP_GET_Start
 *  Rte_CallHook_Sa_TmprlMon_SysFault3_OP_SET_Return
 *  Rte_CallHook_Sa_TmprlMon_SysFault3_OP_SET_Start
 *  Rte_CallHook_Sa_TmprlMon_SystemTime_DtrmnElapsedTime_mS_u16_Return
 *  Rte_CallHook_Sa_TmprlMon_SystemTime_DtrmnElapsedTime_mS_u16_Start
 *  Rte_CallHook_Sa_TmprlMon_SystemTime_GetSystemTime_mS_u32_Return
 *  Rte_CallHook_Sa_TmprlMon_SystemTime_GetSystemTime_mS_u32_Start
 *  Rte_CallHook_Sa_TmprlMon_WdMonitor_OP_SET_Return
 *  Rte_CallHook_Sa_TmprlMon_WdMonitor_OP_SET_Start
 *  Rte_CallHook_Sa_TmprlMon_WdReset_OP_SET_Return
 *  Rte_CallHook_Sa_TmprlMon_WdReset_OP_SET_Start
 *  Rte_EnterHook_Ap_StaMd8_StaMds8_MilestoneRqst_WARMINIT_ExclArea_Return
 *  Rte_EnterHook_Ap_StaMd8_StaMds8_MilestoneRqst_WARMINIT_ExclArea_Start
 *  Rte_EnterHook_Ap_StaMd9_StaMds9_MilestoneRqst_WARMINIT_ExclArea_Return
 *  Rte_EnterHook_Ap_StaMd9_StaMds9_MilestoneRqst_WARMINIT_ExclArea_Start
 *  Rte_EnterHook_Ap_StaMd_StaMds_MilestoneRqst_WARMINIT_ExclArea_Return
 *  Rte_EnterHook_Ap_StaMd_StaMds_MilestoneRqst_WARMINIT_ExclArea_Start
 *  Rte_ExitHook_Ap_StaMd8_StaMds8_MilestoneRqst_WARMINIT_ExclArea_Return
 *  Rte_ExitHook_Ap_StaMd8_StaMds8_MilestoneRqst_WARMINIT_ExclArea_Start
 *  Rte_ExitHook_Ap_StaMd9_StaMds9_MilestoneRqst_WARMINIT_ExclArea_Return
 *  Rte_ExitHook_Ap_StaMd9_StaMds9_MilestoneRqst_WARMINIT_ExclArea_Start
 *  Rte_ExitHook_Ap_StaMd_StaMds_MilestoneRqst_WARMINIT_ExclArea_Return
 *  Rte_ExitHook_Ap_StaMd_StaMds_MilestoneRqst_WARMINIT_ExclArea_Start
 *  Rte_IrvReadHook_NexteerLibs_DtrmnElapsedTime_mS_u16_Time_mS_u32_Return
 *  Rte_IrvReadHook_NexteerLibs_DtrmnElapsedTime_mS_u16_Time_mS_u32_Start
 *  Rte_IrvReadHook_NexteerLibs_DtrmnElapsedTime_mS_u32_Time_mS_u32_Return
 *  Rte_IrvReadHook_NexteerLibs_DtrmnElapsedTime_mS_u32_Time_mS_u32_Start
 *  Rte_IrvReadHook_NexteerLibs_GetSystemTime_mS_u32_Time_mS_u32_Return
 *  Rte_IrvReadHook_NexteerLibs_GetSystemTime_mS_u32_Time_mS_u32_Start
 *  Rte_IrvReadHook_NexteerLibs_SystemTime_Per1_Time_mS_u32_Return
 *  Rte_IrvReadHook_NexteerLibs_SystemTime_Per1_Time_mS_u32_Start
 *  Rte_IrvWriteHook_NexteerLibs_SystemTime_Per1_Time_mS_u32_Return
 *  Rte_IrvWriteHook_NexteerLibs_SystemTime_Per1_Time_mS_u32_Start
 *  Rte_ReadHook_Ap_AstLmt_VehSpd_Kph_f32_Return
 *  Rte_ReadHook_Ap_AstLmt_VehSpd_Kph_f32_Start
 *  Rte_ReadHook_Ap_DemIf_CMDIgnStat_Cnt_u08_Return
 *  Rte_ReadHook_Ap_DemIf_CMDIgnStat_Cnt_u08_Start
 *  Rte_ReadHook_Ap_DemIf_NET_CFG_STAT_PT_Cnt_u16_Return
 *  Rte_ReadHook_Ap_DemIf_NET_CFG_STAT_PT_Cnt_u16_Start
 *  Rte_ReadHook_Ap_DiagMgr10_HwTrq_HwNm_f32_Return
 *  Rte_ReadHook_Ap_DiagMgr10_HwTrq_HwNm_f32_Start
 *  Rte_ReadHook_Ap_DiagMgr10_IgnCnt_Cnt_u16_Return
 *  Rte_ReadHook_Ap_DiagMgr10_IgnCnt_Cnt_u16_Start
 *  Rte_ReadHook_Ap_DiagMgr10_MEC_Cnt_enum_Return
 *  Rte_ReadHook_Ap_DiagMgr10_MEC_Cnt_enum_Start
 *  Rte_ReadHook_Ap_DiagMgr10_MfgDiagInhibit_Cnt_lgc_Return
 *  Rte_ReadHook_Ap_DiagMgr10_MfgDiagInhibit_Cnt_lgc_Start
 *  Rte_ReadHook_Ap_DiagMgr10_MtrTrq_MtrNm_f32_Return
 *  Rte_ReadHook_Ap_DiagMgr10_MtrTrq_MtrNm_f32_Start
 *  Rte_ReadHook_Ap_DiagMgr10_VehSpd_Kph_f32_Return
 *  Rte_ReadHook_Ap_DiagMgr10_VehSpd_Kph_f32_Start
 *  Rte_ReadHook_Ap_DiagMgr8_HwTrq_HwNm_f32_Return
 *  Rte_ReadHook_Ap_DiagMgr8_HwTrq_HwNm_f32_Start
 *  Rte_ReadHook_Ap_DiagMgr8_IgnCnt_Cnt_u16_Return
 *  Rte_ReadHook_Ap_DiagMgr8_IgnCnt_Cnt_u16_Start
 *  Rte_ReadHook_Ap_DiagMgr8_MEC_Cnt_enum_Return
 *  Rte_ReadHook_Ap_DiagMgr8_MEC_Cnt_enum_Start
 *  Rte_ReadHook_Ap_DiagMgr8_MfgDiagInhibit_Cnt_lgc_Return
 *  Rte_ReadHook_Ap_DiagMgr8_MfgDiagInhibit_Cnt_lgc_Start
 *  Rte_ReadHook_Ap_DiagMgr8_MtrTrq_MtrNm_f32_Return
 *  Rte_ReadHook_Ap_DiagMgr8_MtrTrq_MtrNm_f32_Start
 *  Rte_ReadHook_Ap_DiagMgr8_VehSpd_Kph_f32_Return
 *  Rte_ReadHook_Ap_DiagMgr8_VehSpd_Kph_f32_Start
 *  Rte_ReadHook_Ap_DiagMgr9_HwTrq_HwNm_f32_Return
 *  Rte_ReadHook_Ap_DiagMgr9_HwTrq_HwNm_f32_Start
 *  Rte_ReadHook_Ap_DiagMgr9_IgnCnt_Cnt_u16_Return
 *  Rte_ReadHook_Ap_DiagMgr9_IgnCnt_Cnt_u16_Start
 *  Rte_ReadHook_Ap_DiagMgr9_MEC_Cnt_enum_Return
 *  Rte_ReadHook_Ap_DiagMgr9_MEC_Cnt_enum_Start
 *  Rte_ReadHook_Ap_DiagMgr9_MfgDiagInhibit_Cnt_lgc_Return
 *  Rte_ReadHook_Ap_DiagMgr9_MfgDiagInhibit_Cnt_lgc_Start
 *  Rte_ReadHook_Ap_DiagMgr9_MtrTrq_MtrNm_f32_Return
 *  Rte_ReadHook_Ap_DiagMgr9_MtrTrq_MtrNm_f32_Start
 *  Rte_ReadHook_Ap_DiagMgr9_VehSpd_Kph_f32_Return
 *  Rte_ReadHook_Ap_DiagMgr9_VehSpd_Kph_f32_Start
 *  Rte_ReadHook_Ap_Gsod_Ana_Hw_Torque_HwNm_f32_Return
 *  Rte_ReadHook_Ap_Gsod_Ana_Hw_Torque_HwNm_f32_Start
 *  Rte_ReadHook_Ap_Gsod_Corrected_MtrPos_Rev_f32_Return
 *  Rte_ReadHook_Ap_Gsod_Corrected_MtrPos_Rev_f32_Start
 *  Rte_ReadHook_Ap_Gsod_Cum_Mtr_Pos_CRF_Deg_f32_Return
 *  Rte_ReadHook_Ap_Gsod_Cum_Mtr_Pos_CRF_Deg_f32_Start
 *  Rte_ReadHook_Ap_Gsod_MtrElecMech_Polarity_Cnt_s08_Return
 *  Rte_ReadHook_Ap_Gsod_MtrElecMech_Polarity_Cnt_s08_Start
 *  Rte_ReadHook_Ap_Gsod_SysC_Ana_Hw_Torque_HwNm_f32_Return
 *  Rte_ReadHook_Ap_Gsod_SysC_Ana_Hw_Torque_HwNm_f32_Start
 *  Rte_ReadHook_Ap_Gsod_SysC_Corrected_MtrPos_Rev_f32_Return
 *  Rte_ReadHook_Ap_Gsod_SysC_Corrected_MtrPos_Rev_f32_Start
 *  Rte_ReadHook_Ap_Gsod_SysC_Cum_Mtr_Pos_CRF_Deg_f32_Return
 *  Rte_ReadHook_Ap_Gsod_SysC_Cum_Mtr_Pos_CRF_Deg_f32_Start
 *  Rte_ReadHook_Ap_Gsod_SysC_MtrElecMech_Polarity_Cnt_s32_Return
 *  Rte_ReadHook_Ap_Gsod_SysC_MtrElecMech_Polarity_Cnt_s32_Start
 *  Rte_ReadHook_Ap_Gsod_SysC_Torque_Cmd_CRF_MtrNm_f32_Return
 *  Rte_ReadHook_Ap_Gsod_SysC_Torque_Cmd_CRF_MtrNm_f32_Start
 *  Rte_ReadHook_Ap_Gsod_SysC_Torque_Cmd_MRF_MtrNm_f32_Return
 *  Rte_ReadHook_Ap_Gsod_SysC_Torque_Cmd_MRF_MtrNm_f32_Start
 *  Rte_ReadHook_Ap_Gsod_SysC_Vecu_Volt_f32_Return
 *  Rte_ReadHook_Ap_Gsod_SysC_Vecu_Volt_f32_Start
 *  Rte_ReadHook_Ap_Gsod_Torque_Cmd_CRF_MtrNm_f32_Return
 *  Rte_ReadHook_Ap_Gsod_Torque_Cmd_CRF_MtrNm_f32_Start
 *  Rte_ReadHook_Ap_Gsod_Torque_Cmd_MRF_MtrNm_f32_Return
 *  Rte_ReadHook_Ap_Gsod_Torque_Cmd_MRF_MtrNm_f32_Start
 *  Rte_ReadHook_Ap_Gsod_Vecu_Volt_f32_Return
 *  Rte_ReadHook_Ap_Gsod_Vecu_Volt_f32_Start
 *  Rte_ReadHook_Ap_SrlComInput_AnaHwTorque_HwNm_f32_Return
 *  Rte_ReadHook_Ap_SrlComInput_AnaHwTorque_HwNm_f32_Start
 *  Rte_ReadHook_Ap_SrlComInput_DSTSlewStart_Cnt_lgc_Return
 *  Rte_ReadHook_Ap_SrlComInput_DSTSlewStart_Cnt_lgc_Start
 *  Rte_ReadHook_Ap_SrlComInput_DSTState_Cnt_u08_Return
 *  Rte_ReadHook_Ap_SrlComInput_DSTState_Cnt_u08_Start
 *  Rte_ReadHook_Ap_SrlComInput_DefaultVehSpd_Cnt_lgc_Return
 *  Rte_ReadHook_Ap_SrlComInput_DefaultVehSpd_Cnt_lgc_Start
 *  Rte_ReadHook_Ap_SrlComInput_EstFric_HwNm_f32_Return
 *  Rte_ReadHook_Ap_SrlComInput_EstFric_HwNm_f32_Start
 *  Rte_ReadHook_Ap_SrlComInput_HaLFState_Cnt_u08_Return
 *  Rte_ReadHook_Ap_SrlComInput_HaLFState_Cnt_u08_Start
 *  Rte_ReadHook_Ap_SrlComInput_HaLFSuspend_Cnt_lgc_Return
 *  Rte_ReadHook_Ap_SrlComInput_HaLFSuspend_Cnt_lgc_Start
 *  Rte_ReadHook_Ap_SrlComInput_HandsOnDetect_Cnt_lgc_Return
 *  Rte_ReadHook_Ap_SrlComInput_HandsOnDetect_Cnt_lgc_Start
 *  Rte_ReadHook_Ap_SrlComInput_MEC_Cnt_enum_Return
 *  Rte_ReadHook_Ap_SrlComInput_MEC_Cnt_enum_Start
 *  Rte_ReadHook_Ap_SrlComInput_PABoostCurveSwitch_Cnt_lgc_Return
 *  Rte_ReadHook_Ap_SrlComInput_PABoostCurveSwitch_Cnt_lgc_Start
 *  Rte_ReadHook_Ap_SrlComInput_PrkAssistState_Cnt_u08_Return
 *  Rte_ReadHook_Ap_SrlComInput_PrkAssistState_Cnt_u08_Start
 *  Rte_ReadHook_Ap_SrlComInput_PrkAssistSuspend_Cnt_lgc_Return
 *  Rte_ReadHook_Ap_SrlComInput_PrkAssistSuspend_Cnt_lgc_Start
 *  Rte_ReadHook_Ap_SrlComInput_RxMsgsSrlComSvcDft_Cnt_lgc_Return
 *  Rte_ReadHook_Ap_SrlComInput_RxMsgsSrlComSvcDft_Cnt_lgc_Start
 *  Rte_ReadHook_Ap_SrlComInput_StrClmTrq_HwNm_f32_Return
 *  Rte_ReadHook_Ap_SrlComInput_StrClmTrq_HwNm_f32_Start
 *  Rte_ReadHook_Ap_SrlComOutput_ATermActive_Cnt_lgc_Return
 *  Rte_ReadHook_Ap_SrlComOutput_ATermActive_Cnt_lgc_Start
 *  Rte_ReadHook_Ap_SrlComOutput_ActiveFunctionBits_Cnt_u08_Return
 *  Rte_ReadHook_Ap_SrlComOutput_ActiveFunctionBits_Cnt_u08_Start
 *  Rte_ReadHook_Ap_SrlComOutput_ActiveTunSet_Cnt_u16_Return
 *  Rte_ReadHook_Ap_SrlComOutput_ActiveTunSet_Cnt_u16_Start
 *  Rte_ReadHook_Ap_SrlComOutput_CRFMtrTrqCmd_MtrNm_f32_Return
 *  Rte_ReadHook_Ap_SrlComOutput_CRFMtrTrqCmd_MtrNm_f32_Start
 *  Rte_ReadHook_Ap_SrlComOutput_CTermActive_Cnt_lgc_Return
 *  Rte_ReadHook_Ap_SrlComOutput_CTermActive_Cnt_lgc_Start
 *  Rte_ReadHook_Ap_SrlComOutput_CanMsgReceived_Cnt_lgc_Return
 *  Rte_ReadHook_Ap_SrlComOutput_CanMsgReceived_Cnt_lgc_Start
 *  Rte_ReadHook_Ap_SrlComOutput_DSTEOLDisable_Cnt_lgc_Return
 *  Rte_ReadHook_Ap_SrlComOutput_DSTEOLDisable_Cnt_lgc_Start
 *  Rte_ReadHook_Ap_SrlComOutput_DSTExtSystemFltActive_Cnt_lgc_Return
 *  Rte_ReadHook_Ap_SrlComOutput_DSTExtSystemFltActive_Cnt_lgc_Start
 *  Rte_ReadHook_Ap_SrlComOutput_DSTState_Cnt_u08_Return
 *  Rte_ReadHook_Ap_SrlComOutput_DSTState_Cnt_u08_Start
 *  Rte_ReadHook_Ap_SrlComOutput_DesiredTunPersTypH_Cnt_u08_Return
 *  Rte_ReadHook_Ap_SrlComOutput_DesiredTunPersTypH_Cnt_u08_Start
 *  Rte_ReadHook_Ap_SrlComOutput_DesiredTunPers_Cnt_u16_Return
 *  Rte_ReadHook_Ap_SrlComOutput_DesiredTunPers_Cnt_u16_Start
 *  Rte_ReadHook_Ap_SrlComOutput_DiagStsNonRecRmpToZeroFltPres_Cnt_lgc_Return
 *  Rte_ReadHook_Ap_SrlComOutput_DiagStsNonRecRmpToZeroFltPres_Cnt_lgc_Start
 *  Rte_ReadHook_Ap_SrlComOutput_DiagStsRecRmpToZeroFltPres_Cnt_lgc_Return
 *  Rte_ReadHook_Ap_SrlComOutput_DiagStsRecRmpToZeroFltPres_Cnt_lgc_Start
 *  Rte_ReadHook_Ap_SrlComOutput_EngRPM_Cnt_u16_Return
 *  Rte_ReadHook_Ap_SrlComOutput_EngRPM_Cnt_u16_Start
 *  Rte_ReadHook_Ap_SrlComOutput_HaLFState_Cnt_u08_Return
 *  Rte_ReadHook_Ap_SrlComOutput_HaLFState_Cnt_u08_Start
 *  Rte_ReadHook_Ap_SrlComOutput_HaLFSuspend_Cnt_lgc_Return
 *  Rte_ReadHook_Ap_SrlComOutput_HaLFSuspend_Cnt_lgc_Start
 *  Rte_ReadHook_Ap_SrlComOutput_HandsOnDetect_Cnt_lgc_Return
 *  Rte_ReadHook_Ap_SrlComOutput_HandsOnDetect_Cnt_lgc_Start
 *  Rte_ReadHook_Ap_SrlComOutput_HwTrq_HwNm_f32_Return
 *  Rte_ReadHook_Ap_SrlComOutput_HwTrq_HwNm_f32_Start
 *  Rte_ReadHook_Ap_SrlComOutput_OutputRampMult_Uls_f32_Return
 *  Rte_ReadHook_Ap_SrlComOutput_OutputRampMult_Uls_f32_Start
 *  Rte_ReadHook_Ap_SrlComOutput_PrkAssistState_Cnt_u08_Return
 *  Rte_ReadHook_Ap_SrlComOutput_PrkAssistState_Cnt_u08_Start
 *  Rte_ReadHook_Ap_SrlComOutput_PrkAssistSuspend_Cnt_lgc_Return
 *  Rte_ReadHook_Ap_SrlComOutput_PrkAssistSuspend_Cnt_lgc_Start
 *  Rte_ReadHook_Ap_SrlComOutput_RampDwnStatusComplete_Cnt_lgc_Return
 *  Rte_ReadHook_Ap_SrlComOutput_RampDwnStatusComplete_Cnt_lgc_Start
 *  Rte_ReadHook_Ap_SrlComOutput_SpStPrsnt_Cnt_lgc_Return
 *  Rte_ReadHook_Ap_SrlComOutput_SpStPrsnt_Cnt_lgc_Start
 *  Rte_ReadHook_Ap_SrlComOutput_SrlComHwTrqValid_Cnt_lgc_Return
 *  Rte_ReadHook_Ap_SrlComOutput_SrlComHwTrqValid_Cnt_lgc_Start
 *  Rte_ReadHook_Ap_SrlComOutput_SrlComVehSpdValid_Cnt_lgc_Return
 *  Rte_ReadHook_Ap_SrlComOutput_SrlComVehSpdValid_Cnt_lgc_Start
 *  Rte_ReadHook_Ap_SrlComOutput_SumLmtTrqCmd_MtrNm_f32_Return
 *  Rte_ReadHook_Ap_SrlComOutput_SumLmtTrqCmd_MtrNm_f32_Start
 *  Rte_ReadHook_Ap_SrlComOutput_SupplyCurrent_Amp_f32_Return
 *  Rte_ReadHook_Ap_SrlComOutput_SupplyCurrent_Amp_f32_Start
 *  Rte_ReadHook_Ap_SrlComOutput_VehicleSpeed_Kph_f32_Return
 *  Rte_ReadHook_Ap_SrlComOutput_VehicleSpeed_Kph_f32_Start
 *  Rte_ReadHook_Sa_CmMtrCurr_MEC_Cnt_enum_Return
 *  Rte_ReadHook_Sa_CmMtrCurr_MEC_Cnt_enum_Start
 *  Rte_ReadHook_Sa_CmMtrCurr_MtrVel_MtrRadpS_f32_Return
 *  Rte_ReadHook_Sa_CmMtrCurr_MtrVel_MtrRadpS_f32_Start
 *  Rte_ReadHook_Sa_CmMtrCurr_VehSpd_Kph_f32_Return
 *  Rte_ReadHook_Sa_CmMtrCurr_VehSpd_Kph_f32_Start
 *  Rte_ReadHook_Sa_CmMtrCurr_VhSpdValid_Cnt_lgc_Return
 *  Rte_ReadHook_Sa_CmMtrCurr_VhSpdValid_Cnt_lgc_Start
 *  Rte_ReadHook_Sa_HwTrq_MECCounter_Cnt_enum_Return
 *  Rte_ReadHook_Sa_HwTrq_MECCounter_Cnt_enum_Start
 *  Rte_ReadHook_Sa_HwTrq_T1ADC_Volt_f32_Return
 *  Rte_ReadHook_Sa_HwTrq_T1ADC_Volt_f32_Start
 *  Rte_ReadHook_Sa_HwTrq_T2ADC_Volt_f32_Return
 *  Rte_ReadHook_Sa_HwTrq_T2ADC_Volt_f32_Start
 *  Rte_Runnable_Ap_AbsHwPosScom_AbsHwPosScom_Init1_Return
 *  Rte_Runnable_Ap_AbsHwPosScom_AbsHwPosScom_Init1_Start
 *  Rte_Runnable_Ap_AbsHwPosScom_AbsHwPosScom_Per1_Return
 *  Rte_Runnable_Ap_AbsHwPosScom_AbsHwPosScom_Per1_Start
 *  Rte_Runnable_Ap_AbsHwPosScom_AbsHwPosScom_Per2_Return
 *  Rte_Runnable_Ap_AbsHwPosScom_AbsHwPosScom_Per2_Start
 *  Rte_Runnable_Ap_AbsHwPosScom_AbsHwPosScom_Per3_Return
 *  Rte_Runnable_Ap_AbsHwPosScom_AbsHwPosScom_Per3_Start
 *  Rte_Runnable_Ap_AbsHwPosScom_AbsHwPosScom_Scom_HwPosSrvRead_Return
 *  Rte_Runnable_Ap_AbsHwPosScom_AbsHwPosScom_Scom_HwPosSrvRead_Start
 *  Rte_Runnable_Ap_AbsHwPosScom_AbsHwPosScom_Scom_HwPosSrvSetToZero_Return
 *  Rte_Runnable_Ap_AbsHwPosScom_AbsHwPosScom_Scom_HwPosSrvSetToZero_Start
 *  Rte_Runnable_Ap_ActivePull_ActivePull_Init1_Return
 *  Rte_Runnable_Ap_ActivePull_ActivePull_Init1_Start
 *  Rte_Runnable_Ap_ActivePull_ActivePull_Per1_Return
 *  Rte_Runnable_Ap_ActivePull_ActivePull_Per1_Start
 *  Rte_Runnable_Ap_ActivePull_ActivePull_Per2_Return
 *  Rte_Runnable_Ap_ActivePull_ActivePull_Per2_Start
 *  Rte_Runnable_Ap_ActivePull_ActivePull_Per3_Return
 *  Rte_Runnable_Ap_ActivePull_ActivePull_Per3_Start
 *  Rte_Runnable_Ap_ActivePull_ActivePull_SCom_ReadParam_Return
 *  Rte_Runnable_Ap_ActivePull_ActivePull_SCom_ReadParam_Start
 *  Rte_Runnable_Ap_ActivePull_ActivePull_SCom_Reset_Return
 *  Rte_Runnable_Ap_ActivePull_ActivePull_SCom_Reset_Start
 *  Rte_Runnable_Ap_ActivePull_ActivePull_SCom_SetLTComp_Return
 *  Rte_Runnable_Ap_ActivePull_ActivePull_SCom_SetLTComp_Start
 *  Rte_Runnable_Ap_ActivePull_ActivePull_SCom_SetSTComp_Return
 *  Rte_Runnable_Ap_ActivePull_ActivePull_SCom_SetSTComp_Start
 *  Rte_Runnable_Ap_ActivePull_ActivePull_Trns1_Return
 *  Rte_Runnable_Ap_ActivePull_ActivePull_Trns1_Start
 *  Rte_Runnable_Ap_ApXcp_ApXcp_Per1_Return
 *  Rte_Runnable_Ap_ApXcp_ApXcp_Per1_Start
 *  Rte_Runnable_Ap_ApXcp_DAQ_2msTL_Return
 *  Rte_Runnable_Ap_ApXcp_DAQ_2msTL_Start
 *  Rte_Runnable_Ap_ArbLmt_ArbLmt_Per1_Return
 *  Rte_Runnable_Ap_ArbLmt_ArbLmt_Per1_Start
 *  Rte_Runnable_Ap_AssistFirewall_AssistFirewall_Init1_Return
 *  Rte_Runnable_Ap_AssistFirewall_AssistFirewall_Init1_Start
 *  Rte_Runnable_Ap_AssistFirewall_AssistFirewall_Per1_Return
 *  Rte_Runnable_Ap_AssistFirewall_AssistFirewall_Per1_Start
 *  Rte_Runnable_Ap_Assist_Assist_Per1_Return
 *  Rte_Runnable_Ap_Assist_Assist_Per1_Start
 *  Rte_Runnable_Ap_AstLmt_AstLmt_Init_Return
 *  Rte_Runnable_Ap_AstLmt_AstLmt_Init_Start
 *  Rte_Runnable_Ap_AstLmt_AstLmt_Per1_Return
 *  Rte_Runnable_Ap_AstLmt_AstLmt_Per1_Start
 *  Rte_Runnable_Ap_AstLmt_AstLmt_Scom_GetSteeringAssistDefeat_Return
 *  Rte_Runnable_Ap_AstLmt_AstLmt_Scom_GetSteeringAssistDefeat_Start
 *  Rte_Runnable_Ap_AstLmt_AstLmt_Scom_ManualTrqCmd_Return
 *  Rte_Runnable_Ap_AstLmt_AstLmt_Scom_ManualTrqCmd_Start
 *  Rte_Runnable_Ap_AstLmt_AstLmt_Scom_SetSteeringAssistDefeat_Return
 *  Rte_Runnable_Ap_AstLmt_AstLmt_Scom_SetSteeringAssistDefeat_Start
 *  Rte_Runnable_Ap_AvgFricLrn_AvgFricLrn_Init1_Return
 *  Rte_Runnable_Ap_AvgFricLrn_AvgFricLrn_Init1_Start
 *  Rte_Runnable_Ap_AvgFricLrn_AvgFricLrn_Per1_Return
 *  Rte_Runnable_Ap_AvgFricLrn_AvgFricLrn_Per1_Start
 *  Rte_Runnable_Ap_AvgFricLrn_AvgFricLrn_SCom_GetEOLFric_Return
 *  Rte_Runnable_Ap_AvgFricLrn_AvgFricLrn_SCom_GetEOLFric_Start
 *  Rte_Runnable_Ap_AvgFricLrn_AvgFricLrn_SCom_GetOffsetOutputDefeat_Return
 *  Rte_Runnable_Ap_AvgFricLrn_AvgFricLrn_SCom_GetOffsetOutputDefeat_Start
 *  Rte_Runnable_Ap_AvgFricLrn_AvgFricLrn_SCom_GetSelect_Return
 *  Rte_Runnable_Ap_AvgFricLrn_AvgFricLrn_SCom_GetSelect_Start
 *  Rte_Runnable_Ap_AvgFricLrn_AvgFricLrn_SCom_InitLearnedTables_Return
 *  Rte_Runnable_Ap_AvgFricLrn_AvgFricLrn_SCom_InitLearnedTables_Start
 *  Rte_Runnable_Ap_AvgFricLrn_AvgFricLrn_SCom_ResetToZero_Return
 *  Rte_Runnable_Ap_AvgFricLrn_AvgFricLrn_SCom_ResetToZero_Start
 *  Rte_Runnable_Ap_AvgFricLrn_AvgFricLrn_SCom_SetEOLFric_Return
 *  Rte_Runnable_Ap_AvgFricLrn_AvgFricLrn_SCom_SetEOLFric_Start
 *  Rte_Runnable_Ap_AvgFricLrn_AvgFricLrn_SCom_SetOffsetOutputDefeat_Return
 *  Rte_Runnable_Ap_AvgFricLrn_AvgFricLrn_SCom_SetOffsetOutputDefeat_Start
 *  Rte_Runnable_Ap_AvgFricLrn_AvgFricLrn_SCom_SetSelect_Return
 *  Rte_Runnable_Ap_AvgFricLrn_AvgFricLrn_SCom_SetSelect_Start
 *  Rte_Runnable_Ap_AvgFricLrn_AvgFricLrn_Trns1_Return
 *  Rte_Runnable_Ap_AvgFricLrn_AvgFricLrn_Trns1_Start
 *  Rte_Runnable_Ap_BVDiag_BVDiag_Per1_Return
 *  Rte_Runnable_Ap_BVDiag_BVDiag_Per1_Start
 *  Rte_Runnable_Ap_BatteryVoltage_BatteryVoltage_Per1_Return
 *  Rte_Runnable_Ap_BatteryVoltage_BatteryVoltage_Per1_Start
 *  Rte_Runnable_Ap_BatteryVoltage_BatteryVoltage_Per2_Return
 *  Rte_Runnable_Ap_BatteryVoltage_BatteryVoltage_Per2_Start
 *  Rte_Runnable_Ap_BatteryVoltage_BatteryVoltage_SCom_ClearTransOvData_Return
 *  Rte_Runnable_Ap_BatteryVoltage_BatteryVoltage_SCom_ClearTransOvData_Start
 *  Rte_Runnable_Ap_BatteryVoltage_BatteryVoltage_SCom_ReadTransOvData_Return
 *  Rte_Runnable_Ap_BatteryVoltage_BatteryVoltage_SCom_ReadTransOvData_Start
 *  Rte_Runnable_Ap_CtrldDisShtdn_CtrldDisShtdn_Per1_Return
 *  Rte_Runnable_Ap_CtrldDisShtdn_CtrldDisShtdn_Per1_Start
 *  Rte_Runnable_Ap_CurrCmd_CurrCmd_Init_Return
 *  Rte_Runnable_Ap_CurrCmd_CurrCmd_Init_Start
 *  Rte_Runnable_Ap_CurrCmd_CurrCmd_Per1_Return
 *  Rte_Runnable_Ap_CurrCmd_CurrCmd_Per1_Start
 *  Rte_Runnable_Ap_CurrParamComp_CurrParamComp_Init_Return
 *  Rte_Runnable_Ap_CurrParamComp_CurrParamComp_Init_Start
 *  Rte_Runnable_Ap_CurrParamComp_CurrParamComp_Per1_Return
 *  Rte_Runnable_Ap_CurrParamComp_CurrParamComp_Per1_Start
 *  Rte_Runnable_Ap_CurrParamComp_CurrParamComp_Per2_Return
 *  Rte_Runnable_Ap_CurrParamComp_CurrParamComp_Per2_Start
 *  Rte_Runnable_Ap_CurrParamComp_SCom_EOLNomMtrParam_Get_Return
 *  Rte_Runnable_Ap_CurrParamComp_SCom_EOLNomMtrParam_Get_Start
 *  Rte_Runnable_Ap_CurrParamComp_SCom_EOLNomMtrParam_Set_Return
 *  Rte_Runnable_Ap_CurrParamComp_SCom_EOLNomMtrParam_Set_Start
 *  Rte_Runnable_Ap_DampingFirewall_DampingFirewall_Init1_Return
 *  Rte_Runnable_Ap_DampingFirewall_DampingFirewall_Init1_Start
 *  Rte_Runnable_Ap_DampingFirewall_DampingFirewall_Per1_Return
 *  Rte_Runnable_Ap_DampingFirewall_DampingFirewall_Per1_Start
 *  Rte_Runnable_Ap_Damping_Damping_Init1_Return
 *  Rte_Runnable_Ap_Damping_Damping_Init1_Start
 *  Rte_Runnable_Ap_Damping_Damping_Per1_Return
 *  Rte_Runnable_Ap_Damping_Damping_Per1_Start
 *  Rte_Runnable_Ap_DemIf_DemIf_Init_Return
 *  Rte_Runnable_Ap_DemIf_DemIf_Init_Start
 *  Rte_Runnable_Ap_DemIf_DemIf_RestartDem_Return
 *  Rte_Runnable_Ap_DemIf_DemIf_RestartDem_Start
 *  Rte_Runnable_Ap_DemIf_DemIf_SetEventStatus_Return
 *  Rte_Runnable_Ap_DemIf_DemIf_SetEventStatus_Start
 *  Rte_Runnable_Ap_DemIf_DemIf_SetInputsConditions_Return
 *  Rte_Runnable_Ap_DemIf_DemIf_SetInputsConditions_Start
 *  Rte_Runnable_Ap_DemIf_DemIf_SetOperationCycleState_Return
 *  Rte_Runnable_Ap_DemIf_DemIf_SetOperationCycleState_Start
 *  Rte_Runnable_Ap_DemIf_DemIf_Shutdown_Return
 *  Rte_Runnable_Ap_DemIf_DemIf_Shutdown_Start
 *  Rte_Runnable_Ap_DiagMgr10_DiagMgr10_Init_Return
 *  Rte_Runnable_Ap_DiagMgr10_DiagMgr10_Init_Start
 *  Rte_Runnable_Ap_DiagMgr10_DiagMgr10_Per_Return
 *  Rte_Runnable_Ap_DiagMgr10_DiagMgr10_Per_Start
 *  Rte_Runnable_Ap_DiagMgr10_DiagMgr10_Trns_Return
 *  Rte_Runnable_Ap_DiagMgr10_DiagMgr10_Trns_Start
 *  Rte_Runnable_Ap_DiagMgr10_DiagMgr_Per1_Return
 *  Rte_Runnable_Ap_DiagMgr10_DiagMgr_Per1_Start
 *  Rte_Runnable_Ap_DiagMgr10_NxtrDiagMgr10_GetNTCActive_Return
 *  Rte_Runnable_Ap_DiagMgr10_NxtrDiagMgr10_GetNTCActive_Start
 *  Rte_Runnable_Ap_DiagMgr10_NxtrDiagMgr10_GetNTCFailed_Return
 *  Rte_Runnable_Ap_DiagMgr10_NxtrDiagMgr10_GetNTCFailed_Start
 *  Rte_Runnable_Ap_DiagMgr10_NxtrDiagMgr10_GetNTCStatus_Return
 *  Rte_Runnable_Ap_DiagMgr10_NxtrDiagMgr10_GetNTCStatus_Start
 *  Rte_Runnable_Ap_DiagMgr10_NxtrDiagMgr10_SetNTCStatus_Return
 *  Rte_Runnable_Ap_DiagMgr10_NxtrDiagMgr10_SetNTCStatus_Start
 *  Rte_Runnable_Ap_DiagMgr8_DiagMgr8_Init_Return
 *  Rte_Runnable_Ap_DiagMgr8_DiagMgr8_Init_Start
 *  Rte_Runnable_Ap_DiagMgr8_DiagMgr8_Per_Return
 *  Rte_Runnable_Ap_DiagMgr8_DiagMgr8_Per_Start
 *  Rte_Runnable_Ap_DiagMgr8_DiagMgr8_Trns_Return
 *  Rte_Runnable_Ap_DiagMgr8_DiagMgr8_Trns_Start
 *  Rte_Runnable_Ap_DiagMgr8_NxtrDiagMgr8_GetNTCActive_Return
 *  Rte_Runnable_Ap_DiagMgr8_NxtrDiagMgr8_GetNTCActive_Start
 *  Rte_Runnable_Ap_DiagMgr8_NxtrDiagMgr8_GetNTCFailed_Return
 *  Rte_Runnable_Ap_DiagMgr8_NxtrDiagMgr8_GetNTCFailed_Start
 *  Rte_Runnable_Ap_DiagMgr8_NxtrDiagMgr8_GetNTCStatus_Return
 *  Rte_Runnable_Ap_DiagMgr8_NxtrDiagMgr8_GetNTCStatus_Start
 *  Rte_Runnable_Ap_DiagMgr8_NxtrDiagMgr8_SetNTCStatus_Return
 *  Rte_Runnable_Ap_DiagMgr8_NxtrDiagMgr8_SetNTCStatus_Start
 *  Rte_Runnable_Ap_DiagMgr9_DiagMgr9_Init_Return
 *  Rte_Runnable_Ap_DiagMgr9_DiagMgr9_Init_Start
 *  Rte_Runnable_Ap_DiagMgr9_DiagMgr9_Per_Return
 *  Rte_Runnable_Ap_DiagMgr9_DiagMgr9_Per_Start
 *  Rte_Runnable_Ap_DiagMgr9_DiagMgr9_Trns_Return
 *  Rte_Runnable_Ap_DiagMgr9_DiagMgr9_Trns_Start
 *  Rte_Runnable_Ap_DiagMgr9_DiagMgr_Init1_Return
 *  Rte_Runnable_Ap_DiagMgr9_DiagMgr_Init1_Start
 *  Rte_Runnable_Ap_DiagMgr9_DiagMgr_Per2_Return
 *  Rte_Runnable_Ap_DiagMgr9_DiagMgr_Per2_Start
 *  Rte_Runnable_Ap_DiagMgr9_DiagMgr_SCom_ClearBlackBox_Return
 *  Rte_Runnable_Ap_DiagMgr9_DiagMgr_SCom_ClearBlackBox_Start
 *  Rte_Runnable_Ap_DiagMgr9_DiagMgr_SCom_ClearLatchCounters_Return
 *  Rte_Runnable_Ap_DiagMgr9_DiagMgr_SCom_ClearLatchCounters_Start
 *  Rte_Runnable_Ap_DiagMgr9_DiagMgr_SCom_GetNTCInfo_Return
 *  Rte_Runnable_Ap_DiagMgr9_DiagMgr_SCom_GetNTCInfo_Start
 *  Rte_Runnable_Ap_DiagMgr9_DiagMgr_SCom_ReadStrgArray_Return
 *  Rte_Runnable_Ap_DiagMgr9_DiagMgr_SCom_ReadStrgArray_Start
 *  Rte_Runnable_Ap_DiagMgr9_DiagMgr_SCom_ResetNTCStatus_Return
 *  Rte_Runnable_Ap_DiagMgr9_DiagMgr_SCom_ResetNTCStatus_Start
 *  Rte_Runnable_Ap_DiagMgr9_DiagMgr_StaCtrl_Shutdown_Return
 *  Rte_Runnable_Ap_DiagMgr9_DiagMgr_StaCtrl_Shutdown_Start
 *  Rte_Runnable_Ap_DiagMgr9_DiagMgr_Trns1_Return
 *  Rte_Runnable_Ap_DiagMgr9_DiagMgr_Trns1_Start
 *  Rte_Runnable_Ap_DiagMgr9_NxtrDiagMgr9_GetNTCActive_Return
 *  Rte_Runnable_Ap_DiagMgr9_NxtrDiagMgr9_GetNTCActive_Start
 *  Rte_Runnable_Ap_DiagMgr9_NxtrDiagMgr9_GetNTCFailed_Return
 *  Rte_Runnable_Ap_DiagMgr9_NxtrDiagMgr9_GetNTCFailed_Start
 *  Rte_Runnable_Ap_DiagMgr9_NxtrDiagMgr9_GetNTCStatus_Return
 *  Rte_Runnable_Ap_DiagMgr9_NxtrDiagMgr9_GetNTCStatus_Start
 *  Rte_Runnable_Ap_DiagMgr9_NxtrDiagMgr9_SetNTCStatus_Return
 *  Rte_Runnable_Ap_DiagMgr9_NxtrDiagMgr9_SetNTCStatus_Start
 *  Rte_Runnable_Ap_DigPhsReasDiag_DigPhsReasDiag_Init_Return
 *  Rte_Runnable_Ap_DigPhsReasDiag_DigPhsReasDiag_Init_Start
 *  Rte_Runnable_Ap_DigPhsReasDiag_DigPhsReasDiag_Per1_Return
 *  Rte_Runnable_Ap_DigPhsReasDiag_DigPhsReasDiag_Per1_Start
 *  Rte_Runnable_Ap_DigPhsReasDiag_DigPhsReasDiag_Trans1_Return
 *  Rte_Runnable_Ap_DigPhsReasDiag_DigPhsReasDiag_Trans1_Start
 *  Rte_Runnable_Ap_EOTActuatorMng_EOTActuatorMng_Per1_Return
 *  Rte_Runnable_Ap_EOTActuatorMng_EOTActuatorMng_Per1_Start
 *  Rte_Runnable_Ap_ElePwr_ElePwr_Per1_Return
 *  Rte_Runnable_Ap_ElePwr_ElePwr_Per1_Start
 *  Rte_Runnable_Ap_FrqDepDmpnInrtCmp_FrqDepDmpnInrtCmp_Init_Return
 *  Rte_Runnable_Ap_FrqDepDmpnInrtCmp_FrqDepDmpnInrtCmp_Init_Start
 *  Rte_Runnable_Ap_FrqDepDmpnInrtCmp_FrqDepDmpnInrtCmp_Per1_Return
 *  Rte_Runnable_Ap_FrqDepDmpnInrtCmp_FrqDepDmpnInrtCmp_Per1_Start
 *  Rte_Runnable_Ap_Gsod_Gsod_Per1_Return
 *  Rte_Runnable_Ap_Gsod_Gsod_Per1_Start
 *  Rte_Runnable_Ap_HaLFTO_HaLFTO_Init1_Return
 *  Rte_Runnable_Ap_HaLFTO_HaLFTO_Init1_Start
 *  Rte_Runnable_Ap_HaLFTO_HaLFTO_Per1_Return
 *  Rte_Runnable_Ap_HaLFTO_HaLFTO_Per1_Start
 *  Rte_Runnable_Ap_HiLoadStall_HiLoadStall_Per1_Return
 *  Rte_Runnable_Ap_HiLoadStall_HiLoadStall_Per1_Start
 *  Rte_Runnable_Ap_HighFreqAssist_HighFreqAssist_Per1_Return
 *  Rte_Runnable_Ap_HighFreqAssist_HighFreqAssist_Per1_Start
 *  Rte_Runnable_Ap_HwPwUp_HwPwUp_Per1_Return
 *  Rte_Runnable_Ap_HwPwUp_HwPwUp_Per1_Start
 *  Rte_Runnable_Ap_HwPwUp_HwPwUp_Trns1_Return
 *  Rte_Runnable_Ap_HwPwUp_HwPwUp_Trns1_Start
 *  Rte_Runnable_Ap_HwPwUp_HwPwUp_Trns2_Return
 *  Rte_Runnable_Ap_HwPwUp_HwPwUp_Trns2_Start
 *  Rte_Runnable_Ap_HystComp_HystComp_Init1_Return
 *  Rte_Runnable_Ap_HystComp_HystComp_Init1_Start
 *  Rte_Runnable_Ap_HystComp_HystComp_Per1_Return
 *  Rte_Runnable_Ap_HystComp_HystComp_Per1_Start
 *  Rte_Runnable_Ap_LmtCod_LmtCod_Per1_Return
 *  Rte_Runnable_Ap_LmtCod_LmtCod_Per1_Start
 *  Rte_Runnable_Ap_LrnEOT_LrnEOT_Init1_Return
 *  Rte_Runnable_Ap_LrnEOT_LrnEOT_Init1_Start
 *  Rte_Runnable_Ap_LrnEOT_LrnEOT_Per1_Return
 *  Rte_Runnable_Ap_LrnEOT_LrnEOT_Per1_Start
 *  Rte_Runnable_Ap_LrnEOT_LrnEOT_Scom_ResetEOT_Return
 *  Rte_Runnable_Ap_LrnEOT_LrnEOT_Scom_ResetEOT_Start
 *  Rte_Runnable_Ap_MtrTempEst_MtrTempEst_Init1_Return
 *  Rte_Runnable_Ap_MtrTempEst_MtrTempEst_Init1_Start
 *  Rte_Runnable_Ap_MtrTempEst_MtrTempEst_Per1_Return
 *  Rte_Runnable_Ap_MtrTempEst_MtrTempEst_Per1_Start
 *  Rte_Runnable_Ap_PAwTO_PAwTO_Init1_Return
 *  Rte_Runnable_Ap_PAwTO_PAwTO_Init1_Start
 *  Rte_Runnable_Ap_PAwTO_PAwTO_Per1_Return
 *  Rte_Runnable_Ap_PAwTO_PAwTO_Per1_Start
 *  Rte_Runnable_Ap_PAwTO_PAwTO_Per2_Return
 *  Rte_Runnable_Ap_PAwTO_PAwTO_Per2_Start
 *  Rte_Runnable_Ap_PICurrCntrl_PICurrCntrl_Per2_Return
 *  Rte_Runnable_Ap_PICurrCntrl_PICurrCntrl_Per2_Start
 *  Rte_Runnable_Ap_PeakCurrEst_PeakCurrEst_Per1_Return
 *  Rte_Runnable_Ap_PeakCurrEst_PeakCurrEst_Per1_Start
 *  Rte_Runnable_Ap_PeakCurrEst_PeakCurrEst_Per2_Return
 *  Rte_Runnable_Ap_PeakCurrEst_PeakCurrEst_Per2_Start
 *  Rte_Runnable_Ap_Polarity_Polarity_Init1_Return
 *  Rte_Runnable_Ap_Polarity_Polarity_Init1_Start
 *  Rte_Runnable_Ap_Polarity_Polarity_Per1_Return
 *  Rte_Runnable_Ap_Polarity_Polarity_Per1_Start
 *  Rte_Runnable_Ap_Polarity_Polarity_SCom_ReadPolarity_Return
 *  Rte_Runnable_Ap_Polarity_Polarity_SCom_ReadPolarity_Start
 *  Rte_Runnable_Ap_Polarity_Polarity_SCom_SetPolarity_Return
 *  Rte_Runnable_Ap_Polarity_Polarity_SCom_SetPolarity_Start
 *  Rte_Runnable_Ap_PwrLmtFuncCr_PwrLmtFuncCr_Init1_Return
 *  Rte_Runnable_Ap_PwrLmtFuncCr_PwrLmtFuncCr_Init1_Start
 *  Rte_Runnable_Ap_PwrLmtFuncCr_PwrLmtFuncCr_Per1_Return
 *  Rte_Runnable_Ap_PwrLmtFuncCr_PwrLmtFuncCr_Per1_Start
 *  Rte_Runnable_Ap_PwrLmtFuncCr_PwrLmtFuncCr_Per2_Return
 *  Rte_Runnable_Ap_PwrLmtFuncCr_PwrLmtFuncCr_Per2_Start
 *  Rte_Runnable_Ap_QuadDet_QuadDet_Per1_Return
 *  Rte_Runnable_Ap_QuadDet_QuadDet_Per1_Start
 *  Rte_Runnable_Ap_ReturnFirewall_ReturnFirewall_Per1_Return
 *  Rte_Runnable_Ap_ReturnFirewall_ReturnFirewall_Per1_Start
 *  Rte_Runnable_Ap_Return_Return_Per1_Return
 *  Rte_Runnable_Ap_Return_Return_Per1_Start
 *  Rte_Runnable_Ap_SignlCondn_SignlCondn_Per1_Return
 *  Rte_Runnable_Ap_SignlCondn_SignlCondn_Per1_Start
 *  Rte_Runnable_Ap_SrlComInput_FaultInjection_FltInjection_Return
 *  Rte_Runnable_Ap_SrlComInput_FaultInjection_FltInjection_Start
 *  Rte_Runnable_Ap_SrlComInput_HaLFState_SCom_Transition_Return
 *  Rte_Runnable_Ap_SrlComInput_HaLFState_SCom_Transition_Start
 *  Rte_Runnable_Ap_SrlComInput_PrkAssistState_SCom_Transition_Return
 *  Rte_Runnable_Ap_SrlComInput_PrkAssistState_SCom_Transition_Start
 *  Rte_Runnable_Ap_SrlComInput_SrlComInput_Init_Return
 *  Rte_Runnable_Ap_SrlComInput_SrlComInput_Init_Start
 *  Rte_Runnable_Ap_SrlComInput_SrlComInput_Per1_Return
 *  Rte_Runnable_Ap_SrlComInput_SrlComInput_Per1_Start
 *  Rte_Runnable_Ap_SrlComInput_SrlComInput_SCom_ManualVehSpd_Return
 *  Rte_Runnable_Ap_SrlComInput_SrlComInput_SCom_ManualVehSpd_Start
 *  Rte_Runnable_Ap_SrlComOutput_SrlComOutput_Init1_Return
 *  Rte_Runnable_Ap_SrlComOutput_SrlComOutput_Init1_Start
 *  Rte_Runnable_Ap_SrlComOutput_SrlComOutput_Per1_Return
 *  Rte_Runnable_Ap_SrlComOutput_SrlComOutput_Per1_Start
 *  Rte_Runnable_Ap_StOpCtrl_StOpCtrl_Per1_Return
 *  Rte_Runnable_Ap_StOpCtrl_StOpCtrl_Per1_Start
 *  Rte_Runnable_Ap_StaMd8_MilestoneRqst8_WarmInitMilestoneComplete_Return
 *  Rte_Runnable_Ap_StaMd8_MilestoneRqst8_WarmInitMilestoneComplete_Start
 *  Rte_Runnable_Ap_StaMd8_MilestoneRqst8_WarmInitMilestoneNotComplete_Return
 *  Rte_Runnable_Ap_StaMd8_MilestoneRqst8_WarmInitMilestoneNotComplete_Start
 *  Rte_Runnable_Ap_StaMd8_StaMd8_Per1_Return
 *  Rte_Runnable_Ap_StaMd8_StaMd8_Per1_Start
 *  Rte_Runnable_Ap_StaMd9_MilestoneRqst9_WarmInitMilestoneComplete_Return
 *  Rte_Runnable_Ap_StaMd9_MilestoneRqst9_WarmInitMilestoneComplete_Start
 *  Rte_Runnable_Ap_StaMd9_MilestoneRqst9_WarmInitMilestoneNotComplete_Return
 *  Rte_Runnable_Ap_StaMd9_MilestoneRqst9_WarmInitMilestoneNotComplete_Start
 *  Rte_Runnable_Ap_StaMd9_StaMd9_Per1_Return
 *  Rte_Runnable_Ap_StaMd9_StaMd9_Per1_Start
 *  Rte_Runnable_Ap_StaMd9_StaMd9_Trns_DemShutdown_Return
 *  Rte_Runnable_Ap_StaMd9_StaMd9_Trns_DemShutdown_Start
 *  Rte_Runnable_Ap_StaMd9_StaMd_SCom_EcuReset_Return
 *  Rte_Runnable_Ap_StaMd9_StaMd_SCom_EcuReset_Start
 *  Rte_Runnable_Ap_StaMd_MilestoneRqst_WarmInitMilestoneComplete_Return
 *  Rte_Runnable_Ap_StaMd_MilestoneRqst_WarmInitMilestoneComplete_Start
 *  Rte_Runnable_Ap_StaMd_MilestoneRqst_WarmInitMilestoneNotComplete_Return
 *  Rte_Runnable_Ap_StaMd_MilestoneRqst_WarmInitMilestoneNotComplete_Start
 *  Rte_Runnable_Ap_StaMd_StaMd_Init1_Return
 *  Rte_Runnable_Ap_StaMd_StaMd_Init1_Start
 *  Rte_Runnable_Ap_StaMd_StaMd_Per1_Return
 *  Rte_Runnable_Ap_StaMd_StaMd_Per1_Start
 *  Rte_Runnable_Ap_StaMd_StaMd_Trns1_Return
 *  Rte_Runnable_Ap_StaMd_StaMd_Trns1_Start
 *  Rte_Runnable_Ap_StabilityComp2_StabilityComp2_Init1_Return
 *  Rte_Runnable_Ap_StabilityComp2_StabilityComp2_Init1_Start
 *  Rte_Runnable_Ap_StabilityComp2_StabilityComp2_Per1_Return
 *  Rte_Runnable_Ap_StabilityComp2_StabilityComp2_Per1_Start
 *  Rte_Runnable_Ap_StabilityComp_StabilityComp_Init1_Return
 *  Rte_Runnable_Ap_StabilityComp_StabilityComp_Init1_Start
 *  Rte_Runnable_Ap_StabilityComp_StabilityComp_Per1_Return
 *  Rte_Runnable_Ap_StabilityComp_StabilityComp_Per1_Start
 *  Rte_Runnable_Ap_StbCTO_StbCTO_Init1_Return
 *  Rte_Runnable_Ap_StbCTO_StbCTO_Init1_Start
 *  Rte_Runnable_Ap_StbCTO_StbCTO_Per1_Return
 *  Rte_Runnable_Ap_StbCTO_StbCTO_Per1_Start
 *  Rte_Runnable_Ap_ThrmlDutyCycle_ThrmlDutyCycle_Init1_Return
 *  Rte_Runnable_Ap_ThrmlDutyCycle_ThrmlDutyCycle_Init1_Start
 *  Rte_Runnable_Ap_ThrmlDutyCycle_ThrmlDutyCycle_Per1_Return
 *  Rte_Runnable_Ap_ThrmlDutyCycle_ThrmlDutyCycle_Per1_Start
 *  Rte_Runnable_Ap_TqRsDg_TqRsDg_Init1_Return
 *  Rte_Runnable_Ap_TqRsDg_TqRsDg_Init1_Start
 *  Rte_Runnable_Ap_TqRsDg_TqRsDg_Per1_Return
 *  Rte_Runnable_Ap_TqRsDg_TqRsDg_Per1_Start
 *  Rte_Runnable_Ap_TrqCanc_TrqCanc_Init_Return
 *  Rte_Runnable_Ap_TrqCanc_TrqCanc_Init_Start
 *  Rte_Runnable_Ap_TrqCanc_TrqCanc_Per1_Return
 *  Rte_Runnable_Ap_TrqCanc_TrqCanc_Per1_Start
 *  Rte_Runnable_Ap_TrqCanc_TrqCanc_Scom_ReadCogTrqCal_Return
 *  Rte_Runnable_Ap_TrqCanc_TrqCanc_Scom_ReadCogTrqCal_Start
 *  Rte_Runnable_Ap_TrqCanc_TrqCanc_Scom_SetCogTrqCal_Return
 *  Rte_Runnable_Ap_TrqCanc_TrqCanc_Scom_SetCogTrqCal_Start
 *  Rte_Runnable_Ap_TrqCmdScl_TrqCmdScl_Per1_Return
 *  Rte_Runnable_Ap_TrqCmdScl_TrqCmdScl_Per1_Start
 *  Rte_Runnable_Ap_TrqCmdScl_TrqCmdScl_SCom_Get_Return
 *  Rte_Runnable_Ap_TrqCmdScl_TrqCmdScl_SCom_Get_Start
 *  Rte_Runnable_Ap_TrqCmdScl_TrqCmdScl_SCom_Set_Return
 *  Rte_Runnable_Ap_TrqCmdScl_TrqCmdScl_SCom_Set_Start
 *  Rte_Runnable_Ap_TuningSelAuth_TuningSelAuth_Init1_Return
 *  Rte_Runnable_Ap_TuningSelAuth_TuningSelAuth_Init1_Start
 *  Rte_Runnable_Ap_TuningSelAuth_TuningSelAuth_Per1_Return
 *  Rte_Runnable_Ap_TuningSelAuth_TuningSelAuth_Per1_Start
 *  Rte_Runnable_Ap_VehPwrMd_VehPwrMd_Init1_Return
 *  Rte_Runnable_Ap_VehPwrMd_VehPwrMd_Init1_Start
 *  Rte_Runnable_Ap_VehPwrMd_VehPwrMd_Per1_Return
 *  Rte_Runnable_Ap_VehPwrMd_VehPwrMd_Per1_Start
 *  Rte_Runnable_Ap_VehSpdLmt_VehSpdLmt_Per1_Return
 *  Rte_Runnable_Ap_VehSpdLmt_VehSpdLmt_Per1_Start
 *  Rte_Runnable_Ap_WIRInputQual_WIRInputQual_Per1_Return
 *  Rte_Runnable_Ap_WIRInputQual_WIRInputQual_Per1_Start
 *  Rte_Runnable_Ap_WhlImbRej_WhlImbRej_Init1_Return
 *  Rte_Runnable_Ap_WhlImbRej_WhlImbRej_Init1_Start
 *  Rte_Runnable_Ap_WhlImbRej_WhlImbRej_Per1_Return
 *  Rte_Runnable_Ap_WhlImbRej_WhlImbRej_Per1_Start
 *  Rte_Runnable_Ap_WhlImbRej_WhlImbRej_Per2_Return
 *  Rte_Runnable_Ap_WhlImbRej_WhlImbRej_Per2_Start
 *  Rte_Runnable_Ap_WhlImbRej_WhlImbRej_Per3_Return
 *  Rte_Runnable_Ap_WhlImbRej_WhlImbRej_Per3_Start
 *  Rte_Runnable_Ap_WhlImbRej_WhlImbRej_SCom_GetWIRInfo_Return
 *  Rte_Runnable_Ap_WhlImbRej_WhlImbRej_SCom_GetWIRInfo_Start
 *  Rte_Runnable_Ap_ePWM2_ePWM2_Trns1_Return
 *  Rte_Runnable_Ap_ePWM2_ePWM2_Trns1_Start
 *  Rte_Runnable_Ap_ePWM2_ePWM2_Trns2_Return
 *  Rte_Runnable_Ap_ePWM2_ePWM2_Trns2_Start
 *  Rte_Runnable_CDD_CDDPorts_ApplyMtrElecMechPol_Return
 *  Rte_Runnable_CDD_CDDPorts_ApplyMtrElecMechPol_Start
 *  Rte_Runnable_CDD_CDDPorts_ClearPhsReasSum_Return
 *  Rte_Runnable_CDD_CDDPorts_ClearPhsReasSum_Start
 *  Rte_Runnable_CDD_Cdd_Mainfunction_Return
 *  Rte_Runnable_CDD_Cdd_Mainfunction_Start
 *  Rte_Runnable_Ccl_CclPollingTask_Return
 *  Rte_Runnable_Ccl_CclPollingTask_Start
 *  Rte_Runnable_Ccl_Ccl_10_0msTaskCont_Return
 *  Rte_Runnable_Ccl_Ccl_10_0msTaskCont_Start
 *  Rte_Runnable_Ccl_Ccl_10_2msTaskCont_Return
 *  Rte_Runnable_Ccl_Ccl_10_2msTaskCont_Start
 *  Rte_Runnable_Ccl_Ccl_2_0msTaskCont_Return
 *  Rte_Runnable_Ccl_Ccl_2_0msTaskCont_Start
 *  Rte_Runnable_Cd_uDiag_uDiagECC_Per_Return
 *  Rte_Runnable_Cd_uDiag_uDiagECC_Per_Start
 *  Rte_Runnable_Cd_uDiag_uDiagLossOfExec_Per2_Return
 *  Rte_Runnable_Cd_uDiag_uDiagLossOfExec_Per2_Start
 *  Rte_Runnable_Cd_uDiag_uDiagLossOfExec_Per3_Return
 *  Rte_Runnable_Cd_uDiag_uDiagLossOfExec_Per3_Start
 *  Rte_Runnable_Cd_uDiag_uDiagResetHandler_Init_Return
 *  Rte_Runnable_Cd_uDiag_uDiagResetHandler_Init_Start
 *  Rte_Runnable_Cd_uDiag_uDiagStaticRegs_Per_Return
 *  Rte_Runnable_Cd_uDiag_uDiagStaticRegs_Per_Start
 *  Rte_Runnable_Cd_uDiag_uDiagVIM_Per_Return
 *  Rte_Runnable_Cd_uDiag_uDiagVIM_Per_Start
 *  Rte_Runnable_Dem_Dem_MainFunction_Return
 *  Rte_Runnable_Dem_Dem_MainFunction_Start
 *  Rte_Runnable_Dem_GetDTCOfEvent_Return
 *  Rte_Runnable_Dem_GetDTCOfEvent_Start
 *  Rte_Runnable_Dem_GetEventFailed_Return
 *  Rte_Runnable_Dem_GetEventFailed_Start
 *  Rte_Runnable_Dem_GetEventStatus_Return
 *  Rte_Runnable_Dem_GetEventStatus_Start
 *  Rte_Runnable_Dem_GetEventTested_Return
 *  Rte_Runnable_Dem_GetEventTested_Start
 *  Rte_Runnable_Dem_GetFaultDetectionCounter_Return
 *  Rte_Runnable_Dem_GetFaultDetectionCounter_Start
 *  Rte_Runnable_Dem_GetIndicatorStatus_Return
 *  Rte_Runnable_Dem_GetIndicatorStatus_Start
 *  Rte_Runnable_Dem_ResetEventStatus_Return
 *  Rte_Runnable_Dem_ResetEventStatus_Start
 *  Rte_Runnable_Dem_SetEventStatus_Return
 *  Rte_Runnable_Dem_SetEventStatus_Start
 *  Rte_Runnable_Dem_SetOperationCycleState_Return
 *  Rte_Runnable_Dem_SetOperationCycleState_Start
 *  Rte_Runnable_EcuM_EcuM_MainFunction_Return
 *  Rte_Runnable_EcuM_EcuM_MainFunction_Start
 *  Rte_Runnable_EcuM_GetState_Return
 *  Rte_Runnable_EcuM_GetState_Start
 *  Rte_Runnable_EcuM_ReleasePOSTRUN_Return
 *  Rte_Runnable_EcuM_ReleasePOSTRUN_Start
 *  Rte_Runnable_EcuM_ReleaseRUN_Return
 *  Rte_Runnable_EcuM_ReleaseRUN_Start
 *  Rte_Runnable_EcuM_RequestPOSTRUN_Return
 *  Rte_Runnable_EcuM_RequestPOSTRUN_Start
 *  Rte_Runnable_EcuM_RequestRUN_Return
 *  Rte_Runnable_EcuM_RequestRUN_Start
 *  Rte_Runnable_IoHwAbstractionUsr_IoHwAb_FdbkPathAdc_Return
 *  Rte_Runnable_IoHwAbstractionUsr_IoHwAb_FdbkPathAdc_Start
 *  Rte_Runnable_IoHwAbstractionUsr_IoHwAb_FwdPathAdc_Return
 *  Rte_Runnable_IoHwAbstractionUsr_IoHwAb_FwdPathAdc_Start
 *  Rte_Runnable_IoHwAbstractionUsr_IoHwAb_Init_Return
 *  Rte_Runnable_IoHwAbstractionUsr_IoHwAb_Init_Start
 *  Rte_Runnable_IoHwAbstraction_IoHwAb_GetEpsEn_Return
 *  Rte_Runnable_IoHwAbstraction_IoHwAb_GetEpsEn_Start
 *  Rte_Runnable_IoHwAbstraction_IoHwAb_GetFetDrvCntl_Return
 *  Rte_Runnable_IoHwAbstraction_IoHwAb_GetFetDrvCntl_Start
 *  Rte_Runnable_IoHwAbstraction_IoHwAb_GetFetDrvReset_Return
 *  Rte_Runnable_IoHwAbstraction_IoHwAb_GetFetDrvReset_Start
 *  Rte_Runnable_IoHwAbstraction_IoHwAb_GetFetFlt1Data_Return
 *  Rte_Runnable_IoHwAbstraction_IoHwAb_GetFetFlt1Data_Start
 *  Rte_Runnable_IoHwAbstraction_IoHwAb_GetFetFlt2Clk_Return
 *  Rte_Runnable_IoHwAbstraction_IoHwAb_GetFetFlt2Clk_Start
 *  Rte_Runnable_IoHwAbstraction_IoHwAb_GetOvrVoltFdbk_Return
 *  Rte_Runnable_IoHwAbstraction_IoHwAb_GetOvrVoltFdbk_Start
 *  Rte_Runnable_IoHwAbstraction_IoHwAb_GetPwrSwitchEn_Return
 *  Rte_Runnable_IoHwAbstraction_IoHwAb_GetPwrSwitchEn_Start
 *  Rte_Runnable_IoHwAbstraction_IoHwAb_GetSysFault2_Return
 *  Rte_Runnable_IoHwAbstraction_IoHwAb_GetSysFault2_Start
 *  Rte_Runnable_IoHwAbstraction_IoHwAb_MainFunctionDummy_Return
 *  Rte_Runnable_IoHwAbstraction_IoHwAb_MainFunctionDummy_Start
 *  Rte_Runnable_IoHwAbstraction_IoHwAb_OP_GET_Return
 *  Rte_Runnable_IoHwAbstraction_IoHwAb_OP_GET_Start
 *  Rte_Runnable_IoHwAbstraction_IoHwAb_OP_SET_Return
 *  Rte_Runnable_IoHwAbstraction_IoHwAb_OP_SET_Start
 *  Rte_Runnable_IoHwAbstraction_IoHwAb_SetFetDrvReset_Return
 *  Rte_Runnable_IoHwAbstraction_IoHwAb_SetFetDrvReset_Start
 *  Rte_Runnable_IoHwAbstraction_IoHwAb_SetFetFlt2Clk_Return
 *  Rte_Runnable_IoHwAbstraction_IoHwAb_SetFetFlt2Clk_Start
 *  Rte_Runnable_IoHwAbstraction_IoHwAb_SetFetFlt2ToOutput_Return
 *  Rte_Runnable_IoHwAbstraction_IoHwAb_SetFetFlt2ToOutput_Start
 *  Rte_Runnable_IoHwAbstraction_IoHwAb_SetSysFault2_Return
 *  Rte_Runnable_IoHwAbstraction_IoHwAb_SetSysFault2_Start
 *  Rte_Runnable_IoHwAbstraction_IoHwAb_SetTODReset_Return
 *  Rte_Runnable_IoHwAbstraction_IoHwAb_SetTODReset_Start
 *  Rte_Runnable_IoHwAbstraction_IoHwAb_SetTcCS_Return
 *  Rte_Runnable_IoHwAbstraction_IoHwAb_SetTcCS_Start
 *  Rte_Runnable_IoHwAbstraction_IoHwAb_SetTcMCLR_Return
 *  Rte_Runnable_IoHwAbstraction_IoHwAb_SetTcMCLR_Start
 *  Rte_Runnable_IoHwAbstraction_IoHwAb_SetWdMonitor_Return
 *  Rte_Runnable_IoHwAbstraction_IoHwAb_SetWdMonitor_Start
 *  Rte_Runnable_IoHwAbstraction_IoHwAb_SetWdReset_Return
 *  Rte_Runnable_IoHwAbstraction_IoHwAb_SetWdReset_Start
 *  Rte_Runnable_NexteerLibs_DtrmnElapsedTime_mS_u16_Return
 *  Rte_Runnable_NexteerLibs_DtrmnElapsedTime_mS_u16_Start
 *  Rte_Runnable_NexteerLibs_DtrmnElapsedTime_mS_u32_Return
 *  Rte_Runnable_NexteerLibs_DtrmnElapsedTime_mS_u32_Start
 *  Rte_Runnable_NexteerLibs_DtrmnElapsedTime_uS_u16_Return
 *  Rte_Runnable_NexteerLibs_DtrmnElapsedTime_uS_u16_Start
 *  Rte_Runnable_NexteerLibs_DtrmnElapsedTime_uS_u32_Return
 *  Rte_Runnable_NexteerLibs_DtrmnElapsedTime_uS_u32_Start
 *  Rte_Runnable_NexteerLibs_GetSystemTime_mS_u32_Return
 *  Rte_Runnable_NexteerLibs_GetSystemTime_mS_u32_Start
 *  Rte_Runnable_NexteerLibs_GetSystemTime_uS_u32_Return
 *  Rte_Runnable_NexteerLibs_GetSystemTime_uS_u32_Start
 *  Rte_Runnable_NexteerLibs_SystemTime_Per1_Return
 *  Rte_Runnable_NexteerLibs_SystemTime_Per1_Start
 *  Rte_Runnable_NtWrap_AbsHwPosScom_Scom_HwPosSrvSetToZero_Return
 *  Rte_Runnable_NtWrap_AbsHwPosScom_Scom_HwPosSrvSetToZero_Start
 *  Rte_Runnable_NtWrap_AstLmt_Scom_ManualTrqCmd_Return
 *  Rte_Runnable_NtWrap_AstLmt_Scom_ManualTrqCmd_Start
 *  Rte_Runnable_NtWrap_CmMtrCurr_SCom_CalGain_Return
 *  Rte_Runnable_NtWrap_CmMtrCurr_SCom_CalGain_Start
 *  Rte_Runnable_NtWrap_CmMtrCurr_SCom_CalOffset_Return
 *  Rte_Runnable_NtWrap_CmMtrCurr_SCom_CalOffset_Start
 *  Rte_Runnable_NtWrap_CmMtrCurr_SCom_SetMtrCurrCals_Return
 *  Rte_Runnable_NtWrap_CmMtrCurr_SCom_SetMtrCurrCals_Start
 *  Rte_Runnable_NtWrap_HwTrq_SCom_ClrHwTrqScale_Return
 *  Rte_Runnable_NtWrap_HwTrq_SCom_ClrHwTrqScale_Start
 *  Rte_Runnable_NtWrap_HwTrq_SCom_ClrHwTrqTrim_Return
 *  Rte_Runnable_NtWrap_HwTrq_SCom_ClrHwTrqTrim_Start
 *  Rte_Runnable_NtWrap_HwTrq_SCom_ManualSetHwTrqTrim_Return
 *  Rte_Runnable_NtWrap_HwTrq_SCom_ManualSetHwTrqTrim_Start
 *  Rte_Runnable_NtWrap_HwTrq_SCom_SetEOLTrqStep_Return
 *  Rte_Runnable_NtWrap_HwTrq_SCom_SetEOLTrqStep_Start
 *  Rte_Runnable_NtWrap_HwTrq_SCom_SetHwTrqScale_Return
 *  Rte_Runnable_NtWrap_HwTrq_SCom_SetHwTrqScale_Start
 *  Rte_Runnable_NtWrap_HwTrq_SCom_SetHwTrqTrim_Return
 *  Rte_Runnable_NtWrap_HwTrq_SCom_SetHwTrqTrim_Start
 *  Rte_Runnable_NtWrap_MtrPos_SCom_SetEOLMtrCals_Return
 *  Rte_Runnable_NtWrap_MtrPos_SCom_SetEOLMtrCals_Start
 *  Rte_Runnable_NtWrap_NtWrap_Per1_Return
 *  Rte_Runnable_NtWrap_NtWrap_Per1_Start
 *  Rte_Runnable_NtWrap_Polarity_SCom_SetPolarity_Return
 *  Rte_Runnable_NtWrap_Polarity_SCom_SetPolarity_Start
 *  Rte_Runnable_NtWrap_SCom_EOLNomMtrParam_Set_Return
 *  Rte_Runnable_NtWrap_SCom_EOLNomMtrParam_Set_Start
 *  Rte_Runnable_NtWrap_StaMd_SCom_EcuReset_Return
 *  Rte_Runnable_NtWrap_StaMd_SCom_EcuReset_Start
 *  Rte_Runnable_NtWrap_TrqCanc_Scom_SetCogTrqCal_Return
 *  Rte_Runnable_NtWrap_TrqCanc_Scom_SetCogTrqCal_Start
 *  Rte_Runnable_NtWrap_TrqCmdScl_SCom_Set_Return
 *  Rte_Runnable_NtWrap_TrqCmdScl_SCom_Set_Start
 *  Rte_Runnable_NvMProxy_GetErrorStatus_Return
 *  Rte_Runnable_NvMProxy_GetErrorStatus_Start
 *  Rte_Runnable_NvMProxy_NvMProxy_MainFunction_Return
 *  Rte_Runnable_NvMProxy_NvMProxy_MainFunction_Start
 *  Rte_Runnable_NvMProxy_SetRamBlockStatus_Return
 *  Rte_Runnable_NvMProxy_SetRamBlockStatus_Start
 *  Rte_Runnable_NvMProxy_WriteBlock_Return
 *  Rte_Runnable_NvMProxy_WriteBlock_Start
 *  Rte_Runnable_NvM_EraseBlock_Return
 *  Rte_Runnable_NvM_EraseBlock_Start
 *  Rte_Runnable_NvM_GetErrorStatus_Return
 *  Rte_Runnable_NvM_GetErrorStatus_Start
 *  Rte_Runnable_NvM_InvalidateNvBlock_Return
 *  Rte_Runnable_NvM_InvalidateNvBlock_Start
 *  Rte_Runnable_NvM_NvM_MainFunction_Return
 *  Rte_Runnable_NvM_NvM_MainFunction_Start
 *  Rte_Runnable_NvM_ReadBlock_Return
 *  Rte_Runnable_NvM_ReadBlock_Start
 *  Rte_Runnable_NvM_SetBlockProtection_Return
 *  Rte_Runnable_NvM_SetBlockProtection_Start
 *  Rte_Runnable_NvM_SetRamBlockStatus_Return
 *  Rte_Runnable_NvM_SetRamBlockStatus_Start
 *  Rte_Runnable_NvM_WriteBlock_Return
 *  Rte_Runnable_NvM_WriteBlock_Start
 *  Rte_Runnable_RteErrata10_RteErrata10_Trns_Return
 *  Rte_Runnable_RteErrata10_RteErrata10_Trns_Start
 *  Rte_Runnable_RteErrata8_RteErrata8_Trns_Return
 *  Rte_Runnable_RteErrata8_RteErrata8_Trns_Start
 *  Rte_Runnable_RteErrata9_RteErrata9_Trns_Return
 *  Rte_Runnable_RteErrata9_RteErrata9_Trns_Start
 *  Rte_Runnable_Sa_BkCpPc_BkCpPc_Per1_Return
 *  Rte_Runnable_Sa_BkCpPc_BkCpPc_Per1_Start
 *  Rte_Runnable_Sa_BkCpPc_BkCpPc_Trns1_Return
 *  Rte_Runnable_Sa_BkCpPc_BkCpPc_Trns1_Start
 *  Rte_Runnable_Sa_BkCpPc_BkCpPc_Trns2_Return
 *  Rte_Runnable_Sa_BkCpPc_BkCpPc_Trns2_Start
 *  Rte_Runnable_Sa_BkCpPc_CapPcDcStub_OP_SET_Return
 *  Rte_Runnable_Sa_BkCpPc_CapPcDcStub_OP_SET_Start
 *  Rte_Runnable_Sa_CDDInterface_CDDInterface_Init1_Return
 *  Rte_Runnable_Sa_CDDInterface_CDDInterface_Init1_Start
 *  Rte_Runnable_Sa_CDDInterface_CDDInterface_Init2_Return
 *  Rte_Runnable_Sa_CDDInterface_CDDInterface_Init2_Start
 *  Rte_Runnable_Sa_CDDInterface_CDDInterface_Per1_Return
 *  Rte_Runnable_Sa_CDDInterface_CDDInterface_Per1_Start
 *  Rte_Runnable_Sa_CDDInterface_CDDInterface_Per2_Return
 *  Rte_Runnable_Sa_CDDInterface_CDDInterface_Per2_Start
 *  Rte_Runnable_Sa_CDDInterface_CDDInterface_Per4_Return
 *  Rte_Runnable_Sa_CDDInterface_CDDInterface_Per4_Start
 *  Rte_Runnable_Sa_CDDInterface_MtrVelCDDInterface_GetMtrVelSignals_Return
 *  Rte_Runnable_Sa_CDDInterface_MtrVelCDDInterface_GetMtrVelSignals_Start
 *  Rte_Runnable_Sa_CmMtrCurr_CmMtrCurrTempOffset_Scom_Get_Return
 *  Rte_Runnable_Sa_CmMtrCurr_CmMtrCurrTempOffset_Scom_Get_Start
 *  Rte_Runnable_Sa_CmMtrCurr_CmMtrCurrTempOffset_Scom_Set_Return
 *  Rte_Runnable_Sa_CmMtrCurr_CmMtrCurrTempOffset_Scom_Set_Start
 *  Rte_Runnable_Sa_CmMtrCurr_CmMtrCurr_Init_Return
 *  Rte_Runnable_Sa_CmMtrCurr_CmMtrCurr_Init_Start
 *  Rte_Runnable_Sa_CmMtrCurr_CmMtrCurr_Per1_Return
 *  Rte_Runnable_Sa_CmMtrCurr_CmMtrCurr_Per1_Start
 *  Rte_Runnable_Sa_CmMtrCurr_CmMtrCurr_Per2_Return
 *  Rte_Runnable_Sa_CmMtrCurr_CmMtrCurr_Per2_Start
 *  Rte_Runnable_Sa_CmMtrCurr_CmMtrCurr_Per3_Return
 *  Rte_Runnable_Sa_CmMtrCurr_CmMtrCurr_Per3_Start
 *  Rte_Runnable_Sa_CmMtrCurr_CmMtrCurr_SCom_CalGain_Return
 *  Rte_Runnable_Sa_CmMtrCurr_CmMtrCurr_SCom_CalGain_Start
 *  Rte_Runnable_Sa_CmMtrCurr_CmMtrCurr_SCom_CalOffset_Return
 *  Rte_Runnable_Sa_CmMtrCurr_CmMtrCurr_SCom_CalOffset_Start
 *  Rte_Runnable_Sa_CmMtrCurr_CmMtrCurr_SCom_MtrCurrOffReadStatus_Return
 *  Rte_Runnable_Sa_CmMtrCurr_CmMtrCurr_SCom_MtrCurrOffReadStatus_Start
 *  Rte_Runnable_Sa_CmMtrCurr_CmMtrCurr_SCom_ReadMtrCurrCals_Return
 *  Rte_Runnable_Sa_CmMtrCurr_CmMtrCurr_SCom_ReadMtrCurrCals_Start
 *  Rte_Runnable_Sa_CmMtrCurr_CmMtrCurr_SCom_SetMtrCurrCals_Return
 *  Rte_Runnable_Sa_CmMtrCurr_CmMtrCurr_SCom_SetMtrCurrCals_Start
 *  Rte_Runnable_Sa_CtrlTemp_CtrlTemp_Init1_Return
 *  Rte_Runnable_Sa_CtrlTemp_CtrlTemp_Init1_Start
 *  Rte_Runnable_Sa_CtrlTemp_CtrlTemp_Per1_Return
 *  Rte_Runnable_Sa_CtrlTemp_CtrlTemp_Per1_Start
 *  Rte_Runnable_Sa_CtrlTemp_CtrlTemp_Per2_Return
 *  Rte_Runnable_Sa_CtrlTemp_CtrlTemp_Per2_Start
 *  Rte_Runnable_Sa_HwTrq2_HwTrq2_Init1_Return
 *  Rte_Runnable_Sa_HwTrq2_HwTrq2_Init1_Start
 *  Rte_Runnable_Sa_HwTrq2_HwTrq2_Per1_Return
 *  Rte_Runnable_Sa_HwTrq2_HwTrq2_Per1_Start
 *  Rte_Runnable_Sa_HwTrq2_HwTrq2_Per2_Return
 *  Rte_Runnable_Sa_HwTrq2_HwTrq2_Per2_Start
 *  Rte_Runnable_Sa_HwTrq2_HwTrq2_Per3_Return
 *  Rte_Runnable_Sa_HwTrq2_HwTrq2_Per3_Start
 *  Rte_Runnable_Sa_HwTrq_HwTrq_Init_Return
 *  Rte_Runnable_Sa_HwTrq_HwTrq_Init_Start
 *  Rte_Runnable_Sa_HwTrq_HwTrq_Per1_Return
 *  Rte_Runnable_Sa_HwTrq_HwTrq_Per1_Start
 *  Rte_Runnable_Sa_HwTrq_HwTrq_Per2_Return
 *  Rte_Runnable_Sa_HwTrq_HwTrq_Per2_Start
 *  Rte_Runnable_Sa_HwTrq_HwTrq_Per3_Return
 *  Rte_Runnable_Sa_HwTrq_HwTrq_Per3_Start
 *  Rte_Runnable_Sa_HwTrq_HwTrq_SCom_ClrHwTrqScale_Return
 *  Rte_Runnable_Sa_HwTrq_HwTrq_SCom_ClrHwTrqScale_Start
 *  Rte_Runnable_Sa_HwTrq_HwTrq_SCom_ClrHwTrqTrim_Return
 *  Rte_Runnable_Sa_HwTrq_HwTrq_SCom_ClrHwTrqTrim_Start
 *  Rte_Runnable_Sa_HwTrq_HwTrq_SCom_ManualSetHwTrqTrim_Return
 *  Rte_Runnable_Sa_HwTrq_HwTrq_SCom_ManualSetHwTrqTrim_Start
 *  Rte_Runnable_Sa_HwTrq_HwTrq_SCom_ReadEOLTrqStep_Return
 *  Rte_Runnable_Sa_HwTrq_HwTrq_SCom_ReadEOLTrqStep_Start
 *  Rte_Runnable_Sa_HwTrq_HwTrq_SCom_ReadHwTrqScale_Return
 *  Rte_Runnable_Sa_HwTrq_HwTrq_SCom_ReadHwTrqScale_Start
 *  Rte_Runnable_Sa_HwTrq_HwTrq_SCom_ReadHwTrqTrim_Return
 *  Rte_Runnable_Sa_HwTrq_HwTrq_SCom_ReadHwTrqTrim_Start
 *  Rte_Runnable_Sa_HwTrq_HwTrq_SCom_SetEOLTrqStep_Return
 *  Rte_Runnable_Sa_HwTrq_HwTrq_SCom_SetEOLTrqStep_Start
 *  Rte_Runnable_Sa_HwTrq_HwTrq_SCom_SetHwTrqScale_Return
 *  Rte_Runnable_Sa_HwTrq_HwTrq_SCom_SetHwTrqScale_Start
 *  Rte_Runnable_Sa_HwTrq_HwTrq_SCom_SetHwTrqTrim_Return
 *  Rte_Runnable_Sa_HwTrq_HwTrq_SCom_SetHwTrqTrim_Start
 *  Rte_Runnable_Sa_MtrDrvDiag_MtrDrvDiag_Per1_Return
 *  Rte_Runnable_Sa_MtrDrvDiag_MtrDrvDiag_Per1_Start
 *  Rte_Runnable_Sa_MtrDrvDiag_MtrDrvDiag_Per2_Return
 *  Rte_Runnable_Sa_MtrDrvDiag_MtrDrvDiag_Per2_Start
 *  Rte_Runnable_Sa_MtrDrvDiag_MtrDrvDiag_Trns1_Return
 *  Rte_Runnable_Sa_MtrDrvDiag_MtrDrvDiag_Trns1_Start
 *  Rte_Runnable_Sa_MtrPos2_MtrPos2_Init1_Return
 *  Rte_Runnable_Sa_MtrPos2_MtrPos2_Init1_Start
 *  Rte_Runnable_Sa_MtrPos2_MtrPos2_Per1_Return
 *  Rte_Runnable_Sa_MtrPos2_MtrPos2_Per1_Start
 *  Rte_Runnable_Sa_MtrPos3_MtrPos3_Per1_Return
 *  Rte_Runnable_Sa_MtrPos3_MtrPos3_Per1_Start
 *  Rte_Runnable_Sa_MtrPos3_MtrPos3_Per2_Return
 *  Rte_Runnable_Sa_MtrPos3_MtrPos3_Per2_Start
 *  Rte_Runnable_Sa_MtrPos_MtrPos_Init1_Return
 *  Rte_Runnable_Sa_MtrPos_MtrPos_Init1_Start
 *  Rte_Runnable_Sa_MtrPos_MtrPos_Per2_Return
 *  Rte_Runnable_Sa_MtrPos_MtrPos_Per2_Start
 *  Rte_Runnable_Sa_MtrPos_MtrPos_SCom_ReadEOLMtrCals_Return
 *  Rte_Runnable_Sa_MtrPos_MtrPos_SCom_ReadEOLMtrCals_Start
 *  Rte_Runnable_Sa_MtrPos_MtrPos_SCom_SetEOLMtrCals_Return
 *  Rte_Runnable_Sa_MtrPos_MtrPos_SCom_SetEOLMtrCals_Start
 *  Rte_Runnable_Sa_MtrVel2_MtrVel2_Init_Return
 *  Rte_Runnable_Sa_MtrVel2_MtrVel2_Init_Start
 *  Rte_Runnable_Sa_MtrVel2_MtrVel2_Per1_Return
 *  Rte_Runnable_Sa_MtrVel2_MtrVel2_Per1_Start
 *  Rte_Runnable_Sa_MtrVel2_MtrVel2_Per2_Return
 *  Rte_Runnable_Sa_MtrVel2_MtrVel2_Per2_Start
 *  Rte_Runnable_Sa_MtrVel3_MtrVel3_Init_Return
 *  Rte_Runnable_Sa_MtrVel3_MtrVel3_Init_Start
 *  Rte_Runnable_Sa_MtrVel_MtrVel_Init1_Return
 *  Rte_Runnable_Sa_MtrVel_MtrVel_Init1_Start
 *  Rte_Runnable_Sa_MtrVel_MtrVel_Per1_Return
 *  Rte_Runnable_Sa_MtrVel_MtrVel_Per1_Start
 *  Rte_Runnable_Sa_MtrVel_MtrVel_Per2_Return
 *  Rte_Runnable_Sa_MtrVel_MtrVel_Per2_Start
 *  Rte_Runnable_Sa_OvrVoltMon_OvrVoltMon_Per1_Return
 *  Rte_Runnable_Sa_OvrVoltMon_OvrVoltMon_Per1_Start
 *  Rte_Runnable_Sa_ShtdnMech_ShtdnMech_Per1_Return
 *  Rte_Runnable_Sa_ShtdnMech_ShtdnMech_Per1_Start
 *  Rte_Runnable_Sa_TmprlMon2_TmprlMon2_Per1_Return
 *  Rte_Runnable_Sa_TmprlMon2_TmprlMon2_Per1_Start
 *  Rte_Runnable_Sa_TmprlMon_TmprlMon_Per1_Return
 *  Rte_Runnable_Sa_TmprlMon_TmprlMon_Per1_Start
 *  Rte_Runnable_Sa_TmprlMon_TmprlMon_Per2_Return
 *  Rte_Runnable_Sa_TmprlMon_TmprlMon_Per2_Start
 *  Rte_Runnable_Sa_TmprlMon_TmprlMon_Per3_Return
 *  Rte_Runnable_Sa_TmprlMon_TmprlMon_Per3_Start
 *  Rte_Runnable_Sa_TmprlMon_TmprlMon_Trns1_Return
 *  Rte_Runnable_Sa_TmprlMon_TmprlMon_Trns1_Start
 *  Rte_Runnable_Sa_TmprlMon_TmprlMon_Trns2_Return
 *  Rte_Runnable_Sa_TmprlMon_TmprlMon_Trns2_Start
 *  Rte_Runnable_WdgM_ActivateSupervisionEntity_Return
 *  Rte_Runnable_WdgM_ActivateSupervisionEntity_Start
 *  Rte_Runnable_WdgM_CheckpointReached_Return
 *  Rte_Runnable_WdgM_CheckpointReached_Start
 *  Rte_Runnable_WdgM_DeactivateSupervisionEntity_Return
 *  Rte_Runnable_WdgM_DeactivateSupervisionEntity_Start
 *  Rte_Runnable_WdgM_GetGlobalStatus_Return
 *  Rte_Runnable_WdgM_GetGlobalStatus_Start
 *  Rte_Runnable_WdgM_GetLocalStatus_Return
 *  Rte_Runnable_WdgM_GetLocalStatus_Start
 *  Rte_Runnable_WdgM_GetMode_Return
 *  Rte_Runnable_WdgM_GetMode_Start
 *  Rte_Runnable_WdgM_GlobalStateChangeCbk_Return
 *  Rte_Runnable_WdgM_GlobalStateChangeCbk_Start
 *  Rte_Runnable_WdgM_MainFunction_Return
 *  Rte_Runnable_WdgM_MainFunction_Start
 *  Rte_Runnable_WdgM_PerformReset_Return
 *  Rte_Runnable_WdgM_PerformReset_Start
 *  Rte_Runnable_WdgM_SetMode_Return
 *  Rte_Runnable_WdgM_SetMode_Start
 *  Rte_SwitchHook_Ap_StaMd8_SystemState8_Mode_Return
 *  Rte_SwitchHook_Ap_StaMd8_SystemState8_Mode_Start
 *  Rte_SwitchHook_Ap_StaMd9_SystemState9_Mode_Return
 *  Rte_SwitchHook_Ap_StaMd9_SystemState9_Mode_Start
 *  Rte_SwitchHook_Ap_StaMd_SystemState_Mode_Return
 *  Rte_SwitchHook_Ap_StaMd_SystemState_Mode_Start
 *  Rte_SwitchHook_EcuM_currentMode_currentMode_Return
 *  Rte_SwitchHook_EcuM_currentMode_currentMode_Start
 *  Rte_Task_Activate
 *  Rte_Task_Dispatch
 *  Rte_Task_SetEvent
 *  Rte_Task_WaitEvent
 *  Rte_Task_WaitEventRet
 *  Rte_WriteHook_Ap_DiagMgr10_DiagRampRate_XpmS_f32_Return
 *  Rte_WriteHook_Ap_DiagMgr10_DiagRampRate_XpmS_f32_Start
 *  Rte_WriteHook_Ap_DiagMgr10_DiagRampValue_Uls_f32_Return
 *  Rte_WriteHook_Ap_DiagMgr10_DiagRampValue_Uls_f32_Start
 *  Rte_WriteHook_Ap_DiagMgr10_DiagRmpToZeroActive_Cnt_lgc_Return
 *  Rte_WriteHook_Ap_DiagMgr10_DiagRmpToZeroActive_Cnt_lgc_Start
 *  Rte_WriteHook_Ap_DiagMgr10_DiagStsCtrldDisRmpPres_Cnt_lgc_Return
 *  Rte_WriteHook_Ap_DiagMgr10_DiagStsCtrldDisRmpPres_Cnt_lgc_Start
 *  Rte_WriteHook_Ap_DiagMgr10_DiagStsDefTemp_Cnt_lgc_Return
 *  Rte_WriteHook_Ap_DiagMgr10_DiagStsDefTemp_Cnt_lgc_Start
 *  Rte_WriteHook_Ap_DiagMgr10_DiagStsDefVehSpd_Cnt_lgc_Return
 *  Rte_WriteHook_Ap_DiagMgr10_DiagStsDefVehSpd_Cnt_lgc_Start
 *  Rte_WriteHook_Ap_DiagMgr10_DiagStsHWASbSystmFltPres_Cnt_lgc_Return
 *  Rte_WriteHook_Ap_DiagMgr10_DiagStsHWASbSystmFltPres_Cnt_lgc_Start
 *  Rte_WriteHook_Ap_DiagMgr10_DiagStsNonRecRmpToZeroFltPres_Cnt_lgc_Return
 *  Rte_WriteHook_Ap_DiagMgr10_DiagStsNonRecRmpToZeroFltPres_Cnt_lgc_Start
 *  Rte_WriteHook_Ap_DiagMgr10_DiagStsRecRmpToZeroFltPres_Cnt_lgc_Return
 *  Rte_WriteHook_Ap_DiagMgr10_DiagStsRecRmpToZeroFltPres_Cnt_lgc_Start
 *  Rte_WriteHook_Ap_DiagMgr10_DiagStsScomHWANotValid_Cnt_lgc_Return
 *  Rte_WriteHook_Ap_DiagMgr10_DiagStsScomHWANotValid_Cnt_lgc_Start
 *  Rte_WriteHook_Ap_DiagMgr10_DiagStsWIRDisable_Cnt_lgc_Return
 *  Rte_WriteHook_Ap_DiagMgr10_DiagStsWIRDisable_Cnt_lgc_Start
 *  Rte_WriteHook_Ap_Polarity_AssistAssyPolarity_Cnt_s08_Return
 *  Rte_WriteHook_Ap_Polarity_AssistAssyPolarity_Cnt_s08_Start
 *  Rte_WriteHook_Ap_Polarity_HwPosPolarity_Cnt_s08_Return
 *  Rte_WriteHook_Ap_Polarity_HwPosPolarity_Cnt_s08_Start
 *  Rte_WriteHook_Ap_Polarity_HwTrqPolarity_Cnt_s08_Return
 *  Rte_WriteHook_Ap_Polarity_HwTrqPolarity_Cnt_s08_Start
 *  Rte_WriteHook_Ap_Polarity_MtrElecMechPolarity_Cnt_s08_Return
 *  Rte_WriteHook_Ap_Polarity_MtrElecMechPolarity_Cnt_s08_Start
 *  Rte_WriteHook_Ap_Polarity_MtrPosPolarity_Cnt_s08_Return
 *  Rte_WriteHook_Ap_Polarity_MtrPosPolarity_Cnt_s08_Start
 *  Rte_WriteHook_Ap_Polarity_MtrVelPolarity_Cnt_s08_Return
 *  Rte_WriteHook_Ap_Polarity_MtrVelPolarity_Cnt_s08_Start
 *  Rte_WriteHook_Ap_Polarity_SysC_MtrElecMechPolarity_Cnt_s32_Return
 *  Rte_WriteHook_Ap_Polarity_SysC_MtrElecMechPolarity_Cnt_s32_Start
 *  Rte_WriteHook_Ap_SrlComInput_AirTempOutside_DegC_f32_Return
 *  Rte_WriteHook_Ap_SrlComInput_AirTempOutside_DegC_f32_Start
 *  Rte_WriteHook_Ap_SrlComInput_AmbTempAvg_DegC_f32_Return
 *  Rte_WriteHook_Ap_SrlComInput_AmbTempAvg_DegC_f32_Start
 *  Rte_WriteHook_Ap_SrlComInput_BattVolt_Volt_f32_Return
 *  Rte_WriteHook_Ap_SrlComInput_BattVolt_Volt_f32_Start
 *  Rte_WriteHook_Ap_SrlComInput_CMDIgnStat_Cnt_u08_Return
 *  Rte_WriteHook_Ap_SrlComInput_CMDIgnStat_Cnt_u08_Start
 *  Rte_WriteHook_Ap_SrlComInput_CanMsgReceived_Cnt_lgc_Return
 *  Rte_WriteHook_Ap_SrlComInput_CanMsgReceived_Cnt_lgc_Start
 *  Rte_WriteHook_Ap_SrlComInput_CfgStatRQ_Cnt_u08_Return
 *  Rte_WriteHook_Ap_SrlComInput_CfgStatRQ_Cnt_u08_Start
 *  Rte_WriteHook_Ap_SrlComInput_DSTEOLDisable_Cnt_lgc_Return
 *  Rte_WriteHook_Ap_SrlComInput_DSTEOLDisable_Cnt_lgc_Start
 *  Rte_WriteHook_Ap_SrlComInput_DSTEnableRqst_Cnt_lgc_Return
 *  Rte_WriteHook_Ap_SrlComInput_DSTEnableRqst_Cnt_lgc_Start
 *  Rte_WriteHook_Ap_SrlComInput_DSTErrCntrRecvLevel_Cnt_u08_Return
 *  Rte_WriteHook_Ap_SrlComInput_DSTErrCntrRecvLevel_Cnt_u08_Start
 *  Rte_WriteHook_Ap_SrlComInput_DSTExtSystemFltActive_Cnt_lgc_Return
 *  Rte_WriteHook_Ap_SrlComInput_DSTExtSystemFltActive_Cnt_lgc_Start
 *  Rte_WriteHook_Ap_SrlComInput_DSTFuncPresent_Cnt_lgc_Return
 *  Rte_WriteHook_Ap_SrlComInput_DSTFuncPresent_Cnt_lgc_Start
 *  Rte_WriteHook_Ap_SrlComInput_DSTRevGearValid_Cnt_lgc_Return
 *  Rte_WriteHook_Ap_SrlComInput_DSTRevGearValid_Cnt_lgc_Start
 *  Rte_WriteHook_Ap_SrlComInput_DSTTOCState_Uls_enum_Return
 *  Rte_WriteHook_Ap_SrlComInput_DSTTOCState_Uls_enum_Start
 *  Rte_WriteHook_Ap_SrlComInput_DSTTrqOvCmdRqst_HwNm_f32_Return
 *  Rte_WriteHook_Ap_SrlComInput_DSTTrqOvCmdRqst_HwNm_f32_Start
 *  Rte_WriteHook_Ap_SrlComInput_DSTTrqOvRqstValid_Cnt_lgc_Return
 *  Rte_WriteHook_Ap_SrlComInput_DSTTrqOvRqstValid_Cnt_lgc_Start
 *  Rte_WriteHook_Ap_SrlComInput_DesiredTunPersTypH_Cnt_u08_Return
 *  Rte_WriteHook_Ap_SrlComInput_DesiredTunPersTypH_Cnt_u08_Start
 *  Rte_WriteHook_Ap_SrlComInput_DesiredTunPers_Cnt_u16_Return
 *  Rte_WriteHook_Ap_SrlComInput_DesiredTunPers_Cnt_u16_Start
 *  Rte_WriteHook_Ap_SrlComInput_DesiredTunSet_Cnt_u16_Return
 *  Rte_WriteHook_Ap_SrlComInput_DesiredTunSet_Cnt_u16_Start
 *  Rte_WriteHook_Ap_SrlComInput_EPS_Mode_Req_Cnt_u08_Return
 *  Rte_WriteHook_Ap_SrlComInput_EPS_Mode_Req_Cnt_u08_Start
 *  Rte_WriteHook_Ap_SrlComInput_EngOilTemp_DegC_f32_Return
 *  Rte_WriteHook_Ap_SrlComInput_EngOilTemp_DegC_f32_Start
 *  Rte_WriteHook_Ap_SrlComInput_EngRPM_Cnt_u16_Return
 *  Rte_WriteHook_Ap_SrlComInput_EngRPM_Cnt_u16_Start
 *  Rte_WriteHook_Ap_SrlComInput_EssEngStop_Cnt_lgc_Return
 *  Rte_WriteHook_Ap_SrlComInput_EssEngStop_Cnt_lgc_Start
 *  Rte_WriteHook_Ap_SrlComInput_HaLFEnableRqst_Cnt_lgc_Return
 *  Rte_WriteHook_Ap_SrlComInput_HaLFEnableRqst_Cnt_lgc_Start
 *  Rte_WriteHook_Ap_SrlComInput_HaLFErrInterfaceActive_Cnt_lgc_Return
 *  Rte_WriteHook_Ap_SrlComInput_HaLFErrInterfaceActive_Cnt_lgc_Start
 *  Rte_WriteHook_Ap_SrlComInput_HaLFExtSystemFltActive_Cnt_lgc_Return
 *  Rte_WriteHook_Ap_SrlComInput_HaLFExtSystemFltActive_Cnt_lgc_Start
 *  Rte_WriteHook_Ap_SrlComInput_HaLFFuncPresent_Cnt_lgc_Return
 *  Rte_WriteHook_Ap_SrlComInput_HaLFFuncPresent_Cnt_lgc_Start
 *  Rte_WriteHook_Ap_SrlComInput_HaLFIntSystemFltActive_Cnt_lgc_Return
 *  Rte_WriteHook_Ap_SrlComInput_HaLFIntSystemFltActive_Cnt_lgc_Start
 *  Rte_WriteHook_Ap_SrlComInput_HaLFSWATrqFail_Cnt_lgc_Return
 *  Rte_WriteHook_Ap_SrlComInput_HaLFSWATrqFail_Cnt_lgc_Start
 *  Rte_WriteHook_Ap_SrlComInput_HaLFTrqOvCmdRqst_MtrNm_f32_Return
 *  Rte_WriteHook_Ap_SrlComInput_HaLFTrqOvCmdRqst_MtrNm_f32_Start
 *  Rte_WriteHook_Ap_SrlComInput_HalfTrqOvRvrsGearEngage_Cnt_lgc_Return
 *  Rte_WriteHook_Ap_SrlComInput_HalfTrqOvRvrsGearEngage_Cnt_lgc_Start
 *  Rte_WriteHook_Ap_SrlComInput_IWSSCalcVspd_Kph_f32_Return
 *  Rte_WriteHook_Ap_SrlComInput_IWSSCalcVspd_Kph_f32_Start
 *  Rte_WriteHook_Ap_SrlComInput_NET_CFG_STAT_PT_Cnt_u16_Return
 *  Rte_WriteHook_Ap_SrlComInput_NET_CFG_STAT_PT_Cnt_u16_Start
 *  Rte_WriteHook_Ap_SrlComInput_ODO_HwNmSq_f32_Return
 *  Rte_WriteHook_Ap_SrlComInput_ODO_HwNmSq_f32_Start
 *  Rte_WriteHook_Ap_SrlComInput_PAEnableRqst_Cnt_lgc_Return
 *  Rte_WriteHook_Ap_SrlComInput_PAEnableRqst_Cnt_lgc_Start
 *  Rte_WriteHook_Ap_SrlComInput_PAErrInterfaceActive_Cnt_lgc_Return
 *  Rte_WriteHook_Ap_SrlComInput_PAErrInterfaceActive_Cnt_lgc_Start
 *  Rte_WriteHook_Ap_SrlComInput_PAExtSystemFltActive_Cnt_lgc_Return
 *  Rte_WriteHook_Ap_SrlComInput_PAExtSystemFltActive_Cnt_lgc_Start
 *  Rte_WriteHook_Ap_SrlComInput_PAIntSystemFltActive_Cnt_lgc_Return
 *  Rte_WriteHook_Ap_SrlComInput_PAIntSystemFltActive_Cnt_lgc_Start
 *  Rte_WriteHook_Ap_SrlComInput_PAManoeuvrePhase_Cnt_u08_Return
 *  Rte_WriteHook_Ap_SrlComInput_PAManoeuvrePhase_Cnt_u08_Start
 *  Rte_WriteHook_Ap_SrlComInput_PATrqOvCmdRqst_HwNm_f32_Return
 *  Rte_WriteHook_Ap_SrlComInput_PATrqOvCmdRqst_HwNm_f32_Start
 *  Rte_WriteHook_Ap_SrlComInput_PAWheelCriteriaMet_Cnt_lgc_Return
 *  Rte_WriteHook_Ap_SrlComInput_PAWheelCriteriaMet_Cnt_lgc_Start
 *  Rte_WriteHook_Ap_SrlComInput_PAWhlDirRLStat_Cnt_u08_Return
 *  Rte_WriteHook_Ap_SrlComInput_PAWhlDirRLStat_Cnt_u08_Start
 *  Rte_WriteHook_Ap_SrlComInput_PAWhlDirRRStat_Cnt_u08_Return
 *  Rte_WriteHook_Ap_SrlComInput_PAWhlDirRRStat_Cnt_u08_Start
 *  Rte_WriteHook_Ap_SrlComInput_PAWhlPlsCntRLValid_Cnt_lgc_Return
 *  Rte_WriteHook_Ap_SrlComInput_PAWhlPlsCntRLValid_Cnt_lgc_Start
 *  Rte_WriteHook_Ap_SrlComInput_PAWhlPlsCntRRValid_Cnt_lgc_Return
 *  Rte_WriteHook_Ap_SrlComInput_PAWhlPlsCntRRValid_Cnt_lgc_Start
 *  Rte_WriteHook_Ap_SrlComInput_PrevHaLFEnableRqst_Cnt_lgc_Return
 *  Rte_WriteHook_Ap_SrlComInput_PrevHaLFEnableRqst_Cnt_lgc_Start
 *  Rte_WriteHook_Ap_SrlComInput_PrevHaLFTrqOvCmdRqst_MtrNm_f32_Return
 *  Rte_WriteHook_Ap_SrlComInput_PrevHaLFTrqOvCmdRqst_MtrNm_f32_Start
 *  Rte_WriteHook_Ap_SrlComInput_PrkAsstFuncPresent_Cnt_lgc_Return
 *  Rte_WriteHook_Ap_SrlComInput_PrkAsstFuncPresent_Cnt_lgc_Start
 *  Rte_WriteHook_Ap_SrlComInput_SpStPrsnt_Cnt_lgc_Return
 *  Rte_WriteHook_Ap_SrlComInput_SpStPrsnt_Cnt_lgc_Start
 *  Rte_WriteHook_Ap_SrlComInput_SrlComLWhlSpdVld_Cnt_lgc_Return
 *  Rte_WriteHook_Ap_SrlComInput_SrlComLWhlSpdVld_Cnt_lgc_Start
 *  Rte_WriteHook_Ap_SrlComInput_SrlComLWhlSpd_Hz_f32_Return
 *  Rte_WriteHook_Ap_SrlComInput_SrlComLWhlSpd_Hz_f32_Start
 *  Rte_WriteHook_Ap_SrlComInput_SrlComRWhlSpdVld_Cnt_lgc_Return
 *  Rte_WriteHook_Ap_SrlComInput_SrlComRWhlSpdVld_Cnt_lgc_Start
 *  Rte_WriteHook_Ap_SrlComInput_SrlComRWhlSpd_Hz_f32_Return
 *  Rte_WriteHook_Ap_SrlComInput_SrlComRWhlSpd_Hz_f32_Start
 *  Rte_WriteHook_Ap_SrlComInput_SrlComVehSpdValid_Cnt_lgc_Return
 *  Rte_WriteHook_Ap_SrlComInput_SrlComVehSpdValid_Cnt_lgc_Start
 *  Rte_WriteHook_Ap_SrlComInput_SrlComVehSpd_Kph_f32_Return
 *  Rte_WriteHook_Ap_SrlComInput_SrlComVehSpd_Kph_f32_Start
 *  Rte_WriteHook_Ap_SrlComInput_StrgWhlAnglValid_Cnt_lgc_Return
 *  Rte_WriteHook_Ap_SrlComInput_StrgWhlAnglValid_Cnt_lgc_Start
 *  Rte_WriteHook_Ap_SrlComInput_StrgWhlAngl_HwDeg_f32_Return
 *  Rte_WriteHook_Ap_SrlComInput_StrgWhlAngl_HwDeg_f32_Start
 *  Rte_WriteHook_Ap_SrlComInput_TrqOvReverseGearEngage_Cnt_lgc_Return
 *  Rte_WriteHook_Ap_SrlComInput_TrqOvReverseGearEngage_Cnt_lgc_Start
 *  Rte_WriteHook_Ap_SrlComInput_VCBodyStyle_Cnt_u08_Return
 *  Rte_WriteHook_Ap_SrlComInput_VCBodyStyle_Cnt_u08_Start
 *  Rte_WriteHook_Ap_SrlComInput_VCCountry_Cnt_u08_Return
 *  Rte_WriteHook_Ap_SrlComInput_VCCountry_Cnt_u08_Start
 *  Rte_WriteHook_Ap_SrlComInput_VCModelYear_Cnt_u08_Return
 *  Rte_WriteHook_Ap_SrlComInput_VCModelYear_Cnt_u08_Start
 *  Rte_WriteHook_Ap_SrlComInput_VCVehLine_Cnt_u08_Return
 *  Rte_WriteHook_Ap_SrlComInput_VCVehLine_Cnt_u08_Start
 *  Rte_WriteHook_Ap_SrlComInput_VehAccelX_KphpS_f32_Return
 *  Rte_WriteHook_Ap_SrlComInput_VehAccelX_KphpS_f32_Start
 *  Rte_WriteHook_Ap_SrlComInput_VehAccel_KphpS_f32_Return
 *  Rte_WriteHook_Ap_SrlComInput_VehAccel_KphpS_f32_Start
 *  Rte_WriteHook_Sa_CmMtrCurr_CurrentGainSvc_Cnt_lgc_Return
 *  Rte_WriteHook_Sa_CmMtrCurr_CurrentGainSvc_Cnt_lgc_Start
 *  Rte_WriteHook_Sa_HwTrq_HwTrqScaleVal_VoltsPerDeg_f32_Return
 *  Rte_WriteHook_Sa_HwTrq_HwTrqScaleVal_VoltsPerDeg_f32_Start
 *  Rte_WriteHook_Sa_HwTrq_T1TrimVal_Volt_f32_Return
 *  Rte_WriteHook_Sa_HwTrq_T1TrimVal_Volt_f32_Start
 *  Rte_WriteHook_Sa_HwTrq_T2TrimVal_Volt_f32_Return
 *  Rte_WriteHook_Sa_HwTrq_T2TrimVal_Volt_f32_Start
 *
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_HOOK_H
# define _RTE_HOOK_H

# include "Os.h"

/* Os.h Compatibility Check */
# ifndef RTE_OS_VERSION
#  if defined (OS_AR_MAJOR_VERSION) && defined (OS_AR_MINOR_VERSION)
#   define RTE_OS_VERSION ((OS_AR_MAJOR_VERSION * 10) + OS_AR_MINOR_VERSION)
#  endif
# endif

# include "Rte_Type.h"
# include "Rte_Cfg.h"

# ifndef RTE_VFB_TRACE
#  define RTE_VFB_TRACE (0)
# endif

# define RTE_START_SEC_APPL_CODE
# include "MemMap.h"

# if defined (Rte_CallHook_Ap_AbsHwPosScom_NxtrDiagMgr_SetNTCStatus_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_Ap_AbsHwPosScom_NxtrDiagMgr_SetNTCStatus_Return
# endif
# if defined (Rte_CallHook_Ap_AbsHwPosScom_NxtrDiagMgr_SetNTCStatus_Return)
#  undef Rte_CallHook_Ap_AbsHwPosScom_NxtrDiagMgr_SetNTCStatus_Return
FUNC(void, RTE_APPL_CODE) Rte_CallHook_Ap_AbsHwPosScom_NxtrDiagMgr_SetNTCStatus_Return(NTCNumber NTC_Cnt_T_enum, UInt8 Param_Cnt_T_u08, NxtrDiagMgrStatus Status_Cnt_T_enum);
# else
#  define Rte_CallHook_Ap_AbsHwPosScom_NxtrDiagMgr_SetNTCStatus_Return(arg1, arg2, arg3) ((void)(0))
# endif /* Rte_CallHook_Ap_AbsHwPosScom_NxtrDiagMgr_SetNTCStatus_Return */

# if defined (Rte_CallHook_Ap_AbsHwPosScom_NxtrDiagMgr_SetNTCStatus_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_Ap_AbsHwPosScom_NxtrDiagMgr_SetNTCStatus_Start
# endif
# if defined (Rte_CallHook_Ap_AbsHwPosScom_NxtrDiagMgr_SetNTCStatus_Start)
#  undef Rte_CallHook_Ap_AbsHwPosScom_NxtrDiagMgr_SetNTCStatus_Start
FUNC(void, RTE_APPL_CODE) Rte_CallHook_Ap_AbsHwPosScom_NxtrDiagMgr_SetNTCStatus_Start(NTCNumber NTC_Cnt_T_enum, UInt8 Param_Cnt_T_u08, NxtrDiagMgrStatus Status_Cnt_T_enum);
# else
#  define Rte_CallHook_Ap_AbsHwPosScom_NxtrDiagMgr_SetNTCStatus_Start(arg1, arg2, arg3) ((void)(0))
# endif /* Rte_CallHook_Ap_AbsHwPosScom_NxtrDiagMgr_SetNTCStatus_Start */

# if defined (Rte_CallHook_Ap_AbsHwPosScom_SystemTime_DtrmnElapsedTime_mS_u16_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_Ap_AbsHwPosScom_SystemTime_DtrmnElapsedTime_mS_u16_Return
# endif
# if defined (Rte_CallHook_Ap_AbsHwPosScom_SystemTime_DtrmnElapsedTime_mS_u16_Return)
#  undef Rte_CallHook_Ap_AbsHwPosScom_SystemTime_DtrmnElapsedTime_mS_u16_Return
FUNC(void, RTE_APPL_CODE) Rte_CallHook_Ap_AbsHwPosScom_SystemTime_DtrmnElapsedTime_mS_u16_Return(UInt32 InitialTime, P2VAR(UInt16, AUTOMATIC, RTE_AP_ABSHWPOSSCOM_APPL_VAR) ElapsedTime);
# else
#  define Rte_CallHook_Ap_AbsHwPosScom_SystemTime_DtrmnElapsedTime_mS_u16_Return(arg1, arg2) ((void)(0))
# endif /* Rte_CallHook_Ap_AbsHwPosScom_SystemTime_DtrmnElapsedTime_mS_u16_Return */

# if defined (Rte_CallHook_Ap_AbsHwPosScom_SystemTime_DtrmnElapsedTime_mS_u16_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_Ap_AbsHwPosScom_SystemTime_DtrmnElapsedTime_mS_u16_Start
# endif
# if defined (Rte_CallHook_Ap_AbsHwPosScom_SystemTime_DtrmnElapsedTime_mS_u16_Start)
#  undef Rte_CallHook_Ap_AbsHwPosScom_SystemTime_DtrmnElapsedTime_mS_u16_Start
FUNC(void, RTE_APPL_CODE) Rte_CallHook_Ap_AbsHwPosScom_SystemTime_DtrmnElapsedTime_mS_u16_Start(UInt32 InitialTime, P2VAR(UInt16, AUTOMATIC, RTE_AP_ABSHWPOSSCOM_APPL_VAR) ElapsedTime);
# else
#  define Rte_CallHook_Ap_AbsHwPosScom_SystemTime_DtrmnElapsedTime_mS_u16_Start(arg1, arg2) ((void)(0))
# endif /* Rte_CallHook_Ap_AbsHwPosScom_SystemTime_DtrmnElapsedTime_mS_u16_Start */

# if defined (Rte_CallHook_Ap_AbsHwPosScom_SystemTime_GetSystemTime_mS_u32_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_Ap_AbsHwPosScom_SystemTime_GetSystemTime_mS_u32_Return
# endif
# if defined (Rte_CallHook_Ap_AbsHwPosScom_SystemTime_GetSystemTime_mS_u32_Return)
#  undef Rte_CallHook_Ap_AbsHwPosScom_SystemTime_GetSystemTime_mS_u32_Return
FUNC(void, RTE_APPL_CODE) Rte_CallHook_Ap_AbsHwPosScom_SystemTime_GetSystemTime_mS_u32_Return(P2VAR(UInt32, AUTOMATIC, RTE_AP_ABSHWPOSSCOM_APPL_VAR) CurrentTime);
# else
#  define Rte_CallHook_Ap_AbsHwPosScom_SystemTime_GetSystemTime_mS_u32_Return(arg1) ((void)(0))
# endif /* Rte_CallHook_Ap_AbsHwPosScom_SystemTime_GetSystemTime_mS_u32_Return */

# if defined (Rte_CallHook_Ap_AbsHwPosScom_SystemTime_GetSystemTime_mS_u32_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_Ap_AbsHwPosScom_SystemTime_GetSystemTime_mS_u32_Start
# endif
# if defined (Rte_CallHook_Ap_AbsHwPosScom_SystemTime_GetSystemTime_mS_u32_Start)
#  undef Rte_CallHook_Ap_AbsHwPosScom_SystemTime_GetSystemTime_mS_u32_Start
FUNC(void, RTE_APPL_CODE) Rte_CallHook_Ap_AbsHwPosScom_SystemTime_GetSystemTime_mS_u32_Start(P2VAR(UInt32, AUTOMATIC, RTE_AP_ABSHWPOSSCOM_APPL_VAR) CurrentTime);
# else
#  define Rte_CallHook_Ap_AbsHwPosScom_SystemTime_GetSystemTime_mS_u32_Start(arg1) ((void)(0))
# endif /* Rte_CallHook_Ap_AbsHwPosScom_SystemTime_GetSystemTime_mS_u32_Start */

# if defined (Rte_CallHook_Ap_ActivePull_SystemTime_DtrmnElapsedTime_mS_u32_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_Ap_ActivePull_SystemTime_DtrmnElapsedTime_mS_u32_Return
# endif
# if defined (Rte_CallHook_Ap_ActivePull_SystemTime_DtrmnElapsedTime_mS_u32_Return)
#  undef Rte_CallHook_Ap_ActivePull_SystemTime_DtrmnElapsedTime_mS_u32_Return
FUNC(void, RTE_APPL_CODE) Rte_CallHook_Ap_ActivePull_SystemTime_DtrmnElapsedTime_mS_u32_Return(UInt32 InitialTime, P2VAR(UInt32, AUTOMATIC, RTE_AP_ACTIVEPULL_APPL_VAR) ElapsedTime);
# else
#  define Rte_CallHook_Ap_ActivePull_SystemTime_DtrmnElapsedTime_mS_u32_Return(arg1, arg2) ((void)(0))
# endif /* Rte_CallHook_Ap_ActivePull_SystemTime_DtrmnElapsedTime_mS_u32_Return */

# if defined (Rte_CallHook_Ap_ActivePull_SystemTime_DtrmnElapsedTime_mS_u32_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_Ap_ActivePull_SystemTime_DtrmnElapsedTime_mS_u32_Start
# endif
# if defined (Rte_CallHook_Ap_ActivePull_SystemTime_DtrmnElapsedTime_mS_u32_Start)
#  undef Rte_CallHook_Ap_ActivePull_SystemTime_DtrmnElapsedTime_mS_u32_Start
FUNC(void, RTE_APPL_CODE) Rte_CallHook_Ap_ActivePull_SystemTime_DtrmnElapsedTime_mS_u32_Start(UInt32 InitialTime, P2VAR(UInt32, AUTOMATIC, RTE_AP_ACTIVEPULL_APPL_VAR) ElapsedTime);
# else
#  define Rte_CallHook_Ap_ActivePull_SystemTime_DtrmnElapsedTime_mS_u32_Start(arg1, arg2) ((void)(0))
# endif /* Rte_CallHook_Ap_ActivePull_SystemTime_DtrmnElapsedTime_mS_u32_Start */

# if defined (Rte_CallHook_Ap_ActivePull_SystemTime_GetSystemTime_mS_u32_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_Ap_ActivePull_SystemTime_GetSystemTime_mS_u32_Return
# endif
# if defined (Rte_CallHook_Ap_ActivePull_SystemTime_GetSystemTime_mS_u32_Return)
#  undef Rte_CallHook_Ap_ActivePull_SystemTime_GetSystemTime_mS_u32_Return
FUNC(void, RTE_APPL_CODE) Rte_CallHook_Ap_ActivePull_SystemTime_GetSystemTime_mS_u32_Return(P2VAR(UInt32, AUTOMATIC, RTE_AP_ACTIVEPULL_APPL_VAR) CurrentTime);
# else
#  define Rte_CallHook_Ap_ActivePull_SystemTime_GetSystemTime_mS_u32_Return(arg1) ((void)(0))
# endif /* Rte_CallHook_Ap_ActivePull_SystemTime_GetSystemTime_mS_u32_Return */

# if defined (Rte_CallHook_Ap_ActivePull_SystemTime_GetSystemTime_mS_u32_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_Ap_ActivePull_SystemTime_GetSystemTime_mS_u32_Start
# endif
# if defined (Rte_CallHook_Ap_ActivePull_SystemTime_GetSystemTime_mS_u32_Start)
#  undef Rte_CallHook_Ap_ActivePull_SystemTime_GetSystemTime_mS_u32_Start
FUNC(void, RTE_APPL_CODE) Rte_CallHook_Ap_ActivePull_SystemTime_GetSystemTime_mS_u32_Start(P2VAR(UInt32, AUTOMATIC, RTE_AP_ACTIVEPULL_APPL_VAR) CurrentTime);
# else
#  define Rte_CallHook_Ap_ActivePull_SystemTime_GetSystemTime_mS_u32_Start(arg1) ((void)(0))
# endif /* Rte_CallHook_Ap_ActivePull_SystemTime_GetSystemTime_mS_u32_Start */

# if defined (Rte_CallHook_Ap_ArbLmt_ArbLmt_Per1_CP1_CheckpointReached_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_Ap_ArbLmt_ArbLmt_Per1_CP1_CheckpointReached_Return
# endif
# if defined (Rte_CallHook_Ap_ArbLmt_ArbLmt_Per1_CP1_CheckpointReached_Return)
#  undef Rte_CallHook_Ap_ArbLmt_ArbLmt_Per1_CP1_CheckpointReached_Return
FUNC(void, RTE_APPL_CODE) Rte_CallHook_Ap_ArbLmt_ArbLmt_Per1_CP1_CheckpointReached_Return(void);
# else
#  define Rte_CallHook_Ap_ArbLmt_ArbLmt_Per1_CP1_CheckpointReached_Return() ((void)(0))
# endif /* Rte_CallHook_Ap_ArbLmt_ArbLmt_Per1_CP1_CheckpointReached_Return */

# if defined (Rte_CallHook_Ap_ArbLmt_ArbLmt_Per1_CP1_CheckpointReached_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_Ap_ArbLmt_ArbLmt_Per1_CP1_CheckpointReached_Start
# endif
# if defined (Rte_CallHook_Ap_ArbLmt_ArbLmt_Per1_CP1_CheckpointReached_Start)
#  undef Rte_CallHook_Ap_ArbLmt_ArbLmt_Per1_CP1_CheckpointReached_Start
FUNC(void, RTE_APPL_CODE) Rte_CallHook_Ap_ArbLmt_ArbLmt_Per1_CP1_CheckpointReached_Start(void);
# else
#  define Rte_CallHook_Ap_ArbLmt_ArbLmt_Per1_CP1_CheckpointReached_Start() ((void)(0))
# endif /* Rte_CallHook_Ap_ArbLmt_ArbLmt_Per1_CP1_CheckpointReached_Start */

# if defined (Rte_CallHook_Ap_AssistFirewall_NxtrDiagMgr_SetNTCStatus_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_Ap_AssistFirewall_NxtrDiagMgr_SetNTCStatus_Return
# endif
# if defined (Rte_CallHook_Ap_AssistFirewall_NxtrDiagMgr_SetNTCStatus_Return)
#  undef Rte_CallHook_Ap_AssistFirewall_NxtrDiagMgr_SetNTCStatus_Return
FUNC(void, RTE_APPL_CODE) Rte_CallHook_Ap_AssistFirewall_NxtrDiagMgr_SetNTCStatus_Return(NTCNumber NTC_Cnt_T_enum, UInt8 Param_Cnt_T_u08, NxtrDiagMgrStatus Status_Cnt_T_enum);
# else
#  define Rte_CallHook_Ap_AssistFirewall_NxtrDiagMgr_SetNTCStatus_Return(arg1, arg2, arg3) ((void)(0))
# endif /* Rte_CallHook_Ap_AssistFirewall_NxtrDiagMgr_SetNTCStatus_Return */

# if defined (Rte_CallHook_Ap_AssistFirewall_NxtrDiagMgr_SetNTCStatus_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_Ap_AssistFirewall_NxtrDiagMgr_SetNTCStatus_Start
# endif
# if defined (Rte_CallHook_Ap_AssistFirewall_NxtrDiagMgr_SetNTCStatus_Start)
#  undef Rte_CallHook_Ap_AssistFirewall_NxtrDiagMgr_SetNTCStatus_Start
FUNC(void, RTE_APPL_CODE) Rte_CallHook_Ap_AssistFirewall_NxtrDiagMgr_SetNTCStatus_Start(NTCNumber NTC_Cnt_T_enum, UInt8 Param_Cnt_T_u08, NxtrDiagMgrStatus Status_Cnt_T_enum);
# else
#  define Rte_CallHook_Ap_AssistFirewall_NxtrDiagMgr_SetNTCStatus_Start(arg1, arg2, arg3) ((void)(0))
# endif /* Rte_CallHook_Ap_AssistFirewall_NxtrDiagMgr_SetNTCStatus_Start */

# if defined (Rte_CallHook_Ap_Assist_FltInjection_SCom_FltInjection_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_Ap_Assist_FltInjection_SCom_FltInjection_Return
# endif
# if defined (Rte_CallHook_Ap_Assist_FltInjection_SCom_FltInjection_Return)
#  undef Rte_CallHook_Ap_Assist_FltInjection_SCom_FltInjection_Return
FUNC(void, RTE_APPL_CODE) Rte_CallHook_Ap_Assist_FltInjection_SCom_FltInjection_Return(P2VAR(Float, AUTOMATIC, RTE_AP_ASSIST_APPL_VAR) SignalPath_Uls_f32, FltInjectionLocType LocationKey_Cnt_enum);
# else
#  define Rte_CallHook_Ap_Assist_FltInjection_SCom_FltInjection_Return(arg1, arg2) ((void)(0))
# endif /* Rte_CallHook_Ap_Assist_FltInjection_SCom_FltInjection_Return */

# if defined (Rte_CallHook_Ap_Assist_FltInjection_SCom_FltInjection_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_Ap_Assist_FltInjection_SCom_FltInjection_Start
# endif
# if defined (Rte_CallHook_Ap_Assist_FltInjection_SCom_FltInjection_Start)
#  undef Rte_CallHook_Ap_Assist_FltInjection_SCom_FltInjection_Start
FUNC(void, RTE_APPL_CODE) Rte_CallHook_Ap_Assist_FltInjection_SCom_FltInjection_Start(P2VAR(Float, AUTOMATIC, RTE_AP_ASSIST_APPL_VAR) SignalPath_Uls_f32, FltInjectionLocType LocationKey_Cnt_enum);
# else
#  define Rte_CallHook_Ap_Assist_FltInjection_SCom_FltInjection_Start(arg1, arg2) ((void)(0))
# endif /* Rte_CallHook_Ap_Assist_FltInjection_SCom_FltInjection_Start */

# if defined (Rte_CallHook_Ap_AvgFricLrn_AvgFricLrnData_WriteBlock_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_Ap_AvgFricLrn_AvgFricLrnData_WriteBlock_Return
# endif
# if defined (Rte_CallHook_Ap_AvgFricLrn_AvgFricLrnData_WriteBlock_Return)
#  undef Rte_CallHook_Ap_AvgFricLrn_AvgFricLrnData_WriteBlock_Return
FUNC(void, RTE_APPL_CODE) Rte_CallHook_Ap_AvgFricLrn_AvgFricLrnData_WriteBlock_Return(P2CONST(NvM_DestPtr, AUTOMATIC, RTE_AP_AVGFRICLRN_APPL_DATA) DstPtr);
# else
#  define Rte_CallHook_Ap_AvgFricLrn_AvgFricLrnData_WriteBlock_Return(arg1) ((void)(0))
# endif /* Rte_CallHook_Ap_AvgFricLrn_AvgFricLrnData_WriteBlock_Return */

# if defined (Rte_CallHook_Ap_AvgFricLrn_AvgFricLrnData_WriteBlock_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_Ap_AvgFricLrn_AvgFricLrnData_WriteBlock_Start
# endif
# if defined (Rte_CallHook_Ap_AvgFricLrn_AvgFricLrnData_WriteBlock_Start)
#  undef Rte_CallHook_Ap_AvgFricLrn_AvgFricLrnData_WriteBlock_Start
FUNC(void, RTE_APPL_CODE) Rte_CallHook_Ap_AvgFricLrn_AvgFricLrnData_WriteBlock_Start(P2CONST(NvM_DestPtr, AUTOMATIC, RTE_AP_AVGFRICLRN_APPL_DATA) DstPtr);
# else
#  define Rte_CallHook_Ap_AvgFricLrn_AvgFricLrnData_WriteBlock_Start(arg1) ((void)(0))
# endif /* Rte_CallHook_Ap_AvgFricLrn_AvgFricLrnData_WriteBlock_Start */

# if defined (Rte_CallHook_Ap_AvgFricLrn_FltInjection_SCom_FltInjection_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_Ap_AvgFricLrn_FltInjection_SCom_FltInjection_Return
# endif
# if defined (Rte_CallHook_Ap_AvgFricLrn_FltInjection_SCom_FltInjection_Return)
#  undef Rte_CallHook_Ap_AvgFricLrn_FltInjection_SCom_FltInjection_Return
FUNC(void, RTE_APPL_CODE) Rte_CallHook_Ap_AvgFricLrn_FltInjection_SCom_FltInjection_Return(P2VAR(Float, AUTOMATIC, RTE_AP_AVGFRICLRN_APPL_VAR) SignalPath_Uls_f32, FltInjectionLocType LocationKey_Cnt_enum);
# else
#  define Rte_CallHook_Ap_AvgFricLrn_FltInjection_SCom_FltInjection_Return(arg1, arg2) ((void)(0))
# endif /* Rte_CallHook_Ap_AvgFricLrn_FltInjection_SCom_FltInjection_Return */

# if defined (Rte_CallHook_Ap_AvgFricLrn_FltInjection_SCom_FltInjection_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_Ap_AvgFricLrn_FltInjection_SCom_FltInjection_Start
# endif
# if defined (Rte_CallHook_Ap_AvgFricLrn_FltInjection_SCom_FltInjection_Start)
#  undef Rte_CallHook_Ap_AvgFricLrn_FltInjection_SCom_FltInjection_Start
FUNC(void, RTE_APPL_CODE) Rte_CallHook_Ap_AvgFricLrn_FltInjection_SCom_FltInjection_Start(P2VAR(Float, AUTOMATIC, RTE_AP_AVGFRICLRN_APPL_VAR) SignalPath_Uls_f32, FltInjectionLocType LocationKey_Cnt_enum);
# else
#  define Rte_CallHook_Ap_AvgFricLrn_FltInjection_SCom_FltInjection_Start(arg1, arg2) ((void)(0))
# endif /* Rte_CallHook_Ap_AvgFricLrn_FltInjection_SCom_FltInjection_Start */

# if defined (Rte_CallHook_Ap_AvgFricLrn_NxtrDiagMgr_SetNTCStatus_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_Ap_AvgFricLrn_NxtrDiagMgr_SetNTCStatus_Return
# endif
# if defined (Rte_CallHook_Ap_AvgFricLrn_NxtrDiagMgr_SetNTCStatus_Return)
#  undef Rte_CallHook_Ap_AvgFricLrn_NxtrDiagMgr_SetNTCStatus_Return
FUNC(void, RTE_APPL_CODE) Rte_CallHook_Ap_AvgFricLrn_NxtrDiagMgr_SetNTCStatus_Return(NTCNumber NTC_Cnt_T_enum, UInt8 Param_Cnt_T_u08, NxtrDiagMgrStatus Status_Cnt_T_enum);
# else
#  define Rte_CallHook_Ap_AvgFricLrn_NxtrDiagMgr_SetNTCStatus_Return(arg1, arg2, arg3) ((void)(0))
# endif /* Rte_CallHook_Ap_AvgFricLrn_NxtrDiagMgr_SetNTCStatus_Return */

# if defined (Rte_CallHook_Ap_AvgFricLrn_NxtrDiagMgr_SetNTCStatus_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_Ap_AvgFricLrn_NxtrDiagMgr_SetNTCStatus_Start
# endif
# if defined (Rte_CallHook_Ap_AvgFricLrn_NxtrDiagMgr_SetNTCStatus_Start)
#  undef Rte_CallHook_Ap_AvgFricLrn_NxtrDiagMgr_SetNTCStatus_Start
FUNC(void, RTE_APPL_CODE) Rte_CallHook_Ap_AvgFricLrn_NxtrDiagMgr_SetNTCStatus_Start(NTCNumber NTC_Cnt_T_enum, UInt8 Param_Cnt_T_u08, NxtrDiagMgrStatus Status_Cnt_T_enum);
# else
#  define Rte_CallHook_Ap_AvgFricLrn_NxtrDiagMgr_SetNTCStatus_Start(arg1, arg2, arg3) ((void)(0))
# endif /* Rte_CallHook_Ap_AvgFricLrn_NxtrDiagMgr_SetNTCStatus_Start */

# if defined (Rte_CallHook_Ap_AvgFricLrn_SystemTime_DtrmnElapsedTime_mS_u32_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_Ap_AvgFricLrn_SystemTime_DtrmnElapsedTime_mS_u32_Return
# endif
# if defined (Rte_CallHook_Ap_AvgFricLrn_SystemTime_DtrmnElapsedTime_mS_u32_Return)
#  undef Rte_CallHook_Ap_AvgFricLrn_SystemTime_DtrmnElapsedTime_mS_u32_Return
FUNC(void, RTE_APPL_CODE) Rte_CallHook_Ap_AvgFricLrn_SystemTime_DtrmnElapsedTime_mS_u32_Return(UInt32 InitialTime, P2VAR(UInt32, AUTOMATIC, RTE_AP_AVGFRICLRN_APPL_VAR) ElapsedTime);
# else
#  define Rte_CallHook_Ap_AvgFricLrn_SystemTime_DtrmnElapsedTime_mS_u32_Return(arg1, arg2) ((void)(0))
# endif /* Rte_CallHook_Ap_AvgFricLrn_SystemTime_DtrmnElapsedTime_mS_u32_Return */

# if defined (Rte_CallHook_Ap_AvgFricLrn_SystemTime_DtrmnElapsedTime_mS_u32_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_Ap_AvgFricLrn_SystemTime_DtrmnElapsedTime_mS_u32_Start
# endif
# if defined (Rte_CallHook_Ap_AvgFricLrn_SystemTime_DtrmnElapsedTime_mS_u32_Start)
#  undef Rte_CallHook_Ap_AvgFricLrn_SystemTime_DtrmnElapsedTime_mS_u32_Start
FUNC(void, RTE_APPL_CODE) Rte_CallHook_Ap_AvgFricLrn_SystemTime_DtrmnElapsedTime_mS_u32_Start(UInt32 InitialTime, P2VAR(UInt32, AUTOMATIC, RTE_AP_AVGFRICLRN_APPL_VAR) ElapsedTime);
# else
#  define Rte_CallHook_Ap_AvgFricLrn_SystemTime_DtrmnElapsedTime_mS_u32_Start(arg1, arg2) ((void)(0))
# endif /* Rte_CallHook_Ap_AvgFricLrn_SystemTime_DtrmnElapsedTime_mS_u32_Start */

# if defined (Rte_CallHook_Ap_AvgFricLrn_SystemTime_GetSystemTime_mS_u32_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_Ap_AvgFricLrn_SystemTime_GetSystemTime_mS_u32_Return
# endif
# if defined (Rte_CallHook_Ap_AvgFricLrn_SystemTime_GetSystemTime_mS_u32_Return)
#  undef Rte_CallHook_Ap_AvgFricLrn_SystemTime_GetSystemTime_mS_u32_Return
FUNC(void, RTE_APPL_CODE) Rte_CallHook_Ap_AvgFricLrn_SystemTime_GetSystemTime_mS_u32_Return(P2VAR(UInt32, AUTOMATIC, RTE_AP_AVGFRICLRN_APPL_VAR) CurrentTime);
# else
#  define Rte_CallHook_Ap_AvgFricLrn_SystemTime_GetSystemTime_mS_u32_Return(arg1) ((void)(0))
# endif /* Rte_CallHook_Ap_AvgFricLrn_SystemTime_GetSystemTime_mS_u32_Return */

# if defined (Rte_CallHook_Ap_AvgFricLrn_SystemTime_GetSystemTime_mS_u32_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_Ap_AvgFricLrn_SystemTime_GetSystemTime_mS_u32_Start
# endif
# if defined (Rte_CallHook_Ap_AvgFricLrn_SystemTime_GetSystemTime_mS_u32_Start)
#  undef Rte_CallHook_Ap_AvgFricLrn_SystemTime_GetSystemTime_mS_u32_Start
FUNC(void, RTE_APPL_CODE) Rte_CallHook_Ap_AvgFricLrn_SystemTime_GetSystemTime_mS_u32_Start(P2VAR(UInt32, AUTOMATIC, RTE_AP_AVGFRICLRN_APPL_VAR) CurrentTime);
# else
#  define Rte_CallHook_Ap_AvgFricLrn_SystemTime_GetSystemTime_mS_u32_Start(arg1) ((void)(0))
# endif /* Rte_CallHook_Ap_AvgFricLrn_SystemTime_GetSystemTime_mS_u32_Start */

# if defined (Rte_CallHook_Ap_BVDiag_BVDiag_Per1_CP1_CheckpointReached_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_Ap_BVDiag_BVDiag_Per1_CP1_CheckpointReached_Return
# endif
# if defined (Rte_CallHook_Ap_BVDiag_BVDiag_Per1_CP1_CheckpointReached_Return)
#  undef Rte_CallHook_Ap_BVDiag_BVDiag_Per1_CP1_CheckpointReached_Return
FUNC(void, RTE_APPL_CODE) Rte_CallHook_Ap_BVDiag_BVDiag_Per1_CP1_CheckpointReached_Return(void);
# else
#  define Rte_CallHook_Ap_BVDiag_BVDiag_Per1_CP1_CheckpointReached_Return() ((void)(0))
# endif /* Rte_CallHook_Ap_BVDiag_BVDiag_Per1_CP1_CheckpointReached_Return */

# if defined (Rte_CallHook_Ap_BVDiag_BVDiag_Per1_CP1_CheckpointReached_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_Ap_BVDiag_BVDiag_Per1_CP1_CheckpointReached_Start
# endif
# if defined (Rte_CallHook_Ap_BVDiag_BVDiag_Per1_CP1_CheckpointReached_Start)
#  undef Rte_CallHook_Ap_BVDiag_BVDiag_Per1_CP1_CheckpointReached_Start
FUNC(void, RTE_APPL_CODE) Rte_CallHook_Ap_BVDiag_BVDiag_Per1_CP1_CheckpointReached_Start(void);
# else
#  define Rte_CallHook_Ap_BVDiag_BVDiag_Per1_CP1_CheckpointReached_Start() ((void)(0))
# endif /* Rte_CallHook_Ap_BVDiag_BVDiag_Per1_CP1_CheckpointReached_Start */

# if defined (Rte_CallHook_Ap_BVDiag_NxtrDiagMgr_SetNTCStatus_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_Ap_BVDiag_NxtrDiagMgr_SetNTCStatus_Return
# endif
# if defined (Rte_CallHook_Ap_BVDiag_NxtrDiagMgr_SetNTCStatus_Return)
#  undef Rte_CallHook_Ap_BVDiag_NxtrDiagMgr_SetNTCStatus_Return
FUNC(void, RTE_APPL_CODE) Rte_CallHook_Ap_BVDiag_NxtrDiagMgr_SetNTCStatus_Return(NTCNumber NTC_Cnt_T_enum, UInt8 Param_Cnt_T_u08, NxtrDiagMgrStatus Status_Cnt_T_enum);
# else
#  define Rte_CallHook_Ap_BVDiag_NxtrDiagMgr_SetNTCStatus_Return(arg1, arg2, arg3) ((void)(0))
# endif /* Rte_CallHook_Ap_BVDiag_NxtrDiagMgr_SetNTCStatus_Return */

# if defined (Rte_CallHook_Ap_BVDiag_NxtrDiagMgr_SetNTCStatus_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_Ap_BVDiag_NxtrDiagMgr_SetNTCStatus_Start
# endif
# if defined (Rte_CallHook_Ap_BVDiag_NxtrDiagMgr_SetNTCStatus_Start)
#  undef Rte_CallHook_Ap_BVDiag_NxtrDiagMgr_SetNTCStatus_Start
FUNC(void, RTE_APPL_CODE) Rte_CallHook_Ap_BVDiag_NxtrDiagMgr_SetNTCStatus_Start(NTCNumber NTC_Cnt_T_enum, UInt8 Param_Cnt_T_u08, NxtrDiagMgrStatus Status_Cnt_T_enum);
# else
#  define Rte_CallHook_Ap_BVDiag_NxtrDiagMgr_SetNTCStatus_Start(arg1, arg2, arg3) ((void)(0))
# endif /* Rte_CallHook_Ap_BVDiag_NxtrDiagMgr_SetNTCStatus_Start */

# if defined (Rte_CallHook_Ap_BVDiag_SystemTime_DtrmnElapsedTime_mS_u16_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_Ap_BVDiag_SystemTime_DtrmnElapsedTime_mS_u16_Return
# endif
# if defined (Rte_CallHook_Ap_BVDiag_SystemTime_DtrmnElapsedTime_mS_u16_Return)
#  undef Rte_CallHook_Ap_BVDiag_SystemTime_DtrmnElapsedTime_mS_u16_Return
FUNC(void, RTE_APPL_CODE) Rte_CallHook_Ap_BVDiag_SystemTime_DtrmnElapsedTime_mS_u16_Return(UInt32 InitialTime, P2VAR(UInt16, AUTOMATIC, RTE_AP_BVDIAG_APPL_VAR) ElapsedTime);
# else
#  define Rte_CallHook_Ap_BVDiag_SystemTime_DtrmnElapsedTime_mS_u16_Return(arg1, arg2) ((void)(0))
# endif /* Rte_CallHook_Ap_BVDiag_SystemTime_DtrmnElapsedTime_mS_u16_Return */

# if defined (Rte_CallHook_Ap_BVDiag_SystemTime_DtrmnElapsedTime_mS_u16_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_Ap_BVDiag_SystemTime_DtrmnElapsedTime_mS_u16_Start
# endif
# if defined (Rte_CallHook_Ap_BVDiag_SystemTime_DtrmnElapsedTime_mS_u16_Start)
#  undef Rte_CallHook_Ap_BVDiag_SystemTime_DtrmnElapsedTime_mS_u16_Start
FUNC(void, RTE_APPL_CODE) Rte_CallHook_Ap_BVDiag_SystemTime_DtrmnElapsedTime_mS_u16_Start(UInt32 InitialTime, P2VAR(UInt16, AUTOMATIC, RTE_AP_BVDIAG_APPL_VAR) ElapsedTime);
# else
#  define Rte_CallHook_Ap_BVDiag_SystemTime_DtrmnElapsedTime_mS_u16_Start(arg1, arg2) ((void)(0))
# endif /* Rte_CallHook_Ap_BVDiag_SystemTime_DtrmnElapsedTime_mS_u16_Start */

# if defined (Rte_CallHook_Ap_BVDiag_SystemTime_GetSystemTime_mS_u32_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_Ap_BVDiag_SystemTime_GetSystemTime_mS_u32_Return
# endif
# if defined (Rte_CallHook_Ap_BVDiag_SystemTime_GetSystemTime_mS_u32_Return)
#  undef Rte_CallHook_Ap_BVDiag_SystemTime_GetSystemTime_mS_u32_Return
FUNC(void, RTE_APPL_CODE) Rte_CallHook_Ap_BVDiag_SystemTime_GetSystemTime_mS_u32_Return(P2VAR(UInt32, AUTOMATIC, RTE_AP_BVDIAG_APPL_VAR) CurrentTime);
# else
#  define Rte_CallHook_Ap_BVDiag_SystemTime_GetSystemTime_mS_u32_Return(arg1) ((void)(0))
# endif /* Rte_CallHook_Ap_BVDiag_SystemTime_GetSystemTime_mS_u32_Return */

# if defined (Rte_CallHook_Ap_BVDiag_SystemTime_GetSystemTime_mS_u32_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_Ap_BVDiag_SystemTime_GetSystemTime_mS_u32_Start
# endif
# if defined (Rte_CallHook_Ap_BVDiag_SystemTime_GetSystemTime_mS_u32_Start)
#  undef Rte_CallHook_Ap_BVDiag_SystemTime_GetSystemTime_mS_u32_Start
FUNC(void, RTE_APPL_CODE) Rte_CallHook_Ap_BVDiag_SystemTime_GetSystemTime_mS_u32_Start(P2VAR(UInt32, AUTOMATIC, RTE_AP_BVDIAG_APPL_VAR) CurrentTime);
# else
#  define Rte_CallHook_Ap_BVDiag_SystemTime_GetSystemTime_mS_u32_Start(arg1) ((void)(0))
# endif /* Rte_CallHook_Ap_BVDiag_SystemTime_GetSystemTime_mS_u32_Start */

# if defined (Rte_CallHook_Ap_BatteryVoltage_BatteryVoltage_Per1_CP0_CheckpointReached_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_Ap_BatteryVoltage_BatteryVoltage_Per1_CP0_CheckpointReached_Return
# endif
# if defined (Rte_CallHook_Ap_BatteryVoltage_BatteryVoltage_Per1_CP0_CheckpointReached_Return)
#  undef Rte_CallHook_Ap_BatteryVoltage_BatteryVoltage_Per1_CP0_CheckpointReached_Return
FUNC(void, RTE_APPL_CODE) Rte_CallHook_Ap_BatteryVoltage_BatteryVoltage_Per1_CP0_CheckpointReached_Return(void);
# else
#  define Rte_CallHook_Ap_BatteryVoltage_BatteryVoltage_Per1_CP0_CheckpointReached_Return() ((void)(0))
# endif /* Rte_CallHook_Ap_BatteryVoltage_BatteryVoltage_Per1_CP0_CheckpointReached_Return */

# if defined (Rte_CallHook_Ap_BatteryVoltage_BatteryVoltage_Per1_CP0_CheckpointReached_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_Ap_BatteryVoltage_BatteryVoltage_Per1_CP0_CheckpointReached_Start
# endif
# if defined (Rte_CallHook_Ap_BatteryVoltage_BatteryVoltage_Per1_CP0_CheckpointReached_Start)
#  undef Rte_CallHook_Ap_BatteryVoltage_BatteryVoltage_Per1_CP0_CheckpointReached_Start
FUNC(void, RTE_APPL_CODE) Rte_CallHook_Ap_BatteryVoltage_BatteryVoltage_Per1_CP0_CheckpointReached_Start(void);
# else
#  define Rte_CallHook_Ap_BatteryVoltage_BatteryVoltage_Per1_CP0_CheckpointReached_Start() ((void)(0))
# endif /* Rte_CallHook_Ap_BatteryVoltage_BatteryVoltage_Per1_CP0_CheckpointReached_Start */

# if defined (Rte_CallHook_Ap_BatteryVoltage_FltInjection_SCom_FltInjection_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_Ap_BatteryVoltage_FltInjection_SCom_FltInjection_Return
# endif
# if defined (Rte_CallHook_Ap_BatteryVoltage_FltInjection_SCom_FltInjection_Return)
#  undef Rte_CallHook_Ap_BatteryVoltage_FltInjection_SCom_FltInjection_Return
FUNC(void, RTE_APPL_CODE) Rte_CallHook_Ap_BatteryVoltage_FltInjection_SCom_FltInjection_Return(P2VAR(Float, AUTOMATIC, RTE_AP_BATTERYVOLTAGE_APPL_VAR) SignalPath_Uls_f32, FltInjectionLocType LocationKey_Cnt_enum);
# else
#  define Rte_CallHook_Ap_BatteryVoltage_FltInjection_SCom_FltInjection_Return(arg1, arg2) ((void)(0))
# endif /* Rte_CallHook_Ap_BatteryVoltage_FltInjection_SCom_FltInjection_Return */

# if defined (Rte_CallHook_Ap_BatteryVoltage_FltInjection_SCom_FltInjection_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_Ap_BatteryVoltage_FltInjection_SCom_FltInjection_Start
# endif
# if defined (Rte_CallHook_Ap_BatteryVoltage_FltInjection_SCom_FltInjection_Start)
#  undef Rte_CallHook_Ap_BatteryVoltage_FltInjection_SCom_FltInjection_Start
FUNC(void, RTE_APPL_CODE) Rte_CallHook_Ap_BatteryVoltage_FltInjection_SCom_FltInjection_Start(P2VAR(Float, AUTOMATIC, RTE_AP_BATTERYVOLTAGE_APPL_VAR) SignalPath_Uls_f32, FltInjectionLocType LocationKey_Cnt_enum);
# else
#  define Rte_CallHook_Ap_BatteryVoltage_FltInjection_SCom_FltInjection_Start(arg1, arg2) ((void)(0))
# endif /* Rte_CallHook_Ap_BatteryVoltage_FltInjection_SCom_FltInjection_Start */

# if defined (Rte_CallHook_Ap_BatteryVoltage_NxtrDiagMgr_SetNTCStatus_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_Ap_BatteryVoltage_NxtrDiagMgr_SetNTCStatus_Return
# endif
# if defined (Rte_CallHook_Ap_BatteryVoltage_NxtrDiagMgr_SetNTCStatus_Return)
#  undef Rte_CallHook_Ap_BatteryVoltage_NxtrDiagMgr_SetNTCStatus_Return
FUNC(void, RTE_APPL_CODE) Rte_CallHook_Ap_BatteryVoltage_NxtrDiagMgr_SetNTCStatus_Return(NTCNumber NTC_Cnt_T_enum, UInt8 Param_Cnt_T_u08, NxtrDiagMgrStatus Status_Cnt_T_enum);
# else
#  define Rte_CallHook_Ap_BatteryVoltage_NxtrDiagMgr_SetNTCStatus_Return(arg1, arg2, arg3) ((void)(0))
# endif /* Rte_CallHook_Ap_BatteryVoltage_NxtrDiagMgr_SetNTCStatus_Return */

# if defined (Rte_CallHook_Ap_BatteryVoltage_NxtrDiagMgr_SetNTCStatus_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_Ap_BatteryVoltage_NxtrDiagMgr_SetNTCStatus_Start
# endif
# if defined (Rte_CallHook_Ap_BatteryVoltage_NxtrDiagMgr_SetNTCStatus_Start)
#  undef Rte_CallHook_Ap_BatteryVoltage_NxtrDiagMgr_SetNTCStatus_Start
FUNC(void, RTE_APPL_CODE) Rte_CallHook_Ap_BatteryVoltage_NxtrDiagMgr_SetNTCStatus_Start(NTCNumber NTC_Cnt_T_enum, UInt8 Param_Cnt_T_u08, NxtrDiagMgrStatus Status_Cnt_T_enum);
# else
#  define Rte_CallHook_Ap_BatteryVoltage_NxtrDiagMgr_SetNTCStatus_Start(arg1, arg2, arg3) ((void)(0))
# endif /* Rte_CallHook_Ap_BatteryVoltage_NxtrDiagMgr_SetNTCStatus_Start */

# if defined (Rte_CallHook_Ap_CtrldDisShtdn_SystemTime_DtrmnElapsedTime_mS_u16_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_Ap_CtrldDisShtdn_SystemTime_DtrmnElapsedTime_mS_u16_Return
# endif
# if defined (Rte_CallHook_Ap_CtrldDisShtdn_SystemTime_DtrmnElapsedTime_mS_u16_Return)
#  undef Rte_CallHook_Ap_CtrldDisShtdn_SystemTime_DtrmnElapsedTime_mS_u16_Return
FUNC(void, RTE_APPL_CODE) Rte_CallHook_Ap_CtrldDisShtdn_SystemTime_DtrmnElapsedTime_mS_u16_Return(UInt32 InitialTime, P2VAR(UInt16, AUTOMATIC, RTE_AP_CTRLDDISSHTDN_APPL_VAR) ElapsedTime);
# else
#  define Rte_CallHook_Ap_CtrldDisShtdn_SystemTime_DtrmnElapsedTime_mS_u16_Return(arg1, arg2) ((void)(0))
# endif /* Rte_CallHook_Ap_CtrldDisShtdn_SystemTime_DtrmnElapsedTime_mS_u16_Return */

# if defined (Rte_CallHook_Ap_CtrldDisShtdn_SystemTime_DtrmnElapsedTime_mS_u16_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_Ap_CtrldDisShtdn_SystemTime_DtrmnElapsedTime_mS_u16_Start
# endif
# if defined (Rte_CallHook_Ap_CtrldDisShtdn_SystemTime_DtrmnElapsedTime_mS_u16_Start)
#  undef Rte_CallHook_Ap_CtrldDisShtdn_SystemTime_DtrmnElapsedTime_mS_u16_Start
FUNC(void, RTE_APPL_CODE) Rte_CallHook_Ap_CtrldDisShtdn_SystemTime_DtrmnElapsedTime_mS_u16_Start(UInt32 InitialTime, P2VAR(UInt16, AUTOMATIC, RTE_AP_CTRLDDISSHTDN_APPL_VAR) ElapsedTime);
# else
#  define Rte_CallHook_Ap_CtrldDisShtdn_SystemTime_DtrmnElapsedTime_mS_u16_Start(arg1, arg2) ((void)(0))
# endif /* Rte_CallHook_Ap_CtrldDisShtdn_SystemTime_DtrmnElapsedTime_mS_u16_Start */

# if defined (Rte_CallHook_Ap_CtrldDisShtdn_SystemTime_GetSystemTime_mS_u32_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_Ap_CtrldDisShtdn_SystemTime_GetSystemTime_mS_u32_Return
# endif
# if defined (Rte_CallHook_Ap_CtrldDisShtdn_SystemTime_GetSystemTime_mS_u32_Return)
#  undef Rte_CallHook_Ap_CtrldDisShtdn_SystemTime_GetSystemTime_mS_u32_Return
FUNC(void, RTE_APPL_CODE) Rte_CallHook_Ap_CtrldDisShtdn_SystemTime_GetSystemTime_mS_u32_Return(P2VAR(UInt32, AUTOMATIC, RTE_AP_CTRLDDISSHTDN_APPL_VAR) CurrentTime);
# else
#  define Rte_CallHook_Ap_CtrldDisShtdn_SystemTime_GetSystemTime_mS_u32_Return(arg1) ((void)(0))
# endif /* Rte_CallHook_Ap_CtrldDisShtdn_SystemTime_GetSystemTime_mS_u32_Return */

# if defined (Rte_CallHook_Ap_CtrldDisShtdn_SystemTime_GetSystemTime_mS_u32_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_Ap_CtrldDisShtdn_SystemTime_GetSystemTime_mS_u32_Start
# endif
# if defined (Rte_CallHook_Ap_CtrldDisShtdn_SystemTime_GetSystemTime_mS_u32_Start)
#  undef Rte_CallHook_Ap_CtrldDisShtdn_SystemTime_GetSystemTime_mS_u32_Start
FUNC(void, RTE_APPL_CODE) Rte_CallHook_Ap_CtrldDisShtdn_SystemTime_GetSystemTime_mS_u32_Start(P2VAR(UInt32, AUTOMATIC, RTE_AP_CTRLDDISSHTDN_APPL_VAR) CurrentTime);
# else
#  define Rte_CallHook_Ap_CtrldDisShtdn_SystemTime_GetSystemTime_mS_u32_Start(arg1) ((void)(0))
# endif /* Rte_CallHook_Ap_CtrldDisShtdn_SystemTime_GetSystemTime_mS_u32_Start */

# if defined (Rte_CallHook_Ap_DampingFirewall_NxtrDiagMgr_SetNTCStatus_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_Ap_DampingFirewall_NxtrDiagMgr_SetNTCStatus_Return
# endif
# if defined (Rte_CallHook_Ap_DampingFirewall_NxtrDiagMgr_SetNTCStatus_Return)
#  undef Rte_CallHook_Ap_DampingFirewall_NxtrDiagMgr_SetNTCStatus_Return
FUNC(void, RTE_APPL_CODE) Rte_CallHook_Ap_DampingFirewall_NxtrDiagMgr_SetNTCStatus_Return(NTCNumber NTC_Cnt_T_enum, UInt8 Param_Cnt_T_u08, NxtrDiagMgrStatus Status_Cnt_T_enum);
# else
#  define Rte_CallHook_Ap_DampingFirewall_NxtrDiagMgr_SetNTCStatus_Return(arg1, arg2, arg3) ((void)(0))
# endif /* Rte_CallHook_Ap_DampingFirewall_NxtrDiagMgr_SetNTCStatus_Return */

# if defined (Rte_CallHook_Ap_DampingFirewall_NxtrDiagMgr_SetNTCStatus_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_Ap_DampingFirewall_NxtrDiagMgr_SetNTCStatus_Start
# endif
# if defined (Rte_CallHook_Ap_DampingFirewall_NxtrDiagMgr_SetNTCStatus_Start)
#  undef Rte_CallHook_Ap_DampingFirewall_NxtrDiagMgr_SetNTCStatus_Start
FUNC(void, RTE_APPL_CODE) Rte_CallHook_Ap_DampingFirewall_NxtrDiagMgr_SetNTCStatus_Start(NTCNumber NTC_Cnt_T_enum, UInt8 Param_Cnt_T_u08, NxtrDiagMgrStatus Status_Cnt_T_enum);
# else
#  define Rte_CallHook_Ap_DampingFirewall_NxtrDiagMgr_SetNTCStatus_Start(arg1, arg2, arg3) ((void)(0))
# endif /* Rte_CallHook_Ap_DampingFirewall_NxtrDiagMgr_SetNTCStatus_Start */

# if defined (Rte_CallHook_Ap_Damping_FltInjection_SCom_FltInjection_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_Ap_Damping_FltInjection_SCom_FltInjection_Return
# endif
# if defined (Rte_CallHook_Ap_Damping_FltInjection_SCom_FltInjection_Return)
#  undef Rte_CallHook_Ap_Damping_FltInjection_SCom_FltInjection_Return
FUNC(void, RTE_APPL_CODE) Rte_CallHook_Ap_Damping_FltInjection_SCom_FltInjection_Return(P2VAR(Float, AUTOMATIC, RTE_AP_DAMPING_APPL_VAR) SignalPath_Uls_f32, FltInjectionLocType LocationKey_Cnt_enum);
# else
#  define Rte_CallHook_Ap_Damping_FltInjection_SCom_FltInjection_Return(arg1, arg2) ((void)(0))
# endif /* Rte_CallHook_Ap_Damping_FltInjection_SCom_FltInjection_Return */

# if defined (Rte_CallHook_Ap_Damping_FltInjection_SCom_FltInjection_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_Ap_Damping_FltInjection_SCom_FltInjection_Start
# endif
# if defined (Rte_CallHook_Ap_Damping_FltInjection_SCom_FltInjection_Start)
#  undef Rte_CallHook_Ap_Damping_FltInjection_SCom_FltInjection_Start
FUNC(void, RTE_APPL_CODE) Rte_CallHook_Ap_Damping_FltInjection_SCom_FltInjection_Start(P2VAR(Float, AUTOMATIC, RTE_AP_DAMPING_APPL_VAR) SignalPath_Uls_f32, FltInjectionLocType LocationKey_Cnt_enum);
# else
#  define Rte_CallHook_Ap_Damping_FltInjection_SCom_FltInjection_Start(arg1, arg2) ((void)(0))
# endif /* Rte_CallHook_Ap_Damping_FltInjection_SCom_FltInjection_Start */

# if defined (Rte_CallHook_Ap_DemIf_NxtrDiagMgr_GetNTCFailed_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_Ap_DemIf_NxtrDiagMgr_GetNTCFailed_Return
# endif
# if defined (Rte_CallHook_Ap_DemIf_NxtrDiagMgr_GetNTCFailed_Return)
#  undef Rte_CallHook_Ap_DemIf_NxtrDiagMgr_GetNTCFailed_Return
FUNC(void, RTE_APPL_CODE) Rte_CallHook_Ap_DemIf_NxtrDiagMgr_GetNTCFailed_Return(NTCNumber NTC_Cnt_T_enum, P2VAR(Boolean, AUTOMATIC, RTE_AP_DEMIF_APPL_VAR) NTCFailed_Ptr_T_lgc);
# else
#  define Rte_CallHook_Ap_DemIf_NxtrDiagMgr_GetNTCFailed_Return(arg1, arg2) ((void)(0))
# endif /* Rte_CallHook_Ap_DemIf_NxtrDiagMgr_GetNTCFailed_Return */

# if defined (Rte_CallHook_Ap_DemIf_NxtrDiagMgr_GetNTCFailed_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_Ap_DemIf_NxtrDiagMgr_GetNTCFailed_Start
# endif
# if defined (Rte_CallHook_Ap_DemIf_NxtrDiagMgr_GetNTCFailed_Start)
#  undef Rte_CallHook_Ap_DemIf_NxtrDiagMgr_GetNTCFailed_Start
FUNC(void, RTE_APPL_CODE) Rte_CallHook_Ap_DemIf_NxtrDiagMgr_GetNTCFailed_Start(NTCNumber NTC_Cnt_T_enum, P2VAR(Boolean, AUTOMATIC, RTE_AP_DEMIF_APPL_VAR) NTCFailed_Ptr_T_lgc);
# else
#  define Rte_CallHook_Ap_DemIf_NxtrDiagMgr_GetNTCFailed_Start(arg1, arg2) ((void)(0))
# endif /* Rte_CallHook_Ap_DemIf_NxtrDiagMgr_GetNTCFailed_Start */

# if defined (Rte_CallHook_Ap_DemIf_NxtrDiagMgr_GetNTCStatus_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_Ap_DemIf_NxtrDiagMgr_GetNTCStatus_Return
# endif
# if defined (Rte_CallHook_Ap_DemIf_NxtrDiagMgr_GetNTCStatus_Return)
#  undef Rte_CallHook_Ap_DemIf_NxtrDiagMgr_GetNTCStatus_Return
FUNC(void, RTE_APPL_CODE) Rte_CallHook_Ap_DemIf_NxtrDiagMgr_GetNTCStatus_Return(NTCNumber NTC_Cnt_T_enum, P2VAR(UInt8, AUTOMATIC, RTE_AP_DEMIF_APPL_VAR) Status_Ptr_T_u08);
# else
#  define Rte_CallHook_Ap_DemIf_NxtrDiagMgr_GetNTCStatus_Return(arg1, arg2) ((void)(0))
# endif /* Rte_CallHook_Ap_DemIf_NxtrDiagMgr_GetNTCStatus_Return */

# if defined (Rte_CallHook_Ap_DemIf_NxtrDiagMgr_GetNTCStatus_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_Ap_DemIf_NxtrDiagMgr_GetNTCStatus_Start
# endif
# if defined (Rte_CallHook_Ap_DemIf_NxtrDiagMgr_GetNTCStatus_Start)
#  undef Rte_CallHook_Ap_DemIf_NxtrDiagMgr_GetNTCStatus_Start
FUNC(void, RTE_APPL_CODE) Rte_CallHook_Ap_DemIf_NxtrDiagMgr_GetNTCStatus_Start(NTCNumber NTC_Cnt_T_enum, P2VAR(UInt8, AUTOMATIC, RTE_AP_DEMIF_APPL_VAR) Status_Ptr_T_u08);
# else
#  define Rte_CallHook_Ap_DemIf_NxtrDiagMgr_GetNTCStatus_Start(arg1, arg2) ((void)(0))
# endif /* Rte_CallHook_Ap_DemIf_NxtrDiagMgr_GetNTCStatus_Start */

# if defined (Rte_CallHook_Ap_DemIf_OperationCycle_SetOperationCycleState_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_Ap_DemIf_OperationCycle_SetOperationCycleState_Return
# endif
# if defined (Rte_CallHook_Ap_DemIf_OperationCycle_SetOperationCycleState_Return)
#  undef Rte_CallHook_Ap_DemIf_OperationCycle_SetOperationCycleState_Return
FUNC(void, RTE_APPL_CODE) Rte_CallHook_Ap_DemIf_OperationCycle_SetOperationCycleState_Return(Dem_OperationCycleStateType CycleState);
# else
#  define Rte_CallHook_Ap_DemIf_OperationCycle_SetOperationCycleState_Return(arg1) ((void)(0))
# endif /* Rte_CallHook_Ap_DemIf_OperationCycle_SetOperationCycleState_Return */

# if defined (Rte_CallHook_Ap_DemIf_OperationCycle_SetOperationCycleState_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_Ap_DemIf_OperationCycle_SetOperationCycleState_Start
# endif
# if defined (Rte_CallHook_Ap_DemIf_OperationCycle_SetOperationCycleState_Start)
#  undef Rte_CallHook_Ap_DemIf_OperationCycle_SetOperationCycleState_Start
FUNC(void, RTE_APPL_CODE) Rte_CallHook_Ap_DemIf_OperationCycle_SetOperationCycleState_Start(Dem_OperationCycleStateType CycleState);
# else
#  define Rte_CallHook_Ap_DemIf_OperationCycle_SetOperationCycleState_Start(arg1) ((void)(0))
# endif /* Rte_CallHook_Ap_DemIf_OperationCycle_SetOperationCycleState_Start */

# if defined (Rte_CallHook_Ap_DiagMgr9_DemIf_DemShutdown_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_Ap_DiagMgr9_DemIf_DemShutdown_Return
# endif
# if defined (Rte_CallHook_Ap_DiagMgr9_DemIf_DemShutdown_Return)
#  undef Rte_CallHook_Ap_DiagMgr9_DemIf_DemShutdown_Return
FUNC(void, RTE_APPL_CODE) Rte_CallHook_Ap_DiagMgr9_DemIf_DemShutdown_Return(void);
# else
#  define Rte_CallHook_Ap_DiagMgr9_DemIf_DemShutdown_Return() ((void)(0))
# endif /* Rte_CallHook_Ap_DiagMgr9_DemIf_DemShutdown_Return */

# if defined (Rte_CallHook_Ap_DiagMgr9_DemIf_DemShutdown_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_Ap_DiagMgr9_DemIf_DemShutdown_Start
# endif
# if defined (Rte_CallHook_Ap_DiagMgr9_DemIf_DemShutdown_Start)
#  undef Rte_CallHook_Ap_DiagMgr9_DemIf_DemShutdown_Start
FUNC(void, RTE_APPL_CODE) Rte_CallHook_Ap_DiagMgr9_DemIf_DemShutdown_Start(void);
# else
#  define Rte_CallHook_Ap_DiagMgr9_DemIf_DemShutdown_Start() ((void)(0))
# endif /* Rte_CallHook_Ap_DiagMgr9_DemIf_DemShutdown_Start */

# if defined (Rte_CallHook_Ap_DiagMgr9_DemIf_RestartDem_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_Ap_DiagMgr9_DemIf_RestartDem_Return
# endif
# if defined (Rte_CallHook_Ap_DiagMgr9_DemIf_RestartDem_Return)
#  undef Rte_CallHook_Ap_DiagMgr9_DemIf_RestartDem_Return
FUNC(void, RTE_APPL_CODE) Rte_CallHook_Ap_DiagMgr9_DemIf_RestartDem_Return(void);
# else
#  define Rte_CallHook_Ap_DiagMgr9_DemIf_RestartDem_Return() ((void)(0))
# endif /* Rte_CallHook_Ap_DiagMgr9_DemIf_RestartDem_Return */

# if defined (Rte_CallHook_Ap_DiagMgr9_DemIf_RestartDem_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_Ap_DiagMgr9_DemIf_RestartDem_Start
# endif
# if defined (Rte_CallHook_Ap_DiagMgr9_DemIf_RestartDem_Start)
#  undef Rte_CallHook_Ap_DiagMgr9_DemIf_RestartDem_Start
FUNC(void, RTE_APPL_CODE) Rte_CallHook_Ap_DiagMgr9_DemIf_RestartDem_Start(void);
# else
#  define Rte_CallHook_Ap_DiagMgr9_DemIf_RestartDem_Start() ((void)(0))
# endif /* Rte_CallHook_Ap_DiagMgr9_DemIf_RestartDem_Start */

# if defined (Rte_CallHook_Ap_DiagMgr9_DemIf_SetEventStatus_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_Ap_DiagMgr9_DemIf_SetEventStatus_Return
# endif
# if defined (Rte_CallHook_Ap_DiagMgr9_DemIf_SetEventStatus_Return)
#  undef Rte_CallHook_Ap_DiagMgr9_DemIf_SetEventStatus_Return
FUNC(void, RTE_APPL_CODE) Rte_CallHook_Ap_DiagMgr9_DemIf_SetEventStatus_Return(UInt8 EventId, NxtrDiagMgrStatus EventStatus);
# else
#  define Rte_CallHook_Ap_DiagMgr9_DemIf_SetEventStatus_Return(arg1, arg2) ((void)(0))
# endif /* Rte_CallHook_Ap_DiagMgr9_DemIf_SetEventStatus_Return */

# if defined (Rte_CallHook_Ap_DiagMgr9_DemIf_SetEventStatus_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_Ap_DiagMgr9_DemIf_SetEventStatus_Start
# endif
# if defined (Rte_CallHook_Ap_DiagMgr9_DemIf_SetEventStatus_Start)
#  undef Rte_CallHook_Ap_DiagMgr9_DemIf_SetEventStatus_Start
FUNC(void, RTE_APPL_CODE) Rte_CallHook_Ap_DiagMgr9_DemIf_SetEventStatus_Start(UInt8 EventId, NxtrDiagMgrStatus EventStatus);
# else
#  define Rte_CallHook_Ap_DiagMgr9_DemIf_SetEventStatus_Start(arg1, arg2) ((void)(0))
# endif /* Rte_CallHook_Ap_DiagMgr9_DemIf_SetEventStatus_Start */

# if defined (Rte_CallHook_Ap_DiagMgr9_DemIf_SetOperationCycleState_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_Ap_DiagMgr9_DemIf_SetOperationCycleState_Return
# endif
# if defined (Rte_CallHook_Ap_DiagMgr9_DemIf_SetOperationCycleState_Return)
#  undef Rte_CallHook_Ap_DiagMgr9_DemIf_SetOperationCycleState_Return
FUNC(void, RTE_APPL_CODE) Rte_CallHook_Ap_DiagMgr9_DemIf_SetOperationCycleState_Return(NxtrOpCycle NxtrOperationCycleId, NxtrOpCycleState NxtrCycleState);
# else
#  define Rte_CallHook_Ap_DiagMgr9_DemIf_SetOperationCycleState_Return(arg1, arg2) ((void)(0))
# endif /* Rte_CallHook_Ap_DiagMgr9_DemIf_SetOperationCycleState_Return */

# if defined (Rte_CallHook_Ap_DiagMgr9_DemIf_SetOperationCycleState_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_Ap_DiagMgr9_DemIf_SetOperationCycleState_Start
# endif
# if defined (Rte_CallHook_Ap_DiagMgr9_DemIf_SetOperationCycleState_Start)
#  undef Rte_CallHook_Ap_DiagMgr9_DemIf_SetOperationCycleState_Start
FUNC(void, RTE_APPL_CODE) Rte_CallHook_Ap_DiagMgr9_DemIf_SetOperationCycleState_Start(NxtrOpCycle NxtrOperationCycleId, NxtrOpCycleState NxtrCycleState);
# else
#  define Rte_CallHook_Ap_DiagMgr9_DemIf_SetOperationCycleState_Start(arg1, arg2) ((void)(0))
# endif /* Rte_CallHook_Ap_DiagMgr9_DemIf_SetOperationCycleState_Start */

# if defined (Rte_CallHook_Ap_DigPhsReasDiag_NxtrDiagMgr_SetNTCStatus_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_Ap_DigPhsReasDiag_NxtrDiagMgr_SetNTCStatus_Return
# endif
# if defined (Rte_CallHook_Ap_DigPhsReasDiag_NxtrDiagMgr_SetNTCStatus_Return)
#  undef Rte_CallHook_Ap_DigPhsReasDiag_NxtrDiagMgr_SetNTCStatus_Return
FUNC(void, RTE_APPL_CODE) Rte_CallHook_Ap_DigPhsReasDiag_NxtrDiagMgr_SetNTCStatus_Return(NTCNumber NTC_Cnt_T_enum, UInt8 Param_Cnt_T_u08, NxtrDiagMgrStatus Status_Cnt_T_enum);
# else
#  define Rte_CallHook_Ap_DigPhsReasDiag_NxtrDiagMgr_SetNTCStatus_Return(arg1, arg2, arg3) ((void)(0))
# endif /* Rte_CallHook_Ap_DigPhsReasDiag_NxtrDiagMgr_SetNTCStatus_Return */

# if defined (Rte_CallHook_Ap_DigPhsReasDiag_NxtrDiagMgr_SetNTCStatus_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_Ap_DigPhsReasDiag_NxtrDiagMgr_SetNTCStatus_Start
# endif
# if defined (Rte_CallHook_Ap_DigPhsReasDiag_NxtrDiagMgr_SetNTCStatus_Start)
#  undef Rte_CallHook_Ap_DigPhsReasDiag_NxtrDiagMgr_SetNTCStatus_Start
FUNC(void, RTE_APPL_CODE) Rte_CallHook_Ap_DigPhsReasDiag_NxtrDiagMgr_SetNTCStatus_Start(NTCNumber NTC_Cnt_T_enum, UInt8 Param_Cnt_T_u08, NxtrDiagMgrStatus Status_Cnt_T_enum);
# else
#  define Rte_CallHook_Ap_DigPhsReasDiag_NxtrDiagMgr_SetNTCStatus_Start(arg1, arg2, arg3) ((void)(0))
# endif /* Rte_CallHook_Ap_DigPhsReasDiag_NxtrDiagMgr_SetNTCStatus_Start */

# if defined (Rte_CallHook_Ap_FrqDepDmpnInrtCmp_FltInjection_SCom_FltInjection_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_Ap_FrqDepDmpnInrtCmp_FltInjection_SCom_FltInjection_Return
# endif
# if defined (Rte_CallHook_Ap_FrqDepDmpnInrtCmp_FltInjection_SCom_FltInjection_Return)
#  undef Rte_CallHook_Ap_FrqDepDmpnInrtCmp_FltInjection_SCom_FltInjection_Return
FUNC(void, RTE_APPL_CODE) Rte_CallHook_Ap_FrqDepDmpnInrtCmp_FltInjection_SCom_FltInjection_Return(P2VAR(Float, AUTOMATIC, RTE_AP_FRQDEPDMPNINRTCMP_APPL_VAR) SignalPath_Uls_f32, FltInjectionLocType LocationKey_Cnt_enum);
# else
#  define Rte_CallHook_Ap_FrqDepDmpnInrtCmp_FltInjection_SCom_FltInjection_Return(arg1, arg2) ((void)(0))
# endif /* Rte_CallHook_Ap_FrqDepDmpnInrtCmp_FltInjection_SCom_FltInjection_Return */

# if defined (Rte_CallHook_Ap_FrqDepDmpnInrtCmp_FltInjection_SCom_FltInjection_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_Ap_FrqDepDmpnInrtCmp_FltInjection_SCom_FltInjection_Start
# endif
# if defined (Rte_CallHook_Ap_FrqDepDmpnInrtCmp_FltInjection_SCom_FltInjection_Start)
#  undef Rte_CallHook_Ap_FrqDepDmpnInrtCmp_FltInjection_SCom_FltInjection_Start
FUNC(void, RTE_APPL_CODE) Rte_CallHook_Ap_FrqDepDmpnInrtCmp_FltInjection_SCom_FltInjection_Start(P2VAR(Float, AUTOMATIC, RTE_AP_FRQDEPDMPNINRTCMP_APPL_VAR) SignalPath_Uls_f32, FltInjectionLocType LocationKey_Cnt_enum);
# else
#  define Rte_CallHook_Ap_FrqDepDmpnInrtCmp_FltInjection_SCom_FltInjection_Start(arg1, arg2) ((void)(0))
# endif /* Rte_CallHook_Ap_FrqDepDmpnInrtCmp_FltInjection_SCom_FltInjection_Start */

# if defined (Rte_CallHook_Ap_Gsod_NxtrDiagMgr_SetNTCStatus_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_Ap_Gsod_NxtrDiagMgr_SetNTCStatus_Return
# endif
# if defined (Rte_CallHook_Ap_Gsod_NxtrDiagMgr_SetNTCStatus_Return)
#  undef Rte_CallHook_Ap_Gsod_NxtrDiagMgr_SetNTCStatus_Return
FUNC(void, RTE_APPL_CODE) Rte_CallHook_Ap_Gsod_NxtrDiagMgr_SetNTCStatus_Return(NTCNumber NTC_Cnt_T_enum, UInt8 Param_Cnt_T_u08, NxtrDiagMgrStatus Status_Cnt_T_enum);
# else
#  define Rte_CallHook_Ap_Gsod_NxtrDiagMgr_SetNTCStatus_Return(arg1, arg2, arg3) ((void)(0))
# endif /* Rte_CallHook_Ap_Gsod_NxtrDiagMgr_SetNTCStatus_Return */

# if defined (Rte_CallHook_Ap_Gsod_NxtrDiagMgr_SetNTCStatus_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_Ap_Gsod_NxtrDiagMgr_SetNTCStatus_Start
# endif
# if defined (Rte_CallHook_Ap_Gsod_NxtrDiagMgr_SetNTCStatus_Start)
#  undef Rte_CallHook_Ap_Gsod_NxtrDiagMgr_SetNTCStatus_Start
FUNC(void, RTE_APPL_CODE) Rte_CallHook_Ap_Gsod_NxtrDiagMgr_SetNTCStatus_Start(NTCNumber NTC_Cnt_T_enum, UInt8 Param_Cnt_T_u08, NxtrDiagMgrStatus Status_Cnt_T_enum);
# else
#  define Rte_CallHook_Ap_Gsod_NxtrDiagMgr_SetNTCStatus_Start(arg1, arg2, arg3) ((void)(0))
# endif /* Rte_CallHook_Ap_Gsod_NxtrDiagMgr_SetNTCStatus_Start */

# if defined (Rte_CallHook_Ap_HaLFTO_HaLFState_SCom_Transition_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_Ap_HaLFTO_HaLFState_SCom_Transition_Return
# endif
# if defined (Rte_CallHook_Ap_HaLFTO_HaLFState_SCom_Transition_Return)
#  undef Rte_CallHook_Ap_HaLFTO_HaLFState_SCom_Transition_Return
FUNC(void, RTE_APPL_CODE) Rte_CallHook_Ap_HaLFTO_HaLFState_SCom_Transition_Return(UInt8 State_Cnt_T_u08);
# else
#  define Rte_CallHook_Ap_HaLFTO_HaLFState_SCom_Transition_Return(arg1) ((void)(0))
# endif /* Rte_CallHook_Ap_HaLFTO_HaLFState_SCom_Transition_Return */

# if defined (Rte_CallHook_Ap_HaLFTO_HaLFState_SCom_Transition_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_Ap_HaLFTO_HaLFState_SCom_Transition_Start
# endif
# if defined (Rte_CallHook_Ap_HaLFTO_HaLFState_SCom_Transition_Start)
#  undef Rte_CallHook_Ap_HaLFTO_HaLFState_SCom_Transition_Start
FUNC(void, RTE_APPL_CODE) Rte_CallHook_Ap_HaLFTO_HaLFState_SCom_Transition_Start(UInt8 State_Cnt_T_u08);
# else
#  define Rte_CallHook_Ap_HaLFTO_HaLFState_SCom_Transition_Start(arg1) ((void)(0))
# endif /* Rte_CallHook_Ap_HaLFTO_HaLFState_SCom_Transition_Start */

# if defined (Rte_CallHook_Ap_HaLFTO_NxtrDiagMgr_GetNTCFailed_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_Ap_HaLFTO_NxtrDiagMgr_GetNTCFailed_Return
# endif
# if defined (Rte_CallHook_Ap_HaLFTO_NxtrDiagMgr_GetNTCFailed_Return)
#  undef Rte_CallHook_Ap_HaLFTO_NxtrDiagMgr_GetNTCFailed_Return
FUNC(void, RTE_APPL_CODE) Rte_CallHook_Ap_HaLFTO_NxtrDiagMgr_GetNTCFailed_Return(NTCNumber NTC_Cnt_T_enum, P2VAR(Boolean, AUTOMATIC, RTE_AP_HALFTO_APPL_VAR) NTCFailed_Ptr_T_lgc);
# else
#  define Rte_CallHook_Ap_HaLFTO_NxtrDiagMgr_GetNTCFailed_Return(arg1, arg2) ((void)(0))
# endif /* Rte_CallHook_Ap_HaLFTO_NxtrDiagMgr_GetNTCFailed_Return */

# if defined (Rte_CallHook_Ap_HaLFTO_NxtrDiagMgr_GetNTCFailed_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_Ap_HaLFTO_NxtrDiagMgr_GetNTCFailed_Start
# endif
# if defined (Rte_CallHook_Ap_HaLFTO_NxtrDiagMgr_GetNTCFailed_Start)
#  undef Rte_CallHook_Ap_HaLFTO_NxtrDiagMgr_GetNTCFailed_Start
FUNC(void, RTE_APPL_CODE) Rte_CallHook_Ap_HaLFTO_NxtrDiagMgr_GetNTCFailed_Start(NTCNumber NTC_Cnt_T_enum, P2VAR(Boolean, AUTOMATIC, RTE_AP_HALFTO_APPL_VAR) NTCFailed_Ptr_T_lgc);
# else
#  define Rte_CallHook_Ap_HaLFTO_NxtrDiagMgr_GetNTCFailed_Start(arg1, arg2) ((void)(0))
# endif /* Rte_CallHook_Ap_HaLFTO_NxtrDiagMgr_GetNTCFailed_Start */

# if defined (Rte_CallHook_Ap_HaLFTO_NxtrDiagMgr_SetNTCStatus_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_Ap_HaLFTO_NxtrDiagMgr_SetNTCStatus_Return
# endif
# if defined (Rte_CallHook_Ap_HaLFTO_NxtrDiagMgr_SetNTCStatus_Return)
#  undef Rte_CallHook_Ap_HaLFTO_NxtrDiagMgr_SetNTCStatus_Return
FUNC(void, RTE_APPL_CODE) Rte_CallHook_Ap_HaLFTO_NxtrDiagMgr_SetNTCStatus_Return(NTCNumber NTC_Cnt_T_enum, UInt8 Param_Cnt_T_u08, NxtrDiagMgrStatus Status_Cnt_T_enum);
# else
#  define Rte_CallHook_Ap_HaLFTO_NxtrDiagMgr_SetNTCStatus_Return(arg1, arg2, arg3) ((void)(0))
# endif /* Rte_CallHook_Ap_HaLFTO_NxtrDiagMgr_SetNTCStatus_Return */

# if defined (Rte_CallHook_Ap_HaLFTO_NxtrDiagMgr_SetNTCStatus_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_Ap_HaLFTO_NxtrDiagMgr_SetNTCStatus_Start
# endif
# if defined (Rte_CallHook_Ap_HaLFTO_NxtrDiagMgr_SetNTCStatus_Start)
#  undef Rte_CallHook_Ap_HaLFTO_NxtrDiagMgr_SetNTCStatus_Start
FUNC(void, RTE_APPL_CODE) Rte_CallHook_Ap_HaLFTO_NxtrDiagMgr_SetNTCStatus_Start(NTCNumber NTC_Cnt_T_enum, UInt8 Param_Cnt_T_u08, NxtrDiagMgrStatus Status_Cnt_T_enum);
# else
#  define Rte_CallHook_Ap_HaLFTO_NxtrDiagMgr_SetNTCStatus_Start(arg1, arg2, arg3) ((void)(0))
# endif /* Rte_CallHook_Ap_HaLFTO_NxtrDiagMgr_SetNTCStatus_Start */

# if defined (Rte_CallHook_Ap_HaLFTO_SystemTime_DtrmnElapsedTime_mS_u16_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_Ap_HaLFTO_SystemTime_DtrmnElapsedTime_mS_u16_Return
# endif
# if defined (Rte_CallHook_Ap_HaLFTO_SystemTime_DtrmnElapsedTime_mS_u16_Return)
#  undef Rte_CallHook_Ap_HaLFTO_SystemTime_DtrmnElapsedTime_mS_u16_Return
FUNC(void, RTE_APPL_CODE) Rte_CallHook_Ap_HaLFTO_SystemTime_DtrmnElapsedTime_mS_u16_Return(UInt32 InitialTime, P2VAR(UInt16, AUTOMATIC, RTE_AP_HALFTO_APPL_VAR) ElapsedTime);
# else
#  define Rte_CallHook_Ap_HaLFTO_SystemTime_DtrmnElapsedTime_mS_u16_Return(arg1, arg2) ((void)(0))
# endif /* Rte_CallHook_Ap_HaLFTO_SystemTime_DtrmnElapsedTime_mS_u16_Return */

# if defined (Rte_CallHook_Ap_HaLFTO_SystemTime_DtrmnElapsedTime_mS_u16_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_Ap_HaLFTO_SystemTime_DtrmnElapsedTime_mS_u16_Start
# endif
# if defined (Rte_CallHook_Ap_HaLFTO_SystemTime_DtrmnElapsedTime_mS_u16_Start)
#  undef Rte_CallHook_Ap_HaLFTO_SystemTime_DtrmnElapsedTime_mS_u16_Start
FUNC(void, RTE_APPL_CODE) Rte_CallHook_Ap_HaLFTO_SystemTime_DtrmnElapsedTime_mS_u16_Start(UInt32 InitialTime, P2VAR(UInt16, AUTOMATIC, RTE_AP_HALFTO_APPL_VAR) ElapsedTime);
# else
#  define Rte_CallHook_Ap_HaLFTO_SystemTime_DtrmnElapsedTime_mS_u16_Start(arg1, arg2) ((void)(0))
# endif /* Rte_CallHook_Ap_HaLFTO_SystemTime_DtrmnElapsedTime_mS_u16_Start */

# if defined (Rte_CallHook_Ap_HaLFTO_SystemTime_GetSystemTime_mS_u32_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_Ap_HaLFTO_SystemTime_GetSystemTime_mS_u32_Return
# endif
# if defined (Rte_CallHook_Ap_HaLFTO_SystemTime_GetSystemTime_mS_u32_Return)
#  undef Rte_CallHook_Ap_HaLFTO_SystemTime_GetSystemTime_mS_u32_Return
FUNC(void, RTE_APPL_CODE) Rte_CallHook_Ap_HaLFTO_SystemTime_GetSystemTime_mS_u32_Return(P2VAR(UInt32, AUTOMATIC, RTE_AP_HALFTO_APPL_VAR) CurrentTime);
# else
#  define Rte_CallHook_Ap_HaLFTO_SystemTime_GetSystemTime_mS_u32_Return(arg1) ((void)(0))
# endif /* Rte_CallHook_Ap_HaLFTO_SystemTime_GetSystemTime_mS_u32_Return */

# if defined (Rte_CallHook_Ap_HaLFTO_SystemTime_GetSystemTime_mS_u32_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_Ap_HaLFTO_SystemTime_GetSystemTime_mS_u32_Start
# endif
# if defined (Rte_CallHook_Ap_HaLFTO_SystemTime_GetSystemTime_mS_u32_Start)
#  undef Rte_CallHook_Ap_HaLFTO_SystemTime_GetSystemTime_mS_u32_Start
FUNC(void, RTE_APPL_CODE) Rte_CallHook_Ap_HaLFTO_SystemTime_GetSystemTime_mS_u32_Start(P2VAR(UInt32, AUTOMATIC, RTE_AP_HALFTO_APPL_VAR) CurrentTime);
# else
#  define Rte_CallHook_Ap_HaLFTO_SystemTime_GetSystemTime_mS_u32_Start(arg1) ((void)(0))
# endif /* Rte_CallHook_Ap_HaLFTO_SystemTime_GetSystemTime_mS_u32_Start */

# if defined (Rte_CallHook_Ap_HwPwUp_MilestoneRqst_WarmInitMilestoneComplete_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_Ap_HwPwUp_MilestoneRqst_WarmInitMilestoneComplete_Return
# endif
# if defined (Rte_CallHook_Ap_HwPwUp_MilestoneRqst_WarmInitMilestoneComplete_Return)
#  undef Rte_CallHook_Ap_HwPwUp_MilestoneRqst_WarmInitMilestoneComplete_Return
FUNC(void, RTE_APPL_CODE) Rte_CallHook_Ap_HwPwUp_MilestoneRqst_WarmInitMilestoneComplete_Return(StaMd_Users user);
# else
#  define Rte_CallHook_Ap_HwPwUp_MilestoneRqst_WarmInitMilestoneComplete_Return(arg1) ((void)(0))
# endif /* Rte_CallHook_Ap_HwPwUp_MilestoneRqst_WarmInitMilestoneComplete_Return */

# if defined (Rte_CallHook_Ap_HwPwUp_MilestoneRqst_WarmInitMilestoneComplete_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_Ap_HwPwUp_MilestoneRqst_WarmInitMilestoneComplete_Start
# endif
# if defined (Rte_CallHook_Ap_HwPwUp_MilestoneRqst_WarmInitMilestoneComplete_Start)
#  undef Rte_CallHook_Ap_HwPwUp_MilestoneRqst_WarmInitMilestoneComplete_Start
FUNC(void, RTE_APPL_CODE) Rte_CallHook_Ap_HwPwUp_MilestoneRqst_WarmInitMilestoneComplete_Start(StaMd_Users user);
# else
#  define Rte_CallHook_Ap_HwPwUp_MilestoneRqst_WarmInitMilestoneComplete_Start(arg1) ((void)(0))
# endif /* Rte_CallHook_Ap_HwPwUp_MilestoneRqst_WarmInitMilestoneComplete_Start */

# if defined (Rte_CallHook_Ap_HwPwUp_MilestoneRqst_WarmInitMilestoneNotComplete_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_Ap_HwPwUp_MilestoneRqst_WarmInitMilestoneNotComplete_Return
# endif
# if defined (Rte_CallHook_Ap_HwPwUp_MilestoneRqst_WarmInitMilestoneNotComplete_Return)
#  undef Rte_CallHook_Ap_HwPwUp_MilestoneRqst_WarmInitMilestoneNotComplete_Return
FUNC(void, RTE_APPL_CODE) Rte_CallHook_Ap_HwPwUp_MilestoneRqst_WarmInitMilestoneNotComplete_Return(StaMd_Users user);
# else
#  define Rte_CallHook_Ap_HwPwUp_MilestoneRqst_WarmInitMilestoneNotComplete_Return(arg1) ((void)(0))
# endif /* Rte_CallHook_Ap_HwPwUp_MilestoneRqst_WarmInitMilestoneNotComplete_Return */

# if defined (Rte_CallHook_Ap_HwPwUp_MilestoneRqst_WarmInitMilestoneNotComplete_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_Ap_HwPwUp_MilestoneRqst_WarmInitMilestoneNotComplete_Start
# endif
# if defined (Rte_CallHook_Ap_HwPwUp_MilestoneRqst_WarmInitMilestoneNotComplete_Start)
#  undef Rte_CallHook_Ap_HwPwUp_MilestoneRqst_WarmInitMilestoneNotComplete_Start
FUNC(void, RTE_APPL_CODE) Rte_CallHook_Ap_HwPwUp_MilestoneRqst_WarmInitMilestoneNotComplete_Start(StaMd_Users user);
# else
#  define Rte_CallHook_Ap_HwPwUp_MilestoneRqst_WarmInitMilestoneNotComplete_Start(arg1) ((void)(0))
# endif /* Rte_CallHook_Ap_HwPwUp_MilestoneRqst_WarmInitMilestoneNotComplete_Start */

# if defined (Rte_CallHook_Ap_HystComp_FltInjection_SCom_FltInjection_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_Ap_HystComp_FltInjection_SCom_FltInjection_Return
# endif
# if defined (Rte_CallHook_Ap_HystComp_FltInjection_SCom_FltInjection_Return)
#  undef Rte_CallHook_Ap_HystComp_FltInjection_SCom_FltInjection_Return
FUNC(void, RTE_APPL_CODE) Rte_CallHook_Ap_HystComp_FltInjection_SCom_FltInjection_Return(P2VAR(Float, AUTOMATIC, RTE_AP_HYSTCOMP_APPL_VAR) SignalPath_Uls_f32, FltInjectionLocType LocationKey_Cnt_enum);
# else
#  define Rte_CallHook_Ap_HystComp_FltInjection_SCom_FltInjection_Return(arg1, arg2) ((void)(0))
# endif /* Rte_CallHook_Ap_HystComp_FltInjection_SCom_FltInjection_Return */

# if defined (Rte_CallHook_Ap_HystComp_FltInjection_SCom_FltInjection_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_Ap_HystComp_FltInjection_SCom_FltInjection_Start
# endif
# if defined (Rte_CallHook_Ap_HystComp_FltInjection_SCom_FltInjection_Start)
#  undef Rte_CallHook_Ap_HystComp_FltInjection_SCom_FltInjection_Start
FUNC(void, RTE_APPL_CODE) Rte_CallHook_Ap_HystComp_FltInjection_SCom_FltInjection_Start(P2VAR(Float, AUTOMATIC, RTE_AP_HYSTCOMP_APPL_VAR) SignalPath_Uls_f32, FltInjectionLocType LocationKey_Cnt_enum);
# else
#  define Rte_CallHook_Ap_HystComp_FltInjection_SCom_FltInjection_Start(arg1, arg2) ((void)(0))
# endif /* Rte_CallHook_Ap_HystComp_FltInjection_SCom_FltInjection_Start */

# if defined (Rte_CallHook_Ap_LmtCod_FltInjection_SCom_FltInjection_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_Ap_LmtCod_FltInjection_SCom_FltInjection_Return
# endif
# if defined (Rte_CallHook_Ap_LmtCod_FltInjection_SCom_FltInjection_Return)
#  undef Rte_CallHook_Ap_LmtCod_FltInjection_SCom_FltInjection_Return
FUNC(void, RTE_APPL_CODE) Rte_CallHook_Ap_LmtCod_FltInjection_SCom_FltInjection_Return(P2VAR(Float, AUTOMATIC, RTE_AP_LMTCOD_APPL_VAR) SignalPath_Uls_f32, FltInjectionLocType LocationKey_Cnt_enum);
# else
#  define Rte_CallHook_Ap_LmtCod_FltInjection_SCom_FltInjection_Return(arg1, arg2) ((void)(0))
# endif /* Rte_CallHook_Ap_LmtCod_FltInjection_SCom_FltInjection_Return */

# if defined (Rte_CallHook_Ap_LmtCod_FltInjection_SCom_FltInjection_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_Ap_LmtCod_FltInjection_SCom_FltInjection_Start
# endif
# if defined (Rte_CallHook_Ap_LmtCod_FltInjection_SCom_FltInjection_Start)
#  undef Rte_CallHook_Ap_LmtCod_FltInjection_SCom_FltInjection_Start
FUNC(void, RTE_APPL_CODE) Rte_CallHook_Ap_LmtCod_FltInjection_SCom_FltInjection_Start(P2VAR(Float, AUTOMATIC, RTE_AP_LMTCOD_APPL_VAR) SignalPath_Uls_f32, FltInjectionLocType LocationKey_Cnt_enum);
# else
#  define Rte_CallHook_Ap_LmtCod_FltInjection_SCom_FltInjection_Start(arg1, arg2) ((void)(0))
# endif /* Rte_CallHook_Ap_LmtCod_FltInjection_SCom_FltInjection_Start */

# if defined (Rte_CallHook_Ap_LrnEOT_LearnedEOTData_SetRamBlockStatus_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_Ap_LrnEOT_LearnedEOTData_SetRamBlockStatus_Return
# endif
# if defined (Rte_CallHook_Ap_LrnEOT_LearnedEOTData_SetRamBlockStatus_Return)
#  undef Rte_CallHook_Ap_LrnEOT_LearnedEOTData_SetRamBlockStatus_Return
FUNC(void, RTE_APPL_CODE) Rte_CallHook_Ap_LrnEOT_LearnedEOTData_SetRamBlockStatus_Return(Boolean RamBlockStatus);
# else
#  define Rte_CallHook_Ap_LrnEOT_LearnedEOTData_SetRamBlockStatus_Return(arg1) ((void)(0))
# endif /* Rte_CallHook_Ap_LrnEOT_LearnedEOTData_SetRamBlockStatus_Return */

# if defined (Rte_CallHook_Ap_LrnEOT_LearnedEOTData_SetRamBlockStatus_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_Ap_LrnEOT_LearnedEOTData_SetRamBlockStatus_Start
# endif
# if defined (Rte_CallHook_Ap_LrnEOT_LearnedEOTData_SetRamBlockStatus_Start)
#  undef Rte_CallHook_Ap_LrnEOT_LearnedEOTData_SetRamBlockStatus_Start
FUNC(void, RTE_APPL_CODE) Rte_CallHook_Ap_LrnEOT_LearnedEOTData_SetRamBlockStatus_Start(Boolean RamBlockStatus);
# else
#  define Rte_CallHook_Ap_LrnEOT_LearnedEOTData_SetRamBlockStatus_Start(arg1) ((void)(0))
# endif /* Rte_CallHook_Ap_LrnEOT_LearnedEOTData_SetRamBlockStatus_Start */

# if defined (Rte_CallHook_Ap_LrnEOT_LearnedEOTData_WriteBlock_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_Ap_LrnEOT_LearnedEOTData_WriteBlock_Return
# endif
# if defined (Rte_CallHook_Ap_LrnEOT_LearnedEOTData_WriteBlock_Return)
#  undef Rte_CallHook_Ap_LrnEOT_LearnedEOTData_WriteBlock_Return
FUNC(void, RTE_APPL_CODE) Rte_CallHook_Ap_LrnEOT_LearnedEOTData_WriteBlock_Return(P2CONST(NvM_DestPtr, AUTOMATIC, RTE_AP_LRNEOT_APPL_DATA) DstPtr);
# else
#  define Rte_CallHook_Ap_LrnEOT_LearnedEOTData_WriteBlock_Return(arg1) ((void)(0))
# endif /* Rte_CallHook_Ap_LrnEOT_LearnedEOTData_WriteBlock_Return */

# if defined (Rte_CallHook_Ap_LrnEOT_LearnedEOTData_WriteBlock_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_Ap_LrnEOT_LearnedEOTData_WriteBlock_Start
# endif
# if defined (Rte_CallHook_Ap_LrnEOT_LearnedEOTData_WriteBlock_Start)
#  undef Rte_CallHook_Ap_LrnEOT_LearnedEOTData_WriteBlock_Start
FUNC(void, RTE_APPL_CODE) Rte_CallHook_Ap_LrnEOT_LearnedEOTData_WriteBlock_Start(P2CONST(NvM_DestPtr, AUTOMATIC, RTE_AP_LRNEOT_APPL_DATA) DstPtr);
# else
#  define Rte_CallHook_Ap_LrnEOT_LearnedEOTData_WriteBlock_Start(arg1) ((void)(0))
# endif /* Rte_CallHook_Ap_LrnEOT_LearnedEOTData_WriteBlock_Start */

# if defined (Rte_CallHook_Ap_LrnEOT_NxtrDiagMgr_GetNTCFailed_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_Ap_LrnEOT_NxtrDiagMgr_GetNTCFailed_Return
# endif
# if defined (Rte_CallHook_Ap_LrnEOT_NxtrDiagMgr_GetNTCFailed_Return)
#  undef Rte_CallHook_Ap_LrnEOT_NxtrDiagMgr_GetNTCFailed_Return
FUNC(void, RTE_APPL_CODE) Rte_CallHook_Ap_LrnEOT_NxtrDiagMgr_GetNTCFailed_Return(NTCNumber NTC_Cnt_T_enum, P2VAR(Boolean, AUTOMATIC, RTE_AP_LRNEOT_APPL_VAR) NTCFailed_Ptr_T_lgc);
# else
#  define Rte_CallHook_Ap_LrnEOT_NxtrDiagMgr_GetNTCFailed_Return(arg1, arg2) ((void)(0))
# endif /* Rte_CallHook_Ap_LrnEOT_NxtrDiagMgr_GetNTCFailed_Return */

# if defined (Rte_CallHook_Ap_LrnEOT_NxtrDiagMgr_GetNTCFailed_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_Ap_LrnEOT_NxtrDiagMgr_GetNTCFailed_Start
# endif
# if defined (Rte_CallHook_Ap_LrnEOT_NxtrDiagMgr_GetNTCFailed_Start)
#  undef Rte_CallHook_Ap_LrnEOT_NxtrDiagMgr_GetNTCFailed_Start
FUNC(void, RTE_APPL_CODE) Rte_CallHook_Ap_LrnEOT_NxtrDiagMgr_GetNTCFailed_Start(NTCNumber NTC_Cnt_T_enum, P2VAR(Boolean, AUTOMATIC, RTE_AP_LRNEOT_APPL_VAR) NTCFailed_Ptr_T_lgc);
# else
#  define Rte_CallHook_Ap_LrnEOT_NxtrDiagMgr_GetNTCFailed_Start(arg1, arg2) ((void)(0))
# endif /* Rte_CallHook_Ap_LrnEOT_NxtrDiagMgr_GetNTCFailed_Start */

# if defined (Rte_CallHook_Ap_LrnEOT_SystemTime_DtrmnElapsedTime_mS_u16_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_Ap_LrnEOT_SystemTime_DtrmnElapsedTime_mS_u16_Return
# endif
# if defined (Rte_CallHook_Ap_LrnEOT_SystemTime_DtrmnElapsedTime_mS_u16_Return)
#  undef Rte_CallHook_Ap_LrnEOT_SystemTime_DtrmnElapsedTime_mS_u16_Return
FUNC(void, RTE_APPL_CODE) Rte_CallHook_Ap_LrnEOT_SystemTime_DtrmnElapsedTime_mS_u16_Return(UInt32 InitialTime, P2VAR(UInt16, AUTOMATIC, RTE_AP_LRNEOT_APPL_VAR) ElapsedTime);
# else
#  define Rte_CallHook_Ap_LrnEOT_SystemTime_DtrmnElapsedTime_mS_u16_Return(arg1, arg2) ((void)(0))
# endif /* Rte_CallHook_Ap_LrnEOT_SystemTime_DtrmnElapsedTime_mS_u16_Return */

# if defined (Rte_CallHook_Ap_LrnEOT_SystemTime_DtrmnElapsedTime_mS_u16_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_Ap_LrnEOT_SystemTime_DtrmnElapsedTime_mS_u16_Start
# endif
# if defined (Rte_CallHook_Ap_LrnEOT_SystemTime_DtrmnElapsedTime_mS_u16_Start)
#  undef Rte_CallHook_Ap_LrnEOT_SystemTime_DtrmnElapsedTime_mS_u16_Start
FUNC(void, RTE_APPL_CODE) Rte_CallHook_Ap_LrnEOT_SystemTime_DtrmnElapsedTime_mS_u16_Start(UInt32 InitialTime, P2VAR(UInt16, AUTOMATIC, RTE_AP_LRNEOT_APPL_VAR) ElapsedTime);
# else
#  define Rte_CallHook_Ap_LrnEOT_SystemTime_DtrmnElapsedTime_mS_u16_Start(arg1, arg2) ((void)(0))
# endif /* Rte_CallHook_Ap_LrnEOT_SystemTime_DtrmnElapsedTime_mS_u16_Start */

# if defined (Rte_CallHook_Ap_LrnEOT_SystemTime_GetSystemTime_mS_u32_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_Ap_LrnEOT_SystemTime_GetSystemTime_mS_u32_Return
# endif
# if defined (Rte_CallHook_Ap_LrnEOT_SystemTime_GetSystemTime_mS_u32_Return)
#  undef Rte_CallHook_Ap_LrnEOT_SystemTime_GetSystemTime_mS_u32_Return
FUNC(void, RTE_APPL_CODE) Rte_CallHook_Ap_LrnEOT_SystemTime_GetSystemTime_mS_u32_Return(P2VAR(UInt32, AUTOMATIC, RTE_AP_LRNEOT_APPL_VAR) CurrentTime);
# else
#  define Rte_CallHook_Ap_LrnEOT_SystemTime_GetSystemTime_mS_u32_Return(arg1) ((void)(0))
# endif /* Rte_CallHook_Ap_LrnEOT_SystemTime_GetSystemTime_mS_u32_Return */

# if defined (Rte_CallHook_Ap_LrnEOT_SystemTime_GetSystemTime_mS_u32_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_Ap_LrnEOT_SystemTime_GetSystemTime_mS_u32_Start
# endif
# if defined (Rte_CallHook_Ap_LrnEOT_SystemTime_GetSystemTime_mS_u32_Start)
#  undef Rte_CallHook_Ap_LrnEOT_SystemTime_GetSystemTime_mS_u32_Start
FUNC(void, RTE_APPL_CODE) Rte_CallHook_Ap_LrnEOT_SystemTime_GetSystemTime_mS_u32_Start(P2VAR(UInt32, AUTOMATIC, RTE_AP_LRNEOT_APPL_VAR) CurrentTime);
# else
#  define Rte_CallHook_Ap_LrnEOT_SystemTime_GetSystemTime_mS_u32_Start(arg1) ((void)(0))
# endif /* Rte_CallHook_Ap_LrnEOT_SystemTime_GetSystemTime_mS_u32_Start */

# if defined (Rte_CallHook_Ap_PAwTO_NxtrDiagMgr_GetNTCActive_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_Ap_PAwTO_NxtrDiagMgr_GetNTCActive_Return
# endif
# if defined (Rte_CallHook_Ap_PAwTO_NxtrDiagMgr_GetNTCActive_Return)
#  undef Rte_CallHook_Ap_PAwTO_NxtrDiagMgr_GetNTCActive_Return
FUNC(void, RTE_APPL_CODE) Rte_CallHook_Ap_PAwTO_NxtrDiagMgr_GetNTCActive_Return(NTCNumber NTC_Cnt_T_enum, P2VAR(Boolean, AUTOMATIC, RTE_AP_PAWTO_APPL_VAR) NTCActive_Ptr_T_lgc);
# else
#  define Rte_CallHook_Ap_PAwTO_NxtrDiagMgr_GetNTCActive_Return(arg1, arg2) ((void)(0))
# endif /* Rte_CallHook_Ap_PAwTO_NxtrDiagMgr_GetNTCActive_Return */

# if defined (Rte_CallHook_Ap_PAwTO_NxtrDiagMgr_GetNTCActive_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_Ap_PAwTO_NxtrDiagMgr_GetNTCActive_Start
# endif
# if defined (Rte_CallHook_Ap_PAwTO_NxtrDiagMgr_GetNTCActive_Start)
#  undef Rte_CallHook_Ap_PAwTO_NxtrDiagMgr_GetNTCActive_Start
FUNC(void, RTE_APPL_CODE) Rte_CallHook_Ap_PAwTO_NxtrDiagMgr_GetNTCActive_Start(NTCNumber NTC_Cnt_T_enum, P2VAR(Boolean, AUTOMATIC, RTE_AP_PAWTO_APPL_VAR) NTCActive_Ptr_T_lgc);
# else
#  define Rte_CallHook_Ap_PAwTO_NxtrDiagMgr_GetNTCActive_Start(arg1, arg2) ((void)(0))
# endif /* Rte_CallHook_Ap_PAwTO_NxtrDiagMgr_GetNTCActive_Start */

# if defined (Rte_CallHook_Ap_PAwTO_NxtrDiagMgr_GetNTCFailed_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_Ap_PAwTO_NxtrDiagMgr_GetNTCFailed_Return
# endif
# if defined (Rte_CallHook_Ap_PAwTO_NxtrDiagMgr_GetNTCFailed_Return)
#  undef Rte_CallHook_Ap_PAwTO_NxtrDiagMgr_GetNTCFailed_Return
FUNC(void, RTE_APPL_CODE) Rte_CallHook_Ap_PAwTO_NxtrDiagMgr_GetNTCFailed_Return(NTCNumber NTC_Cnt_T_enum, P2VAR(Boolean, AUTOMATIC, RTE_AP_PAWTO_APPL_VAR) NTCFailed_Ptr_T_lgc);
# else
#  define Rte_CallHook_Ap_PAwTO_NxtrDiagMgr_GetNTCFailed_Return(arg1, arg2) ((void)(0))
# endif /* Rte_CallHook_Ap_PAwTO_NxtrDiagMgr_GetNTCFailed_Return */

# if defined (Rte_CallHook_Ap_PAwTO_NxtrDiagMgr_GetNTCFailed_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_Ap_PAwTO_NxtrDiagMgr_GetNTCFailed_Start
# endif
# if defined (Rte_CallHook_Ap_PAwTO_NxtrDiagMgr_GetNTCFailed_Start)
#  undef Rte_CallHook_Ap_PAwTO_NxtrDiagMgr_GetNTCFailed_Start
FUNC(void, RTE_APPL_CODE) Rte_CallHook_Ap_PAwTO_NxtrDiagMgr_GetNTCFailed_Start(NTCNumber NTC_Cnt_T_enum, P2VAR(Boolean, AUTOMATIC, RTE_AP_PAWTO_APPL_VAR) NTCFailed_Ptr_T_lgc);
# else
#  define Rte_CallHook_Ap_PAwTO_NxtrDiagMgr_GetNTCFailed_Start(arg1, arg2) ((void)(0))
# endif /* Rte_CallHook_Ap_PAwTO_NxtrDiagMgr_GetNTCFailed_Start */

# if defined (Rte_CallHook_Ap_PAwTO_NxtrDiagMgr_SetNTCStatus_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_Ap_PAwTO_NxtrDiagMgr_SetNTCStatus_Return
# endif
# if defined (Rte_CallHook_Ap_PAwTO_NxtrDiagMgr_SetNTCStatus_Return)
#  undef Rte_CallHook_Ap_PAwTO_NxtrDiagMgr_SetNTCStatus_Return
FUNC(void, RTE_APPL_CODE) Rte_CallHook_Ap_PAwTO_NxtrDiagMgr_SetNTCStatus_Return(NTCNumber NTC_Cnt_T_enum, UInt8 Param_Cnt_T_u08, NxtrDiagMgrStatus Status_Cnt_T_enum);
# else
#  define Rte_CallHook_Ap_PAwTO_NxtrDiagMgr_SetNTCStatus_Return(arg1, arg2, arg3) ((void)(0))
# endif /* Rte_CallHook_Ap_PAwTO_NxtrDiagMgr_SetNTCStatus_Return */

# if defined (Rte_CallHook_Ap_PAwTO_NxtrDiagMgr_SetNTCStatus_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_Ap_PAwTO_NxtrDiagMgr_SetNTCStatus_Start
# endif
# if defined (Rte_CallHook_Ap_PAwTO_NxtrDiagMgr_SetNTCStatus_Start)
#  undef Rte_CallHook_Ap_PAwTO_NxtrDiagMgr_SetNTCStatus_Start
FUNC(void, RTE_APPL_CODE) Rte_CallHook_Ap_PAwTO_NxtrDiagMgr_SetNTCStatus_Start(NTCNumber NTC_Cnt_T_enum, UInt8 Param_Cnt_T_u08, NxtrDiagMgrStatus Status_Cnt_T_enum);
# else
#  define Rte_CallHook_Ap_PAwTO_NxtrDiagMgr_SetNTCStatus_Start(arg1, arg2, arg3) ((void)(0))
# endif /* Rte_CallHook_Ap_PAwTO_NxtrDiagMgr_SetNTCStatus_Start */

# if defined (Rte_CallHook_Ap_PAwTO_PAwTO_Per2_CP1_CheckpointReached_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_Ap_PAwTO_PAwTO_Per2_CP1_CheckpointReached_Return
# endif
# if defined (Rte_CallHook_Ap_PAwTO_PAwTO_Per2_CP1_CheckpointReached_Return)
#  undef Rte_CallHook_Ap_PAwTO_PAwTO_Per2_CP1_CheckpointReached_Return
FUNC(void, RTE_APPL_CODE) Rte_CallHook_Ap_PAwTO_PAwTO_Per2_CP1_CheckpointReached_Return(void);
# else
#  define Rte_CallHook_Ap_PAwTO_PAwTO_Per2_CP1_CheckpointReached_Return() ((void)(0))
# endif /* Rte_CallHook_Ap_PAwTO_PAwTO_Per2_CP1_CheckpointReached_Return */

# if defined (Rte_CallHook_Ap_PAwTO_PAwTO_Per2_CP1_CheckpointReached_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_Ap_PAwTO_PAwTO_Per2_CP1_CheckpointReached_Start
# endif
# if defined (Rte_CallHook_Ap_PAwTO_PAwTO_Per2_CP1_CheckpointReached_Start)
#  undef Rte_CallHook_Ap_PAwTO_PAwTO_Per2_CP1_CheckpointReached_Start
FUNC(void, RTE_APPL_CODE) Rte_CallHook_Ap_PAwTO_PAwTO_Per2_CP1_CheckpointReached_Start(void);
# else
#  define Rte_CallHook_Ap_PAwTO_PAwTO_Per2_CP1_CheckpointReached_Start() ((void)(0))
# endif /* Rte_CallHook_Ap_PAwTO_PAwTO_Per2_CP1_CheckpointReached_Start */

# if defined (Rte_CallHook_Ap_PAwTO_PrkAssistState_SCom_Transition_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_Ap_PAwTO_PrkAssistState_SCom_Transition_Return
# endif
# if defined (Rte_CallHook_Ap_PAwTO_PrkAssistState_SCom_Transition_Return)
#  undef Rte_CallHook_Ap_PAwTO_PrkAssistState_SCom_Transition_Return
FUNC(void, RTE_APPL_CODE) Rte_CallHook_Ap_PAwTO_PrkAssistState_SCom_Transition_Return(UInt8 State_Cnt_T_u08);
# else
#  define Rte_CallHook_Ap_PAwTO_PrkAssistState_SCom_Transition_Return(arg1) ((void)(0))
# endif /* Rte_CallHook_Ap_PAwTO_PrkAssistState_SCom_Transition_Return */

# if defined (Rte_CallHook_Ap_PAwTO_PrkAssistState_SCom_Transition_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_Ap_PAwTO_PrkAssistState_SCom_Transition_Start
# endif
# if defined (Rte_CallHook_Ap_PAwTO_PrkAssistState_SCom_Transition_Start)
#  undef Rte_CallHook_Ap_PAwTO_PrkAssistState_SCom_Transition_Start
FUNC(void, RTE_APPL_CODE) Rte_CallHook_Ap_PAwTO_PrkAssistState_SCom_Transition_Start(UInt8 State_Cnt_T_u08);
# else
#  define Rte_CallHook_Ap_PAwTO_PrkAssistState_SCom_Transition_Start(arg1) ((void)(0))
# endif /* Rte_CallHook_Ap_PAwTO_PrkAssistState_SCom_Transition_Start */

# if defined (Rte_CallHook_Ap_PAwTO_SystemTime_DtrmnElapsedTime_mS_u16_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_Ap_PAwTO_SystemTime_DtrmnElapsedTime_mS_u16_Return
# endif
# if defined (Rte_CallHook_Ap_PAwTO_SystemTime_DtrmnElapsedTime_mS_u16_Return)
#  undef Rte_CallHook_Ap_PAwTO_SystemTime_DtrmnElapsedTime_mS_u16_Return
FUNC(void, RTE_APPL_CODE) Rte_CallHook_Ap_PAwTO_SystemTime_DtrmnElapsedTime_mS_u16_Return(UInt32 InitialTime, P2VAR(UInt16, AUTOMATIC, RTE_AP_PAWTO_APPL_VAR) ElapsedTime);
# else
#  define Rte_CallHook_Ap_PAwTO_SystemTime_DtrmnElapsedTime_mS_u16_Return(arg1, arg2) ((void)(0))
# endif /* Rte_CallHook_Ap_PAwTO_SystemTime_DtrmnElapsedTime_mS_u16_Return */

# if defined (Rte_CallHook_Ap_PAwTO_SystemTime_DtrmnElapsedTime_mS_u16_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_Ap_PAwTO_SystemTime_DtrmnElapsedTime_mS_u16_Start
# endif
# if defined (Rte_CallHook_Ap_PAwTO_SystemTime_DtrmnElapsedTime_mS_u16_Start)
#  undef Rte_CallHook_Ap_PAwTO_SystemTime_DtrmnElapsedTime_mS_u16_Start
FUNC(void, RTE_APPL_CODE) Rte_CallHook_Ap_PAwTO_SystemTime_DtrmnElapsedTime_mS_u16_Start(UInt32 InitialTime, P2VAR(UInt16, AUTOMATIC, RTE_AP_PAWTO_APPL_VAR) ElapsedTime);
# else
#  define Rte_CallHook_Ap_PAwTO_SystemTime_DtrmnElapsedTime_mS_u16_Start(arg1, arg2) ((void)(0))
# endif /* Rte_CallHook_Ap_PAwTO_SystemTime_DtrmnElapsedTime_mS_u16_Start */

# if defined (Rte_CallHook_Ap_PAwTO_SystemTime_GetSystemTime_mS_u32_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_Ap_PAwTO_SystemTime_GetSystemTime_mS_u32_Return
# endif
# if defined (Rte_CallHook_Ap_PAwTO_SystemTime_GetSystemTime_mS_u32_Return)
#  undef Rte_CallHook_Ap_PAwTO_SystemTime_GetSystemTime_mS_u32_Return
FUNC(void, RTE_APPL_CODE) Rte_CallHook_Ap_PAwTO_SystemTime_GetSystemTime_mS_u32_Return(P2VAR(UInt32, AUTOMATIC, RTE_AP_PAWTO_APPL_VAR) CurrentTime);
# else
#  define Rte_CallHook_Ap_PAwTO_SystemTime_GetSystemTime_mS_u32_Return(arg1) ((void)(0))
# endif /* Rte_CallHook_Ap_PAwTO_SystemTime_GetSystemTime_mS_u32_Return */

# if defined (Rte_CallHook_Ap_PAwTO_SystemTime_GetSystemTime_mS_u32_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_Ap_PAwTO_SystemTime_GetSystemTime_mS_u32_Start
# endif
# if defined (Rte_CallHook_Ap_PAwTO_SystemTime_GetSystemTime_mS_u32_Start)
#  undef Rte_CallHook_Ap_PAwTO_SystemTime_GetSystemTime_mS_u32_Start
FUNC(void, RTE_APPL_CODE) Rte_CallHook_Ap_PAwTO_SystemTime_GetSystemTime_mS_u32_Start(P2VAR(UInt32, AUTOMATIC, RTE_AP_PAWTO_APPL_VAR) CurrentTime);
# else
#  define Rte_CallHook_Ap_PAwTO_SystemTime_GetSystemTime_mS_u32_Start(arg1) ((void)(0))
# endif /* Rte_CallHook_Ap_PAwTO_SystemTime_GetSystemTime_mS_u32_Start */

# if defined (Rte_CallHook_Ap_Polarity_NxtrDiagMgr_SetNTCStatus_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_Ap_Polarity_NxtrDiagMgr_SetNTCStatus_Return
# endif
# if defined (Rte_CallHook_Ap_Polarity_NxtrDiagMgr_SetNTCStatus_Return)
#  undef Rte_CallHook_Ap_Polarity_NxtrDiagMgr_SetNTCStatus_Return
FUNC(void, RTE_APPL_CODE) Rte_CallHook_Ap_Polarity_NxtrDiagMgr_SetNTCStatus_Return(NTCNumber NTC_Cnt_T_enum, UInt8 Param_Cnt_T_u08, NxtrDiagMgrStatus Status_Cnt_T_enum);
# else
#  define Rte_CallHook_Ap_Polarity_NxtrDiagMgr_SetNTCStatus_Return(arg1, arg2, arg3) ((void)(0))
# endif /* Rte_CallHook_Ap_Polarity_NxtrDiagMgr_SetNTCStatus_Return */

# if defined (Rte_CallHook_Ap_Polarity_NxtrDiagMgr_SetNTCStatus_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_Ap_Polarity_NxtrDiagMgr_SetNTCStatus_Start
# endif
# if defined (Rte_CallHook_Ap_Polarity_NxtrDiagMgr_SetNTCStatus_Start)
#  undef Rte_CallHook_Ap_Polarity_NxtrDiagMgr_SetNTCStatus_Start
FUNC(void, RTE_APPL_CODE) Rte_CallHook_Ap_Polarity_NxtrDiagMgr_SetNTCStatus_Start(NTCNumber NTC_Cnt_T_enum, UInt8 Param_Cnt_T_u08, NxtrDiagMgrStatus Status_Cnt_T_enum);
# else
#  define Rte_CallHook_Ap_Polarity_NxtrDiagMgr_SetNTCStatus_Start(arg1, arg2, arg3) ((void)(0))
# endif /* Rte_CallHook_Ap_Polarity_NxtrDiagMgr_SetNTCStatus_Start */

# if defined (Rte_CallHook_Ap_PwrLmtFuncCr_NxtrDiagMgr_GetNTCStatus_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_Ap_PwrLmtFuncCr_NxtrDiagMgr_GetNTCStatus_Return
# endif
# if defined (Rte_CallHook_Ap_PwrLmtFuncCr_NxtrDiagMgr_GetNTCStatus_Return)
#  undef Rte_CallHook_Ap_PwrLmtFuncCr_NxtrDiagMgr_GetNTCStatus_Return
FUNC(void, RTE_APPL_CODE) Rte_CallHook_Ap_PwrLmtFuncCr_NxtrDiagMgr_GetNTCStatus_Return(NTCNumber NTC_Cnt_T_enum, P2VAR(UInt8, AUTOMATIC, RTE_AP_PWRLMTFUNCCR_APPL_VAR) Status_Ptr_T_u08);
# else
#  define Rte_CallHook_Ap_PwrLmtFuncCr_NxtrDiagMgr_GetNTCStatus_Return(arg1, arg2) ((void)(0))
# endif /* Rte_CallHook_Ap_PwrLmtFuncCr_NxtrDiagMgr_GetNTCStatus_Return */

# if defined (Rte_CallHook_Ap_PwrLmtFuncCr_NxtrDiagMgr_GetNTCStatus_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_Ap_PwrLmtFuncCr_NxtrDiagMgr_GetNTCStatus_Start
# endif
# if defined (Rte_CallHook_Ap_PwrLmtFuncCr_NxtrDiagMgr_GetNTCStatus_Start)
#  undef Rte_CallHook_Ap_PwrLmtFuncCr_NxtrDiagMgr_GetNTCStatus_Start
FUNC(void, RTE_APPL_CODE) Rte_CallHook_Ap_PwrLmtFuncCr_NxtrDiagMgr_GetNTCStatus_Start(NTCNumber NTC_Cnt_T_enum, P2VAR(UInt8, AUTOMATIC, RTE_AP_PWRLMTFUNCCR_APPL_VAR) Status_Ptr_T_u08);
# else
#  define Rte_CallHook_Ap_PwrLmtFuncCr_NxtrDiagMgr_GetNTCStatus_Start(arg1, arg2) ((void)(0))
# endif /* Rte_CallHook_Ap_PwrLmtFuncCr_NxtrDiagMgr_GetNTCStatus_Start */

# if defined (Rte_CallHook_Ap_PwrLmtFuncCr_NxtrDiagMgr_SetNTCStatus_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_Ap_PwrLmtFuncCr_NxtrDiagMgr_SetNTCStatus_Return
# endif
# if defined (Rte_CallHook_Ap_PwrLmtFuncCr_NxtrDiagMgr_SetNTCStatus_Return)
#  undef Rte_CallHook_Ap_PwrLmtFuncCr_NxtrDiagMgr_SetNTCStatus_Return
FUNC(void, RTE_APPL_CODE) Rte_CallHook_Ap_PwrLmtFuncCr_NxtrDiagMgr_SetNTCStatus_Return(NTCNumber NTC_Cnt_T_enum, UInt8 Param_Cnt_T_u08, NxtrDiagMgrStatus Status_Cnt_T_enum);
# else
#  define Rte_CallHook_Ap_PwrLmtFuncCr_NxtrDiagMgr_SetNTCStatus_Return(arg1, arg2, arg3) ((void)(0))
# endif /* Rte_CallHook_Ap_PwrLmtFuncCr_NxtrDiagMgr_SetNTCStatus_Return */

# if defined (Rte_CallHook_Ap_PwrLmtFuncCr_NxtrDiagMgr_SetNTCStatus_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_Ap_PwrLmtFuncCr_NxtrDiagMgr_SetNTCStatus_Start
# endif
# if defined (Rte_CallHook_Ap_PwrLmtFuncCr_NxtrDiagMgr_SetNTCStatus_Start)
#  undef Rte_CallHook_Ap_PwrLmtFuncCr_NxtrDiagMgr_SetNTCStatus_Start
FUNC(void, RTE_APPL_CODE) Rte_CallHook_Ap_PwrLmtFuncCr_NxtrDiagMgr_SetNTCStatus_Start(NTCNumber NTC_Cnt_T_enum, UInt8 Param_Cnt_T_u08, NxtrDiagMgrStatus Status_Cnt_T_enum);
# else
#  define Rte_CallHook_Ap_PwrLmtFuncCr_NxtrDiagMgr_SetNTCStatus_Start(arg1, arg2, arg3) ((void)(0))
# endif /* Rte_CallHook_Ap_PwrLmtFuncCr_NxtrDiagMgr_SetNTCStatus_Start */

# if defined (Rte_CallHook_Ap_PwrLmtFuncCr_SystemTime_DtrmnElapsedTime_mS_u16_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_Ap_PwrLmtFuncCr_SystemTime_DtrmnElapsedTime_mS_u16_Return
# endif
# if defined (Rte_CallHook_Ap_PwrLmtFuncCr_SystemTime_DtrmnElapsedTime_mS_u16_Return)
#  undef Rte_CallHook_Ap_PwrLmtFuncCr_SystemTime_DtrmnElapsedTime_mS_u16_Return
FUNC(void, RTE_APPL_CODE) Rte_CallHook_Ap_PwrLmtFuncCr_SystemTime_DtrmnElapsedTime_mS_u16_Return(UInt32 InitialTime, P2VAR(UInt16, AUTOMATIC, RTE_AP_PWRLMTFUNCCR_APPL_VAR) ElapsedTime);
# else
#  define Rte_CallHook_Ap_PwrLmtFuncCr_SystemTime_DtrmnElapsedTime_mS_u16_Return(arg1, arg2) ((void)(0))
# endif /* Rte_CallHook_Ap_PwrLmtFuncCr_SystemTime_DtrmnElapsedTime_mS_u16_Return */

# if defined (Rte_CallHook_Ap_PwrLmtFuncCr_SystemTime_DtrmnElapsedTime_mS_u16_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_Ap_PwrLmtFuncCr_SystemTime_DtrmnElapsedTime_mS_u16_Start
# endif
# if defined (Rte_CallHook_Ap_PwrLmtFuncCr_SystemTime_DtrmnElapsedTime_mS_u16_Start)
#  undef Rte_CallHook_Ap_PwrLmtFuncCr_SystemTime_DtrmnElapsedTime_mS_u16_Start
FUNC(void, RTE_APPL_CODE) Rte_CallHook_Ap_PwrLmtFuncCr_SystemTime_DtrmnElapsedTime_mS_u16_Start(UInt32 InitialTime, P2VAR(UInt16, AUTOMATIC, RTE_AP_PWRLMTFUNCCR_APPL_VAR) ElapsedTime);
# else
#  define Rte_CallHook_Ap_PwrLmtFuncCr_SystemTime_DtrmnElapsedTime_mS_u16_Start(arg1, arg2) ((void)(0))
# endif /* Rte_CallHook_Ap_PwrLmtFuncCr_SystemTime_DtrmnElapsedTime_mS_u16_Start */

# if defined (Rte_CallHook_Ap_PwrLmtFuncCr_SystemTime_GetSystemTime_mS_u32_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_Ap_PwrLmtFuncCr_SystemTime_GetSystemTime_mS_u32_Return
# endif
# if defined (Rte_CallHook_Ap_PwrLmtFuncCr_SystemTime_GetSystemTime_mS_u32_Return)
#  undef Rte_CallHook_Ap_PwrLmtFuncCr_SystemTime_GetSystemTime_mS_u32_Return
FUNC(void, RTE_APPL_CODE) Rte_CallHook_Ap_PwrLmtFuncCr_SystemTime_GetSystemTime_mS_u32_Return(P2VAR(UInt32, AUTOMATIC, RTE_AP_PWRLMTFUNCCR_APPL_VAR) CurrentTime);
# else
#  define Rte_CallHook_Ap_PwrLmtFuncCr_SystemTime_GetSystemTime_mS_u32_Return(arg1) ((void)(0))
# endif /* Rte_CallHook_Ap_PwrLmtFuncCr_SystemTime_GetSystemTime_mS_u32_Return */

# if defined (Rte_CallHook_Ap_PwrLmtFuncCr_SystemTime_GetSystemTime_mS_u32_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_Ap_PwrLmtFuncCr_SystemTime_GetSystemTime_mS_u32_Start
# endif
# if defined (Rte_CallHook_Ap_PwrLmtFuncCr_SystemTime_GetSystemTime_mS_u32_Start)
#  undef Rte_CallHook_Ap_PwrLmtFuncCr_SystemTime_GetSystemTime_mS_u32_Start
FUNC(void, RTE_APPL_CODE) Rte_CallHook_Ap_PwrLmtFuncCr_SystemTime_GetSystemTime_mS_u32_Start(P2VAR(UInt32, AUTOMATIC, RTE_AP_PWRLMTFUNCCR_APPL_VAR) CurrentTime);
# else
#  define Rte_CallHook_Ap_PwrLmtFuncCr_SystemTime_GetSystemTime_mS_u32_Start(arg1) ((void)(0))
# endif /* Rte_CallHook_Ap_PwrLmtFuncCr_SystemTime_GetSystemTime_mS_u32_Start */

# if defined (Rte_CallHook_Ap_ReturnFirewall_NxtrDiagMgr_SetNTCStatus_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_Ap_ReturnFirewall_NxtrDiagMgr_SetNTCStatus_Return
# endif
# if defined (Rte_CallHook_Ap_ReturnFirewall_NxtrDiagMgr_SetNTCStatus_Return)
#  undef Rte_CallHook_Ap_ReturnFirewall_NxtrDiagMgr_SetNTCStatus_Return
FUNC(void, RTE_APPL_CODE) Rte_CallHook_Ap_ReturnFirewall_NxtrDiagMgr_SetNTCStatus_Return(NTCNumber NTC_Cnt_T_enum, UInt8 Param_Cnt_T_u08, NxtrDiagMgrStatus Status_Cnt_T_enum);
# else
#  define Rte_CallHook_Ap_ReturnFirewall_NxtrDiagMgr_SetNTCStatus_Return(arg1, arg2, arg3) ((void)(0))
# endif /* Rte_CallHook_Ap_ReturnFirewall_NxtrDiagMgr_SetNTCStatus_Return */

# if defined (Rte_CallHook_Ap_ReturnFirewall_NxtrDiagMgr_SetNTCStatus_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_Ap_ReturnFirewall_NxtrDiagMgr_SetNTCStatus_Start
# endif
# if defined (Rte_CallHook_Ap_ReturnFirewall_NxtrDiagMgr_SetNTCStatus_Start)
#  undef Rte_CallHook_Ap_ReturnFirewall_NxtrDiagMgr_SetNTCStatus_Start
FUNC(void, RTE_APPL_CODE) Rte_CallHook_Ap_ReturnFirewall_NxtrDiagMgr_SetNTCStatus_Start(NTCNumber NTC_Cnt_T_enum, UInt8 Param_Cnt_T_u08, NxtrDiagMgrStatus Status_Cnt_T_enum);
# else
#  define Rte_CallHook_Ap_ReturnFirewall_NxtrDiagMgr_SetNTCStatus_Start(arg1, arg2, arg3) ((void)(0))
# endif /* Rte_CallHook_Ap_ReturnFirewall_NxtrDiagMgr_SetNTCStatus_Start */

# if defined (Rte_CallHook_Ap_Return_FltInjection_SCom_FltInjection_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_Ap_Return_FltInjection_SCom_FltInjection_Return
# endif
# if defined (Rte_CallHook_Ap_Return_FltInjection_SCom_FltInjection_Return)
#  undef Rte_CallHook_Ap_Return_FltInjection_SCom_FltInjection_Return
FUNC(void, RTE_APPL_CODE) Rte_CallHook_Ap_Return_FltInjection_SCom_FltInjection_Return(P2VAR(Float, AUTOMATIC, RTE_AP_RETURN_APPL_VAR) SignalPath_Uls_f32, FltInjectionLocType LocationKey_Cnt_enum);
# else
#  define Rte_CallHook_Ap_Return_FltInjection_SCom_FltInjection_Return(arg1, arg2) ((void)(0))
# endif /* Rte_CallHook_Ap_Return_FltInjection_SCom_FltInjection_Return */

# if defined (Rte_CallHook_Ap_Return_FltInjection_SCom_FltInjection_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_Ap_Return_FltInjection_SCom_FltInjection_Start
# endif
# if defined (Rte_CallHook_Ap_Return_FltInjection_SCom_FltInjection_Start)
#  undef Rte_CallHook_Ap_Return_FltInjection_SCom_FltInjection_Start
FUNC(void, RTE_APPL_CODE) Rte_CallHook_Ap_Return_FltInjection_SCom_FltInjection_Start(P2VAR(Float, AUTOMATIC, RTE_AP_RETURN_APPL_VAR) SignalPath_Uls_f32, FltInjectionLocType LocationKey_Cnt_enum);
# else
#  define Rte_CallHook_Ap_Return_FltInjection_SCom_FltInjection_Start(arg1, arg2) ((void)(0))
# endif /* Rte_CallHook_Ap_Return_FltInjection_SCom_FltInjection_Start */

# if defined (Rte_CallHook_Ap_SignlCondn_FaultInjection_SCom_FltInjection_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_Ap_SignlCondn_FaultInjection_SCom_FltInjection_Return
# endif
# if defined (Rte_CallHook_Ap_SignlCondn_FaultInjection_SCom_FltInjection_Return)
#  undef Rte_CallHook_Ap_SignlCondn_FaultInjection_SCom_FltInjection_Return
FUNC(void, RTE_APPL_CODE) Rte_CallHook_Ap_SignlCondn_FaultInjection_SCom_FltInjection_Return(P2VAR(Float, AUTOMATIC, RTE_AP_SIGNLCONDN_APPL_VAR) SignalPath_Uls_f32, FltInjectionLocType LocationKey_Cnt_enum);
# else
#  define Rte_CallHook_Ap_SignlCondn_FaultInjection_SCom_FltInjection_Return(arg1, arg2) ((void)(0))
# endif /* Rte_CallHook_Ap_SignlCondn_FaultInjection_SCom_FltInjection_Return */

# if defined (Rte_CallHook_Ap_SignlCondn_FaultInjection_SCom_FltInjection_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_Ap_SignlCondn_FaultInjection_SCom_FltInjection_Start
# endif
# if defined (Rte_CallHook_Ap_SignlCondn_FaultInjection_SCom_FltInjection_Start)
#  undef Rte_CallHook_Ap_SignlCondn_FaultInjection_SCom_FltInjection_Start
FUNC(void, RTE_APPL_CODE) Rte_CallHook_Ap_SignlCondn_FaultInjection_SCom_FltInjection_Start(P2VAR(Float, AUTOMATIC, RTE_AP_SIGNLCONDN_APPL_VAR) SignalPath_Uls_f32, FltInjectionLocType LocationKey_Cnt_enum);
# else
#  define Rte_CallHook_Ap_SignlCondn_FaultInjection_SCom_FltInjection_Start(arg1, arg2) ((void)(0))
# endif /* Rte_CallHook_Ap_SignlCondn_FaultInjection_SCom_FltInjection_Start */

# if defined (Rte_CallHook_Ap_SrlComInput_NxtrDiagMgr_GetNTCFailed_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_Ap_SrlComInput_NxtrDiagMgr_GetNTCFailed_Return
# endif
# if defined (Rte_CallHook_Ap_SrlComInput_NxtrDiagMgr_GetNTCFailed_Return)
#  undef Rte_CallHook_Ap_SrlComInput_NxtrDiagMgr_GetNTCFailed_Return
FUNC(void, RTE_APPL_CODE) Rte_CallHook_Ap_SrlComInput_NxtrDiagMgr_GetNTCFailed_Return(NTCNumber NTC_Cnt_T_enum, P2VAR(Boolean, AUTOMATIC, RTE_AP_SRLCOMINPUT_APPL_VAR) NTCFailed_Ptr_T_lgc);
# else
#  define Rte_CallHook_Ap_SrlComInput_NxtrDiagMgr_GetNTCFailed_Return(arg1, arg2) ((void)(0))
# endif /* Rte_CallHook_Ap_SrlComInput_NxtrDiagMgr_GetNTCFailed_Return */

# if defined (Rte_CallHook_Ap_SrlComInput_NxtrDiagMgr_GetNTCFailed_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_Ap_SrlComInput_NxtrDiagMgr_GetNTCFailed_Start
# endif
# if defined (Rte_CallHook_Ap_SrlComInput_NxtrDiagMgr_GetNTCFailed_Start)
#  undef Rte_CallHook_Ap_SrlComInput_NxtrDiagMgr_GetNTCFailed_Start
FUNC(void, RTE_APPL_CODE) Rte_CallHook_Ap_SrlComInput_NxtrDiagMgr_GetNTCFailed_Start(NTCNumber NTC_Cnt_T_enum, P2VAR(Boolean, AUTOMATIC, RTE_AP_SRLCOMINPUT_APPL_VAR) NTCFailed_Ptr_T_lgc);
# else
#  define Rte_CallHook_Ap_SrlComInput_NxtrDiagMgr_GetNTCFailed_Start(arg1, arg2) ((void)(0))
# endif /* Rte_CallHook_Ap_SrlComInput_NxtrDiagMgr_GetNTCFailed_Start */

# if defined (Rte_CallHook_Ap_SrlComInput_NxtrDiagMgr_GetNTCStatus_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_Ap_SrlComInput_NxtrDiagMgr_GetNTCStatus_Return
# endif
# if defined (Rte_CallHook_Ap_SrlComInput_NxtrDiagMgr_GetNTCStatus_Return)
#  undef Rte_CallHook_Ap_SrlComInput_NxtrDiagMgr_GetNTCStatus_Return
FUNC(void, RTE_APPL_CODE) Rte_CallHook_Ap_SrlComInput_NxtrDiagMgr_GetNTCStatus_Return(NTCNumber NTC_Cnt_T_enum, P2VAR(UInt8, AUTOMATIC, RTE_AP_SRLCOMINPUT_APPL_VAR) Status_Ptr_T_u08);
# else
#  define Rte_CallHook_Ap_SrlComInput_NxtrDiagMgr_GetNTCStatus_Return(arg1, arg2) ((void)(0))
# endif /* Rte_CallHook_Ap_SrlComInput_NxtrDiagMgr_GetNTCStatus_Return */

# if defined (Rte_CallHook_Ap_SrlComInput_NxtrDiagMgr_GetNTCStatus_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_Ap_SrlComInput_NxtrDiagMgr_GetNTCStatus_Start
# endif
# if defined (Rte_CallHook_Ap_SrlComInput_NxtrDiagMgr_GetNTCStatus_Start)
#  undef Rte_CallHook_Ap_SrlComInput_NxtrDiagMgr_GetNTCStatus_Start
FUNC(void, RTE_APPL_CODE) Rte_CallHook_Ap_SrlComInput_NxtrDiagMgr_GetNTCStatus_Start(NTCNumber NTC_Cnt_T_enum, P2VAR(UInt8, AUTOMATIC, RTE_AP_SRLCOMINPUT_APPL_VAR) Status_Ptr_T_u08);
# else
#  define Rte_CallHook_Ap_SrlComInput_NxtrDiagMgr_GetNTCStatus_Start(arg1, arg2) ((void)(0))
# endif /* Rte_CallHook_Ap_SrlComInput_NxtrDiagMgr_GetNTCStatus_Start */

# if defined (Rte_CallHook_Ap_SrlComInput_NxtrDiagMgr_SetNTCStatus_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_Ap_SrlComInput_NxtrDiagMgr_SetNTCStatus_Return
# endif
# if defined (Rte_CallHook_Ap_SrlComInput_NxtrDiagMgr_SetNTCStatus_Return)
#  undef Rte_CallHook_Ap_SrlComInput_NxtrDiagMgr_SetNTCStatus_Return
FUNC(void, RTE_APPL_CODE) Rte_CallHook_Ap_SrlComInput_NxtrDiagMgr_SetNTCStatus_Return(NTCNumber NTC_Cnt_T_enum, UInt8 Param_Cnt_T_u08, NxtrDiagMgrStatus Status_Cnt_T_enum);
# else
#  define Rte_CallHook_Ap_SrlComInput_NxtrDiagMgr_SetNTCStatus_Return(arg1, arg2, arg3) ((void)(0))
# endif /* Rte_CallHook_Ap_SrlComInput_NxtrDiagMgr_SetNTCStatus_Return */

# if defined (Rte_CallHook_Ap_SrlComInput_NxtrDiagMgr_SetNTCStatus_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_Ap_SrlComInput_NxtrDiagMgr_SetNTCStatus_Start
# endif
# if defined (Rte_CallHook_Ap_SrlComInput_NxtrDiagMgr_SetNTCStatus_Start)
#  undef Rte_CallHook_Ap_SrlComInput_NxtrDiagMgr_SetNTCStatus_Start
FUNC(void, RTE_APPL_CODE) Rte_CallHook_Ap_SrlComInput_NxtrDiagMgr_SetNTCStatus_Start(NTCNumber NTC_Cnt_T_enum, UInt8 Param_Cnt_T_u08, NxtrDiagMgrStatus Status_Cnt_T_enum);
# else
#  define Rte_CallHook_Ap_SrlComInput_NxtrDiagMgr_SetNTCStatus_Start(arg1, arg2, arg3) ((void)(0))
# endif /* Rte_CallHook_Ap_SrlComInput_NxtrDiagMgr_SetNTCStatus_Start */

# if defined (Rte_CallHook_Ap_SrlComInput_SrlComInput_Per1_CP0_CheckpointReached_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_Ap_SrlComInput_SrlComInput_Per1_CP0_CheckpointReached_Return
# endif
# if defined (Rte_CallHook_Ap_SrlComInput_SrlComInput_Per1_CP0_CheckpointReached_Return)
#  undef Rte_CallHook_Ap_SrlComInput_SrlComInput_Per1_CP0_CheckpointReached_Return
FUNC(void, RTE_APPL_CODE) Rte_CallHook_Ap_SrlComInput_SrlComInput_Per1_CP0_CheckpointReached_Return(void);
# else
#  define Rte_CallHook_Ap_SrlComInput_SrlComInput_Per1_CP0_CheckpointReached_Return() ((void)(0))
# endif /* Rte_CallHook_Ap_SrlComInput_SrlComInput_Per1_CP0_CheckpointReached_Return */

# if defined (Rte_CallHook_Ap_SrlComInput_SrlComInput_Per1_CP0_CheckpointReached_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_Ap_SrlComInput_SrlComInput_Per1_CP0_CheckpointReached_Start
# endif
# if defined (Rte_CallHook_Ap_SrlComInput_SrlComInput_Per1_CP0_CheckpointReached_Start)
#  undef Rte_CallHook_Ap_SrlComInput_SrlComInput_Per1_CP0_CheckpointReached_Start
FUNC(void, RTE_APPL_CODE) Rte_CallHook_Ap_SrlComInput_SrlComInput_Per1_CP0_CheckpointReached_Start(void);
# else
#  define Rte_CallHook_Ap_SrlComInput_SrlComInput_Per1_CP0_CheckpointReached_Start() ((void)(0))
# endif /* Rte_CallHook_Ap_SrlComInput_SrlComInput_Per1_CP0_CheckpointReached_Start */

# if defined (Rte_CallHook_Ap_SrlComInput_SystemTime_DtrmnElapsedTime_mS_u16_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_Ap_SrlComInput_SystemTime_DtrmnElapsedTime_mS_u16_Return
# endif
# if defined (Rte_CallHook_Ap_SrlComInput_SystemTime_DtrmnElapsedTime_mS_u16_Return)
#  undef Rte_CallHook_Ap_SrlComInput_SystemTime_DtrmnElapsedTime_mS_u16_Return
FUNC(void, RTE_APPL_CODE) Rte_CallHook_Ap_SrlComInput_SystemTime_DtrmnElapsedTime_mS_u16_Return(UInt32 InitialTime, P2VAR(UInt16, AUTOMATIC, RTE_AP_SRLCOMINPUT_APPL_VAR) ElapsedTime);
# else
#  define Rte_CallHook_Ap_SrlComInput_SystemTime_DtrmnElapsedTime_mS_u16_Return(arg1, arg2) ((void)(0))
# endif /* Rte_CallHook_Ap_SrlComInput_SystemTime_DtrmnElapsedTime_mS_u16_Return */

# if defined (Rte_CallHook_Ap_SrlComInput_SystemTime_DtrmnElapsedTime_mS_u16_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_Ap_SrlComInput_SystemTime_DtrmnElapsedTime_mS_u16_Start
# endif
# if defined (Rte_CallHook_Ap_SrlComInput_SystemTime_DtrmnElapsedTime_mS_u16_Start)
#  undef Rte_CallHook_Ap_SrlComInput_SystemTime_DtrmnElapsedTime_mS_u16_Start
FUNC(void, RTE_APPL_CODE) Rte_CallHook_Ap_SrlComInput_SystemTime_DtrmnElapsedTime_mS_u16_Start(UInt32 InitialTime, P2VAR(UInt16, AUTOMATIC, RTE_AP_SRLCOMINPUT_APPL_VAR) ElapsedTime);
# else
#  define Rte_CallHook_Ap_SrlComInput_SystemTime_DtrmnElapsedTime_mS_u16_Start(arg1, arg2) ((void)(0))
# endif /* Rte_CallHook_Ap_SrlComInput_SystemTime_DtrmnElapsedTime_mS_u16_Start */

# if defined (Rte_CallHook_Ap_SrlComInput_SystemTime_DtrmnElapsedTime_mS_u32_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_Ap_SrlComInput_SystemTime_DtrmnElapsedTime_mS_u32_Return
# endif
# if defined (Rte_CallHook_Ap_SrlComInput_SystemTime_DtrmnElapsedTime_mS_u32_Return)
#  undef Rte_CallHook_Ap_SrlComInput_SystemTime_DtrmnElapsedTime_mS_u32_Return
FUNC(void, RTE_APPL_CODE) Rte_CallHook_Ap_SrlComInput_SystemTime_DtrmnElapsedTime_mS_u32_Return(UInt32 InitialTime, P2VAR(UInt32, AUTOMATIC, RTE_AP_SRLCOMINPUT_APPL_VAR) ElapsedTime);
# else
#  define Rte_CallHook_Ap_SrlComInput_SystemTime_DtrmnElapsedTime_mS_u32_Return(arg1, arg2) ((void)(0))
# endif /* Rte_CallHook_Ap_SrlComInput_SystemTime_DtrmnElapsedTime_mS_u32_Return */

# if defined (Rte_CallHook_Ap_SrlComInput_SystemTime_DtrmnElapsedTime_mS_u32_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_Ap_SrlComInput_SystemTime_DtrmnElapsedTime_mS_u32_Start
# endif
# if defined (Rte_CallHook_Ap_SrlComInput_SystemTime_DtrmnElapsedTime_mS_u32_Start)
#  undef Rte_CallHook_Ap_SrlComInput_SystemTime_DtrmnElapsedTime_mS_u32_Start
FUNC(void, RTE_APPL_CODE) Rte_CallHook_Ap_SrlComInput_SystemTime_DtrmnElapsedTime_mS_u32_Start(UInt32 InitialTime, P2VAR(UInt32, AUTOMATIC, RTE_AP_SRLCOMINPUT_APPL_VAR) ElapsedTime);
# else
#  define Rte_CallHook_Ap_SrlComInput_SystemTime_DtrmnElapsedTime_mS_u32_Start(arg1, arg2) ((void)(0))
# endif /* Rte_CallHook_Ap_SrlComInput_SystemTime_DtrmnElapsedTime_mS_u32_Start */

# if defined (Rte_CallHook_Ap_SrlComInput_SystemTime_GetSystemTime_mS_u32_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_Ap_SrlComInput_SystemTime_GetSystemTime_mS_u32_Return
# endif
# if defined (Rte_CallHook_Ap_SrlComInput_SystemTime_GetSystemTime_mS_u32_Return)
#  undef Rte_CallHook_Ap_SrlComInput_SystemTime_GetSystemTime_mS_u32_Return
FUNC(void, RTE_APPL_CODE) Rte_CallHook_Ap_SrlComInput_SystemTime_GetSystemTime_mS_u32_Return(P2VAR(UInt32, AUTOMATIC, RTE_AP_SRLCOMINPUT_APPL_VAR) CurrentTime);
# else
#  define Rte_CallHook_Ap_SrlComInput_SystemTime_GetSystemTime_mS_u32_Return(arg1) ((void)(0))
# endif /* Rte_CallHook_Ap_SrlComInput_SystemTime_GetSystemTime_mS_u32_Return */

# if defined (Rte_CallHook_Ap_SrlComInput_SystemTime_GetSystemTime_mS_u32_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_Ap_SrlComInput_SystemTime_GetSystemTime_mS_u32_Start
# endif
# if defined (Rte_CallHook_Ap_SrlComInput_SystemTime_GetSystemTime_mS_u32_Start)
#  undef Rte_CallHook_Ap_SrlComInput_SystemTime_GetSystemTime_mS_u32_Start
FUNC(void, RTE_APPL_CODE) Rte_CallHook_Ap_SrlComInput_SystemTime_GetSystemTime_mS_u32_Start(P2VAR(UInt32, AUTOMATIC, RTE_AP_SRLCOMINPUT_APPL_VAR) CurrentTime);
# else
#  define Rte_CallHook_Ap_SrlComInput_SystemTime_GetSystemTime_mS_u32_Start(arg1) ((void)(0))
# endif /* Rte_CallHook_Ap_SrlComInput_SystemTime_GetSystemTime_mS_u32_Start */

# if defined (Rte_CallHook_Ap_SrlComOutput_NxtrDiagMgr_GetNTCFailed_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_Ap_SrlComOutput_NxtrDiagMgr_GetNTCFailed_Return
# endif
# if defined (Rte_CallHook_Ap_SrlComOutput_NxtrDiagMgr_GetNTCFailed_Return)
#  undef Rte_CallHook_Ap_SrlComOutput_NxtrDiagMgr_GetNTCFailed_Return
FUNC(void, RTE_APPL_CODE) Rte_CallHook_Ap_SrlComOutput_NxtrDiagMgr_GetNTCFailed_Return(NTCNumber NTC_Cnt_T_enum, P2VAR(Boolean, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_VAR) NTCFailed_Ptr_T_lgc);
# else
#  define Rte_CallHook_Ap_SrlComOutput_NxtrDiagMgr_GetNTCFailed_Return(arg1, arg2) ((void)(0))
# endif /* Rte_CallHook_Ap_SrlComOutput_NxtrDiagMgr_GetNTCFailed_Return */

# if defined (Rte_CallHook_Ap_SrlComOutput_NxtrDiagMgr_GetNTCFailed_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_Ap_SrlComOutput_NxtrDiagMgr_GetNTCFailed_Start
# endif
# if defined (Rte_CallHook_Ap_SrlComOutput_NxtrDiagMgr_GetNTCFailed_Start)
#  undef Rte_CallHook_Ap_SrlComOutput_NxtrDiagMgr_GetNTCFailed_Start
FUNC(void, RTE_APPL_CODE) Rte_CallHook_Ap_SrlComOutput_NxtrDiagMgr_GetNTCFailed_Start(NTCNumber NTC_Cnt_T_enum, P2VAR(Boolean, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_VAR) NTCFailed_Ptr_T_lgc);
# else
#  define Rte_CallHook_Ap_SrlComOutput_NxtrDiagMgr_GetNTCFailed_Start(arg1, arg2) ((void)(0))
# endif /* Rte_CallHook_Ap_SrlComOutput_NxtrDiagMgr_GetNTCFailed_Start */

# if defined (Rte_CallHook_Ap_SrlComOutput_SystemTime_DtrmnElapsedTime_mS_u32_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_Ap_SrlComOutput_SystemTime_DtrmnElapsedTime_mS_u32_Return
# endif
# if defined (Rte_CallHook_Ap_SrlComOutput_SystemTime_DtrmnElapsedTime_mS_u32_Return)
#  undef Rte_CallHook_Ap_SrlComOutput_SystemTime_DtrmnElapsedTime_mS_u32_Return
FUNC(void, RTE_APPL_CODE) Rte_CallHook_Ap_SrlComOutput_SystemTime_DtrmnElapsedTime_mS_u32_Return(UInt32 InitialTime, P2VAR(UInt32, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_VAR) ElapsedTime);
# else
#  define Rte_CallHook_Ap_SrlComOutput_SystemTime_DtrmnElapsedTime_mS_u32_Return(arg1, arg2) ((void)(0))
# endif /* Rte_CallHook_Ap_SrlComOutput_SystemTime_DtrmnElapsedTime_mS_u32_Return */

# if defined (Rte_CallHook_Ap_SrlComOutput_SystemTime_DtrmnElapsedTime_mS_u32_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_Ap_SrlComOutput_SystemTime_DtrmnElapsedTime_mS_u32_Start
# endif
# if defined (Rte_CallHook_Ap_SrlComOutput_SystemTime_DtrmnElapsedTime_mS_u32_Start)
#  undef Rte_CallHook_Ap_SrlComOutput_SystemTime_DtrmnElapsedTime_mS_u32_Start
FUNC(void, RTE_APPL_CODE) Rte_CallHook_Ap_SrlComOutput_SystemTime_DtrmnElapsedTime_mS_u32_Start(UInt32 InitialTime, P2VAR(UInt32, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_VAR) ElapsedTime);
# else
#  define Rte_CallHook_Ap_SrlComOutput_SystemTime_DtrmnElapsedTime_mS_u32_Start(arg1, arg2) ((void)(0))
# endif /* Rte_CallHook_Ap_SrlComOutput_SystemTime_DtrmnElapsedTime_mS_u32_Start */

# if defined (Rte_CallHook_Ap_SrlComOutput_SystemTime_GetSystemTime_mS_u32_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_Ap_SrlComOutput_SystemTime_GetSystemTime_mS_u32_Return
# endif
# if defined (Rte_CallHook_Ap_SrlComOutput_SystemTime_GetSystemTime_mS_u32_Return)
#  undef Rte_CallHook_Ap_SrlComOutput_SystemTime_GetSystemTime_mS_u32_Return
FUNC(void, RTE_APPL_CODE) Rte_CallHook_Ap_SrlComOutput_SystemTime_GetSystemTime_mS_u32_Return(P2VAR(UInt32, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_VAR) CurrentTime);
# else
#  define Rte_CallHook_Ap_SrlComOutput_SystemTime_GetSystemTime_mS_u32_Return(arg1) ((void)(0))
# endif /* Rte_CallHook_Ap_SrlComOutput_SystemTime_GetSystemTime_mS_u32_Return */

# if defined (Rte_CallHook_Ap_SrlComOutput_SystemTime_GetSystemTime_mS_u32_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_Ap_SrlComOutput_SystemTime_GetSystemTime_mS_u32_Start
# endif
# if defined (Rte_CallHook_Ap_SrlComOutput_SystemTime_GetSystemTime_mS_u32_Start)
#  undef Rte_CallHook_Ap_SrlComOutput_SystemTime_GetSystemTime_mS_u32_Start
FUNC(void, RTE_APPL_CODE) Rte_CallHook_Ap_SrlComOutput_SystemTime_GetSystemTime_mS_u32_Start(P2VAR(UInt32, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_VAR) CurrentTime);
# else
#  define Rte_CallHook_Ap_SrlComOutput_SystemTime_GetSystemTime_mS_u32_Start(arg1) ((void)(0))
# endif /* Rte_CallHook_Ap_SrlComOutput_SystemTime_GetSystemTime_mS_u32_Start */

# if defined (Rte_CallHook_Ap_StOpCtrl_SystemTime_DtrmnElapsedTime_mS_u32_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_Ap_StOpCtrl_SystemTime_DtrmnElapsedTime_mS_u32_Return
# endif
# if defined (Rte_CallHook_Ap_StOpCtrl_SystemTime_DtrmnElapsedTime_mS_u32_Return)
#  undef Rte_CallHook_Ap_StOpCtrl_SystemTime_DtrmnElapsedTime_mS_u32_Return
FUNC(void, RTE_APPL_CODE) Rte_CallHook_Ap_StOpCtrl_SystemTime_DtrmnElapsedTime_mS_u32_Return(UInt32 InitialTime, P2VAR(UInt32, AUTOMATIC, RTE_AP_STOPCTRL_APPL_VAR) ElapsedTime);
# else
#  define Rte_CallHook_Ap_StOpCtrl_SystemTime_DtrmnElapsedTime_mS_u32_Return(arg1, arg2) ((void)(0))
# endif /* Rte_CallHook_Ap_StOpCtrl_SystemTime_DtrmnElapsedTime_mS_u32_Return */

# if defined (Rte_CallHook_Ap_StOpCtrl_SystemTime_DtrmnElapsedTime_mS_u32_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_Ap_StOpCtrl_SystemTime_DtrmnElapsedTime_mS_u32_Start
# endif
# if defined (Rte_CallHook_Ap_StOpCtrl_SystemTime_DtrmnElapsedTime_mS_u32_Start)
#  undef Rte_CallHook_Ap_StOpCtrl_SystemTime_DtrmnElapsedTime_mS_u32_Start
FUNC(void, RTE_APPL_CODE) Rte_CallHook_Ap_StOpCtrl_SystemTime_DtrmnElapsedTime_mS_u32_Start(UInt32 InitialTime, P2VAR(UInt32, AUTOMATIC, RTE_AP_STOPCTRL_APPL_VAR) ElapsedTime);
# else
#  define Rte_CallHook_Ap_StOpCtrl_SystemTime_DtrmnElapsedTime_mS_u32_Start(arg1, arg2) ((void)(0))
# endif /* Rte_CallHook_Ap_StOpCtrl_SystemTime_DtrmnElapsedTime_mS_u32_Start */

# if defined (Rte_CallHook_Ap_StOpCtrl_SystemTime_GetSystemTime_mS_u32_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_Ap_StOpCtrl_SystemTime_GetSystemTime_mS_u32_Return
# endif
# if defined (Rte_CallHook_Ap_StOpCtrl_SystemTime_GetSystemTime_mS_u32_Return)
#  undef Rte_CallHook_Ap_StOpCtrl_SystemTime_GetSystemTime_mS_u32_Return
FUNC(void, RTE_APPL_CODE) Rte_CallHook_Ap_StOpCtrl_SystemTime_GetSystemTime_mS_u32_Return(P2VAR(UInt32, AUTOMATIC, RTE_AP_STOPCTRL_APPL_VAR) CurrentTime);
# else
#  define Rte_CallHook_Ap_StOpCtrl_SystemTime_GetSystemTime_mS_u32_Return(arg1) ((void)(0))
# endif /* Rte_CallHook_Ap_StOpCtrl_SystemTime_GetSystemTime_mS_u32_Return */

# if defined (Rte_CallHook_Ap_StOpCtrl_SystemTime_GetSystemTime_mS_u32_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_Ap_StOpCtrl_SystemTime_GetSystemTime_mS_u32_Start
# endif
# if defined (Rte_CallHook_Ap_StOpCtrl_SystemTime_GetSystemTime_mS_u32_Start)
#  undef Rte_CallHook_Ap_StOpCtrl_SystemTime_GetSystemTime_mS_u32_Start
FUNC(void, RTE_APPL_CODE) Rte_CallHook_Ap_StOpCtrl_SystemTime_GetSystemTime_mS_u32_Start(P2VAR(UInt32, AUTOMATIC, RTE_AP_STOPCTRL_APPL_VAR) CurrentTime);
# else
#  define Rte_CallHook_Ap_StOpCtrl_SystemTime_GetSystemTime_mS_u32_Start(arg1) ((void)(0))
# endif /* Rte_CallHook_Ap_StOpCtrl_SystemTime_GetSystemTime_mS_u32_Start */

# if defined (Rte_CallHook_Ap_StaMd9_DiagMgr_StaCtrl_Shutdown_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_Ap_StaMd9_DiagMgr_StaCtrl_Shutdown_Return
# endif
# if defined (Rte_CallHook_Ap_StaMd9_DiagMgr_StaCtrl_Shutdown_Return)
#  undef Rte_CallHook_Ap_StaMd9_DiagMgr_StaCtrl_Shutdown_Return
FUNC(void, RTE_APPL_CODE) Rte_CallHook_Ap_StaMd9_DiagMgr_StaCtrl_Shutdown_Return(void);
# else
#  define Rte_CallHook_Ap_StaMd9_DiagMgr_StaCtrl_Shutdown_Return() ((void)(0))
# endif /* Rte_CallHook_Ap_StaMd9_DiagMgr_StaCtrl_Shutdown_Return */

# if defined (Rte_CallHook_Ap_StaMd9_DiagMgr_StaCtrl_Shutdown_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_Ap_StaMd9_DiagMgr_StaCtrl_Shutdown_Start
# endif
# if defined (Rte_CallHook_Ap_StaMd9_DiagMgr_StaCtrl_Shutdown_Start)
#  undef Rte_CallHook_Ap_StaMd9_DiagMgr_StaCtrl_Shutdown_Start
FUNC(void, RTE_APPL_CODE) Rte_CallHook_Ap_StaMd9_DiagMgr_StaCtrl_Shutdown_Start(void);
# else
#  define Rte_CallHook_Ap_StaMd9_DiagMgr_StaCtrl_Shutdown_Start() ((void)(0))
# endif /* Rte_CallHook_Ap_StaMd9_DiagMgr_StaCtrl_Shutdown_Start */

# if defined (Rte_CallHook_Ap_StaMd_CloseCheckData_GetErrorStatus_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_Ap_StaMd_CloseCheckData_GetErrorStatus_Return
# endif
# if defined (Rte_CallHook_Ap_StaMd_CloseCheckData_GetErrorStatus_Return)
#  undef Rte_CallHook_Ap_StaMd_CloseCheckData_GetErrorStatus_Return
FUNC(void, RTE_APPL_CODE) Rte_CallHook_Ap_StaMd_CloseCheckData_GetErrorStatus_Return(P2VAR(NvM_RequestResultType, AUTOMATIC, RTE_AP_STAMD_APPL_VAR) ErrorStatus);
# else
#  define Rte_CallHook_Ap_StaMd_CloseCheckData_GetErrorStatus_Return(arg1) ((void)(0))
# endif /* Rte_CallHook_Ap_StaMd_CloseCheckData_GetErrorStatus_Return */

# if defined (Rte_CallHook_Ap_StaMd_CloseCheckData_GetErrorStatus_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_Ap_StaMd_CloseCheckData_GetErrorStatus_Start
# endif
# if defined (Rte_CallHook_Ap_StaMd_CloseCheckData_GetErrorStatus_Start)
#  undef Rte_CallHook_Ap_StaMd_CloseCheckData_GetErrorStatus_Start
FUNC(void, RTE_APPL_CODE) Rte_CallHook_Ap_StaMd_CloseCheckData_GetErrorStatus_Start(P2VAR(NvM_RequestResultType, AUTOMATIC, RTE_AP_STAMD_APPL_VAR) ErrorStatus);
# else
#  define Rte_CallHook_Ap_StaMd_CloseCheckData_GetErrorStatus_Start(arg1) ((void)(0))
# endif /* Rte_CallHook_Ap_StaMd_CloseCheckData_GetErrorStatus_Start */

# if defined (Rte_CallHook_Ap_StaMd_CloseCheckData_WriteBlock_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_Ap_StaMd_CloseCheckData_WriteBlock_Return
# endif
# if defined (Rte_CallHook_Ap_StaMd_CloseCheckData_WriteBlock_Return)
#  undef Rte_CallHook_Ap_StaMd_CloseCheckData_WriteBlock_Return
FUNC(void, RTE_APPL_CODE) Rte_CallHook_Ap_StaMd_CloseCheckData_WriteBlock_Return(P2CONST(NvM_DestPtr, AUTOMATIC, RTE_AP_STAMD_APPL_DATA) DstPtr);
# else
#  define Rte_CallHook_Ap_StaMd_CloseCheckData_WriteBlock_Return(arg1) ((void)(0))
# endif /* Rte_CallHook_Ap_StaMd_CloseCheckData_WriteBlock_Return */

# if defined (Rte_CallHook_Ap_StaMd_CloseCheckData_WriteBlock_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_Ap_StaMd_CloseCheckData_WriteBlock_Start
# endif
# if defined (Rte_CallHook_Ap_StaMd_CloseCheckData_WriteBlock_Start)
#  undef Rte_CallHook_Ap_StaMd_CloseCheckData_WriteBlock_Start
FUNC(void, RTE_APPL_CODE) Rte_CallHook_Ap_StaMd_CloseCheckData_WriteBlock_Start(P2CONST(NvM_DestPtr, AUTOMATIC, RTE_AP_STAMD_APPL_DATA) DstPtr);
# else
#  define Rte_CallHook_Ap_StaMd_CloseCheckData_WriteBlock_Start(arg1) ((void)(0))
# endif /* Rte_CallHook_Ap_StaMd_CloseCheckData_WriteBlock_Start */

# if defined (Rte_CallHook_Ap_StaMd_NxtrDiagMgr_SetNTCStatus_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_Ap_StaMd_NxtrDiagMgr_SetNTCStatus_Return
# endif
# if defined (Rte_CallHook_Ap_StaMd_NxtrDiagMgr_SetNTCStatus_Return)
#  undef Rte_CallHook_Ap_StaMd_NxtrDiagMgr_SetNTCStatus_Return
FUNC(void, RTE_APPL_CODE) Rte_CallHook_Ap_StaMd_NxtrDiagMgr_SetNTCStatus_Return(NTCNumber NTC_Cnt_T_enum, UInt8 Param_Cnt_T_u08, NxtrDiagMgrStatus Status_Cnt_T_enum);
# else
#  define Rte_CallHook_Ap_StaMd_NxtrDiagMgr_SetNTCStatus_Return(arg1, arg2, arg3) ((void)(0))
# endif /* Rte_CallHook_Ap_StaMd_NxtrDiagMgr_SetNTCStatus_Return */

# if defined (Rte_CallHook_Ap_StaMd_NxtrDiagMgr_SetNTCStatus_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_Ap_StaMd_NxtrDiagMgr_SetNTCStatus_Start
# endif
# if defined (Rte_CallHook_Ap_StaMd_NxtrDiagMgr_SetNTCStatus_Start)
#  undef Rte_CallHook_Ap_StaMd_NxtrDiagMgr_SetNTCStatus_Start
FUNC(void, RTE_APPL_CODE) Rte_CallHook_Ap_StaMd_NxtrDiagMgr_SetNTCStatus_Start(NTCNumber NTC_Cnt_T_enum, UInt8 Param_Cnt_T_u08, NxtrDiagMgrStatus Status_Cnt_T_enum);
# else
#  define Rte_CallHook_Ap_StaMd_NxtrDiagMgr_SetNTCStatus_Start(arg1, arg2, arg3) ((void)(0))
# endif /* Rte_CallHook_Ap_StaMd_NxtrDiagMgr_SetNTCStatus_Start */

# if defined (Rte_CallHook_Ap_StaMd_StaMd_Per1_CP1_CheckpointReached_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_Ap_StaMd_StaMd_Per1_CP1_CheckpointReached_Return
# endif
# if defined (Rte_CallHook_Ap_StaMd_StaMd_Per1_CP1_CheckpointReached_Return)
#  undef Rte_CallHook_Ap_StaMd_StaMd_Per1_CP1_CheckpointReached_Return
FUNC(void, RTE_APPL_CODE) Rte_CallHook_Ap_StaMd_StaMd_Per1_CP1_CheckpointReached_Return(void);
# else
#  define Rte_CallHook_Ap_StaMd_StaMd_Per1_CP1_CheckpointReached_Return() ((void)(0))
# endif /* Rte_CallHook_Ap_StaMd_StaMd_Per1_CP1_CheckpointReached_Return */

# if defined (Rte_CallHook_Ap_StaMd_StaMd_Per1_CP1_CheckpointReached_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_Ap_StaMd_StaMd_Per1_CP1_CheckpointReached_Start
# endif
# if defined (Rte_CallHook_Ap_StaMd_StaMd_Per1_CP1_CheckpointReached_Start)
#  undef Rte_CallHook_Ap_StaMd_StaMd_Per1_CP1_CheckpointReached_Start
FUNC(void, RTE_APPL_CODE) Rte_CallHook_Ap_StaMd_StaMd_Per1_CP1_CheckpointReached_Start(void);
# else
#  define Rte_CallHook_Ap_StaMd_StaMd_Per1_CP1_CheckpointReached_Start() ((void)(0))
# endif /* Rte_CallHook_Ap_StaMd_StaMd_Per1_CP1_CheckpointReached_Start */

# if defined (Rte_CallHook_Ap_StaMd_TOD_OP_SET_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_Ap_StaMd_TOD_OP_SET_Return
# endif
# if defined (Rte_CallHook_Ap_StaMd_TOD_OP_SET_Return)
#  undef Rte_CallHook_Ap_StaMd_TOD_OP_SET_Return
FUNC(void, RTE_APPL_CODE) Rte_CallHook_Ap_StaMd_TOD_OP_SET_Return(IoHwAb_BoolType signal);
# else
#  define Rte_CallHook_Ap_StaMd_TOD_OP_SET_Return(arg1) ((void)(0))
# endif /* Rte_CallHook_Ap_StaMd_TOD_OP_SET_Return */

# if defined (Rte_CallHook_Ap_StaMd_TOD_OP_SET_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_Ap_StaMd_TOD_OP_SET_Start
# endif
# if defined (Rte_CallHook_Ap_StaMd_TOD_OP_SET_Start)
#  undef Rte_CallHook_Ap_StaMd_TOD_OP_SET_Start
FUNC(void, RTE_APPL_CODE) Rte_CallHook_Ap_StaMd_TOD_OP_SET_Start(IoHwAb_BoolType signal);
# else
#  define Rte_CallHook_Ap_StaMd_TOD_OP_SET_Start(arg1) ((void)(0))
# endif /* Rte_CallHook_Ap_StaMd_TOD_OP_SET_Start */

# if defined (Rte_CallHook_Ap_StaMd_TypeHData_WriteBlock_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_Ap_StaMd_TypeHData_WriteBlock_Return
# endif
# if defined (Rte_CallHook_Ap_StaMd_TypeHData_WriteBlock_Return)
#  undef Rte_CallHook_Ap_StaMd_TypeHData_WriteBlock_Return
FUNC(void, RTE_APPL_CODE) Rte_CallHook_Ap_StaMd_TypeHData_WriteBlock_Return(P2CONST(NvM_DestPtr, AUTOMATIC, RTE_AP_STAMD_APPL_DATA) DstPtr);
# else
#  define Rte_CallHook_Ap_StaMd_TypeHData_WriteBlock_Return(arg1) ((void)(0))
# endif /* Rte_CallHook_Ap_StaMd_TypeHData_WriteBlock_Return */

# if defined (Rte_CallHook_Ap_StaMd_TypeHData_WriteBlock_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_Ap_StaMd_TypeHData_WriteBlock_Start
# endif
# if defined (Rte_CallHook_Ap_StaMd_TypeHData_WriteBlock_Start)
#  undef Rte_CallHook_Ap_StaMd_TypeHData_WriteBlock_Start
FUNC(void, RTE_APPL_CODE) Rte_CallHook_Ap_StaMd_TypeHData_WriteBlock_Start(P2CONST(NvM_DestPtr, AUTOMATIC, RTE_AP_STAMD_APPL_DATA) DstPtr);
# else
#  define Rte_CallHook_Ap_StaMd_TypeHData_WriteBlock_Start(arg1) ((void)(0))
# endif /* Rte_CallHook_Ap_StaMd_TypeHData_WriteBlock_Start */

# if defined (Rte_CallHook_Ap_StabilityComp_FaultInjection_SCom_FltInjection_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_Ap_StabilityComp_FaultInjection_SCom_FltInjection_Return
# endif
# if defined (Rte_CallHook_Ap_StabilityComp_FaultInjection_SCom_FltInjection_Return)
#  undef Rte_CallHook_Ap_StabilityComp_FaultInjection_SCom_FltInjection_Return
FUNC(void, RTE_APPL_CODE) Rte_CallHook_Ap_StabilityComp_FaultInjection_SCom_FltInjection_Return(P2VAR(Float, AUTOMATIC, RTE_AP_STABILITYCOMP_APPL_VAR) SignalPath_Uls_f32, FltInjectionLocType LocationKey_Cnt_enum);
# else
#  define Rte_CallHook_Ap_StabilityComp_FaultInjection_SCom_FltInjection_Return(arg1, arg2) ((void)(0))
# endif /* Rte_CallHook_Ap_StabilityComp_FaultInjection_SCom_FltInjection_Return */

# if defined (Rte_CallHook_Ap_StabilityComp_FaultInjection_SCom_FltInjection_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_Ap_StabilityComp_FaultInjection_SCom_FltInjection_Start
# endif
# if defined (Rte_CallHook_Ap_StabilityComp_FaultInjection_SCom_FltInjection_Start)
#  undef Rte_CallHook_Ap_StabilityComp_FaultInjection_SCom_FltInjection_Start
FUNC(void, RTE_APPL_CODE) Rte_CallHook_Ap_StabilityComp_FaultInjection_SCom_FltInjection_Start(P2VAR(Float, AUTOMATIC, RTE_AP_STABILITYCOMP_APPL_VAR) SignalPath_Uls_f32, FltInjectionLocType LocationKey_Cnt_enum);
# else
#  define Rte_CallHook_Ap_StabilityComp_FaultInjection_SCom_FltInjection_Start(arg1, arg2) ((void)(0))
# endif /* Rte_CallHook_Ap_StabilityComp_FaultInjection_SCom_FltInjection_Start */

# if defined (Rte_CallHook_Ap_StabilityComp_NxtrDiagMgr_SetNTCStatus_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_Ap_StabilityComp_NxtrDiagMgr_SetNTCStatus_Return
# endif
# if defined (Rte_CallHook_Ap_StabilityComp_NxtrDiagMgr_SetNTCStatus_Return)
#  undef Rte_CallHook_Ap_StabilityComp_NxtrDiagMgr_SetNTCStatus_Return
FUNC(void, RTE_APPL_CODE) Rte_CallHook_Ap_StabilityComp_NxtrDiagMgr_SetNTCStatus_Return(NTCNumber NTC_Cnt_T_enum, UInt8 Param_Cnt_T_u08, NxtrDiagMgrStatus Status_Cnt_T_enum);
# else
#  define Rte_CallHook_Ap_StabilityComp_NxtrDiagMgr_SetNTCStatus_Return(arg1, arg2, arg3) ((void)(0))
# endif /* Rte_CallHook_Ap_StabilityComp_NxtrDiagMgr_SetNTCStatus_Return */

# if defined (Rte_CallHook_Ap_StabilityComp_NxtrDiagMgr_SetNTCStatus_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_Ap_StabilityComp_NxtrDiagMgr_SetNTCStatus_Start
# endif
# if defined (Rte_CallHook_Ap_StabilityComp_NxtrDiagMgr_SetNTCStatus_Start)
#  undef Rte_CallHook_Ap_StabilityComp_NxtrDiagMgr_SetNTCStatus_Start
FUNC(void, RTE_APPL_CODE) Rte_CallHook_Ap_StabilityComp_NxtrDiagMgr_SetNTCStatus_Start(NTCNumber NTC_Cnt_T_enum, UInt8 Param_Cnt_T_u08, NxtrDiagMgrStatus Status_Cnt_T_enum);
# else
#  define Rte_CallHook_Ap_StabilityComp_NxtrDiagMgr_SetNTCStatus_Start(arg1, arg2, arg3) ((void)(0))
# endif /* Rte_CallHook_Ap_StabilityComp_NxtrDiagMgr_SetNTCStatus_Start */

# if defined (Rte_CallHook_Ap_StbCTO_NxtrDiagMgr_GetNTCActive_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_Ap_StbCTO_NxtrDiagMgr_GetNTCActive_Return
# endif
# if defined (Rte_CallHook_Ap_StbCTO_NxtrDiagMgr_GetNTCActive_Return)
#  undef Rte_CallHook_Ap_StbCTO_NxtrDiagMgr_GetNTCActive_Return
FUNC(void, RTE_APPL_CODE) Rte_CallHook_Ap_StbCTO_NxtrDiagMgr_GetNTCActive_Return(NTCNumber NTC_Cnt_T_enum, P2VAR(Boolean, AUTOMATIC, RTE_AP_STBCTO_APPL_VAR) NTCActive_Ptr_T_lgc);
# else
#  define Rte_CallHook_Ap_StbCTO_NxtrDiagMgr_GetNTCActive_Return(arg1, arg2) ((void)(0))
# endif /* Rte_CallHook_Ap_StbCTO_NxtrDiagMgr_GetNTCActive_Return */

# if defined (Rte_CallHook_Ap_StbCTO_NxtrDiagMgr_GetNTCActive_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_Ap_StbCTO_NxtrDiagMgr_GetNTCActive_Start
# endif
# if defined (Rte_CallHook_Ap_StbCTO_NxtrDiagMgr_GetNTCActive_Start)
#  undef Rte_CallHook_Ap_StbCTO_NxtrDiagMgr_GetNTCActive_Start
FUNC(void, RTE_APPL_CODE) Rte_CallHook_Ap_StbCTO_NxtrDiagMgr_GetNTCActive_Start(NTCNumber NTC_Cnt_T_enum, P2VAR(Boolean, AUTOMATIC, RTE_AP_STBCTO_APPL_VAR) NTCActive_Ptr_T_lgc);
# else
#  define Rte_CallHook_Ap_StbCTO_NxtrDiagMgr_GetNTCActive_Start(arg1, arg2) ((void)(0))
# endif /* Rte_CallHook_Ap_StbCTO_NxtrDiagMgr_GetNTCActive_Start */

# if defined (Rte_CallHook_Ap_StbCTO_NxtrDiagMgr_GetNTCFailed_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_Ap_StbCTO_NxtrDiagMgr_GetNTCFailed_Return
# endif
# if defined (Rte_CallHook_Ap_StbCTO_NxtrDiagMgr_GetNTCFailed_Return)
#  undef Rte_CallHook_Ap_StbCTO_NxtrDiagMgr_GetNTCFailed_Return
FUNC(void, RTE_APPL_CODE) Rte_CallHook_Ap_StbCTO_NxtrDiagMgr_GetNTCFailed_Return(NTCNumber NTC_Cnt_T_enum, P2VAR(Boolean, AUTOMATIC, RTE_AP_STBCTO_APPL_VAR) NTCFailed_Ptr_T_lgc);
# else
#  define Rte_CallHook_Ap_StbCTO_NxtrDiagMgr_GetNTCFailed_Return(arg1, arg2) ((void)(0))
# endif /* Rte_CallHook_Ap_StbCTO_NxtrDiagMgr_GetNTCFailed_Return */

# if defined (Rte_CallHook_Ap_StbCTO_NxtrDiagMgr_GetNTCFailed_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_Ap_StbCTO_NxtrDiagMgr_GetNTCFailed_Start
# endif
# if defined (Rte_CallHook_Ap_StbCTO_NxtrDiagMgr_GetNTCFailed_Start)
#  undef Rte_CallHook_Ap_StbCTO_NxtrDiagMgr_GetNTCFailed_Start
FUNC(void, RTE_APPL_CODE) Rte_CallHook_Ap_StbCTO_NxtrDiagMgr_GetNTCFailed_Start(NTCNumber NTC_Cnt_T_enum, P2VAR(Boolean, AUTOMATIC, RTE_AP_STBCTO_APPL_VAR) NTCFailed_Ptr_T_lgc);
# else
#  define Rte_CallHook_Ap_StbCTO_NxtrDiagMgr_GetNTCFailed_Start(arg1, arg2) ((void)(0))
# endif /* Rte_CallHook_Ap_StbCTO_NxtrDiagMgr_GetNTCFailed_Start */

# if defined (Rte_CallHook_Ap_StbCTO_NxtrDiagMgr_SetNTCStatus_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_Ap_StbCTO_NxtrDiagMgr_SetNTCStatus_Return
# endif
# if defined (Rte_CallHook_Ap_StbCTO_NxtrDiagMgr_SetNTCStatus_Return)
#  undef Rte_CallHook_Ap_StbCTO_NxtrDiagMgr_SetNTCStatus_Return
FUNC(void, RTE_APPL_CODE) Rte_CallHook_Ap_StbCTO_NxtrDiagMgr_SetNTCStatus_Return(NTCNumber NTC_Cnt_T_enum, UInt8 Param_Cnt_T_u08, NxtrDiagMgrStatus Status_Cnt_T_enum);
# else
#  define Rte_CallHook_Ap_StbCTO_NxtrDiagMgr_SetNTCStatus_Return(arg1, arg2, arg3) ((void)(0))
# endif /* Rte_CallHook_Ap_StbCTO_NxtrDiagMgr_SetNTCStatus_Return */

# if defined (Rte_CallHook_Ap_StbCTO_NxtrDiagMgr_SetNTCStatus_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_Ap_StbCTO_NxtrDiagMgr_SetNTCStatus_Start
# endif
# if defined (Rte_CallHook_Ap_StbCTO_NxtrDiagMgr_SetNTCStatus_Start)
#  undef Rte_CallHook_Ap_StbCTO_NxtrDiagMgr_SetNTCStatus_Start
FUNC(void, RTE_APPL_CODE) Rte_CallHook_Ap_StbCTO_NxtrDiagMgr_SetNTCStatus_Start(NTCNumber NTC_Cnt_T_enum, UInt8 Param_Cnt_T_u08, NxtrDiagMgrStatus Status_Cnt_T_enum);
# else
#  define Rte_CallHook_Ap_StbCTO_NxtrDiagMgr_SetNTCStatus_Start(arg1, arg2, arg3) ((void)(0))
# endif /* Rte_CallHook_Ap_StbCTO_NxtrDiagMgr_SetNTCStatus_Start */

# if defined (Rte_CallHook_Ap_StbCTO_SystemTime_DtrmnElapsedTime_mS_u16_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_Ap_StbCTO_SystemTime_DtrmnElapsedTime_mS_u16_Return
# endif
# if defined (Rte_CallHook_Ap_StbCTO_SystemTime_DtrmnElapsedTime_mS_u16_Return)
#  undef Rte_CallHook_Ap_StbCTO_SystemTime_DtrmnElapsedTime_mS_u16_Return
FUNC(void, RTE_APPL_CODE) Rte_CallHook_Ap_StbCTO_SystemTime_DtrmnElapsedTime_mS_u16_Return(UInt32 InitialTime, P2VAR(UInt16, AUTOMATIC, RTE_AP_STBCTO_APPL_VAR) ElapsedTime);
# else
#  define Rte_CallHook_Ap_StbCTO_SystemTime_DtrmnElapsedTime_mS_u16_Return(arg1, arg2) ((void)(0))
# endif /* Rte_CallHook_Ap_StbCTO_SystemTime_DtrmnElapsedTime_mS_u16_Return */

# if defined (Rte_CallHook_Ap_StbCTO_SystemTime_DtrmnElapsedTime_mS_u16_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_Ap_StbCTO_SystemTime_DtrmnElapsedTime_mS_u16_Start
# endif
# if defined (Rte_CallHook_Ap_StbCTO_SystemTime_DtrmnElapsedTime_mS_u16_Start)
#  undef Rte_CallHook_Ap_StbCTO_SystemTime_DtrmnElapsedTime_mS_u16_Start
FUNC(void, RTE_APPL_CODE) Rte_CallHook_Ap_StbCTO_SystemTime_DtrmnElapsedTime_mS_u16_Start(UInt32 InitialTime, P2VAR(UInt16, AUTOMATIC, RTE_AP_STBCTO_APPL_VAR) ElapsedTime);
# else
#  define Rte_CallHook_Ap_StbCTO_SystemTime_DtrmnElapsedTime_mS_u16_Start(arg1, arg2) ((void)(0))
# endif /* Rte_CallHook_Ap_StbCTO_SystemTime_DtrmnElapsedTime_mS_u16_Start */

# if defined (Rte_CallHook_Ap_StbCTO_SystemTime_GetSystemTime_mS_u32_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_Ap_StbCTO_SystemTime_GetSystemTime_mS_u32_Return
# endif
# if defined (Rte_CallHook_Ap_StbCTO_SystemTime_GetSystemTime_mS_u32_Return)
#  undef Rte_CallHook_Ap_StbCTO_SystemTime_GetSystemTime_mS_u32_Return
FUNC(void, RTE_APPL_CODE) Rte_CallHook_Ap_StbCTO_SystemTime_GetSystemTime_mS_u32_Return(P2VAR(UInt32, AUTOMATIC, RTE_AP_STBCTO_APPL_VAR) CurrentTime);
# else
#  define Rte_CallHook_Ap_StbCTO_SystemTime_GetSystemTime_mS_u32_Return(arg1) ((void)(0))
# endif /* Rte_CallHook_Ap_StbCTO_SystemTime_GetSystemTime_mS_u32_Return */

# if defined (Rte_CallHook_Ap_StbCTO_SystemTime_GetSystemTime_mS_u32_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_Ap_StbCTO_SystemTime_GetSystemTime_mS_u32_Start
# endif
# if defined (Rte_CallHook_Ap_StbCTO_SystemTime_GetSystemTime_mS_u32_Start)
#  undef Rte_CallHook_Ap_StbCTO_SystemTime_GetSystemTime_mS_u32_Start
FUNC(void, RTE_APPL_CODE) Rte_CallHook_Ap_StbCTO_SystemTime_GetSystemTime_mS_u32_Start(P2VAR(UInt32, AUTOMATIC, RTE_AP_STBCTO_APPL_VAR) CurrentTime);
# else
#  define Rte_CallHook_Ap_StbCTO_SystemTime_GetSystemTime_mS_u32_Start(arg1) ((void)(0))
# endif /* Rte_CallHook_Ap_StbCTO_SystemTime_GetSystemTime_mS_u32_Start */

# if defined (Rte_CallHook_Ap_ThrmlDutyCycle_NxtrDiagMgr_GetNTCFailed_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_Ap_ThrmlDutyCycle_NxtrDiagMgr_GetNTCFailed_Return
# endif
# if defined (Rte_CallHook_Ap_ThrmlDutyCycle_NxtrDiagMgr_GetNTCFailed_Return)
#  undef Rte_CallHook_Ap_ThrmlDutyCycle_NxtrDiagMgr_GetNTCFailed_Return
FUNC(void, RTE_APPL_CODE) Rte_CallHook_Ap_ThrmlDutyCycle_NxtrDiagMgr_GetNTCFailed_Return(NTCNumber NTC_Cnt_T_enum, P2VAR(Boolean, AUTOMATIC, RTE_AP_THRMLDUTYCYCLE_APPL_VAR) NTCFailed_Ptr_T_lgc);
# else
#  define Rte_CallHook_Ap_ThrmlDutyCycle_NxtrDiagMgr_GetNTCFailed_Return(arg1, arg2) ((void)(0))
# endif /* Rte_CallHook_Ap_ThrmlDutyCycle_NxtrDiagMgr_GetNTCFailed_Return */

# if defined (Rte_CallHook_Ap_ThrmlDutyCycle_NxtrDiagMgr_GetNTCFailed_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_Ap_ThrmlDutyCycle_NxtrDiagMgr_GetNTCFailed_Start
# endif
# if defined (Rte_CallHook_Ap_ThrmlDutyCycle_NxtrDiagMgr_GetNTCFailed_Start)
#  undef Rte_CallHook_Ap_ThrmlDutyCycle_NxtrDiagMgr_GetNTCFailed_Start
FUNC(void, RTE_APPL_CODE) Rte_CallHook_Ap_ThrmlDutyCycle_NxtrDiagMgr_GetNTCFailed_Start(NTCNumber NTC_Cnt_T_enum, P2VAR(Boolean, AUTOMATIC, RTE_AP_THRMLDUTYCYCLE_APPL_VAR) NTCFailed_Ptr_T_lgc);
# else
#  define Rte_CallHook_Ap_ThrmlDutyCycle_NxtrDiagMgr_GetNTCFailed_Start(arg1, arg2) ((void)(0))
# endif /* Rte_CallHook_Ap_ThrmlDutyCycle_NxtrDiagMgr_GetNTCFailed_Start */

# if defined (Rte_CallHook_Ap_ThrmlDutyCycle_NxtrDiagMgr_SetNTCStatus_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_Ap_ThrmlDutyCycle_NxtrDiagMgr_SetNTCStatus_Return
# endif
# if defined (Rte_CallHook_Ap_ThrmlDutyCycle_NxtrDiagMgr_SetNTCStatus_Return)
#  undef Rte_CallHook_Ap_ThrmlDutyCycle_NxtrDiagMgr_SetNTCStatus_Return
FUNC(void, RTE_APPL_CODE) Rte_CallHook_Ap_ThrmlDutyCycle_NxtrDiagMgr_SetNTCStatus_Return(NTCNumber NTC_Cnt_T_enum, UInt8 Param_Cnt_T_u08, NxtrDiagMgrStatus Status_Cnt_T_enum);
# else
#  define Rte_CallHook_Ap_ThrmlDutyCycle_NxtrDiagMgr_SetNTCStatus_Return(arg1, arg2, arg3) ((void)(0))
# endif /* Rte_CallHook_Ap_ThrmlDutyCycle_NxtrDiagMgr_SetNTCStatus_Return */

# if defined (Rte_CallHook_Ap_ThrmlDutyCycle_NxtrDiagMgr_SetNTCStatus_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_Ap_ThrmlDutyCycle_NxtrDiagMgr_SetNTCStatus_Start
# endif
# if defined (Rte_CallHook_Ap_ThrmlDutyCycle_NxtrDiagMgr_SetNTCStatus_Start)
#  undef Rte_CallHook_Ap_ThrmlDutyCycle_NxtrDiagMgr_SetNTCStatus_Start
FUNC(void, RTE_APPL_CODE) Rte_CallHook_Ap_ThrmlDutyCycle_NxtrDiagMgr_SetNTCStatus_Start(NTCNumber NTC_Cnt_T_enum, UInt8 Param_Cnt_T_u08, NxtrDiagMgrStatus Status_Cnt_T_enum);
# else
#  define Rte_CallHook_Ap_ThrmlDutyCycle_NxtrDiagMgr_SetNTCStatus_Start(arg1, arg2, arg3) ((void)(0))
# endif /* Rte_CallHook_Ap_ThrmlDutyCycle_NxtrDiagMgr_SetNTCStatus_Start */

# if defined (Rte_CallHook_Ap_ThrmlDutyCycle_ThrmlDutyCycle_Per1_CP1_CheckpointReached_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_Ap_ThrmlDutyCycle_ThrmlDutyCycle_Per1_CP1_CheckpointReached_Return
# endif
# if defined (Rte_CallHook_Ap_ThrmlDutyCycle_ThrmlDutyCycle_Per1_CP1_CheckpointReached_Return)
#  undef Rte_CallHook_Ap_ThrmlDutyCycle_ThrmlDutyCycle_Per1_CP1_CheckpointReached_Return
FUNC(void, RTE_APPL_CODE) Rte_CallHook_Ap_ThrmlDutyCycle_ThrmlDutyCycle_Per1_CP1_CheckpointReached_Return(void);
# else
#  define Rte_CallHook_Ap_ThrmlDutyCycle_ThrmlDutyCycle_Per1_CP1_CheckpointReached_Return() ((void)(0))
# endif /* Rte_CallHook_Ap_ThrmlDutyCycle_ThrmlDutyCycle_Per1_CP1_CheckpointReached_Return */

# if defined (Rte_CallHook_Ap_ThrmlDutyCycle_ThrmlDutyCycle_Per1_CP1_CheckpointReached_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_Ap_ThrmlDutyCycle_ThrmlDutyCycle_Per1_CP1_CheckpointReached_Start
# endif
# if defined (Rte_CallHook_Ap_ThrmlDutyCycle_ThrmlDutyCycle_Per1_CP1_CheckpointReached_Start)
#  undef Rte_CallHook_Ap_ThrmlDutyCycle_ThrmlDutyCycle_Per1_CP1_CheckpointReached_Start
FUNC(void, RTE_APPL_CODE) Rte_CallHook_Ap_ThrmlDutyCycle_ThrmlDutyCycle_Per1_CP1_CheckpointReached_Start(void);
# else
#  define Rte_CallHook_Ap_ThrmlDutyCycle_ThrmlDutyCycle_Per1_CP1_CheckpointReached_Start() ((void)(0))
# endif /* Rte_CallHook_Ap_ThrmlDutyCycle_ThrmlDutyCycle_Per1_CP1_CheckpointReached_Start */

# if defined (Rte_CallHook_Ap_TqRsDg_NxtrDiagMgr_SetNTCStatus_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_Ap_TqRsDg_NxtrDiagMgr_SetNTCStatus_Return
# endif
# if defined (Rte_CallHook_Ap_TqRsDg_NxtrDiagMgr_SetNTCStatus_Return)
#  undef Rte_CallHook_Ap_TqRsDg_NxtrDiagMgr_SetNTCStatus_Return
FUNC(void, RTE_APPL_CODE) Rte_CallHook_Ap_TqRsDg_NxtrDiagMgr_SetNTCStatus_Return(NTCNumber NTC_Cnt_T_enum, UInt8 Param_Cnt_T_u08, NxtrDiagMgrStatus Status_Cnt_T_enum);
# else
#  define Rte_CallHook_Ap_TqRsDg_NxtrDiagMgr_SetNTCStatus_Return(arg1, arg2, arg3) ((void)(0))
# endif /* Rte_CallHook_Ap_TqRsDg_NxtrDiagMgr_SetNTCStatus_Return */

# if defined (Rte_CallHook_Ap_TqRsDg_NxtrDiagMgr_SetNTCStatus_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_Ap_TqRsDg_NxtrDiagMgr_SetNTCStatus_Start
# endif
# if defined (Rte_CallHook_Ap_TqRsDg_NxtrDiagMgr_SetNTCStatus_Start)
#  undef Rte_CallHook_Ap_TqRsDg_NxtrDiagMgr_SetNTCStatus_Start
FUNC(void, RTE_APPL_CODE) Rte_CallHook_Ap_TqRsDg_NxtrDiagMgr_SetNTCStatus_Start(NTCNumber NTC_Cnt_T_enum, UInt8 Param_Cnt_T_u08, NxtrDiagMgrStatus Status_Cnt_T_enum);
# else
#  define Rte_CallHook_Ap_TqRsDg_NxtrDiagMgr_SetNTCStatus_Start(arg1, arg2, arg3) ((void)(0))
# endif /* Rte_CallHook_Ap_TqRsDg_NxtrDiagMgr_SetNTCStatus_Start */

# if defined (Rte_CallHook_Ap_TuningSelAuth_TuningSelAuth_Per1_CP0_CheckpointReached_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_Ap_TuningSelAuth_TuningSelAuth_Per1_CP0_CheckpointReached_Return
# endif
# if defined (Rte_CallHook_Ap_TuningSelAuth_TuningSelAuth_Per1_CP0_CheckpointReached_Return)
#  undef Rte_CallHook_Ap_TuningSelAuth_TuningSelAuth_Per1_CP0_CheckpointReached_Return
FUNC(void, RTE_APPL_CODE) Rte_CallHook_Ap_TuningSelAuth_TuningSelAuth_Per1_CP0_CheckpointReached_Return(void);
# else
#  define Rte_CallHook_Ap_TuningSelAuth_TuningSelAuth_Per1_CP0_CheckpointReached_Return() ((void)(0))
# endif /* Rte_CallHook_Ap_TuningSelAuth_TuningSelAuth_Per1_CP0_CheckpointReached_Return */

# if defined (Rte_CallHook_Ap_TuningSelAuth_TuningSelAuth_Per1_CP0_CheckpointReached_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_Ap_TuningSelAuth_TuningSelAuth_Per1_CP0_CheckpointReached_Start
# endif
# if defined (Rte_CallHook_Ap_TuningSelAuth_TuningSelAuth_Per1_CP0_CheckpointReached_Start)
#  undef Rte_CallHook_Ap_TuningSelAuth_TuningSelAuth_Per1_CP0_CheckpointReached_Start
FUNC(void, RTE_APPL_CODE) Rte_CallHook_Ap_TuningSelAuth_TuningSelAuth_Per1_CP0_CheckpointReached_Start(void);
# else
#  define Rte_CallHook_Ap_TuningSelAuth_TuningSelAuth_Per1_CP0_CheckpointReached_Start() ((void)(0))
# endif /* Rte_CallHook_Ap_TuningSelAuth_TuningSelAuth_Per1_CP0_CheckpointReached_Start */

# if defined (Rte_CallHook_Ap_VehPwrMd_EpsEn_OP_GET_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_Ap_VehPwrMd_EpsEn_OP_GET_Return
# endif
# if defined (Rte_CallHook_Ap_VehPwrMd_EpsEn_OP_GET_Return)
#  undef Rte_CallHook_Ap_VehPwrMd_EpsEn_OP_GET_Return
FUNC(void, RTE_APPL_CODE) Rte_CallHook_Ap_VehPwrMd_EpsEn_OP_GET_Return(P2VAR(IoHwAb_BoolType, AUTOMATIC, RTE_AP_VEHPWRMD_APPL_VAR) signal);
# else
#  define Rte_CallHook_Ap_VehPwrMd_EpsEn_OP_GET_Return(arg1) ((void)(0))
# endif /* Rte_CallHook_Ap_VehPwrMd_EpsEn_OP_GET_Return */

# if defined (Rte_CallHook_Ap_VehPwrMd_EpsEn_OP_GET_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_Ap_VehPwrMd_EpsEn_OP_GET_Start
# endif
# if defined (Rte_CallHook_Ap_VehPwrMd_EpsEn_OP_GET_Start)
#  undef Rte_CallHook_Ap_VehPwrMd_EpsEn_OP_GET_Start
FUNC(void, RTE_APPL_CODE) Rte_CallHook_Ap_VehPwrMd_EpsEn_OP_GET_Start(P2VAR(IoHwAb_BoolType, AUTOMATIC, RTE_AP_VEHPWRMD_APPL_VAR) signal);
# else
#  define Rte_CallHook_Ap_VehPwrMd_EpsEn_OP_GET_Start(arg1) ((void)(0))
# endif /* Rte_CallHook_Ap_VehPwrMd_EpsEn_OP_GET_Start */

# if defined (Rte_CallHook_Ap_VehPwrMd_VehPwrMd_Per1_CP1_CheckpointReached_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_Ap_VehPwrMd_VehPwrMd_Per1_CP1_CheckpointReached_Return
# endif
# if defined (Rte_CallHook_Ap_VehPwrMd_VehPwrMd_Per1_CP1_CheckpointReached_Return)
#  undef Rte_CallHook_Ap_VehPwrMd_VehPwrMd_Per1_CP1_CheckpointReached_Return
FUNC(void, RTE_APPL_CODE) Rte_CallHook_Ap_VehPwrMd_VehPwrMd_Per1_CP1_CheckpointReached_Return(void);
# else
#  define Rte_CallHook_Ap_VehPwrMd_VehPwrMd_Per1_CP1_CheckpointReached_Return() ((void)(0))
# endif /* Rte_CallHook_Ap_VehPwrMd_VehPwrMd_Per1_CP1_CheckpointReached_Return */

# if defined (Rte_CallHook_Ap_VehPwrMd_VehPwrMd_Per1_CP1_CheckpointReached_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_Ap_VehPwrMd_VehPwrMd_Per1_CP1_CheckpointReached_Start
# endif
# if defined (Rte_CallHook_Ap_VehPwrMd_VehPwrMd_Per1_CP1_CheckpointReached_Start)
#  undef Rte_CallHook_Ap_VehPwrMd_VehPwrMd_Per1_CP1_CheckpointReached_Start
FUNC(void, RTE_APPL_CODE) Rte_CallHook_Ap_VehPwrMd_VehPwrMd_Per1_CP1_CheckpointReached_Start(void);
# else
#  define Rte_CallHook_Ap_VehPwrMd_VehPwrMd_Per1_CP1_CheckpointReached_Start() ((void)(0))
# endif /* Rte_CallHook_Ap_VehPwrMd_VehPwrMd_Per1_CP1_CheckpointReached_Start */

# if defined (Rte_CallHook_Ap_WIRInputQual_SystemTime_DtrmnElapsedTime_mS_u16_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_Ap_WIRInputQual_SystemTime_DtrmnElapsedTime_mS_u16_Return
# endif
# if defined (Rte_CallHook_Ap_WIRInputQual_SystemTime_DtrmnElapsedTime_mS_u16_Return)
#  undef Rte_CallHook_Ap_WIRInputQual_SystemTime_DtrmnElapsedTime_mS_u16_Return
FUNC(void, RTE_APPL_CODE) Rte_CallHook_Ap_WIRInputQual_SystemTime_DtrmnElapsedTime_mS_u16_Return(UInt32 InitialTime, P2VAR(UInt16, AUTOMATIC, RTE_AP_WIRINPUTQUAL_APPL_VAR) ElapsedTime);
# else
#  define Rte_CallHook_Ap_WIRInputQual_SystemTime_DtrmnElapsedTime_mS_u16_Return(arg1, arg2) ((void)(0))
# endif /* Rte_CallHook_Ap_WIRInputQual_SystemTime_DtrmnElapsedTime_mS_u16_Return */

# if defined (Rte_CallHook_Ap_WIRInputQual_SystemTime_DtrmnElapsedTime_mS_u16_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_Ap_WIRInputQual_SystemTime_DtrmnElapsedTime_mS_u16_Start
# endif
# if defined (Rte_CallHook_Ap_WIRInputQual_SystemTime_DtrmnElapsedTime_mS_u16_Start)
#  undef Rte_CallHook_Ap_WIRInputQual_SystemTime_DtrmnElapsedTime_mS_u16_Start
FUNC(void, RTE_APPL_CODE) Rte_CallHook_Ap_WIRInputQual_SystemTime_DtrmnElapsedTime_mS_u16_Start(UInt32 InitialTime, P2VAR(UInt16, AUTOMATIC, RTE_AP_WIRINPUTQUAL_APPL_VAR) ElapsedTime);
# else
#  define Rte_CallHook_Ap_WIRInputQual_SystemTime_DtrmnElapsedTime_mS_u16_Start(arg1, arg2) ((void)(0))
# endif /* Rte_CallHook_Ap_WIRInputQual_SystemTime_DtrmnElapsedTime_mS_u16_Start */

# if defined (Rte_CallHook_Ap_WIRInputQual_SystemTime_GetSystemTime_mS_u32_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_Ap_WIRInputQual_SystemTime_GetSystemTime_mS_u32_Return
# endif
# if defined (Rte_CallHook_Ap_WIRInputQual_SystemTime_GetSystemTime_mS_u32_Return)
#  undef Rte_CallHook_Ap_WIRInputQual_SystemTime_GetSystemTime_mS_u32_Return
FUNC(void, RTE_APPL_CODE) Rte_CallHook_Ap_WIRInputQual_SystemTime_GetSystemTime_mS_u32_Return(P2VAR(UInt32, AUTOMATIC, RTE_AP_WIRINPUTQUAL_APPL_VAR) CurrentTime);
# else
#  define Rte_CallHook_Ap_WIRInputQual_SystemTime_GetSystemTime_mS_u32_Return(arg1) ((void)(0))
# endif /* Rte_CallHook_Ap_WIRInputQual_SystemTime_GetSystemTime_mS_u32_Return */

# if defined (Rte_CallHook_Ap_WIRInputQual_SystemTime_GetSystemTime_mS_u32_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_Ap_WIRInputQual_SystemTime_GetSystemTime_mS_u32_Start
# endif
# if defined (Rte_CallHook_Ap_WIRInputQual_SystemTime_GetSystemTime_mS_u32_Start)
#  undef Rte_CallHook_Ap_WIRInputQual_SystemTime_GetSystemTime_mS_u32_Start
FUNC(void, RTE_APPL_CODE) Rte_CallHook_Ap_WIRInputQual_SystemTime_GetSystemTime_mS_u32_Start(P2VAR(UInt32, AUTOMATIC, RTE_AP_WIRINPUTQUAL_APPL_VAR) CurrentTime);
# else
#  define Rte_CallHook_Ap_WIRInputQual_SystemTime_GetSystemTime_mS_u32_Start(arg1) ((void)(0))
# endif /* Rte_CallHook_Ap_WIRInputQual_SystemTime_GetSystemTime_mS_u32_Start */

# if defined (Rte_CallHook_Ap_WhlImbRej_NxtrDiagMgr_SetNTCStatus_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_Ap_WhlImbRej_NxtrDiagMgr_SetNTCStatus_Return
# endif
# if defined (Rte_CallHook_Ap_WhlImbRej_NxtrDiagMgr_SetNTCStatus_Return)
#  undef Rte_CallHook_Ap_WhlImbRej_NxtrDiagMgr_SetNTCStatus_Return
FUNC(void, RTE_APPL_CODE) Rte_CallHook_Ap_WhlImbRej_NxtrDiagMgr_SetNTCStatus_Return(NTCNumber NTC_Cnt_T_enum, UInt8 Param_Cnt_T_u08, NxtrDiagMgrStatus Status_Cnt_T_enum);
# else
#  define Rte_CallHook_Ap_WhlImbRej_NxtrDiagMgr_SetNTCStatus_Return(arg1, arg2, arg3) ((void)(0))
# endif /* Rte_CallHook_Ap_WhlImbRej_NxtrDiagMgr_SetNTCStatus_Return */

# if defined (Rte_CallHook_Ap_WhlImbRej_NxtrDiagMgr_SetNTCStatus_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_Ap_WhlImbRej_NxtrDiagMgr_SetNTCStatus_Start
# endif
# if defined (Rte_CallHook_Ap_WhlImbRej_NxtrDiagMgr_SetNTCStatus_Start)
#  undef Rte_CallHook_Ap_WhlImbRej_NxtrDiagMgr_SetNTCStatus_Start
FUNC(void, RTE_APPL_CODE) Rte_CallHook_Ap_WhlImbRej_NxtrDiagMgr_SetNTCStatus_Start(NTCNumber NTC_Cnt_T_enum, UInt8 Param_Cnt_T_u08, NxtrDiagMgrStatus Status_Cnt_T_enum);
# else
#  define Rte_CallHook_Ap_WhlImbRej_NxtrDiagMgr_SetNTCStatus_Start(arg1, arg2, arg3) ((void)(0))
# endif /* Rte_CallHook_Ap_WhlImbRej_NxtrDiagMgr_SetNTCStatus_Start */

# if defined (Rte_CallHook_Ap_WhlImbRej_SystemTime_DtrmnElapsedTime_mS_u16_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_Ap_WhlImbRej_SystemTime_DtrmnElapsedTime_mS_u16_Return
# endif
# if defined (Rte_CallHook_Ap_WhlImbRej_SystemTime_DtrmnElapsedTime_mS_u16_Return)
#  undef Rte_CallHook_Ap_WhlImbRej_SystemTime_DtrmnElapsedTime_mS_u16_Return
FUNC(void, RTE_APPL_CODE) Rte_CallHook_Ap_WhlImbRej_SystemTime_DtrmnElapsedTime_mS_u16_Return(UInt32 InitialTime, P2VAR(UInt16, AUTOMATIC, RTE_AP_WHLIMBREJ_APPL_VAR) ElapsedTime);
# else
#  define Rte_CallHook_Ap_WhlImbRej_SystemTime_DtrmnElapsedTime_mS_u16_Return(arg1, arg2) ((void)(0))
# endif /* Rte_CallHook_Ap_WhlImbRej_SystemTime_DtrmnElapsedTime_mS_u16_Return */

# if defined (Rte_CallHook_Ap_WhlImbRej_SystemTime_DtrmnElapsedTime_mS_u16_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_Ap_WhlImbRej_SystemTime_DtrmnElapsedTime_mS_u16_Start
# endif
# if defined (Rte_CallHook_Ap_WhlImbRej_SystemTime_DtrmnElapsedTime_mS_u16_Start)
#  undef Rte_CallHook_Ap_WhlImbRej_SystemTime_DtrmnElapsedTime_mS_u16_Start
FUNC(void, RTE_APPL_CODE) Rte_CallHook_Ap_WhlImbRej_SystemTime_DtrmnElapsedTime_mS_u16_Start(UInt32 InitialTime, P2VAR(UInt16, AUTOMATIC, RTE_AP_WHLIMBREJ_APPL_VAR) ElapsedTime);
# else
#  define Rte_CallHook_Ap_WhlImbRej_SystemTime_DtrmnElapsedTime_mS_u16_Start(arg1, arg2) ((void)(0))
# endif /* Rte_CallHook_Ap_WhlImbRej_SystemTime_DtrmnElapsedTime_mS_u16_Start */

# if defined (Rte_CallHook_Ap_WhlImbRej_SystemTime_DtrmnElapsedTime_mS_u32_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_Ap_WhlImbRej_SystemTime_DtrmnElapsedTime_mS_u32_Return
# endif
# if defined (Rte_CallHook_Ap_WhlImbRej_SystemTime_DtrmnElapsedTime_mS_u32_Return)
#  undef Rte_CallHook_Ap_WhlImbRej_SystemTime_DtrmnElapsedTime_mS_u32_Return
FUNC(void, RTE_APPL_CODE) Rte_CallHook_Ap_WhlImbRej_SystemTime_DtrmnElapsedTime_mS_u32_Return(UInt32 InitialTime, P2VAR(UInt32, AUTOMATIC, RTE_AP_WHLIMBREJ_APPL_VAR) ElapsedTime);
# else
#  define Rte_CallHook_Ap_WhlImbRej_SystemTime_DtrmnElapsedTime_mS_u32_Return(arg1, arg2) ((void)(0))
# endif /* Rte_CallHook_Ap_WhlImbRej_SystemTime_DtrmnElapsedTime_mS_u32_Return */

# if defined (Rte_CallHook_Ap_WhlImbRej_SystemTime_DtrmnElapsedTime_mS_u32_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_Ap_WhlImbRej_SystemTime_DtrmnElapsedTime_mS_u32_Start
# endif
# if defined (Rte_CallHook_Ap_WhlImbRej_SystemTime_DtrmnElapsedTime_mS_u32_Start)
#  undef Rte_CallHook_Ap_WhlImbRej_SystemTime_DtrmnElapsedTime_mS_u32_Start
FUNC(void, RTE_APPL_CODE) Rte_CallHook_Ap_WhlImbRej_SystemTime_DtrmnElapsedTime_mS_u32_Start(UInt32 InitialTime, P2VAR(UInt32, AUTOMATIC, RTE_AP_WHLIMBREJ_APPL_VAR) ElapsedTime);
# else
#  define Rte_CallHook_Ap_WhlImbRej_SystemTime_DtrmnElapsedTime_mS_u32_Start(arg1, arg2) ((void)(0))
# endif /* Rte_CallHook_Ap_WhlImbRej_SystemTime_DtrmnElapsedTime_mS_u32_Start */

# if defined (Rte_CallHook_Ap_WhlImbRej_SystemTime_GetSystemTime_mS_u32_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_Ap_WhlImbRej_SystemTime_GetSystemTime_mS_u32_Return
# endif
# if defined (Rte_CallHook_Ap_WhlImbRej_SystemTime_GetSystemTime_mS_u32_Return)
#  undef Rte_CallHook_Ap_WhlImbRej_SystemTime_GetSystemTime_mS_u32_Return
FUNC(void, RTE_APPL_CODE) Rte_CallHook_Ap_WhlImbRej_SystemTime_GetSystemTime_mS_u32_Return(P2VAR(UInt32, AUTOMATIC, RTE_AP_WHLIMBREJ_APPL_VAR) CurrentTime);
# else
#  define Rte_CallHook_Ap_WhlImbRej_SystemTime_GetSystemTime_mS_u32_Return(arg1) ((void)(0))
# endif /* Rte_CallHook_Ap_WhlImbRej_SystemTime_GetSystemTime_mS_u32_Return */

# if defined (Rte_CallHook_Ap_WhlImbRej_SystemTime_GetSystemTime_mS_u32_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_Ap_WhlImbRej_SystemTime_GetSystemTime_mS_u32_Start
# endif
# if defined (Rte_CallHook_Ap_WhlImbRej_SystemTime_GetSystemTime_mS_u32_Start)
#  undef Rte_CallHook_Ap_WhlImbRej_SystemTime_GetSystemTime_mS_u32_Start
FUNC(void, RTE_APPL_CODE) Rte_CallHook_Ap_WhlImbRej_SystemTime_GetSystemTime_mS_u32_Start(P2VAR(UInt32, AUTOMATIC, RTE_AP_WHLIMBREJ_APPL_VAR) CurrentTime);
# else
#  define Rte_CallHook_Ap_WhlImbRej_SystemTime_GetSystemTime_mS_u32_Start(arg1) ((void)(0))
# endif /* Rte_CallHook_Ap_WhlImbRej_SystemTime_GetSystemTime_mS_u32_Start */

# if defined (Rte_CallHook_Cd_uDiag_NxtrDiagMgr_SetNTCStatus_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_Cd_uDiag_NxtrDiagMgr_SetNTCStatus_Return
# endif
# if defined (Rte_CallHook_Cd_uDiag_NxtrDiagMgr_SetNTCStatus_Return)
#  undef Rte_CallHook_Cd_uDiag_NxtrDiagMgr_SetNTCStatus_Return
FUNC(void, RTE_APPL_CODE) Rte_CallHook_Cd_uDiag_NxtrDiagMgr_SetNTCStatus_Return(NTCNumber NTC_Cnt_T_enum, UInt8 Param_Cnt_T_u08, NxtrDiagMgrStatus Status_Cnt_T_enum);
# else
#  define Rte_CallHook_Cd_uDiag_NxtrDiagMgr_SetNTCStatus_Return(arg1, arg2, arg3) ((void)(0))
# endif /* Rte_CallHook_Cd_uDiag_NxtrDiagMgr_SetNTCStatus_Return */

# if defined (Rte_CallHook_Cd_uDiag_NxtrDiagMgr_SetNTCStatus_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_Cd_uDiag_NxtrDiagMgr_SetNTCStatus_Start
# endif
# if defined (Rte_CallHook_Cd_uDiag_NxtrDiagMgr_SetNTCStatus_Start)
#  undef Rte_CallHook_Cd_uDiag_NxtrDiagMgr_SetNTCStatus_Start
FUNC(void, RTE_APPL_CODE) Rte_CallHook_Cd_uDiag_NxtrDiagMgr_SetNTCStatus_Start(NTCNumber NTC_Cnt_T_enum, UInt8 Param_Cnt_T_u08, NxtrDiagMgrStatus Status_Cnt_T_enum);
# else
#  define Rte_CallHook_Cd_uDiag_NxtrDiagMgr_SetNTCStatus_Start(arg1, arg2, arg3) ((void)(0))
# endif /* Rte_CallHook_Cd_uDiag_NxtrDiagMgr_SetNTCStatus_Start */

# if defined (Rte_CallHook_Cd_uDiag_uDiagLossOfExec_Per3_CP0_CheckpointReached_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_Cd_uDiag_uDiagLossOfExec_Per3_CP0_CheckpointReached_Return
# endif
# if defined (Rte_CallHook_Cd_uDiag_uDiagLossOfExec_Per3_CP0_CheckpointReached_Return)
#  undef Rte_CallHook_Cd_uDiag_uDiagLossOfExec_Per3_CP0_CheckpointReached_Return
FUNC(void, RTE_APPL_CODE) Rte_CallHook_Cd_uDiag_uDiagLossOfExec_Per3_CP0_CheckpointReached_Return(void);
# else
#  define Rte_CallHook_Cd_uDiag_uDiagLossOfExec_Per3_CP0_CheckpointReached_Return() ((void)(0))
# endif /* Rte_CallHook_Cd_uDiag_uDiagLossOfExec_Per3_CP0_CheckpointReached_Return */

# if defined (Rte_CallHook_Cd_uDiag_uDiagLossOfExec_Per3_CP0_CheckpointReached_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_Cd_uDiag_uDiagLossOfExec_Per3_CP0_CheckpointReached_Start
# endif
# if defined (Rte_CallHook_Cd_uDiag_uDiagLossOfExec_Per3_CP0_CheckpointReached_Start)
#  undef Rte_CallHook_Cd_uDiag_uDiagLossOfExec_Per3_CP0_CheckpointReached_Start
FUNC(void, RTE_APPL_CODE) Rte_CallHook_Cd_uDiag_uDiagLossOfExec_Per3_CP0_CheckpointReached_Start(void);
# else
#  define Rte_CallHook_Cd_uDiag_uDiagLossOfExec_Per3_CP0_CheckpointReached_Start() ((void)(0))
# endif /* Rte_CallHook_Cd_uDiag_uDiagLossOfExec_Per3_CP0_CheckpointReached_Start */

# if defined (Rte_CallHook_Cd_uDiag_uDiagStaticRegs_Per_CP1_CheckpointReached_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_Cd_uDiag_uDiagStaticRegs_Per_CP1_CheckpointReached_Return
# endif
# if defined (Rte_CallHook_Cd_uDiag_uDiagStaticRegs_Per_CP1_CheckpointReached_Return)
#  undef Rte_CallHook_Cd_uDiag_uDiagStaticRegs_Per_CP1_CheckpointReached_Return
FUNC(void, RTE_APPL_CODE) Rte_CallHook_Cd_uDiag_uDiagStaticRegs_Per_CP1_CheckpointReached_Return(void);
# else
#  define Rte_CallHook_Cd_uDiag_uDiagStaticRegs_Per_CP1_CheckpointReached_Return() ((void)(0))
# endif /* Rte_CallHook_Cd_uDiag_uDiagStaticRegs_Per_CP1_CheckpointReached_Return */

# if defined (Rte_CallHook_Cd_uDiag_uDiagStaticRegs_Per_CP1_CheckpointReached_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_Cd_uDiag_uDiagStaticRegs_Per_CP1_CheckpointReached_Start
# endif
# if defined (Rte_CallHook_Cd_uDiag_uDiagStaticRegs_Per_CP1_CheckpointReached_Start)
#  undef Rte_CallHook_Cd_uDiag_uDiagStaticRegs_Per_CP1_CheckpointReached_Start
FUNC(void, RTE_APPL_CODE) Rte_CallHook_Cd_uDiag_uDiagStaticRegs_Per_CP1_CheckpointReached_Start(void);
# else
#  define Rte_CallHook_Cd_uDiag_uDiagStaticRegs_Per_CP1_CheckpointReached_Start() ((void)(0))
# endif /* Rte_CallHook_Cd_uDiag_uDiagStaticRegs_Per_CP1_CheckpointReached_Start */

# if defined (Rte_CallHook_IoHwAbstractionUsr_NxtrDiagMgr_SetNTCStatus_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_IoHwAbstractionUsr_NxtrDiagMgr_SetNTCStatus_Return
# endif
# if defined (Rte_CallHook_IoHwAbstractionUsr_NxtrDiagMgr_SetNTCStatus_Return)
#  undef Rte_CallHook_IoHwAbstractionUsr_NxtrDiagMgr_SetNTCStatus_Return
FUNC(void, RTE_APPL_CODE) Rte_CallHook_IoHwAbstractionUsr_NxtrDiagMgr_SetNTCStatus_Return(NTCNumber NTC_Cnt_T_enum, UInt8 Param_Cnt_T_u08, NxtrDiagMgrStatus Status_Cnt_T_enum);
# else
#  define Rte_CallHook_IoHwAbstractionUsr_NxtrDiagMgr_SetNTCStatus_Return(arg1, arg2, arg3) ((void)(0))
# endif /* Rte_CallHook_IoHwAbstractionUsr_NxtrDiagMgr_SetNTCStatus_Return */

# if defined (Rte_CallHook_IoHwAbstractionUsr_NxtrDiagMgr_SetNTCStatus_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_IoHwAbstractionUsr_NxtrDiagMgr_SetNTCStatus_Start
# endif
# if defined (Rte_CallHook_IoHwAbstractionUsr_NxtrDiagMgr_SetNTCStatus_Start)
#  undef Rte_CallHook_IoHwAbstractionUsr_NxtrDiagMgr_SetNTCStatus_Start
FUNC(void, RTE_APPL_CODE) Rte_CallHook_IoHwAbstractionUsr_NxtrDiagMgr_SetNTCStatus_Start(NTCNumber NTC_Cnt_T_enum, UInt8 Param_Cnt_T_u08, NxtrDiagMgrStatus Status_Cnt_T_enum);
# else
#  define Rte_CallHook_IoHwAbstractionUsr_NxtrDiagMgr_SetNTCStatus_Start(arg1, arg2, arg3) ((void)(0))
# endif /* Rte_CallHook_IoHwAbstractionUsr_NxtrDiagMgr_SetNTCStatus_Start */

# if defined (Rte_CallHook_IoHwAbstractionUsr_SystemTime_DtrmnElapsedTime_uS_u16_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_IoHwAbstractionUsr_SystemTime_DtrmnElapsedTime_uS_u16_Return
# endif
# if defined (Rte_CallHook_IoHwAbstractionUsr_SystemTime_DtrmnElapsedTime_uS_u16_Return)
#  undef Rte_CallHook_IoHwAbstractionUsr_SystemTime_DtrmnElapsedTime_uS_u16_Return
FUNC(void, RTE_APPL_CODE) Rte_CallHook_IoHwAbstractionUsr_SystemTime_DtrmnElapsedTime_uS_u16_Return(UInt32 InitialTime, P2VAR(UInt16, AUTOMATIC, RTE_IOHWABSTRACTIONUSR_APPL_VAR) ElapsedTime);
# else
#  define Rte_CallHook_IoHwAbstractionUsr_SystemTime_DtrmnElapsedTime_uS_u16_Return(arg1, arg2) ((void)(0))
# endif /* Rte_CallHook_IoHwAbstractionUsr_SystemTime_DtrmnElapsedTime_uS_u16_Return */

# if defined (Rte_CallHook_IoHwAbstractionUsr_SystemTime_DtrmnElapsedTime_uS_u16_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_IoHwAbstractionUsr_SystemTime_DtrmnElapsedTime_uS_u16_Start
# endif
# if defined (Rte_CallHook_IoHwAbstractionUsr_SystemTime_DtrmnElapsedTime_uS_u16_Start)
#  undef Rte_CallHook_IoHwAbstractionUsr_SystemTime_DtrmnElapsedTime_uS_u16_Start
FUNC(void, RTE_APPL_CODE) Rte_CallHook_IoHwAbstractionUsr_SystemTime_DtrmnElapsedTime_uS_u16_Start(UInt32 InitialTime, P2VAR(UInt16, AUTOMATIC, RTE_IOHWABSTRACTIONUSR_APPL_VAR) ElapsedTime);
# else
#  define Rte_CallHook_IoHwAbstractionUsr_SystemTime_DtrmnElapsedTime_uS_u16_Start(arg1, arg2) ((void)(0))
# endif /* Rte_CallHook_IoHwAbstractionUsr_SystemTime_DtrmnElapsedTime_uS_u16_Start */

# if defined (Rte_CallHook_IoHwAbstractionUsr_SystemTime_GetSystemTime_uS_u32_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_IoHwAbstractionUsr_SystemTime_GetSystemTime_uS_u32_Return
# endif
# if defined (Rte_CallHook_IoHwAbstractionUsr_SystemTime_GetSystemTime_uS_u32_Return)
#  undef Rte_CallHook_IoHwAbstractionUsr_SystemTime_GetSystemTime_uS_u32_Return
FUNC(void, RTE_APPL_CODE) Rte_CallHook_IoHwAbstractionUsr_SystemTime_GetSystemTime_uS_u32_Return(P2VAR(UInt32, AUTOMATIC, RTE_IOHWABSTRACTIONUSR_APPL_VAR) CurrentTime);
# else
#  define Rte_CallHook_IoHwAbstractionUsr_SystemTime_GetSystemTime_uS_u32_Return(arg1) ((void)(0))
# endif /* Rte_CallHook_IoHwAbstractionUsr_SystemTime_GetSystemTime_uS_u32_Return */

# if defined (Rte_CallHook_IoHwAbstractionUsr_SystemTime_GetSystemTime_uS_u32_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_IoHwAbstractionUsr_SystemTime_GetSystemTime_uS_u32_Start
# endif
# if defined (Rte_CallHook_IoHwAbstractionUsr_SystemTime_GetSystemTime_uS_u32_Start)
#  undef Rte_CallHook_IoHwAbstractionUsr_SystemTime_GetSystemTime_uS_u32_Start
FUNC(void, RTE_APPL_CODE) Rte_CallHook_IoHwAbstractionUsr_SystemTime_GetSystemTime_uS_u32_Start(P2VAR(UInt32, AUTOMATIC, RTE_IOHWABSTRACTIONUSR_APPL_VAR) CurrentTime);
# else
#  define Rte_CallHook_IoHwAbstractionUsr_SystemTime_GetSystemTime_uS_u32_Start(arg1) ((void)(0))
# endif /* Rte_CallHook_IoHwAbstractionUsr_SystemTime_GetSystemTime_uS_u32_Start */

# if defined (Rte_CallHook_Sa_BkCpPc_NxtrDiagMgr_SetNTCStatus_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_Sa_BkCpPc_NxtrDiagMgr_SetNTCStatus_Return
# endif
# if defined (Rte_CallHook_Sa_BkCpPc_NxtrDiagMgr_SetNTCStatus_Return)
#  undef Rte_CallHook_Sa_BkCpPc_NxtrDiagMgr_SetNTCStatus_Return
FUNC(void, RTE_APPL_CODE) Rte_CallHook_Sa_BkCpPc_NxtrDiagMgr_SetNTCStatus_Return(NTCNumber NTC_Cnt_T_enum, UInt8 Param_Cnt_T_u08, NxtrDiagMgrStatus Status_Cnt_T_enum);
# else
#  define Rte_CallHook_Sa_BkCpPc_NxtrDiagMgr_SetNTCStatus_Return(arg1, arg2, arg3) ((void)(0))
# endif /* Rte_CallHook_Sa_BkCpPc_NxtrDiagMgr_SetNTCStatus_Return */

# if defined (Rte_CallHook_Sa_BkCpPc_NxtrDiagMgr_SetNTCStatus_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_Sa_BkCpPc_NxtrDiagMgr_SetNTCStatus_Start
# endif
# if defined (Rte_CallHook_Sa_BkCpPc_NxtrDiagMgr_SetNTCStatus_Start)
#  undef Rte_CallHook_Sa_BkCpPc_NxtrDiagMgr_SetNTCStatus_Start
FUNC(void, RTE_APPL_CODE) Rte_CallHook_Sa_BkCpPc_NxtrDiagMgr_SetNTCStatus_Start(NTCNumber NTC_Cnt_T_enum, UInt8 Param_Cnt_T_u08, NxtrDiagMgrStatus Status_Cnt_T_enum);
# else
#  define Rte_CallHook_Sa_BkCpPc_NxtrDiagMgr_SetNTCStatus_Start(arg1, arg2, arg3) ((void)(0))
# endif /* Rte_CallHook_Sa_BkCpPc_NxtrDiagMgr_SetNTCStatus_Start */

# if defined (Rte_CallHook_Sa_BkCpPc_PhyCapDischarge_OP_SET_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_Sa_BkCpPc_PhyCapDischarge_OP_SET_Return
# endif
# if defined (Rte_CallHook_Sa_BkCpPc_PhyCapDischarge_OP_SET_Return)
#  undef Rte_CallHook_Sa_BkCpPc_PhyCapDischarge_OP_SET_Return
FUNC(void, RTE_APPL_CODE) Rte_CallHook_Sa_BkCpPc_PhyCapDischarge_OP_SET_Return(IoHwAb_BoolType signal);
# else
#  define Rte_CallHook_Sa_BkCpPc_PhyCapDischarge_OP_SET_Return(arg1) ((void)(0))
# endif /* Rte_CallHook_Sa_BkCpPc_PhyCapDischarge_OP_SET_Return */

# if defined (Rte_CallHook_Sa_BkCpPc_PhyCapDischarge_OP_SET_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_Sa_BkCpPc_PhyCapDischarge_OP_SET_Start
# endif
# if defined (Rte_CallHook_Sa_BkCpPc_PhyCapDischarge_OP_SET_Start)
#  undef Rte_CallHook_Sa_BkCpPc_PhyCapDischarge_OP_SET_Start
FUNC(void, RTE_APPL_CODE) Rte_CallHook_Sa_BkCpPc_PhyCapDischarge_OP_SET_Start(IoHwAb_BoolType signal);
# else
#  define Rte_CallHook_Sa_BkCpPc_PhyCapDischarge_OP_SET_Start(arg1) ((void)(0))
# endif /* Rte_CallHook_Sa_BkCpPc_PhyCapDischarge_OP_SET_Start */

# if defined (Rte_CallHook_Sa_BkCpPc_PhyCapPrecharge_OP_SET_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_Sa_BkCpPc_PhyCapPrecharge_OP_SET_Return
# endif
# if defined (Rte_CallHook_Sa_BkCpPc_PhyCapPrecharge_OP_SET_Return)
#  undef Rte_CallHook_Sa_BkCpPc_PhyCapPrecharge_OP_SET_Return
FUNC(void, RTE_APPL_CODE) Rte_CallHook_Sa_BkCpPc_PhyCapPrecharge_OP_SET_Return(IoHwAb_BoolType signal);
# else
#  define Rte_CallHook_Sa_BkCpPc_PhyCapPrecharge_OP_SET_Return(arg1) ((void)(0))
# endif /* Rte_CallHook_Sa_BkCpPc_PhyCapPrecharge_OP_SET_Return */

# if defined (Rte_CallHook_Sa_BkCpPc_PhyCapPrecharge_OP_SET_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_Sa_BkCpPc_PhyCapPrecharge_OP_SET_Start
# endif
# if defined (Rte_CallHook_Sa_BkCpPc_PhyCapPrecharge_OP_SET_Start)
#  undef Rte_CallHook_Sa_BkCpPc_PhyCapPrecharge_OP_SET_Start
FUNC(void, RTE_APPL_CODE) Rte_CallHook_Sa_BkCpPc_PhyCapPrecharge_OP_SET_Start(IoHwAb_BoolType signal);
# else
#  define Rte_CallHook_Sa_BkCpPc_PhyCapPrecharge_OP_SET_Start(arg1) ((void)(0))
# endif /* Rte_CallHook_Sa_BkCpPc_PhyCapPrecharge_OP_SET_Start */

# if defined (Rte_CallHook_Sa_BkCpPc_SystemTime_DtrmnElapsedTime_mS_u16_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_Sa_BkCpPc_SystemTime_DtrmnElapsedTime_mS_u16_Return
# endif
# if defined (Rte_CallHook_Sa_BkCpPc_SystemTime_DtrmnElapsedTime_mS_u16_Return)
#  undef Rte_CallHook_Sa_BkCpPc_SystemTime_DtrmnElapsedTime_mS_u16_Return
FUNC(void, RTE_APPL_CODE) Rte_CallHook_Sa_BkCpPc_SystemTime_DtrmnElapsedTime_mS_u16_Return(UInt32 InitialTime, P2VAR(UInt16, AUTOMATIC, RTE_SA_BKCPPC_APPL_VAR) ElapsedTime);
# else
#  define Rte_CallHook_Sa_BkCpPc_SystemTime_DtrmnElapsedTime_mS_u16_Return(arg1, arg2) ((void)(0))
# endif /* Rte_CallHook_Sa_BkCpPc_SystemTime_DtrmnElapsedTime_mS_u16_Return */

# if defined (Rte_CallHook_Sa_BkCpPc_SystemTime_DtrmnElapsedTime_mS_u16_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_Sa_BkCpPc_SystemTime_DtrmnElapsedTime_mS_u16_Start
# endif
# if defined (Rte_CallHook_Sa_BkCpPc_SystemTime_DtrmnElapsedTime_mS_u16_Start)
#  undef Rte_CallHook_Sa_BkCpPc_SystemTime_DtrmnElapsedTime_mS_u16_Start
FUNC(void, RTE_APPL_CODE) Rte_CallHook_Sa_BkCpPc_SystemTime_DtrmnElapsedTime_mS_u16_Start(UInt32 InitialTime, P2VAR(UInt16, AUTOMATIC, RTE_SA_BKCPPC_APPL_VAR) ElapsedTime);
# else
#  define Rte_CallHook_Sa_BkCpPc_SystemTime_DtrmnElapsedTime_mS_u16_Start(arg1, arg2) ((void)(0))
# endif /* Rte_CallHook_Sa_BkCpPc_SystemTime_DtrmnElapsedTime_mS_u16_Start */

# if defined (Rte_CallHook_Sa_BkCpPc_SystemTime_GetSystemTime_mS_u32_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_Sa_BkCpPc_SystemTime_GetSystemTime_mS_u32_Return
# endif
# if defined (Rte_CallHook_Sa_BkCpPc_SystemTime_GetSystemTime_mS_u32_Return)
#  undef Rte_CallHook_Sa_BkCpPc_SystemTime_GetSystemTime_mS_u32_Return
FUNC(void, RTE_APPL_CODE) Rte_CallHook_Sa_BkCpPc_SystemTime_GetSystemTime_mS_u32_Return(P2VAR(UInt32, AUTOMATIC, RTE_SA_BKCPPC_APPL_VAR) CurrentTime);
# else
#  define Rte_CallHook_Sa_BkCpPc_SystemTime_GetSystemTime_mS_u32_Return(arg1) ((void)(0))
# endif /* Rte_CallHook_Sa_BkCpPc_SystemTime_GetSystemTime_mS_u32_Return */

# if defined (Rte_CallHook_Sa_BkCpPc_SystemTime_GetSystemTime_mS_u32_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_Sa_BkCpPc_SystemTime_GetSystemTime_mS_u32_Start
# endif
# if defined (Rte_CallHook_Sa_BkCpPc_SystemTime_GetSystemTime_mS_u32_Start)
#  undef Rte_CallHook_Sa_BkCpPc_SystemTime_GetSystemTime_mS_u32_Start
FUNC(void, RTE_APPL_CODE) Rte_CallHook_Sa_BkCpPc_SystemTime_GetSystemTime_mS_u32_Start(P2VAR(UInt32, AUTOMATIC, RTE_SA_BKCPPC_APPL_VAR) CurrentTime);
# else
#  define Rte_CallHook_Sa_BkCpPc_SystemTime_GetSystemTime_mS_u32_Start(arg1) ((void)(0))
# endif /* Rte_CallHook_Sa_BkCpPc_SystemTime_GetSystemTime_mS_u32_Start */

# if defined (Rte_CallHook_Sa_CDDInterface_CDDPorts_ApplyMtrElecMechPol_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_Sa_CDDInterface_CDDPorts_ApplyMtrElecMechPol_Return
# endif
# if defined (Rte_CallHook_Sa_CDDInterface_CDDPorts_ApplyMtrElecMechPol_Return)
#  undef Rte_CallHook_Sa_CDDInterface_CDDPorts_ApplyMtrElecMechPol_Return
FUNC(void, RTE_APPL_CODE) Rte_CallHook_Sa_CDDInterface_CDDPorts_ApplyMtrElecMechPol_Return(SInt8 MtrElecMechPol_Cnt_s8);
# else
#  define Rte_CallHook_Sa_CDDInterface_CDDPorts_ApplyMtrElecMechPol_Return(arg1) ((void)(0))
# endif /* Rte_CallHook_Sa_CDDInterface_CDDPorts_ApplyMtrElecMechPol_Return */

# if defined (Rte_CallHook_Sa_CDDInterface_CDDPorts_ApplyMtrElecMechPol_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_Sa_CDDInterface_CDDPorts_ApplyMtrElecMechPol_Start
# endif
# if defined (Rte_CallHook_Sa_CDDInterface_CDDPorts_ApplyMtrElecMechPol_Start)
#  undef Rte_CallHook_Sa_CDDInterface_CDDPorts_ApplyMtrElecMechPol_Start
FUNC(void, RTE_APPL_CODE) Rte_CallHook_Sa_CDDInterface_CDDPorts_ApplyMtrElecMechPol_Start(SInt8 MtrElecMechPol_Cnt_s8);
# else
#  define Rte_CallHook_Sa_CDDInterface_CDDPorts_ApplyMtrElecMechPol_Start(arg1) ((void)(0))
# endif /* Rte_CallHook_Sa_CDDInterface_CDDPorts_ApplyMtrElecMechPol_Start */

# if defined (Rte_CallHook_Sa_CDDInterface_CDDPorts_ClearPhsReasSum_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_Sa_CDDInterface_CDDPorts_ClearPhsReasSum_Return
# endif
# if defined (Rte_CallHook_Sa_CDDInterface_CDDPorts_ClearPhsReasSum_Return)
#  undef Rte_CallHook_Sa_CDDInterface_CDDPorts_ClearPhsReasSum_Return
FUNC(void, RTE_APPL_CODE) Rte_CallHook_Sa_CDDInterface_CDDPorts_ClearPhsReasSum_Return(UInt16 DataAccessBfr_Cnt_T_u16);
# else
#  define Rte_CallHook_Sa_CDDInterface_CDDPorts_ClearPhsReasSum_Return(arg1) ((void)(0))
# endif /* Rte_CallHook_Sa_CDDInterface_CDDPorts_ClearPhsReasSum_Return */

# if defined (Rte_CallHook_Sa_CDDInterface_CDDPorts_ClearPhsReasSum_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_Sa_CDDInterface_CDDPorts_ClearPhsReasSum_Start
# endif
# if defined (Rte_CallHook_Sa_CDDInterface_CDDPorts_ClearPhsReasSum_Start)
#  undef Rte_CallHook_Sa_CDDInterface_CDDPorts_ClearPhsReasSum_Start
FUNC(void, RTE_APPL_CODE) Rte_CallHook_Sa_CDDInterface_CDDPorts_ClearPhsReasSum_Start(UInt16 DataAccessBfr_Cnt_T_u16);
# else
#  define Rte_CallHook_Sa_CDDInterface_CDDPorts_ClearPhsReasSum_Start(arg1) ((void)(0))
# endif /* Rte_CallHook_Sa_CDDInterface_CDDPorts_ClearPhsReasSum_Start */

# if defined (Rte_CallHook_Sa_CmMtrCurr_EOLShCurrCal_WriteBlock_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_Sa_CmMtrCurr_EOLShCurrCal_WriteBlock_Return
# endif
# if defined (Rte_CallHook_Sa_CmMtrCurr_EOLShCurrCal_WriteBlock_Return)
#  undef Rte_CallHook_Sa_CmMtrCurr_EOLShCurrCal_WriteBlock_Return
FUNC(void, RTE_APPL_CODE) Rte_CallHook_Sa_CmMtrCurr_EOLShCurrCal_WriteBlock_Return(P2CONST(NvM_DestPtr, AUTOMATIC, RTE_SA_CMMTRCURR_APPL_DATA) DstPtr);
# else
#  define Rte_CallHook_Sa_CmMtrCurr_EOLShCurrCal_WriteBlock_Return(arg1) ((void)(0))
# endif /* Rte_CallHook_Sa_CmMtrCurr_EOLShCurrCal_WriteBlock_Return */

# if defined (Rte_CallHook_Sa_CmMtrCurr_EOLShCurrCal_WriteBlock_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_Sa_CmMtrCurr_EOLShCurrCal_WriteBlock_Start
# endif
# if defined (Rte_CallHook_Sa_CmMtrCurr_EOLShCurrCal_WriteBlock_Start)
#  undef Rte_CallHook_Sa_CmMtrCurr_EOLShCurrCal_WriteBlock_Start
FUNC(void, RTE_APPL_CODE) Rte_CallHook_Sa_CmMtrCurr_EOLShCurrCal_WriteBlock_Start(P2CONST(NvM_DestPtr, AUTOMATIC, RTE_SA_CMMTRCURR_APPL_DATA) DstPtr);
# else
#  define Rte_CallHook_Sa_CmMtrCurr_EOLShCurrCal_WriteBlock_Start(arg1) ((void)(0))
# endif /* Rte_CallHook_Sa_CmMtrCurr_EOLShCurrCal_WriteBlock_Start */

# if defined (Rte_CallHook_Sa_CmMtrCurr_NxtrDiagMgr_SetNTCStatus_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_Sa_CmMtrCurr_NxtrDiagMgr_SetNTCStatus_Return
# endif
# if defined (Rte_CallHook_Sa_CmMtrCurr_NxtrDiagMgr_SetNTCStatus_Return)
#  undef Rte_CallHook_Sa_CmMtrCurr_NxtrDiagMgr_SetNTCStatus_Return
FUNC(void, RTE_APPL_CODE) Rte_CallHook_Sa_CmMtrCurr_NxtrDiagMgr_SetNTCStatus_Return(NTCNumber NTC_Cnt_T_enum, UInt8 Param_Cnt_T_u08, NxtrDiagMgrStatus Status_Cnt_T_enum);
# else
#  define Rte_CallHook_Sa_CmMtrCurr_NxtrDiagMgr_SetNTCStatus_Return(arg1, arg2, arg3) ((void)(0))
# endif /* Rte_CallHook_Sa_CmMtrCurr_NxtrDiagMgr_SetNTCStatus_Return */

# if defined (Rte_CallHook_Sa_CmMtrCurr_NxtrDiagMgr_SetNTCStatus_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_Sa_CmMtrCurr_NxtrDiagMgr_SetNTCStatus_Start
# endif
# if defined (Rte_CallHook_Sa_CmMtrCurr_NxtrDiagMgr_SetNTCStatus_Start)
#  undef Rte_CallHook_Sa_CmMtrCurr_NxtrDiagMgr_SetNTCStatus_Start
FUNC(void, RTE_APPL_CODE) Rte_CallHook_Sa_CmMtrCurr_NxtrDiagMgr_SetNTCStatus_Start(NTCNumber NTC_Cnt_T_enum, UInt8 Param_Cnt_T_u08, NxtrDiagMgrStatus Status_Cnt_T_enum);
# else
#  define Rte_CallHook_Sa_CmMtrCurr_NxtrDiagMgr_SetNTCStatus_Start(arg1, arg2, arg3) ((void)(0))
# endif /* Rte_CallHook_Sa_CmMtrCurr_NxtrDiagMgr_SetNTCStatus_Start */

# if defined (Rte_CallHook_Sa_CtrlTemp_CtrlTemp_Per2_CP0_CheckpointReached_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_Sa_CtrlTemp_CtrlTemp_Per2_CP0_CheckpointReached_Return
# endif
# if defined (Rte_CallHook_Sa_CtrlTemp_CtrlTemp_Per2_CP0_CheckpointReached_Return)
#  undef Rte_CallHook_Sa_CtrlTemp_CtrlTemp_Per2_CP0_CheckpointReached_Return
FUNC(void, RTE_APPL_CODE) Rte_CallHook_Sa_CtrlTemp_CtrlTemp_Per2_CP0_CheckpointReached_Return(void);
# else
#  define Rte_CallHook_Sa_CtrlTemp_CtrlTemp_Per2_CP0_CheckpointReached_Return() ((void)(0))
# endif /* Rte_CallHook_Sa_CtrlTemp_CtrlTemp_Per2_CP0_CheckpointReached_Return */

# if defined (Rte_CallHook_Sa_CtrlTemp_CtrlTemp_Per2_CP0_CheckpointReached_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_Sa_CtrlTemp_CtrlTemp_Per2_CP0_CheckpointReached_Start
# endif
# if defined (Rte_CallHook_Sa_CtrlTemp_CtrlTemp_Per2_CP0_CheckpointReached_Start)
#  undef Rte_CallHook_Sa_CtrlTemp_CtrlTemp_Per2_CP0_CheckpointReached_Start
FUNC(void, RTE_APPL_CODE) Rte_CallHook_Sa_CtrlTemp_CtrlTemp_Per2_CP0_CheckpointReached_Start(void);
# else
#  define Rte_CallHook_Sa_CtrlTemp_CtrlTemp_Per2_CP0_CheckpointReached_Start() ((void)(0))
# endif /* Rte_CallHook_Sa_CtrlTemp_CtrlTemp_Per2_CP0_CheckpointReached_Start */

# if defined (Rte_CallHook_Sa_CtrlTemp_NxtrDiagMgr_SetNTCStatus_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_Sa_CtrlTemp_NxtrDiagMgr_SetNTCStatus_Return
# endif
# if defined (Rte_CallHook_Sa_CtrlTemp_NxtrDiagMgr_SetNTCStatus_Return)
#  undef Rte_CallHook_Sa_CtrlTemp_NxtrDiagMgr_SetNTCStatus_Return
FUNC(void, RTE_APPL_CODE) Rte_CallHook_Sa_CtrlTemp_NxtrDiagMgr_SetNTCStatus_Return(NTCNumber NTC_Cnt_T_enum, UInt8 Param_Cnt_T_u08, NxtrDiagMgrStatus Status_Cnt_T_enum);
# else
#  define Rte_CallHook_Sa_CtrlTemp_NxtrDiagMgr_SetNTCStatus_Return(arg1, arg2, arg3) ((void)(0))
# endif /* Rte_CallHook_Sa_CtrlTemp_NxtrDiagMgr_SetNTCStatus_Return */

# if defined (Rte_CallHook_Sa_CtrlTemp_NxtrDiagMgr_SetNTCStatus_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_Sa_CtrlTemp_NxtrDiagMgr_SetNTCStatus_Start
# endif
# if defined (Rte_CallHook_Sa_CtrlTemp_NxtrDiagMgr_SetNTCStatus_Start)
#  undef Rte_CallHook_Sa_CtrlTemp_NxtrDiagMgr_SetNTCStatus_Start
FUNC(void, RTE_APPL_CODE) Rte_CallHook_Sa_CtrlTemp_NxtrDiagMgr_SetNTCStatus_Start(NTCNumber NTC_Cnt_T_enum, UInt8 Param_Cnt_T_u08, NxtrDiagMgrStatus Status_Cnt_T_enum);
# else
#  define Rte_CallHook_Sa_CtrlTemp_NxtrDiagMgr_SetNTCStatus_Start(arg1, arg2, arg3) ((void)(0))
# endif /* Rte_CallHook_Sa_CtrlTemp_NxtrDiagMgr_SetNTCStatus_Start */

# if defined (Rte_CallHook_Sa_HwTrq2_HwTrq2_Per3_CP0_CheckpointReached_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_Sa_HwTrq2_HwTrq2_Per3_CP0_CheckpointReached_Return
# endif
# if defined (Rte_CallHook_Sa_HwTrq2_HwTrq2_Per3_CP0_CheckpointReached_Return)
#  undef Rte_CallHook_Sa_HwTrq2_HwTrq2_Per3_CP0_CheckpointReached_Return
FUNC(void, RTE_APPL_CODE) Rte_CallHook_Sa_HwTrq2_HwTrq2_Per3_CP0_CheckpointReached_Return(void);
# else
#  define Rte_CallHook_Sa_HwTrq2_HwTrq2_Per3_CP0_CheckpointReached_Return() ((void)(0))
# endif /* Rte_CallHook_Sa_HwTrq2_HwTrq2_Per3_CP0_CheckpointReached_Return */

# if defined (Rte_CallHook_Sa_HwTrq2_HwTrq2_Per3_CP0_CheckpointReached_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_Sa_HwTrq2_HwTrq2_Per3_CP0_CheckpointReached_Start
# endif
# if defined (Rte_CallHook_Sa_HwTrq2_HwTrq2_Per3_CP0_CheckpointReached_Start)
#  undef Rte_CallHook_Sa_HwTrq2_HwTrq2_Per3_CP0_CheckpointReached_Start
FUNC(void, RTE_APPL_CODE) Rte_CallHook_Sa_HwTrq2_HwTrq2_Per3_CP0_CheckpointReached_Start(void);
# else
#  define Rte_CallHook_Sa_HwTrq2_HwTrq2_Per3_CP0_CheckpointReached_Start() ((void)(0))
# endif /* Rte_CallHook_Sa_HwTrq2_HwTrq2_Per3_CP0_CheckpointReached_Start */

# if defined (Rte_CallHook_Sa_HwTrq2_NxtrDiagMgr_SetNTCStatus_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_Sa_HwTrq2_NxtrDiagMgr_SetNTCStatus_Return
# endif
# if defined (Rte_CallHook_Sa_HwTrq2_NxtrDiagMgr_SetNTCStatus_Return)
#  undef Rte_CallHook_Sa_HwTrq2_NxtrDiagMgr_SetNTCStatus_Return
FUNC(void, RTE_APPL_CODE) Rte_CallHook_Sa_HwTrq2_NxtrDiagMgr_SetNTCStatus_Return(NTCNumber NTC_Cnt_T_enum, UInt8 Param_Cnt_T_u08, NxtrDiagMgrStatus Status_Cnt_T_enum);
# else
#  define Rte_CallHook_Sa_HwTrq2_NxtrDiagMgr_SetNTCStatus_Return(arg1, arg2, arg3) ((void)(0))
# endif /* Rte_CallHook_Sa_HwTrq2_NxtrDiagMgr_SetNTCStatus_Return */

# if defined (Rte_CallHook_Sa_HwTrq2_NxtrDiagMgr_SetNTCStatus_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_Sa_HwTrq2_NxtrDiagMgr_SetNTCStatus_Start
# endif
# if defined (Rte_CallHook_Sa_HwTrq2_NxtrDiagMgr_SetNTCStatus_Start)
#  undef Rte_CallHook_Sa_HwTrq2_NxtrDiagMgr_SetNTCStatus_Start
FUNC(void, RTE_APPL_CODE) Rte_CallHook_Sa_HwTrq2_NxtrDiagMgr_SetNTCStatus_Start(NTCNumber NTC_Cnt_T_enum, UInt8 Param_Cnt_T_u08, NxtrDiagMgrStatus Status_Cnt_T_enum);
# else
#  define Rte_CallHook_Sa_HwTrq2_NxtrDiagMgr_SetNTCStatus_Start(arg1, arg2, arg3) ((void)(0))
# endif /* Rte_CallHook_Sa_HwTrq2_NxtrDiagMgr_SetNTCStatus_Start */

# if defined (Rte_CallHook_Sa_HwTrq_HwTrqTrim_GetErrorStatus_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_Sa_HwTrq_HwTrqTrim_GetErrorStatus_Return
# endif
# if defined (Rte_CallHook_Sa_HwTrq_HwTrqTrim_GetErrorStatus_Return)
#  undef Rte_CallHook_Sa_HwTrq_HwTrqTrim_GetErrorStatus_Return
FUNC(void, RTE_APPL_CODE) Rte_CallHook_Sa_HwTrq_HwTrqTrim_GetErrorStatus_Return(P2VAR(NvM_RequestResultType, AUTOMATIC, RTE_SA_HWTRQ_APPL_VAR) ErrorStatus);
# else
#  define Rte_CallHook_Sa_HwTrq_HwTrqTrim_GetErrorStatus_Return(arg1) ((void)(0))
# endif /* Rte_CallHook_Sa_HwTrq_HwTrqTrim_GetErrorStatus_Return */

# if defined (Rte_CallHook_Sa_HwTrq_HwTrqTrim_GetErrorStatus_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_Sa_HwTrq_HwTrqTrim_GetErrorStatus_Start
# endif
# if defined (Rte_CallHook_Sa_HwTrq_HwTrqTrim_GetErrorStatus_Start)
#  undef Rte_CallHook_Sa_HwTrq_HwTrqTrim_GetErrorStatus_Start
FUNC(void, RTE_APPL_CODE) Rte_CallHook_Sa_HwTrq_HwTrqTrim_GetErrorStatus_Start(P2VAR(NvM_RequestResultType, AUTOMATIC, RTE_SA_HWTRQ_APPL_VAR) ErrorStatus);
# else
#  define Rte_CallHook_Sa_HwTrq_HwTrqTrim_GetErrorStatus_Start(arg1) ((void)(0))
# endif /* Rte_CallHook_Sa_HwTrq_HwTrqTrim_GetErrorStatus_Start */

# if defined (Rte_CallHook_Sa_HwTrq_HwTrq_Per3_CP0_CheckpointReached_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_Sa_HwTrq_HwTrq_Per3_CP0_CheckpointReached_Return
# endif
# if defined (Rte_CallHook_Sa_HwTrq_HwTrq_Per3_CP0_CheckpointReached_Return)
#  undef Rte_CallHook_Sa_HwTrq_HwTrq_Per3_CP0_CheckpointReached_Return
FUNC(void, RTE_APPL_CODE) Rte_CallHook_Sa_HwTrq_HwTrq_Per3_CP0_CheckpointReached_Return(void);
# else
#  define Rte_CallHook_Sa_HwTrq_HwTrq_Per3_CP0_CheckpointReached_Return() ((void)(0))
# endif /* Rte_CallHook_Sa_HwTrq_HwTrq_Per3_CP0_CheckpointReached_Return */

# if defined (Rte_CallHook_Sa_HwTrq_HwTrq_Per3_CP0_CheckpointReached_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_Sa_HwTrq_HwTrq_Per3_CP0_CheckpointReached_Start
# endif
# if defined (Rte_CallHook_Sa_HwTrq_HwTrq_Per3_CP0_CheckpointReached_Start)
#  undef Rte_CallHook_Sa_HwTrq_HwTrq_Per3_CP0_CheckpointReached_Start
FUNC(void, RTE_APPL_CODE) Rte_CallHook_Sa_HwTrq_HwTrq_Per3_CP0_CheckpointReached_Start(void);
# else
#  define Rte_CallHook_Sa_HwTrq_HwTrq_Per3_CP0_CheckpointReached_Start() ((void)(0))
# endif /* Rte_CallHook_Sa_HwTrq_HwTrq_Per3_CP0_CheckpointReached_Start */

# if defined (Rte_CallHook_Sa_HwTrq_NxtrDiagMgr_GetNTCFailed_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_Sa_HwTrq_NxtrDiagMgr_GetNTCFailed_Return
# endif
# if defined (Rte_CallHook_Sa_HwTrq_NxtrDiagMgr_GetNTCFailed_Return)
#  undef Rte_CallHook_Sa_HwTrq_NxtrDiagMgr_GetNTCFailed_Return
FUNC(void, RTE_APPL_CODE) Rte_CallHook_Sa_HwTrq_NxtrDiagMgr_GetNTCFailed_Return(NTCNumber NTC_Cnt_T_enum, P2VAR(Boolean, AUTOMATIC, RTE_SA_HWTRQ_APPL_VAR) NTCFailed_Ptr_T_lgc);
# else
#  define Rte_CallHook_Sa_HwTrq_NxtrDiagMgr_GetNTCFailed_Return(arg1, arg2) ((void)(0))
# endif /* Rte_CallHook_Sa_HwTrq_NxtrDiagMgr_GetNTCFailed_Return */

# if defined (Rte_CallHook_Sa_HwTrq_NxtrDiagMgr_GetNTCFailed_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_Sa_HwTrq_NxtrDiagMgr_GetNTCFailed_Start
# endif
# if defined (Rte_CallHook_Sa_HwTrq_NxtrDiagMgr_GetNTCFailed_Start)
#  undef Rte_CallHook_Sa_HwTrq_NxtrDiagMgr_GetNTCFailed_Start
FUNC(void, RTE_APPL_CODE) Rte_CallHook_Sa_HwTrq_NxtrDiagMgr_GetNTCFailed_Start(NTCNumber NTC_Cnt_T_enum, P2VAR(Boolean, AUTOMATIC, RTE_SA_HWTRQ_APPL_VAR) NTCFailed_Ptr_T_lgc);
# else
#  define Rte_CallHook_Sa_HwTrq_NxtrDiagMgr_GetNTCFailed_Start(arg1, arg2) ((void)(0))
# endif /* Rte_CallHook_Sa_HwTrq_NxtrDiagMgr_GetNTCFailed_Start */

# if defined (Rte_CallHook_Sa_HwTrq_NxtrDiagMgr_GetNTCStatus_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_Sa_HwTrq_NxtrDiagMgr_GetNTCStatus_Return
# endif
# if defined (Rte_CallHook_Sa_HwTrq_NxtrDiagMgr_GetNTCStatus_Return)
#  undef Rte_CallHook_Sa_HwTrq_NxtrDiagMgr_GetNTCStatus_Return
FUNC(void, RTE_APPL_CODE) Rte_CallHook_Sa_HwTrq_NxtrDiagMgr_GetNTCStatus_Return(NTCNumber NTC_Cnt_T_enum, P2VAR(UInt8, AUTOMATIC, RTE_SA_HWTRQ_APPL_VAR) Status_Ptr_T_u08);
# else
#  define Rte_CallHook_Sa_HwTrq_NxtrDiagMgr_GetNTCStatus_Return(arg1, arg2) ((void)(0))
# endif /* Rte_CallHook_Sa_HwTrq_NxtrDiagMgr_GetNTCStatus_Return */

# if defined (Rte_CallHook_Sa_HwTrq_NxtrDiagMgr_GetNTCStatus_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_Sa_HwTrq_NxtrDiagMgr_GetNTCStatus_Start
# endif
# if defined (Rte_CallHook_Sa_HwTrq_NxtrDiagMgr_GetNTCStatus_Start)
#  undef Rte_CallHook_Sa_HwTrq_NxtrDiagMgr_GetNTCStatus_Start
FUNC(void, RTE_APPL_CODE) Rte_CallHook_Sa_HwTrq_NxtrDiagMgr_GetNTCStatus_Start(NTCNumber NTC_Cnt_T_enum, P2VAR(UInt8, AUTOMATIC, RTE_SA_HWTRQ_APPL_VAR) Status_Ptr_T_u08);
# else
#  define Rte_CallHook_Sa_HwTrq_NxtrDiagMgr_GetNTCStatus_Start(arg1, arg2) ((void)(0))
# endif /* Rte_CallHook_Sa_HwTrq_NxtrDiagMgr_GetNTCStatus_Start */

# if defined (Rte_CallHook_Sa_HwTrq_NxtrDiagMgr_SetNTCStatus_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_Sa_HwTrq_NxtrDiagMgr_SetNTCStatus_Return
# endif
# if defined (Rte_CallHook_Sa_HwTrq_NxtrDiagMgr_SetNTCStatus_Return)
#  undef Rte_CallHook_Sa_HwTrq_NxtrDiagMgr_SetNTCStatus_Return
FUNC(void, RTE_APPL_CODE) Rte_CallHook_Sa_HwTrq_NxtrDiagMgr_SetNTCStatus_Return(NTCNumber NTC_Cnt_T_enum, UInt8 Param_Cnt_T_u08, NxtrDiagMgrStatus Status_Cnt_T_enum);
# else
#  define Rte_CallHook_Sa_HwTrq_NxtrDiagMgr_SetNTCStatus_Return(arg1, arg2, arg3) ((void)(0))
# endif /* Rte_CallHook_Sa_HwTrq_NxtrDiagMgr_SetNTCStatus_Return */

# if defined (Rte_CallHook_Sa_HwTrq_NxtrDiagMgr_SetNTCStatus_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_Sa_HwTrq_NxtrDiagMgr_SetNTCStatus_Start
# endif
# if defined (Rte_CallHook_Sa_HwTrq_NxtrDiagMgr_SetNTCStatus_Start)
#  undef Rte_CallHook_Sa_HwTrq_NxtrDiagMgr_SetNTCStatus_Start
FUNC(void, RTE_APPL_CODE) Rte_CallHook_Sa_HwTrq_NxtrDiagMgr_SetNTCStatus_Start(NTCNumber NTC_Cnt_T_enum, UInt8 Param_Cnt_T_u08, NxtrDiagMgrStatus Status_Cnt_T_enum);
# else
#  define Rte_CallHook_Sa_HwTrq_NxtrDiagMgr_SetNTCStatus_Start(arg1, arg2, arg3) ((void)(0))
# endif /* Rte_CallHook_Sa_HwTrq_NxtrDiagMgr_SetNTCStatus_Start */

# if defined (Rte_CallHook_Sa_MtrDrvDiag_FetDrvReset_OP_SET_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_Sa_MtrDrvDiag_FetDrvReset_OP_SET_Return
# endif
# if defined (Rte_CallHook_Sa_MtrDrvDiag_FetDrvReset_OP_SET_Return)
#  undef Rte_CallHook_Sa_MtrDrvDiag_FetDrvReset_OP_SET_Return
FUNC(void, RTE_APPL_CODE) Rte_CallHook_Sa_MtrDrvDiag_FetDrvReset_OP_SET_Return(IoHwAb_BoolType signal);
# else
#  define Rte_CallHook_Sa_MtrDrvDiag_FetDrvReset_OP_SET_Return(arg1) ((void)(0))
# endif /* Rte_CallHook_Sa_MtrDrvDiag_FetDrvReset_OP_SET_Return */

# if defined (Rte_CallHook_Sa_MtrDrvDiag_FetDrvReset_OP_SET_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_Sa_MtrDrvDiag_FetDrvReset_OP_SET_Start
# endif
# if defined (Rte_CallHook_Sa_MtrDrvDiag_FetDrvReset_OP_SET_Start)
#  undef Rte_CallHook_Sa_MtrDrvDiag_FetDrvReset_OP_SET_Start
FUNC(void, RTE_APPL_CODE) Rte_CallHook_Sa_MtrDrvDiag_FetDrvReset_OP_SET_Start(IoHwAb_BoolType signal);
# else
#  define Rte_CallHook_Sa_MtrDrvDiag_FetDrvReset_OP_SET_Start(arg1) ((void)(0))
# endif /* Rte_CallHook_Sa_MtrDrvDiag_FetDrvReset_OP_SET_Start */

# if defined (Rte_CallHook_Sa_MtrDrvDiag_FetFlt1Data_OP_GET_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_Sa_MtrDrvDiag_FetFlt1Data_OP_GET_Return
# endif
# if defined (Rte_CallHook_Sa_MtrDrvDiag_FetFlt1Data_OP_GET_Return)
#  undef Rte_CallHook_Sa_MtrDrvDiag_FetFlt1Data_OP_GET_Return
FUNC(void, RTE_APPL_CODE) Rte_CallHook_Sa_MtrDrvDiag_FetFlt1Data_OP_GET_Return(P2VAR(IoHwAb_BoolType, AUTOMATIC, RTE_SA_MTRDRVDIAG_APPL_VAR) signal);
# else
#  define Rte_CallHook_Sa_MtrDrvDiag_FetFlt1Data_OP_GET_Return(arg1) ((void)(0))
# endif /* Rte_CallHook_Sa_MtrDrvDiag_FetFlt1Data_OP_GET_Return */

# if defined (Rte_CallHook_Sa_MtrDrvDiag_FetFlt1Data_OP_GET_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_Sa_MtrDrvDiag_FetFlt1Data_OP_GET_Start
# endif
# if defined (Rte_CallHook_Sa_MtrDrvDiag_FetFlt1Data_OP_GET_Start)
#  undef Rte_CallHook_Sa_MtrDrvDiag_FetFlt1Data_OP_GET_Start
FUNC(void, RTE_APPL_CODE) Rte_CallHook_Sa_MtrDrvDiag_FetFlt1Data_OP_GET_Start(P2VAR(IoHwAb_BoolType, AUTOMATIC, RTE_SA_MTRDRVDIAG_APPL_VAR) signal);
# else
#  define Rte_CallHook_Sa_MtrDrvDiag_FetFlt1Data_OP_GET_Start(arg1) ((void)(0))
# endif /* Rte_CallHook_Sa_MtrDrvDiag_FetFlt1Data_OP_GET_Start */

# if defined (Rte_CallHook_Sa_MtrDrvDiag_FetFlt2Clk_OP_GET_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_Sa_MtrDrvDiag_FetFlt2Clk_OP_GET_Return
# endif
# if defined (Rte_CallHook_Sa_MtrDrvDiag_FetFlt2Clk_OP_GET_Return)
#  undef Rte_CallHook_Sa_MtrDrvDiag_FetFlt2Clk_OP_GET_Return
FUNC(void, RTE_APPL_CODE) Rte_CallHook_Sa_MtrDrvDiag_FetFlt2Clk_OP_GET_Return(P2VAR(IoHwAb_BoolType, AUTOMATIC, RTE_SA_MTRDRVDIAG_APPL_VAR) signal);
# else
#  define Rte_CallHook_Sa_MtrDrvDiag_FetFlt2Clk_OP_GET_Return(arg1) ((void)(0))
# endif /* Rte_CallHook_Sa_MtrDrvDiag_FetFlt2Clk_OP_GET_Return */

# if defined (Rte_CallHook_Sa_MtrDrvDiag_FetFlt2Clk_OP_GET_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_Sa_MtrDrvDiag_FetFlt2Clk_OP_GET_Start
# endif
# if defined (Rte_CallHook_Sa_MtrDrvDiag_FetFlt2Clk_OP_GET_Start)
#  undef Rte_CallHook_Sa_MtrDrvDiag_FetFlt2Clk_OP_GET_Start
FUNC(void, RTE_APPL_CODE) Rte_CallHook_Sa_MtrDrvDiag_FetFlt2Clk_OP_GET_Start(P2VAR(IoHwAb_BoolType, AUTOMATIC, RTE_SA_MTRDRVDIAG_APPL_VAR) signal);
# else
#  define Rte_CallHook_Sa_MtrDrvDiag_FetFlt2Clk_OP_GET_Start(arg1) ((void)(0))
# endif /* Rte_CallHook_Sa_MtrDrvDiag_FetFlt2Clk_OP_GET_Start */

# if defined (Rte_CallHook_Sa_MtrDrvDiag_FetFlt2Clk_OP_SET_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_Sa_MtrDrvDiag_FetFlt2Clk_OP_SET_Return
# endif
# if defined (Rte_CallHook_Sa_MtrDrvDiag_FetFlt2Clk_OP_SET_Return)
#  undef Rte_CallHook_Sa_MtrDrvDiag_FetFlt2Clk_OP_SET_Return
FUNC(void, RTE_APPL_CODE) Rte_CallHook_Sa_MtrDrvDiag_FetFlt2Clk_OP_SET_Return(IoHwAb_BoolType signal);
# else
#  define Rte_CallHook_Sa_MtrDrvDiag_FetFlt2Clk_OP_SET_Return(arg1) ((void)(0))
# endif /* Rte_CallHook_Sa_MtrDrvDiag_FetFlt2Clk_OP_SET_Return */

# if defined (Rte_CallHook_Sa_MtrDrvDiag_FetFlt2Clk_OP_SET_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_Sa_MtrDrvDiag_FetFlt2Clk_OP_SET_Start
# endif
# if defined (Rte_CallHook_Sa_MtrDrvDiag_FetFlt2Clk_OP_SET_Start)
#  undef Rte_CallHook_Sa_MtrDrvDiag_FetFlt2Clk_OP_SET_Start
FUNC(void, RTE_APPL_CODE) Rte_CallHook_Sa_MtrDrvDiag_FetFlt2Clk_OP_SET_Start(IoHwAb_BoolType signal);
# else
#  define Rte_CallHook_Sa_MtrDrvDiag_FetFlt2Clk_OP_SET_Start(arg1) ((void)(0))
# endif /* Rte_CallHook_Sa_MtrDrvDiag_FetFlt2Clk_OP_SET_Start */

# if defined (Rte_CallHook_Sa_MtrDrvDiag_IoHwAbPortConfig_SetFetFlt2ToOutput_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_Sa_MtrDrvDiag_IoHwAbPortConfig_SetFetFlt2ToOutput_Return
# endif
# if defined (Rte_CallHook_Sa_MtrDrvDiag_IoHwAbPortConfig_SetFetFlt2ToOutput_Return)
#  undef Rte_CallHook_Sa_MtrDrvDiag_IoHwAbPortConfig_SetFetFlt2ToOutput_Return
FUNC(void, RTE_APPL_CODE) Rte_CallHook_Sa_MtrDrvDiag_IoHwAbPortConfig_SetFetFlt2ToOutput_Return(IoHwAb_BoolType signal);
# else
#  define Rte_CallHook_Sa_MtrDrvDiag_IoHwAbPortConfig_SetFetFlt2ToOutput_Return(arg1) ((void)(0))
# endif /* Rte_CallHook_Sa_MtrDrvDiag_IoHwAbPortConfig_SetFetFlt2ToOutput_Return */

# if defined (Rte_CallHook_Sa_MtrDrvDiag_IoHwAbPortConfig_SetFetFlt2ToOutput_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_Sa_MtrDrvDiag_IoHwAbPortConfig_SetFetFlt2ToOutput_Start
# endif
# if defined (Rte_CallHook_Sa_MtrDrvDiag_IoHwAbPortConfig_SetFetFlt2ToOutput_Start)
#  undef Rte_CallHook_Sa_MtrDrvDiag_IoHwAbPortConfig_SetFetFlt2ToOutput_Start
FUNC(void, RTE_APPL_CODE) Rte_CallHook_Sa_MtrDrvDiag_IoHwAbPortConfig_SetFetFlt2ToOutput_Start(IoHwAb_BoolType signal);
# else
#  define Rte_CallHook_Sa_MtrDrvDiag_IoHwAbPortConfig_SetFetFlt2ToOutput_Start(arg1) ((void)(0))
# endif /* Rte_CallHook_Sa_MtrDrvDiag_IoHwAbPortConfig_SetFetFlt2ToOutput_Start */

# if defined (Rte_CallHook_Sa_MtrDrvDiag_NxtrDiagMgr_GetNTCFailed_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_Sa_MtrDrvDiag_NxtrDiagMgr_GetNTCFailed_Return
# endif
# if defined (Rte_CallHook_Sa_MtrDrvDiag_NxtrDiagMgr_GetNTCFailed_Return)
#  undef Rte_CallHook_Sa_MtrDrvDiag_NxtrDiagMgr_GetNTCFailed_Return
FUNC(void, RTE_APPL_CODE) Rte_CallHook_Sa_MtrDrvDiag_NxtrDiagMgr_GetNTCFailed_Return(NTCNumber NTC_Cnt_T_enum, P2VAR(Boolean, AUTOMATIC, RTE_SA_MTRDRVDIAG_APPL_VAR) NTCFailed_Ptr_T_lgc);
# else
#  define Rte_CallHook_Sa_MtrDrvDiag_NxtrDiagMgr_GetNTCFailed_Return(arg1, arg2) ((void)(0))
# endif /* Rte_CallHook_Sa_MtrDrvDiag_NxtrDiagMgr_GetNTCFailed_Return */

# if defined (Rte_CallHook_Sa_MtrDrvDiag_NxtrDiagMgr_GetNTCFailed_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_Sa_MtrDrvDiag_NxtrDiagMgr_GetNTCFailed_Start
# endif
# if defined (Rte_CallHook_Sa_MtrDrvDiag_NxtrDiagMgr_GetNTCFailed_Start)
#  undef Rte_CallHook_Sa_MtrDrvDiag_NxtrDiagMgr_GetNTCFailed_Start
FUNC(void, RTE_APPL_CODE) Rte_CallHook_Sa_MtrDrvDiag_NxtrDiagMgr_GetNTCFailed_Start(NTCNumber NTC_Cnt_T_enum, P2VAR(Boolean, AUTOMATIC, RTE_SA_MTRDRVDIAG_APPL_VAR) NTCFailed_Ptr_T_lgc);
# else
#  define Rte_CallHook_Sa_MtrDrvDiag_NxtrDiagMgr_GetNTCFailed_Start(arg1, arg2) ((void)(0))
# endif /* Rte_CallHook_Sa_MtrDrvDiag_NxtrDiagMgr_GetNTCFailed_Start */

# if defined (Rte_CallHook_Sa_MtrDrvDiag_NxtrDiagMgr_SetNTCStatus_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_Sa_MtrDrvDiag_NxtrDiagMgr_SetNTCStatus_Return
# endif
# if defined (Rte_CallHook_Sa_MtrDrvDiag_NxtrDiagMgr_SetNTCStatus_Return)
#  undef Rte_CallHook_Sa_MtrDrvDiag_NxtrDiagMgr_SetNTCStatus_Return
FUNC(void, RTE_APPL_CODE) Rte_CallHook_Sa_MtrDrvDiag_NxtrDiagMgr_SetNTCStatus_Return(NTCNumber NTC_Cnt_T_enum, UInt8 Param_Cnt_T_u08, NxtrDiagMgrStatus Status_Cnt_T_enum);
# else
#  define Rte_CallHook_Sa_MtrDrvDiag_NxtrDiagMgr_SetNTCStatus_Return(arg1, arg2, arg3) ((void)(0))
# endif /* Rte_CallHook_Sa_MtrDrvDiag_NxtrDiagMgr_SetNTCStatus_Return */

# if defined (Rte_CallHook_Sa_MtrDrvDiag_NxtrDiagMgr_SetNTCStatus_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_Sa_MtrDrvDiag_NxtrDiagMgr_SetNTCStatus_Start
# endif
# if defined (Rte_CallHook_Sa_MtrDrvDiag_NxtrDiagMgr_SetNTCStatus_Start)
#  undef Rte_CallHook_Sa_MtrDrvDiag_NxtrDiagMgr_SetNTCStatus_Start
FUNC(void, RTE_APPL_CODE) Rte_CallHook_Sa_MtrDrvDiag_NxtrDiagMgr_SetNTCStatus_Start(NTCNumber NTC_Cnt_T_enum, UInt8 Param_Cnt_T_u08, NxtrDiagMgrStatus Status_Cnt_T_enum);
# else
#  define Rte_CallHook_Sa_MtrDrvDiag_NxtrDiagMgr_SetNTCStatus_Start(arg1, arg2, arg3) ((void)(0))
# endif /* Rte_CallHook_Sa_MtrDrvDiag_NxtrDiagMgr_SetNTCStatus_Start */

# if defined (Rte_CallHook_Sa_MtrDrvDiag_SystemTime_DtrmnElapsedTime_mS_u16_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_Sa_MtrDrvDiag_SystemTime_DtrmnElapsedTime_mS_u16_Return
# endif
# if defined (Rte_CallHook_Sa_MtrDrvDiag_SystemTime_DtrmnElapsedTime_mS_u16_Return)
#  undef Rte_CallHook_Sa_MtrDrvDiag_SystemTime_DtrmnElapsedTime_mS_u16_Return
FUNC(void, RTE_APPL_CODE) Rte_CallHook_Sa_MtrDrvDiag_SystemTime_DtrmnElapsedTime_mS_u16_Return(UInt32 InitialTime, P2VAR(UInt16, AUTOMATIC, RTE_SA_MTRDRVDIAG_APPL_VAR) ElapsedTime);
# else
#  define Rte_CallHook_Sa_MtrDrvDiag_SystemTime_DtrmnElapsedTime_mS_u16_Return(arg1, arg2) ((void)(0))
# endif /* Rte_CallHook_Sa_MtrDrvDiag_SystemTime_DtrmnElapsedTime_mS_u16_Return */

# if defined (Rte_CallHook_Sa_MtrDrvDiag_SystemTime_DtrmnElapsedTime_mS_u16_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_Sa_MtrDrvDiag_SystemTime_DtrmnElapsedTime_mS_u16_Start
# endif
# if defined (Rte_CallHook_Sa_MtrDrvDiag_SystemTime_DtrmnElapsedTime_mS_u16_Start)
#  undef Rte_CallHook_Sa_MtrDrvDiag_SystemTime_DtrmnElapsedTime_mS_u16_Start
FUNC(void, RTE_APPL_CODE) Rte_CallHook_Sa_MtrDrvDiag_SystemTime_DtrmnElapsedTime_mS_u16_Start(UInt32 InitialTime, P2VAR(UInt16, AUTOMATIC, RTE_SA_MTRDRVDIAG_APPL_VAR) ElapsedTime);
# else
#  define Rte_CallHook_Sa_MtrDrvDiag_SystemTime_DtrmnElapsedTime_mS_u16_Start(arg1, arg2) ((void)(0))
# endif /* Rte_CallHook_Sa_MtrDrvDiag_SystemTime_DtrmnElapsedTime_mS_u16_Start */

# if defined (Rte_CallHook_Sa_MtrDrvDiag_SystemTime_DtrmnElapsedTime_uS_u16_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_Sa_MtrDrvDiag_SystemTime_DtrmnElapsedTime_uS_u16_Return
# endif
# if defined (Rte_CallHook_Sa_MtrDrvDiag_SystemTime_DtrmnElapsedTime_uS_u16_Return)
#  undef Rte_CallHook_Sa_MtrDrvDiag_SystemTime_DtrmnElapsedTime_uS_u16_Return
FUNC(void, RTE_APPL_CODE) Rte_CallHook_Sa_MtrDrvDiag_SystemTime_DtrmnElapsedTime_uS_u16_Return(UInt32 InitialTime, P2VAR(UInt16, AUTOMATIC, RTE_SA_MTRDRVDIAG_APPL_VAR) ElapsedTime);
# else
#  define Rte_CallHook_Sa_MtrDrvDiag_SystemTime_DtrmnElapsedTime_uS_u16_Return(arg1, arg2) ((void)(0))
# endif /* Rte_CallHook_Sa_MtrDrvDiag_SystemTime_DtrmnElapsedTime_uS_u16_Return */

# if defined (Rte_CallHook_Sa_MtrDrvDiag_SystemTime_DtrmnElapsedTime_uS_u16_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_Sa_MtrDrvDiag_SystemTime_DtrmnElapsedTime_uS_u16_Start
# endif
# if defined (Rte_CallHook_Sa_MtrDrvDiag_SystemTime_DtrmnElapsedTime_uS_u16_Start)
#  undef Rte_CallHook_Sa_MtrDrvDiag_SystemTime_DtrmnElapsedTime_uS_u16_Start
FUNC(void, RTE_APPL_CODE) Rte_CallHook_Sa_MtrDrvDiag_SystemTime_DtrmnElapsedTime_uS_u16_Start(UInt32 InitialTime, P2VAR(UInt16, AUTOMATIC, RTE_SA_MTRDRVDIAG_APPL_VAR) ElapsedTime);
# else
#  define Rte_CallHook_Sa_MtrDrvDiag_SystemTime_DtrmnElapsedTime_uS_u16_Start(arg1, arg2) ((void)(0))
# endif /* Rte_CallHook_Sa_MtrDrvDiag_SystemTime_DtrmnElapsedTime_uS_u16_Start */

# if defined (Rte_CallHook_Sa_MtrDrvDiag_SystemTime_GetSystemTime_mS_u32_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_Sa_MtrDrvDiag_SystemTime_GetSystemTime_mS_u32_Return
# endif
# if defined (Rte_CallHook_Sa_MtrDrvDiag_SystemTime_GetSystemTime_mS_u32_Return)
#  undef Rte_CallHook_Sa_MtrDrvDiag_SystemTime_GetSystemTime_mS_u32_Return
FUNC(void, RTE_APPL_CODE) Rte_CallHook_Sa_MtrDrvDiag_SystemTime_GetSystemTime_mS_u32_Return(P2VAR(UInt32, AUTOMATIC, RTE_SA_MTRDRVDIAG_APPL_VAR) CurrentTime);
# else
#  define Rte_CallHook_Sa_MtrDrvDiag_SystemTime_GetSystemTime_mS_u32_Return(arg1) ((void)(0))
# endif /* Rte_CallHook_Sa_MtrDrvDiag_SystemTime_GetSystemTime_mS_u32_Return */

# if defined (Rte_CallHook_Sa_MtrDrvDiag_SystemTime_GetSystemTime_mS_u32_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_Sa_MtrDrvDiag_SystemTime_GetSystemTime_mS_u32_Start
# endif
# if defined (Rte_CallHook_Sa_MtrDrvDiag_SystemTime_GetSystemTime_mS_u32_Start)
#  undef Rte_CallHook_Sa_MtrDrvDiag_SystemTime_GetSystemTime_mS_u32_Start
FUNC(void, RTE_APPL_CODE) Rte_CallHook_Sa_MtrDrvDiag_SystemTime_GetSystemTime_mS_u32_Start(P2VAR(UInt32, AUTOMATIC, RTE_SA_MTRDRVDIAG_APPL_VAR) CurrentTime);
# else
#  define Rte_CallHook_Sa_MtrDrvDiag_SystemTime_GetSystemTime_mS_u32_Start(arg1) ((void)(0))
# endif /* Rte_CallHook_Sa_MtrDrvDiag_SystemTime_GetSystemTime_mS_u32_Start */

# if defined (Rte_CallHook_Sa_MtrDrvDiag_SystemTime_GetSystemTime_uS_u32_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_Sa_MtrDrvDiag_SystemTime_GetSystemTime_uS_u32_Return
# endif
# if defined (Rte_CallHook_Sa_MtrDrvDiag_SystemTime_GetSystemTime_uS_u32_Return)
#  undef Rte_CallHook_Sa_MtrDrvDiag_SystemTime_GetSystemTime_uS_u32_Return
FUNC(void, RTE_APPL_CODE) Rte_CallHook_Sa_MtrDrvDiag_SystemTime_GetSystemTime_uS_u32_Return(P2VAR(UInt32, AUTOMATIC, RTE_SA_MTRDRVDIAG_APPL_VAR) CurrentTime);
# else
#  define Rte_CallHook_Sa_MtrDrvDiag_SystemTime_GetSystemTime_uS_u32_Return(arg1) ((void)(0))
# endif /* Rte_CallHook_Sa_MtrDrvDiag_SystemTime_GetSystemTime_uS_u32_Return */

# if defined (Rte_CallHook_Sa_MtrDrvDiag_SystemTime_GetSystemTime_uS_u32_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_Sa_MtrDrvDiag_SystemTime_GetSystemTime_uS_u32_Start
# endif
# if defined (Rte_CallHook_Sa_MtrDrvDiag_SystemTime_GetSystemTime_uS_u32_Start)
#  undef Rte_CallHook_Sa_MtrDrvDiag_SystemTime_GetSystemTime_uS_u32_Start
FUNC(void, RTE_APPL_CODE) Rte_CallHook_Sa_MtrDrvDiag_SystemTime_GetSystemTime_uS_u32_Start(P2VAR(UInt32, AUTOMATIC, RTE_SA_MTRDRVDIAG_APPL_VAR) CurrentTime);
# else
#  define Rte_CallHook_Sa_MtrDrvDiag_SystemTime_GetSystemTime_uS_u32_Start(arg1) ((void)(0))
# endif /* Rte_CallHook_Sa_MtrDrvDiag_SystemTime_GetSystemTime_uS_u32_Start */

# if defined (Rte_CallHook_Sa_MtrPos2_NxtrDiagMgr_GetNTCFailed_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_Sa_MtrPos2_NxtrDiagMgr_GetNTCFailed_Return
# endif
# if defined (Rte_CallHook_Sa_MtrPos2_NxtrDiagMgr_GetNTCFailed_Return)
#  undef Rte_CallHook_Sa_MtrPos2_NxtrDiagMgr_GetNTCFailed_Return
FUNC(void, RTE_APPL_CODE) Rte_CallHook_Sa_MtrPos2_NxtrDiagMgr_GetNTCFailed_Return(NTCNumber NTC_Cnt_T_enum, P2VAR(Boolean, AUTOMATIC, RTE_SA_MTRPOS2_APPL_VAR) NTCFailed_Ptr_T_lgc);
# else
#  define Rte_CallHook_Sa_MtrPos2_NxtrDiagMgr_GetNTCFailed_Return(arg1, arg2) ((void)(0))
# endif /* Rte_CallHook_Sa_MtrPos2_NxtrDiagMgr_GetNTCFailed_Return */

# if defined (Rte_CallHook_Sa_MtrPos2_NxtrDiagMgr_GetNTCFailed_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_Sa_MtrPos2_NxtrDiagMgr_GetNTCFailed_Start
# endif
# if defined (Rte_CallHook_Sa_MtrPos2_NxtrDiagMgr_GetNTCFailed_Start)
#  undef Rte_CallHook_Sa_MtrPos2_NxtrDiagMgr_GetNTCFailed_Start
FUNC(void, RTE_APPL_CODE) Rte_CallHook_Sa_MtrPos2_NxtrDiagMgr_GetNTCFailed_Start(NTCNumber NTC_Cnt_T_enum, P2VAR(Boolean, AUTOMATIC, RTE_SA_MTRPOS2_APPL_VAR) NTCFailed_Ptr_T_lgc);
# else
#  define Rte_CallHook_Sa_MtrPos2_NxtrDiagMgr_GetNTCFailed_Start(arg1, arg2) ((void)(0))
# endif /* Rte_CallHook_Sa_MtrPos2_NxtrDiagMgr_GetNTCFailed_Start */

# if defined (Rte_CallHook_Sa_MtrPos2_NxtrDiagMgr_SetNTCStatus_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_Sa_MtrPos2_NxtrDiagMgr_SetNTCStatus_Return
# endif
# if defined (Rte_CallHook_Sa_MtrPos2_NxtrDiagMgr_SetNTCStatus_Return)
#  undef Rte_CallHook_Sa_MtrPos2_NxtrDiagMgr_SetNTCStatus_Return
FUNC(void, RTE_APPL_CODE) Rte_CallHook_Sa_MtrPos2_NxtrDiagMgr_SetNTCStatus_Return(NTCNumber NTC_Cnt_T_enum, UInt8 Param_Cnt_T_u08, NxtrDiagMgrStatus Status_Cnt_T_enum);
# else
#  define Rte_CallHook_Sa_MtrPos2_NxtrDiagMgr_SetNTCStatus_Return(arg1, arg2, arg3) ((void)(0))
# endif /* Rte_CallHook_Sa_MtrPos2_NxtrDiagMgr_SetNTCStatus_Return */

# if defined (Rte_CallHook_Sa_MtrPos2_NxtrDiagMgr_SetNTCStatus_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_Sa_MtrPos2_NxtrDiagMgr_SetNTCStatus_Start
# endif
# if defined (Rte_CallHook_Sa_MtrPos2_NxtrDiagMgr_SetNTCStatus_Start)
#  undef Rte_CallHook_Sa_MtrPos2_NxtrDiagMgr_SetNTCStatus_Start
FUNC(void, RTE_APPL_CODE) Rte_CallHook_Sa_MtrPos2_NxtrDiagMgr_SetNTCStatus_Start(NTCNumber NTC_Cnt_T_enum, UInt8 Param_Cnt_T_u08, NxtrDiagMgrStatus Status_Cnt_T_enum);
# else
#  define Rte_CallHook_Sa_MtrPos2_NxtrDiagMgr_SetNTCStatus_Start(arg1, arg2, arg3) ((void)(0))
# endif /* Rte_CallHook_Sa_MtrPos2_NxtrDiagMgr_SetNTCStatus_Start */

# if defined (Rte_CallHook_Sa_MtrPos3_MtrPos3_Per2_CP1_CheckpointReached_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_Sa_MtrPos3_MtrPos3_Per2_CP1_CheckpointReached_Return
# endif
# if defined (Rte_CallHook_Sa_MtrPos3_MtrPos3_Per2_CP1_CheckpointReached_Return)
#  undef Rte_CallHook_Sa_MtrPos3_MtrPos3_Per2_CP1_CheckpointReached_Return
FUNC(void, RTE_APPL_CODE) Rte_CallHook_Sa_MtrPos3_MtrPos3_Per2_CP1_CheckpointReached_Return(void);
# else
#  define Rte_CallHook_Sa_MtrPos3_MtrPos3_Per2_CP1_CheckpointReached_Return() ((void)(0))
# endif /* Rte_CallHook_Sa_MtrPos3_MtrPos3_Per2_CP1_CheckpointReached_Return */

# if defined (Rte_CallHook_Sa_MtrPos3_MtrPos3_Per2_CP1_CheckpointReached_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_Sa_MtrPos3_MtrPos3_Per2_CP1_CheckpointReached_Start
# endif
# if defined (Rte_CallHook_Sa_MtrPos3_MtrPos3_Per2_CP1_CheckpointReached_Start)
#  undef Rte_CallHook_Sa_MtrPos3_MtrPos3_Per2_CP1_CheckpointReached_Start
FUNC(void, RTE_APPL_CODE) Rte_CallHook_Sa_MtrPos3_MtrPos3_Per2_CP1_CheckpointReached_Start(void);
# else
#  define Rte_CallHook_Sa_MtrPos3_MtrPos3_Per2_CP1_CheckpointReached_Start() ((void)(0))
# endif /* Rte_CallHook_Sa_MtrPos3_MtrPos3_Per2_CP1_CheckpointReached_Start */

# if defined (Rte_CallHook_Sa_MtrPos3_NxtrDiagMgr_SetNTCStatus_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_Sa_MtrPos3_NxtrDiagMgr_SetNTCStatus_Return
# endif
# if defined (Rte_CallHook_Sa_MtrPos3_NxtrDiagMgr_SetNTCStatus_Return)
#  undef Rte_CallHook_Sa_MtrPos3_NxtrDiagMgr_SetNTCStatus_Return
FUNC(void, RTE_APPL_CODE) Rte_CallHook_Sa_MtrPos3_NxtrDiagMgr_SetNTCStatus_Return(NTCNumber NTC_Cnt_T_enum, UInt8 Param_Cnt_T_u08, NxtrDiagMgrStatus Status_Cnt_T_enum);
# else
#  define Rte_CallHook_Sa_MtrPos3_NxtrDiagMgr_SetNTCStatus_Return(arg1, arg2, arg3) ((void)(0))
# endif /* Rte_CallHook_Sa_MtrPos3_NxtrDiagMgr_SetNTCStatus_Return */

# if defined (Rte_CallHook_Sa_MtrPos3_NxtrDiagMgr_SetNTCStatus_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_Sa_MtrPos3_NxtrDiagMgr_SetNTCStatus_Start
# endif
# if defined (Rte_CallHook_Sa_MtrPos3_NxtrDiagMgr_SetNTCStatus_Start)
#  undef Rte_CallHook_Sa_MtrPos3_NxtrDiagMgr_SetNTCStatus_Start
FUNC(void, RTE_APPL_CODE) Rte_CallHook_Sa_MtrPos3_NxtrDiagMgr_SetNTCStatus_Start(NTCNumber NTC_Cnt_T_enum, UInt8 Param_Cnt_T_u08, NxtrDiagMgrStatus Status_Cnt_T_enum);
# else
#  define Rte_CallHook_Sa_MtrPos3_NxtrDiagMgr_SetNTCStatus_Start(arg1, arg2, arg3) ((void)(0))
# endif /* Rte_CallHook_Sa_MtrPos3_NxtrDiagMgr_SetNTCStatus_Start */

# if defined (Rte_CallHook_Sa_MtrVel2_MtrVel2_Per1_CP0_CheckpointReached_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_Sa_MtrVel2_MtrVel2_Per1_CP0_CheckpointReached_Return
# endif
# if defined (Rte_CallHook_Sa_MtrVel2_MtrVel2_Per1_CP0_CheckpointReached_Return)
#  undef Rte_CallHook_Sa_MtrVel2_MtrVel2_Per1_CP0_CheckpointReached_Return
FUNC(void, RTE_APPL_CODE) Rte_CallHook_Sa_MtrVel2_MtrVel2_Per1_CP0_CheckpointReached_Return(void);
# else
#  define Rte_CallHook_Sa_MtrVel2_MtrVel2_Per1_CP0_CheckpointReached_Return() ((void)(0))
# endif /* Rte_CallHook_Sa_MtrVel2_MtrVel2_Per1_CP0_CheckpointReached_Return */

# if defined (Rte_CallHook_Sa_MtrVel2_MtrVel2_Per1_CP0_CheckpointReached_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_Sa_MtrVel2_MtrVel2_Per1_CP0_CheckpointReached_Start
# endif
# if defined (Rte_CallHook_Sa_MtrVel2_MtrVel2_Per1_CP0_CheckpointReached_Start)
#  undef Rte_CallHook_Sa_MtrVel2_MtrVel2_Per1_CP0_CheckpointReached_Start
FUNC(void, RTE_APPL_CODE) Rte_CallHook_Sa_MtrVel2_MtrVel2_Per1_CP0_CheckpointReached_Start(void);
# else
#  define Rte_CallHook_Sa_MtrVel2_MtrVel2_Per1_CP0_CheckpointReached_Start() ((void)(0))
# endif /* Rte_CallHook_Sa_MtrVel2_MtrVel2_Per1_CP0_CheckpointReached_Start */

# if defined (Rte_CallHook_Sa_MtrVel2_MtrVel2_Per2_CP0_CheckpointReached_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_Sa_MtrVel2_MtrVel2_Per2_CP0_CheckpointReached_Return
# endif
# if defined (Rte_CallHook_Sa_MtrVel2_MtrVel2_Per2_CP0_CheckpointReached_Return)
#  undef Rte_CallHook_Sa_MtrVel2_MtrVel2_Per2_CP0_CheckpointReached_Return
FUNC(void, RTE_APPL_CODE) Rte_CallHook_Sa_MtrVel2_MtrVel2_Per2_CP0_CheckpointReached_Return(void);
# else
#  define Rte_CallHook_Sa_MtrVel2_MtrVel2_Per2_CP0_CheckpointReached_Return() ((void)(0))
# endif /* Rte_CallHook_Sa_MtrVel2_MtrVel2_Per2_CP0_CheckpointReached_Return */

# if defined (Rte_CallHook_Sa_MtrVel2_MtrVel2_Per2_CP0_CheckpointReached_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_Sa_MtrVel2_MtrVel2_Per2_CP0_CheckpointReached_Start
# endif
# if defined (Rte_CallHook_Sa_MtrVel2_MtrVel2_Per2_CP0_CheckpointReached_Start)
#  undef Rte_CallHook_Sa_MtrVel2_MtrVel2_Per2_CP0_CheckpointReached_Start
FUNC(void, RTE_APPL_CODE) Rte_CallHook_Sa_MtrVel2_MtrVel2_Per2_CP0_CheckpointReached_Start(void);
# else
#  define Rte_CallHook_Sa_MtrVel2_MtrVel2_Per2_CP0_CheckpointReached_Start() ((void)(0))
# endif /* Rte_CallHook_Sa_MtrVel2_MtrVel2_Per2_CP0_CheckpointReached_Start */

# if defined (Rte_CallHook_Sa_MtrVel2_NxtrDiagMgr_SetNTCStatus_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_Sa_MtrVel2_NxtrDiagMgr_SetNTCStatus_Return
# endif
# if defined (Rte_CallHook_Sa_MtrVel2_NxtrDiagMgr_SetNTCStatus_Return)
#  undef Rte_CallHook_Sa_MtrVel2_NxtrDiagMgr_SetNTCStatus_Return
FUNC(void, RTE_APPL_CODE) Rte_CallHook_Sa_MtrVel2_NxtrDiagMgr_SetNTCStatus_Return(NTCNumber NTC_Cnt_T_enum, UInt8 Param_Cnt_T_u08, NxtrDiagMgrStatus Status_Cnt_T_enum);
# else
#  define Rte_CallHook_Sa_MtrVel2_NxtrDiagMgr_SetNTCStatus_Return(arg1, arg2, arg3) ((void)(0))
# endif /* Rte_CallHook_Sa_MtrVel2_NxtrDiagMgr_SetNTCStatus_Return */

# if defined (Rte_CallHook_Sa_MtrVel2_NxtrDiagMgr_SetNTCStatus_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_Sa_MtrVel2_NxtrDiagMgr_SetNTCStatus_Start
# endif
# if defined (Rte_CallHook_Sa_MtrVel2_NxtrDiagMgr_SetNTCStatus_Start)
#  undef Rte_CallHook_Sa_MtrVel2_NxtrDiagMgr_SetNTCStatus_Start
FUNC(void, RTE_APPL_CODE) Rte_CallHook_Sa_MtrVel2_NxtrDiagMgr_SetNTCStatus_Start(NTCNumber NTC_Cnt_T_enum, UInt8 Param_Cnt_T_u08, NxtrDiagMgrStatus Status_Cnt_T_enum);
# else
#  define Rte_CallHook_Sa_MtrVel2_NxtrDiagMgr_SetNTCStatus_Start(arg1, arg2, arg3) ((void)(0))
# endif /* Rte_CallHook_Sa_MtrVel2_NxtrDiagMgr_SetNTCStatus_Start */

# if defined (Rte_CallHook_Sa_MtrVel_MtrVel_Per1_CP0_CheckpointReached_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_Sa_MtrVel_MtrVel_Per1_CP0_CheckpointReached_Return
# endif
# if defined (Rte_CallHook_Sa_MtrVel_MtrVel_Per1_CP0_CheckpointReached_Return)
#  undef Rte_CallHook_Sa_MtrVel_MtrVel_Per1_CP0_CheckpointReached_Return
FUNC(void, RTE_APPL_CODE) Rte_CallHook_Sa_MtrVel_MtrVel_Per1_CP0_CheckpointReached_Return(void);
# else
#  define Rte_CallHook_Sa_MtrVel_MtrVel_Per1_CP0_CheckpointReached_Return() ((void)(0))
# endif /* Rte_CallHook_Sa_MtrVel_MtrVel_Per1_CP0_CheckpointReached_Return */

# if defined (Rte_CallHook_Sa_MtrVel_MtrVel_Per1_CP0_CheckpointReached_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_Sa_MtrVel_MtrVel_Per1_CP0_CheckpointReached_Start
# endif
# if defined (Rte_CallHook_Sa_MtrVel_MtrVel_Per1_CP0_CheckpointReached_Start)
#  undef Rte_CallHook_Sa_MtrVel_MtrVel_Per1_CP0_CheckpointReached_Start
FUNC(void, RTE_APPL_CODE) Rte_CallHook_Sa_MtrVel_MtrVel_Per1_CP0_CheckpointReached_Start(void);
# else
#  define Rte_CallHook_Sa_MtrVel_MtrVel_Per1_CP0_CheckpointReached_Start() ((void)(0))
# endif /* Rte_CallHook_Sa_MtrVel_MtrVel_Per1_CP0_CheckpointReached_Start */

# if defined (Rte_CallHook_Sa_MtrVel_NxtrDiagMgr_GetNTCFailed_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_Sa_MtrVel_NxtrDiagMgr_GetNTCFailed_Return
# endif
# if defined (Rte_CallHook_Sa_MtrVel_NxtrDiagMgr_GetNTCFailed_Return)
#  undef Rte_CallHook_Sa_MtrVel_NxtrDiagMgr_GetNTCFailed_Return
FUNC(void, RTE_APPL_CODE) Rte_CallHook_Sa_MtrVel_NxtrDiagMgr_GetNTCFailed_Return(NTCNumber NTC_Cnt_T_enum, P2VAR(Boolean, AUTOMATIC, RTE_SA_MTRVEL_APPL_VAR) NTCFailed_Ptr_T_lgc);
# else
#  define Rte_CallHook_Sa_MtrVel_NxtrDiagMgr_GetNTCFailed_Return(arg1, arg2) ((void)(0))
# endif /* Rte_CallHook_Sa_MtrVel_NxtrDiagMgr_GetNTCFailed_Return */

# if defined (Rte_CallHook_Sa_MtrVel_NxtrDiagMgr_GetNTCFailed_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_Sa_MtrVel_NxtrDiagMgr_GetNTCFailed_Start
# endif
# if defined (Rte_CallHook_Sa_MtrVel_NxtrDiagMgr_GetNTCFailed_Start)
#  undef Rte_CallHook_Sa_MtrVel_NxtrDiagMgr_GetNTCFailed_Start
FUNC(void, RTE_APPL_CODE) Rte_CallHook_Sa_MtrVel_NxtrDiagMgr_GetNTCFailed_Start(NTCNumber NTC_Cnt_T_enum, P2VAR(Boolean, AUTOMATIC, RTE_SA_MTRVEL_APPL_VAR) NTCFailed_Ptr_T_lgc);
# else
#  define Rte_CallHook_Sa_MtrVel_NxtrDiagMgr_GetNTCFailed_Start(arg1, arg2) ((void)(0))
# endif /* Rte_CallHook_Sa_MtrVel_NxtrDiagMgr_GetNTCFailed_Start */

# if defined (Rte_CallHook_Sa_MtrVel_NxtrDiagMgr_SetNTCStatus_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_Sa_MtrVel_NxtrDiagMgr_SetNTCStatus_Return
# endif
# if defined (Rte_CallHook_Sa_MtrVel_NxtrDiagMgr_SetNTCStatus_Return)
#  undef Rte_CallHook_Sa_MtrVel_NxtrDiagMgr_SetNTCStatus_Return
FUNC(void, RTE_APPL_CODE) Rte_CallHook_Sa_MtrVel_NxtrDiagMgr_SetNTCStatus_Return(NTCNumber NTC_Cnt_T_enum, UInt8 Param_Cnt_T_u08, NxtrDiagMgrStatus Status_Cnt_T_enum);
# else
#  define Rte_CallHook_Sa_MtrVel_NxtrDiagMgr_SetNTCStatus_Return(arg1, arg2, arg3) ((void)(0))
# endif /* Rte_CallHook_Sa_MtrVel_NxtrDiagMgr_SetNTCStatus_Return */

# if defined (Rte_CallHook_Sa_MtrVel_NxtrDiagMgr_SetNTCStatus_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_Sa_MtrVel_NxtrDiagMgr_SetNTCStatus_Start
# endif
# if defined (Rte_CallHook_Sa_MtrVel_NxtrDiagMgr_SetNTCStatus_Start)
#  undef Rte_CallHook_Sa_MtrVel_NxtrDiagMgr_SetNTCStatus_Start
FUNC(void, RTE_APPL_CODE) Rte_CallHook_Sa_MtrVel_NxtrDiagMgr_SetNTCStatus_Start(NTCNumber NTC_Cnt_T_enum, UInt8 Param_Cnt_T_u08, NxtrDiagMgrStatus Status_Cnt_T_enum);
# else
#  define Rte_CallHook_Sa_MtrVel_NxtrDiagMgr_SetNTCStatus_Start(arg1, arg2, arg3) ((void)(0))
# endif /* Rte_CallHook_Sa_MtrVel_NxtrDiagMgr_SetNTCStatus_Start */

# if defined (Rte_CallHook_Sa_OvrVoltMon_NxtrDiagMgr_SetNTCStatus_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_Sa_OvrVoltMon_NxtrDiagMgr_SetNTCStatus_Return
# endif
# if defined (Rte_CallHook_Sa_OvrVoltMon_NxtrDiagMgr_SetNTCStatus_Return)
#  undef Rte_CallHook_Sa_OvrVoltMon_NxtrDiagMgr_SetNTCStatus_Return
FUNC(void, RTE_APPL_CODE) Rte_CallHook_Sa_OvrVoltMon_NxtrDiagMgr_SetNTCStatus_Return(NTCNumber NTC_Cnt_T_enum, UInt8 Param_Cnt_T_u08, NxtrDiagMgrStatus Status_Cnt_T_enum);
# else
#  define Rte_CallHook_Sa_OvrVoltMon_NxtrDiagMgr_SetNTCStatus_Return(arg1, arg2, arg3) ((void)(0))
# endif /* Rte_CallHook_Sa_OvrVoltMon_NxtrDiagMgr_SetNTCStatus_Return */

# if defined (Rte_CallHook_Sa_OvrVoltMon_NxtrDiagMgr_SetNTCStatus_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_Sa_OvrVoltMon_NxtrDiagMgr_SetNTCStatus_Start
# endif
# if defined (Rte_CallHook_Sa_OvrVoltMon_NxtrDiagMgr_SetNTCStatus_Start)
#  undef Rte_CallHook_Sa_OvrVoltMon_NxtrDiagMgr_SetNTCStatus_Start
FUNC(void, RTE_APPL_CODE) Rte_CallHook_Sa_OvrVoltMon_NxtrDiagMgr_SetNTCStatus_Start(NTCNumber NTC_Cnt_T_enum, UInt8 Param_Cnt_T_u08, NxtrDiagMgrStatus Status_Cnt_T_enum);
# else
#  define Rte_CallHook_Sa_OvrVoltMon_NxtrDiagMgr_SetNTCStatus_Start(arg1, arg2, arg3) ((void)(0))
# endif /* Rte_CallHook_Sa_OvrVoltMon_NxtrDiagMgr_SetNTCStatus_Start */

# if defined (Rte_CallHook_Sa_OvrVoltMon_phyOvrVoltFdbk_OP_GET_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_Sa_OvrVoltMon_phyOvrVoltFdbk_OP_GET_Return
# endif
# if defined (Rte_CallHook_Sa_OvrVoltMon_phyOvrVoltFdbk_OP_GET_Return)
#  undef Rte_CallHook_Sa_OvrVoltMon_phyOvrVoltFdbk_OP_GET_Return
FUNC(void, RTE_APPL_CODE) Rte_CallHook_Sa_OvrVoltMon_phyOvrVoltFdbk_OP_GET_Return(P2VAR(IoHwAb_BoolType, AUTOMATIC, RTE_SA_OVRVOLTMON_APPL_VAR) signal);
# else
#  define Rte_CallHook_Sa_OvrVoltMon_phyOvrVoltFdbk_OP_GET_Return(arg1) ((void)(0))
# endif /* Rte_CallHook_Sa_OvrVoltMon_phyOvrVoltFdbk_OP_GET_Return */

# if defined (Rte_CallHook_Sa_OvrVoltMon_phyOvrVoltFdbk_OP_GET_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_Sa_OvrVoltMon_phyOvrVoltFdbk_OP_GET_Start
# endif
# if defined (Rte_CallHook_Sa_OvrVoltMon_phyOvrVoltFdbk_OP_GET_Start)
#  undef Rte_CallHook_Sa_OvrVoltMon_phyOvrVoltFdbk_OP_GET_Start
FUNC(void, RTE_APPL_CODE) Rte_CallHook_Sa_OvrVoltMon_phyOvrVoltFdbk_OP_GET_Start(P2VAR(IoHwAb_BoolType, AUTOMATIC, RTE_SA_OVRVOLTMON_APPL_VAR) signal);
# else
#  define Rte_CallHook_Sa_OvrVoltMon_phyOvrVoltFdbk_OP_GET_Start(arg1) ((void)(0))
# endif /* Rte_CallHook_Sa_OvrVoltMon_phyOvrVoltFdbk_OP_GET_Start */

# if defined (Rte_CallHook_Sa_ShtdnMech_FetDrvReset_OP_GET_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_Sa_ShtdnMech_FetDrvReset_OP_GET_Return
# endif
# if defined (Rte_CallHook_Sa_ShtdnMech_FetDrvReset_OP_GET_Return)
#  undef Rte_CallHook_Sa_ShtdnMech_FetDrvReset_OP_GET_Return
FUNC(void, RTE_APPL_CODE) Rte_CallHook_Sa_ShtdnMech_FetDrvReset_OP_GET_Return(P2VAR(IoHwAb_BoolType, AUTOMATIC, RTE_SA_SHTDNMECH_APPL_VAR) signal);
# else
#  define Rte_CallHook_Sa_ShtdnMech_FetDrvReset_OP_GET_Return(arg1) ((void)(0))
# endif /* Rte_CallHook_Sa_ShtdnMech_FetDrvReset_OP_GET_Return */

# if defined (Rte_CallHook_Sa_ShtdnMech_FetDrvReset_OP_GET_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_Sa_ShtdnMech_FetDrvReset_OP_GET_Start
# endif
# if defined (Rte_CallHook_Sa_ShtdnMech_FetDrvReset_OP_GET_Start)
#  undef Rte_CallHook_Sa_ShtdnMech_FetDrvReset_OP_GET_Start
FUNC(void, RTE_APPL_CODE) Rte_CallHook_Sa_ShtdnMech_FetDrvReset_OP_GET_Start(P2VAR(IoHwAb_BoolType, AUTOMATIC, RTE_SA_SHTDNMECH_APPL_VAR) signal);
# else
#  define Rte_CallHook_Sa_ShtdnMech_FetDrvReset_OP_GET_Start(arg1) ((void)(0))
# endif /* Rte_CallHook_Sa_ShtdnMech_FetDrvReset_OP_GET_Start */

# if defined (Rte_CallHook_Sa_ShtdnMech_SysFault2_OP_GET_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_Sa_ShtdnMech_SysFault2_OP_GET_Return
# endif
# if defined (Rte_CallHook_Sa_ShtdnMech_SysFault2_OP_GET_Return)
#  undef Rte_CallHook_Sa_ShtdnMech_SysFault2_OP_GET_Return
FUNC(void, RTE_APPL_CODE) Rte_CallHook_Sa_ShtdnMech_SysFault2_OP_GET_Return(P2VAR(IoHwAb_BoolType, AUTOMATIC, RTE_SA_SHTDNMECH_APPL_VAR) signal);
# else
#  define Rte_CallHook_Sa_ShtdnMech_SysFault2_OP_GET_Return(arg1) ((void)(0))
# endif /* Rte_CallHook_Sa_ShtdnMech_SysFault2_OP_GET_Return */

# if defined (Rte_CallHook_Sa_ShtdnMech_SysFault2_OP_GET_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_Sa_ShtdnMech_SysFault2_OP_GET_Start
# endif
# if defined (Rte_CallHook_Sa_ShtdnMech_SysFault2_OP_GET_Start)
#  undef Rte_CallHook_Sa_ShtdnMech_SysFault2_OP_GET_Start
FUNC(void, RTE_APPL_CODE) Rte_CallHook_Sa_ShtdnMech_SysFault2_OP_GET_Start(P2VAR(IoHwAb_BoolType, AUTOMATIC, RTE_SA_SHTDNMECH_APPL_VAR) signal);
# else
#  define Rte_CallHook_Sa_ShtdnMech_SysFault2_OP_GET_Start(arg1) ((void)(0))
# endif /* Rte_CallHook_Sa_ShtdnMech_SysFault2_OP_GET_Start */

# if defined (Rte_CallHook_Sa_ShtdnMech_SysFault3_OP_GET_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_Sa_ShtdnMech_SysFault3_OP_GET_Return
# endif
# if defined (Rte_CallHook_Sa_ShtdnMech_SysFault3_OP_GET_Return)
#  undef Rte_CallHook_Sa_ShtdnMech_SysFault3_OP_GET_Return
FUNC(void, RTE_APPL_CODE) Rte_CallHook_Sa_ShtdnMech_SysFault3_OP_GET_Return(P2VAR(IoHwAb_BoolType, AUTOMATIC, RTE_SA_SHTDNMECH_APPL_VAR) signal);
# else
#  define Rte_CallHook_Sa_ShtdnMech_SysFault3_OP_GET_Return(arg1) ((void)(0))
# endif /* Rte_CallHook_Sa_ShtdnMech_SysFault3_OP_GET_Return */

# if defined (Rte_CallHook_Sa_ShtdnMech_SysFault3_OP_GET_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_Sa_ShtdnMech_SysFault3_OP_GET_Start
# endif
# if defined (Rte_CallHook_Sa_ShtdnMech_SysFault3_OP_GET_Start)
#  undef Rte_CallHook_Sa_ShtdnMech_SysFault3_OP_GET_Start
FUNC(void, RTE_APPL_CODE) Rte_CallHook_Sa_ShtdnMech_SysFault3_OP_GET_Start(P2VAR(IoHwAb_BoolType, AUTOMATIC, RTE_SA_SHTDNMECH_APPL_VAR) signal);
# else
#  define Rte_CallHook_Sa_ShtdnMech_SysFault3_OP_GET_Start(arg1) ((void)(0))
# endif /* Rte_CallHook_Sa_ShtdnMech_SysFault3_OP_GET_Start */

# if defined (Rte_CallHook_Sa_TmprlMon2_TmprlMon2_Per1_CP1_CheckpointReached_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_Sa_TmprlMon2_TmprlMon2_Per1_CP1_CheckpointReached_Return
# endif
# if defined (Rte_CallHook_Sa_TmprlMon2_TmprlMon2_Per1_CP1_CheckpointReached_Return)
#  undef Rte_CallHook_Sa_TmprlMon2_TmprlMon2_Per1_CP1_CheckpointReached_Return
FUNC(void, RTE_APPL_CODE) Rte_CallHook_Sa_TmprlMon2_TmprlMon2_Per1_CP1_CheckpointReached_Return(void);
# else
#  define Rte_CallHook_Sa_TmprlMon2_TmprlMon2_Per1_CP1_CheckpointReached_Return() ((void)(0))
# endif /* Rte_CallHook_Sa_TmprlMon2_TmprlMon2_Per1_CP1_CheckpointReached_Return */

# if defined (Rte_CallHook_Sa_TmprlMon2_TmprlMon2_Per1_CP1_CheckpointReached_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_Sa_TmprlMon2_TmprlMon2_Per1_CP1_CheckpointReached_Start
# endif
# if defined (Rte_CallHook_Sa_TmprlMon2_TmprlMon2_Per1_CP1_CheckpointReached_Start)
#  undef Rte_CallHook_Sa_TmprlMon2_TmprlMon2_Per1_CP1_CheckpointReached_Start
FUNC(void, RTE_APPL_CODE) Rte_CallHook_Sa_TmprlMon2_TmprlMon2_Per1_CP1_CheckpointReached_Start(void);
# else
#  define Rte_CallHook_Sa_TmprlMon2_TmprlMon2_Per1_CP1_CheckpointReached_Start() ((void)(0))
# endif /* Rte_CallHook_Sa_TmprlMon2_TmprlMon2_Per1_CP1_CheckpointReached_Start */

# if defined (Rte_CallHook_Sa_TmprlMon2_WdMonitor_OP_SET_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_Sa_TmprlMon2_WdMonitor_OP_SET_Return
# endif
# if defined (Rte_CallHook_Sa_TmprlMon2_WdMonitor_OP_SET_Return)
#  undef Rte_CallHook_Sa_TmprlMon2_WdMonitor_OP_SET_Return
FUNC(void, RTE_APPL_CODE) Rte_CallHook_Sa_TmprlMon2_WdMonitor_OP_SET_Return(IoHwAb_BoolType signal);
# else
#  define Rte_CallHook_Sa_TmprlMon2_WdMonitor_OP_SET_Return(arg1) ((void)(0))
# endif /* Rte_CallHook_Sa_TmprlMon2_WdMonitor_OP_SET_Return */

# if defined (Rte_CallHook_Sa_TmprlMon2_WdMonitor_OP_SET_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_Sa_TmprlMon2_WdMonitor_OP_SET_Start
# endif
# if defined (Rte_CallHook_Sa_TmprlMon2_WdMonitor_OP_SET_Start)
#  undef Rte_CallHook_Sa_TmprlMon2_WdMonitor_OP_SET_Start
FUNC(void, RTE_APPL_CODE) Rte_CallHook_Sa_TmprlMon2_WdMonitor_OP_SET_Start(IoHwAb_BoolType signal);
# else
#  define Rte_CallHook_Sa_TmprlMon2_WdMonitor_OP_SET_Start(arg1) ((void)(0))
# endif /* Rte_CallHook_Sa_TmprlMon2_WdMonitor_OP_SET_Start */

# if defined (Rte_CallHook_Sa_TmprlMon_FetDrvCntl_OP_GET_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_Sa_TmprlMon_FetDrvCntl_OP_GET_Return
# endif
# if defined (Rte_CallHook_Sa_TmprlMon_FetDrvCntl_OP_GET_Return)
#  undef Rte_CallHook_Sa_TmprlMon_FetDrvCntl_OP_GET_Return
FUNC(void, RTE_APPL_CODE) Rte_CallHook_Sa_TmprlMon_FetDrvCntl_OP_GET_Return(P2VAR(IoHwAb_BoolType, AUTOMATIC, RTE_SA_TMPRLMON_APPL_VAR) signal);
# else
#  define Rte_CallHook_Sa_TmprlMon_FetDrvCntl_OP_GET_Return(arg1) ((void)(0))
# endif /* Rte_CallHook_Sa_TmprlMon_FetDrvCntl_OP_GET_Return */

# if defined (Rte_CallHook_Sa_TmprlMon_FetDrvCntl_OP_GET_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_Sa_TmprlMon_FetDrvCntl_OP_GET_Start
# endif
# if defined (Rte_CallHook_Sa_TmprlMon_FetDrvCntl_OP_GET_Start)
#  undef Rte_CallHook_Sa_TmprlMon_FetDrvCntl_OP_GET_Start
FUNC(void, RTE_APPL_CODE) Rte_CallHook_Sa_TmprlMon_FetDrvCntl_OP_GET_Start(P2VAR(IoHwAb_BoolType, AUTOMATIC, RTE_SA_TMPRLMON_APPL_VAR) signal);
# else
#  define Rte_CallHook_Sa_TmprlMon_FetDrvCntl_OP_GET_Start(arg1) ((void)(0))
# endif /* Rte_CallHook_Sa_TmprlMon_FetDrvCntl_OP_GET_Start */

# if defined (Rte_CallHook_Sa_TmprlMon_NxtrDiagMgr_SetNTCStatus_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_Sa_TmprlMon_NxtrDiagMgr_SetNTCStatus_Return
# endif
# if defined (Rte_CallHook_Sa_TmprlMon_NxtrDiagMgr_SetNTCStatus_Return)
#  undef Rte_CallHook_Sa_TmprlMon_NxtrDiagMgr_SetNTCStatus_Return
FUNC(void, RTE_APPL_CODE) Rte_CallHook_Sa_TmprlMon_NxtrDiagMgr_SetNTCStatus_Return(NTCNumber NTC_Cnt_T_enum, UInt8 Param_Cnt_T_u08, NxtrDiagMgrStatus Status_Cnt_T_enum);
# else
#  define Rte_CallHook_Sa_TmprlMon_NxtrDiagMgr_SetNTCStatus_Return(arg1, arg2, arg3) ((void)(0))
# endif /* Rte_CallHook_Sa_TmprlMon_NxtrDiagMgr_SetNTCStatus_Return */

# if defined (Rte_CallHook_Sa_TmprlMon_NxtrDiagMgr_SetNTCStatus_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_Sa_TmprlMon_NxtrDiagMgr_SetNTCStatus_Start
# endif
# if defined (Rte_CallHook_Sa_TmprlMon_NxtrDiagMgr_SetNTCStatus_Start)
#  undef Rte_CallHook_Sa_TmprlMon_NxtrDiagMgr_SetNTCStatus_Start
FUNC(void, RTE_APPL_CODE) Rte_CallHook_Sa_TmprlMon_NxtrDiagMgr_SetNTCStatus_Start(NTCNumber NTC_Cnt_T_enum, UInt8 Param_Cnt_T_u08, NxtrDiagMgrStatus Status_Cnt_T_enum);
# else
#  define Rte_CallHook_Sa_TmprlMon_NxtrDiagMgr_SetNTCStatus_Start(arg1, arg2, arg3) ((void)(0))
# endif /* Rte_CallHook_Sa_TmprlMon_NxtrDiagMgr_SetNTCStatus_Start */

# if defined (Rte_CallHook_Sa_TmprlMon_PwrSwitchEn_OP_GET_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_Sa_TmprlMon_PwrSwitchEn_OP_GET_Return
# endif
# if defined (Rte_CallHook_Sa_TmprlMon_PwrSwitchEn_OP_GET_Return)
#  undef Rte_CallHook_Sa_TmprlMon_PwrSwitchEn_OP_GET_Return
FUNC(void, RTE_APPL_CODE) Rte_CallHook_Sa_TmprlMon_PwrSwitchEn_OP_GET_Return(P2VAR(IoHwAb_BoolType, AUTOMATIC, RTE_SA_TMPRLMON_APPL_VAR) signal);
# else
#  define Rte_CallHook_Sa_TmprlMon_PwrSwitchEn_OP_GET_Return(arg1) ((void)(0))
# endif /* Rte_CallHook_Sa_TmprlMon_PwrSwitchEn_OP_GET_Return */

# if defined (Rte_CallHook_Sa_TmprlMon_PwrSwitchEn_OP_GET_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_Sa_TmprlMon_PwrSwitchEn_OP_GET_Start
# endif
# if defined (Rte_CallHook_Sa_TmprlMon_PwrSwitchEn_OP_GET_Start)
#  undef Rte_CallHook_Sa_TmprlMon_PwrSwitchEn_OP_GET_Start
FUNC(void, RTE_APPL_CODE) Rte_CallHook_Sa_TmprlMon_PwrSwitchEn_OP_GET_Start(P2VAR(IoHwAb_BoolType, AUTOMATIC, RTE_SA_TMPRLMON_APPL_VAR) signal);
# else
#  define Rte_CallHook_Sa_TmprlMon_PwrSwitchEn_OP_GET_Start(arg1) ((void)(0))
# endif /* Rte_CallHook_Sa_TmprlMon_PwrSwitchEn_OP_GET_Start */

# if defined (Rte_CallHook_Sa_TmprlMon_SysFault2_OP_GET_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_Sa_TmprlMon_SysFault2_OP_GET_Return
# endif
# if defined (Rte_CallHook_Sa_TmprlMon_SysFault2_OP_GET_Return)
#  undef Rte_CallHook_Sa_TmprlMon_SysFault2_OP_GET_Return
FUNC(void, RTE_APPL_CODE) Rte_CallHook_Sa_TmprlMon_SysFault2_OP_GET_Return(P2VAR(IoHwAb_BoolType, AUTOMATIC, RTE_SA_TMPRLMON_APPL_VAR) signal);
# else
#  define Rte_CallHook_Sa_TmprlMon_SysFault2_OP_GET_Return(arg1) ((void)(0))
# endif /* Rte_CallHook_Sa_TmprlMon_SysFault2_OP_GET_Return */

# if defined (Rte_CallHook_Sa_TmprlMon_SysFault2_OP_GET_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_Sa_TmprlMon_SysFault2_OP_GET_Start
# endif
# if defined (Rte_CallHook_Sa_TmprlMon_SysFault2_OP_GET_Start)
#  undef Rte_CallHook_Sa_TmprlMon_SysFault2_OP_GET_Start
FUNC(void, RTE_APPL_CODE) Rte_CallHook_Sa_TmprlMon_SysFault2_OP_GET_Start(P2VAR(IoHwAb_BoolType, AUTOMATIC, RTE_SA_TMPRLMON_APPL_VAR) signal);
# else
#  define Rte_CallHook_Sa_TmprlMon_SysFault2_OP_GET_Start(arg1) ((void)(0))
# endif /* Rte_CallHook_Sa_TmprlMon_SysFault2_OP_GET_Start */

# if defined (Rte_CallHook_Sa_TmprlMon_SysFault2_OP_SET_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_Sa_TmprlMon_SysFault2_OP_SET_Return
# endif
# if defined (Rte_CallHook_Sa_TmprlMon_SysFault2_OP_SET_Return)
#  undef Rte_CallHook_Sa_TmprlMon_SysFault2_OP_SET_Return
FUNC(void, RTE_APPL_CODE) Rte_CallHook_Sa_TmprlMon_SysFault2_OP_SET_Return(IoHwAb_BoolType signal);
# else
#  define Rte_CallHook_Sa_TmprlMon_SysFault2_OP_SET_Return(arg1) ((void)(0))
# endif /* Rte_CallHook_Sa_TmprlMon_SysFault2_OP_SET_Return */

# if defined (Rte_CallHook_Sa_TmprlMon_SysFault2_OP_SET_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_Sa_TmprlMon_SysFault2_OP_SET_Start
# endif
# if defined (Rte_CallHook_Sa_TmprlMon_SysFault2_OP_SET_Start)
#  undef Rte_CallHook_Sa_TmprlMon_SysFault2_OP_SET_Start
FUNC(void, RTE_APPL_CODE) Rte_CallHook_Sa_TmprlMon_SysFault2_OP_SET_Start(IoHwAb_BoolType signal);
# else
#  define Rte_CallHook_Sa_TmprlMon_SysFault2_OP_SET_Start(arg1) ((void)(0))
# endif /* Rte_CallHook_Sa_TmprlMon_SysFault2_OP_SET_Start */

# if defined (Rte_CallHook_Sa_TmprlMon_SysFault3_OP_GET_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_Sa_TmprlMon_SysFault3_OP_GET_Return
# endif
# if defined (Rte_CallHook_Sa_TmprlMon_SysFault3_OP_GET_Return)
#  undef Rte_CallHook_Sa_TmprlMon_SysFault3_OP_GET_Return
FUNC(void, RTE_APPL_CODE) Rte_CallHook_Sa_TmprlMon_SysFault3_OP_GET_Return(P2VAR(IoHwAb_BoolType, AUTOMATIC, RTE_SA_TMPRLMON_APPL_VAR) signal);
# else
#  define Rte_CallHook_Sa_TmprlMon_SysFault3_OP_GET_Return(arg1) ((void)(0))
# endif /* Rte_CallHook_Sa_TmprlMon_SysFault3_OP_GET_Return */

# if defined (Rte_CallHook_Sa_TmprlMon_SysFault3_OP_GET_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_Sa_TmprlMon_SysFault3_OP_GET_Start
# endif
# if defined (Rte_CallHook_Sa_TmprlMon_SysFault3_OP_GET_Start)
#  undef Rte_CallHook_Sa_TmprlMon_SysFault3_OP_GET_Start
FUNC(void, RTE_APPL_CODE) Rte_CallHook_Sa_TmprlMon_SysFault3_OP_GET_Start(P2VAR(IoHwAb_BoolType, AUTOMATIC, RTE_SA_TMPRLMON_APPL_VAR) signal);
# else
#  define Rte_CallHook_Sa_TmprlMon_SysFault3_OP_GET_Start(arg1) ((void)(0))
# endif /* Rte_CallHook_Sa_TmprlMon_SysFault3_OP_GET_Start */

# if defined (Rte_CallHook_Sa_TmprlMon_SysFault3_OP_SET_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_Sa_TmprlMon_SysFault3_OP_SET_Return
# endif
# if defined (Rte_CallHook_Sa_TmprlMon_SysFault3_OP_SET_Return)
#  undef Rte_CallHook_Sa_TmprlMon_SysFault3_OP_SET_Return
FUNC(void, RTE_APPL_CODE) Rte_CallHook_Sa_TmprlMon_SysFault3_OP_SET_Return(IoHwAb_BoolType signal);
# else
#  define Rte_CallHook_Sa_TmprlMon_SysFault3_OP_SET_Return(arg1) ((void)(0))
# endif /* Rte_CallHook_Sa_TmprlMon_SysFault3_OP_SET_Return */

# if defined (Rte_CallHook_Sa_TmprlMon_SysFault3_OP_SET_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_Sa_TmprlMon_SysFault3_OP_SET_Start
# endif
# if defined (Rte_CallHook_Sa_TmprlMon_SysFault3_OP_SET_Start)
#  undef Rte_CallHook_Sa_TmprlMon_SysFault3_OP_SET_Start
FUNC(void, RTE_APPL_CODE) Rte_CallHook_Sa_TmprlMon_SysFault3_OP_SET_Start(IoHwAb_BoolType signal);
# else
#  define Rte_CallHook_Sa_TmprlMon_SysFault3_OP_SET_Start(arg1) ((void)(0))
# endif /* Rte_CallHook_Sa_TmprlMon_SysFault3_OP_SET_Start */

# if defined (Rte_CallHook_Sa_TmprlMon_SystemTime_DtrmnElapsedTime_mS_u16_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_Sa_TmprlMon_SystemTime_DtrmnElapsedTime_mS_u16_Return
# endif
# if defined (Rte_CallHook_Sa_TmprlMon_SystemTime_DtrmnElapsedTime_mS_u16_Return)
#  undef Rte_CallHook_Sa_TmprlMon_SystemTime_DtrmnElapsedTime_mS_u16_Return
FUNC(void, RTE_APPL_CODE) Rte_CallHook_Sa_TmprlMon_SystemTime_DtrmnElapsedTime_mS_u16_Return(UInt32 InitialTime, P2VAR(UInt16, AUTOMATIC, RTE_SA_TMPRLMON_APPL_VAR) ElapsedTime);
# else
#  define Rte_CallHook_Sa_TmprlMon_SystemTime_DtrmnElapsedTime_mS_u16_Return(arg1, arg2) ((void)(0))
# endif /* Rte_CallHook_Sa_TmprlMon_SystemTime_DtrmnElapsedTime_mS_u16_Return */

# if defined (Rte_CallHook_Sa_TmprlMon_SystemTime_DtrmnElapsedTime_mS_u16_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_Sa_TmprlMon_SystemTime_DtrmnElapsedTime_mS_u16_Start
# endif
# if defined (Rte_CallHook_Sa_TmprlMon_SystemTime_DtrmnElapsedTime_mS_u16_Start)
#  undef Rte_CallHook_Sa_TmprlMon_SystemTime_DtrmnElapsedTime_mS_u16_Start
FUNC(void, RTE_APPL_CODE) Rte_CallHook_Sa_TmprlMon_SystemTime_DtrmnElapsedTime_mS_u16_Start(UInt32 InitialTime, P2VAR(UInt16, AUTOMATIC, RTE_SA_TMPRLMON_APPL_VAR) ElapsedTime);
# else
#  define Rte_CallHook_Sa_TmprlMon_SystemTime_DtrmnElapsedTime_mS_u16_Start(arg1, arg2) ((void)(0))
# endif /* Rte_CallHook_Sa_TmprlMon_SystemTime_DtrmnElapsedTime_mS_u16_Start */

# if defined (Rte_CallHook_Sa_TmprlMon_SystemTime_GetSystemTime_mS_u32_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_Sa_TmprlMon_SystemTime_GetSystemTime_mS_u32_Return
# endif
# if defined (Rte_CallHook_Sa_TmprlMon_SystemTime_GetSystemTime_mS_u32_Return)
#  undef Rte_CallHook_Sa_TmprlMon_SystemTime_GetSystemTime_mS_u32_Return
FUNC(void, RTE_APPL_CODE) Rte_CallHook_Sa_TmprlMon_SystemTime_GetSystemTime_mS_u32_Return(P2VAR(UInt32, AUTOMATIC, RTE_SA_TMPRLMON_APPL_VAR) CurrentTime);
# else
#  define Rte_CallHook_Sa_TmprlMon_SystemTime_GetSystemTime_mS_u32_Return(arg1) ((void)(0))
# endif /* Rte_CallHook_Sa_TmprlMon_SystemTime_GetSystemTime_mS_u32_Return */

# if defined (Rte_CallHook_Sa_TmprlMon_SystemTime_GetSystemTime_mS_u32_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_Sa_TmprlMon_SystemTime_GetSystemTime_mS_u32_Start
# endif
# if defined (Rte_CallHook_Sa_TmprlMon_SystemTime_GetSystemTime_mS_u32_Start)
#  undef Rte_CallHook_Sa_TmprlMon_SystemTime_GetSystemTime_mS_u32_Start
FUNC(void, RTE_APPL_CODE) Rte_CallHook_Sa_TmprlMon_SystemTime_GetSystemTime_mS_u32_Start(P2VAR(UInt32, AUTOMATIC, RTE_SA_TMPRLMON_APPL_VAR) CurrentTime);
# else
#  define Rte_CallHook_Sa_TmprlMon_SystemTime_GetSystemTime_mS_u32_Start(arg1) ((void)(0))
# endif /* Rte_CallHook_Sa_TmprlMon_SystemTime_GetSystemTime_mS_u32_Start */

# if defined (Rte_CallHook_Sa_TmprlMon_WdMonitor_OP_SET_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_Sa_TmprlMon_WdMonitor_OP_SET_Return
# endif
# if defined (Rte_CallHook_Sa_TmprlMon_WdMonitor_OP_SET_Return)
#  undef Rte_CallHook_Sa_TmprlMon_WdMonitor_OP_SET_Return
FUNC(void, RTE_APPL_CODE) Rte_CallHook_Sa_TmprlMon_WdMonitor_OP_SET_Return(IoHwAb_BoolType signal);
# else
#  define Rte_CallHook_Sa_TmprlMon_WdMonitor_OP_SET_Return(arg1) ((void)(0))
# endif /* Rte_CallHook_Sa_TmprlMon_WdMonitor_OP_SET_Return */

# if defined (Rte_CallHook_Sa_TmprlMon_WdMonitor_OP_SET_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_Sa_TmprlMon_WdMonitor_OP_SET_Start
# endif
# if defined (Rte_CallHook_Sa_TmprlMon_WdMonitor_OP_SET_Start)
#  undef Rte_CallHook_Sa_TmprlMon_WdMonitor_OP_SET_Start
FUNC(void, RTE_APPL_CODE) Rte_CallHook_Sa_TmprlMon_WdMonitor_OP_SET_Start(IoHwAb_BoolType signal);
# else
#  define Rte_CallHook_Sa_TmprlMon_WdMonitor_OP_SET_Start(arg1) ((void)(0))
# endif /* Rte_CallHook_Sa_TmprlMon_WdMonitor_OP_SET_Start */

# if defined (Rte_CallHook_Sa_TmprlMon_WdReset_OP_SET_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_Sa_TmprlMon_WdReset_OP_SET_Return
# endif
# if defined (Rte_CallHook_Sa_TmprlMon_WdReset_OP_SET_Return)
#  undef Rte_CallHook_Sa_TmprlMon_WdReset_OP_SET_Return
FUNC(void, RTE_APPL_CODE) Rte_CallHook_Sa_TmprlMon_WdReset_OP_SET_Return(IoHwAb_BoolType signal);
# else
#  define Rte_CallHook_Sa_TmprlMon_WdReset_OP_SET_Return(arg1) ((void)(0))
# endif /* Rte_CallHook_Sa_TmprlMon_WdReset_OP_SET_Return */

# if defined (Rte_CallHook_Sa_TmprlMon_WdReset_OP_SET_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_Sa_TmprlMon_WdReset_OP_SET_Start
# endif
# if defined (Rte_CallHook_Sa_TmprlMon_WdReset_OP_SET_Start)
#  undef Rte_CallHook_Sa_TmprlMon_WdReset_OP_SET_Start
FUNC(void, RTE_APPL_CODE) Rte_CallHook_Sa_TmprlMon_WdReset_OP_SET_Start(IoHwAb_BoolType signal);
# else
#  define Rte_CallHook_Sa_TmprlMon_WdReset_OP_SET_Start(arg1) ((void)(0))
# endif /* Rte_CallHook_Sa_TmprlMon_WdReset_OP_SET_Start */

# if defined (Rte_EnterHook_Ap_StaMd8_StaMds8_MilestoneRqst_WARMINIT_ExclArea_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_EnterHook_Ap_StaMd8_StaMds8_MilestoneRqst_WARMINIT_ExclArea_Return
# endif
# if defined (Rte_EnterHook_Ap_StaMd8_StaMds8_MilestoneRqst_WARMINIT_ExclArea_Return)
#  undef Rte_EnterHook_Ap_StaMd8_StaMds8_MilestoneRqst_WARMINIT_ExclArea_Return
FUNC(void, RTE_APPL_CODE) Rte_EnterHook_Ap_StaMd8_StaMds8_MilestoneRqst_WARMINIT_ExclArea_Return(void);
# else
#  define Rte_EnterHook_Ap_StaMd8_StaMds8_MilestoneRqst_WARMINIT_ExclArea_Return() ((void)(0))
# endif /* Rte_EnterHook_Ap_StaMd8_StaMds8_MilestoneRqst_WARMINIT_ExclArea_Return */

# if defined (Rte_EnterHook_Ap_StaMd8_StaMds8_MilestoneRqst_WARMINIT_ExclArea_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_EnterHook_Ap_StaMd8_StaMds8_MilestoneRqst_WARMINIT_ExclArea_Start
# endif
# if defined (Rte_EnterHook_Ap_StaMd8_StaMds8_MilestoneRqst_WARMINIT_ExclArea_Start)
#  undef Rte_EnterHook_Ap_StaMd8_StaMds8_MilestoneRqst_WARMINIT_ExclArea_Start
FUNC(void, RTE_APPL_CODE) Rte_EnterHook_Ap_StaMd8_StaMds8_MilestoneRqst_WARMINIT_ExclArea_Start(void);
# else
#  define Rte_EnterHook_Ap_StaMd8_StaMds8_MilestoneRqst_WARMINIT_ExclArea_Start() ((void)(0))
# endif /* Rte_EnterHook_Ap_StaMd8_StaMds8_MilestoneRqst_WARMINIT_ExclArea_Start */

# if defined (Rte_EnterHook_Ap_StaMd9_StaMds9_MilestoneRqst_WARMINIT_ExclArea_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_EnterHook_Ap_StaMd9_StaMds9_MilestoneRqst_WARMINIT_ExclArea_Return
# endif
# if defined (Rte_EnterHook_Ap_StaMd9_StaMds9_MilestoneRqst_WARMINIT_ExclArea_Return)
#  undef Rte_EnterHook_Ap_StaMd9_StaMds9_MilestoneRqst_WARMINIT_ExclArea_Return
FUNC(void, RTE_APPL_CODE) Rte_EnterHook_Ap_StaMd9_StaMds9_MilestoneRqst_WARMINIT_ExclArea_Return(void);
# else
#  define Rte_EnterHook_Ap_StaMd9_StaMds9_MilestoneRqst_WARMINIT_ExclArea_Return() ((void)(0))
# endif /* Rte_EnterHook_Ap_StaMd9_StaMds9_MilestoneRqst_WARMINIT_ExclArea_Return */

# if defined (Rte_EnterHook_Ap_StaMd9_StaMds9_MilestoneRqst_WARMINIT_ExclArea_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_EnterHook_Ap_StaMd9_StaMds9_MilestoneRqst_WARMINIT_ExclArea_Start
# endif
# if defined (Rte_EnterHook_Ap_StaMd9_StaMds9_MilestoneRqst_WARMINIT_ExclArea_Start)
#  undef Rte_EnterHook_Ap_StaMd9_StaMds9_MilestoneRqst_WARMINIT_ExclArea_Start
FUNC(void, RTE_APPL_CODE) Rte_EnterHook_Ap_StaMd9_StaMds9_MilestoneRqst_WARMINIT_ExclArea_Start(void);
# else
#  define Rte_EnterHook_Ap_StaMd9_StaMds9_MilestoneRqst_WARMINIT_ExclArea_Start() ((void)(0))
# endif /* Rte_EnterHook_Ap_StaMd9_StaMds9_MilestoneRqst_WARMINIT_ExclArea_Start */

# if defined (Rte_EnterHook_Ap_StaMd_StaMds_MilestoneRqst_WARMINIT_ExclArea_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_EnterHook_Ap_StaMd_StaMds_MilestoneRqst_WARMINIT_ExclArea_Return
# endif
# if defined (Rte_EnterHook_Ap_StaMd_StaMds_MilestoneRqst_WARMINIT_ExclArea_Return)
#  undef Rte_EnterHook_Ap_StaMd_StaMds_MilestoneRqst_WARMINIT_ExclArea_Return
FUNC(void, RTE_APPL_CODE) Rte_EnterHook_Ap_StaMd_StaMds_MilestoneRqst_WARMINIT_ExclArea_Return(void);
# else
#  define Rte_EnterHook_Ap_StaMd_StaMds_MilestoneRqst_WARMINIT_ExclArea_Return() ((void)(0))
# endif /* Rte_EnterHook_Ap_StaMd_StaMds_MilestoneRqst_WARMINIT_ExclArea_Return */

# if defined (Rte_EnterHook_Ap_StaMd_StaMds_MilestoneRqst_WARMINIT_ExclArea_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_EnterHook_Ap_StaMd_StaMds_MilestoneRqst_WARMINIT_ExclArea_Start
# endif
# if defined (Rte_EnterHook_Ap_StaMd_StaMds_MilestoneRqst_WARMINIT_ExclArea_Start)
#  undef Rte_EnterHook_Ap_StaMd_StaMds_MilestoneRqst_WARMINIT_ExclArea_Start
FUNC(void, RTE_APPL_CODE) Rte_EnterHook_Ap_StaMd_StaMds_MilestoneRqst_WARMINIT_ExclArea_Start(void);
# else
#  define Rte_EnterHook_Ap_StaMd_StaMds_MilestoneRqst_WARMINIT_ExclArea_Start() ((void)(0))
# endif /* Rte_EnterHook_Ap_StaMd_StaMds_MilestoneRqst_WARMINIT_ExclArea_Start */

# if defined (Rte_ExitHook_Ap_StaMd8_StaMds8_MilestoneRqst_WARMINIT_ExclArea_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_ExitHook_Ap_StaMd8_StaMds8_MilestoneRqst_WARMINIT_ExclArea_Return
# endif
# if defined (Rte_ExitHook_Ap_StaMd8_StaMds8_MilestoneRqst_WARMINIT_ExclArea_Return)
#  undef Rte_ExitHook_Ap_StaMd8_StaMds8_MilestoneRqst_WARMINIT_ExclArea_Return
FUNC(void, RTE_APPL_CODE) Rte_ExitHook_Ap_StaMd8_StaMds8_MilestoneRqst_WARMINIT_ExclArea_Return(void);
# else
#  define Rte_ExitHook_Ap_StaMd8_StaMds8_MilestoneRqst_WARMINIT_ExclArea_Return() ((void)(0))
# endif /* Rte_ExitHook_Ap_StaMd8_StaMds8_MilestoneRqst_WARMINIT_ExclArea_Return */

# if defined (Rte_ExitHook_Ap_StaMd8_StaMds8_MilestoneRqst_WARMINIT_ExclArea_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_ExitHook_Ap_StaMd8_StaMds8_MilestoneRqst_WARMINIT_ExclArea_Start
# endif
# if defined (Rte_ExitHook_Ap_StaMd8_StaMds8_MilestoneRqst_WARMINIT_ExclArea_Start)
#  undef Rte_ExitHook_Ap_StaMd8_StaMds8_MilestoneRqst_WARMINIT_ExclArea_Start
FUNC(void, RTE_APPL_CODE) Rte_ExitHook_Ap_StaMd8_StaMds8_MilestoneRqst_WARMINIT_ExclArea_Start(void);
# else
#  define Rte_ExitHook_Ap_StaMd8_StaMds8_MilestoneRqst_WARMINIT_ExclArea_Start() ((void)(0))
# endif /* Rte_ExitHook_Ap_StaMd8_StaMds8_MilestoneRqst_WARMINIT_ExclArea_Start */

# if defined (Rte_ExitHook_Ap_StaMd9_StaMds9_MilestoneRqst_WARMINIT_ExclArea_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_ExitHook_Ap_StaMd9_StaMds9_MilestoneRqst_WARMINIT_ExclArea_Return
# endif
# if defined (Rte_ExitHook_Ap_StaMd9_StaMds9_MilestoneRqst_WARMINIT_ExclArea_Return)
#  undef Rte_ExitHook_Ap_StaMd9_StaMds9_MilestoneRqst_WARMINIT_ExclArea_Return
FUNC(void, RTE_APPL_CODE) Rte_ExitHook_Ap_StaMd9_StaMds9_MilestoneRqst_WARMINIT_ExclArea_Return(void);
# else
#  define Rte_ExitHook_Ap_StaMd9_StaMds9_MilestoneRqst_WARMINIT_ExclArea_Return() ((void)(0))
# endif /* Rte_ExitHook_Ap_StaMd9_StaMds9_MilestoneRqst_WARMINIT_ExclArea_Return */

# if defined (Rte_ExitHook_Ap_StaMd9_StaMds9_MilestoneRqst_WARMINIT_ExclArea_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_ExitHook_Ap_StaMd9_StaMds9_MilestoneRqst_WARMINIT_ExclArea_Start
# endif
# if defined (Rte_ExitHook_Ap_StaMd9_StaMds9_MilestoneRqst_WARMINIT_ExclArea_Start)
#  undef Rte_ExitHook_Ap_StaMd9_StaMds9_MilestoneRqst_WARMINIT_ExclArea_Start
FUNC(void, RTE_APPL_CODE) Rte_ExitHook_Ap_StaMd9_StaMds9_MilestoneRqst_WARMINIT_ExclArea_Start(void);
# else
#  define Rte_ExitHook_Ap_StaMd9_StaMds9_MilestoneRqst_WARMINIT_ExclArea_Start() ((void)(0))
# endif /* Rte_ExitHook_Ap_StaMd9_StaMds9_MilestoneRqst_WARMINIT_ExclArea_Start */

# if defined (Rte_ExitHook_Ap_StaMd_StaMds_MilestoneRqst_WARMINIT_ExclArea_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_ExitHook_Ap_StaMd_StaMds_MilestoneRqst_WARMINIT_ExclArea_Return
# endif
# if defined (Rte_ExitHook_Ap_StaMd_StaMds_MilestoneRqst_WARMINIT_ExclArea_Return)
#  undef Rte_ExitHook_Ap_StaMd_StaMds_MilestoneRqst_WARMINIT_ExclArea_Return
FUNC(void, RTE_APPL_CODE) Rte_ExitHook_Ap_StaMd_StaMds_MilestoneRqst_WARMINIT_ExclArea_Return(void);
# else
#  define Rte_ExitHook_Ap_StaMd_StaMds_MilestoneRqst_WARMINIT_ExclArea_Return() ((void)(0))
# endif /* Rte_ExitHook_Ap_StaMd_StaMds_MilestoneRqst_WARMINIT_ExclArea_Return */

# if defined (Rte_ExitHook_Ap_StaMd_StaMds_MilestoneRqst_WARMINIT_ExclArea_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_ExitHook_Ap_StaMd_StaMds_MilestoneRqst_WARMINIT_ExclArea_Start
# endif
# if defined (Rte_ExitHook_Ap_StaMd_StaMds_MilestoneRqst_WARMINIT_ExclArea_Start)
#  undef Rte_ExitHook_Ap_StaMd_StaMds_MilestoneRqst_WARMINIT_ExclArea_Start
FUNC(void, RTE_APPL_CODE) Rte_ExitHook_Ap_StaMd_StaMds_MilestoneRqst_WARMINIT_ExclArea_Start(void);
# else
#  define Rte_ExitHook_Ap_StaMd_StaMds_MilestoneRqst_WARMINIT_ExclArea_Start() ((void)(0))
# endif /* Rte_ExitHook_Ap_StaMd_StaMds_MilestoneRqst_WARMINIT_ExclArea_Start */

# if defined (Rte_IrvReadHook_NexteerLibs_DtrmnElapsedTime_mS_u16_Time_mS_u32_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_IrvReadHook_NexteerLibs_DtrmnElapsedTime_mS_u16_Time_mS_u32_Return
# endif
# if defined (Rte_IrvReadHook_NexteerLibs_DtrmnElapsedTime_mS_u16_Time_mS_u32_Return)
#  undef Rte_IrvReadHook_NexteerLibs_DtrmnElapsedTime_mS_u16_Time_mS_u32_Return
FUNC(void, RTE_APPL_CODE) Rte_IrvReadHook_NexteerLibs_DtrmnElapsedTime_mS_u16_Time_mS_u32_Return(void);
# else
#  define Rte_IrvReadHook_NexteerLibs_DtrmnElapsedTime_mS_u16_Time_mS_u32_Return() ((void)(0))
# endif /* Rte_IrvReadHook_NexteerLibs_DtrmnElapsedTime_mS_u16_Time_mS_u32_Return */

# if defined (Rte_IrvReadHook_NexteerLibs_DtrmnElapsedTime_mS_u16_Time_mS_u32_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_IrvReadHook_NexteerLibs_DtrmnElapsedTime_mS_u16_Time_mS_u32_Start
# endif
# if defined (Rte_IrvReadHook_NexteerLibs_DtrmnElapsedTime_mS_u16_Time_mS_u32_Start)
#  undef Rte_IrvReadHook_NexteerLibs_DtrmnElapsedTime_mS_u16_Time_mS_u32_Start
FUNC(void, RTE_APPL_CODE) Rte_IrvReadHook_NexteerLibs_DtrmnElapsedTime_mS_u16_Time_mS_u32_Start(void);
# else
#  define Rte_IrvReadHook_NexteerLibs_DtrmnElapsedTime_mS_u16_Time_mS_u32_Start() ((void)(0))
# endif /* Rte_IrvReadHook_NexteerLibs_DtrmnElapsedTime_mS_u16_Time_mS_u32_Start */

# if defined (Rte_IrvReadHook_NexteerLibs_DtrmnElapsedTime_mS_u32_Time_mS_u32_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_IrvReadHook_NexteerLibs_DtrmnElapsedTime_mS_u32_Time_mS_u32_Return
# endif
# if defined (Rte_IrvReadHook_NexteerLibs_DtrmnElapsedTime_mS_u32_Time_mS_u32_Return)
#  undef Rte_IrvReadHook_NexteerLibs_DtrmnElapsedTime_mS_u32_Time_mS_u32_Return
FUNC(void, RTE_APPL_CODE) Rte_IrvReadHook_NexteerLibs_DtrmnElapsedTime_mS_u32_Time_mS_u32_Return(void);
# else
#  define Rte_IrvReadHook_NexteerLibs_DtrmnElapsedTime_mS_u32_Time_mS_u32_Return() ((void)(0))
# endif /* Rte_IrvReadHook_NexteerLibs_DtrmnElapsedTime_mS_u32_Time_mS_u32_Return */

# if defined (Rte_IrvReadHook_NexteerLibs_DtrmnElapsedTime_mS_u32_Time_mS_u32_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_IrvReadHook_NexteerLibs_DtrmnElapsedTime_mS_u32_Time_mS_u32_Start
# endif
# if defined (Rte_IrvReadHook_NexteerLibs_DtrmnElapsedTime_mS_u32_Time_mS_u32_Start)
#  undef Rte_IrvReadHook_NexteerLibs_DtrmnElapsedTime_mS_u32_Time_mS_u32_Start
FUNC(void, RTE_APPL_CODE) Rte_IrvReadHook_NexteerLibs_DtrmnElapsedTime_mS_u32_Time_mS_u32_Start(void);
# else
#  define Rte_IrvReadHook_NexteerLibs_DtrmnElapsedTime_mS_u32_Time_mS_u32_Start() ((void)(0))
# endif /* Rte_IrvReadHook_NexteerLibs_DtrmnElapsedTime_mS_u32_Time_mS_u32_Start */

# if defined (Rte_IrvReadHook_NexteerLibs_GetSystemTime_mS_u32_Time_mS_u32_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_IrvReadHook_NexteerLibs_GetSystemTime_mS_u32_Time_mS_u32_Return
# endif
# if defined (Rte_IrvReadHook_NexteerLibs_GetSystemTime_mS_u32_Time_mS_u32_Return)
#  undef Rte_IrvReadHook_NexteerLibs_GetSystemTime_mS_u32_Time_mS_u32_Return
FUNC(void, RTE_APPL_CODE) Rte_IrvReadHook_NexteerLibs_GetSystemTime_mS_u32_Time_mS_u32_Return(void);
# else
#  define Rte_IrvReadHook_NexteerLibs_GetSystemTime_mS_u32_Time_mS_u32_Return() ((void)(0))
# endif /* Rte_IrvReadHook_NexteerLibs_GetSystemTime_mS_u32_Time_mS_u32_Return */

# if defined (Rte_IrvReadHook_NexteerLibs_GetSystemTime_mS_u32_Time_mS_u32_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_IrvReadHook_NexteerLibs_GetSystemTime_mS_u32_Time_mS_u32_Start
# endif
# if defined (Rte_IrvReadHook_NexteerLibs_GetSystemTime_mS_u32_Time_mS_u32_Start)
#  undef Rte_IrvReadHook_NexteerLibs_GetSystemTime_mS_u32_Time_mS_u32_Start
FUNC(void, RTE_APPL_CODE) Rte_IrvReadHook_NexteerLibs_GetSystemTime_mS_u32_Time_mS_u32_Start(void);
# else
#  define Rte_IrvReadHook_NexteerLibs_GetSystemTime_mS_u32_Time_mS_u32_Start() ((void)(0))
# endif /* Rte_IrvReadHook_NexteerLibs_GetSystemTime_mS_u32_Time_mS_u32_Start */

# if defined (Rte_IrvReadHook_NexteerLibs_SystemTime_Per1_Time_mS_u32_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_IrvReadHook_NexteerLibs_SystemTime_Per1_Time_mS_u32_Return
# endif
# if defined (Rte_IrvReadHook_NexteerLibs_SystemTime_Per1_Time_mS_u32_Return)
#  undef Rte_IrvReadHook_NexteerLibs_SystemTime_Per1_Time_mS_u32_Return
FUNC(void, RTE_APPL_CODE) Rte_IrvReadHook_NexteerLibs_SystemTime_Per1_Time_mS_u32_Return(void);
# else
#  define Rte_IrvReadHook_NexteerLibs_SystemTime_Per1_Time_mS_u32_Return() ((void)(0))
# endif /* Rte_IrvReadHook_NexteerLibs_SystemTime_Per1_Time_mS_u32_Return */

# if defined (Rte_IrvReadHook_NexteerLibs_SystemTime_Per1_Time_mS_u32_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_IrvReadHook_NexteerLibs_SystemTime_Per1_Time_mS_u32_Start
# endif
# if defined (Rte_IrvReadHook_NexteerLibs_SystemTime_Per1_Time_mS_u32_Start)
#  undef Rte_IrvReadHook_NexteerLibs_SystemTime_Per1_Time_mS_u32_Start
FUNC(void, RTE_APPL_CODE) Rte_IrvReadHook_NexteerLibs_SystemTime_Per1_Time_mS_u32_Start(void);
# else
#  define Rte_IrvReadHook_NexteerLibs_SystemTime_Per1_Time_mS_u32_Start() ((void)(0))
# endif /* Rte_IrvReadHook_NexteerLibs_SystemTime_Per1_Time_mS_u32_Start */

# if defined (Rte_IrvWriteHook_NexteerLibs_SystemTime_Per1_Time_mS_u32_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_IrvWriteHook_NexteerLibs_SystemTime_Per1_Time_mS_u32_Return
# endif
# if defined (Rte_IrvWriteHook_NexteerLibs_SystemTime_Per1_Time_mS_u32_Return)
#  undef Rte_IrvWriteHook_NexteerLibs_SystemTime_Per1_Time_mS_u32_Return
FUNC(void, RTE_APPL_CODE) Rte_IrvWriteHook_NexteerLibs_SystemTime_Per1_Time_mS_u32_Return(UInt32 data);
# else
#  define Rte_IrvWriteHook_NexteerLibs_SystemTime_Per1_Time_mS_u32_Return(arg1) ((void)(0))
# endif /* Rte_IrvWriteHook_NexteerLibs_SystemTime_Per1_Time_mS_u32_Return */

# if defined (Rte_IrvWriteHook_NexteerLibs_SystemTime_Per1_Time_mS_u32_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_IrvWriteHook_NexteerLibs_SystemTime_Per1_Time_mS_u32_Start
# endif
# if defined (Rte_IrvWriteHook_NexteerLibs_SystemTime_Per1_Time_mS_u32_Start)
#  undef Rte_IrvWriteHook_NexteerLibs_SystemTime_Per1_Time_mS_u32_Start
FUNC(void, RTE_APPL_CODE) Rte_IrvWriteHook_NexteerLibs_SystemTime_Per1_Time_mS_u32_Start(UInt32 data);
# else
#  define Rte_IrvWriteHook_NexteerLibs_SystemTime_Per1_Time_mS_u32_Start(arg1) ((void)(0))
# endif /* Rte_IrvWriteHook_NexteerLibs_SystemTime_Per1_Time_mS_u32_Start */

# if defined (Rte_ReadHook_Ap_AstLmt_VehSpd_Kph_f32_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_Ap_AstLmt_VehSpd_Kph_f32_Return
# endif
# if defined (Rte_ReadHook_Ap_AstLmt_VehSpd_Kph_f32_Return)
#  undef Rte_ReadHook_Ap_AstLmt_VehSpd_Kph_f32_Return
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_Ap_AstLmt_VehSpd_Kph_f32_Return(P2VAR(Float, AUTOMATIC, RTE_AP_ASTLMT_APPL_VAR) data);
# else
#  define Rte_ReadHook_Ap_AstLmt_VehSpd_Kph_f32_Return(arg1) ((void)(0))
# endif /* Rte_ReadHook_Ap_AstLmt_VehSpd_Kph_f32_Return */

# if defined (Rte_ReadHook_Ap_AstLmt_VehSpd_Kph_f32_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_Ap_AstLmt_VehSpd_Kph_f32_Start
# endif
# if defined (Rte_ReadHook_Ap_AstLmt_VehSpd_Kph_f32_Start)
#  undef Rte_ReadHook_Ap_AstLmt_VehSpd_Kph_f32_Start
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_Ap_AstLmt_VehSpd_Kph_f32_Start(P2VAR(Float, AUTOMATIC, RTE_AP_ASTLMT_APPL_VAR) data);
# else
#  define Rte_ReadHook_Ap_AstLmt_VehSpd_Kph_f32_Start(arg1) ((void)(0))
# endif /* Rte_ReadHook_Ap_AstLmt_VehSpd_Kph_f32_Start */

# if defined (Rte_ReadHook_Ap_DemIf_CMDIgnStat_Cnt_u08_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_Ap_DemIf_CMDIgnStat_Cnt_u08_Return
# endif
# if defined (Rte_ReadHook_Ap_DemIf_CMDIgnStat_Cnt_u08_Return)
#  undef Rte_ReadHook_Ap_DemIf_CMDIgnStat_Cnt_u08_Return
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_Ap_DemIf_CMDIgnStat_Cnt_u08_Return(P2VAR(UInt8, AUTOMATIC, RTE_AP_DEMIF_APPL_VAR) data);
# else
#  define Rte_ReadHook_Ap_DemIf_CMDIgnStat_Cnt_u08_Return(arg1) ((void)(0))
# endif /* Rte_ReadHook_Ap_DemIf_CMDIgnStat_Cnt_u08_Return */

# if defined (Rte_ReadHook_Ap_DemIf_CMDIgnStat_Cnt_u08_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_Ap_DemIf_CMDIgnStat_Cnt_u08_Start
# endif
# if defined (Rte_ReadHook_Ap_DemIf_CMDIgnStat_Cnt_u08_Start)
#  undef Rte_ReadHook_Ap_DemIf_CMDIgnStat_Cnt_u08_Start
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_Ap_DemIf_CMDIgnStat_Cnt_u08_Start(P2VAR(UInt8, AUTOMATIC, RTE_AP_DEMIF_APPL_VAR) data);
# else
#  define Rte_ReadHook_Ap_DemIf_CMDIgnStat_Cnt_u08_Start(arg1) ((void)(0))
# endif /* Rte_ReadHook_Ap_DemIf_CMDIgnStat_Cnt_u08_Start */

# if defined (Rte_ReadHook_Ap_DemIf_NET_CFG_STAT_PT_Cnt_u16_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_Ap_DemIf_NET_CFG_STAT_PT_Cnt_u16_Return
# endif
# if defined (Rte_ReadHook_Ap_DemIf_NET_CFG_STAT_PT_Cnt_u16_Return)
#  undef Rte_ReadHook_Ap_DemIf_NET_CFG_STAT_PT_Cnt_u16_Return
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_Ap_DemIf_NET_CFG_STAT_PT_Cnt_u16_Return(P2VAR(UInt16, AUTOMATIC, RTE_AP_DEMIF_APPL_VAR) data);
# else
#  define Rte_ReadHook_Ap_DemIf_NET_CFG_STAT_PT_Cnt_u16_Return(arg1) ((void)(0))
# endif /* Rte_ReadHook_Ap_DemIf_NET_CFG_STAT_PT_Cnt_u16_Return */

# if defined (Rte_ReadHook_Ap_DemIf_NET_CFG_STAT_PT_Cnt_u16_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_Ap_DemIf_NET_CFG_STAT_PT_Cnt_u16_Start
# endif
# if defined (Rte_ReadHook_Ap_DemIf_NET_CFG_STAT_PT_Cnt_u16_Start)
#  undef Rte_ReadHook_Ap_DemIf_NET_CFG_STAT_PT_Cnt_u16_Start
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_Ap_DemIf_NET_CFG_STAT_PT_Cnt_u16_Start(P2VAR(UInt16, AUTOMATIC, RTE_AP_DEMIF_APPL_VAR) data);
# else
#  define Rte_ReadHook_Ap_DemIf_NET_CFG_STAT_PT_Cnt_u16_Start(arg1) ((void)(0))
# endif /* Rte_ReadHook_Ap_DemIf_NET_CFG_STAT_PT_Cnt_u16_Start */

# if defined (Rte_ReadHook_Ap_DiagMgr10_HwTrq_HwNm_f32_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_Ap_DiagMgr10_HwTrq_HwNm_f32_Return
# endif
# if defined (Rte_ReadHook_Ap_DiagMgr10_HwTrq_HwNm_f32_Return)
#  undef Rte_ReadHook_Ap_DiagMgr10_HwTrq_HwNm_f32_Return
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_Ap_DiagMgr10_HwTrq_HwNm_f32_Return(P2VAR(Float, AUTOMATIC, RTE_AP_DIAGMGR10_APPL_VAR) data);
# else
#  define Rte_ReadHook_Ap_DiagMgr10_HwTrq_HwNm_f32_Return(arg1) ((void)(0))
# endif /* Rte_ReadHook_Ap_DiagMgr10_HwTrq_HwNm_f32_Return */

# if defined (Rte_ReadHook_Ap_DiagMgr10_HwTrq_HwNm_f32_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_Ap_DiagMgr10_HwTrq_HwNm_f32_Start
# endif
# if defined (Rte_ReadHook_Ap_DiagMgr10_HwTrq_HwNm_f32_Start)
#  undef Rte_ReadHook_Ap_DiagMgr10_HwTrq_HwNm_f32_Start
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_Ap_DiagMgr10_HwTrq_HwNm_f32_Start(P2VAR(Float, AUTOMATIC, RTE_AP_DIAGMGR10_APPL_VAR) data);
# else
#  define Rte_ReadHook_Ap_DiagMgr10_HwTrq_HwNm_f32_Start(arg1) ((void)(0))
# endif /* Rte_ReadHook_Ap_DiagMgr10_HwTrq_HwNm_f32_Start */

# if defined (Rte_ReadHook_Ap_DiagMgr10_IgnCnt_Cnt_u16_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_Ap_DiagMgr10_IgnCnt_Cnt_u16_Return
# endif
# if defined (Rte_ReadHook_Ap_DiagMgr10_IgnCnt_Cnt_u16_Return)
#  undef Rte_ReadHook_Ap_DiagMgr10_IgnCnt_Cnt_u16_Return
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_Ap_DiagMgr10_IgnCnt_Cnt_u16_Return(P2VAR(UInt16, AUTOMATIC, RTE_AP_DIAGMGR10_APPL_VAR) data);
# else
#  define Rte_ReadHook_Ap_DiagMgr10_IgnCnt_Cnt_u16_Return(arg1) ((void)(0))
# endif /* Rte_ReadHook_Ap_DiagMgr10_IgnCnt_Cnt_u16_Return */

# if defined (Rte_ReadHook_Ap_DiagMgr10_IgnCnt_Cnt_u16_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_Ap_DiagMgr10_IgnCnt_Cnt_u16_Start
# endif
# if defined (Rte_ReadHook_Ap_DiagMgr10_IgnCnt_Cnt_u16_Start)
#  undef Rte_ReadHook_Ap_DiagMgr10_IgnCnt_Cnt_u16_Start
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_Ap_DiagMgr10_IgnCnt_Cnt_u16_Start(P2VAR(UInt16, AUTOMATIC, RTE_AP_DIAGMGR10_APPL_VAR) data);
# else
#  define Rte_ReadHook_Ap_DiagMgr10_IgnCnt_Cnt_u16_Start(arg1) ((void)(0))
# endif /* Rte_ReadHook_Ap_DiagMgr10_IgnCnt_Cnt_u16_Start */

# if defined (Rte_ReadHook_Ap_DiagMgr10_MEC_Cnt_enum_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_Ap_DiagMgr10_MEC_Cnt_enum_Return
# endif
# if defined (Rte_ReadHook_Ap_DiagMgr10_MEC_Cnt_enum_Return)
#  undef Rte_ReadHook_Ap_DiagMgr10_MEC_Cnt_enum_Return
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_Ap_DiagMgr10_MEC_Cnt_enum_Return(P2VAR(ManufModeType, AUTOMATIC, RTE_AP_DIAGMGR10_APPL_VAR) data);
# else
#  define Rte_ReadHook_Ap_DiagMgr10_MEC_Cnt_enum_Return(arg1) ((void)(0))
# endif /* Rte_ReadHook_Ap_DiagMgr10_MEC_Cnt_enum_Return */

# if defined (Rte_ReadHook_Ap_DiagMgr10_MEC_Cnt_enum_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_Ap_DiagMgr10_MEC_Cnt_enum_Start
# endif
# if defined (Rte_ReadHook_Ap_DiagMgr10_MEC_Cnt_enum_Start)
#  undef Rte_ReadHook_Ap_DiagMgr10_MEC_Cnt_enum_Start
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_Ap_DiagMgr10_MEC_Cnt_enum_Start(P2VAR(ManufModeType, AUTOMATIC, RTE_AP_DIAGMGR10_APPL_VAR) data);
# else
#  define Rte_ReadHook_Ap_DiagMgr10_MEC_Cnt_enum_Start(arg1) ((void)(0))
# endif /* Rte_ReadHook_Ap_DiagMgr10_MEC_Cnt_enum_Start */

# if defined (Rte_ReadHook_Ap_DiagMgr10_MfgDiagInhibit_Cnt_lgc_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_Ap_DiagMgr10_MfgDiagInhibit_Cnt_lgc_Return
# endif
# if defined (Rte_ReadHook_Ap_DiagMgr10_MfgDiagInhibit_Cnt_lgc_Return)
#  undef Rte_ReadHook_Ap_DiagMgr10_MfgDiagInhibit_Cnt_lgc_Return
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_Ap_DiagMgr10_MfgDiagInhibit_Cnt_lgc_Return(P2VAR(Boolean, AUTOMATIC, RTE_AP_DIAGMGR10_APPL_VAR) data);
# else
#  define Rte_ReadHook_Ap_DiagMgr10_MfgDiagInhibit_Cnt_lgc_Return(arg1) ((void)(0))
# endif /* Rte_ReadHook_Ap_DiagMgr10_MfgDiagInhibit_Cnt_lgc_Return */

# if defined (Rte_ReadHook_Ap_DiagMgr10_MfgDiagInhibit_Cnt_lgc_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_Ap_DiagMgr10_MfgDiagInhibit_Cnt_lgc_Start
# endif
# if defined (Rte_ReadHook_Ap_DiagMgr10_MfgDiagInhibit_Cnt_lgc_Start)
#  undef Rte_ReadHook_Ap_DiagMgr10_MfgDiagInhibit_Cnt_lgc_Start
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_Ap_DiagMgr10_MfgDiagInhibit_Cnt_lgc_Start(P2VAR(Boolean, AUTOMATIC, RTE_AP_DIAGMGR10_APPL_VAR) data);
# else
#  define Rte_ReadHook_Ap_DiagMgr10_MfgDiagInhibit_Cnt_lgc_Start(arg1) ((void)(0))
# endif /* Rte_ReadHook_Ap_DiagMgr10_MfgDiagInhibit_Cnt_lgc_Start */

# if defined (Rte_ReadHook_Ap_DiagMgr10_MtrTrq_MtrNm_f32_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_Ap_DiagMgr10_MtrTrq_MtrNm_f32_Return
# endif
# if defined (Rte_ReadHook_Ap_DiagMgr10_MtrTrq_MtrNm_f32_Return)
#  undef Rte_ReadHook_Ap_DiagMgr10_MtrTrq_MtrNm_f32_Return
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_Ap_DiagMgr10_MtrTrq_MtrNm_f32_Return(P2VAR(Float, AUTOMATIC, RTE_AP_DIAGMGR10_APPL_VAR) data);
# else
#  define Rte_ReadHook_Ap_DiagMgr10_MtrTrq_MtrNm_f32_Return(arg1) ((void)(0))
# endif /* Rte_ReadHook_Ap_DiagMgr10_MtrTrq_MtrNm_f32_Return */

# if defined (Rte_ReadHook_Ap_DiagMgr10_MtrTrq_MtrNm_f32_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_Ap_DiagMgr10_MtrTrq_MtrNm_f32_Start
# endif
# if defined (Rte_ReadHook_Ap_DiagMgr10_MtrTrq_MtrNm_f32_Start)
#  undef Rte_ReadHook_Ap_DiagMgr10_MtrTrq_MtrNm_f32_Start
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_Ap_DiagMgr10_MtrTrq_MtrNm_f32_Start(P2VAR(Float, AUTOMATIC, RTE_AP_DIAGMGR10_APPL_VAR) data);
# else
#  define Rte_ReadHook_Ap_DiagMgr10_MtrTrq_MtrNm_f32_Start(arg1) ((void)(0))
# endif /* Rte_ReadHook_Ap_DiagMgr10_MtrTrq_MtrNm_f32_Start */

# if defined (Rte_ReadHook_Ap_DiagMgr10_VehSpd_Kph_f32_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_Ap_DiagMgr10_VehSpd_Kph_f32_Return
# endif
# if defined (Rte_ReadHook_Ap_DiagMgr10_VehSpd_Kph_f32_Return)
#  undef Rte_ReadHook_Ap_DiagMgr10_VehSpd_Kph_f32_Return
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_Ap_DiagMgr10_VehSpd_Kph_f32_Return(P2VAR(Float, AUTOMATIC, RTE_AP_DIAGMGR10_APPL_VAR) data);
# else
#  define Rte_ReadHook_Ap_DiagMgr10_VehSpd_Kph_f32_Return(arg1) ((void)(0))
# endif /* Rte_ReadHook_Ap_DiagMgr10_VehSpd_Kph_f32_Return */

# if defined (Rte_ReadHook_Ap_DiagMgr10_VehSpd_Kph_f32_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_Ap_DiagMgr10_VehSpd_Kph_f32_Start
# endif
# if defined (Rte_ReadHook_Ap_DiagMgr10_VehSpd_Kph_f32_Start)
#  undef Rte_ReadHook_Ap_DiagMgr10_VehSpd_Kph_f32_Start
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_Ap_DiagMgr10_VehSpd_Kph_f32_Start(P2VAR(Float, AUTOMATIC, RTE_AP_DIAGMGR10_APPL_VAR) data);
# else
#  define Rte_ReadHook_Ap_DiagMgr10_VehSpd_Kph_f32_Start(arg1) ((void)(0))
# endif /* Rte_ReadHook_Ap_DiagMgr10_VehSpd_Kph_f32_Start */

# if defined (Rte_ReadHook_Ap_DiagMgr8_HwTrq_HwNm_f32_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_Ap_DiagMgr8_HwTrq_HwNm_f32_Return
# endif
# if defined (Rte_ReadHook_Ap_DiagMgr8_HwTrq_HwNm_f32_Return)
#  undef Rte_ReadHook_Ap_DiagMgr8_HwTrq_HwNm_f32_Return
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_Ap_DiagMgr8_HwTrq_HwNm_f32_Return(P2VAR(Float, AUTOMATIC, RTE_AP_DIAGMGR8_APPL_VAR) data);
# else
#  define Rte_ReadHook_Ap_DiagMgr8_HwTrq_HwNm_f32_Return(arg1) ((void)(0))
# endif /* Rte_ReadHook_Ap_DiagMgr8_HwTrq_HwNm_f32_Return */

# if defined (Rte_ReadHook_Ap_DiagMgr8_HwTrq_HwNm_f32_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_Ap_DiagMgr8_HwTrq_HwNm_f32_Start
# endif
# if defined (Rte_ReadHook_Ap_DiagMgr8_HwTrq_HwNm_f32_Start)
#  undef Rte_ReadHook_Ap_DiagMgr8_HwTrq_HwNm_f32_Start
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_Ap_DiagMgr8_HwTrq_HwNm_f32_Start(P2VAR(Float, AUTOMATIC, RTE_AP_DIAGMGR8_APPL_VAR) data);
# else
#  define Rte_ReadHook_Ap_DiagMgr8_HwTrq_HwNm_f32_Start(arg1) ((void)(0))
# endif /* Rte_ReadHook_Ap_DiagMgr8_HwTrq_HwNm_f32_Start */

# if defined (Rte_ReadHook_Ap_DiagMgr8_IgnCnt_Cnt_u16_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_Ap_DiagMgr8_IgnCnt_Cnt_u16_Return
# endif
# if defined (Rte_ReadHook_Ap_DiagMgr8_IgnCnt_Cnt_u16_Return)
#  undef Rte_ReadHook_Ap_DiagMgr8_IgnCnt_Cnt_u16_Return
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_Ap_DiagMgr8_IgnCnt_Cnt_u16_Return(P2VAR(UInt16, AUTOMATIC, RTE_AP_DIAGMGR8_APPL_VAR) data);
# else
#  define Rte_ReadHook_Ap_DiagMgr8_IgnCnt_Cnt_u16_Return(arg1) ((void)(0))
# endif /* Rte_ReadHook_Ap_DiagMgr8_IgnCnt_Cnt_u16_Return */

# if defined (Rte_ReadHook_Ap_DiagMgr8_IgnCnt_Cnt_u16_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_Ap_DiagMgr8_IgnCnt_Cnt_u16_Start
# endif
# if defined (Rte_ReadHook_Ap_DiagMgr8_IgnCnt_Cnt_u16_Start)
#  undef Rte_ReadHook_Ap_DiagMgr8_IgnCnt_Cnt_u16_Start
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_Ap_DiagMgr8_IgnCnt_Cnt_u16_Start(P2VAR(UInt16, AUTOMATIC, RTE_AP_DIAGMGR8_APPL_VAR) data);
# else
#  define Rte_ReadHook_Ap_DiagMgr8_IgnCnt_Cnt_u16_Start(arg1) ((void)(0))
# endif /* Rte_ReadHook_Ap_DiagMgr8_IgnCnt_Cnt_u16_Start */

# if defined (Rte_ReadHook_Ap_DiagMgr8_MEC_Cnt_enum_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_Ap_DiagMgr8_MEC_Cnt_enum_Return
# endif
# if defined (Rte_ReadHook_Ap_DiagMgr8_MEC_Cnt_enum_Return)
#  undef Rte_ReadHook_Ap_DiagMgr8_MEC_Cnt_enum_Return
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_Ap_DiagMgr8_MEC_Cnt_enum_Return(P2VAR(ManufModeType, AUTOMATIC, RTE_AP_DIAGMGR8_APPL_VAR) data);
# else
#  define Rte_ReadHook_Ap_DiagMgr8_MEC_Cnt_enum_Return(arg1) ((void)(0))
# endif /* Rte_ReadHook_Ap_DiagMgr8_MEC_Cnt_enum_Return */

# if defined (Rte_ReadHook_Ap_DiagMgr8_MEC_Cnt_enum_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_Ap_DiagMgr8_MEC_Cnt_enum_Start
# endif
# if defined (Rte_ReadHook_Ap_DiagMgr8_MEC_Cnt_enum_Start)
#  undef Rte_ReadHook_Ap_DiagMgr8_MEC_Cnt_enum_Start
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_Ap_DiagMgr8_MEC_Cnt_enum_Start(P2VAR(ManufModeType, AUTOMATIC, RTE_AP_DIAGMGR8_APPL_VAR) data);
# else
#  define Rte_ReadHook_Ap_DiagMgr8_MEC_Cnt_enum_Start(arg1) ((void)(0))
# endif /* Rte_ReadHook_Ap_DiagMgr8_MEC_Cnt_enum_Start */

# if defined (Rte_ReadHook_Ap_DiagMgr8_MfgDiagInhibit_Cnt_lgc_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_Ap_DiagMgr8_MfgDiagInhibit_Cnt_lgc_Return
# endif
# if defined (Rte_ReadHook_Ap_DiagMgr8_MfgDiagInhibit_Cnt_lgc_Return)
#  undef Rte_ReadHook_Ap_DiagMgr8_MfgDiagInhibit_Cnt_lgc_Return
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_Ap_DiagMgr8_MfgDiagInhibit_Cnt_lgc_Return(P2VAR(Boolean, AUTOMATIC, RTE_AP_DIAGMGR8_APPL_VAR) data);
# else
#  define Rte_ReadHook_Ap_DiagMgr8_MfgDiagInhibit_Cnt_lgc_Return(arg1) ((void)(0))
# endif /* Rte_ReadHook_Ap_DiagMgr8_MfgDiagInhibit_Cnt_lgc_Return */

# if defined (Rte_ReadHook_Ap_DiagMgr8_MfgDiagInhibit_Cnt_lgc_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_Ap_DiagMgr8_MfgDiagInhibit_Cnt_lgc_Start
# endif
# if defined (Rte_ReadHook_Ap_DiagMgr8_MfgDiagInhibit_Cnt_lgc_Start)
#  undef Rte_ReadHook_Ap_DiagMgr8_MfgDiagInhibit_Cnt_lgc_Start
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_Ap_DiagMgr8_MfgDiagInhibit_Cnt_lgc_Start(P2VAR(Boolean, AUTOMATIC, RTE_AP_DIAGMGR8_APPL_VAR) data);
# else
#  define Rte_ReadHook_Ap_DiagMgr8_MfgDiagInhibit_Cnt_lgc_Start(arg1) ((void)(0))
# endif /* Rte_ReadHook_Ap_DiagMgr8_MfgDiagInhibit_Cnt_lgc_Start */

# if defined (Rte_ReadHook_Ap_DiagMgr8_MtrTrq_MtrNm_f32_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_Ap_DiagMgr8_MtrTrq_MtrNm_f32_Return
# endif
# if defined (Rte_ReadHook_Ap_DiagMgr8_MtrTrq_MtrNm_f32_Return)
#  undef Rte_ReadHook_Ap_DiagMgr8_MtrTrq_MtrNm_f32_Return
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_Ap_DiagMgr8_MtrTrq_MtrNm_f32_Return(P2VAR(Float, AUTOMATIC, RTE_AP_DIAGMGR8_APPL_VAR) data);
# else
#  define Rte_ReadHook_Ap_DiagMgr8_MtrTrq_MtrNm_f32_Return(arg1) ((void)(0))
# endif /* Rte_ReadHook_Ap_DiagMgr8_MtrTrq_MtrNm_f32_Return */

# if defined (Rte_ReadHook_Ap_DiagMgr8_MtrTrq_MtrNm_f32_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_Ap_DiagMgr8_MtrTrq_MtrNm_f32_Start
# endif
# if defined (Rte_ReadHook_Ap_DiagMgr8_MtrTrq_MtrNm_f32_Start)
#  undef Rte_ReadHook_Ap_DiagMgr8_MtrTrq_MtrNm_f32_Start
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_Ap_DiagMgr8_MtrTrq_MtrNm_f32_Start(P2VAR(Float, AUTOMATIC, RTE_AP_DIAGMGR8_APPL_VAR) data);
# else
#  define Rte_ReadHook_Ap_DiagMgr8_MtrTrq_MtrNm_f32_Start(arg1) ((void)(0))
# endif /* Rte_ReadHook_Ap_DiagMgr8_MtrTrq_MtrNm_f32_Start */

# if defined (Rte_ReadHook_Ap_DiagMgr8_VehSpd_Kph_f32_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_Ap_DiagMgr8_VehSpd_Kph_f32_Return
# endif
# if defined (Rte_ReadHook_Ap_DiagMgr8_VehSpd_Kph_f32_Return)
#  undef Rte_ReadHook_Ap_DiagMgr8_VehSpd_Kph_f32_Return
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_Ap_DiagMgr8_VehSpd_Kph_f32_Return(P2VAR(Float, AUTOMATIC, RTE_AP_DIAGMGR8_APPL_VAR) data);
# else
#  define Rte_ReadHook_Ap_DiagMgr8_VehSpd_Kph_f32_Return(arg1) ((void)(0))
# endif /* Rte_ReadHook_Ap_DiagMgr8_VehSpd_Kph_f32_Return */

# if defined (Rte_ReadHook_Ap_DiagMgr8_VehSpd_Kph_f32_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_Ap_DiagMgr8_VehSpd_Kph_f32_Start
# endif
# if defined (Rte_ReadHook_Ap_DiagMgr8_VehSpd_Kph_f32_Start)
#  undef Rte_ReadHook_Ap_DiagMgr8_VehSpd_Kph_f32_Start
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_Ap_DiagMgr8_VehSpd_Kph_f32_Start(P2VAR(Float, AUTOMATIC, RTE_AP_DIAGMGR8_APPL_VAR) data);
# else
#  define Rte_ReadHook_Ap_DiagMgr8_VehSpd_Kph_f32_Start(arg1) ((void)(0))
# endif /* Rte_ReadHook_Ap_DiagMgr8_VehSpd_Kph_f32_Start */

# if defined (Rte_ReadHook_Ap_DiagMgr9_HwTrq_HwNm_f32_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_Ap_DiagMgr9_HwTrq_HwNm_f32_Return
# endif
# if defined (Rte_ReadHook_Ap_DiagMgr9_HwTrq_HwNm_f32_Return)
#  undef Rte_ReadHook_Ap_DiagMgr9_HwTrq_HwNm_f32_Return
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_Ap_DiagMgr9_HwTrq_HwNm_f32_Return(P2VAR(Float, AUTOMATIC, RTE_AP_DIAGMGR9_APPL_VAR) data);
# else
#  define Rte_ReadHook_Ap_DiagMgr9_HwTrq_HwNm_f32_Return(arg1) ((void)(0))
# endif /* Rte_ReadHook_Ap_DiagMgr9_HwTrq_HwNm_f32_Return */

# if defined (Rte_ReadHook_Ap_DiagMgr9_HwTrq_HwNm_f32_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_Ap_DiagMgr9_HwTrq_HwNm_f32_Start
# endif
# if defined (Rte_ReadHook_Ap_DiagMgr9_HwTrq_HwNm_f32_Start)
#  undef Rte_ReadHook_Ap_DiagMgr9_HwTrq_HwNm_f32_Start
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_Ap_DiagMgr9_HwTrq_HwNm_f32_Start(P2VAR(Float, AUTOMATIC, RTE_AP_DIAGMGR9_APPL_VAR) data);
# else
#  define Rte_ReadHook_Ap_DiagMgr9_HwTrq_HwNm_f32_Start(arg1) ((void)(0))
# endif /* Rte_ReadHook_Ap_DiagMgr9_HwTrq_HwNm_f32_Start */

# if defined (Rte_ReadHook_Ap_DiagMgr9_IgnCnt_Cnt_u16_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_Ap_DiagMgr9_IgnCnt_Cnt_u16_Return
# endif
# if defined (Rte_ReadHook_Ap_DiagMgr9_IgnCnt_Cnt_u16_Return)
#  undef Rte_ReadHook_Ap_DiagMgr9_IgnCnt_Cnt_u16_Return
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_Ap_DiagMgr9_IgnCnt_Cnt_u16_Return(P2VAR(UInt16, AUTOMATIC, RTE_AP_DIAGMGR9_APPL_VAR) data);
# else
#  define Rte_ReadHook_Ap_DiagMgr9_IgnCnt_Cnt_u16_Return(arg1) ((void)(0))
# endif /* Rte_ReadHook_Ap_DiagMgr9_IgnCnt_Cnt_u16_Return */

# if defined (Rte_ReadHook_Ap_DiagMgr9_IgnCnt_Cnt_u16_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_Ap_DiagMgr9_IgnCnt_Cnt_u16_Start
# endif
# if defined (Rte_ReadHook_Ap_DiagMgr9_IgnCnt_Cnt_u16_Start)
#  undef Rte_ReadHook_Ap_DiagMgr9_IgnCnt_Cnt_u16_Start
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_Ap_DiagMgr9_IgnCnt_Cnt_u16_Start(P2VAR(UInt16, AUTOMATIC, RTE_AP_DIAGMGR9_APPL_VAR) data);
# else
#  define Rte_ReadHook_Ap_DiagMgr9_IgnCnt_Cnt_u16_Start(arg1) ((void)(0))
# endif /* Rte_ReadHook_Ap_DiagMgr9_IgnCnt_Cnt_u16_Start */

# if defined (Rte_ReadHook_Ap_DiagMgr9_MEC_Cnt_enum_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_Ap_DiagMgr9_MEC_Cnt_enum_Return
# endif
# if defined (Rte_ReadHook_Ap_DiagMgr9_MEC_Cnt_enum_Return)
#  undef Rte_ReadHook_Ap_DiagMgr9_MEC_Cnt_enum_Return
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_Ap_DiagMgr9_MEC_Cnt_enum_Return(P2VAR(ManufModeType, AUTOMATIC, RTE_AP_DIAGMGR9_APPL_VAR) data);
# else
#  define Rte_ReadHook_Ap_DiagMgr9_MEC_Cnt_enum_Return(arg1) ((void)(0))
# endif /* Rte_ReadHook_Ap_DiagMgr9_MEC_Cnt_enum_Return */

# if defined (Rte_ReadHook_Ap_DiagMgr9_MEC_Cnt_enum_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_Ap_DiagMgr9_MEC_Cnt_enum_Start
# endif
# if defined (Rte_ReadHook_Ap_DiagMgr9_MEC_Cnt_enum_Start)
#  undef Rte_ReadHook_Ap_DiagMgr9_MEC_Cnt_enum_Start
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_Ap_DiagMgr9_MEC_Cnt_enum_Start(P2VAR(ManufModeType, AUTOMATIC, RTE_AP_DIAGMGR9_APPL_VAR) data);
# else
#  define Rte_ReadHook_Ap_DiagMgr9_MEC_Cnt_enum_Start(arg1) ((void)(0))
# endif /* Rte_ReadHook_Ap_DiagMgr9_MEC_Cnt_enum_Start */

# if defined (Rte_ReadHook_Ap_DiagMgr9_MfgDiagInhibit_Cnt_lgc_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_Ap_DiagMgr9_MfgDiagInhibit_Cnt_lgc_Return
# endif
# if defined (Rte_ReadHook_Ap_DiagMgr9_MfgDiagInhibit_Cnt_lgc_Return)
#  undef Rte_ReadHook_Ap_DiagMgr9_MfgDiagInhibit_Cnt_lgc_Return
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_Ap_DiagMgr9_MfgDiagInhibit_Cnt_lgc_Return(P2VAR(Boolean, AUTOMATIC, RTE_AP_DIAGMGR9_APPL_VAR) data);
# else
#  define Rte_ReadHook_Ap_DiagMgr9_MfgDiagInhibit_Cnt_lgc_Return(arg1) ((void)(0))
# endif /* Rte_ReadHook_Ap_DiagMgr9_MfgDiagInhibit_Cnt_lgc_Return */

# if defined (Rte_ReadHook_Ap_DiagMgr9_MfgDiagInhibit_Cnt_lgc_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_Ap_DiagMgr9_MfgDiagInhibit_Cnt_lgc_Start
# endif
# if defined (Rte_ReadHook_Ap_DiagMgr9_MfgDiagInhibit_Cnt_lgc_Start)
#  undef Rte_ReadHook_Ap_DiagMgr9_MfgDiagInhibit_Cnt_lgc_Start
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_Ap_DiagMgr9_MfgDiagInhibit_Cnt_lgc_Start(P2VAR(Boolean, AUTOMATIC, RTE_AP_DIAGMGR9_APPL_VAR) data);
# else
#  define Rte_ReadHook_Ap_DiagMgr9_MfgDiagInhibit_Cnt_lgc_Start(arg1) ((void)(0))
# endif /* Rte_ReadHook_Ap_DiagMgr9_MfgDiagInhibit_Cnt_lgc_Start */

# if defined (Rte_ReadHook_Ap_DiagMgr9_MtrTrq_MtrNm_f32_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_Ap_DiagMgr9_MtrTrq_MtrNm_f32_Return
# endif
# if defined (Rte_ReadHook_Ap_DiagMgr9_MtrTrq_MtrNm_f32_Return)
#  undef Rte_ReadHook_Ap_DiagMgr9_MtrTrq_MtrNm_f32_Return
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_Ap_DiagMgr9_MtrTrq_MtrNm_f32_Return(P2VAR(Float, AUTOMATIC, RTE_AP_DIAGMGR9_APPL_VAR) data);
# else
#  define Rte_ReadHook_Ap_DiagMgr9_MtrTrq_MtrNm_f32_Return(arg1) ((void)(0))
# endif /* Rte_ReadHook_Ap_DiagMgr9_MtrTrq_MtrNm_f32_Return */

# if defined (Rte_ReadHook_Ap_DiagMgr9_MtrTrq_MtrNm_f32_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_Ap_DiagMgr9_MtrTrq_MtrNm_f32_Start
# endif
# if defined (Rte_ReadHook_Ap_DiagMgr9_MtrTrq_MtrNm_f32_Start)
#  undef Rte_ReadHook_Ap_DiagMgr9_MtrTrq_MtrNm_f32_Start
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_Ap_DiagMgr9_MtrTrq_MtrNm_f32_Start(P2VAR(Float, AUTOMATIC, RTE_AP_DIAGMGR9_APPL_VAR) data);
# else
#  define Rte_ReadHook_Ap_DiagMgr9_MtrTrq_MtrNm_f32_Start(arg1) ((void)(0))
# endif /* Rte_ReadHook_Ap_DiagMgr9_MtrTrq_MtrNm_f32_Start */

# if defined (Rte_ReadHook_Ap_DiagMgr9_VehSpd_Kph_f32_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_Ap_DiagMgr9_VehSpd_Kph_f32_Return
# endif
# if defined (Rte_ReadHook_Ap_DiagMgr9_VehSpd_Kph_f32_Return)
#  undef Rte_ReadHook_Ap_DiagMgr9_VehSpd_Kph_f32_Return
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_Ap_DiagMgr9_VehSpd_Kph_f32_Return(P2VAR(Float, AUTOMATIC, RTE_AP_DIAGMGR9_APPL_VAR) data);
# else
#  define Rte_ReadHook_Ap_DiagMgr9_VehSpd_Kph_f32_Return(arg1) ((void)(0))
# endif /* Rte_ReadHook_Ap_DiagMgr9_VehSpd_Kph_f32_Return */

# if defined (Rte_ReadHook_Ap_DiagMgr9_VehSpd_Kph_f32_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_Ap_DiagMgr9_VehSpd_Kph_f32_Start
# endif
# if defined (Rte_ReadHook_Ap_DiagMgr9_VehSpd_Kph_f32_Start)
#  undef Rte_ReadHook_Ap_DiagMgr9_VehSpd_Kph_f32_Start
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_Ap_DiagMgr9_VehSpd_Kph_f32_Start(P2VAR(Float, AUTOMATIC, RTE_AP_DIAGMGR9_APPL_VAR) data);
# else
#  define Rte_ReadHook_Ap_DiagMgr9_VehSpd_Kph_f32_Start(arg1) ((void)(0))
# endif /* Rte_ReadHook_Ap_DiagMgr9_VehSpd_Kph_f32_Start */

# if defined (Rte_ReadHook_Ap_Gsod_Ana_Hw_Torque_HwNm_f32_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_Ap_Gsod_Ana_Hw_Torque_HwNm_f32_Return
# endif
# if defined (Rte_ReadHook_Ap_Gsod_Ana_Hw_Torque_HwNm_f32_Return)
#  undef Rte_ReadHook_Ap_Gsod_Ana_Hw_Torque_HwNm_f32_Return
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_Ap_Gsod_Ana_Hw_Torque_HwNm_f32_Return(P2VAR(Float, AUTOMATIC, RTE_AP_GSOD_APPL_VAR) data);
# else
#  define Rte_ReadHook_Ap_Gsod_Ana_Hw_Torque_HwNm_f32_Return(arg1) ((void)(0))
# endif /* Rte_ReadHook_Ap_Gsod_Ana_Hw_Torque_HwNm_f32_Return */

# if defined (Rte_ReadHook_Ap_Gsod_Ana_Hw_Torque_HwNm_f32_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_Ap_Gsod_Ana_Hw_Torque_HwNm_f32_Start
# endif
# if defined (Rte_ReadHook_Ap_Gsod_Ana_Hw_Torque_HwNm_f32_Start)
#  undef Rte_ReadHook_Ap_Gsod_Ana_Hw_Torque_HwNm_f32_Start
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_Ap_Gsod_Ana_Hw_Torque_HwNm_f32_Start(P2VAR(Float, AUTOMATIC, RTE_AP_GSOD_APPL_VAR) data);
# else
#  define Rte_ReadHook_Ap_Gsod_Ana_Hw_Torque_HwNm_f32_Start(arg1) ((void)(0))
# endif /* Rte_ReadHook_Ap_Gsod_Ana_Hw_Torque_HwNm_f32_Start */

# if defined (Rte_ReadHook_Ap_Gsod_Corrected_MtrPos_Rev_f32_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_Ap_Gsod_Corrected_MtrPos_Rev_f32_Return
# endif
# if defined (Rte_ReadHook_Ap_Gsod_Corrected_MtrPos_Rev_f32_Return)
#  undef Rte_ReadHook_Ap_Gsod_Corrected_MtrPos_Rev_f32_Return
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_Ap_Gsod_Corrected_MtrPos_Rev_f32_Return(P2VAR(Float, AUTOMATIC, RTE_AP_GSOD_APPL_VAR) data);
# else
#  define Rte_ReadHook_Ap_Gsod_Corrected_MtrPos_Rev_f32_Return(arg1) ((void)(0))
# endif /* Rte_ReadHook_Ap_Gsod_Corrected_MtrPos_Rev_f32_Return */

# if defined (Rte_ReadHook_Ap_Gsod_Corrected_MtrPos_Rev_f32_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_Ap_Gsod_Corrected_MtrPos_Rev_f32_Start
# endif
# if defined (Rte_ReadHook_Ap_Gsod_Corrected_MtrPos_Rev_f32_Start)
#  undef Rte_ReadHook_Ap_Gsod_Corrected_MtrPos_Rev_f32_Start
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_Ap_Gsod_Corrected_MtrPos_Rev_f32_Start(P2VAR(Float, AUTOMATIC, RTE_AP_GSOD_APPL_VAR) data);
# else
#  define Rte_ReadHook_Ap_Gsod_Corrected_MtrPos_Rev_f32_Start(arg1) ((void)(0))
# endif /* Rte_ReadHook_Ap_Gsod_Corrected_MtrPos_Rev_f32_Start */

# if defined (Rte_ReadHook_Ap_Gsod_Cum_Mtr_Pos_CRF_Deg_f32_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_Ap_Gsod_Cum_Mtr_Pos_CRF_Deg_f32_Return
# endif
# if defined (Rte_ReadHook_Ap_Gsod_Cum_Mtr_Pos_CRF_Deg_f32_Return)
#  undef Rte_ReadHook_Ap_Gsod_Cum_Mtr_Pos_CRF_Deg_f32_Return
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_Ap_Gsod_Cum_Mtr_Pos_CRF_Deg_f32_Return(P2VAR(Float, AUTOMATIC, RTE_AP_GSOD_APPL_VAR) data);
# else
#  define Rte_ReadHook_Ap_Gsod_Cum_Mtr_Pos_CRF_Deg_f32_Return(arg1) ((void)(0))
# endif /* Rte_ReadHook_Ap_Gsod_Cum_Mtr_Pos_CRF_Deg_f32_Return */

# if defined (Rte_ReadHook_Ap_Gsod_Cum_Mtr_Pos_CRF_Deg_f32_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_Ap_Gsod_Cum_Mtr_Pos_CRF_Deg_f32_Start
# endif
# if defined (Rte_ReadHook_Ap_Gsod_Cum_Mtr_Pos_CRF_Deg_f32_Start)
#  undef Rte_ReadHook_Ap_Gsod_Cum_Mtr_Pos_CRF_Deg_f32_Start
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_Ap_Gsod_Cum_Mtr_Pos_CRF_Deg_f32_Start(P2VAR(Float, AUTOMATIC, RTE_AP_GSOD_APPL_VAR) data);
# else
#  define Rte_ReadHook_Ap_Gsod_Cum_Mtr_Pos_CRF_Deg_f32_Start(arg1) ((void)(0))
# endif /* Rte_ReadHook_Ap_Gsod_Cum_Mtr_Pos_CRF_Deg_f32_Start */

# if defined (Rte_ReadHook_Ap_Gsod_MtrElecMech_Polarity_Cnt_s08_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_Ap_Gsod_MtrElecMech_Polarity_Cnt_s08_Return
# endif
# if defined (Rte_ReadHook_Ap_Gsod_MtrElecMech_Polarity_Cnt_s08_Return)
#  undef Rte_ReadHook_Ap_Gsod_MtrElecMech_Polarity_Cnt_s08_Return
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_Ap_Gsod_MtrElecMech_Polarity_Cnt_s08_Return(P2VAR(SInt8, AUTOMATIC, RTE_AP_GSOD_APPL_VAR) data);
# else
#  define Rte_ReadHook_Ap_Gsod_MtrElecMech_Polarity_Cnt_s08_Return(arg1) ((void)(0))
# endif /* Rte_ReadHook_Ap_Gsod_MtrElecMech_Polarity_Cnt_s08_Return */

# if defined (Rte_ReadHook_Ap_Gsod_MtrElecMech_Polarity_Cnt_s08_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_Ap_Gsod_MtrElecMech_Polarity_Cnt_s08_Start
# endif
# if defined (Rte_ReadHook_Ap_Gsod_MtrElecMech_Polarity_Cnt_s08_Start)
#  undef Rte_ReadHook_Ap_Gsod_MtrElecMech_Polarity_Cnt_s08_Start
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_Ap_Gsod_MtrElecMech_Polarity_Cnt_s08_Start(P2VAR(SInt8, AUTOMATIC, RTE_AP_GSOD_APPL_VAR) data);
# else
#  define Rte_ReadHook_Ap_Gsod_MtrElecMech_Polarity_Cnt_s08_Start(arg1) ((void)(0))
# endif /* Rte_ReadHook_Ap_Gsod_MtrElecMech_Polarity_Cnt_s08_Start */

# if defined (Rte_ReadHook_Ap_Gsod_SysC_Ana_Hw_Torque_HwNm_f32_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_Ap_Gsod_SysC_Ana_Hw_Torque_HwNm_f32_Return
# endif
# if defined (Rte_ReadHook_Ap_Gsod_SysC_Ana_Hw_Torque_HwNm_f32_Return)
#  undef Rte_ReadHook_Ap_Gsod_SysC_Ana_Hw_Torque_HwNm_f32_Return
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_Ap_Gsod_SysC_Ana_Hw_Torque_HwNm_f32_Return(P2VAR(Float, AUTOMATIC, RTE_AP_GSOD_APPL_VAR) data);
# else
#  define Rte_ReadHook_Ap_Gsod_SysC_Ana_Hw_Torque_HwNm_f32_Return(arg1) ((void)(0))
# endif /* Rte_ReadHook_Ap_Gsod_SysC_Ana_Hw_Torque_HwNm_f32_Return */

# if defined (Rte_ReadHook_Ap_Gsod_SysC_Ana_Hw_Torque_HwNm_f32_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_Ap_Gsod_SysC_Ana_Hw_Torque_HwNm_f32_Start
# endif
# if defined (Rte_ReadHook_Ap_Gsod_SysC_Ana_Hw_Torque_HwNm_f32_Start)
#  undef Rte_ReadHook_Ap_Gsod_SysC_Ana_Hw_Torque_HwNm_f32_Start
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_Ap_Gsod_SysC_Ana_Hw_Torque_HwNm_f32_Start(P2VAR(Float, AUTOMATIC, RTE_AP_GSOD_APPL_VAR) data);
# else
#  define Rte_ReadHook_Ap_Gsod_SysC_Ana_Hw_Torque_HwNm_f32_Start(arg1) ((void)(0))
# endif /* Rte_ReadHook_Ap_Gsod_SysC_Ana_Hw_Torque_HwNm_f32_Start */

# if defined (Rte_ReadHook_Ap_Gsod_SysC_Corrected_MtrPos_Rev_f32_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_Ap_Gsod_SysC_Corrected_MtrPos_Rev_f32_Return
# endif
# if defined (Rte_ReadHook_Ap_Gsod_SysC_Corrected_MtrPos_Rev_f32_Return)
#  undef Rte_ReadHook_Ap_Gsod_SysC_Corrected_MtrPos_Rev_f32_Return
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_Ap_Gsod_SysC_Corrected_MtrPos_Rev_f32_Return(P2VAR(Float, AUTOMATIC, RTE_AP_GSOD_APPL_VAR) data);
# else
#  define Rte_ReadHook_Ap_Gsod_SysC_Corrected_MtrPos_Rev_f32_Return(arg1) ((void)(0))
# endif /* Rte_ReadHook_Ap_Gsod_SysC_Corrected_MtrPos_Rev_f32_Return */

# if defined (Rte_ReadHook_Ap_Gsod_SysC_Corrected_MtrPos_Rev_f32_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_Ap_Gsod_SysC_Corrected_MtrPos_Rev_f32_Start
# endif
# if defined (Rte_ReadHook_Ap_Gsod_SysC_Corrected_MtrPos_Rev_f32_Start)
#  undef Rte_ReadHook_Ap_Gsod_SysC_Corrected_MtrPos_Rev_f32_Start
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_Ap_Gsod_SysC_Corrected_MtrPos_Rev_f32_Start(P2VAR(Float, AUTOMATIC, RTE_AP_GSOD_APPL_VAR) data);
# else
#  define Rte_ReadHook_Ap_Gsod_SysC_Corrected_MtrPos_Rev_f32_Start(arg1) ((void)(0))
# endif /* Rte_ReadHook_Ap_Gsod_SysC_Corrected_MtrPos_Rev_f32_Start */

# if defined (Rte_ReadHook_Ap_Gsod_SysC_Cum_Mtr_Pos_CRF_Deg_f32_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_Ap_Gsod_SysC_Cum_Mtr_Pos_CRF_Deg_f32_Return
# endif
# if defined (Rte_ReadHook_Ap_Gsod_SysC_Cum_Mtr_Pos_CRF_Deg_f32_Return)
#  undef Rte_ReadHook_Ap_Gsod_SysC_Cum_Mtr_Pos_CRF_Deg_f32_Return
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_Ap_Gsod_SysC_Cum_Mtr_Pos_CRF_Deg_f32_Return(P2VAR(Float, AUTOMATIC, RTE_AP_GSOD_APPL_VAR) data);
# else
#  define Rte_ReadHook_Ap_Gsod_SysC_Cum_Mtr_Pos_CRF_Deg_f32_Return(arg1) ((void)(0))
# endif /* Rte_ReadHook_Ap_Gsod_SysC_Cum_Mtr_Pos_CRF_Deg_f32_Return */

# if defined (Rte_ReadHook_Ap_Gsod_SysC_Cum_Mtr_Pos_CRF_Deg_f32_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_Ap_Gsod_SysC_Cum_Mtr_Pos_CRF_Deg_f32_Start
# endif
# if defined (Rte_ReadHook_Ap_Gsod_SysC_Cum_Mtr_Pos_CRF_Deg_f32_Start)
#  undef Rte_ReadHook_Ap_Gsod_SysC_Cum_Mtr_Pos_CRF_Deg_f32_Start
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_Ap_Gsod_SysC_Cum_Mtr_Pos_CRF_Deg_f32_Start(P2VAR(Float, AUTOMATIC, RTE_AP_GSOD_APPL_VAR) data);
# else
#  define Rte_ReadHook_Ap_Gsod_SysC_Cum_Mtr_Pos_CRF_Deg_f32_Start(arg1) ((void)(0))
# endif /* Rte_ReadHook_Ap_Gsod_SysC_Cum_Mtr_Pos_CRF_Deg_f32_Start */

# if defined (Rte_ReadHook_Ap_Gsod_SysC_MtrElecMech_Polarity_Cnt_s32_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_Ap_Gsod_SysC_MtrElecMech_Polarity_Cnt_s32_Return
# endif
# if defined (Rte_ReadHook_Ap_Gsod_SysC_MtrElecMech_Polarity_Cnt_s32_Return)
#  undef Rte_ReadHook_Ap_Gsod_SysC_MtrElecMech_Polarity_Cnt_s32_Return
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_Ap_Gsod_SysC_MtrElecMech_Polarity_Cnt_s32_Return(P2VAR(SInt32, AUTOMATIC, RTE_AP_GSOD_APPL_VAR) data);
# else
#  define Rte_ReadHook_Ap_Gsod_SysC_MtrElecMech_Polarity_Cnt_s32_Return(arg1) ((void)(0))
# endif /* Rte_ReadHook_Ap_Gsod_SysC_MtrElecMech_Polarity_Cnt_s32_Return */

# if defined (Rte_ReadHook_Ap_Gsod_SysC_MtrElecMech_Polarity_Cnt_s32_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_Ap_Gsod_SysC_MtrElecMech_Polarity_Cnt_s32_Start
# endif
# if defined (Rte_ReadHook_Ap_Gsod_SysC_MtrElecMech_Polarity_Cnt_s32_Start)
#  undef Rte_ReadHook_Ap_Gsod_SysC_MtrElecMech_Polarity_Cnt_s32_Start
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_Ap_Gsod_SysC_MtrElecMech_Polarity_Cnt_s32_Start(P2VAR(SInt32, AUTOMATIC, RTE_AP_GSOD_APPL_VAR) data);
# else
#  define Rte_ReadHook_Ap_Gsod_SysC_MtrElecMech_Polarity_Cnt_s32_Start(arg1) ((void)(0))
# endif /* Rte_ReadHook_Ap_Gsod_SysC_MtrElecMech_Polarity_Cnt_s32_Start */

# if defined (Rte_ReadHook_Ap_Gsod_SysC_Torque_Cmd_CRF_MtrNm_f32_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_Ap_Gsod_SysC_Torque_Cmd_CRF_MtrNm_f32_Return
# endif
# if defined (Rte_ReadHook_Ap_Gsod_SysC_Torque_Cmd_CRF_MtrNm_f32_Return)
#  undef Rte_ReadHook_Ap_Gsod_SysC_Torque_Cmd_CRF_MtrNm_f32_Return
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_Ap_Gsod_SysC_Torque_Cmd_CRF_MtrNm_f32_Return(P2VAR(Float, AUTOMATIC, RTE_AP_GSOD_APPL_VAR) data);
# else
#  define Rte_ReadHook_Ap_Gsod_SysC_Torque_Cmd_CRF_MtrNm_f32_Return(arg1) ((void)(0))
# endif /* Rte_ReadHook_Ap_Gsod_SysC_Torque_Cmd_CRF_MtrNm_f32_Return */

# if defined (Rte_ReadHook_Ap_Gsod_SysC_Torque_Cmd_CRF_MtrNm_f32_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_Ap_Gsod_SysC_Torque_Cmd_CRF_MtrNm_f32_Start
# endif
# if defined (Rte_ReadHook_Ap_Gsod_SysC_Torque_Cmd_CRF_MtrNm_f32_Start)
#  undef Rte_ReadHook_Ap_Gsod_SysC_Torque_Cmd_CRF_MtrNm_f32_Start
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_Ap_Gsod_SysC_Torque_Cmd_CRF_MtrNm_f32_Start(P2VAR(Float, AUTOMATIC, RTE_AP_GSOD_APPL_VAR) data);
# else
#  define Rte_ReadHook_Ap_Gsod_SysC_Torque_Cmd_CRF_MtrNm_f32_Start(arg1) ((void)(0))
# endif /* Rte_ReadHook_Ap_Gsod_SysC_Torque_Cmd_CRF_MtrNm_f32_Start */

# if defined (Rte_ReadHook_Ap_Gsod_SysC_Torque_Cmd_MRF_MtrNm_f32_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_Ap_Gsod_SysC_Torque_Cmd_MRF_MtrNm_f32_Return
# endif
# if defined (Rte_ReadHook_Ap_Gsod_SysC_Torque_Cmd_MRF_MtrNm_f32_Return)
#  undef Rte_ReadHook_Ap_Gsod_SysC_Torque_Cmd_MRF_MtrNm_f32_Return
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_Ap_Gsod_SysC_Torque_Cmd_MRF_MtrNm_f32_Return(P2VAR(Float, AUTOMATIC, RTE_AP_GSOD_APPL_VAR) data);
# else
#  define Rte_ReadHook_Ap_Gsod_SysC_Torque_Cmd_MRF_MtrNm_f32_Return(arg1) ((void)(0))
# endif /* Rte_ReadHook_Ap_Gsod_SysC_Torque_Cmd_MRF_MtrNm_f32_Return */

# if defined (Rte_ReadHook_Ap_Gsod_SysC_Torque_Cmd_MRF_MtrNm_f32_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_Ap_Gsod_SysC_Torque_Cmd_MRF_MtrNm_f32_Start
# endif
# if defined (Rte_ReadHook_Ap_Gsod_SysC_Torque_Cmd_MRF_MtrNm_f32_Start)
#  undef Rte_ReadHook_Ap_Gsod_SysC_Torque_Cmd_MRF_MtrNm_f32_Start
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_Ap_Gsod_SysC_Torque_Cmd_MRF_MtrNm_f32_Start(P2VAR(Float, AUTOMATIC, RTE_AP_GSOD_APPL_VAR) data);
# else
#  define Rte_ReadHook_Ap_Gsod_SysC_Torque_Cmd_MRF_MtrNm_f32_Start(arg1) ((void)(0))
# endif /* Rte_ReadHook_Ap_Gsod_SysC_Torque_Cmd_MRF_MtrNm_f32_Start */

# if defined (Rte_ReadHook_Ap_Gsod_SysC_Vecu_Volt_f32_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_Ap_Gsod_SysC_Vecu_Volt_f32_Return
# endif
# if defined (Rte_ReadHook_Ap_Gsod_SysC_Vecu_Volt_f32_Return)
#  undef Rte_ReadHook_Ap_Gsod_SysC_Vecu_Volt_f32_Return
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_Ap_Gsod_SysC_Vecu_Volt_f32_Return(P2VAR(Float, AUTOMATIC, RTE_AP_GSOD_APPL_VAR) data);
# else
#  define Rte_ReadHook_Ap_Gsod_SysC_Vecu_Volt_f32_Return(arg1) ((void)(0))
# endif /* Rte_ReadHook_Ap_Gsod_SysC_Vecu_Volt_f32_Return */

# if defined (Rte_ReadHook_Ap_Gsod_SysC_Vecu_Volt_f32_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_Ap_Gsod_SysC_Vecu_Volt_f32_Start
# endif
# if defined (Rte_ReadHook_Ap_Gsod_SysC_Vecu_Volt_f32_Start)
#  undef Rte_ReadHook_Ap_Gsod_SysC_Vecu_Volt_f32_Start
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_Ap_Gsod_SysC_Vecu_Volt_f32_Start(P2VAR(Float, AUTOMATIC, RTE_AP_GSOD_APPL_VAR) data);
# else
#  define Rte_ReadHook_Ap_Gsod_SysC_Vecu_Volt_f32_Start(arg1) ((void)(0))
# endif /* Rte_ReadHook_Ap_Gsod_SysC_Vecu_Volt_f32_Start */

# if defined (Rte_ReadHook_Ap_Gsod_Torque_Cmd_CRF_MtrNm_f32_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_Ap_Gsod_Torque_Cmd_CRF_MtrNm_f32_Return
# endif
# if defined (Rte_ReadHook_Ap_Gsod_Torque_Cmd_CRF_MtrNm_f32_Return)
#  undef Rte_ReadHook_Ap_Gsod_Torque_Cmd_CRF_MtrNm_f32_Return
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_Ap_Gsod_Torque_Cmd_CRF_MtrNm_f32_Return(P2VAR(Float, AUTOMATIC, RTE_AP_GSOD_APPL_VAR) data);
# else
#  define Rte_ReadHook_Ap_Gsod_Torque_Cmd_CRF_MtrNm_f32_Return(arg1) ((void)(0))
# endif /* Rte_ReadHook_Ap_Gsod_Torque_Cmd_CRF_MtrNm_f32_Return */

# if defined (Rte_ReadHook_Ap_Gsod_Torque_Cmd_CRF_MtrNm_f32_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_Ap_Gsod_Torque_Cmd_CRF_MtrNm_f32_Start
# endif
# if defined (Rte_ReadHook_Ap_Gsod_Torque_Cmd_CRF_MtrNm_f32_Start)
#  undef Rte_ReadHook_Ap_Gsod_Torque_Cmd_CRF_MtrNm_f32_Start
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_Ap_Gsod_Torque_Cmd_CRF_MtrNm_f32_Start(P2VAR(Float, AUTOMATIC, RTE_AP_GSOD_APPL_VAR) data);
# else
#  define Rte_ReadHook_Ap_Gsod_Torque_Cmd_CRF_MtrNm_f32_Start(arg1) ((void)(0))
# endif /* Rte_ReadHook_Ap_Gsod_Torque_Cmd_CRF_MtrNm_f32_Start */

# if defined (Rte_ReadHook_Ap_Gsod_Torque_Cmd_MRF_MtrNm_f32_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_Ap_Gsod_Torque_Cmd_MRF_MtrNm_f32_Return
# endif
# if defined (Rte_ReadHook_Ap_Gsod_Torque_Cmd_MRF_MtrNm_f32_Return)
#  undef Rte_ReadHook_Ap_Gsod_Torque_Cmd_MRF_MtrNm_f32_Return
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_Ap_Gsod_Torque_Cmd_MRF_MtrNm_f32_Return(P2VAR(Float, AUTOMATIC, RTE_AP_GSOD_APPL_VAR) data);
# else
#  define Rte_ReadHook_Ap_Gsod_Torque_Cmd_MRF_MtrNm_f32_Return(arg1) ((void)(0))
# endif /* Rte_ReadHook_Ap_Gsod_Torque_Cmd_MRF_MtrNm_f32_Return */

# if defined (Rte_ReadHook_Ap_Gsod_Torque_Cmd_MRF_MtrNm_f32_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_Ap_Gsod_Torque_Cmd_MRF_MtrNm_f32_Start
# endif
# if defined (Rte_ReadHook_Ap_Gsod_Torque_Cmd_MRF_MtrNm_f32_Start)
#  undef Rte_ReadHook_Ap_Gsod_Torque_Cmd_MRF_MtrNm_f32_Start
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_Ap_Gsod_Torque_Cmd_MRF_MtrNm_f32_Start(P2VAR(Float, AUTOMATIC, RTE_AP_GSOD_APPL_VAR) data);
# else
#  define Rte_ReadHook_Ap_Gsod_Torque_Cmd_MRF_MtrNm_f32_Start(arg1) ((void)(0))
# endif /* Rte_ReadHook_Ap_Gsod_Torque_Cmd_MRF_MtrNm_f32_Start */

# if defined (Rte_ReadHook_Ap_Gsod_Vecu_Volt_f32_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_Ap_Gsod_Vecu_Volt_f32_Return
# endif
# if defined (Rte_ReadHook_Ap_Gsod_Vecu_Volt_f32_Return)
#  undef Rte_ReadHook_Ap_Gsod_Vecu_Volt_f32_Return
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_Ap_Gsod_Vecu_Volt_f32_Return(P2VAR(Float, AUTOMATIC, RTE_AP_GSOD_APPL_VAR) data);
# else
#  define Rte_ReadHook_Ap_Gsod_Vecu_Volt_f32_Return(arg1) ((void)(0))
# endif /* Rte_ReadHook_Ap_Gsod_Vecu_Volt_f32_Return */

# if defined (Rte_ReadHook_Ap_Gsod_Vecu_Volt_f32_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_Ap_Gsod_Vecu_Volt_f32_Start
# endif
# if defined (Rte_ReadHook_Ap_Gsod_Vecu_Volt_f32_Start)
#  undef Rte_ReadHook_Ap_Gsod_Vecu_Volt_f32_Start
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_Ap_Gsod_Vecu_Volt_f32_Start(P2VAR(Float, AUTOMATIC, RTE_AP_GSOD_APPL_VAR) data);
# else
#  define Rte_ReadHook_Ap_Gsod_Vecu_Volt_f32_Start(arg1) ((void)(0))
# endif /* Rte_ReadHook_Ap_Gsod_Vecu_Volt_f32_Start */

# if defined (Rte_ReadHook_Ap_SrlComInput_AnaHwTorque_HwNm_f32_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_Ap_SrlComInput_AnaHwTorque_HwNm_f32_Return
# endif
# if defined (Rte_ReadHook_Ap_SrlComInput_AnaHwTorque_HwNm_f32_Return)
#  undef Rte_ReadHook_Ap_SrlComInput_AnaHwTorque_HwNm_f32_Return
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_Ap_SrlComInput_AnaHwTorque_HwNm_f32_Return(P2VAR(Float, AUTOMATIC, RTE_AP_SRLCOMINPUT_APPL_VAR) data);
# else
#  define Rte_ReadHook_Ap_SrlComInput_AnaHwTorque_HwNm_f32_Return(arg1) ((void)(0))
# endif /* Rte_ReadHook_Ap_SrlComInput_AnaHwTorque_HwNm_f32_Return */

# if defined (Rte_ReadHook_Ap_SrlComInput_AnaHwTorque_HwNm_f32_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_Ap_SrlComInput_AnaHwTorque_HwNm_f32_Start
# endif
# if defined (Rte_ReadHook_Ap_SrlComInput_AnaHwTorque_HwNm_f32_Start)
#  undef Rte_ReadHook_Ap_SrlComInput_AnaHwTorque_HwNm_f32_Start
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_Ap_SrlComInput_AnaHwTorque_HwNm_f32_Start(P2VAR(Float, AUTOMATIC, RTE_AP_SRLCOMINPUT_APPL_VAR) data);
# else
#  define Rte_ReadHook_Ap_SrlComInput_AnaHwTorque_HwNm_f32_Start(arg1) ((void)(0))
# endif /* Rte_ReadHook_Ap_SrlComInput_AnaHwTorque_HwNm_f32_Start */

# if defined (Rte_ReadHook_Ap_SrlComInput_DSTSlewStart_Cnt_lgc_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_Ap_SrlComInput_DSTSlewStart_Cnt_lgc_Return
# endif
# if defined (Rte_ReadHook_Ap_SrlComInput_DSTSlewStart_Cnt_lgc_Return)
#  undef Rte_ReadHook_Ap_SrlComInput_DSTSlewStart_Cnt_lgc_Return
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_Ap_SrlComInput_DSTSlewStart_Cnt_lgc_Return(P2VAR(Boolean, AUTOMATIC, RTE_AP_SRLCOMINPUT_APPL_VAR) data);
# else
#  define Rte_ReadHook_Ap_SrlComInput_DSTSlewStart_Cnt_lgc_Return(arg1) ((void)(0))
# endif /* Rte_ReadHook_Ap_SrlComInput_DSTSlewStart_Cnt_lgc_Return */

# if defined (Rte_ReadHook_Ap_SrlComInput_DSTSlewStart_Cnt_lgc_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_Ap_SrlComInput_DSTSlewStart_Cnt_lgc_Start
# endif
# if defined (Rte_ReadHook_Ap_SrlComInput_DSTSlewStart_Cnt_lgc_Start)
#  undef Rte_ReadHook_Ap_SrlComInput_DSTSlewStart_Cnt_lgc_Start
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_Ap_SrlComInput_DSTSlewStart_Cnt_lgc_Start(P2VAR(Boolean, AUTOMATIC, RTE_AP_SRLCOMINPUT_APPL_VAR) data);
# else
#  define Rte_ReadHook_Ap_SrlComInput_DSTSlewStart_Cnt_lgc_Start(arg1) ((void)(0))
# endif /* Rte_ReadHook_Ap_SrlComInput_DSTSlewStart_Cnt_lgc_Start */

# if defined (Rte_ReadHook_Ap_SrlComInput_DSTState_Cnt_u08_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_Ap_SrlComInput_DSTState_Cnt_u08_Return
# endif
# if defined (Rte_ReadHook_Ap_SrlComInput_DSTState_Cnt_u08_Return)
#  undef Rte_ReadHook_Ap_SrlComInput_DSTState_Cnt_u08_Return
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_Ap_SrlComInput_DSTState_Cnt_u08_Return(P2VAR(UInt8, AUTOMATIC, RTE_AP_SRLCOMINPUT_APPL_VAR) data);
# else
#  define Rte_ReadHook_Ap_SrlComInput_DSTState_Cnt_u08_Return(arg1) ((void)(0))
# endif /* Rte_ReadHook_Ap_SrlComInput_DSTState_Cnt_u08_Return */

# if defined (Rte_ReadHook_Ap_SrlComInput_DSTState_Cnt_u08_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_Ap_SrlComInput_DSTState_Cnt_u08_Start
# endif
# if defined (Rte_ReadHook_Ap_SrlComInput_DSTState_Cnt_u08_Start)
#  undef Rte_ReadHook_Ap_SrlComInput_DSTState_Cnt_u08_Start
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_Ap_SrlComInput_DSTState_Cnt_u08_Start(P2VAR(UInt8, AUTOMATIC, RTE_AP_SRLCOMINPUT_APPL_VAR) data);
# else
#  define Rte_ReadHook_Ap_SrlComInput_DSTState_Cnt_u08_Start(arg1) ((void)(0))
# endif /* Rte_ReadHook_Ap_SrlComInput_DSTState_Cnt_u08_Start */

# if defined (Rte_ReadHook_Ap_SrlComInput_DefaultVehSpd_Cnt_lgc_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_Ap_SrlComInput_DefaultVehSpd_Cnt_lgc_Return
# endif
# if defined (Rte_ReadHook_Ap_SrlComInput_DefaultVehSpd_Cnt_lgc_Return)
#  undef Rte_ReadHook_Ap_SrlComInput_DefaultVehSpd_Cnt_lgc_Return
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_Ap_SrlComInput_DefaultVehSpd_Cnt_lgc_Return(P2VAR(Boolean, AUTOMATIC, RTE_AP_SRLCOMINPUT_APPL_VAR) data);
# else
#  define Rte_ReadHook_Ap_SrlComInput_DefaultVehSpd_Cnt_lgc_Return(arg1) ((void)(0))
# endif /* Rte_ReadHook_Ap_SrlComInput_DefaultVehSpd_Cnt_lgc_Return */

# if defined (Rte_ReadHook_Ap_SrlComInput_DefaultVehSpd_Cnt_lgc_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_Ap_SrlComInput_DefaultVehSpd_Cnt_lgc_Start
# endif
# if defined (Rte_ReadHook_Ap_SrlComInput_DefaultVehSpd_Cnt_lgc_Start)
#  undef Rte_ReadHook_Ap_SrlComInput_DefaultVehSpd_Cnt_lgc_Start
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_Ap_SrlComInput_DefaultVehSpd_Cnt_lgc_Start(P2VAR(Boolean, AUTOMATIC, RTE_AP_SRLCOMINPUT_APPL_VAR) data);
# else
#  define Rte_ReadHook_Ap_SrlComInput_DefaultVehSpd_Cnt_lgc_Start(arg1) ((void)(0))
# endif /* Rte_ReadHook_Ap_SrlComInput_DefaultVehSpd_Cnt_lgc_Start */

# if defined (Rte_ReadHook_Ap_SrlComInput_EstFric_HwNm_f32_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_Ap_SrlComInput_EstFric_HwNm_f32_Return
# endif
# if defined (Rte_ReadHook_Ap_SrlComInput_EstFric_HwNm_f32_Return)
#  undef Rte_ReadHook_Ap_SrlComInput_EstFric_HwNm_f32_Return
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_Ap_SrlComInput_EstFric_HwNm_f32_Return(P2VAR(Float, AUTOMATIC, RTE_AP_SRLCOMINPUT_APPL_VAR) data);
# else
#  define Rte_ReadHook_Ap_SrlComInput_EstFric_HwNm_f32_Return(arg1) ((void)(0))
# endif /* Rte_ReadHook_Ap_SrlComInput_EstFric_HwNm_f32_Return */

# if defined (Rte_ReadHook_Ap_SrlComInput_EstFric_HwNm_f32_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_Ap_SrlComInput_EstFric_HwNm_f32_Start
# endif
# if defined (Rte_ReadHook_Ap_SrlComInput_EstFric_HwNm_f32_Start)
#  undef Rte_ReadHook_Ap_SrlComInput_EstFric_HwNm_f32_Start
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_Ap_SrlComInput_EstFric_HwNm_f32_Start(P2VAR(Float, AUTOMATIC, RTE_AP_SRLCOMINPUT_APPL_VAR) data);
# else
#  define Rte_ReadHook_Ap_SrlComInput_EstFric_HwNm_f32_Start(arg1) ((void)(0))
# endif /* Rte_ReadHook_Ap_SrlComInput_EstFric_HwNm_f32_Start */

# if defined (Rte_ReadHook_Ap_SrlComInput_HaLFState_Cnt_u08_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_Ap_SrlComInput_HaLFState_Cnt_u08_Return
# endif
# if defined (Rte_ReadHook_Ap_SrlComInput_HaLFState_Cnt_u08_Return)
#  undef Rte_ReadHook_Ap_SrlComInput_HaLFState_Cnt_u08_Return
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_Ap_SrlComInput_HaLFState_Cnt_u08_Return(P2VAR(UInt8, AUTOMATIC, RTE_AP_SRLCOMINPUT_APPL_VAR) data);
# else
#  define Rte_ReadHook_Ap_SrlComInput_HaLFState_Cnt_u08_Return(arg1) ((void)(0))
# endif /* Rte_ReadHook_Ap_SrlComInput_HaLFState_Cnt_u08_Return */

# if defined (Rte_ReadHook_Ap_SrlComInput_HaLFState_Cnt_u08_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_Ap_SrlComInput_HaLFState_Cnt_u08_Start
# endif
# if defined (Rte_ReadHook_Ap_SrlComInput_HaLFState_Cnt_u08_Start)
#  undef Rte_ReadHook_Ap_SrlComInput_HaLFState_Cnt_u08_Start
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_Ap_SrlComInput_HaLFState_Cnt_u08_Start(P2VAR(UInt8, AUTOMATIC, RTE_AP_SRLCOMINPUT_APPL_VAR) data);
# else
#  define Rte_ReadHook_Ap_SrlComInput_HaLFState_Cnt_u08_Start(arg1) ((void)(0))
# endif /* Rte_ReadHook_Ap_SrlComInput_HaLFState_Cnt_u08_Start */

# if defined (Rte_ReadHook_Ap_SrlComInput_HaLFSuspend_Cnt_lgc_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_Ap_SrlComInput_HaLFSuspend_Cnt_lgc_Return
# endif
# if defined (Rte_ReadHook_Ap_SrlComInput_HaLFSuspend_Cnt_lgc_Return)
#  undef Rte_ReadHook_Ap_SrlComInput_HaLFSuspend_Cnt_lgc_Return
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_Ap_SrlComInput_HaLFSuspend_Cnt_lgc_Return(P2VAR(Boolean, AUTOMATIC, RTE_AP_SRLCOMINPUT_APPL_VAR) data);
# else
#  define Rte_ReadHook_Ap_SrlComInput_HaLFSuspend_Cnt_lgc_Return(arg1) ((void)(0))
# endif /* Rte_ReadHook_Ap_SrlComInput_HaLFSuspend_Cnt_lgc_Return */

# if defined (Rte_ReadHook_Ap_SrlComInput_HaLFSuspend_Cnt_lgc_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_Ap_SrlComInput_HaLFSuspend_Cnt_lgc_Start
# endif
# if defined (Rte_ReadHook_Ap_SrlComInput_HaLFSuspend_Cnt_lgc_Start)
#  undef Rte_ReadHook_Ap_SrlComInput_HaLFSuspend_Cnt_lgc_Start
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_Ap_SrlComInput_HaLFSuspend_Cnt_lgc_Start(P2VAR(Boolean, AUTOMATIC, RTE_AP_SRLCOMINPUT_APPL_VAR) data);
# else
#  define Rte_ReadHook_Ap_SrlComInput_HaLFSuspend_Cnt_lgc_Start(arg1) ((void)(0))
# endif /* Rte_ReadHook_Ap_SrlComInput_HaLFSuspend_Cnt_lgc_Start */

# if defined (Rte_ReadHook_Ap_SrlComInput_HandsOnDetect_Cnt_lgc_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_Ap_SrlComInput_HandsOnDetect_Cnt_lgc_Return
# endif
# if defined (Rte_ReadHook_Ap_SrlComInput_HandsOnDetect_Cnt_lgc_Return)
#  undef Rte_ReadHook_Ap_SrlComInput_HandsOnDetect_Cnt_lgc_Return
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_Ap_SrlComInput_HandsOnDetect_Cnt_lgc_Return(P2VAR(Boolean, AUTOMATIC, RTE_AP_SRLCOMINPUT_APPL_VAR) data);
# else
#  define Rte_ReadHook_Ap_SrlComInput_HandsOnDetect_Cnt_lgc_Return(arg1) ((void)(0))
# endif /* Rte_ReadHook_Ap_SrlComInput_HandsOnDetect_Cnt_lgc_Return */

# if defined (Rte_ReadHook_Ap_SrlComInput_HandsOnDetect_Cnt_lgc_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_Ap_SrlComInput_HandsOnDetect_Cnt_lgc_Start
# endif
# if defined (Rte_ReadHook_Ap_SrlComInput_HandsOnDetect_Cnt_lgc_Start)
#  undef Rte_ReadHook_Ap_SrlComInput_HandsOnDetect_Cnt_lgc_Start
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_Ap_SrlComInput_HandsOnDetect_Cnt_lgc_Start(P2VAR(Boolean, AUTOMATIC, RTE_AP_SRLCOMINPUT_APPL_VAR) data);
# else
#  define Rte_ReadHook_Ap_SrlComInput_HandsOnDetect_Cnt_lgc_Start(arg1) ((void)(0))
# endif /* Rte_ReadHook_Ap_SrlComInput_HandsOnDetect_Cnt_lgc_Start */

# if defined (Rte_ReadHook_Ap_SrlComInput_MEC_Cnt_enum_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_Ap_SrlComInput_MEC_Cnt_enum_Return
# endif
# if defined (Rte_ReadHook_Ap_SrlComInput_MEC_Cnt_enum_Return)
#  undef Rte_ReadHook_Ap_SrlComInput_MEC_Cnt_enum_Return
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_Ap_SrlComInput_MEC_Cnt_enum_Return(P2VAR(ManufModeType, AUTOMATIC, RTE_AP_SRLCOMINPUT_APPL_VAR) data);
# else
#  define Rte_ReadHook_Ap_SrlComInput_MEC_Cnt_enum_Return(arg1) ((void)(0))
# endif /* Rte_ReadHook_Ap_SrlComInput_MEC_Cnt_enum_Return */

# if defined (Rte_ReadHook_Ap_SrlComInput_MEC_Cnt_enum_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_Ap_SrlComInput_MEC_Cnt_enum_Start
# endif
# if defined (Rte_ReadHook_Ap_SrlComInput_MEC_Cnt_enum_Start)
#  undef Rte_ReadHook_Ap_SrlComInput_MEC_Cnt_enum_Start
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_Ap_SrlComInput_MEC_Cnt_enum_Start(P2VAR(ManufModeType, AUTOMATIC, RTE_AP_SRLCOMINPUT_APPL_VAR) data);
# else
#  define Rte_ReadHook_Ap_SrlComInput_MEC_Cnt_enum_Start(arg1) ((void)(0))
# endif /* Rte_ReadHook_Ap_SrlComInput_MEC_Cnt_enum_Start */

# if defined (Rte_ReadHook_Ap_SrlComInput_PABoostCurveSwitch_Cnt_lgc_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_Ap_SrlComInput_PABoostCurveSwitch_Cnt_lgc_Return
# endif
# if defined (Rte_ReadHook_Ap_SrlComInput_PABoostCurveSwitch_Cnt_lgc_Return)
#  undef Rte_ReadHook_Ap_SrlComInput_PABoostCurveSwitch_Cnt_lgc_Return
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_Ap_SrlComInput_PABoostCurveSwitch_Cnt_lgc_Return(P2VAR(Boolean, AUTOMATIC, RTE_AP_SRLCOMINPUT_APPL_VAR) data);
# else
#  define Rte_ReadHook_Ap_SrlComInput_PABoostCurveSwitch_Cnt_lgc_Return(arg1) ((void)(0))
# endif /* Rte_ReadHook_Ap_SrlComInput_PABoostCurveSwitch_Cnt_lgc_Return */

# if defined (Rte_ReadHook_Ap_SrlComInput_PABoostCurveSwitch_Cnt_lgc_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_Ap_SrlComInput_PABoostCurveSwitch_Cnt_lgc_Start
# endif
# if defined (Rte_ReadHook_Ap_SrlComInput_PABoostCurveSwitch_Cnt_lgc_Start)
#  undef Rte_ReadHook_Ap_SrlComInput_PABoostCurveSwitch_Cnt_lgc_Start
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_Ap_SrlComInput_PABoostCurveSwitch_Cnt_lgc_Start(P2VAR(Boolean, AUTOMATIC, RTE_AP_SRLCOMINPUT_APPL_VAR) data);
# else
#  define Rte_ReadHook_Ap_SrlComInput_PABoostCurveSwitch_Cnt_lgc_Start(arg1) ((void)(0))
# endif /* Rte_ReadHook_Ap_SrlComInput_PABoostCurveSwitch_Cnt_lgc_Start */

# if defined (Rte_ReadHook_Ap_SrlComInput_PrkAssistState_Cnt_u08_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_Ap_SrlComInput_PrkAssistState_Cnt_u08_Return
# endif
# if defined (Rte_ReadHook_Ap_SrlComInput_PrkAssistState_Cnt_u08_Return)
#  undef Rte_ReadHook_Ap_SrlComInput_PrkAssistState_Cnt_u08_Return
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_Ap_SrlComInput_PrkAssistState_Cnt_u08_Return(P2VAR(UInt8, AUTOMATIC, RTE_AP_SRLCOMINPUT_APPL_VAR) data);
# else
#  define Rte_ReadHook_Ap_SrlComInput_PrkAssistState_Cnt_u08_Return(arg1) ((void)(0))
# endif /* Rte_ReadHook_Ap_SrlComInput_PrkAssistState_Cnt_u08_Return */

# if defined (Rte_ReadHook_Ap_SrlComInput_PrkAssistState_Cnt_u08_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_Ap_SrlComInput_PrkAssistState_Cnt_u08_Start
# endif
# if defined (Rte_ReadHook_Ap_SrlComInput_PrkAssistState_Cnt_u08_Start)
#  undef Rte_ReadHook_Ap_SrlComInput_PrkAssistState_Cnt_u08_Start
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_Ap_SrlComInput_PrkAssistState_Cnt_u08_Start(P2VAR(UInt8, AUTOMATIC, RTE_AP_SRLCOMINPUT_APPL_VAR) data);
# else
#  define Rte_ReadHook_Ap_SrlComInput_PrkAssistState_Cnt_u08_Start(arg1) ((void)(0))
# endif /* Rte_ReadHook_Ap_SrlComInput_PrkAssistState_Cnt_u08_Start */

# if defined (Rte_ReadHook_Ap_SrlComInput_PrkAssistSuspend_Cnt_lgc_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_Ap_SrlComInput_PrkAssistSuspend_Cnt_lgc_Return
# endif
# if defined (Rte_ReadHook_Ap_SrlComInput_PrkAssistSuspend_Cnt_lgc_Return)
#  undef Rte_ReadHook_Ap_SrlComInput_PrkAssistSuspend_Cnt_lgc_Return
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_Ap_SrlComInput_PrkAssistSuspend_Cnt_lgc_Return(P2VAR(Boolean, AUTOMATIC, RTE_AP_SRLCOMINPUT_APPL_VAR) data);
# else
#  define Rte_ReadHook_Ap_SrlComInput_PrkAssistSuspend_Cnt_lgc_Return(arg1) ((void)(0))
# endif /* Rte_ReadHook_Ap_SrlComInput_PrkAssistSuspend_Cnt_lgc_Return */

# if defined (Rte_ReadHook_Ap_SrlComInput_PrkAssistSuspend_Cnt_lgc_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_Ap_SrlComInput_PrkAssistSuspend_Cnt_lgc_Start
# endif
# if defined (Rte_ReadHook_Ap_SrlComInput_PrkAssistSuspend_Cnt_lgc_Start)
#  undef Rte_ReadHook_Ap_SrlComInput_PrkAssistSuspend_Cnt_lgc_Start
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_Ap_SrlComInput_PrkAssistSuspend_Cnt_lgc_Start(P2VAR(Boolean, AUTOMATIC, RTE_AP_SRLCOMINPUT_APPL_VAR) data);
# else
#  define Rte_ReadHook_Ap_SrlComInput_PrkAssistSuspend_Cnt_lgc_Start(arg1) ((void)(0))
# endif /* Rte_ReadHook_Ap_SrlComInput_PrkAssistSuspend_Cnt_lgc_Start */

# if defined (Rte_ReadHook_Ap_SrlComInput_RxMsgsSrlComSvcDft_Cnt_lgc_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_Ap_SrlComInput_RxMsgsSrlComSvcDft_Cnt_lgc_Return
# endif
# if defined (Rte_ReadHook_Ap_SrlComInput_RxMsgsSrlComSvcDft_Cnt_lgc_Return)
#  undef Rte_ReadHook_Ap_SrlComInput_RxMsgsSrlComSvcDft_Cnt_lgc_Return
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_Ap_SrlComInput_RxMsgsSrlComSvcDft_Cnt_lgc_Return(P2VAR(Boolean, AUTOMATIC, RTE_AP_SRLCOMINPUT_APPL_VAR) data);
# else
#  define Rte_ReadHook_Ap_SrlComInput_RxMsgsSrlComSvcDft_Cnt_lgc_Return(arg1) ((void)(0))
# endif /* Rte_ReadHook_Ap_SrlComInput_RxMsgsSrlComSvcDft_Cnt_lgc_Return */

# if defined (Rte_ReadHook_Ap_SrlComInput_RxMsgsSrlComSvcDft_Cnt_lgc_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_Ap_SrlComInput_RxMsgsSrlComSvcDft_Cnt_lgc_Start
# endif
# if defined (Rte_ReadHook_Ap_SrlComInput_RxMsgsSrlComSvcDft_Cnt_lgc_Start)
#  undef Rte_ReadHook_Ap_SrlComInput_RxMsgsSrlComSvcDft_Cnt_lgc_Start
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_Ap_SrlComInput_RxMsgsSrlComSvcDft_Cnt_lgc_Start(P2VAR(Boolean, AUTOMATIC, RTE_AP_SRLCOMINPUT_APPL_VAR) data);
# else
#  define Rte_ReadHook_Ap_SrlComInput_RxMsgsSrlComSvcDft_Cnt_lgc_Start(arg1) ((void)(0))
# endif /* Rte_ReadHook_Ap_SrlComInput_RxMsgsSrlComSvcDft_Cnt_lgc_Start */

# if defined (Rte_ReadHook_Ap_SrlComInput_StrClmTrq_HwNm_f32_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_Ap_SrlComInput_StrClmTrq_HwNm_f32_Return
# endif
# if defined (Rte_ReadHook_Ap_SrlComInput_StrClmTrq_HwNm_f32_Return)
#  undef Rte_ReadHook_Ap_SrlComInput_StrClmTrq_HwNm_f32_Return
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_Ap_SrlComInput_StrClmTrq_HwNm_f32_Return(P2VAR(Float, AUTOMATIC, RTE_AP_SRLCOMINPUT_APPL_VAR) data);
# else
#  define Rte_ReadHook_Ap_SrlComInput_StrClmTrq_HwNm_f32_Return(arg1) ((void)(0))
# endif /* Rte_ReadHook_Ap_SrlComInput_StrClmTrq_HwNm_f32_Return */

# if defined (Rte_ReadHook_Ap_SrlComInput_StrClmTrq_HwNm_f32_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_Ap_SrlComInput_StrClmTrq_HwNm_f32_Start
# endif
# if defined (Rte_ReadHook_Ap_SrlComInput_StrClmTrq_HwNm_f32_Start)
#  undef Rte_ReadHook_Ap_SrlComInput_StrClmTrq_HwNm_f32_Start
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_Ap_SrlComInput_StrClmTrq_HwNm_f32_Start(P2VAR(Float, AUTOMATIC, RTE_AP_SRLCOMINPUT_APPL_VAR) data);
# else
#  define Rte_ReadHook_Ap_SrlComInput_StrClmTrq_HwNm_f32_Start(arg1) ((void)(0))
# endif /* Rte_ReadHook_Ap_SrlComInput_StrClmTrq_HwNm_f32_Start */

# if defined (Rte_ReadHook_Ap_SrlComOutput_ATermActive_Cnt_lgc_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_Ap_SrlComOutput_ATermActive_Cnt_lgc_Return
# endif
# if defined (Rte_ReadHook_Ap_SrlComOutput_ATermActive_Cnt_lgc_Return)
#  undef Rte_ReadHook_Ap_SrlComOutput_ATermActive_Cnt_lgc_Return
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_Ap_SrlComOutput_ATermActive_Cnt_lgc_Return(P2VAR(Boolean, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_VAR) data);
# else
#  define Rte_ReadHook_Ap_SrlComOutput_ATermActive_Cnt_lgc_Return(arg1) ((void)(0))
# endif /* Rte_ReadHook_Ap_SrlComOutput_ATermActive_Cnt_lgc_Return */

# if defined (Rte_ReadHook_Ap_SrlComOutput_ATermActive_Cnt_lgc_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_Ap_SrlComOutput_ATermActive_Cnt_lgc_Start
# endif
# if defined (Rte_ReadHook_Ap_SrlComOutput_ATermActive_Cnt_lgc_Start)
#  undef Rte_ReadHook_Ap_SrlComOutput_ATermActive_Cnt_lgc_Start
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_Ap_SrlComOutput_ATermActive_Cnt_lgc_Start(P2VAR(Boolean, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_VAR) data);
# else
#  define Rte_ReadHook_Ap_SrlComOutput_ATermActive_Cnt_lgc_Start(arg1) ((void)(0))
# endif /* Rte_ReadHook_Ap_SrlComOutput_ATermActive_Cnt_lgc_Start */

# if defined (Rte_ReadHook_Ap_SrlComOutput_ActiveFunctionBits_Cnt_u08_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_Ap_SrlComOutput_ActiveFunctionBits_Cnt_u08_Return
# endif
# if defined (Rte_ReadHook_Ap_SrlComOutput_ActiveFunctionBits_Cnt_u08_Return)
#  undef Rte_ReadHook_Ap_SrlComOutput_ActiveFunctionBits_Cnt_u08_Return
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_Ap_SrlComOutput_ActiveFunctionBits_Cnt_u08_Return(P2VAR(UInt8, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_VAR) data);
# else
#  define Rte_ReadHook_Ap_SrlComOutput_ActiveFunctionBits_Cnt_u08_Return(arg1) ((void)(0))
# endif /* Rte_ReadHook_Ap_SrlComOutput_ActiveFunctionBits_Cnt_u08_Return */

# if defined (Rte_ReadHook_Ap_SrlComOutput_ActiveFunctionBits_Cnt_u08_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_Ap_SrlComOutput_ActiveFunctionBits_Cnt_u08_Start
# endif
# if defined (Rte_ReadHook_Ap_SrlComOutput_ActiveFunctionBits_Cnt_u08_Start)
#  undef Rte_ReadHook_Ap_SrlComOutput_ActiveFunctionBits_Cnt_u08_Start
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_Ap_SrlComOutput_ActiveFunctionBits_Cnt_u08_Start(P2VAR(UInt8, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_VAR) data);
# else
#  define Rte_ReadHook_Ap_SrlComOutput_ActiveFunctionBits_Cnt_u08_Start(arg1) ((void)(0))
# endif /* Rte_ReadHook_Ap_SrlComOutput_ActiveFunctionBits_Cnt_u08_Start */

# if defined (Rte_ReadHook_Ap_SrlComOutput_ActiveTunSet_Cnt_u16_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_Ap_SrlComOutput_ActiveTunSet_Cnt_u16_Return
# endif
# if defined (Rte_ReadHook_Ap_SrlComOutput_ActiveTunSet_Cnt_u16_Return)
#  undef Rte_ReadHook_Ap_SrlComOutput_ActiveTunSet_Cnt_u16_Return
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_Ap_SrlComOutput_ActiveTunSet_Cnt_u16_Return(P2VAR(UInt16, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_VAR) data);
# else
#  define Rte_ReadHook_Ap_SrlComOutput_ActiveTunSet_Cnt_u16_Return(arg1) ((void)(0))
# endif /* Rte_ReadHook_Ap_SrlComOutput_ActiveTunSet_Cnt_u16_Return */

# if defined (Rte_ReadHook_Ap_SrlComOutput_ActiveTunSet_Cnt_u16_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_Ap_SrlComOutput_ActiveTunSet_Cnt_u16_Start
# endif
# if defined (Rte_ReadHook_Ap_SrlComOutput_ActiveTunSet_Cnt_u16_Start)
#  undef Rte_ReadHook_Ap_SrlComOutput_ActiveTunSet_Cnt_u16_Start
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_Ap_SrlComOutput_ActiveTunSet_Cnt_u16_Start(P2VAR(UInt16, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_VAR) data);
# else
#  define Rte_ReadHook_Ap_SrlComOutput_ActiveTunSet_Cnt_u16_Start(arg1) ((void)(0))
# endif /* Rte_ReadHook_Ap_SrlComOutput_ActiveTunSet_Cnt_u16_Start */

# if defined (Rte_ReadHook_Ap_SrlComOutput_CRFMtrTrqCmd_MtrNm_f32_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_Ap_SrlComOutput_CRFMtrTrqCmd_MtrNm_f32_Return
# endif
# if defined (Rte_ReadHook_Ap_SrlComOutput_CRFMtrTrqCmd_MtrNm_f32_Return)
#  undef Rte_ReadHook_Ap_SrlComOutput_CRFMtrTrqCmd_MtrNm_f32_Return
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_Ap_SrlComOutput_CRFMtrTrqCmd_MtrNm_f32_Return(P2VAR(Float, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_VAR) data);
# else
#  define Rte_ReadHook_Ap_SrlComOutput_CRFMtrTrqCmd_MtrNm_f32_Return(arg1) ((void)(0))
# endif /* Rte_ReadHook_Ap_SrlComOutput_CRFMtrTrqCmd_MtrNm_f32_Return */

# if defined (Rte_ReadHook_Ap_SrlComOutput_CRFMtrTrqCmd_MtrNm_f32_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_Ap_SrlComOutput_CRFMtrTrqCmd_MtrNm_f32_Start
# endif
# if defined (Rte_ReadHook_Ap_SrlComOutput_CRFMtrTrqCmd_MtrNm_f32_Start)
#  undef Rte_ReadHook_Ap_SrlComOutput_CRFMtrTrqCmd_MtrNm_f32_Start
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_Ap_SrlComOutput_CRFMtrTrqCmd_MtrNm_f32_Start(P2VAR(Float, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_VAR) data);
# else
#  define Rte_ReadHook_Ap_SrlComOutput_CRFMtrTrqCmd_MtrNm_f32_Start(arg1) ((void)(0))
# endif /* Rte_ReadHook_Ap_SrlComOutput_CRFMtrTrqCmd_MtrNm_f32_Start */

# if defined (Rte_ReadHook_Ap_SrlComOutput_CTermActive_Cnt_lgc_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_Ap_SrlComOutput_CTermActive_Cnt_lgc_Return
# endif
# if defined (Rte_ReadHook_Ap_SrlComOutput_CTermActive_Cnt_lgc_Return)
#  undef Rte_ReadHook_Ap_SrlComOutput_CTermActive_Cnt_lgc_Return
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_Ap_SrlComOutput_CTermActive_Cnt_lgc_Return(P2VAR(Boolean, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_VAR) data);
# else
#  define Rte_ReadHook_Ap_SrlComOutput_CTermActive_Cnt_lgc_Return(arg1) ((void)(0))
# endif /* Rte_ReadHook_Ap_SrlComOutput_CTermActive_Cnt_lgc_Return */

# if defined (Rte_ReadHook_Ap_SrlComOutput_CTermActive_Cnt_lgc_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_Ap_SrlComOutput_CTermActive_Cnt_lgc_Start
# endif
# if defined (Rte_ReadHook_Ap_SrlComOutput_CTermActive_Cnt_lgc_Start)
#  undef Rte_ReadHook_Ap_SrlComOutput_CTermActive_Cnt_lgc_Start
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_Ap_SrlComOutput_CTermActive_Cnt_lgc_Start(P2VAR(Boolean, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_VAR) data);
# else
#  define Rte_ReadHook_Ap_SrlComOutput_CTermActive_Cnt_lgc_Start(arg1) ((void)(0))
# endif /* Rte_ReadHook_Ap_SrlComOutput_CTermActive_Cnt_lgc_Start */

# if defined (Rte_ReadHook_Ap_SrlComOutput_CanMsgReceived_Cnt_lgc_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_Ap_SrlComOutput_CanMsgReceived_Cnt_lgc_Return
# endif
# if defined (Rte_ReadHook_Ap_SrlComOutput_CanMsgReceived_Cnt_lgc_Return)
#  undef Rte_ReadHook_Ap_SrlComOutput_CanMsgReceived_Cnt_lgc_Return
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_Ap_SrlComOutput_CanMsgReceived_Cnt_lgc_Return(P2VAR(Boolean, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_VAR) data);
# else
#  define Rte_ReadHook_Ap_SrlComOutput_CanMsgReceived_Cnt_lgc_Return(arg1) ((void)(0))
# endif /* Rte_ReadHook_Ap_SrlComOutput_CanMsgReceived_Cnt_lgc_Return */

# if defined (Rte_ReadHook_Ap_SrlComOutput_CanMsgReceived_Cnt_lgc_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_Ap_SrlComOutput_CanMsgReceived_Cnt_lgc_Start
# endif
# if defined (Rte_ReadHook_Ap_SrlComOutput_CanMsgReceived_Cnt_lgc_Start)
#  undef Rte_ReadHook_Ap_SrlComOutput_CanMsgReceived_Cnt_lgc_Start
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_Ap_SrlComOutput_CanMsgReceived_Cnt_lgc_Start(P2VAR(Boolean, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_VAR) data);
# else
#  define Rte_ReadHook_Ap_SrlComOutput_CanMsgReceived_Cnt_lgc_Start(arg1) ((void)(0))
# endif /* Rte_ReadHook_Ap_SrlComOutput_CanMsgReceived_Cnt_lgc_Start */

# if defined (Rte_ReadHook_Ap_SrlComOutput_DSTEOLDisable_Cnt_lgc_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_Ap_SrlComOutput_DSTEOLDisable_Cnt_lgc_Return
# endif
# if defined (Rte_ReadHook_Ap_SrlComOutput_DSTEOLDisable_Cnt_lgc_Return)
#  undef Rte_ReadHook_Ap_SrlComOutput_DSTEOLDisable_Cnt_lgc_Return
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_Ap_SrlComOutput_DSTEOLDisable_Cnt_lgc_Return(P2VAR(Boolean, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_VAR) data);
# else
#  define Rte_ReadHook_Ap_SrlComOutput_DSTEOLDisable_Cnt_lgc_Return(arg1) ((void)(0))
# endif /* Rte_ReadHook_Ap_SrlComOutput_DSTEOLDisable_Cnt_lgc_Return */

# if defined (Rte_ReadHook_Ap_SrlComOutput_DSTEOLDisable_Cnt_lgc_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_Ap_SrlComOutput_DSTEOLDisable_Cnt_lgc_Start
# endif
# if defined (Rte_ReadHook_Ap_SrlComOutput_DSTEOLDisable_Cnt_lgc_Start)
#  undef Rte_ReadHook_Ap_SrlComOutput_DSTEOLDisable_Cnt_lgc_Start
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_Ap_SrlComOutput_DSTEOLDisable_Cnt_lgc_Start(P2VAR(Boolean, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_VAR) data);
# else
#  define Rte_ReadHook_Ap_SrlComOutput_DSTEOLDisable_Cnt_lgc_Start(arg1) ((void)(0))
# endif /* Rte_ReadHook_Ap_SrlComOutput_DSTEOLDisable_Cnt_lgc_Start */

# if defined (Rte_ReadHook_Ap_SrlComOutput_DSTExtSystemFltActive_Cnt_lgc_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_Ap_SrlComOutput_DSTExtSystemFltActive_Cnt_lgc_Return
# endif
# if defined (Rte_ReadHook_Ap_SrlComOutput_DSTExtSystemFltActive_Cnt_lgc_Return)
#  undef Rte_ReadHook_Ap_SrlComOutput_DSTExtSystemFltActive_Cnt_lgc_Return
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_Ap_SrlComOutput_DSTExtSystemFltActive_Cnt_lgc_Return(P2VAR(Boolean, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_VAR) data);
# else
#  define Rte_ReadHook_Ap_SrlComOutput_DSTExtSystemFltActive_Cnt_lgc_Return(arg1) ((void)(0))
# endif /* Rte_ReadHook_Ap_SrlComOutput_DSTExtSystemFltActive_Cnt_lgc_Return */

# if defined (Rte_ReadHook_Ap_SrlComOutput_DSTExtSystemFltActive_Cnt_lgc_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_Ap_SrlComOutput_DSTExtSystemFltActive_Cnt_lgc_Start
# endif
# if defined (Rte_ReadHook_Ap_SrlComOutput_DSTExtSystemFltActive_Cnt_lgc_Start)
#  undef Rte_ReadHook_Ap_SrlComOutput_DSTExtSystemFltActive_Cnt_lgc_Start
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_Ap_SrlComOutput_DSTExtSystemFltActive_Cnt_lgc_Start(P2VAR(Boolean, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_VAR) data);
# else
#  define Rte_ReadHook_Ap_SrlComOutput_DSTExtSystemFltActive_Cnt_lgc_Start(arg1) ((void)(0))
# endif /* Rte_ReadHook_Ap_SrlComOutput_DSTExtSystemFltActive_Cnt_lgc_Start */

# if defined (Rte_ReadHook_Ap_SrlComOutput_DSTState_Cnt_u08_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_Ap_SrlComOutput_DSTState_Cnt_u08_Return
# endif
# if defined (Rte_ReadHook_Ap_SrlComOutput_DSTState_Cnt_u08_Return)
#  undef Rte_ReadHook_Ap_SrlComOutput_DSTState_Cnt_u08_Return
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_Ap_SrlComOutput_DSTState_Cnt_u08_Return(P2VAR(UInt8, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_VAR) data);
# else
#  define Rte_ReadHook_Ap_SrlComOutput_DSTState_Cnt_u08_Return(arg1) ((void)(0))
# endif /* Rte_ReadHook_Ap_SrlComOutput_DSTState_Cnt_u08_Return */

# if defined (Rte_ReadHook_Ap_SrlComOutput_DSTState_Cnt_u08_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_Ap_SrlComOutput_DSTState_Cnt_u08_Start
# endif
# if defined (Rte_ReadHook_Ap_SrlComOutput_DSTState_Cnt_u08_Start)
#  undef Rte_ReadHook_Ap_SrlComOutput_DSTState_Cnt_u08_Start
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_Ap_SrlComOutput_DSTState_Cnt_u08_Start(P2VAR(UInt8, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_VAR) data);
# else
#  define Rte_ReadHook_Ap_SrlComOutput_DSTState_Cnt_u08_Start(arg1) ((void)(0))
# endif /* Rte_ReadHook_Ap_SrlComOutput_DSTState_Cnt_u08_Start */

# if defined (Rte_ReadHook_Ap_SrlComOutput_DesiredTunPersTypH_Cnt_u08_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_Ap_SrlComOutput_DesiredTunPersTypH_Cnt_u08_Return
# endif
# if defined (Rte_ReadHook_Ap_SrlComOutput_DesiredTunPersTypH_Cnt_u08_Return)
#  undef Rte_ReadHook_Ap_SrlComOutput_DesiredTunPersTypH_Cnt_u08_Return
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_Ap_SrlComOutput_DesiredTunPersTypH_Cnt_u08_Return(P2VAR(UInt8, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_VAR) data);
# else
#  define Rte_ReadHook_Ap_SrlComOutput_DesiredTunPersTypH_Cnt_u08_Return(arg1) ((void)(0))
# endif /* Rte_ReadHook_Ap_SrlComOutput_DesiredTunPersTypH_Cnt_u08_Return */

# if defined (Rte_ReadHook_Ap_SrlComOutput_DesiredTunPersTypH_Cnt_u08_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_Ap_SrlComOutput_DesiredTunPersTypH_Cnt_u08_Start
# endif
# if defined (Rte_ReadHook_Ap_SrlComOutput_DesiredTunPersTypH_Cnt_u08_Start)
#  undef Rte_ReadHook_Ap_SrlComOutput_DesiredTunPersTypH_Cnt_u08_Start
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_Ap_SrlComOutput_DesiredTunPersTypH_Cnt_u08_Start(P2VAR(UInt8, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_VAR) data);
# else
#  define Rte_ReadHook_Ap_SrlComOutput_DesiredTunPersTypH_Cnt_u08_Start(arg1) ((void)(0))
# endif /* Rte_ReadHook_Ap_SrlComOutput_DesiredTunPersTypH_Cnt_u08_Start */

# if defined (Rte_ReadHook_Ap_SrlComOutput_DesiredTunPers_Cnt_u16_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_Ap_SrlComOutput_DesiredTunPers_Cnt_u16_Return
# endif
# if defined (Rte_ReadHook_Ap_SrlComOutput_DesiredTunPers_Cnt_u16_Return)
#  undef Rte_ReadHook_Ap_SrlComOutput_DesiredTunPers_Cnt_u16_Return
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_Ap_SrlComOutput_DesiredTunPers_Cnt_u16_Return(P2VAR(UInt16, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_VAR) data);
# else
#  define Rte_ReadHook_Ap_SrlComOutput_DesiredTunPers_Cnt_u16_Return(arg1) ((void)(0))
# endif /* Rte_ReadHook_Ap_SrlComOutput_DesiredTunPers_Cnt_u16_Return */

# if defined (Rte_ReadHook_Ap_SrlComOutput_DesiredTunPers_Cnt_u16_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_Ap_SrlComOutput_DesiredTunPers_Cnt_u16_Start
# endif
# if defined (Rte_ReadHook_Ap_SrlComOutput_DesiredTunPers_Cnt_u16_Start)
#  undef Rte_ReadHook_Ap_SrlComOutput_DesiredTunPers_Cnt_u16_Start
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_Ap_SrlComOutput_DesiredTunPers_Cnt_u16_Start(P2VAR(UInt16, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_VAR) data);
# else
#  define Rte_ReadHook_Ap_SrlComOutput_DesiredTunPers_Cnt_u16_Start(arg1) ((void)(0))
# endif /* Rte_ReadHook_Ap_SrlComOutput_DesiredTunPers_Cnt_u16_Start */

# if defined (Rte_ReadHook_Ap_SrlComOutput_DiagStsNonRecRmpToZeroFltPres_Cnt_lgc_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_Ap_SrlComOutput_DiagStsNonRecRmpToZeroFltPres_Cnt_lgc_Return
# endif
# if defined (Rte_ReadHook_Ap_SrlComOutput_DiagStsNonRecRmpToZeroFltPres_Cnt_lgc_Return)
#  undef Rte_ReadHook_Ap_SrlComOutput_DiagStsNonRecRmpToZeroFltPres_Cnt_lgc_Return
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_Ap_SrlComOutput_DiagStsNonRecRmpToZeroFltPres_Cnt_lgc_Return(P2VAR(Boolean, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_VAR) data);
# else
#  define Rte_ReadHook_Ap_SrlComOutput_DiagStsNonRecRmpToZeroFltPres_Cnt_lgc_Return(arg1) ((void)(0))
# endif /* Rte_ReadHook_Ap_SrlComOutput_DiagStsNonRecRmpToZeroFltPres_Cnt_lgc_Return */

# if defined (Rte_ReadHook_Ap_SrlComOutput_DiagStsNonRecRmpToZeroFltPres_Cnt_lgc_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_Ap_SrlComOutput_DiagStsNonRecRmpToZeroFltPres_Cnt_lgc_Start
# endif
# if defined (Rte_ReadHook_Ap_SrlComOutput_DiagStsNonRecRmpToZeroFltPres_Cnt_lgc_Start)
#  undef Rte_ReadHook_Ap_SrlComOutput_DiagStsNonRecRmpToZeroFltPres_Cnt_lgc_Start
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_Ap_SrlComOutput_DiagStsNonRecRmpToZeroFltPres_Cnt_lgc_Start(P2VAR(Boolean, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_VAR) data);
# else
#  define Rte_ReadHook_Ap_SrlComOutput_DiagStsNonRecRmpToZeroFltPres_Cnt_lgc_Start(arg1) ((void)(0))
# endif /* Rte_ReadHook_Ap_SrlComOutput_DiagStsNonRecRmpToZeroFltPres_Cnt_lgc_Start */

# if defined (Rte_ReadHook_Ap_SrlComOutput_DiagStsRecRmpToZeroFltPres_Cnt_lgc_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_Ap_SrlComOutput_DiagStsRecRmpToZeroFltPres_Cnt_lgc_Return
# endif
# if defined (Rte_ReadHook_Ap_SrlComOutput_DiagStsRecRmpToZeroFltPres_Cnt_lgc_Return)
#  undef Rte_ReadHook_Ap_SrlComOutput_DiagStsRecRmpToZeroFltPres_Cnt_lgc_Return
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_Ap_SrlComOutput_DiagStsRecRmpToZeroFltPres_Cnt_lgc_Return(P2VAR(Boolean, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_VAR) data);
# else
#  define Rte_ReadHook_Ap_SrlComOutput_DiagStsRecRmpToZeroFltPres_Cnt_lgc_Return(arg1) ((void)(0))
# endif /* Rte_ReadHook_Ap_SrlComOutput_DiagStsRecRmpToZeroFltPres_Cnt_lgc_Return */

# if defined (Rte_ReadHook_Ap_SrlComOutput_DiagStsRecRmpToZeroFltPres_Cnt_lgc_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_Ap_SrlComOutput_DiagStsRecRmpToZeroFltPres_Cnt_lgc_Start
# endif
# if defined (Rte_ReadHook_Ap_SrlComOutput_DiagStsRecRmpToZeroFltPres_Cnt_lgc_Start)
#  undef Rte_ReadHook_Ap_SrlComOutput_DiagStsRecRmpToZeroFltPres_Cnt_lgc_Start
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_Ap_SrlComOutput_DiagStsRecRmpToZeroFltPres_Cnt_lgc_Start(P2VAR(Boolean, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_VAR) data);
# else
#  define Rte_ReadHook_Ap_SrlComOutput_DiagStsRecRmpToZeroFltPres_Cnt_lgc_Start(arg1) ((void)(0))
# endif /* Rte_ReadHook_Ap_SrlComOutput_DiagStsRecRmpToZeroFltPres_Cnt_lgc_Start */

# if defined (Rte_ReadHook_Ap_SrlComOutput_EngRPM_Cnt_u16_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_Ap_SrlComOutput_EngRPM_Cnt_u16_Return
# endif
# if defined (Rte_ReadHook_Ap_SrlComOutput_EngRPM_Cnt_u16_Return)
#  undef Rte_ReadHook_Ap_SrlComOutput_EngRPM_Cnt_u16_Return
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_Ap_SrlComOutput_EngRPM_Cnt_u16_Return(P2VAR(UInt16, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_VAR) data);
# else
#  define Rte_ReadHook_Ap_SrlComOutput_EngRPM_Cnt_u16_Return(arg1) ((void)(0))
# endif /* Rte_ReadHook_Ap_SrlComOutput_EngRPM_Cnt_u16_Return */

# if defined (Rte_ReadHook_Ap_SrlComOutput_EngRPM_Cnt_u16_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_Ap_SrlComOutput_EngRPM_Cnt_u16_Start
# endif
# if defined (Rte_ReadHook_Ap_SrlComOutput_EngRPM_Cnt_u16_Start)
#  undef Rte_ReadHook_Ap_SrlComOutput_EngRPM_Cnt_u16_Start
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_Ap_SrlComOutput_EngRPM_Cnt_u16_Start(P2VAR(UInt16, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_VAR) data);
# else
#  define Rte_ReadHook_Ap_SrlComOutput_EngRPM_Cnt_u16_Start(arg1) ((void)(0))
# endif /* Rte_ReadHook_Ap_SrlComOutput_EngRPM_Cnt_u16_Start */

# if defined (Rte_ReadHook_Ap_SrlComOutput_HaLFState_Cnt_u08_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_Ap_SrlComOutput_HaLFState_Cnt_u08_Return
# endif
# if defined (Rte_ReadHook_Ap_SrlComOutput_HaLFState_Cnt_u08_Return)
#  undef Rte_ReadHook_Ap_SrlComOutput_HaLFState_Cnt_u08_Return
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_Ap_SrlComOutput_HaLFState_Cnt_u08_Return(P2VAR(UInt8, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_VAR) data);
# else
#  define Rte_ReadHook_Ap_SrlComOutput_HaLFState_Cnt_u08_Return(arg1) ((void)(0))
# endif /* Rte_ReadHook_Ap_SrlComOutput_HaLFState_Cnt_u08_Return */

# if defined (Rte_ReadHook_Ap_SrlComOutput_HaLFState_Cnt_u08_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_Ap_SrlComOutput_HaLFState_Cnt_u08_Start
# endif
# if defined (Rte_ReadHook_Ap_SrlComOutput_HaLFState_Cnt_u08_Start)
#  undef Rte_ReadHook_Ap_SrlComOutput_HaLFState_Cnt_u08_Start
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_Ap_SrlComOutput_HaLFState_Cnt_u08_Start(P2VAR(UInt8, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_VAR) data);
# else
#  define Rte_ReadHook_Ap_SrlComOutput_HaLFState_Cnt_u08_Start(arg1) ((void)(0))
# endif /* Rte_ReadHook_Ap_SrlComOutput_HaLFState_Cnt_u08_Start */

# if defined (Rte_ReadHook_Ap_SrlComOutput_HaLFSuspend_Cnt_lgc_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_Ap_SrlComOutput_HaLFSuspend_Cnt_lgc_Return
# endif
# if defined (Rte_ReadHook_Ap_SrlComOutput_HaLFSuspend_Cnt_lgc_Return)
#  undef Rte_ReadHook_Ap_SrlComOutput_HaLFSuspend_Cnt_lgc_Return
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_Ap_SrlComOutput_HaLFSuspend_Cnt_lgc_Return(P2VAR(Boolean, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_VAR) data);
# else
#  define Rte_ReadHook_Ap_SrlComOutput_HaLFSuspend_Cnt_lgc_Return(arg1) ((void)(0))
# endif /* Rte_ReadHook_Ap_SrlComOutput_HaLFSuspend_Cnt_lgc_Return */

# if defined (Rte_ReadHook_Ap_SrlComOutput_HaLFSuspend_Cnt_lgc_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_Ap_SrlComOutput_HaLFSuspend_Cnt_lgc_Start
# endif
# if defined (Rte_ReadHook_Ap_SrlComOutput_HaLFSuspend_Cnt_lgc_Start)
#  undef Rte_ReadHook_Ap_SrlComOutput_HaLFSuspend_Cnt_lgc_Start
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_Ap_SrlComOutput_HaLFSuspend_Cnt_lgc_Start(P2VAR(Boolean, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_VAR) data);
# else
#  define Rte_ReadHook_Ap_SrlComOutput_HaLFSuspend_Cnt_lgc_Start(arg1) ((void)(0))
# endif /* Rte_ReadHook_Ap_SrlComOutput_HaLFSuspend_Cnt_lgc_Start */

# if defined (Rte_ReadHook_Ap_SrlComOutput_HandsOnDetect_Cnt_lgc_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_Ap_SrlComOutput_HandsOnDetect_Cnt_lgc_Return
# endif
# if defined (Rte_ReadHook_Ap_SrlComOutput_HandsOnDetect_Cnt_lgc_Return)
#  undef Rte_ReadHook_Ap_SrlComOutput_HandsOnDetect_Cnt_lgc_Return
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_Ap_SrlComOutput_HandsOnDetect_Cnt_lgc_Return(P2VAR(Boolean, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_VAR) data);
# else
#  define Rte_ReadHook_Ap_SrlComOutput_HandsOnDetect_Cnt_lgc_Return(arg1) ((void)(0))
# endif /* Rte_ReadHook_Ap_SrlComOutput_HandsOnDetect_Cnt_lgc_Return */

# if defined (Rte_ReadHook_Ap_SrlComOutput_HandsOnDetect_Cnt_lgc_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_Ap_SrlComOutput_HandsOnDetect_Cnt_lgc_Start
# endif
# if defined (Rte_ReadHook_Ap_SrlComOutput_HandsOnDetect_Cnt_lgc_Start)
#  undef Rte_ReadHook_Ap_SrlComOutput_HandsOnDetect_Cnt_lgc_Start
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_Ap_SrlComOutput_HandsOnDetect_Cnt_lgc_Start(P2VAR(Boolean, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_VAR) data);
# else
#  define Rte_ReadHook_Ap_SrlComOutput_HandsOnDetect_Cnt_lgc_Start(arg1) ((void)(0))
# endif /* Rte_ReadHook_Ap_SrlComOutput_HandsOnDetect_Cnt_lgc_Start */

# if defined (Rte_ReadHook_Ap_SrlComOutput_HwTrq_HwNm_f32_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_Ap_SrlComOutput_HwTrq_HwNm_f32_Return
# endif
# if defined (Rte_ReadHook_Ap_SrlComOutput_HwTrq_HwNm_f32_Return)
#  undef Rte_ReadHook_Ap_SrlComOutput_HwTrq_HwNm_f32_Return
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_Ap_SrlComOutput_HwTrq_HwNm_f32_Return(P2VAR(Float, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_VAR) data);
# else
#  define Rte_ReadHook_Ap_SrlComOutput_HwTrq_HwNm_f32_Return(arg1) ((void)(0))
# endif /* Rte_ReadHook_Ap_SrlComOutput_HwTrq_HwNm_f32_Return */

# if defined (Rte_ReadHook_Ap_SrlComOutput_HwTrq_HwNm_f32_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_Ap_SrlComOutput_HwTrq_HwNm_f32_Start
# endif
# if defined (Rte_ReadHook_Ap_SrlComOutput_HwTrq_HwNm_f32_Start)
#  undef Rte_ReadHook_Ap_SrlComOutput_HwTrq_HwNm_f32_Start
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_Ap_SrlComOutput_HwTrq_HwNm_f32_Start(P2VAR(Float, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_VAR) data);
# else
#  define Rte_ReadHook_Ap_SrlComOutput_HwTrq_HwNm_f32_Start(arg1) ((void)(0))
# endif /* Rte_ReadHook_Ap_SrlComOutput_HwTrq_HwNm_f32_Start */

# if defined (Rte_ReadHook_Ap_SrlComOutput_OutputRampMult_Uls_f32_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_Ap_SrlComOutput_OutputRampMult_Uls_f32_Return
# endif
# if defined (Rte_ReadHook_Ap_SrlComOutput_OutputRampMult_Uls_f32_Return)
#  undef Rte_ReadHook_Ap_SrlComOutput_OutputRampMult_Uls_f32_Return
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_Ap_SrlComOutput_OutputRampMult_Uls_f32_Return(P2VAR(Float, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_VAR) data);
# else
#  define Rte_ReadHook_Ap_SrlComOutput_OutputRampMult_Uls_f32_Return(arg1) ((void)(0))
# endif /* Rte_ReadHook_Ap_SrlComOutput_OutputRampMult_Uls_f32_Return */

# if defined (Rte_ReadHook_Ap_SrlComOutput_OutputRampMult_Uls_f32_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_Ap_SrlComOutput_OutputRampMult_Uls_f32_Start
# endif
# if defined (Rte_ReadHook_Ap_SrlComOutput_OutputRampMult_Uls_f32_Start)
#  undef Rte_ReadHook_Ap_SrlComOutput_OutputRampMult_Uls_f32_Start
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_Ap_SrlComOutput_OutputRampMult_Uls_f32_Start(P2VAR(Float, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_VAR) data);
# else
#  define Rte_ReadHook_Ap_SrlComOutput_OutputRampMult_Uls_f32_Start(arg1) ((void)(0))
# endif /* Rte_ReadHook_Ap_SrlComOutput_OutputRampMult_Uls_f32_Start */

# if defined (Rte_ReadHook_Ap_SrlComOutput_PrkAssistState_Cnt_u08_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_Ap_SrlComOutput_PrkAssistState_Cnt_u08_Return
# endif
# if defined (Rte_ReadHook_Ap_SrlComOutput_PrkAssistState_Cnt_u08_Return)
#  undef Rte_ReadHook_Ap_SrlComOutput_PrkAssistState_Cnt_u08_Return
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_Ap_SrlComOutput_PrkAssistState_Cnt_u08_Return(P2VAR(UInt8, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_VAR) data);
# else
#  define Rte_ReadHook_Ap_SrlComOutput_PrkAssistState_Cnt_u08_Return(arg1) ((void)(0))
# endif /* Rte_ReadHook_Ap_SrlComOutput_PrkAssistState_Cnt_u08_Return */

# if defined (Rte_ReadHook_Ap_SrlComOutput_PrkAssistState_Cnt_u08_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_Ap_SrlComOutput_PrkAssistState_Cnt_u08_Start
# endif
# if defined (Rte_ReadHook_Ap_SrlComOutput_PrkAssistState_Cnt_u08_Start)
#  undef Rte_ReadHook_Ap_SrlComOutput_PrkAssistState_Cnt_u08_Start
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_Ap_SrlComOutput_PrkAssistState_Cnt_u08_Start(P2VAR(UInt8, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_VAR) data);
# else
#  define Rte_ReadHook_Ap_SrlComOutput_PrkAssistState_Cnt_u08_Start(arg1) ((void)(0))
# endif /* Rte_ReadHook_Ap_SrlComOutput_PrkAssistState_Cnt_u08_Start */

# if defined (Rte_ReadHook_Ap_SrlComOutput_PrkAssistSuspend_Cnt_lgc_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_Ap_SrlComOutput_PrkAssistSuspend_Cnt_lgc_Return
# endif
# if defined (Rte_ReadHook_Ap_SrlComOutput_PrkAssistSuspend_Cnt_lgc_Return)
#  undef Rte_ReadHook_Ap_SrlComOutput_PrkAssistSuspend_Cnt_lgc_Return
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_Ap_SrlComOutput_PrkAssistSuspend_Cnt_lgc_Return(P2VAR(Boolean, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_VAR) data);
# else
#  define Rte_ReadHook_Ap_SrlComOutput_PrkAssistSuspend_Cnt_lgc_Return(arg1) ((void)(0))
# endif /* Rte_ReadHook_Ap_SrlComOutput_PrkAssistSuspend_Cnt_lgc_Return */

# if defined (Rte_ReadHook_Ap_SrlComOutput_PrkAssistSuspend_Cnt_lgc_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_Ap_SrlComOutput_PrkAssistSuspend_Cnt_lgc_Start
# endif
# if defined (Rte_ReadHook_Ap_SrlComOutput_PrkAssistSuspend_Cnt_lgc_Start)
#  undef Rte_ReadHook_Ap_SrlComOutput_PrkAssistSuspend_Cnt_lgc_Start
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_Ap_SrlComOutput_PrkAssistSuspend_Cnt_lgc_Start(P2VAR(Boolean, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_VAR) data);
# else
#  define Rte_ReadHook_Ap_SrlComOutput_PrkAssistSuspend_Cnt_lgc_Start(arg1) ((void)(0))
# endif /* Rte_ReadHook_Ap_SrlComOutput_PrkAssistSuspend_Cnt_lgc_Start */

# if defined (Rte_ReadHook_Ap_SrlComOutput_RampDwnStatusComplete_Cnt_lgc_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_Ap_SrlComOutput_RampDwnStatusComplete_Cnt_lgc_Return
# endif
# if defined (Rte_ReadHook_Ap_SrlComOutput_RampDwnStatusComplete_Cnt_lgc_Return)
#  undef Rte_ReadHook_Ap_SrlComOutput_RampDwnStatusComplete_Cnt_lgc_Return
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_Ap_SrlComOutput_RampDwnStatusComplete_Cnt_lgc_Return(P2VAR(Boolean, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_VAR) data);
# else
#  define Rte_ReadHook_Ap_SrlComOutput_RampDwnStatusComplete_Cnt_lgc_Return(arg1) ((void)(0))
# endif /* Rte_ReadHook_Ap_SrlComOutput_RampDwnStatusComplete_Cnt_lgc_Return */

# if defined (Rte_ReadHook_Ap_SrlComOutput_RampDwnStatusComplete_Cnt_lgc_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_Ap_SrlComOutput_RampDwnStatusComplete_Cnt_lgc_Start
# endif
# if defined (Rte_ReadHook_Ap_SrlComOutput_RampDwnStatusComplete_Cnt_lgc_Start)
#  undef Rte_ReadHook_Ap_SrlComOutput_RampDwnStatusComplete_Cnt_lgc_Start
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_Ap_SrlComOutput_RampDwnStatusComplete_Cnt_lgc_Start(P2VAR(Boolean, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_VAR) data);
# else
#  define Rte_ReadHook_Ap_SrlComOutput_RampDwnStatusComplete_Cnt_lgc_Start(arg1) ((void)(0))
# endif /* Rte_ReadHook_Ap_SrlComOutput_RampDwnStatusComplete_Cnt_lgc_Start */

# if defined (Rte_ReadHook_Ap_SrlComOutput_SpStPrsnt_Cnt_lgc_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_Ap_SrlComOutput_SpStPrsnt_Cnt_lgc_Return
# endif
# if defined (Rte_ReadHook_Ap_SrlComOutput_SpStPrsnt_Cnt_lgc_Return)
#  undef Rte_ReadHook_Ap_SrlComOutput_SpStPrsnt_Cnt_lgc_Return
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_Ap_SrlComOutput_SpStPrsnt_Cnt_lgc_Return(P2VAR(Boolean, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_VAR) data);
# else
#  define Rte_ReadHook_Ap_SrlComOutput_SpStPrsnt_Cnt_lgc_Return(arg1) ((void)(0))
# endif /* Rte_ReadHook_Ap_SrlComOutput_SpStPrsnt_Cnt_lgc_Return */

# if defined (Rte_ReadHook_Ap_SrlComOutput_SpStPrsnt_Cnt_lgc_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_Ap_SrlComOutput_SpStPrsnt_Cnt_lgc_Start
# endif
# if defined (Rte_ReadHook_Ap_SrlComOutput_SpStPrsnt_Cnt_lgc_Start)
#  undef Rte_ReadHook_Ap_SrlComOutput_SpStPrsnt_Cnt_lgc_Start
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_Ap_SrlComOutput_SpStPrsnt_Cnt_lgc_Start(P2VAR(Boolean, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_VAR) data);
# else
#  define Rte_ReadHook_Ap_SrlComOutput_SpStPrsnt_Cnt_lgc_Start(arg1) ((void)(0))
# endif /* Rte_ReadHook_Ap_SrlComOutput_SpStPrsnt_Cnt_lgc_Start */

# if defined (Rte_ReadHook_Ap_SrlComOutput_SrlComHwTrqValid_Cnt_lgc_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_Ap_SrlComOutput_SrlComHwTrqValid_Cnt_lgc_Return
# endif
# if defined (Rte_ReadHook_Ap_SrlComOutput_SrlComHwTrqValid_Cnt_lgc_Return)
#  undef Rte_ReadHook_Ap_SrlComOutput_SrlComHwTrqValid_Cnt_lgc_Return
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_Ap_SrlComOutput_SrlComHwTrqValid_Cnt_lgc_Return(P2VAR(Boolean, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_VAR) data);
# else
#  define Rte_ReadHook_Ap_SrlComOutput_SrlComHwTrqValid_Cnt_lgc_Return(arg1) ((void)(0))
# endif /* Rte_ReadHook_Ap_SrlComOutput_SrlComHwTrqValid_Cnt_lgc_Return */

# if defined (Rte_ReadHook_Ap_SrlComOutput_SrlComHwTrqValid_Cnt_lgc_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_Ap_SrlComOutput_SrlComHwTrqValid_Cnt_lgc_Start
# endif
# if defined (Rte_ReadHook_Ap_SrlComOutput_SrlComHwTrqValid_Cnt_lgc_Start)
#  undef Rte_ReadHook_Ap_SrlComOutput_SrlComHwTrqValid_Cnt_lgc_Start
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_Ap_SrlComOutput_SrlComHwTrqValid_Cnt_lgc_Start(P2VAR(Boolean, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_VAR) data);
# else
#  define Rte_ReadHook_Ap_SrlComOutput_SrlComHwTrqValid_Cnt_lgc_Start(arg1) ((void)(0))
# endif /* Rte_ReadHook_Ap_SrlComOutput_SrlComHwTrqValid_Cnt_lgc_Start */

# if defined (Rte_ReadHook_Ap_SrlComOutput_SrlComVehSpdValid_Cnt_lgc_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_Ap_SrlComOutput_SrlComVehSpdValid_Cnt_lgc_Return
# endif
# if defined (Rte_ReadHook_Ap_SrlComOutput_SrlComVehSpdValid_Cnt_lgc_Return)
#  undef Rte_ReadHook_Ap_SrlComOutput_SrlComVehSpdValid_Cnt_lgc_Return
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_Ap_SrlComOutput_SrlComVehSpdValid_Cnt_lgc_Return(P2VAR(Boolean, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_VAR) data);
# else
#  define Rte_ReadHook_Ap_SrlComOutput_SrlComVehSpdValid_Cnt_lgc_Return(arg1) ((void)(0))
# endif /* Rte_ReadHook_Ap_SrlComOutput_SrlComVehSpdValid_Cnt_lgc_Return */

# if defined (Rte_ReadHook_Ap_SrlComOutput_SrlComVehSpdValid_Cnt_lgc_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_Ap_SrlComOutput_SrlComVehSpdValid_Cnt_lgc_Start
# endif
# if defined (Rte_ReadHook_Ap_SrlComOutput_SrlComVehSpdValid_Cnt_lgc_Start)
#  undef Rte_ReadHook_Ap_SrlComOutput_SrlComVehSpdValid_Cnt_lgc_Start
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_Ap_SrlComOutput_SrlComVehSpdValid_Cnt_lgc_Start(P2VAR(Boolean, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_VAR) data);
# else
#  define Rte_ReadHook_Ap_SrlComOutput_SrlComVehSpdValid_Cnt_lgc_Start(arg1) ((void)(0))
# endif /* Rte_ReadHook_Ap_SrlComOutput_SrlComVehSpdValid_Cnt_lgc_Start */

# if defined (Rte_ReadHook_Ap_SrlComOutput_SumLmtTrqCmd_MtrNm_f32_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_Ap_SrlComOutput_SumLmtTrqCmd_MtrNm_f32_Return
# endif
# if defined (Rte_ReadHook_Ap_SrlComOutput_SumLmtTrqCmd_MtrNm_f32_Return)
#  undef Rte_ReadHook_Ap_SrlComOutput_SumLmtTrqCmd_MtrNm_f32_Return
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_Ap_SrlComOutput_SumLmtTrqCmd_MtrNm_f32_Return(P2VAR(Float, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_VAR) data);
# else
#  define Rte_ReadHook_Ap_SrlComOutput_SumLmtTrqCmd_MtrNm_f32_Return(arg1) ((void)(0))
# endif /* Rte_ReadHook_Ap_SrlComOutput_SumLmtTrqCmd_MtrNm_f32_Return */

# if defined (Rte_ReadHook_Ap_SrlComOutput_SumLmtTrqCmd_MtrNm_f32_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_Ap_SrlComOutput_SumLmtTrqCmd_MtrNm_f32_Start
# endif
# if defined (Rte_ReadHook_Ap_SrlComOutput_SumLmtTrqCmd_MtrNm_f32_Start)
#  undef Rte_ReadHook_Ap_SrlComOutput_SumLmtTrqCmd_MtrNm_f32_Start
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_Ap_SrlComOutput_SumLmtTrqCmd_MtrNm_f32_Start(P2VAR(Float, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_VAR) data);
# else
#  define Rte_ReadHook_Ap_SrlComOutput_SumLmtTrqCmd_MtrNm_f32_Start(arg1) ((void)(0))
# endif /* Rte_ReadHook_Ap_SrlComOutput_SumLmtTrqCmd_MtrNm_f32_Start */

# if defined (Rte_ReadHook_Ap_SrlComOutput_SupplyCurrent_Amp_f32_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_Ap_SrlComOutput_SupplyCurrent_Amp_f32_Return
# endif
# if defined (Rte_ReadHook_Ap_SrlComOutput_SupplyCurrent_Amp_f32_Return)
#  undef Rte_ReadHook_Ap_SrlComOutput_SupplyCurrent_Amp_f32_Return
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_Ap_SrlComOutput_SupplyCurrent_Amp_f32_Return(P2VAR(Float, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_VAR) data);
# else
#  define Rte_ReadHook_Ap_SrlComOutput_SupplyCurrent_Amp_f32_Return(arg1) ((void)(0))
# endif /* Rte_ReadHook_Ap_SrlComOutput_SupplyCurrent_Amp_f32_Return */

# if defined (Rte_ReadHook_Ap_SrlComOutput_SupplyCurrent_Amp_f32_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_Ap_SrlComOutput_SupplyCurrent_Amp_f32_Start
# endif
# if defined (Rte_ReadHook_Ap_SrlComOutput_SupplyCurrent_Amp_f32_Start)
#  undef Rte_ReadHook_Ap_SrlComOutput_SupplyCurrent_Amp_f32_Start
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_Ap_SrlComOutput_SupplyCurrent_Amp_f32_Start(P2VAR(Float, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_VAR) data);
# else
#  define Rte_ReadHook_Ap_SrlComOutput_SupplyCurrent_Amp_f32_Start(arg1) ((void)(0))
# endif /* Rte_ReadHook_Ap_SrlComOutput_SupplyCurrent_Amp_f32_Start */

# if defined (Rte_ReadHook_Ap_SrlComOutput_VehicleSpeed_Kph_f32_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_Ap_SrlComOutput_VehicleSpeed_Kph_f32_Return
# endif
# if defined (Rte_ReadHook_Ap_SrlComOutput_VehicleSpeed_Kph_f32_Return)
#  undef Rte_ReadHook_Ap_SrlComOutput_VehicleSpeed_Kph_f32_Return
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_Ap_SrlComOutput_VehicleSpeed_Kph_f32_Return(P2VAR(Float, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_VAR) data);
# else
#  define Rte_ReadHook_Ap_SrlComOutput_VehicleSpeed_Kph_f32_Return(arg1) ((void)(0))
# endif /* Rte_ReadHook_Ap_SrlComOutput_VehicleSpeed_Kph_f32_Return */

# if defined (Rte_ReadHook_Ap_SrlComOutput_VehicleSpeed_Kph_f32_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_Ap_SrlComOutput_VehicleSpeed_Kph_f32_Start
# endif
# if defined (Rte_ReadHook_Ap_SrlComOutput_VehicleSpeed_Kph_f32_Start)
#  undef Rte_ReadHook_Ap_SrlComOutput_VehicleSpeed_Kph_f32_Start
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_Ap_SrlComOutput_VehicleSpeed_Kph_f32_Start(P2VAR(Float, AUTOMATIC, RTE_AP_SRLCOMOUTPUT_APPL_VAR) data);
# else
#  define Rte_ReadHook_Ap_SrlComOutput_VehicleSpeed_Kph_f32_Start(arg1) ((void)(0))
# endif /* Rte_ReadHook_Ap_SrlComOutput_VehicleSpeed_Kph_f32_Start */

# if defined (Rte_ReadHook_Sa_CmMtrCurr_MEC_Cnt_enum_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_Sa_CmMtrCurr_MEC_Cnt_enum_Return
# endif
# if defined (Rte_ReadHook_Sa_CmMtrCurr_MEC_Cnt_enum_Return)
#  undef Rte_ReadHook_Sa_CmMtrCurr_MEC_Cnt_enum_Return
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_Sa_CmMtrCurr_MEC_Cnt_enum_Return(P2VAR(ManufModeType, AUTOMATIC, RTE_SA_CMMTRCURR_APPL_VAR) data);
# else
#  define Rte_ReadHook_Sa_CmMtrCurr_MEC_Cnt_enum_Return(arg1) ((void)(0))
# endif /* Rte_ReadHook_Sa_CmMtrCurr_MEC_Cnt_enum_Return */

# if defined (Rte_ReadHook_Sa_CmMtrCurr_MEC_Cnt_enum_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_Sa_CmMtrCurr_MEC_Cnt_enum_Start
# endif
# if defined (Rte_ReadHook_Sa_CmMtrCurr_MEC_Cnt_enum_Start)
#  undef Rte_ReadHook_Sa_CmMtrCurr_MEC_Cnt_enum_Start
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_Sa_CmMtrCurr_MEC_Cnt_enum_Start(P2VAR(ManufModeType, AUTOMATIC, RTE_SA_CMMTRCURR_APPL_VAR) data);
# else
#  define Rte_ReadHook_Sa_CmMtrCurr_MEC_Cnt_enum_Start(arg1) ((void)(0))
# endif /* Rte_ReadHook_Sa_CmMtrCurr_MEC_Cnt_enum_Start */

# if defined (Rte_ReadHook_Sa_CmMtrCurr_MtrVel_MtrRadpS_f32_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_Sa_CmMtrCurr_MtrVel_MtrRadpS_f32_Return
# endif
# if defined (Rte_ReadHook_Sa_CmMtrCurr_MtrVel_MtrRadpS_f32_Return)
#  undef Rte_ReadHook_Sa_CmMtrCurr_MtrVel_MtrRadpS_f32_Return
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_Sa_CmMtrCurr_MtrVel_MtrRadpS_f32_Return(P2VAR(Float, AUTOMATIC, RTE_SA_CMMTRCURR_APPL_VAR) data);
# else
#  define Rte_ReadHook_Sa_CmMtrCurr_MtrVel_MtrRadpS_f32_Return(arg1) ((void)(0))
# endif /* Rte_ReadHook_Sa_CmMtrCurr_MtrVel_MtrRadpS_f32_Return */

# if defined (Rte_ReadHook_Sa_CmMtrCurr_MtrVel_MtrRadpS_f32_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_Sa_CmMtrCurr_MtrVel_MtrRadpS_f32_Start
# endif
# if defined (Rte_ReadHook_Sa_CmMtrCurr_MtrVel_MtrRadpS_f32_Start)
#  undef Rte_ReadHook_Sa_CmMtrCurr_MtrVel_MtrRadpS_f32_Start
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_Sa_CmMtrCurr_MtrVel_MtrRadpS_f32_Start(P2VAR(Float, AUTOMATIC, RTE_SA_CMMTRCURR_APPL_VAR) data);
# else
#  define Rte_ReadHook_Sa_CmMtrCurr_MtrVel_MtrRadpS_f32_Start(arg1) ((void)(0))
# endif /* Rte_ReadHook_Sa_CmMtrCurr_MtrVel_MtrRadpS_f32_Start */

# if defined (Rte_ReadHook_Sa_CmMtrCurr_VehSpd_Kph_f32_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_Sa_CmMtrCurr_VehSpd_Kph_f32_Return
# endif
# if defined (Rte_ReadHook_Sa_CmMtrCurr_VehSpd_Kph_f32_Return)
#  undef Rte_ReadHook_Sa_CmMtrCurr_VehSpd_Kph_f32_Return
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_Sa_CmMtrCurr_VehSpd_Kph_f32_Return(P2VAR(Float, AUTOMATIC, RTE_SA_CMMTRCURR_APPL_VAR) data);
# else
#  define Rte_ReadHook_Sa_CmMtrCurr_VehSpd_Kph_f32_Return(arg1) ((void)(0))
# endif /* Rte_ReadHook_Sa_CmMtrCurr_VehSpd_Kph_f32_Return */

# if defined (Rte_ReadHook_Sa_CmMtrCurr_VehSpd_Kph_f32_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_Sa_CmMtrCurr_VehSpd_Kph_f32_Start
# endif
# if defined (Rte_ReadHook_Sa_CmMtrCurr_VehSpd_Kph_f32_Start)
#  undef Rte_ReadHook_Sa_CmMtrCurr_VehSpd_Kph_f32_Start
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_Sa_CmMtrCurr_VehSpd_Kph_f32_Start(P2VAR(Float, AUTOMATIC, RTE_SA_CMMTRCURR_APPL_VAR) data);
# else
#  define Rte_ReadHook_Sa_CmMtrCurr_VehSpd_Kph_f32_Start(arg1) ((void)(0))
# endif /* Rte_ReadHook_Sa_CmMtrCurr_VehSpd_Kph_f32_Start */

# if defined (Rte_ReadHook_Sa_CmMtrCurr_VhSpdValid_Cnt_lgc_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_Sa_CmMtrCurr_VhSpdValid_Cnt_lgc_Return
# endif
# if defined (Rte_ReadHook_Sa_CmMtrCurr_VhSpdValid_Cnt_lgc_Return)
#  undef Rte_ReadHook_Sa_CmMtrCurr_VhSpdValid_Cnt_lgc_Return
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_Sa_CmMtrCurr_VhSpdValid_Cnt_lgc_Return(P2VAR(Boolean, AUTOMATIC, RTE_SA_CMMTRCURR_APPL_VAR) data);
# else
#  define Rte_ReadHook_Sa_CmMtrCurr_VhSpdValid_Cnt_lgc_Return(arg1) ((void)(0))
# endif /* Rte_ReadHook_Sa_CmMtrCurr_VhSpdValid_Cnt_lgc_Return */

# if defined (Rte_ReadHook_Sa_CmMtrCurr_VhSpdValid_Cnt_lgc_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_Sa_CmMtrCurr_VhSpdValid_Cnt_lgc_Start
# endif
# if defined (Rte_ReadHook_Sa_CmMtrCurr_VhSpdValid_Cnt_lgc_Start)
#  undef Rte_ReadHook_Sa_CmMtrCurr_VhSpdValid_Cnt_lgc_Start
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_Sa_CmMtrCurr_VhSpdValid_Cnt_lgc_Start(P2VAR(Boolean, AUTOMATIC, RTE_SA_CMMTRCURR_APPL_VAR) data);
# else
#  define Rte_ReadHook_Sa_CmMtrCurr_VhSpdValid_Cnt_lgc_Start(arg1) ((void)(0))
# endif /* Rte_ReadHook_Sa_CmMtrCurr_VhSpdValid_Cnt_lgc_Start */

# if defined (Rte_ReadHook_Sa_HwTrq_MECCounter_Cnt_enum_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_Sa_HwTrq_MECCounter_Cnt_enum_Return
# endif
# if defined (Rte_ReadHook_Sa_HwTrq_MECCounter_Cnt_enum_Return)
#  undef Rte_ReadHook_Sa_HwTrq_MECCounter_Cnt_enum_Return
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_Sa_HwTrq_MECCounter_Cnt_enum_Return(P2VAR(ManufModeType, AUTOMATIC, RTE_SA_HWTRQ_APPL_VAR) data);
# else
#  define Rte_ReadHook_Sa_HwTrq_MECCounter_Cnt_enum_Return(arg1) ((void)(0))
# endif /* Rte_ReadHook_Sa_HwTrq_MECCounter_Cnt_enum_Return */

# if defined (Rte_ReadHook_Sa_HwTrq_MECCounter_Cnt_enum_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_Sa_HwTrq_MECCounter_Cnt_enum_Start
# endif
# if defined (Rte_ReadHook_Sa_HwTrq_MECCounter_Cnt_enum_Start)
#  undef Rte_ReadHook_Sa_HwTrq_MECCounter_Cnt_enum_Start
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_Sa_HwTrq_MECCounter_Cnt_enum_Start(P2VAR(ManufModeType, AUTOMATIC, RTE_SA_HWTRQ_APPL_VAR) data);
# else
#  define Rte_ReadHook_Sa_HwTrq_MECCounter_Cnt_enum_Start(arg1) ((void)(0))
# endif /* Rte_ReadHook_Sa_HwTrq_MECCounter_Cnt_enum_Start */

# if defined (Rte_ReadHook_Sa_HwTrq_T1ADC_Volt_f32_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_Sa_HwTrq_T1ADC_Volt_f32_Return
# endif
# if defined (Rte_ReadHook_Sa_HwTrq_T1ADC_Volt_f32_Return)
#  undef Rte_ReadHook_Sa_HwTrq_T1ADC_Volt_f32_Return
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_Sa_HwTrq_T1ADC_Volt_f32_Return(P2VAR(Float, AUTOMATIC, RTE_SA_HWTRQ_APPL_VAR) data);
# else
#  define Rte_ReadHook_Sa_HwTrq_T1ADC_Volt_f32_Return(arg1) ((void)(0))
# endif /* Rte_ReadHook_Sa_HwTrq_T1ADC_Volt_f32_Return */

# if defined (Rte_ReadHook_Sa_HwTrq_T1ADC_Volt_f32_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_Sa_HwTrq_T1ADC_Volt_f32_Start
# endif
# if defined (Rte_ReadHook_Sa_HwTrq_T1ADC_Volt_f32_Start)
#  undef Rte_ReadHook_Sa_HwTrq_T1ADC_Volt_f32_Start
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_Sa_HwTrq_T1ADC_Volt_f32_Start(P2VAR(Float, AUTOMATIC, RTE_SA_HWTRQ_APPL_VAR) data);
# else
#  define Rte_ReadHook_Sa_HwTrq_T1ADC_Volt_f32_Start(arg1) ((void)(0))
# endif /* Rte_ReadHook_Sa_HwTrq_T1ADC_Volt_f32_Start */

# if defined (Rte_ReadHook_Sa_HwTrq_T2ADC_Volt_f32_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_Sa_HwTrq_T2ADC_Volt_f32_Return
# endif
# if defined (Rte_ReadHook_Sa_HwTrq_T2ADC_Volt_f32_Return)
#  undef Rte_ReadHook_Sa_HwTrq_T2ADC_Volt_f32_Return
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_Sa_HwTrq_T2ADC_Volt_f32_Return(P2VAR(Float, AUTOMATIC, RTE_SA_HWTRQ_APPL_VAR) data);
# else
#  define Rte_ReadHook_Sa_HwTrq_T2ADC_Volt_f32_Return(arg1) ((void)(0))
# endif /* Rte_ReadHook_Sa_HwTrq_T2ADC_Volt_f32_Return */

# if defined (Rte_ReadHook_Sa_HwTrq_T2ADC_Volt_f32_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_Sa_HwTrq_T2ADC_Volt_f32_Start
# endif
# if defined (Rte_ReadHook_Sa_HwTrq_T2ADC_Volt_f32_Start)
#  undef Rte_ReadHook_Sa_HwTrq_T2ADC_Volt_f32_Start
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_Sa_HwTrq_T2ADC_Volt_f32_Start(P2VAR(Float, AUTOMATIC, RTE_SA_HWTRQ_APPL_VAR) data);
# else
#  define Rte_ReadHook_Sa_HwTrq_T2ADC_Volt_f32_Start(arg1) ((void)(0))
# endif /* Rte_ReadHook_Sa_HwTrq_T2ADC_Volt_f32_Start */

# if defined (Rte_Runnable_Ap_AbsHwPosScom_AbsHwPosScom_Init1_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_AbsHwPosScom_AbsHwPosScom_Init1_Return
# endif
# if defined (Rte_Runnable_Ap_AbsHwPosScom_AbsHwPosScom_Init1_Return)
#  undef Rte_Runnable_Ap_AbsHwPosScom_AbsHwPosScom_Init1_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_AbsHwPosScom_AbsHwPosScom_Init1_Return(void);
# else
#  define Rte_Runnable_Ap_AbsHwPosScom_AbsHwPosScom_Init1_Return() ((void)(0))
# endif /* Rte_Runnable_Ap_AbsHwPosScom_AbsHwPosScom_Init1_Return */

# if defined (Rte_Runnable_Ap_AbsHwPosScom_AbsHwPosScom_Init1_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_AbsHwPosScom_AbsHwPosScom_Init1_Start
# endif
# if defined (Rte_Runnable_Ap_AbsHwPosScom_AbsHwPosScom_Init1_Start)
#  undef Rte_Runnable_Ap_AbsHwPosScom_AbsHwPosScom_Init1_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_AbsHwPosScom_AbsHwPosScom_Init1_Start(void);
# else
#  define Rte_Runnable_Ap_AbsHwPosScom_AbsHwPosScom_Init1_Start() ((void)(0))
# endif /* Rte_Runnable_Ap_AbsHwPosScom_AbsHwPosScom_Init1_Start */

# if defined (Rte_Runnable_Ap_AbsHwPosScom_AbsHwPosScom_Per1_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_AbsHwPosScom_AbsHwPosScom_Per1_Return
# endif
# if defined (Rte_Runnable_Ap_AbsHwPosScom_AbsHwPosScom_Per1_Return)
#  undef Rte_Runnable_Ap_AbsHwPosScom_AbsHwPosScom_Per1_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_AbsHwPosScom_AbsHwPosScom_Per1_Return(void);
# else
#  define Rte_Runnable_Ap_AbsHwPosScom_AbsHwPosScom_Per1_Return() ((void)(0))
# endif /* Rte_Runnable_Ap_AbsHwPosScom_AbsHwPosScom_Per1_Return */

# if defined (Rte_Runnable_Ap_AbsHwPosScom_AbsHwPosScom_Per1_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_AbsHwPosScom_AbsHwPosScom_Per1_Start
# endif
# if defined (Rte_Runnable_Ap_AbsHwPosScom_AbsHwPosScom_Per1_Start)
#  undef Rte_Runnable_Ap_AbsHwPosScom_AbsHwPosScom_Per1_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_AbsHwPosScom_AbsHwPosScom_Per1_Start(void);
# else
#  define Rte_Runnable_Ap_AbsHwPosScom_AbsHwPosScom_Per1_Start() ((void)(0))
# endif /* Rte_Runnable_Ap_AbsHwPosScom_AbsHwPosScom_Per1_Start */

# if defined (Rte_Runnable_Ap_AbsHwPosScom_AbsHwPosScom_Per2_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_AbsHwPosScom_AbsHwPosScom_Per2_Return
# endif
# if defined (Rte_Runnable_Ap_AbsHwPosScom_AbsHwPosScom_Per2_Return)
#  undef Rte_Runnable_Ap_AbsHwPosScom_AbsHwPosScom_Per2_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_AbsHwPosScom_AbsHwPosScom_Per2_Return(void);
# else
#  define Rte_Runnable_Ap_AbsHwPosScom_AbsHwPosScom_Per2_Return() ((void)(0))
# endif /* Rte_Runnable_Ap_AbsHwPosScom_AbsHwPosScom_Per2_Return */

# if defined (Rte_Runnable_Ap_AbsHwPosScom_AbsHwPosScom_Per2_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_AbsHwPosScom_AbsHwPosScom_Per2_Start
# endif
# if defined (Rte_Runnable_Ap_AbsHwPosScom_AbsHwPosScom_Per2_Start)
#  undef Rte_Runnable_Ap_AbsHwPosScom_AbsHwPosScom_Per2_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_AbsHwPosScom_AbsHwPosScom_Per2_Start(void);
# else
#  define Rte_Runnable_Ap_AbsHwPosScom_AbsHwPosScom_Per2_Start() ((void)(0))
# endif /* Rte_Runnable_Ap_AbsHwPosScom_AbsHwPosScom_Per2_Start */

# if defined (Rte_Runnable_Ap_AbsHwPosScom_AbsHwPosScom_Per3_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_AbsHwPosScom_AbsHwPosScom_Per3_Return
# endif
# if defined (Rte_Runnable_Ap_AbsHwPosScom_AbsHwPosScom_Per3_Return)
#  undef Rte_Runnable_Ap_AbsHwPosScom_AbsHwPosScom_Per3_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_AbsHwPosScom_AbsHwPosScom_Per3_Return(void);
# else
#  define Rte_Runnable_Ap_AbsHwPosScom_AbsHwPosScom_Per3_Return() ((void)(0))
# endif /* Rte_Runnable_Ap_AbsHwPosScom_AbsHwPosScom_Per3_Return */

# if defined (Rte_Runnable_Ap_AbsHwPosScom_AbsHwPosScom_Per3_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_AbsHwPosScom_AbsHwPosScom_Per3_Start
# endif
# if defined (Rte_Runnable_Ap_AbsHwPosScom_AbsHwPosScom_Per3_Start)
#  undef Rte_Runnable_Ap_AbsHwPosScom_AbsHwPosScom_Per3_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_AbsHwPosScom_AbsHwPosScom_Per3_Start(void);
# else
#  define Rte_Runnable_Ap_AbsHwPosScom_AbsHwPosScom_Per3_Start() ((void)(0))
# endif /* Rte_Runnable_Ap_AbsHwPosScom_AbsHwPosScom_Per3_Start */

# if defined (Rte_Runnable_Ap_AbsHwPosScom_AbsHwPosScom_Scom_HwPosSrvRead_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_AbsHwPosScom_AbsHwPosScom_Scom_HwPosSrvRead_Return
# endif
# if defined (Rte_Runnable_Ap_AbsHwPosScom_AbsHwPosScom_Scom_HwPosSrvRead_Return)
#  undef Rte_Runnable_Ap_AbsHwPosScom_AbsHwPosScom_Scom_HwPosSrvRead_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_AbsHwPosScom_AbsHwPosScom_Scom_HwPosSrvRead_Return(P2VAR(Boolean, AUTOMATIC, RTE_AP_ABSHWPOSSCOM_APPL_VAR) Par);
# else
#  define Rte_Runnable_Ap_AbsHwPosScom_AbsHwPosScom_Scom_HwPosSrvRead_Return(arg1) ((void)(0))
# endif /* Rte_Runnable_Ap_AbsHwPosScom_AbsHwPosScom_Scom_HwPosSrvRead_Return */

# if defined (Rte_Runnable_Ap_AbsHwPosScom_AbsHwPosScom_Scom_HwPosSrvRead_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_AbsHwPosScom_AbsHwPosScom_Scom_HwPosSrvRead_Start
# endif
# if defined (Rte_Runnable_Ap_AbsHwPosScom_AbsHwPosScom_Scom_HwPosSrvRead_Start)
#  undef Rte_Runnable_Ap_AbsHwPosScom_AbsHwPosScom_Scom_HwPosSrvRead_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_AbsHwPosScom_AbsHwPosScom_Scom_HwPosSrvRead_Start(P2VAR(Boolean, AUTOMATIC, RTE_AP_ABSHWPOSSCOM_APPL_VAR) Par);
# else
#  define Rte_Runnable_Ap_AbsHwPosScom_AbsHwPosScom_Scom_HwPosSrvRead_Start(arg1) ((void)(0))
# endif /* Rte_Runnable_Ap_AbsHwPosScom_AbsHwPosScom_Scom_HwPosSrvRead_Start */

# if defined (Rte_Runnable_Ap_AbsHwPosScom_AbsHwPosScom_Scom_HwPosSrvSetToZero_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_AbsHwPosScom_AbsHwPosScom_Scom_HwPosSrvSetToZero_Return
# endif
# if defined (Rte_Runnable_Ap_AbsHwPosScom_AbsHwPosScom_Scom_HwPosSrvSetToZero_Return)
#  undef Rte_Runnable_Ap_AbsHwPosScom_AbsHwPosScom_Scom_HwPosSrvSetToZero_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_AbsHwPosScom_AbsHwPosScom_Scom_HwPosSrvSetToZero_Return(Boolean Par);
# else
#  define Rte_Runnable_Ap_AbsHwPosScom_AbsHwPosScom_Scom_HwPosSrvSetToZero_Return(arg1) ((void)(0))
# endif /* Rte_Runnable_Ap_AbsHwPosScom_AbsHwPosScom_Scom_HwPosSrvSetToZero_Return */

# if defined (Rte_Runnable_Ap_AbsHwPosScom_AbsHwPosScom_Scom_HwPosSrvSetToZero_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_AbsHwPosScom_AbsHwPosScom_Scom_HwPosSrvSetToZero_Start
# endif
# if defined (Rte_Runnable_Ap_AbsHwPosScom_AbsHwPosScom_Scom_HwPosSrvSetToZero_Start)
#  undef Rte_Runnable_Ap_AbsHwPosScom_AbsHwPosScom_Scom_HwPosSrvSetToZero_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_AbsHwPosScom_AbsHwPosScom_Scom_HwPosSrvSetToZero_Start(Boolean Par);
# else
#  define Rte_Runnable_Ap_AbsHwPosScom_AbsHwPosScom_Scom_HwPosSrvSetToZero_Start(arg1) ((void)(0))
# endif /* Rte_Runnable_Ap_AbsHwPosScom_AbsHwPosScom_Scom_HwPosSrvSetToZero_Start */

# if defined (Rte_Runnable_Ap_ActivePull_ActivePull_Init1_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_ActivePull_ActivePull_Init1_Return
# endif
# if defined (Rte_Runnable_Ap_ActivePull_ActivePull_Init1_Return)
#  undef Rte_Runnable_Ap_ActivePull_ActivePull_Init1_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_ActivePull_ActivePull_Init1_Return(void);
# else
#  define Rte_Runnable_Ap_ActivePull_ActivePull_Init1_Return() ((void)(0))
# endif /* Rte_Runnable_Ap_ActivePull_ActivePull_Init1_Return */

# if defined (Rte_Runnable_Ap_ActivePull_ActivePull_Init1_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_ActivePull_ActivePull_Init1_Start
# endif
# if defined (Rte_Runnable_Ap_ActivePull_ActivePull_Init1_Start)
#  undef Rte_Runnable_Ap_ActivePull_ActivePull_Init1_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_ActivePull_ActivePull_Init1_Start(void);
# else
#  define Rte_Runnable_Ap_ActivePull_ActivePull_Init1_Start() ((void)(0))
# endif /* Rte_Runnable_Ap_ActivePull_ActivePull_Init1_Start */

# if defined (Rte_Runnable_Ap_ActivePull_ActivePull_Per1_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_ActivePull_ActivePull_Per1_Return
# endif
# if defined (Rte_Runnable_Ap_ActivePull_ActivePull_Per1_Return)
#  undef Rte_Runnable_Ap_ActivePull_ActivePull_Per1_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_ActivePull_ActivePull_Per1_Return(void);
# else
#  define Rte_Runnable_Ap_ActivePull_ActivePull_Per1_Return() ((void)(0))
# endif /* Rte_Runnable_Ap_ActivePull_ActivePull_Per1_Return */

# if defined (Rte_Runnable_Ap_ActivePull_ActivePull_Per1_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_ActivePull_ActivePull_Per1_Start
# endif
# if defined (Rte_Runnable_Ap_ActivePull_ActivePull_Per1_Start)
#  undef Rte_Runnable_Ap_ActivePull_ActivePull_Per1_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_ActivePull_ActivePull_Per1_Start(void);
# else
#  define Rte_Runnable_Ap_ActivePull_ActivePull_Per1_Start() ((void)(0))
# endif /* Rte_Runnable_Ap_ActivePull_ActivePull_Per1_Start */

# if defined (Rte_Runnable_Ap_ActivePull_ActivePull_Per2_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_ActivePull_ActivePull_Per2_Return
# endif
# if defined (Rte_Runnable_Ap_ActivePull_ActivePull_Per2_Return)
#  undef Rte_Runnable_Ap_ActivePull_ActivePull_Per2_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_ActivePull_ActivePull_Per2_Return(void);
# else
#  define Rte_Runnable_Ap_ActivePull_ActivePull_Per2_Return() ((void)(0))
# endif /* Rte_Runnable_Ap_ActivePull_ActivePull_Per2_Return */

# if defined (Rte_Runnable_Ap_ActivePull_ActivePull_Per2_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_ActivePull_ActivePull_Per2_Start
# endif
# if defined (Rte_Runnable_Ap_ActivePull_ActivePull_Per2_Start)
#  undef Rte_Runnable_Ap_ActivePull_ActivePull_Per2_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_ActivePull_ActivePull_Per2_Start(void);
# else
#  define Rte_Runnable_Ap_ActivePull_ActivePull_Per2_Start() ((void)(0))
# endif /* Rte_Runnable_Ap_ActivePull_ActivePull_Per2_Start */

# if defined (Rte_Runnable_Ap_ActivePull_ActivePull_Per3_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_ActivePull_ActivePull_Per3_Return
# endif
# if defined (Rte_Runnable_Ap_ActivePull_ActivePull_Per3_Return)
#  undef Rte_Runnable_Ap_ActivePull_ActivePull_Per3_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_ActivePull_ActivePull_Per3_Return(void);
# else
#  define Rte_Runnable_Ap_ActivePull_ActivePull_Per3_Return() ((void)(0))
# endif /* Rte_Runnable_Ap_ActivePull_ActivePull_Per3_Return */

# if defined (Rte_Runnable_Ap_ActivePull_ActivePull_Per3_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_ActivePull_ActivePull_Per3_Start
# endif
# if defined (Rte_Runnable_Ap_ActivePull_ActivePull_Per3_Start)
#  undef Rte_Runnable_Ap_ActivePull_ActivePull_Per3_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_ActivePull_ActivePull_Per3_Start(void);
# else
#  define Rte_Runnable_Ap_ActivePull_ActivePull_Per3_Start() ((void)(0))
# endif /* Rte_Runnable_Ap_ActivePull_ActivePull_Per3_Start */

# if defined (Rte_Runnable_Ap_ActivePull_ActivePull_SCom_ReadParam_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_ActivePull_ActivePull_SCom_ReadParam_Return
# endif
# if defined (Rte_Runnable_Ap_ActivePull_ActivePull_SCom_ReadParam_Return)
#  undef Rte_Runnable_Ap_ActivePull_ActivePull_SCom_ReadParam_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_ActivePull_ActivePull_SCom_ReadParam_Return(P2VAR(Float, AUTOMATIC, RTE_AP_ACTIVEPULL_APPL_VAR) PullCompCmd_HwNm_f32, P2VAR(Float, AUTOMATIC, RTE_AP_ACTIVEPULL_APPL_VAR) STComp_HwNm_f32, P2VAR(Float, AUTOMATIC, RTE_AP_ACTIVEPULL_APPL_VAR) LTComp_HwNm_f32, P2VAR(Boolean, AUTOMATIC, RTE_AP_ACTIVEPULL_APPL_VAR) EnableLearn_Cnt_lgc);
# else
#  define Rte_Runnable_Ap_ActivePull_ActivePull_SCom_ReadParam_Return(arg1, arg2, arg3, arg4) ((void)(0))
# endif /* Rte_Runnable_Ap_ActivePull_ActivePull_SCom_ReadParam_Return */

# if defined (Rte_Runnable_Ap_ActivePull_ActivePull_SCom_ReadParam_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_ActivePull_ActivePull_SCom_ReadParam_Start
# endif
# if defined (Rte_Runnable_Ap_ActivePull_ActivePull_SCom_ReadParam_Start)
#  undef Rte_Runnable_Ap_ActivePull_ActivePull_SCom_ReadParam_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_ActivePull_ActivePull_SCom_ReadParam_Start(P2VAR(Float, AUTOMATIC, RTE_AP_ACTIVEPULL_APPL_VAR) PullCompCmd_HwNm_f32, P2VAR(Float, AUTOMATIC, RTE_AP_ACTIVEPULL_APPL_VAR) STComp_HwNm_f32, P2VAR(Float, AUTOMATIC, RTE_AP_ACTIVEPULL_APPL_VAR) LTComp_HwNm_f32, P2VAR(Boolean, AUTOMATIC, RTE_AP_ACTIVEPULL_APPL_VAR) EnableLearn_Cnt_lgc);
# else
#  define Rte_Runnable_Ap_ActivePull_ActivePull_SCom_ReadParam_Start(arg1, arg2, arg3, arg4) ((void)(0))
# endif /* Rte_Runnable_Ap_ActivePull_ActivePull_SCom_ReadParam_Start */

# if defined (Rte_Runnable_Ap_ActivePull_ActivePull_SCom_Reset_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_ActivePull_ActivePull_SCom_Reset_Return
# endif
# if defined (Rte_Runnable_Ap_ActivePull_ActivePull_SCom_Reset_Return)
#  undef Rte_Runnable_Ap_ActivePull_ActivePull_SCom_Reset_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_ActivePull_ActivePull_SCom_Reset_Return(void);
# else
#  define Rte_Runnable_Ap_ActivePull_ActivePull_SCom_Reset_Return() ((void)(0))
# endif /* Rte_Runnable_Ap_ActivePull_ActivePull_SCom_Reset_Return */

# if defined (Rte_Runnable_Ap_ActivePull_ActivePull_SCom_Reset_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_ActivePull_ActivePull_SCom_Reset_Start
# endif
# if defined (Rte_Runnable_Ap_ActivePull_ActivePull_SCom_Reset_Start)
#  undef Rte_Runnable_Ap_ActivePull_ActivePull_SCom_Reset_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_ActivePull_ActivePull_SCom_Reset_Start(void);
# else
#  define Rte_Runnable_Ap_ActivePull_ActivePull_SCom_Reset_Start() ((void)(0))
# endif /* Rte_Runnable_Ap_ActivePull_ActivePull_SCom_Reset_Start */

# if defined (Rte_Runnable_Ap_ActivePull_ActivePull_SCom_SetLTComp_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_ActivePull_ActivePull_SCom_SetLTComp_Return
# endif
# if defined (Rte_Runnable_Ap_ActivePull_ActivePull_SCom_SetLTComp_Return)
#  undef Rte_Runnable_Ap_ActivePull_ActivePull_SCom_SetLTComp_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_ActivePull_ActivePull_SCom_SetLTComp_Return(Float LTComp_HwNm_f32);
# else
#  define Rte_Runnable_Ap_ActivePull_ActivePull_SCom_SetLTComp_Return(arg1) ((void)(0))
# endif /* Rte_Runnable_Ap_ActivePull_ActivePull_SCom_SetLTComp_Return */

# if defined (Rte_Runnable_Ap_ActivePull_ActivePull_SCom_SetLTComp_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_ActivePull_ActivePull_SCom_SetLTComp_Start
# endif
# if defined (Rte_Runnable_Ap_ActivePull_ActivePull_SCom_SetLTComp_Start)
#  undef Rte_Runnable_Ap_ActivePull_ActivePull_SCom_SetLTComp_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_ActivePull_ActivePull_SCom_SetLTComp_Start(Float LTComp_HwNm_f32);
# else
#  define Rte_Runnable_Ap_ActivePull_ActivePull_SCom_SetLTComp_Start(arg1) ((void)(0))
# endif /* Rte_Runnable_Ap_ActivePull_ActivePull_SCom_SetLTComp_Start */

# if defined (Rte_Runnable_Ap_ActivePull_ActivePull_SCom_SetSTComp_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_ActivePull_ActivePull_SCom_SetSTComp_Return
# endif
# if defined (Rte_Runnable_Ap_ActivePull_ActivePull_SCom_SetSTComp_Return)
#  undef Rte_Runnable_Ap_ActivePull_ActivePull_SCom_SetSTComp_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_ActivePull_ActivePull_SCom_SetSTComp_Return(Float STComp_HwNm_f32);
# else
#  define Rte_Runnable_Ap_ActivePull_ActivePull_SCom_SetSTComp_Return(arg1) ((void)(0))
# endif /* Rte_Runnable_Ap_ActivePull_ActivePull_SCom_SetSTComp_Return */

# if defined (Rte_Runnable_Ap_ActivePull_ActivePull_SCom_SetSTComp_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_ActivePull_ActivePull_SCom_SetSTComp_Start
# endif
# if defined (Rte_Runnable_Ap_ActivePull_ActivePull_SCom_SetSTComp_Start)
#  undef Rte_Runnable_Ap_ActivePull_ActivePull_SCom_SetSTComp_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_ActivePull_ActivePull_SCom_SetSTComp_Start(Float STComp_HwNm_f32);
# else
#  define Rte_Runnable_Ap_ActivePull_ActivePull_SCom_SetSTComp_Start(arg1) ((void)(0))
# endif /* Rte_Runnable_Ap_ActivePull_ActivePull_SCom_SetSTComp_Start */

# if defined (Rte_Runnable_Ap_ActivePull_ActivePull_Trns1_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_ActivePull_ActivePull_Trns1_Return
# endif
# if defined (Rte_Runnable_Ap_ActivePull_ActivePull_Trns1_Return)
#  undef Rte_Runnable_Ap_ActivePull_ActivePull_Trns1_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_ActivePull_ActivePull_Trns1_Return(void);
# else
#  define Rte_Runnable_Ap_ActivePull_ActivePull_Trns1_Return() ((void)(0))
# endif /* Rte_Runnable_Ap_ActivePull_ActivePull_Trns1_Return */

# if defined (Rte_Runnable_Ap_ActivePull_ActivePull_Trns1_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_ActivePull_ActivePull_Trns1_Start
# endif
# if defined (Rte_Runnable_Ap_ActivePull_ActivePull_Trns1_Start)
#  undef Rte_Runnable_Ap_ActivePull_ActivePull_Trns1_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_ActivePull_ActivePull_Trns1_Start(void);
# else
#  define Rte_Runnable_Ap_ActivePull_ActivePull_Trns1_Start() ((void)(0))
# endif /* Rte_Runnable_Ap_ActivePull_ActivePull_Trns1_Start */

# if defined (Rte_Runnable_Ap_ApXcp_ApXcp_Per1_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_ApXcp_ApXcp_Per1_Return
# endif
# if defined (Rte_Runnable_Ap_ApXcp_ApXcp_Per1_Return)
#  undef Rte_Runnable_Ap_ApXcp_ApXcp_Per1_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_ApXcp_ApXcp_Per1_Return(void);
# else
#  define Rte_Runnable_Ap_ApXcp_ApXcp_Per1_Return() ((void)(0))
# endif /* Rte_Runnable_Ap_ApXcp_ApXcp_Per1_Return */

# if defined (Rte_Runnable_Ap_ApXcp_ApXcp_Per1_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_ApXcp_ApXcp_Per1_Start
# endif
# if defined (Rte_Runnable_Ap_ApXcp_ApXcp_Per1_Start)
#  undef Rte_Runnable_Ap_ApXcp_ApXcp_Per1_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_ApXcp_ApXcp_Per1_Start(void);
# else
#  define Rte_Runnable_Ap_ApXcp_ApXcp_Per1_Start() ((void)(0))
# endif /* Rte_Runnable_Ap_ApXcp_ApXcp_Per1_Start */

# if defined (Rte_Runnable_Ap_ApXcp_DAQ_2msTL_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_ApXcp_DAQ_2msTL_Return
# endif
# if defined (Rte_Runnable_Ap_ApXcp_DAQ_2msTL_Return)
#  undef Rte_Runnable_Ap_ApXcp_DAQ_2msTL_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_ApXcp_DAQ_2msTL_Return(void);
# else
#  define Rte_Runnable_Ap_ApXcp_DAQ_2msTL_Return() ((void)(0))
# endif /* Rte_Runnable_Ap_ApXcp_DAQ_2msTL_Return */

# if defined (Rte_Runnable_Ap_ApXcp_DAQ_2msTL_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_ApXcp_DAQ_2msTL_Start
# endif
# if defined (Rte_Runnable_Ap_ApXcp_DAQ_2msTL_Start)
#  undef Rte_Runnable_Ap_ApXcp_DAQ_2msTL_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_ApXcp_DAQ_2msTL_Start(void);
# else
#  define Rte_Runnable_Ap_ApXcp_DAQ_2msTL_Start() ((void)(0))
# endif /* Rte_Runnable_Ap_ApXcp_DAQ_2msTL_Start */

# if defined (Rte_Runnable_Ap_ArbLmt_ArbLmt_Per1_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_ArbLmt_ArbLmt_Per1_Return
# endif
# if defined (Rte_Runnable_Ap_ArbLmt_ArbLmt_Per1_Return)
#  undef Rte_Runnable_Ap_ArbLmt_ArbLmt_Per1_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_ArbLmt_ArbLmt_Per1_Return(void);
# else
#  define Rte_Runnable_Ap_ArbLmt_ArbLmt_Per1_Return() ((void)(0))
# endif /* Rte_Runnable_Ap_ArbLmt_ArbLmt_Per1_Return */

# if defined (Rte_Runnable_Ap_ArbLmt_ArbLmt_Per1_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_ArbLmt_ArbLmt_Per1_Start
# endif
# if defined (Rte_Runnable_Ap_ArbLmt_ArbLmt_Per1_Start)
#  undef Rte_Runnable_Ap_ArbLmt_ArbLmt_Per1_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_ArbLmt_ArbLmt_Per1_Start(void);
# else
#  define Rte_Runnable_Ap_ArbLmt_ArbLmt_Per1_Start() ((void)(0))
# endif /* Rte_Runnable_Ap_ArbLmt_ArbLmt_Per1_Start */

# if defined (Rte_Runnable_Ap_AssistFirewall_AssistFirewall_Init1_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_AssistFirewall_AssistFirewall_Init1_Return
# endif
# if defined (Rte_Runnable_Ap_AssistFirewall_AssistFirewall_Init1_Return)
#  undef Rte_Runnable_Ap_AssistFirewall_AssistFirewall_Init1_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_AssistFirewall_AssistFirewall_Init1_Return(void);
# else
#  define Rte_Runnable_Ap_AssistFirewall_AssistFirewall_Init1_Return() ((void)(0))
# endif /* Rte_Runnable_Ap_AssistFirewall_AssistFirewall_Init1_Return */

# if defined (Rte_Runnable_Ap_AssistFirewall_AssistFirewall_Init1_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_AssistFirewall_AssistFirewall_Init1_Start
# endif
# if defined (Rte_Runnable_Ap_AssistFirewall_AssistFirewall_Init1_Start)
#  undef Rte_Runnable_Ap_AssistFirewall_AssistFirewall_Init1_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_AssistFirewall_AssistFirewall_Init1_Start(void);
# else
#  define Rte_Runnable_Ap_AssistFirewall_AssistFirewall_Init1_Start() ((void)(0))
# endif /* Rte_Runnable_Ap_AssistFirewall_AssistFirewall_Init1_Start */

# if defined (Rte_Runnable_Ap_AssistFirewall_AssistFirewall_Per1_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_AssistFirewall_AssistFirewall_Per1_Return
# endif
# if defined (Rte_Runnable_Ap_AssistFirewall_AssistFirewall_Per1_Return)
#  undef Rte_Runnable_Ap_AssistFirewall_AssistFirewall_Per1_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_AssistFirewall_AssistFirewall_Per1_Return(void);
# else
#  define Rte_Runnable_Ap_AssistFirewall_AssistFirewall_Per1_Return() ((void)(0))
# endif /* Rte_Runnable_Ap_AssistFirewall_AssistFirewall_Per1_Return */

# if defined (Rte_Runnable_Ap_AssistFirewall_AssistFirewall_Per1_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_AssistFirewall_AssistFirewall_Per1_Start
# endif
# if defined (Rte_Runnable_Ap_AssistFirewall_AssistFirewall_Per1_Start)
#  undef Rte_Runnable_Ap_AssistFirewall_AssistFirewall_Per1_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_AssistFirewall_AssistFirewall_Per1_Start(void);
# else
#  define Rte_Runnable_Ap_AssistFirewall_AssistFirewall_Per1_Start() ((void)(0))
# endif /* Rte_Runnable_Ap_AssistFirewall_AssistFirewall_Per1_Start */

# if defined (Rte_Runnable_Ap_Assist_Assist_Per1_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_Assist_Assist_Per1_Return
# endif
# if defined (Rte_Runnable_Ap_Assist_Assist_Per1_Return)
#  undef Rte_Runnable_Ap_Assist_Assist_Per1_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_Assist_Assist_Per1_Return(void);
# else
#  define Rte_Runnable_Ap_Assist_Assist_Per1_Return() ((void)(0))
# endif /* Rte_Runnable_Ap_Assist_Assist_Per1_Return */

# if defined (Rte_Runnable_Ap_Assist_Assist_Per1_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_Assist_Assist_Per1_Start
# endif
# if defined (Rte_Runnable_Ap_Assist_Assist_Per1_Start)
#  undef Rte_Runnable_Ap_Assist_Assist_Per1_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_Assist_Assist_Per1_Start(void);
# else
#  define Rte_Runnable_Ap_Assist_Assist_Per1_Start() ((void)(0))
# endif /* Rte_Runnable_Ap_Assist_Assist_Per1_Start */

# if defined (Rte_Runnable_Ap_AstLmt_AstLmt_Init_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_AstLmt_AstLmt_Init_Return
# endif
# if defined (Rte_Runnable_Ap_AstLmt_AstLmt_Init_Return)
#  undef Rte_Runnable_Ap_AstLmt_AstLmt_Init_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_AstLmt_AstLmt_Init_Return(void);
# else
#  define Rte_Runnable_Ap_AstLmt_AstLmt_Init_Return() ((void)(0))
# endif /* Rte_Runnable_Ap_AstLmt_AstLmt_Init_Return */

# if defined (Rte_Runnable_Ap_AstLmt_AstLmt_Init_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_AstLmt_AstLmt_Init_Start
# endif
# if defined (Rte_Runnable_Ap_AstLmt_AstLmt_Init_Start)
#  undef Rte_Runnable_Ap_AstLmt_AstLmt_Init_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_AstLmt_AstLmt_Init_Start(void);
# else
#  define Rte_Runnable_Ap_AstLmt_AstLmt_Init_Start() ((void)(0))
# endif /* Rte_Runnable_Ap_AstLmt_AstLmt_Init_Start */

# if defined (Rte_Runnable_Ap_AstLmt_AstLmt_Per1_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_AstLmt_AstLmt_Per1_Return
# endif
# if defined (Rte_Runnable_Ap_AstLmt_AstLmt_Per1_Return)
#  undef Rte_Runnable_Ap_AstLmt_AstLmt_Per1_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_AstLmt_AstLmt_Per1_Return(void);
# else
#  define Rte_Runnable_Ap_AstLmt_AstLmt_Per1_Return() ((void)(0))
# endif /* Rte_Runnable_Ap_AstLmt_AstLmt_Per1_Return */

# if defined (Rte_Runnable_Ap_AstLmt_AstLmt_Per1_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_AstLmt_AstLmt_Per1_Start
# endif
# if defined (Rte_Runnable_Ap_AstLmt_AstLmt_Per1_Start)
#  undef Rte_Runnable_Ap_AstLmt_AstLmt_Per1_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_AstLmt_AstLmt_Per1_Start(void);
# else
#  define Rte_Runnable_Ap_AstLmt_AstLmt_Per1_Start() ((void)(0))
# endif /* Rte_Runnable_Ap_AstLmt_AstLmt_Per1_Start */

# if defined (Rte_Runnable_Ap_AstLmt_AstLmt_Scom_GetSteeringAssistDefeat_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_AstLmt_AstLmt_Scom_GetSteeringAssistDefeat_Return
# endif
# if defined (Rte_Runnable_Ap_AstLmt_AstLmt_Scom_GetSteeringAssistDefeat_Return)
#  undef Rte_Runnable_Ap_AstLmt_AstLmt_Scom_GetSteeringAssistDefeat_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_AstLmt_AstLmt_Scom_GetSteeringAssistDefeat_Return(P2VAR(Boolean, AUTOMATIC, RTE_AP_ASTLMT_APPL_VAR) SteeringAsstDefeat_Cnt_lgc);
# else
#  define Rte_Runnable_Ap_AstLmt_AstLmt_Scom_GetSteeringAssistDefeat_Return(arg1) ((void)(0))
# endif /* Rte_Runnable_Ap_AstLmt_AstLmt_Scom_GetSteeringAssistDefeat_Return */

# if defined (Rte_Runnable_Ap_AstLmt_AstLmt_Scom_GetSteeringAssistDefeat_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_AstLmt_AstLmt_Scom_GetSteeringAssistDefeat_Start
# endif
# if defined (Rte_Runnable_Ap_AstLmt_AstLmt_Scom_GetSteeringAssistDefeat_Start)
#  undef Rte_Runnable_Ap_AstLmt_AstLmt_Scom_GetSteeringAssistDefeat_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_AstLmt_AstLmt_Scom_GetSteeringAssistDefeat_Start(P2VAR(Boolean, AUTOMATIC, RTE_AP_ASTLMT_APPL_VAR) SteeringAsstDefeat_Cnt_lgc);
# else
#  define Rte_Runnable_Ap_AstLmt_AstLmt_Scom_GetSteeringAssistDefeat_Start(arg1) ((void)(0))
# endif /* Rte_Runnable_Ap_AstLmt_AstLmt_Scom_GetSteeringAssistDefeat_Start */

# if defined (Rte_Runnable_Ap_AstLmt_AstLmt_Scom_ManualTrqCmd_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_AstLmt_AstLmt_Scom_ManualTrqCmd_Return
# endif
# if defined (Rte_Runnable_Ap_AstLmt_AstLmt_Scom_ManualTrqCmd_Return)
#  undef Rte_Runnable_Ap_AstLmt_AstLmt_Scom_ManualTrqCmd_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_AstLmt_AstLmt_Scom_ManualTrqCmd_Return(Boolean EnableManualCtrl, Float MtrTrqCmd_MtrNm_f32);
# else
#  define Rte_Runnable_Ap_AstLmt_AstLmt_Scom_ManualTrqCmd_Return(arg1, arg2) ((void)(0))
# endif /* Rte_Runnable_Ap_AstLmt_AstLmt_Scom_ManualTrqCmd_Return */

# if defined (Rte_Runnable_Ap_AstLmt_AstLmt_Scom_ManualTrqCmd_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_AstLmt_AstLmt_Scom_ManualTrqCmd_Start
# endif
# if defined (Rte_Runnable_Ap_AstLmt_AstLmt_Scom_ManualTrqCmd_Start)
#  undef Rte_Runnable_Ap_AstLmt_AstLmt_Scom_ManualTrqCmd_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_AstLmt_AstLmt_Scom_ManualTrqCmd_Start(Boolean EnableManualCtrl, Float MtrTrqCmd_MtrNm_f32);
# else
#  define Rte_Runnable_Ap_AstLmt_AstLmt_Scom_ManualTrqCmd_Start(arg1, arg2) ((void)(0))
# endif /* Rte_Runnable_Ap_AstLmt_AstLmt_Scom_ManualTrqCmd_Start */

# if defined (Rte_Runnable_Ap_AstLmt_AstLmt_Scom_SetSteeringAssistDefeat_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_AstLmt_AstLmt_Scom_SetSteeringAssistDefeat_Return
# endif
# if defined (Rte_Runnable_Ap_AstLmt_AstLmt_Scom_SetSteeringAssistDefeat_Return)
#  undef Rte_Runnable_Ap_AstLmt_AstLmt_Scom_SetSteeringAssistDefeat_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_AstLmt_AstLmt_Scom_SetSteeringAssistDefeat_Return(Boolean SteeringAsstDefeat_Cnt_lgc);
# else
#  define Rte_Runnable_Ap_AstLmt_AstLmt_Scom_SetSteeringAssistDefeat_Return(arg1) ((void)(0))
# endif /* Rte_Runnable_Ap_AstLmt_AstLmt_Scom_SetSteeringAssistDefeat_Return */

# if defined (Rte_Runnable_Ap_AstLmt_AstLmt_Scom_SetSteeringAssistDefeat_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_AstLmt_AstLmt_Scom_SetSteeringAssistDefeat_Start
# endif
# if defined (Rte_Runnable_Ap_AstLmt_AstLmt_Scom_SetSteeringAssistDefeat_Start)
#  undef Rte_Runnable_Ap_AstLmt_AstLmt_Scom_SetSteeringAssistDefeat_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_AstLmt_AstLmt_Scom_SetSteeringAssistDefeat_Start(Boolean SteeringAsstDefeat_Cnt_lgc);
# else
#  define Rte_Runnable_Ap_AstLmt_AstLmt_Scom_SetSteeringAssistDefeat_Start(arg1) ((void)(0))
# endif /* Rte_Runnable_Ap_AstLmt_AstLmt_Scom_SetSteeringAssistDefeat_Start */

# if defined (Rte_Runnable_Ap_AvgFricLrn_AvgFricLrn_Init1_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_AvgFricLrn_AvgFricLrn_Init1_Return
# endif
# if defined (Rte_Runnable_Ap_AvgFricLrn_AvgFricLrn_Init1_Return)
#  undef Rte_Runnable_Ap_AvgFricLrn_AvgFricLrn_Init1_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_AvgFricLrn_AvgFricLrn_Init1_Return(void);
# else
#  define Rte_Runnable_Ap_AvgFricLrn_AvgFricLrn_Init1_Return() ((void)(0))
# endif /* Rte_Runnable_Ap_AvgFricLrn_AvgFricLrn_Init1_Return */

# if defined (Rte_Runnable_Ap_AvgFricLrn_AvgFricLrn_Init1_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_AvgFricLrn_AvgFricLrn_Init1_Start
# endif
# if defined (Rte_Runnable_Ap_AvgFricLrn_AvgFricLrn_Init1_Start)
#  undef Rte_Runnable_Ap_AvgFricLrn_AvgFricLrn_Init1_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_AvgFricLrn_AvgFricLrn_Init1_Start(void);
# else
#  define Rte_Runnable_Ap_AvgFricLrn_AvgFricLrn_Init1_Start() ((void)(0))
# endif /* Rte_Runnable_Ap_AvgFricLrn_AvgFricLrn_Init1_Start */

# if defined (Rte_Runnable_Ap_AvgFricLrn_AvgFricLrn_Per1_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_AvgFricLrn_AvgFricLrn_Per1_Return
# endif
# if defined (Rte_Runnable_Ap_AvgFricLrn_AvgFricLrn_Per1_Return)
#  undef Rte_Runnable_Ap_AvgFricLrn_AvgFricLrn_Per1_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_AvgFricLrn_AvgFricLrn_Per1_Return(void);
# else
#  define Rte_Runnable_Ap_AvgFricLrn_AvgFricLrn_Per1_Return() ((void)(0))
# endif /* Rte_Runnable_Ap_AvgFricLrn_AvgFricLrn_Per1_Return */

# if defined (Rte_Runnable_Ap_AvgFricLrn_AvgFricLrn_Per1_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_AvgFricLrn_AvgFricLrn_Per1_Start
# endif
# if defined (Rte_Runnable_Ap_AvgFricLrn_AvgFricLrn_Per1_Start)
#  undef Rte_Runnable_Ap_AvgFricLrn_AvgFricLrn_Per1_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_AvgFricLrn_AvgFricLrn_Per1_Start(void);
# else
#  define Rte_Runnable_Ap_AvgFricLrn_AvgFricLrn_Per1_Start() ((void)(0))
# endif /* Rte_Runnable_Ap_AvgFricLrn_AvgFricLrn_Per1_Start */

# if defined (Rte_Runnable_Ap_AvgFricLrn_AvgFricLrn_SCom_GetEOLFric_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_AvgFricLrn_AvgFricLrn_SCom_GetEOLFric_Return
# endif
# if defined (Rte_Runnable_Ap_AvgFricLrn_AvgFricLrn_SCom_GetEOLFric_Return)
#  undef Rte_Runnable_Ap_AvgFricLrn_AvgFricLrn_SCom_GetEOLFric_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_AvgFricLrn_AvgFricLrn_SCom_GetEOLFric_Return(P2VAR(Float, AUTOMATIC, RTE_AP_AVGFRICLRN_APPL_VAR) EOLFric_HwNm_f32);
# else
#  define Rte_Runnable_Ap_AvgFricLrn_AvgFricLrn_SCom_GetEOLFric_Return(arg1) ((void)(0))
# endif /* Rte_Runnable_Ap_AvgFricLrn_AvgFricLrn_SCom_GetEOLFric_Return */

# if defined (Rte_Runnable_Ap_AvgFricLrn_AvgFricLrn_SCom_GetEOLFric_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_AvgFricLrn_AvgFricLrn_SCom_GetEOLFric_Start
# endif
# if defined (Rte_Runnable_Ap_AvgFricLrn_AvgFricLrn_SCom_GetEOLFric_Start)
#  undef Rte_Runnable_Ap_AvgFricLrn_AvgFricLrn_SCom_GetEOLFric_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_AvgFricLrn_AvgFricLrn_SCom_GetEOLFric_Start(P2VAR(Float, AUTOMATIC, RTE_AP_AVGFRICLRN_APPL_VAR) EOLFric_HwNm_f32);
# else
#  define Rte_Runnable_Ap_AvgFricLrn_AvgFricLrn_SCom_GetEOLFric_Start(arg1) ((void)(0))
# endif /* Rte_Runnable_Ap_AvgFricLrn_AvgFricLrn_SCom_GetEOLFric_Start */

# if defined (Rte_Runnable_Ap_AvgFricLrn_AvgFricLrn_SCom_GetOffsetOutputDefeat_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_AvgFricLrn_AvgFricLrn_SCom_GetOffsetOutputDefeat_Return
# endif
# if defined (Rte_Runnable_Ap_AvgFricLrn_AvgFricLrn_SCom_GetOffsetOutputDefeat_Return)
#  undef Rte_Runnable_Ap_AvgFricLrn_AvgFricLrn_SCom_GetOffsetOutputDefeat_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_AvgFricLrn_AvgFricLrn_SCom_GetOffsetOutputDefeat_Return(P2VAR(Boolean, AUTOMATIC, RTE_AP_AVGFRICLRN_APPL_VAR) DefeatOffsetOutput_Cnt_lgc);
# else
#  define Rte_Runnable_Ap_AvgFricLrn_AvgFricLrn_SCom_GetOffsetOutputDefeat_Return(arg1) ((void)(0))
# endif /* Rte_Runnable_Ap_AvgFricLrn_AvgFricLrn_SCom_GetOffsetOutputDefeat_Return */

# if defined (Rte_Runnable_Ap_AvgFricLrn_AvgFricLrn_SCom_GetOffsetOutputDefeat_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_AvgFricLrn_AvgFricLrn_SCom_GetOffsetOutputDefeat_Start
# endif
# if defined (Rte_Runnable_Ap_AvgFricLrn_AvgFricLrn_SCom_GetOffsetOutputDefeat_Start)
#  undef Rte_Runnable_Ap_AvgFricLrn_AvgFricLrn_SCom_GetOffsetOutputDefeat_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_AvgFricLrn_AvgFricLrn_SCom_GetOffsetOutputDefeat_Start(P2VAR(Boolean, AUTOMATIC, RTE_AP_AVGFRICLRN_APPL_VAR) DefeatOffsetOutput_Cnt_lgc);
# else
#  define Rte_Runnable_Ap_AvgFricLrn_AvgFricLrn_SCom_GetOffsetOutputDefeat_Start(arg1) ((void)(0))
# endif /* Rte_Runnable_Ap_AvgFricLrn_AvgFricLrn_SCom_GetOffsetOutputDefeat_Start */

# if defined (Rte_Runnable_Ap_AvgFricLrn_AvgFricLrn_SCom_GetSelect_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_AvgFricLrn_AvgFricLrn_SCom_GetSelect_Return
# endif
# if defined (Rte_Runnable_Ap_AvgFricLrn_AvgFricLrn_SCom_GetSelect_Return)
#  undef Rte_Runnable_Ap_AvgFricLrn_AvgFricLrn_SCom_GetSelect_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_AvgFricLrn_AvgFricLrn_SCom_GetSelect_Return(P2VAR(Boolean, AUTOMATIC, RTE_AP_AVGFRICLRN_APPL_VAR) EnableFricLearning_Cnt_lgc, P2VAR(Boolean, AUTOMATIC, RTE_AP_AVGFRICLRN_APPL_VAR) EnableOffsetOutput_Cnt_lgc, P2VAR(UInt8, AUTOMATIC, RTE_AP_AVGFRICLRN_APPL_VAR) OpMode_Uls_u08);
# else
#  define Rte_Runnable_Ap_AvgFricLrn_AvgFricLrn_SCom_GetSelect_Return(arg1, arg2, arg3) ((void)(0))
# endif /* Rte_Runnable_Ap_AvgFricLrn_AvgFricLrn_SCom_GetSelect_Return */

# if defined (Rte_Runnable_Ap_AvgFricLrn_AvgFricLrn_SCom_GetSelect_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_AvgFricLrn_AvgFricLrn_SCom_GetSelect_Start
# endif
# if defined (Rte_Runnable_Ap_AvgFricLrn_AvgFricLrn_SCom_GetSelect_Start)
#  undef Rte_Runnable_Ap_AvgFricLrn_AvgFricLrn_SCom_GetSelect_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_AvgFricLrn_AvgFricLrn_SCom_GetSelect_Start(P2VAR(Boolean, AUTOMATIC, RTE_AP_AVGFRICLRN_APPL_VAR) EnableFricLearning_Cnt_lgc, P2VAR(Boolean, AUTOMATIC, RTE_AP_AVGFRICLRN_APPL_VAR) EnableOffsetOutput_Cnt_lgc, P2VAR(UInt8, AUTOMATIC, RTE_AP_AVGFRICLRN_APPL_VAR) OpMode_Uls_u08);
# else
#  define Rte_Runnable_Ap_AvgFricLrn_AvgFricLrn_SCom_GetSelect_Start(arg1, arg2, arg3) ((void)(0))
# endif /* Rte_Runnable_Ap_AvgFricLrn_AvgFricLrn_SCom_GetSelect_Start */

# if defined (Rte_Runnable_Ap_AvgFricLrn_AvgFricLrn_SCom_InitLearnedTables_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_AvgFricLrn_AvgFricLrn_SCom_InitLearnedTables_Return
# endif
# if defined (Rte_Runnable_Ap_AvgFricLrn_AvgFricLrn_SCom_InitLearnedTables_Return)
#  undef Rte_Runnable_Ap_AvgFricLrn_AvgFricLrn_SCom_InitLearnedTables_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_AvgFricLrn_AvgFricLrn_SCom_InitLearnedTables_Return(void);
# else
#  define Rte_Runnable_Ap_AvgFricLrn_AvgFricLrn_SCom_InitLearnedTables_Return() ((void)(0))
# endif /* Rte_Runnable_Ap_AvgFricLrn_AvgFricLrn_SCom_InitLearnedTables_Return */

# if defined (Rte_Runnable_Ap_AvgFricLrn_AvgFricLrn_SCom_InitLearnedTables_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_AvgFricLrn_AvgFricLrn_SCom_InitLearnedTables_Start
# endif
# if defined (Rte_Runnable_Ap_AvgFricLrn_AvgFricLrn_SCom_InitLearnedTables_Start)
#  undef Rte_Runnable_Ap_AvgFricLrn_AvgFricLrn_SCom_InitLearnedTables_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_AvgFricLrn_AvgFricLrn_SCom_InitLearnedTables_Start(void);
# else
#  define Rte_Runnable_Ap_AvgFricLrn_AvgFricLrn_SCom_InitLearnedTables_Start() ((void)(0))
# endif /* Rte_Runnable_Ap_AvgFricLrn_AvgFricLrn_SCom_InitLearnedTables_Start */

# if defined (Rte_Runnable_Ap_AvgFricLrn_AvgFricLrn_SCom_ResetToZero_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_AvgFricLrn_AvgFricLrn_SCom_ResetToZero_Return
# endif
# if defined (Rte_Runnable_Ap_AvgFricLrn_AvgFricLrn_SCom_ResetToZero_Return)
#  undef Rte_Runnable_Ap_AvgFricLrn_AvgFricLrn_SCom_ResetToZero_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_AvgFricLrn_AvgFricLrn_SCom_ResetToZero_Return(void);
# else
#  define Rte_Runnable_Ap_AvgFricLrn_AvgFricLrn_SCom_ResetToZero_Return() ((void)(0))
# endif /* Rte_Runnable_Ap_AvgFricLrn_AvgFricLrn_SCom_ResetToZero_Return */

# if defined (Rte_Runnable_Ap_AvgFricLrn_AvgFricLrn_SCom_ResetToZero_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_AvgFricLrn_AvgFricLrn_SCom_ResetToZero_Start
# endif
# if defined (Rte_Runnable_Ap_AvgFricLrn_AvgFricLrn_SCom_ResetToZero_Start)
#  undef Rte_Runnable_Ap_AvgFricLrn_AvgFricLrn_SCom_ResetToZero_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_AvgFricLrn_AvgFricLrn_SCom_ResetToZero_Start(void);
# else
#  define Rte_Runnable_Ap_AvgFricLrn_AvgFricLrn_SCom_ResetToZero_Start() ((void)(0))
# endif /* Rte_Runnable_Ap_AvgFricLrn_AvgFricLrn_SCom_ResetToZero_Start */

# if defined (Rte_Runnable_Ap_AvgFricLrn_AvgFricLrn_SCom_SetEOLFric_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_AvgFricLrn_AvgFricLrn_SCom_SetEOLFric_Return
# endif
# if defined (Rte_Runnable_Ap_AvgFricLrn_AvgFricLrn_SCom_SetEOLFric_Return)
#  undef Rte_Runnable_Ap_AvgFricLrn_AvgFricLrn_SCom_SetEOLFric_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_AvgFricLrn_AvgFricLrn_SCom_SetEOLFric_Return(Float EOLFric_HwNm_f32);
# else
#  define Rte_Runnable_Ap_AvgFricLrn_AvgFricLrn_SCom_SetEOLFric_Return(arg1) ((void)(0))
# endif /* Rte_Runnable_Ap_AvgFricLrn_AvgFricLrn_SCom_SetEOLFric_Return */

# if defined (Rte_Runnable_Ap_AvgFricLrn_AvgFricLrn_SCom_SetEOLFric_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_AvgFricLrn_AvgFricLrn_SCom_SetEOLFric_Start
# endif
# if defined (Rte_Runnable_Ap_AvgFricLrn_AvgFricLrn_SCom_SetEOLFric_Start)
#  undef Rte_Runnable_Ap_AvgFricLrn_AvgFricLrn_SCom_SetEOLFric_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_AvgFricLrn_AvgFricLrn_SCom_SetEOLFric_Start(Float EOLFric_HwNm_f32);
# else
#  define Rte_Runnable_Ap_AvgFricLrn_AvgFricLrn_SCom_SetEOLFric_Start(arg1) ((void)(0))
# endif /* Rte_Runnable_Ap_AvgFricLrn_AvgFricLrn_SCom_SetEOLFric_Start */

# if defined (Rte_Runnable_Ap_AvgFricLrn_AvgFricLrn_SCom_SetOffsetOutputDefeat_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_AvgFricLrn_AvgFricLrn_SCom_SetOffsetOutputDefeat_Return
# endif
# if defined (Rte_Runnable_Ap_AvgFricLrn_AvgFricLrn_SCom_SetOffsetOutputDefeat_Return)
#  undef Rte_Runnable_Ap_AvgFricLrn_AvgFricLrn_SCom_SetOffsetOutputDefeat_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_AvgFricLrn_AvgFricLrn_SCom_SetOffsetOutputDefeat_Return(Boolean DefeatOffsetOutput_Cnt_lgc);
# else
#  define Rte_Runnable_Ap_AvgFricLrn_AvgFricLrn_SCom_SetOffsetOutputDefeat_Return(arg1) ((void)(0))
# endif /* Rte_Runnable_Ap_AvgFricLrn_AvgFricLrn_SCom_SetOffsetOutputDefeat_Return */

# if defined (Rte_Runnable_Ap_AvgFricLrn_AvgFricLrn_SCom_SetOffsetOutputDefeat_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_AvgFricLrn_AvgFricLrn_SCom_SetOffsetOutputDefeat_Start
# endif
# if defined (Rte_Runnable_Ap_AvgFricLrn_AvgFricLrn_SCom_SetOffsetOutputDefeat_Start)
#  undef Rte_Runnable_Ap_AvgFricLrn_AvgFricLrn_SCom_SetOffsetOutputDefeat_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_AvgFricLrn_AvgFricLrn_SCom_SetOffsetOutputDefeat_Start(Boolean DefeatOffsetOutput_Cnt_lgc);
# else
#  define Rte_Runnable_Ap_AvgFricLrn_AvgFricLrn_SCom_SetOffsetOutputDefeat_Start(arg1) ((void)(0))
# endif /* Rte_Runnable_Ap_AvgFricLrn_AvgFricLrn_SCom_SetOffsetOutputDefeat_Start */

# if defined (Rte_Runnable_Ap_AvgFricLrn_AvgFricLrn_SCom_SetSelect_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_AvgFricLrn_AvgFricLrn_SCom_SetSelect_Return
# endif
# if defined (Rte_Runnable_Ap_AvgFricLrn_AvgFricLrn_SCom_SetSelect_Return)
#  undef Rte_Runnable_Ap_AvgFricLrn_AvgFricLrn_SCom_SetSelect_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_AvgFricLrn_AvgFricLrn_SCom_SetSelect_Return(Boolean EnableFricLearning_Cnt_lgc, Boolean EnableOffsetOutput_Cnt_lgc, UInt8 OpMode_Uls_u08);
# else
#  define Rte_Runnable_Ap_AvgFricLrn_AvgFricLrn_SCom_SetSelect_Return(arg1, arg2, arg3) ((void)(0))
# endif /* Rte_Runnable_Ap_AvgFricLrn_AvgFricLrn_SCom_SetSelect_Return */

# if defined (Rte_Runnable_Ap_AvgFricLrn_AvgFricLrn_SCom_SetSelect_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_AvgFricLrn_AvgFricLrn_SCom_SetSelect_Start
# endif
# if defined (Rte_Runnable_Ap_AvgFricLrn_AvgFricLrn_SCom_SetSelect_Start)
#  undef Rte_Runnable_Ap_AvgFricLrn_AvgFricLrn_SCom_SetSelect_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_AvgFricLrn_AvgFricLrn_SCom_SetSelect_Start(Boolean EnableFricLearning_Cnt_lgc, Boolean EnableOffsetOutput_Cnt_lgc, UInt8 OpMode_Uls_u08);
# else
#  define Rte_Runnable_Ap_AvgFricLrn_AvgFricLrn_SCom_SetSelect_Start(arg1, arg2, arg3) ((void)(0))
# endif /* Rte_Runnable_Ap_AvgFricLrn_AvgFricLrn_SCom_SetSelect_Start */

# if defined (Rte_Runnable_Ap_AvgFricLrn_AvgFricLrn_Trns1_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_AvgFricLrn_AvgFricLrn_Trns1_Return
# endif
# if defined (Rte_Runnable_Ap_AvgFricLrn_AvgFricLrn_Trns1_Return)
#  undef Rte_Runnable_Ap_AvgFricLrn_AvgFricLrn_Trns1_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_AvgFricLrn_AvgFricLrn_Trns1_Return(void);
# else
#  define Rte_Runnable_Ap_AvgFricLrn_AvgFricLrn_Trns1_Return() ((void)(0))
# endif /* Rte_Runnable_Ap_AvgFricLrn_AvgFricLrn_Trns1_Return */

# if defined (Rte_Runnable_Ap_AvgFricLrn_AvgFricLrn_Trns1_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_AvgFricLrn_AvgFricLrn_Trns1_Start
# endif
# if defined (Rte_Runnable_Ap_AvgFricLrn_AvgFricLrn_Trns1_Start)
#  undef Rte_Runnable_Ap_AvgFricLrn_AvgFricLrn_Trns1_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_AvgFricLrn_AvgFricLrn_Trns1_Start(void);
# else
#  define Rte_Runnable_Ap_AvgFricLrn_AvgFricLrn_Trns1_Start() ((void)(0))
# endif /* Rte_Runnable_Ap_AvgFricLrn_AvgFricLrn_Trns1_Start */

# if defined (Rte_Runnable_Ap_BVDiag_BVDiag_Per1_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_BVDiag_BVDiag_Per1_Return
# endif
# if defined (Rte_Runnable_Ap_BVDiag_BVDiag_Per1_Return)
#  undef Rte_Runnable_Ap_BVDiag_BVDiag_Per1_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_BVDiag_BVDiag_Per1_Return(void);
# else
#  define Rte_Runnable_Ap_BVDiag_BVDiag_Per1_Return() ((void)(0))
# endif /* Rte_Runnable_Ap_BVDiag_BVDiag_Per1_Return */

# if defined (Rte_Runnable_Ap_BVDiag_BVDiag_Per1_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_BVDiag_BVDiag_Per1_Start
# endif
# if defined (Rte_Runnable_Ap_BVDiag_BVDiag_Per1_Start)
#  undef Rte_Runnable_Ap_BVDiag_BVDiag_Per1_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_BVDiag_BVDiag_Per1_Start(void);
# else
#  define Rte_Runnable_Ap_BVDiag_BVDiag_Per1_Start() ((void)(0))
# endif /* Rte_Runnable_Ap_BVDiag_BVDiag_Per1_Start */

# if defined (Rte_Runnable_Ap_BatteryVoltage_BatteryVoltage_Per1_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_BatteryVoltage_BatteryVoltage_Per1_Return
# endif
# if defined (Rte_Runnable_Ap_BatteryVoltage_BatteryVoltage_Per1_Return)
#  undef Rte_Runnable_Ap_BatteryVoltage_BatteryVoltage_Per1_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_BatteryVoltage_BatteryVoltage_Per1_Return(void);
# else
#  define Rte_Runnable_Ap_BatteryVoltage_BatteryVoltage_Per1_Return() ((void)(0))
# endif /* Rte_Runnable_Ap_BatteryVoltage_BatteryVoltage_Per1_Return */

# if defined (Rte_Runnable_Ap_BatteryVoltage_BatteryVoltage_Per1_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_BatteryVoltage_BatteryVoltage_Per1_Start
# endif
# if defined (Rte_Runnable_Ap_BatteryVoltage_BatteryVoltage_Per1_Start)
#  undef Rte_Runnable_Ap_BatteryVoltage_BatteryVoltage_Per1_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_BatteryVoltage_BatteryVoltage_Per1_Start(void);
# else
#  define Rte_Runnable_Ap_BatteryVoltage_BatteryVoltage_Per1_Start() ((void)(0))
# endif /* Rte_Runnable_Ap_BatteryVoltage_BatteryVoltage_Per1_Start */

# if defined (Rte_Runnable_Ap_BatteryVoltage_BatteryVoltage_Per2_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_BatteryVoltage_BatteryVoltage_Per2_Return
# endif
# if defined (Rte_Runnable_Ap_BatteryVoltage_BatteryVoltage_Per2_Return)
#  undef Rte_Runnable_Ap_BatteryVoltage_BatteryVoltage_Per2_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_BatteryVoltage_BatteryVoltage_Per2_Return(void);
# else
#  define Rte_Runnable_Ap_BatteryVoltage_BatteryVoltage_Per2_Return() ((void)(0))
# endif /* Rte_Runnable_Ap_BatteryVoltage_BatteryVoltage_Per2_Return */

# if defined (Rte_Runnable_Ap_BatteryVoltage_BatteryVoltage_Per2_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_BatteryVoltage_BatteryVoltage_Per2_Start
# endif
# if defined (Rte_Runnable_Ap_BatteryVoltage_BatteryVoltage_Per2_Start)
#  undef Rte_Runnable_Ap_BatteryVoltage_BatteryVoltage_Per2_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_BatteryVoltage_BatteryVoltage_Per2_Start(void);
# else
#  define Rte_Runnable_Ap_BatteryVoltage_BatteryVoltage_Per2_Start() ((void)(0))
# endif /* Rte_Runnable_Ap_BatteryVoltage_BatteryVoltage_Per2_Start */

# if defined (Rte_Runnable_Ap_BatteryVoltage_BatteryVoltage_SCom_ClearTransOvData_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_BatteryVoltage_BatteryVoltage_SCom_ClearTransOvData_Return
# endif
# if defined (Rte_Runnable_Ap_BatteryVoltage_BatteryVoltage_SCom_ClearTransOvData_Return)
#  undef Rte_Runnable_Ap_BatteryVoltage_BatteryVoltage_SCom_ClearTransOvData_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_BatteryVoltage_BatteryVoltage_SCom_ClearTransOvData_Return(void);
# else
#  define Rte_Runnable_Ap_BatteryVoltage_BatteryVoltage_SCom_ClearTransOvData_Return() ((void)(0))
# endif /* Rte_Runnable_Ap_BatteryVoltage_BatteryVoltage_SCom_ClearTransOvData_Return */

# if defined (Rte_Runnable_Ap_BatteryVoltage_BatteryVoltage_SCom_ClearTransOvData_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_BatteryVoltage_BatteryVoltage_SCom_ClearTransOvData_Start
# endif
# if defined (Rte_Runnable_Ap_BatteryVoltage_BatteryVoltage_SCom_ClearTransOvData_Start)
#  undef Rte_Runnable_Ap_BatteryVoltage_BatteryVoltage_SCom_ClearTransOvData_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_BatteryVoltage_BatteryVoltage_SCom_ClearTransOvData_Start(void);
# else
#  define Rte_Runnable_Ap_BatteryVoltage_BatteryVoltage_SCom_ClearTransOvData_Start() ((void)(0))
# endif /* Rte_Runnable_Ap_BatteryVoltage_BatteryVoltage_SCom_ClearTransOvData_Start */

# if defined (Rte_Runnable_Ap_BatteryVoltage_BatteryVoltage_SCom_ReadTransOvData_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_BatteryVoltage_BatteryVoltage_SCom_ReadTransOvData_Return
# endif
# if defined (Rte_Runnable_Ap_BatteryVoltage_BatteryVoltage_SCom_ReadTransOvData_Return)
#  undef Rte_Runnable_Ap_BatteryVoltage_BatteryVoltage_SCom_ReadTransOvData_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_BatteryVoltage_BatteryVoltage_SCom_ReadTransOvData_Return(P2VAR(UInt16, AUTOMATIC, RTE_AP_BATTERYVOLTAGE_APPL_VAR) OvervoltageCounter_Cnt_u16, P2VAR(Float, AUTOMATIC, RTE_AP_BATTERYVOLTAGE_APPL_VAR) MaxBattVoltage_Volts_f32);
# else
#  define Rte_Runnable_Ap_BatteryVoltage_BatteryVoltage_SCom_ReadTransOvData_Return(arg1, arg2) ((void)(0))
# endif /* Rte_Runnable_Ap_BatteryVoltage_BatteryVoltage_SCom_ReadTransOvData_Return */

# if defined (Rte_Runnable_Ap_BatteryVoltage_BatteryVoltage_SCom_ReadTransOvData_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_BatteryVoltage_BatteryVoltage_SCom_ReadTransOvData_Start
# endif
# if defined (Rte_Runnable_Ap_BatteryVoltage_BatteryVoltage_SCom_ReadTransOvData_Start)
#  undef Rte_Runnable_Ap_BatteryVoltage_BatteryVoltage_SCom_ReadTransOvData_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_BatteryVoltage_BatteryVoltage_SCom_ReadTransOvData_Start(P2VAR(UInt16, AUTOMATIC, RTE_AP_BATTERYVOLTAGE_APPL_VAR) OvervoltageCounter_Cnt_u16, P2VAR(Float, AUTOMATIC, RTE_AP_BATTERYVOLTAGE_APPL_VAR) MaxBattVoltage_Volts_f32);
# else
#  define Rte_Runnable_Ap_BatteryVoltage_BatteryVoltage_SCom_ReadTransOvData_Start(arg1, arg2) ((void)(0))
# endif /* Rte_Runnable_Ap_BatteryVoltage_BatteryVoltage_SCom_ReadTransOvData_Start */

# if defined (Rte_Runnable_Ap_CtrldDisShtdn_CtrldDisShtdn_Per1_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_CtrldDisShtdn_CtrldDisShtdn_Per1_Return
# endif
# if defined (Rte_Runnable_Ap_CtrldDisShtdn_CtrldDisShtdn_Per1_Return)
#  undef Rte_Runnable_Ap_CtrldDisShtdn_CtrldDisShtdn_Per1_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_CtrldDisShtdn_CtrldDisShtdn_Per1_Return(void);
# else
#  define Rte_Runnable_Ap_CtrldDisShtdn_CtrldDisShtdn_Per1_Return() ((void)(0))
# endif /* Rte_Runnable_Ap_CtrldDisShtdn_CtrldDisShtdn_Per1_Return */

# if defined (Rte_Runnable_Ap_CtrldDisShtdn_CtrldDisShtdn_Per1_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_CtrldDisShtdn_CtrldDisShtdn_Per1_Start
# endif
# if defined (Rte_Runnable_Ap_CtrldDisShtdn_CtrldDisShtdn_Per1_Start)
#  undef Rte_Runnable_Ap_CtrldDisShtdn_CtrldDisShtdn_Per1_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_CtrldDisShtdn_CtrldDisShtdn_Per1_Start(void);
# else
#  define Rte_Runnable_Ap_CtrldDisShtdn_CtrldDisShtdn_Per1_Start() ((void)(0))
# endif /* Rte_Runnable_Ap_CtrldDisShtdn_CtrldDisShtdn_Per1_Start */

# if defined (Rte_Runnable_Ap_CurrCmd_CurrCmd_Init_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_CurrCmd_CurrCmd_Init_Return
# endif
# if defined (Rte_Runnable_Ap_CurrCmd_CurrCmd_Init_Return)
#  undef Rte_Runnable_Ap_CurrCmd_CurrCmd_Init_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_CurrCmd_CurrCmd_Init_Return(void);
# else
#  define Rte_Runnable_Ap_CurrCmd_CurrCmd_Init_Return() ((void)(0))
# endif /* Rte_Runnable_Ap_CurrCmd_CurrCmd_Init_Return */

# if defined (Rte_Runnable_Ap_CurrCmd_CurrCmd_Init_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_CurrCmd_CurrCmd_Init_Start
# endif
# if defined (Rte_Runnable_Ap_CurrCmd_CurrCmd_Init_Start)
#  undef Rte_Runnable_Ap_CurrCmd_CurrCmd_Init_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_CurrCmd_CurrCmd_Init_Start(void);
# else
#  define Rte_Runnable_Ap_CurrCmd_CurrCmd_Init_Start() ((void)(0))
# endif /* Rte_Runnable_Ap_CurrCmd_CurrCmd_Init_Start */

# if defined (Rte_Runnable_Ap_CurrCmd_CurrCmd_Per1_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_CurrCmd_CurrCmd_Per1_Return
# endif
# if defined (Rte_Runnable_Ap_CurrCmd_CurrCmd_Per1_Return)
#  undef Rte_Runnable_Ap_CurrCmd_CurrCmd_Per1_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_CurrCmd_CurrCmd_Per1_Return(void);
# else
#  define Rte_Runnable_Ap_CurrCmd_CurrCmd_Per1_Return() ((void)(0))
# endif /* Rte_Runnable_Ap_CurrCmd_CurrCmd_Per1_Return */

# if defined (Rte_Runnable_Ap_CurrCmd_CurrCmd_Per1_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_CurrCmd_CurrCmd_Per1_Start
# endif
# if defined (Rte_Runnable_Ap_CurrCmd_CurrCmd_Per1_Start)
#  undef Rte_Runnable_Ap_CurrCmd_CurrCmd_Per1_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_CurrCmd_CurrCmd_Per1_Start(void);
# else
#  define Rte_Runnable_Ap_CurrCmd_CurrCmd_Per1_Start() ((void)(0))
# endif /* Rte_Runnable_Ap_CurrCmd_CurrCmd_Per1_Start */

# if defined (Rte_Runnable_Ap_CurrParamComp_CurrParamComp_Init_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_CurrParamComp_CurrParamComp_Init_Return
# endif
# if defined (Rte_Runnable_Ap_CurrParamComp_CurrParamComp_Init_Return)
#  undef Rte_Runnable_Ap_CurrParamComp_CurrParamComp_Init_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_CurrParamComp_CurrParamComp_Init_Return(void);
# else
#  define Rte_Runnable_Ap_CurrParamComp_CurrParamComp_Init_Return() ((void)(0))
# endif /* Rte_Runnable_Ap_CurrParamComp_CurrParamComp_Init_Return */

# if defined (Rte_Runnable_Ap_CurrParamComp_CurrParamComp_Init_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_CurrParamComp_CurrParamComp_Init_Start
# endif
# if defined (Rte_Runnable_Ap_CurrParamComp_CurrParamComp_Init_Start)
#  undef Rte_Runnable_Ap_CurrParamComp_CurrParamComp_Init_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_CurrParamComp_CurrParamComp_Init_Start(void);
# else
#  define Rte_Runnable_Ap_CurrParamComp_CurrParamComp_Init_Start() ((void)(0))
# endif /* Rte_Runnable_Ap_CurrParamComp_CurrParamComp_Init_Start */

# if defined (Rte_Runnable_Ap_CurrParamComp_CurrParamComp_Per1_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_CurrParamComp_CurrParamComp_Per1_Return
# endif
# if defined (Rte_Runnable_Ap_CurrParamComp_CurrParamComp_Per1_Return)
#  undef Rte_Runnable_Ap_CurrParamComp_CurrParamComp_Per1_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_CurrParamComp_CurrParamComp_Per1_Return(void);
# else
#  define Rte_Runnable_Ap_CurrParamComp_CurrParamComp_Per1_Return() ((void)(0))
# endif /* Rte_Runnable_Ap_CurrParamComp_CurrParamComp_Per1_Return */

# if defined (Rte_Runnable_Ap_CurrParamComp_CurrParamComp_Per1_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_CurrParamComp_CurrParamComp_Per1_Start
# endif
# if defined (Rte_Runnable_Ap_CurrParamComp_CurrParamComp_Per1_Start)
#  undef Rte_Runnable_Ap_CurrParamComp_CurrParamComp_Per1_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_CurrParamComp_CurrParamComp_Per1_Start(void);
# else
#  define Rte_Runnable_Ap_CurrParamComp_CurrParamComp_Per1_Start() ((void)(0))
# endif /* Rte_Runnable_Ap_CurrParamComp_CurrParamComp_Per1_Start */

# if defined (Rte_Runnable_Ap_CurrParamComp_CurrParamComp_Per2_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_CurrParamComp_CurrParamComp_Per2_Return
# endif
# if defined (Rte_Runnable_Ap_CurrParamComp_CurrParamComp_Per2_Return)
#  undef Rte_Runnable_Ap_CurrParamComp_CurrParamComp_Per2_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_CurrParamComp_CurrParamComp_Per2_Return(void);
# else
#  define Rte_Runnable_Ap_CurrParamComp_CurrParamComp_Per2_Return() ((void)(0))
# endif /* Rte_Runnable_Ap_CurrParamComp_CurrParamComp_Per2_Return */

# if defined (Rte_Runnable_Ap_CurrParamComp_CurrParamComp_Per2_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_CurrParamComp_CurrParamComp_Per2_Start
# endif
# if defined (Rte_Runnable_Ap_CurrParamComp_CurrParamComp_Per2_Start)
#  undef Rte_Runnable_Ap_CurrParamComp_CurrParamComp_Per2_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_CurrParamComp_CurrParamComp_Per2_Start(void);
# else
#  define Rte_Runnable_Ap_CurrParamComp_CurrParamComp_Per2_Start() ((void)(0))
# endif /* Rte_Runnable_Ap_CurrParamComp_CurrParamComp_Per2_Start */

# if defined (Rte_Runnable_Ap_CurrParamComp_SCom_EOLNomMtrParam_Get_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_CurrParamComp_SCom_EOLNomMtrParam_Get_Return
# endif
# if defined (Rte_Runnable_Ap_CurrParamComp_SCom_EOLNomMtrParam_Get_Return)
#  undef Rte_Runnable_Ap_CurrParamComp_SCom_EOLNomMtrParam_Get_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_CurrParamComp_SCom_EOLNomMtrParam_Get_Return(P2VAR(Float, AUTOMATIC, RTE_AP_CURRPARAMCOMP_APPL_VAR) NomKe_VpRadpS_f32, P2VAR(Float, AUTOMATIC, RTE_AP_CURRPARAMCOMP_APPL_VAR) NomRmtr_Ohm_f32);
# else
#  define Rte_Runnable_Ap_CurrParamComp_SCom_EOLNomMtrParam_Get_Return(arg1, arg2) ((void)(0))
# endif /* Rte_Runnable_Ap_CurrParamComp_SCom_EOLNomMtrParam_Get_Return */

# if defined (Rte_Runnable_Ap_CurrParamComp_SCom_EOLNomMtrParam_Get_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_CurrParamComp_SCom_EOLNomMtrParam_Get_Start
# endif
# if defined (Rte_Runnable_Ap_CurrParamComp_SCom_EOLNomMtrParam_Get_Start)
#  undef Rte_Runnable_Ap_CurrParamComp_SCom_EOLNomMtrParam_Get_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_CurrParamComp_SCom_EOLNomMtrParam_Get_Start(P2VAR(Float, AUTOMATIC, RTE_AP_CURRPARAMCOMP_APPL_VAR) NomKe_VpRadpS_f32, P2VAR(Float, AUTOMATIC, RTE_AP_CURRPARAMCOMP_APPL_VAR) NomRmtr_Ohm_f32);
# else
#  define Rte_Runnable_Ap_CurrParamComp_SCom_EOLNomMtrParam_Get_Start(arg1, arg2) ((void)(0))
# endif /* Rte_Runnable_Ap_CurrParamComp_SCom_EOLNomMtrParam_Get_Start */

# if defined (Rte_Runnable_Ap_CurrParamComp_SCom_EOLNomMtrParam_Set_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_CurrParamComp_SCom_EOLNomMtrParam_Set_Return
# endif
# if defined (Rte_Runnable_Ap_CurrParamComp_SCom_EOLNomMtrParam_Set_Return)
#  undef Rte_Runnable_Ap_CurrParamComp_SCom_EOLNomMtrParam_Set_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_CurrParamComp_SCom_EOLNomMtrParam_Set_Return(Float NomKe_VpRadpS_f32, Float NomRmtr_Ohm_f32);
# else
#  define Rte_Runnable_Ap_CurrParamComp_SCom_EOLNomMtrParam_Set_Return(arg1, arg2) ((void)(0))
# endif /* Rte_Runnable_Ap_CurrParamComp_SCom_EOLNomMtrParam_Set_Return */

# if defined (Rte_Runnable_Ap_CurrParamComp_SCom_EOLNomMtrParam_Set_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_CurrParamComp_SCom_EOLNomMtrParam_Set_Start
# endif
# if defined (Rte_Runnable_Ap_CurrParamComp_SCom_EOLNomMtrParam_Set_Start)
#  undef Rte_Runnable_Ap_CurrParamComp_SCom_EOLNomMtrParam_Set_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_CurrParamComp_SCom_EOLNomMtrParam_Set_Start(Float NomKe_VpRadpS_f32, Float NomRmtr_Ohm_f32);
# else
#  define Rte_Runnable_Ap_CurrParamComp_SCom_EOLNomMtrParam_Set_Start(arg1, arg2) ((void)(0))
# endif /* Rte_Runnable_Ap_CurrParamComp_SCom_EOLNomMtrParam_Set_Start */

# if defined (Rte_Runnable_Ap_DampingFirewall_DampingFirewall_Init1_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_DampingFirewall_DampingFirewall_Init1_Return
# endif
# if defined (Rte_Runnable_Ap_DampingFirewall_DampingFirewall_Init1_Return)
#  undef Rte_Runnable_Ap_DampingFirewall_DampingFirewall_Init1_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_DampingFirewall_DampingFirewall_Init1_Return(void);
# else
#  define Rte_Runnable_Ap_DampingFirewall_DampingFirewall_Init1_Return() ((void)(0))
# endif /* Rte_Runnable_Ap_DampingFirewall_DampingFirewall_Init1_Return */

# if defined (Rte_Runnable_Ap_DampingFirewall_DampingFirewall_Init1_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_DampingFirewall_DampingFirewall_Init1_Start
# endif
# if defined (Rte_Runnable_Ap_DampingFirewall_DampingFirewall_Init1_Start)
#  undef Rte_Runnable_Ap_DampingFirewall_DampingFirewall_Init1_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_DampingFirewall_DampingFirewall_Init1_Start(void);
# else
#  define Rte_Runnable_Ap_DampingFirewall_DampingFirewall_Init1_Start() ((void)(0))
# endif /* Rte_Runnable_Ap_DampingFirewall_DampingFirewall_Init1_Start */

# if defined (Rte_Runnable_Ap_DampingFirewall_DampingFirewall_Per1_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_DampingFirewall_DampingFirewall_Per1_Return
# endif
# if defined (Rte_Runnable_Ap_DampingFirewall_DampingFirewall_Per1_Return)
#  undef Rte_Runnable_Ap_DampingFirewall_DampingFirewall_Per1_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_DampingFirewall_DampingFirewall_Per1_Return(void);
# else
#  define Rte_Runnable_Ap_DampingFirewall_DampingFirewall_Per1_Return() ((void)(0))
# endif /* Rte_Runnable_Ap_DampingFirewall_DampingFirewall_Per1_Return */

# if defined (Rte_Runnable_Ap_DampingFirewall_DampingFirewall_Per1_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_DampingFirewall_DampingFirewall_Per1_Start
# endif
# if defined (Rte_Runnable_Ap_DampingFirewall_DampingFirewall_Per1_Start)
#  undef Rte_Runnable_Ap_DampingFirewall_DampingFirewall_Per1_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_DampingFirewall_DampingFirewall_Per1_Start(void);
# else
#  define Rte_Runnable_Ap_DampingFirewall_DampingFirewall_Per1_Start() ((void)(0))
# endif /* Rte_Runnable_Ap_DampingFirewall_DampingFirewall_Per1_Start */

# if defined (Rte_Runnable_Ap_Damping_Damping_Init1_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_Damping_Damping_Init1_Return
# endif
# if defined (Rte_Runnable_Ap_Damping_Damping_Init1_Return)
#  undef Rte_Runnable_Ap_Damping_Damping_Init1_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_Damping_Damping_Init1_Return(void);
# else
#  define Rte_Runnable_Ap_Damping_Damping_Init1_Return() ((void)(0))
# endif /* Rte_Runnable_Ap_Damping_Damping_Init1_Return */

# if defined (Rte_Runnable_Ap_Damping_Damping_Init1_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_Damping_Damping_Init1_Start
# endif
# if defined (Rte_Runnable_Ap_Damping_Damping_Init1_Start)
#  undef Rte_Runnable_Ap_Damping_Damping_Init1_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_Damping_Damping_Init1_Start(void);
# else
#  define Rte_Runnable_Ap_Damping_Damping_Init1_Start() ((void)(0))
# endif /* Rte_Runnable_Ap_Damping_Damping_Init1_Start */

# if defined (Rte_Runnable_Ap_Damping_Damping_Per1_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_Damping_Damping_Per1_Return
# endif
# if defined (Rte_Runnable_Ap_Damping_Damping_Per1_Return)
#  undef Rte_Runnable_Ap_Damping_Damping_Per1_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_Damping_Damping_Per1_Return(void);
# else
#  define Rte_Runnable_Ap_Damping_Damping_Per1_Return() ((void)(0))
# endif /* Rte_Runnable_Ap_Damping_Damping_Per1_Return */

# if defined (Rte_Runnable_Ap_Damping_Damping_Per1_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_Damping_Damping_Per1_Start
# endif
# if defined (Rte_Runnable_Ap_Damping_Damping_Per1_Start)
#  undef Rte_Runnable_Ap_Damping_Damping_Per1_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_Damping_Damping_Per1_Start(void);
# else
#  define Rte_Runnable_Ap_Damping_Damping_Per1_Start() ((void)(0))
# endif /* Rte_Runnable_Ap_Damping_Damping_Per1_Start */

# if defined (Rte_Runnable_Ap_DemIf_DemIf_Init_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_DemIf_DemIf_Init_Return
# endif
# if defined (Rte_Runnable_Ap_DemIf_DemIf_Init_Return)
#  undef Rte_Runnable_Ap_DemIf_DemIf_Init_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_DemIf_DemIf_Init_Return(void);
# else
#  define Rte_Runnable_Ap_DemIf_DemIf_Init_Return() ((void)(0))
# endif /* Rte_Runnable_Ap_DemIf_DemIf_Init_Return */

# if defined (Rte_Runnable_Ap_DemIf_DemIf_Init_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_DemIf_DemIf_Init_Start
# endif
# if defined (Rte_Runnable_Ap_DemIf_DemIf_Init_Start)
#  undef Rte_Runnable_Ap_DemIf_DemIf_Init_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_DemIf_DemIf_Init_Start(void);
# else
#  define Rte_Runnable_Ap_DemIf_DemIf_Init_Start() ((void)(0))
# endif /* Rte_Runnable_Ap_DemIf_DemIf_Init_Start */

# if defined (Rte_Runnable_Ap_DemIf_DemIf_RestartDem_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_DemIf_DemIf_RestartDem_Return
# endif
# if defined (Rte_Runnable_Ap_DemIf_DemIf_RestartDem_Return)
#  undef Rte_Runnable_Ap_DemIf_DemIf_RestartDem_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_DemIf_DemIf_RestartDem_Return(void);
# else
#  define Rte_Runnable_Ap_DemIf_DemIf_RestartDem_Return() ((void)(0))
# endif /* Rte_Runnable_Ap_DemIf_DemIf_RestartDem_Return */

# if defined (Rte_Runnable_Ap_DemIf_DemIf_RestartDem_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_DemIf_DemIf_RestartDem_Start
# endif
# if defined (Rte_Runnable_Ap_DemIf_DemIf_RestartDem_Start)
#  undef Rte_Runnable_Ap_DemIf_DemIf_RestartDem_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_DemIf_DemIf_RestartDem_Start(void);
# else
#  define Rte_Runnable_Ap_DemIf_DemIf_RestartDem_Start() ((void)(0))
# endif /* Rte_Runnable_Ap_DemIf_DemIf_RestartDem_Start */

# if defined (Rte_Runnable_Ap_DemIf_DemIf_SetEventStatus_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_DemIf_DemIf_SetEventStatus_Return
# endif
# if defined (Rte_Runnable_Ap_DemIf_DemIf_SetEventStatus_Return)
#  undef Rte_Runnable_Ap_DemIf_DemIf_SetEventStatus_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_DemIf_DemIf_SetEventStatus_Return(UInt8 EventId, NxtrDiagMgrStatus EventStatus);
# else
#  define Rte_Runnable_Ap_DemIf_DemIf_SetEventStatus_Return(arg1, arg2) ((void)(0))
# endif /* Rte_Runnable_Ap_DemIf_DemIf_SetEventStatus_Return */

# if defined (Rte_Runnable_Ap_DemIf_DemIf_SetEventStatus_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_DemIf_DemIf_SetEventStatus_Start
# endif
# if defined (Rte_Runnable_Ap_DemIf_DemIf_SetEventStatus_Start)
#  undef Rte_Runnable_Ap_DemIf_DemIf_SetEventStatus_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_DemIf_DemIf_SetEventStatus_Start(UInt8 EventId, NxtrDiagMgrStatus EventStatus);
# else
#  define Rte_Runnable_Ap_DemIf_DemIf_SetEventStatus_Start(arg1, arg2) ((void)(0))
# endif /* Rte_Runnable_Ap_DemIf_DemIf_SetEventStatus_Start */

# if defined (Rte_Runnable_Ap_DemIf_DemIf_SetInputsConditions_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_DemIf_DemIf_SetInputsConditions_Return
# endif
# if defined (Rte_Runnable_Ap_DemIf_DemIf_SetInputsConditions_Return)
#  undef Rte_Runnable_Ap_DemIf_DemIf_SetInputsConditions_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_DemIf_DemIf_SetInputsConditions_Return(void);
# else
#  define Rte_Runnable_Ap_DemIf_DemIf_SetInputsConditions_Return() ((void)(0))
# endif /* Rte_Runnable_Ap_DemIf_DemIf_SetInputsConditions_Return */

# if defined (Rte_Runnable_Ap_DemIf_DemIf_SetInputsConditions_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_DemIf_DemIf_SetInputsConditions_Start
# endif
# if defined (Rte_Runnable_Ap_DemIf_DemIf_SetInputsConditions_Start)
#  undef Rte_Runnable_Ap_DemIf_DemIf_SetInputsConditions_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_DemIf_DemIf_SetInputsConditions_Start(void);
# else
#  define Rte_Runnable_Ap_DemIf_DemIf_SetInputsConditions_Start() ((void)(0))
# endif /* Rte_Runnable_Ap_DemIf_DemIf_SetInputsConditions_Start */

# if defined (Rte_Runnable_Ap_DemIf_DemIf_SetOperationCycleState_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_DemIf_DemIf_SetOperationCycleState_Return
# endif
# if defined (Rte_Runnable_Ap_DemIf_DemIf_SetOperationCycleState_Return)
#  undef Rte_Runnable_Ap_DemIf_DemIf_SetOperationCycleState_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_DemIf_DemIf_SetOperationCycleState_Return(NxtrOpCycle NxtrOperationCycleId, NxtrOpCycleState NxtrCycleState);
# else
#  define Rte_Runnable_Ap_DemIf_DemIf_SetOperationCycleState_Return(arg1, arg2) ((void)(0))
# endif /* Rte_Runnable_Ap_DemIf_DemIf_SetOperationCycleState_Return */

# if defined (Rte_Runnable_Ap_DemIf_DemIf_SetOperationCycleState_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_DemIf_DemIf_SetOperationCycleState_Start
# endif
# if defined (Rte_Runnable_Ap_DemIf_DemIf_SetOperationCycleState_Start)
#  undef Rte_Runnable_Ap_DemIf_DemIf_SetOperationCycleState_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_DemIf_DemIf_SetOperationCycleState_Start(NxtrOpCycle NxtrOperationCycleId, NxtrOpCycleState NxtrCycleState);
# else
#  define Rte_Runnable_Ap_DemIf_DemIf_SetOperationCycleState_Start(arg1, arg2) ((void)(0))
# endif /* Rte_Runnable_Ap_DemIf_DemIf_SetOperationCycleState_Start */

# if defined (Rte_Runnable_Ap_DemIf_DemIf_Shutdown_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_DemIf_DemIf_Shutdown_Return
# endif
# if defined (Rte_Runnable_Ap_DemIf_DemIf_Shutdown_Return)
#  undef Rte_Runnable_Ap_DemIf_DemIf_Shutdown_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_DemIf_DemIf_Shutdown_Return(void);
# else
#  define Rte_Runnable_Ap_DemIf_DemIf_Shutdown_Return() ((void)(0))
# endif /* Rte_Runnable_Ap_DemIf_DemIf_Shutdown_Return */

# if defined (Rte_Runnable_Ap_DemIf_DemIf_Shutdown_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_DemIf_DemIf_Shutdown_Start
# endif
# if defined (Rte_Runnable_Ap_DemIf_DemIf_Shutdown_Start)
#  undef Rte_Runnable_Ap_DemIf_DemIf_Shutdown_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_DemIf_DemIf_Shutdown_Start(void);
# else
#  define Rte_Runnable_Ap_DemIf_DemIf_Shutdown_Start() ((void)(0))
# endif /* Rte_Runnable_Ap_DemIf_DemIf_Shutdown_Start */

# if defined (Rte_Runnable_Ap_DiagMgr10_DiagMgr10_Init_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_DiagMgr10_DiagMgr10_Init_Return
# endif
# if defined (Rte_Runnable_Ap_DiagMgr10_DiagMgr10_Init_Return)
#  undef Rte_Runnable_Ap_DiagMgr10_DiagMgr10_Init_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_DiagMgr10_DiagMgr10_Init_Return(void);
# else
#  define Rte_Runnable_Ap_DiagMgr10_DiagMgr10_Init_Return() ((void)(0))
# endif /* Rte_Runnable_Ap_DiagMgr10_DiagMgr10_Init_Return */

# if defined (Rte_Runnable_Ap_DiagMgr10_DiagMgr10_Init_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_DiagMgr10_DiagMgr10_Init_Start
# endif
# if defined (Rte_Runnable_Ap_DiagMgr10_DiagMgr10_Init_Start)
#  undef Rte_Runnable_Ap_DiagMgr10_DiagMgr10_Init_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_DiagMgr10_DiagMgr10_Init_Start(void);
# else
#  define Rte_Runnable_Ap_DiagMgr10_DiagMgr10_Init_Start() ((void)(0))
# endif /* Rte_Runnable_Ap_DiagMgr10_DiagMgr10_Init_Start */

# if defined (Rte_Runnable_Ap_DiagMgr10_DiagMgr10_Per_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_DiagMgr10_DiagMgr10_Per_Return
# endif
# if defined (Rte_Runnable_Ap_DiagMgr10_DiagMgr10_Per_Return)
#  undef Rte_Runnable_Ap_DiagMgr10_DiagMgr10_Per_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_DiagMgr10_DiagMgr10_Per_Return(void);
# else
#  define Rte_Runnable_Ap_DiagMgr10_DiagMgr10_Per_Return() ((void)(0))
# endif /* Rte_Runnable_Ap_DiagMgr10_DiagMgr10_Per_Return */

# if defined (Rte_Runnable_Ap_DiagMgr10_DiagMgr10_Per_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_DiagMgr10_DiagMgr10_Per_Start
# endif
# if defined (Rte_Runnable_Ap_DiagMgr10_DiagMgr10_Per_Start)
#  undef Rte_Runnable_Ap_DiagMgr10_DiagMgr10_Per_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_DiagMgr10_DiagMgr10_Per_Start(void);
# else
#  define Rte_Runnable_Ap_DiagMgr10_DiagMgr10_Per_Start() ((void)(0))
# endif /* Rte_Runnable_Ap_DiagMgr10_DiagMgr10_Per_Start */

# if defined (Rte_Runnable_Ap_DiagMgr10_DiagMgr10_Trns_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_DiagMgr10_DiagMgr10_Trns_Return
# endif
# if defined (Rte_Runnable_Ap_DiagMgr10_DiagMgr10_Trns_Return)
#  undef Rte_Runnable_Ap_DiagMgr10_DiagMgr10_Trns_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_DiagMgr10_DiagMgr10_Trns_Return(void);
# else
#  define Rte_Runnable_Ap_DiagMgr10_DiagMgr10_Trns_Return() ((void)(0))
# endif /* Rte_Runnable_Ap_DiagMgr10_DiagMgr10_Trns_Return */

# if defined (Rte_Runnable_Ap_DiagMgr10_DiagMgr10_Trns_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_DiagMgr10_DiagMgr10_Trns_Start
# endif
# if defined (Rte_Runnable_Ap_DiagMgr10_DiagMgr10_Trns_Start)
#  undef Rte_Runnable_Ap_DiagMgr10_DiagMgr10_Trns_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_DiagMgr10_DiagMgr10_Trns_Start(void);
# else
#  define Rte_Runnable_Ap_DiagMgr10_DiagMgr10_Trns_Start() ((void)(0))
# endif /* Rte_Runnable_Ap_DiagMgr10_DiagMgr10_Trns_Start */

# if defined (Rte_Runnable_Ap_DiagMgr10_DiagMgr_Per1_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_DiagMgr10_DiagMgr_Per1_Return
# endif
# if defined (Rte_Runnable_Ap_DiagMgr10_DiagMgr_Per1_Return)
#  undef Rte_Runnable_Ap_DiagMgr10_DiagMgr_Per1_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_DiagMgr10_DiagMgr_Per1_Return(void);
# else
#  define Rte_Runnable_Ap_DiagMgr10_DiagMgr_Per1_Return() ((void)(0))
# endif /* Rte_Runnable_Ap_DiagMgr10_DiagMgr_Per1_Return */

# if defined (Rte_Runnable_Ap_DiagMgr10_DiagMgr_Per1_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_DiagMgr10_DiagMgr_Per1_Start
# endif
# if defined (Rte_Runnable_Ap_DiagMgr10_DiagMgr_Per1_Start)
#  undef Rte_Runnable_Ap_DiagMgr10_DiagMgr_Per1_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_DiagMgr10_DiagMgr_Per1_Start(void);
# else
#  define Rte_Runnable_Ap_DiagMgr10_DiagMgr_Per1_Start() ((void)(0))
# endif /* Rte_Runnable_Ap_DiagMgr10_DiagMgr_Per1_Start */

# if defined (Rte_Runnable_Ap_DiagMgr10_NxtrDiagMgr10_GetNTCActive_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_DiagMgr10_NxtrDiagMgr10_GetNTCActive_Return
# endif
# if defined (Rte_Runnable_Ap_DiagMgr10_NxtrDiagMgr10_GetNTCActive_Return)
#  undef Rte_Runnable_Ap_DiagMgr10_NxtrDiagMgr10_GetNTCActive_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_DiagMgr10_NxtrDiagMgr10_GetNTCActive_Return(NTCNumber NTC_Cnt_T_enum, P2VAR(Boolean, AUTOMATIC, RTE_AP_DIAGMGR10_APPL_VAR) NTCActive_Ptr_T_lgc);
# else
#  define Rte_Runnable_Ap_DiagMgr10_NxtrDiagMgr10_GetNTCActive_Return(arg1, arg2) ((void)(0))
# endif /* Rte_Runnable_Ap_DiagMgr10_NxtrDiagMgr10_GetNTCActive_Return */

# if defined (Rte_Runnable_Ap_DiagMgr10_NxtrDiagMgr10_GetNTCActive_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_DiagMgr10_NxtrDiagMgr10_GetNTCActive_Start
# endif
# if defined (Rte_Runnable_Ap_DiagMgr10_NxtrDiagMgr10_GetNTCActive_Start)
#  undef Rte_Runnable_Ap_DiagMgr10_NxtrDiagMgr10_GetNTCActive_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_DiagMgr10_NxtrDiagMgr10_GetNTCActive_Start(NTCNumber NTC_Cnt_T_enum, P2VAR(Boolean, AUTOMATIC, RTE_AP_DIAGMGR10_APPL_VAR) NTCActive_Ptr_T_lgc);
# else
#  define Rte_Runnable_Ap_DiagMgr10_NxtrDiagMgr10_GetNTCActive_Start(arg1, arg2) ((void)(0))
# endif /* Rte_Runnable_Ap_DiagMgr10_NxtrDiagMgr10_GetNTCActive_Start */

# if defined (Rte_Runnable_Ap_DiagMgr10_NxtrDiagMgr10_GetNTCFailed_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_DiagMgr10_NxtrDiagMgr10_GetNTCFailed_Return
# endif
# if defined (Rte_Runnable_Ap_DiagMgr10_NxtrDiagMgr10_GetNTCFailed_Return)
#  undef Rte_Runnable_Ap_DiagMgr10_NxtrDiagMgr10_GetNTCFailed_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_DiagMgr10_NxtrDiagMgr10_GetNTCFailed_Return(NTCNumber NTC_Cnt_T_enum, P2VAR(Boolean, AUTOMATIC, RTE_AP_DIAGMGR10_APPL_VAR) NTCFailed_Ptr_T_lgc);
# else
#  define Rte_Runnable_Ap_DiagMgr10_NxtrDiagMgr10_GetNTCFailed_Return(arg1, arg2) ((void)(0))
# endif /* Rte_Runnable_Ap_DiagMgr10_NxtrDiagMgr10_GetNTCFailed_Return */

# if defined (Rte_Runnable_Ap_DiagMgr10_NxtrDiagMgr10_GetNTCFailed_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_DiagMgr10_NxtrDiagMgr10_GetNTCFailed_Start
# endif
# if defined (Rte_Runnable_Ap_DiagMgr10_NxtrDiagMgr10_GetNTCFailed_Start)
#  undef Rte_Runnable_Ap_DiagMgr10_NxtrDiagMgr10_GetNTCFailed_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_DiagMgr10_NxtrDiagMgr10_GetNTCFailed_Start(NTCNumber NTC_Cnt_T_enum, P2VAR(Boolean, AUTOMATIC, RTE_AP_DIAGMGR10_APPL_VAR) NTCFailed_Ptr_T_lgc);
# else
#  define Rte_Runnable_Ap_DiagMgr10_NxtrDiagMgr10_GetNTCFailed_Start(arg1, arg2) ((void)(0))
# endif /* Rte_Runnable_Ap_DiagMgr10_NxtrDiagMgr10_GetNTCFailed_Start */

# if defined (Rte_Runnable_Ap_DiagMgr10_NxtrDiagMgr10_GetNTCStatus_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_DiagMgr10_NxtrDiagMgr10_GetNTCStatus_Return
# endif
# if defined (Rte_Runnable_Ap_DiagMgr10_NxtrDiagMgr10_GetNTCStatus_Return)
#  undef Rte_Runnable_Ap_DiagMgr10_NxtrDiagMgr10_GetNTCStatus_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_DiagMgr10_NxtrDiagMgr10_GetNTCStatus_Return(NTCNumber NTC_Cnt_T_enum, P2VAR(UInt8, AUTOMATIC, RTE_AP_DIAGMGR10_APPL_VAR) Status_Ptr_T_u08);
# else
#  define Rte_Runnable_Ap_DiagMgr10_NxtrDiagMgr10_GetNTCStatus_Return(arg1, arg2) ((void)(0))
# endif /* Rte_Runnable_Ap_DiagMgr10_NxtrDiagMgr10_GetNTCStatus_Return */

# if defined (Rte_Runnable_Ap_DiagMgr10_NxtrDiagMgr10_GetNTCStatus_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_DiagMgr10_NxtrDiagMgr10_GetNTCStatus_Start
# endif
# if defined (Rte_Runnable_Ap_DiagMgr10_NxtrDiagMgr10_GetNTCStatus_Start)
#  undef Rte_Runnable_Ap_DiagMgr10_NxtrDiagMgr10_GetNTCStatus_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_DiagMgr10_NxtrDiagMgr10_GetNTCStatus_Start(NTCNumber NTC_Cnt_T_enum, P2VAR(UInt8, AUTOMATIC, RTE_AP_DIAGMGR10_APPL_VAR) Status_Ptr_T_u08);
# else
#  define Rte_Runnable_Ap_DiagMgr10_NxtrDiagMgr10_GetNTCStatus_Start(arg1, arg2) ((void)(0))
# endif /* Rte_Runnable_Ap_DiagMgr10_NxtrDiagMgr10_GetNTCStatus_Start */

# if defined (Rte_Runnable_Ap_DiagMgr10_NxtrDiagMgr10_SetNTCStatus_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_DiagMgr10_NxtrDiagMgr10_SetNTCStatus_Return
# endif
# if defined (Rte_Runnable_Ap_DiagMgr10_NxtrDiagMgr10_SetNTCStatus_Return)
#  undef Rte_Runnable_Ap_DiagMgr10_NxtrDiagMgr10_SetNTCStatus_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_DiagMgr10_NxtrDiagMgr10_SetNTCStatus_Return(NTCNumber NTC_Cnt_T_enum, UInt8 Param_Cnt_T_u08, NxtrDiagMgrStatus Status_Cnt_T_enum);
# else
#  define Rte_Runnable_Ap_DiagMgr10_NxtrDiagMgr10_SetNTCStatus_Return(arg1, arg2, arg3) ((void)(0))
# endif /* Rte_Runnable_Ap_DiagMgr10_NxtrDiagMgr10_SetNTCStatus_Return */

# if defined (Rte_Runnable_Ap_DiagMgr10_NxtrDiagMgr10_SetNTCStatus_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_DiagMgr10_NxtrDiagMgr10_SetNTCStatus_Start
# endif
# if defined (Rte_Runnable_Ap_DiagMgr10_NxtrDiagMgr10_SetNTCStatus_Start)
#  undef Rte_Runnable_Ap_DiagMgr10_NxtrDiagMgr10_SetNTCStatus_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_DiagMgr10_NxtrDiagMgr10_SetNTCStatus_Start(NTCNumber NTC_Cnt_T_enum, UInt8 Param_Cnt_T_u08, NxtrDiagMgrStatus Status_Cnt_T_enum);
# else
#  define Rte_Runnable_Ap_DiagMgr10_NxtrDiagMgr10_SetNTCStatus_Start(arg1, arg2, arg3) ((void)(0))
# endif /* Rte_Runnable_Ap_DiagMgr10_NxtrDiagMgr10_SetNTCStatus_Start */

# if defined (Rte_Runnable_Ap_DiagMgr8_DiagMgr8_Init_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_DiagMgr8_DiagMgr8_Init_Return
# endif
# if defined (Rte_Runnable_Ap_DiagMgr8_DiagMgr8_Init_Return)
#  undef Rte_Runnable_Ap_DiagMgr8_DiagMgr8_Init_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_DiagMgr8_DiagMgr8_Init_Return(void);
# else
#  define Rte_Runnable_Ap_DiagMgr8_DiagMgr8_Init_Return() ((void)(0))
# endif /* Rte_Runnable_Ap_DiagMgr8_DiagMgr8_Init_Return */

# if defined (Rte_Runnable_Ap_DiagMgr8_DiagMgr8_Init_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_DiagMgr8_DiagMgr8_Init_Start
# endif
# if defined (Rte_Runnable_Ap_DiagMgr8_DiagMgr8_Init_Start)
#  undef Rte_Runnable_Ap_DiagMgr8_DiagMgr8_Init_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_DiagMgr8_DiagMgr8_Init_Start(void);
# else
#  define Rte_Runnable_Ap_DiagMgr8_DiagMgr8_Init_Start() ((void)(0))
# endif /* Rte_Runnable_Ap_DiagMgr8_DiagMgr8_Init_Start */

# if defined (Rte_Runnable_Ap_DiagMgr8_DiagMgr8_Per_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_DiagMgr8_DiagMgr8_Per_Return
# endif
# if defined (Rte_Runnable_Ap_DiagMgr8_DiagMgr8_Per_Return)
#  undef Rte_Runnable_Ap_DiagMgr8_DiagMgr8_Per_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_DiagMgr8_DiagMgr8_Per_Return(void);
# else
#  define Rte_Runnable_Ap_DiagMgr8_DiagMgr8_Per_Return() ((void)(0))
# endif /* Rte_Runnable_Ap_DiagMgr8_DiagMgr8_Per_Return */

# if defined (Rte_Runnable_Ap_DiagMgr8_DiagMgr8_Per_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_DiagMgr8_DiagMgr8_Per_Start
# endif
# if defined (Rte_Runnable_Ap_DiagMgr8_DiagMgr8_Per_Start)
#  undef Rte_Runnable_Ap_DiagMgr8_DiagMgr8_Per_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_DiagMgr8_DiagMgr8_Per_Start(void);
# else
#  define Rte_Runnable_Ap_DiagMgr8_DiagMgr8_Per_Start() ((void)(0))
# endif /* Rte_Runnable_Ap_DiagMgr8_DiagMgr8_Per_Start */

# if defined (Rte_Runnable_Ap_DiagMgr8_DiagMgr8_Trns_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_DiagMgr8_DiagMgr8_Trns_Return
# endif
# if defined (Rte_Runnable_Ap_DiagMgr8_DiagMgr8_Trns_Return)
#  undef Rte_Runnable_Ap_DiagMgr8_DiagMgr8_Trns_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_DiagMgr8_DiagMgr8_Trns_Return(void);
# else
#  define Rte_Runnable_Ap_DiagMgr8_DiagMgr8_Trns_Return() ((void)(0))
# endif /* Rte_Runnable_Ap_DiagMgr8_DiagMgr8_Trns_Return */

# if defined (Rte_Runnable_Ap_DiagMgr8_DiagMgr8_Trns_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_DiagMgr8_DiagMgr8_Trns_Start
# endif
# if defined (Rte_Runnable_Ap_DiagMgr8_DiagMgr8_Trns_Start)
#  undef Rte_Runnable_Ap_DiagMgr8_DiagMgr8_Trns_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_DiagMgr8_DiagMgr8_Trns_Start(void);
# else
#  define Rte_Runnable_Ap_DiagMgr8_DiagMgr8_Trns_Start() ((void)(0))
# endif /* Rte_Runnable_Ap_DiagMgr8_DiagMgr8_Trns_Start */

# if defined (Rte_Runnable_Ap_DiagMgr8_NxtrDiagMgr8_GetNTCActive_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_DiagMgr8_NxtrDiagMgr8_GetNTCActive_Return
# endif
# if defined (Rte_Runnable_Ap_DiagMgr8_NxtrDiagMgr8_GetNTCActive_Return)
#  undef Rte_Runnable_Ap_DiagMgr8_NxtrDiagMgr8_GetNTCActive_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_DiagMgr8_NxtrDiagMgr8_GetNTCActive_Return(NTCNumber NTC_Cnt_T_enum, P2VAR(Boolean, AUTOMATIC, RTE_AP_DIAGMGR8_APPL_VAR) NTCActive_Ptr_T_lgc);
# else
#  define Rte_Runnable_Ap_DiagMgr8_NxtrDiagMgr8_GetNTCActive_Return(arg1, arg2) ((void)(0))
# endif /* Rte_Runnable_Ap_DiagMgr8_NxtrDiagMgr8_GetNTCActive_Return */

# if defined (Rte_Runnable_Ap_DiagMgr8_NxtrDiagMgr8_GetNTCActive_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_DiagMgr8_NxtrDiagMgr8_GetNTCActive_Start
# endif
# if defined (Rte_Runnable_Ap_DiagMgr8_NxtrDiagMgr8_GetNTCActive_Start)
#  undef Rte_Runnable_Ap_DiagMgr8_NxtrDiagMgr8_GetNTCActive_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_DiagMgr8_NxtrDiagMgr8_GetNTCActive_Start(NTCNumber NTC_Cnt_T_enum, P2VAR(Boolean, AUTOMATIC, RTE_AP_DIAGMGR8_APPL_VAR) NTCActive_Ptr_T_lgc);
# else
#  define Rte_Runnable_Ap_DiagMgr8_NxtrDiagMgr8_GetNTCActive_Start(arg1, arg2) ((void)(0))
# endif /* Rte_Runnable_Ap_DiagMgr8_NxtrDiagMgr8_GetNTCActive_Start */

# if defined (Rte_Runnable_Ap_DiagMgr8_NxtrDiagMgr8_GetNTCFailed_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_DiagMgr8_NxtrDiagMgr8_GetNTCFailed_Return
# endif
# if defined (Rte_Runnable_Ap_DiagMgr8_NxtrDiagMgr8_GetNTCFailed_Return)
#  undef Rte_Runnable_Ap_DiagMgr8_NxtrDiagMgr8_GetNTCFailed_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_DiagMgr8_NxtrDiagMgr8_GetNTCFailed_Return(NTCNumber NTC_Cnt_T_enum, P2VAR(Boolean, AUTOMATIC, RTE_AP_DIAGMGR8_APPL_VAR) NTCFailed_Ptr_T_lgc);
# else
#  define Rte_Runnable_Ap_DiagMgr8_NxtrDiagMgr8_GetNTCFailed_Return(arg1, arg2) ((void)(0))
# endif /* Rte_Runnable_Ap_DiagMgr8_NxtrDiagMgr8_GetNTCFailed_Return */

# if defined (Rte_Runnable_Ap_DiagMgr8_NxtrDiagMgr8_GetNTCFailed_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_DiagMgr8_NxtrDiagMgr8_GetNTCFailed_Start
# endif
# if defined (Rte_Runnable_Ap_DiagMgr8_NxtrDiagMgr8_GetNTCFailed_Start)
#  undef Rte_Runnable_Ap_DiagMgr8_NxtrDiagMgr8_GetNTCFailed_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_DiagMgr8_NxtrDiagMgr8_GetNTCFailed_Start(NTCNumber NTC_Cnt_T_enum, P2VAR(Boolean, AUTOMATIC, RTE_AP_DIAGMGR8_APPL_VAR) NTCFailed_Ptr_T_lgc);
# else
#  define Rte_Runnable_Ap_DiagMgr8_NxtrDiagMgr8_GetNTCFailed_Start(arg1, arg2) ((void)(0))
# endif /* Rte_Runnable_Ap_DiagMgr8_NxtrDiagMgr8_GetNTCFailed_Start */

# if defined (Rte_Runnable_Ap_DiagMgr8_NxtrDiagMgr8_GetNTCStatus_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_DiagMgr8_NxtrDiagMgr8_GetNTCStatus_Return
# endif
# if defined (Rte_Runnable_Ap_DiagMgr8_NxtrDiagMgr8_GetNTCStatus_Return)
#  undef Rte_Runnable_Ap_DiagMgr8_NxtrDiagMgr8_GetNTCStatus_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_DiagMgr8_NxtrDiagMgr8_GetNTCStatus_Return(NTCNumber NTC_Cnt_T_enum, P2VAR(UInt8, AUTOMATIC, RTE_AP_DIAGMGR8_APPL_VAR) Status_Ptr_T_u08);
# else
#  define Rte_Runnable_Ap_DiagMgr8_NxtrDiagMgr8_GetNTCStatus_Return(arg1, arg2) ((void)(0))
# endif /* Rte_Runnable_Ap_DiagMgr8_NxtrDiagMgr8_GetNTCStatus_Return */

# if defined (Rte_Runnable_Ap_DiagMgr8_NxtrDiagMgr8_GetNTCStatus_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_DiagMgr8_NxtrDiagMgr8_GetNTCStatus_Start
# endif
# if defined (Rte_Runnable_Ap_DiagMgr8_NxtrDiagMgr8_GetNTCStatus_Start)
#  undef Rte_Runnable_Ap_DiagMgr8_NxtrDiagMgr8_GetNTCStatus_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_DiagMgr8_NxtrDiagMgr8_GetNTCStatus_Start(NTCNumber NTC_Cnt_T_enum, P2VAR(UInt8, AUTOMATIC, RTE_AP_DIAGMGR8_APPL_VAR) Status_Ptr_T_u08);
# else
#  define Rte_Runnable_Ap_DiagMgr8_NxtrDiagMgr8_GetNTCStatus_Start(arg1, arg2) ((void)(0))
# endif /* Rte_Runnable_Ap_DiagMgr8_NxtrDiagMgr8_GetNTCStatus_Start */

# if defined (Rte_Runnable_Ap_DiagMgr8_NxtrDiagMgr8_SetNTCStatus_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_DiagMgr8_NxtrDiagMgr8_SetNTCStatus_Return
# endif
# if defined (Rte_Runnable_Ap_DiagMgr8_NxtrDiagMgr8_SetNTCStatus_Return)
#  undef Rte_Runnable_Ap_DiagMgr8_NxtrDiagMgr8_SetNTCStatus_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_DiagMgr8_NxtrDiagMgr8_SetNTCStatus_Return(NTCNumber NTC_Cnt_T_enum, UInt8 Param_Cnt_T_u08, NxtrDiagMgrStatus Status_Cnt_T_enum);
# else
#  define Rte_Runnable_Ap_DiagMgr8_NxtrDiagMgr8_SetNTCStatus_Return(arg1, arg2, arg3) ((void)(0))
# endif /* Rte_Runnable_Ap_DiagMgr8_NxtrDiagMgr8_SetNTCStatus_Return */

# if defined (Rte_Runnable_Ap_DiagMgr8_NxtrDiagMgr8_SetNTCStatus_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_DiagMgr8_NxtrDiagMgr8_SetNTCStatus_Start
# endif
# if defined (Rte_Runnable_Ap_DiagMgr8_NxtrDiagMgr8_SetNTCStatus_Start)
#  undef Rte_Runnable_Ap_DiagMgr8_NxtrDiagMgr8_SetNTCStatus_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_DiagMgr8_NxtrDiagMgr8_SetNTCStatus_Start(NTCNumber NTC_Cnt_T_enum, UInt8 Param_Cnt_T_u08, NxtrDiagMgrStatus Status_Cnt_T_enum);
# else
#  define Rte_Runnable_Ap_DiagMgr8_NxtrDiagMgr8_SetNTCStatus_Start(arg1, arg2, arg3) ((void)(0))
# endif /* Rte_Runnable_Ap_DiagMgr8_NxtrDiagMgr8_SetNTCStatus_Start */

# if defined (Rte_Runnable_Ap_DiagMgr9_DiagMgr9_Init_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_DiagMgr9_DiagMgr9_Init_Return
# endif
# if defined (Rte_Runnable_Ap_DiagMgr9_DiagMgr9_Init_Return)
#  undef Rte_Runnable_Ap_DiagMgr9_DiagMgr9_Init_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_DiagMgr9_DiagMgr9_Init_Return(void);
# else
#  define Rte_Runnable_Ap_DiagMgr9_DiagMgr9_Init_Return() ((void)(0))
# endif /* Rte_Runnable_Ap_DiagMgr9_DiagMgr9_Init_Return */

# if defined (Rte_Runnable_Ap_DiagMgr9_DiagMgr9_Init_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_DiagMgr9_DiagMgr9_Init_Start
# endif
# if defined (Rte_Runnable_Ap_DiagMgr9_DiagMgr9_Init_Start)
#  undef Rte_Runnable_Ap_DiagMgr9_DiagMgr9_Init_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_DiagMgr9_DiagMgr9_Init_Start(void);
# else
#  define Rte_Runnable_Ap_DiagMgr9_DiagMgr9_Init_Start() ((void)(0))
# endif /* Rte_Runnable_Ap_DiagMgr9_DiagMgr9_Init_Start */

# if defined (Rte_Runnable_Ap_DiagMgr9_DiagMgr9_Per_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_DiagMgr9_DiagMgr9_Per_Return
# endif
# if defined (Rte_Runnable_Ap_DiagMgr9_DiagMgr9_Per_Return)
#  undef Rte_Runnable_Ap_DiagMgr9_DiagMgr9_Per_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_DiagMgr9_DiagMgr9_Per_Return(void);
# else
#  define Rte_Runnable_Ap_DiagMgr9_DiagMgr9_Per_Return() ((void)(0))
# endif /* Rte_Runnable_Ap_DiagMgr9_DiagMgr9_Per_Return */

# if defined (Rte_Runnable_Ap_DiagMgr9_DiagMgr9_Per_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_DiagMgr9_DiagMgr9_Per_Start
# endif
# if defined (Rte_Runnable_Ap_DiagMgr9_DiagMgr9_Per_Start)
#  undef Rte_Runnable_Ap_DiagMgr9_DiagMgr9_Per_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_DiagMgr9_DiagMgr9_Per_Start(void);
# else
#  define Rte_Runnable_Ap_DiagMgr9_DiagMgr9_Per_Start() ((void)(0))
# endif /* Rte_Runnable_Ap_DiagMgr9_DiagMgr9_Per_Start */

# if defined (Rte_Runnable_Ap_DiagMgr9_DiagMgr9_Trns_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_DiagMgr9_DiagMgr9_Trns_Return
# endif
# if defined (Rte_Runnable_Ap_DiagMgr9_DiagMgr9_Trns_Return)
#  undef Rte_Runnable_Ap_DiagMgr9_DiagMgr9_Trns_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_DiagMgr9_DiagMgr9_Trns_Return(void);
# else
#  define Rte_Runnable_Ap_DiagMgr9_DiagMgr9_Trns_Return() ((void)(0))
# endif /* Rte_Runnable_Ap_DiagMgr9_DiagMgr9_Trns_Return */

# if defined (Rte_Runnable_Ap_DiagMgr9_DiagMgr9_Trns_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_DiagMgr9_DiagMgr9_Trns_Start
# endif
# if defined (Rte_Runnable_Ap_DiagMgr9_DiagMgr9_Trns_Start)
#  undef Rte_Runnable_Ap_DiagMgr9_DiagMgr9_Trns_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_DiagMgr9_DiagMgr9_Trns_Start(void);
# else
#  define Rte_Runnable_Ap_DiagMgr9_DiagMgr9_Trns_Start() ((void)(0))
# endif /* Rte_Runnable_Ap_DiagMgr9_DiagMgr9_Trns_Start */

# if defined (Rte_Runnable_Ap_DiagMgr9_DiagMgr_Init1_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_DiagMgr9_DiagMgr_Init1_Return
# endif
# if defined (Rte_Runnable_Ap_DiagMgr9_DiagMgr_Init1_Return)
#  undef Rte_Runnable_Ap_DiagMgr9_DiagMgr_Init1_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_DiagMgr9_DiagMgr_Init1_Return(void);
# else
#  define Rte_Runnable_Ap_DiagMgr9_DiagMgr_Init1_Return() ((void)(0))
# endif /* Rte_Runnable_Ap_DiagMgr9_DiagMgr_Init1_Return */

# if defined (Rte_Runnable_Ap_DiagMgr9_DiagMgr_Init1_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_DiagMgr9_DiagMgr_Init1_Start
# endif
# if defined (Rte_Runnable_Ap_DiagMgr9_DiagMgr_Init1_Start)
#  undef Rte_Runnable_Ap_DiagMgr9_DiagMgr_Init1_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_DiagMgr9_DiagMgr_Init1_Start(void);
# else
#  define Rte_Runnable_Ap_DiagMgr9_DiagMgr_Init1_Start() ((void)(0))
# endif /* Rte_Runnable_Ap_DiagMgr9_DiagMgr_Init1_Start */

# if defined (Rte_Runnable_Ap_DiagMgr9_DiagMgr_Per2_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_DiagMgr9_DiagMgr_Per2_Return
# endif
# if defined (Rte_Runnable_Ap_DiagMgr9_DiagMgr_Per2_Return)
#  undef Rte_Runnable_Ap_DiagMgr9_DiagMgr_Per2_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_DiagMgr9_DiagMgr_Per2_Return(void);
# else
#  define Rte_Runnable_Ap_DiagMgr9_DiagMgr_Per2_Return() ((void)(0))
# endif /* Rte_Runnable_Ap_DiagMgr9_DiagMgr_Per2_Return */

# if defined (Rte_Runnable_Ap_DiagMgr9_DiagMgr_Per2_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_DiagMgr9_DiagMgr_Per2_Start
# endif
# if defined (Rte_Runnable_Ap_DiagMgr9_DiagMgr_Per2_Start)
#  undef Rte_Runnable_Ap_DiagMgr9_DiagMgr_Per2_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_DiagMgr9_DiagMgr_Per2_Start(void);
# else
#  define Rte_Runnable_Ap_DiagMgr9_DiagMgr_Per2_Start() ((void)(0))
# endif /* Rte_Runnable_Ap_DiagMgr9_DiagMgr_Per2_Start */

# if defined (Rte_Runnable_Ap_DiagMgr9_DiagMgr_SCom_ClearBlackBox_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_DiagMgr9_DiagMgr_SCom_ClearBlackBox_Return
# endif
# if defined (Rte_Runnable_Ap_DiagMgr9_DiagMgr_SCom_ClearBlackBox_Return)
#  undef Rte_Runnable_Ap_DiagMgr9_DiagMgr_SCom_ClearBlackBox_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_DiagMgr9_DiagMgr_SCom_ClearBlackBox_Return(void);
# else
#  define Rte_Runnable_Ap_DiagMgr9_DiagMgr_SCom_ClearBlackBox_Return() ((void)(0))
# endif /* Rte_Runnable_Ap_DiagMgr9_DiagMgr_SCom_ClearBlackBox_Return */

# if defined (Rte_Runnable_Ap_DiagMgr9_DiagMgr_SCom_ClearBlackBox_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_DiagMgr9_DiagMgr_SCom_ClearBlackBox_Start
# endif
# if defined (Rte_Runnable_Ap_DiagMgr9_DiagMgr_SCom_ClearBlackBox_Start)
#  undef Rte_Runnable_Ap_DiagMgr9_DiagMgr_SCom_ClearBlackBox_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_DiagMgr9_DiagMgr_SCom_ClearBlackBox_Start(void);
# else
#  define Rte_Runnable_Ap_DiagMgr9_DiagMgr_SCom_ClearBlackBox_Start() ((void)(0))
# endif /* Rte_Runnable_Ap_DiagMgr9_DiagMgr_SCom_ClearBlackBox_Start */

# if defined (Rte_Runnable_Ap_DiagMgr9_DiagMgr_SCom_ClearLatchCounters_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_DiagMgr9_DiagMgr_SCom_ClearLatchCounters_Return
# endif
# if defined (Rte_Runnable_Ap_DiagMgr9_DiagMgr_SCom_ClearLatchCounters_Return)
#  undef Rte_Runnable_Ap_DiagMgr9_DiagMgr_SCom_ClearLatchCounters_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_DiagMgr9_DiagMgr_SCom_ClearLatchCounters_Return(void);
# else
#  define Rte_Runnable_Ap_DiagMgr9_DiagMgr_SCom_ClearLatchCounters_Return() ((void)(0))
# endif /* Rte_Runnable_Ap_DiagMgr9_DiagMgr_SCom_ClearLatchCounters_Return */

# if defined (Rte_Runnable_Ap_DiagMgr9_DiagMgr_SCom_ClearLatchCounters_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_DiagMgr9_DiagMgr_SCom_ClearLatchCounters_Start
# endif
# if defined (Rte_Runnable_Ap_DiagMgr9_DiagMgr_SCom_ClearLatchCounters_Start)
#  undef Rte_Runnable_Ap_DiagMgr9_DiagMgr_SCom_ClearLatchCounters_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_DiagMgr9_DiagMgr_SCom_ClearLatchCounters_Start(void);
# else
#  define Rte_Runnable_Ap_DiagMgr9_DiagMgr_SCom_ClearLatchCounters_Start() ((void)(0))
# endif /* Rte_Runnable_Ap_DiagMgr9_DiagMgr_SCom_ClearLatchCounters_Start */

# if defined (Rte_Runnable_Ap_DiagMgr9_DiagMgr_SCom_GetNTCInfo_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_DiagMgr9_DiagMgr_SCom_GetNTCInfo_Return
# endif
# if defined (Rte_Runnable_Ap_DiagMgr9_DiagMgr_SCom_GetNTCInfo_Return)
#  undef Rte_Runnable_Ap_DiagMgr9_DiagMgr_SCom_GetNTCInfo_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_DiagMgr9_DiagMgr_SCom_GetNTCInfo_Return(NTCNumber NTC_Cnt_T_enum, P2VAR(UInt8, AUTOMATIC, RTE_AP_DIAGMGR9_APPL_VAR) Param_Ptr_T_u08, P2VAR(UInt8, AUTOMATIC, RTE_AP_DIAGMGR9_APPL_VAR) Status_Ptr_T_u08, P2VAR(UInt8, AUTOMATIC, RTE_AP_DIAGMGR9_APPL_VAR) AgingCounter_Ptr_T_u08);
# else
#  define Rte_Runnable_Ap_DiagMgr9_DiagMgr_SCom_GetNTCInfo_Return(arg1, arg2, arg3, arg4) ((void)(0))
# endif /* Rte_Runnable_Ap_DiagMgr9_DiagMgr_SCom_GetNTCInfo_Return */

# if defined (Rte_Runnable_Ap_DiagMgr9_DiagMgr_SCom_GetNTCInfo_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_DiagMgr9_DiagMgr_SCom_GetNTCInfo_Start
# endif
# if defined (Rte_Runnable_Ap_DiagMgr9_DiagMgr_SCom_GetNTCInfo_Start)
#  undef Rte_Runnable_Ap_DiagMgr9_DiagMgr_SCom_GetNTCInfo_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_DiagMgr9_DiagMgr_SCom_GetNTCInfo_Start(NTCNumber NTC_Cnt_T_enum, P2VAR(UInt8, AUTOMATIC, RTE_AP_DIAGMGR9_APPL_VAR) Param_Ptr_T_u08, P2VAR(UInt8, AUTOMATIC, RTE_AP_DIAGMGR9_APPL_VAR) Status_Ptr_T_u08, P2VAR(UInt8, AUTOMATIC, RTE_AP_DIAGMGR9_APPL_VAR) AgingCounter_Ptr_T_u08);
# else
#  define Rte_Runnable_Ap_DiagMgr9_DiagMgr_SCom_GetNTCInfo_Start(arg1, arg2, arg3, arg4) ((void)(0))
# endif /* Rte_Runnable_Ap_DiagMgr9_DiagMgr_SCom_GetNTCInfo_Start */

# if defined (Rte_Runnable_Ap_DiagMgr9_DiagMgr_SCom_ReadStrgArray_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_DiagMgr9_DiagMgr_SCom_ReadStrgArray_Return
# endif
# if defined (Rte_Runnable_Ap_DiagMgr9_DiagMgr_SCom_ReadStrgArray_Return)
#  undef Rte_Runnable_Ap_DiagMgr9_DiagMgr_SCom_ReadStrgArray_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_DiagMgr9_DiagMgr_SCom_ReadStrgArray_Return(void);
# else
#  define Rte_Runnable_Ap_DiagMgr9_DiagMgr_SCom_ReadStrgArray_Return() ((void)(0))
# endif /* Rte_Runnable_Ap_DiagMgr9_DiagMgr_SCom_ReadStrgArray_Return */

# if defined (Rte_Runnable_Ap_DiagMgr9_DiagMgr_SCom_ReadStrgArray_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_DiagMgr9_DiagMgr_SCom_ReadStrgArray_Start
# endif
# if defined (Rte_Runnable_Ap_DiagMgr9_DiagMgr_SCom_ReadStrgArray_Start)
#  undef Rte_Runnable_Ap_DiagMgr9_DiagMgr_SCom_ReadStrgArray_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_DiagMgr9_DiagMgr_SCom_ReadStrgArray_Start(void);
# else
#  define Rte_Runnable_Ap_DiagMgr9_DiagMgr_SCom_ReadStrgArray_Start() ((void)(0))
# endif /* Rte_Runnable_Ap_DiagMgr9_DiagMgr_SCom_ReadStrgArray_Start */

# if defined (Rte_Runnable_Ap_DiagMgr9_DiagMgr_SCom_ResetNTCStatus_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_DiagMgr9_DiagMgr_SCom_ResetNTCStatus_Return
# endif
# if defined (Rte_Runnable_Ap_DiagMgr9_DiagMgr_SCom_ResetNTCStatus_Return)
#  undef Rte_Runnable_Ap_DiagMgr9_DiagMgr_SCom_ResetNTCStatus_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_DiagMgr9_DiagMgr_SCom_ResetNTCStatus_Return(void);
# else
#  define Rte_Runnable_Ap_DiagMgr9_DiagMgr_SCom_ResetNTCStatus_Return() ((void)(0))
# endif /* Rte_Runnable_Ap_DiagMgr9_DiagMgr_SCom_ResetNTCStatus_Return */

# if defined (Rte_Runnable_Ap_DiagMgr9_DiagMgr_SCom_ResetNTCStatus_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_DiagMgr9_DiagMgr_SCom_ResetNTCStatus_Start
# endif
# if defined (Rte_Runnable_Ap_DiagMgr9_DiagMgr_SCom_ResetNTCStatus_Start)
#  undef Rte_Runnable_Ap_DiagMgr9_DiagMgr_SCom_ResetNTCStatus_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_DiagMgr9_DiagMgr_SCom_ResetNTCStatus_Start(void);
# else
#  define Rte_Runnable_Ap_DiagMgr9_DiagMgr_SCom_ResetNTCStatus_Start() ((void)(0))
# endif /* Rte_Runnable_Ap_DiagMgr9_DiagMgr_SCom_ResetNTCStatus_Start */

# if defined (Rte_Runnable_Ap_DiagMgr9_DiagMgr_StaCtrl_Shutdown_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_DiagMgr9_DiagMgr_StaCtrl_Shutdown_Return
# endif
# if defined (Rte_Runnable_Ap_DiagMgr9_DiagMgr_StaCtrl_Shutdown_Return)
#  undef Rte_Runnable_Ap_DiagMgr9_DiagMgr_StaCtrl_Shutdown_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_DiagMgr9_DiagMgr_StaCtrl_Shutdown_Return(void);
# else
#  define Rte_Runnable_Ap_DiagMgr9_DiagMgr_StaCtrl_Shutdown_Return() ((void)(0))
# endif /* Rte_Runnable_Ap_DiagMgr9_DiagMgr_StaCtrl_Shutdown_Return */

# if defined (Rte_Runnable_Ap_DiagMgr9_DiagMgr_StaCtrl_Shutdown_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_DiagMgr9_DiagMgr_StaCtrl_Shutdown_Start
# endif
# if defined (Rte_Runnable_Ap_DiagMgr9_DiagMgr_StaCtrl_Shutdown_Start)
#  undef Rte_Runnable_Ap_DiagMgr9_DiagMgr_StaCtrl_Shutdown_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_DiagMgr9_DiagMgr_StaCtrl_Shutdown_Start(void);
# else
#  define Rte_Runnable_Ap_DiagMgr9_DiagMgr_StaCtrl_Shutdown_Start() ((void)(0))
# endif /* Rte_Runnable_Ap_DiagMgr9_DiagMgr_StaCtrl_Shutdown_Start */

# if defined (Rte_Runnable_Ap_DiagMgr9_DiagMgr_Trns1_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_DiagMgr9_DiagMgr_Trns1_Return
# endif
# if defined (Rte_Runnable_Ap_DiagMgr9_DiagMgr_Trns1_Return)
#  undef Rte_Runnable_Ap_DiagMgr9_DiagMgr_Trns1_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_DiagMgr9_DiagMgr_Trns1_Return(void);
# else
#  define Rte_Runnable_Ap_DiagMgr9_DiagMgr_Trns1_Return() ((void)(0))
# endif /* Rte_Runnable_Ap_DiagMgr9_DiagMgr_Trns1_Return */

# if defined (Rte_Runnable_Ap_DiagMgr9_DiagMgr_Trns1_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_DiagMgr9_DiagMgr_Trns1_Start
# endif
# if defined (Rte_Runnable_Ap_DiagMgr9_DiagMgr_Trns1_Start)
#  undef Rte_Runnable_Ap_DiagMgr9_DiagMgr_Trns1_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_DiagMgr9_DiagMgr_Trns1_Start(void);
# else
#  define Rte_Runnable_Ap_DiagMgr9_DiagMgr_Trns1_Start() ((void)(0))
# endif /* Rte_Runnable_Ap_DiagMgr9_DiagMgr_Trns1_Start */

# if defined (Rte_Runnable_Ap_DiagMgr9_NxtrDiagMgr9_GetNTCActive_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_DiagMgr9_NxtrDiagMgr9_GetNTCActive_Return
# endif
# if defined (Rte_Runnable_Ap_DiagMgr9_NxtrDiagMgr9_GetNTCActive_Return)
#  undef Rte_Runnable_Ap_DiagMgr9_NxtrDiagMgr9_GetNTCActive_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_DiagMgr9_NxtrDiagMgr9_GetNTCActive_Return(NTCNumber NTC_Cnt_T_enum, P2VAR(Boolean, AUTOMATIC, RTE_AP_DIAGMGR9_APPL_VAR) NTCActive_Ptr_T_lgc);
# else
#  define Rte_Runnable_Ap_DiagMgr9_NxtrDiagMgr9_GetNTCActive_Return(arg1, arg2) ((void)(0))
# endif /* Rte_Runnable_Ap_DiagMgr9_NxtrDiagMgr9_GetNTCActive_Return */

# if defined (Rte_Runnable_Ap_DiagMgr9_NxtrDiagMgr9_GetNTCActive_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_DiagMgr9_NxtrDiagMgr9_GetNTCActive_Start
# endif
# if defined (Rte_Runnable_Ap_DiagMgr9_NxtrDiagMgr9_GetNTCActive_Start)
#  undef Rte_Runnable_Ap_DiagMgr9_NxtrDiagMgr9_GetNTCActive_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_DiagMgr9_NxtrDiagMgr9_GetNTCActive_Start(NTCNumber NTC_Cnt_T_enum, P2VAR(Boolean, AUTOMATIC, RTE_AP_DIAGMGR9_APPL_VAR) NTCActive_Ptr_T_lgc);
# else
#  define Rte_Runnable_Ap_DiagMgr9_NxtrDiagMgr9_GetNTCActive_Start(arg1, arg2) ((void)(0))
# endif /* Rte_Runnable_Ap_DiagMgr9_NxtrDiagMgr9_GetNTCActive_Start */

# if defined (Rte_Runnable_Ap_DiagMgr9_NxtrDiagMgr9_GetNTCFailed_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_DiagMgr9_NxtrDiagMgr9_GetNTCFailed_Return
# endif
# if defined (Rte_Runnable_Ap_DiagMgr9_NxtrDiagMgr9_GetNTCFailed_Return)
#  undef Rte_Runnable_Ap_DiagMgr9_NxtrDiagMgr9_GetNTCFailed_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_DiagMgr9_NxtrDiagMgr9_GetNTCFailed_Return(NTCNumber NTC_Cnt_T_enum, P2VAR(Boolean, AUTOMATIC, RTE_AP_DIAGMGR9_APPL_VAR) NTCFailed_Ptr_T_lgc);
# else
#  define Rte_Runnable_Ap_DiagMgr9_NxtrDiagMgr9_GetNTCFailed_Return(arg1, arg2) ((void)(0))
# endif /* Rte_Runnable_Ap_DiagMgr9_NxtrDiagMgr9_GetNTCFailed_Return */

# if defined (Rte_Runnable_Ap_DiagMgr9_NxtrDiagMgr9_GetNTCFailed_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_DiagMgr9_NxtrDiagMgr9_GetNTCFailed_Start
# endif
# if defined (Rte_Runnable_Ap_DiagMgr9_NxtrDiagMgr9_GetNTCFailed_Start)
#  undef Rte_Runnable_Ap_DiagMgr9_NxtrDiagMgr9_GetNTCFailed_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_DiagMgr9_NxtrDiagMgr9_GetNTCFailed_Start(NTCNumber NTC_Cnt_T_enum, P2VAR(Boolean, AUTOMATIC, RTE_AP_DIAGMGR9_APPL_VAR) NTCFailed_Ptr_T_lgc);
# else
#  define Rte_Runnable_Ap_DiagMgr9_NxtrDiagMgr9_GetNTCFailed_Start(arg1, arg2) ((void)(0))
# endif /* Rte_Runnable_Ap_DiagMgr9_NxtrDiagMgr9_GetNTCFailed_Start */

# if defined (Rte_Runnable_Ap_DiagMgr9_NxtrDiagMgr9_GetNTCStatus_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_DiagMgr9_NxtrDiagMgr9_GetNTCStatus_Return
# endif
# if defined (Rte_Runnable_Ap_DiagMgr9_NxtrDiagMgr9_GetNTCStatus_Return)
#  undef Rte_Runnable_Ap_DiagMgr9_NxtrDiagMgr9_GetNTCStatus_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_DiagMgr9_NxtrDiagMgr9_GetNTCStatus_Return(NTCNumber NTC_Cnt_T_enum, P2VAR(UInt8, AUTOMATIC, RTE_AP_DIAGMGR9_APPL_VAR) Status_Ptr_T_u08);
# else
#  define Rte_Runnable_Ap_DiagMgr9_NxtrDiagMgr9_GetNTCStatus_Return(arg1, arg2) ((void)(0))
# endif /* Rte_Runnable_Ap_DiagMgr9_NxtrDiagMgr9_GetNTCStatus_Return */

# if defined (Rte_Runnable_Ap_DiagMgr9_NxtrDiagMgr9_GetNTCStatus_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_DiagMgr9_NxtrDiagMgr9_GetNTCStatus_Start
# endif
# if defined (Rte_Runnable_Ap_DiagMgr9_NxtrDiagMgr9_GetNTCStatus_Start)
#  undef Rte_Runnable_Ap_DiagMgr9_NxtrDiagMgr9_GetNTCStatus_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_DiagMgr9_NxtrDiagMgr9_GetNTCStatus_Start(NTCNumber NTC_Cnt_T_enum, P2VAR(UInt8, AUTOMATIC, RTE_AP_DIAGMGR9_APPL_VAR) Status_Ptr_T_u08);
# else
#  define Rte_Runnable_Ap_DiagMgr9_NxtrDiagMgr9_GetNTCStatus_Start(arg1, arg2) ((void)(0))
# endif /* Rte_Runnable_Ap_DiagMgr9_NxtrDiagMgr9_GetNTCStatus_Start */

# if defined (Rte_Runnable_Ap_DiagMgr9_NxtrDiagMgr9_SetNTCStatus_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_DiagMgr9_NxtrDiagMgr9_SetNTCStatus_Return
# endif
# if defined (Rte_Runnable_Ap_DiagMgr9_NxtrDiagMgr9_SetNTCStatus_Return)
#  undef Rte_Runnable_Ap_DiagMgr9_NxtrDiagMgr9_SetNTCStatus_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_DiagMgr9_NxtrDiagMgr9_SetNTCStatus_Return(NTCNumber NTC_Cnt_T_enum, UInt8 Param_Cnt_T_u08, NxtrDiagMgrStatus Status_Cnt_T_enum);
# else
#  define Rte_Runnable_Ap_DiagMgr9_NxtrDiagMgr9_SetNTCStatus_Return(arg1, arg2, arg3) ((void)(0))
# endif /* Rte_Runnable_Ap_DiagMgr9_NxtrDiagMgr9_SetNTCStatus_Return */

# if defined (Rte_Runnable_Ap_DiagMgr9_NxtrDiagMgr9_SetNTCStatus_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_DiagMgr9_NxtrDiagMgr9_SetNTCStatus_Start
# endif
# if defined (Rte_Runnable_Ap_DiagMgr9_NxtrDiagMgr9_SetNTCStatus_Start)
#  undef Rte_Runnable_Ap_DiagMgr9_NxtrDiagMgr9_SetNTCStatus_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_DiagMgr9_NxtrDiagMgr9_SetNTCStatus_Start(NTCNumber NTC_Cnt_T_enum, UInt8 Param_Cnt_T_u08, NxtrDiagMgrStatus Status_Cnt_T_enum);
# else
#  define Rte_Runnable_Ap_DiagMgr9_NxtrDiagMgr9_SetNTCStatus_Start(arg1, arg2, arg3) ((void)(0))
# endif /* Rte_Runnable_Ap_DiagMgr9_NxtrDiagMgr9_SetNTCStatus_Start */

# if defined (Rte_Runnable_Ap_DigPhsReasDiag_DigPhsReasDiag_Init_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_DigPhsReasDiag_DigPhsReasDiag_Init_Return
# endif
# if defined (Rte_Runnable_Ap_DigPhsReasDiag_DigPhsReasDiag_Init_Return)
#  undef Rte_Runnable_Ap_DigPhsReasDiag_DigPhsReasDiag_Init_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_DigPhsReasDiag_DigPhsReasDiag_Init_Return(void);
# else
#  define Rte_Runnable_Ap_DigPhsReasDiag_DigPhsReasDiag_Init_Return() ((void)(0))
# endif /* Rte_Runnable_Ap_DigPhsReasDiag_DigPhsReasDiag_Init_Return */

# if defined (Rte_Runnable_Ap_DigPhsReasDiag_DigPhsReasDiag_Init_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_DigPhsReasDiag_DigPhsReasDiag_Init_Start
# endif
# if defined (Rte_Runnable_Ap_DigPhsReasDiag_DigPhsReasDiag_Init_Start)
#  undef Rte_Runnable_Ap_DigPhsReasDiag_DigPhsReasDiag_Init_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_DigPhsReasDiag_DigPhsReasDiag_Init_Start(void);
# else
#  define Rte_Runnable_Ap_DigPhsReasDiag_DigPhsReasDiag_Init_Start() ((void)(0))
# endif /* Rte_Runnable_Ap_DigPhsReasDiag_DigPhsReasDiag_Init_Start */

# if defined (Rte_Runnable_Ap_DigPhsReasDiag_DigPhsReasDiag_Per1_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_DigPhsReasDiag_DigPhsReasDiag_Per1_Return
# endif
# if defined (Rte_Runnable_Ap_DigPhsReasDiag_DigPhsReasDiag_Per1_Return)
#  undef Rte_Runnable_Ap_DigPhsReasDiag_DigPhsReasDiag_Per1_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_DigPhsReasDiag_DigPhsReasDiag_Per1_Return(void);
# else
#  define Rte_Runnable_Ap_DigPhsReasDiag_DigPhsReasDiag_Per1_Return() ((void)(0))
# endif /* Rte_Runnable_Ap_DigPhsReasDiag_DigPhsReasDiag_Per1_Return */

# if defined (Rte_Runnable_Ap_DigPhsReasDiag_DigPhsReasDiag_Per1_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_DigPhsReasDiag_DigPhsReasDiag_Per1_Start
# endif
# if defined (Rte_Runnable_Ap_DigPhsReasDiag_DigPhsReasDiag_Per1_Start)
#  undef Rte_Runnable_Ap_DigPhsReasDiag_DigPhsReasDiag_Per1_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_DigPhsReasDiag_DigPhsReasDiag_Per1_Start(void);
# else
#  define Rte_Runnable_Ap_DigPhsReasDiag_DigPhsReasDiag_Per1_Start() ((void)(0))
# endif /* Rte_Runnable_Ap_DigPhsReasDiag_DigPhsReasDiag_Per1_Start */

# if defined (Rte_Runnable_Ap_DigPhsReasDiag_DigPhsReasDiag_Trans1_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_DigPhsReasDiag_DigPhsReasDiag_Trans1_Return
# endif
# if defined (Rte_Runnable_Ap_DigPhsReasDiag_DigPhsReasDiag_Trans1_Return)
#  undef Rte_Runnable_Ap_DigPhsReasDiag_DigPhsReasDiag_Trans1_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_DigPhsReasDiag_DigPhsReasDiag_Trans1_Return(void);
# else
#  define Rte_Runnable_Ap_DigPhsReasDiag_DigPhsReasDiag_Trans1_Return() ((void)(0))
# endif /* Rte_Runnable_Ap_DigPhsReasDiag_DigPhsReasDiag_Trans1_Return */

# if defined (Rte_Runnable_Ap_DigPhsReasDiag_DigPhsReasDiag_Trans1_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_DigPhsReasDiag_DigPhsReasDiag_Trans1_Start
# endif
# if defined (Rte_Runnable_Ap_DigPhsReasDiag_DigPhsReasDiag_Trans1_Start)
#  undef Rte_Runnable_Ap_DigPhsReasDiag_DigPhsReasDiag_Trans1_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_DigPhsReasDiag_DigPhsReasDiag_Trans1_Start(void);
# else
#  define Rte_Runnable_Ap_DigPhsReasDiag_DigPhsReasDiag_Trans1_Start() ((void)(0))
# endif /* Rte_Runnable_Ap_DigPhsReasDiag_DigPhsReasDiag_Trans1_Start */

# if defined (Rte_Runnable_Ap_EOTActuatorMng_EOTActuatorMng_Per1_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_EOTActuatorMng_EOTActuatorMng_Per1_Return
# endif
# if defined (Rte_Runnable_Ap_EOTActuatorMng_EOTActuatorMng_Per1_Return)
#  undef Rte_Runnable_Ap_EOTActuatorMng_EOTActuatorMng_Per1_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_EOTActuatorMng_EOTActuatorMng_Per1_Return(void);
# else
#  define Rte_Runnable_Ap_EOTActuatorMng_EOTActuatorMng_Per1_Return() ((void)(0))
# endif /* Rte_Runnable_Ap_EOTActuatorMng_EOTActuatorMng_Per1_Return */

# if defined (Rte_Runnable_Ap_EOTActuatorMng_EOTActuatorMng_Per1_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_EOTActuatorMng_EOTActuatorMng_Per1_Start
# endif
# if defined (Rte_Runnable_Ap_EOTActuatorMng_EOTActuatorMng_Per1_Start)
#  undef Rte_Runnable_Ap_EOTActuatorMng_EOTActuatorMng_Per1_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_EOTActuatorMng_EOTActuatorMng_Per1_Start(void);
# else
#  define Rte_Runnable_Ap_EOTActuatorMng_EOTActuatorMng_Per1_Start() ((void)(0))
# endif /* Rte_Runnable_Ap_EOTActuatorMng_EOTActuatorMng_Per1_Start */

# if defined (Rte_Runnable_Ap_ElePwr_ElePwr_Per1_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_ElePwr_ElePwr_Per1_Return
# endif
# if defined (Rte_Runnable_Ap_ElePwr_ElePwr_Per1_Return)
#  undef Rte_Runnable_Ap_ElePwr_ElePwr_Per1_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_ElePwr_ElePwr_Per1_Return(void);
# else
#  define Rte_Runnable_Ap_ElePwr_ElePwr_Per1_Return() ((void)(0))
# endif /* Rte_Runnable_Ap_ElePwr_ElePwr_Per1_Return */

# if defined (Rte_Runnable_Ap_ElePwr_ElePwr_Per1_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_ElePwr_ElePwr_Per1_Start
# endif
# if defined (Rte_Runnable_Ap_ElePwr_ElePwr_Per1_Start)
#  undef Rte_Runnable_Ap_ElePwr_ElePwr_Per1_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_ElePwr_ElePwr_Per1_Start(void);
# else
#  define Rte_Runnable_Ap_ElePwr_ElePwr_Per1_Start() ((void)(0))
# endif /* Rte_Runnable_Ap_ElePwr_ElePwr_Per1_Start */

# if defined (Rte_Runnable_Ap_FrqDepDmpnInrtCmp_FrqDepDmpnInrtCmp_Init_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_FrqDepDmpnInrtCmp_FrqDepDmpnInrtCmp_Init_Return
# endif
# if defined (Rte_Runnable_Ap_FrqDepDmpnInrtCmp_FrqDepDmpnInrtCmp_Init_Return)
#  undef Rte_Runnable_Ap_FrqDepDmpnInrtCmp_FrqDepDmpnInrtCmp_Init_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_FrqDepDmpnInrtCmp_FrqDepDmpnInrtCmp_Init_Return(void);
# else
#  define Rte_Runnable_Ap_FrqDepDmpnInrtCmp_FrqDepDmpnInrtCmp_Init_Return() ((void)(0))
# endif /* Rte_Runnable_Ap_FrqDepDmpnInrtCmp_FrqDepDmpnInrtCmp_Init_Return */

# if defined (Rte_Runnable_Ap_FrqDepDmpnInrtCmp_FrqDepDmpnInrtCmp_Init_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_FrqDepDmpnInrtCmp_FrqDepDmpnInrtCmp_Init_Start
# endif
# if defined (Rte_Runnable_Ap_FrqDepDmpnInrtCmp_FrqDepDmpnInrtCmp_Init_Start)
#  undef Rte_Runnable_Ap_FrqDepDmpnInrtCmp_FrqDepDmpnInrtCmp_Init_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_FrqDepDmpnInrtCmp_FrqDepDmpnInrtCmp_Init_Start(void);
# else
#  define Rte_Runnable_Ap_FrqDepDmpnInrtCmp_FrqDepDmpnInrtCmp_Init_Start() ((void)(0))
# endif /* Rte_Runnable_Ap_FrqDepDmpnInrtCmp_FrqDepDmpnInrtCmp_Init_Start */

# if defined (Rte_Runnable_Ap_FrqDepDmpnInrtCmp_FrqDepDmpnInrtCmp_Per1_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_FrqDepDmpnInrtCmp_FrqDepDmpnInrtCmp_Per1_Return
# endif
# if defined (Rte_Runnable_Ap_FrqDepDmpnInrtCmp_FrqDepDmpnInrtCmp_Per1_Return)
#  undef Rte_Runnable_Ap_FrqDepDmpnInrtCmp_FrqDepDmpnInrtCmp_Per1_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_FrqDepDmpnInrtCmp_FrqDepDmpnInrtCmp_Per1_Return(void);
# else
#  define Rte_Runnable_Ap_FrqDepDmpnInrtCmp_FrqDepDmpnInrtCmp_Per1_Return() ((void)(0))
# endif /* Rte_Runnable_Ap_FrqDepDmpnInrtCmp_FrqDepDmpnInrtCmp_Per1_Return */

# if defined (Rte_Runnable_Ap_FrqDepDmpnInrtCmp_FrqDepDmpnInrtCmp_Per1_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_FrqDepDmpnInrtCmp_FrqDepDmpnInrtCmp_Per1_Start
# endif
# if defined (Rte_Runnable_Ap_FrqDepDmpnInrtCmp_FrqDepDmpnInrtCmp_Per1_Start)
#  undef Rte_Runnable_Ap_FrqDepDmpnInrtCmp_FrqDepDmpnInrtCmp_Per1_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_FrqDepDmpnInrtCmp_FrqDepDmpnInrtCmp_Per1_Start(void);
# else
#  define Rte_Runnable_Ap_FrqDepDmpnInrtCmp_FrqDepDmpnInrtCmp_Per1_Start() ((void)(0))
# endif /* Rte_Runnable_Ap_FrqDepDmpnInrtCmp_FrqDepDmpnInrtCmp_Per1_Start */

# if defined (Rte_Runnable_Ap_Gsod_Gsod_Per1_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_Gsod_Gsod_Per1_Return
# endif
# if defined (Rte_Runnable_Ap_Gsod_Gsod_Per1_Return)
#  undef Rte_Runnable_Ap_Gsod_Gsod_Per1_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_Gsod_Gsod_Per1_Return(void);
# else
#  define Rte_Runnable_Ap_Gsod_Gsod_Per1_Return() ((void)(0))
# endif /* Rte_Runnable_Ap_Gsod_Gsod_Per1_Return */

# if defined (Rte_Runnable_Ap_Gsod_Gsod_Per1_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_Gsod_Gsod_Per1_Start
# endif
# if defined (Rte_Runnable_Ap_Gsod_Gsod_Per1_Start)
#  undef Rte_Runnable_Ap_Gsod_Gsod_Per1_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_Gsod_Gsod_Per1_Start(void);
# else
#  define Rte_Runnable_Ap_Gsod_Gsod_Per1_Start() ((void)(0))
# endif /* Rte_Runnable_Ap_Gsod_Gsod_Per1_Start */

# if defined (Rte_Runnable_Ap_HaLFTO_HaLFTO_Init1_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_HaLFTO_HaLFTO_Init1_Return
# endif
# if defined (Rte_Runnable_Ap_HaLFTO_HaLFTO_Init1_Return)
#  undef Rte_Runnable_Ap_HaLFTO_HaLFTO_Init1_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_HaLFTO_HaLFTO_Init1_Return(void);
# else
#  define Rte_Runnable_Ap_HaLFTO_HaLFTO_Init1_Return() ((void)(0))
# endif /* Rte_Runnable_Ap_HaLFTO_HaLFTO_Init1_Return */

# if defined (Rte_Runnable_Ap_HaLFTO_HaLFTO_Init1_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_HaLFTO_HaLFTO_Init1_Start
# endif
# if defined (Rte_Runnable_Ap_HaLFTO_HaLFTO_Init1_Start)
#  undef Rte_Runnable_Ap_HaLFTO_HaLFTO_Init1_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_HaLFTO_HaLFTO_Init1_Start(void);
# else
#  define Rte_Runnable_Ap_HaLFTO_HaLFTO_Init1_Start() ((void)(0))
# endif /* Rte_Runnable_Ap_HaLFTO_HaLFTO_Init1_Start */

# if defined (Rte_Runnable_Ap_HaLFTO_HaLFTO_Per1_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_HaLFTO_HaLFTO_Per1_Return
# endif
# if defined (Rte_Runnable_Ap_HaLFTO_HaLFTO_Per1_Return)
#  undef Rte_Runnable_Ap_HaLFTO_HaLFTO_Per1_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_HaLFTO_HaLFTO_Per1_Return(void);
# else
#  define Rte_Runnable_Ap_HaLFTO_HaLFTO_Per1_Return() ((void)(0))
# endif /* Rte_Runnable_Ap_HaLFTO_HaLFTO_Per1_Return */

# if defined (Rte_Runnable_Ap_HaLFTO_HaLFTO_Per1_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_HaLFTO_HaLFTO_Per1_Start
# endif
# if defined (Rte_Runnable_Ap_HaLFTO_HaLFTO_Per1_Start)
#  undef Rte_Runnable_Ap_HaLFTO_HaLFTO_Per1_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_HaLFTO_HaLFTO_Per1_Start(void);
# else
#  define Rte_Runnable_Ap_HaLFTO_HaLFTO_Per1_Start() ((void)(0))
# endif /* Rte_Runnable_Ap_HaLFTO_HaLFTO_Per1_Start */

# if defined (Rte_Runnable_Ap_HiLoadStall_HiLoadStall_Per1_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_HiLoadStall_HiLoadStall_Per1_Return
# endif
# if defined (Rte_Runnable_Ap_HiLoadStall_HiLoadStall_Per1_Return)
#  undef Rte_Runnable_Ap_HiLoadStall_HiLoadStall_Per1_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_HiLoadStall_HiLoadStall_Per1_Return(void);
# else
#  define Rte_Runnable_Ap_HiLoadStall_HiLoadStall_Per1_Return() ((void)(0))
# endif /* Rte_Runnable_Ap_HiLoadStall_HiLoadStall_Per1_Return */

# if defined (Rte_Runnable_Ap_HiLoadStall_HiLoadStall_Per1_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_HiLoadStall_HiLoadStall_Per1_Start
# endif
# if defined (Rte_Runnable_Ap_HiLoadStall_HiLoadStall_Per1_Start)
#  undef Rte_Runnable_Ap_HiLoadStall_HiLoadStall_Per1_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_HiLoadStall_HiLoadStall_Per1_Start(void);
# else
#  define Rte_Runnable_Ap_HiLoadStall_HiLoadStall_Per1_Start() ((void)(0))
# endif /* Rte_Runnable_Ap_HiLoadStall_HiLoadStall_Per1_Start */

# if defined (Rte_Runnable_Ap_HighFreqAssist_HighFreqAssist_Per1_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_HighFreqAssist_HighFreqAssist_Per1_Return
# endif
# if defined (Rte_Runnable_Ap_HighFreqAssist_HighFreqAssist_Per1_Return)
#  undef Rte_Runnable_Ap_HighFreqAssist_HighFreqAssist_Per1_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_HighFreqAssist_HighFreqAssist_Per1_Return(void);
# else
#  define Rte_Runnable_Ap_HighFreqAssist_HighFreqAssist_Per1_Return() ((void)(0))
# endif /* Rte_Runnable_Ap_HighFreqAssist_HighFreqAssist_Per1_Return */

# if defined (Rte_Runnable_Ap_HighFreqAssist_HighFreqAssist_Per1_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_HighFreqAssist_HighFreqAssist_Per1_Start
# endif
# if defined (Rte_Runnable_Ap_HighFreqAssist_HighFreqAssist_Per1_Start)
#  undef Rte_Runnable_Ap_HighFreqAssist_HighFreqAssist_Per1_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_HighFreqAssist_HighFreqAssist_Per1_Start(void);
# else
#  define Rte_Runnable_Ap_HighFreqAssist_HighFreqAssist_Per1_Start() ((void)(0))
# endif /* Rte_Runnable_Ap_HighFreqAssist_HighFreqAssist_Per1_Start */

# if defined (Rte_Runnable_Ap_HwPwUp_HwPwUp_Per1_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_HwPwUp_HwPwUp_Per1_Return
# endif
# if defined (Rte_Runnable_Ap_HwPwUp_HwPwUp_Per1_Return)
#  undef Rte_Runnable_Ap_HwPwUp_HwPwUp_Per1_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_HwPwUp_HwPwUp_Per1_Return(void);
# else
#  define Rte_Runnable_Ap_HwPwUp_HwPwUp_Per1_Return() ((void)(0))
# endif /* Rte_Runnable_Ap_HwPwUp_HwPwUp_Per1_Return */

# if defined (Rte_Runnable_Ap_HwPwUp_HwPwUp_Per1_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_HwPwUp_HwPwUp_Per1_Start
# endif
# if defined (Rte_Runnable_Ap_HwPwUp_HwPwUp_Per1_Start)
#  undef Rte_Runnable_Ap_HwPwUp_HwPwUp_Per1_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_HwPwUp_HwPwUp_Per1_Start(void);
# else
#  define Rte_Runnable_Ap_HwPwUp_HwPwUp_Per1_Start() ((void)(0))
# endif /* Rte_Runnable_Ap_HwPwUp_HwPwUp_Per1_Start */

# if defined (Rte_Runnable_Ap_HwPwUp_HwPwUp_Trns1_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_HwPwUp_HwPwUp_Trns1_Return
# endif
# if defined (Rte_Runnable_Ap_HwPwUp_HwPwUp_Trns1_Return)
#  undef Rte_Runnable_Ap_HwPwUp_HwPwUp_Trns1_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_HwPwUp_HwPwUp_Trns1_Return(void);
# else
#  define Rte_Runnable_Ap_HwPwUp_HwPwUp_Trns1_Return() ((void)(0))
# endif /* Rte_Runnable_Ap_HwPwUp_HwPwUp_Trns1_Return */

# if defined (Rte_Runnable_Ap_HwPwUp_HwPwUp_Trns1_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_HwPwUp_HwPwUp_Trns1_Start
# endif
# if defined (Rte_Runnable_Ap_HwPwUp_HwPwUp_Trns1_Start)
#  undef Rte_Runnable_Ap_HwPwUp_HwPwUp_Trns1_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_HwPwUp_HwPwUp_Trns1_Start(void);
# else
#  define Rte_Runnable_Ap_HwPwUp_HwPwUp_Trns1_Start() ((void)(0))
# endif /* Rte_Runnable_Ap_HwPwUp_HwPwUp_Trns1_Start */

# if defined (Rte_Runnable_Ap_HwPwUp_HwPwUp_Trns2_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_HwPwUp_HwPwUp_Trns2_Return
# endif
# if defined (Rte_Runnable_Ap_HwPwUp_HwPwUp_Trns2_Return)
#  undef Rte_Runnable_Ap_HwPwUp_HwPwUp_Trns2_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_HwPwUp_HwPwUp_Trns2_Return(void);
# else
#  define Rte_Runnable_Ap_HwPwUp_HwPwUp_Trns2_Return() ((void)(0))
# endif /* Rte_Runnable_Ap_HwPwUp_HwPwUp_Trns2_Return */

# if defined (Rte_Runnable_Ap_HwPwUp_HwPwUp_Trns2_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_HwPwUp_HwPwUp_Trns2_Start
# endif
# if defined (Rte_Runnable_Ap_HwPwUp_HwPwUp_Trns2_Start)
#  undef Rte_Runnable_Ap_HwPwUp_HwPwUp_Trns2_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_HwPwUp_HwPwUp_Trns2_Start(void);
# else
#  define Rte_Runnable_Ap_HwPwUp_HwPwUp_Trns2_Start() ((void)(0))
# endif /* Rte_Runnable_Ap_HwPwUp_HwPwUp_Trns2_Start */

# if defined (Rte_Runnable_Ap_HystComp_HystComp_Init1_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_HystComp_HystComp_Init1_Return
# endif
# if defined (Rte_Runnable_Ap_HystComp_HystComp_Init1_Return)
#  undef Rte_Runnable_Ap_HystComp_HystComp_Init1_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_HystComp_HystComp_Init1_Return(void);
# else
#  define Rte_Runnable_Ap_HystComp_HystComp_Init1_Return() ((void)(0))
# endif /* Rte_Runnable_Ap_HystComp_HystComp_Init1_Return */

# if defined (Rte_Runnable_Ap_HystComp_HystComp_Init1_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_HystComp_HystComp_Init1_Start
# endif
# if defined (Rte_Runnable_Ap_HystComp_HystComp_Init1_Start)
#  undef Rte_Runnable_Ap_HystComp_HystComp_Init1_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_HystComp_HystComp_Init1_Start(void);
# else
#  define Rte_Runnable_Ap_HystComp_HystComp_Init1_Start() ((void)(0))
# endif /* Rte_Runnable_Ap_HystComp_HystComp_Init1_Start */

# if defined (Rte_Runnable_Ap_HystComp_HystComp_Per1_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_HystComp_HystComp_Per1_Return
# endif
# if defined (Rte_Runnable_Ap_HystComp_HystComp_Per1_Return)
#  undef Rte_Runnable_Ap_HystComp_HystComp_Per1_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_HystComp_HystComp_Per1_Return(void);
# else
#  define Rte_Runnable_Ap_HystComp_HystComp_Per1_Return() ((void)(0))
# endif /* Rte_Runnable_Ap_HystComp_HystComp_Per1_Return */

# if defined (Rte_Runnable_Ap_HystComp_HystComp_Per1_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_HystComp_HystComp_Per1_Start
# endif
# if defined (Rte_Runnable_Ap_HystComp_HystComp_Per1_Start)
#  undef Rte_Runnable_Ap_HystComp_HystComp_Per1_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_HystComp_HystComp_Per1_Start(void);
# else
#  define Rte_Runnable_Ap_HystComp_HystComp_Per1_Start() ((void)(0))
# endif /* Rte_Runnable_Ap_HystComp_HystComp_Per1_Start */

# if defined (Rte_Runnable_Ap_LmtCod_LmtCod_Per1_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_LmtCod_LmtCod_Per1_Return
# endif
# if defined (Rte_Runnable_Ap_LmtCod_LmtCod_Per1_Return)
#  undef Rte_Runnable_Ap_LmtCod_LmtCod_Per1_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_LmtCod_LmtCod_Per1_Return(void);
# else
#  define Rte_Runnable_Ap_LmtCod_LmtCod_Per1_Return() ((void)(0))
# endif /* Rte_Runnable_Ap_LmtCod_LmtCod_Per1_Return */

# if defined (Rte_Runnable_Ap_LmtCod_LmtCod_Per1_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_LmtCod_LmtCod_Per1_Start
# endif
# if defined (Rte_Runnable_Ap_LmtCod_LmtCod_Per1_Start)
#  undef Rte_Runnable_Ap_LmtCod_LmtCod_Per1_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_LmtCod_LmtCod_Per1_Start(void);
# else
#  define Rte_Runnable_Ap_LmtCod_LmtCod_Per1_Start() ((void)(0))
# endif /* Rte_Runnable_Ap_LmtCod_LmtCod_Per1_Start */

# if defined (Rte_Runnable_Ap_LrnEOT_LrnEOT_Init1_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_LrnEOT_LrnEOT_Init1_Return
# endif
# if defined (Rte_Runnable_Ap_LrnEOT_LrnEOT_Init1_Return)
#  undef Rte_Runnable_Ap_LrnEOT_LrnEOT_Init1_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_LrnEOT_LrnEOT_Init1_Return(void);
# else
#  define Rte_Runnable_Ap_LrnEOT_LrnEOT_Init1_Return() ((void)(0))
# endif /* Rte_Runnable_Ap_LrnEOT_LrnEOT_Init1_Return */

# if defined (Rte_Runnable_Ap_LrnEOT_LrnEOT_Init1_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_LrnEOT_LrnEOT_Init1_Start
# endif
# if defined (Rte_Runnable_Ap_LrnEOT_LrnEOT_Init1_Start)
#  undef Rte_Runnable_Ap_LrnEOT_LrnEOT_Init1_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_LrnEOT_LrnEOT_Init1_Start(void);
# else
#  define Rte_Runnable_Ap_LrnEOT_LrnEOT_Init1_Start() ((void)(0))
# endif /* Rte_Runnable_Ap_LrnEOT_LrnEOT_Init1_Start */

# if defined (Rte_Runnable_Ap_LrnEOT_LrnEOT_Per1_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_LrnEOT_LrnEOT_Per1_Return
# endif
# if defined (Rte_Runnable_Ap_LrnEOT_LrnEOT_Per1_Return)
#  undef Rte_Runnable_Ap_LrnEOT_LrnEOT_Per1_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_LrnEOT_LrnEOT_Per1_Return(void);
# else
#  define Rte_Runnable_Ap_LrnEOT_LrnEOT_Per1_Return() ((void)(0))
# endif /* Rte_Runnable_Ap_LrnEOT_LrnEOT_Per1_Return */

# if defined (Rte_Runnable_Ap_LrnEOT_LrnEOT_Per1_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_LrnEOT_LrnEOT_Per1_Start
# endif
# if defined (Rte_Runnable_Ap_LrnEOT_LrnEOT_Per1_Start)
#  undef Rte_Runnable_Ap_LrnEOT_LrnEOT_Per1_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_LrnEOT_LrnEOT_Per1_Start(void);
# else
#  define Rte_Runnable_Ap_LrnEOT_LrnEOT_Per1_Start() ((void)(0))
# endif /* Rte_Runnable_Ap_LrnEOT_LrnEOT_Per1_Start */

# if defined (Rte_Runnable_Ap_LrnEOT_LrnEOT_Scom_ResetEOT_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_LrnEOT_LrnEOT_Scom_ResetEOT_Return
# endif
# if defined (Rte_Runnable_Ap_LrnEOT_LrnEOT_Scom_ResetEOT_Return)
#  undef Rte_Runnable_Ap_LrnEOT_LrnEOT_Scom_ResetEOT_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_LrnEOT_LrnEOT_Scom_ResetEOT_Return(void);
# else
#  define Rte_Runnable_Ap_LrnEOT_LrnEOT_Scom_ResetEOT_Return() ((void)(0))
# endif /* Rte_Runnable_Ap_LrnEOT_LrnEOT_Scom_ResetEOT_Return */

# if defined (Rte_Runnable_Ap_LrnEOT_LrnEOT_Scom_ResetEOT_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_LrnEOT_LrnEOT_Scom_ResetEOT_Start
# endif
# if defined (Rte_Runnable_Ap_LrnEOT_LrnEOT_Scom_ResetEOT_Start)
#  undef Rte_Runnable_Ap_LrnEOT_LrnEOT_Scom_ResetEOT_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_LrnEOT_LrnEOT_Scom_ResetEOT_Start(void);
# else
#  define Rte_Runnable_Ap_LrnEOT_LrnEOT_Scom_ResetEOT_Start() ((void)(0))
# endif /* Rte_Runnable_Ap_LrnEOT_LrnEOT_Scom_ResetEOT_Start */

# if defined (Rte_Runnable_Ap_MtrTempEst_MtrTempEst_Init1_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_MtrTempEst_MtrTempEst_Init1_Return
# endif
# if defined (Rte_Runnable_Ap_MtrTempEst_MtrTempEst_Init1_Return)
#  undef Rte_Runnable_Ap_MtrTempEst_MtrTempEst_Init1_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_MtrTempEst_MtrTempEst_Init1_Return(void);
# else
#  define Rte_Runnable_Ap_MtrTempEst_MtrTempEst_Init1_Return() ((void)(0))
# endif /* Rte_Runnable_Ap_MtrTempEst_MtrTempEst_Init1_Return */

# if defined (Rte_Runnable_Ap_MtrTempEst_MtrTempEst_Init1_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_MtrTempEst_MtrTempEst_Init1_Start
# endif
# if defined (Rte_Runnable_Ap_MtrTempEst_MtrTempEst_Init1_Start)
#  undef Rte_Runnable_Ap_MtrTempEst_MtrTempEst_Init1_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_MtrTempEst_MtrTempEst_Init1_Start(void);
# else
#  define Rte_Runnable_Ap_MtrTempEst_MtrTempEst_Init1_Start() ((void)(0))
# endif /* Rte_Runnable_Ap_MtrTempEst_MtrTempEst_Init1_Start */

# if defined (Rte_Runnable_Ap_MtrTempEst_MtrTempEst_Per1_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_MtrTempEst_MtrTempEst_Per1_Return
# endif
# if defined (Rte_Runnable_Ap_MtrTempEst_MtrTempEst_Per1_Return)
#  undef Rte_Runnable_Ap_MtrTempEst_MtrTempEst_Per1_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_MtrTempEst_MtrTempEst_Per1_Return(void);
# else
#  define Rte_Runnable_Ap_MtrTempEst_MtrTempEst_Per1_Return() ((void)(0))
# endif /* Rte_Runnable_Ap_MtrTempEst_MtrTempEst_Per1_Return */

# if defined (Rte_Runnable_Ap_MtrTempEst_MtrTempEst_Per1_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_MtrTempEst_MtrTempEst_Per1_Start
# endif
# if defined (Rte_Runnable_Ap_MtrTempEst_MtrTempEst_Per1_Start)
#  undef Rte_Runnable_Ap_MtrTempEst_MtrTempEst_Per1_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_MtrTempEst_MtrTempEst_Per1_Start(void);
# else
#  define Rte_Runnable_Ap_MtrTempEst_MtrTempEst_Per1_Start() ((void)(0))
# endif /* Rte_Runnable_Ap_MtrTempEst_MtrTempEst_Per1_Start */

# if defined (Rte_Runnable_Ap_PAwTO_PAwTO_Init1_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_PAwTO_PAwTO_Init1_Return
# endif
# if defined (Rte_Runnable_Ap_PAwTO_PAwTO_Init1_Return)
#  undef Rte_Runnable_Ap_PAwTO_PAwTO_Init1_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_PAwTO_PAwTO_Init1_Return(void);
# else
#  define Rte_Runnable_Ap_PAwTO_PAwTO_Init1_Return() ((void)(0))
# endif /* Rte_Runnable_Ap_PAwTO_PAwTO_Init1_Return */

# if defined (Rte_Runnable_Ap_PAwTO_PAwTO_Init1_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_PAwTO_PAwTO_Init1_Start
# endif
# if defined (Rte_Runnable_Ap_PAwTO_PAwTO_Init1_Start)
#  undef Rte_Runnable_Ap_PAwTO_PAwTO_Init1_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_PAwTO_PAwTO_Init1_Start(void);
# else
#  define Rte_Runnable_Ap_PAwTO_PAwTO_Init1_Start() ((void)(0))
# endif /* Rte_Runnable_Ap_PAwTO_PAwTO_Init1_Start */

# if defined (Rte_Runnable_Ap_PAwTO_PAwTO_Per1_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_PAwTO_PAwTO_Per1_Return
# endif
# if defined (Rte_Runnable_Ap_PAwTO_PAwTO_Per1_Return)
#  undef Rte_Runnable_Ap_PAwTO_PAwTO_Per1_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_PAwTO_PAwTO_Per1_Return(void);
# else
#  define Rte_Runnable_Ap_PAwTO_PAwTO_Per1_Return() ((void)(0))
# endif /* Rte_Runnable_Ap_PAwTO_PAwTO_Per1_Return */

# if defined (Rte_Runnable_Ap_PAwTO_PAwTO_Per1_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_PAwTO_PAwTO_Per1_Start
# endif
# if defined (Rte_Runnable_Ap_PAwTO_PAwTO_Per1_Start)
#  undef Rte_Runnable_Ap_PAwTO_PAwTO_Per1_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_PAwTO_PAwTO_Per1_Start(void);
# else
#  define Rte_Runnable_Ap_PAwTO_PAwTO_Per1_Start() ((void)(0))
# endif /* Rte_Runnable_Ap_PAwTO_PAwTO_Per1_Start */

# if defined (Rte_Runnable_Ap_PAwTO_PAwTO_Per2_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_PAwTO_PAwTO_Per2_Return
# endif
# if defined (Rte_Runnable_Ap_PAwTO_PAwTO_Per2_Return)
#  undef Rte_Runnable_Ap_PAwTO_PAwTO_Per2_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_PAwTO_PAwTO_Per2_Return(void);
# else
#  define Rte_Runnable_Ap_PAwTO_PAwTO_Per2_Return() ((void)(0))
# endif /* Rte_Runnable_Ap_PAwTO_PAwTO_Per2_Return */

# if defined (Rte_Runnable_Ap_PAwTO_PAwTO_Per2_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_PAwTO_PAwTO_Per2_Start
# endif
# if defined (Rte_Runnable_Ap_PAwTO_PAwTO_Per2_Start)
#  undef Rte_Runnable_Ap_PAwTO_PAwTO_Per2_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_PAwTO_PAwTO_Per2_Start(void);
# else
#  define Rte_Runnable_Ap_PAwTO_PAwTO_Per2_Start() ((void)(0))
# endif /* Rte_Runnable_Ap_PAwTO_PAwTO_Per2_Start */

# if defined (Rte_Runnable_Ap_PICurrCntrl_PICurrCntrl_Per2_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_PICurrCntrl_PICurrCntrl_Per2_Return
# endif
# if defined (Rte_Runnable_Ap_PICurrCntrl_PICurrCntrl_Per2_Return)
#  undef Rte_Runnable_Ap_PICurrCntrl_PICurrCntrl_Per2_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_PICurrCntrl_PICurrCntrl_Per2_Return(void);
# else
#  define Rte_Runnable_Ap_PICurrCntrl_PICurrCntrl_Per2_Return() ((void)(0))
# endif /* Rte_Runnable_Ap_PICurrCntrl_PICurrCntrl_Per2_Return */

# if defined (Rte_Runnable_Ap_PICurrCntrl_PICurrCntrl_Per2_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_PICurrCntrl_PICurrCntrl_Per2_Start
# endif
# if defined (Rte_Runnable_Ap_PICurrCntrl_PICurrCntrl_Per2_Start)
#  undef Rte_Runnable_Ap_PICurrCntrl_PICurrCntrl_Per2_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_PICurrCntrl_PICurrCntrl_Per2_Start(void);
# else
#  define Rte_Runnable_Ap_PICurrCntrl_PICurrCntrl_Per2_Start() ((void)(0))
# endif /* Rte_Runnable_Ap_PICurrCntrl_PICurrCntrl_Per2_Start */

# if defined (Rte_Runnable_Ap_PeakCurrEst_PeakCurrEst_Per1_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_PeakCurrEst_PeakCurrEst_Per1_Return
# endif
# if defined (Rte_Runnable_Ap_PeakCurrEst_PeakCurrEst_Per1_Return)
#  undef Rte_Runnable_Ap_PeakCurrEst_PeakCurrEst_Per1_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_PeakCurrEst_PeakCurrEst_Per1_Return(void);
# else
#  define Rte_Runnable_Ap_PeakCurrEst_PeakCurrEst_Per1_Return() ((void)(0))
# endif /* Rte_Runnable_Ap_PeakCurrEst_PeakCurrEst_Per1_Return */

# if defined (Rte_Runnable_Ap_PeakCurrEst_PeakCurrEst_Per1_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_PeakCurrEst_PeakCurrEst_Per1_Start
# endif
# if defined (Rte_Runnable_Ap_PeakCurrEst_PeakCurrEst_Per1_Start)
#  undef Rte_Runnable_Ap_PeakCurrEst_PeakCurrEst_Per1_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_PeakCurrEst_PeakCurrEst_Per1_Start(void);
# else
#  define Rte_Runnable_Ap_PeakCurrEst_PeakCurrEst_Per1_Start() ((void)(0))
# endif /* Rte_Runnable_Ap_PeakCurrEst_PeakCurrEst_Per1_Start */

# if defined (Rte_Runnable_Ap_PeakCurrEst_PeakCurrEst_Per2_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_PeakCurrEst_PeakCurrEst_Per2_Return
# endif
# if defined (Rte_Runnable_Ap_PeakCurrEst_PeakCurrEst_Per2_Return)
#  undef Rte_Runnable_Ap_PeakCurrEst_PeakCurrEst_Per2_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_PeakCurrEst_PeakCurrEst_Per2_Return(void);
# else
#  define Rte_Runnable_Ap_PeakCurrEst_PeakCurrEst_Per2_Return() ((void)(0))
# endif /* Rte_Runnable_Ap_PeakCurrEst_PeakCurrEst_Per2_Return */

# if defined (Rte_Runnable_Ap_PeakCurrEst_PeakCurrEst_Per2_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_PeakCurrEst_PeakCurrEst_Per2_Start
# endif
# if defined (Rte_Runnable_Ap_PeakCurrEst_PeakCurrEst_Per2_Start)
#  undef Rte_Runnable_Ap_PeakCurrEst_PeakCurrEst_Per2_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_PeakCurrEst_PeakCurrEst_Per2_Start(void);
# else
#  define Rte_Runnable_Ap_PeakCurrEst_PeakCurrEst_Per2_Start() ((void)(0))
# endif /* Rte_Runnable_Ap_PeakCurrEst_PeakCurrEst_Per2_Start */

# if defined (Rte_Runnable_Ap_Polarity_Polarity_Init1_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_Polarity_Polarity_Init1_Return
# endif
# if defined (Rte_Runnable_Ap_Polarity_Polarity_Init1_Return)
#  undef Rte_Runnable_Ap_Polarity_Polarity_Init1_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_Polarity_Polarity_Init1_Return(void);
# else
#  define Rte_Runnable_Ap_Polarity_Polarity_Init1_Return() ((void)(0))
# endif /* Rte_Runnable_Ap_Polarity_Polarity_Init1_Return */

# if defined (Rte_Runnable_Ap_Polarity_Polarity_Init1_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_Polarity_Polarity_Init1_Start
# endif
# if defined (Rte_Runnable_Ap_Polarity_Polarity_Init1_Start)
#  undef Rte_Runnable_Ap_Polarity_Polarity_Init1_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_Polarity_Polarity_Init1_Start(void);
# else
#  define Rte_Runnable_Ap_Polarity_Polarity_Init1_Start() ((void)(0))
# endif /* Rte_Runnable_Ap_Polarity_Polarity_Init1_Start */

# if defined (Rte_Runnable_Ap_Polarity_Polarity_Per1_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_Polarity_Polarity_Per1_Return
# endif
# if defined (Rte_Runnable_Ap_Polarity_Polarity_Per1_Return)
#  undef Rte_Runnable_Ap_Polarity_Polarity_Per1_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_Polarity_Polarity_Per1_Return(void);
# else
#  define Rte_Runnable_Ap_Polarity_Polarity_Per1_Return() ((void)(0))
# endif /* Rte_Runnable_Ap_Polarity_Polarity_Per1_Return */

# if defined (Rte_Runnable_Ap_Polarity_Polarity_Per1_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_Polarity_Polarity_Per1_Start
# endif
# if defined (Rte_Runnable_Ap_Polarity_Polarity_Per1_Start)
#  undef Rte_Runnable_Ap_Polarity_Polarity_Per1_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_Polarity_Polarity_Per1_Start(void);
# else
#  define Rte_Runnable_Ap_Polarity_Polarity_Per1_Start() ((void)(0))
# endif /* Rte_Runnable_Ap_Polarity_Polarity_Per1_Start */

# if defined (Rte_Runnable_Ap_Polarity_Polarity_SCom_ReadPolarity_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_Polarity_Polarity_SCom_ReadPolarity_Return
# endif
# if defined (Rte_Runnable_Ap_Polarity_Polarity_SCom_ReadPolarity_Return)
#  undef Rte_Runnable_Ap_Polarity_Polarity_SCom_ReadPolarity_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_Polarity_Polarity_SCom_ReadPolarity_Return(P2VAR(UInt8, AUTOMATIC, RTE_AP_POLARITY_APPL_VAR) Polarity_Ptr_T_b08);
# else
#  define Rte_Runnable_Ap_Polarity_Polarity_SCom_ReadPolarity_Return(arg1) ((void)(0))
# endif /* Rte_Runnable_Ap_Polarity_Polarity_SCom_ReadPolarity_Return */

# if defined (Rte_Runnable_Ap_Polarity_Polarity_SCom_ReadPolarity_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_Polarity_Polarity_SCom_ReadPolarity_Start
# endif
# if defined (Rte_Runnable_Ap_Polarity_Polarity_SCom_ReadPolarity_Start)
#  undef Rte_Runnable_Ap_Polarity_Polarity_SCom_ReadPolarity_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_Polarity_Polarity_SCom_ReadPolarity_Start(P2VAR(UInt8, AUTOMATIC, RTE_AP_POLARITY_APPL_VAR) Polarity_Ptr_T_b08);
# else
#  define Rte_Runnable_Ap_Polarity_Polarity_SCom_ReadPolarity_Start(arg1) ((void)(0))
# endif /* Rte_Runnable_Ap_Polarity_Polarity_SCom_ReadPolarity_Start */

# if defined (Rte_Runnable_Ap_Polarity_Polarity_SCom_SetPolarity_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_Polarity_Polarity_SCom_SetPolarity_Return
# endif
# if defined (Rte_Runnable_Ap_Polarity_Polarity_SCom_SetPolarity_Return)
#  undef Rte_Runnable_Ap_Polarity_Polarity_SCom_SetPolarity_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_Polarity_Polarity_SCom_SetPolarity_Return(UInt8 Polarity_Cnt_T_b08);
# else
#  define Rte_Runnable_Ap_Polarity_Polarity_SCom_SetPolarity_Return(arg1) ((void)(0))
# endif /* Rte_Runnable_Ap_Polarity_Polarity_SCom_SetPolarity_Return */

# if defined (Rte_Runnable_Ap_Polarity_Polarity_SCom_SetPolarity_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_Polarity_Polarity_SCom_SetPolarity_Start
# endif
# if defined (Rte_Runnable_Ap_Polarity_Polarity_SCom_SetPolarity_Start)
#  undef Rte_Runnable_Ap_Polarity_Polarity_SCom_SetPolarity_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_Polarity_Polarity_SCom_SetPolarity_Start(UInt8 Polarity_Cnt_T_b08);
# else
#  define Rte_Runnable_Ap_Polarity_Polarity_SCom_SetPolarity_Start(arg1) ((void)(0))
# endif /* Rte_Runnable_Ap_Polarity_Polarity_SCom_SetPolarity_Start */

# if defined (Rte_Runnable_Ap_PwrLmtFuncCr_PwrLmtFuncCr_Init1_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_PwrLmtFuncCr_PwrLmtFuncCr_Init1_Return
# endif
# if defined (Rte_Runnable_Ap_PwrLmtFuncCr_PwrLmtFuncCr_Init1_Return)
#  undef Rte_Runnable_Ap_PwrLmtFuncCr_PwrLmtFuncCr_Init1_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_PwrLmtFuncCr_PwrLmtFuncCr_Init1_Return(void);
# else
#  define Rte_Runnable_Ap_PwrLmtFuncCr_PwrLmtFuncCr_Init1_Return() ((void)(0))
# endif /* Rte_Runnable_Ap_PwrLmtFuncCr_PwrLmtFuncCr_Init1_Return */

# if defined (Rte_Runnable_Ap_PwrLmtFuncCr_PwrLmtFuncCr_Init1_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_PwrLmtFuncCr_PwrLmtFuncCr_Init1_Start
# endif
# if defined (Rte_Runnable_Ap_PwrLmtFuncCr_PwrLmtFuncCr_Init1_Start)
#  undef Rte_Runnable_Ap_PwrLmtFuncCr_PwrLmtFuncCr_Init1_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_PwrLmtFuncCr_PwrLmtFuncCr_Init1_Start(void);
# else
#  define Rte_Runnable_Ap_PwrLmtFuncCr_PwrLmtFuncCr_Init1_Start() ((void)(0))
# endif /* Rte_Runnable_Ap_PwrLmtFuncCr_PwrLmtFuncCr_Init1_Start */

# if defined (Rte_Runnable_Ap_PwrLmtFuncCr_PwrLmtFuncCr_Per1_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_PwrLmtFuncCr_PwrLmtFuncCr_Per1_Return
# endif
# if defined (Rte_Runnable_Ap_PwrLmtFuncCr_PwrLmtFuncCr_Per1_Return)
#  undef Rte_Runnable_Ap_PwrLmtFuncCr_PwrLmtFuncCr_Per1_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_PwrLmtFuncCr_PwrLmtFuncCr_Per1_Return(void);
# else
#  define Rte_Runnable_Ap_PwrLmtFuncCr_PwrLmtFuncCr_Per1_Return() ((void)(0))
# endif /* Rte_Runnable_Ap_PwrLmtFuncCr_PwrLmtFuncCr_Per1_Return */

# if defined (Rte_Runnable_Ap_PwrLmtFuncCr_PwrLmtFuncCr_Per1_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_PwrLmtFuncCr_PwrLmtFuncCr_Per1_Start
# endif
# if defined (Rte_Runnable_Ap_PwrLmtFuncCr_PwrLmtFuncCr_Per1_Start)
#  undef Rte_Runnable_Ap_PwrLmtFuncCr_PwrLmtFuncCr_Per1_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_PwrLmtFuncCr_PwrLmtFuncCr_Per1_Start(void);
# else
#  define Rte_Runnable_Ap_PwrLmtFuncCr_PwrLmtFuncCr_Per1_Start() ((void)(0))
# endif /* Rte_Runnable_Ap_PwrLmtFuncCr_PwrLmtFuncCr_Per1_Start */

# if defined (Rte_Runnable_Ap_PwrLmtFuncCr_PwrLmtFuncCr_Per2_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_PwrLmtFuncCr_PwrLmtFuncCr_Per2_Return
# endif
# if defined (Rte_Runnable_Ap_PwrLmtFuncCr_PwrLmtFuncCr_Per2_Return)
#  undef Rte_Runnable_Ap_PwrLmtFuncCr_PwrLmtFuncCr_Per2_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_PwrLmtFuncCr_PwrLmtFuncCr_Per2_Return(void);
# else
#  define Rte_Runnable_Ap_PwrLmtFuncCr_PwrLmtFuncCr_Per2_Return() ((void)(0))
# endif /* Rte_Runnable_Ap_PwrLmtFuncCr_PwrLmtFuncCr_Per2_Return */

# if defined (Rte_Runnable_Ap_PwrLmtFuncCr_PwrLmtFuncCr_Per2_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_PwrLmtFuncCr_PwrLmtFuncCr_Per2_Start
# endif
# if defined (Rte_Runnable_Ap_PwrLmtFuncCr_PwrLmtFuncCr_Per2_Start)
#  undef Rte_Runnable_Ap_PwrLmtFuncCr_PwrLmtFuncCr_Per2_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_PwrLmtFuncCr_PwrLmtFuncCr_Per2_Start(void);
# else
#  define Rte_Runnable_Ap_PwrLmtFuncCr_PwrLmtFuncCr_Per2_Start() ((void)(0))
# endif /* Rte_Runnable_Ap_PwrLmtFuncCr_PwrLmtFuncCr_Per2_Start */

# if defined (Rte_Runnable_Ap_QuadDet_QuadDet_Per1_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_QuadDet_QuadDet_Per1_Return
# endif
# if defined (Rte_Runnable_Ap_QuadDet_QuadDet_Per1_Return)
#  undef Rte_Runnable_Ap_QuadDet_QuadDet_Per1_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_QuadDet_QuadDet_Per1_Return(void);
# else
#  define Rte_Runnable_Ap_QuadDet_QuadDet_Per1_Return() ((void)(0))
# endif /* Rte_Runnable_Ap_QuadDet_QuadDet_Per1_Return */

# if defined (Rte_Runnable_Ap_QuadDet_QuadDet_Per1_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_QuadDet_QuadDet_Per1_Start
# endif
# if defined (Rte_Runnable_Ap_QuadDet_QuadDet_Per1_Start)
#  undef Rte_Runnable_Ap_QuadDet_QuadDet_Per1_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_QuadDet_QuadDet_Per1_Start(void);
# else
#  define Rte_Runnable_Ap_QuadDet_QuadDet_Per1_Start() ((void)(0))
# endif /* Rte_Runnable_Ap_QuadDet_QuadDet_Per1_Start */

# if defined (Rte_Runnable_Ap_ReturnFirewall_ReturnFirewall_Per1_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_ReturnFirewall_ReturnFirewall_Per1_Return
# endif
# if defined (Rte_Runnable_Ap_ReturnFirewall_ReturnFirewall_Per1_Return)
#  undef Rte_Runnable_Ap_ReturnFirewall_ReturnFirewall_Per1_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_ReturnFirewall_ReturnFirewall_Per1_Return(void);
# else
#  define Rte_Runnable_Ap_ReturnFirewall_ReturnFirewall_Per1_Return() ((void)(0))
# endif /* Rte_Runnable_Ap_ReturnFirewall_ReturnFirewall_Per1_Return */

# if defined (Rte_Runnable_Ap_ReturnFirewall_ReturnFirewall_Per1_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_ReturnFirewall_ReturnFirewall_Per1_Start
# endif
# if defined (Rte_Runnable_Ap_ReturnFirewall_ReturnFirewall_Per1_Start)
#  undef Rte_Runnable_Ap_ReturnFirewall_ReturnFirewall_Per1_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_ReturnFirewall_ReturnFirewall_Per1_Start(void);
# else
#  define Rte_Runnable_Ap_ReturnFirewall_ReturnFirewall_Per1_Start() ((void)(0))
# endif /* Rte_Runnable_Ap_ReturnFirewall_ReturnFirewall_Per1_Start */

# if defined (Rte_Runnable_Ap_Return_Return_Per1_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_Return_Return_Per1_Return
# endif
# if defined (Rte_Runnable_Ap_Return_Return_Per1_Return)
#  undef Rte_Runnable_Ap_Return_Return_Per1_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_Return_Return_Per1_Return(void);
# else
#  define Rte_Runnable_Ap_Return_Return_Per1_Return() ((void)(0))
# endif /* Rte_Runnable_Ap_Return_Return_Per1_Return */

# if defined (Rte_Runnable_Ap_Return_Return_Per1_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_Return_Return_Per1_Start
# endif
# if defined (Rte_Runnable_Ap_Return_Return_Per1_Start)
#  undef Rte_Runnable_Ap_Return_Return_Per1_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_Return_Return_Per1_Start(void);
# else
#  define Rte_Runnable_Ap_Return_Return_Per1_Start() ((void)(0))
# endif /* Rte_Runnable_Ap_Return_Return_Per1_Start */

# if defined (Rte_Runnable_Ap_SignlCondn_SignlCondn_Per1_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_SignlCondn_SignlCondn_Per1_Return
# endif
# if defined (Rte_Runnable_Ap_SignlCondn_SignlCondn_Per1_Return)
#  undef Rte_Runnable_Ap_SignlCondn_SignlCondn_Per1_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_SignlCondn_SignlCondn_Per1_Return(void);
# else
#  define Rte_Runnable_Ap_SignlCondn_SignlCondn_Per1_Return() ((void)(0))
# endif /* Rte_Runnable_Ap_SignlCondn_SignlCondn_Per1_Return */

# if defined (Rte_Runnable_Ap_SignlCondn_SignlCondn_Per1_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_SignlCondn_SignlCondn_Per1_Start
# endif
# if defined (Rte_Runnable_Ap_SignlCondn_SignlCondn_Per1_Start)
#  undef Rte_Runnable_Ap_SignlCondn_SignlCondn_Per1_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_SignlCondn_SignlCondn_Per1_Start(void);
# else
#  define Rte_Runnable_Ap_SignlCondn_SignlCondn_Per1_Start() ((void)(0))
# endif /* Rte_Runnable_Ap_SignlCondn_SignlCondn_Per1_Start */

# if defined (Rte_Runnable_Ap_SrlComInput_FaultInjection_FltInjection_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_SrlComInput_FaultInjection_FltInjection_Return
# endif
# if defined (Rte_Runnable_Ap_SrlComInput_FaultInjection_FltInjection_Return)
#  undef Rte_Runnable_Ap_SrlComInput_FaultInjection_FltInjection_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_SrlComInput_FaultInjection_FltInjection_Return(P2VAR(Float, AUTOMATIC, RTE_AP_SRLCOMINPUT_APPL_VAR) SignalPath_Uls_f32, FltInjectionLocType LocationKey_Cnt_enum);
# else
#  define Rte_Runnable_Ap_SrlComInput_FaultInjection_FltInjection_Return(arg1, arg2) ((void)(0))
# endif /* Rte_Runnable_Ap_SrlComInput_FaultInjection_FltInjection_Return */

# if defined (Rte_Runnable_Ap_SrlComInput_FaultInjection_FltInjection_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_SrlComInput_FaultInjection_FltInjection_Start
# endif
# if defined (Rte_Runnable_Ap_SrlComInput_FaultInjection_FltInjection_Start)
#  undef Rte_Runnable_Ap_SrlComInput_FaultInjection_FltInjection_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_SrlComInput_FaultInjection_FltInjection_Start(P2VAR(Float, AUTOMATIC, RTE_AP_SRLCOMINPUT_APPL_VAR) SignalPath_Uls_f32, FltInjectionLocType LocationKey_Cnt_enum);
# else
#  define Rte_Runnable_Ap_SrlComInput_FaultInjection_FltInjection_Start(arg1, arg2) ((void)(0))
# endif /* Rte_Runnable_Ap_SrlComInput_FaultInjection_FltInjection_Start */

# if defined (Rte_Runnable_Ap_SrlComInput_HaLFState_SCom_Transition_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_SrlComInput_HaLFState_SCom_Transition_Return
# endif
# if defined (Rte_Runnable_Ap_SrlComInput_HaLFState_SCom_Transition_Return)
#  undef Rte_Runnable_Ap_SrlComInput_HaLFState_SCom_Transition_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_SrlComInput_HaLFState_SCom_Transition_Return(UInt8 State_Cnt_T_u08);
# else
#  define Rte_Runnable_Ap_SrlComInput_HaLFState_SCom_Transition_Return(arg1) ((void)(0))
# endif /* Rte_Runnable_Ap_SrlComInput_HaLFState_SCom_Transition_Return */

# if defined (Rte_Runnable_Ap_SrlComInput_HaLFState_SCom_Transition_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_SrlComInput_HaLFState_SCom_Transition_Start
# endif
# if defined (Rte_Runnable_Ap_SrlComInput_HaLFState_SCom_Transition_Start)
#  undef Rte_Runnable_Ap_SrlComInput_HaLFState_SCom_Transition_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_SrlComInput_HaLFState_SCom_Transition_Start(UInt8 State_Cnt_T_u08);
# else
#  define Rte_Runnable_Ap_SrlComInput_HaLFState_SCom_Transition_Start(arg1) ((void)(0))
# endif /* Rte_Runnable_Ap_SrlComInput_HaLFState_SCom_Transition_Start */

# if defined (Rte_Runnable_Ap_SrlComInput_PrkAssistState_SCom_Transition_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_SrlComInput_PrkAssistState_SCom_Transition_Return
# endif
# if defined (Rte_Runnable_Ap_SrlComInput_PrkAssistState_SCom_Transition_Return)
#  undef Rte_Runnable_Ap_SrlComInput_PrkAssistState_SCom_Transition_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_SrlComInput_PrkAssistState_SCom_Transition_Return(UInt8 State_Cnt_T_u08);
# else
#  define Rte_Runnable_Ap_SrlComInput_PrkAssistState_SCom_Transition_Return(arg1) ((void)(0))
# endif /* Rte_Runnable_Ap_SrlComInput_PrkAssistState_SCom_Transition_Return */

# if defined (Rte_Runnable_Ap_SrlComInput_PrkAssistState_SCom_Transition_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_SrlComInput_PrkAssistState_SCom_Transition_Start
# endif
# if defined (Rte_Runnable_Ap_SrlComInput_PrkAssistState_SCom_Transition_Start)
#  undef Rte_Runnable_Ap_SrlComInput_PrkAssistState_SCom_Transition_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_SrlComInput_PrkAssistState_SCom_Transition_Start(UInt8 State_Cnt_T_u08);
# else
#  define Rte_Runnable_Ap_SrlComInput_PrkAssistState_SCom_Transition_Start(arg1) ((void)(0))
# endif /* Rte_Runnable_Ap_SrlComInput_PrkAssistState_SCom_Transition_Start */

# if defined (Rte_Runnable_Ap_SrlComInput_SrlComInput_Init_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_SrlComInput_SrlComInput_Init_Return
# endif
# if defined (Rte_Runnable_Ap_SrlComInput_SrlComInput_Init_Return)
#  undef Rte_Runnable_Ap_SrlComInput_SrlComInput_Init_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_SrlComInput_SrlComInput_Init_Return(void);
# else
#  define Rte_Runnable_Ap_SrlComInput_SrlComInput_Init_Return() ((void)(0))
# endif /* Rte_Runnable_Ap_SrlComInput_SrlComInput_Init_Return */

# if defined (Rte_Runnable_Ap_SrlComInput_SrlComInput_Init_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_SrlComInput_SrlComInput_Init_Start
# endif
# if defined (Rte_Runnable_Ap_SrlComInput_SrlComInput_Init_Start)
#  undef Rte_Runnable_Ap_SrlComInput_SrlComInput_Init_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_SrlComInput_SrlComInput_Init_Start(void);
# else
#  define Rte_Runnable_Ap_SrlComInput_SrlComInput_Init_Start() ((void)(0))
# endif /* Rte_Runnable_Ap_SrlComInput_SrlComInput_Init_Start */

# if defined (Rte_Runnable_Ap_SrlComInput_SrlComInput_Per1_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_SrlComInput_SrlComInput_Per1_Return
# endif
# if defined (Rte_Runnable_Ap_SrlComInput_SrlComInput_Per1_Return)
#  undef Rte_Runnable_Ap_SrlComInput_SrlComInput_Per1_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_SrlComInput_SrlComInput_Per1_Return(void);
# else
#  define Rte_Runnable_Ap_SrlComInput_SrlComInput_Per1_Return() ((void)(0))
# endif /* Rte_Runnable_Ap_SrlComInput_SrlComInput_Per1_Return */

# if defined (Rte_Runnable_Ap_SrlComInput_SrlComInput_Per1_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_SrlComInput_SrlComInput_Per1_Start
# endif
# if defined (Rte_Runnable_Ap_SrlComInput_SrlComInput_Per1_Start)
#  undef Rte_Runnable_Ap_SrlComInput_SrlComInput_Per1_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_SrlComInput_SrlComInput_Per1_Start(void);
# else
#  define Rte_Runnable_Ap_SrlComInput_SrlComInput_Per1_Start() ((void)(0))
# endif /* Rte_Runnable_Ap_SrlComInput_SrlComInput_Per1_Start */

# if defined (Rte_Runnable_Ap_SrlComInput_SrlComInput_SCom_ManualVehSpd_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_SrlComInput_SrlComInput_SCom_ManualVehSpd_Return
# endif
# if defined (Rte_Runnable_Ap_SrlComInput_SrlComInput_SCom_ManualVehSpd_Return)
#  undef Rte_Runnable_Ap_SrlComInput_SrlComInput_SCom_ManualVehSpd_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_SrlComInput_SrlComInput_SCom_ManualVehSpd_Return(Float VehSpd_Kph_f32);
# else
#  define Rte_Runnable_Ap_SrlComInput_SrlComInput_SCom_ManualVehSpd_Return(arg1) ((void)(0))
# endif /* Rte_Runnable_Ap_SrlComInput_SrlComInput_SCom_ManualVehSpd_Return */

# if defined (Rte_Runnable_Ap_SrlComInput_SrlComInput_SCom_ManualVehSpd_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_SrlComInput_SrlComInput_SCom_ManualVehSpd_Start
# endif
# if defined (Rte_Runnable_Ap_SrlComInput_SrlComInput_SCom_ManualVehSpd_Start)
#  undef Rte_Runnable_Ap_SrlComInput_SrlComInput_SCom_ManualVehSpd_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_SrlComInput_SrlComInput_SCom_ManualVehSpd_Start(Float VehSpd_Kph_f32);
# else
#  define Rte_Runnable_Ap_SrlComInput_SrlComInput_SCom_ManualVehSpd_Start(arg1) ((void)(0))
# endif /* Rte_Runnable_Ap_SrlComInput_SrlComInput_SCom_ManualVehSpd_Start */

# if defined (Rte_Runnable_Ap_SrlComOutput_SrlComOutput_Init1_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_SrlComOutput_SrlComOutput_Init1_Return
# endif
# if defined (Rte_Runnable_Ap_SrlComOutput_SrlComOutput_Init1_Return)
#  undef Rte_Runnable_Ap_SrlComOutput_SrlComOutput_Init1_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_SrlComOutput_SrlComOutput_Init1_Return(void);
# else
#  define Rte_Runnable_Ap_SrlComOutput_SrlComOutput_Init1_Return() ((void)(0))
# endif /* Rte_Runnable_Ap_SrlComOutput_SrlComOutput_Init1_Return */

# if defined (Rte_Runnable_Ap_SrlComOutput_SrlComOutput_Init1_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_SrlComOutput_SrlComOutput_Init1_Start
# endif
# if defined (Rte_Runnable_Ap_SrlComOutput_SrlComOutput_Init1_Start)
#  undef Rte_Runnable_Ap_SrlComOutput_SrlComOutput_Init1_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_SrlComOutput_SrlComOutput_Init1_Start(void);
# else
#  define Rte_Runnable_Ap_SrlComOutput_SrlComOutput_Init1_Start() ((void)(0))
# endif /* Rte_Runnable_Ap_SrlComOutput_SrlComOutput_Init1_Start */

# if defined (Rte_Runnable_Ap_SrlComOutput_SrlComOutput_Per1_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_SrlComOutput_SrlComOutput_Per1_Return
# endif
# if defined (Rte_Runnable_Ap_SrlComOutput_SrlComOutput_Per1_Return)
#  undef Rte_Runnable_Ap_SrlComOutput_SrlComOutput_Per1_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_SrlComOutput_SrlComOutput_Per1_Return(void);
# else
#  define Rte_Runnable_Ap_SrlComOutput_SrlComOutput_Per1_Return() ((void)(0))
# endif /* Rte_Runnable_Ap_SrlComOutput_SrlComOutput_Per1_Return */

# if defined (Rte_Runnable_Ap_SrlComOutput_SrlComOutput_Per1_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_SrlComOutput_SrlComOutput_Per1_Start
# endif
# if defined (Rte_Runnable_Ap_SrlComOutput_SrlComOutput_Per1_Start)
#  undef Rte_Runnable_Ap_SrlComOutput_SrlComOutput_Per1_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_SrlComOutput_SrlComOutput_Per1_Start(void);
# else
#  define Rte_Runnable_Ap_SrlComOutput_SrlComOutput_Per1_Start() ((void)(0))
# endif /* Rte_Runnable_Ap_SrlComOutput_SrlComOutput_Per1_Start */

# if defined (Rte_Runnable_Ap_StOpCtrl_StOpCtrl_Per1_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_StOpCtrl_StOpCtrl_Per1_Return
# endif
# if defined (Rte_Runnable_Ap_StOpCtrl_StOpCtrl_Per1_Return)
#  undef Rte_Runnable_Ap_StOpCtrl_StOpCtrl_Per1_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_StOpCtrl_StOpCtrl_Per1_Return(void);
# else
#  define Rte_Runnable_Ap_StOpCtrl_StOpCtrl_Per1_Return() ((void)(0))
# endif /* Rte_Runnable_Ap_StOpCtrl_StOpCtrl_Per1_Return */

# if defined (Rte_Runnable_Ap_StOpCtrl_StOpCtrl_Per1_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_StOpCtrl_StOpCtrl_Per1_Start
# endif
# if defined (Rte_Runnable_Ap_StOpCtrl_StOpCtrl_Per1_Start)
#  undef Rte_Runnable_Ap_StOpCtrl_StOpCtrl_Per1_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_StOpCtrl_StOpCtrl_Per1_Start(void);
# else
#  define Rte_Runnable_Ap_StOpCtrl_StOpCtrl_Per1_Start() ((void)(0))
# endif /* Rte_Runnable_Ap_StOpCtrl_StOpCtrl_Per1_Start */

# if defined (Rte_Runnable_Ap_StaMd8_MilestoneRqst8_WarmInitMilestoneComplete_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_StaMd8_MilestoneRqst8_WarmInitMilestoneComplete_Return
# endif
# if defined (Rte_Runnable_Ap_StaMd8_MilestoneRqst8_WarmInitMilestoneComplete_Return)
#  undef Rte_Runnable_Ap_StaMd8_MilestoneRqst8_WarmInitMilestoneComplete_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_StaMd8_MilestoneRqst8_WarmInitMilestoneComplete_Return(StaMd_Users user);
# else
#  define Rte_Runnable_Ap_StaMd8_MilestoneRqst8_WarmInitMilestoneComplete_Return(arg1) ((void)(0))
# endif /* Rte_Runnable_Ap_StaMd8_MilestoneRqst8_WarmInitMilestoneComplete_Return */

# if defined (Rte_Runnable_Ap_StaMd8_MilestoneRqst8_WarmInitMilestoneComplete_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_StaMd8_MilestoneRqst8_WarmInitMilestoneComplete_Start
# endif
# if defined (Rte_Runnable_Ap_StaMd8_MilestoneRqst8_WarmInitMilestoneComplete_Start)
#  undef Rte_Runnable_Ap_StaMd8_MilestoneRqst8_WarmInitMilestoneComplete_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_StaMd8_MilestoneRqst8_WarmInitMilestoneComplete_Start(StaMd_Users user);
# else
#  define Rte_Runnable_Ap_StaMd8_MilestoneRqst8_WarmInitMilestoneComplete_Start(arg1) ((void)(0))
# endif /* Rte_Runnable_Ap_StaMd8_MilestoneRqst8_WarmInitMilestoneComplete_Start */

# if defined (Rte_Runnable_Ap_StaMd8_MilestoneRqst8_WarmInitMilestoneNotComplete_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_StaMd8_MilestoneRqst8_WarmInitMilestoneNotComplete_Return
# endif
# if defined (Rte_Runnable_Ap_StaMd8_MilestoneRqst8_WarmInitMilestoneNotComplete_Return)
#  undef Rte_Runnable_Ap_StaMd8_MilestoneRqst8_WarmInitMilestoneNotComplete_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_StaMd8_MilestoneRqst8_WarmInitMilestoneNotComplete_Return(StaMd_Users user);
# else
#  define Rte_Runnable_Ap_StaMd8_MilestoneRqst8_WarmInitMilestoneNotComplete_Return(arg1) ((void)(0))
# endif /* Rte_Runnable_Ap_StaMd8_MilestoneRqst8_WarmInitMilestoneNotComplete_Return */

# if defined (Rte_Runnable_Ap_StaMd8_MilestoneRqst8_WarmInitMilestoneNotComplete_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_StaMd8_MilestoneRqst8_WarmInitMilestoneNotComplete_Start
# endif
# if defined (Rte_Runnable_Ap_StaMd8_MilestoneRqst8_WarmInitMilestoneNotComplete_Start)
#  undef Rte_Runnable_Ap_StaMd8_MilestoneRqst8_WarmInitMilestoneNotComplete_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_StaMd8_MilestoneRqst8_WarmInitMilestoneNotComplete_Start(StaMd_Users user);
# else
#  define Rte_Runnable_Ap_StaMd8_MilestoneRqst8_WarmInitMilestoneNotComplete_Start(arg1) ((void)(0))
# endif /* Rte_Runnable_Ap_StaMd8_MilestoneRqst8_WarmInitMilestoneNotComplete_Start */

# if defined (Rte_Runnable_Ap_StaMd8_StaMd8_Per1_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_StaMd8_StaMd8_Per1_Return
# endif
# if defined (Rte_Runnable_Ap_StaMd8_StaMd8_Per1_Return)
#  undef Rte_Runnable_Ap_StaMd8_StaMd8_Per1_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_StaMd8_StaMd8_Per1_Return(void);
# else
#  define Rte_Runnable_Ap_StaMd8_StaMd8_Per1_Return() ((void)(0))
# endif /* Rte_Runnable_Ap_StaMd8_StaMd8_Per1_Return */

# if defined (Rte_Runnable_Ap_StaMd8_StaMd8_Per1_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_StaMd8_StaMd8_Per1_Start
# endif
# if defined (Rte_Runnable_Ap_StaMd8_StaMd8_Per1_Start)
#  undef Rte_Runnable_Ap_StaMd8_StaMd8_Per1_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_StaMd8_StaMd8_Per1_Start(void);
# else
#  define Rte_Runnable_Ap_StaMd8_StaMd8_Per1_Start() ((void)(0))
# endif /* Rte_Runnable_Ap_StaMd8_StaMd8_Per1_Start */

# if defined (Rte_Runnable_Ap_StaMd9_MilestoneRqst9_WarmInitMilestoneComplete_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_StaMd9_MilestoneRqst9_WarmInitMilestoneComplete_Return
# endif
# if defined (Rte_Runnable_Ap_StaMd9_MilestoneRqst9_WarmInitMilestoneComplete_Return)
#  undef Rte_Runnable_Ap_StaMd9_MilestoneRqst9_WarmInitMilestoneComplete_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_StaMd9_MilestoneRqst9_WarmInitMilestoneComplete_Return(StaMd_Users user);
# else
#  define Rte_Runnable_Ap_StaMd9_MilestoneRqst9_WarmInitMilestoneComplete_Return(arg1) ((void)(0))
# endif /* Rte_Runnable_Ap_StaMd9_MilestoneRqst9_WarmInitMilestoneComplete_Return */

# if defined (Rte_Runnable_Ap_StaMd9_MilestoneRqst9_WarmInitMilestoneComplete_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_StaMd9_MilestoneRqst9_WarmInitMilestoneComplete_Start
# endif
# if defined (Rte_Runnable_Ap_StaMd9_MilestoneRqst9_WarmInitMilestoneComplete_Start)
#  undef Rte_Runnable_Ap_StaMd9_MilestoneRqst9_WarmInitMilestoneComplete_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_StaMd9_MilestoneRqst9_WarmInitMilestoneComplete_Start(StaMd_Users user);
# else
#  define Rte_Runnable_Ap_StaMd9_MilestoneRqst9_WarmInitMilestoneComplete_Start(arg1) ((void)(0))
# endif /* Rte_Runnable_Ap_StaMd9_MilestoneRqst9_WarmInitMilestoneComplete_Start */

# if defined (Rte_Runnable_Ap_StaMd9_MilestoneRqst9_WarmInitMilestoneNotComplete_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_StaMd9_MilestoneRqst9_WarmInitMilestoneNotComplete_Return
# endif
# if defined (Rte_Runnable_Ap_StaMd9_MilestoneRqst9_WarmInitMilestoneNotComplete_Return)
#  undef Rte_Runnable_Ap_StaMd9_MilestoneRqst9_WarmInitMilestoneNotComplete_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_StaMd9_MilestoneRqst9_WarmInitMilestoneNotComplete_Return(StaMd_Users user);
# else
#  define Rte_Runnable_Ap_StaMd9_MilestoneRqst9_WarmInitMilestoneNotComplete_Return(arg1) ((void)(0))
# endif /* Rte_Runnable_Ap_StaMd9_MilestoneRqst9_WarmInitMilestoneNotComplete_Return */

# if defined (Rte_Runnable_Ap_StaMd9_MilestoneRqst9_WarmInitMilestoneNotComplete_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_StaMd9_MilestoneRqst9_WarmInitMilestoneNotComplete_Start
# endif
# if defined (Rte_Runnable_Ap_StaMd9_MilestoneRqst9_WarmInitMilestoneNotComplete_Start)
#  undef Rte_Runnable_Ap_StaMd9_MilestoneRqst9_WarmInitMilestoneNotComplete_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_StaMd9_MilestoneRqst9_WarmInitMilestoneNotComplete_Start(StaMd_Users user);
# else
#  define Rte_Runnable_Ap_StaMd9_MilestoneRqst9_WarmInitMilestoneNotComplete_Start(arg1) ((void)(0))
# endif /* Rte_Runnable_Ap_StaMd9_MilestoneRqst9_WarmInitMilestoneNotComplete_Start */

# if defined (Rte_Runnable_Ap_StaMd9_StaMd9_Per1_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_StaMd9_StaMd9_Per1_Return
# endif
# if defined (Rte_Runnable_Ap_StaMd9_StaMd9_Per1_Return)
#  undef Rte_Runnable_Ap_StaMd9_StaMd9_Per1_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_StaMd9_StaMd9_Per1_Return(void);
# else
#  define Rte_Runnable_Ap_StaMd9_StaMd9_Per1_Return() ((void)(0))
# endif /* Rte_Runnable_Ap_StaMd9_StaMd9_Per1_Return */

# if defined (Rte_Runnable_Ap_StaMd9_StaMd9_Per1_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_StaMd9_StaMd9_Per1_Start
# endif
# if defined (Rte_Runnable_Ap_StaMd9_StaMd9_Per1_Start)
#  undef Rte_Runnable_Ap_StaMd9_StaMd9_Per1_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_StaMd9_StaMd9_Per1_Start(void);
# else
#  define Rte_Runnable_Ap_StaMd9_StaMd9_Per1_Start() ((void)(0))
# endif /* Rte_Runnable_Ap_StaMd9_StaMd9_Per1_Start */

# if defined (Rte_Runnable_Ap_StaMd9_StaMd9_Trns_DemShutdown_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_StaMd9_StaMd9_Trns_DemShutdown_Return
# endif
# if defined (Rte_Runnable_Ap_StaMd9_StaMd9_Trns_DemShutdown_Return)
#  undef Rte_Runnable_Ap_StaMd9_StaMd9_Trns_DemShutdown_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_StaMd9_StaMd9_Trns_DemShutdown_Return(void);
# else
#  define Rte_Runnable_Ap_StaMd9_StaMd9_Trns_DemShutdown_Return() ((void)(0))
# endif /* Rte_Runnable_Ap_StaMd9_StaMd9_Trns_DemShutdown_Return */

# if defined (Rte_Runnable_Ap_StaMd9_StaMd9_Trns_DemShutdown_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_StaMd9_StaMd9_Trns_DemShutdown_Start
# endif
# if defined (Rte_Runnable_Ap_StaMd9_StaMd9_Trns_DemShutdown_Start)
#  undef Rte_Runnable_Ap_StaMd9_StaMd9_Trns_DemShutdown_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_StaMd9_StaMd9_Trns_DemShutdown_Start(void);
# else
#  define Rte_Runnable_Ap_StaMd9_StaMd9_Trns_DemShutdown_Start() ((void)(0))
# endif /* Rte_Runnable_Ap_StaMd9_StaMd9_Trns_DemShutdown_Start */

# if defined (Rte_Runnable_Ap_StaMd9_StaMd_SCom_EcuReset_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_StaMd9_StaMd_SCom_EcuReset_Return
# endif
# if defined (Rte_Runnable_Ap_StaMd9_StaMd_SCom_EcuReset_Return)
#  undef Rte_Runnable_Ap_StaMd9_StaMd_SCom_EcuReset_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_StaMd9_StaMd_SCom_EcuReset_Return(void);
# else
#  define Rte_Runnable_Ap_StaMd9_StaMd_SCom_EcuReset_Return() ((void)(0))
# endif /* Rte_Runnable_Ap_StaMd9_StaMd_SCom_EcuReset_Return */

# if defined (Rte_Runnable_Ap_StaMd9_StaMd_SCom_EcuReset_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_StaMd9_StaMd_SCom_EcuReset_Start
# endif
# if defined (Rte_Runnable_Ap_StaMd9_StaMd_SCom_EcuReset_Start)
#  undef Rte_Runnable_Ap_StaMd9_StaMd_SCom_EcuReset_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_StaMd9_StaMd_SCom_EcuReset_Start(void);
# else
#  define Rte_Runnable_Ap_StaMd9_StaMd_SCom_EcuReset_Start() ((void)(0))
# endif /* Rte_Runnable_Ap_StaMd9_StaMd_SCom_EcuReset_Start */

# if defined (Rte_Runnable_Ap_StaMd_MilestoneRqst_WarmInitMilestoneComplete_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_StaMd_MilestoneRqst_WarmInitMilestoneComplete_Return
# endif
# if defined (Rte_Runnable_Ap_StaMd_MilestoneRqst_WarmInitMilestoneComplete_Return)
#  undef Rte_Runnable_Ap_StaMd_MilestoneRqst_WarmInitMilestoneComplete_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_StaMd_MilestoneRqst_WarmInitMilestoneComplete_Return(StaMd_Users user);
# else
#  define Rte_Runnable_Ap_StaMd_MilestoneRqst_WarmInitMilestoneComplete_Return(arg1) ((void)(0))
# endif /* Rte_Runnable_Ap_StaMd_MilestoneRqst_WarmInitMilestoneComplete_Return */

# if defined (Rte_Runnable_Ap_StaMd_MilestoneRqst_WarmInitMilestoneComplete_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_StaMd_MilestoneRqst_WarmInitMilestoneComplete_Start
# endif
# if defined (Rte_Runnable_Ap_StaMd_MilestoneRqst_WarmInitMilestoneComplete_Start)
#  undef Rte_Runnable_Ap_StaMd_MilestoneRqst_WarmInitMilestoneComplete_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_StaMd_MilestoneRqst_WarmInitMilestoneComplete_Start(StaMd_Users user);
# else
#  define Rte_Runnable_Ap_StaMd_MilestoneRqst_WarmInitMilestoneComplete_Start(arg1) ((void)(0))
# endif /* Rte_Runnable_Ap_StaMd_MilestoneRqst_WarmInitMilestoneComplete_Start */

# if defined (Rte_Runnable_Ap_StaMd_MilestoneRqst_WarmInitMilestoneNotComplete_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_StaMd_MilestoneRqst_WarmInitMilestoneNotComplete_Return
# endif
# if defined (Rte_Runnable_Ap_StaMd_MilestoneRqst_WarmInitMilestoneNotComplete_Return)
#  undef Rte_Runnable_Ap_StaMd_MilestoneRqst_WarmInitMilestoneNotComplete_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_StaMd_MilestoneRqst_WarmInitMilestoneNotComplete_Return(StaMd_Users user);
# else
#  define Rte_Runnable_Ap_StaMd_MilestoneRqst_WarmInitMilestoneNotComplete_Return(arg1) ((void)(0))
# endif /* Rte_Runnable_Ap_StaMd_MilestoneRqst_WarmInitMilestoneNotComplete_Return */

# if defined (Rte_Runnable_Ap_StaMd_MilestoneRqst_WarmInitMilestoneNotComplete_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_StaMd_MilestoneRqst_WarmInitMilestoneNotComplete_Start
# endif
# if defined (Rte_Runnable_Ap_StaMd_MilestoneRqst_WarmInitMilestoneNotComplete_Start)
#  undef Rte_Runnable_Ap_StaMd_MilestoneRqst_WarmInitMilestoneNotComplete_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_StaMd_MilestoneRqst_WarmInitMilestoneNotComplete_Start(StaMd_Users user);
# else
#  define Rte_Runnable_Ap_StaMd_MilestoneRqst_WarmInitMilestoneNotComplete_Start(arg1) ((void)(0))
# endif /* Rte_Runnable_Ap_StaMd_MilestoneRqst_WarmInitMilestoneNotComplete_Start */

# if defined (Rte_Runnable_Ap_StaMd_StaMd_Init1_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_StaMd_StaMd_Init1_Return
# endif
# if defined (Rte_Runnable_Ap_StaMd_StaMd_Init1_Return)
#  undef Rte_Runnable_Ap_StaMd_StaMd_Init1_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_StaMd_StaMd_Init1_Return(void);
# else
#  define Rte_Runnable_Ap_StaMd_StaMd_Init1_Return() ((void)(0))
# endif /* Rte_Runnable_Ap_StaMd_StaMd_Init1_Return */

# if defined (Rte_Runnable_Ap_StaMd_StaMd_Init1_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_StaMd_StaMd_Init1_Start
# endif
# if defined (Rte_Runnable_Ap_StaMd_StaMd_Init1_Start)
#  undef Rte_Runnable_Ap_StaMd_StaMd_Init1_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_StaMd_StaMd_Init1_Start(void);
# else
#  define Rte_Runnable_Ap_StaMd_StaMd_Init1_Start() ((void)(0))
# endif /* Rte_Runnable_Ap_StaMd_StaMd_Init1_Start */

# if defined (Rte_Runnable_Ap_StaMd_StaMd_Per1_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_StaMd_StaMd_Per1_Return
# endif
# if defined (Rte_Runnable_Ap_StaMd_StaMd_Per1_Return)
#  undef Rte_Runnable_Ap_StaMd_StaMd_Per1_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_StaMd_StaMd_Per1_Return(void);
# else
#  define Rte_Runnable_Ap_StaMd_StaMd_Per1_Return() ((void)(0))
# endif /* Rte_Runnable_Ap_StaMd_StaMd_Per1_Return */

# if defined (Rte_Runnable_Ap_StaMd_StaMd_Per1_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_StaMd_StaMd_Per1_Start
# endif
# if defined (Rte_Runnable_Ap_StaMd_StaMd_Per1_Start)
#  undef Rte_Runnable_Ap_StaMd_StaMd_Per1_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_StaMd_StaMd_Per1_Start(void);
# else
#  define Rte_Runnable_Ap_StaMd_StaMd_Per1_Start() ((void)(0))
# endif /* Rte_Runnable_Ap_StaMd_StaMd_Per1_Start */

# if defined (Rte_Runnable_Ap_StaMd_StaMd_Trns1_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_StaMd_StaMd_Trns1_Return
# endif
# if defined (Rte_Runnable_Ap_StaMd_StaMd_Trns1_Return)
#  undef Rte_Runnable_Ap_StaMd_StaMd_Trns1_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_StaMd_StaMd_Trns1_Return(void);
# else
#  define Rte_Runnable_Ap_StaMd_StaMd_Trns1_Return() ((void)(0))
# endif /* Rte_Runnable_Ap_StaMd_StaMd_Trns1_Return */

# if defined (Rte_Runnable_Ap_StaMd_StaMd_Trns1_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_StaMd_StaMd_Trns1_Start
# endif
# if defined (Rte_Runnable_Ap_StaMd_StaMd_Trns1_Start)
#  undef Rte_Runnable_Ap_StaMd_StaMd_Trns1_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_StaMd_StaMd_Trns1_Start(void);
# else
#  define Rte_Runnable_Ap_StaMd_StaMd_Trns1_Start() ((void)(0))
# endif /* Rte_Runnable_Ap_StaMd_StaMd_Trns1_Start */

# if defined (Rte_Runnable_Ap_StabilityComp2_StabilityComp2_Init1_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_StabilityComp2_StabilityComp2_Init1_Return
# endif
# if defined (Rte_Runnable_Ap_StabilityComp2_StabilityComp2_Init1_Return)
#  undef Rte_Runnable_Ap_StabilityComp2_StabilityComp2_Init1_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_StabilityComp2_StabilityComp2_Init1_Return(void);
# else
#  define Rte_Runnable_Ap_StabilityComp2_StabilityComp2_Init1_Return() ((void)(0))
# endif /* Rte_Runnable_Ap_StabilityComp2_StabilityComp2_Init1_Return */

# if defined (Rte_Runnable_Ap_StabilityComp2_StabilityComp2_Init1_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_StabilityComp2_StabilityComp2_Init1_Start
# endif
# if defined (Rte_Runnable_Ap_StabilityComp2_StabilityComp2_Init1_Start)
#  undef Rte_Runnable_Ap_StabilityComp2_StabilityComp2_Init1_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_StabilityComp2_StabilityComp2_Init1_Start(void);
# else
#  define Rte_Runnable_Ap_StabilityComp2_StabilityComp2_Init1_Start() ((void)(0))
# endif /* Rte_Runnable_Ap_StabilityComp2_StabilityComp2_Init1_Start */

# if defined (Rte_Runnable_Ap_StabilityComp2_StabilityComp2_Per1_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_StabilityComp2_StabilityComp2_Per1_Return
# endif
# if defined (Rte_Runnable_Ap_StabilityComp2_StabilityComp2_Per1_Return)
#  undef Rte_Runnable_Ap_StabilityComp2_StabilityComp2_Per1_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_StabilityComp2_StabilityComp2_Per1_Return(void);
# else
#  define Rte_Runnable_Ap_StabilityComp2_StabilityComp2_Per1_Return() ((void)(0))
# endif /* Rte_Runnable_Ap_StabilityComp2_StabilityComp2_Per1_Return */

# if defined (Rte_Runnable_Ap_StabilityComp2_StabilityComp2_Per1_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_StabilityComp2_StabilityComp2_Per1_Start
# endif
# if defined (Rte_Runnable_Ap_StabilityComp2_StabilityComp2_Per1_Start)
#  undef Rte_Runnable_Ap_StabilityComp2_StabilityComp2_Per1_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_StabilityComp2_StabilityComp2_Per1_Start(void);
# else
#  define Rte_Runnable_Ap_StabilityComp2_StabilityComp2_Per1_Start() ((void)(0))
# endif /* Rte_Runnable_Ap_StabilityComp2_StabilityComp2_Per1_Start */

# if defined (Rte_Runnable_Ap_StabilityComp_StabilityComp_Init1_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_StabilityComp_StabilityComp_Init1_Return
# endif
# if defined (Rte_Runnable_Ap_StabilityComp_StabilityComp_Init1_Return)
#  undef Rte_Runnable_Ap_StabilityComp_StabilityComp_Init1_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_StabilityComp_StabilityComp_Init1_Return(void);
# else
#  define Rte_Runnable_Ap_StabilityComp_StabilityComp_Init1_Return() ((void)(0))
# endif /* Rte_Runnable_Ap_StabilityComp_StabilityComp_Init1_Return */

# if defined (Rte_Runnable_Ap_StabilityComp_StabilityComp_Init1_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_StabilityComp_StabilityComp_Init1_Start
# endif
# if defined (Rte_Runnable_Ap_StabilityComp_StabilityComp_Init1_Start)
#  undef Rte_Runnable_Ap_StabilityComp_StabilityComp_Init1_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_StabilityComp_StabilityComp_Init1_Start(void);
# else
#  define Rte_Runnable_Ap_StabilityComp_StabilityComp_Init1_Start() ((void)(0))
# endif /* Rte_Runnable_Ap_StabilityComp_StabilityComp_Init1_Start */

# if defined (Rte_Runnable_Ap_StabilityComp_StabilityComp_Per1_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_StabilityComp_StabilityComp_Per1_Return
# endif
# if defined (Rte_Runnable_Ap_StabilityComp_StabilityComp_Per1_Return)
#  undef Rte_Runnable_Ap_StabilityComp_StabilityComp_Per1_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_StabilityComp_StabilityComp_Per1_Return(void);
# else
#  define Rte_Runnable_Ap_StabilityComp_StabilityComp_Per1_Return() ((void)(0))
# endif /* Rte_Runnable_Ap_StabilityComp_StabilityComp_Per1_Return */

# if defined (Rte_Runnable_Ap_StabilityComp_StabilityComp_Per1_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_StabilityComp_StabilityComp_Per1_Start
# endif
# if defined (Rte_Runnable_Ap_StabilityComp_StabilityComp_Per1_Start)
#  undef Rte_Runnable_Ap_StabilityComp_StabilityComp_Per1_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_StabilityComp_StabilityComp_Per1_Start(void);
# else
#  define Rte_Runnable_Ap_StabilityComp_StabilityComp_Per1_Start() ((void)(0))
# endif /* Rte_Runnable_Ap_StabilityComp_StabilityComp_Per1_Start */

# if defined (Rte_Runnable_Ap_StbCTO_StbCTO_Init1_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_StbCTO_StbCTO_Init1_Return
# endif
# if defined (Rte_Runnable_Ap_StbCTO_StbCTO_Init1_Return)
#  undef Rte_Runnable_Ap_StbCTO_StbCTO_Init1_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_StbCTO_StbCTO_Init1_Return(void);
# else
#  define Rte_Runnable_Ap_StbCTO_StbCTO_Init1_Return() ((void)(0))
# endif /* Rte_Runnable_Ap_StbCTO_StbCTO_Init1_Return */

# if defined (Rte_Runnable_Ap_StbCTO_StbCTO_Init1_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_StbCTO_StbCTO_Init1_Start
# endif
# if defined (Rte_Runnable_Ap_StbCTO_StbCTO_Init1_Start)
#  undef Rte_Runnable_Ap_StbCTO_StbCTO_Init1_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_StbCTO_StbCTO_Init1_Start(void);
# else
#  define Rte_Runnable_Ap_StbCTO_StbCTO_Init1_Start() ((void)(0))
# endif /* Rte_Runnable_Ap_StbCTO_StbCTO_Init1_Start */

# if defined (Rte_Runnable_Ap_StbCTO_StbCTO_Per1_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_StbCTO_StbCTO_Per1_Return
# endif
# if defined (Rte_Runnable_Ap_StbCTO_StbCTO_Per1_Return)
#  undef Rte_Runnable_Ap_StbCTO_StbCTO_Per1_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_StbCTO_StbCTO_Per1_Return(void);
# else
#  define Rte_Runnable_Ap_StbCTO_StbCTO_Per1_Return() ((void)(0))
# endif /* Rte_Runnable_Ap_StbCTO_StbCTO_Per1_Return */

# if defined (Rte_Runnable_Ap_StbCTO_StbCTO_Per1_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_StbCTO_StbCTO_Per1_Start
# endif
# if defined (Rte_Runnable_Ap_StbCTO_StbCTO_Per1_Start)
#  undef Rte_Runnable_Ap_StbCTO_StbCTO_Per1_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_StbCTO_StbCTO_Per1_Start(void);
# else
#  define Rte_Runnable_Ap_StbCTO_StbCTO_Per1_Start() ((void)(0))
# endif /* Rte_Runnable_Ap_StbCTO_StbCTO_Per1_Start */

# if defined (Rte_Runnable_Ap_ThrmlDutyCycle_ThrmlDutyCycle_Init1_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_ThrmlDutyCycle_ThrmlDutyCycle_Init1_Return
# endif
# if defined (Rte_Runnable_Ap_ThrmlDutyCycle_ThrmlDutyCycle_Init1_Return)
#  undef Rte_Runnable_Ap_ThrmlDutyCycle_ThrmlDutyCycle_Init1_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_ThrmlDutyCycle_ThrmlDutyCycle_Init1_Return(void);
# else
#  define Rte_Runnable_Ap_ThrmlDutyCycle_ThrmlDutyCycle_Init1_Return() ((void)(0))
# endif /* Rte_Runnable_Ap_ThrmlDutyCycle_ThrmlDutyCycle_Init1_Return */

# if defined (Rte_Runnable_Ap_ThrmlDutyCycle_ThrmlDutyCycle_Init1_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_ThrmlDutyCycle_ThrmlDutyCycle_Init1_Start
# endif
# if defined (Rte_Runnable_Ap_ThrmlDutyCycle_ThrmlDutyCycle_Init1_Start)
#  undef Rte_Runnable_Ap_ThrmlDutyCycle_ThrmlDutyCycle_Init1_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_ThrmlDutyCycle_ThrmlDutyCycle_Init1_Start(void);
# else
#  define Rte_Runnable_Ap_ThrmlDutyCycle_ThrmlDutyCycle_Init1_Start() ((void)(0))
# endif /* Rte_Runnable_Ap_ThrmlDutyCycle_ThrmlDutyCycle_Init1_Start */

# if defined (Rte_Runnable_Ap_ThrmlDutyCycle_ThrmlDutyCycle_Per1_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_ThrmlDutyCycle_ThrmlDutyCycle_Per1_Return
# endif
# if defined (Rte_Runnable_Ap_ThrmlDutyCycle_ThrmlDutyCycle_Per1_Return)
#  undef Rte_Runnable_Ap_ThrmlDutyCycle_ThrmlDutyCycle_Per1_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_ThrmlDutyCycle_ThrmlDutyCycle_Per1_Return(void);
# else
#  define Rte_Runnable_Ap_ThrmlDutyCycle_ThrmlDutyCycle_Per1_Return() ((void)(0))
# endif /* Rte_Runnable_Ap_ThrmlDutyCycle_ThrmlDutyCycle_Per1_Return */

# if defined (Rte_Runnable_Ap_ThrmlDutyCycle_ThrmlDutyCycle_Per1_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_ThrmlDutyCycle_ThrmlDutyCycle_Per1_Start
# endif
# if defined (Rte_Runnable_Ap_ThrmlDutyCycle_ThrmlDutyCycle_Per1_Start)
#  undef Rte_Runnable_Ap_ThrmlDutyCycle_ThrmlDutyCycle_Per1_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_ThrmlDutyCycle_ThrmlDutyCycle_Per1_Start(void);
# else
#  define Rte_Runnable_Ap_ThrmlDutyCycle_ThrmlDutyCycle_Per1_Start() ((void)(0))
# endif /* Rte_Runnable_Ap_ThrmlDutyCycle_ThrmlDutyCycle_Per1_Start */

# if defined (Rte_Runnable_Ap_TqRsDg_TqRsDg_Init1_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_TqRsDg_TqRsDg_Init1_Return
# endif
# if defined (Rte_Runnable_Ap_TqRsDg_TqRsDg_Init1_Return)
#  undef Rte_Runnable_Ap_TqRsDg_TqRsDg_Init1_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_TqRsDg_TqRsDg_Init1_Return(void);
# else
#  define Rte_Runnable_Ap_TqRsDg_TqRsDg_Init1_Return() ((void)(0))
# endif /* Rte_Runnable_Ap_TqRsDg_TqRsDg_Init1_Return */

# if defined (Rte_Runnable_Ap_TqRsDg_TqRsDg_Init1_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_TqRsDg_TqRsDg_Init1_Start
# endif
# if defined (Rte_Runnable_Ap_TqRsDg_TqRsDg_Init1_Start)
#  undef Rte_Runnable_Ap_TqRsDg_TqRsDg_Init1_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_TqRsDg_TqRsDg_Init1_Start(void);
# else
#  define Rte_Runnable_Ap_TqRsDg_TqRsDg_Init1_Start() ((void)(0))
# endif /* Rte_Runnable_Ap_TqRsDg_TqRsDg_Init1_Start */

# if defined (Rte_Runnable_Ap_TqRsDg_TqRsDg_Per1_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_TqRsDg_TqRsDg_Per1_Return
# endif
# if defined (Rte_Runnable_Ap_TqRsDg_TqRsDg_Per1_Return)
#  undef Rte_Runnable_Ap_TqRsDg_TqRsDg_Per1_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_TqRsDg_TqRsDg_Per1_Return(void);
# else
#  define Rte_Runnable_Ap_TqRsDg_TqRsDg_Per1_Return() ((void)(0))
# endif /* Rte_Runnable_Ap_TqRsDg_TqRsDg_Per1_Return */

# if defined (Rte_Runnable_Ap_TqRsDg_TqRsDg_Per1_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_TqRsDg_TqRsDg_Per1_Start
# endif
# if defined (Rte_Runnable_Ap_TqRsDg_TqRsDg_Per1_Start)
#  undef Rte_Runnable_Ap_TqRsDg_TqRsDg_Per1_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_TqRsDg_TqRsDg_Per1_Start(void);
# else
#  define Rte_Runnable_Ap_TqRsDg_TqRsDg_Per1_Start() ((void)(0))
# endif /* Rte_Runnable_Ap_TqRsDg_TqRsDg_Per1_Start */

# if defined (Rte_Runnable_Ap_TrqCanc_TrqCanc_Init_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_TrqCanc_TrqCanc_Init_Return
# endif
# if defined (Rte_Runnable_Ap_TrqCanc_TrqCanc_Init_Return)
#  undef Rte_Runnable_Ap_TrqCanc_TrqCanc_Init_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_TrqCanc_TrqCanc_Init_Return(void);
# else
#  define Rte_Runnable_Ap_TrqCanc_TrqCanc_Init_Return() ((void)(0))
# endif /* Rte_Runnable_Ap_TrqCanc_TrqCanc_Init_Return */

# if defined (Rte_Runnable_Ap_TrqCanc_TrqCanc_Init_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_TrqCanc_TrqCanc_Init_Start
# endif
# if defined (Rte_Runnable_Ap_TrqCanc_TrqCanc_Init_Start)
#  undef Rte_Runnable_Ap_TrqCanc_TrqCanc_Init_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_TrqCanc_TrqCanc_Init_Start(void);
# else
#  define Rte_Runnable_Ap_TrqCanc_TrqCanc_Init_Start() ((void)(0))
# endif /* Rte_Runnable_Ap_TrqCanc_TrqCanc_Init_Start */

# if defined (Rte_Runnable_Ap_TrqCanc_TrqCanc_Per1_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_TrqCanc_TrqCanc_Per1_Return
# endif
# if defined (Rte_Runnable_Ap_TrqCanc_TrqCanc_Per1_Return)
#  undef Rte_Runnable_Ap_TrqCanc_TrqCanc_Per1_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_TrqCanc_TrqCanc_Per1_Return(void);
# else
#  define Rte_Runnable_Ap_TrqCanc_TrqCanc_Per1_Return() ((void)(0))
# endif /* Rte_Runnable_Ap_TrqCanc_TrqCanc_Per1_Return */

# if defined (Rte_Runnable_Ap_TrqCanc_TrqCanc_Per1_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_TrqCanc_TrqCanc_Per1_Start
# endif
# if defined (Rte_Runnable_Ap_TrqCanc_TrqCanc_Per1_Start)
#  undef Rte_Runnable_Ap_TrqCanc_TrqCanc_Per1_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_TrqCanc_TrqCanc_Per1_Start(void);
# else
#  define Rte_Runnable_Ap_TrqCanc_TrqCanc_Per1_Start() ((void)(0))
# endif /* Rte_Runnable_Ap_TrqCanc_TrqCanc_Per1_Start */

# if defined (Rte_Runnable_Ap_TrqCanc_TrqCanc_Scom_ReadCogTrqCal_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_TrqCanc_TrqCanc_Scom_ReadCogTrqCal_Return
# endif
# if defined (Rte_Runnable_Ap_TrqCanc_TrqCanc_Scom_ReadCogTrqCal_Return)
#  undef Rte_Runnable_Ap_TrqCanc_TrqCanc_Scom_ReadCogTrqCal_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_TrqCanc_TrqCanc_Scom_ReadCogTrqCal_Return(P2VAR(CoggingCancTrq, AUTOMATIC, RTE_AP_TRQCANC_APPL_VAR) CogTrqCalPtr, UInt16 ID);
# else
#  define Rte_Runnable_Ap_TrqCanc_TrqCanc_Scom_ReadCogTrqCal_Return(arg1, arg2) ((void)(0))
# endif /* Rte_Runnable_Ap_TrqCanc_TrqCanc_Scom_ReadCogTrqCal_Return */

# if defined (Rte_Runnable_Ap_TrqCanc_TrqCanc_Scom_ReadCogTrqCal_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_TrqCanc_TrqCanc_Scom_ReadCogTrqCal_Start
# endif
# if defined (Rte_Runnable_Ap_TrqCanc_TrqCanc_Scom_ReadCogTrqCal_Start)
#  undef Rte_Runnable_Ap_TrqCanc_TrqCanc_Scom_ReadCogTrqCal_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_TrqCanc_TrqCanc_Scom_ReadCogTrqCal_Start(P2VAR(CoggingCancTrq, AUTOMATIC, RTE_AP_TRQCANC_APPL_VAR) CogTrqCalPtr, UInt16 ID);
# else
#  define Rte_Runnable_Ap_TrqCanc_TrqCanc_Scom_ReadCogTrqCal_Start(arg1, arg2) ((void)(0))
# endif /* Rte_Runnable_Ap_TrqCanc_TrqCanc_Scom_ReadCogTrqCal_Start */

# if defined (Rte_Runnable_Ap_TrqCanc_TrqCanc_Scom_SetCogTrqCal_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_TrqCanc_TrqCanc_Scom_SetCogTrqCal_Return
# endif
# if defined (Rte_Runnable_Ap_TrqCanc_TrqCanc_Scom_SetCogTrqCal_Return)
#  undef Rte_Runnable_Ap_TrqCanc_TrqCanc_Scom_SetCogTrqCal_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_TrqCanc_TrqCanc_Scom_SetCogTrqCal_Return(P2CONST(CoggingCancTrq, AUTOMATIC, RTE_AP_TRQCANC_APPL_DATA) CogTrqCalPtr, UInt16 ID);
# else
#  define Rte_Runnable_Ap_TrqCanc_TrqCanc_Scom_SetCogTrqCal_Return(arg1, arg2) ((void)(0))
# endif /* Rte_Runnable_Ap_TrqCanc_TrqCanc_Scom_SetCogTrqCal_Return */

# if defined (Rte_Runnable_Ap_TrqCanc_TrqCanc_Scom_SetCogTrqCal_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_TrqCanc_TrqCanc_Scom_SetCogTrqCal_Start
# endif
# if defined (Rte_Runnable_Ap_TrqCanc_TrqCanc_Scom_SetCogTrqCal_Start)
#  undef Rte_Runnable_Ap_TrqCanc_TrqCanc_Scom_SetCogTrqCal_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_TrqCanc_TrqCanc_Scom_SetCogTrqCal_Start(P2CONST(CoggingCancTrq, AUTOMATIC, RTE_AP_TRQCANC_APPL_DATA) CogTrqCalPtr, UInt16 ID);
# else
#  define Rte_Runnable_Ap_TrqCanc_TrqCanc_Scom_SetCogTrqCal_Start(arg1, arg2) ((void)(0))
# endif /* Rte_Runnable_Ap_TrqCanc_TrqCanc_Scom_SetCogTrqCal_Start */

# if defined (Rte_Runnable_Ap_TrqCmdScl_TrqCmdScl_Per1_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_TrqCmdScl_TrqCmdScl_Per1_Return
# endif
# if defined (Rte_Runnable_Ap_TrqCmdScl_TrqCmdScl_Per1_Return)
#  undef Rte_Runnable_Ap_TrqCmdScl_TrqCmdScl_Per1_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_TrqCmdScl_TrqCmdScl_Per1_Return(void);
# else
#  define Rte_Runnable_Ap_TrqCmdScl_TrqCmdScl_Per1_Return() ((void)(0))
# endif /* Rte_Runnable_Ap_TrqCmdScl_TrqCmdScl_Per1_Return */

# if defined (Rte_Runnable_Ap_TrqCmdScl_TrqCmdScl_Per1_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_TrqCmdScl_TrqCmdScl_Per1_Start
# endif
# if defined (Rte_Runnable_Ap_TrqCmdScl_TrqCmdScl_Per1_Start)
#  undef Rte_Runnable_Ap_TrqCmdScl_TrqCmdScl_Per1_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_TrqCmdScl_TrqCmdScl_Per1_Start(void);
# else
#  define Rte_Runnable_Ap_TrqCmdScl_TrqCmdScl_Per1_Start() ((void)(0))
# endif /* Rte_Runnable_Ap_TrqCmdScl_TrqCmdScl_Per1_Start */

# if defined (Rte_Runnable_Ap_TrqCmdScl_TrqCmdScl_SCom_Get_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_TrqCmdScl_TrqCmdScl_SCom_Get_Return
# endif
# if defined (Rte_Runnable_Ap_TrqCmdScl_TrqCmdScl_SCom_Get_Return)
#  undef Rte_Runnable_Ap_TrqCmdScl_TrqCmdScl_SCom_Get_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_TrqCmdScl_TrqCmdScl_SCom_Get_Return(P2VAR(Float, AUTOMATIC, RTE_AP_TRQCMDSCL_APPL_VAR) Par_f32);
# else
#  define Rte_Runnable_Ap_TrqCmdScl_TrqCmdScl_SCom_Get_Return(arg1) ((void)(0))
# endif /* Rte_Runnable_Ap_TrqCmdScl_TrqCmdScl_SCom_Get_Return */

# if defined (Rte_Runnable_Ap_TrqCmdScl_TrqCmdScl_SCom_Get_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_TrqCmdScl_TrqCmdScl_SCom_Get_Start
# endif
# if defined (Rte_Runnable_Ap_TrqCmdScl_TrqCmdScl_SCom_Get_Start)
#  undef Rte_Runnable_Ap_TrqCmdScl_TrqCmdScl_SCom_Get_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_TrqCmdScl_TrqCmdScl_SCom_Get_Start(P2VAR(Float, AUTOMATIC, RTE_AP_TRQCMDSCL_APPL_VAR) Par_f32);
# else
#  define Rte_Runnable_Ap_TrqCmdScl_TrqCmdScl_SCom_Get_Start(arg1) ((void)(0))
# endif /* Rte_Runnable_Ap_TrqCmdScl_TrqCmdScl_SCom_Get_Start */

# if defined (Rte_Runnable_Ap_TrqCmdScl_TrqCmdScl_SCom_Set_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_TrqCmdScl_TrqCmdScl_SCom_Set_Return
# endif
# if defined (Rte_Runnable_Ap_TrqCmdScl_TrqCmdScl_SCom_Set_Return)
#  undef Rte_Runnable_Ap_TrqCmdScl_TrqCmdScl_SCom_Set_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_TrqCmdScl_TrqCmdScl_SCom_Set_Return(Float Par_f32);
# else
#  define Rte_Runnable_Ap_TrqCmdScl_TrqCmdScl_SCom_Set_Return(arg1) ((void)(0))
# endif /* Rte_Runnable_Ap_TrqCmdScl_TrqCmdScl_SCom_Set_Return */

# if defined (Rte_Runnable_Ap_TrqCmdScl_TrqCmdScl_SCom_Set_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_TrqCmdScl_TrqCmdScl_SCom_Set_Start
# endif
# if defined (Rte_Runnable_Ap_TrqCmdScl_TrqCmdScl_SCom_Set_Start)
#  undef Rte_Runnable_Ap_TrqCmdScl_TrqCmdScl_SCom_Set_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_TrqCmdScl_TrqCmdScl_SCom_Set_Start(Float Par_f32);
# else
#  define Rte_Runnable_Ap_TrqCmdScl_TrqCmdScl_SCom_Set_Start(arg1) ((void)(0))
# endif /* Rte_Runnable_Ap_TrqCmdScl_TrqCmdScl_SCom_Set_Start */

# if defined (Rte_Runnable_Ap_TuningSelAuth_TuningSelAuth_Init1_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_TuningSelAuth_TuningSelAuth_Init1_Return
# endif
# if defined (Rte_Runnable_Ap_TuningSelAuth_TuningSelAuth_Init1_Return)
#  undef Rte_Runnable_Ap_TuningSelAuth_TuningSelAuth_Init1_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_TuningSelAuth_TuningSelAuth_Init1_Return(void);
# else
#  define Rte_Runnable_Ap_TuningSelAuth_TuningSelAuth_Init1_Return() ((void)(0))
# endif /* Rte_Runnable_Ap_TuningSelAuth_TuningSelAuth_Init1_Return */

# if defined (Rte_Runnable_Ap_TuningSelAuth_TuningSelAuth_Init1_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_TuningSelAuth_TuningSelAuth_Init1_Start
# endif
# if defined (Rte_Runnable_Ap_TuningSelAuth_TuningSelAuth_Init1_Start)
#  undef Rte_Runnable_Ap_TuningSelAuth_TuningSelAuth_Init1_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_TuningSelAuth_TuningSelAuth_Init1_Start(void);
# else
#  define Rte_Runnable_Ap_TuningSelAuth_TuningSelAuth_Init1_Start() ((void)(0))
# endif /* Rte_Runnable_Ap_TuningSelAuth_TuningSelAuth_Init1_Start */

# if defined (Rte_Runnable_Ap_TuningSelAuth_TuningSelAuth_Per1_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_TuningSelAuth_TuningSelAuth_Per1_Return
# endif
# if defined (Rte_Runnable_Ap_TuningSelAuth_TuningSelAuth_Per1_Return)
#  undef Rte_Runnable_Ap_TuningSelAuth_TuningSelAuth_Per1_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_TuningSelAuth_TuningSelAuth_Per1_Return(void);
# else
#  define Rte_Runnable_Ap_TuningSelAuth_TuningSelAuth_Per1_Return() ((void)(0))
# endif /* Rte_Runnable_Ap_TuningSelAuth_TuningSelAuth_Per1_Return */

# if defined (Rte_Runnable_Ap_TuningSelAuth_TuningSelAuth_Per1_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_TuningSelAuth_TuningSelAuth_Per1_Start
# endif
# if defined (Rte_Runnable_Ap_TuningSelAuth_TuningSelAuth_Per1_Start)
#  undef Rte_Runnable_Ap_TuningSelAuth_TuningSelAuth_Per1_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_TuningSelAuth_TuningSelAuth_Per1_Start(void);
# else
#  define Rte_Runnable_Ap_TuningSelAuth_TuningSelAuth_Per1_Start() ((void)(0))
# endif /* Rte_Runnable_Ap_TuningSelAuth_TuningSelAuth_Per1_Start */

# if defined (Rte_Runnable_Ap_VehPwrMd_VehPwrMd_Init1_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_VehPwrMd_VehPwrMd_Init1_Return
# endif
# if defined (Rte_Runnable_Ap_VehPwrMd_VehPwrMd_Init1_Return)
#  undef Rte_Runnable_Ap_VehPwrMd_VehPwrMd_Init1_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_VehPwrMd_VehPwrMd_Init1_Return(void);
# else
#  define Rte_Runnable_Ap_VehPwrMd_VehPwrMd_Init1_Return() ((void)(0))
# endif /* Rte_Runnable_Ap_VehPwrMd_VehPwrMd_Init1_Return */

# if defined (Rte_Runnable_Ap_VehPwrMd_VehPwrMd_Init1_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_VehPwrMd_VehPwrMd_Init1_Start
# endif
# if defined (Rte_Runnable_Ap_VehPwrMd_VehPwrMd_Init1_Start)
#  undef Rte_Runnable_Ap_VehPwrMd_VehPwrMd_Init1_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_VehPwrMd_VehPwrMd_Init1_Start(void);
# else
#  define Rte_Runnable_Ap_VehPwrMd_VehPwrMd_Init1_Start() ((void)(0))
# endif /* Rte_Runnable_Ap_VehPwrMd_VehPwrMd_Init1_Start */

# if defined (Rte_Runnable_Ap_VehPwrMd_VehPwrMd_Per1_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_VehPwrMd_VehPwrMd_Per1_Return
# endif
# if defined (Rte_Runnable_Ap_VehPwrMd_VehPwrMd_Per1_Return)
#  undef Rte_Runnable_Ap_VehPwrMd_VehPwrMd_Per1_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_VehPwrMd_VehPwrMd_Per1_Return(void);
# else
#  define Rte_Runnable_Ap_VehPwrMd_VehPwrMd_Per1_Return() ((void)(0))
# endif /* Rte_Runnable_Ap_VehPwrMd_VehPwrMd_Per1_Return */

# if defined (Rte_Runnable_Ap_VehPwrMd_VehPwrMd_Per1_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_VehPwrMd_VehPwrMd_Per1_Start
# endif
# if defined (Rte_Runnable_Ap_VehPwrMd_VehPwrMd_Per1_Start)
#  undef Rte_Runnable_Ap_VehPwrMd_VehPwrMd_Per1_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_VehPwrMd_VehPwrMd_Per1_Start(void);
# else
#  define Rte_Runnable_Ap_VehPwrMd_VehPwrMd_Per1_Start() ((void)(0))
# endif /* Rte_Runnable_Ap_VehPwrMd_VehPwrMd_Per1_Start */

# if defined (Rte_Runnable_Ap_VehSpdLmt_VehSpdLmt_Per1_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_VehSpdLmt_VehSpdLmt_Per1_Return
# endif
# if defined (Rte_Runnable_Ap_VehSpdLmt_VehSpdLmt_Per1_Return)
#  undef Rte_Runnable_Ap_VehSpdLmt_VehSpdLmt_Per1_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_VehSpdLmt_VehSpdLmt_Per1_Return(void);
# else
#  define Rte_Runnable_Ap_VehSpdLmt_VehSpdLmt_Per1_Return() ((void)(0))
# endif /* Rte_Runnable_Ap_VehSpdLmt_VehSpdLmt_Per1_Return */

# if defined (Rte_Runnable_Ap_VehSpdLmt_VehSpdLmt_Per1_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_VehSpdLmt_VehSpdLmt_Per1_Start
# endif
# if defined (Rte_Runnable_Ap_VehSpdLmt_VehSpdLmt_Per1_Start)
#  undef Rte_Runnable_Ap_VehSpdLmt_VehSpdLmt_Per1_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_VehSpdLmt_VehSpdLmt_Per1_Start(void);
# else
#  define Rte_Runnable_Ap_VehSpdLmt_VehSpdLmt_Per1_Start() ((void)(0))
# endif /* Rte_Runnable_Ap_VehSpdLmt_VehSpdLmt_Per1_Start */

# if defined (Rte_Runnable_Ap_WIRInputQual_WIRInputQual_Per1_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_WIRInputQual_WIRInputQual_Per1_Return
# endif
# if defined (Rte_Runnable_Ap_WIRInputQual_WIRInputQual_Per1_Return)
#  undef Rte_Runnable_Ap_WIRInputQual_WIRInputQual_Per1_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_WIRInputQual_WIRInputQual_Per1_Return(void);
# else
#  define Rte_Runnable_Ap_WIRInputQual_WIRInputQual_Per1_Return() ((void)(0))
# endif /* Rte_Runnable_Ap_WIRInputQual_WIRInputQual_Per1_Return */

# if defined (Rte_Runnable_Ap_WIRInputQual_WIRInputQual_Per1_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_WIRInputQual_WIRInputQual_Per1_Start
# endif
# if defined (Rte_Runnable_Ap_WIRInputQual_WIRInputQual_Per1_Start)
#  undef Rte_Runnable_Ap_WIRInputQual_WIRInputQual_Per1_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_WIRInputQual_WIRInputQual_Per1_Start(void);
# else
#  define Rte_Runnable_Ap_WIRInputQual_WIRInputQual_Per1_Start() ((void)(0))
# endif /* Rte_Runnable_Ap_WIRInputQual_WIRInputQual_Per1_Start */

# if defined (Rte_Runnable_Ap_WhlImbRej_WhlImbRej_Init1_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_WhlImbRej_WhlImbRej_Init1_Return
# endif
# if defined (Rte_Runnable_Ap_WhlImbRej_WhlImbRej_Init1_Return)
#  undef Rte_Runnable_Ap_WhlImbRej_WhlImbRej_Init1_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_WhlImbRej_WhlImbRej_Init1_Return(void);
# else
#  define Rte_Runnable_Ap_WhlImbRej_WhlImbRej_Init1_Return() ((void)(0))
# endif /* Rte_Runnable_Ap_WhlImbRej_WhlImbRej_Init1_Return */

# if defined (Rte_Runnable_Ap_WhlImbRej_WhlImbRej_Init1_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_WhlImbRej_WhlImbRej_Init1_Start
# endif
# if defined (Rte_Runnable_Ap_WhlImbRej_WhlImbRej_Init1_Start)
#  undef Rte_Runnable_Ap_WhlImbRej_WhlImbRej_Init1_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_WhlImbRej_WhlImbRej_Init1_Start(void);
# else
#  define Rte_Runnable_Ap_WhlImbRej_WhlImbRej_Init1_Start() ((void)(0))
# endif /* Rte_Runnable_Ap_WhlImbRej_WhlImbRej_Init1_Start */

# if defined (Rte_Runnable_Ap_WhlImbRej_WhlImbRej_Per1_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_WhlImbRej_WhlImbRej_Per1_Return
# endif
# if defined (Rte_Runnable_Ap_WhlImbRej_WhlImbRej_Per1_Return)
#  undef Rte_Runnable_Ap_WhlImbRej_WhlImbRej_Per1_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_WhlImbRej_WhlImbRej_Per1_Return(void);
# else
#  define Rte_Runnable_Ap_WhlImbRej_WhlImbRej_Per1_Return() ((void)(0))
# endif /* Rte_Runnable_Ap_WhlImbRej_WhlImbRej_Per1_Return */

# if defined (Rte_Runnable_Ap_WhlImbRej_WhlImbRej_Per1_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_WhlImbRej_WhlImbRej_Per1_Start
# endif
# if defined (Rte_Runnable_Ap_WhlImbRej_WhlImbRej_Per1_Start)
#  undef Rte_Runnable_Ap_WhlImbRej_WhlImbRej_Per1_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_WhlImbRej_WhlImbRej_Per1_Start(void);
# else
#  define Rte_Runnable_Ap_WhlImbRej_WhlImbRej_Per1_Start() ((void)(0))
# endif /* Rte_Runnable_Ap_WhlImbRej_WhlImbRej_Per1_Start */

# if defined (Rte_Runnable_Ap_WhlImbRej_WhlImbRej_Per2_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_WhlImbRej_WhlImbRej_Per2_Return
# endif
# if defined (Rte_Runnable_Ap_WhlImbRej_WhlImbRej_Per2_Return)
#  undef Rte_Runnable_Ap_WhlImbRej_WhlImbRej_Per2_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_WhlImbRej_WhlImbRej_Per2_Return(void);
# else
#  define Rte_Runnable_Ap_WhlImbRej_WhlImbRej_Per2_Return() ((void)(0))
# endif /* Rte_Runnable_Ap_WhlImbRej_WhlImbRej_Per2_Return */

# if defined (Rte_Runnable_Ap_WhlImbRej_WhlImbRej_Per2_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_WhlImbRej_WhlImbRej_Per2_Start
# endif
# if defined (Rte_Runnable_Ap_WhlImbRej_WhlImbRej_Per2_Start)
#  undef Rte_Runnable_Ap_WhlImbRej_WhlImbRej_Per2_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_WhlImbRej_WhlImbRej_Per2_Start(void);
# else
#  define Rte_Runnable_Ap_WhlImbRej_WhlImbRej_Per2_Start() ((void)(0))
# endif /* Rte_Runnable_Ap_WhlImbRej_WhlImbRej_Per2_Start */

# if defined (Rte_Runnable_Ap_WhlImbRej_WhlImbRej_Per3_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_WhlImbRej_WhlImbRej_Per3_Return
# endif
# if defined (Rte_Runnable_Ap_WhlImbRej_WhlImbRej_Per3_Return)
#  undef Rte_Runnable_Ap_WhlImbRej_WhlImbRej_Per3_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_WhlImbRej_WhlImbRej_Per3_Return(void);
# else
#  define Rte_Runnable_Ap_WhlImbRej_WhlImbRej_Per3_Return() ((void)(0))
# endif /* Rte_Runnable_Ap_WhlImbRej_WhlImbRej_Per3_Return */

# if defined (Rte_Runnable_Ap_WhlImbRej_WhlImbRej_Per3_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_WhlImbRej_WhlImbRej_Per3_Start
# endif
# if defined (Rte_Runnable_Ap_WhlImbRej_WhlImbRej_Per3_Start)
#  undef Rte_Runnable_Ap_WhlImbRej_WhlImbRej_Per3_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_WhlImbRej_WhlImbRej_Per3_Start(void);
# else
#  define Rte_Runnable_Ap_WhlImbRej_WhlImbRej_Per3_Start() ((void)(0))
# endif /* Rte_Runnable_Ap_WhlImbRej_WhlImbRej_Per3_Start */

# if defined (Rte_Runnable_Ap_WhlImbRej_WhlImbRej_SCom_GetWIRInfo_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_WhlImbRej_WhlImbRej_SCom_GetWIRInfo_Return
# endif
# if defined (Rte_Runnable_Ap_WhlImbRej_WhlImbRej_SCom_GetWIRInfo_Return)
#  undef Rte_Runnable_Ap_WhlImbRej_WhlImbRej_SCom_GetWIRInfo_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_WhlImbRej_WhlImbRej_SCom_GetWIRInfo_Return(P2VAR(UInt32, AUTOMATIC, RTE_AP_WHLIMBREJ_APPL_VAR) WIRCmpActRng1Ptr_Cnt_u32, P2VAR(UInt32, AUTOMATIC, RTE_AP_WHLIMBREJ_APPL_VAR) WIRCmpActRng2Ptr_Cnt_u32, P2VAR(UInt32, AUTOMATIC, RTE_AP_WHLIMBREJ_APPL_VAR) WIRCmpActRng3Ptr_Cnt_u32, P2VAR(UInt16, AUTOMATIC, RTE_AP_WHLIMBREJ_APPL_VAR) AlgFltStatusPtr_Cnt_b16, P2VAR(Float, AUTOMATIC, RTE_AP_WHLIMBREJ_APPL_VAR) WIRMaxCompPtr_Pct_f32);
# else
#  define Rte_Runnable_Ap_WhlImbRej_WhlImbRej_SCom_GetWIRInfo_Return(arg1, arg2, arg3, arg4, arg5) ((void)(0))
# endif /* Rte_Runnable_Ap_WhlImbRej_WhlImbRej_SCom_GetWIRInfo_Return */

# if defined (Rte_Runnable_Ap_WhlImbRej_WhlImbRej_SCom_GetWIRInfo_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_WhlImbRej_WhlImbRej_SCom_GetWIRInfo_Start
# endif
# if defined (Rte_Runnable_Ap_WhlImbRej_WhlImbRej_SCom_GetWIRInfo_Start)
#  undef Rte_Runnable_Ap_WhlImbRej_WhlImbRej_SCom_GetWIRInfo_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_WhlImbRej_WhlImbRej_SCom_GetWIRInfo_Start(P2VAR(UInt32, AUTOMATIC, RTE_AP_WHLIMBREJ_APPL_VAR) WIRCmpActRng1Ptr_Cnt_u32, P2VAR(UInt32, AUTOMATIC, RTE_AP_WHLIMBREJ_APPL_VAR) WIRCmpActRng2Ptr_Cnt_u32, P2VAR(UInt32, AUTOMATIC, RTE_AP_WHLIMBREJ_APPL_VAR) WIRCmpActRng3Ptr_Cnt_u32, P2VAR(UInt16, AUTOMATIC, RTE_AP_WHLIMBREJ_APPL_VAR) AlgFltStatusPtr_Cnt_b16, P2VAR(Float, AUTOMATIC, RTE_AP_WHLIMBREJ_APPL_VAR) WIRMaxCompPtr_Pct_f32);
# else
#  define Rte_Runnable_Ap_WhlImbRej_WhlImbRej_SCom_GetWIRInfo_Start(arg1, arg2, arg3, arg4, arg5) ((void)(0))
# endif /* Rte_Runnable_Ap_WhlImbRej_WhlImbRej_SCom_GetWIRInfo_Start */

# if defined (Rte_Runnable_Ap_ePWM2_ePWM2_Trns1_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_ePWM2_ePWM2_Trns1_Return
# endif
# if defined (Rte_Runnable_Ap_ePWM2_ePWM2_Trns1_Return)
#  undef Rte_Runnable_Ap_ePWM2_ePWM2_Trns1_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_ePWM2_ePWM2_Trns1_Return(void);
# else
#  define Rte_Runnable_Ap_ePWM2_ePWM2_Trns1_Return() ((void)(0))
# endif /* Rte_Runnable_Ap_ePWM2_ePWM2_Trns1_Return */

# if defined (Rte_Runnable_Ap_ePWM2_ePWM2_Trns1_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_ePWM2_ePWM2_Trns1_Start
# endif
# if defined (Rte_Runnable_Ap_ePWM2_ePWM2_Trns1_Start)
#  undef Rte_Runnable_Ap_ePWM2_ePWM2_Trns1_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_ePWM2_ePWM2_Trns1_Start(void);
# else
#  define Rte_Runnable_Ap_ePWM2_ePWM2_Trns1_Start() ((void)(0))
# endif /* Rte_Runnable_Ap_ePWM2_ePWM2_Trns1_Start */

# if defined (Rte_Runnable_Ap_ePWM2_ePWM2_Trns2_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_ePWM2_ePWM2_Trns2_Return
# endif
# if defined (Rte_Runnable_Ap_ePWM2_ePWM2_Trns2_Return)
#  undef Rte_Runnable_Ap_ePWM2_ePWM2_Trns2_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_ePWM2_ePWM2_Trns2_Return(void);
# else
#  define Rte_Runnable_Ap_ePWM2_ePWM2_Trns2_Return() ((void)(0))
# endif /* Rte_Runnable_Ap_ePWM2_ePWM2_Trns2_Return */

# if defined (Rte_Runnable_Ap_ePWM2_ePWM2_Trns2_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ap_ePWM2_ePWM2_Trns2_Start
# endif
# if defined (Rte_Runnable_Ap_ePWM2_ePWM2_Trns2_Start)
#  undef Rte_Runnable_Ap_ePWM2_ePWM2_Trns2_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ap_ePWM2_ePWM2_Trns2_Start(void);
# else
#  define Rte_Runnable_Ap_ePWM2_ePWM2_Trns2_Start() ((void)(0))
# endif /* Rte_Runnable_Ap_ePWM2_ePWM2_Trns2_Start */

# if defined (Rte_Runnable_CDD_CDDPorts_ApplyMtrElecMechPol_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_CDD_CDDPorts_ApplyMtrElecMechPol_Return
# endif
# if defined (Rte_Runnable_CDD_CDDPorts_ApplyMtrElecMechPol_Return)
#  undef Rte_Runnable_CDD_CDDPorts_ApplyMtrElecMechPol_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_CDD_CDDPorts_ApplyMtrElecMechPol_Return(SInt8 MtrElecMechPol_Cnt_s8);
# else
#  define Rte_Runnable_CDD_CDDPorts_ApplyMtrElecMechPol_Return(arg1) ((void)(0))
# endif /* Rte_Runnable_CDD_CDDPorts_ApplyMtrElecMechPol_Return */

# if defined (Rte_Runnable_CDD_CDDPorts_ApplyMtrElecMechPol_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_CDD_CDDPorts_ApplyMtrElecMechPol_Start
# endif
# if defined (Rte_Runnable_CDD_CDDPorts_ApplyMtrElecMechPol_Start)
#  undef Rte_Runnable_CDD_CDDPorts_ApplyMtrElecMechPol_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_CDD_CDDPorts_ApplyMtrElecMechPol_Start(SInt8 MtrElecMechPol_Cnt_s8);
# else
#  define Rte_Runnable_CDD_CDDPorts_ApplyMtrElecMechPol_Start(arg1) ((void)(0))
# endif /* Rte_Runnable_CDD_CDDPorts_ApplyMtrElecMechPol_Start */

# if defined (Rte_Runnable_CDD_CDDPorts_ClearPhsReasSum_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_CDD_CDDPorts_ClearPhsReasSum_Return
# endif
# if defined (Rte_Runnable_CDD_CDDPorts_ClearPhsReasSum_Return)
#  undef Rte_Runnable_CDD_CDDPorts_ClearPhsReasSum_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_CDD_CDDPorts_ClearPhsReasSum_Return(UInt16 DataAccessBfr_Cnt_T_u16);
# else
#  define Rte_Runnable_CDD_CDDPorts_ClearPhsReasSum_Return(arg1) ((void)(0))
# endif /* Rte_Runnable_CDD_CDDPorts_ClearPhsReasSum_Return */

# if defined (Rte_Runnable_CDD_CDDPorts_ClearPhsReasSum_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_CDD_CDDPorts_ClearPhsReasSum_Start
# endif
# if defined (Rte_Runnable_CDD_CDDPorts_ClearPhsReasSum_Start)
#  undef Rte_Runnable_CDD_CDDPorts_ClearPhsReasSum_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_CDD_CDDPorts_ClearPhsReasSum_Start(UInt16 DataAccessBfr_Cnt_T_u16);
# else
#  define Rte_Runnable_CDD_CDDPorts_ClearPhsReasSum_Start(arg1) ((void)(0))
# endif /* Rte_Runnable_CDD_CDDPorts_ClearPhsReasSum_Start */

# if defined (Rte_Runnable_CDD_Cdd_Mainfunction_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_CDD_Cdd_Mainfunction_Return
# endif
# if defined (Rte_Runnable_CDD_Cdd_Mainfunction_Return)
#  undef Rte_Runnable_CDD_Cdd_Mainfunction_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_CDD_Cdd_Mainfunction_Return(void);
# else
#  define Rte_Runnable_CDD_Cdd_Mainfunction_Return() ((void)(0))
# endif /* Rte_Runnable_CDD_Cdd_Mainfunction_Return */

# if defined (Rte_Runnable_CDD_Cdd_Mainfunction_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_CDD_Cdd_Mainfunction_Start
# endif
# if defined (Rte_Runnable_CDD_Cdd_Mainfunction_Start)
#  undef Rte_Runnable_CDD_Cdd_Mainfunction_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_CDD_Cdd_Mainfunction_Start(void);
# else
#  define Rte_Runnable_CDD_Cdd_Mainfunction_Start() ((void)(0))
# endif /* Rte_Runnable_CDD_Cdd_Mainfunction_Start */

# if defined (Rte_Runnable_Ccl_CclPollingTask_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ccl_CclPollingTask_Return
# endif
# if defined (Rte_Runnable_Ccl_CclPollingTask_Return)
#  undef Rte_Runnable_Ccl_CclPollingTask_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ccl_CclPollingTask_Return(void);
# else
#  define Rte_Runnable_Ccl_CclPollingTask_Return() ((void)(0))
# endif /* Rte_Runnable_Ccl_CclPollingTask_Return */

# if defined (Rte_Runnable_Ccl_CclPollingTask_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ccl_CclPollingTask_Start
# endif
# if defined (Rte_Runnable_Ccl_CclPollingTask_Start)
#  undef Rte_Runnable_Ccl_CclPollingTask_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ccl_CclPollingTask_Start(void);
# else
#  define Rte_Runnable_Ccl_CclPollingTask_Start() ((void)(0))
# endif /* Rte_Runnable_Ccl_CclPollingTask_Start */

# if defined (Rte_Runnable_Ccl_Ccl_10_0msTaskCont_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ccl_Ccl_10_0msTaskCont_Return
# endif
# if defined (Rte_Runnable_Ccl_Ccl_10_0msTaskCont_Return)
#  undef Rte_Runnable_Ccl_Ccl_10_0msTaskCont_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ccl_Ccl_10_0msTaskCont_Return(void);
# else
#  define Rte_Runnable_Ccl_Ccl_10_0msTaskCont_Return() ((void)(0))
# endif /* Rte_Runnable_Ccl_Ccl_10_0msTaskCont_Return */

# if defined (Rte_Runnable_Ccl_Ccl_10_0msTaskCont_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ccl_Ccl_10_0msTaskCont_Start
# endif
# if defined (Rte_Runnable_Ccl_Ccl_10_0msTaskCont_Start)
#  undef Rte_Runnable_Ccl_Ccl_10_0msTaskCont_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ccl_Ccl_10_0msTaskCont_Start(void);
# else
#  define Rte_Runnable_Ccl_Ccl_10_0msTaskCont_Start() ((void)(0))
# endif /* Rte_Runnable_Ccl_Ccl_10_0msTaskCont_Start */

# if defined (Rte_Runnable_Ccl_Ccl_10_2msTaskCont_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ccl_Ccl_10_2msTaskCont_Return
# endif
# if defined (Rte_Runnable_Ccl_Ccl_10_2msTaskCont_Return)
#  undef Rte_Runnable_Ccl_Ccl_10_2msTaskCont_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ccl_Ccl_10_2msTaskCont_Return(void);
# else
#  define Rte_Runnable_Ccl_Ccl_10_2msTaskCont_Return() ((void)(0))
# endif /* Rte_Runnable_Ccl_Ccl_10_2msTaskCont_Return */

# if defined (Rte_Runnable_Ccl_Ccl_10_2msTaskCont_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ccl_Ccl_10_2msTaskCont_Start
# endif
# if defined (Rte_Runnable_Ccl_Ccl_10_2msTaskCont_Start)
#  undef Rte_Runnable_Ccl_Ccl_10_2msTaskCont_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ccl_Ccl_10_2msTaskCont_Start(void);
# else
#  define Rte_Runnable_Ccl_Ccl_10_2msTaskCont_Start() ((void)(0))
# endif /* Rte_Runnable_Ccl_Ccl_10_2msTaskCont_Start */

# if defined (Rte_Runnable_Ccl_Ccl_2_0msTaskCont_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ccl_Ccl_2_0msTaskCont_Return
# endif
# if defined (Rte_Runnable_Ccl_Ccl_2_0msTaskCont_Return)
#  undef Rte_Runnable_Ccl_Ccl_2_0msTaskCont_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ccl_Ccl_2_0msTaskCont_Return(void);
# else
#  define Rte_Runnable_Ccl_Ccl_2_0msTaskCont_Return() ((void)(0))
# endif /* Rte_Runnable_Ccl_Ccl_2_0msTaskCont_Return */

# if defined (Rte_Runnable_Ccl_Ccl_2_0msTaskCont_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Ccl_Ccl_2_0msTaskCont_Start
# endif
# if defined (Rte_Runnable_Ccl_Ccl_2_0msTaskCont_Start)
#  undef Rte_Runnable_Ccl_Ccl_2_0msTaskCont_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Ccl_Ccl_2_0msTaskCont_Start(void);
# else
#  define Rte_Runnable_Ccl_Ccl_2_0msTaskCont_Start() ((void)(0))
# endif /* Rte_Runnable_Ccl_Ccl_2_0msTaskCont_Start */

# if defined (Rte_Runnable_Cd_uDiag_uDiagECC_Per_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Cd_uDiag_uDiagECC_Per_Return
# endif
# if defined (Rte_Runnable_Cd_uDiag_uDiagECC_Per_Return)
#  undef Rte_Runnable_Cd_uDiag_uDiagECC_Per_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Cd_uDiag_uDiagECC_Per_Return(void);
# else
#  define Rte_Runnable_Cd_uDiag_uDiagECC_Per_Return() ((void)(0))
# endif /* Rte_Runnable_Cd_uDiag_uDiagECC_Per_Return */

# if defined (Rte_Runnable_Cd_uDiag_uDiagECC_Per_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Cd_uDiag_uDiagECC_Per_Start
# endif
# if defined (Rte_Runnable_Cd_uDiag_uDiagECC_Per_Start)
#  undef Rte_Runnable_Cd_uDiag_uDiagECC_Per_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Cd_uDiag_uDiagECC_Per_Start(void);
# else
#  define Rte_Runnable_Cd_uDiag_uDiagECC_Per_Start() ((void)(0))
# endif /* Rte_Runnable_Cd_uDiag_uDiagECC_Per_Start */

# if defined (Rte_Runnable_Cd_uDiag_uDiagLossOfExec_Per2_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Cd_uDiag_uDiagLossOfExec_Per2_Return
# endif
# if defined (Rte_Runnable_Cd_uDiag_uDiagLossOfExec_Per2_Return)
#  undef Rte_Runnable_Cd_uDiag_uDiagLossOfExec_Per2_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Cd_uDiag_uDiagLossOfExec_Per2_Return(void);
# else
#  define Rte_Runnable_Cd_uDiag_uDiagLossOfExec_Per2_Return() ((void)(0))
# endif /* Rte_Runnable_Cd_uDiag_uDiagLossOfExec_Per2_Return */

# if defined (Rte_Runnable_Cd_uDiag_uDiagLossOfExec_Per2_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Cd_uDiag_uDiagLossOfExec_Per2_Start
# endif
# if defined (Rte_Runnable_Cd_uDiag_uDiagLossOfExec_Per2_Start)
#  undef Rte_Runnable_Cd_uDiag_uDiagLossOfExec_Per2_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Cd_uDiag_uDiagLossOfExec_Per2_Start(void);
# else
#  define Rte_Runnable_Cd_uDiag_uDiagLossOfExec_Per2_Start() ((void)(0))
# endif /* Rte_Runnable_Cd_uDiag_uDiagLossOfExec_Per2_Start */

# if defined (Rte_Runnable_Cd_uDiag_uDiagLossOfExec_Per3_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Cd_uDiag_uDiagLossOfExec_Per3_Return
# endif
# if defined (Rte_Runnable_Cd_uDiag_uDiagLossOfExec_Per3_Return)
#  undef Rte_Runnable_Cd_uDiag_uDiagLossOfExec_Per3_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Cd_uDiag_uDiagLossOfExec_Per3_Return(void);
# else
#  define Rte_Runnable_Cd_uDiag_uDiagLossOfExec_Per3_Return() ((void)(0))
# endif /* Rte_Runnable_Cd_uDiag_uDiagLossOfExec_Per3_Return */

# if defined (Rte_Runnable_Cd_uDiag_uDiagLossOfExec_Per3_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Cd_uDiag_uDiagLossOfExec_Per3_Start
# endif
# if defined (Rte_Runnable_Cd_uDiag_uDiagLossOfExec_Per3_Start)
#  undef Rte_Runnable_Cd_uDiag_uDiagLossOfExec_Per3_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Cd_uDiag_uDiagLossOfExec_Per3_Start(void);
# else
#  define Rte_Runnable_Cd_uDiag_uDiagLossOfExec_Per3_Start() ((void)(0))
# endif /* Rte_Runnable_Cd_uDiag_uDiagLossOfExec_Per3_Start */

# if defined (Rte_Runnable_Cd_uDiag_uDiagResetHandler_Init_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Cd_uDiag_uDiagResetHandler_Init_Return
# endif
# if defined (Rte_Runnable_Cd_uDiag_uDiagResetHandler_Init_Return)
#  undef Rte_Runnable_Cd_uDiag_uDiagResetHandler_Init_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Cd_uDiag_uDiagResetHandler_Init_Return(void);
# else
#  define Rte_Runnable_Cd_uDiag_uDiagResetHandler_Init_Return() ((void)(0))
# endif /* Rte_Runnable_Cd_uDiag_uDiagResetHandler_Init_Return */

# if defined (Rte_Runnable_Cd_uDiag_uDiagResetHandler_Init_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Cd_uDiag_uDiagResetHandler_Init_Start
# endif
# if defined (Rte_Runnable_Cd_uDiag_uDiagResetHandler_Init_Start)
#  undef Rte_Runnable_Cd_uDiag_uDiagResetHandler_Init_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Cd_uDiag_uDiagResetHandler_Init_Start(void);
# else
#  define Rte_Runnable_Cd_uDiag_uDiagResetHandler_Init_Start() ((void)(0))
# endif /* Rte_Runnable_Cd_uDiag_uDiagResetHandler_Init_Start */

# if defined (Rte_Runnable_Cd_uDiag_uDiagStaticRegs_Per_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Cd_uDiag_uDiagStaticRegs_Per_Return
# endif
# if defined (Rte_Runnable_Cd_uDiag_uDiagStaticRegs_Per_Return)
#  undef Rte_Runnable_Cd_uDiag_uDiagStaticRegs_Per_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Cd_uDiag_uDiagStaticRegs_Per_Return(void);
# else
#  define Rte_Runnable_Cd_uDiag_uDiagStaticRegs_Per_Return() ((void)(0))
# endif /* Rte_Runnable_Cd_uDiag_uDiagStaticRegs_Per_Return */

# if defined (Rte_Runnable_Cd_uDiag_uDiagStaticRegs_Per_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Cd_uDiag_uDiagStaticRegs_Per_Start
# endif
# if defined (Rte_Runnable_Cd_uDiag_uDiagStaticRegs_Per_Start)
#  undef Rte_Runnable_Cd_uDiag_uDiagStaticRegs_Per_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Cd_uDiag_uDiagStaticRegs_Per_Start(void);
# else
#  define Rte_Runnable_Cd_uDiag_uDiagStaticRegs_Per_Start() ((void)(0))
# endif /* Rte_Runnable_Cd_uDiag_uDiagStaticRegs_Per_Start */

# if defined (Rte_Runnable_Cd_uDiag_uDiagVIM_Per_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Cd_uDiag_uDiagVIM_Per_Return
# endif
# if defined (Rte_Runnable_Cd_uDiag_uDiagVIM_Per_Return)
#  undef Rte_Runnable_Cd_uDiag_uDiagVIM_Per_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Cd_uDiag_uDiagVIM_Per_Return(void);
# else
#  define Rte_Runnable_Cd_uDiag_uDiagVIM_Per_Return() ((void)(0))
# endif /* Rte_Runnable_Cd_uDiag_uDiagVIM_Per_Return */

# if defined (Rte_Runnable_Cd_uDiag_uDiagVIM_Per_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Cd_uDiag_uDiagVIM_Per_Start
# endif
# if defined (Rte_Runnable_Cd_uDiag_uDiagVIM_Per_Start)
#  undef Rte_Runnable_Cd_uDiag_uDiagVIM_Per_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Cd_uDiag_uDiagVIM_Per_Start(void);
# else
#  define Rte_Runnable_Cd_uDiag_uDiagVIM_Per_Start() ((void)(0))
# endif /* Rte_Runnable_Cd_uDiag_uDiagVIM_Per_Start */

# if defined (Rte_Runnable_Dem_Dem_MainFunction_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Dem_Dem_MainFunction_Return
# endif
# if defined (Rte_Runnable_Dem_Dem_MainFunction_Return)
#  undef Rte_Runnable_Dem_Dem_MainFunction_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Dem_Dem_MainFunction_Return(void);
# else
#  define Rte_Runnable_Dem_Dem_MainFunction_Return() ((void)(0))
# endif /* Rte_Runnable_Dem_Dem_MainFunction_Return */

# if defined (Rte_Runnable_Dem_Dem_MainFunction_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Dem_Dem_MainFunction_Start
# endif
# if defined (Rte_Runnable_Dem_Dem_MainFunction_Start)
#  undef Rte_Runnable_Dem_Dem_MainFunction_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Dem_Dem_MainFunction_Start(void);
# else
#  define Rte_Runnable_Dem_Dem_MainFunction_Start() ((void)(0))
# endif /* Rte_Runnable_Dem_Dem_MainFunction_Start */

# if defined (Rte_Runnable_Dem_GetDTCOfEvent_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Dem_GetDTCOfEvent_Return
# endif
# if defined (Rte_Runnable_Dem_GetDTCOfEvent_Return)
#  undef Rte_Runnable_Dem_GetDTCOfEvent_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Dem_GetDTCOfEvent_Return(Dem_EventIdType parg0, Dem_DTCKindType DTCKind, P2VAR(Dem_DTCType, AUTOMATIC, RTE_DEM_APPL_VAR) DTC);
# else
#  define Rte_Runnable_Dem_GetDTCOfEvent_Return(arg1, arg2, arg3) ((void)(0))
# endif /* Rte_Runnable_Dem_GetDTCOfEvent_Return */

# if defined (Rte_Runnable_Dem_GetDTCOfEvent_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Dem_GetDTCOfEvent_Start
# endif
# if defined (Rte_Runnable_Dem_GetDTCOfEvent_Start)
#  undef Rte_Runnable_Dem_GetDTCOfEvent_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Dem_GetDTCOfEvent_Start(Dem_EventIdType parg0, Dem_DTCKindType DTCKind, P2VAR(Dem_DTCType, AUTOMATIC, RTE_DEM_APPL_VAR) DTC);
# else
#  define Rte_Runnable_Dem_GetDTCOfEvent_Start(arg1, arg2, arg3) ((void)(0))
# endif /* Rte_Runnable_Dem_GetDTCOfEvent_Start */

# if defined (Rte_Runnable_Dem_GetEventFailed_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Dem_GetEventFailed_Return
# endif
# if defined (Rte_Runnable_Dem_GetEventFailed_Return)
#  undef Rte_Runnable_Dem_GetEventFailed_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Dem_GetEventFailed_Return(Dem_EventIdType parg0, P2VAR(Boolean, AUTOMATIC, RTE_DEM_APPL_VAR) Failed);
# else
#  define Rte_Runnable_Dem_GetEventFailed_Return(arg1, arg2) ((void)(0))
# endif /* Rte_Runnable_Dem_GetEventFailed_Return */

# if defined (Rte_Runnable_Dem_GetEventFailed_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Dem_GetEventFailed_Start
# endif
# if defined (Rte_Runnable_Dem_GetEventFailed_Start)
#  undef Rte_Runnable_Dem_GetEventFailed_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Dem_GetEventFailed_Start(Dem_EventIdType parg0, P2VAR(Boolean, AUTOMATIC, RTE_DEM_APPL_VAR) Failed);
# else
#  define Rte_Runnable_Dem_GetEventFailed_Start(arg1, arg2) ((void)(0))
# endif /* Rte_Runnable_Dem_GetEventFailed_Start */

# if defined (Rte_Runnable_Dem_GetEventStatus_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Dem_GetEventStatus_Return
# endif
# if defined (Rte_Runnable_Dem_GetEventStatus_Return)
#  undef Rte_Runnable_Dem_GetEventStatus_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Dem_GetEventStatus_Return(Dem_EventIdType parg0, P2VAR(Dem_EventStatusExtendedType, AUTOMATIC, RTE_DEM_APPL_VAR) EventStatus);
# else
#  define Rte_Runnable_Dem_GetEventStatus_Return(arg1, arg2) ((void)(0))
# endif /* Rte_Runnable_Dem_GetEventStatus_Return */

# if defined (Rte_Runnable_Dem_GetEventStatus_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Dem_GetEventStatus_Start
# endif
# if defined (Rte_Runnable_Dem_GetEventStatus_Start)
#  undef Rte_Runnable_Dem_GetEventStatus_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Dem_GetEventStatus_Start(Dem_EventIdType parg0, P2VAR(Dem_EventStatusExtendedType, AUTOMATIC, RTE_DEM_APPL_VAR) EventStatus);
# else
#  define Rte_Runnable_Dem_GetEventStatus_Start(arg1, arg2) ((void)(0))
# endif /* Rte_Runnable_Dem_GetEventStatus_Start */

# if defined (Rte_Runnable_Dem_GetEventTested_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Dem_GetEventTested_Return
# endif
# if defined (Rte_Runnable_Dem_GetEventTested_Return)
#  undef Rte_Runnable_Dem_GetEventTested_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Dem_GetEventTested_Return(Dem_EventIdType parg0, P2VAR(Boolean, AUTOMATIC, RTE_DEM_APPL_VAR) Failed);
# else
#  define Rte_Runnable_Dem_GetEventTested_Return(arg1, arg2) ((void)(0))
# endif /* Rte_Runnable_Dem_GetEventTested_Return */

# if defined (Rte_Runnable_Dem_GetEventTested_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Dem_GetEventTested_Start
# endif
# if defined (Rte_Runnable_Dem_GetEventTested_Start)
#  undef Rte_Runnable_Dem_GetEventTested_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Dem_GetEventTested_Start(Dem_EventIdType parg0, P2VAR(Boolean, AUTOMATIC, RTE_DEM_APPL_VAR) Failed);
# else
#  define Rte_Runnable_Dem_GetEventTested_Start(arg1, arg2) ((void)(0))
# endif /* Rte_Runnable_Dem_GetEventTested_Start */

# if defined (Rte_Runnable_Dem_GetFaultDetectionCounter_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Dem_GetFaultDetectionCounter_Return
# endif
# if defined (Rte_Runnable_Dem_GetFaultDetectionCounter_Return)
#  undef Rte_Runnable_Dem_GetFaultDetectionCounter_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Dem_GetFaultDetectionCounter_Return(Dem_EventIdType parg0, P2VAR(Dem_FaultDetectionCounterType, AUTOMATIC, RTE_DEM_APPL_VAR) EventIdFaultDetectionCounter);
# else
#  define Rte_Runnable_Dem_GetFaultDetectionCounter_Return(arg1, arg2) ((void)(0))
# endif /* Rte_Runnable_Dem_GetFaultDetectionCounter_Return */

# if defined (Rte_Runnable_Dem_GetFaultDetectionCounter_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Dem_GetFaultDetectionCounter_Start
# endif
# if defined (Rte_Runnable_Dem_GetFaultDetectionCounter_Start)
#  undef Rte_Runnable_Dem_GetFaultDetectionCounter_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Dem_GetFaultDetectionCounter_Start(Dem_EventIdType parg0, P2VAR(Dem_FaultDetectionCounterType, AUTOMATIC, RTE_DEM_APPL_VAR) EventIdFaultDetectionCounter);
# else
#  define Rte_Runnable_Dem_GetFaultDetectionCounter_Start(arg1, arg2) ((void)(0))
# endif /* Rte_Runnable_Dem_GetFaultDetectionCounter_Start */

# if defined (Rte_Runnable_Dem_GetIndicatorStatus_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Dem_GetIndicatorStatus_Return
# endif
# if defined (Rte_Runnable_Dem_GetIndicatorStatus_Return)
#  undef Rte_Runnable_Dem_GetIndicatorStatus_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Dem_GetIndicatorStatus_Return(UInt8 parg0, P2VAR(Dem_IndicatorStatusType, AUTOMATIC, RTE_DEM_APPL_VAR) IndicatorStatus);
# else
#  define Rte_Runnable_Dem_GetIndicatorStatus_Return(arg1, arg2) ((void)(0))
# endif /* Rte_Runnable_Dem_GetIndicatorStatus_Return */

# if defined (Rte_Runnable_Dem_GetIndicatorStatus_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Dem_GetIndicatorStatus_Start
# endif
# if defined (Rte_Runnable_Dem_GetIndicatorStatus_Start)
#  undef Rte_Runnable_Dem_GetIndicatorStatus_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Dem_GetIndicatorStatus_Start(UInt8 parg0, P2VAR(Dem_IndicatorStatusType, AUTOMATIC, RTE_DEM_APPL_VAR) IndicatorStatus);
# else
#  define Rte_Runnable_Dem_GetIndicatorStatus_Start(arg1, arg2) ((void)(0))
# endif /* Rte_Runnable_Dem_GetIndicatorStatus_Start */

# if defined (Rte_Runnable_Dem_ResetEventStatus_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Dem_ResetEventStatus_Return
# endif
# if defined (Rte_Runnable_Dem_ResetEventStatus_Return)
#  undef Rte_Runnable_Dem_ResetEventStatus_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Dem_ResetEventStatus_Return(Dem_EventIdType parg0);
# else
#  define Rte_Runnable_Dem_ResetEventStatus_Return(arg1) ((void)(0))
# endif /* Rte_Runnable_Dem_ResetEventStatus_Return */

# if defined (Rte_Runnable_Dem_ResetEventStatus_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Dem_ResetEventStatus_Start
# endif
# if defined (Rte_Runnable_Dem_ResetEventStatus_Start)
#  undef Rte_Runnable_Dem_ResetEventStatus_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Dem_ResetEventStatus_Start(Dem_EventIdType parg0);
# else
#  define Rte_Runnable_Dem_ResetEventStatus_Start(arg1) ((void)(0))
# endif /* Rte_Runnable_Dem_ResetEventStatus_Start */

# if defined (Rte_Runnable_Dem_SetEventStatus_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Dem_SetEventStatus_Return
# endif
# if defined (Rte_Runnable_Dem_SetEventStatus_Return)
#  undef Rte_Runnable_Dem_SetEventStatus_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Dem_SetEventStatus_Return(Dem_EventIdType parg0, Dem_EventStatusType EventStatus);
# else
#  define Rte_Runnable_Dem_SetEventStatus_Return(arg1, arg2) ((void)(0))
# endif /* Rte_Runnable_Dem_SetEventStatus_Return */

# if defined (Rte_Runnable_Dem_SetEventStatus_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Dem_SetEventStatus_Start
# endif
# if defined (Rte_Runnable_Dem_SetEventStatus_Start)
#  undef Rte_Runnable_Dem_SetEventStatus_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Dem_SetEventStatus_Start(Dem_EventIdType parg0, Dem_EventStatusType EventStatus);
# else
#  define Rte_Runnable_Dem_SetEventStatus_Start(arg1, arg2) ((void)(0))
# endif /* Rte_Runnable_Dem_SetEventStatus_Start */

# if defined (Rte_Runnable_Dem_SetOperationCycleState_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Dem_SetOperationCycleState_Return
# endif
# if defined (Rte_Runnable_Dem_SetOperationCycleState_Return)
#  undef Rte_Runnable_Dem_SetOperationCycleState_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Dem_SetOperationCycleState_Return(Dem_OperationCycleIdType parg0, Dem_OperationCycleStateType CycleState);
# else
#  define Rte_Runnable_Dem_SetOperationCycleState_Return(arg1, arg2) ((void)(0))
# endif /* Rte_Runnable_Dem_SetOperationCycleState_Return */

# if defined (Rte_Runnable_Dem_SetOperationCycleState_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Dem_SetOperationCycleState_Start
# endif
# if defined (Rte_Runnable_Dem_SetOperationCycleState_Start)
#  undef Rte_Runnable_Dem_SetOperationCycleState_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Dem_SetOperationCycleState_Start(Dem_OperationCycleIdType parg0, Dem_OperationCycleStateType CycleState);
# else
#  define Rte_Runnable_Dem_SetOperationCycleState_Start(arg1, arg2) ((void)(0))
# endif /* Rte_Runnable_Dem_SetOperationCycleState_Start */

# if defined (Rte_Runnable_EcuM_EcuM_MainFunction_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_EcuM_EcuM_MainFunction_Return
# endif
# if defined (Rte_Runnable_EcuM_EcuM_MainFunction_Return)
#  undef Rte_Runnable_EcuM_EcuM_MainFunction_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_EcuM_EcuM_MainFunction_Return(void);
# else
#  define Rte_Runnable_EcuM_EcuM_MainFunction_Return() ((void)(0))
# endif /* Rte_Runnable_EcuM_EcuM_MainFunction_Return */

# if defined (Rte_Runnable_EcuM_EcuM_MainFunction_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_EcuM_EcuM_MainFunction_Start
# endif
# if defined (Rte_Runnable_EcuM_EcuM_MainFunction_Start)
#  undef Rte_Runnable_EcuM_EcuM_MainFunction_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_EcuM_EcuM_MainFunction_Start(void);
# else
#  define Rte_Runnable_EcuM_EcuM_MainFunction_Start() ((void)(0))
# endif /* Rte_Runnable_EcuM_EcuM_MainFunction_Start */

# if defined (Rte_Runnable_EcuM_GetState_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_EcuM_GetState_Return
# endif
# if defined (Rte_Runnable_EcuM_GetState_Return)
#  undef Rte_Runnable_EcuM_GetState_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_EcuM_GetState_Return(EcuM_UserType parg0, P2VAR(EcuM_StateType, AUTOMATIC, RTE_ECUM_APPL_VAR) state);
# else
#  define Rte_Runnable_EcuM_GetState_Return(arg1, arg2) ((void)(0))
# endif /* Rte_Runnable_EcuM_GetState_Return */

# if defined (Rte_Runnable_EcuM_GetState_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_EcuM_GetState_Start
# endif
# if defined (Rte_Runnable_EcuM_GetState_Start)
#  undef Rte_Runnable_EcuM_GetState_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_EcuM_GetState_Start(EcuM_UserType parg0, P2VAR(EcuM_StateType, AUTOMATIC, RTE_ECUM_APPL_VAR) state);
# else
#  define Rte_Runnable_EcuM_GetState_Start(arg1, arg2) ((void)(0))
# endif /* Rte_Runnable_EcuM_GetState_Start */

# if defined (Rte_Runnable_EcuM_ReleasePOSTRUN_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_EcuM_ReleasePOSTRUN_Return
# endif
# if defined (Rte_Runnable_EcuM_ReleasePOSTRUN_Return)
#  undef Rte_Runnable_EcuM_ReleasePOSTRUN_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_EcuM_ReleasePOSTRUN_Return(EcuM_UserType parg0);
# else
#  define Rte_Runnable_EcuM_ReleasePOSTRUN_Return(arg1) ((void)(0))
# endif /* Rte_Runnable_EcuM_ReleasePOSTRUN_Return */

# if defined (Rte_Runnable_EcuM_ReleasePOSTRUN_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_EcuM_ReleasePOSTRUN_Start
# endif
# if defined (Rte_Runnable_EcuM_ReleasePOSTRUN_Start)
#  undef Rte_Runnable_EcuM_ReleasePOSTRUN_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_EcuM_ReleasePOSTRUN_Start(EcuM_UserType parg0);
# else
#  define Rte_Runnable_EcuM_ReleasePOSTRUN_Start(arg1) ((void)(0))
# endif /* Rte_Runnable_EcuM_ReleasePOSTRUN_Start */

# if defined (Rte_Runnable_EcuM_ReleaseRUN_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_EcuM_ReleaseRUN_Return
# endif
# if defined (Rte_Runnable_EcuM_ReleaseRUN_Return)
#  undef Rte_Runnable_EcuM_ReleaseRUN_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_EcuM_ReleaseRUN_Return(EcuM_UserType parg0);
# else
#  define Rte_Runnable_EcuM_ReleaseRUN_Return(arg1) ((void)(0))
# endif /* Rte_Runnable_EcuM_ReleaseRUN_Return */

# if defined (Rte_Runnable_EcuM_ReleaseRUN_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_EcuM_ReleaseRUN_Start
# endif
# if defined (Rte_Runnable_EcuM_ReleaseRUN_Start)
#  undef Rte_Runnable_EcuM_ReleaseRUN_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_EcuM_ReleaseRUN_Start(EcuM_UserType parg0);
# else
#  define Rte_Runnable_EcuM_ReleaseRUN_Start(arg1) ((void)(0))
# endif /* Rte_Runnable_EcuM_ReleaseRUN_Start */

# if defined (Rte_Runnable_EcuM_RequestPOSTRUN_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_EcuM_RequestPOSTRUN_Return
# endif
# if defined (Rte_Runnable_EcuM_RequestPOSTRUN_Return)
#  undef Rte_Runnable_EcuM_RequestPOSTRUN_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_EcuM_RequestPOSTRUN_Return(EcuM_UserType parg0);
# else
#  define Rte_Runnable_EcuM_RequestPOSTRUN_Return(arg1) ((void)(0))
# endif /* Rte_Runnable_EcuM_RequestPOSTRUN_Return */

# if defined (Rte_Runnable_EcuM_RequestPOSTRUN_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_EcuM_RequestPOSTRUN_Start
# endif
# if defined (Rte_Runnable_EcuM_RequestPOSTRUN_Start)
#  undef Rte_Runnable_EcuM_RequestPOSTRUN_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_EcuM_RequestPOSTRUN_Start(EcuM_UserType parg0);
# else
#  define Rte_Runnable_EcuM_RequestPOSTRUN_Start(arg1) ((void)(0))
# endif /* Rte_Runnable_EcuM_RequestPOSTRUN_Start */

# if defined (Rte_Runnable_EcuM_RequestRUN_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_EcuM_RequestRUN_Return
# endif
# if defined (Rte_Runnable_EcuM_RequestRUN_Return)
#  undef Rte_Runnable_EcuM_RequestRUN_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_EcuM_RequestRUN_Return(EcuM_UserType parg0);
# else
#  define Rte_Runnable_EcuM_RequestRUN_Return(arg1) ((void)(0))
# endif /* Rte_Runnable_EcuM_RequestRUN_Return */

# if defined (Rte_Runnable_EcuM_RequestRUN_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_EcuM_RequestRUN_Start
# endif
# if defined (Rte_Runnable_EcuM_RequestRUN_Start)
#  undef Rte_Runnable_EcuM_RequestRUN_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_EcuM_RequestRUN_Start(EcuM_UserType parg0);
# else
#  define Rte_Runnable_EcuM_RequestRUN_Start(arg1) ((void)(0))
# endif /* Rte_Runnable_EcuM_RequestRUN_Start */

# if defined (Rte_Runnable_IoHwAbstractionUsr_IoHwAb_FdbkPathAdc_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_IoHwAbstractionUsr_IoHwAb_FdbkPathAdc_Return
# endif
# if defined (Rte_Runnable_IoHwAbstractionUsr_IoHwAb_FdbkPathAdc_Return)
#  undef Rte_Runnable_IoHwAbstractionUsr_IoHwAb_FdbkPathAdc_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_IoHwAbstractionUsr_IoHwAb_FdbkPathAdc_Return(void);
# else
#  define Rte_Runnable_IoHwAbstractionUsr_IoHwAb_FdbkPathAdc_Return() ((void)(0))
# endif /* Rte_Runnable_IoHwAbstractionUsr_IoHwAb_FdbkPathAdc_Return */

# if defined (Rte_Runnable_IoHwAbstractionUsr_IoHwAb_FdbkPathAdc_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_IoHwAbstractionUsr_IoHwAb_FdbkPathAdc_Start
# endif
# if defined (Rte_Runnable_IoHwAbstractionUsr_IoHwAb_FdbkPathAdc_Start)
#  undef Rte_Runnable_IoHwAbstractionUsr_IoHwAb_FdbkPathAdc_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_IoHwAbstractionUsr_IoHwAb_FdbkPathAdc_Start(void);
# else
#  define Rte_Runnable_IoHwAbstractionUsr_IoHwAb_FdbkPathAdc_Start() ((void)(0))
# endif /* Rte_Runnable_IoHwAbstractionUsr_IoHwAb_FdbkPathAdc_Start */

# if defined (Rte_Runnable_IoHwAbstractionUsr_IoHwAb_FwdPathAdc_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_IoHwAbstractionUsr_IoHwAb_FwdPathAdc_Return
# endif
# if defined (Rte_Runnable_IoHwAbstractionUsr_IoHwAb_FwdPathAdc_Return)
#  undef Rte_Runnable_IoHwAbstractionUsr_IoHwAb_FwdPathAdc_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_IoHwAbstractionUsr_IoHwAb_FwdPathAdc_Return(void);
# else
#  define Rte_Runnable_IoHwAbstractionUsr_IoHwAb_FwdPathAdc_Return() ((void)(0))
# endif /* Rte_Runnable_IoHwAbstractionUsr_IoHwAb_FwdPathAdc_Return */

# if defined (Rte_Runnable_IoHwAbstractionUsr_IoHwAb_FwdPathAdc_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_IoHwAbstractionUsr_IoHwAb_FwdPathAdc_Start
# endif
# if defined (Rte_Runnable_IoHwAbstractionUsr_IoHwAb_FwdPathAdc_Start)
#  undef Rte_Runnable_IoHwAbstractionUsr_IoHwAb_FwdPathAdc_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_IoHwAbstractionUsr_IoHwAb_FwdPathAdc_Start(void);
# else
#  define Rte_Runnable_IoHwAbstractionUsr_IoHwAb_FwdPathAdc_Start() ((void)(0))
# endif /* Rte_Runnable_IoHwAbstractionUsr_IoHwAb_FwdPathAdc_Start */

# if defined (Rte_Runnable_IoHwAbstractionUsr_IoHwAb_Init_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_IoHwAbstractionUsr_IoHwAb_Init_Return
# endif
# if defined (Rte_Runnable_IoHwAbstractionUsr_IoHwAb_Init_Return)
#  undef Rte_Runnable_IoHwAbstractionUsr_IoHwAb_Init_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_IoHwAbstractionUsr_IoHwAb_Init_Return(void);
# else
#  define Rte_Runnable_IoHwAbstractionUsr_IoHwAb_Init_Return() ((void)(0))
# endif /* Rte_Runnable_IoHwAbstractionUsr_IoHwAb_Init_Return */

# if defined (Rte_Runnable_IoHwAbstractionUsr_IoHwAb_Init_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_IoHwAbstractionUsr_IoHwAb_Init_Start
# endif
# if defined (Rte_Runnable_IoHwAbstractionUsr_IoHwAb_Init_Start)
#  undef Rte_Runnable_IoHwAbstractionUsr_IoHwAb_Init_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_IoHwAbstractionUsr_IoHwAb_Init_Start(void);
# else
#  define Rte_Runnable_IoHwAbstractionUsr_IoHwAb_Init_Start() ((void)(0))
# endif /* Rte_Runnable_IoHwAbstractionUsr_IoHwAb_Init_Start */

# if defined (Rte_Runnable_IoHwAbstraction_IoHwAb_GetEpsEn_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_IoHwAbstraction_IoHwAb_GetEpsEn_Return
# endif
# if defined (Rte_Runnable_IoHwAbstraction_IoHwAb_GetEpsEn_Return)
#  undef Rte_Runnable_IoHwAbstraction_IoHwAb_GetEpsEn_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_IoHwAbstraction_IoHwAb_GetEpsEn_Return(P2VAR(IoHwAb_BoolType, AUTOMATIC, RTE_IOHWABSTRACTION_APPL_VAR) signal);
# else
#  define Rte_Runnable_IoHwAbstraction_IoHwAb_GetEpsEn_Return(arg1) ((void)(0))
# endif /* Rte_Runnable_IoHwAbstraction_IoHwAb_GetEpsEn_Return */

# if defined (Rte_Runnable_IoHwAbstraction_IoHwAb_GetEpsEn_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_IoHwAbstraction_IoHwAb_GetEpsEn_Start
# endif
# if defined (Rte_Runnable_IoHwAbstraction_IoHwAb_GetEpsEn_Start)
#  undef Rte_Runnable_IoHwAbstraction_IoHwAb_GetEpsEn_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_IoHwAbstraction_IoHwAb_GetEpsEn_Start(P2VAR(IoHwAb_BoolType, AUTOMATIC, RTE_IOHWABSTRACTION_APPL_VAR) signal);
# else
#  define Rte_Runnable_IoHwAbstraction_IoHwAb_GetEpsEn_Start(arg1) ((void)(0))
# endif /* Rte_Runnable_IoHwAbstraction_IoHwAb_GetEpsEn_Start */

# if defined (Rte_Runnable_IoHwAbstraction_IoHwAb_GetFetDrvCntl_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_IoHwAbstraction_IoHwAb_GetFetDrvCntl_Return
# endif
# if defined (Rte_Runnable_IoHwAbstraction_IoHwAb_GetFetDrvCntl_Return)
#  undef Rte_Runnable_IoHwAbstraction_IoHwAb_GetFetDrvCntl_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_IoHwAbstraction_IoHwAb_GetFetDrvCntl_Return(P2VAR(IoHwAb_BoolType, AUTOMATIC, RTE_IOHWABSTRACTION_APPL_VAR) signal);
# else
#  define Rte_Runnable_IoHwAbstraction_IoHwAb_GetFetDrvCntl_Return(arg1) ((void)(0))
# endif /* Rte_Runnable_IoHwAbstraction_IoHwAb_GetFetDrvCntl_Return */

# if defined (Rte_Runnable_IoHwAbstraction_IoHwAb_GetFetDrvCntl_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_IoHwAbstraction_IoHwAb_GetFetDrvCntl_Start
# endif
# if defined (Rte_Runnable_IoHwAbstraction_IoHwAb_GetFetDrvCntl_Start)
#  undef Rte_Runnable_IoHwAbstraction_IoHwAb_GetFetDrvCntl_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_IoHwAbstraction_IoHwAb_GetFetDrvCntl_Start(P2VAR(IoHwAb_BoolType, AUTOMATIC, RTE_IOHWABSTRACTION_APPL_VAR) signal);
# else
#  define Rte_Runnable_IoHwAbstraction_IoHwAb_GetFetDrvCntl_Start(arg1) ((void)(0))
# endif /* Rte_Runnable_IoHwAbstraction_IoHwAb_GetFetDrvCntl_Start */

# if defined (Rte_Runnable_IoHwAbstraction_IoHwAb_GetFetDrvReset_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_IoHwAbstraction_IoHwAb_GetFetDrvReset_Return
# endif
# if defined (Rte_Runnable_IoHwAbstraction_IoHwAb_GetFetDrvReset_Return)
#  undef Rte_Runnable_IoHwAbstraction_IoHwAb_GetFetDrvReset_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_IoHwAbstraction_IoHwAb_GetFetDrvReset_Return(P2VAR(IoHwAb_BoolType, AUTOMATIC, RTE_IOHWABSTRACTION_APPL_VAR) signal);
# else
#  define Rte_Runnable_IoHwAbstraction_IoHwAb_GetFetDrvReset_Return(arg1) ((void)(0))
# endif /* Rte_Runnable_IoHwAbstraction_IoHwAb_GetFetDrvReset_Return */

# if defined (Rte_Runnable_IoHwAbstraction_IoHwAb_GetFetDrvReset_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_IoHwAbstraction_IoHwAb_GetFetDrvReset_Start
# endif
# if defined (Rte_Runnable_IoHwAbstraction_IoHwAb_GetFetDrvReset_Start)
#  undef Rte_Runnable_IoHwAbstraction_IoHwAb_GetFetDrvReset_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_IoHwAbstraction_IoHwAb_GetFetDrvReset_Start(P2VAR(IoHwAb_BoolType, AUTOMATIC, RTE_IOHWABSTRACTION_APPL_VAR) signal);
# else
#  define Rte_Runnable_IoHwAbstraction_IoHwAb_GetFetDrvReset_Start(arg1) ((void)(0))
# endif /* Rte_Runnable_IoHwAbstraction_IoHwAb_GetFetDrvReset_Start */

# if defined (Rte_Runnable_IoHwAbstraction_IoHwAb_GetFetFlt1Data_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_IoHwAbstraction_IoHwAb_GetFetFlt1Data_Return
# endif
# if defined (Rte_Runnable_IoHwAbstraction_IoHwAb_GetFetFlt1Data_Return)
#  undef Rte_Runnable_IoHwAbstraction_IoHwAb_GetFetFlt1Data_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_IoHwAbstraction_IoHwAb_GetFetFlt1Data_Return(P2VAR(IoHwAb_BoolType, AUTOMATIC, RTE_IOHWABSTRACTION_APPL_VAR) signal);
# else
#  define Rte_Runnable_IoHwAbstraction_IoHwAb_GetFetFlt1Data_Return(arg1) ((void)(0))
# endif /* Rte_Runnable_IoHwAbstraction_IoHwAb_GetFetFlt1Data_Return */

# if defined (Rte_Runnable_IoHwAbstraction_IoHwAb_GetFetFlt1Data_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_IoHwAbstraction_IoHwAb_GetFetFlt1Data_Start
# endif
# if defined (Rte_Runnable_IoHwAbstraction_IoHwAb_GetFetFlt1Data_Start)
#  undef Rte_Runnable_IoHwAbstraction_IoHwAb_GetFetFlt1Data_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_IoHwAbstraction_IoHwAb_GetFetFlt1Data_Start(P2VAR(IoHwAb_BoolType, AUTOMATIC, RTE_IOHWABSTRACTION_APPL_VAR) signal);
# else
#  define Rte_Runnable_IoHwAbstraction_IoHwAb_GetFetFlt1Data_Start(arg1) ((void)(0))
# endif /* Rte_Runnable_IoHwAbstraction_IoHwAb_GetFetFlt1Data_Start */

# if defined (Rte_Runnable_IoHwAbstraction_IoHwAb_GetFetFlt2Clk_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_IoHwAbstraction_IoHwAb_GetFetFlt2Clk_Return
# endif
# if defined (Rte_Runnable_IoHwAbstraction_IoHwAb_GetFetFlt2Clk_Return)
#  undef Rte_Runnable_IoHwAbstraction_IoHwAb_GetFetFlt2Clk_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_IoHwAbstraction_IoHwAb_GetFetFlt2Clk_Return(P2VAR(IoHwAb_BoolType, AUTOMATIC, RTE_IOHWABSTRACTION_APPL_VAR) signal);
# else
#  define Rte_Runnable_IoHwAbstraction_IoHwAb_GetFetFlt2Clk_Return(arg1) ((void)(0))
# endif /* Rte_Runnable_IoHwAbstraction_IoHwAb_GetFetFlt2Clk_Return */

# if defined (Rte_Runnable_IoHwAbstraction_IoHwAb_GetFetFlt2Clk_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_IoHwAbstraction_IoHwAb_GetFetFlt2Clk_Start
# endif
# if defined (Rte_Runnable_IoHwAbstraction_IoHwAb_GetFetFlt2Clk_Start)
#  undef Rte_Runnable_IoHwAbstraction_IoHwAb_GetFetFlt2Clk_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_IoHwAbstraction_IoHwAb_GetFetFlt2Clk_Start(P2VAR(IoHwAb_BoolType, AUTOMATIC, RTE_IOHWABSTRACTION_APPL_VAR) signal);
# else
#  define Rte_Runnable_IoHwAbstraction_IoHwAb_GetFetFlt2Clk_Start(arg1) ((void)(0))
# endif /* Rte_Runnable_IoHwAbstraction_IoHwAb_GetFetFlt2Clk_Start */

# if defined (Rte_Runnable_IoHwAbstraction_IoHwAb_GetOvrVoltFdbk_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_IoHwAbstraction_IoHwAb_GetOvrVoltFdbk_Return
# endif
# if defined (Rte_Runnable_IoHwAbstraction_IoHwAb_GetOvrVoltFdbk_Return)
#  undef Rte_Runnable_IoHwAbstraction_IoHwAb_GetOvrVoltFdbk_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_IoHwAbstraction_IoHwAb_GetOvrVoltFdbk_Return(P2VAR(IoHwAb_BoolType, AUTOMATIC, RTE_IOHWABSTRACTION_APPL_VAR) signal);
# else
#  define Rte_Runnable_IoHwAbstraction_IoHwAb_GetOvrVoltFdbk_Return(arg1) ((void)(0))
# endif /* Rte_Runnable_IoHwAbstraction_IoHwAb_GetOvrVoltFdbk_Return */

# if defined (Rte_Runnable_IoHwAbstraction_IoHwAb_GetOvrVoltFdbk_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_IoHwAbstraction_IoHwAb_GetOvrVoltFdbk_Start
# endif
# if defined (Rte_Runnable_IoHwAbstraction_IoHwAb_GetOvrVoltFdbk_Start)
#  undef Rte_Runnable_IoHwAbstraction_IoHwAb_GetOvrVoltFdbk_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_IoHwAbstraction_IoHwAb_GetOvrVoltFdbk_Start(P2VAR(IoHwAb_BoolType, AUTOMATIC, RTE_IOHWABSTRACTION_APPL_VAR) signal);
# else
#  define Rte_Runnable_IoHwAbstraction_IoHwAb_GetOvrVoltFdbk_Start(arg1) ((void)(0))
# endif /* Rte_Runnable_IoHwAbstraction_IoHwAb_GetOvrVoltFdbk_Start */

# if defined (Rte_Runnable_IoHwAbstraction_IoHwAb_GetPwrSwitchEn_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_IoHwAbstraction_IoHwAb_GetPwrSwitchEn_Return
# endif
# if defined (Rte_Runnable_IoHwAbstraction_IoHwAb_GetPwrSwitchEn_Return)
#  undef Rte_Runnable_IoHwAbstraction_IoHwAb_GetPwrSwitchEn_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_IoHwAbstraction_IoHwAb_GetPwrSwitchEn_Return(P2VAR(IoHwAb_BoolType, AUTOMATIC, RTE_IOHWABSTRACTION_APPL_VAR) signal);
# else
#  define Rte_Runnable_IoHwAbstraction_IoHwAb_GetPwrSwitchEn_Return(arg1) ((void)(0))
# endif /* Rte_Runnable_IoHwAbstraction_IoHwAb_GetPwrSwitchEn_Return */

# if defined (Rte_Runnable_IoHwAbstraction_IoHwAb_GetPwrSwitchEn_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_IoHwAbstraction_IoHwAb_GetPwrSwitchEn_Start
# endif
# if defined (Rte_Runnable_IoHwAbstraction_IoHwAb_GetPwrSwitchEn_Start)
#  undef Rte_Runnable_IoHwAbstraction_IoHwAb_GetPwrSwitchEn_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_IoHwAbstraction_IoHwAb_GetPwrSwitchEn_Start(P2VAR(IoHwAb_BoolType, AUTOMATIC, RTE_IOHWABSTRACTION_APPL_VAR) signal);
# else
#  define Rte_Runnable_IoHwAbstraction_IoHwAb_GetPwrSwitchEn_Start(arg1) ((void)(0))
# endif /* Rte_Runnable_IoHwAbstraction_IoHwAb_GetPwrSwitchEn_Start */

# if defined (Rte_Runnable_IoHwAbstraction_IoHwAb_GetSysFault2_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_IoHwAbstraction_IoHwAb_GetSysFault2_Return
# endif
# if defined (Rte_Runnable_IoHwAbstraction_IoHwAb_GetSysFault2_Return)
#  undef Rte_Runnable_IoHwAbstraction_IoHwAb_GetSysFault2_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_IoHwAbstraction_IoHwAb_GetSysFault2_Return(P2VAR(IoHwAb_BoolType, AUTOMATIC, RTE_IOHWABSTRACTION_APPL_VAR) signal);
# else
#  define Rte_Runnable_IoHwAbstraction_IoHwAb_GetSysFault2_Return(arg1) ((void)(0))
# endif /* Rte_Runnable_IoHwAbstraction_IoHwAb_GetSysFault2_Return */

# if defined (Rte_Runnable_IoHwAbstraction_IoHwAb_GetSysFault2_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_IoHwAbstraction_IoHwAb_GetSysFault2_Start
# endif
# if defined (Rte_Runnable_IoHwAbstraction_IoHwAb_GetSysFault2_Start)
#  undef Rte_Runnable_IoHwAbstraction_IoHwAb_GetSysFault2_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_IoHwAbstraction_IoHwAb_GetSysFault2_Start(P2VAR(IoHwAb_BoolType, AUTOMATIC, RTE_IOHWABSTRACTION_APPL_VAR) signal);
# else
#  define Rte_Runnable_IoHwAbstraction_IoHwAb_GetSysFault2_Start(arg1) ((void)(0))
# endif /* Rte_Runnable_IoHwAbstraction_IoHwAb_GetSysFault2_Start */

# if defined (Rte_Runnable_IoHwAbstraction_IoHwAb_MainFunctionDummy_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_IoHwAbstraction_IoHwAb_MainFunctionDummy_Return
# endif
# if defined (Rte_Runnable_IoHwAbstraction_IoHwAb_MainFunctionDummy_Return)
#  undef Rte_Runnable_IoHwAbstraction_IoHwAb_MainFunctionDummy_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_IoHwAbstraction_IoHwAb_MainFunctionDummy_Return(void);
# else
#  define Rte_Runnable_IoHwAbstraction_IoHwAb_MainFunctionDummy_Return() ((void)(0))
# endif /* Rte_Runnable_IoHwAbstraction_IoHwAb_MainFunctionDummy_Return */

# if defined (Rte_Runnable_IoHwAbstraction_IoHwAb_MainFunctionDummy_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_IoHwAbstraction_IoHwAb_MainFunctionDummy_Start
# endif
# if defined (Rte_Runnable_IoHwAbstraction_IoHwAb_MainFunctionDummy_Start)
#  undef Rte_Runnable_IoHwAbstraction_IoHwAb_MainFunctionDummy_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_IoHwAbstraction_IoHwAb_MainFunctionDummy_Start(void);
# else
#  define Rte_Runnable_IoHwAbstraction_IoHwAb_MainFunctionDummy_Start() ((void)(0))
# endif /* Rte_Runnable_IoHwAbstraction_IoHwAb_MainFunctionDummy_Start */

# if defined (Rte_Runnable_IoHwAbstraction_IoHwAb_OP_GET_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_IoHwAbstraction_IoHwAb_OP_GET_Return
# endif
# if defined (Rte_Runnable_IoHwAbstraction_IoHwAb_OP_GET_Return)
#  undef Rte_Runnable_IoHwAbstraction_IoHwAb_OP_GET_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_IoHwAbstraction_IoHwAb_OP_GET_Return(P2VAR(IoHwAb_BoolType, AUTOMATIC, RTE_IOHWABSTRACTION_APPL_VAR) signal);
# else
#  define Rte_Runnable_IoHwAbstraction_IoHwAb_OP_GET_Return(arg1) ((void)(0))
# endif /* Rte_Runnable_IoHwAbstraction_IoHwAb_OP_GET_Return */

# if defined (Rte_Runnable_IoHwAbstraction_IoHwAb_OP_GET_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_IoHwAbstraction_IoHwAb_OP_GET_Start
# endif
# if defined (Rte_Runnable_IoHwAbstraction_IoHwAb_OP_GET_Start)
#  undef Rte_Runnable_IoHwAbstraction_IoHwAb_OP_GET_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_IoHwAbstraction_IoHwAb_OP_GET_Start(P2VAR(IoHwAb_BoolType, AUTOMATIC, RTE_IOHWABSTRACTION_APPL_VAR) signal);
# else
#  define Rte_Runnable_IoHwAbstraction_IoHwAb_OP_GET_Start(arg1) ((void)(0))
# endif /* Rte_Runnable_IoHwAbstraction_IoHwAb_OP_GET_Start */

# if defined (Rte_Runnable_IoHwAbstraction_IoHwAb_OP_SET_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_IoHwAbstraction_IoHwAb_OP_SET_Return
# endif
# if defined (Rte_Runnable_IoHwAbstraction_IoHwAb_OP_SET_Return)
#  undef Rte_Runnable_IoHwAbstraction_IoHwAb_OP_SET_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_IoHwAbstraction_IoHwAb_OP_SET_Return(IoHwAb_BoolType signal);
# else
#  define Rte_Runnable_IoHwAbstraction_IoHwAb_OP_SET_Return(arg1) ((void)(0))
# endif /* Rte_Runnable_IoHwAbstraction_IoHwAb_OP_SET_Return */

# if defined (Rte_Runnable_IoHwAbstraction_IoHwAb_OP_SET_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_IoHwAbstraction_IoHwAb_OP_SET_Start
# endif
# if defined (Rte_Runnable_IoHwAbstraction_IoHwAb_OP_SET_Start)
#  undef Rte_Runnable_IoHwAbstraction_IoHwAb_OP_SET_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_IoHwAbstraction_IoHwAb_OP_SET_Start(IoHwAb_BoolType signal);
# else
#  define Rte_Runnable_IoHwAbstraction_IoHwAb_OP_SET_Start(arg1) ((void)(0))
# endif /* Rte_Runnable_IoHwAbstraction_IoHwAb_OP_SET_Start */

# if defined (Rte_Runnable_IoHwAbstraction_IoHwAb_SetFetDrvReset_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_IoHwAbstraction_IoHwAb_SetFetDrvReset_Return
# endif
# if defined (Rte_Runnable_IoHwAbstraction_IoHwAb_SetFetDrvReset_Return)
#  undef Rte_Runnable_IoHwAbstraction_IoHwAb_SetFetDrvReset_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_IoHwAbstraction_IoHwAb_SetFetDrvReset_Return(IoHwAb_BoolType signal);
# else
#  define Rte_Runnable_IoHwAbstraction_IoHwAb_SetFetDrvReset_Return(arg1) ((void)(0))
# endif /* Rte_Runnable_IoHwAbstraction_IoHwAb_SetFetDrvReset_Return */

# if defined (Rte_Runnable_IoHwAbstraction_IoHwAb_SetFetDrvReset_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_IoHwAbstraction_IoHwAb_SetFetDrvReset_Start
# endif
# if defined (Rte_Runnable_IoHwAbstraction_IoHwAb_SetFetDrvReset_Start)
#  undef Rte_Runnable_IoHwAbstraction_IoHwAb_SetFetDrvReset_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_IoHwAbstraction_IoHwAb_SetFetDrvReset_Start(IoHwAb_BoolType signal);
# else
#  define Rte_Runnable_IoHwAbstraction_IoHwAb_SetFetDrvReset_Start(arg1) ((void)(0))
# endif /* Rte_Runnable_IoHwAbstraction_IoHwAb_SetFetDrvReset_Start */

# if defined (Rte_Runnable_IoHwAbstraction_IoHwAb_SetFetFlt2Clk_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_IoHwAbstraction_IoHwAb_SetFetFlt2Clk_Return
# endif
# if defined (Rte_Runnable_IoHwAbstraction_IoHwAb_SetFetFlt2Clk_Return)
#  undef Rte_Runnable_IoHwAbstraction_IoHwAb_SetFetFlt2Clk_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_IoHwAbstraction_IoHwAb_SetFetFlt2Clk_Return(IoHwAb_BoolType signal);
# else
#  define Rte_Runnable_IoHwAbstraction_IoHwAb_SetFetFlt2Clk_Return(arg1) ((void)(0))
# endif /* Rte_Runnable_IoHwAbstraction_IoHwAb_SetFetFlt2Clk_Return */

# if defined (Rte_Runnable_IoHwAbstraction_IoHwAb_SetFetFlt2Clk_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_IoHwAbstraction_IoHwAb_SetFetFlt2Clk_Start
# endif
# if defined (Rte_Runnable_IoHwAbstraction_IoHwAb_SetFetFlt2Clk_Start)
#  undef Rte_Runnable_IoHwAbstraction_IoHwAb_SetFetFlt2Clk_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_IoHwAbstraction_IoHwAb_SetFetFlt2Clk_Start(IoHwAb_BoolType signal);
# else
#  define Rte_Runnable_IoHwAbstraction_IoHwAb_SetFetFlt2Clk_Start(arg1) ((void)(0))
# endif /* Rte_Runnable_IoHwAbstraction_IoHwAb_SetFetFlt2Clk_Start */

# if defined (Rte_Runnable_IoHwAbstraction_IoHwAb_SetFetFlt2ToOutput_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_IoHwAbstraction_IoHwAb_SetFetFlt2ToOutput_Return
# endif
# if defined (Rte_Runnable_IoHwAbstraction_IoHwAb_SetFetFlt2ToOutput_Return)
#  undef Rte_Runnable_IoHwAbstraction_IoHwAb_SetFetFlt2ToOutput_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_IoHwAbstraction_IoHwAb_SetFetFlt2ToOutput_Return(IoHwAb_BoolType signal);
# else
#  define Rte_Runnable_IoHwAbstraction_IoHwAb_SetFetFlt2ToOutput_Return(arg1) ((void)(0))
# endif /* Rte_Runnable_IoHwAbstraction_IoHwAb_SetFetFlt2ToOutput_Return */

# if defined (Rte_Runnable_IoHwAbstraction_IoHwAb_SetFetFlt2ToOutput_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_IoHwAbstraction_IoHwAb_SetFetFlt2ToOutput_Start
# endif
# if defined (Rte_Runnable_IoHwAbstraction_IoHwAb_SetFetFlt2ToOutput_Start)
#  undef Rte_Runnable_IoHwAbstraction_IoHwAb_SetFetFlt2ToOutput_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_IoHwAbstraction_IoHwAb_SetFetFlt2ToOutput_Start(IoHwAb_BoolType signal);
# else
#  define Rte_Runnable_IoHwAbstraction_IoHwAb_SetFetFlt2ToOutput_Start(arg1) ((void)(0))
# endif /* Rte_Runnable_IoHwAbstraction_IoHwAb_SetFetFlt2ToOutput_Start */

# if defined (Rte_Runnable_IoHwAbstraction_IoHwAb_SetSysFault2_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_IoHwAbstraction_IoHwAb_SetSysFault2_Return
# endif
# if defined (Rte_Runnable_IoHwAbstraction_IoHwAb_SetSysFault2_Return)
#  undef Rte_Runnable_IoHwAbstraction_IoHwAb_SetSysFault2_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_IoHwAbstraction_IoHwAb_SetSysFault2_Return(IoHwAb_BoolType signal);
# else
#  define Rte_Runnable_IoHwAbstraction_IoHwAb_SetSysFault2_Return(arg1) ((void)(0))
# endif /* Rte_Runnable_IoHwAbstraction_IoHwAb_SetSysFault2_Return */

# if defined (Rte_Runnable_IoHwAbstraction_IoHwAb_SetSysFault2_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_IoHwAbstraction_IoHwAb_SetSysFault2_Start
# endif
# if defined (Rte_Runnable_IoHwAbstraction_IoHwAb_SetSysFault2_Start)
#  undef Rte_Runnable_IoHwAbstraction_IoHwAb_SetSysFault2_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_IoHwAbstraction_IoHwAb_SetSysFault2_Start(IoHwAb_BoolType signal);
# else
#  define Rte_Runnable_IoHwAbstraction_IoHwAb_SetSysFault2_Start(arg1) ((void)(0))
# endif /* Rte_Runnable_IoHwAbstraction_IoHwAb_SetSysFault2_Start */

# if defined (Rte_Runnable_IoHwAbstraction_IoHwAb_SetTODReset_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_IoHwAbstraction_IoHwAb_SetTODReset_Return
# endif
# if defined (Rte_Runnable_IoHwAbstraction_IoHwAb_SetTODReset_Return)
#  undef Rte_Runnable_IoHwAbstraction_IoHwAb_SetTODReset_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_IoHwAbstraction_IoHwAb_SetTODReset_Return(IoHwAb_BoolType signal);
# else
#  define Rte_Runnable_IoHwAbstraction_IoHwAb_SetTODReset_Return(arg1) ((void)(0))
# endif /* Rte_Runnable_IoHwAbstraction_IoHwAb_SetTODReset_Return */

# if defined (Rte_Runnable_IoHwAbstraction_IoHwAb_SetTODReset_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_IoHwAbstraction_IoHwAb_SetTODReset_Start
# endif
# if defined (Rte_Runnable_IoHwAbstraction_IoHwAb_SetTODReset_Start)
#  undef Rte_Runnable_IoHwAbstraction_IoHwAb_SetTODReset_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_IoHwAbstraction_IoHwAb_SetTODReset_Start(IoHwAb_BoolType signal);
# else
#  define Rte_Runnable_IoHwAbstraction_IoHwAb_SetTODReset_Start(arg1) ((void)(0))
# endif /* Rte_Runnable_IoHwAbstraction_IoHwAb_SetTODReset_Start */

# if defined (Rte_Runnable_IoHwAbstraction_IoHwAb_SetTcCS_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_IoHwAbstraction_IoHwAb_SetTcCS_Return
# endif
# if defined (Rte_Runnable_IoHwAbstraction_IoHwAb_SetTcCS_Return)
#  undef Rte_Runnable_IoHwAbstraction_IoHwAb_SetTcCS_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_IoHwAbstraction_IoHwAb_SetTcCS_Return(IoHwAb_BoolType signal);
# else
#  define Rte_Runnable_IoHwAbstraction_IoHwAb_SetTcCS_Return(arg1) ((void)(0))
# endif /* Rte_Runnable_IoHwAbstraction_IoHwAb_SetTcCS_Return */

# if defined (Rte_Runnable_IoHwAbstraction_IoHwAb_SetTcCS_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_IoHwAbstraction_IoHwAb_SetTcCS_Start
# endif
# if defined (Rte_Runnable_IoHwAbstraction_IoHwAb_SetTcCS_Start)
#  undef Rte_Runnable_IoHwAbstraction_IoHwAb_SetTcCS_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_IoHwAbstraction_IoHwAb_SetTcCS_Start(IoHwAb_BoolType signal);
# else
#  define Rte_Runnable_IoHwAbstraction_IoHwAb_SetTcCS_Start(arg1) ((void)(0))
# endif /* Rte_Runnable_IoHwAbstraction_IoHwAb_SetTcCS_Start */

# if defined (Rte_Runnable_IoHwAbstraction_IoHwAb_SetTcMCLR_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_IoHwAbstraction_IoHwAb_SetTcMCLR_Return
# endif
# if defined (Rte_Runnable_IoHwAbstraction_IoHwAb_SetTcMCLR_Return)
#  undef Rte_Runnable_IoHwAbstraction_IoHwAb_SetTcMCLR_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_IoHwAbstraction_IoHwAb_SetTcMCLR_Return(IoHwAb_BoolType signal);
# else
#  define Rte_Runnable_IoHwAbstraction_IoHwAb_SetTcMCLR_Return(arg1) ((void)(0))
# endif /* Rte_Runnable_IoHwAbstraction_IoHwAb_SetTcMCLR_Return */

# if defined (Rte_Runnable_IoHwAbstraction_IoHwAb_SetTcMCLR_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_IoHwAbstraction_IoHwAb_SetTcMCLR_Start
# endif
# if defined (Rte_Runnable_IoHwAbstraction_IoHwAb_SetTcMCLR_Start)
#  undef Rte_Runnable_IoHwAbstraction_IoHwAb_SetTcMCLR_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_IoHwAbstraction_IoHwAb_SetTcMCLR_Start(IoHwAb_BoolType signal);
# else
#  define Rte_Runnable_IoHwAbstraction_IoHwAb_SetTcMCLR_Start(arg1) ((void)(0))
# endif /* Rte_Runnable_IoHwAbstraction_IoHwAb_SetTcMCLR_Start */

# if defined (Rte_Runnable_IoHwAbstraction_IoHwAb_SetWdMonitor_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_IoHwAbstraction_IoHwAb_SetWdMonitor_Return
# endif
# if defined (Rte_Runnable_IoHwAbstraction_IoHwAb_SetWdMonitor_Return)
#  undef Rte_Runnable_IoHwAbstraction_IoHwAb_SetWdMonitor_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_IoHwAbstraction_IoHwAb_SetWdMonitor_Return(IoHwAb_BoolType signal);
# else
#  define Rte_Runnable_IoHwAbstraction_IoHwAb_SetWdMonitor_Return(arg1) ((void)(0))
# endif /* Rte_Runnable_IoHwAbstraction_IoHwAb_SetWdMonitor_Return */

# if defined (Rte_Runnable_IoHwAbstraction_IoHwAb_SetWdMonitor_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_IoHwAbstraction_IoHwAb_SetWdMonitor_Start
# endif
# if defined (Rte_Runnable_IoHwAbstraction_IoHwAb_SetWdMonitor_Start)
#  undef Rte_Runnable_IoHwAbstraction_IoHwAb_SetWdMonitor_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_IoHwAbstraction_IoHwAb_SetWdMonitor_Start(IoHwAb_BoolType signal);
# else
#  define Rte_Runnable_IoHwAbstraction_IoHwAb_SetWdMonitor_Start(arg1) ((void)(0))
# endif /* Rte_Runnable_IoHwAbstraction_IoHwAb_SetWdMonitor_Start */

# if defined (Rte_Runnable_IoHwAbstraction_IoHwAb_SetWdReset_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_IoHwAbstraction_IoHwAb_SetWdReset_Return
# endif
# if defined (Rte_Runnable_IoHwAbstraction_IoHwAb_SetWdReset_Return)
#  undef Rte_Runnable_IoHwAbstraction_IoHwAb_SetWdReset_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_IoHwAbstraction_IoHwAb_SetWdReset_Return(IoHwAb_BoolType signal);
# else
#  define Rte_Runnable_IoHwAbstraction_IoHwAb_SetWdReset_Return(arg1) ((void)(0))
# endif /* Rte_Runnable_IoHwAbstraction_IoHwAb_SetWdReset_Return */

# if defined (Rte_Runnable_IoHwAbstraction_IoHwAb_SetWdReset_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_IoHwAbstraction_IoHwAb_SetWdReset_Start
# endif
# if defined (Rte_Runnable_IoHwAbstraction_IoHwAb_SetWdReset_Start)
#  undef Rte_Runnable_IoHwAbstraction_IoHwAb_SetWdReset_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_IoHwAbstraction_IoHwAb_SetWdReset_Start(IoHwAb_BoolType signal);
# else
#  define Rte_Runnable_IoHwAbstraction_IoHwAb_SetWdReset_Start(arg1) ((void)(0))
# endif /* Rte_Runnable_IoHwAbstraction_IoHwAb_SetWdReset_Start */

# if defined (Rte_Runnable_NexteerLibs_DtrmnElapsedTime_mS_u16_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_NexteerLibs_DtrmnElapsedTime_mS_u16_Return
# endif
# if defined (Rte_Runnable_NexteerLibs_DtrmnElapsedTime_mS_u16_Return)
#  undef Rte_Runnable_NexteerLibs_DtrmnElapsedTime_mS_u16_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_NexteerLibs_DtrmnElapsedTime_mS_u16_Return(UInt32 InitialTime, P2VAR(UInt16, AUTOMATIC, RTE_NEXTEERLIBS_APPL_VAR) ElapsedTime);
# else
#  define Rte_Runnable_NexteerLibs_DtrmnElapsedTime_mS_u16_Return(arg1, arg2) ((void)(0))
# endif /* Rte_Runnable_NexteerLibs_DtrmnElapsedTime_mS_u16_Return */

# if defined (Rte_Runnable_NexteerLibs_DtrmnElapsedTime_mS_u16_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_NexteerLibs_DtrmnElapsedTime_mS_u16_Start
# endif
# if defined (Rte_Runnable_NexteerLibs_DtrmnElapsedTime_mS_u16_Start)
#  undef Rte_Runnable_NexteerLibs_DtrmnElapsedTime_mS_u16_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_NexteerLibs_DtrmnElapsedTime_mS_u16_Start(UInt32 InitialTime, P2VAR(UInt16, AUTOMATIC, RTE_NEXTEERLIBS_APPL_VAR) ElapsedTime);
# else
#  define Rte_Runnable_NexteerLibs_DtrmnElapsedTime_mS_u16_Start(arg1, arg2) ((void)(0))
# endif /* Rte_Runnable_NexteerLibs_DtrmnElapsedTime_mS_u16_Start */

# if defined (Rte_Runnable_NexteerLibs_DtrmnElapsedTime_mS_u32_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_NexteerLibs_DtrmnElapsedTime_mS_u32_Return
# endif
# if defined (Rte_Runnable_NexteerLibs_DtrmnElapsedTime_mS_u32_Return)
#  undef Rte_Runnable_NexteerLibs_DtrmnElapsedTime_mS_u32_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_NexteerLibs_DtrmnElapsedTime_mS_u32_Return(UInt32 InitialTime, P2VAR(UInt32, AUTOMATIC, RTE_NEXTEERLIBS_APPL_VAR) ElapsedTime);
# else
#  define Rte_Runnable_NexteerLibs_DtrmnElapsedTime_mS_u32_Return(arg1, arg2) ((void)(0))
# endif /* Rte_Runnable_NexteerLibs_DtrmnElapsedTime_mS_u32_Return */

# if defined (Rte_Runnable_NexteerLibs_DtrmnElapsedTime_mS_u32_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_NexteerLibs_DtrmnElapsedTime_mS_u32_Start
# endif
# if defined (Rte_Runnable_NexteerLibs_DtrmnElapsedTime_mS_u32_Start)
#  undef Rte_Runnable_NexteerLibs_DtrmnElapsedTime_mS_u32_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_NexteerLibs_DtrmnElapsedTime_mS_u32_Start(UInt32 InitialTime, P2VAR(UInt32, AUTOMATIC, RTE_NEXTEERLIBS_APPL_VAR) ElapsedTime);
# else
#  define Rte_Runnable_NexteerLibs_DtrmnElapsedTime_mS_u32_Start(arg1, arg2) ((void)(0))
# endif /* Rte_Runnable_NexteerLibs_DtrmnElapsedTime_mS_u32_Start */

# if defined (Rte_Runnable_NexteerLibs_DtrmnElapsedTime_uS_u16_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_NexteerLibs_DtrmnElapsedTime_uS_u16_Return
# endif
# if defined (Rte_Runnable_NexteerLibs_DtrmnElapsedTime_uS_u16_Return)
#  undef Rte_Runnable_NexteerLibs_DtrmnElapsedTime_uS_u16_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_NexteerLibs_DtrmnElapsedTime_uS_u16_Return(UInt32 InitialTime, P2VAR(UInt16, AUTOMATIC, RTE_NEXTEERLIBS_APPL_VAR) ElapsedTime);
# else
#  define Rte_Runnable_NexteerLibs_DtrmnElapsedTime_uS_u16_Return(arg1, arg2) ((void)(0))
# endif /* Rte_Runnable_NexteerLibs_DtrmnElapsedTime_uS_u16_Return */

# if defined (Rte_Runnable_NexteerLibs_DtrmnElapsedTime_uS_u16_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_NexteerLibs_DtrmnElapsedTime_uS_u16_Start
# endif
# if defined (Rte_Runnable_NexteerLibs_DtrmnElapsedTime_uS_u16_Start)
#  undef Rte_Runnable_NexteerLibs_DtrmnElapsedTime_uS_u16_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_NexteerLibs_DtrmnElapsedTime_uS_u16_Start(UInt32 InitialTime, P2VAR(UInt16, AUTOMATIC, RTE_NEXTEERLIBS_APPL_VAR) ElapsedTime);
# else
#  define Rte_Runnable_NexteerLibs_DtrmnElapsedTime_uS_u16_Start(arg1, arg2) ((void)(0))
# endif /* Rte_Runnable_NexteerLibs_DtrmnElapsedTime_uS_u16_Start */

# if defined (Rte_Runnable_NexteerLibs_DtrmnElapsedTime_uS_u32_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_NexteerLibs_DtrmnElapsedTime_uS_u32_Return
# endif
# if defined (Rte_Runnable_NexteerLibs_DtrmnElapsedTime_uS_u32_Return)
#  undef Rte_Runnable_NexteerLibs_DtrmnElapsedTime_uS_u32_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_NexteerLibs_DtrmnElapsedTime_uS_u32_Return(UInt32 InitialTime, P2VAR(UInt32, AUTOMATIC, RTE_NEXTEERLIBS_APPL_VAR) ElapsedTime);
# else
#  define Rte_Runnable_NexteerLibs_DtrmnElapsedTime_uS_u32_Return(arg1, arg2) ((void)(0))
# endif /* Rte_Runnable_NexteerLibs_DtrmnElapsedTime_uS_u32_Return */

# if defined (Rte_Runnable_NexteerLibs_DtrmnElapsedTime_uS_u32_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_NexteerLibs_DtrmnElapsedTime_uS_u32_Start
# endif
# if defined (Rte_Runnable_NexteerLibs_DtrmnElapsedTime_uS_u32_Start)
#  undef Rte_Runnable_NexteerLibs_DtrmnElapsedTime_uS_u32_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_NexteerLibs_DtrmnElapsedTime_uS_u32_Start(UInt32 InitialTime, P2VAR(UInt32, AUTOMATIC, RTE_NEXTEERLIBS_APPL_VAR) ElapsedTime);
# else
#  define Rte_Runnable_NexteerLibs_DtrmnElapsedTime_uS_u32_Start(arg1, arg2) ((void)(0))
# endif /* Rte_Runnable_NexteerLibs_DtrmnElapsedTime_uS_u32_Start */

# if defined (Rte_Runnable_NexteerLibs_GetSystemTime_mS_u32_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_NexteerLibs_GetSystemTime_mS_u32_Return
# endif
# if defined (Rte_Runnable_NexteerLibs_GetSystemTime_mS_u32_Return)
#  undef Rte_Runnable_NexteerLibs_GetSystemTime_mS_u32_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_NexteerLibs_GetSystemTime_mS_u32_Return(P2VAR(UInt32, AUTOMATIC, RTE_NEXTEERLIBS_APPL_VAR) CurrentTime);
# else
#  define Rte_Runnable_NexteerLibs_GetSystemTime_mS_u32_Return(arg1) ((void)(0))
# endif /* Rte_Runnable_NexteerLibs_GetSystemTime_mS_u32_Return */

# if defined (Rte_Runnable_NexteerLibs_GetSystemTime_mS_u32_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_NexteerLibs_GetSystemTime_mS_u32_Start
# endif
# if defined (Rte_Runnable_NexteerLibs_GetSystemTime_mS_u32_Start)
#  undef Rte_Runnable_NexteerLibs_GetSystemTime_mS_u32_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_NexteerLibs_GetSystemTime_mS_u32_Start(P2VAR(UInt32, AUTOMATIC, RTE_NEXTEERLIBS_APPL_VAR) CurrentTime);
# else
#  define Rte_Runnable_NexteerLibs_GetSystemTime_mS_u32_Start(arg1) ((void)(0))
# endif /* Rte_Runnable_NexteerLibs_GetSystemTime_mS_u32_Start */

# if defined (Rte_Runnable_NexteerLibs_GetSystemTime_uS_u32_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_NexteerLibs_GetSystemTime_uS_u32_Return
# endif
# if defined (Rte_Runnable_NexteerLibs_GetSystemTime_uS_u32_Return)
#  undef Rte_Runnable_NexteerLibs_GetSystemTime_uS_u32_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_NexteerLibs_GetSystemTime_uS_u32_Return(P2VAR(UInt32, AUTOMATIC, RTE_NEXTEERLIBS_APPL_VAR) CurrentTime);
# else
#  define Rte_Runnable_NexteerLibs_GetSystemTime_uS_u32_Return(arg1) ((void)(0))
# endif /* Rte_Runnable_NexteerLibs_GetSystemTime_uS_u32_Return */

# if defined (Rte_Runnable_NexteerLibs_GetSystemTime_uS_u32_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_NexteerLibs_GetSystemTime_uS_u32_Start
# endif
# if defined (Rte_Runnable_NexteerLibs_GetSystemTime_uS_u32_Start)
#  undef Rte_Runnable_NexteerLibs_GetSystemTime_uS_u32_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_NexteerLibs_GetSystemTime_uS_u32_Start(P2VAR(UInt32, AUTOMATIC, RTE_NEXTEERLIBS_APPL_VAR) CurrentTime);
# else
#  define Rte_Runnable_NexteerLibs_GetSystemTime_uS_u32_Start(arg1) ((void)(0))
# endif /* Rte_Runnable_NexteerLibs_GetSystemTime_uS_u32_Start */

# if defined (Rte_Runnable_NexteerLibs_SystemTime_Per1_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_NexteerLibs_SystemTime_Per1_Return
# endif
# if defined (Rte_Runnable_NexteerLibs_SystemTime_Per1_Return)
#  undef Rte_Runnable_NexteerLibs_SystemTime_Per1_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_NexteerLibs_SystemTime_Per1_Return(void);
# else
#  define Rte_Runnable_NexteerLibs_SystemTime_Per1_Return() ((void)(0))
# endif /* Rte_Runnable_NexteerLibs_SystemTime_Per1_Return */

# if defined (Rte_Runnable_NexteerLibs_SystemTime_Per1_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_NexteerLibs_SystemTime_Per1_Start
# endif
# if defined (Rte_Runnable_NexteerLibs_SystemTime_Per1_Start)
#  undef Rte_Runnable_NexteerLibs_SystemTime_Per1_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_NexteerLibs_SystemTime_Per1_Start(void);
# else
#  define Rte_Runnable_NexteerLibs_SystemTime_Per1_Start() ((void)(0))
# endif /* Rte_Runnable_NexteerLibs_SystemTime_Per1_Start */

# if defined (Rte_Runnable_NtWrap_AbsHwPosScom_Scom_HwPosSrvSetToZero_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_NtWrap_AbsHwPosScom_Scom_HwPosSrvSetToZero_Return
# endif
# if defined (Rte_Runnable_NtWrap_AbsHwPosScom_Scom_HwPosSrvSetToZero_Return)
#  undef Rte_Runnable_NtWrap_AbsHwPosScom_Scom_HwPosSrvSetToZero_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_NtWrap_AbsHwPosScom_Scom_HwPosSrvSetToZero_Return(Boolean Par);
# else
#  define Rte_Runnable_NtWrap_AbsHwPosScom_Scom_HwPosSrvSetToZero_Return(arg1) ((void)(0))
# endif /* Rte_Runnable_NtWrap_AbsHwPosScom_Scom_HwPosSrvSetToZero_Return */

# if defined (Rte_Runnable_NtWrap_AbsHwPosScom_Scom_HwPosSrvSetToZero_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_NtWrap_AbsHwPosScom_Scom_HwPosSrvSetToZero_Start
# endif
# if defined (Rte_Runnable_NtWrap_AbsHwPosScom_Scom_HwPosSrvSetToZero_Start)
#  undef Rte_Runnable_NtWrap_AbsHwPosScom_Scom_HwPosSrvSetToZero_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_NtWrap_AbsHwPosScom_Scom_HwPosSrvSetToZero_Start(Boolean Par);
# else
#  define Rte_Runnable_NtWrap_AbsHwPosScom_Scom_HwPosSrvSetToZero_Start(arg1) ((void)(0))
# endif /* Rte_Runnable_NtWrap_AbsHwPosScom_Scom_HwPosSrvSetToZero_Start */

# if defined (Rte_Runnable_NtWrap_AstLmt_Scom_ManualTrqCmd_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_NtWrap_AstLmt_Scom_ManualTrqCmd_Return
# endif
# if defined (Rte_Runnable_NtWrap_AstLmt_Scom_ManualTrqCmd_Return)
#  undef Rte_Runnable_NtWrap_AstLmt_Scom_ManualTrqCmd_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_NtWrap_AstLmt_Scom_ManualTrqCmd_Return(Boolean EnableManualCtrl, Float MtrTrqCmd_MtrNm_f32);
# else
#  define Rte_Runnable_NtWrap_AstLmt_Scom_ManualTrqCmd_Return(arg1, arg2) ((void)(0))
# endif /* Rte_Runnable_NtWrap_AstLmt_Scom_ManualTrqCmd_Return */

# if defined (Rte_Runnable_NtWrap_AstLmt_Scom_ManualTrqCmd_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_NtWrap_AstLmt_Scom_ManualTrqCmd_Start
# endif
# if defined (Rte_Runnable_NtWrap_AstLmt_Scom_ManualTrqCmd_Start)
#  undef Rte_Runnable_NtWrap_AstLmt_Scom_ManualTrqCmd_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_NtWrap_AstLmt_Scom_ManualTrqCmd_Start(Boolean EnableManualCtrl, Float MtrTrqCmd_MtrNm_f32);
# else
#  define Rte_Runnable_NtWrap_AstLmt_Scom_ManualTrqCmd_Start(arg1, arg2) ((void)(0))
# endif /* Rte_Runnable_NtWrap_AstLmt_Scom_ManualTrqCmd_Start */

# if defined (Rte_Runnable_NtWrap_CmMtrCurr_SCom_CalGain_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_NtWrap_CmMtrCurr_SCom_CalGain_Return
# endif
# if defined (Rte_Runnable_NtWrap_CmMtrCurr_SCom_CalGain_Return)
#  undef Rte_Runnable_NtWrap_CmMtrCurr_SCom_CalGain_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_NtWrap_CmMtrCurr_SCom_CalGain_Return(void);
# else
#  define Rte_Runnable_NtWrap_CmMtrCurr_SCom_CalGain_Return() ((void)(0))
# endif /* Rte_Runnable_NtWrap_CmMtrCurr_SCom_CalGain_Return */

# if defined (Rte_Runnable_NtWrap_CmMtrCurr_SCom_CalGain_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_NtWrap_CmMtrCurr_SCom_CalGain_Start
# endif
# if defined (Rte_Runnable_NtWrap_CmMtrCurr_SCom_CalGain_Start)
#  undef Rte_Runnable_NtWrap_CmMtrCurr_SCom_CalGain_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_NtWrap_CmMtrCurr_SCom_CalGain_Start(void);
# else
#  define Rte_Runnable_NtWrap_CmMtrCurr_SCom_CalGain_Start() ((void)(0))
# endif /* Rte_Runnable_NtWrap_CmMtrCurr_SCom_CalGain_Start */

# if defined (Rte_Runnable_NtWrap_CmMtrCurr_SCom_CalOffset_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_NtWrap_CmMtrCurr_SCom_CalOffset_Return
# endif
# if defined (Rte_Runnable_NtWrap_CmMtrCurr_SCom_CalOffset_Return)
#  undef Rte_Runnable_NtWrap_CmMtrCurr_SCom_CalOffset_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_NtWrap_CmMtrCurr_SCom_CalOffset_Return(void);
# else
#  define Rte_Runnable_NtWrap_CmMtrCurr_SCom_CalOffset_Return() ((void)(0))
# endif /* Rte_Runnable_NtWrap_CmMtrCurr_SCom_CalOffset_Return */

# if defined (Rte_Runnable_NtWrap_CmMtrCurr_SCom_CalOffset_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_NtWrap_CmMtrCurr_SCom_CalOffset_Start
# endif
# if defined (Rte_Runnable_NtWrap_CmMtrCurr_SCom_CalOffset_Start)
#  undef Rte_Runnable_NtWrap_CmMtrCurr_SCom_CalOffset_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_NtWrap_CmMtrCurr_SCom_CalOffset_Start(void);
# else
#  define Rte_Runnable_NtWrap_CmMtrCurr_SCom_CalOffset_Start() ((void)(0))
# endif /* Rte_Runnable_NtWrap_CmMtrCurr_SCom_CalOffset_Start */

# if defined (Rte_Runnable_NtWrap_CmMtrCurr_SCom_SetMtrCurrCals_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_NtWrap_CmMtrCurr_SCom_SetMtrCurrCals_Return
# endif
# if defined (Rte_Runnable_NtWrap_CmMtrCurr_SCom_SetMtrCurrCals_Return)
#  undef Rte_Runnable_NtWrap_CmMtrCurr_SCom_SetMtrCurrCals_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_NtWrap_CmMtrCurr_SCom_SetMtrCurrCals_Return(P2CONST(PhaseCurrCal_DataType, AUTOMATIC, RTE_NTWRAP_APPL_DATA) ShCurrCalPtr);
# else
#  define Rte_Runnable_NtWrap_CmMtrCurr_SCom_SetMtrCurrCals_Return(arg1) ((void)(0))
# endif /* Rte_Runnable_NtWrap_CmMtrCurr_SCom_SetMtrCurrCals_Return */

# if defined (Rte_Runnable_NtWrap_CmMtrCurr_SCom_SetMtrCurrCals_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_NtWrap_CmMtrCurr_SCom_SetMtrCurrCals_Start
# endif
# if defined (Rte_Runnable_NtWrap_CmMtrCurr_SCom_SetMtrCurrCals_Start)
#  undef Rte_Runnable_NtWrap_CmMtrCurr_SCom_SetMtrCurrCals_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_NtWrap_CmMtrCurr_SCom_SetMtrCurrCals_Start(P2CONST(PhaseCurrCal_DataType, AUTOMATIC, RTE_NTWRAP_APPL_DATA) ShCurrCalPtr);
# else
#  define Rte_Runnable_NtWrap_CmMtrCurr_SCom_SetMtrCurrCals_Start(arg1) ((void)(0))
# endif /* Rte_Runnable_NtWrap_CmMtrCurr_SCom_SetMtrCurrCals_Start */

# if defined (Rte_Runnable_NtWrap_HwTrq_SCom_ClrHwTrqScale_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_NtWrap_HwTrq_SCom_ClrHwTrqScale_Return
# endif
# if defined (Rte_Runnable_NtWrap_HwTrq_SCom_ClrHwTrqScale_Return)
#  undef Rte_Runnable_NtWrap_HwTrq_SCom_ClrHwTrqScale_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_NtWrap_HwTrq_SCom_ClrHwTrqScale_Return(void);
# else
#  define Rte_Runnable_NtWrap_HwTrq_SCom_ClrHwTrqScale_Return() ((void)(0))
# endif /* Rte_Runnable_NtWrap_HwTrq_SCom_ClrHwTrqScale_Return */

# if defined (Rte_Runnable_NtWrap_HwTrq_SCom_ClrHwTrqScale_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_NtWrap_HwTrq_SCom_ClrHwTrqScale_Start
# endif
# if defined (Rte_Runnable_NtWrap_HwTrq_SCom_ClrHwTrqScale_Start)
#  undef Rte_Runnable_NtWrap_HwTrq_SCom_ClrHwTrqScale_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_NtWrap_HwTrq_SCom_ClrHwTrqScale_Start(void);
# else
#  define Rte_Runnable_NtWrap_HwTrq_SCom_ClrHwTrqScale_Start() ((void)(0))
# endif /* Rte_Runnable_NtWrap_HwTrq_SCom_ClrHwTrqScale_Start */

# if defined (Rte_Runnable_NtWrap_HwTrq_SCom_ClrHwTrqTrim_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_NtWrap_HwTrq_SCom_ClrHwTrqTrim_Return
# endif
# if defined (Rte_Runnable_NtWrap_HwTrq_SCom_ClrHwTrqTrim_Return)
#  undef Rte_Runnable_NtWrap_HwTrq_SCom_ClrHwTrqTrim_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_NtWrap_HwTrq_SCom_ClrHwTrqTrim_Return(void);
# else
#  define Rte_Runnable_NtWrap_HwTrq_SCom_ClrHwTrqTrim_Return() ((void)(0))
# endif /* Rte_Runnable_NtWrap_HwTrq_SCom_ClrHwTrqTrim_Return */

# if defined (Rte_Runnable_NtWrap_HwTrq_SCom_ClrHwTrqTrim_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_NtWrap_HwTrq_SCom_ClrHwTrqTrim_Start
# endif
# if defined (Rte_Runnable_NtWrap_HwTrq_SCom_ClrHwTrqTrim_Start)
#  undef Rte_Runnable_NtWrap_HwTrq_SCom_ClrHwTrqTrim_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_NtWrap_HwTrq_SCom_ClrHwTrqTrim_Start(void);
# else
#  define Rte_Runnable_NtWrap_HwTrq_SCom_ClrHwTrqTrim_Start() ((void)(0))
# endif /* Rte_Runnable_NtWrap_HwTrq_SCom_ClrHwTrqTrim_Start */

# if defined (Rte_Runnable_NtWrap_HwTrq_SCom_ManualSetHwTrqTrim_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_NtWrap_HwTrq_SCom_ManualSetHwTrqTrim_Return
# endif
# if defined (Rte_Runnable_NtWrap_HwTrq_SCom_ManualSetHwTrqTrim_Return)
#  undef Rte_Runnable_NtWrap_HwTrq_SCom_ManualSetHwTrqTrim_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_NtWrap_HwTrq_SCom_ManualSetHwTrqTrim_Return(P2CONST(HwTrqTrim_Datatype, AUTOMATIC, RTE_NTWRAP_APPL_DATA) HwTrqTrimDataPtr);
# else
#  define Rte_Runnable_NtWrap_HwTrq_SCom_ManualSetHwTrqTrim_Return(arg1) ((void)(0))
# endif /* Rte_Runnable_NtWrap_HwTrq_SCom_ManualSetHwTrqTrim_Return */

# if defined (Rte_Runnable_NtWrap_HwTrq_SCom_ManualSetHwTrqTrim_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_NtWrap_HwTrq_SCom_ManualSetHwTrqTrim_Start
# endif
# if defined (Rte_Runnable_NtWrap_HwTrq_SCom_ManualSetHwTrqTrim_Start)
#  undef Rte_Runnable_NtWrap_HwTrq_SCom_ManualSetHwTrqTrim_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_NtWrap_HwTrq_SCom_ManualSetHwTrqTrim_Start(P2CONST(HwTrqTrim_Datatype, AUTOMATIC, RTE_NTWRAP_APPL_DATA) HwTrqTrimDataPtr);
# else
#  define Rte_Runnable_NtWrap_HwTrq_SCom_ManualSetHwTrqTrim_Start(arg1) ((void)(0))
# endif /* Rte_Runnable_NtWrap_HwTrq_SCom_ManualSetHwTrqTrim_Start */

# if defined (Rte_Runnable_NtWrap_HwTrq_SCom_SetEOLTrqStep_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_NtWrap_HwTrq_SCom_SetEOLTrqStep_Return
# endif
# if defined (Rte_Runnable_NtWrap_HwTrq_SCom_SetEOLTrqStep_Return)
#  undef Rte_Runnable_NtWrap_HwTrq_SCom_SetEOLTrqStep_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_NtWrap_HwTrq_SCom_SetEOLTrqStep_Return(P2CONST(EOLTrqStepType, AUTOMATIC, RTE_NTWRAP_APPL_DATA) TrqStep_HwNm_T_f32);
# else
#  define Rte_Runnable_NtWrap_HwTrq_SCom_SetEOLTrqStep_Return(arg1) ((void)(0))
# endif /* Rte_Runnable_NtWrap_HwTrq_SCom_SetEOLTrqStep_Return */

# if defined (Rte_Runnable_NtWrap_HwTrq_SCom_SetEOLTrqStep_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_NtWrap_HwTrq_SCom_SetEOLTrqStep_Start
# endif
# if defined (Rte_Runnable_NtWrap_HwTrq_SCom_SetEOLTrqStep_Start)
#  undef Rte_Runnable_NtWrap_HwTrq_SCom_SetEOLTrqStep_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_NtWrap_HwTrq_SCom_SetEOLTrqStep_Start(P2CONST(EOLTrqStepType, AUTOMATIC, RTE_NTWRAP_APPL_DATA) TrqStep_HwNm_T_f32);
# else
#  define Rte_Runnable_NtWrap_HwTrq_SCom_SetEOLTrqStep_Start(arg1) ((void)(0))
# endif /* Rte_Runnable_NtWrap_HwTrq_SCom_SetEOLTrqStep_Start */

# if defined (Rte_Runnable_NtWrap_HwTrq_SCom_SetHwTrqScale_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_NtWrap_HwTrq_SCom_SetHwTrqScale_Return
# endif
# if defined (Rte_Runnable_NtWrap_HwTrq_SCom_SetHwTrqScale_Return)
#  undef Rte_Runnable_NtWrap_HwTrq_SCom_SetHwTrqScale_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_NtWrap_HwTrq_SCom_SetHwTrqScale_Return(Float ScaleValue);
# else
#  define Rte_Runnable_NtWrap_HwTrq_SCom_SetHwTrqScale_Return(arg1) ((void)(0))
# endif /* Rte_Runnable_NtWrap_HwTrq_SCom_SetHwTrqScale_Return */

# if defined (Rte_Runnable_NtWrap_HwTrq_SCom_SetHwTrqScale_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_NtWrap_HwTrq_SCom_SetHwTrqScale_Start
# endif
# if defined (Rte_Runnable_NtWrap_HwTrq_SCom_SetHwTrqScale_Start)
#  undef Rte_Runnable_NtWrap_HwTrq_SCom_SetHwTrqScale_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_NtWrap_HwTrq_SCom_SetHwTrqScale_Start(Float ScaleValue);
# else
#  define Rte_Runnable_NtWrap_HwTrq_SCom_SetHwTrqScale_Start(arg1) ((void)(0))
# endif /* Rte_Runnable_NtWrap_HwTrq_SCom_SetHwTrqScale_Start */

# if defined (Rte_Runnable_NtWrap_HwTrq_SCom_SetHwTrqTrim_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_NtWrap_HwTrq_SCom_SetHwTrqTrim_Return
# endif
# if defined (Rte_Runnable_NtWrap_HwTrq_SCom_SetHwTrqTrim_Return)
#  undef Rte_Runnable_NtWrap_HwTrq_SCom_SetHwTrqTrim_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_NtWrap_HwTrq_SCom_SetHwTrqTrim_Return(void);
# else
#  define Rte_Runnable_NtWrap_HwTrq_SCom_SetHwTrqTrim_Return() ((void)(0))
# endif /* Rte_Runnable_NtWrap_HwTrq_SCom_SetHwTrqTrim_Return */

# if defined (Rte_Runnable_NtWrap_HwTrq_SCom_SetHwTrqTrim_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_NtWrap_HwTrq_SCom_SetHwTrqTrim_Start
# endif
# if defined (Rte_Runnable_NtWrap_HwTrq_SCom_SetHwTrqTrim_Start)
#  undef Rte_Runnable_NtWrap_HwTrq_SCom_SetHwTrqTrim_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_NtWrap_HwTrq_SCom_SetHwTrqTrim_Start(void);
# else
#  define Rte_Runnable_NtWrap_HwTrq_SCom_SetHwTrqTrim_Start() ((void)(0))
# endif /* Rte_Runnable_NtWrap_HwTrq_SCom_SetHwTrqTrim_Start */

# if defined (Rte_Runnable_NtWrap_MtrPos_SCom_SetEOLMtrCals_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_NtWrap_MtrPos_SCom_SetEOLMtrCals_Return
# endif
# if defined (Rte_Runnable_NtWrap_MtrPos_SCom_SetEOLMtrCals_Return)
#  undef Rte_Runnable_NtWrap_MtrPos_SCom_SetEOLMtrCals_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_NtWrap_MtrPos_SCom_SetEOLMtrCals_Return(P2CONST(MtrPosCal_DataType, AUTOMATIC, RTE_NTWRAP_APPL_DATA) MtrCalDataPtr);
# else
#  define Rte_Runnable_NtWrap_MtrPos_SCom_SetEOLMtrCals_Return(arg1) ((void)(0))
# endif /* Rte_Runnable_NtWrap_MtrPos_SCom_SetEOLMtrCals_Return */

# if defined (Rte_Runnable_NtWrap_MtrPos_SCom_SetEOLMtrCals_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_NtWrap_MtrPos_SCom_SetEOLMtrCals_Start
# endif
# if defined (Rte_Runnable_NtWrap_MtrPos_SCom_SetEOLMtrCals_Start)
#  undef Rte_Runnable_NtWrap_MtrPos_SCom_SetEOLMtrCals_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_NtWrap_MtrPos_SCom_SetEOLMtrCals_Start(P2CONST(MtrPosCal_DataType, AUTOMATIC, RTE_NTWRAP_APPL_DATA) MtrCalDataPtr);
# else
#  define Rte_Runnable_NtWrap_MtrPos_SCom_SetEOLMtrCals_Start(arg1) ((void)(0))
# endif /* Rte_Runnable_NtWrap_MtrPos_SCom_SetEOLMtrCals_Start */

# if defined (Rte_Runnable_NtWrap_NtWrap_Per1_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_NtWrap_NtWrap_Per1_Return
# endif
# if defined (Rte_Runnable_NtWrap_NtWrap_Per1_Return)
#  undef Rte_Runnable_NtWrap_NtWrap_Per1_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_NtWrap_NtWrap_Per1_Return(void);
# else
#  define Rte_Runnable_NtWrap_NtWrap_Per1_Return() ((void)(0))
# endif /* Rte_Runnable_NtWrap_NtWrap_Per1_Return */

# if defined (Rte_Runnable_NtWrap_NtWrap_Per1_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_NtWrap_NtWrap_Per1_Start
# endif
# if defined (Rte_Runnable_NtWrap_NtWrap_Per1_Start)
#  undef Rte_Runnable_NtWrap_NtWrap_Per1_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_NtWrap_NtWrap_Per1_Start(void);
# else
#  define Rte_Runnable_NtWrap_NtWrap_Per1_Start() ((void)(0))
# endif /* Rte_Runnable_NtWrap_NtWrap_Per1_Start */

# if defined (Rte_Runnable_NtWrap_Polarity_SCom_SetPolarity_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_NtWrap_Polarity_SCom_SetPolarity_Return
# endif
# if defined (Rte_Runnable_NtWrap_Polarity_SCom_SetPolarity_Return)
#  undef Rte_Runnable_NtWrap_Polarity_SCom_SetPolarity_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_NtWrap_Polarity_SCom_SetPolarity_Return(UInt8 Polarity_Cnt_T_b08);
# else
#  define Rte_Runnable_NtWrap_Polarity_SCom_SetPolarity_Return(arg1) ((void)(0))
# endif /* Rte_Runnable_NtWrap_Polarity_SCom_SetPolarity_Return */

# if defined (Rte_Runnable_NtWrap_Polarity_SCom_SetPolarity_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_NtWrap_Polarity_SCom_SetPolarity_Start
# endif
# if defined (Rte_Runnable_NtWrap_Polarity_SCom_SetPolarity_Start)
#  undef Rte_Runnable_NtWrap_Polarity_SCom_SetPolarity_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_NtWrap_Polarity_SCom_SetPolarity_Start(UInt8 Polarity_Cnt_T_b08);
# else
#  define Rte_Runnable_NtWrap_Polarity_SCom_SetPolarity_Start(arg1) ((void)(0))
# endif /* Rte_Runnable_NtWrap_Polarity_SCom_SetPolarity_Start */

# if defined (Rte_Runnable_NtWrap_SCom_EOLNomMtrParam_Set_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_NtWrap_SCom_EOLNomMtrParam_Set_Return
# endif
# if defined (Rte_Runnable_NtWrap_SCom_EOLNomMtrParam_Set_Return)
#  undef Rte_Runnable_NtWrap_SCom_EOLNomMtrParam_Set_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_NtWrap_SCom_EOLNomMtrParam_Set_Return(Float NomKe_VpRadpS_f32, Float NomRmtr_Ohm_f32);
# else
#  define Rte_Runnable_NtWrap_SCom_EOLNomMtrParam_Set_Return(arg1, arg2) ((void)(0))
# endif /* Rte_Runnable_NtWrap_SCom_EOLNomMtrParam_Set_Return */

# if defined (Rte_Runnable_NtWrap_SCom_EOLNomMtrParam_Set_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_NtWrap_SCom_EOLNomMtrParam_Set_Start
# endif
# if defined (Rte_Runnable_NtWrap_SCom_EOLNomMtrParam_Set_Start)
#  undef Rte_Runnable_NtWrap_SCom_EOLNomMtrParam_Set_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_NtWrap_SCom_EOLNomMtrParam_Set_Start(Float NomKe_VpRadpS_f32, Float NomRmtr_Ohm_f32);
# else
#  define Rte_Runnable_NtWrap_SCom_EOLNomMtrParam_Set_Start(arg1, arg2) ((void)(0))
# endif /* Rte_Runnable_NtWrap_SCom_EOLNomMtrParam_Set_Start */

# if defined (Rte_Runnable_NtWrap_StaMd_SCom_EcuReset_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_NtWrap_StaMd_SCom_EcuReset_Return
# endif
# if defined (Rte_Runnable_NtWrap_StaMd_SCom_EcuReset_Return)
#  undef Rte_Runnable_NtWrap_StaMd_SCom_EcuReset_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_NtWrap_StaMd_SCom_EcuReset_Return(void);
# else
#  define Rte_Runnable_NtWrap_StaMd_SCom_EcuReset_Return() ((void)(0))
# endif /* Rte_Runnable_NtWrap_StaMd_SCom_EcuReset_Return */

# if defined (Rte_Runnable_NtWrap_StaMd_SCom_EcuReset_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_NtWrap_StaMd_SCom_EcuReset_Start
# endif
# if defined (Rte_Runnable_NtWrap_StaMd_SCom_EcuReset_Start)
#  undef Rte_Runnable_NtWrap_StaMd_SCom_EcuReset_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_NtWrap_StaMd_SCom_EcuReset_Start(void);
# else
#  define Rte_Runnable_NtWrap_StaMd_SCom_EcuReset_Start() ((void)(0))
# endif /* Rte_Runnable_NtWrap_StaMd_SCom_EcuReset_Start */

# if defined (Rte_Runnable_NtWrap_TrqCanc_Scom_SetCogTrqCal_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_NtWrap_TrqCanc_Scom_SetCogTrqCal_Return
# endif
# if defined (Rte_Runnable_NtWrap_TrqCanc_Scom_SetCogTrqCal_Return)
#  undef Rte_Runnable_NtWrap_TrqCanc_Scom_SetCogTrqCal_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_NtWrap_TrqCanc_Scom_SetCogTrqCal_Return(P2CONST(CoggingCancTrq, AUTOMATIC, RTE_NTWRAP_APPL_DATA) CogTrqCalPtr, UInt16 ID);
# else
#  define Rte_Runnable_NtWrap_TrqCanc_Scom_SetCogTrqCal_Return(arg1, arg2) ((void)(0))
# endif /* Rte_Runnable_NtWrap_TrqCanc_Scom_SetCogTrqCal_Return */

# if defined (Rte_Runnable_NtWrap_TrqCanc_Scom_SetCogTrqCal_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_NtWrap_TrqCanc_Scom_SetCogTrqCal_Start
# endif
# if defined (Rte_Runnable_NtWrap_TrqCanc_Scom_SetCogTrqCal_Start)
#  undef Rte_Runnable_NtWrap_TrqCanc_Scom_SetCogTrqCal_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_NtWrap_TrqCanc_Scom_SetCogTrqCal_Start(P2CONST(CoggingCancTrq, AUTOMATIC, RTE_NTWRAP_APPL_DATA) CogTrqCalPtr, UInt16 ID);
# else
#  define Rte_Runnable_NtWrap_TrqCanc_Scom_SetCogTrqCal_Start(arg1, arg2) ((void)(0))
# endif /* Rte_Runnable_NtWrap_TrqCanc_Scom_SetCogTrqCal_Start */

# if defined (Rte_Runnable_NtWrap_TrqCmdScl_SCom_Set_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_NtWrap_TrqCmdScl_SCom_Set_Return
# endif
# if defined (Rte_Runnable_NtWrap_TrqCmdScl_SCom_Set_Return)
#  undef Rte_Runnable_NtWrap_TrqCmdScl_SCom_Set_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_NtWrap_TrqCmdScl_SCom_Set_Return(Float Par_f32);
# else
#  define Rte_Runnable_NtWrap_TrqCmdScl_SCom_Set_Return(arg1) ((void)(0))
# endif /* Rte_Runnable_NtWrap_TrqCmdScl_SCom_Set_Return */

# if defined (Rte_Runnable_NtWrap_TrqCmdScl_SCom_Set_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_NtWrap_TrqCmdScl_SCom_Set_Start
# endif
# if defined (Rte_Runnable_NtWrap_TrqCmdScl_SCom_Set_Start)
#  undef Rte_Runnable_NtWrap_TrqCmdScl_SCom_Set_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_NtWrap_TrqCmdScl_SCom_Set_Start(Float Par_f32);
# else
#  define Rte_Runnable_NtWrap_TrqCmdScl_SCom_Set_Start(arg1) ((void)(0))
# endif /* Rte_Runnable_NtWrap_TrqCmdScl_SCom_Set_Start */

# if defined (Rte_Runnable_NvMProxy_GetErrorStatus_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_NvMProxy_GetErrorStatus_Return
# endif
# if defined (Rte_Runnable_NvMProxy_GetErrorStatus_Return)
#  undef Rte_Runnable_NvMProxy_GetErrorStatus_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_NvMProxy_GetErrorStatus_Return(UInt8 parg0, P2VAR(NvM_RequestResultType, AUTOMATIC, RTE_NVMPROXY_APPL_VAR) ErrorStatus);
# else
#  define Rte_Runnable_NvMProxy_GetErrorStatus_Return(arg1, arg2) ((void)(0))
# endif /* Rte_Runnable_NvMProxy_GetErrorStatus_Return */

# if defined (Rte_Runnable_NvMProxy_GetErrorStatus_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_NvMProxy_GetErrorStatus_Start
# endif
# if defined (Rte_Runnable_NvMProxy_GetErrorStatus_Start)
#  undef Rte_Runnable_NvMProxy_GetErrorStatus_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_NvMProxy_GetErrorStatus_Start(UInt8 parg0, P2VAR(NvM_RequestResultType, AUTOMATIC, RTE_NVMPROXY_APPL_VAR) ErrorStatus);
# else
#  define Rte_Runnable_NvMProxy_GetErrorStatus_Start(arg1, arg2) ((void)(0))
# endif /* Rte_Runnable_NvMProxy_GetErrorStatus_Start */

# if defined (Rte_Runnable_NvMProxy_NvMProxy_MainFunction_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_NvMProxy_NvMProxy_MainFunction_Return
# endif
# if defined (Rte_Runnable_NvMProxy_NvMProxy_MainFunction_Return)
#  undef Rte_Runnable_NvMProxy_NvMProxy_MainFunction_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_NvMProxy_NvMProxy_MainFunction_Return(void);
# else
#  define Rte_Runnable_NvMProxy_NvMProxy_MainFunction_Return() ((void)(0))
# endif /* Rte_Runnable_NvMProxy_NvMProxy_MainFunction_Return */

# if defined (Rte_Runnable_NvMProxy_NvMProxy_MainFunction_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_NvMProxy_NvMProxy_MainFunction_Start
# endif
# if defined (Rte_Runnable_NvMProxy_NvMProxy_MainFunction_Start)
#  undef Rte_Runnable_NvMProxy_NvMProxy_MainFunction_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_NvMProxy_NvMProxy_MainFunction_Start(void);
# else
#  define Rte_Runnable_NvMProxy_NvMProxy_MainFunction_Start() ((void)(0))
# endif /* Rte_Runnable_NvMProxy_NvMProxy_MainFunction_Start */

# if defined (Rte_Runnable_NvMProxy_SetRamBlockStatus_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_NvMProxy_SetRamBlockStatus_Return
# endif
# if defined (Rte_Runnable_NvMProxy_SetRamBlockStatus_Return)
#  undef Rte_Runnable_NvMProxy_SetRamBlockStatus_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_NvMProxy_SetRamBlockStatus_Return(UInt8 parg0, Boolean RamBlockStatus);
# else
#  define Rte_Runnable_NvMProxy_SetRamBlockStatus_Return(arg1, arg2) ((void)(0))
# endif /* Rte_Runnable_NvMProxy_SetRamBlockStatus_Return */

# if defined (Rte_Runnable_NvMProxy_SetRamBlockStatus_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_NvMProxy_SetRamBlockStatus_Start
# endif
# if defined (Rte_Runnable_NvMProxy_SetRamBlockStatus_Start)
#  undef Rte_Runnable_NvMProxy_SetRamBlockStatus_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_NvMProxy_SetRamBlockStatus_Start(UInt8 parg0, Boolean RamBlockStatus);
# else
#  define Rte_Runnable_NvMProxy_SetRamBlockStatus_Start(arg1, arg2) ((void)(0))
# endif /* Rte_Runnable_NvMProxy_SetRamBlockStatus_Start */

# if defined (Rte_Runnable_NvMProxy_WriteBlock_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_NvMProxy_WriteBlock_Return
# endif
# if defined (Rte_Runnable_NvMProxy_WriteBlock_Return)
#  undef Rte_Runnable_NvMProxy_WriteBlock_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_NvMProxy_WriteBlock_Return(UInt8 parg0, P2CONST(NvM_DestPtr, AUTOMATIC, RTE_NVMPROXY_APPL_DATA) DstPtr);
# else
#  define Rte_Runnable_NvMProxy_WriteBlock_Return(arg1, arg2) ((void)(0))
# endif /* Rte_Runnable_NvMProxy_WriteBlock_Return */

# if defined (Rte_Runnable_NvMProxy_WriteBlock_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_NvMProxy_WriteBlock_Start
# endif
# if defined (Rte_Runnable_NvMProxy_WriteBlock_Start)
#  undef Rte_Runnable_NvMProxy_WriteBlock_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_NvMProxy_WriteBlock_Start(UInt8 parg0, P2CONST(NvM_DestPtr, AUTOMATIC, RTE_NVMPROXY_APPL_DATA) DstPtr);
# else
#  define Rte_Runnable_NvMProxy_WriteBlock_Start(arg1, arg2) ((void)(0))
# endif /* Rte_Runnable_NvMProxy_WriteBlock_Start */

# if defined (Rte_Runnable_NvM_EraseBlock_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_NvM_EraseBlock_Return
# endif
# if defined (Rte_Runnable_NvM_EraseBlock_Return)
#  undef Rte_Runnable_NvM_EraseBlock_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_NvM_EraseBlock_Return(NvM_BlockIdType parg0);
# else
#  define Rte_Runnable_NvM_EraseBlock_Return(arg1) ((void)(0))
# endif /* Rte_Runnable_NvM_EraseBlock_Return */

# if defined (Rte_Runnable_NvM_EraseBlock_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_NvM_EraseBlock_Start
# endif
# if defined (Rte_Runnable_NvM_EraseBlock_Start)
#  undef Rte_Runnable_NvM_EraseBlock_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_NvM_EraseBlock_Start(NvM_BlockIdType parg0);
# else
#  define Rte_Runnable_NvM_EraseBlock_Start(arg1) ((void)(0))
# endif /* Rte_Runnable_NvM_EraseBlock_Start */

# if defined (Rte_Runnable_NvM_GetErrorStatus_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_NvM_GetErrorStatus_Return
# endif
# if defined (Rte_Runnable_NvM_GetErrorStatus_Return)
#  undef Rte_Runnable_NvM_GetErrorStatus_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_NvM_GetErrorStatus_Return(NvM_BlockIdType parg0, P2VAR(NvM_RequestResultType, AUTOMATIC, RTE_NVM_APPL_VAR) ErrorStatus);
# else
#  define Rte_Runnable_NvM_GetErrorStatus_Return(arg1, arg2) ((void)(0))
# endif /* Rte_Runnable_NvM_GetErrorStatus_Return */

# if defined (Rte_Runnable_NvM_GetErrorStatus_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_NvM_GetErrorStatus_Start
# endif
# if defined (Rte_Runnable_NvM_GetErrorStatus_Start)
#  undef Rte_Runnable_NvM_GetErrorStatus_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_NvM_GetErrorStatus_Start(NvM_BlockIdType parg0, P2VAR(NvM_RequestResultType, AUTOMATIC, RTE_NVM_APPL_VAR) ErrorStatus);
# else
#  define Rte_Runnable_NvM_GetErrorStatus_Start(arg1, arg2) ((void)(0))
# endif /* Rte_Runnable_NvM_GetErrorStatus_Start */

# if defined (Rte_Runnable_NvM_InvalidateNvBlock_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_NvM_InvalidateNvBlock_Return
# endif
# if defined (Rte_Runnable_NvM_InvalidateNvBlock_Return)
#  undef Rte_Runnable_NvM_InvalidateNvBlock_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_NvM_InvalidateNvBlock_Return(NvM_BlockIdType parg0);
# else
#  define Rte_Runnable_NvM_InvalidateNvBlock_Return(arg1) ((void)(0))
# endif /* Rte_Runnable_NvM_InvalidateNvBlock_Return */

# if defined (Rte_Runnable_NvM_InvalidateNvBlock_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_NvM_InvalidateNvBlock_Start
# endif
# if defined (Rte_Runnable_NvM_InvalidateNvBlock_Start)
#  undef Rte_Runnable_NvM_InvalidateNvBlock_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_NvM_InvalidateNvBlock_Start(NvM_BlockIdType parg0);
# else
#  define Rte_Runnable_NvM_InvalidateNvBlock_Start(arg1) ((void)(0))
# endif /* Rte_Runnable_NvM_InvalidateNvBlock_Start */

# if defined (Rte_Runnable_NvM_NvM_MainFunction_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_NvM_NvM_MainFunction_Return
# endif
# if defined (Rte_Runnable_NvM_NvM_MainFunction_Return)
#  undef Rte_Runnable_NvM_NvM_MainFunction_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_NvM_NvM_MainFunction_Return(void);
# else
#  define Rte_Runnable_NvM_NvM_MainFunction_Return() ((void)(0))
# endif /* Rte_Runnable_NvM_NvM_MainFunction_Return */

# if defined (Rte_Runnable_NvM_NvM_MainFunction_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_NvM_NvM_MainFunction_Start
# endif
# if defined (Rte_Runnable_NvM_NvM_MainFunction_Start)
#  undef Rte_Runnable_NvM_NvM_MainFunction_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_NvM_NvM_MainFunction_Start(void);
# else
#  define Rte_Runnable_NvM_NvM_MainFunction_Start() ((void)(0))
# endif /* Rte_Runnable_NvM_NvM_MainFunction_Start */

# if defined (Rte_Runnable_NvM_ReadBlock_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_NvM_ReadBlock_Return
# endif
# if defined (Rte_Runnable_NvM_ReadBlock_Return)
#  undef Rte_Runnable_NvM_ReadBlock_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_NvM_ReadBlock_Return(NvM_BlockIdType parg0, P2VAR(NvM_DestPtr, AUTOMATIC, RTE_NVM_APPL_VAR) DstPtr);
# else
#  define Rte_Runnable_NvM_ReadBlock_Return(arg1, arg2) ((void)(0))
# endif /* Rte_Runnable_NvM_ReadBlock_Return */

# if defined (Rte_Runnable_NvM_ReadBlock_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_NvM_ReadBlock_Start
# endif
# if defined (Rte_Runnable_NvM_ReadBlock_Start)
#  undef Rte_Runnable_NvM_ReadBlock_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_NvM_ReadBlock_Start(NvM_BlockIdType parg0, P2VAR(NvM_DestPtr, AUTOMATIC, RTE_NVM_APPL_VAR) DstPtr);
# else
#  define Rte_Runnable_NvM_ReadBlock_Start(arg1, arg2) ((void)(0))
# endif /* Rte_Runnable_NvM_ReadBlock_Start */

# if defined (Rte_Runnable_NvM_SetBlockProtection_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_NvM_SetBlockProtection_Return
# endif
# if defined (Rte_Runnable_NvM_SetBlockProtection_Return)
#  undef Rte_Runnable_NvM_SetBlockProtection_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_NvM_SetBlockProtection_Return(NvM_BlockIdType parg0, Boolean ProtectionEnabled);
# else
#  define Rte_Runnable_NvM_SetBlockProtection_Return(arg1, arg2) ((void)(0))
# endif /* Rte_Runnable_NvM_SetBlockProtection_Return */

# if defined (Rte_Runnable_NvM_SetBlockProtection_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_NvM_SetBlockProtection_Start
# endif
# if defined (Rte_Runnable_NvM_SetBlockProtection_Start)
#  undef Rte_Runnable_NvM_SetBlockProtection_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_NvM_SetBlockProtection_Start(NvM_BlockIdType parg0, Boolean ProtectionEnabled);
# else
#  define Rte_Runnable_NvM_SetBlockProtection_Start(arg1, arg2) ((void)(0))
# endif /* Rte_Runnable_NvM_SetBlockProtection_Start */

# if defined (Rte_Runnable_NvM_SetRamBlockStatus_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_NvM_SetRamBlockStatus_Return
# endif
# if defined (Rte_Runnable_NvM_SetRamBlockStatus_Return)
#  undef Rte_Runnable_NvM_SetRamBlockStatus_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_NvM_SetRamBlockStatus_Return(NvM_BlockIdType parg0, Boolean RamBlockStatus);
# else
#  define Rte_Runnable_NvM_SetRamBlockStatus_Return(arg1, arg2) ((void)(0))
# endif /* Rte_Runnable_NvM_SetRamBlockStatus_Return */

# if defined (Rte_Runnable_NvM_SetRamBlockStatus_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_NvM_SetRamBlockStatus_Start
# endif
# if defined (Rte_Runnable_NvM_SetRamBlockStatus_Start)
#  undef Rte_Runnable_NvM_SetRamBlockStatus_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_NvM_SetRamBlockStatus_Start(NvM_BlockIdType parg0, Boolean RamBlockStatus);
# else
#  define Rte_Runnable_NvM_SetRamBlockStatus_Start(arg1, arg2) ((void)(0))
# endif /* Rte_Runnable_NvM_SetRamBlockStatus_Start */

# if defined (Rte_Runnable_NvM_WriteBlock_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_NvM_WriteBlock_Return
# endif
# if defined (Rte_Runnable_NvM_WriteBlock_Return)
#  undef Rte_Runnable_NvM_WriteBlock_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_NvM_WriteBlock_Return(NvM_BlockIdType parg0, P2CONST(NvM_DestPtr, AUTOMATIC, RTE_NVM_APPL_DATA) DstPtr);
# else
#  define Rte_Runnable_NvM_WriteBlock_Return(arg1, arg2) ((void)(0))
# endif /* Rte_Runnable_NvM_WriteBlock_Return */

# if defined (Rte_Runnable_NvM_WriteBlock_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_NvM_WriteBlock_Start
# endif
# if defined (Rte_Runnable_NvM_WriteBlock_Start)
#  undef Rte_Runnable_NvM_WriteBlock_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_NvM_WriteBlock_Start(NvM_BlockIdType parg0, P2CONST(NvM_DestPtr, AUTOMATIC, RTE_NVM_APPL_DATA) DstPtr);
# else
#  define Rte_Runnable_NvM_WriteBlock_Start(arg1, arg2) ((void)(0))
# endif /* Rte_Runnable_NvM_WriteBlock_Start */

# if defined (Rte_Runnable_RteErrata10_RteErrata10_Trns_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_RteErrata10_RteErrata10_Trns_Return
# endif
# if defined (Rte_Runnable_RteErrata10_RteErrata10_Trns_Return)
#  undef Rte_Runnable_RteErrata10_RteErrata10_Trns_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_RteErrata10_RteErrata10_Trns_Return(void);
# else
#  define Rte_Runnable_RteErrata10_RteErrata10_Trns_Return() ((void)(0))
# endif /* Rte_Runnable_RteErrata10_RteErrata10_Trns_Return */

# if defined (Rte_Runnable_RteErrata10_RteErrata10_Trns_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_RteErrata10_RteErrata10_Trns_Start
# endif
# if defined (Rte_Runnable_RteErrata10_RteErrata10_Trns_Start)
#  undef Rte_Runnable_RteErrata10_RteErrata10_Trns_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_RteErrata10_RteErrata10_Trns_Start(void);
# else
#  define Rte_Runnable_RteErrata10_RteErrata10_Trns_Start() ((void)(0))
# endif /* Rte_Runnable_RteErrata10_RteErrata10_Trns_Start */

# if defined (Rte_Runnable_RteErrata8_RteErrata8_Trns_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_RteErrata8_RteErrata8_Trns_Return
# endif
# if defined (Rte_Runnable_RteErrata8_RteErrata8_Trns_Return)
#  undef Rte_Runnable_RteErrata8_RteErrata8_Trns_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_RteErrata8_RteErrata8_Trns_Return(void);
# else
#  define Rte_Runnable_RteErrata8_RteErrata8_Trns_Return() ((void)(0))
# endif /* Rte_Runnable_RteErrata8_RteErrata8_Trns_Return */

# if defined (Rte_Runnable_RteErrata8_RteErrata8_Trns_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_RteErrata8_RteErrata8_Trns_Start
# endif
# if defined (Rte_Runnable_RteErrata8_RteErrata8_Trns_Start)
#  undef Rte_Runnable_RteErrata8_RteErrata8_Trns_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_RteErrata8_RteErrata8_Trns_Start(void);
# else
#  define Rte_Runnable_RteErrata8_RteErrata8_Trns_Start() ((void)(0))
# endif /* Rte_Runnable_RteErrata8_RteErrata8_Trns_Start */

# if defined (Rte_Runnable_RteErrata9_RteErrata9_Trns_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_RteErrata9_RteErrata9_Trns_Return
# endif
# if defined (Rte_Runnable_RteErrata9_RteErrata9_Trns_Return)
#  undef Rte_Runnable_RteErrata9_RteErrata9_Trns_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_RteErrata9_RteErrata9_Trns_Return(void);
# else
#  define Rte_Runnable_RteErrata9_RteErrata9_Trns_Return() ((void)(0))
# endif /* Rte_Runnable_RteErrata9_RteErrata9_Trns_Return */

# if defined (Rte_Runnable_RteErrata9_RteErrata9_Trns_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_RteErrata9_RteErrata9_Trns_Start
# endif
# if defined (Rte_Runnable_RteErrata9_RteErrata9_Trns_Start)
#  undef Rte_Runnable_RteErrata9_RteErrata9_Trns_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_RteErrata9_RteErrata9_Trns_Start(void);
# else
#  define Rte_Runnable_RteErrata9_RteErrata9_Trns_Start() ((void)(0))
# endif /* Rte_Runnable_RteErrata9_RteErrata9_Trns_Start */

# if defined (Rte_Runnable_Sa_BkCpPc_BkCpPc_Per1_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Sa_BkCpPc_BkCpPc_Per1_Return
# endif
# if defined (Rte_Runnable_Sa_BkCpPc_BkCpPc_Per1_Return)
#  undef Rte_Runnable_Sa_BkCpPc_BkCpPc_Per1_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Sa_BkCpPc_BkCpPc_Per1_Return(void);
# else
#  define Rte_Runnable_Sa_BkCpPc_BkCpPc_Per1_Return() ((void)(0))
# endif /* Rte_Runnable_Sa_BkCpPc_BkCpPc_Per1_Return */

# if defined (Rte_Runnable_Sa_BkCpPc_BkCpPc_Per1_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Sa_BkCpPc_BkCpPc_Per1_Start
# endif
# if defined (Rte_Runnable_Sa_BkCpPc_BkCpPc_Per1_Start)
#  undef Rte_Runnable_Sa_BkCpPc_BkCpPc_Per1_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Sa_BkCpPc_BkCpPc_Per1_Start(void);
# else
#  define Rte_Runnable_Sa_BkCpPc_BkCpPc_Per1_Start() ((void)(0))
# endif /* Rte_Runnable_Sa_BkCpPc_BkCpPc_Per1_Start */

# if defined (Rte_Runnable_Sa_BkCpPc_BkCpPc_Trns1_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Sa_BkCpPc_BkCpPc_Trns1_Return
# endif
# if defined (Rte_Runnable_Sa_BkCpPc_BkCpPc_Trns1_Return)
#  undef Rte_Runnable_Sa_BkCpPc_BkCpPc_Trns1_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Sa_BkCpPc_BkCpPc_Trns1_Return(void);
# else
#  define Rte_Runnable_Sa_BkCpPc_BkCpPc_Trns1_Return() ((void)(0))
# endif /* Rte_Runnable_Sa_BkCpPc_BkCpPc_Trns1_Return */

# if defined (Rte_Runnable_Sa_BkCpPc_BkCpPc_Trns1_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Sa_BkCpPc_BkCpPc_Trns1_Start
# endif
# if defined (Rte_Runnable_Sa_BkCpPc_BkCpPc_Trns1_Start)
#  undef Rte_Runnable_Sa_BkCpPc_BkCpPc_Trns1_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Sa_BkCpPc_BkCpPc_Trns1_Start(void);
# else
#  define Rte_Runnable_Sa_BkCpPc_BkCpPc_Trns1_Start() ((void)(0))
# endif /* Rte_Runnable_Sa_BkCpPc_BkCpPc_Trns1_Start */

# if defined (Rte_Runnable_Sa_BkCpPc_BkCpPc_Trns2_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Sa_BkCpPc_BkCpPc_Trns2_Return
# endif
# if defined (Rte_Runnable_Sa_BkCpPc_BkCpPc_Trns2_Return)
#  undef Rte_Runnable_Sa_BkCpPc_BkCpPc_Trns2_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Sa_BkCpPc_BkCpPc_Trns2_Return(void);
# else
#  define Rte_Runnable_Sa_BkCpPc_BkCpPc_Trns2_Return() ((void)(0))
# endif /* Rte_Runnable_Sa_BkCpPc_BkCpPc_Trns2_Return */

# if defined (Rte_Runnable_Sa_BkCpPc_BkCpPc_Trns2_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Sa_BkCpPc_BkCpPc_Trns2_Start
# endif
# if defined (Rte_Runnable_Sa_BkCpPc_BkCpPc_Trns2_Start)
#  undef Rte_Runnable_Sa_BkCpPc_BkCpPc_Trns2_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Sa_BkCpPc_BkCpPc_Trns2_Start(void);
# else
#  define Rte_Runnable_Sa_BkCpPc_BkCpPc_Trns2_Start() ((void)(0))
# endif /* Rte_Runnable_Sa_BkCpPc_BkCpPc_Trns2_Start */

# if defined (Rte_Runnable_Sa_BkCpPc_CapPcDcStub_OP_SET_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Sa_BkCpPc_CapPcDcStub_OP_SET_Return
# endif
# if defined (Rte_Runnable_Sa_BkCpPc_CapPcDcStub_OP_SET_Return)
#  undef Rte_Runnable_Sa_BkCpPc_CapPcDcStub_OP_SET_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Sa_BkCpPc_CapPcDcStub_OP_SET_Return(IoHwAb_BoolType signal);
# else
#  define Rte_Runnable_Sa_BkCpPc_CapPcDcStub_OP_SET_Return(arg1) ((void)(0))
# endif /* Rte_Runnable_Sa_BkCpPc_CapPcDcStub_OP_SET_Return */

# if defined (Rte_Runnable_Sa_BkCpPc_CapPcDcStub_OP_SET_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Sa_BkCpPc_CapPcDcStub_OP_SET_Start
# endif
# if defined (Rte_Runnable_Sa_BkCpPc_CapPcDcStub_OP_SET_Start)
#  undef Rte_Runnable_Sa_BkCpPc_CapPcDcStub_OP_SET_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Sa_BkCpPc_CapPcDcStub_OP_SET_Start(IoHwAb_BoolType signal);
# else
#  define Rte_Runnable_Sa_BkCpPc_CapPcDcStub_OP_SET_Start(arg1) ((void)(0))
# endif /* Rte_Runnable_Sa_BkCpPc_CapPcDcStub_OP_SET_Start */

# if defined (Rte_Runnable_Sa_CDDInterface_CDDInterface_Init1_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Sa_CDDInterface_CDDInterface_Init1_Return
# endif
# if defined (Rte_Runnable_Sa_CDDInterface_CDDInterface_Init1_Return)
#  undef Rte_Runnable_Sa_CDDInterface_CDDInterface_Init1_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Sa_CDDInterface_CDDInterface_Init1_Return(void);
# else
#  define Rte_Runnable_Sa_CDDInterface_CDDInterface_Init1_Return() ((void)(0))
# endif /* Rte_Runnable_Sa_CDDInterface_CDDInterface_Init1_Return */

# if defined (Rte_Runnable_Sa_CDDInterface_CDDInterface_Init1_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Sa_CDDInterface_CDDInterface_Init1_Start
# endif
# if defined (Rte_Runnable_Sa_CDDInterface_CDDInterface_Init1_Start)
#  undef Rte_Runnable_Sa_CDDInterface_CDDInterface_Init1_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Sa_CDDInterface_CDDInterface_Init1_Start(void);
# else
#  define Rte_Runnable_Sa_CDDInterface_CDDInterface_Init1_Start() ((void)(0))
# endif /* Rte_Runnable_Sa_CDDInterface_CDDInterface_Init1_Start */

# if defined (Rte_Runnable_Sa_CDDInterface_CDDInterface_Init2_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Sa_CDDInterface_CDDInterface_Init2_Return
# endif
# if defined (Rte_Runnable_Sa_CDDInterface_CDDInterface_Init2_Return)
#  undef Rte_Runnable_Sa_CDDInterface_CDDInterface_Init2_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Sa_CDDInterface_CDDInterface_Init2_Return(void);
# else
#  define Rte_Runnable_Sa_CDDInterface_CDDInterface_Init2_Return() ((void)(0))
# endif /* Rte_Runnable_Sa_CDDInterface_CDDInterface_Init2_Return */

# if defined (Rte_Runnable_Sa_CDDInterface_CDDInterface_Init2_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Sa_CDDInterface_CDDInterface_Init2_Start
# endif
# if defined (Rte_Runnable_Sa_CDDInterface_CDDInterface_Init2_Start)
#  undef Rte_Runnable_Sa_CDDInterface_CDDInterface_Init2_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Sa_CDDInterface_CDDInterface_Init2_Start(void);
# else
#  define Rte_Runnable_Sa_CDDInterface_CDDInterface_Init2_Start() ((void)(0))
# endif /* Rte_Runnable_Sa_CDDInterface_CDDInterface_Init2_Start */

# if defined (Rte_Runnable_Sa_CDDInterface_CDDInterface_Per1_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Sa_CDDInterface_CDDInterface_Per1_Return
# endif
# if defined (Rte_Runnable_Sa_CDDInterface_CDDInterface_Per1_Return)
#  undef Rte_Runnable_Sa_CDDInterface_CDDInterface_Per1_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Sa_CDDInterface_CDDInterface_Per1_Return(void);
# else
#  define Rte_Runnable_Sa_CDDInterface_CDDInterface_Per1_Return() ((void)(0))
# endif /* Rte_Runnable_Sa_CDDInterface_CDDInterface_Per1_Return */

# if defined (Rte_Runnable_Sa_CDDInterface_CDDInterface_Per1_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Sa_CDDInterface_CDDInterface_Per1_Start
# endif
# if defined (Rte_Runnable_Sa_CDDInterface_CDDInterface_Per1_Start)
#  undef Rte_Runnable_Sa_CDDInterface_CDDInterface_Per1_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Sa_CDDInterface_CDDInterface_Per1_Start(void);
# else
#  define Rte_Runnable_Sa_CDDInterface_CDDInterface_Per1_Start() ((void)(0))
# endif /* Rte_Runnable_Sa_CDDInterface_CDDInterface_Per1_Start */

# if defined (Rte_Runnable_Sa_CDDInterface_CDDInterface_Per2_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Sa_CDDInterface_CDDInterface_Per2_Return
# endif
# if defined (Rte_Runnable_Sa_CDDInterface_CDDInterface_Per2_Return)
#  undef Rte_Runnable_Sa_CDDInterface_CDDInterface_Per2_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Sa_CDDInterface_CDDInterface_Per2_Return(void);
# else
#  define Rte_Runnable_Sa_CDDInterface_CDDInterface_Per2_Return() ((void)(0))
# endif /* Rte_Runnable_Sa_CDDInterface_CDDInterface_Per2_Return */

# if defined (Rte_Runnable_Sa_CDDInterface_CDDInterface_Per2_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Sa_CDDInterface_CDDInterface_Per2_Start
# endif
# if defined (Rte_Runnable_Sa_CDDInterface_CDDInterface_Per2_Start)
#  undef Rte_Runnable_Sa_CDDInterface_CDDInterface_Per2_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Sa_CDDInterface_CDDInterface_Per2_Start(void);
# else
#  define Rte_Runnable_Sa_CDDInterface_CDDInterface_Per2_Start() ((void)(0))
# endif /* Rte_Runnable_Sa_CDDInterface_CDDInterface_Per2_Start */

# if defined (Rte_Runnable_Sa_CDDInterface_CDDInterface_Per4_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Sa_CDDInterface_CDDInterface_Per4_Return
# endif
# if defined (Rte_Runnable_Sa_CDDInterface_CDDInterface_Per4_Return)
#  undef Rte_Runnable_Sa_CDDInterface_CDDInterface_Per4_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Sa_CDDInterface_CDDInterface_Per4_Return(void);
# else
#  define Rte_Runnable_Sa_CDDInterface_CDDInterface_Per4_Return() ((void)(0))
# endif /* Rte_Runnable_Sa_CDDInterface_CDDInterface_Per4_Return */

# if defined (Rte_Runnable_Sa_CDDInterface_CDDInterface_Per4_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Sa_CDDInterface_CDDInterface_Per4_Start
# endif
# if defined (Rte_Runnable_Sa_CDDInterface_CDDInterface_Per4_Start)
#  undef Rte_Runnable_Sa_CDDInterface_CDDInterface_Per4_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Sa_CDDInterface_CDDInterface_Per4_Start(void);
# else
#  define Rte_Runnable_Sa_CDDInterface_CDDInterface_Per4_Start() ((void)(0))
# endif /* Rte_Runnable_Sa_CDDInterface_CDDInterface_Per4_Start */

# if defined (Rte_Runnable_Sa_CDDInterface_MtrVelCDDInterface_GetMtrVelSignals_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Sa_CDDInterface_MtrVelCDDInterface_GetMtrVelSignals_Return
# endif
# if defined (Rte_Runnable_Sa_CDDInterface_MtrVelCDDInterface_GetMtrVelSignals_Return)
#  undef Rte_Runnable_Sa_CDDInterface_MtrVelCDDInterface_GetMtrVelSignals_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Sa_CDDInterface_MtrVelCDDInterface_GetMtrVelSignals_Return(P2VAR(SInt16, AUTOMATIC, RTE_SA_CDDINTERFACE_APPL_VAR) SinAvg_Uls_T_s2p13, P2VAR(SInt16, AUTOMATIC, RTE_SA_CDDINTERFACE_APPL_VAR) CosAvg_Uls_T_s2p13, P2VAR(UInt16, AUTOMATIC, RTE_SA_CDDINTERFACE_APPL_VAR) PosAvg_Rev_T_u0p16, P2VAR(UInt16, AUTOMATIC, RTE_SA_CDDINTERFACE_APPL_VAR) TimeAvg_uS_T_u16p0);
# else
#  define Rte_Runnable_Sa_CDDInterface_MtrVelCDDInterface_GetMtrVelSignals_Return(arg1, arg2, arg3, arg4) ((void)(0))
# endif /* Rte_Runnable_Sa_CDDInterface_MtrVelCDDInterface_GetMtrVelSignals_Return */

# if defined (Rte_Runnable_Sa_CDDInterface_MtrVelCDDInterface_GetMtrVelSignals_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Sa_CDDInterface_MtrVelCDDInterface_GetMtrVelSignals_Start
# endif
# if defined (Rte_Runnable_Sa_CDDInterface_MtrVelCDDInterface_GetMtrVelSignals_Start)
#  undef Rte_Runnable_Sa_CDDInterface_MtrVelCDDInterface_GetMtrVelSignals_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Sa_CDDInterface_MtrVelCDDInterface_GetMtrVelSignals_Start(P2VAR(SInt16, AUTOMATIC, RTE_SA_CDDINTERFACE_APPL_VAR) SinAvg_Uls_T_s2p13, P2VAR(SInt16, AUTOMATIC, RTE_SA_CDDINTERFACE_APPL_VAR) CosAvg_Uls_T_s2p13, P2VAR(UInt16, AUTOMATIC, RTE_SA_CDDINTERFACE_APPL_VAR) PosAvg_Rev_T_u0p16, P2VAR(UInt16, AUTOMATIC, RTE_SA_CDDINTERFACE_APPL_VAR) TimeAvg_uS_T_u16p0);
# else
#  define Rte_Runnable_Sa_CDDInterface_MtrVelCDDInterface_GetMtrVelSignals_Start(arg1, arg2, arg3, arg4) ((void)(0))
# endif /* Rte_Runnable_Sa_CDDInterface_MtrVelCDDInterface_GetMtrVelSignals_Start */

# if defined (Rte_Runnable_Sa_CmMtrCurr_CmMtrCurrTempOffset_Scom_Get_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Sa_CmMtrCurr_CmMtrCurrTempOffset_Scom_Get_Return
# endif
# if defined (Rte_Runnable_Sa_CmMtrCurr_CmMtrCurrTempOffset_Scom_Get_Return)
#  undef Rte_Runnable_Sa_CmMtrCurr_CmMtrCurrTempOffset_Scom_Get_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Sa_CmMtrCurr_CmMtrCurrTempOffset_Scom_Get_Return(P2VAR(CurrTempOffsetType, AUTOMATIC, RTE_SA_CMMTRCURR_APPL_VAR) CurrTempOffCal);
# else
#  define Rte_Runnable_Sa_CmMtrCurr_CmMtrCurrTempOffset_Scom_Get_Return(arg1) ((void)(0))
# endif /* Rte_Runnable_Sa_CmMtrCurr_CmMtrCurrTempOffset_Scom_Get_Return */

# if defined (Rte_Runnable_Sa_CmMtrCurr_CmMtrCurrTempOffset_Scom_Get_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Sa_CmMtrCurr_CmMtrCurrTempOffset_Scom_Get_Start
# endif
# if defined (Rte_Runnable_Sa_CmMtrCurr_CmMtrCurrTempOffset_Scom_Get_Start)
#  undef Rte_Runnable_Sa_CmMtrCurr_CmMtrCurrTempOffset_Scom_Get_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Sa_CmMtrCurr_CmMtrCurrTempOffset_Scom_Get_Start(P2VAR(CurrTempOffsetType, AUTOMATIC, RTE_SA_CMMTRCURR_APPL_VAR) CurrTempOffCal);
# else
#  define Rte_Runnable_Sa_CmMtrCurr_CmMtrCurrTempOffset_Scom_Get_Start(arg1) ((void)(0))
# endif /* Rte_Runnable_Sa_CmMtrCurr_CmMtrCurrTempOffset_Scom_Get_Start */

# if defined (Rte_Runnable_Sa_CmMtrCurr_CmMtrCurrTempOffset_Scom_Set_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Sa_CmMtrCurr_CmMtrCurrTempOffset_Scom_Set_Return
# endif
# if defined (Rte_Runnable_Sa_CmMtrCurr_CmMtrCurrTempOffset_Scom_Set_Return)
#  undef Rte_Runnable_Sa_CmMtrCurr_CmMtrCurrTempOffset_Scom_Set_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Sa_CmMtrCurr_CmMtrCurrTempOffset_Scom_Set_Return(P2CONST(CurrTempOffsetType, AUTOMATIC, RTE_SA_CMMTRCURR_APPL_DATA) CurrTempOffCal);
# else
#  define Rte_Runnable_Sa_CmMtrCurr_CmMtrCurrTempOffset_Scom_Set_Return(arg1) ((void)(0))
# endif /* Rte_Runnable_Sa_CmMtrCurr_CmMtrCurrTempOffset_Scom_Set_Return */

# if defined (Rte_Runnable_Sa_CmMtrCurr_CmMtrCurrTempOffset_Scom_Set_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Sa_CmMtrCurr_CmMtrCurrTempOffset_Scom_Set_Start
# endif
# if defined (Rte_Runnable_Sa_CmMtrCurr_CmMtrCurrTempOffset_Scom_Set_Start)
#  undef Rte_Runnable_Sa_CmMtrCurr_CmMtrCurrTempOffset_Scom_Set_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Sa_CmMtrCurr_CmMtrCurrTempOffset_Scom_Set_Start(P2CONST(CurrTempOffsetType, AUTOMATIC, RTE_SA_CMMTRCURR_APPL_DATA) CurrTempOffCal);
# else
#  define Rte_Runnable_Sa_CmMtrCurr_CmMtrCurrTempOffset_Scom_Set_Start(arg1) ((void)(0))
# endif /* Rte_Runnable_Sa_CmMtrCurr_CmMtrCurrTempOffset_Scom_Set_Start */

# if defined (Rte_Runnable_Sa_CmMtrCurr_CmMtrCurr_Init_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Sa_CmMtrCurr_CmMtrCurr_Init_Return
# endif
# if defined (Rte_Runnable_Sa_CmMtrCurr_CmMtrCurr_Init_Return)
#  undef Rte_Runnable_Sa_CmMtrCurr_CmMtrCurr_Init_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Sa_CmMtrCurr_CmMtrCurr_Init_Return(void);
# else
#  define Rte_Runnable_Sa_CmMtrCurr_CmMtrCurr_Init_Return() ((void)(0))
# endif /* Rte_Runnable_Sa_CmMtrCurr_CmMtrCurr_Init_Return */

# if defined (Rte_Runnable_Sa_CmMtrCurr_CmMtrCurr_Init_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Sa_CmMtrCurr_CmMtrCurr_Init_Start
# endif
# if defined (Rte_Runnable_Sa_CmMtrCurr_CmMtrCurr_Init_Start)
#  undef Rte_Runnable_Sa_CmMtrCurr_CmMtrCurr_Init_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Sa_CmMtrCurr_CmMtrCurr_Init_Start(void);
# else
#  define Rte_Runnable_Sa_CmMtrCurr_CmMtrCurr_Init_Start() ((void)(0))
# endif /* Rte_Runnable_Sa_CmMtrCurr_CmMtrCurr_Init_Start */

# if defined (Rte_Runnable_Sa_CmMtrCurr_CmMtrCurr_Per1_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Sa_CmMtrCurr_CmMtrCurr_Per1_Return
# endif
# if defined (Rte_Runnable_Sa_CmMtrCurr_CmMtrCurr_Per1_Return)
#  undef Rte_Runnable_Sa_CmMtrCurr_CmMtrCurr_Per1_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Sa_CmMtrCurr_CmMtrCurr_Per1_Return(void);
# else
#  define Rte_Runnable_Sa_CmMtrCurr_CmMtrCurr_Per1_Return() ((void)(0))
# endif /* Rte_Runnable_Sa_CmMtrCurr_CmMtrCurr_Per1_Return */

# if defined (Rte_Runnable_Sa_CmMtrCurr_CmMtrCurr_Per1_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Sa_CmMtrCurr_CmMtrCurr_Per1_Start
# endif
# if defined (Rte_Runnable_Sa_CmMtrCurr_CmMtrCurr_Per1_Start)
#  undef Rte_Runnable_Sa_CmMtrCurr_CmMtrCurr_Per1_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Sa_CmMtrCurr_CmMtrCurr_Per1_Start(void);
# else
#  define Rte_Runnable_Sa_CmMtrCurr_CmMtrCurr_Per1_Start() ((void)(0))
# endif /* Rte_Runnable_Sa_CmMtrCurr_CmMtrCurr_Per1_Start */

# if defined (Rte_Runnable_Sa_CmMtrCurr_CmMtrCurr_Per2_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Sa_CmMtrCurr_CmMtrCurr_Per2_Return
# endif
# if defined (Rte_Runnable_Sa_CmMtrCurr_CmMtrCurr_Per2_Return)
#  undef Rte_Runnable_Sa_CmMtrCurr_CmMtrCurr_Per2_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Sa_CmMtrCurr_CmMtrCurr_Per2_Return(void);
# else
#  define Rte_Runnable_Sa_CmMtrCurr_CmMtrCurr_Per2_Return() ((void)(0))
# endif /* Rte_Runnable_Sa_CmMtrCurr_CmMtrCurr_Per2_Return */

# if defined (Rte_Runnable_Sa_CmMtrCurr_CmMtrCurr_Per2_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Sa_CmMtrCurr_CmMtrCurr_Per2_Start
# endif
# if defined (Rte_Runnable_Sa_CmMtrCurr_CmMtrCurr_Per2_Start)
#  undef Rte_Runnable_Sa_CmMtrCurr_CmMtrCurr_Per2_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Sa_CmMtrCurr_CmMtrCurr_Per2_Start(void);
# else
#  define Rte_Runnable_Sa_CmMtrCurr_CmMtrCurr_Per2_Start() ((void)(0))
# endif /* Rte_Runnable_Sa_CmMtrCurr_CmMtrCurr_Per2_Start */

# if defined (Rte_Runnable_Sa_CmMtrCurr_CmMtrCurr_Per3_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Sa_CmMtrCurr_CmMtrCurr_Per3_Return
# endif
# if defined (Rte_Runnable_Sa_CmMtrCurr_CmMtrCurr_Per3_Return)
#  undef Rte_Runnable_Sa_CmMtrCurr_CmMtrCurr_Per3_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Sa_CmMtrCurr_CmMtrCurr_Per3_Return(void);
# else
#  define Rte_Runnable_Sa_CmMtrCurr_CmMtrCurr_Per3_Return() ((void)(0))
# endif /* Rte_Runnable_Sa_CmMtrCurr_CmMtrCurr_Per3_Return */

# if defined (Rte_Runnable_Sa_CmMtrCurr_CmMtrCurr_Per3_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Sa_CmMtrCurr_CmMtrCurr_Per3_Start
# endif
# if defined (Rte_Runnable_Sa_CmMtrCurr_CmMtrCurr_Per3_Start)
#  undef Rte_Runnable_Sa_CmMtrCurr_CmMtrCurr_Per3_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Sa_CmMtrCurr_CmMtrCurr_Per3_Start(void);
# else
#  define Rte_Runnable_Sa_CmMtrCurr_CmMtrCurr_Per3_Start() ((void)(0))
# endif /* Rte_Runnable_Sa_CmMtrCurr_CmMtrCurr_Per3_Start */

# if defined (Rte_Runnable_Sa_CmMtrCurr_CmMtrCurr_SCom_CalGain_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Sa_CmMtrCurr_CmMtrCurr_SCom_CalGain_Return
# endif
# if defined (Rte_Runnable_Sa_CmMtrCurr_CmMtrCurr_SCom_CalGain_Return)
#  undef Rte_Runnable_Sa_CmMtrCurr_CmMtrCurr_SCom_CalGain_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Sa_CmMtrCurr_CmMtrCurr_SCom_CalGain_Return(void);
# else
#  define Rte_Runnable_Sa_CmMtrCurr_CmMtrCurr_SCom_CalGain_Return() ((void)(0))
# endif /* Rte_Runnable_Sa_CmMtrCurr_CmMtrCurr_SCom_CalGain_Return */

# if defined (Rte_Runnable_Sa_CmMtrCurr_CmMtrCurr_SCom_CalGain_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Sa_CmMtrCurr_CmMtrCurr_SCom_CalGain_Start
# endif
# if defined (Rte_Runnable_Sa_CmMtrCurr_CmMtrCurr_SCom_CalGain_Start)
#  undef Rte_Runnable_Sa_CmMtrCurr_CmMtrCurr_SCom_CalGain_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Sa_CmMtrCurr_CmMtrCurr_SCom_CalGain_Start(void);
# else
#  define Rte_Runnable_Sa_CmMtrCurr_CmMtrCurr_SCom_CalGain_Start() ((void)(0))
# endif /* Rte_Runnable_Sa_CmMtrCurr_CmMtrCurr_SCom_CalGain_Start */

# if defined (Rte_Runnable_Sa_CmMtrCurr_CmMtrCurr_SCom_CalOffset_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Sa_CmMtrCurr_CmMtrCurr_SCom_CalOffset_Return
# endif
# if defined (Rte_Runnable_Sa_CmMtrCurr_CmMtrCurr_SCom_CalOffset_Return)
#  undef Rte_Runnable_Sa_CmMtrCurr_CmMtrCurr_SCom_CalOffset_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Sa_CmMtrCurr_CmMtrCurr_SCom_CalOffset_Return(void);
# else
#  define Rte_Runnable_Sa_CmMtrCurr_CmMtrCurr_SCom_CalOffset_Return() ((void)(0))
# endif /* Rte_Runnable_Sa_CmMtrCurr_CmMtrCurr_SCom_CalOffset_Return */

# if defined (Rte_Runnable_Sa_CmMtrCurr_CmMtrCurr_SCom_CalOffset_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Sa_CmMtrCurr_CmMtrCurr_SCom_CalOffset_Start
# endif
# if defined (Rte_Runnable_Sa_CmMtrCurr_CmMtrCurr_SCom_CalOffset_Start)
#  undef Rte_Runnable_Sa_CmMtrCurr_CmMtrCurr_SCom_CalOffset_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Sa_CmMtrCurr_CmMtrCurr_SCom_CalOffset_Start(void);
# else
#  define Rte_Runnable_Sa_CmMtrCurr_CmMtrCurr_SCom_CalOffset_Start() ((void)(0))
# endif /* Rte_Runnable_Sa_CmMtrCurr_CmMtrCurr_SCom_CalOffset_Start */

# if defined (Rte_Runnable_Sa_CmMtrCurr_CmMtrCurr_SCom_MtrCurrOffReadStatus_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Sa_CmMtrCurr_CmMtrCurr_SCom_MtrCurrOffReadStatus_Return
# endif
# if defined (Rte_Runnable_Sa_CmMtrCurr_CmMtrCurr_SCom_MtrCurrOffReadStatus_Return)
#  undef Rte_Runnable_Sa_CmMtrCurr_CmMtrCurr_SCom_MtrCurrOffReadStatus_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Sa_CmMtrCurr_CmMtrCurr_SCom_MtrCurrOffReadStatus_Return(P2VAR(MtrCurrOffProcessFlag, AUTOMATIC, RTE_SA_CMMTRCURR_APPL_VAR) CurrOffStatus);
# else
#  define Rte_Runnable_Sa_CmMtrCurr_CmMtrCurr_SCom_MtrCurrOffReadStatus_Return(arg1) ((void)(0))
# endif /* Rte_Runnable_Sa_CmMtrCurr_CmMtrCurr_SCom_MtrCurrOffReadStatus_Return */

# if defined (Rte_Runnable_Sa_CmMtrCurr_CmMtrCurr_SCom_MtrCurrOffReadStatus_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Sa_CmMtrCurr_CmMtrCurr_SCom_MtrCurrOffReadStatus_Start
# endif
# if defined (Rte_Runnable_Sa_CmMtrCurr_CmMtrCurr_SCom_MtrCurrOffReadStatus_Start)
#  undef Rte_Runnable_Sa_CmMtrCurr_CmMtrCurr_SCom_MtrCurrOffReadStatus_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Sa_CmMtrCurr_CmMtrCurr_SCom_MtrCurrOffReadStatus_Start(P2VAR(MtrCurrOffProcessFlag, AUTOMATIC, RTE_SA_CMMTRCURR_APPL_VAR) CurrOffStatus);
# else
#  define Rte_Runnable_Sa_CmMtrCurr_CmMtrCurr_SCom_MtrCurrOffReadStatus_Start(arg1) ((void)(0))
# endif /* Rte_Runnable_Sa_CmMtrCurr_CmMtrCurr_SCom_MtrCurrOffReadStatus_Start */

# if defined (Rte_Runnable_Sa_CmMtrCurr_CmMtrCurr_SCom_ReadMtrCurrCals_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Sa_CmMtrCurr_CmMtrCurr_SCom_ReadMtrCurrCals_Return
# endif
# if defined (Rte_Runnable_Sa_CmMtrCurr_CmMtrCurr_SCom_ReadMtrCurrCals_Return)
#  undef Rte_Runnable_Sa_CmMtrCurr_CmMtrCurr_SCom_ReadMtrCurrCals_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Sa_CmMtrCurr_CmMtrCurr_SCom_ReadMtrCurrCals_Return(P2VAR(PhaseCurrCal_DataType, AUTOMATIC, RTE_SA_CMMTRCURR_APPL_VAR) ShCurrCalPtr);
# else
#  define Rte_Runnable_Sa_CmMtrCurr_CmMtrCurr_SCom_ReadMtrCurrCals_Return(arg1) ((void)(0))
# endif /* Rte_Runnable_Sa_CmMtrCurr_CmMtrCurr_SCom_ReadMtrCurrCals_Return */

# if defined (Rte_Runnable_Sa_CmMtrCurr_CmMtrCurr_SCom_ReadMtrCurrCals_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Sa_CmMtrCurr_CmMtrCurr_SCom_ReadMtrCurrCals_Start
# endif
# if defined (Rte_Runnable_Sa_CmMtrCurr_CmMtrCurr_SCom_ReadMtrCurrCals_Start)
#  undef Rte_Runnable_Sa_CmMtrCurr_CmMtrCurr_SCom_ReadMtrCurrCals_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Sa_CmMtrCurr_CmMtrCurr_SCom_ReadMtrCurrCals_Start(P2VAR(PhaseCurrCal_DataType, AUTOMATIC, RTE_SA_CMMTRCURR_APPL_VAR) ShCurrCalPtr);
# else
#  define Rte_Runnable_Sa_CmMtrCurr_CmMtrCurr_SCom_ReadMtrCurrCals_Start(arg1) ((void)(0))
# endif /* Rte_Runnable_Sa_CmMtrCurr_CmMtrCurr_SCom_ReadMtrCurrCals_Start */

# if defined (Rte_Runnable_Sa_CmMtrCurr_CmMtrCurr_SCom_SetMtrCurrCals_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Sa_CmMtrCurr_CmMtrCurr_SCom_SetMtrCurrCals_Return
# endif
# if defined (Rte_Runnable_Sa_CmMtrCurr_CmMtrCurr_SCom_SetMtrCurrCals_Return)
#  undef Rte_Runnable_Sa_CmMtrCurr_CmMtrCurr_SCom_SetMtrCurrCals_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Sa_CmMtrCurr_CmMtrCurr_SCom_SetMtrCurrCals_Return(P2CONST(PhaseCurrCal_DataType, AUTOMATIC, RTE_SA_CMMTRCURR_APPL_DATA) ShCurrCalPtr);
# else
#  define Rte_Runnable_Sa_CmMtrCurr_CmMtrCurr_SCom_SetMtrCurrCals_Return(arg1) ((void)(0))
# endif /* Rte_Runnable_Sa_CmMtrCurr_CmMtrCurr_SCom_SetMtrCurrCals_Return */

# if defined (Rte_Runnable_Sa_CmMtrCurr_CmMtrCurr_SCom_SetMtrCurrCals_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Sa_CmMtrCurr_CmMtrCurr_SCom_SetMtrCurrCals_Start
# endif
# if defined (Rte_Runnable_Sa_CmMtrCurr_CmMtrCurr_SCom_SetMtrCurrCals_Start)
#  undef Rte_Runnable_Sa_CmMtrCurr_CmMtrCurr_SCom_SetMtrCurrCals_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Sa_CmMtrCurr_CmMtrCurr_SCom_SetMtrCurrCals_Start(P2CONST(PhaseCurrCal_DataType, AUTOMATIC, RTE_SA_CMMTRCURR_APPL_DATA) ShCurrCalPtr);
# else
#  define Rte_Runnable_Sa_CmMtrCurr_CmMtrCurr_SCom_SetMtrCurrCals_Start(arg1) ((void)(0))
# endif /* Rte_Runnable_Sa_CmMtrCurr_CmMtrCurr_SCom_SetMtrCurrCals_Start */

# if defined (Rte_Runnable_Sa_CtrlTemp_CtrlTemp_Init1_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Sa_CtrlTemp_CtrlTemp_Init1_Return
# endif
# if defined (Rte_Runnable_Sa_CtrlTemp_CtrlTemp_Init1_Return)
#  undef Rte_Runnable_Sa_CtrlTemp_CtrlTemp_Init1_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Sa_CtrlTemp_CtrlTemp_Init1_Return(void);
# else
#  define Rte_Runnable_Sa_CtrlTemp_CtrlTemp_Init1_Return() ((void)(0))
# endif /* Rte_Runnable_Sa_CtrlTemp_CtrlTemp_Init1_Return */

# if defined (Rte_Runnable_Sa_CtrlTemp_CtrlTemp_Init1_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Sa_CtrlTemp_CtrlTemp_Init1_Start
# endif
# if defined (Rte_Runnable_Sa_CtrlTemp_CtrlTemp_Init1_Start)
#  undef Rte_Runnable_Sa_CtrlTemp_CtrlTemp_Init1_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Sa_CtrlTemp_CtrlTemp_Init1_Start(void);
# else
#  define Rte_Runnable_Sa_CtrlTemp_CtrlTemp_Init1_Start() ((void)(0))
# endif /* Rte_Runnable_Sa_CtrlTemp_CtrlTemp_Init1_Start */

# if defined (Rte_Runnable_Sa_CtrlTemp_CtrlTemp_Per1_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Sa_CtrlTemp_CtrlTemp_Per1_Return
# endif
# if defined (Rte_Runnable_Sa_CtrlTemp_CtrlTemp_Per1_Return)
#  undef Rte_Runnable_Sa_CtrlTemp_CtrlTemp_Per1_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Sa_CtrlTemp_CtrlTemp_Per1_Return(void);
# else
#  define Rte_Runnable_Sa_CtrlTemp_CtrlTemp_Per1_Return() ((void)(0))
# endif /* Rte_Runnable_Sa_CtrlTemp_CtrlTemp_Per1_Return */

# if defined (Rte_Runnable_Sa_CtrlTemp_CtrlTemp_Per1_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Sa_CtrlTemp_CtrlTemp_Per1_Start
# endif
# if defined (Rte_Runnable_Sa_CtrlTemp_CtrlTemp_Per1_Start)
#  undef Rte_Runnable_Sa_CtrlTemp_CtrlTemp_Per1_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Sa_CtrlTemp_CtrlTemp_Per1_Start(void);
# else
#  define Rte_Runnable_Sa_CtrlTemp_CtrlTemp_Per1_Start() ((void)(0))
# endif /* Rte_Runnable_Sa_CtrlTemp_CtrlTemp_Per1_Start */

# if defined (Rte_Runnable_Sa_CtrlTemp_CtrlTemp_Per2_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Sa_CtrlTemp_CtrlTemp_Per2_Return
# endif
# if defined (Rte_Runnable_Sa_CtrlTemp_CtrlTemp_Per2_Return)
#  undef Rte_Runnable_Sa_CtrlTemp_CtrlTemp_Per2_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Sa_CtrlTemp_CtrlTemp_Per2_Return(void);
# else
#  define Rte_Runnable_Sa_CtrlTemp_CtrlTemp_Per2_Return() ((void)(0))
# endif /* Rte_Runnable_Sa_CtrlTemp_CtrlTemp_Per2_Return */

# if defined (Rte_Runnable_Sa_CtrlTemp_CtrlTemp_Per2_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Sa_CtrlTemp_CtrlTemp_Per2_Start
# endif
# if defined (Rte_Runnable_Sa_CtrlTemp_CtrlTemp_Per2_Start)
#  undef Rte_Runnable_Sa_CtrlTemp_CtrlTemp_Per2_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Sa_CtrlTemp_CtrlTemp_Per2_Start(void);
# else
#  define Rte_Runnable_Sa_CtrlTemp_CtrlTemp_Per2_Start() ((void)(0))
# endif /* Rte_Runnable_Sa_CtrlTemp_CtrlTemp_Per2_Start */

# if defined (Rte_Runnable_Sa_HwTrq2_HwTrq2_Init1_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Sa_HwTrq2_HwTrq2_Init1_Return
# endif
# if defined (Rte_Runnable_Sa_HwTrq2_HwTrq2_Init1_Return)
#  undef Rte_Runnable_Sa_HwTrq2_HwTrq2_Init1_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Sa_HwTrq2_HwTrq2_Init1_Return(void);
# else
#  define Rte_Runnable_Sa_HwTrq2_HwTrq2_Init1_Return() ((void)(0))
# endif /* Rte_Runnable_Sa_HwTrq2_HwTrq2_Init1_Return */

# if defined (Rte_Runnable_Sa_HwTrq2_HwTrq2_Init1_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Sa_HwTrq2_HwTrq2_Init1_Start
# endif
# if defined (Rte_Runnable_Sa_HwTrq2_HwTrq2_Init1_Start)
#  undef Rte_Runnable_Sa_HwTrq2_HwTrq2_Init1_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Sa_HwTrq2_HwTrq2_Init1_Start(void);
# else
#  define Rte_Runnable_Sa_HwTrq2_HwTrq2_Init1_Start() ((void)(0))
# endif /* Rte_Runnable_Sa_HwTrq2_HwTrq2_Init1_Start */

# if defined (Rte_Runnable_Sa_HwTrq2_HwTrq2_Per1_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Sa_HwTrq2_HwTrq2_Per1_Return
# endif
# if defined (Rte_Runnable_Sa_HwTrq2_HwTrq2_Per1_Return)
#  undef Rte_Runnable_Sa_HwTrq2_HwTrq2_Per1_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Sa_HwTrq2_HwTrq2_Per1_Return(void);
# else
#  define Rte_Runnable_Sa_HwTrq2_HwTrq2_Per1_Return() ((void)(0))
# endif /* Rte_Runnable_Sa_HwTrq2_HwTrq2_Per1_Return */

# if defined (Rte_Runnable_Sa_HwTrq2_HwTrq2_Per1_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Sa_HwTrq2_HwTrq2_Per1_Start
# endif
# if defined (Rte_Runnable_Sa_HwTrq2_HwTrq2_Per1_Start)
#  undef Rte_Runnable_Sa_HwTrq2_HwTrq2_Per1_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Sa_HwTrq2_HwTrq2_Per1_Start(void);
# else
#  define Rte_Runnable_Sa_HwTrq2_HwTrq2_Per1_Start() ((void)(0))
# endif /* Rte_Runnable_Sa_HwTrq2_HwTrq2_Per1_Start */

# if defined (Rte_Runnable_Sa_HwTrq2_HwTrq2_Per2_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Sa_HwTrq2_HwTrq2_Per2_Return
# endif
# if defined (Rte_Runnable_Sa_HwTrq2_HwTrq2_Per2_Return)
#  undef Rte_Runnable_Sa_HwTrq2_HwTrq2_Per2_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Sa_HwTrq2_HwTrq2_Per2_Return(void);
# else
#  define Rte_Runnable_Sa_HwTrq2_HwTrq2_Per2_Return() ((void)(0))
# endif /* Rte_Runnable_Sa_HwTrq2_HwTrq2_Per2_Return */

# if defined (Rte_Runnable_Sa_HwTrq2_HwTrq2_Per2_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Sa_HwTrq2_HwTrq2_Per2_Start
# endif
# if defined (Rte_Runnable_Sa_HwTrq2_HwTrq2_Per2_Start)
#  undef Rte_Runnable_Sa_HwTrq2_HwTrq2_Per2_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Sa_HwTrq2_HwTrq2_Per2_Start(void);
# else
#  define Rte_Runnable_Sa_HwTrq2_HwTrq2_Per2_Start() ((void)(0))
# endif /* Rte_Runnable_Sa_HwTrq2_HwTrq2_Per2_Start */

# if defined (Rte_Runnable_Sa_HwTrq2_HwTrq2_Per3_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Sa_HwTrq2_HwTrq2_Per3_Return
# endif
# if defined (Rte_Runnable_Sa_HwTrq2_HwTrq2_Per3_Return)
#  undef Rte_Runnable_Sa_HwTrq2_HwTrq2_Per3_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Sa_HwTrq2_HwTrq2_Per3_Return(void);
# else
#  define Rte_Runnable_Sa_HwTrq2_HwTrq2_Per3_Return() ((void)(0))
# endif /* Rte_Runnable_Sa_HwTrq2_HwTrq2_Per3_Return */

# if defined (Rte_Runnable_Sa_HwTrq2_HwTrq2_Per3_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Sa_HwTrq2_HwTrq2_Per3_Start
# endif
# if defined (Rte_Runnable_Sa_HwTrq2_HwTrq2_Per3_Start)
#  undef Rte_Runnable_Sa_HwTrq2_HwTrq2_Per3_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Sa_HwTrq2_HwTrq2_Per3_Start(void);
# else
#  define Rte_Runnable_Sa_HwTrq2_HwTrq2_Per3_Start() ((void)(0))
# endif /* Rte_Runnable_Sa_HwTrq2_HwTrq2_Per3_Start */

# if defined (Rte_Runnable_Sa_HwTrq_HwTrq_Init_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Sa_HwTrq_HwTrq_Init_Return
# endif
# if defined (Rte_Runnable_Sa_HwTrq_HwTrq_Init_Return)
#  undef Rte_Runnable_Sa_HwTrq_HwTrq_Init_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Sa_HwTrq_HwTrq_Init_Return(void);
# else
#  define Rte_Runnable_Sa_HwTrq_HwTrq_Init_Return() ((void)(0))
# endif /* Rte_Runnable_Sa_HwTrq_HwTrq_Init_Return */

# if defined (Rte_Runnable_Sa_HwTrq_HwTrq_Init_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Sa_HwTrq_HwTrq_Init_Start
# endif
# if defined (Rte_Runnable_Sa_HwTrq_HwTrq_Init_Start)
#  undef Rte_Runnable_Sa_HwTrq_HwTrq_Init_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Sa_HwTrq_HwTrq_Init_Start(void);
# else
#  define Rte_Runnable_Sa_HwTrq_HwTrq_Init_Start() ((void)(0))
# endif /* Rte_Runnable_Sa_HwTrq_HwTrq_Init_Start */

# if defined (Rte_Runnable_Sa_HwTrq_HwTrq_Per1_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Sa_HwTrq_HwTrq_Per1_Return
# endif
# if defined (Rte_Runnable_Sa_HwTrq_HwTrq_Per1_Return)
#  undef Rte_Runnable_Sa_HwTrq_HwTrq_Per1_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Sa_HwTrq_HwTrq_Per1_Return(void);
# else
#  define Rte_Runnable_Sa_HwTrq_HwTrq_Per1_Return() ((void)(0))
# endif /* Rte_Runnable_Sa_HwTrq_HwTrq_Per1_Return */

# if defined (Rte_Runnable_Sa_HwTrq_HwTrq_Per1_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Sa_HwTrq_HwTrq_Per1_Start
# endif
# if defined (Rte_Runnable_Sa_HwTrq_HwTrq_Per1_Start)
#  undef Rte_Runnable_Sa_HwTrq_HwTrq_Per1_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Sa_HwTrq_HwTrq_Per1_Start(void);
# else
#  define Rte_Runnable_Sa_HwTrq_HwTrq_Per1_Start() ((void)(0))
# endif /* Rte_Runnable_Sa_HwTrq_HwTrq_Per1_Start */

# if defined (Rte_Runnable_Sa_HwTrq_HwTrq_Per2_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Sa_HwTrq_HwTrq_Per2_Return
# endif
# if defined (Rte_Runnable_Sa_HwTrq_HwTrq_Per2_Return)
#  undef Rte_Runnable_Sa_HwTrq_HwTrq_Per2_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Sa_HwTrq_HwTrq_Per2_Return(void);
# else
#  define Rte_Runnable_Sa_HwTrq_HwTrq_Per2_Return() ((void)(0))
# endif /* Rte_Runnable_Sa_HwTrq_HwTrq_Per2_Return */

# if defined (Rte_Runnable_Sa_HwTrq_HwTrq_Per2_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Sa_HwTrq_HwTrq_Per2_Start
# endif
# if defined (Rte_Runnable_Sa_HwTrq_HwTrq_Per2_Start)
#  undef Rte_Runnable_Sa_HwTrq_HwTrq_Per2_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Sa_HwTrq_HwTrq_Per2_Start(void);
# else
#  define Rte_Runnable_Sa_HwTrq_HwTrq_Per2_Start() ((void)(0))
# endif /* Rte_Runnable_Sa_HwTrq_HwTrq_Per2_Start */

# if defined (Rte_Runnable_Sa_HwTrq_HwTrq_Per3_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Sa_HwTrq_HwTrq_Per3_Return
# endif
# if defined (Rte_Runnable_Sa_HwTrq_HwTrq_Per3_Return)
#  undef Rte_Runnable_Sa_HwTrq_HwTrq_Per3_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Sa_HwTrq_HwTrq_Per3_Return(void);
# else
#  define Rte_Runnable_Sa_HwTrq_HwTrq_Per3_Return() ((void)(0))
# endif /* Rte_Runnable_Sa_HwTrq_HwTrq_Per3_Return */

# if defined (Rte_Runnable_Sa_HwTrq_HwTrq_Per3_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Sa_HwTrq_HwTrq_Per3_Start
# endif
# if defined (Rte_Runnable_Sa_HwTrq_HwTrq_Per3_Start)
#  undef Rte_Runnable_Sa_HwTrq_HwTrq_Per3_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Sa_HwTrq_HwTrq_Per3_Start(void);
# else
#  define Rte_Runnable_Sa_HwTrq_HwTrq_Per3_Start() ((void)(0))
# endif /* Rte_Runnable_Sa_HwTrq_HwTrq_Per3_Start */

# if defined (Rte_Runnable_Sa_HwTrq_HwTrq_SCom_ClrHwTrqScale_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Sa_HwTrq_HwTrq_SCom_ClrHwTrqScale_Return
# endif
# if defined (Rte_Runnable_Sa_HwTrq_HwTrq_SCom_ClrHwTrqScale_Return)
#  undef Rte_Runnable_Sa_HwTrq_HwTrq_SCom_ClrHwTrqScale_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Sa_HwTrq_HwTrq_SCom_ClrHwTrqScale_Return(void);
# else
#  define Rte_Runnable_Sa_HwTrq_HwTrq_SCom_ClrHwTrqScale_Return() ((void)(0))
# endif /* Rte_Runnable_Sa_HwTrq_HwTrq_SCom_ClrHwTrqScale_Return */

# if defined (Rte_Runnable_Sa_HwTrq_HwTrq_SCom_ClrHwTrqScale_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Sa_HwTrq_HwTrq_SCom_ClrHwTrqScale_Start
# endif
# if defined (Rte_Runnable_Sa_HwTrq_HwTrq_SCom_ClrHwTrqScale_Start)
#  undef Rte_Runnable_Sa_HwTrq_HwTrq_SCom_ClrHwTrqScale_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Sa_HwTrq_HwTrq_SCom_ClrHwTrqScale_Start(void);
# else
#  define Rte_Runnable_Sa_HwTrq_HwTrq_SCom_ClrHwTrqScale_Start() ((void)(0))
# endif /* Rte_Runnable_Sa_HwTrq_HwTrq_SCom_ClrHwTrqScale_Start */

# if defined (Rte_Runnable_Sa_HwTrq_HwTrq_SCom_ClrHwTrqTrim_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Sa_HwTrq_HwTrq_SCom_ClrHwTrqTrim_Return
# endif
# if defined (Rte_Runnable_Sa_HwTrq_HwTrq_SCom_ClrHwTrqTrim_Return)
#  undef Rte_Runnable_Sa_HwTrq_HwTrq_SCom_ClrHwTrqTrim_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Sa_HwTrq_HwTrq_SCom_ClrHwTrqTrim_Return(void);
# else
#  define Rte_Runnable_Sa_HwTrq_HwTrq_SCom_ClrHwTrqTrim_Return() ((void)(0))
# endif /* Rte_Runnable_Sa_HwTrq_HwTrq_SCom_ClrHwTrqTrim_Return */

# if defined (Rte_Runnable_Sa_HwTrq_HwTrq_SCom_ClrHwTrqTrim_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Sa_HwTrq_HwTrq_SCom_ClrHwTrqTrim_Start
# endif
# if defined (Rte_Runnable_Sa_HwTrq_HwTrq_SCom_ClrHwTrqTrim_Start)
#  undef Rte_Runnable_Sa_HwTrq_HwTrq_SCom_ClrHwTrqTrim_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Sa_HwTrq_HwTrq_SCom_ClrHwTrqTrim_Start(void);
# else
#  define Rte_Runnable_Sa_HwTrq_HwTrq_SCom_ClrHwTrqTrim_Start() ((void)(0))
# endif /* Rte_Runnable_Sa_HwTrq_HwTrq_SCom_ClrHwTrqTrim_Start */

# if defined (Rte_Runnable_Sa_HwTrq_HwTrq_SCom_ManualSetHwTrqTrim_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Sa_HwTrq_HwTrq_SCom_ManualSetHwTrqTrim_Return
# endif
# if defined (Rte_Runnable_Sa_HwTrq_HwTrq_SCom_ManualSetHwTrqTrim_Return)
#  undef Rte_Runnable_Sa_HwTrq_HwTrq_SCom_ManualSetHwTrqTrim_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Sa_HwTrq_HwTrq_SCom_ManualSetHwTrqTrim_Return(P2CONST(HwTrqTrim_Datatype, AUTOMATIC, RTE_SA_HWTRQ_APPL_DATA) HwTrqTrimDataPtr);
# else
#  define Rte_Runnable_Sa_HwTrq_HwTrq_SCom_ManualSetHwTrqTrim_Return(arg1) ((void)(0))
# endif /* Rte_Runnable_Sa_HwTrq_HwTrq_SCom_ManualSetHwTrqTrim_Return */

# if defined (Rte_Runnable_Sa_HwTrq_HwTrq_SCom_ManualSetHwTrqTrim_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Sa_HwTrq_HwTrq_SCom_ManualSetHwTrqTrim_Start
# endif
# if defined (Rte_Runnable_Sa_HwTrq_HwTrq_SCom_ManualSetHwTrqTrim_Start)
#  undef Rte_Runnable_Sa_HwTrq_HwTrq_SCom_ManualSetHwTrqTrim_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Sa_HwTrq_HwTrq_SCom_ManualSetHwTrqTrim_Start(P2CONST(HwTrqTrim_Datatype, AUTOMATIC, RTE_SA_HWTRQ_APPL_DATA) HwTrqTrimDataPtr);
# else
#  define Rte_Runnable_Sa_HwTrq_HwTrq_SCom_ManualSetHwTrqTrim_Start(arg1) ((void)(0))
# endif /* Rte_Runnable_Sa_HwTrq_HwTrq_SCom_ManualSetHwTrqTrim_Start */

# if defined (Rte_Runnable_Sa_HwTrq_HwTrq_SCom_ReadEOLTrqStep_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Sa_HwTrq_HwTrq_SCom_ReadEOLTrqStep_Return
# endif
# if defined (Rte_Runnable_Sa_HwTrq_HwTrq_SCom_ReadEOLTrqStep_Return)
#  undef Rte_Runnable_Sa_HwTrq_HwTrq_SCom_ReadEOLTrqStep_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Sa_HwTrq_HwTrq_SCom_ReadEOLTrqStep_Return(P2VAR(EOLTrqStepType, AUTOMATIC, RTE_SA_HWTRQ_APPL_VAR) TrqStep_HwNm_T_f32);
# else
#  define Rte_Runnable_Sa_HwTrq_HwTrq_SCom_ReadEOLTrqStep_Return(arg1) ((void)(0))
# endif /* Rte_Runnable_Sa_HwTrq_HwTrq_SCom_ReadEOLTrqStep_Return */

# if defined (Rte_Runnable_Sa_HwTrq_HwTrq_SCom_ReadEOLTrqStep_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Sa_HwTrq_HwTrq_SCom_ReadEOLTrqStep_Start
# endif
# if defined (Rte_Runnable_Sa_HwTrq_HwTrq_SCom_ReadEOLTrqStep_Start)
#  undef Rte_Runnable_Sa_HwTrq_HwTrq_SCom_ReadEOLTrqStep_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Sa_HwTrq_HwTrq_SCom_ReadEOLTrqStep_Start(P2VAR(EOLTrqStepType, AUTOMATIC, RTE_SA_HWTRQ_APPL_VAR) TrqStep_HwNm_T_f32);
# else
#  define Rte_Runnable_Sa_HwTrq_HwTrq_SCom_ReadEOLTrqStep_Start(arg1) ((void)(0))
# endif /* Rte_Runnable_Sa_HwTrq_HwTrq_SCom_ReadEOLTrqStep_Start */

# if defined (Rte_Runnable_Sa_HwTrq_HwTrq_SCom_ReadHwTrqScale_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Sa_HwTrq_HwTrq_SCom_ReadHwTrqScale_Return
# endif
# if defined (Rte_Runnable_Sa_HwTrq_HwTrq_SCom_ReadHwTrqScale_Return)
#  undef Rte_Runnable_Sa_HwTrq_HwTrq_SCom_ReadHwTrqScale_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Sa_HwTrq_HwTrq_SCom_ReadHwTrqScale_Return(P2VAR(HwTrqScale_Datatype, AUTOMATIC, RTE_SA_HWTRQ_APPL_VAR) HwTrqScaleDataPtr);
# else
#  define Rte_Runnable_Sa_HwTrq_HwTrq_SCom_ReadHwTrqScale_Return(arg1) ((void)(0))
# endif /* Rte_Runnable_Sa_HwTrq_HwTrq_SCom_ReadHwTrqScale_Return */

# if defined (Rte_Runnable_Sa_HwTrq_HwTrq_SCom_ReadHwTrqScale_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Sa_HwTrq_HwTrq_SCom_ReadHwTrqScale_Start
# endif
# if defined (Rte_Runnable_Sa_HwTrq_HwTrq_SCom_ReadHwTrqScale_Start)
#  undef Rte_Runnable_Sa_HwTrq_HwTrq_SCom_ReadHwTrqScale_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Sa_HwTrq_HwTrq_SCom_ReadHwTrqScale_Start(P2VAR(HwTrqScale_Datatype, AUTOMATIC, RTE_SA_HWTRQ_APPL_VAR) HwTrqScaleDataPtr);
# else
#  define Rte_Runnable_Sa_HwTrq_HwTrq_SCom_ReadHwTrqScale_Start(arg1) ((void)(0))
# endif /* Rte_Runnable_Sa_HwTrq_HwTrq_SCom_ReadHwTrqScale_Start */

# if defined (Rte_Runnable_Sa_HwTrq_HwTrq_SCom_ReadHwTrqTrim_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Sa_HwTrq_HwTrq_SCom_ReadHwTrqTrim_Return
# endif
# if defined (Rte_Runnable_Sa_HwTrq_HwTrq_SCom_ReadHwTrqTrim_Return)
#  undef Rte_Runnable_Sa_HwTrq_HwTrq_SCom_ReadHwTrqTrim_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Sa_HwTrq_HwTrq_SCom_ReadHwTrqTrim_Return(P2VAR(HwTrqTrim_Datatype, AUTOMATIC, RTE_SA_HWTRQ_APPL_VAR) HwTrqTrimDatPtr);
# else
#  define Rte_Runnable_Sa_HwTrq_HwTrq_SCom_ReadHwTrqTrim_Return(arg1) ((void)(0))
# endif /* Rte_Runnable_Sa_HwTrq_HwTrq_SCom_ReadHwTrqTrim_Return */

# if defined (Rte_Runnable_Sa_HwTrq_HwTrq_SCom_ReadHwTrqTrim_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Sa_HwTrq_HwTrq_SCom_ReadHwTrqTrim_Start
# endif
# if defined (Rte_Runnable_Sa_HwTrq_HwTrq_SCom_ReadHwTrqTrim_Start)
#  undef Rte_Runnable_Sa_HwTrq_HwTrq_SCom_ReadHwTrqTrim_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Sa_HwTrq_HwTrq_SCom_ReadHwTrqTrim_Start(P2VAR(HwTrqTrim_Datatype, AUTOMATIC, RTE_SA_HWTRQ_APPL_VAR) HwTrqTrimDatPtr);
# else
#  define Rte_Runnable_Sa_HwTrq_HwTrq_SCom_ReadHwTrqTrim_Start(arg1) ((void)(0))
# endif /* Rte_Runnable_Sa_HwTrq_HwTrq_SCom_ReadHwTrqTrim_Start */

# if defined (Rte_Runnable_Sa_HwTrq_HwTrq_SCom_SetEOLTrqStep_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Sa_HwTrq_HwTrq_SCom_SetEOLTrqStep_Return
# endif
# if defined (Rte_Runnable_Sa_HwTrq_HwTrq_SCom_SetEOLTrqStep_Return)
#  undef Rte_Runnable_Sa_HwTrq_HwTrq_SCom_SetEOLTrqStep_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Sa_HwTrq_HwTrq_SCom_SetEOLTrqStep_Return(P2CONST(EOLTrqStepType, AUTOMATIC, RTE_SA_HWTRQ_APPL_DATA) TrqStep_HwNm_T_f32);
# else
#  define Rte_Runnable_Sa_HwTrq_HwTrq_SCom_SetEOLTrqStep_Return(arg1) ((void)(0))
# endif /* Rte_Runnable_Sa_HwTrq_HwTrq_SCom_SetEOLTrqStep_Return */

# if defined (Rte_Runnable_Sa_HwTrq_HwTrq_SCom_SetEOLTrqStep_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Sa_HwTrq_HwTrq_SCom_SetEOLTrqStep_Start
# endif
# if defined (Rte_Runnable_Sa_HwTrq_HwTrq_SCom_SetEOLTrqStep_Start)
#  undef Rte_Runnable_Sa_HwTrq_HwTrq_SCom_SetEOLTrqStep_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Sa_HwTrq_HwTrq_SCom_SetEOLTrqStep_Start(P2CONST(EOLTrqStepType, AUTOMATIC, RTE_SA_HWTRQ_APPL_DATA) TrqStep_HwNm_T_f32);
# else
#  define Rte_Runnable_Sa_HwTrq_HwTrq_SCom_SetEOLTrqStep_Start(arg1) ((void)(0))
# endif /* Rte_Runnable_Sa_HwTrq_HwTrq_SCom_SetEOLTrqStep_Start */

# if defined (Rte_Runnable_Sa_HwTrq_HwTrq_SCom_SetHwTrqScale_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Sa_HwTrq_HwTrq_SCom_SetHwTrqScale_Return
# endif
# if defined (Rte_Runnable_Sa_HwTrq_HwTrq_SCom_SetHwTrqScale_Return)
#  undef Rte_Runnable_Sa_HwTrq_HwTrq_SCom_SetHwTrqScale_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Sa_HwTrq_HwTrq_SCom_SetHwTrqScale_Return(Float ScaleValue);
# else
#  define Rte_Runnable_Sa_HwTrq_HwTrq_SCom_SetHwTrqScale_Return(arg1) ((void)(0))
# endif /* Rte_Runnable_Sa_HwTrq_HwTrq_SCom_SetHwTrqScale_Return */

# if defined (Rte_Runnable_Sa_HwTrq_HwTrq_SCom_SetHwTrqScale_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Sa_HwTrq_HwTrq_SCom_SetHwTrqScale_Start
# endif
# if defined (Rte_Runnable_Sa_HwTrq_HwTrq_SCom_SetHwTrqScale_Start)
#  undef Rte_Runnable_Sa_HwTrq_HwTrq_SCom_SetHwTrqScale_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Sa_HwTrq_HwTrq_SCom_SetHwTrqScale_Start(Float ScaleValue);
# else
#  define Rte_Runnable_Sa_HwTrq_HwTrq_SCom_SetHwTrqScale_Start(arg1) ((void)(0))
# endif /* Rte_Runnable_Sa_HwTrq_HwTrq_SCom_SetHwTrqScale_Start */

# if defined (Rte_Runnable_Sa_HwTrq_HwTrq_SCom_SetHwTrqTrim_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Sa_HwTrq_HwTrq_SCom_SetHwTrqTrim_Return
# endif
# if defined (Rte_Runnable_Sa_HwTrq_HwTrq_SCom_SetHwTrqTrim_Return)
#  undef Rte_Runnable_Sa_HwTrq_HwTrq_SCom_SetHwTrqTrim_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Sa_HwTrq_HwTrq_SCom_SetHwTrqTrim_Return(void);
# else
#  define Rte_Runnable_Sa_HwTrq_HwTrq_SCom_SetHwTrqTrim_Return() ((void)(0))
# endif /* Rte_Runnable_Sa_HwTrq_HwTrq_SCom_SetHwTrqTrim_Return */

# if defined (Rte_Runnable_Sa_HwTrq_HwTrq_SCom_SetHwTrqTrim_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Sa_HwTrq_HwTrq_SCom_SetHwTrqTrim_Start
# endif
# if defined (Rte_Runnable_Sa_HwTrq_HwTrq_SCom_SetHwTrqTrim_Start)
#  undef Rte_Runnable_Sa_HwTrq_HwTrq_SCom_SetHwTrqTrim_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Sa_HwTrq_HwTrq_SCom_SetHwTrqTrim_Start(void);
# else
#  define Rte_Runnable_Sa_HwTrq_HwTrq_SCom_SetHwTrqTrim_Start() ((void)(0))
# endif /* Rte_Runnable_Sa_HwTrq_HwTrq_SCom_SetHwTrqTrim_Start */

# if defined (Rte_Runnable_Sa_MtrDrvDiag_MtrDrvDiag_Per1_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Sa_MtrDrvDiag_MtrDrvDiag_Per1_Return
# endif
# if defined (Rte_Runnable_Sa_MtrDrvDiag_MtrDrvDiag_Per1_Return)
#  undef Rte_Runnable_Sa_MtrDrvDiag_MtrDrvDiag_Per1_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Sa_MtrDrvDiag_MtrDrvDiag_Per1_Return(void);
# else
#  define Rte_Runnable_Sa_MtrDrvDiag_MtrDrvDiag_Per1_Return() ((void)(0))
# endif /* Rte_Runnable_Sa_MtrDrvDiag_MtrDrvDiag_Per1_Return */

# if defined (Rte_Runnable_Sa_MtrDrvDiag_MtrDrvDiag_Per1_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Sa_MtrDrvDiag_MtrDrvDiag_Per1_Start
# endif
# if defined (Rte_Runnable_Sa_MtrDrvDiag_MtrDrvDiag_Per1_Start)
#  undef Rte_Runnable_Sa_MtrDrvDiag_MtrDrvDiag_Per1_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Sa_MtrDrvDiag_MtrDrvDiag_Per1_Start(void);
# else
#  define Rte_Runnable_Sa_MtrDrvDiag_MtrDrvDiag_Per1_Start() ((void)(0))
# endif /* Rte_Runnable_Sa_MtrDrvDiag_MtrDrvDiag_Per1_Start */

# if defined (Rte_Runnable_Sa_MtrDrvDiag_MtrDrvDiag_Per2_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Sa_MtrDrvDiag_MtrDrvDiag_Per2_Return
# endif
# if defined (Rte_Runnable_Sa_MtrDrvDiag_MtrDrvDiag_Per2_Return)
#  undef Rte_Runnable_Sa_MtrDrvDiag_MtrDrvDiag_Per2_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Sa_MtrDrvDiag_MtrDrvDiag_Per2_Return(void);
# else
#  define Rte_Runnable_Sa_MtrDrvDiag_MtrDrvDiag_Per2_Return() ((void)(0))
# endif /* Rte_Runnable_Sa_MtrDrvDiag_MtrDrvDiag_Per2_Return */

# if defined (Rte_Runnable_Sa_MtrDrvDiag_MtrDrvDiag_Per2_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Sa_MtrDrvDiag_MtrDrvDiag_Per2_Start
# endif
# if defined (Rte_Runnable_Sa_MtrDrvDiag_MtrDrvDiag_Per2_Start)
#  undef Rte_Runnable_Sa_MtrDrvDiag_MtrDrvDiag_Per2_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Sa_MtrDrvDiag_MtrDrvDiag_Per2_Start(void);
# else
#  define Rte_Runnable_Sa_MtrDrvDiag_MtrDrvDiag_Per2_Start() ((void)(0))
# endif /* Rte_Runnable_Sa_MtrDrvDiag_MtrDrvDiag_Per2_Start */

# if defined (Rte_Runnable_Sa_MtrDrvDiag_MtrDrvDiag_Trns1_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Sa_MtrDrvDiag_MtrDrvDiag_Trns1_Return
# endif
# if defined (Rte_Runnable_Sa_MtrDrvDiag_MtrDrvDiag_Trns1_Return)
#  undef Rte_Runnable_Sa_MtrDrvDiag_MtrDrvDiag_Trns1_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Sa_MtrDrvDiag_MtrDrvDiag_Trns1_Return(void);
# else
#  define Rte_Runnable_Sa_MtrDrvDiag_MtrDrvDiag_Trns1_Return() ((void)(0))
# endif /* Rte_Runnable_Sa_MtrDrvDiag_MtrDrvDiag_Trns1_Return */

# if defined (Rte_Runnable_Sa_MtrDrvDiag_MtrDrvDiag_Trns1_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Sa_MtrDrvDiag_MtrDrvDiag_Trns1_Start
# endif
# if defined (Rte_Runnable_Sa_MtrDrvDiag_MtrDrvDiag_Trns1_Start)
#  undef Rte_Runnable_Sa_MtrDrvDiag_MtrDrvDiag_Trns1_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Sa_MtrDrvDiag_MtrDrvDiag_Trns1_Start(void);
# else
#  define Rte_Runnable_Sa_MtrDrvDiag_MtrDrvDiag_Trns1_Start() ((void)(0))
# endif /* Rte_Runnable_Sa_MtrDrvDiag_MtrDrvDiag_Trns1_Start */

# if defined (Rte_Runnable_Sa_MtrPos2_MtrPos2_Init1_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Sa_MtrPos2_MtrPos2_Init1_Return
# endif
# if defined (Rte_Runnable_Sa_MtrPos2_MtrPos2_Init1_Return)
#  undef Rte_Runnable_Sa_MtrPos2_MtrPos2_Init1_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Sa_MtrPos2_MtrPos2_Init1_Return(void);
# else
#  define Rte_Runnable_Sa_MtrPos2_MtrPos2_Init1_Return() ((void)(0))
# endif /* Rte_Runnable_Sa_MtrPos2_MtrPos2_Init1_Return */

# if defined (Rte_Runnable_Sa_MtrPos2_MtrPos2_Init1_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Sa_MtrPos2_MtrPos2_Init1_Start
# endif
# if defined (Rte_Runnable_Sa_MtrPos2_MtrPos2_Init1_Start)
#  undef Rte_Runnable_Sa_MtrPos2_MtrPos2_Init1_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Sa_MtrPos2_MtrPos2_Init1_Start(void);
# else
#  define Rte_Runnable_Sa_MtrPos2_MtrPos2_Init1_Start() ((void)(0))
# endif /* Rte_Runnable_Sa_MtrPos2_MtrPos2_Init1_Start */

# if defined (Rte_Runnable_Sa_MtrPos2_MtrPos2_Per1_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Sa_MtrPos2_MtrPos2_Per1_Return
# endif
# if defined (Rte_Runnable_Sa_MtrPos2_MtrPos2_Per1_Return)
#  undef Rte_Runnable_Sa_MtrPos2_MtrPos2_Per1_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Sa_MtrPos2_MtrPos2_Per1_Return(void);
# else
#  define Rte_Runnable_Sa_MtrPos2_MtrPos2_Per1_Return() ((void)(0))
# endif /* Rte_Runnable_Sa_MtrPos2_MtrPos2_Per1_Return */

# if defined (Rte_Runnable_Sa_MtrPos2_MtrPos2_Per1_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Sa_MtrPos2_MtrPos2_Per1_Start
# endif
# if defined (Rte_Runnable_Sa_MtrPos2_MtrPos2_Per1_Start)
#  undef Rte_Runnable_Sa_MtrPos2_MtrPos2_Per1_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Sa_MtrPos2_MtrPos2_Per1_Start(void);
# else
#  define Rte_Runnable_Sa_MtrPos2_MtrPos2_Per1_Start() ((void)(0))
# endif /* Rte_Runnable_Sa_MtrPos2_MtrPos2_Per1_Start */

# if defined (Rte_Runnable_Sa_MtrPos3_MtrPos3_Per1_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Sa_MtrPos3_MtrPos3_Per1_Return
# endif
# if defined (Rte_Runnable_Sa_MtrPos3_MtrPos3_Per1_Return)
#  undef Rte_Runnable_Sa_MtrPos3_MtrPos3_Per1_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Sa_MtrPos3_MtrPos3_Per1_Return(void);
# else
#  define Rte_Runnable_Sa_MtrPos3_MtrPos3_Per1_Return() ((void)(0))
# endif /* Rte_Runnable_Sa_MtrPos3_MtrPos3_Per1_Return */

# if defined (Rte_Runnable_Sa_MtrPos3_MtrPos3_Per1_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Sa_MtrPos3_MtrPos3_Per1_Start
# endif
# if defined (Rte_Runnable_Sa_MtrPos3_MtrPos3_Per1_Start)
#  undef Rte_Runnable_Sa_MtrPos3_MtrPos3_Per1_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Sa_MtrPos3_MtrPos3_Per1_Start(void);
# else
#  define Rte_Runnable_Sa_MtrPos3_MtrPos3_Per1_Start() ((void)(0))
# endif /* Rte_Runnable_Sa_MtrPos3_MtrPos3_Per1_Start */

# if defined (Rte_Runnable_Sa_MtrPos3_MtrPos3_Per2_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Sa_MtrPos3_MtrPos3_Per2_Return
# endif
# if defined (Rte_Runnable_Sa_MtrPos3_MtrPos3_Per2_Return)
#  undef Rte_Runnable_Sa_MtrPos3_MtrPos3_Per2_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Sa_MtrPos3_MtrPos3_Per2_Return(void);
# else
#  define Rte_Runnable_Sa_MtrPos3_MtrPos3_Per2_Return() ((void)(0))
# endif /* Rte_Runnable_Sa_MtrPos3_MtrPos3_Per2_Return */

# if defined (Rte_Runnable_Sa_MtrPos3_MtrPos3_Per2_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Sa_MtrPos3_MtrPos3_Per2_Start
# endif
# if defined (Rte_Runnable_Sa_MtrPos3_MtrPos3_Per2_Start)
#  undef Rte_Runnable_Sa_MtrPos3_MtrPos3_Per2_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Sa_MtrPos3_MtrPos3_Per2_Start(void);
# else
#  define Rte_Runnable_Sa_MtrPos3_MtrPos3_Per2_Start() ((void)(0))
# endif /* Rte_Runnable_Sa_MtrPos3_MtrPos3_Per2_Start */

# if defined (Rte_Runnable_Sa_MtrPos_MtrPos_Init1_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Sa_MtrPos_MtrPos_Init1_Return
# endif
# if defined (Rte_Runnable_Sa_MtrPos_MtrPos_Init1_Return)
#  undef Rte_Runnable_Sa_MtrPos_MtrPos_Init1_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Sa_MtrPos_MtrPos_Init1_Return(void);
# else
#  define Rte_Runnable_Sa_MtrPos_MtrPos_Init1_Return() ((void)(0))
# endif /* Rte_Runnable_Sa_MtrPos_MtrPos_Init1_Return */

# if defined (Rte_Runnable_Sa_MtrPos_MtrPos_Init1_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Sa_MtrPos_MtrPos_Init1_Start
# endif
# if defined (Rte_Runnable_Sa_MtrPos_MtrPos_Init1_Start)
#  undef Rte_Runnable_Sa_MtrPos_MtrPos_Init1_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Sa_MtrPos_MtrPos_Init1_Start(void);
# else
#  define Rte_Runnable_Sa_MtrPos_MtrPos_Init1_Start() ((void)(0))
# endif /* Rte_Runnable_Sa_MtrPos_MtrPos_Init1_Start */

# if defined (Rte_Runnable_Sa_MtrPos_MtrPos_Per2_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Sa_MtrPos_MtrPos_Per2_Return
# endif
# if defined (Rte_Runnable_Sa_MtrPos_MtrPos_Per2_Return)
#  undef Rte_Runnable_Sa_MtrPos_MtrPos_Per2_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Sa_MtrPos_MtrPos_Per2_Return(void);
# else
#  define Rte_Runnable_Sa_MtrPos_MtrPos_Per2_Return() ((void)(0))
# endif /* Rte_Runnable_Sa_MtrPos_MtrPos_Per2_Return */

# if defined (Rte_Runnable_Sa_MtrPos_MtrPos_Per2_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Sa_MtrPos_MtrPos_Per2_Start
# endif
# if defined (Rte_Runnable_Sa_MtrPos_MtrPos_Per2_Start)
#  undef Rte_Runnable_Sa_MtrPos_MtrPos_Per2_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Sa_MtrPos_MtrPos_Per2_Start(void);
# else
#  define Rte_Runnable_Sa_MtrPos_MtrPos_Per2_Start() ((void)(0))
# endif /* Rte_Runnable_Sa_MtrPos_MtrPos_Per2_Start */

# if defined (Rte_Runnable_Sa_MtrPos_MtrPos_SCom_ReadEOLMtrCals_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Sa_MtrPos_MtrPos_SCom_ReadEOLMtrCals_Return
# endif
# if defined (Rte_Runnable_Sa_MtrPos_MtrPos_SCom_ReadEOLMtrCals_Return)
#  undef Rte_Runnable_Sa_MtrPos_MtrPos_SCom_ReadEOLMtrCals_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Sa_MtrPos_MtrPos_SCom_ReadEOLMtrCals_Return(P2VAR(MtrPosCal_DataType, AUTOMATIC, RTE_SA_MTRPOS_APPL_VAR) MtrCalDataPtr);
# else
#  define Rte_Runnable_Sa_MtrPos_MtrPos_SCom_ReadEOLMtrCals_Return(arg1) ((void)(0))
# endif /* Rte_Runnable_Sa_MtrPos_MtrPos_SCom_ReadEOLMtrCals_Return */

# if defined (Rte_Runnable_Sa_MtrPos_MtrPos_SCom_ReadEOLMtrCals_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Sa_MtrPos_MtrPos_SCom_ReadEOLMtrCals_Start
# endif
# if defined (Rte_Runnable_Sa_MtrPos_MtrPos_SCom_ReadEOLMtrCals_Start)
#  undef Rte_Runnable_Sa_MtrPos_MtrPos_SCom_ReadEOLMtrCals_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Sa_MtrPos_MtrPos_SCom_ReadEOLMtrCals_Start(P2VAR(MtrPosCal_DataType, AUTOMATIC, RTE_SA_MTRPOS_APPL_VAR) MtrCalDataPtr);
# else
#  define Rte_Runnable_Sa_MtrPos_MtrPos_SCom_ReadEOLMtrCals_Start(arg1) ((void)(0))
# endif /* Rte_Runnable_Sa_MtrPos_MtrPos_SCom_ReadEOLMtrCals_Start */

# if defined (Rte_Runnable_Sa_MtrPos_MtrPos_SCom_SetEOLMtrCals_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Sa_MtrPos_MtrPos_SCom_SetEOLMtrCals_Return
# endif
# if defined (Rte_Runnable_Sa_MtrPos_MtrPos_SCom_SetEOLMtrCals_Return)
#  undef Rte_Runnable_Sa_MtrPos_MtrPos_SCom_SetEOLMtrCals_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Sa_MtrPos_MtrPos_SCom_SetEOLMtrCals_Return(P2CONST(MtrPosCal_DataType, AUTOMATIC, RTE_SA_MTRPOS_APPL_DATA) MtrCalDataPtr);
# else
#  define Rte_Runnable_Sa_MtrPos_MtrPos_SCom_SetEOLMtrCals_Return(arg1) ((void)(0))
# endif /* Rte_Runnable_Sa_MtrPos_MtrPos_SCom_SetEOLMtrCals_Return */

# if defined (Rte_Runnable_Sa_MtrPos_MtrPos_SCom_SetEOLMtrCals_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Sa_MtrPos_MtrPos_SCom_SetEOLMtrCals_Start
# endif
# if defined (Rte_Runnable_Sa_MtrPos_MtrPos_SCom_SetEOLMtrCals_Start)
#  undef Rte_Runnable_Sa_MtrPos_MtrPos_SCom_SetEOLMtrCals_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Sa_MtrPos_MtrPos_SCom_SetEOLMtrCals_Start(P2CONST(MtrPosCal_DataType, AUTOMATIC, RTE_SA_MTRPOS_APPL_DATA) MtrCalDataPtr);
# else
#  define Rte_Runnable_Sa_MtrPos_MtrPos_SCom_SetEOLMtrCals_Start(arg1) ((void)(0))
# endif /* Rte_Runnable_Sa_MtrPos_MtrPos_SCom_SetEOLMtrCals_Start */

# if defined (Rte_Runnable_Sa_MtrVel2_MtrVel2_Init_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Sa_MtrVel2_MtrVel2_Init_Return
# endif
# if defined (Rte_Runnable_Sa_MtrVel2_MtrVel2_Init_Return)
#  undef Rte_Runnable_Sa_MtrVel2_MtrVel2_Init_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Sa_MtrVel2_MtrVel2_Init_Return(void);
# else
#  define Rte_Runnable_Sa_MtrVel2_MtrVel2_Init_Return() ((void)(0))
# endif /* Rte_Runnable_Sa_MtrVel2_MtrVel2_Init_Return */

# if defined (Rte_Runnable_Sa_MtrVel2_MtrVel2_Init_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Sa_MtrVel2_MtrVel2_Init_Start
# endif
# if defined (Rte_Runnable_Sa_MtrVel2_MtrVel2_Init_Start)
#  undef Rte_Runnable_Sa_MtrVel2_MtrVel2_Init_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Sa_MtrVel2_MtrVel2_Init_Start(void);
# else
#  define Rte_Runnable_Sa_MtrVel2_MtrVel2_Init_Start() ((void)(0))
# endif /* Rte_Runnable_Sa_MtrVel2_MtrVel2_Init_Start */

# if defined (Rte_Runnable_Sa_MtrVel2_MtrVel2_Per1_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Sa_MtrVel2_MtrVel2_Per1_Return
# endif
# if defined (Rte_Runnable_Sa_MtrVel2_MtrVel2_Per1_Return)
#  undef Rte_Runnable_Sa_MtrVel2_MtrVel2_Per1_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Sa_MtrVel2_MtrVel2_Per1_Return(void);
# else
#  define Rte_Runnable_Sa_MtrVel2_MtrVel2_Per1_Return() ((void)(0))
# endif /* Rte_Runnable_Sa_MtrVel2_MtrVel2_Per1_Return */

# if defined (Rte_Runnable_Sa_MtrVel2_MtrVel2_Per1_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Sa_MtrVel2_MtrVel2_Per1_Start
# endif
# if defined (Rte_Runnable_Sa_MtrVel2_MtrVel2_Per1_Start)
#  undef Rte_Runnable_Sa_MtrVel2_MtrVel2_Per1_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Sa_MtrVel2_MtrVel2_Per1_Start(void);
# else
#  define Rte_Runnable_Sa_MtrVel2_MtrVel2_Per1_Start() ((void)(0))
# endif /* Rte_Runnable_Sa_MtrVel2_MtrVel2_Per1_Start */

# if defined (Rte_Runnable_Sa_MtrVel2_MtrVel2_Per2_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Sa_MtrVel2_MtrVel2_Per2_Return
# endif
# if defined (Rte_Runnable_Sa_MtrVel2_MtrVel2_Per2_Return)
#  undef Rte_Runnable_Sa_MtrVel2_MtrVel2_Per2_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Sa_MtrVel2_MtrVel2_Per2_Return(void);
# else
#  define Rte_Runnable_Sa_MtrVel2_MtrVel2_Per2_Return() ((void)(0))
# endif /* Rte_Runnable_Sa_MtrVel2_MtrVel2_Per2_Return */

# if defined (Rte_Runnable_Sa_MtrVel2_MtrVel2_Per2_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Sa_MtrVel2_MtrVel2_Per2_Start
# endif
# if defined (Rte_Runnable_Sa_MtrVel2_MtrVel2_Per2_Start)
#  undef Rte_Runnable_Sa_MtrVel2_MtrVel2_Per2_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Sa_MtrVel2_MtrVel2_Per2_Start(void);
# else
#  define Rte_Runnable_Sa_MtrVel2_MtrVel2_Per2_Start() ((void)(0))
# endif /* Rte_Runnable_Sa_MtrVel2_MtrVel2_Per2_Start */

# if defined (Rte_Runnable_Sa_MtrVel3_MtrVel3_Init_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Sa_MtrVel3_MtrVel3_Init_Return
# endif
# if defined (Rte_Runnable_Sa_MtrVel3_MtrVel3_Init_Return)
#  undef Rte_Runnable_Sa_MtrVel3_MtrVel3_Init_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Sa_MtrVel3_MtrVel3_Init_Return(void);
# else
#  define Rte_Runnable_Sa_MtrVel3_MtrVel3_Init_Return() ((void)(0))
# endif /* Rte_Runnable_Sa_MtrVel3_MtrVel3_Init_Return */

# if defined (Rte_Runnable_Sa_MtrVel3_MtrVel3_Init_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Sa_MtrVel3_MtrVel3_Init_Start
# endif
# if defined (Rte_Runnable_Sa_MtrVel3_MtrVel3_Init_Start)
#  undef Rte_Runnable_Sa_MtrVel3_MtrVel3_Init_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Sa_MtrVel3_MtrVel3_Init_Start(void);
# else
#  define Rte_Runnable_Sa_MtrVel3_MtrVel3_Init_Start() ((void)(0))
# endif /* Rte_Runnable_Sa_MtrVel3_MtrVel3_Init_Start */

# if defined (Rte_Runnable_Sa_MtrVel_MtrVel_Init1_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Sa_MtrVel_MtrVel_Init1_Return
# endif
# if defined (Rte_Runnable_Sa_MtrVel_MtrVel_Init1_Return)
#  undef Rte_Runnable_Sa_MtrVel_MtrVel_Init1_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Sa_MtrVel_MtrVel_Init1_Return(void);
# else
#  define Rte_Runnable_Sa_MtrVel_MtrVel_Init1_Return() ((void)(0))
# endif /* Rte_Runnable_Sa_MtrVel_MtrVel_Init1_Return */

# if defined (Rte_Runnable_Sa_MtrVel_MtrVel_Init1_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Sa_MtrVel_MtrVel_Init1_Start
# endif
# if defined (Rte_Runnable_Sa_MtrVel_MtrVel_Init1_Start)
#  undef Rte_Runnable_Sa_MtrVel_MtrVel_Init1_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Sa_MtrVel_MtrVel_Init1_Start(void);
# else
#  define Rte_Runnable_Sa_MtrVel_MtrVel_Init1_Start() ((void)(0))
# endif /* Rte_Runnable_Sa_MtrVel_MtrVel_Init1_Start */

# if defined (Rte_Runnable_Sa_MtrVel_MtrVel_Per1_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Sa_MtrVel_MtrVel_Per1_Return
# endif
# if defined (Rte_Runnable_Sa_MtrVel_MtrVel_Per1_Return)
#  undef Rte_Runnable_Sa_MtrVel_MtrVel_Per1_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Sa_MtrVel_MtrVel_Per1_Return(void);
# else
#  define Rte_Runnable_Sa_MtrVel_MtrVel_Per1_Return() ((void)(0))
# endif /* Rte_Runnable_Sa_MtrVel_MtrVel_Per1_Return */

# if defined (Rte_Runnable_Sa_MtrVel_MtrVel_Per1_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Sa_MtrVel_MtrVel_Per1_Start
# endif
# if defined (Rte_Runnable_Sa_MtrVel_MtrVel_Per1_Start)
#  undef Rte_Runnable_Sa_MtrVel_MtrVel_Per1_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Sa_MtrVel_MtrVel_Per1_Start(void);
# else
#  define Rte_Runnable_Sa_MtrVel_MtrVel_Per1_Start() ((void)(0))
# endif /* Rte_Runnable_Sa_MtrVel_MtrVel_Per1_Start */

# if defined (Rte_Runnable_Sa_MtrVel_MtrVel_Per2_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Sa_MtrVel_MtrVel_Per2_Return
# endif
# if defined (Rte_Runnable_Sa_MtrVel_MtrVel_Per2_Return)
#  undef Rte_Runnable_Sa_MtrVel_MtrVel_Per2_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Sa_MtrVel_MtrVel_Per2_Return(void);
# else
#  define Rte_Runnable_Sa_MtrVel_MtrVel_Per2_Return() ((void)(0))
# endif /* Rte_Runnable_Sa_MtrVel_MtrVel_Per2_Return */

# if defined (Rte_Runnable_Sa_MtrVel_MtrVel_Per2_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Sa_MtrVel_MtrVel_Per2_Start
# endif
# if defined (Rte_Runnable_Sa_MtrVel_MtrVel_Per2_Start)
#  undef Rte_Runnable_Sa_MtrVel_MtrVel_Per2_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Sa_MtrVel_MtrVel_Per2_Start(void);
# else
#  define Rte_Runnable_Sa_MtrVel_MtrVel_Per2_Start() ((void)(0))
# endif /* Rte_Runnable_Sa_MtrVel_MtrVel_Per2_Start */

# if defined (Rte_Runnable_Sa_OvrVoltMon_OvrVoltMon_Per1_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Sa_OvrVoltMon_OvrVoltMon_Per1_Return
# endif
# if defined (Rte_Runnable_Sa_OvrVoltMon_OvrVoltMon_Per1_Return)
#  undef Rte_Runnable_Sa_OvrVoltMon_OvrVoltMon_Per1_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Sa_OvrVoltMon_OvrVoltMon_Per1_Return(void);
# else
#  define Rte_Runnable_Sa_OvrVoltMon_OvrVoltMon_Per1_Return() ((void)(0))
# endif /* Rte_Runnable_Sa_OvrVoltMon_OvrVoltMon_Per1_Return */

# if defined (Rte_Runnable_Sa_OvrVoltMon_OvrVoltMon_Per1_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Sa_OvrVoltMon_OvrVoltMon_Per1_Start
# endif
# if defined (Rte_Runnable_Sa_OvrVoltMon_OvrVoltMon_Per1_Start)
#  undef Rte_Runnable_Sa_OvrVoltMon_OvrVoltMon_Per1_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Sa_OvrVoltMon_OvrVoltMon_Per1_Start(void);
# else
#  define Rte_Runnable_Sa_OvrVoltMon_OvrVoltMon_Per1_Start() ((void)(0))
# endif /* Rte_Runnable_Sa_OvrVoltMon_OvrVoltMon_Per1_Start */

# if defined (Rte_Runnable_Sa_ShtdnMech_ShtdnMech_Per1_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Sa_ShtdnMech_ShtdnMech_Per1_Return
# endif
# if defined (Rte_Runnable_Sa_ShtdnMech_ShtdnMech_Per1_Return)
#  undef Rte_Runnable_Sa_ShtdnMech_ShtdnMech_Per1_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Sa_ShtdnMech_ShtdnMech_Per1_Return(void);
# else
#  define Rte_Runnable_Sa_ShtdnMech_ShtdnMech_Per1_Return() ((void)(0))
# endif /* Rte_Runnable_Sa_ShtdnMech_ShtdnMech_Per1_Return */

# if defined (Rte_Runnable_Sa_ShtdnMech_ShtdnMech_Per1_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Sa_ShtdnMech_ShtdnMech_Per1_Start
# endif
# if defined (Rte_Runnable_Sa_ShtdnMech_ShtdnMech_Per1_Start)
#  undef Rte_Runnable_Sa_ShtdnMech_ShtdnMech_Per1_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Sa_ShtdnMech_ShtdnMech_Per1_Start(void);
# else
#  define Rte_Runnable_Sa_ShtdnMech_ShtdnMech_Per1_Start() ((void)(0))
# endif /* Rte_Runnable_Sa_ShtdnMech_ShtdnMech_Per1_Start */

# if defined (Rte_Runnable_Sa_TmprlMon2_TmprlMon2_Per1_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Sa_TmprlMon2_TmprlMon2_Per1_Return
# endif
# if defined (Rte_Runnable_Sa_TmprlMon2_TmprlMon2_Per1_Return)
#  undef Rte_Runnable_Sa_TmprlMon2_TmprlMon2_Per1_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Sa_TmprlMon2_TmprlMon2_Per1_Return(void);
# else
#  define Rte_Runnable_Sa_TmprlMon2_TmprlMon2_Per1_Return() ((void)(0))
# endif /* Rte_Runnable_Sa_TmprlMon2_TmprlMon2_Per1_Return */

# if defined (Rte_Runnable_Sa_TmprlMon2_TmprlMon2_Per1_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Sa_TmprlMon2_TmprlMon2_Per1_Start
# endif
# if defined (Rte_Runnable_Sa_TmprlMon2_TmprlMon2_Per1_Start)
#  undef Rte_Runnable_Sa_TmprlMon2_TmprlMon2_Per1_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Sa_TmprlMon2_TmprlMon2_Per1_Start(void);
# else
#  define Rte_Runnable_Sa_TmprlMon2_TmprlMon2_Per1_Start() ((void)(0))
# endif /* Rte_Runnable_Sa_TmprlMon2_TmprlMon2_Per1_Start */

# if defined (Rte_Runnable_Sa_TmprlMon_TmprlMon_Per1_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Sa_TmprlMon_TmprlMon_Per1_Return
# endif
# if defined (Rte_Runnable_Sa_TmprlMon_TmprlMon_Per1_Return)
#  undef Rte_Runnable_Sa_TmprlMon_TmprlMon_Per1_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Sa_TmprlMon_TmprlMon_Per1_Return(void);
# else
#  define Rte_Runnable_Sa_TmprlMon_TmprlMon_Per1_Return() ((void)(0))
# endif /* Rte_Runnable_Sa_TmprlMon_TmprlMon_Per1_Return */

# if defined (Rte_Runnable_Sa_TmprlMon_TmprlMon_Per1_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Sa_TmprlMon_TmprlMon_Per1_Start
# endif
# if defined (Rte_Runnable_Sa_TmprlMon_TmprlMon_Per1_Start)
#  undef Rte_Runnable_Sa_TmprlMon_TmprlMon_Per1_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Sa_TmprlMon_TmprlMon_Per1_Start(void);
# else
#  define Rte_Runnable_Sa_TmprlMon_TmprlMon_Per1_Start() ((void)(0))
# endif /* Rte_Runnable_Sa_TmprlMon_TmprlMon_Per1_Start */

# if defined (Rte_Runnable_Sa_TmprlMon_TmprlMon_Per2_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Sa_TmprlMon_TmprlMon_Per2_Return
# endif
# if defined (Rte_Runnable_Sa_TmprlMon_TmprlMon_Per2_Return)
#  undef Rte_Runnable_Sa_TmprlMon_TmprlMon_Per2_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Sa_TmprlMon_TmprlMon_Per2_Return(void);
# else
#  define Rte_Runnable_Sa_TmprlMon_TmprlMon_Per2_Return() ((void)(0))
# endif /* Rte_Runnable_Sa_TmprlMon_TmprlMon_Per2_Return */

# if defined (Rte_Runnable_Sa_TmprlMon_TmprlMon_Per2_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Sa_TmprlMon_TmprlMon_Per2_Start
# endif
# if defined (Rte_Runnable_Sa_TmprlMon_TmprlMon_Per2_Start)
#  undef Rte_Runnable_Sa_TmprlMon_TmprlMon_Per2_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Sa_TmprlMon_TmprlMon_Per2_Start(void);
# else
#  define Rte_Runnable_Sa_TmprlMon_TmprlMon_Per2_Start() ((void)(0))
# endif /* Rte_Runnable_Sa_TmprlMon_TmprlMon_Per2_Start */

# if defined (Rte_Runnable_Sa_TmprlMon_TmprlMon_Per3_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Sa_TmprlMon_TmprlMon_Per3_Return
# endif
# if defined (Rte_Runnable_Sa_TmprlMon_TmprlMon_Per3_Return)
#  undef Rte_Runnable_Sa_TmprlMon_TmprlMon_Per3_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Sa_TmprlMon_TmprlMon_Per3_Return(void);
# else
#  define Rte_Runnable_Sa_TmprlMon_TmprlMon_Per3_Return() ((void)(0))
# endif /* Rte_Runnable_Sa_TmprlMon_TmprlMon_Per3_Return */

# if defined (Rte_Runnable_Sa_TmprlMon_TmprlMon_Per3_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Sa_TmprlMon_TmprlMon_Per3_Start
# endif
# if defined (Rte_Runnable_Sa_TmprlMon_TmprlMon_Per3_Start)
#  undef Rte_Runnable_Sa_TmprlMon_TmprlMon_Per3_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Sa_TmprlMon_TmprlMon_Per3_Start(void);
# else
#  define Rte_Runnable_Sa_TmprlMon_TmprlMon_Per3_Start() ((void)(0))
# endif /* Rte_Runnable_Sa_TmprlMon_TmprlMon_Per3_Start */

# if defined (Rte_Runnable_Sa_TmprlMon_TmprlMon_Trns1_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Sa_TmprlMon_TmprlMon_Trns1_Return
# endif
# if defined (Rte_Runnable_Sa_TmprlMon_TmprlMon_Trns1_Return)
#  undef Rte_Runnable_Sa_TmprlMon_TmprlMon_Trns1_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Sa_TmprlMon_TmprlMon_Trns1_Return(void);
# else
#  define Rte_Runnable_Sa_TmprlMon_TmprlMon_Trns1_Return() ((void)(0))
# endif /* Rte_Runnable_Sa_TmprlMon_TmprlMon_Trns1_Return */

# if defined (Rte_Runnable_Sa_TmprlMon_TmprlMon_Trns1_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Sa_TmprlMon_TmprlMon_Trns1_Start
# endif
# if defined (Rte_Runnable_Sa_TmprlMon_TmprlMon_Trns1_Start)
#  undef Rte_Runnable_Sa_TmprlMon_TmprlMon_Trns1_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Sa_TmprlMon_TmprlMon_Trns1_Start(void);
# else
#  define Rte_Runnable_Sa_TmprlMon_TmprlMon_Trns1_Start() ((void)(0))
# endif /* Rte_Runnable_Sa_TmprlMon_TmprlMon_Trns1_Start */

# if defined (Rte_Runnable_Sa_TmprlMon_TmprlMon_Trns2_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Sa_TmprlMon_TmprlMon_Trns2_Return
# endif
# if defined (Rte_Runnable_Sa_TmprlMon_TmprlMon_Trns2_Return)
#  undef Rte_Runnable_Sa_TmprlMon_TmprlMon_Trns2_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Sa_TmprlMon_TmprlMon_Trns2_Return(void);
# else
#  define Rte_Runnable_Sa_TmprlMon_TmprlMon_Trns2_Return() ((void)(0))
# endif /* Rte_Runnable_Sa_TmprlMon_TmprlMon_Trns2_Return */

# if defined (Rte_Runnable_Sa_TmprlMon_TmprlMon_Trns2_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Sa_TmprlMon_TmprlMon_Trns2_Start
# endif
# if defined (Rte_Runnable_Sa_TmprlMon_TmprlMon_Trns2_Start)
#  undef Rte_Runnable_Sa_TmprlMon_TmprlMon_Trns2_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Sa_TmprlMon_TmprlMon_Trns2_Start(void);
# else
#  define Rte_Runnable_Sa_TmprlMon_TmprlMon_Trns2_Start() ((void)(0))
# endif /* Rte_Runnable_Sa_TmprlMon_TmprlMon_Trns2_Start */

# if defined (Rte_Runnable_WdgM_ActivateSupervisionEntity_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_WdgM_ActivateSupervisionEntity_Return
# endif
# if defined (Rte_Runnable_WdgM_ActivateSupervisionEntity_Return)
#  undef Rte_Runnable_WdgM_ActivateSupervisionEntity_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_WdgM_ActivateSupervisionEntity_Return(WdgM_SupervisedEntityIdType parg0);
# else
#  define Rte_Runnable_WdgM_ActivateSupervisionEntity_Return(arg1) ((void)(0))
# endif /* Rte_Runnable_WdgM_ActivateSupervisionEntity_Return */

# if defined (Rte_Runnable_WdgM_ActivateSupervisionEntity_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_WdgM_ActivateSupervisionEntity_Start
# endif
# if defined (Rte_Runnable_WdgM_ActivateSupervisionEntity_Start)
#  undef Rte_Runnable_WdgM_ActivateSupervisionEntity_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_WdgM_ActivateSupervisionEntity_Start(WdgM_SupervisedEntityIdType parg0);
# else
#  define Rte_Runnable_WdgM_ActivateSupervisionEntity_Start(arg1) ((void)(0))
# endif /* Rte_Runnable_WdgM_ActivateSupervisionEntity_Start */

# if defined (Rte_Runnable_WdgM_CheckpointReached_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_WdgM_CheckpointReached_Return
# endif
# if defined (Rte_Runnable_WdgM_CheckpointReached_Return)
#  undef Rte_Runnable_WdgM_CheckpointReached_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_WdgM_CheckpointReached_Return(WdgM_SupervisedEntityIdType parg0, WdgM_CheckpointIdType parg1);
# else
#  define Rte_Runnable_WdgM_CheckpointReached_Return(arg1, arg2) ((void)(0))
# endif /* Rte_Runnable_WdgM_CheckpointReached_Return */

# if defined (Rte_Runnable_WdgM_CheckpointReached_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_WdgM_CheckpointReached_Start
# endif
# if defined (Rte_Runnable_WdgM_CheckpointReached_Start)
#  undef Rte_Runnable_WdgM_CheckpointReached_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_WdgM_CheckpointReached_Start(WdgM_SupervisedEntityIdType parg0, WdgM_CheckpointIdType parg1);
# else
#  define Rte_Runnable_WdgM_CheckpointReached_Start(arg1, arg2) ((void)(0))
# endif /* Rte_Runnable_WdgM_CheckpointReached_Start */

# if defined (Rte_Runnable_WdgM_DeactivateSupervisionEntity_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_WdgM_DeactivateSupervisionEntity_Return
# endif
# if defined (Rte_Runnable_WdgM_DeactivateSupervisionEntity_Return)
#  undef Rte_Runnable_WdgM_DeactivateSupervisionEntity_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_WdgM_DeactivateSupervisionEntity_Return(WdgM_SupervisedEntityIdType parg0);
# else
#  define Rte_Runnable_WdgM_DeactivateSupervisionEntity_Return(arg1) ((void)(0))
# endif /* Rte_Runnable_WdgM_DeactivateSupervisionEntity_Return */

# if defined (Rte_Runnable_WdgM_DeactivateSupervisionEntity_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_WdgM_DeactivateSupervisionEntity_Start
# endif
# if defined (Rte_Runnable_WdgM_DeactivateSupervisionEntity_Start)
#  undef Rte_Runnable_WdgM_DeactivateSupervisionEntity_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_WdgM_DeactivateSupervisionEntity_Start(WdgM_SupervisedEntityIdType parg0);
# else
#  define Rte_Runnable_WdgM_DeactivateSupervisionEntity_Start(arg1) ((void)(0))
# endif /* Rte_Runnable_WdgM_DeactivateSupervisionEntity_Start */

# if defined (Rte_Runnable_WdgM_GetGlobalStatus_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_WdgM_GetGlobalStatus_Return
# endif
# if defined (Rte_Runnable_WdgM_GetGlobalStatus_Return)
#  undef Rte_Runnable_WdgM_GetGlobalStatus_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_WdgM_GetGlobalStatus_Return(P2VAR(WdgM_GlobalStatusType, AUTOMATIC, RTE_WDGM_APPL_VAR) Status);
# else
#  define Rte_Runnable_WdgM_GetGlobalStatus_Return(arg1) ((void)(0))
# endif /* Rte_Runnable_WdgM_GetGlobalStatus_Return */

# if defined (Rte_Runnable_WdgM_GetGlobalStatus_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_WdgM_GetGlobalStatus_Start
# endif
# if defined (Rte_Runnable_WdgM_GetGlobalStatus_Start)
#  undef Rte_Runnable_WdgM_GetGlobalStatus_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_WdgM_GetGlobalStatus_Start(P2VAR(WdgM_GlobalStatusType, AUTOMATIC, RTE_WDGM_APPL_VAR) Status);
# else
#  define Rte_Runnable_WdgM_GetGlobalStatus_Start(arg1) ((void)(0))
# endif /* Rte_Runnable_WdgM_GetGlobalStatus_Start */

# if defined (Rte_Runnable_WdgM_GetLocalStatus_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_WdgM_GetLocalStatus_Return
# endif
# if defined (Rte_Runnable_WdgM_GetLocalStatus_Return)
#  undef Rte_Runnable_WdgM_GetLocalStatus_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_WdgM_GetLocalStatus_Return(WdgM_SupervisedEntityIdType parg0, P2VAR(WdgM_LocalStatusType, AUTOMATIC, RTE_WDGM_APPL_VAR) Status);
# else
#  define Rte_Runnable_WdgM_GetLocalStatus_Return(arg1, arg2) ((void)(0))
# endif /* Rte_Runnable_WdgM_GetLocalStatus_Return */

# if defined (Rte_Runnable_WdgM_GetLocalStatus_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_WdgM_GetLocalStatus_Start
# endif
# if defined (Rte_Runnable_WdgM_GetLocalStatus_Start)
#  undef Rte_Runnable_WdgM_GetLocalStatus_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_WdgM_GetLocalStatus_Start(WdgM_SupervisedEntityIdType parg0, P2VAR(WdgM_LocalStatusType, AUTOMATIC, RTE_WDGM_APPL_VAR) Status);
# else
#  define Rte_Runnable_WdgM_GetLocalStatus_Start(arg1, arg2) ((void)(0))
# endif /* Rte_Runnable_WdgM_GetLocalStatus_Start */

# if defined (Rte_Runnable_WdgM_GetMode_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_WdgM_GetMode_Return
# endif
# if defined (Rte_Runnable_WdgM_GetMode_Return)
#  undef Rte_Runnable_WdgM_GetMode_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_WdgM_GetMode_Return(P2VAR(WdgM_ModeType, AUTOMATIC, RTE_WDGM_APPL_VAR) Mode);
# else
#  define Rte_Runnable_WdgM_GetMode_Return(arg1) ((void)(0))
# endif /* Rte_Runnable_WdgM_GetMode_Return */

# if defined (Rte_Runnable_WdgM_GetMode_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_WdgM_GetMode_Start
# endif
# if defined (Rte_Runnable_WdgM_GetMode_Start)
#  undef Rte_Runnable_WdgM_GetMode_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_WdgM_GetMode_Start(P2VAR(WdgM_ModeType, AUTOMATIC, RTE_WDGM_APPL_VAR) Mode);
# else
#  define Rte_Runnable_WdgM_GetMode_Start(arg1) ((void)(0))
# endif /* Rte_Runnable_WdgM_GetMode_Start */

# if defined (Rte_Runnable_WdgM_GlobalStateChangeCbk_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_WdgM_GlobalStateChangeCbk_Return
# endif
# if defined (Rte_Runnable_WdgM_GlobalStateChangeCbk_Return)
#  undef Rte_Runnable_WdgM_GlobalStateChangeCbk_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_WdgM_GlobalStateChangeCbk_Return(WdgM_GlobalStatusType Status);
# else
#  define Rte_Runnable_WdgM_GlobalStateChangeCbk_Return(arg1) ((void)(0))
# endif /* Rte_Runnable_WdgM_GlobalStateChangeCbk_Return */

# if defined (Rte_Runnable_WdgM_GlobalStateChangeCbk_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_WdgM_GlobalStateChangeCbk_Start
# endif
# if defined (Rte_Runnable_WdgM_GlobalStateChangeCbk_Start)
#  undef Rte_Runnable_WdgM_GlobalStateChangeCbk_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_WdgM_GlobalStateChangeCbk_Start(WdgM_GlobalStatusType Status);
# else
#  define Rte_Runnable_WdgM_GlobalStateChangeCbk_Start(arg1) ((void)(0))
# endif /* Rte_Runnable_WdgM_GlobalStateChangeCbk_Start */

# if defined (Rte_Runnable_WdgM_MainFunction_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_WdgM_MainFunction_Return
# endif
# if defined (Rte_Runnable_WdgM_MainFunction_Return)
#  undef Rte_Runnable_WdgM_MainFunction_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_WdgM_MainFunction_Return(void);
# else
#  define Rte_Runnable_WdgM_MainFunction_Return() ((void)(0))
# endif /* Rte_Runnable_WdgM_MainFunction_Return */

# if defined (Rte_Runnable_WdgM_MainFunction_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_WdgM_MainFunction_Start
# endif
# if defined (Rte_Runnable_WdgM_MainFunction_Start)
#  undef Rte_Runnable_WdgM_MainFunction_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_WdgM_MainFunction_Start(void);
# else
#  define Rte_Runnable_WdgM_MainFunction_Start() ((void)(0))
# endif /* Rte_Runnable_WdgM_MainFunction_Start */

# if defined (Rte_Runnable_WdgM_PerformReset_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_WdgM_PerformReset_Return
# endif
# if defined (Rte_Runnable_WdgM_PerformReset_Return)
#  undef Rte_Runnable_WdgM_PerformReset_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_WdgM_PerformReset_Return(void);
# else
#  define Rte_Runnable_WdgM_PerformReset_Return() ((void)(0))
# endif /* Rte_Runnable_WdgM_PerformReset_Return */

# if defined (Rte_Runnable_WdgM_PerformReset_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_WdgM_PerformReset_Start
# endif
# if defined (Rte_Runnable_WdgM_PerformReset_Start)
#  undef Rte_Runnable_WdgM_PerformReset_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_WdgM_PerformReset_Start(void);
# else
#  define Rte_Runnable_WdgM_PerformReset_Start() ((void)(0))
# endif /* Rte_Runnable_WdgM_PerformReset_Start */

# if defined (Rte_Runnable_WdgM_SetMode_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_WdgM_SetMode_Return
# endif
# if defined (Rte_Runnable_WdgM_SetMode_Return)
#  undef Rte_Runnable_WdgM_SetMode_Return
FUNC(void, RTE_APPL_CODE) Rte_Runnable_WdgM_SetMode_Return(WdgM_ModeType parg0, UInt16 parg1);
# else
#  define Rte_Runnable_WdgM_SetMode_Return(arg1, arg2) ((void)(0))
# endif /* Rte_Runnable_WdgM_SetMode_Return */

# if defined (Rte_Runnable_WdgM_SetMode_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_WdgM_SetMode_Start
# endif
# if defined (Rte_Runnable_WdgM_SetMode_Start)
#  undef Rte_Runnable_WdgM_SetMode_Start
FUNC(void, RTE_APPL_CODE) Rte_Runnable_WdgM_SetMode_Start(WdgM_ModeType parg0, UInt16 parg1);
# else
#  define Rte_Runnable_WdgM_SetMode_Start(arg1, arg2) ((void)(0))
# endif /* Rte_Runnable_WdgM_SetMode_Start */

# if defined (Rte_SwitchHook_Ap_StaMd8_SystemState8_Mode_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_SwitchHook_Ap_StaMd8_SystemState8_Mode_Return
# endif
# if defined (Rte_SwitchHook_Ap_StaMd8_SystemState8_Mode_Return)
#  undef Rte_SwitchHook_Ap_StaMd8_SystemState8_Mode_Return
FUNC(void, RTE_APPL_CODE) Rte_SwitchHook_Ap_StaMd8_SystemState8_Mode_Return(Rte_ModeType_StaMd_Mode mode);
# else
#  define Rte_SwitchHook_Ap_StaMd8_SystemState8_Mode_Return(arg1) ((void)(0))
# endif /* Rte_SwitchHook_Ap_StaMd8_SystemState8_Mode_Return */

# if defined (Rte_SwitchHook_Ap_StaMd8_SystemState8_Mode_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_SwitchHook_Ap_StaMd8_SystemState8_Mode_Start
# endif
# if defined (Rte_SwitchHook_Ap_StaMd8_SystemState8_Mode_Start)
#  undef Rte_SwitchHook_Ap_StaMd8_SystemState8_Mode_Start
FUNC(void, RTE_APPL_CODE) Rte_SwitchHook_Ap_StaMd8_SystemState8_Mode_Start(Rte_ModeType_StaMd_Mode mode);
# else
#  define Rte_SwitchHook_Ap_StaMd8_SystemState8_Mode_Start(arg1) ((void)(0))
# endif /* Rte_SwitchHook_Ap_StaMd8_SystemState8_Mode_Start */

# if defined (Rte_SwitchHook_Ap_StaMd9_SystemState9_Mode_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_SwitchHook_Ap_StaMd9_SystemState9_Mode_Return
# endif
# if defined (Rte_SwitchHook_Ap_StaMd9_SystemState9_Mode_Return)
#  undef Rte_SwitchHook_Ap_StaMd9_SystemState9_Mode_Return
FUNC(void, RTE_APPL_CODE) Rte_SwitchHook_Ap_StaMd9_SystemState9_Mode_Return(Rte_ModeType_StaMd_Mode mode);
# else
#  define Rte_SwitchHook_Ap_StaMd9_SystemState9_Mode_Return(arg1) ((void)(0))
# endif /* Rte_SwitchHook_Ap_StaMd9_SystemState9_Mode_Return */

# if defined (Rte_SwitchHook_Ap_StaMd9_SystemState9_Mode_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_SwitchHook_Ap_StaMd9_SystemState9_Mode_Start
# endif
# if defined (Rte_SwitchHook_Ap_StaMd9_SystemState9_Mode_Start)
#  undef Rte_SwitchHook_Ap_StaMd9_SystemState9_Mode_Start
FUNC(void, RTE_APPL_CODE) Rte_SwitchHook_Ap_StaMd9_SystemState9_Mode_Start(Rte_ModeType_StaMd_Mode mode);
# else
#  define Rte_SwitchHook_Ap_StaMd9_SystemState9_Mode_Start(arg1) ((void)(0))
# endif /* Rte_SwitchHook_Ap_StaMd9_SystemState9_Mode_Start */

# if defined (Rte_SwitchHook_Ap_StaMd_SystemState_Mode_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_SwitchHook_Ap_StaMd_SystemState_Mode_Return
# endif
# if defined (Rte_SwitchHook_Ap_StaMd_SystemState_Mode_Return)
#  undef Rte_SwitchHook_Ap_StaMd_SystemState_Mode_Return
FUNC(void, RTE_APPL_CODE) Rte_SwitchHook_Ap_StaMd_SystemState_Mode_Return(Rte_ModeType_StaMd_Mode mode);
# else
#  define Rte_SwitchHook_Ap_StaMd_SystemState_Mode_Return(arg1) ((void)(0))
# endif /* Rte_SwitchHook_Ap_StaMd_SystemState_Mode_Return */

# if defined (Rte_SwitchHook_Ap_StaMd_SystemState_Mode_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_SwitchHook_Ap_StaMd_SystemState_Mode_Start
# endif
# if defined (Rte_SwitchHook_Ap_StaMd_SystemState_Mode_Start)
#  undef Rte_SwitchHook_Ap_StaMd_SystemState_Mode_Start
FUNC(void, RTE_APPL_CODE) Rte_SwitchHook_Ap_StaMd_SystemState_Mode_Start(Rte_ModeType_StaMd_Mode mode);
# else
#  define Rte_SwitchHook_Ap_StaMd_SystemState_Mode_Start(arg1) ((void)(0))
# endif /* Rte_SwitchHook_Ap_StaMd_SystemState_Mode_Start */

# if defined (Rte_SwitchHook_EcuM_currentMode_currentMode_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_SwitchHook_EcuM_currentMode_currentMode_Return
# endif
# if defined (Rte_SwitchHook_EcuM_currentMode_currentMode_Return)
#  undef Rte_SwitchHook_EcuM_currentMode_currentMode_Return
FUNC(void, RTE_APPL_CODE) Rte_SwitchHook_EcuM_currentMode_currentMode_Return(Rte_ModeType_EcuM_Mode mode);
# else
#  define Rte_SwitchHook_EcuM_currentMode_currentMode_Return(arg1) ((void)(0))
# endif /* Rte_SwitchHook_EcuM_currentMode_currentMode_Return */

# if defined (Rte_SwitchHook_EcuM_currentMode_currentMode_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_SwitchHook_EcuM_currentMode_currentMode_Start
# endif
# if defined (Rte_SwitchHook_EcuM_currentMode_currentMode_Start)
#  undef Rte_SwitchHook_EcuM_currentMode_currentMode_Start
FUNC(void, RTE_APPL_CODE) Rte_SwitchHook_EcuM_currentMode_currentMode_Start(Rte_ModeType_EcuM_Mode mode);
# else
#  define Rte_SwitchHook_EcuM_currentMode_currentMode_Start(arg1) ((void)(0))
# endif /* Rte_SwitchHook_EcuM_currentMode_currentMode_Start */

# if defined (Rte_Task_Activate) && (RTE_VFB_TRACE == 0)
#  undef Rte_Task_Activate
# endif
# if defined (Rte_Task_Activate)
#  undef Rte_Task_Activate
FUNC(void, RTE_APPL_CODE) Rte_Task_Activate(TaskType task);
# else
#  define Rte_Task_Activate(arg1) ((void)(0))
# endif /* Rte_Task_Activate */

# if defined (Rte_Task_Dispatch) && (RTE_VFB_TRACE == 0)
#  undef Rte_Task_Dispatch
# endif
# if defined (Rte_Task_Dispatch)
#  undef Rte_Task_Dispatch
FUNC(void, RTE_APPL_CODE) Rte_Task_Dispatch(TaskType task);
# else
#  define Rte_Task_Dispatch(arg1) ((void)(0))
# endif /* Rte_Task_Dispatch */

# if defined (Rte_Task_SetEvent) && (RTE_VFB_TRACE == 0)
#  undef Rte_Task_SetEvent
# endif
# if defined (Rte_Task_SetEvent)
#  undef Rte_Task_SetEvent
FUNC(void, RTE_APPL_CODE) Rte_Task_SetEvent(TaskType task, EventMaskType ev);
# else
#  define Rte_Task_SetEvent(arg1, arg2) ((void)(0))
# endif /* Rte_Task_SetEvent */

# if defined (Rte_Task_WaitEvent) && (RTE_VFB_TRACE == 0)
#  undef Rte_Task_WaitEvent
# endif
# if defined (Rte_Task_WaitEvent)
#  undef Rte_Task_WaitEvent
FUNC(void, RTE_APPL_CODE) Rte_Task_WaitEvent(TaskType task, EventMaskType ev);
# else
#  define Rte_Task_WaitEvent(arg1, arg2) ((void)(0))
# endif /* Rte_Task_WaitEvent */

# if defined (Rte_Task_WaitEventRet) && (RTE_VFB_TRACE == 0)
#  undef Rte_Task_WaitEventRet
# endif
# if defined (Rte_Task_WaitEventRet)
#  undef Rte_Task_WaitEventRet
FUNC(void, RTE_APPL_CODE) Rte_Task_WaitEventRet(TaskType task, EventMaskType ev);
# else
#  define Rte_Task_WaitEventRet(arg1, arg2) ((void)(0))
# endif /* Rte_Task_WaitEventRet */

# if defined (Rte_WriteHook_Ap_DiagMgr10_DiagRampRate_XpmS_f32_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_WriteHook_Ap_DiagMgr10_DiagRampRate_XpmS_f32_Return
# endif
# if defined (Rte_WriteHook_Ap_DiagMgr10_DiagRampRate_XpmS_f32_Return)
#  undef Rte_WriteHook_Ap_DiagMgr10_DiagRampRate_XpmS_f32_Return
FUNC(void, RTE_APPL_CODE) Rte_WriteHook_Ap_DiagMgr10_DiagRampRate_XpmS_f32_Return(Float data);
# else
#  define Rte_WriteHook_Ap_DiagMgr10_DiagRampRate_XpmS_f32_Return(arg1) ((void)(0))
# endif /* Rte_WriteHook_Ap_DiagMgr10_DiagRampRate_XpmS_f32_Return */

# if defined (Rte_WriteHook_Ap_DiagMgr10_DiagRampRate_XpmS_f32_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_WriteHook_Ap_DiagMgr10_DiagRampRate_XpmS_f32_Start
# endif
# if defined (Rte_WriteHook_Ap_DiagMgr10_DiagRampRate_XpmS_f32_Start)
#  undef Rte_WriteHook_Ap_DiagMgr10_DiagRampRate_XpmS_f32_Start
FUNC(void, RTE_APPL_CODE) Rte_WriteHook_Ap_DiagMgr10_DiagRampRate_XpmS_f32_Start(Float data);
# else
#  define Rte_WriteHook_Ap_DiagMgr10_DiagRampRate_XpmS_f32_Start(arg1) ((void)(0))
# endif /* Rte_WriteHook_Ap_DiagMgr10_DiagRampRate_XpmS_f32_Start */

# if defined (Rte_WriteHook_Ap_DiagMgr10_DiagRampValue_Uls_f32_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_WriteHook_Ap_DiagMgr10_DiagRampValue_Uls_f32_Return
# endif
# if defined (Rte_WriteHook_Ap_DiagMgr10_DiagRampValue_Uls_f32_Return)
#  undef Rte_WriteHook_Ap_DiagMgr10_DiagRampValue_Uls_f32_Return
FUNC(void, RTE_APPL_CODE) Rte_WriteHook_Ap_DiagMgr10_DiagRampValue_Uls_f32_Return(Float data);
# else
#  define Rte_WriteHook_Ap_DiagMgr10_DiagRampValue_Uls_f32_Return(arg1) ((void)(0))
# endif /* Rte_WriteHook_Ap_DiagMgr10_DiagRampValue_Uls_f32_Return */

# if defined (Rte_WriteHook_Ap_DiagMgr10_DiagRampValue_Uls_f32_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_WriteHook_Ap_DiagMgr10_DiagRampValue_Uls_f32_Start
# endif
# if defined (Rte_WriteHook_Ap_DiagMgr10_DiagRampValue_Uls_f32_Start)
#  undef Rte_WriteHook_Ap_DiagMgr10_DiagRampValue_Uls_f32_Start
FUNC(void, RTE_APPL_CODE) Rte_WriteHook_Ap_DiagMgr10_DiagRampValue_Uls_f32_Start(Float data);
# else
#  define Rte_WriteHook_Ap_DiagMgr10_DiagRampValue_Uls_f32_Start(arg1) ((void)(0))
# endif /* Rte_WriteHook_Ap_DiagMgr10_DiagRampValue_Uls_f32_Start */

# if defined (Rte_WriteHook_Ap_DiagMgr10_DiagRmpToZeroActive_Cnt_lgc_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_WriteHook_Ap_DiagMgr10_DiagRmpToZeroActive_Cnt_lgc_Return
# endif
# if defined (Rte_WriteHook_Ap_DiagMgr10_DiagRmpToZeroActive_Cnt_lgc_Return)
#  undef Rte_WriteHook_Ap_DiagMgr10_DiagRmpToZeroActive_Cnt_lgc_Return
FUNC(void, RTE_APPL_CODE) Rte_WriteHook_Ap_DiagMgr10_DiagRmpToZeroActive_Cnt_lgc_Return(Boolean data);
# else
#  define Rte_WriteHook_Ap_DiagMgr10_DiagRmpToZeroActive_Cnt_lgc_Return(arg1) ((void)(0))
# endif /* Rte_WriteHook_Ap_DiagMgr10_DiagRmpToZeroActive_Cnt_lgc_Return */

# if defined (Rte_WriteHook_Ap_DiagMgr10_DiagRmpToZeroActive_Cnt_lgc_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_WriteHook_Ap_DiagMgr10_DiagRmpToZeroActive_Cnt_lgc_Start
# endif
# if defined (Rte_WriteHook_Ap_DiagMgr10_DiagRmpToZeroActive_Cnt_lgc_Start)
#  undef Rte_WriteHook_Ap_DiagMgr10_DiagRmpToZeroActive_Cnt_lgc_Start
FUNC(void, RTE_APPL_CODE) Rte_WriteHook_Ap_DiagMgr10_DiagRmpToZeroActive_Cnt_lgc_Start(Boolean data);
# else
#  define Rte_WriteHook_Ap_DiagMgr10_DiagRmpToZeroActive_Cnt_lgc_Start(arg1) ((void)(0))
# endif /* Rte_WriteHook_Ap_DiagMgr10_DiagRmpToZeroActive_Cnt_lgc_Start */

# if defined (Rte_WriteHook_Ap_DiagMgr10_DiagStsCtrldDisRmpPres_Cnt_lgc_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_WriteHook_Ap_DiagMgr10_DiagStsCtrldDisRmpPres_Cnt_lgc_Return
# endif
# if defined (Rte_WriteHook_Ap_DiagMgr10_DiagStsCtrldDisRmpPres_Cnt_lgc_Return)
#  undef Rte_WriteHook_Ap_DiagMgr10_DiagStsCtrldDisRmpPres_Cnt_lgc_Return
FUNC(void, RTE_APPL_CODE) Rte_WriteHook_Ap_DiagMgr10_DiagStsCtrldDisRmpPres_Cnt_lgc_Return(Boolean data);
# else
#  define Rte_WriteHook_Ap_DiagMgr10_DiagStsCtrldDisRmpPres_Cnt_lgc_Return(arg1) ((void)(0))
# endif /* Rte_WriteHook_Ap_DiagMgr10_DiagStsCtrldDisRmpPres_Cnt_lgc_Return */

# if defined (Rte_WriteHook_Ap_DiagMgr10_DiagStsCtrldDisRmpPres_Cnt_lgc_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_WriteHook_Ap_DiagMgr10_DiagStsCtrldDisRmpPres_Cnt_lgc_Start
# endif
# if defined (Rte_WriteHook_Ap_DiagMgr10_DiagStsCtrldDisRmpPres_Cnt_lgc_Start)
#  undef Rte_WriteHook_Ap_DiagMgr10_DiagStsCtrldDisRmpPres_Cnt_lgc_Start
FUNC(void, RTE_APPL_CODE) Rte_WriteHook_Ap_DiagMgr10_DiagStsCtrldDisRmpPres_Cnt_lgc_Start(Boolean data);
# else
#  define Rte_WriteHook_Ap_DiagMgr10_DiagStsCtrldDisRmpPres_Cnt_lgc_Start(arg1) ((void)(0))
# endif /* Rte_WriteHook_Ap_DiagMgr10_DiagStsCtrldDisRmpPres_Cnt_lgc_Start */

# if defined (Rte_WriteHook_Ap_DiagMgr10_DiagStsDefTemp_Cnt_lgc_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_WriteHook_Ap_DiagMgr10_DiagStsDefTemp_Cnt_lgc_Return
# endif
# if defined (Rte_WriteHook_Ap_DiagMgr10_DiagStsDefTemp_Cnt_lgc_Return)
#  undef Rte_WriteHook_Ap_DiagMgr10_DiagStsDefTemp_Cnt_lgc_Return
FUNC(void, RTE_APPL_CODE) Rte_WriteHook_Ap_DiagMgr10_DiagStsDefTemp_Cnt_lgc_Return(Boolean data);
# else
#  define Rte_WriteHook_Ap_DiagMgr10_DiagStsDefTemp_Cnt_lgc_Return(arg1) ((void)(0))
# endif /* Rte_WriteHook_Ap_DiagMgr10_DiagStsDefTemp_Cnt_lgc_Return */

# if defined (Rte_WriteHook_Ap_DiagMgr10_DiagStsDefTemp_Cnt_lgc_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_WriteHook_Ap_DiagMgr10_DiagStsDefTemp_Cnt_lgc_Start
# endif
# if defined (Rte_WriteHook_Ap_DiagMgr10_DiagStsDefTemp_Cnt_lgc_Start)
#  undef Rte_WriteHook_Ap_DiagMgr10_DiagStsDefTemp_Cnt_lgc_Start
FUNC(void, RTE_APPL_CODE) Rte_WriteHook_Ap_DiagMgr10_DiagStsDefTemp_Cnt_lgc_Start(Boolean data);
# else
#  define Rte_WriteHook_Ap_DiagMgr10_DiagStsDefTemp_Cnt_lgc_Start(arg1) ((void)(0))
# endif /* Rte_WriteHook_Ap_DiagMgr10_DiagStsDefTemp_Cnt_lgc_Start */

# if defined (Rte_WriteHook_Ap_DiagMgr10_DiagStsDefVehSpd_Cnt_lgc_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_WriteHook_Ap_DiagMgr10_DiagStsDefVehSpd_Cnt_lgc_Return
# endif
# if defined (Rte_WriteHook_Ap_DiagMgr10_DiagStsDefVehSpd_Cnt_lgc_Return)
#  undef Rte_WriteHook_Ap_DiagMgr10_DiagStsDefVehSpd_Cnt_lgc_Return
FUNC(void, RTE_APPL_CODE) Rte_WriteHook_Ap_DiagMgr10_DiagStsDefVehSpd_Cnt_lgc_Return(Boolean data);
# else
#  define Rte_WriteHook_Ap_DiagMgr10_DiagStsDefVehSpd_Cnt_lgc_Return(arg1) ((void)(0))
# endif /* Rte_WriteHook_Ap_DiagMgr10_DiagStsDefVehSpd_Cnt_lgc_Return */

# if defined (Rte_WriteHook_Ap_DiagMgr10_DiagStsDefVehSpd_Cnt_lgc_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_WriteHook_Ap_DiagMgr10_DiagStsDefVehSpd_Cnt_lgc_Start
# endif
# if defined (Rte_WriteHook_Ap_DiagMgr10_DiagStsDefVehSpd_Cnt_lgc_Start)
#  undef Rte_WriteHook_Ap_DiagMgr10_DiagStsDefVehSpd_Cnt_lgc_Start
FUNC(void, RTE_APPL_CODE) Rte_WriteHook_Ap_DiagMgr10_DiagStsDefVehSpd_Cnt_lgc_Start(Boolean data);
# else
#  define Rte_WriteHook_Ap_DiagMgr10_DiagStsDefVehSpd_Cnt_lgc_Start(arg1) ((void)(0))
# endif /* Rte_WriteHook_Ap_DiagMgr10_DiagStsDefVehSpd_Cnt_lgc_Start */

# if defined (Rte_WriteHook_Ap_DiagMgr10_DiagStsHWASbSystmFltPres_Cnt_lgc_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_WriteHook_Ap_DiagMgr10_DiagStsHWASbSystmFltPres_Cnt_lgc_Return
# endif
# if defined (Rte_WriteHook_Ap_DiagMgr10_DiagStsHWASbSystmFltPres_Cnt_lgc_Return)
#  undef Rte_WriteHook_Ap_DiagMgr10_DiagStsHWASbSystmFltPres_Cnt_lgc_Return
FUNC(void, RTE_APPL_CODE) Rte_WriteHook_Ap_DiagMgr10_DiagStsHWASbSystmFltPres_Cnt_lgc_Return(Boolean data);
# else
#  define Rte_WriteHook_Ap_DiagMgr10_DiagStsHWASbSystmFltPres_Cnt_lgc_Return(arg1) ((void)(0))
# endif /* Rte_WriteHook_Ap_DiagMgr10_DiagStsHWASbSystmFltPres_Cnt_lgc_Return */

# if defined (Rte_WriteHook_Ap_DiagMgr10_DiagStsHWASbSystmFltPres_Cnt_lgc_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_WriteHook_Ap_DiagMgr10_DiagStsHWASbSystmFltPres_Cnt_lgc_Start
# endif
# if defined (Rte_WriteHook_Ap_DiagMgr10_DiagStsHWASbSystmFltPres_Cnt_lgc_Start)
#  undef Rte_WriteHook_Ap_DiagMgr10_DiagStsHWASbSystmFltPres_Cnt_lgc_Start
FUNC(void, RTE_APPL_CODE) Rte_WriteHook_Ap_DiagMgr10_DiagStsHWASbSystmFltPres_Cnt_lgc_Start(Boolean data);
# else
#  define Rte_WriteHook_Ap_DiagMgr10_DiagStsHWASbSystmFltPres_Cnt_lgc_Start(arg1) ((void)(0))
# endif /* Rte_WriteHook_Ap_DiagMgr10_DiagStsHWASbSystmFltPres_Cnt_lgc_Start */

# if defined (Rte_WriteHook_Ap_DiagMgr10_DiagStsNonRecRmpToZeroFltPres_Cnt_lgc_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_WriteHook_Ap_DiagMgr10_DiagStsNonRecRmpToZeroFltPres_Cnt_lgc_Return
# endif
# if defined (Rte_WriteHook_Ap_DiagMgr10_DiagStsNonRecRmpToZeroFltPres_Cnt_lgc_Return)
#  undef Rte_WriteHook_Ap_DiagMgr10_DiagStsNonRecRmpToZeroFltPres_Cnt_lgc_Return
FUNC(void, RTE_APPL_CODE) Rte_WriteHook_Ap_DiagMgr10_DiagStsNonRecRmpToZeroFltPres_Cnt_lgc_Return(Boolean data);
# else
#  define Rte_WriteHook_Ap_DiagMgr10_DiagStsNonRecRmpToZeroFltPres_Cnt_lgc_Return(arg1) ((void)(0))
# endif /* Rte_WriteHook_Ap_DiagMgr10_DiagStsNonRecRmpToZeroFltPres_Cnt_lgc_Return */

# if defined (Rte_WriteHook_Ap_DiagMgr10_DiagStsNonRecRmpToZeroFltPres_Cnt_lgc_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_WriteHook_Ap_DiagMgr10_DiagStsNonRecRmpToZeroFltPres_Cnt_lgc_Start
# endif
# if defined (Rte_WriteHook_Ap_DiagMgr10_DiagStsNonRecRmpToZeroFltPres_Cnt_lgc_Start)
#  undef Rte_WriteHook_Ap_DiagMgr10_DiagStsNonRecRmpToZeroFltPres_Cnt_lgc_Start
FUNC(void, RTE_APPL_CODE) Rte_WriteHook_Ap_DiagMgr10_DiagStsNonRecRmpToZeroFltPres_Cnt_lgc_Start(Boolean data);
# else
#  define Rte_WriteHook_Ap_DiagMgr10_DiagStsNonRecRmpToZeroFltPres_Cnt_lgc_Start(arg1) ((void)(0))
# endif /* Rte_WriteHook_Ap_DiagMgr10_DiagStsNonRecRmpToZeroFltPres_Cnt_lgc_Start */

# if defined (Rte_WriteHook_Ap_DiagMgr10_DiagStsRecRmpToZeroFltPres_Cnt_lgc_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_WriteHook_Ap_DiagMgr10_DiagStsRecRmpToZeroFltPres_Cnt_lgc_Return
# endif
# if defined (Rte_WriteHook_Ap_DiagMgr10_DiagStsRecRmpToZeroFltPres_Cnt_lgc_Return)
#  undef Rte_WriteHook_Ap_DiagMgr10_DiagStsRecRmpToZeroFltPres_Cnt_lgc_Return
FUNC(void, RTE_APPL_CODE) Rte_WriteHook_Ap_DiagMgr10_DiagStsRecRmpToZeroFltPres_Cnt_lgc_Return(Boolean data);
# else
#  define Rte_WriteHook_Ap_DiagMgr10_DiagStsRecRmpToZeroFltPres_Cnt_lgc_Return(arg1) ((void)(0))
# endif /* Rte_WriteHook_Ap_DiagMgr10_DiagStsRecRmpToZeroFltPres_Cnt_lgc_Return */

# if defined (Rte_WriteHook_Ap_DiagMgr10_DiagStsRecRmpToZeroFltPres_Cnt_lgc_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_WriteHook_Ap_DiagMgr10_DiagStsRecRmpToZeroFltPres_Cnt_lgc_Start
# endif
# if defined (Rte_WriteHook_Ap_DiagMgr10_DiagStsRecRmpToZeroFltPres_Cnt_lgc_Start)
#  undef Rte_WriteHook_Ap_DiagMgr10_DiagStsRecRmpToZeroFltPres_Cnt_lgc_Start
FUNC(void, RTE_APPL_CODE) Rte_WriteHook_Ap_DiagMgr10_DiagStsRecRmpToZeroFltPres_Cnt_lgc_Start(Boolean data);
# else
#  define Rte_WriteHook_Ap_DiagMgr10_DiagStsRecRmpToZeroFltPres_Cnt_lgc_Start(arg1) ((void)(0))
# endif /* Rte_WriteHook_Ap_DiagMgr10_DiagStsRecRmpToZeroFltPres_Cnt_lgc_Start */

# if defined (Rte_WriteHook_Ap_DiagMgr10_DiagStsScomHWANotValid_Cnt_lgc_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_WriteHook_Ap_DiagMgr10_DiagStsScomHWANotValid_Cnt_lgc_Return
# endif
# if defined (Rte_WriteHook_Ap_DiagMgr10_DiagStsScomHWANotValid_Cnt_lgc_Return)
#  undef Rte_WriteHook_Ap_DiagMgr10_DiagStsScomHWANotValid_Cnt_lgc_Return
FUNC(void, RTE_APPL_CODE) Rte_WriteHook_Ap_DiagMgr10_DiagStsScomHWANotValid_Cnt_lgc_Return(Boolean data);
# else
#  define Rte_WriteHook_Ap_DiagMgr10_DiagStsScomHWANotValid_Cnt_lgc_Return(arg1) ((void)(0))
# endif /* Rte_WriteHook_Ap_DiagMgr10_DiagStsScomHWANotValid_Cnt_lgc_Return */

# if defined (Rte_WriteHook_Ap_DiagMgr10_DiagStsScomHWANotValid_Cnt_lgc_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_WriteHook_Ap_DiagMgr10_DiagStsScomHWANotValid_Cnt_lgc_Start
# endif
# if defined (Rte_WriteHook_Ap_DiagMgr10_DiagStsScomHWANotValid_Cnt_lgc_Start)
#  undef Rte_WriteHook_Ap_DiagMgr10_DiagStsScomHWANotValid_Cnt_lgc_Start
FUNC(void, RTE_APPL_CODE) Rte_WriteHook_Ap_DiagMgr10_DiagStsScomHWANotValid_Cnt_lgc_Start(Boolean data);
# else
#  define Rte_WriteHook_Ap_DiagMgr10_DiagStsScomHWANotValid_Cnt_lgc_Start(arg1) ((void)(0))
# endif /* Rte_WriteHook_Ap_DiagMgr10_DiagStsScomHWANotValid_Cnt_lgc_Start */

# if defined (Rte_WriteHook_Ap_DiagMgr10_DiagStsWIRDisable_Cnt_lgc_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_WriteHook_Ap_DiagMgr10_DiagStsWIRDisable_Cnt_lgc_Return
# endif
# if defined (Rte_WriteHook_Ap_DiagMgr10_DiagStsWIRDisable_Cnt_lgc_Return)
#  undef Rte_WriteHook_Ap_DiagMgr10_DiagStsWIRDisable_Cnt_lgc_Return
FUNC(void, RTE_APPL_CODE) Rte_WriteHook_Ap_DiagMgr10_DiagStsWIRDisable_Cnt_lgc_Return(Boolean data);
# else
#  define Rte_WriteHook_Ap_DiagMgr10_DiagStsWIRDisable_Cnt_lgc_Return(arg1) ((void)(0))
# endif /* Rte_WriteHook_Ap_DiagMgr10_DiagStsWIRDisable_Cnt_lgc_Return */

# if defined (Rte_WriteHook_Ap_DiagMgr10_DiagStsWIRDisable_Cnt_lgc_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_WriteHook_Ap_DiagMgr10_DiagStsWIRDisable_Cnt_lgc_Start
# endif
# if defined (Rte_WriteHook_Ap_DiagMgr10_DiagStsWIRDisable_Cnt_lgc_Start)
#  undef Rte_WriteHook_Ap_DiagMgr10_DiagStsWIRDisable_Cnt_lgc_Start
FUNC(void, RTE_APPL_CODE) Rte_WriteHook_Ap_DiagMgr10_DiagStsWIRDisable_Cnt_lgc_Start(Boolean data);
# else
#  define Rte_WriteHook_Ap_DiagMgr10_DiagStsWIRDisable_Cnt_lgc_Start(arg1) ((void)(0))
# endif /* Rte_WriteHook_Ap_DiagMgr10_DiagStsWIRDisable_Cnt_lgc_Start */

# if defined (Rte_WriteHook_Ap_Polarity_AssistAssyPolarity_Cnt_s08_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_WriteHook_Ap_Polarity_AssistAssyPolarity_Cnt_s08_Return
# endif
# if defined (Rte_WriteHook_Ap_Polarity_AssistAssyPolarity_Cnt_s08_Return)
#  undef Rte_WriteHook_Ap_Polarity_AssistAssyPolarity_Cnt_s08_Return
FUNC(void, RTE_APPL_CODE) Rte_WriteHook_Ap_Polarity_AssistAssyPolarity_Cnt_s08_Return(SInt8 data);
# else
#  define Rte_WriteHook_Ap_Polarity_AssistAssyPolarity_Cnt_s08_Return(arg1) ((void)(0))
# endif /* Rte_WriteHook_Ap_Polarity_AssistAssyPolarity_Cnt_s08_Return */

# if defined (Rte_WriteHook_Ap_Polarity_AssistAssyPolarity_Cnt_s08_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_WriteHook_Ap_Polarity_AssistAssyPolarity_Cnt_s08_Start
# endif
# if defined (Rte_WriteHook_Ap_Polarity_AssistAssyPolarity_Cnt_s08_Start)
#  undef Rte_WriteHook_Ap_Polarity_AssistAssyPolarity_Cnt_s08_Start
FUNC(void, RTE_APPL_CODE) Rte_WriteHook_Ap_Polarity_AssistAssyPolarity_Cnt_s08_Start(SInt8 data);
# else
#  define Rte_WriteHook_Ap_Polarity_AssistAssyPolarity_Cnt_s08_Start(arg1) ((void)(0))
# endif /* Rte_WriteHook_Ap_Polarity_AssistAssyPolarity_Cnt_s08_Start */

# if defined (Rte_WriteHook_Ap_Polarity_HwPosPolarity_Cnt_s08_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_WriteHook_Ap_Polarity_HwPosPolarity_Cnt_s08_Return
# endif
# if defined (Rte_WriteHook_Ap_Polarity_HwPosPolarity_Cnt_s08_Return)
#  undef Rte_WriteHook_Ap_Polarity_HwPosPolarity_Cnt_s08_Return
FUNC(void, RTE_APPL_CODE) Rte_WriteHook_Ap_Polarity_HwPosPolarity_Cnt_s08_Return(SInt8 data);
# else
#  define Rte_WriteHook_Ap_Polarity_HwPosPolarity_Cnt_s08_Return(arg1) ((void)(0))
# endif /* Rte_WriteHook_Ap_Polarity_HwPosPolarity_Cnt_s08_Return */

# if defined (Rte_WriteHook_Ap_Polarity_HwPosPolarity_Cnt_s08_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_WriteHook_Ap_Polarity_HwPosPolarity_Cnt_s08_Start
# endif
# if defined (Rte_WriteHook_Ap_Polarity_HwPosPolarity_Cnt_s08_Start)
#  undef Rte_WriteHook_Ap_Polarity_HwPosPolarity_Cnt_s08_Start
FUNC(void, RTE_APPL_CODE) Rte_WriteHook_Ap_Polarity_HwPosPolarity_Cnt_s08_Start(SInt8 data);
# else
#  define Rte_WriteHook_Ap_Polarity_HwPosPolarity_Cnt_s08_Start(arg1) ((void)(0))
# endif /* Rte_WriteHook_Ap_Polarity_HwPosPolarity_Cnt_s08_Start */

# if defined (Rte_WriteHook_Ap_Polarity_HwTrqPolarity_Cnt_s08_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_WriteHook_Ap_Polarity_HwTrqPolarity_Cnt_s08_Return
# endif
# if defined (Rte_WriteHook_Ap_Polarity_HwTrqPolarity_Cnt_s08_Return)
#  undef Rte_WriteHook_Ap_Polarity_HwTrqPolarity_Cnt_s08_Return
FUNC(void, RTE_APPL_CODE) Rte_WriteHook_Ap_Polarity_HwTrqPolarity_Cnt_s08_Return(SInt8 data);
# else
#  define Rte_WriteHook_Ap_Polarity_HwTrqPolarity_Cnt_s08_Return(arg1) ((void)(0))
# endif /* Rte_WriteHook_Ap_Polarity_HwTrqPolarity_Cnt_s08_Return */

# if defined (Rte_WriteHook_Ap_Polarity_HwTrqPolarity_Cnt_s08_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_WriteHook_Ap_Polarity_HwTrqPolarity_Cnt_s08_Start
# endif
# if defined (Rte_WriteHook_Ap_Polarity_HwTrqPolarity_Cnt_s08_Start)
#  undef Rte_WriteHook_Ap_Polarity_HwTrqPolarity_Cnt_s08_Start
FUNC(void, RTE_APPL_CODE) Rte_WriteHook_Ap_Polarity_HwTrqPolarity_Cnt_s08_Start(SInt8 data);
# else
#  define Rte_WriteHook_Ap_Polarity_HwTrqPolarity_Cnt_s08_Start(arg1) ((void)(0))
# endif /* Rte_WriteHook_Ap_Polarity_HwTrqPolarity_Cnt_s08_Start */

# if defined (Rte_WriteHook_Ap_Polarity_MtrElecMechPolarity_Cnt_s08_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_WriteHook_Ap_Polarity_MtrElecMechPolarity_Cnt_s08_Return
# endif
# if defined (Rte_WriteHook_Ap_Polarity_MtrElecMechPolarity_Cnt_s08_Return)
#  undef Rte_WriteHook_Ap_Polarity_MtrElecMechPolarity_Cnt_s08_Return
FUNC(void, RTE_APPL_CODE) Rte_WriteHook_Ap_Polarity_MtrElecMechPolarity_Cnt_s08_Return(SInt8 data);
# else
#  define Rte_WriteHook_Ap_Polarity_MtrElecMechPolarity_Cnt_s08_Return(arg1) ((void)(0))
# endif /* Rte_WriteHook_Ap_Polarity_MtrElecMechPolarity_Cnt_s08_Return */

# if defined (Rte_WriteHook_Ap_Polarity_MtrElecMechPolarity_Cnt_s08_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_WriteHook_Ap_Polarity_MtrElecMechPolarity_Cnt_s08_Start
# endif
# if defined (Rte_WriteHook_Ap_Polarity_MtrElecMechPolarity_Cnt_s08_Start)
#  undef Rte_WriteHook_Ap_Polarity_MtrElecMechPolarity_Cnt_s08_Start
FUNC(void, RTE_APPL_CODE) Rte_WriteHook_Ap_Polarity_MtrElecMechPolarity_Cnt_s08_Start(SInt8 data);
# else
#  define Rte_WriteHook_Ap_Polarity_MtrElecMechPolarity_Cnt_s08_Start(arg1) ((void)(0))
# endif /* Rte_WriteHook_Ap_Polarity_MtrElecMechPolarity_Cnt_s08_Start */

# if defined (Rte_WriteHook_Ap_Polarity_MtrPosPolarity_Cnt_s08_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_WriteHook_Ap_Polarity_MtrPosPolarity_Cnt_s08_Return
# endif
# if defined (Rte_WriteHook_Ap_Polarity_MtrPosPolarity_Cnt_s08_Return)
#  undef Rte_WriteHook_Ap_Polarity_MtrPosPolarity_Cnt_s08_Return
FUNC(void, RTE_APPL_CODE) Rte_WriteHook_Ap_Polarity_MtrPosPolarity_Cnt_s08_Return(SInt8 data);
# else
#  define Rte_WriteHook_Ap_Polarity_MtrPosPolarity_Cnt_s08_Return(arg1) ((void)(0))
# endif /* Rte_WriteHook_Ap_Polarity_MtrPosPolarity_Cnt_s08_Return */

# if defined (Rte_WriteHook_Ap_Polarity_MtrPosPolarity_Cnt_s08_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_WriteHook_Ap_Polarity_MtrPosPolarity_Cnt_s08_Start
# endif
# if defined (Rte_WriteHook_Ap_Polarity_MtrPosPolarity_Cnt_s08_Start)
#  undef Rte_WriteHook_Ap_Polarity_MtrPosPolarity_Cnt_s08_Start
FUNC(void, RTE_APPL_CODE) Rte_WriteHook_Ap_Polarity_MtrPosPolarity_Cnt_s08_Start(SInt8 data);
# else
#  define Rte_WriteHook_Ap_Polarity_MtrPosPolarity_Cnt_s08_Start(arg1) ((void)(0))
# endif /* Rte_WriteHook_Ap_Polarity_MtrPosPolarity_Cnt_s08_Start */

# if defined (Rte_WriteHook_Ap_Polarity_MtrVelPolarity_Cnt_s08_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_WriteHook_Ap_Polarity_MtrVelPolarity_Cnt_s08_Return
# endif
# if defined (Rte_WriteHook_Ap_Polarity_MtrVelPolarity_Cnt_s08_Return)
#  undef Rte_WriteHook_Ap_Polarity_MtrVelPolarity_Cnt_s08_Return
FUNC(void, RTE_APPL_CODE) Rte_WriteHook_Ap_Polarity_MtrVelPolarity_Cnt_s08_Return(SInt8 data);
# else
#  define Rte_WriteHook_Ap_Polarity_MtrVelPolarity_Cnt_s08_Return(arg1) ((void)(0))
# endif /* Rte_WriteHook_Ap_Polarity_MtrVelPolarity_Cnt_s08_Return */

# if defined (Rte_WriteHook_Ap_Polarity_MtrVelPolarity_Cnt_s08_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_WriteHook_Ap_Polarity_MtrVelPolarity_Cnt_s08_Start
# endif
# if defined (Rte_WriteHook_Ap_Polarity_MtrVelPolarity_Cnt_s08_Start)
#  undef Rte_WriteHook_Ap_Polarity_MtrVelPolarity_Cnt_s08_Start
FUNC(void, RTE_APPL_CODE) Rte_WriteHook_Ap_Polarity_MtrVelPolarity_Cnt_s08_Start(SInt8 data);
# else
#  define Rte_WriteHook_Ap_Polarity_MtrVelPolarity_Cnt_s08_Start(arg1) ((void)(0))
# endif /* Rte_WriteHook_Ap_Polarity_MtrVelPolarity_Cnt_s08_Start */

# if defined (Rte_WriteHook_Ap_Polarity_SysC_MtrElecMechPolarity_Cnt_s32_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_WriteHook_Ap_Polarity_SysC_MtrElecMechPolarity_Cnt_s32_Return
# endif
# if defined (Rte_WriteHook_Ap_Polarity_SysC_MtrElecMechPolarity_Cnt_s32_Return)
#  undef Rte_WriteHook_Ap_Polarity_SysC_MtrElecMechPolarity_Cnt_s32_Return
FUNC(void, RTE_APPL_CODE) Rte_WriteHook_Ap_Polarity_SysC_MtrElecMechPolarity_Cnt_s32_Return(SInt32 data);
# else
#  define Rte_WriteHook_Ap_Polarity_SysC_MtrElecMechPolarity_Cnt_s32_Return(arg1) ((void)(0))
# endif /* Rte_WriteHook_Ap_Polarity_SysC_MtrElecMechPolarity_Cnt_s32_Return */

# if defined (Rte_WriteHook_Ap_Polarity_SysC_MtrElecMechPolarity_Cnt_s32_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_WriteHook_Ap_Polarity_SysC_MtrElecMechPolarity_Cnt_s32_Start
# endif
# if defined (Rte_WriteHook_Ap_Polarity_SysC_MtrElecMechPolarity_Cnt_s32_Start)
#  undef Rte_WriteHook_Ap_Polarity_SysC_MtrElecMechPolarity_Cnt_s32_Start
FUNC(void, RTE_APPL_CODE) Rte_WriteHook_Ap_Polarity_SysC_MtrElecMechPolarity_Cnt_s32_Start(SInt32 data);
# else
#  define Rte_WriteHook_Ap_Polarity_SysC_MtrElecMechPolarity_Cnt_s32_Start(arg1) ((void)(0))
# endif /* Rte_WriteHook_Ap_Polarity_SysC_MtrElecMechPolarity_Cnt_s32_Start */

# if defined (Rte_WriteHook_Ap_SrlComInput_AirTempOutside_DegC_f32_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_WriteHook_Ap_SrlComInput_AirTempOutside_DegC_f32_Return
# endif
# if defined (Rte_WriteHook_Ap_SrlComInput_AirTempOutside_DegC_f32_Return)
#  undef Rte_WriteHook_Ap_SrlComInput_AirTempOutside_DegC_f32_Return
FUNC(void, RTE_APPL_CODE) Rte_WriteHook_Ap_SrlComInput_AirTempOutside_DegC_f32_Return(Float data);
# else
#  define Rte_WriteHook_Ap_SrlComInput_AirTempOutside_DegC_f32_Return(arg1) ((void)(0))
# endif /* Rte_WriteHook_Ap_SrlComInput_AirTempOutside_DegC_f32_Return */

# if defined (Rte_WriteHook_Ap_SrlComInput_AirTempOutside_DegC_f32_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_WriteHook_Ap_SrlComInput_AirTempOutside_DegC_f32_Start
# endif
# if defined (Rte_WriteHook_Ap_SrlComInput_AirTempOutside_DegC_f32_Start)
#  undef Rte_WriteHook_Ap_SrlComInput_AirTempOutside_DegC_f32_Start
FUNC(void, RTE_APPL_CODE) Rte_WriteHook_Ap_SrlComInput_AirTempOutside_DegC_f32_Start(Float data);
# else
#  define Rte_WriteHook_Ap_SrlComInput_AirTempOutside_DegC_f32_Start(arg1) ((void)(0))
# endif /* Rte_WriteHook_Ap_SrlComInput_AirTempOutside_DegC_f32_Start */

# if defined (Rte_WriteHook_Ap_SrlComInput_AmbTempAvg_DegC_f32_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_WriteHook_Ap_SrlComInput_AmbTempAvg_DegC_f32_Return
# endif
# if defined (Rte_WriteHook_Ap_SrlComInput_AmbTempAvg_DegC_f32_Return)
#  undef Rte_WriteHook_Ap_SrlComInput_AmbTempAvg_DegC_f32_Return
FUNC(void, RTE_APPL_CODE) Rte_WriteHook_Ap_SrlComInput_AmbTempAvg_DegC_f32_Return(Float data);
# else
#  define Rte_WriteHook_Ap_SrlComInput_AmbTempAvg_DegC_f32_Return(arg1) ((void)(0))
# endif /* Rte_WriteHook_Ap_SrlComInput_AmbTempAvg_DegC_f32_Return */

# if defined (Rte_WriteHook_Ap_SrlComInput_AmbTempAvg_DegC_f32_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_WriteHook_Ap_SrlComInput_AmbTempAvg_DegC_f32_Start
# endif
# if defined (Rte_WriteHook_Ap_SrlComInput_AmbTempAvg_DegC_f32_Start)
#  undef Rte_WriteHook_Ap_SrlComInput_AmbTempAvg_DegC_f32_Start
FUNC(void, RTE_APPL_CODE) Rte_WriteHook_Ap_SrlComInput_AmbTempAvg_DegC_f32_Start(Float data);
# else
#  define Rte_WriteHook_Ap_SrlComInput_AmbTempAvg_DegC_f32_Start(arg1) ((void)(0))
# endif /* Rte_WriteHook_Ap_SrlComInput_AmbTempAvg_DegC_f32_Start */

# if defined (Rte_WriteHook_Ap_SrlComInput_BattVolt_Volt_f32_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_WriteHook_Ap_SrlComInput_BattVolt_Volt_f32_Return
# endif
# if defined (Rte_WriteHook_Ap_SrlComInput_BattVolt_Volt_f32_Return)
#  undef Rte_WriteHook_Ap_SrlComInput_BattVolt_Volt_f32_Return
FUNC(void, RTE_APPL_CODE) Rte_WriteHook_Ap_SrlComInput_BattVolt_Volt_f32_Return(Float data);
# else
#  define Rte_WriteHook_Ap_SrlComInput_BattVolt_Volt_f32_Return(arg1) ((void)(0))
# endif /* Rte_WriteHook_Ap_SrlComInput_BattVolt_Volt_f32_Return */

# if defined (Rte_WriteHook_Ap_SrlComInput_BattVolt_Volt_f32_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_WriteHook_Ap_SrlComInput_BattVolt_Volt_f32_Start
# endif
# if defined (Rte_WriteHook_Ap_SrlComInput_BattVolt_Volt_f32_Start)
#  undef Rte_WriteHook_Ap_SrlComInput_BattVolt_Volt_f32_Start
FUNC(void, RTE_APPL_CODE) Rte_WriteHook_Ap_SrlComInput_BattVolt_Volt_f32_Start(Float data);
# else
#  define Rte_WriteHook_Ap_SrlComInput_BattVolt_Volt_f32_Start(arg1) ((void)(0))
# endif /* Rte_WriteHook_Ap_SrlComInput_BattVolt_Volt_f32_Start */

# if defined (Rte_WriteHook_Ap_SrlComInput_CMDIgnStat_Cnt_u08_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_WriteHook_Ap_SrlComInput_CMDIgnStat_Cnt_u08_Return
# endif
# if defined (Rte_WriteHook_Ap_SrlComInput_CMDIgnStat_Cnt_u08_Return)
#  undef Rte_WriteHook_Ap_SrlComInput_CMDIgnStat_Cnt_u08_Return
FUNC(void, RTE_APPL_CODE) Rte_WriteHook_Ap_SrlComInput_CMDIgnStat_Cnt_u08_Return(UInt8 data);
# else
#  define Rte_WriteHook_Ap_SrlComInput_CMDIgnStat_Cnt_u08_Return(arg1) ((void)(0))
# endif /* Rte_WriteHook_Ap_SrlComInput_CMDIgnStat_Cnt_u08_Return */

# if defined (Rte_WriteHook_Ap_SrlComInput_CMDIgnStat_Cnt_u08_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_WriteHook_Ap_SrlComInput_CMDIgnStat_Cnt_u08_Start
# endif
# if defined (Rte_WriteHook_Ap_SrlComInput_CMDIgnStat_Cnt_u08_Start)
#  undef Rte_WriteHook_Ap_SrlComInput_CMDIgnStat_Cnt_u08_Start
FUNC(void, RTE_APPL_CODE) Rte_WriteHook_Ap_SrlComInput_CMDIgnStat_Cnt_u08_Start(UInt8 data);
# else
#  define Rte_WriteHook_Ap_SrlComInput_CMDIgnStat_Cnt_u08_Start(arg1) ((void)(0))
# endif /* Rte_WriteHook_Ap_SrlComInput_CMDIgnStat_Cnt_u08_Start */

# if defined (Rte_WriteHook_Ap_SrlComInput_CanMsgReceived_Cnt_lgc_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_WriteHook_Ap_SrlComInput_CanMsgReceived_Cnt_lgc_Return
# endif
# if defined (Rte_WriteHook_Ap_SrlComInput_CanMsgReceived_Cnt_lgc_Return)
#  undef Rte_WriteHook_Ap_SrlComInput_CanMsgReceived_Cnt_lgc_Return
FUNC(void, RTE_APPL_CODE) Rte_WriteHook_Ap_SrlComInput_CanMsgReceived_Cnt_lgc_Return(Boolean data);
# else
#  define Rte_WriteHook_Ap_SrlComInput_CanMsgReceived_Cnt_lgc_Return(arg1) ((void)(0))
# endif /* Rte_WriteHook_Ap_SrlComInput_CanMsgReceived_Cnt_lgc_Return */

# if defined (Rte_WriteHook_Ap_SrlComInput_CanMsgReceived_Cnt_lgc_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_WriteHook_Ap_SrlComInput_CanMsgReceived_Cnt_lgc_Start
# endif
# if defined (Rte_WriteHook_Ap_SrlComInput_CanMsgReceived_Cnt_lgc_Start)
#  undef Rte_WriteHook_Ap_SrlComInput_CanMsgReceived_Cnt_lgc_Start
FUNC(void, RTE_APPL_CODE) Rte_WriteHook_Ap_SrlComInput_CanMsgReceived_Cnt_lgc_Start(Boolean data);
# else
#  define Rte_WriteHook_Ap_SrlComInput_CanMsgReceived_Cnt_lgc_Start(arg1) ((void)(0))
# endif /* Rte_WriteHook_Ap_SrlComInput_CanMsgReceived_Cnt_lgc_Start */

# if defined (Rte_WriteHook_Ap_SrlComInput_CfgStatRQ_Cnt_u08_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_WriteHook_Ap_SrlComInput_CfgStatRQ_Cnt_u08_Return
# endif
# if defined (Rte_WriteHook_Ap_SrlComInput_CfgStatRQ_Cnt_u08_Return)
#  undef Rte_WriteHook_Ap_SrlComInput_CfgStatRQ_Cnt_u08_Return
FUNC(void, RTE_APPL_CODE) Rte_WriteHook_Ap_SrlComInput_CfgStatRQ_Cnt_u08_Return(UInt8 data);
# else
#  define Rte_WriteHook_Ap_SrlComInput_CfgStatRQ_Cnt_u08_Return(arg1) ((void)(0))
# endif /* Rte_WriteHook_Ap_SrlComInput_CfgStatRQ_Cnt_u08_Return */

# if defined (Rte_WriteHook_Ap_SrlComInput_CfgStatRQ_Cnt_u08_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_WriteHook_Ap_SrlComInput_CfgStatRQ_Cnt_u08_Start
# endif
# if defined (Rte_WriteHook_Ap_SrlComInput_CfgStatRQ_Cnt_u08_Start)
#  undef Rte_WriteHook_Ap_SrlComInput_CfgStatRQ_Cnt_u08_Start
FUNC(void, RTE_APPL_CODE) Rte_WriteHook_Ap_SrlComInput_CfgStatRQ_Cnt_u08_Start(UInt8 data);
# else
#  define Rte_WriteHook_Ap_SrlComInput_CfgStatRQ_Cnt_u08_Start(arg1) ((void)(0))
# endif /* Rte_WriteHook_Ap_SrlComInput_CfgStatRQ_Cnt_u08_Start */

# if defined (Rte_WriteHook_Ap_SrlComInput_DSTEOLDisable_Cnt_lgc_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_WriteHook_Ap_SrlComInput_DSTEOLDisable_Cnt_lgc_Return
# endif
# if defined (Rte_WriteHook_Ap_SrlComInput_DSTEOLDisable_Cnt_lgc_Return)
#  undef Rte_WriteHook_Ap_SrlComInput_DSTEOLDisable_Cnt_lgc_Return
FUNC(void, RTE_APPL_CODE) Rte_WriteHook_Ap_SrlComInput_DSTEOLDisable_Cnt_lgc_Return(Boolean data);
# else
#  define Rte_WriteHook_Ap_SrlComInput_DSTEOLDisable_Cnt_lgc_Return(arg1) ((void)(0))
# endif /* Rte_WriteHook_Ap_SrlComInput_DSTEOLDisable_Cnt_lgc_Return */

# if defined (Rte_WriteHook_Ap_SrlComInput_DSTEOLDisable_Cnt_lgc_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_WriteHook_Ap_SrlComInput_DSTEOLDisable_Cnt_lgc_Start
# endif
# if defined (Rte_WriteHook_Ap_SrlComInput_DSTEOLDisable_Cnt_lgc_Start)
#  undef Rte_WriteHook_Ap_SrlComInput_DSTEOLDisable_Cnt_lgc_Start
FUNC(void, RTE_APPL_CODE) Rte_WriteHook_Ap_SrlComInput_DSTEOLDisable_Cnt_lgc_Start(Boolean data);
# else
#  define Rte_WriteHook_Ap_SrlComInput_DSTEOLDisable_Cnt_lgc_Start(arg1) ((void)(0))
# endif /* Rte_WriteHook_Ap_SrlComInput_DSTEOLDisable_Cnt_lgc_Start */

# if defined (Rte_WriteHook_Ap_SrlComInput_DSTEnableRqst_Cnt_lgc_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_WriteHook_Ap_SrlComInput_DSTEnableRqst_Cnt_lgc_Return
# endif
# if defined (Rte_WriteHook_Ap_SrlComInput_DSTEnableRqst_Cnt_lgc_Return)
#  undef Rte_WriteHook_Ap_SrlComInput_DSTEnableRqst_Cnt_lgc_Return
FUNC(void, RTE_APPL_CODE) Rte_WriteHook_Ap_SrlComInput_DSTEnableRqst_Cnt_lgc_Return(Boolean data);
# else
#  define Rte_WriteHook_Ap_SrlComInput_DSTEnableRqst_Cnt_lgc_Return(arg1) ((void)(0))
# endif /* Rte_WriteHook_Ap_SrlComInput_DSTEnableRqst_Cnt_lgc_Return */

# if defined (Rte_WriteHook_Ap_SrlComInput_DSTEnableRqst_Cnt_lgc_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_WriteHook_Ap_SrlComInput_DSTEnableRqst_Cnt_lgc_Start
# endif
# if defined (Rte_WriteHook_Ap_SrlComInput_DSTEnableRqst_Cnt_lgc_Start)
#  undef Rte_WriteHook_Ap_SrlComInput_DSTEnableRqst_Cnt_lgc_Start
FUNC(void, RTE_APPL_CODE) Rte_WriteHook_Ap_SrlComInput_DSTEnableRqst_Cnt_lgc_Start(Boolean data);
# else
#  define Rte_WriteHook_Ap_SrlComInput_DSTEnableRqst_Cnt_lgc_Start(arg1) ((void)(0))
# endif /* Rte_WriteHook_Ap_SrlComInput_DSTEnableRqst_Cnt_lgc_Start */

# if defined (Rte_WriteHook_Ap_SrlComInput_DSTErrCntrRecvLevel_Cnt_u08_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_WriteHook_Ap_SrlComInput_DSTErrCntrRecvLevel_Cnt_u08_Return
# endif
# if defined (Rte_WriteHook_Ap_SrlComInput_DSTErrCntrRecvLevel_Cnt_u08_Return)
#  undef Rte_WriteHook_Ap_SrlComInput_DSTErrCntrRecvLevel_Cnt_u08_Return
FUNC(void, RTE_APPL_CODE) Rte_WriteHook_Ap_SrlComInput_DSTErrCntrRecvLevel_Cnt_u08_Return(UInt8 data);
# else
#  define Rte_WriteHook_Ap_SrlComInput_DSTErrCntrRecvLevel_Cnt_u08_Return(arg1) ((void)(0))
# endif /* Rte_WriteHook_Ap_SrlComInput_DSTErrCntrRecvLevel_Cnt_u08_Return */

# if defined (Rte_WriteHook_Ap_SrlComInput_DSTErrCntrRecvLevel_Cnt_u08_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_WriteHook_Ap_SrlComInput_DSTErrCntrRecvLevel_Cnt_u08_Start
# endif
# if defined (Rte_WriteHook_Ap_SrlComInput_DSTErrCntrRecvLevel_Cnt_u08_Start)
#  undef Rte_WriteHook_Ap_SrlComInput_DSTErrCntrRecvLevel_Cnt_u08_Start
FUNC(void, RTE_APPL_CODE) Rte_WriteHook_Ap_SrlComInput_DSTErrCntrRecvLevel_Cnt_u08_Start(UInt8 data);
# else
#  define Rte_WriteHook_Ap_SrlComInput_DSTErrCntrRecvLevel_Cnt_u08_Start(arg1) ((void)(0))
# endif /* Rte_WriteHook_Ap_SrlComInput_DSTErrCntrRecvLevel_Cnt_u08_Start */

# if defined (Rte_WriteHook_Ap_SrlComInput_DSTExtSystemFltActive_Cnt_lgc_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_WriteHook_Ap_SrlComInput_DSTExtSystemFltActive_Cnt_lgc_Return
# endif
# if defined (Rte_WriteHook_Ap_SrlComInput_DSTExtSystemFltActive_Cnt_lgc_Return)
#  undef Rte_WriteHook_Ap_SrlComInput_DSTExtSystemFltActive_Cnt_lgc_Return
FUNC(void, RTE_APPL_CODE) Rte_WriteHook_Ap_SrlComInput_DSTExtSystemFltActive_Cnt_lgc_Return(Boolean data);
# else
#  define Rte_WriteHook_Ap_SrlComInput_DSTExtSystemFltActive_Cnt_lgc_Return(arg1) ((void)(0))
# endif /* Rte_WriteHook_Ap_SrlComInput_DSTExtSystemFltActive_Cnt_lgc_Return */

# if defined (Rte_WriteHook_Ap_SrlComInput_DSTExtSystemFltActive_Cnt_lgc_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_WriteHook_Ap_SrlComInput_DSTExtSystemFltActive_Cnt_lgc_Start
# endif
# if defined (Rte_WriteHook_Ap_SrlComInput_DSTExtSystemFltActive_Cnt_lgc_Start)
#  undef Rte_WriteHook_Ap_SrlComInput_DSTExtSystemFltActive_Cnt_lgc_Start
FUNC(void, RTE_APPL_CODE) Rte_WriteHook_Ap_SrlComInput_DSTExtSystemFltActive_Cnt_lgc_Start(Boolean data);
# else
#  define Rte_WriteHook_Ap_SrlComInput_DSTExtSystemFltActive_Cnt_lgc_Start(arg1) ((void)(0))
# endif /* Rte_WriteHook_Ap_SrlComInput_DSTExtSystemFltActive_Cnt_lgc_Start */

# if defined (Rte_WriteHook_Ap_SrlComInput_DSTFuncPresent_Cnt_lgc_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_WriteHook_Ap_SrlComInput_DSTFuncPresent_Cnt_lgc_Return
# endif
# if defined (Rte_WriteHook_Ap_SrlComInput_DSTFuncPresent_Cnt_lgc_Return)
#  undef Rte_WriteHook_Ap_SrlComInput_DSTFuncPresent_Cnt_lgc_Return
FUNC(void, RTE_APPL_CODE) Rte_WriteHook_Ap_SrlComInput_DSTFuncPresent_Cnt_lgc_Return(Boolean data);
# else
#  define Rte_WriteHook_Ap_SrlComInput_DSTFuncPresent_Cnt_lgc_Return(arg1) ((void)(0))
# endif /* Rte_WriteHook_Ap_SrlComInput_DSTFuncPresent_Cnt_lgc_Return */

# if defined (Rte_WriteHook_Ap_SrlComInput_DSTFuncPresent_Cnt_lgc_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_WriteHook_Ap_SrlComInput_DSTFuncPresent_Cnt_lgc_Start
# endif
# if defined (Rte_WriteHook_Ap_SrlComInput_DSTFuncPresent_Cnt_lgc_Start)
#  undef Rte_WriteHook_Ap_SrlComInput_DSTFuncPresent_Cnt_lgc_Start
FUNC(void, RTE_APPL_CODE) Rte_WriteHook_Ap_SrlComInput_DSTFuncPresent_Cnt_lgc_Start(Boolean data);
# else
#  define Rte_WriteHook_Ap_SrlComInput_DSTFuncPresent_Cnt_lgc_Start(arg1) ((void)(0))
# endif /* Rte_WriteHook_Ap_SrlComInput_DSTFuncPresent_Cnt_lgc_Start */

# if defined (Rte_WriteHook_Ap_SrlComInput_DSTRevGearValid_Cnt_lgc_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_WriteHook_Ap_SrlComInput_DSTRevGearValid_Cnt_lgc_Return
# endif
# if defined (Rte_WriteHook_Ap_SrlComInput_DSTRevGearValid_Cnt_lgc_Return)
#  undef Rte_WriteHook_Ap_SrlComInput_DSTRevGearValid_Cnt_lgc_Return
FUNC(void, RTE_APPL_CODE) Rte_WriteHook_Ap_SrlComInput_DSTRevGearValid_Cnt_lgc_Return(Boolean data);
# else
#  define Rte_WriteHook_Ap_SrlComInput_DSTRevGearValid_Cnt_lgc_Return(arg1) ((void)(0))
# endif /* Rte_WriteHook_Ap_SrlComInput_DSTRevGearValid_Cnt_lgc_Return */

# if defined (Rte_WriteHook_Ap_SrlComInput_DSTRevGearValid_Cnt_lgc_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_WriteHook_Ap_SrlComInput_DSTRevGearValid_Cnt_lgc_Start
# endif
# if defined (Rte_WriteHook_Ap_SrlComInput_DSTRevGearValid_Cnt_lgc_Start)
#  undef Rte_WriteHook_Ap_SrlComInput_DSTRevGearValid_Cnt_lgc_Start
FUNC(void, RTE_APPL_CODE) Rte_WriteHook_Ap_SrlComInput_DSTRevGearValid_Cnt_lgc_Start(Boolean data);
# else
#  define Rte_WriteHook_Ap_SrlComInput_DSTRevGearValid_Cnt_lgc_Start(arg1) ((void)(0))
# endif /* Rte_WriteHook_Ap_SrlComInput_DSTRevGearValid_Cnt_lgc_Start */

# if defined (Rte_WriteHook_Ap_SrlComInput_DSTTOCState_Uls_enum_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_WriteHook_Ap_SrlComInput_DSTTOCState_Uls_enum_Return
# endif
# if defined (Rte_WriteHook_Ap_SrlComInput_DSTTOCState_Uls_enum_Return)
#  undef Rte_WriteHook_Ap_SrlComInput_DSTTOCState_Uls_enum_Return
FUNC(void, RTE_APPL_CODE) Rte_WriteHook_Ap_SrlComInput_DSTTOCState_Uls_enum_Return(TOC_STATE data);
# else
#  define Rte_WriteHook_Ap_SrlComInput_DSTTOCState_Uls_enum_Return(arg1) ((void)(0))
# endif /* Rte_WriteHook_Ap_SrlComInput_DSTTOCState_Uls_enum_Return */

# if defined (Rte_WriteHook_Ap_SrlComInput_DSTTOCState_Uls_enum_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_WriteHook_Ap_SrlComInput_DSTTOCState_Uls_enum_Start
# endif
# if defined (Rte_WriteHook_Ap_SrlComInput_DSTTOCState_Uls_enum_Start)
#  undef Rte_WriteHook_Ap_SrlComInput_DSTTOCState_Uls_enum_Start
FUNC(void, RTE_APPL_CODE) Rte_WriteHook_Ap_SrlComInput_DSTTOCState_Uls_enum_Start(TOC_STATE data);
# else
#  define Rte_WriteHook_Ap_SrlComInput_DSTTOCState_Uls_enum_Start(arg1) ((void)(0))
# endif /* Rte_WriteHook_Ap_SrlComInput_DSTTOCState_Uls_enum_Start */

# if defined (Rte_WriteHook_Ap_SrlComInput_DSTTrqOvCmdRqst_HwNm_f32_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_WriteHook_Ap_SrlComInput_DSTTrqOvCmdRqst_HwNm_f32_Return
# endif
# if defined (Rte_WriteHook_Ap_SrlComInput_DSTTrqOvCmdRqst_HwNm_f32_Return)
#  undef Rte_WriteHook_Ap_SrlComInput_DSTTrqOvCmdRqst_HwNm_f32_Return
FUNC(void, RTE_APPL_CODE) Rte_WriteHook_Ap_SrlComInput_DSTTrqOvCmdRqst_HwNm_f32_Return(Float data);
# else
#  define Rte_WriteHook_Ap_SrlComInput_DSTTrqOvCmdRqst_HwNm_f32_Return(arg1) ((void)(0))
# endif /* Rte_WriteHook_Ap_SrlComInput_DSTTrqOvCmdRqst_HwNm_f32_Return */

# if defined (Rte_WriteHook_Ap_SrlComInput_DSTTrqOvCmdRqst_HwNm_f32_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_WriteHook_Ap_SrlComInput_DSTTrqOvCmdRqst_HwNm_f32_Start
# endif
# if defined (Rte_WriteHook_Ap_SrlComInput_DSTTrqOvCmdRqst_HwNm_f32_Start)
#  undef Rte_WriteHook_Ap_SrlComInput_DSTTrqOvCmdRqst_HwNm_f32_Start
FUNC(void, RTE_APPL_CODE) Rte_WriteHook_Ap_SrlComInput_DSTTrqOvCmdRqst_HwNm_f32_Start(Float data);
# else
#  define Rte_WriteHook_Ap_SrlComInput_DSTTrqOvCmdRqst_HwNm_f32_Start(arg1) ((void)(0))
# endif /* Rte_WriteHook_Ap_SrlComInput_DSTTrqOvCmdRqst_HwNm_f32_Start */

# if defined (Rte_WriteHook_Ap_SrlComInput_DSTTrqOvRqstValid_Cnt_lgc_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_WriteHook_Ap_SrlComInput_DSTTrqOvRqstValid_Cnt_lgc_Return
# endif
# if defined (Rte_WriteHook_Ap_SrlComInput_DSTTrqOvRqstValid_Cnt_lgc_Return)
#  undef Rte_WriteHook_Ap_SrlComInput_DSTTrqOvRqstValid_Cnt_lgc_Return
FUNC(void, RTE_APPL_CODE) Rte_WriteHook_Ap_SrlComInput_DSTTrqOvRqstValid_Cnt_lgc_Return(Boolean data);
# else
#  define Rte_WriteHook_Ap_SrlComInput_DSTTrqOvRqstValid_Cnt_lgc_Return(arg1) ((void)(0))
# endif /* Rte_WriteHook_Ap_SrlComInput_DSTTrqOvRqstValid_Cnt_lgc_Return */

# if defined (Rte_WriteHook_Ap_SrlComInput_DSTTrqOvRqstValid_Cnt_lgc_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_WriteHook_Ap_SrlComInput_DSTTrqOvRqstValid_Cnt_lgc_Start
# endif
# if defined (Rte_WriteHook_Ap_SrlComInput_DSTTrqOvRqstValid_Cnt_lgc_Start)
#  undef Rte_WriteHook_Ap_SrlComInput_DSTTrqOvRqstValid_Cnt_lgc_Start
FUNC(void, RTE_APPL_CODE) Rte_WriteHook_Ap_SrlComInput_DSTTrqOvRqstValid_Cnt_lgc_Start(Boolean data);
# else
#  define Rte_WriteHook_Ap_SrlComInput_DSTTrqOvRqstValid_Cnt_lgc_Start(arg1) ((void)(0))
# endif /* Rte_WriteHook_Ap_SrlComInput_DSTTrqOvRqstValid_Cnt_lgc_Start */

# if defined (Rte_WriteHook_Ap_SrlComInput_DesiredTunPersTypH_Cnt_u08_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_WriteHook_Ap_SrlComInput_DesiredTunPersTypH_Cnt_u08_Return
# endif
# if defined (Rte_WriteHook_Ap_SrlComInput_DesiredTunPersTypH_Cnt_u08_Return)
#  undef Rte_WriteHook_Ap_SrlComInput_DesiredTunPersTypH_Cnt_u08_Return
FUNC(void, RTE_APPL_CODE) Rte_WriteHook_Ap_SrlComInput_DesiredTunPersTypH_Cnt_u08_Return(UInt8 data);
# else
#  define Rte_WriteHook_Ap_SrlComInput_DesiredTunPersTypH_Cnt_u08_Return(arg1) ((void)(0))
# endif /* Rte_WriteHook_Ap_SrlComInput_DesiredTunPersTypH_Cnt_u08_Return */

# if defined (Rte_WriteHook_Ap_SrlComInput_DesiredTunPersTypH_Cnt_u08_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_WriteHook_Ap_SrlComInput_DesiredTunPersTypH_Cnt_u08_Start
# endif
# if defined (Rte_WriteHook_Ap_SrlComInput_DesiredTunPersTypH_Cnt_u08_Start)
#  undef Rte_WriteHook_Ap_SrlComInput_DesiredTunPersTypH_Cnt_u08_Start
FUNC(void, RTE_APPL_CODE) Rte_WriteHook_Ap_SrlComInput_DesiredTunPersTypH_Cnt_u08_Start(UInt8 data);
# else
#  define Rte_WriteHook_Ap_SrlComInput_DesiredTunPersTypH_Cnt_u08_Start(arg1) ((void)(0))
# endif /* Rte_WriteHook_Ap_SrlComInput_DesiredTunPersTypH_Cnt_u08_Start */

# if defined (Rte_WriteHook_Ap_SrlComInput_DesiredTunPers_Cnt_u16_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_WriteHook_Ap_SrlComInput_DesiredTunPers_Cnt_u16_Return
# endif
# if defined (Rte_WriteHook_Ap_SrlComInput_DesiredTunPers_Cnt_u16_Return)
#  undef Rte_WriteHook_Ap_SrlComInput_DesiredTunPers_Cnt_u16_Return
FUNC(void, RTE_APPL_CODE) Rte_WriteHook_Ap_SrlComInput_DesiredTunPers_Cnt_u16_Return(UInt16 data);
# else
#  define Rte_WriteHook_Ap_SrlComInput_DesiredTunPers_Cnt_u16_Return(arg1) ((void)(0))
# endif /* Rte_WriteHook_Ap_SrlComInput_DesiredTunPers_Cnt_u16_Return */

# if defined (Rte_WriteHook_Ap_SrlComInput_DesiredTunPers_Cnt_u16_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_WriteHook_Ap_SrlComInput_DesiredTunPers_Cnt_u16_Start
# endif
# if defined (Rte_WriteHook_Ap_SrlComInput_DesiredTunPers_Cnt_u16_Start)
#  undef Rte_WriteHook_Ap_SrlComInput_DesiredTunPers_Cnt_u16_Start
FUNC(void, RTE_APPL_CODE) Rte_WriteHook_Ap_SrlComInput_DesiredTunPers_Cnt_u16_Start(UInt16 data);
# else
#  define Rte_WriteHook_Ap_SrlComInput_DesiredTunPers_Cnt_u16_Start(arg1) ((void)(0))
# endif /* Rte_WriteHook_Ap_SrlComInput_DesiredTunPers_Cnt_u16_Start */

# if defined (Rte_WriteHook_Ap_SrlComInput_DesiredTunSet_Cnt_u16_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_WriteHook_Ap_SrlComInput_DesiredTunSet_Cnt_u16_Return
# endif
# if defined (Rte_WriteHook_Ap_SrlComInput_DesiredTunSet_Cnt_u16_Return)
#  undef Rte_WriteHook_Ap_SrlComInput_DesiredTunSet_Cnt_u16_Return
FUNC(void, RTE_APPL_CODE) Rte_WriteHook_Ap_SrlComInput_DesiredTunSet_Cnt_u16_Return(UInt16 data);
# else
#  define Rte_WriteHook_Ap_SrlComInput_DesiredTunSet_Cnt_u16_Return(arg1) ((void)(0))
# endif /* Rte_WriteHook_Ap_SrlComInput_DesiredTunSet_Cnt_u16_Return */

# if defined (Rte_WriteHook_Ap_SrlComInput_DesiredTunSet_Cnt_u16_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_WriteHook_Ap_SrlComInput_DesiredTunSet_Cnt_u16_Start
# endif
# if defined (Rte_WriteHook_Ap_SrlComInput_DesiredTunSet_Cnt_u16_Start)
#  undef Rte_WriteHook_Ap_SrlComInput_DesiredTunSet_Cnt_u16_Start
FUNC(void, RTE_APPL_CODE) Rte_WriteHook_Ap_SrlComInput_DesiredTunSet_Cnt_u16_Start(UInt16 data);
# else
#  define Rte_WriteHook_Ap_SrlComInput_DesiredTunSet_Cnt_u16_Start(arg1) ((void)(0))
# endif /* Rte_WriteHook_Ap_SrlComInput_DesiredTunSet_Cnt_u16_Start */

# if defined (Rte_WriteHook_Ap_SrlComInput_EPS_Mode_Req_Cnt_u08_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_WriteHook_Ap_SrlComInput_EPS_Mode_Req_Cnt_u08_Return
# endif
# if defined (Rte_WriteHook_Ap_SrlComInput_EPS_Mode_Req_Cnt_u08_Return)
#  undef Rte_WriteHook_Ap_SrlComInput_EPS_Mode_Req_Cnt_u08_Return
FUNC(void, RTE_APPL_CODE) Rte_WriteHook_Ap_SrlComInput_EPS_Mode_Req_Cnt_u08_Return(UInt8 data);
# else
#  define Rte_WriteHook_Ap_SrlComInput_EPS_Mode_Req_Cnt_u08_Return(arg1) ((void)(0))
# endif /* Rte_WriteHook_Ap_SrlComInput_EPS_Mode_Req_Cnt_u08_Return */

# if defined (Rte_WriteHook_Ap_SrlComInput_EPS_Mode_Req_Cnt_u08_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_WriteHook_Ap_SrlComInput_EPS_Mode_Req_Cnt_u08_Start
# endif
# if defined (Rte_WriteHook_Ap_SrlComInput_EPS_Mode_Req_Cnt_u08_Start)
#  undef Rte_WriteHook_Ap_SrlComInput_EPS_Mode_Req_Cnt_u08_Start
FUNC(void, RTE_APPL_CODE) Rte_WriteHook_Ap_SrlComInput_EPS_Mode_Req_Cnt_u08_Start(UInt8 data);
# else
#  define Rte_WriteHook_Ap_SrlComInput_EPS_Mode_Req_Cnt_u08_Start(arg1) ((void)(0))
# endif /* Rte_WriteHook_Ap_SrlComInput_EPS_Mode_Req_Cnt_u08_Start */

# if defined (Rte_WriteHook_Ap_SrlComInput_EngOilTemp_DegC_f32_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_WriteHook_Ap_SrlComInput_EngOilTemp_DegC_f32_Return
# endif
# if defined (Rte_WriteHook_Ap_SrlComInput_EngOilTemp_DegC_f32_Return)
#  undef Rte_WriteHook_Ap_SrlComInput_EngOilTemp_DegC_f32_Return
FUNC(void, RTE_APPL_CODE) Rte_WriteHook_Ap_SrlComInput_EngOilTemp_DegC_f32_Return(Float data);
# else
#  define Rte_WriteHook_Ap_SrlComInput_EngOilTemp_DegC_f32_Return(arg1) ((void)(0))
# endif /* Rte_WriteHook_Ap_SrlComInput_EngOilTemp_DegC_f32_Return */

# if defined (Rte_WriteHook_Ap_SrlComInput_EngOilTemp_DegC_f32_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_WriteHook_Ap_SrlComInput_EngOilTemp_DegC_f32_Start
# endif
# if defined (Rte_WriteHook_Ap_SrlComInput_EngOilTemp_DegC_f32_Start)
#  undef Rte_WriteHook_Ap_SrlComInput_EngOilTemp_DegC_f32_Start
FUNC(void, RTE_APPL_CODE) Rte_WriteHook_Ap_SrlComInput_EngOilTemp_DegC_f32_Start(Float data);
# else
#  define Rte_WriteHook_Ap_SrlComInput_EngOilTemp_DegC_f32_Start(arg1) ((void)(0))
# endif /* Rte_WriteHook_Ap_SrlComInput_EngOilTemp_DegC_f32_Start */

# if defined (Rte_WriteHook_Ap_SrlComInput_EngRPM_Cnt_u16_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_WriteHook_Ap_SrlComInput_EngRPM_Cnt_u16_Return
# endif
# if defined (Rte_WriteHook_Ap_SrlComInput_EngRPM_Cnt_u16_Return)
#  undef Rte_WriteHook_Ap_SrlComInput_EngRPM_Cnt_u16_Return
FUNC(void, RTE_APPL_CODE) Rte_WriteHook_Ap_SrlComInput_EngRPM_Cnt_u16_Return(UInt16 data);
# else
#  define Rte_WriteHook_Ap_SrlComInput_EngRPM_Cnt_u16_Return(arg1) ((void)(0))
# endif /* Rte_WriteHook_Ap_SrlComInput_EngRPM_Cnt_u16_Return */

# if defined (Rte_WriteHook_Ap_SrlComInput_EngRPM_Cnt_u16_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_WriteHook_Ap_SrlComInput_EngRPM_Cnt_u16_Start
# endif
# if defined (Rte_WriteHook_Ap_SrlComInput_EngRPM_Cnt_u16_Start)
#  undef Rte_WriteHook_Ap_SrlComInput_EngRPM_Cnt_u16_Start
FUNC(void, RTE_APPL_CODE) Rte_WriteHook_Ap_SrlComInput_EngRPM_Cnt_u16_Start(UInt16 data);
# else
#  define Rte_WriteHook_Ap_SrlComInput_EngRPM_Cnt_u16_Start(arg1) ((void)(0))
# endif /* Rte_WriteHook_Ap_SrlComInput_EngRPM_Cnt_u16_Start */

# if defined (Rte_WriteHook_Ap_SrlComInput_EssEngStop_Cnt_lgc_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_WriteHook_Ap_SrlComInput_EssEngStop_Cnt_lgc_Return
# endif
# if defined (Rte_WriteHook_Ap_SrlComInput_EssEngStop_Cnt_lgc_Return)
#  undef Rte_WriteHook_Ap_SrlComInput_EssEngStop_Cnt_lgc_Return
FUNC(void, RTE_APPL_CODE) Rte_WriteHook_Ap_SrlComInput_EssEngStop_Cnt_lgc_Return(Boolean data);
# else
#  define Rte_WriteHook_Ap_SrlComInput_EssEngStop_Cnt_lgc_Return(arg1) ((void)(0))
# endif /* Rte_WriteHook_Ap_SrlComInput_EssEngStop_Cnt_lgc_Return */

# if defined (Rte_WriteHook_Ap_SrlComInput_EssEngStop_Cnt_lgc_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_WriteHook_Ap_SrlComInput_EssEngStop_Cnt_lgc_Start
# endif
# if defined (Rte_WriteHook_Ap_SrlComInput_EssEngStop_Cnt_lgc_Start)
#  undef Rte_WriteHook_Ap_SrlComInput_EssEngStop_Cnt_lgc_Start
FUNC(void, RTE_APPL_CODE) Rte_WriteHook_Ap_SrlComInput_EssEngStop_Cnt_lgc_Start(Boolean data);
# else
#  define Rte_WriteHook_Ap_SrlComInput_EssEngStop_Cnt_lgc_Start(arg1) ((void)(0))
# endif /* Rte_WriteHook_Ap_SrlComInput_EssEngStop_Cnt_lgc_Start */

# if defined (Rte_WriteHook_Ap_SrlComInput_HaLFEnableRqst_Cnt_lgc_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_WriteHook_Ap_SrlComInput_HaLFEnableRqst_Cnt_lgc_Return
# endif
# if defined (Rte_WriteHook_Ap_SrlComInput_HaLFEnableRqst_Cnt_lgc_Return)
#  undef Rte_WriteHook_Ap_SrlComInput_HaLFEnableRqst_Cnt_lgc_Return
FUNC(void, RTE_APPL_CODE) Rte_WriteHook_Ap_SrlComInput_HaLFEnableRqst_Cnt_lgc_Return(Boolean data);
# else
#  define Rte_WriteHook_Ap_SrlComInput_HaLFEnableRqst_Cnt_lgc_Return(arg1) ((void)(0))
# endif /* Rte_WriteHook_Ap_SrlComInput_HaLFEnableRqst_Cnt_lgc_Return */

# if defined (Rte_WriteHook_Ap_SrlComInput_HaLFEnableRqst_Cnt_lgc_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_WriteHook_Ap_SrlComInput_HaLFEnableRqst_Cnt_lgc_Start
# endif
# if defined (Rte_WriteHook_Ap_SrlComInput_HaLFEnableRqst_Cnt_lgc_Start)
#  undef Rte_WriteHook_Ap_SrlComInput_HaLFEnableRqst_Cnt_lgc_Start
FUNC(void, RTE_APPL_CODE) Rte_WriteHook_Ap_SrlComInput_HaLFEnableRqst_Cnt_lgc_Start(Boolean data);
# else
#  define Rte_WriteHook_Ap_SrlComInput_HaLFEnableRqst_Cnt_lgc_Start(arg1) ((void)(0))
# endif /* Rte_WriteHook_Ap_SrlComInput_HaLFEnableRqst_Cnt_lgc_Start */

# if defined (Rte_WriteHook_Ap_SrlComInput_HaLFErrInterfaceActive_Cnt_lgc_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_WriteHook_Ap_SrlComInput_HaLFErrInterfaceActive_Cnt_lgc_Return
# endif
# if defined (Rte_WriteHook_Ap_SrlComInput_HaLFErrInterfaceActive_Cnt_lgc_Return)
#  undef Rte_WriteHook_Ap_SrlComInput_HaLFErrInterfaceActive_Cnt_lgc_Return
FUNC(void, RTE_APPL_CODE) Rte_WriteHook_Ap_SrlComInput_HaLFErrInterfaceActive_Cnt_lgc_Return(Boolean data);
# else
#  define Rte_WriteHook_Ap_SrlComInput_HaLFErrInterfaceActive_Cnt_lgc_Return(arg1) ((void)(0))
# endif /* Rte_WriteHook_Ap_SrlComInput_HaLFErrInterfaceActive_Cnt_lgc_Return */

# if defined (Rte_WriteHook_Ap_SrlComInput_HaLFErrInterfaceActive_Cnt_lgc_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_WriteHook_Ap_SrlComInput_HaLFErrInterfaceActive_Cnt_lgc_Start
# endif
# if defined (Rte_WriteHook_Ap_SrlComInput_HaLFErrInterfaceActive_Cnt_lgc_Start)
#  undef Rte_WriteHook_Ap_SrlComInput_HaLFErrInterfaceActive_Cnt_lgc_Start
FUNC(void, RTE_APPL_CODE) Rte_WriteHook_Ap_SrlComInput_HaLFErrInterfaceActive_Cnt_lgc_Start(Boolean data);
# else
#  define Rte_WriteHook_Ap_SrlComInput_HaLFErrInterfaceActive_Cnt_lgc_Start(arg1) ((void)(0))
# endif /* Rte_WriteHook_Ap_SrlComInput_HaLFErrInterfaceActive_Cnt_lgc_Start */

# if defined (Rte_WriteHook_Ap_SrlComInput_HaLFExtSystemFltActive_Cnt_lgc_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_WriteHook_Ap_SrlComInput_HaLFExtSystemFltActive_Cnt_lgc_Return
# endif
# if defined (Rte_WriteHook_Ap_SrlComInput_HaLFExtSystemFltActive_Cnt_lgc_Return)
#  undef Rte_WriteHook_Ap_SrlComInput_HaLFExtSystemFltActive_Cnt_lgc_Return
FUNC(void, RTE_APPL_CODE) Rte_WriteHook_Ap_SrlComInput_HaLFExtSystemFltActive_Cnt_lgc_Return(Boolean data);
# else
#  define Rte_WriteHook_Ap_SrlComInput_HaLFExtSystemFltActive_Cnt_lgc_Return(arg1) ((void)(0))
# endif /* Rte_WriteHook_Ap_SrlComInput_HaLFExtSystemFltActive_Cnt_lgc_Return */

# if defined (Rte_WriteHook_Ap_SrlComInput_HaLFExtSystemFltActive_Cnt_lgc_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_WriteHook_Ap_SrlComInput_HaLFExtSystemFltActive_Cnt_lgc_Start
# endif
# if defined (Rte_WriteHook_Ap_SrlComInput_HaLFExtSystemFltActive_Cnt_lgc_Start)
#  undef Rte_WriteHook_Ap_SrlComInput_HaLFExtSystemFltActive_Cnt_lgc_Start
FUNC(void, RTE_APPL_CODE) Rte_WriteHook_Ap_SrlComInput_HaLFExtSystemFltActive_Cnt_lgc_Start(Boolean data);
# else
#  define Rte_WriteHook_Ap_SrlComInput_HaLFExtSystemFltActive_Cnt_lgc_Start(arg1) ((void)(0))
# endif /* Rte_WriteHook_Ap_SrlComInput_HaLFExtSystemFltActive_Cnt_lgc_Start */

# if defined (Rte_WriteHook_Ap_SrlComInput_HaLFFuncPresent_Cnt_lgc_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_WriteHook_Ap_SrlComInput_HaLFFuncPresent_Cnt_lgc_Return
# endif
# if defined (Rte_WriteHook_Ap_SrlComInput_HaLFFuncPresent_Cnt_lgc_Return)
#  undef Rte_WriteHook_Ap_SrlComInput_HaLFFuncPresent_Cnt_lgc_Return
FUNC(void, RTE_APPL_CODE) Rte_WriteHook_Ap_SrlComInput_HaLFFuncPresent_Cnt_lgc_Return(Boolean data);
# else
#  define Rte_WriteHook_Ap_SrlComInput_HaLFFuncPresent_Cnt_lgc_Return(arg1) ((void)(0))
# endif /* Rte_WriteHook_Ap_SrlComInput_HaLFFuncPresent_Cnt_lgc_Return */

# if defined (Rte_WriteHook_Ap_SrlComInput_HaLFFuncPresent_Cnt_lgc_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_WriteHook_Ap_SrlComInput_HaLFFuncPresent_Cnt_lgc_Start
# endif
# if defined (Rte_WriteHook_Ap_SrlComInput_HaLFFuncPresent_Cnt_lgc_Start)
#  undef Rte_WriteHook_Ap_SrlComInput_HaLFFuncPresent_Cnt_lgc_Start
FUNC(void, RTE_APPL_CODE) Rte_WriteHook_Ap_SrlComInput_HaLFFuncPresent_Cnt_lgc_Start(Boolean data);
# else
#  define Rte_WriteHook_Ap_SrlComInput_HaLFFuncPresent_Cnt_lgc_Start(arg1) ((void)(0))
# endif /* Rte_WriteHook_Ap_SrlComInput_HaLFFuncPresent_Cnt_lgc_Start */

# if defined (Rte_WriteHook_Ap_SrlComInput_HaLFIntSystemFltActive_Cnt_lgc_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_WriteHook_Ap_SrlComInput_HaLFIntSystemFltActive_Cnt_lgc_Return
# endif
# if defined (Rte_WriteHook_Ap_SrlComInput_HaLFIntSystemFltActive_Cnt_lgc_Return)
#  undef Rte_WriteHook_Ap_SrlComInput_HaLFIntSystemFltActive_Cnt_lgc_Return
FUNC(void, RTE_APPL_CODE) Rte_WriteHook_Ap_SrlComInput_HaLFIntSystemFltActive_Cnt_lgc_Return(Boolean data);
# else
#  define Rte_WriteHook_Ap_SrlComInput_HaLFIntSystemFltActive_Cnt_lgc_Return(arg1) ((void)(0))
# endif /* Rte_WriteHook_Ap_SrlComInput_HaLFIntSystemFltActive_Cnt_lgc_Return */

# if defined (Rte_WriteHook_Ap_SrlComInput_HaLFIntSystemFltActive_Cnt_lgc_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_WriteHook_Ap_SrlComInput_HaLFIntSystemFltActive_Cnt_lgc_Start
# endif
# if defined (Rte_WriteHook_Ap_SrlComInput_HaLFIntSystemFltActive_Cnt_lgc_Start)
#  undef Rte_WriteHook_Ap_SrlComInput_HaLFIntSystemFltActive_Cnt_lgc_Start
FUNC(void, RTE_APPL_CODE) Rte_WriteHook_Ap_SrlComInput_HaLFIntSystemFltActive_Cnt_lgc_Start(Boolean data);
# else
#  define Rte_WriteHook_Ap_SrlComInput_HaLFIntSystemFltActive_Cnt_lgc_Start(arg1) ((void)(0))
# endif /* Rte_WriteHook_Ap_SrlComInput_HaLFIntSystemFltActive_Cnt_lgc_Start */

# if defined (Rte_WriteHook_Ap_SrlComInput_HaLFSWATrqFail_Cnt_lgc_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_WriteHook_Ap_SrlComInput_HaLFSWATrqFail_Cnt_lgc_Return
# endif
# if defined (Rte_WriteHook_Ap_SrlComInput_HaLFSWATrqFail_Cnt_lgc_Return)
#  undef Rte_WriteHook_Ap_SrlComInput_HaLFSWATrqFail_Cnt_lgc_Return
FUNC(void, RTE_APPL_CODE) Rte_WriteHook_Ap_SrlComInput_HaLFSWATrqFail_Cnt_lgc_Return(Boolean data);
# else
#  define Rte_WriteHook_Ap_SrlComInput_HaLFSWATrqFail_Cnt_lgc_Return(arg1) ((void)(0))
# endif /* Rte_WriteHook_Ap_SrlComInput_HaLFSWATrqFail_Cnt_lgc_Return */

# if defined (Rte_WriteHook_Ap_SrlComInput_HaLFSWATrqFail_Cnt_lgc_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_WriteHook_Ap_SrlComInput_HaLFSWATrqFail_Cnt_lgc_Start
# endif
# if defined (Rte_WriteHook_Ap_SrlComInput_HaLFSWATrqFail_Cnt_lgc_Start)
#  undef Rte_WriteHook_Ap_SrlComInput_HaLFSWATrqFail_Cnt_lgc_Start
FUNC(void, RTE_APPL_CODE) Rte_WriteHook_Ap_SrlComInput_HaLFSWATrqFail_Cnt_lgc_Start(Boolean data);
# else
#  define Rte_WriteHook_Ap_SrlComInput_HaLFSWATrqFail_Cnt_lgc_Start(arg1) ((void)(0))
# endif /* Rte_WriteHook_Ap_SrlComInput_HaLFSWATrqFail_Cnt_lgc_Start */

# if defined (Rte_WriteHook_Ap_SrlComInput_HaLFTrqOvCmdRqst_MtrNm_f32_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_WriteHook_Ap_SrlComInput_HaLFTrqOvCmdRqst_MtrNm_f32_Return
# endif
# if defined (Rte_WriteHook_Ap_SrlComInput_HaLFTrqOvCmdRqst_MtrNm_f32_Return)
#  undef Rte_WriteHook_Ap_SrlComInput_HaLFTrqOvCmdRqst_MtrNm_f32_Return
FUNC(void, RTE_APPL_CODE) Rte_WriteHook_Ap_SrlComInput_HaLFTrqOvCmdRqst_MtrNm_f32_Return(Float data);
# else
#  define Rte_WriteHook_Ap_SrlComInput_HaLFTrqOvCmdRqst_MtrNm_f32_Return(arg1) ((void)(0))
# endif /* Rte_WriteHook_Ap_SrlComInput_HaLFTrqOvCmdRqst_MtrNm_f32_Return */

# if defined (Rte_WriteHook_Ap_SrlComInput_HaLFTrqOvCmdRqst_MtrNm_f32_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_WriteHook_Ap_SrlComInput_HaLFTrqOvCmdRqst_MtrNm_f32_Start
# endif
# if defined (Rte_WriteHook_Ap_SrlComInput_HaLFTrqOvCmdRqst_MtrNm_f32_Start)
#  undef Rte_WriteHook_Ap_SrlComInput_HaLFTrqOvCmdRqst_MtrNm_f32_Start
FUNC(void, RTE_APPL_CODE) Rte_WriteHook_Ap_SrlComInput_HaLFTrqOvCmdRqst_MtrNm_f32_Start(Float data);
# else
#  define Rte_WriteHook_Ap_SrlComInput_HaLFTrqOvCmdRqst_MtrNm_f32_Start(arg1) ((void)(0))
# endif /* Rte_WriteHook_Ap_SrlComInput_HaLFTrqOvCmdRqst_MtrNm_f32_Start */

# if defined (Rte_WriteHook_Ap_SrlComInput_HalfTrqOvRvrsGearEngage_Cnt_lgc_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_WriteHook_Ap_SrlComInput_HalfTrqOvRvrsGearEngage_Cnt_lgc_Return
# endif
# if defined (Rte_WriteHook_Ap_SrlComInput_HalfTrqOvRvrsGearEngage_Cnt_lgc_Return)
#  undef Rte_WriteHook_Ap_SrlComInput_HalfTrqOvRvrsGearEngage_Cnt_lgc_Return
FUNC(void, RTE_APPL_CODE) Rte_WriteHook_Ap_SrlComInput_HalfTrqOvRvrsGearEngage_Cnt_lgc_Return(Boolean data);
# else
#  define Rte_WriteHook_Ap_SrlComInput_HalfTrqOvRvrsGearEngage_Cnt_lgc_Return(arg1) ((void)(0))
# endif /* Rte_WriteHook_Ap_SrlComInput_HalfTrqOvRvrsGearEngage_Cnt_lgc_Return */

# if defined (Rte_WriteHook_Ap_SrlComInput_HalfTrqOvRvrsGearEngage_Cnt_lgc_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_WriteHook_Ap_SrlComInput_HalfTrqOvRvrsGearEngage_Cnt_lgc_Start
# endif
# if defined (Rte_WriteHook_Ap_SrlComInput_HalfTrqOvRvrsGearEngage_Cnt_lgc_Start)
#  undef Rte_WriteHook_Ap_SrlComInput_HalfTrqOvRvrsGearEngage_Cnt_lgc_Start
FUNC(void, RTE_APPL_CODE) Rte_WriteHook_Ap_SrlComInput_HalfTrqOvRvrsGearEngage_Cnt_lgc_Start(Boolean data);
# else
#  define Rte_WriteHook_Ap_SrlComInput_HalfTrqOvRvrsGearEngage_Cnt_lgc_Start(arg1) ((void)(0))
# endif /* Rte_WriteHook_Ap_SrlComInput_HalfTrqOvRvrsGearEngage_Cnt_lgc_Start */

# if defined (Rte_WriteHook_Ap_SrlComInput_IWSSCalcVspd_Kph_f32_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_WriteHook_Ap_SrlComInput_IWSSCalcVspd_Kph_f32_Return
# endif
# if defined (Rte_WriteHook_Ap_SrlComInput_IWSSCalcVspd_Kph_f32_Return)
#  undef Rte_WriteHook_Ap_SrlComInput_IWSSCalcVspd_Kph_f32_Return
FUNC(void, RTE_APPL_CODE) Rte_WriteHook_Ap_SrlComInput_IWSSCalcVspd_Kph_f32_Return(Float data);
# else
#  define Rte_WriteHook_Ap_SrlComInput_IWSSCalcVspd_Kph_f32_Return(arg1) ((void)(0))
# endif /* Rte_WriteHook_Ap_SrlComInput_IWSSCalcVspd_Kph_f32_Return */

# if defined (Rte_WriteHook_Ap_SrlComInput_IWSSCalcVspd_Kph_f32_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_WriteHook_Ap_SrlComInput_IWSSCalcVspd_Kph_f32_Start
# endif
# if defined (Rte_WriteHook_Ap_SrlComInput_IWSSCalcVspd_Kph_f32_Start)
#  undef Rte_WriteHook_Ap_SrlComInput_IWSSCalcVspd_Kph_f32_Start
FUNC(void, RTE_APPL_CODE) Rte_WriteHook_Ap_SrlComInput_IWSSCalcVspd_Kph_f32_Start(Float data);
# else
#  define Rte_WriteHook_Ap_SrlComInput_IWSSCalcVspd_Kph_f32_Start(arg1) ((void)(0))
# endif /* Rte_WriteHook_Ap_SrlComInput_IWSSCalcVspd_Kph_f32_Start */

# if defined (Rte_WriteHook_Ap_SrlComInput_NET_CFG_STAT_PT_Cnt_u16_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_WriteHook_Ap_SrlComInput_NET_CFG_STAT_PT_Cnt_u16_Return
# endif
# if defined (Rte_WriteHook_Ap_SrlComInput_NET_CFG_STAT_PT_Cnt_u16_Return)
#  undef Rte_WriteHook_Ap_SrlComInput_NET_CFG_STAT_PT_Cnt_u16_Return
FUNC(void, RTE_APPL_CODE) Rte_WriteHook_Ap_SrlComInput_NET_CFG_STAT_PT_Cnt_u16_Return(UInt16 data);
# else
#  define Rte_WriteHook_Ap_SrlComInput_NET_CFG_STAT_PT_Cnt_u16_Return(arg1) ((void)(0))
# endif /* Rte_WriteHook_Ap_SrlComInput_NET_CFG_STAT_PT_Cnt_u16_Return */

# if defined (Rte_WriteHook_Ap_SrlComInput_NET_CFG_STAT_PT_Cnt_u16_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_WriteHook_Ap_SrlComInput_NET_CFG_STAT_PT_Cnt_u16_Start
# endif
# if defined (Rte_WriteHook_Ap_SrlComInput_NET_CFG_STAT_PT_Cnt_u16_Start)
#  undef Rte_WriteHook_Ap_SrlComInput_NET_CFG_STAT_PT_Cnt_u16_Start
FUNC(void, RTE_APPL_CODE) Rte_WriteHook_Ap_SrlComInput_NET_CFG_STAT_PT_Cnt_u16_Start(UInt16 data);
# else
#  define Rte_WriteHook_Ap_SrlComInput_NET_CFG_STAT_PT_Cnt_u16_Start(arg1) ((void)(0))
# endif /* Rte_WriteHook_Ap_SrlComInput_NET_CFG_STAT_PT_Cnt_u16_Start */

# if defined (Rte_WriteHook_Ap_SrlComInput_ODO_HwNmSq_f32_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_WriteHook_Ap_SrlComInput_ODO_HwNmSq_f32_Return
# endif
# if defined (Rte_WriteHook_Ap_SrlComInput_ODO_HwNmSq_f32_Return)
#  undef Rte_WriteHook_Ap_SrlComInput_ODO_HwNmSq_f32_Return
FUNC(void, RTE_APPL_CODE) Rte_WriteHook_Ap_SrlComInput_ODO_HwNmSq_f32_Return(Float data);
# else
#  define Rte_WriteHook_Ap_SrlComInput_ODO_HwNmSq_f32_Return(arg1) ((void)(0))
# endif /* Rte_WriteHook_Ap_SrlComInput_ODO_HwNmSq_f32_Return */

# if defined (Rte_WriteHook_Ap_SrlComInput_ODO_HwNmSq_f32_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_WriteHook_Ap_SrlComInput_ODO_HwNmSq_f32_Start
# endif
# if defined (Rte_WriteHook_Ap_SrlComInput_ODO_HwNmSq_f32_Start)
#  undef Rte_WriteHook_Ap_SrlComInput_ODO_HwNmSq_f32_Start
FUNC(void, RTE_APPL_CODE) Rte_WriteHook_Ap_SrlComInput_ODO_HwNmSq_f32_Start(Float data);
# else
#  define Rte_WriteHook_Ap_SrlComInput_ODO_HwNmSq_f32_Start(arg1) ((void)(0))
# endif /* Rte_WriteHook_Ap_SrlComInput_ODO_HwNmSq_f32_Start */

# if defined (Rte_WriteHook_Ap_SrlComInput_PAEnableRqst_Cnt_lgc_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_WriteHook_Ap_SrlComInput_PAEnableRqst_Cnt_lgc_Return
# endif
# if defined (Rte_WriteHook_Ap_SrlComInput_PAEnableRqst_Cnt_lgc_Return)
#  undef Rte_WriteHook_Ap_SrlComInput_PAEnableRqst_Cnt_lgc_Return
FUNC(void, RTE_APPL_CODE) Rte_WriteHook_Ap_SrlComInput_PAEnableRqst_Cnt_lgc_Return(Boolean data);
# else
#  define Rte_WriteHook_Ap_SrlComInput_PAEnableRqst_Cnt_lgc_Return(arg1) ((void)(0))
# endif /* Rte_WriteHook_Ap_SrlComInput_PAEnableRqst_Cnt_lgc_Return */

# if defined (Rte_WriteHook_Ap_SrlComInput_PAEnableRqst_Cnt_lgc_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_WriteHook_Ap_SrlComInput_PAEnableRqst_Cnt_lgc_Start
# endif
# if defined (Rte_WriteHook_Ap_SrlComInput_PAEnableRqst_Cnt_lgc_Start)
#  undef Rte_WriteHook_Ap_SrlComInput_PAEnableRqst_Cnt_lgc_Start
FUNC(void, RTE_APPL_CODE) Rte_WriteHook_Ap_SrlComInput_PAEnableRqst_Cnt_lgc_Start(Boolean data);
# else
#  define Rte_WriteHook_Ap_SrlComInput_PAEnableRqst_Cnt_lgc_Start(arg1) ((void)(0))
# endif /* Rte_WriteHook_Ap_SrlComInput_PAEnableRqst_Cnt_lgc_Start */

# if defined (Rte_WriteHook_Ap_SrlComInput_PAErrInterfaceActive_Cnt_lgc_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_WriteHook_Ap_SrlComInput_PAErrInterfaceActive_Cnt_lgc_Return
# endif
# if defined (Rte_WriteHook_Ap_SrlComInput_PAErrInterfaceActive_Cnt_lgc_Return)
#  undef Rte_WriteHook_Ap_SrlComInput_PAErrInterfaceActive_Cnt_lgc_Return
FUNC(void, RTE_APPL_CODE) Rte_WriteHook_Ap_SrlComInput_PAErrInterfaceActive_Cnt_lgc_Return(Boolean data);
# else
#  define Rte_WriteHook_Ap_SrlComInput_PAErrInterfaceActive_Cnt_lgc_Return(arg1) ((void)(0))
# endif /* Rte_WriteHook_Ap_SrlComInput_PAErrInterfaceActive_Cnt_lgc_Return */

# if defined (Rte_WriteHook_Ap_SrlComInput_PAErrInterfaceActive_Cnt_lgc_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_WriteHook_Ap_SrlComInput_PAErrInterfaceActive_Cnt_lgc_Start
# endif
# if defined (Rte_WriteHook_Ap_SrlComInput_PAErrInterfaceActive_Cnt_lgc_Start)
#  undef Rte_WriteHook_Ap_SrlComInput_PAErrInterfaceActive_Cnt_lgc_Start
FUNC(void, RTE_APPL_CODE) Rte_WriteHook_Ap_SrlComInput_PAErrInterfaceActive_Cnt_lgc_Start(Boolean data);
# else
#  define Rte_WriteHook_Ap_SrlComInput_PAErrInterfaceActive_Cnt_lgc_Start(arg1) ((void)(0))
# endif /* Rte_WriteHook_Ap_SrlComInput_PAErrInterfaceActive_Cnt_lgc_Start */

# if defined (Rte_WriteHook_Ap_SrlComInput_PAExtSystemFltActive_Cnt_lgc_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_WriteHook_Ap_SrlComInput_PAExtSystemFltActive_Cnt_lgc_Return
# endif
# if defined (Rte_WriteHook_Ap_SrlComInput_PAExtSystemFltActive_Cnt_lgc_Return)
#  undef Rte_WriteHook_Ap_SrlComInput_PAExtSystemFltActive_Cnt_lgc_Return
FUNC(void, RTE_APPL_CODE) Rte_WriteHook_Ap_SrlComInput_PAExtSystemFltActive_Cnt_lgc_Return(Boolean data);
# else
#  define Rte_WriteHook_Ap_SrlComInput_PAExtSystemFltActive_Cnt_lgc_Return(arg1) ((void)(0))
# endif /* Rte_WriteHook_Ap_SrlComInput_PAExtSystemFltActive_Cnt_lgc_Return */

# if defined (Rte_WriteHook_Ap_SrlComInput_PAExtSystemFltActive_Cnt_lgc_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_WriteHook_Ap_SrlComInput_PAExtSystemFltActive_Cnt_lgc_Start
# endif
# if defined (Rte_WriteHook_Ap_SrlComInput_PAExtSystemFltActive_Cnt_lgc_Start)
#  undef Rte_WriteHook_Ap_SrlComInput_PAExtSystemFltActive_Cnt_lgc_Start
FUNC(void, RTE_APPL_CODE) Rte_WriteHook_Ap_SrlComInput_PAExtSystemFltActive_Cnt_lgc_Start(Boolean data);
# else
#  define Rte_WriteHook_Ap_SrlComInput_PAExtSystemFltActive_Cnt_lgc_Start(arg1) ((void)(0))
# endif /* Rte_WriteHook_Ap_SrlComInput_PAExtSystemFltActive_Cnt_lgc_Start */

# if defined (Rte_WriteHook_Ap_SrlComInput_PAIntSystemFltActive_Cnt_lgc_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_WriteHook_Ap_SrlComInput_PAIntSystemFltActive_Cnt_lgc_Return
# endif
# if defined (Rte_WriteHook_Ap_SrlComInput_PAIntSystemFltActive_Cnt_lgc_Return)
#  undef Rte_WriteHook_Ap_SrlComInput_PAIntSystemFltActive_Cnt_lgc_Return
FUNC(void, RTE_APPL_CODE) Rte_WriteHook_Ap_SrlComInput_PAIntSystemFltActive_Cnt_lgc_Return(Boolean data);
# else
#  define Rte_WriteHook_Ap_SrlComInput_PAIntSystemFltActive_Cnt_lgc_Return(arg1) ((void)(0))
# endif /* Rte_WriteHook_Ap_SrlComInput_PAIntSystemFltActive_Cnt_lgc_Return */

# if defined (Rte_WriteHook_Ap_SrlComInput_PAIntSystemFltActive_Cnt_lgc_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_WriteHook_Ap_SrlComInput_PAIntSystemFltActive_Cnt_lgc_Start
# endif
# if defined (Rte_WriteHook_Ap_SrlComInput_PAIntSystemFltActive_Cnt_lgc_Start)
#  undef Rte_WriteHook_Ap_SrlComInput_PAIntSystemFltActive_Cnt_lgc_Start
FUNC(void, RTE_APPL_CODE) Rte_WriteHook_Ap_SrlComInput_PAIntSystemFltActive_Cnt_lgc_Start(Boolean data);
# else
#  define Rte_WriteHook_Ap_SrlComInput_PAIntSystemFltActive_Cnt_lgc_Start(arg1) ((void)(0))
# endif /* Rte_WriteHook_Ap_SrlComInput_PAIntSystemFltActive_Cnt_lgc_Start */

# if defined (Rte_WriteHook_Ap_SrlComInput_PAManoeuvrePhase_Cnt_u08_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_WriteHook_Ap_SrlComInput_PAManoeuvrePhase_Cnt_u08_Return
# endif
# if defined (Rte_WriteHook_Ap_SrlComInput_PAManoeuvrePhase_Cnt_u08_Return)
#  undef Rte_WriteHook_Ap_SrlComInput_PAManoeuvrePhase_Cnt_u08_Return
FUNC(void, RTE_APPL_CODE) Rte_WriteHook_Ap_SrlComInput_PAManoeuvrePhase_Cnt_u08_Return(UInt8 data);
# else
#  define Rte_WriteHook_Ap_SrlComInput_PAManoeuvrePhase_Cnt_u08_Return(arg1) ((void)(0))
# endif /* Rte_WriteHook_Ap_SrlComInput_PAManoeuvrePhase_Cnt_u08_Return */

# if defined (Rte_WriteHook_Ap_SrlComInput_PAManoeuvrePhase_Cnt_u08_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_WriteHook_Ap_SrlComInput_PAManoeuvrePhase_Cnt_u08_Start
# endif
# if defined (Rte_WriteHook_Ap_SrlComInput_PAManoeuvrePhase_Cnt_u08_Start)
#  undef Rte_WriteHook_Ap_SrlComInput_PAManoeuvrePhase_Cnt_u08_Start
FUNC(void, RTE_APPL_CODE) Rte_WriteHook_Ap_SrlComInput_PAManoeuvrePhase_Cnt_u08_Start(UInt8 data);
# else
#  define Rte_WriteHook_Ap_SrlComInput_PAManoeuvrePhase_Cnt_u08_Start(arg1) ((void)(0))
# endif /* Rte_WriteHook_Ap_SrlComInput_PAManoeuvrePhase_Cnt_u08_Start */

# if defined (Rte_WriteHook_Ap_SrlComInput_PATrqOvCmdRqst_HwNm_f32_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_WriteHook_Ap_SrlComInput_PATrqOvCmdRqst_HwNm_f32_Return
# endif
# if defined (Rte_WriteHook_Ap_SrlComInput_PATrqOvCmdRqst_HwNm_f32_Return)
#  undef Rte_WriteHook_Ap_SrlComInput_PATrqOvCmdRqst_HwNm_f32_Return
FUNC(void, RTE_APPL_CODE) Rte_WriteHook_Ap_SrlComInput_PATrqOvCmdRqst_HwNm_f32_Return(Float data);
# else
#  define Rte_WriteHook_Ap_SrlComInput_PATrqOvCmdRqst_HwNm_f32_Return(arg1) ((void)(0))
# endif /* Rte_WriteHook_Ap_SrlComInput_PATrqOvCmdRqst_HwNm_f32_Return */

# if defined (Rte_WriteHook_Ap_SrlComInput_PATrqOvCmdRqst_HwNm_f32_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_WriteHook_Ap_SrlComInput_PATrqOvCmdRqst_HwNm_f32_Start
# endif
# if defined (Rte_WriteHook_Ap_SrlComInput_PATrqOvCmdRqst_HwNm_f32_Start)
#  undef Rte_WriteHook_Ap_SrlComInput_PATrqOvCmdRqst_HwNm_f32_Start
FUNC(void, RTE_APPL_CODE) Rte_WriteHook_Ap_SrlComInput_PATrqOvCmdRqst_HwNm_f32_Start(Float data);
# else
#  define Rte_WriteHook_Ap_SrlComInput_PATrqOvCmdRqst_HwNm_f32_Start(arg1) ((void)(0))
# endif /* Rte_WriteHook_Ap_SrlComInput_PATrqOvCmdRqst_HwNm_f32_Start */

# if defined (Rte_WriteHook_Ap_SrlComInput_PAWheelCriteriaMet_Cnt_lgc_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_WriteHook_Ap_SrlComInput_PAWheelCriteriaMet_Cnt_lgc_Return
# endif
# if defined (Rte_WriteHook_Ap_SrlComInput_PAWheelCriteriaMet_Cnt_lgc_Return)
#  undef Rte_WriteHook_Ap_SrlComInput_PAWheelCriteriaMet_Cnt_lgc_Return
FUNC(void, RTE_APPL_CODE) Rte_WriteHook_Ap_SrlComInput_PAWheelCriteriaMet_Cnt_lgc_Return(Boolean data);
# else
#  define Rte_WriteHook_Ap_SrlComInput_PAWheelCriteriaMet_Cnt_lgc_Return(arg1) ((void)(0))
# endif /* Rte_WriteHook_Ap_SrlComInput_PAWheelCriteriaMet_Cnt_lgc_Return */

# if defined (Rte_WriteHook_Ap_SrlComInput_PAWheelCriteriaMet_Cnt_lgc_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_WriteHook_Ap_SrlComInput_PAWheelCriteriaMet_Cnt_lgc_Start
# endif
# if defined (Rte_WriteHook_Ap_SrlComInput_PAWheelCriteriaMet_Cnt_lgc_Start)
#  undef Rte_WriteHook_Ap_SrlComInput_PAWheelCriteriaMet_Cnt_lgc_Start
FUNC(void, RTE_APPL_CODE) Rte_WriteHook_Ap_SrlComInput_PAWheelCriteriaMet_Cnt_lgc_Start(Boolean data);
# else
#  define Rte_WriteHook_Ap_SrlComInput_PAWheelCriteriaMet_Cnt_lgc_Start(arg1) ((void)(0))
# endif /* Rte_WriteHook_Ap_SrlComInput_PAWheelCriteriaMet_Cnt_lgc_Start */

# if defined (Rte_WriteHook_Ap_SrlComInput_PAWhlDirRLStat_Cnt_u08_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_WriteHook_Ap_SrlComInput_PAWhlDirRLStat_Cnt_u08_Return
# endif
# if defined (Rte_WriteHook_Ap_SrlComInput_PAWhlDirRLStat_Cnt_u08_Return)
#  undef Rte_WriteHook_Ap_SrlComInput_PAWhlDirRLStat_Cnt_u08_Return
FUNC(void, RTE_APPL_CODE) Rte_WriteHook_Ap_SrlComInput_PAWhlDirRLStat_Cnt_u08_Return(UInt8 data);
# else
#  define Rte_WriteHook_Ap_SrlComInput_PAWhlDirRLStat_Cnt_u08_Return(arg1) ((void)(0))
# endif /* Rte_WriteHook_Ap_SrlComInput_PAWhlDirRLStat_Cnt_u08_Return */

# if defined (Rte_WriteHook_Ap_SrlComInput_PAWhlDirRLStat_Cnt_u08_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_WriteHook_Ap_SrlComInput_PAWhlDirRLStat_Cnt_u08_Start
# endif
# if defined (Rte_WriteHook_Ap_SrlComInput_PAWhlDirRLStat_Cnt_u08_Start)
#  undef Rte_WriteHook_Ap_SrlComInput_PAWhlDirRLStat_Cnt_u08_Start
FUNC(void, RTE_APPL_CODE) Rte_WriteHook_Ap_SrlComInput_PAWhlDirRLStat_Cnt_u08_Start(UInt8 data);
# else
#  define Rte_WriteHook_Ap_SrlComInput_PAWhlDirRLStat_Cnt_u08_Start(arg1) ((void)(0))
# endif /* Rte_WriteHook_Ap_SrlComInput_PAWhlDirRLStat_Cnt_u08_Start */

# if defined (Rte_WriteHook_Ap_SrlComInput_PAWhlDirRRStat_Cnt_u08_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_WriteHook_Ap_SrlComInput_PAWhlDirRRStat_Cnt_u08_Return
# endif
# if defined (Rte_WriteHook_Ap_SrlComInput_PAWhlDirRRStat_Cnt_u08_Return)
#  undef Rte_WriteHook_Ap_SrlComInput_PAWhlDirRRStat_Cnt_u08_Return
FUNC(void, RTE_APPL_CODE) Rte_WriteHook_Ap_SrlComInput_PAWhlDirRRStat_Cnt_u08_Return(UInt8 data);
# else
#  define Rte_WriteHook_Ap_SrlComInput_PAWhlDirRRStat_Cnt_u08_Return(arg1) ((void)(0))
# endif /* Rte_WriteHook_Ap_SrlComInput_PAWhlDirRRStat_Cnt_u08_Return */

# if defined (Rte_WriteHook_Ap_SrlComInput_PAWhlDirRRStat_Cnt_u08_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_WriteHook_Ap_SrlComInput_PAWhlDirRRStat_Cnt_u08_Start
# endif
# if defined (Rte_WriteHook_Ap_SrlComInput_PAWhlDirRRStat_Cnt_u08_Start)
#  undef Rte_WriteHook_Ap_SrlComInput_PAWhlDirRRStat_Cnt_u08_Start
FUNC(void, RTE_APPL_CODE) Rte_WriteHook_Ap_SrlComInput_PAWhlDirRRStat_Cnt_u08_Start(UInt8 data);
# else
#  define Rte_WriteHook_Ap_SrlComInput_PAWhlDirRRStat_Cnt_u08_Start(arg1) ((void)(0))
# endif /* Rte_WriteHook_Ap_SrlComInput_PAWhlDirRRStat_Cnt_u08_Start */

# if defined (Rte_WriteHook_Ap_SrlComInput_PAWhlPlsCntRLValid_Cnt_lgc_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_WriteHook_Ap_SrlComInput_PAWhlPlsCntRLValid_Cnt_lgc_Return
# endif
# if defined (Rte_WriteHook_Ap_SrlComInput_PAWhlPlsCntRLValid_Cnt_lgc_Return)
#  undef Rte_WriteHook_Ap_SrlComInput_PAWhlPlsCntRLValid_Cnt_lgc_Return
FUNC(void, RTE_APPL_CODE) Rte_WriteHook_Ap_SrlComInput_PAWhlPlsCntRLValid_Cnt_lgc_Return(Boolean data);
# else
#  define Rte_WriteHook_Ap_SrlComInput_PAWhlPlsCntRLValid_Cnt_lgc_Return(arg1) ((void)(0))
# endif /* Rte_WriteHook_Ap_SrlComInput_PAWhlPlsCntRLValid_Cnt_lgc_Return */

# if defined (Rte_WriteHook_Ap_SrlComInput_PAWhlPlsCntRLValid_Cnt_lgc_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_WriteHook_Ap_SrlComInput_PAWhlPlsCntRLValid_Cnt_lgc_Start
# endif
# if defined (Rte_WriteHook_Ap_SrlComInput_PAWhlPlsCntRLValid_Cnt_lgc_Start)
#  undef Rte_WriteHook_Ap_SrlComInput_PAWhlPlsCntRLValid_Cnt_lgc_Start
FUNC(void, RTE_APPL_CODE) Rte_WriteHook_Ap_SrlComInput_PAWhlPlsCntRLValid_Cnt_lgc_Start(Boolean data);
# else
#  define Rte_WriteHook_Ap_SrlComInput_PAWhlPlsCntRLValid_Cnt_lgc_Start(arg1) ((void)(0))
# endif /* Rte_WriteHook_Ap_SrlComInput_PAWhlPlsCntRLValid_Cnt_lgc_Start */

# if defined (Rte_WriteHook_Ap_SrlComInput_PAWhlPlsCntRRValid_Cnt_lgc_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_WriteHook_Ap_SrlComInput_PAWhlPlsCntRRValid_Cnt_lgc_Return
# endif
# if defined (Rte_WriteHook_Ap_SrlComInput_PAWhlPlsCntRRValid_Cnt_lgc_Return)
#  undef Rte_WriteHook_Ap_SrlComInput_PAWhlPlsCntRRValid_Cnt_lgc_Return
FUNC(void, RTE_APPL_CODE) Rte_WriteHook_Ap_SrlComInput_PAWhlPlsCntRRValid_Cnt_lgc_Return(Boolean data);
# else
#  define Rte_WriteHook_Ap_SrlComInput_PAWhlPlsCntRRValid_Cnt_lgc_Return(arg1) ((void)(0))
# endif /* Rte_WriteHook_Ap_SrlComInput_PAWhlPlsCntRRValid_Cnt_lgc_Return */

# if defined (Rte_WriteHook_Ap_SrlComInput_PAWhlPlsCntRRValid_Cnt_lgc_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_WriteHook_Ap_SrlComInput_PAWhlPlsCntRRValid_Cnt_lgc_Start
# endif
# if defined (Rte_WriteHook_Ap_SrlComInput_PAWhlPlsCntRRValid_Cnt_lgc_Start)
#  undef Rte_WriteHook_Ap_SrlComInput_PAWhlPlsCntRRValid_Cnt_lgc_Start
FUNC(void, RTE_APPL_CODE) Rte_WriteHook_Ap_SrlComInput_PAWhlPlsCntRRValid_Cnt_lgc_Start(Boolean data);
# else
#  define Rte_WriteHook_Ap_SrlComInput_PAWhlPlsCntRRValid_Cnt_lgc_Start(arg1) ((void)(0))
# endif /* Rte_WriteHook_Ap_SrlComInput_PAWhlPlsCntRRValid_Cnt_lgc_Start */

# if defined (Rte_WriteHook_Ap_SrlComInput_PrevHaLFEnableRqst_Cnt_lgc_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_WriteHook_Ap_SrlComInput_PrevHaLFEnableRqst_Cnt_lgc_Return
# endif
# if defined (Rte_WriteHook_Ap_SrlComInput_PrevHaLFEnableRqst_Cnt_lgc_Return)
#  undef Rte_WriteHook_Ap_SrlComInput_PrevHaLFEnableRqst_Cnt_lgc_Return
FUNC(void, RTE_APPL_CODE) Rte_WriteHook_Ap_SrlComInput_PrevHaLFEnableRqst_Cnt_lgc_Return(Boolean data);
# else
#  define Rte_WriteHook_Ap_SrlComInput_PrevHaLFEnableRqst_Cnt_lgc_Return(arg1) ((void)(0))
# endif /* Rte_WriteHook_Ap_SrlComInput_PrevHaLFEnableRqst_Cnt_lgc_Return */

# if defined (Rte_WriteHook_Ap_SrlComInput_PrevHaLFEnableRqst_Cnt_lgc_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_WriteHook_Ap_SrlComInput_PrevHaLFEnableRqst_Cnt_lgc_Start
# endif
# if defined (Rte_WriteHook_Ap_SrlComInput_PrevHaLFEnableRqst_Cnt_lgc_Start)
#  undef Rte_WriteHook_Ap_SrlComInput_PrevHaLFEnableRqst_Cnt_lgc_Start
FUNC(void, RTE_APPL_CODE) Rte_WriteHook_Ap_SrlComInput_PrevHaLFEnableRqst_Cnt_lgc_Start(Boolean data);
# else
#  define Rte_WriteHook_Ap_SrlComInput_PrevHaLFEnableRqst_Cnt_lgc_Start(arg1) ((void)(0))
# endif /* Rte_WriteHook_Ap_SrlComInput_PrevHaLFEnableRqst_Cnt_lgc_Start */

# if defined (Rte_WriteHook_Ap_SrlComInput_PrevHaLFTrqOvCmdRqst_MtrNm_f32_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_WriteHook_Ap_SrlComInput_PrevHaLFTrqOvCmdRqst_MtrNm_f32_Return
# endif
# if defined (Rte_WriteHook_Ap_SrlComInput_PrevHaLFTrqOvCmdRqst_MtrNm_f32_Return)
#  undef Rte_WriteHook_Ap_SrlComInput_PrevHaLFTrqOvCmdRqst_MtrNm_f32_Return
FUNC(void, RTE_APPL_CODE) Rte_WriteHook_Ap_SrlComInput_PrevHaLFTrqOvCmdRqst_MtrNm_f32_Return(Float data);
# else
#  define Rte_WriteHook_Ap_SrlComInput_PrevHaLFTrqOvCmdRqst_MtrNm_f32_Return(arg1) ((void)(0))
# endif /* Rte_WriteHook_Ap_SrlComInput_PrevHaLFTrqOvCmdRqst_MtrNm_f32_Return */

# if defined (Rte_WriteHook_Ap_SrlComInput_PrevHaLFTrqOvCmdRqst_MtrNm_f32_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_WriteHook_Ap_SrlComInput_PrevHaLFTrqOvCmdRqst_MtrNm_f32_Start
# endif
# if defined (Rte_WriteHook_Ap_SrlComInput_PrevHaLFTrqOvCmdRqst_MtrNm_f32_Start)
#  undef Rte_WriteHook_Ap_SrlComInput_PrevHaLFTrqOvCmdRqst_MtrNm_f32_Start
FUNC(void, RTE_APPL_CODE) Rte_WriteHook_Ap_SrlComInput_PrevHaLFTrqOvCmdRqst_MtrNm_f32_Start(Float data);
# else
#  define Rte_WriteHook_Ap_SrlComInput_PrevHaLFTrqOvCmdRqst_MtrNm_f32_Start(arg1) ((void)(0))
# endif /* Rte_WriteHook_Ap_SrlComInput_PrevHaLFTrqOvCmdRqst_MtrNm_f32_Start */

# if defined (Rte_WriteHook_Ap_SrlComInput_PrkAsstFuncPresent_Cnt_lgc_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_WriteHook_Ap_SrlComInput_PrkAsstFuncPresent_Cnt_lgc_Return
# endif
# if defined (Rte_WriteHook_Ap_SrlComInput_PrkAsstFuncPresent_Cnt_lgc_Return)
#  undef Rte_WriteHook_Ap_SrlComInput_PrkAsstFuncPresent_Cnt_lgc_Return
FUNC(void, RTE_APPL_CODE) Rte_WriteHook_Ap_SrlComInput_PrkAsstFuncPresent_Cnt_lgc_Return(Boolean data);
# else
#  define Rte_WriteHook_Ap_SrlComInput_PrkAsstFuncPresent_Cnt_lgc_Return(arg1) ((void)(0))
# endif /* Rte_WriteHook_Ap_SrlComInput_PrkAsstFuncPresent_Cnt_lgc_Return */

# if defined (Rte_WriteHook_Ap_SrlComInput_PrkAsstFuncPresent_Cnt_lgc_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_WriteHook_Ap_SrlComInput_PrkAsstFuncPresent_Cnt_lgc_Start
# endif
# if defined (Rte_WriteHook_Ap_SrlComInput_PrkAsstFuncPresent_Cnt_lgc_Start)
#  undef Rte_WriteHook_Ap_SrlComInput_PrkAsstFuncPresent_Cnt_lgc_Start
FUNC(void, RTE_APPL_CODE) Rte_WriteHook_Ap_SrlComInput_PrkAsstFuncPresent_Cnt_lgc_Start(Boolean data);
# else
#  define Rte_WriteHook_Ap_SrlComInput_PrkAsstFuncPresent_Cnt_lgc_Start(arg1) ((void)(0))
# endif /* Rte_WriteHook_Ap_SrlComInput_PrkAsstFuncPresent_Cnt_lgc_Start */

# if defined (Rte_WriteHook_Ap_SrlComInput_SpStPrsnt_Cnt_lgc_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_WriteHook_Ap_SrlComInput_SpStPrsnt_Cnt_lgc_Return
# endif
# if defined (Rte_WriteHook_Ap_SrlComInput_SpStPrsnt_Cnt_lgc_Return)
#  undef Rte_WriteHook_Ap_SrlComInput_SpStPrsnt_Cnt_lgc_Return
FUNC(void, RTE_APPL_CODE) Rte_WriteHook_Ap_SrlComInput_SpStPrsnt_Cnt_lgc_Return(Boolean data);
# else
#  define Rte_WriteHook_Ap_SrlComInput_SpStPrsnt_Cnt_lgc_Return(arg1) ((void)(0))
# endif /* Rte_WriteHook_Ap_SrlComInput_SpStPrsnt_Cnt_lgc_Return */

# if defined (Rte_WriteHook_Ap_SrlComInput_SpStPrsnt_Cnt_lgc_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_WriteHook_Ap_SrlComInput_SpStPrsnt_Cnt_lgc_Start
# endif
# if defined (Rte_WriteHook_Ap_SrlComInput_SpStPrsnt_Cnt_lgc_Start)
#  undef Rte_WriteHook_Ap_SrlComInput_SpStPrsnt_Cnt_lgc_Start
FUNC(void, RTE_APPL_CODE) Rte_WriteHook_Ap_SrlComInput_SpStPrsnt_Cnt_lgc_Start(Boolean data);
# else
#  define Rte_WriteHook_Ap_SrlComInput_SpStPrsnt_Cnt_lgc_Start(arg1) ((void)(0))
# endif /* Rte_WriteHook_Ap_SrlComInput_SpStPrsnt_Cnt_lgc_Start */

# if defined (Rte_WriteHook_Ap_SrlComInput_SrlComLWhlSpdVld_Cnt_lgc_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_WriteHook_Ap_SrlComInput_SrlComLWhlSpdVld_Cnt_lgc_Return
# endif
# if defined (Rte_WriteHook_Ap_SrlComInput_SrlComLWhlSpdVld_Cnt_lgc_Return)
#  undef Rte_WriteHook_Ap_SrlComInput_SrlComLWhlSpdVld_Cnt_lgc_Return
FUNC(void, RTE_APPL_CODE) Rte_WriteHook_Ap_SrlComInput_SrlComLWhlSpdVld_Cnt_lgc_Return(Boolean data);
# else
#  define Rte_WriteHook_Ap_SrlComInput_SrlComLWhlSpdVld_Cnt_lgc_Return(arg1) ((void)(0))
# endif /* Rte_WriteHook_Ap_SrlComInput_SrlComLWhlSpdVld_Cnt_lgc_Return */

# if defined (Rte_WriteHook_Ap_SrlComInput_SrlComLWhlSpdVld_Cnt_lgc_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_WriteHook_Ap_SrlComInput_SrlComLWhlSpdVld_Cnt_lgc_Start
# endif
# if defined (Rte_WriteHook_Ap_SrlComInput_SrlComLWhlSpdVld_Cnt_lgc_Start)
#  undef Rte_WriteHook_Ap_SrlComInput_SrlComLWhlSpdVld_Cnt_lgc_Start
FUNC(void, RTE_APPL_CODE) Rte_WriteHook_Ap_SrlComInput_SrlComLWhlSpdVld_Cnt_lgc_Start(Boolean data);
# else
#  define Rte_WriteHook_Ap_SrlComInput_SrlComLWhlSpdVld_Cnt_lgc_Start(arg1) ((void)(0))
# endif /* Rte_WriteHook_Ap_SrlComInput_SrlComLWhlSpdVld_Cnt_lgc_Start */

# if defined (Rte_WriteHook_Ap_SrlComInput_SrlComLWhlSpd_Hz_f32_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_WriteHook_Ap_SrlComInput_SrlComLWhlSpd_Hz_f32_Return
# endif
# if defined (Rte_WriteHook_Ap_SrlComInput_SrlComLWhlSpd_Hz_f32_Return)
#  undef Rte_WriteHook_Ap_SrlComInput_SrlComLWhlSpd_Hz_f32_Return
FUNC(void, RTE_APPL_CODE) Rte_WriteHook_Ap_SrlComInput_SrlComLWhlSpd_Hz_f32_Return(Float data);
# else
#  define Rte_WriteHook_Ap_SrlComInput_SrlComLWhlSpd_Hz_f32_Return(arg1) ((void)(0))
# endif /* Rte_WriteHook_Ap_SrlComInput_SrlComLWhlSpd_Hz_f32_Return */

# if defined (Rte_WriteHook_Ap_SrlComInput_SrlComLWhlSpd_Hz_f32_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_WriteHook_Ap_SrlComInput_SrlComLWhlSpd_Hz_f32_Start
# endif
# if defined (Rte_WriteHook_Ap_SrlComInput_SrlComLWhlSpd_Hz_f32_Start)
#  undef Rte_WriteHook_Ap_SrlComInput_SrlComLWhlSpd_Hz_f32_Start
FUNC(void, RTE_APPL_CODE) Rte_WriteHook_Ap_SrlComInput_SrlComLWhlSpd_Hz_f32_Start(Float data);
# else
#  define Rte_WriteHook_Ap_SrlComInput_SrlComLWhlSpd_Hz_f32_Start(arg1) ((void)(0))
# endif /* Rte_WriteHook_Ap_SrlComInput_SrlComLWhlSpd_Hz_f32_Start */

# if defined (Rte_WriteHook_Ap_SrlComInput_SrlComRWhlSpdVld_Cnt_lgc_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_WriteHook_Ap_SrlComInput_SrlComRWhlSpdVld_Cnt_lgc_Return
# endif
# if defined (Rte_WriteHook_Ap_SrlComInput_SrlComRWhlSpdVld_Cnt_lgc_Return)
#  undef Rte_WriteHook_Ap_SrlComInput_SrlComRWhlSpdVld_Cnt_lgc_Return
FUNC(void, RTE_APPL_CODE) Rte_WriteHook_Ap_SrlComInput_SrlComRWhlSpdVld_Cnt_lgc_Return(Boolean data);
# else
#  define Rte_WriteHook_Ap_SrlComInput_SrlComRWhlSpdVld_Cnt_lgc_Return(arg1) ((void)(0))
# endif /* Rte_WriteHook_Ap_SrlComInput_SrlComRWhlSpdVld_Cnt_lgc_Return */

# if defined (Rte_WriteHook_Ap_SrlComInput_SrlComRWhlSpdVld_Cnt_lgc_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_WriteHook_Ap_SrlComInput_SrlComRWhlSpdVld_Cnt_lgc_Start
# endif
# if defined (Rte_WriteHook_Ap_SrlComInput_SrlComRWhlSpdVld_Cnt_lgc_Start)
#  undef Rte_WriteHook_Ap_SrlComInput_SrlComRWhlSpdVld_Cnt_lgc_Start
FUNC(void, RTE_APPL_CODE) Rte_WriteHook_Ap_SrlComInput_SrlComRWhlSpdVld_Cnt_lgc_Start(Boolean data);
# else
#  define Rte_WriteHook_Ap_SrlComInput_SrlComRWhlSpdVld_Cnt_lgc_Start(arg1) ((void)(0))
# endif /* Rte_WriteHook_Ap_SrlComInput_SrlComRWhlSpdVld_Cnt_lgc_Start */

# if defined (Rte_WriteHook_Ap_SrlComInput_SrlComRWhlSpd_Hz_f32_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_WriteHook_Ap_SrlComInput_SrlComRWhlSpd_Hz_f32_Return
# endif
# if defined (Rte_WriteHook_Ap_SrlComInput_SrlComRWhlSpd_Hz_f32_Return)
#  undef Rte_WriteHook_Ap_SrlComInput_SrlComRWhlSpd_Hz_f32_Return
FUNC(void, RTE_APPL_CODE) Rte_WriteHook_Ap_SrlComInput_SrlComRWhlSpd_Hz_f32_Return(Float data);
# else
#  define Rte_WriteHook_Ap_SrlComInput_SrlComRWhlSpd_Hz_f32_Return(arg1) ((void)(0))
# endif /* Rte_WriteHook_Ap_SrlComInput_SrlComRWhlSpd_Hz_f32_Return */

# if defined (Rte_WriteHook_Ap_SrlComInput_SrlComRWhlSpd_Hz_f32_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_WriteHook_Ap_SrlComInput_SrlComRWhlSpd_Hz_f32_Start
# endif
# if defined (Rte_WriteHook_Ap_SrlComInput_SrlComRWhlSpd_Hz_f32_Start)
#  undef Rte_WriteHook_Ap_SrlComInput_SrlComRWhlSpd_Hz_f32_Start
FUNC(void, RTE_APPL_CODE) Rte_WriteHook_Ap_SrlComInput_SrlComRWhlSpd_Hz_f32_Start(Float data);
# else
#  define Rte_WriteHook_Ap_SrlComInput_SrlComRWhlSpd_Hz_f32_Start(arg1) ((void)(0))
# endif /* Rte_WriteHook_Ap_SrlComInput_SrlComRWhlSpd_Hz_f32_Start */

# if defined (Rte_WriteHook_Ap_SrlComInput_SrlComVehSpdValid_Cnt_lgc_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_WriteHook_Ap_SrlComInput_SrlComVehSpdValid_Cnt_lgc_Return
# endif
# if defined (Rte_WriteHook_Ap_SrlComInput_SrlComVehSpdValid_Cnt_lgc_Return)
#  undef Rte_WriteHook_Ap_SrlComInput_SrlComVehSpdValid_Cnt_lgc_Return
FUNC(void, RTE_APPL_CODE) Rte_WriteHook_Ap_SrlComInput_SrlComVehSpdValid_Cnt_lgc_Return(Boolean data);
# else
#  define Rte_WriteHook_Ap_SrlComInput_SrlComVehSpdValid_Cnt_lgc_Return(arg1) ((void)(0))
# endif /* Rte_WriteHook_Ap_SrlComInput_SrlComVehSpdValid_Cnt_lgc_Return */

# if defined (Rte_WriteHook_Ap_SrlComInput_SrlComVehSpdValid_Cnt_lgc_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_WriteHook_Ap_SrlComInput_SrlComVehSpdValid_Cnt_lgc_Start
# endif
# if defined (Rte_WriteHook_Ap_SrlComInput_SrlComVehSpdValid_Cnt_lgc_Start)
#  undef Rte_WriteHook_Ap_SrlComInput_SrlComVehSpdValid_Cnt_lgc_Start
FUNC(void, RTE_APPL_CODE) Rte_WriteHook_Ap_SrlComInput_SrlComVehSpdValid_Cnt_lgc_Start(Boolean data);
# else
#  define Rte_WriteHook_Ap_SrlComInput_SrlComVehSpdValid_Cnt_lgc_Start(arg1) ((void)(0))
# endif /* Rte_WriteHook_Ap_SrlComInput_SrlComVehSpdValid_Cnt_lgc_Start */

# if defined (Rte_WriteHook_Ap_SrlComInput_SrlComVehSpd_Kph_f32_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_WriteHook_Ap_SrlComInput_SrlComVehSpd_Kph_f32_Return
# endif
# if defined (Rte_WriteHook_Ap_SrlComInput_SrlComVehSpd_Kph_f32_Return)
#  undef Rte_WriteHook_Ap_SrlComInput_SrlComVehSpd_Kph_f32_Return
FUNC(void, RTE_APPL_CODE) Rte_WriteHook_Ap_SrlComInput_SrlComVehSpd_Kph_f32_Return(Float data);
# else
#  define Rte_WriteHook_Ap_SrlComInput_SrlComVehSpd_Kph_f32_Return(arg1) ((void)(0))
# endif /* Rte_WriteHook_Ap_SrlComInput_SrlComVehSpd_Kph_f32_Return */

# if defined (Rte_WriteHook_Ap_SrlComInput_SrlComVehSpd_Kph_f32_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_WriteHook_Ap_SrlComInput_SrlComVehSpd_Kph_f32_Start
# endif
# if defined (Rte_WriteHook_Ap_SrlComInput_SrlComVehSpd_Kph_f32_Start)
#  undef Rte_WriteHook_Ap_SrlComInput_SrlComVehSpd_Kph_f32_Start
FUNC(void, RTE_APPL_CODE) Rte_WriteHook_Ap_SrlComInput_SrlComVehSpd_Kph_f32_Start(Float data);
# else
#  define Rte_WriteHook_Ap_SrlComInput_SrlComVehSpd_Kph_f32_Start(arg1) ((void)(0))
# endif /* Rte_WriteHook_Ap_SrlComInput_SrlComVehSpd_Kph_f32_Start */

# if defined (Rte_WriteHook_Ap_SrlComInput_StrgWhlAnglValid_Cnt_lgc_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_WriteHook_Ap_SrlComInput_StrgWhlAnglValid_Cnt_lgc_Return
# endif
# if defined (Rte_WriteHook_Ap_SrlComInput_StrgWhlAnglValid_Cnt_lgc_Return)
#  undef Rte_WriteHook_Ap_SrlComInput_StrgWhlAnglValid_Cnt_lgc_Return
FUNC(void, RTE_APPL_CODE) Rte_WriteHook_Ap_SrlComInput_StrgWhlAnglValid_Cnt_lgc_Return(Boolean data);
# else
#  define Rte_WriteHook_Ap_SrlComInput_StrgWhlAnglValid_Cnt_lgc_Return(arg1) ((void)(0))
# endif /* Rte_WriteHook_Ap_SrlComInput_StrgWhlAnglValid_Cnt_lgc_Return */

# if defined (Rte_WriteHook_Ap_SrlComInput_StrgWhlAnglValid_Cnt_lgc_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_WriteHook_Ap_SrlComInput_StrgWhlAnglValid_Cnt_lgc_Start
# endif
# if defined (Rte_WriteHook_Ap_SrlComInput_StrgWhlAnglValid_Cnt_lgc_Start)
#  undef Rte_WriteHook_Ap_SrlComInput_StrgWhlAnglValid_Cnt_lgc_Start
FUNC(void, RTE_APPL_CODE) Rte_WriteHook_Ap_SrlComInput_StrgWhlAnglValid_Cnt_lgc_Start(Boolean data);
# else
#  define Rte_WriteHook_Ap_SrlComInput_StrgWhlAnglValid_Cnt_lgc_Start(arg1) ((void)(0))
# endif /* Rte_WriteHook_Ap_SrlComInput_StrgWhlAnglValid_Cnt_lgc_Start */

# if defined (Rte_WriteHook_Ap_SrlComInput_StrgWhlAngl_HwDeg_f32_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_WriteHook_Ap_SrlComInput_StrgWhlAngl_HwDeg_f32_Return
# endif
# if defined (Rte_WriteHook_Ap_SrlComInput_StrgWhlAngl_HwDeg_f32_Return)
#  undef Rte_WriteHook_Ap_SrlComInput_StrgWhlAngl_HwDeg_f32_Return
FUNC(void, RTE_APPL_CODE) Rte_WriteHook_Ap_SrlComInput_StrgWhlAngl_HwDeg_f32_Return(Float data);
# else
#  define Rte_WriteHook_Ap_SrlComInput_StrgWhlAngl_HwDeg_f32_Return(arg1) ((void)(0))
# endif /* Rte_WriteHook_Ap_SrlComInput_StrgWhlAngl_HwDeg_f32_Return */

# if defined (Rte_WriteHook_Ap_SrlComInput_StrgWhlAngl_HwDeg_f32_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_WriteHook_Ap_SrlComInput_StrgWhlAngl_HwDeg_f32_Start
# endif
# if defined (Rte_WriteHook_Ap_SrlComInput_StrgWhlAngl_HwDeg_f32_Start)
#  undef Rte_WriteHook_Ap_SrlComInput_StrgWhlAngl_HwDeg_f32_Start
FUNC(void, RTE_APPL_CODE) Rte_WriteHook_Ap_SrlComInput_StrgWhlAngl_HwDeg_f32_Start(Float data);
# else
#  define Rte_WriteHook_Ap_SrlComInput_StrgWhlAngl_HwDeg_f32_Start(arg1) ((void)(0))
# endif /* Rte_WriteHook_Ap_SrlComInput_StrgWhlAngl_HwDeg_f32_Start */

# if defined (Rte_WriteHook_Ap_SrlComInput_TrqOvReverseGearEngage_Cnt_lgc_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_WriteHook_Ap_SrlComInput_TrqOvReverseGearEngage_Cnt_lgc_Return
# endif
# if defined (Rte_WriteHook_Ap_SrlComInput_TrqOvReverseGearEngage_Cnt_lgc_Return)
#  undef Rte_WriteHook_Ap_SrlComInput_TrqOvReverseGearEngage_Cnt_lgc_Return
FUNC(void, RTE_APPL_CODE) Rte_WriteHook_Ap_SrlComInput_TrqOvReverseGearEngage_Cnt_lgc_Return(Boolean data);
# else
#  define Rte_WriteHook_Ap_SrlComInput_TrqOvReverseGearEngage_Cnt_lgc_Return(arg1) ((void)(0))
# endif /* Rte_WriteHook_Ap_SrlComInput_TrqOvReverseGearEngage_Cnt_lgc_Return */

# if defined (Rte_WriteHook_Ap_SrlComInput_TrqOvReverseGearEngage_Cnt_lgc_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_WriteHook_Ap_SrlComInput_TrqOvReverseGearEngage_Cnt_lgc_Start
# endif
# if defined (Rte_WriteHook_Ap_SrlComInput_TrqOvReverseGearEngage_Cnt_lgc_Start)
#  undef Rte_WriteHook_Ap_SrlComInput_TrqOvReverseGearEngage_Cnt_lgc_Start
FUNC(void, RTE_APPL_CODE) Rte_WriteHook_Ap_SrlComInput_TrqOvReverseGearEngage_Cnt_lgc_Start(Boolean data);
# else
#  define Rte_WriteHook_Ap_SrlComInput_TrqOvReverseGearEngage_Cnt_lgc_Start(arg1) ((void)(0))
# endif /* Rte_WriteHook_Ap_SrlComInput_TrqOvReverseGearEngage_Cnt_lgc_Start */

# if defined (Rte_WriteHook_Ap_SrlComInput_VCBodyStyle_Cnt_u08_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_WriteHook_Ap_SrlComInput_VCBodyStyle_Cnt_u08_Return
# endif
# if defined (Rte_WriteHook_Ap_SrlComInput_VCBodyStyle_Cnt_u08_Return)
#  undef Rte_WriteHook_Ap_SrlComInput_VCBodyStyle_Cnt_u08_Return
FUNC(void, RTE_APPL_CODE) Rte_WriteHook_Ap_SrlComInput_VCBodyStyle_Cnt_u08_Return(UInt8 data);
# else
#  define Rte_WriteHook_Ap_SrlComInput_VCBodyStyle_Cnt_u08_Return(arg1) ((void)(0))
# endif /* Rte_WriteHook_Ap_SrlComInput_VCBodyStyle_Cnt_u08_Return */

# if defined (Rte_WriteHook_Ap_SrlComInput_VCBodyStyle_Cnt_u08_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_WriteHook_Ap_SrlComInput_VCBodyStyle_Cnt_u08_Start
# endif
# if defined (Rte_WriteHook_Ap_SrlComInput_VCBodyStyle_Cnt_u08_Start)
#  undef Rte_WriteHook_Ap_SrlComInput_VCBodyStyle_Cnt_u08_Start
FUNC(void, RTE_APPL_CODE) Rte_WriteHook_Ap_SrlComInput_VCBodyStyle_Cnt_u08_Start(UInt8 data);
# else
#  define Rte_WriteHook_Ap_SrlComInput_VCBodyStyle_Cnt_u08_Start(arg1) ((void)(0))
# endif /* Rte_WriteHook_Ap_SrlComInput_VCBodyStyle_Cnt_u08_Start */

# if defined (Rte_WriteHook_Ap_SrlComInput_VCCountry_Cnt_u08_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_WriteHook_Ap_SrlComInput_VCCountry_Cnt_u08_Return
# endif
# if defined (Rte_WriteHook_Ap_SrlComInput_VCCountry_Cnt_u08_Return)
#  undef Rte_WriteHook_Ap_SrlComInput_VCCountry_Cnt_u08_Return
FUNC(void, RTE_APPL_CODE) Rte_WriteHook_Ap_SrlComInput_VCCountry_Cnt_u08_Return(UInt8 data);
# else
#  define Rte_WriteHook_Ap_SrlComInput_VCCountry_Cnt_u08_Return(arg1) ((void)(0))
# endif /* Rte_WriteHook_Ap_SrlComInput_VCCountry_Cnt_u08_Return */

# if defined (Rte_WriteHook_Ap_SrlComInput_VCCountry_Cnt_u08_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_WriteHook_Ap_SrlComInput_VCCountry_Cnt_u08_Start
# endif
# if defined (Rte_WriteHook_Ap_SrlComInput_VCCountry_Cnt_u08_Start)
#  undef Rte_WriteHook_Ap_SrlComInput_VCCountry_Cnt_u08_Start
FUNC(void, RTE_APPL_CODE) Rte_WriteHook_Ap_SrlComInput_VCCountry_Cnt_u08_Start(UInt8 data);
# else
#  define Rte_WriteHook_Ap_SrlComInput_VCCountry_Cnt_u08_Start(arg1) ((void)(0))
# endif /* Rte_WriteHook_Ap_SrlComInput_VCCountry_Cnt_u08_Start */

# if defined (Rte_WriteHook_Ap_SrlComInput_VCModelYear_Cnt_u08_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_WriteHook_Ap_SrlComInput_VCModelYear_Cnt_u08_Return
# endif
# if defined (Rte_WriteHook_Ap_SrlComInput_VCModelYear_Cnt_u08_Return)
#  undef Rte_WriteHook_Ap_SrlComInput_VCModelYear_Cnt_u08_Return
FUNC(void, RTE_APPL_CODE) Rte_WriteHook_Ap_SrlComInput_VCModelYear_Cnt_u08_Return(UInt8 data);
# else
#  define Rte_WriteHook_Ap_SrlComInput_VCModelYear_Cnt_u08_Return(arg1) ((void)(0))
# endif /* Rte_WriteHook_Ap_SrlComInput_VCModelYear_Cnt_u08_Return */

# if defined (Rte_WriteHook_Ap_SrlComInput_VCModelYear_Cnt_u08_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_WriteHook_Ap_SrlComInput_VCModelYear_Cnt_u08_Start
# endif
# if defined (Rte_WriteHook_Ap_SrlComInput_VCModelYear_Cnt_u08_Start)
#  undef Rte_WriteHook_Ap_SrlComInput_VCModelYear_Cnt_u08_Start
FUNC(void, RTE_APPL_CODE) Rte_WriteHook_Ap_SrlComInput_VCModelYear_Cnt_u08_Start(UInt8 data);
# else
#  define Rte_WriteHook_Ap_SrlComInput_VCModelYear_Cnt_u08_Start(arg1) ((void)(0))
# endif /* Rte_WriteHook_Ap_SrlComInput_VCModelYear_Cnt_u08_Start */

# if defined (Rte_WriteHook_Ap_SrlComInput_VCVehLine_Cnt_u08_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_WriteHook_Ap_SrlComInput_VCVehLine_Cnt_u08_Return
# endif
# if defined (Rte_WriteHook_Ap_SrlComInput_VCVehLine_Cnt_u08_Return)
#  undef Rte_WriteHook_Ap_SrlComInput_VCVehLine_Cnt_u08_Return
FUNC(void, RTE_APPL_CODE) Rte_WriteHook_Ap_SrlComInput_VCVehLine_Cnt_u08_Return(UInt8 data);
# else
#  define Rte_WriteHook_Ap_SrlComInput_VCVehLine_Cnt_u08_Return(arg1) ((void)(0))
# endif /* Rte_WriteHook_Ap_SrlComInput_VCVehLine_Cnt_u08_Return */

# if defined (Rte_WriteHook_Ap_SrlComInput_VCVehLine_Cnt_u08_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_WriteHook_Ap_SrlComInput_VCVehLine_Cnt_u08_Start
# endif
# if defined (Rte_WriteHook_Ap_SrlComInput_VCVehLine_Cnt_u08_Start)
#  undef Rte_WriteHook_Ap_SrlComInput_VCVehLine_Cnt_u08_Start
FUNC(void, RTE_APPL_CODE) Rte_WriteHook_Ap_SrlComInput_VCVehLine_Cnt_u08_Start(UInt8 data);
# else
#  define Rte_WriteHook_Ap_SrlComInput_VCVehLine_Cnt_u08_Start(arg1) ((void)(0))
# endif /* Rte_WriteHook_Ap_SrlComInput_VCVehLine_Cnt_u08_Start */

# if defined (Rte_WriteHook_Ap_SrlComInput_VehAccelX_KphpS_f32_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_WriteHook_Ap_SrlComInput_VehAccelX_KphpS_f32_Return
# endif
# if defined (Rte_WriteHook_Ap_SrlComInput_VehAccelX_KphpS_f32_Return)
#  undef Rte_WriteHook_Ap_SrlComInput_VehAccelX_KphpS_f32_Return
FUNC(void, RTE_APPL_CODE) Rte_WriteHook_Ap_SrlComInput_VehAccelX_KphpS_f32_Return(Float data);
# else
#  define Rte_WriteHook_Ap_SrlComInput_VehAccelX_KphpS_f32_Return(arg1) ((void)(0))
# endif /* Rte_WriteHook_Ap_SrlComInput_VehAccelX_KphpS_f32_Return */

# if defined (Rte_WriteHook_Ap_SrlComInput_VehAccelX_KphpS_f32_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_WriteHook_Ap_SrlComInput_VehAccelX_KphpS_f32_Start
# endif
# if defined (Rte_WriteHook_Ap_SrlComInput_VehAccelX_KphpS_f32_Start)
#  undef Rte_WriteHook_Ap_SrlComInput_VehAccelX_KphpS_f32_Start
FUNC(void, RTE_APPL_CODE) Rte_WriteHook_Ap_SrlComInput_VehAccelX_KphpS_f32_Start(Float data);
# else
#  define Rte_WriteHook_Ap_SrlComInput_VehAccelX_KphpS_f32_Start(arg1) ((void)(0))
# endif /* Rte_WriteHook_Ap_SrlComInput_VehAccelX_KphpS_f32_Start */

# if defined (Rte_WriteHook_Ap_SrlComInput_VehAccel_KphpS_f32_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_WriteHook_Ap_SrlComInput_VehAccel_KphpS_f32_Return
# endif
# if defined (Rte_WriteHook_Ap_SrlComInput_VehAccel_KphpS_f32_Return)
#  undef Rte_WriteHook_Ap_SrlComInput_VehAccel_KphpS_f32_Return
FUNC(void, RTE_APPL_CODE) Rte_WriteHook_Ap_SrlComInput_VehAccel_KphpS_f32_Return(Float data);
# else
#  define Rte_WriteHook_Ap_SrlComInput_VehAccel_KphpS_f32_Return(arg1) ((void)(0))
# endif /* Rte_WriteHook_Ap_SrlComInput_VehAccel_KphpS_f32_Return */

# if defined (Rte_WriteHook_Ap_SrlComInput_VehAccel_KphpS_f32_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_WriteHook_Ap_SrlComInput_VehAccel_KphpS_f32_Start
# endif
# if defined (Rte_WriteHook_Ap_SrlComInput_VehAccel_KphpS_f32_Start)
#  undef Rte_WriteHook_Ap_SrlComInput_VehAccel_KphpS_f32_Start
FUNC(void, RTE_APPL_CODE) Rte_WriteHook_Ap_SrlComInput_VehAccel_KphpS_f32_Start(Float data);
# else
#  define Rte_WriteHook_Ap_SrlComInput_VehAccel_KphpS_f32_Start(arg1) ((void)(0))
# endif /* Rte_WriteHook_Ap_SrlComInput_VehAccel_KphpS_f32_Start */

# if defined (Rte_WriteHook_Sa_CmMtrCurr_CurrentGainSvc_Cnt_lgc_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_WriteHook_Sa_CmMtrCurr_CurrentGainSvc_Cnt_lgc_Return
# endif
# if defined (Rte_WriteHook_Sa_CmMtrCurr_CurrentGainSvc_Cnt_lgc_Return)
#  undef Rte_WriteHook_Sa_CmMtrCurr_CurrentGainSvc_Cnt_lgc_Return
FUNC(void, RTE_APPL_CODE) Rte_WriteHook_Sa_CmMtrCurr_CurrentGainSvc_Cnt_lgc_Return(Boolean data);
# else
#  define Rte_WriteHook_Sa_CmMtrCurr_CurrentGainSvc_Cnt_lgc_Return(arg1) ((void)(0))
# endif /* Rte_WriteHook_Sa_CmMtrCurr_CurrentGainSvc_Cnt_lgc_Return */

# if defined (Rte_WriteHook_Sa_CmMtrCurr_CurrentGainSvc_Cnt_lgc_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_WriteHook_Sa_CmMtrCurr_CurrentGainSvc_Cnt_lgc_Start
# endif
# if defined (Rte_WriteHook_Sa_CmMtrCurr_CurrentGainSvc_Cnt_lgc_Start)
#  undef Rte_WriteHook_Sa_CmMtrCurr_CurrentGainSvc_Cnt_lgc_Start
FUNC(void, RTE_APPL_CODE) Rte_WriteHook_Sa_CmMtrCurr_CurrentGainSvc_Cnt_lgc_Start(Boolean data);
# else
#  define Rte_WriteHook_Sa_CmMtrCurr_CurrentGainSvc_Cnt_lgc_Start(arg1) ((void)(0))
# endif /* Rte_WriteHook_Sa_CmMtrCurr_CurrentGainSvc_Cnt_lgc_Start */

# if defined (Rte_WriteHook_Sa_HwTrq_HwTrqScaleVal_VoltsPerDeg_f32_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_WriteHook_Sa_HwTrq_HwTrqScaleVal_VoltsPerDeg_f32_Return
# endif
# if defined (Rte_WriteHook_Sa_HwTrq_HwTrqScaleVal_VoltsPerDeg_f32_Return)
#  undef Rte_WriteHook_Sa_HwTrq_HwTrqScaleVal_VoltsPerDeg_f32_Return
FUNC(void, RTE_APPL_CODE) Rte_WriteHook_Sa_HwTrq_HwTrqScaleVal_VoltsPerDeg_f32_Return(Float data);
# else
#  define Rte_WriteHook_Sa_HwTrq_HwTrqScaleVal_VoltsPerDeg_f32_Return(arg1) ((void)(0))
# endif /* Rte_WriteHook_Sa_HwTrq_HwTrqScaleVal_VoltsPerDeg_f32_Return */

# if defined (Rte_WriteHook_Sa_HwTrq_HwTrqScaleVal_VoltsPerDeg_f32_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_WriteHook_Sa_HwTrq_HwTrqScaleVal_VoltsPerDeg_f32_Start
# endif
# if defined (Rte_WriteHook_Sa_HwTrq_HwTrqScaleVal_VoltsPerDeg_f32_Start)
#  undef Rte_WriteHook_Sa_HwTrq_HwTrqScaleVal_VoltsPerDeg_f32_Start
FUNC(void, RTE_APPL_CODE) Rte_WriteHook_Sa_HwTrq_HwTrqScaleVal_VoltsPerDeg_f32_Start(Float data);
# else
#  define Rte_WriteHook_Sa_HwTrq_HwTrqScaleVal_VoltsPerDeg_f32_Start(arg1) ((void)(0))
# endif /* Rte_WriteHook_Sa_HwTrq_HwTrqScaleVal_VoltsPerDeg_f32_Start */

# if defined (Rte_WriteHook_Sa_HwTrq_T1TrimVal_Volt_f32_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_WriteHook_Sa_HwTrq_T1TrimVal_Volt_f32_Return
# endif
# if defined (Rte_WriteHook_Sa_HwTrq_T1TrimVal_Volt_f32_Return)
#  undef Rte_WriteHook_Sa_HwTrq_T1TrimVal_Volt_f32_Return
FUNC(void, RTE_APPL_CODE) Rte_WriteHook_Sa_HwTrq_T1TrimVal_Volt_f32_Return(Float data);
# else
#  define Rte_WriteHook_Sa_HwTrq_T1TrimVal_Volt_f32_Return(arg1) ((void)(0))
# endif /* Rte_WriteHook_Sa_HwTrq_T1TrimVal_Volt_f32_Return */

# if defined (Rte_WriteHook_Sa_HwTrq_T1TrimVal_Volt_f32_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_WriteHook_Sa_HwTrq_T1TrimVal_Volt_f32_Start
# endif
# if defined (Rte_WriteHook_Sa_HwTrq_T1TrimVal_Volt_f32_Start)
#  undef Rte_WriteHook_Sa_HwTrq_T1TrimVal_Volt_f32_Start
FUNC(void, RTE_APPL_CODE) Rte_WriteHook_Sa_HwTrq_T1TrimVal_Volt_f32_Start(Float data);
# else
#  define Rte_WriteHook_Sa_HwTrq_T1TrimVal_Volt_f32_Start(arg1) ((void)(0))
# endif /* Rte_WriteHook_Sa_HwTrq_T1TrimVal_Volt_f32_Start */

# if defined (Rte_WriteHook_Sa_HwTrq_T2TrimVal_Volt_f32_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_WriteHook_Sa_HwTrq_T2TrimVal_Volt_f32_Return
# endif
# if defined (Rte_WriteHook_Sa_HwTrq_T2TrimVal_Volt_f32_Return)
#  undef Rte_WriteHook_Sa_HwTrq_T2TrimVal_Volt_f32_Return
FUNC(void, RTE_APPL_CODE) Rte_WriteHook_Sa_HwTrq_T2TrimVal_Volt_f32_Return(Float data);
# else
#  define Rte_WriteHook_Sa_HwTrq_T2TrimVal_Volt_f32_Return(arg1) ((void)(0))
# endif /* Rte_WriteHook_Sa_HwTrq_T2TrimVal_Volt_f32_Return */

# if defined (Rte_WriteHook_Sa_HwTrq_T2TrimVal_Volt_f32_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_WriteHook_Sa_HwTrq_T2TrimVal_Volt_f32_Start
# endif
# if defined (Rte_WriteHook_Sa_HwTrq_T2TrimVal_Volt_f32_Start)
#  undef Rte_WriteHook_Sa_HwTrq_T2TrimVal_Volt_f32_Start
FUNC(void, RTE_APPL_CODE) Rte_WriteHook_Sa_HwTrq_T2TrimVal_Volt_f32_Start(Float data);
# else
#  define Rte_WriteHook_Sa_HwTrq_T2TrimVal_Volt_f32_Start(arg1) ((void)(0))
# endif /* Rte_WriteHook_Sa_HwTrq_T2TrimVal_Volt_f32_Start */

# define RTE_STOP_SEC_APPL_CODE
# include "MemMap.h"

/* begin Fileversion check */
# ifndef SKIP_MAGIC_NUMBER
#  ifdef RTE_MAGIC_NUMBER
#   if RTE_MAGIC_NUMBER != 1468867288
#    error "The magic number of the generated file <C:/Sankar/Chrysler/Synergy/CL/Temp_work/Chrysler_LWR_EPS_TMS570/SwProject/Source/GenDataRte/Rte_Hook.h> is different. Please check time and date of the generated RTE files!"
#   endif
#  else
#   define RTE_MAGIC_NUMBER 1468867288
#  endif  /* RTE_MAGIC_NUMBER */
# endif  /* SKIP_MAGIC_NUMBER */
/* end Fileversion check */

#endif /* _RTE_HOOK_H */
