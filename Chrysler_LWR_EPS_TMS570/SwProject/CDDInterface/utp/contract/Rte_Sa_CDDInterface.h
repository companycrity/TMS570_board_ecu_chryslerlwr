/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  Copyright (c) 2006-2010 by Vector Informatik GmbH.                                             All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  Rte_Sa_CDDInterface.h
 *     Workspace:  C:/CMSynergy_Projects/Ford_S550_P552_EPS_TMS570/SwProject/CDDInterface/autosar
 *     SW-C Type:  Sa_CDDInterface
 *  Generated at:  Wed Apr 18 13:50:23 2012
 *
 *     Generator:  MICROSAR RTE Generator Version 2.17.2
 *       License:  License CBD1010122 valid for CBD1010122 Nexteer  GM MSR_SLP3_BSW_RTE_wGMLAN TexasInstruments TMS570 Texas Instruments
 *
 *   Description:  Application header file for SW-C <Sa_CDDInterface> (Contract Phase)
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_SA_CDDINTERFACE_H
# define _RTE_SA_CDDINTERFACE_H

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

typedef P2CONST(struct Rte_CDS_Sa_CDDInterface, TYPEDEF, RTE_CONST) Rte_Instance;


/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

# define Rte_InitValue_ADCMtrCurr1_Volts_f32 ((Float)0)
# define Rte_InitValue_ADCMtrCurr2_Volts_f32 ((Float)0)
# define Rte_InitValue_CommOffset_Cnt_u16 ((UInt16)0u)
# define Rte_InitValue_CorrMtrPosElec_Rev_f32 ((Float)0)
# define Rte_InitValue_Cos1RTAmpRec_Uls_f32 ((Float)0)
# define Rte_InitValue_Cos1RTOffset_Volts_f32 ((Float)0)
# define Rte_InitValue_Cos1Theta_Volts_f32 ((Float)0)
# define Rte_InitValue_DampingSrlComSvcDft_Cnt_lgc ((Boolean)FALSE)
# define Rte_InitValue_DaxIntegralGain_IPM_Uls_f32 ((Float)0)
# define Rte_InitValue_DaxIntegralGain_SPM_Uls_f32 ((Float)0)
# define Rte_InitValue_DaxPropotionalGain_IPM_Uls_f32 ((Float)0)
# define Rte_InitValue_DaxPropotionalGain_SPM_Uls_f32 ((Float)0)
# define Rte_InitValue_DftAsstTbl_Cnt_lgc ((Boolean)FALSE)
# define Rte_InitValue_DiagStsDefVehSpd_Cnt_lgc ((Boolean)FALSE)
# define Rte_InitValue_DrivingDynSrlComSvcDft_Cnt_lgc ((Boolean)FALSE)
# define Rte_InitValue_DutyCycleSmall_Cnt_u16 ((UInt16)0u)
# define Rte_InitValue_DwnldAsstGain_Uls_f32 ((Float)0)
# define Rte_InitValue_EOTImpactSrlComSvcDft_Cnt_lgc ((Boolean)FALSE)
# define Rte_InitValue_EOTThermalSrlComSvcDft_Cnt_lgc ((Boolean)FALSE)
# define Rte_InitValue_EngONSrlComSvcDft_Cnt_lgc ((Boolean)FALSE)
# define Rte_InitValue_EstKe_VpRadpS_f32 ((Float)0)
# define Rte_InitValue_ExpectedOnTimeA_Cnt_u32 ((UInt32)0u)
# define Rte_InitValue_ExpectedOnTimeB_Cnt_u32 ((UInt32)0u)
# define Rte_InitValue_ExpectedOnTimeC_Cnt_u32 ((UInt32)0u)
# define Rte_InitValue_FETFaultPhase_Cnt_enum ((FETPHASETYPE_ENUM)0u)
# define Rte_InitValue_FETFaultType_Cnt_enum ((FETFAULTTYPE_ENUM)0u)
# define Rte_InitValue_FreqDepDmpSrlComSvcDft_Cnt_lgc ((Boolean)FALSE)
# define Rte_InitValue_HysAddSrlComSvcDft_Cnt_lgc ((Boolean)FALSE)
# define Rte_InitValue_HystCompSrlComSvcDft_Cnt_lgc ((Boolean)FALSE)
# define Rte_InitValue_KinIntDiagSrlComSvcDft_Cnt_lgc ((Boolean)FALSE)
# define Rte_InitValue_LimitSrlComSvcDft_Cnt_lgc ((Boolean)FALSE)
# define Rte_InitValue_MEC_Cnt_enum ((ManufModeType)0u)
# define Rte_InitValue_MRFMtrVel_MtrRadpS_f32 ((Float)0)
# define Rte_InitValue_MeasuredOnTimeA_Cnt_u32 ((UInt32)0u)
# define Rte_InitValue_MeasuredOnTimeB_Cnt_u32 ((UInt32)0u)
# define Rte_InitValue_MeasuredOnTimeC_Cnt_u32 ((UInt32)0u)
# define Rte_InitValue_ModIdxFinal_Uls_f32 ((Float)0)
# define Rte_InitValue_ModIdxSrlComSvcDft_Cnt_lgc ((Boolean)FALSE)
# define Rte_InitValue_MtrCurr1TempOffset_Volt_f32 ((Float)0)
# define Rte_InitValue_MtrCurr2TempOffset_Volt_f32 ((Float)0)
# define Rte_InitValue_MtrCurrDax_Amp_f32 ((Float)0)
# define Rte_InitValue_MtrCurrDaxRef_IPM_Amp_f32 ((Float)0)
# define Rte_InitValue_MtrCurrDaxRef_SPM_Amp_f32 ((Float)0)
# define Rte_InitValue_MtrCurrK1_Amp_f32 ((Float)0)
# define Rte_InitValue_MtrCurrK2_Amp_f32 ((Float)0)
# define Rte_InitValue_MtrCurrQax_Amp_f32 ((Float)0)
# define Rte_InitValue_MtrCurrQax12Mag_Amp_f32 ((Float)0)
# define Rte_InitValue_MtrCurrQax12Ph_Rev_f32 ((Float)0)
# define Rte_InitValue_MtrCurrQax6Mag_Amp_f32 ((Float)0)
# define Rte_InitValue_MtrCurrQax6Ph_Rev_f32 ((Float)0)
# define Rte_InitValue_MtrCurrQaxRef_IPM_Amp_f32 ((Float)0)
# define Rte_InitValue_MtrCurrQaxRef_SPM_Amp_f32 ((Float)0)
# define Rte_InitValue_MtrParmNrmLrnSrlComSvcDft_Cnt_lgc ((Boolean)FALSE)
# define Rte_InitValue_MtrPosComputationDelay_IPM_Deg_f32 ((Float)0)
# define Rte_InitValue_MtrPosComputationDelay_SPM_Deg_f32 ((Float)0)
# define Rte_InitValue_MtrPosElec_Rev_f32 ((Float)0)
# define Rte_InitValue_MtrPosMech_Rev_f32 ((Float)0)
# define Rte_InitValue_MtrRevCntr_Cnt_s16 ((SInt16)0)
# define Rte_InitValue_MtrTrqCmdSign_IPM_Cnt_s16 ((SInt16)0)
# define Rte_InitValue_MtrTrqCmdSign_SPM_Cnt_s16 ((SInt16)0)
# define Rte_InitValue_MtrVelNrmLrnSrlComSvcDft_Cnt_lgc ((Boolean)FALSE)
# define Rte_InitValue_MtrVoltDaxFF_IPM_Volt_f32 ((Float)0)
# define Rte_InitValue_MtrVoltDaxFF_SPM_Volt_f32 ((Float)0)
# define Rte_InitValue_MtrVoltQaxFF_IPM_Volt_f32 ((Float)0)
# define Rte_InitValue_MtrVoltQaxFF_SPM_Volt_f32 ((Float)0)
# define Rte_InitValue_MultIgnSrlComSvcDft_Cnt_lgc ((Boolean)FALSE)
# define Rte_InitValue_ParkAstSrlComSvcDft_Cnt_lgc ((Boolean)FALSE)
# define Rte_InitValue_PhsReasA_Volts_f32 ((Float)0)
# define Rte_InitValue_PhsReasB_Volts_f32 ((Float)0)
# define Rte_InitValue_PhsReasC_Volts_f32 ((Float)0)
# define Rte_InitValue_PullCompSrlComSvcDft_Cnt_lgc ((Boolean)FALSE)
# define Rte_InitValue_QaxIntegralGain_IPM_Uls_f32 ((Float)0)
# define Rte_InitValue_QaxIntegralGain_SPM_Uls_f32 ((Float)0)
# define Rte_InitValue_QaxPropotionalGain_IPM_Uls_f32 ((Float)0)
# define Rte_InitValue_QaxPropotionalGain_SPM_Uls_f32 ((Float)0)
# define Rte_InitValue_ReturnSrlComSvcDft_Cnt_lgc ((Boolean)FALSE)
# define Rte_InitValue_RxMsgsSrlComSvcDft_Cnt_lgc ((Boolean)FALSE)
# define Rte_InitValue_SWDutyCycleA_Uls_f32 ((Float)0)
# define Rte_InitValue_SWDutyCycleB_Uls_f32 ((Float)0)
# define Rte_InitValue_SWDutyCycleC_Uls_f32 ((Float)0)
# define Rte_InitValue_Sin1RTAmpRec_Uls_f32 ((Float)0)
# define Rte_InitValue_Sin1RTOffset_Volts_f32 ((Float)0)
# define Rte_InitValue_Sin1Theta_Volts_f32 ((Float)0)
# define Rte_InitValue_SrlComSvcDft_Cnt_b32 ((UInt32)0u)
# define Rte_InitValue_ThermalDCSrlComSvcDft_Cnt_lgc ((Boolean)FALSE)
# define Rte_InitValue_TrqRmpSrlComSvcDft_Cnt_lgc ((Boolean)FALSE)
# define Rte_InitValue_Vecu_Volt_f32 ((Float)5)
# define Rte_InitValue_VehSpdValid_Cnt_lgc ((Boolean)FALSE)
# define Rte_InitValue_WIREnabled_Cnt_lgc ((Boolean)FALSE)
# define Rte_InitValue_WhlImbRejSrlComSvcDft_Cnt_lgc ((Boolean)FALSE)


