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
 *          File:  Components/Rte_Sa_CDDInterface.h
 *     Workspace:  C:/Sankar/Chrysler/Synergy/CL/Temp_work/Chrysler_LWR_EPS_TMS570/Tools/AsrProject/Config/DCF/EPS.dcf
 *   ECU-Project:  EPS
 *  Generated at:  Mon Jul 18 14:56:53 2016
 *
 *     Generator:  MICROSAR RTE Generator Version 2.19.1
 *       License:  License CBD1010124 valid for CBD1010124 Nexteer  Package: BMW MSR SIP BAC3.0     Micro: TI TMS570 TMS570LS30306  Compiler: Code Composer Studio 4.9.0
 *
 *   Description:  Application header file for SW-C
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_SA_CDDINTERFACE_H
# define _RTE_SA_CDDINTERFACE_H

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
/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

#  define Rte_InitValue_ADCMtrCurr1_Volts_f32 (0.0F)
#  define Rte_InitValue_ADCMtrCurr2_Volts_f32 (0.0F)
#  define Rte_InitValue_CommOffset_Cnt_u16 (0U)
#  define Rte_InitValue_CorrMtrCurrPosition_Rev_f32 (0.0F)
#  define Rte_InitValue_CorrMtrPosElec_Rev_f32 (0.0F)
#  define Rte_InitValue_Cos1Theta_Volts_f32 (0.0F)
#  define Rte_InitValue_DampingSrlComSvcDft_Cnt_lgc (FALSE)
#  define Rte_InitValue_DaxIntegralGain_IPM_Uls_f32 (0.0F)
#  define Rte_InitValue_DaxIntegralGain_SPM_Uls_f32 (0.0F)
#  define Rte_InitValue_DaxPropotionalGain_IPM_Uls_f32 (0.0F)
#  define Rte_InitValue_DaxPropotionalGain_SPM_Uls_f32 (0.0F)
#  define Rte_InitValue_DftAsstTbl_Cnt_lgc (FALSE)
#  define Rte_InitValue_DrivingDynSrlComSvcDft_Cnt_lgc (FALSE)
#  define Rte_InitValue_DutyCycleSmall_Cnt_u16 (0U)
#  define Rte_InitValue_DwnldAsstGain_Uls_f32 (0.0F)
#  define Rte_InitValue_EOTImpactSrlComSvcDft_Cnt_lgc (FALSE)
#  define Rte_InitValue_EOTThermalSrlComSvcDft_Cnt_lgc (FALSE)
#  define Rte_InitValue_EngONSrlComSvcDft_Cnt_lgc (FALSE)
#  define Rte_InitValue_EstKe_VpRadpS_f32 (0.0F)
#  define Rte_InitValue_ExpectedOnTimeA_Cnt_u32 (0U)
#  define Rte_InitValue_ExpectedOnTimeB_Cnt_u32 (0U)
#  define Rte_InitValue_ExpectedOnTimeC_Cnt_u32 (0U)
#  define Rte_InitValue_FETFaultPhase_Cnt_enum (0U)
#  define Rte_InitValue_FETFaultType_Cnt_enum (0U)
#  define Rte_InitValue_FreqDepDmpSrlComSvcDft_Cnt_lgc (FALSE)
#  define Rte_InitValue_FricLrnSrlComSvcDft_Cnt_lgc (FALSE)
#  define Rte_InitValue_HysAddSrlComSvcDft_Cnt_lgc (FALSE)
#  define Rte_InitValue_HystCompSrlComSvcDft_Cnt_lgc (FALSE)
#  define Rte_InitValue_IgnCnt_Cnt_u16 (0U)
#  define Rte_InitValue_KinIntDiagSrlComSvcDft_Cnt_lgc (FALSE)
#  define Rte_InitValue_LRPRPhaseadvanceCaptured_Cnt_s16 (0)
#  define Rte_InitValue_LimitSrlComSvcDft_Cnt_lgc (FALSE)
#  define Rte_InitValue_MEC_Cnt_enum (0U)
#  define Rte_InitValue_MRFMtrVel_MtrRadpS_f32 (0.0F)
#  define Rte_InitValue_MeasuredOnTimeA_Cnt_u32 (0U)
#  define Rte_InitValue_MeasuredOnTimeB_Cnt_u32 (0U)
#  define Rte_InitValue_MeasuredOnTimeC_Cnt_u32 (0U)
#  define Rte_InitValue_MfgDiagInhibit_Cnt_lgc (FALSE)
#  define Rte_InitValue_ModIdxFinal_Uls_f32 (0.0F)
#  define Rte_InitValue_ModIdxSrlComSvcDft_Cnt_lgc (FALSE)
#  define Rte_InitValue_MtrCurr1TempOffset_Volt_f32 (0.0F)
#  define Rte_InitValue_MtrCurr2TempOffset_Volt_f32 (0.0F)
#  define Rte_InitValue_MtrCurrDax_Amp_f32 (0.0F)
#  define Rte_InitValue_MtrCurrDaxRef_Amp_f32 (0.0F)
#  define Rte_InitValue_MtrCurrDaxRef_IPM_Amp_f32 (0.0F)
#  define Rte_InitValue_MtrCurrDaxRef_SPM_Amp_f32 (0.0F)
#  define Rte_InitValue_MtrCurrK1_Amp_f32 (0.0F)
#  define Rte_InitValue_MtrCurrK2_Amp_f32 (0.0F)
#  define Rte_InitValue_MtrCurrQax_Amp_f32 (0.0F)
#  define Rte_InitValue_MtrCurrQax12Mag_Amp_f32 (0.0F)
#  define Rte_InitValue_MtrCurrQax12Ph_Rev_f32 (0.0F)
#  define Rte_InitValue_MtrCurrQax6Mag_Amp_f32 (0.0F)
#  define Rte_InitValue_MtrCurrQax6Ph_Rev_f32 (0.0F)
#  define Rte_InitValue_MtrCurrQaxFinalRef_Amp_f32 (0.0F)
#  define Rte_InitValue_MtrCurrQaxRef_IPM_Amp_f32 (0.0F)
#  define Rte_InitValue_MtrCurrQaxRef_SPM_Amp_f32 (0.0F)
#  define Rte_InitValue_MtrElecMechPolarity_Cnt_s08 (0)
#  define Rte_InitValue_MtrParmNrmLrnSrlComSvcDft_Cnt_lgc (FALSE)
#  define Rte_InitValue_MtrPosComputationDelay_IPM_Deg_f32 (0.0F)
#  define Rte_InitValue_MtrPosComputationDelay_SPM_Deg_f32 (0.0F)
#  define Rte_InitValue_MtrPosElec_Rev_f32 (0.0F)
#  define Rte_InitValue_MtrPosMech_Rev_f32 (0.0F)
#  define Rte_InitValue_MtrRevCntr_Cnt_s16 (0)
#  define Rte_InitValue_MtrTrqCmdSign_IPM_Cnt_s16 (0)
#  define Rte_InitValue_MtrTrqCmdSign_SPM_Cnt_s16 (0)
#  define Rte_InitValue_MtrVelNrmLrnSrlComSvcDft_Cnt_lgc (FALSE)
#  define Rte_InitValue_MtrVoltDax_Volt_f32 (0.0F)
#  define Rte_InitValue_MtrVoltDaxFF_IPM_Volt_f32 (0.0F)
#  define Rte_InitValue_MtrVoltDaxFF_SPM_Volt_f32 (0.0F)
#  define Rte_InitValue_MtrVoltQax_Volt_f32 (0.0F)
#  define Rte_InitValue_MtrVoltQaxFF_IPM_Volt_f32 (0.0F)
#  define Rte_InitValue_MtrVoltQaxFF_SPM_Volt_f32 (0.0F)
#  define Rte_InitValue_MultIgnSrlComSvcDft_Cnt_lgc (FALSE)
#  define Rte_InitValue_ParkAstSrlComSvcDft_Cnt_lgc (FALSE)
#  define Rte_InitValue_PhsReasA_Volts_f32 (0.0F)
#  define Rte_InitValue_PhsReasB_Volts_f32 (0.0F)
#  define Rte_InitValue_PhsReasC_Volts_f32 (0.0F)
#  define Rte_InitValue_PullCompSrlComSvcDft_Cnt_lgc (FALSE)
#  define Rte_InitValue_QaxIntegralGain_IPM_Uls_f32 (0.0F)
#  define Rte_InitValue_QaxIntegralGain_SPM_Uls_f32 (0.0F)
#  define Rte_InitValue_QaxPropotionalGain_IPM_Uls_f32 (0.0F)
#  define Rte_InitValue_QaxPropotionalGain_SPM_Uls_f32 (0.0F)
#  define Rte_InitValue_ReturnSrlComSvcDft_Cnt_lgc (FALSE)
#  define Rte_InitValue_RxMsgsSrlComSvcDft_Cnt_lgc (FALSE)
#  define Rte_InitValue_SWDutyCycleA_Uls_f32 (0.0F)
#  define Rte_InitValue_SWDutyCycleB_Uls_f32 (0.0F)
#  define Rte_InitValue_SWDutyCycleC_Uls_f32 (0.0F)
#  define Rte_InitValue_Sin1Theta_Volts_f32 (0.0F)
#  define Rte_InitValue_SrlComSvcDft_Cnt_b32 (0U)
#  define Rte_InitValue_SysCCorrectedMtrPos_Rev_f32 (0.0F)
#  define Rte_InitValue_TOEOLDisable_Cnt_lgc (FALSE)
#  define Rte_InitValue_ThermalDCSrlComSvcDft_Cnt_lgc (FALSE)
#  define Rte_InitValue_TrqRmpSrlComSvcDft_Cnt_lgc (FALSE)
#  define Rte_InitValue_Vecu_Volt_f32 (5.0F)
#  define Rte_InitValue_WIREnabled_Cnt_lgc (FALSE)
#  define Rte_InitValue_WhlImbRejSrlComSvcDft_Cnt_lgc (FALSE)
# endif


