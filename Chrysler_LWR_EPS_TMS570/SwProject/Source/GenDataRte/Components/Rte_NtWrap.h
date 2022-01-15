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
 *          File:  Components/Rte_NtWrap.h
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
#ifndef _RTE_NTWRAP_H
# define _RTE_NTWRAP_H

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


# define RTE_START_SEC_CODE
# include "MemMap.h"

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/

# define RTE_STOP_SEC_CODE
# include "MemMap.h"


# ifndef RTE_CORE

/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (unmapped) for synchronous C/S communication
 *********************************************************************************************************************/
#  define RTE_START_SEC_AP_ABSHWPOSSCOM_APPL_CODE
#  include "MemMap.h"
FUNC(void, RTE_AP_ABSHWPOSSCOM_APPL_CODE) AbsHwPosScom_Scom_HwPosSrvSetToZero(Boolean Par);
#  define RTE_STOP_SEC_AP_ABSHWPOSSCOM_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_C_AbsHwPosScom_Scom_HwPosSrvSetToZero(arg1) (AbsHwPosScom_Scom_HwPosSrvSetToZero(arg1), ((Std_ReturnType)RTE_E_OK))
#  define RTE_START_SEC_AP_ASTLMT_APPL_CODE
#  include "MemMap.h"
FUNC(Std_ReturnType, RTE_AP_ASTLMT_APPL_CODE) AstLmt_Scom_ManualTrqCmd(Boolean EnableManualCtrl, Float MtrTrqCmd_MtrNm_f32);
#  define RTE_STOP_SEC_AP_ASTLMT_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_C_AstLmt_Scom_ManualTrqCmd AstLmt_Scom_ManualTrqCmd
#  define RTE_START_SEC_SA_CMMTRCURR_APPL_CODE
#  include "MemMap.h"
FUNC(Std_ReturnType, RTE_SA_CMMTRCURR_APPL_CODE) CmMtrCurr_SCom_CalGain(void);
#  define RTE_STOP_SEC_SA_CMMTRCURR_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_C_CmMtrCurr_SCom_CalGain CmMtrCurr_SCom_CalGain
#  define RTE_START_SEC_SA_CMMTRCURR_APPL_CODE
#  include "MemMap.h"
FUNC(Std_ReturnType, RTE_SA_CMMTRCURR_APPL_CODE) CmMtrCurr_SCom_CalOffset(void);
#  define RTE_STOP_SEC_SA_CMMTRCURR_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_C_CmMtrCurr_SCom_CalOffset CmMtrCurr_SCom_CalOffset
#  define RTE_START_SEC_SA_CMMTRCURR_APPL_CODE
#  include "MemMap.h"
FUNC(void, RTE_SA_CMMTRCURR_APPL_CODE) CmMtrCurr_SCom_SetMtrCurrCals(P2CONST(PhaseCurrCal_DataType, AUTOMATIC, RTE_SA_CMMTRCURR_APPL_DATA) ShCurrCalPtr);
#  define RTE_STOP_SEC_SA_CMMTRCURR_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_C_CmMtrCurr_SCom_SetMtrCurrCals(arg1) (CmMtrCurr_SCom_SetMtrCurrCals(arg1), ((Std_ReturnType)RTE_E_OK))
#  define RTE_START_SEC_SA_HWTRQ_APPL_CODE
#  include "MemMap.h"
FUNC(Std_ReturnType, RTE_SA_HWTRQ_APPL_CODE) HwTrq_SCom_ClrHwTrqScale(void);
#  define RTE_STOP_SEC_SA_HWTRQ_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_C_HwTrq_SCom_ClrHwTrqScale HwTrq_SCom_ClrHwTrqScale
#  define RTE_START_SEC_SA_HWTRQ_APPL_CODE
#  include "MemMap.h"
FUNC(Std_ReturnType, RTE_SA_HWTRQ_APPL_CODE) HwTrq_SCom_ClrHwTrqTrim(void);
#  define RTE_STOP_SEC_SA_HWTRQ_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_C_HwTrq_SCom_ClrHwTrqTrim HwTrq_SCom_ClrHwTrqTrim
#  define RTE_START_SEC_SA_HWTRQ_APPL_CODE
#  include "MemMap.h"
FUNC(Std_ReturnType, RTE_SA_HWTRQ_APPL_CODE) HwTrq_SCom_ManualSetHwTrqTrim(P2CONST(HwTrqTrim_Datatype, AUTOMATIC, RTE_SA_HWTRQ_APPL_DATA) HwTrqTrimDataPtr);
#  define RTE_STOP_SEC_SA_HWTRQ_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_C_HwTrq_SCom_ManualSetHwTrqTrim HwTrq_SCom_ManualSetHwTrqTrim
#  define RTE_START_SEC_SA_HWTRQ_APPL_CODE
#  include "MemMap.h"
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, RTE_SA_HWTRQ_APPL_CODE) HwTrq_SCom_SetEOLTrqStep(P2CONST(Float, AUTOMATIC, RTE_SA_HWTRQ_APPL_DATA) TrqStep_HwNm_T_f32);
# else
FUNC(void, RTE_SA_HWTRQ_APPL_CODE) HwTrq_SCom_SetEOLTrqStep(P2CONST(EOLTrqStepType, AUTOMATIC, RTE_SA_HWTRQ_APPL_DATA) TrqStep_HwNm_T_f32);
# endif
#  define RTE_STOP_SEC_SA_HWTRQ_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_C_HwTrq_SCom_SetEOLTrqStep(arg1) (HwTrq_SCom_SetEOLTrqStep(arg1), ((Std_ReturnType)RTE_E_OK))
#  define RTE_START_SEC_SA_HWTRQ_APPL_CODE
#  include "MemMap.h"
FUNC(Std_ReturnType, RTE_SA_HWTRQ_APPL_CODE) HwTrq_SCom_SetHwTrqScale(Float ScaleValue);
#  define RTE_STOP_SEC_SA_HWTRQ_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_C_HwTrq_SCom_SetHwTrqScale HwTrq_SCom_SetHwTrqScale
#  define RTE_START_SEC_SA_HWTRQ_APPL_CODE
#  include "MemMap.h"
FUNC(Std_ReturnType, RTE_SA_HWTRQ_APPL_CODE) HwTrq_SCom_SetHwTrqTrim(void);
#  define RTE_STOP_SEC_SA_HWTRQ_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_C_HwTrq_SCom_SetHwTrqTrim HwTrq_SCom_SetHwTrqTrim
#  define RTE_START_SEC_SA_MTRPOS_APPL_CODE
#  include "MemMap.h"
FUNC(void, RTE_SA_MTRPOS_APPL_CODE) MtrPos_SCom_SetEOLMtrCals(P2CONST(MtrPosCal_DataType, AUTOMATIC, RTE_SA_MTRPOS_APPL_DATA) MtrCalDataPtr);
#  define RTE_STOP_SEC_SA_MTRPOS_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_C_MtrPos_SCom_SetEOLMtrCals(arg1) (MtrPos_SCom_SetEOLMtrCals(arg1), ((Std_ReturnType)RTE_E_OK))
#  define RTE_START_SEC_AP_POLARITY_APPL_CODE
#  include "MemMap.h"
FUNC(void, RTE_AP_POLARITY_APPL_CODE) Polarity_SCom_SetPolarity(UInt8 Polarity_Cnt_T_b08);
#  define RTE_STOP_SEC_AP_POLARITY_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_C_Polarity_SCom_SetPolarity(arg1) (Polarity_SCom_SetPolarity(arg1), ((Std_ReturnType)RTE_E_OK))
#  define RTE_START_SEC_AP_CURRPARAMCOMP_APPL_CODE
#  include "MemMap.h"
FUNC(void, RTE_AP_CURRPARAMCOMP_APPL_CODE) SCom_EOLNomMtrParam_Set(Float NomKe_VpRadpS_f32, Float NomRmtr_Ohm_f32);
#  define RTE_STOP_SEC_AP_CURRPARAMCOMP_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_C_SCom_EOLNomMtrParam_Set(arg1, arg2) (SCom_EOLNomMtrParam_Set(arg1, arg2), ((Std_ReturnType)RTE_E_OK))
#  define RTE_START_SEC_AP_STAMD9_APPL_CODE
#  include "MemMap.h"
FUNC(void, RTE_AP_STAMD9_APPL_CODE) StaMd_SCom_EcuReset(void);
#  define RTE_STOP_SEC_AP_STAMD9_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_C_StaMd_SCom_EcuReset() (StaMd_SCom_EcuReset(), ((Std_ReturnType)RTE_E_OK))
#  define RTE_START_SEC_AP_TRQCANC_APPL_CODE
#  include "MemMap.h"
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, RTE_AP_TRQCANC_APPL_CODE) TrqCanc_Scom_SetCogTrqCal(P2CONST(UInt16, AUTOMATIC, RTE_AP_TRQCANC_APPL_DATA) CogTrqCalPtr, UInt16 ID);
# else
FUNC(void, RTE_AP_TRQCANC_APPL_CODE) TrqCanc_Scom_SetCogTrqCal(P2CONST(CoggingCancTrq, AUTOMATIC, RTE_AP_TRQCANC_APPL_DATA) CogTrqCalPtr, UInt16 ID);
# endif
#  define RTE_STOP_SEC_AP_TRQCANC_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_C_TrqCanc_Scom_SetCogTrqCal(arg1, arg2) (TrqCanc_Scom_SetCogTrqCal(arg1, arg2), ((Std_ReturnType)RTE_E_OK))
#  define RTE_START_SEC_AP_TRQCMDSCL_APPL_CODE
#  include "MemMap.h"
FUNC(void, RTE_AP_TRQCMDSCL_APPL_CODE) TrqCmdScl_SCom_Set(Float Par_f32);
#  define RTE_STOP_SEC_AP_TRQCMDSCL_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_C_TrqCmdScl_SCom_Set(arg1) (TrqCmdScl_SCom_Set(arg1), ((Std_ReturnType)RTE_E_OK))