# define RTE_START_SEC_CODE
# include "MemMap.h"

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/
FUNC(Rte_ModeType_StaMd_Mode, RTE_CODE) Rte_Mode_Sa_CDDInterface_SystemState_Mode(void);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Sa_CDDInterface_CDDPorts_ClearPhsReasSum(UInt16 DataAccessBfr_Cnt_T_u16);

# define RTE_STOP_SEC_CODE
# include "MemMap.h"



/**********************************************************************************************************************
 * Rte_IRead_<r>_<p>_<d>
 * Rte_IStatus_<r>_<p>_<d>
 * Rte_IWrite_<r>_<p>_<d>
 * Rte_IWriteRef_<r>_<p>_<d>
 * Rte_IInvalidate_<r>_<p>_<d>
 *********************************************************************************************************************/

# define Rte_IRead_CDDInterface_Init1_Cos1RTAmpRec_Uls_f32() \
  (Rte_Inst_Sa_CDDInterface->CDDInterface_Init1_Cos1RTAmpRec_Uls_f32->value)

# define Rte_IRead_CDDInterface_Init1_Cos1RTOffset_Volts_f32() \
  (Rte_Inst_Sa_CDDInterface->CDDInterface_Init1_Cos1RTOffset_Volts_f32->value)

# define Rte_IRead_CDDInterface_Init1_Sin1RTAmpRec_Uls_f32() \
  (Rte_Inst_Sa_CDDInterface->CDDInterface_Init1_Sin1RTAmpRec_Uls_f32->value)

# define Rte_IRead_CDDInterface_Init1_Sin1RTOffset_Volts_f32() \
  (Rte_Inst_Sa_CDDInterface->CDDInterface_Init1_Sin1RTOffset_Volts_f32->value)

# define Rte_IWrite_CDDInterface_Per1_ADCMtrCurr1_Volts_f32(data) \
  ( \
  Rte_Inst_Sa_CDDInterface->CDDInterface_Per1_ADCMtrCurr1_Volts_f32->value = (data) \
  )

# define Rte_IWriteRef_CDDInterface_Per1_ADCMtrCurr1_Volts_f32() \
  (&Rte_Inst_Sa_CDDInterface->CDDInterface_Per1_ADCMtrCurr1_Volts_f32->value)

# define Rte_IWrite_CDDInterface_Per1_ADCMtrCurr2_Volts_f32(data) \
  ( \
  Rte_Inst_Sa_CDDInterface->CDDInterface_Per1_ADCMtrCurr2_Volts_f32->value = (data) \
  )

# define Rte_IWriteRef_CDDInterface_Per1_ADCMtrCurr2_Volts_f32() \
  (&Rte_Inst_Sa_CDDInterface->CDDInterface_Per1_ADCMtrCurr2_Volts_f32->value)

# define Rte_IWrite_CDDInterface_Per1_CorrMtrPosElec_Rev_f32(data) \
  ( \
  Rte_Inst_Sa_CDDInterface->CDDInterface_Per1_CorrMtrPosElec_Rev_f32->value = (data) \
  )

# define Rte_IWriteRef_CDDInterface_Per1_CorrMtrPosElec_Rev_f32() \
  (&Rte_Inst_Sa_CDDInterface->CDDInterface_Per1_CorrMtrPosElec_Rev_f32->value)

# define Rte_IWrite_CDDInterface_Per1_Cos1Theta_Volts_f32(data) \
  ( \
  Rte_Inst_Sa_CDDInterface->CDDInterface_Per1_Cos1Theta_Volts_f32->value = (data) \
  )

# define Rte_IWriteRef_CDDInterface_Per1_Cos1Theta_Volts_f32() \
  (&Rte_Inst_Sa_CDDInterface->CDDInterface_Per1_Cos1Theta_Volts_f32->value)

# define Rte_IWrite_CDDInterface_Per1_DutyCycleSmall_Cnt_u16(data) \
  ( \
  Rte_Inst_Sa_CDDInterface->CDDInterface_Per1_DutyCycleSmall_Cnt_u16->value = (data) \
  )

# define Rte_IWriteRef_CDDInterface_Per1_DutyCycleSmall_Cnt_u16() \
  (&Rte_Inst_Sa_CDDInterface->CDDInterface_Per1_DutyCycleSmall_Cnt_u16->value)

# define Rte_IWrite_CDDInterface_Per1_ExpectedOnTimeA_Cnt_u32(data) \
  ( \
  Rte_Inst_Sa_CDDInterface->CDDInterface_Per1_ExpectedOnTimeA_Cnt_u32->value = (data) \
  )

# define Rte_IWriteRef_CDDInterface_Per1_ExpectedOnTimeA_Cnt_u32() \
  (&Rte_Inst_Sa_CDDInterface->CDDInterface_Per1_ExpectedOnTimeA_Cnt_u32->value)

# define Rte_IWrite_CDDInterface_Per1_ExpectedOnTimeB_Cnt_u32(data) \
  ( \
  Rte_Inst_Sa_CDDInterface->CDDInterface_Per1_ExpectedOnTimeB_Cnt_u32->value = (data) \
  )

# define Rte_IWriteRef_CDDInterface_Per1_ExpectedOnTimeB_Cnt_u32() \
  (&Rte_Inst_Sa_CDDInterface->CDDInterface_Per1_ExpectedOnTimeB_Cnt_u32->value)

# define Rte_IWrite_CDDInterface_Per1_ExpectedOnTimeC_Cnt_u32(data) \
  ( \
  Rte_Inst_Sa_CDDInterface->CDDInterface_Per1_ExpectedOnTimeC_Cnt_u32->value = (data) \
  )

# define Rte_IWriteRef_CDDInterface_Per1_ExpectedOnTimeC_Cnt_u32() \
  (&Rte_Inst_Sa_CDDInterface->CDDInterface_Per1_ExpectedOnTimeC_Cnt_u32->value)

# define Rte_IWrite_CDDInterface_Per1_MeasuredOnTimeA_Cnt_u32(data) \
  ( \
  Rte_Inst_Sa_CDDInterface->CDDInterface_Per1_MeasuredOnTimeA_Cnt_u32->value = (data) \
  )

# define Rte_IWriteRef_CDDInterface_Per1_MeasuredOnTimeA_Cnt_u32() \
  (&Rte_Inst_Sa_CDDInterface->CDDInterface_Per1_MeasuredOnTimeA_Cnt_u32->value)

# define Rte_IWrite_CDDInterface_Per1_MeasuredOnTimeB_Cnt_u32(data) \
  ( \
  Rte_Inst_Sa_CDDInterface->CDDInterface_Per1_MeasuredOnTimeB_Cnt_u32->value = (data) \
  )

# define Rte_IWriteRef_CDDInterface_Per1_MeasuredOnTimeB_Cnt_u32() \
  (&Rte_Inst_Sa_CDDInterface->CDDInterface_Per1_MeasuredOnTimeB_Cnt_u32->value)

# define Rte_IWrite_CDDInterface_Per1_MeasuredOnTimeC_Cnt_u32(data) \
  ( \
  Rte_Inst_Sa_CDDInterface->CDDInterface_Per1_MeasuredOnTimeC_Cnt_u32->value = (data) \
  )