# ifndef RTE_CORE
#  define RTE_START_SEC_VAR_NOINIT_UNSPECIFIED
#  include "MemMap.h"

/**********************************************************************************************************************
 * Buffers for Mode Management
 *********************************************************************************************************************/
extern VAR(Rte_ModeType_StaMd_Mode, RTE_VAR_NOINIT) Rte_ModeMachine_StaMd_SystemState_Mode;

#  define RTE_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#  include "MemMap.h"
# endif /* !defined(RTE_CORE) */



# ifndef RTE_CORE
#  define RTE_START_SEC_VAR_Ap_10_NOINIT_UNSPECIFIED
#  include "MemMap.h"

/**********************************************************************************************************************
 * Buffers for implicit communication
 *********************************************************************************************************************/

extern VAR(Rte_tsTask_Init_10, RTE_VAR_NOINIT) Rte_Task_Init_10;

extern VAR(Rte_tsTask_2ms_10, RTE_VAR_NOINIT) Rte_Task_2ms_10;

extern VAR(Rte_tsTask_10ms_10, RTE_VAR_NOINIT) Rte_Task_10ms_10;

#  define RTE_STOP_SEC_VAR_Ap_10_NOINIT_UNSPECIFIED
#  include "MemMap.h"
# endif


# define RTE_START_SEC_CODE
# include "MemMap.h"

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/

# define RTE_STOP_SEC_CODE
# include "MemMap.h"


# ifndef RTE_CORE

/**********************************************************************************************************************
 * Rte_IRead_<r>_<p>_<d>
 * Rte_IStatus_<r>_<p>_<d>
 * Rte_IWrite_<r>_<p>_<d>
 * Rte_IWriteRef_<r>_<p>_<d>
 * Rte_IInvalidate_<r>_<p>_<d>
 *********************************************************************************************************************/

#  define Rte_IRead_CDDInterface_Init1_MtrElecMechPolarity_Cnt_s08() \
  (Rte_Task_Init_10.Rte_TB.Rte_I_Polarity_MtrElecMechPolarity_Cnt_s08.value)

#  define Rte_IWrite_CDDInterface_Init1_IgnCnt_Cnt_u16(data) \
  ( \
    Rte_Task_Init_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Init1.Rte_IgnCnt_Cnt_u16.value = (data) \
  )

#  define Rte_IWriteRef_CDDInterface_Init1_IgnCnt_Cnt_u16() \
  (&Rte_Task_Init_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Init1.Rte_IgnCnt_Cnt_u16.value)

#  define Rte_IWrite_CDDInterface_Init1_MEC_Cnt_enum(data) \
  ( \
    Rte_Task_Init_10.Rte_TB.Rte_I_CDDInterface_MEC_Cnt_enum.value = (data) \
  )

#  define Rte_IWriteRef_CDDInterface_Init1_MEC_Cnt_enum() \
  (&Rte_Task_Init_10.Rte_TB.Rte_I_CDDInterface_MEC_Cnt_enum.value)

#  define Rte_IWrite_CDDInterface_Per1_ADCMtrCurr1_Volts_f32(data) \
  ( \
    Rte_Task_2ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per1.Rte_ADCMtrCurr1_Volts_f32.value = (data) \
  )