# endif /* !defined(RTE_CORE) */


# define RTE_START_SEC_NTWRAP_APPL_CODE
# include "MemMap.h"

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

FUNC(void, RTE_NTWRAP_APPL_CODE) NtWrapC_AbsHwPosScom_Scom_HwPosSrvSetToZero(Boolean Par);

FUNC(Std_ReturnType, RTE_NTWRAP_APPL_CODE) NtWrapC_AstLmt_Scom_ManualTrqCmd(Boolean EnableManualCtrl, Float MtrTrqCmd_MtrNm_f32);

FUNC(Std_ReturnType, RTE_NTWRAP_APPL_CODE) NtWrapC_CmMtrCurr_SCom_CalGain(void);

FUNC(Std_ReturnType, RTE_NTWRAP_APPL_CODE) NtWrapC_CmMtrCurr_SCom_CalOffset(void);

FUNC(void, RTE_NTWRAP_APPL_CODE) NtWrapC_CmMtrCurr_SCom_SetMtrCurrCals(P2CONST(PhaseCurrCal_DataType, AUTOMATIC, RTE_NTWRAP_APPL_DATA) ShCurrCalPtr);

FUNC(Std_ReturnType, RTE_NTWRAP_APPL_CODE) NtWrapC_HwTrq_SCom_ClrHwTrqScale(void);