# define Rte_IWriteRef_CDDInterface_Per1_MeasuredOnTimeC_Cnt_u32() \
  (&Rte_Inst_Sa_CDDInterface->CDDInterface_Per1_MeasuredOnTimeC_Cnt_u32->value)

# define Rte_IWrite_CDDInterface_Per1_ModIdxFinal_Uls_f32(data) \
  ( \
  Rte_Inst_Sa_CDDInterface->CDDInterface_Per1_ModIdxFinal_Uls_f32->value = (data) \
  )

# define Rte_IWriteRef_CDDInterface_Per1_ModIdxFinal_Uls_f32() \
  (&Rte_Inst_Sa_CDDInterface->CDDInterface_Per1_ModIdxFinal_Uls_f32->value)

# define Rte_IWrite_CDDInterface_Per1_MtrCurrDax_Amp_f32(data) \
  ( \
  Rte_Inst_Sa_CDDInterface->CDDInterface_Per1_MtrCurrDax_Amp_f32->value = (data) \
  )

# define Rte_IWriteRef_CDDInterface_Per1_MtrCurrDax_Amp_f32() \
  (&Rte_Inst_Sa_CDDInterface->CDDInterface_Per1_MtrCurrDax_Amp_f32->value)

# define Rte_IWrite_CDDInterface_Per1_MtrCurrK1_Amp_f32(data) \
  ( \
  Rte_Inst_Sa_CDDInterface->CDDInterface_Per1_MtrCurrK1_Amp_f32->value = (data) \
  )

# define Rte_IWriteRef_CDDInterface_Per1_MtrCurrK1_Amp_f32() \
  (&Rte_Inst_Sa_CDDInterface->CDDInterface_Per1_MtrCurrK1_Amp_f32->value)

# define Rte_IWrite_CDDInterface_Per1_MtrCurrK2_Amp_f32(data) \
  ( \
  Rte_Inst_Sa_CDDInterface->CDDInterface_Per1_MtrCurrK2_Amp_f32->value = (data) \
  )

# define Rte_IWriteRef_CDDInterface_Per1_MtrCurrK2_Amp_f32() \
  (&Rte_Inst_Sa_CDDInterface->CDDInterface_Per1_MtrCurrK2_Amp_f32->value)

# define Rte_IWrite_CDDInterface_Per1_MtrCurrQax_Amp_f32(data) \
  ( \
  Rte_Inst_Sa_CDDInterface->CDDInterface_Per1_MtrCurrQax_Amp_f32->value = (data) \
  )

# define Rte_IWriteRef_CDDInterface_Per1_MtrCurrQax_Amp_f32() \
  (&Rte_Inst_Sa_CDDInterface->CDDInterface_Per1_MtrCurrQax_Amp_f32->value)

# define Rte_IWrite_CDDInterface_Per1_MtrPosElec_Rev_f32(data) \
  ( \
  Rte_Inst_Sa_CDDInterface->CDDInterface_Per1_MtrPosElec_Rev_f32->value = (data) \
  )

# define Rte_IWriteRef_CDDInterface_Per1_MtrPosElec_Rev_f32() \
  (&Rte_Inst_Sa_CDDInterface->CDDInterface_Per1_MtrPosElec_Rev_f32->value)

# define Rte_IWrite_CDDInterface_Per1_MtrPosMech_Rev_f32(data) \
  ( \
  Rte_Inst_Sa_CDDInterface->CDDInterface_Per1_MtrPosMech_Rev_f32->value = (data) \
  )

# define Rte_IWriteRef_CDDInterface_Per1_MtrPosMech_Rev_f32() \
  (&Rte_Inst_Sa_CDDInterface->CDDInterface_Per1_MtrPosMech_Rev_f32->value)

# define Rte_IWrite_CDDInterface_Per1_MtrRevCntr_Cnt_s16(data) \
  ( \
  Rte_Inst_Sa_CDDInterface->CDDInterface_Per1_MtrRevCntr_Cnt_s16->value = (data) \
  )

# define Rte_IWriteRef_CDDInterface_Per1_MtrRevCntr_Cnt_s16() \
  (&Rte_Inst_Sa_CDDInterface->CDDInterface_Per1_MtrRevCntr_Cnt_s16->value)

# define Rte_IWrite_CDDInterface_Per1_PhsReasA_Volts_f32(data) \
  ( \
  Rte_Inst_Sa_CDDInterface->CDDInterface_Per1_PhsReasA_Volts_f32->value = (data) \
  )

# define Rte_IWriteRef_CDDInterface_Per1_PhsReasA_Volts_f32() \
  (&Rte_Inst_Sa_CDDInterface->CDDInterface_Per1_PhsReasA_Volts_f32->value)

# define Rte_IWrite_CDDInterface_Per1_PhsReasB_Volts_f32(data) \
  ( \
  Rte_Inst_Sa_CDDInterface->CDDInterface_Per1_PhsReasB_Volts_f32->value = (data) \
  )

# define Rte_IWriteRef_CDDInterface_Per1_PhsReasB_Volts_f32() \
  (&Rte_Inst_Sa_CDDInterface->CDDInterface_Per1_PhsReasB_Volts_f32->value)

# define Rte_IWrite_CDDInterface_Per1_PhsReasC_Volts_f32(data) \
  ( \
  Rte_Inst_Sa_CDDInterface->CDDInterface_Per1_PhsReasC_Volts_f32->value = (data) \
  )

# define Rte_IWriteRef_CDDInterface_Per1_PhsReasC_Volts_f32() \
  (&Rte_Inst_Sa_CDDInterface->CDDInterface_Per1_PhsReasC_Volts_f32->value)

# define Rte_IWrite_CDDInterface_Per1_SWDutyCycleA_Uls_f32(data) \
  ( \
  Rte_Inst_Sa_CDDInterface->CDDInterface_Per1_SWDutyCycleA_Uls_f32->value = (data) \
  )

# define Rte_IWriteRef_CDDInterface_Per1_SWDutyCycleA_Uls_f32() \
  (&Rte_Inst_Sa_CDDInterface->CDDInterface_Per1_SWDutyCycleA_Uls_f32->value)

# define Rte_IWrite_CDDInterface_Per1_SWDutyCycleB_Uls_f32(data) \
  ( \
  Rte_Inst_Sa_CDDInterface->CDDInterface_Per1_SWDutyCycleB_Uls_f32->value = (data) \
  )

# define Rte_IWriteRef_CDDInterface_Per1_SWDutyCycleB_Uls_f32() \
  (&Rte_Inst_Sa_CDDInterface->CDDInterface_Per1_SWDutyCycleB_Uls_f32->value)

# define Rte_IWrite_CDDInterface_Per1_SWDutyCycleC_Uls_f32(data) \
  ( \
  Rte_Inst_Sa_CDDInterface->CDDInterface_Per1_SWDutyCycleC_Uls_f32->value = (data) \
  )

# define Rte_IWriteRef_CDDInterface_Per1_SWDutyCycleC_Uls_f32() \
  (&Rte_Inst_Sa_CDDInterface->CDDInterface_Per1_SWDutyCycleC_Uls_f32->value)

# define Rte_IWrite_CDDInterface_Per1_Sin1Theta_Volts_f32(data) \
  ( \
  Rte_Inst_Sa_CDDInterface->CDDInterface_Per1_Sin1Theta_Volts_f32->value = (data) \
  )

# define Rte_IWriteRef_CDDInterface_Per1_Sin1Theta_Volts_f32() \
  (&Rte_Inst_Sa_CDDInterface->CDDInterface_Per1_Sin1Theta_Volts_f32->value)

# define Rte_IRead_CDDInterface_Per2_CommOffset_Cnt_u16() \
  (Rte_Inst_Sa_CDDInterface->CDDInterface_Per2_CommOffset_Cnt_u16->value)

# define Rte_IRead_CDDInterface_Per2_DaxIntegralGain_IPM_Uls_f32() \
  (Rte_Inst_Sa_CDDInterface->CDDInterface_Per2_DaxIntegralGain_IPM_Uls_f32->value)

# define Rte_IRead_CDDInterface_Per2_DaxIntegralGain_SPM_Uls_f32() \
  (Rte_Inst_Sa_CDDInterface->CDDInterface_Per2_DaxIntegralGain_SPM_Uls_f32->value)

# define Rte_IRead_CDDInterface_Per2_DaxPropotionalGain_IPM_Uls_f32() \
  (Rte_Inst_Sa_CDDInterface->CDDInterface_Per2_DaxPropotionalGain_IPM_Uls_f32->value)

# define Rte_IRead_CDDInterface_Per2_DaxPropotionalGain_SPM_Uls_f32() \
  (Rte_Inst_Sa_CDDInterface->CDDInterface_Per2_DaxPropotionalGain_SPM_Uls_f32->value)