#  define Rte_IWriteRef_CDDInterface_Per1_ADCMtrCurr1_Volts_f32() \
  (&Rte_Task_2ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per1.Rte_ADCMtrCurr1_Volts_f32.value)

#  define Rte_IWrite_CDDInterface_Per1_ADCMtrCurr2_Volts_f32(data) \
  ( \
    Rte_Task_2ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per1.Rte_ADCMtrCurr2_Volts_f32.value = (data) \
  )

#  define Rte_IWriteRef_CDDInterface_Per1_ADCMtrCurr2_Volts_f32() \
  (&Rte_Task_2ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per1.Rte_ADCMtrCurr2_Volts_f32.value)

#  define Rte_IWrite_CDDInterface_Per1_CorrMtrCurrPosition_Rev_f32(data) \
  ( \
    Rte_Task_2ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per1.Rte_CorrMtrCurrPosition_Rev_f32.value = (data) \
  )

#  define Rte_IWriteRef_CDDInterface_Per1_CorrMtrCurrPosition_Rev_f32() \
  (&Rte_Task_2ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per1.Rte_CorrMtrCurrPosition_Rev_f32.value)

#  define Rte_IWrite_CDDInterface_Per1_CorrMtrPosElec_Rev_f32(data) \
  ( \
    Rte_Task_2ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per1.Rte_CorrMtrPosElec_Rev_f32.value = (data) \
  )

#  define Rte_IWriteRef_CDDInterface_Per1_CorrMtrPosElec_Rev_f32() \
  (&Rte_Task_2ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per1.Rte_CorrMtrPosElec_Rev_f32.value)

#  define Rte_IWrite_CDDInterface_Per1_Cos1Theta_Volts_f32(data) \
  ( \
    Rte_Task_2ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per1.Rte_Cos1Theta_Volts_f32.value = (data) \
  )

#  define Rte_IWriteRef_CDDInterface_Per1_Cos1Theta_Volts_f32() \
  (&Rte_Task_2ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per1.Rte_Cos1Theta_Volts_f32.value)

#  define Rte_IWrite_CDDInterface_Per1_DutyCycleSmall_Cnt_u16(data) \
  ( \
    Rte_Task_2ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per1.Rte_DutyCycleSmall_Cnt_u16.value = (data) \
  )

#  define Rte_IWriteRef_CDDInterface_Per1_DutyCycleSmall_Cnt_u16() \
  (&Rte_Task_2ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per1.Rte_DutyCycleSmall_Cnt_u16.value)

#  define Rte_IWrite_CDDInterface_Per1_ExpectedOnTimeA_Cnt_u32(data) \
  ( \
    Rte_Task_2ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per1.Rte_ExpectedOnTimeA_Cnt_u32.value = (data) \
  )

#  define Rte_IWriteRef_CDDInterface_Per1_ExpectedOnTimeA_Cnt_u32() \
  (&Rte_Task_2ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per1.Rte_ExpectedOnTimeA_Cnt_u32.value)

#  define Rte_IWrite_CDDInterface_Per1_ExpectedOnTimeB_Cnt_u32(data) \
  ( \
    Rte_Task_2ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per1.Rte_ExpectedOnTimeB_Cnt_u32.value = (data) \
  )

#  define Rte_IWriteRef_CDDInterface_Per1_ExpectedOnTimeB_Cnt_u32() \
  (&Rte_Task_2ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per1.Rte_ExpectedOnTimeB_Cnt_u32.value)

#  define Rte_IWrite_CDDInterface_Per1_ExpectedOnTimeC_Cnt_u32(data) \
  ( \
    Rte_Task_2ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per1.Rte_ExpectedOnTimeC_Cnt_u32.value = (data) \
  )

#  define Rte_IWriteRef_CDDInterface_Per1_ExpectedOnTimeC_Cnt_u32() \
  (&Rte_Task_2ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per1.Rte_ExpectedOnTimeC_Cnt_u32.value)

#  define Rte_IWrite_CDDInterface_Per1_LRPRPhaseadvanceCaptured_Cnt_s16(data) \
  ( \
    Rte_Task_2ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per1.Rte_LRPRPhaseadvanceCaptured_Cnt_s16.value = (data) \
  )

#  define Rte_IWriteRef_CDDInterface_Per1_LRPRPhaseadvanceCaptured_Cnt_s16() \
  (&Rte_Task_2ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per1.Rte_LRPRPhaseadvanceCaptured_Cnt_s16.value)

#  define Rte_IWrite_CDDInterface_Per1_MeasuredOnTimeA_Cnt_u32(data) \
  ( \
    Rte_Task_2ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per1.Rte_MeasuredOnTimeA_Cnt_u32.value = (data) \
  )

#  define Rte_IWriteRef_CDDInterface_Per1_MeasuredOnTimeA_Cnt_u32() \
  (&Rte_Task_2ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per1.Rte_MeasuredOnTimeA_Cnt_u32.value)

#  define Rte_IWrite_CDDInterface_Per1_MeasuredOnTimeB_Cnt_u32(data) \
  ( \
    Rte_Task_2ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per1.Rte_MeasuredOnTimeB_Cnt_u32.value = (data) \
  )

#  define Rte_IWriteRef_CDDInterface_Per1_MeasuredOnTimeB_Cnt_u32() \
  (&Rte_Task_2ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per1.Rte_MeasuredOnTimeB_Cnt_u32.value)

#  define Rte_IWrite_CDDInterface_Per1_MeasuredOnTimeC_Cnt_u32(data) \
  ( \
    Rte_Task_2ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per1.Rte_MeasuredOnTimeC_Cnt_u32.value = (data) \
  )

#  define Rte_IWriteRef_CDDInterface_Per1_MeasuredOnTimeC_Cnt_u32() \
  (&Rte_Task_2ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per1.Rte_MeasuredOnTimeC_Cnt_u32.value)

#  define Rte_IWrite_CDDInterface_Per1_ModIdxFinal_Uls_f32(data) \
  ( \
    Rte_Task_2ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per1.Rte_ModIdxFinal_Uls_f32.value = (data) \
  )

#  define Rte_IWriteRef_CDDInterface_Per1_ModIdxFinal_Uls_f32() \
  (&Rte_Task_2ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per1.Rte_ModIdxFinal_Uls_f32.value)

#  define Rte_IWrite_CDDInterface_Per1_MtrCurrDaxRef_Amp_f32(data) \
  ( \
    Rte_Task_2ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per1.Rte_MtrCurrDaxRef_Amp_f32.value = (data) \
  )