FUNC(Std_ReturnType, RTE_NTWRAP_APPL_CODE) NtWrapC_HwTrq_SCom_ClrHwTrqTrim(void);

FUNC(Std_ReturnType, RTE_NTWRAP_APPL_CODE) NtWrapC_HwTrq_SCom_ManualSetHwTrqTrim(P2CONST(HwTrqTrim_Datatype, AUTOMATIC, RTE_NTWRAP_APPL_DATA) HwTrqTrimDataPtr);

# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, RTE_NTWRAP_APPL_CODE) NtWrapC_HwTrq_SCom_SetEOLTrqStep(P2CONST(Float, AUTOMATIC, RTE_NTWRAP_APPL_DATA) TrqStep_HwNm_T_f32);
# else
FUNC(void, RTE_NTWRAP_APPL_CODE) NtWrapC_HwTrq_SCom_SetEOLTrqStep(P2CONST(EOLTrqStepType, AUTOMATIC, RTE_NTWRAP_APPL_DATA) TrqStep_HwNm_T_f32);
# endif

FUNC(Std_ReturnType, RTE_NTWRAP_APPL_CODE) NtWrapC_HwTrq_SCom_SetHwTrqScale(Float ScaleValue);

FUNC(Std_ReturnType, RTE_NTWRAP_APPL_CODE) NtWrapC_HwTrq_SCom_SetHwTrqTrim(void);