# define Rte_IRead_CDDInterface_Per2_EstKe_VpRadpS_f32() \
  (Rte_Inst_Sa_CDDInterface->CDDInterface_Per2_EstKe_VpRadpS_f32->value)

# define Rte_IRead_CDDInterface_Per2_MRFMtrVel_MtrRadpS_f32() \
  (Rte_Inst_Sa_CDDInterface->CDDInterface_Per2_MRFMtrVel_MtrRadpS_f32->value)

# define Rte_IRead_CDDInterface_Per2_MtrCurr1TempOffset_Volt_f32() \
  (Rte_Inst_Sa_CDDInterface->CDDInterface_Per2_MtrCurr1TempOffset_Volt_f32->value)

# define Rte_IRead_CDDInterface_Per2_MtrCurr2TempOffset_Volt_f32() \
  (Rte_Inst_Sa_CDDInterface->CDDInterface_Per2_MtrCurr2TempOffset_Volt_f32->value)

# define Rte_IRead_CDDInterface_Per2_MtrCurrDaxRef_IPM_Amp_f32() \
  (Rte_Inst_Sa_CDDInterface->CDDInterface_Per2_MtrCurrDaxRef_IPM_Amp_f32->value)

# define Rte_IRead_CDDInterface_Per2_MtrCurrDaxRef_SPM_Amp_f32() \
  (Rte_Inst_Sa_CDDInterface->CDDInterface_Per2_MtrCurrDaxRef_SPM_Amp_f32->value)

# define Rte_IRead_CDDInterface_Per2_MtrCurrQax12Mag_Amp_f32() \
  (Rte_Inst_Sa_CDDInterface->CDDInterface_Per2_MtrCurrQax12Mag_Amp_f32->value)

# define Rte_IRead_CDDInterface_Per2_MtrCurrQax12Ph_Rev_f32() \
  (Rte_Inst_Sa_CDDInterface->CDDInterface_Per2_MtrCurrQax12Ph_Rev_f32->value)

# define Rte_IRead_CDDInterface_Per2_MtrCurrQax6Mag_Amp_f32() \
  (Rte_Inst_Sa_CDDInterface->CDDInterface_Per2_MtrCurrQax6Mag_Amp_f32->value)

# define Rte_IRead_CDDInterface_Per2_MtrCurrQax6Ph_Rev_f32() \
  (Rte_Inst_Sa_CDDInterface->CDDInterface_Per2_MtrCurrQax6Ph_Rev_f32->value)

# define Rte_IRead_CDDInterface_Per2_MtrCurrQaxRef_IPM_Amp_f32() \
  (Rte_Inst_Sa_CDDInterface->CDDInterface_Per2_MtrCurrQaxRef_IPM_Amp_f32->value)

# define Rte_IRead_CDDInterface_Per2_MtrCurrQaxRef_SPM_Amp_f32() \
  (Rte_Inst_Sa_CDDInterface->CDDInterface_Per2_MtrCurrQaxRef_SPM_Amp_f32->value)

# define Rte_IRead_CDDInterface_Per2_MtrPosComputationDelay_IPM_Deg_f32() \
  (Rte_Inst_Sa_CDDInterface->CDDInterface_Per2_MtrPosComputationDelay_IPM_Deg_f32->value)

# define Rte_IRead_CDDInterface_Per2_MtrPosComputationDelay_SPM_Deg_f32() \
  (Rte_Inst_Sa_CDDInterface->CDDInterface_Per2_MtrPosComputationDelay_SPM_Deg_f32->value)

# define Rte_IRead_CDDInterface_Per2_MtrTrqCmdSign_IPM_Cnt_s16() \
  (Rte_Inst_Sa_CDDInterface->CDDInterface_Per2_MtrTrqCmdSign_IPM_Cnt_s16->value)

# define Rte_IRead_CDDInterface_Per2_MtrTrqCmdSign_SPM_Cnt_s16() \
  (Rte_Inst_Sa_CDDInterface->CDDInterface_Per2_MtrTrqCmdSign_SPM_Cnt_s16->value)

# define Rte_IRead_CDDInterface_Per2_MtrVoltDaxFF_IPM_Volt_f32() \
  (Rte_Inst_Sa_CDDInterface->CDDInterface_Per2_MtrVoltDaxFF_IPM_Volt_f32->value)

# define Rte_IRead_CDDInterface_Per2_MtrVoltDaxFF_SPM_Volt_f32() \
  (Rte_Inst_Sa_CDDInterface->CDDInterface_Per2_MtrVoltDaxFF_SPM_Volt_f32->value)

# define Rte_IRead_CDDInterface_Per2_MtrVoltQaxFF_IPM_Volt_f32() \
  (Rte_Inst_Sa_CDDInterface->CDDInterface_Per2_MtrVoltQaxFF_IPM_Volt_f32->value)

# define Rte_IRead_CDDInterface_Per2_MtrVoltQaxFF_SPM_Volt_f32() \
  (Rte_Inst_Sa_CDDInterface->CDDInterface_Per2_MtrVoltQaxFF_SPM_Volt_f32->value)

# define Rte_IRead_CDDInterface_Per2_QaxIntegralGain_IPM_Uls_f32() \
  (Rte_Inst_Sa_CDDInterface->CDDInterface_Per2_QaxIntegralGain_IPM_Uls_f32->value)

# define Rte_IRead_CDDInterface_Per2_QaxIntegralGain_SPM_Uls_f32() \
  (Rte_Inst_Sa_CDDInterface->CDDInterface_Per2_QaxIntegralGain_SPM_Uls_f32->value)

# define Rte_IRead_CDDInterface_Per2_QaxPropotionalGain_IPM_Uls_f32() \
  (Rte_Inst_Sa_CDDInterface->CDDInterface_Per2_QaxPropotionalGain_IPM_Uls_f32->value)

# define Rte_IRead_CDDInterface_Per2_QaxPropotionalGain_SPM_Uls_f32() \
  (Rte_Inst_Sa_CDDInterface->CDDInterface_Per2_QaxPropotionalGain_SPM_Uls_f32->value)

# define Rte_IRead_CDDInterface_Per2_Vecu_Volt_f32() \
  (Rte_Inst_Sa_CDDInterface->CDDInterface_Per2_Vecu_Volt_f32->value)

# define Rte_IRead_CDDInterface_Per3_Cos1RTAmpRec_Uls_f32() \
  (Rte_Inst_Sa_CDDInterface->CDDInterface_Per3_Cos1RTAmpRec_Uls_f32->value)

# define Rte_IRead_CDDInterface_Per3_Cos1RTOffset_Volts_f32() \
  (Rte_Inst_Sa_CDDInterface->CDDInterface_Per3_Cos1RTOffset_Volts_f32->value)

# define Rte_IRead_CDDInterface_Per3_FETFaultPhase_Cnt_enum() \
  (Rte_Inst_Sa_CDDInterface->CDDInterface_Per3_FETFaultPhase_Cnt_enum->value)

# define Rte_IRead_CDDInterface_Per3_FETFaultType_Cnt_enum() \
  (Rte_Inst_Sa_CDDInterface->CDDInterface_Per3_FETFaultType_Cnt_enum->value)

# define Rte_IRead_CDDInterface_Per3_Sin1RTAmpRec_Uls_f32() \
  (Rte_Inst_Sa_CDDInterface->CDDInterface_Per3_Sin1RTAmpRec_Uls_f32->value)

# define Rte_IRead_CDDInterface_Per3_Sin1RTOffset_Volts_f32() \
  (Rte_Inst_Sa_CDDInterface->CDDInterface_Per3_Sin1RTOffset_Volts_f32->value)

# define Rte_IRead_CDDInterface_Per4_DiagStsDefVehSpd_Cnt_lgc() \
  (Rte_Inst_Sa_CDDInterface->CDDInterface_Per4_DiagStsDefVehSpd_Cnt_lgc->value)

# define Rte_IWrite_CDDInterface_Per4_DampingSrlComSvcDft_Cnt_lgc(data) \
  ( \
  Rte_Inst_Sa_CDDInterface->CDDInterface_Per4_DampingSrlComSvcDft_Cnt_lgc->value = (data) \
  )

# define Rte_IWriteRef_CDDInterface_Per4_DampingSrlComSvcDft_Cnt_lgc() \
  (&Rte_Inst_Sa_CDDInterface->CDDInterface_Per4_DampingSrlComSvcDft_Cnt_lgc->value)

# define Rte_IWrite_CDDInterface_Per4_DftAsstTbl_Cnt_lgc(data) \
  ( \
  Rte_Inst_Sa_CDDInterface->CDDInterface_Per4_DftAsstTbl_Cnt_lgc->value = (data) \
  )