#  define Rte_IWriteRef_CDDInterface_Per1_MtrCurrDaxRef_Amp_f32() \
  (&Rte_Task_2ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per1.Rte_MtrCurrDaxRef_Amp_f32.value)

#  define Rte_IWrite_CDDInterface_Per1_MtrCurrDax_Amp_f32(data) \
  ( \
    Rte_Task_2ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per1.Rte_MtrCurrDax_Amp_f32.value = (data) \
  )

#  define Rte_IWriteRef_CDDInterface_Per1_MtrCurrDax_Amp_f32() \
  (&Rte_Task_2ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per1.Rte_MtrCurrDax_Amp_f32.value)

#  define Rte_IWrite_CDDInterface_Per1_MtrCurrK1_Amp_f32(data) \
  ( \
    Rte_Task_2ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per1.Rte_MtrCurrK1_Amp_f32.value = (data) \
  )

#  define Rte_IWriteRef_CDDInterface_Per1_MtrCurrK1_Amp_f32() \
  (&Rte_Task_2ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per1.Rte_MtrCurrK1_Amp_f32.value)

#  define Rte_IWrite_CDDInterface_Per1_MtrCurrK2_Amp_f32(data) \
  ( \
    Rte_Task_2ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per1.Rte_MtrCurrK2_Amp_f32.value = (data) \
  )

#  define Rte_IWriteRef_CDDInterface_Per1_MtrCurrK2_Amp_f32() \
  (&Rte_Task_2ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per1.Rte_MtrCurrK2_Amp_f32.value)

#  define Rte_IWrite_CDDInterface_Per1_MtrCurrQaxFinalRef_Amp_f32(data) \
  ( \
    Rte_Task_2ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per1.Rte_MtrCurrQaxFinalRef_Amp_f32.value = (data) \
  )

#  define Rte_IWriteRef_CDDInterface_Per1_MtrCurrQaxFinalRef_Amp_f32() \
  (&Rte_Task_2ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per1.Rte_MtrCurrQaxFinalRef_Amp_f32.value)

#  define Rte_IWrite_CDDInterface_Per1_MtrCurrQax_Amp_f32(data) \
  ( \
    Rte_Task_2ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per1.Rte_MtrCurrQax_Amp_f32.value = (data) \
  )

#  define Rte_IWriteRef_CDDInterface_Per1_MtrCurrQax_Amp_f32() \
  (&Rte_Task_2ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per1.Rte_MtrCurrQax_Amp_f32.value)

#  define Rte_IWrite_CDDInterface_Per1_MtrPosElec_Rev_f32(data) \
  ( \
    Rte_Task_2ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per1.Rte_MtrPosElec_Rev_f32.value = (data) \
  )

#  define Rte_IWriteRef_CDDInterface_Per1_MtrPosElec_Rev_f32() \
  (&Rte_Task_2ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per1.Rte_MtrPosElec_Rev_f32.value)

#  define Rte_IWrite_CDDInterface_Per1_MtrPosMech_Rev_f32(data) \
  ( \
    Rte_Task_2ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per1.Rte_MtrPosMech_Rev_f32.value = (data) \
  )

#  define Rte_IWriteRef_CDDInterface_Per1_MtrPosMech_Rev_f32() \
  (&Rte_Task_2ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per1.Rte_MtrPosMech_Rev_f32.value)

#  define Rte_IWrite_CDDInterface_Per1_MtrRevCntr_Cnt_s16(data) \
  ( \
    Rte_Task_2ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per1.Rte_MtrRevCntr_Cnt_s16.value = (data) \
  )

#  define Rte_IWriteRef_CDDInterface_Per1_MtrRevCntr_Cnt_s16() \
  (&Rte_Task_2ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per1.Rte_MtrRevCntr_Cnt_s16.value)

#  define Rte_IWrite_CDDInterface_Per1_MtrVoltDax_Volt_f32(data) \
  ( \
    Rte_Task_2ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per1.Rte_MtrVoltDax_Volt_f32.value = (data) \
  )

#  define Rte_IWriteRef_CDDInterface_Per1_MtrVoltDax_Volt_f32() \
  (&Rte_Task_2ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per1.Rte_MtrVoltDax_Volt_f32.value)

#  define Rte_IWrite_CDDInterface_Per1_MtrVoltQax_Volt_f32(data) \
  ( \
    Rte_Task_2ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per1.Rte_MtrVoltQax_Volt_f32.value = (data) \
  )

#  define Rte_IWriteRef_CDDInterface_Per1_MtrVoltQax_Volt_f32() \
  (&Rte_Task_2ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per1.Rte_MtrVoltQax_Volt_f32.value)

#  define Rte_IWrite_CDDInterface_Per1_PhsReasA_Volts_f32(data) \
  ( \
    Rte_Task_2ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per1.Rte_PhsReasA_Volts_f32.value = (data) \
  )

#  define Rte_IWriteRef_CDDInterface_Per1_PhsReasA_Volts_f32() \
  (&Rte_Task_2ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per1.Rte_PhsReasA_Volts_f32.value)

#  define Rte_IWrite_CDDInterface_Per1_PhsReasB_Volts_f32(data) \
  ( \
    Rte_Task_2ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per1.Rte_PhsReasB_Volts_f32.value = (data) \
  )

#  define Rte_IWriteRef_CDDInterface_Per1_PhsReasB_Volts_f32() \
  (&Rte_Task_2ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per1.Rte_PhsReasB_Volts_f32.value)

#  define Rte_IWrite_CDDInterface_Per1_PhsReasC_Volts_f32(data) \
  ( \
    Rte_Task_2ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per1.Rte_PhsReasC_Volts_f32.value = (data) \
  )

#  define Rte_IWriteRef_CDDInterface_Per1_PhsReasC_Volts_f32() \
  (&Rte_Task_2ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per1.Rte_PhsReasC_Volts_f32.value)

#  define Rte_IWrite_CDDInterface_Per1_SWDutyCycleA_Uls_f32(data) \
  /* unconnected */

#  define Rte_IWriteRef_CDDInterface_Per1_SWDutyCycleA_Uls_f32() \
  (&Rte_Task_2ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per1.Rte_SWDutyCycleA_Uls_f32.value)

#  define Rte_IWrite_CDDInterface_Per1_SWDutyCycleB_Uls_f32(data) \
  /* unconnected */

#  define Rte_IWriteRef_CDDInterface_Per1_SWDutyCycleB_Uls_f32() \
  (&Rte_Task_2ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per1.Rte_SWDutyCycleB_Uls_f32.value)

#  define Rte_IWrite_CDDInterface_Per1_SWDutyCycleC_Uls_f32(data) \
  /* unconnected */