FUNC(void, RTE_NTWRAP_APPL_CODE) NtWrapC_MtrPos_SCom_SetEOLMtrCals(P2CONST(MtrPosCal_DataType, AUTOMATIC, RTE_NTWRAP_APPL_DATA) MtrCalDataPtr);

FUNC(void, RTE_NTWRAP_APPL_CODE) NtWrap_Per1(void);

FUNC(void, RTE_NTWRAP_APPL_CODE) NtWrapC_Polarity_SCom_SetPolarity(UInt8 Polarity_Cnt_T_b08);

FUNC(void, RTE_NTWRAP_APPL_CODE) NtWrapC_SCom_EOLNomMtrParam_Set(Float NomKe_VpRadpS_f32, Float NomRmtr_Ohm_f32);

FUNC(void, RTE_NTWRAP_APPL_CODE) NtWrapC_StaMd_SCom_EcuReset(void);

# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, RTE_NTWRAP_APPL_CODE) NtWrapC_TrqCanc_Scom_SetCogTrqCal(P2CONST(UInt16, AUTOMATIC, RTE_NTWRAP_APPL_DATA) CogTrqCalPtr, UInt16 ID);
# else
FUNC(void, RTE_NTWRAP_APPL_CODE) NtWrapC_TrqCanc_Scom_SetCogTrqCal(P2CONST(CoggingCancTrq, AUTOMATIC, RTE_NTWRAP_APPL_DATA) CogTrqCalPtr, UInt16 ID);
# endif

FUNC(void, RTE_NTWRAP_APPL_CODE) NtWrapC_TrqCmdScl_SCom_Set(Float Par_f32);

# define RTE_STOP_SEC_NTWRAP_APPL_CODE
# include "MemMap.h"


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

#  define RTE_E_AssistLmtFunc_Scom_RTE_E_MtrTrqLmt_SCom_VSTH (34U)

#  define RTE_E_AssistLmtFunc_Scom_RTE_E_OK (1U)

#  define RTE_E_CmMtrCurr_SCom_ConditionNotCorrect (34U)

#  define RTE_E_CmMtrCurr_SCom_CurrentOutOfRange (20U)

#  define RTE_E_CmMtrCurr_SCom_VehSpdOutofRange (21U)

#  define RTE_E_HwTrq_SCom_ConditionsNotCorrect (34U)
# endif /* !defined(RTE_CORE) */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

/* begin Fileversion check */
# ifndef SKIP_MAGIC_NUMBER
#  ifdef RTE_MAGIC_NUMBER
#   if RTE_MAGIC_NUMBER != 1468867288
#    error "The magic number of the generated file <C:/Sankar/Chrysler/Synergy/CL/Temp_work/Chrysler_LWR_EPS_TMS570/SwProject/Source/GenDataRte/Components/Rte_NtWrap.h> is different. Please check time and date of the generated RTE files!"
#   endif
#  else
#   define RTE_MAGIC_NUMBER 1468867288
#  endif  /* RTE_MAGIC_NUMBER */
# endif  /* SKIP_MAGIC_NUMBER */
/* end Fileversion check */

#endif /* _RTE_NTWRAP_H */