# define Rte_IWriteRef_CDDInterface_Per4_DftAsstTbl_Cnt_lgc() \
  (&Rte_Inst_Sa_CDDInterface->CDDInterface_Per4_DftAsstTbl_Cnt_lgc->value)

# define Rte_IWrite_CDDInterface_Per4_DrivingDynSrlComSvcDft_Cnt_lgc(data) \
  ( \
  Rte_Inst_Sa_CDDInterface->CDDInterface_Per4_DrivingDynSrlComSvcDft_Cnt_lgc->value = (data) \
  )

# define Rte_IWriteRef_CDDInterface_Per4_DrivingDynSrlComSvcDft_Cnt_lgc() \
  (&Rte_Inst_Sa_CDDInterface->CDDInterface_Per4_DrivingDynSrlComSvcDft_Cnt_lgc->value)

# define Rte_IWrite_CDDInterface_Per4_DwnldAsstGain_Uls_f32(data) \
  ( \
  Rte_Inst_Sa_CDDInterface->CDDInterface_Per4_DwnldAsstGain_Uls_f32->value = (data) \
  )

# define Rte_IWriteRef_CDDInterface_Per4_DwnldAsstGain_Uls_f32() \
  (&Rte_Inst_Sa_CDDInterface->CDDInterface_Per4_DwnldAsstGain_Uls_f32->value)

# define Rte_IWrite_CDDInterface_Per4_EOTImpactSrlComSvcDft_Cnt_lgc(data) \
  ( \
  Rte_Inst_Sa_CDDInterface->CDDInterface_Per4_EOTImpactSrlComSvcDft_Cnt_lgc->value = (data) \
  )

# define Rte_IWriteRef_CDDInterface_Per4_EOTImpactSrlComSvcDft_Cnt_lgc() \
  (&Rte_Inst_Sa_CDDInterface->CDDInterface_Per4_EOTImpactSrlComSvcDft_Cnt_lgc->value)

# define Rte_IWrite_CDDInterface_Per4_EOTThermalSrlComSvcDft_Cnt_lgc(data) \
  ( \
  Rte_Inst_Sa_CDDInterface->CDDInterface_Per4_EOTThermalSrlComSvcDft_Cnt_lgc->value = (data) \
  )

# define Rte_IWriteRef_CDDInterface_Per4_EOTThermalSrlComSvcDft_Cnt_lgc() \
  (&Rte_Inst_Sa_CDDInterface->CDDInterface_Per4_EOTThermalSrlComSvcDft_Cnt_lgc->value)

# define Rte_IWrite_CDDInterface_Per4_EngONSrlComSvcDft_Cnt_lgc(data) \
  ( \
  Rte_Inst_Sa_CDDInterface->CDDInterface_Per4_EngONSrlComSvcDft_Cnt_lgc->value = (data) \
  )

# define Rte_IWriteRef_CDDInterface_Per4_EngONSrlComSvcDft_Cnt_lgc() \
  (&Rte_Inst_Sa_CDDInterface->CDDInterface_Per4_EngONSrlComSvcDft_Cnt_lgc->value)

# define Rte_IWrite_CDDInterface_Per4_FreqDepDmpSrlComSvcDft_Cnt_lgc(data) \
  ( \
  Rte_Inst_Sa_CDDInterface->CDDInterface_Per4_FreqDepDmpSrlComSvcDft_Cnt_lgc->value = (data) \
  )

# define Rte_IWriteRef_CDDInterface_Per4_FreqDepDmpSrlComSvcDft_Cnt_lgc() \
  (&Rte_Inst_Sa_CDDInterface->CDDInterface_Per4_FreqDepDmpSrlComSvcDft_Cnt_lgc->value)

# define Rte_IWrite_CDDInterface_Per4_HysAddSrlComSvcDft_Cnt_lgc(data) \
  ( \
  Rte_Inst_Sa_CDDInterface->CDDInterface_Per4_HysAddSrlComSvcDft_Cnt_lgc->value = (data) \
  )

# define Rte_IWriteRef_CDDInterface_Per4_HysAddSrlComSvcDft_Cnt_lgc() \
  (&Rte_Inst_Sa_CDDInterface->CDDInterface_Per4_HysAddSrlComSvcDft_Cnt_lgc->value)

# define Rte_IWrite_CDDInterface_Per4_HystCompSrlComSvcDft_Cnt_lgc(data) \
  ( \
  Rte_Inst_Sa_CDDInterface->CDDInterface_Per4_HystCompSrlComSvcDft_Cnt_lgc->value = (data) \
  )

# define Rte_IWriteRef_CDDInterface_Per4_HystCompSrlComSvcDft_Cnt_lgc() \
  (&Rte_Inst_Sa_CDDInterface->CDDInterface_Per4_HystCompSrlComSvcDft_Cnt_lgc->value)

# define Rte_IWrite_CDDInterface_Per4_KinIntDiagSrlComSvcDft_Cnt_lgc(data) \
  ( \
  Rte_Inst_Sa_CDDInterface->CDDInterface_Per4_KinIntDiagSrlComSvcDft_Cnt_lgc->value = (data) \
  )

# define Rte_IWriteRef_CDDInterface_Per4_KinIntDiagSrlComSvcDft_Cnt_lgc() \
  (&Rte_Inst_Sa_CDDInterface->CDDInterface_Per4_KinIntDiagSrlComSvcDft_Cnt_lgc->value)

# define Rte_IWrite_CDDInterface_Per4_LimitSrlComSvcDft_Cnt_lgc(data) \
  ( \
  Rte_Inst_Sa_CDDInterface->CDDInterface_Per4_LimitSrlComSvcDft_Cnt_lgc->value = (data) \
  )

# define Rte_IWriteRef_CDDInterface_Per4_LimitSrlComSvcDft_Cnt_lgc() \
  (&Rte_Inst_Sa_CDDInterface->CDDInterface_Per4_LimitSrlComSvcDft_Cnt_lgc->value)

# define Rte_IWrite_CDDInterface_Per4_MEC_Cnt_enum(data) \
  ( \
  Rte_Inst_Sa_CDDInterface->CDDInterface_Per4_MEC_Cnt_enum->value = (data) \
  )

# define Rte_IWriteRef_CDDInterface_Per4_MEC_Cnt_enum() \
  (&Rte_Inst_Sa_CDDInterface->CDDInterface_Per4_MEC_Cnt_enum->value)

# define Rte_IWrite_CDDInterface_Per4_ModIdxSrlComSvcDft_Cnt_lgc(data) \
  ( \
  Rte_Inst_Sa_CDDInterface->CDDInterface_Per4_ModIdxSrlComSvcDft_Cnt_lgc->value = (data) \
  )

# define Rte_IWriteRef_CDDInterface_Per4_ModIdxSrlComSvcDft_Cnt_lgc() \
  (&Rte_Inst_Sa_CDDInterface->CDDInterface_Per4_ModIdxSrlComSvcDft_Cnt_lgc->value)

# define Rte_IWrite_CDDInterface_Per4_MtrParmNrmLrnSrlComSvcDft_Cnt_lgc(data) \
  ( \
  Rte_Inst_Sa_CDDInterface->CDDInterface_Per4_MtrParmNrmLrnSrlComSvcDft_Cnt_lgc->value = (data) \
  )

# define Rte_IWriteRef_CDDInterface_Per4_MtrParmNrmLrnSrlComSvcDft_Cnt_lgc() \
  (&Rte_Inst_Sa_CDDInterface->CDDInterface_Per4_MtrParmNrmLrnSrlComSvcDft_Cnt_lgc->value)

# define Rte_IWrite_CDDInterface_Per4_MtrVelNrmLrnSrlComSvcDft_Cnt_lgc(data) \
  ( \
  Rte_Inst_Sa_CDDInterface->CDDInterface_Per4_MtrVelNrmLrnSrlComSvcDft_Cnt_lgc->value = (data) \
  )

# define Rte_IWriteRef_CDDInterface_Per4_MtrVelNrmLrnSrlComSvcDft_Cnt_lgc() \
  (&Rte_Inst_Sa_CDDInterface->CDDInterface_Per4_MtrVelNrmLrnSrlComSvcDft_Cnt_lgc->value)

# define Rte_IWrite_CDDInterface_Per4_MultIgnSrlComSvcDft_Cnt_lgc(data) \
  ( \
  Rte_Inst_Sa_CDDInterface->CDDInterface_Per4_MultIgnSrlComSvcDft_Cnt_lgc->value = (data) \
  )

# define Rte_IWriteRef_CDDInterface_Per4_MultIgnSrlComSvcDft_Cnt_lgc() \
  (&Rte_Inst_Sa_CDDInterface->CDDInterface_Per4_MultIgnSrlComSvcDft_Cnt_lgc->value)