#  define Rte_IWriteRef_CDDInterface_Per1_SWDutyCycleC_Uls_f32() \
  (&Rte_Task_2ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per1.Rte_SWDutyCycleC_Uls_f32.value)

#  define Rte_IWrite_CDDInterface_Per1_Sin1Theta_Volts_f32(data) \
  ( \
    Rte_Task_2ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per1.Rte_Sin1Theta_Volts_f32.value = (data) \
  )

#  define Rte_IWriteRef_CDDInterface_Per1_Sin1Theta_Volts_f32() \
  (&Rte_Task_2ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per1.Rte_Sin1Theta_Volts_f32.value)

#  define Rte_IWrite_CDDInterface_Per1_SysCCorrectedMtrPos_Rev_f32(data) \
  ( \
    Rte_Task_2ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per1.Rte_SysCCorrectedMtrPos_Rev_f32.value = (data) \
  )

#  define Rte_IWriteRef_CDDInterface_Per1_SysCCorrectedMtrPos_Rev_f32() \
  (&Rte_Task_2ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per1.Rte_SysCCorrectedMtrPos_Rev_f32.value)

#  define Rte_IRead_CDDInterface_Per2_CommOffset_Cnt_u16() \
  (Rte_Task_2ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per2.Rte_CommOffset_Cnt_u16.value)

#  define Rte_IRead_CDDInterface_Per2_DaxIntegralGain_IPM_Uls_f32() \
  (Rte_Task_2ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per2.Rte_DaxIntegralGain_IPM_Uls_f32.value)

#  define Rte_IRead_CDDInterface_Per2_DaxIntegralGain_SPM_Uls_f32() \
  (Rte_Task_2ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per2.Rte_DaxIntegralGain_SPM_Uls_f32.value)

#  define Rte_IRead_CDDInterface_Per2_DaxPropotionalGain_IPM_Uls_f32() \
  (Rte_Task_2ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per2.Rte_DaxPropotionalGain_IPM_Uls_f32.value)

#  define Rte_IRead_CDDInterface_Per2_DaxPropotionalGain_SPM_Uls_f32() \
  (Rte_Task_2ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per2.Rte_DaxPropotionalGain_SPM_Uls_f32.value)

#  define Rte_IRead_CDDInterface_Per2_EstKe_VpRadpS_f32() \
  (Rte_Task_2ms_10.Rte_TB.Rte_I_CurrParamComp_EstKe_VpRadpS_f32.value)

#  define Rte_IRead_CDDInterface_Per2_MRFMtrVel_MtrRadpS_f32() \
  (Rte_Task_2ms_10.Rte_TB.Rte_I_MtrVel_MRFMotorVel_MtrRadpS_f32.value)

#  define Rte_IRead_CDDInterface_Per2_MtrCurr1TempOffset_Volt_f32() \
  (Rte_Task_2ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per2.Rte_MtrCurr1TempOffset_Volt_f32.value)

#  define Rte_IRead_CDDInterface_Per2_MtrCurr2TempOffset_Volt_f32() \
  (Rte_Task_2ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per2.Rte_MtrCurr2TempOffset_Volt_f32.value)

#  define Rte_IRead_CDDInterface_Per2_MtrCurrDaxRef_IPM_Amp_f32() \
  (Rte_Task_2ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per2.Rte_MtrCurrDaxRef_IPM_Amp_f32.value)

#  define Rte_IRead_CDDInterface_Per2_MtrCurrDaxRef_SPM_Amp_f32() \
  (Rte_Task_2ms_10.Rte_TB.Rte_I_CurrCmd_MtrCurrDaxRef_Amp_f32.value)

#  define Rte_IRead_CDDInterface_Per2_MtrCurrQax12Mag_Amp_f32() \
  (Rte_Task_2ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per2.Rte_MtrCurrQax12Mag_Amp_f32.value)

#  define Rte_IRead_CDDInterface_Per2_MtrCurrQax12Ph_Rev_f32() \
  (Rte_Task_2ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per2.Rte_MtrCurrQax12Ph_Rev_f32.value)

#  define Rte_IRead_CDDInterface_Per2_MtrCurrQax6Mag_Amp_f32() \
  (Rte_Task_2ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per2.Rte_MtrCurrQax6Mag_Amp_f32.value)

#  define Rte_IRead_CDDInterface_Per2_MtrCurrQax6Ph_Rev_f32() \
  (Rte_Task_2ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per2.Rte_MtrCurrQax6Ph_Rev_f32.value)

#  define Rte_IRead_CDDInterface_Per2_MtrCurrQaxRef_IPM_Amp_f32() \
  (Rte_Task_2ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per2.Rte_MtrCurrQaxRef_IPM_Amp_f32.value)

#  define Rte_IRead_CDDInterface_Per2_MtrCurrQaxRef_SPM_Amp_f32() \
  (Rte_Task_2ms_10.Rte_TB.Rte_I_CurrCmd_MtrCurrQaxRef_Amp_f32.value)

#  define Rte_IRead_CDDInterface_Per2_MtrPosComputationDelay_IPM_Deg_f32() \
  (Rte_Task_2ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per2.Rte_MtrPosComputationDelay_IPM_Deg_f32.value)

#  define Rte_IRead_CDDInterface_Per2_MtrPosComputationDelay_SPM_Deg_f32() \
  (Rte_Task_2ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per2.Rte_MtrPosComputationDelay_SPM_Deg_f32.value)

#  define Rte_IRead_CDDInterface_Per2_MtrTrqCmdSign_IPM_Cnt_s16() \
  (Rte_Task_2ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per2.Rte_MtrTrqCmdSign_IPM_Cnt_s16.value)

#  define Rte_IRead_CDDInterface_Per2_MtrTrqCmdSign_SPM_Cnt_s16() \
  (Rte_Task_2ms_10.Rte_TB.Rte_I_CurrCmd_MtrTrqCmdSign_Cnt_s16.value)

#  define Rte_IRead_CDDInterface_Per2_MtrVoltDaxFF_IPM_Volt_f32() \
  (Rte_Task_2ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per2.Rte_MtrVoltDaxFF_IPM_Volt_f32.value)

#  define Rte_IRead_CDDInterface_Per2_MtrVoltDaxFF_SPM_Volt_f32() \
  (Rte_Task_2ms_10.Rte_TB.Rte_I_CurrCmd_MtrVoltDaxFF_Volt_f32.value)

#  define Rte_IRead_CDDInterface_Per2_MtrVoltQaxFF_IPM_Volt_f32() \
  (Rte_Task_2ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per2.Rte_MtrVoltQaxFF_IPM_Volt_f32.value)