# define Rte_IWrite_CDDInterface_Per4_ParkAstSrlComSvcDft_Cnt_lgc(data) \
  ( \
  Rte_Inst_Sa_CDDInterface->CDDInterface_Per4_ParkAstSrlComSvcDft_Cnt_lgc->value = (data) \
  )

# define Rte_IWriteRef_CDDInterface_Per4_ParkAstSrlComSvcDft_Cnt_lgc() \
  (&Rte_Inst_Sa_CDDInterface->CDDInterface_Per4_ParkAstSrlComSvcDft_Cnt_lgc->value)

# define Rte_IWrite_CDDInterface_Per4_PullCompSrlComSvcDft_Cnt_lgc(data) \
  ( \
  Rte_Inst_Sa_CDDInterface->CDDInterface_Per4_PullCompSrlComSvcDft_Cnt_lgc->value = (data) \
  )

# define Rte_IWriteRef_CDDInterface_Per4_PullCompSrlComSvcDft_Cnt_lgc() \
  (&Rte_Inst_Sa_CDDInterface->CDDInterface_Per4_PullCompSrlComSvcDft_Cnt_lgc->value)

# define Rte_IWrite_CDDInterface_Per4_ReturnSrlComSvcDft_Cnt_lgc(data) \
  ( \
  Rte_Inst_Sa_CDDInterface->CDDInterface_Per4_ReturnSrlComSvcDft_Cnt_lgc->value = (data) \
  )

# define Rte_IWriteRef_CDDInterface_Per4_ReturnSrlComSvcDft_Cnt_lgc() \
  (&Rte_Inst_Sa_CDDInterface->CDDInterface_Per4_ReturnSrlComSvcDft_Cnt_lgc->value)

# define Rte_IWrite_CDDInterface_Per4_RxMsgsSrlComSvcDft_Cnt_lgc(data) \
  ( \
  Rte_Inst_Sa_CDDInterface->CDDInterface_Per4_RxMsgsSrlComSvcDft_Cnt_lgc->value = (data) \
  )

# define Rte_IWriteRef_CDDInterface_Per4_RxMsgsSrlComSvcDft_Cnt_lgc() \
  (&Rte_Inst_Sa_CDDInterface->CDDInterface_Per4_RxMsgsSrlComSvcDft_Cnt_lgc->value)

# define Rte_IWrite_CDDInterface_Per4_SrlComSvcDft_Cnt_b32(data) \
  ( \
  Rte_Inst_Sa_CDDInterface->CDDInterface_Per4_SrlComSvcDft_Cnt_b32->value = (data) \
  )

# define Rte_IWriteRef_CDDInterface_Per4_SrlComSvcDft_Cnt_b32() \
  (&Rte_Inst_Sa_CDDInterface->CDDInterface_Per4_SrlComSvcDft_Cnt_b32->value)

# define Rte_IWrite_CDDInterface_Per4_ThermalDCSrlComSvcDft_Cnt_lgc(data) \
  ( \
  Rte_Inst_Sa_CDDInterface->CDDInterface_Per4_ThermalDCSrlComSvcDft_Cnt_lgc->value = (data) \
  )

# define Rte_IWriteRef_CDDInterface_Per4_ThermalDCSrlComSvcDft_Cnt_lgc() \
  (&Rte_Inst_Sa_CDDInterface->CDDInterface_Per4_ThermalDCSrlComSvcDft_Cnt_lgc->value)

# define Rte_IWrite_CDDInterface_Per4_TrqRmpSrlComSvcDft_Cnt_lgc(data) \
  ( \
  Rte_Inst_Sa_CDDInterface->CDDInterface_Per4_TrqRmpSrlComSvcDft_Cnt_lgc->value = (data) \
  )

# define Rte_IWriteRef_CDDInterface_Per4_TrqRmpSrlComSvcDft_Cnt_lgc() \
  (&Rte_Inst_Sa_CDDInterface->CDDInterface_Per4_TrqRmpSrlComSvcDft_Cnt_lgc->value)

# define Rte_IWrite_CDDInterface_Per4_VehSpdValid_Cnt_lgc(data) \
  ( \
  Rte_Inst_Sa_CDDInterface->CDDInterface_Per4_VehSpdValid_Cnt_lgc->value = (data) \
  )

# define Rte_IWriteRef_CDDInterface_Per4_VehSpdValid_Cnt_lgc() \
  (&Rte_Inst_Sa_CDDInterface->CDDInterface_Per4_VehSpdValid_Cnt_lgc->value)

# define Rte_IWrite_CDDInterface_Per4_WIREnabled_Cnt_lgc(data) \
  ( \
  Rte_Inst_Sa_CDDInterface->CDDInterface_Per4_WIREnabled_Cnt_lgc->value = (data) \
  )

# define Rte_IWriteRef_CDDInterface_Per4_WIREnabled_Cnt_lgc() \
  (&Rte_Inst_Sa_CDDInterface->CDDInterface_Per4_WIREnabled_Cnt_lgc->value)

# define Rte_IWrite_CDDInterface_Per4_WhlImbRejSrlComSvcDft_Cnt_lgc(data) \
  ( \
  Rte_Inst_Sa_CDDInterface->CDDInterface_Per4_WhlImbRejSrlComSvcDft_Cnt_lgc->value = (data) \
  )

# define Rte_IWriteRef_CDDInterface_Per4_WhlImbRejSrlComSvcDft_Cnt_lgc() \
  (&Rte_Inst_Sa_CDDInterface->CDDInterface_Per4_WhlImbRejSrlComSvcDft_Cnt_lgc->value)


/**********************************************************************************************************************
 * Rte_Mode_<p>_<m>
 *********************************************************************************************************************/
# define Rte_Mode_SystemState_Mode Rte_Mode_Sa_CDDInterface_SystemState_Mode


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (C/S invocation)
 *********************************************************************************************************************/
# define Rte_Call_CDDPorts_ClearPhsReasSum Rte_Call_Sa_CDDInterface_CDDPorts_ClearPhsReasSum




# define RTE_START_SEC_SA_CDDINTERFACE_APPL_CODE
# include "MemMap.h"


/**********************************************************************************************************************
 *
 * Runnable Entity Name: CDDInterface_Init1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Implicit S/R API:
 *   -----------------
 *   Float Rte_IRead_CDDInterface_Init1_Cos1RTAmpRec_Uls_f32(void)
 *   Float Rte_IRead_CDDInterface_Init1_Cos1RTOffset_Volts_f32(void)
 *   Float Rte_IRead_CDDInterface_Init1_Sin1RTAmpRec_Uls_f32(void)
 *   Float Rte_IRead_CDDInterface_Init1_Sin1RTOffset_Volts_f32(void)
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

FUNC(void, RTE_SA_CDDINTERFACE_APPL_CODE) CDDInterface_Init1(void);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CDDInterface_Init2
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

FUNC(void, RTE_SA_CDDINTERFACE_APPL_CODE) CDDInterface_Init2(void);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CDDInterface_Per1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 2ms
 *
 **********************************************************************************************************************
 *
 * Output Interfaces:
 * ==================
 *   Implicit S/R API:
 *   -----------------
 *   void Rte_IWrite_CDDInterface_Per1_ADCMtrCurr1_Volts_f32(Float data)
 *   Float *Rte_IWriteRef_CDDInterface_Per1_ADCMtrCurr1_Volts_f32(void)
 *   void Rte_IWrite_CDDInterface_Per1_ADCMtrCurr2_Volts_f32(Float data)
 *   Float *Rte_IWriteRef_CDDInterface_Per1_ADCMtrCurr2_Volts_f32(void)
 *   void Rte_IWrite_CDDInterface_Per1_CorrMtrPosElec_Rev_f32(Float data)
 *   Float *Rte_IWriteRef_CDDInterface_Per1_CorrMtrPosElec_Rev_f32(void)
 *   void Rte_IWrite_CDDInterface_Per1_Cos1Theta_Volts_f32(Float data)
 *   Float *Rte_IWriteRef_CDDInterface_Per1_Cos1Theta_Volts_f32(void)
 *   void Rte_IWrite_CDDInterface_Per1_DutyCycleSmall_Cnt_u16(UInt16 data)
 *   UInt16 *Rte_IWriteRef_CDDInterface_Per1_DutyCycleSmall_Cnt_u16(void)
 *   void Rte_IWrite_CDDInterface_Per1_ExpectedOnTimeA_Cnt_u32(UInt32 data)
 *   UInt32 *Rte_IWriteRef_CDDInterface_Per1_ExpectedOnTimeA_Cnt_u32(void)
 *   void Rte_IWrite_CDDInterface_Per1_ExpectedOnTimeB_Cnt_u32(UInt32 data)
 *   UInt32 *Rte_IWriteRef_CDDInterface_Per1_ExpectedOnTimeB_Cnt_u32(void)
 *   void Rte_IWrite_CDDInterface_Per1_ExpectedOnTimeC_Cnt_u32(UInt32 data)
 *   UInt32 *Rte_IWriteRef_CDDInterface_Per1_ExpectedOnTimeC_Cnt_u32(void)
 *   void Rte_IWrite_CDDInterface_Per1_MeasuredOnTimeA_Cnt_u32(UInt32 data)
 *   UInt32 *Rte_IWriteRef_CDDInterface_Per1_MeasuredOnTimeA_Cnt_u32(void)
 *   void Rte_IWrite_CDDInterface_Per1_MeasuredOnTimeB_Cnt_u32(UInt32 data)
 *   UInt32 *Rte_IWriteRef_CDDInterface_Per1_MeasuredOnTimeB_Cnt_u32(void)
 *   void Rte_IWrite_CDDInterface_Per1_MeasuredOnTimeC_Cnt_u32(UInt32 data)
 *   UInt32 *Rte_IWriteRef_CDDInterface_Per1_MeasuredOnTimeC_Cnt_u32(void)
 *   void Rte_IWrite_CDDInterface_Per1_ModIdxFinal_Uls_f32(Float data)
 *   Float *Rte_IWriteRef_CDDInterface_Per1_ModIdxFinal_Uls_f32(void)
 *   void Rte_IWrite_CDDInterface_Per1_MtrCurrDax_Amp_f32(Float data)
 *   Float *Rte_IWriteRef_CDDInterface_Per1_MtrCurrDax_Amp_f32(void)
 *   void Rte_IWrite_CDDInterface_Per1_MtrCurrK1_Amp_f32(Float data)
 *   Float *Rte_IWriteRef_CDDInterface_Per1_MtrCurrK1_Amp_f32(void)
 *   void Rte_IWrite_CDDInterface_Per1_MtrCurrK2_Amp_f32(Float data)
 *   Float *Rte_IWriteRef_CDDInterface_Per1_MtrCurrK2_Amp_f32(void)
 *   void Rte_IWrite_CDDInterface_Per1_MtrCurrQax_Amp_f32(Float data)
 *   Float *Rte_IWriteRef_CDDInterface_Per1_MtrCurrQax_Amp_f32(void)
 *   void Rte_IWrite_CDDInterface_Per1_MtrPosElec_Rev_f32(Float data)
 *   Float *Rte_IWriteRef_CDDInterface_Per1_MtrPosElec_Rev_f32(void)
 *   void Rte_IWrite_CDDInterface_Per1_MtrPosMech_Rev_f32(Float data)
 *   Float *Rte_IWriteRef_CDDInterface_Per1_MtrPosMech_Rev_f32(void)
 *   void Rte_IWrite_CDDInterface_Per1_MtrRevCntr_Cnt_s16(SInt16 data)
 *   SInt16 *Rte_IWriteRef_CDDInterface_Per1_MtrRevCntr_Cnt_s16(void)
 *   void Rte_IWrite_CDDInterface_Per1_PhsReasA_Volts_f32(Float data)
 *   Float *Rte_IWriteRef_CDDInterface_Per1_PhsReasA_Volts_f32(void)
 *   void Rte_IWrite_CDDInterface_Per1_PhsReasB_Volts_f32(Float data)
 *   Float *Rte_IWriteRef_CDDInterface_Per1_PhsReasB_Volts_f32(void)
 *   void Rte_IWrite_CDDInterface_Per1_PhsReasC_Volts_f32(Float data)
 *   Float *Rte_IWriteRef_CDDInterface_Per1_PhsReasC_Volts_f32(void)
 *   void Rte_IWrite_CDDInterface_Per1_SWDutyCycleA_Uls_f32(Float data)
 *   Float *Rte_IWriteRef_CDDInterface_Per1_SWDutyCycleA_Uls_f32(void)
 *   void Rte_IWrite_CDDInterface_Per1_SWDutyCycleB_Uls_f32(Float data)
 *   Float *Rte_IWriteRef_CDDInterface_Per1_SWDutyCycleB_Uls_f32(void)
 *   void Rte_IWrite_CDDInterface_Per1_SWDutyCycleC_Uls_f32(Float data)
 *   Float *Rte_IWriteRef_CDDInterface_Per1_SWDutyCycleC_Uls_f32(void)
 *   void Rte_IWrite_CDDInterface_Per1_Sin1Theta_Volts_f32(Float data)
 *   Float *Rte_IWriteRef_CDDInterface_Per1_Sin1Theta_Volts_f32(void)
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
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_CDDPorts_ClearPhsReasSum(UInt16 DataAccessBfr_Cnt_T_u16)
 *     Synchronous Service Invocation. Timeout: None
 *
 *********************************************************************************************************************/

FUNC(void, RTE_SA_CDDINTERFACE_APPL_CODE) CDDInterface_Per1(void);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CDDInterface_Per2
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 1ms
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Implicit S/R API:
 *   -----------------
 *   UInt16 Rte_IRead_CDDInterface_Per2_CommOffset_Cnt_u16(void)
 *   Float Rte_IRead_CDDInterface_Per2_DaxIntegralGain_IPM_Uls_f32(void)
 *   Float Rte_IRead_CDDInterface_Per2_DaxIntegralGain_SPM_Uls_f32(void)
 *   Float Rte_IRead_CDDInterface_Per2_DaxPropotionalGain_IPM_Uls_f32(void)
 *   Float Rte_IRead_CDDInterface_Per2_DaxPropotionalGain_SPM_Uls_f32(void)
 *   Float Rte_IRead_CDDInterface_Per2_EstKe_VpRadpS_f32(void)
 *   Float Rte_IRead_CDDInterface_Per2_MRFMtrVel_MtrRadpS_f32(void)
 *   Float Rte_IRead_CDDInterface_Per2_MtrCurr1TempOffset_Volt_f32(void)
 *   Float Rte_IRead_CDDInterface_Per2_MtrCurr2TempOffset_Volt_f32(void)
 *   Float Rte_IRead_CDDInterface_Per2_MtrCurrDaxRef_IPM_Amp_f32(void)
 *   Float Rte_IRead_CDDInterface_Per2_MtrCurrDaxRef_SPM_Amp_f32(void)
 *   Float Rte_IRead_CDDInterface_Per2_MtrCurrQax12Mag_Amp_f32(void)
 *   Float Rte_IRead_CDDInterface_Per2_MtrCurrQax12Ph_Rev_f32(void)
 *   Float Rte_IRead_CDDInterface_Per2_MtrCurrQax6Mag_Amp_f32(void)
 *   Float Rte_IRead_CDDInterface_Per2_MtrCurrQax6Ph_Rev_f32(void)
 *   Float Rte_IRead_CDDInterface_Per2_MtrCurrQaxRef_IPM_Amp_f32(void)
 *   Float Rte_IRead_CDDInterface_Per2_MtrCurrQaxRef_SPM_Amp_f32(void)
 *   Float Rte_IRead_CDDInterface_Per2_MtrPosComputationDelay_IPM_Deg_f32(void)
 *   Float Rte_IRead_CDDInterface_Per2_MtrPosComputationDelay_SPM_Deg_f32(void)
 *   SInt16 Rte_IRead_CDDInterface_Per2_MtrTrqCmdSign_IPM_Cnt_s16(void)
 *   SInt16 Rte_IRead_CDDInterface_Per2_MtrTrqCmdSign_SPM_Cnt_s16(void)
 *   Float Rte_IRead_CDDInterface_Per2_MtrVoltDaxFF_IPM_Volt_f32(void)
 *   Float Rte_IRead_CDDInterface_Per2_MtrVoltDaxFF_SPM_Volt_f32(void)
 *   Float Rte_IRead_CDDInterface_Per2_MtrVoltQaxFF_IPM_Volt_f32(void)
 *   Float Rte_IRead_CDDInterface_Per2_MtrVoltQaxFF_SPM_Volt_f32(void)
 *   Float Rte_IRead_CDDInterface_Per2_QaxIntegralGain_IPM_Uls_f32(void)
 *   Float Rte_IRead_CDDInterface_Per2_QaxIntegralGain_SPM_Uls_f32(void)
 *   Float Rte_IRead_CDDInterface_Per2_QaxPropotionalGain_IPM_Uls_f32(void)
 *   Float Rte_IRead_CDDInterface_Per2_QaxPropotionalGain_SPM_Uls_f32(void)
 *   Float Rte_IRead_CDDInterface_Per2_Vecu_Volt_f32(void)
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