#  define Rte_IRead_CDDInterface_Per2_MtrVoltQaxFF_SPM_Volt_f32() \
  (Rte_Task_2ms_10.Rte_TB.Rte_I_CurrCmd_MtrVoltQaxFF_Volt_f32.value)

#  define Rte_IRead_CDDInterface_Per2_QaxIntegralGain_IPM_Uls_f32() \
  (Rte_Task_2ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per2.Rte_QaxIntegralGain_IPM_Uls_f32.value)

#  define Rte_IRead_CDDInterface_Per2_QaxIntegralGain_SPM_Uls_f32() \
  (Rte_Task_2ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per2.Rte_QaxIntegralGain_SPM_Uls_f32.value)

#  define Rte_IRead_CDDInterface_Per2_QaxPropotionalGain_IPM_Uls_f32() \
  (Rte_Task_2ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per2.Rte_QaxPropotionalGain_IPM_Uls_f32.value)

#  define Rte_IRead_CDDInterface_Per2_QaxPropotionalGain_SPM_Uls_f32() \
  (Rte_Task_2ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per2.Rte_QaxPropotionalGain_SPM_Uls_f32.value)

#  define Rte_IRead_CDDInterface_Per2_Vecu_Volt_f32() \
  (Rte_Task_2ms_10.Rte_TB.Rte_I_BatteryVoltage_Vecu_Volt_f32.value)

#  define Rte_IRead_CDDInterface_Per4_MtrElecMechPolarity_Cnt_s08() \
  (Rte_Task_10ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per4.Rte_MtrElecMechPolarity_Cnt_s08.value)

#  define Rte_IWrite_CDDInterface_Per4_DampingSrlComSvcDft_Cnt_lgc(data) \
  ( \
    Rte_Task_10ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per4.Rte_DampingSrlComSvcDft_Cnt_lgc.value = (data) \
  )

#  define Rte_IWriteRef_CDDInterface_Per4_DampingSrlComSvcDft_Cnt_lgc() \
  (&Rte_Task_10ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per4.Rte_DampingSrlComSvcDft_Cnt_lgc.value)

#  define Rte_IWrite_CDDInterface_Per4_DftAsstTbl_Cnt_lgc(data) \
  ( \
    Rte_Task_10ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per4.Rte_DftAsstTbl_Cnt_lgc.value = (data) \
  )

#  define Rte_IWriteRef_CDDInterface_Per4_DftAsstTbl_Cnt_lgc() \
  (&Rte_Task_10ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per4.Rte_DftAsstTbl_Cnt_lgc.value)

#  define Rte_IWrite_CDDInterface_Per4_DrivingDynSrlComSvcDft_Cnt_lgc(data) \
  ( \
    Rte_Task_10ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per4.Rte_DrivingDynSrlComSvcDft_Cnt_lgc.value = (data) \
  )

#  define Rte_IWriteRef_CDDInterface_Per4_DrivingDynSrlComSvcDft_Cnt_lgc() \
  (&Rte_Task_10ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per4.Rte_DrivingDynSrlComSvcDft_Cnt_lgc.value)

#  define Rte_IWrite_CDDInterface_Per4_DwnldAsstGain_Uls_f32(data) \
  ( \
    Rte_Task_10ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per4.Rte_DwnldAsstGain_Uls_f32.value = (data) \
  )

#  define Rte_IWriteRef_CDDInterface_Per4_DwnldAsstGain_Uls_f32() \
  (&Rte_Task_10ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per4.Rte_DwnldAsstGain_Uls_f32.value)

#  define Rte_IWrite_CDDInterface_Per4_EOTImpactSrlComSvcDft_Cnt_lgc(data) \
  ( \
    Rte_Task_10ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per4.Rte_EOTImpactSrlComSvcDft_Cnt_lgc.value = (data) \
  )

#  define Rte_IWriteRef_CDDInterface_Per4_EOTImpactSrlComSvcDft_Cnt_lgc() \
  (&Rte_Task_10ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per4.Rte_EOTImpactSrlComSvcDft_Cnt_lgc.value)

#  define Rte_IWrite_CDDInterface_Per4_EOTThermalSrlComSvcDft_Cnt_lgc(data) \
  ( \
    Rte_Task_10ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per4.Rte_EOTThermalSrlComSvcDft_Cnt_lgc.value = (data) \
  )

#  define Rte_IWriteRef_CDDInterface_Per4_EOTThermalSrlComSvcDft_Cnt_lgc() \
  (&Rte_Task_10ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per4.Rte_EOTThermalSrlComSvcDft_Cnt_lgc.value)

#  define Rte_IWrite_CDDInterface_Per4_EngONSrlComSvcDft_Cnt_lgc(data) \
  ( \
    Rte_Task_10ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per4.Rte_EngONSrlComSvcDft_Cnt_lgc.value = (data) \
  )

#  define Rte_IWriteRef_CDDInterface_Per4_EngONSrlComSvcDft_Cnt_lgc() \
  (&Rte_Task_10ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per4.Rte_EngONSrlComSvcDft_Cnt_lgc.value)

#  define Rte_IWrite_CDDInterface_Per4_FreqDepDmpSrlComSvcDft_Cnt_lgc(data) \
  ( \
    Rte_Task_10ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per4.Rte_FreqDepDmpSrlComSvcDft_Cnt_lgc.value = (data) \
  )

#  define Rte_IWriteRef_CDDInterface_Per4_FreqDepDmpSrlComSvcDft_Cnt_lgc() \
  (&Rte_Task_10ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per4.Rte_FreqDepDmpSrlComSvcDft_Cnt_lgc.value)

#  define Rte_IWrite_CDDInterface_Per4_FricLrnSrlComSvcDft_Cnt_lgc(data) \
  ( \
    Rte_Task_10ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per4.Rte_FricLrnSrlComSvcDft_Cnt_lgc.value = (data) \
  )

#  define Rte_IWriteRef_CDDInterface_Per4_FricLrnSrlComSvcDft_Cnt_lgc() \
  (&Rte_Task_10ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per4.Rte_FricLrnSrlComSvcDft_Cnt_lgc.value)

#  define Rte_IWrite_CDDInterface_Per4_HysAddSrlComSvcDft_Cnt_lgc(data) \
  ( \
    Rte_Task_10ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per4.Rte_HysAddSrlComSvcDft_Cnt_lgc.value = (data) \
  )

#  define Rte_IWriteRef_CDDInterface_Per4_HysAddSrlComSvcDft_Cnt_lgc() \
  (&Rte_Task_10ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per4.Rte_HysAddSrlComSvcDft_Cnt_lgc.value)

#  define Rte_IWrite_CDDInterface_Per4_HystCompSrlComSvcDft_Cnt_lgc(data) \
  ( \
    Rte_Task_10ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per4.Rte_HystCompSrlComSvcDft_Cnt_lgc.value = (data) \
  )

#  define Rte_IWriteRef_CDDInterface_Per4_HystCompSrlComSvcDft_Cnt_lgc() \
  (&Rte_Task_10ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per4.Rte_HystCompSrlComSvcDft_Cnt_lgc.value)

#  define Rte_IWrite_CDDInterface_Per4_KinIntDiagSrlComSvcDft_Cnt_lgc(data) \
  ( \
    Rte_Task_10ms_10.Rte_TB.Rte_I_CDDInterface_KinIntDiagSrlComSvcDft_Cnt_lgc.value = (data) \
  )

#  define Rte_IWriteRef_CDDInterface_Per4_KinIntDiagSrlComSvcDft_Cnt_lgc() \
  (&Rte_Task_10ms_10.Rte_TB.Rte_I_CDDInterface_KinIntDiagSrlComSvcDft_Cnt_lgc.value)

#  define Rte_IWrite_CDDInterface_Per4_LimitSrlComSvcDft_Cnt_lgc(data) \
  ( \
    Rte_Task_10ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per4.Rte_LimitSrlComSvcDft_Cnt_lgc.value = (data) \
  )

#  define Rte_IWriteRef_CDDInterface_Per4_LimitSrlComSvcDft_Cnt_lgc() \
  (&Rte_Task_10ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per4.Rte_LimitSrlComSvcDft_Cnt_lgc.value)

#  define Rte_IWrite_CDDInterface_Per4_MEC_Cnt_enum(data) \
  ( \
    Rte_Task_10ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per4.Rte_MEC_Cnt_enum.value = (data) \
  )

#  define Rte_IWriteRef_CDDInterface_Per4_MEC_Cnt_enum() \
  (&Rte_Task_10ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per4.Rte_MEC_Cnt_enum.value)

#  define Rte_IWrite_CDDInterface_Per4_MfgDiagInhibit_Cnt_lgc(data) \
  ( \
    Rte_Task_10ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per4.Rte_MfgDiagInhibit_Cnt_lgc.value = (data) \
  )

#  define Rte_IWriteRef_CDDInterface_Per4_MfgDiagInhibit_Cnt_lgc() \
  (&Rte_Task_10ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per4.Rte_MfgDiagInhibit_Cnt_lgc.value)

#  define Rte_IWrite_CDDInterface_Per4_ModIdxSrlComSvcDft_Cnt_lgc(data) \
  ( \
    Rte_Task_10ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per4.Rte_ModIdxSrlComSvcDft_Cnt_lgc.value = (data) \
  )

#  define Rte_IWriteRef_CDDInterface_Per4_ModIdxSrlComSvcDft_Cnt_lgc() \
  (&Rte_Task_10ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per4.Rte_ModIdxSrlComSvcDft_Cnt_lgc.value)

#  define Rte_IWrite_CDDInterface_Per4_MtrParmNrmLrnSrlComSvcDft_Cnt_lgc(data) \
  ( \
    Rte_Task_10ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per4.Rte_MtrParmNrmLrnSrlComSvcDft_Cnt_lgc.value = (data) \
  )

#  define Rte_IWriteRef_CDDInterface_Per4_MtrParmNrmLrnSrlComSvcDft_Cnt_lgc() \
  (&Rte_Task_10ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per4.Rte_MtrParmNrmLrnSrlComSvcDft_Cnt_lgc.value)

#  define Rte_IWrite_CDDInterface_Per4_MtrVelNrmLrnSrlComSvcDft_Cnt_lgc(data) \
  ( \
    Rte_Task_10ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per4.Rte_MtrVelNrmLrnSrlComSvcDft_Cnt_lgc.value = (data) \
  )

#  define Rte_IWriteRef_CDDInterface_Per4_MtrVelNrmLrnSrlComSvcDft_Cnt_lgc() \
  (&Rte_Task_10ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per4.Rte_MtrVelNrmLrnSrlComSvcDft_Cnt_lgc.value)

#  define Rte_IWrite_CDDInterface_Per4_MultIgnSrlComSvcDft_Cnt_lgc(data) \
  ( \
    Rte_Task_10ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per4.Rte_MultIgnSrlComSvcDft_Cnt_lgc.value = (data) \
  )

#  define Rte_IWriteRef_CDDInterface_Per4_MultIgnSrlComSvcDft_Cnt_lgc() \
  (&Rte_Task_10ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per4.Rte_MultIgnSrlComSvcDft_Cnt_lgc.value)

#  define Rte_IWrite_CDDInterface_Per4_ParkAstSrlComSvcDft_Cnt_lgc(data) \
  ( \
    Rte_Task_10ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per4.Rte_ParkAstSrlComSvcDft_Cnt_lgc.value = (data) \
  )

#  define Rte_IWriteRef_CDDInterface_Per4_ParkAstSrlComSvcDft_Cnt_lgc() \
  (&Rte_Task_10ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per4.Rte_ParkAstSrlComSvcDft_Cnt_lgc.value)

#  define Rte_IWrite_CDDInterface_Per4_PullCompSrlComSvcDft_Cnt_lgc(data) \
  ( \
    Rte_Task_10ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per4.Rte_PullCompSrlComSvcDft_Cnt_lgc.value = (data) \
  )

#  define Rte_IWriteRef_CDDInterface_Per4_PullCompSrlComSvcDft_Cnt_lgc() \
  (&Rte_Task_10ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per4.Rte_PullCompSrlComSvcDft_Cnt_lgc.value)

#  define Rte_IWrite_CDDInterface_Per4_ReturnSrlComSvcDft_Cnt_lgc(data) \
  ( \
    Rte_Task_10ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per4.Rte_ReturnSrlComSvcDft_Cnt_lgc.value = (data) \
  )

#  define Rte_IWriteRef_CDDInterface_Per4_ReturnSrlComSvcDft_Cnt_lgc() \
  (&Rte_Task_10ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per4.Rte_ReturnSrlComSvcDft_Cnt_lgc.value)

#  define Rte_IWrite_CDDInterface_Per4_RxMsgsSrlComSvcDft_Cnt_lgc(data) \
  ( \
    Rte_Task_10ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per4.Rte_RxMsgsSrlComSvcDft_Cnt_lgc.value = (data) \
  )

#  define Rte_IWriteRef_CDDInterface_Per4_RxMsgsSrlComSvcDft_Cnt_lgc() \
  (&Rte_Task_10ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per4.Rte_RxMsgsSrlComSvcDft_Cnt_lgc.value)