FUNC(void, RTE_SA_CDDINTERFACE_APPL_CODE) CDDInterface_Per2(void);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CDDInterface_Per3
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 2ms
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Implicit S/R API:
 *   -----------------
 *   Float Rte_IRead_CDDInterface_Per3_Cos1RTAmpRec_Uls_f32(void)
 *   Float Rte_IRead_CDDInterface_Per3_Cos1RTOffset_Volts_f32(void)
 *   FETPHASETYPE_ENUM Rte_IRead_CDDInterface_Per3_FETFaultPhase_Cnt_enum(void)
 *   FETFAULTTYPE_ENUM Rte_IRead_CDDInterface_Per3_FETFaultType_Cnt_enum(void)
 *   Float Rte_IRead_CDDInterface_Per3_Sin1RTAmpRec_Uls_f32(void)
 *   Float Rte_IRead_CDDInterface_Per3_Sin1RTOffset_Volts_f32(void)
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

FUNC(void, RTE_SA_CDDINTERFACE_APPL_CODE) CDDInterface_Per3(void);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CDDInterface_Per4
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 5ms
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Implicit S/R API:
 *   -----------------
 *   Boolean Rte_IRead_CDDInterface_Per4_DiagStsDefVehSpd_Cnt_lgc(void)
 *
 * Output Interfaces:
 * ==================
 *   Implicit S/R API:
 *   -----------------
 *   void Rte_IWrite_CDDInterface_Per4_DampingSrlComSvcDft_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_CDDInterface_Per4_DampingSrlComSvcDft_Cnt_lgc(void)
 *   void Rte_IWrite_CDDInterface_Per4_DftAsstTbl_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_CDDInterface_Per4_DftAsstTbl_Cnt_lgc(void)
 *   void Rte_IWrite_CDDInterface_Per4_DrivingDynSrlComSvcDft_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_CDDInterface_Per4_DrivingDynSrlComSvcDft_Cnt_lgc(void)
 *   void Rte_IWrite_CDDInterface_Per4_DwnldAsstGain_Uls_f32(Float data)
 *   Float *Rte_IWriteRef_CDDInterface_Per4_DwnldAsstGain_Uls_f32(void)
 *   void Rte_IWrite_CDDInterface_Per4_EOTImpactSrlComSvcDft_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_CDDInterface_Per4_EOTImpactSrlComSvcDft_Cnt_lgc(void)
 *   void Rte_IWrite_CDDInterface_Per4_EOTThermalSrlComSvcDft_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_CDDInterface_Per4_EOTThermalSrlComSvcDft_Cnt_lgc(void)
 *   void Rte_IWrite_CDDInterface_Per4_EngONSrlComSvcDft_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_CDDInterface_Per4_EngONSrlComSvcDft_Cnt_lgc(void)
 *   void Rte_IWrite_CDDInterface_Per4_FreqDepDmpSrlComSvcDft_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_CDDInterface_Per4_FreqDepDmpSrlComSvcDft_Cnt_lgc(void)
 *   void Rte_IWrite_CDDInterface_Per4_HysAddSrlComSvcDft_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_CDDInterface_Per4_HysAddSrlComSvcDft_Cnt_lgc(void)
 *   void Rte_IWrite_CDDInterface_Per4_HystCompSrlComSvcDft_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_CDDInterface_Per4_HystCompSrlComSvcDft_Cnt_lgc(void)
 *   void Rte_IWrite_CDDInterface_Per4_KinIntDiagSrlComSvcDft_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_CDDInterface_Per4_KinIntDiagSrlComSvcDft_Cnt_lgc(void)
 *   void Rte_IWrite_CDDInterface_Per4_LimitSrlComSvcDft_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_CDDInterface_Per4_LimitSrlComSvcDft_Cnt_lgc(void)
 *   void Rte_IWrite_CDDInterface_Per4_MEC_Cnt_enum(ManufModeType data)
 *   ManufModeType *Rte_IWriteRef_CDDInterface_Per4_MEC_Cnt_enum(void)
 *   void Rte_IWrite_CDDInterface_Per4_ModIdxSrlComSvcDft_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_CDDInterface_Per4_ModIdxSrlComSvcDft_Cnt_lgc(void)
 *   void Rte_IWrite_CDDInterface_Per4_MtrParmNrmLrnSrlComSvcDft_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_CDDInterface_Per4_MtrParmNrmLrnSrlComSvcDft_Cnt_lgc(void)
 *   void Rte_IWrite_CDDInterface_Per4_MtrVelNrmLrnSrlComSvcDft_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_CDDInterface_Per4_MtrVelNrmLrnSrlComSvcDft_Cnt_lgc(void)
 *   void Rte_IWrite_CDDInterface_Per4_MultIgnSrlComSvcDft_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_CDDInterface_Per4_MultIgnSrlComSvcDft_Cnt_lgc(void)
 *   void Rte_IWrite_CDDInterface_Per4_ParkAstSrlComSvcDft_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_CDDInterface_Per4_ParkAstSrlComSvcDft_Cnt_lgc(void)
 *   void Rte_IWrite_CDDInterface_Per4_PullCompSrlComSvcDft_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_CDDInterface_Per4_PullCompSrlComSvcDft_Cnt_lgc(void)
 *   void Rte_IWrite_CDDInterface_Per4_ReturnSrlComSvcDft_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_CDDInterface_Per4_ReturnSrlComSvcDft_Cnt_lgc(void)
 *   void Rte_IWrite_CDDInterface_Per4_RxMsgsSrlComSvcDft_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_CDDInterface_Per4_RxMsgsSrlComSvcDft_Cnt_lgc(void)
 *   void Rte_IWrite_CDDInterface_Per4_SrlComSvcDft_Cnt_b32(UInt32 data)
 *   UInt32 *Rte_IWriteRef_CDDInterface_Per4_SrlComSvcDft_Cnt_b32(void)
 *   void Rte_IWrite_CDDInterface_Per4_ThermalDCSrlComSvcDft_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_CDDInterface_Per4_ThermalDCSrlComSvcDft_Cnt_lgc(void)
 *   void Rte_IWrite_CDDInterface_Per4_TrqRmpSrlComSvcDft_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_CDDInterface_Per4_TrqRmpSrlComSvcDft_Cnt_lgc(void)
 *   void Rte_IWrite_CDDInterface_Per4_VehSpdValid_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_CDDInterface_Per4_VehSpdValid_Cnt_lgc(void)
 *   void Rte_IWrite_CDDInterface_Per4_WIREnabled_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_CDDInterface_Per4_WIREnabled_Cnt_lgc(void)
 *   void Rte_IWrite_CDDInterface_Per4_WhlImbRejSrlComSvcDft_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_CDDInterface_Per4_WhlImbRejSrlComSvcDft_Cnt_lgc(void)
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

FUNC(void, RTE_SA_CDDINTERFACE_APPL_CODE) CDDInterface_Per4(void);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MtrVelCDDInterface_GetMtrVelSignals
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <GetMtrVelSignals> of PortPrototype <MtrVelCDDInterface>
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
 *   void MtrVelCDDInterface_GetMtrVelSignals(SInt16 *SinAvg_Uls_T_s2p13, SInt16 *CosAvg_Uls_T_s2p13, UInt16 *PosAvg_Rev_T_u0p16, UInt16 *TimeAvg_uS_T_u16p0)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_SA_CDDINTERFACE_APPL_CODE) MtrVelCDDInterface_GetMtrVelSignals(P2VAR(SInt16, AUTOMATIC, RTE_SA_CDDINTERFACE_APPL_VAR) SinAvg_Uls_T_s2p13, P2VAR(SInt16, AUTOMATIC, RTE_SA_CDDINTERFACE_APPL_VAR) CosAvg_Uls_T_s2p13, P2VAR(UInt16, AUTOMATIC, RTE_SA_CDDINTERFACE_APPL_VAR) PosAvg_Rev_T_u0p16, P2VAR(UInt16, AUTOMATIC, RTE_SA_CDDINTERFACE_APPL_VAR) TimeAvg_uS_T_u16p0);

# define RTE_STOP_SEC_SA_CDDINTERFACE_APPL_CODE
# include "MemMap.h"

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

/* begin Fileversion check */
# ifndef SKIP_MAGIC_NUMBER
#  ifdef RTE_MAGIC_NUMBER
#   if RTE_MAGIC_NUMBER != 1334766041
#    error "The magic number of the generated file <C:/CMSynergy_Projects/Ford_S550_P552_EPS_TMS570/SwProject/CDDInterface/utp/contract/Rte_Sa_CDDInterface.h> is different. Please check time and date of the generated RTE files!"
#   endif
#  else
#   define RTE_MAGIC_NUMBER 1334766041
#  endif  /* RTE_MAGIC_NUMBER */
# endif  /* SKIP_MAGIC_NUMBER */
/* end Fileversion check */

#endif /* _RTE_SA_CDDINTERFACE_H */