#  define Rte_IWrite_CDDInterface_Per4_SrlComSvcDft_Cnt_b32(data) \
  ( \
    Rte_Task_10ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per4.Rte_SrlComSvcDft_Cnt_b32.value = (data) \
  )

#  define Rte_IWriteRef_CDDInterface_Per4_SrlComSvcDft_Cnt_b32() \
  (&Rte_Task_10ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per4.Rte_SrlComSvcDft_Cnt_b32.value)

#  define Rte_IWrite_CDDInterface_Per4_TOEOLDisable_Cnt_lgc(data) \
  ( \
    Rte_Task_10ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per4.Rte_TOEOLDisable_Cnt_lgc.value = (data) \
  )

#  define Rte_IWriteRef_CDDInterface_Per4_TOEOLDisable_Cnt_lgc() \
  (&Rte_Task_10ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per4.Rte_TOEOLDisable_Cnt_lgc.value)

#  define Rte_IWrite_CDDInterface_Per4_ThermalDCSrlComSvcDft_Cnt_lgc(data) \
  ( \
    Rte_Task_10ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per4.Rte_ThermalDCSrlComSvcDft_Cnt_lgc.value = (data) \
  )

#  define Rte_IWriteRef_CDDInterface_Per4_ThermalDCSrlComSvcDft_Cnt_lgc() \
  (&Rte_Task_10ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per4.Rte_ThermalDCSrlComSvcDft_Cnt_lgc.value)

#  define Rte_IWrite_CDDInterface_Per4_TrqRmpSrlComSvcDft_Cnt_lgc(data) \
  ( \
    Rte_Task_10ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per4.Rte_TrqRmpSrlComSvcDft_Cnt_lgc.value = (data) \
  )

#  define Rte_IWriteRef_CDDInterface_Per4_TrqRmpSrlComSvcDft_Cnt_lgc() \
  (&Rte_Task_10ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per4.Rte_TrqRmpSrlComSvcDft_Cnt_lgc.value)

#  define Rte_IWrite_CDDInterface_Per4_WIREnabled_Cnt_lgc(data) \
  ( \
    Rte_Task_10ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per4.Rte_WIREnabled_Cnt_lgc.value = (data) \
  )

#  define Rte_IWriteRef_CDDInterface_Per4_WIREnabled_Cnt_lgc() \
  (&Rte_Task_10ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per4.Rte_WIREnabled_Cnt_lgc.value)

#  define Rte_IWrite_CDDInterface_Per4_WhlImbRejSrlComSvcDft_Cnt_lgc(data) \
  ( \
    Rte_Task_10ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per4.Rte_WhlImbRejSrlComSvcDft_Cnt_lgc.value = (data) \
  )

#  define Rte_IWriteRef_CDDInterface_Per4_WhlImbRejSrlComSvcDft_Cnt_lgc() \
  (&Rte_Task_10ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per4.Rte_WhlImbRejSrlComSvcDft_Cnt_lgc.value)


/**********************************************************************************************************************
 * Rte_Mode_<p>_<m>
 *********************************************************************************************************************/
#  define Rte_Mode_SystemState_Mode() Rte_ModeMachine_StaMd_SystemState_Mode


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (unmapped) for synchronous C/S communication
 *********************************************************************************************************************/
#  define RTE_START_SEC_CDD_APPL_CODE
#  include "MemMap.h"
FUNC(void, RTE_CDD_APPL_CODE) CDDPorts_ApplyMtrElecMechPol(SInt8 MtrElecMechPol_Cnt_s8);
#  define RTE_STOP_SEC_CDD_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_CDDPorts_ApplyMtrElecMechPol(arg1) (CDDPorts_ApplyMtrElecMechPol(arg1), ((Std_ReturnType)RTE_E_OK))
#  define RTE_START_SEC_CDD_APPL_CODE
#  include "MemMap.h"
FUNC(void, RTE_CDD_APPL_CODE) CDDPorts_ClearPhsReasSum(UInt16 DataAccessBfr_Cnt_T_u16);
#  define RTE_STOP_SEC_CDD_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_CDDPorts_ClearPhsReasSum(arg1) (CDDPorts_ClearPhsReasSum(arg1), ((Std_ReturnType)RTE_E_OK))


# endif /* !defined(RTE_CORE) */


# define RTE_START_SEC_SA_CDDINTERFACE_APPL_CODE
# include "MemMap.h"

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

FUNC(void, RTE_SA_CDDINTERFACE_APPL_CODE) CDDInterface_Init1(void);

FUNC(void, RTE_SA_CDDINTERFACE_APPL_CODE) CDDInterface_Init2(void);

FUNC(void, RTE_SA_CDDINTERFACE_APPL_CODE) CDDInterface_Per1(void);

FUNC(void, RTE_SA_CDDINTERFACE_APPL_CODE) CDDInterface_Per2(void);

FUNC(void, RTE_SA_CDDINTERFACE_APPL_CODE) CDDInterface_Per4(void);

FUNC(void, RTE_SA_CDDINTERFACE_APPL_CODE) MtrVelCDDInterface_GetMtrVelSignals(P2VAR(SInt16, AUTOMATIC, RTE_SA_CDDINTERFACE_APPL_VAR) SinAvg_Uls_T_s2p13, P2VAR(SInt16, AUTOMATIC, RTE_SA_CDDINTERFACE_APPL_VAR) CosAvg_Uls_T_s2p13, P2VAR(UInt16, AUTOMATIC, RTE_SA_CDDINTERFACE_APPL_VAR) PosAvg_Rev_T_u0p16, P2VAR(UInt16, AUTOMATIC, RTE_SA_CDDINTERFACE_APPL_VAR) TimeAvg_uS_T_u16p0);

# define RTE_STOP_SEC_SA_CDDINTERFACE_APPL_CODE
# include "MemMap.h"

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

/* begin Fileversion check */
# ifndef SKIP_MAGIC_NUMBER
#  ifdef RTE_MAGIC_NUMBER
#   if RTE_MAGIC_NUMBER != 1468867288
#    error "The magic number of the generated file <C:/Sankar/Chrysler/Synergy/CL/Temp_work/Chrysler_LWR_EPS_TMS570/SwProject/Source/GenDataRte/Components/Rte_Sa_CDDInterface.h> is different. Please check time and date of the generated RTE files!"
#   endif
#  else
#   define RTE_MAGIC_NUMBER 1468867288
#  endif  /* RTE_MAGIC_NUMBER */
# endif  /* SKIP_MAGIC_NUMBER */
/* end Fileversion check */

#endif /* _RTE_SA_CDDINTERFACE_H */
