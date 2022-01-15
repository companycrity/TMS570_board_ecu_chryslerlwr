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
 *          File:  Components/Rte_Ap_ArbLmt.h
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
#ifndef _RTE_AP_ARBLMT_H
# define _RTE_AP_ARBLMT_H

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

#  define Rte_InitValue_ActiveFunctionBits_Cnt_u08 (0U)
#  define Rte_InitValue_DSTActive_Cnt_lgc (FALSE)
#  define Rte_InitValue_DSTSlewComplete_Cnt_lgc (FALSE)
#  define Rte_InitValue_DSTState_Cnt_u08 (0U)
#  define Rte_InitValue_DSTTrqOvCmdRqst_HwNm_f32 (0.0F)
#  define Rte_InitValue_HaLFActive_Cnt_lgc (FALSE)
#  define Rte_InitValue_HaLFSlewComplete_Cnt_lgc (FALSE)
#  define Rte_InitValue_HaLFTOState_Cnt_u08 (0U)
#  define Rte_InitValue_HaLFTrqOvCmdRqst_MtrNm_f32 (0.0F)
#  define Rte_InitValue_IpTrqOvr_HwNm_f32 (0.0F)
#  define Rte_InitValue_OpTrqOvr_MtrNm_f32 (0.0F)
#  define Rte_InitValue_PAReturnSclFct_Uls_f32 (1.0F)
#  define Rte_InitValue_PATrqOvCmdRqst_HwNm_f32 (0.0F)
#  define Rte_InitValue_PICmpDisableLearning_Cnt_lgc (FALSE)
#  define Rte_InitValue_PrkAssistState_Cnt_u08 (0U)
#  define Rte_InitValue_PrkAsstSlewComplete_Cnt_lgc (FALSE)
#  define Rte_InitValue_VehicleSpeed_Kph_f32 (0.0F)
# endif


# ifndef RTE_CORE
#  define RTE_START_SEC_VAR_Ap_10_NOINIT_UNSPECIFIED
#  include "MemMap.h"

/**********************************************************************************************************************
 * Buffers for implicit communication
 *********************************************************************************************************************/

extern VAR(Rte_tsTask_4ms_10, RTE_VAR_NOINIT) Rte_Task_4ms_10;

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

#  define Rte_IRead_ArbLmt_Per1_DSTActive_Cnt_lgc() \
  (Rte_Task_4ms_10.Rte_RB.Rte_Ap_ArbLmt_ArbLmt_Per1.Rte_DSTActive_Cnt_lgc.value)

#  define Rte_IRead_ArbLmt_Per1_DSTState_Cnt_u08() \
  (Rte_Task_4ms_10.Rte_RB.Rte_Ap_ArbLmt_ArbLmt_Per1.Rte_DSTState_Cnt_u08.value)

#  define Rte_IRead_ArbLmt_Per1_DSTTrqOvCmdRqst_HwNm_f32() \
  (Rte_Task_4ms_10.Rte_RB.Rte_Ap_ArbLmt_ArbLmt_Per1.Rte_DSTTrqOvCmdRqst_HwNm_f32.value)

#  define Rte_IRead_ArbLmt_Per1_HaLFActive_Cnt_lgc() \
  (Rte_Task_4ms_10.Rte_RB.Rte_Ap_ArbLmt_ArbLmt_Per1.Rte_HaLFActive_Cnt_lgc.value)

#  define Rte_IRead_ArbLmt_Per1_HaLFTOState_Cnt_u08() \
  (Rte_Task_4ms_10.Rte_RB.Rte_Ap_ArbLmt_ArbLmt_Per1.Rte_HaLFTOState_Cnt_u08.value)

#  define Rte_IRead_ArbLmt_Per1_HaLFTrqOvCmdRqst_MtrNm_f32() \
  (Rte_Task_4ms_10.Rte_RB.Rte_Ap_ArbLmt_ArbLmt_Per1.Rte_HaLFTrqOvCmdRqst_MtrNm_f32.value)

#  define Rte_IRead_ArbLmt_Per1_PATrqOvCmdRqst_HwNm_f32() \
  (Rte_Task_4ms_10.Rte_RB.Rte_Ap_ArbLmt_ArbLmt_Per1.Rte_PATrqOvCmdRqst_HwNm_f32.value)

#  define Rte_IRead_ArbLmt_Per1_PrkAssistState_Cnt_u08() \
  (Rte_Task_4ms_10.Rte_RB.Rte_Ap_ArbLmt_ArbLmt_Per1.Rte_PrkAssistState_Cnt_u08.value)

#  define Rte_IRead_ArbLmt_Per1_VehicleSpeed_Kph_f32() \
  (Rte_Task_4ms_10.Rte_RB.Rte_Ap_ArbLmt_ArbLmt_Per1.Rte_VehicleSpeed_Kph_f32.value)

#  define Rte_IWrite_ArbLmt_Per1_ActiveFunctionBits_Cnt_u08(data) \
  ( \
    Rte_Task_4ms_10.Rte_RB.Rte_Ap_ArbLmt_ArbLmt_Per1.Rte_ActiveFunctionBits_Cnt_u08.value = (data) \
  )

#  define Rte_IWriteRef_ArbLmt_Per1_ActiveFunctionBits_Cnt_u08() \
  (&Rte_Task_4ms_10.Rte_RB.Rte_Ap_ArbLmt_ArbLmt_Per1.Rte_ActiveFunctionBits_Cnt_u08.value)

#  define Rte_IWrite_ArbLmt_Per1_DSTSlewComplete_Cnt_lgc(data) \
  ( \
    Rte_Task_4ms_10.Rte_RB.Rte_Ap_ArbLmt_ArbLmt_Per1.Rte_DSTSlewComplete_Cnt_lgc.value = (data) \
  )

#  define Rte_IWriteRef_ArbLmt_Per1_DSTSlewComplete_Cnt_lgc() \
  (&Rte_Task_4ms_10.Rte_RB.Rte_Ap_ArbLmt_ArbLmt_Per1.Rte_DSTSlewComplete_Cnt_lgc.value)

#  define Rte_IWrite_ArbLmt_Per1_HaLFSlewComplete_Cnt_lgc(data) \
  ( \
    Rte_Task_4ms_10.Rte_RB.Rte_Ap_ArbLmt_ArbLmt_Per1.Rte_HaLFSlewComplete_Cnt_lgc.value = (data) \
  )

#  define Rte_IWriteRef_ArbLmt_Per1_HaLFSlewComplete_Cnt_lgc() \
  (&Rte_Task_4ms_10.Rte_RB.Rte_Ap_ArbLmt_ArbLmt_Per1.Rte_HaLFSlewComplete_Cnt_lgc.value)

#  define Rte_IWrite_ArbLmt_Per1_IpTrqOvr_HwNm_f32(data) \
  ( \
    Rte_Task_4ms_10.Rte_RB.Rte_Ap_ArbLmt_ArbLmt_Per1.Rte_IpTrqOvr_HwNm_f32.value = (data) \
  )

#  define Rte_IWriteRef_ArbLmt_Per1_IpTrqOvr_HwNm_f32() \
  (&Rte_Task_4ms_10.Rte_RB.Rte_Ap_ArbLmt_ArbLmt_Per1.Rte_IpTrqOvr_HwNm_f32.value)

#  define Rte_IWrite_ArbLmt_Per1_OpTrqOvr_MtrNm_f32(data) \
  ( \
    Rte_Task_4ms_10.Rte_RB.Rte_Ap_ArbLmt_ArbLmt_Per1.Rte_OpTrqOvr_MtrNm_f32.value = (data) \
  )

#  define Rte_IWriteRef_ArbLmt_Per1_OpTrqOvr_MtrNm_f32() \
  (&Rte_Task_4ms_10.Rte_RB.Rte_Ap_ArbLmt_ArbLmt_Per1.Rte_OpTrqOvr_MtrNm_f32.value)

#  define Rte_IWrite_ArbLmt_Per1_PAReturnSclFct_Uls_f32(data) \
  ( \
    Rte_Task_4ms_10.Rte_RB.Rte_Ap_ArbLmt_ArbLmt_Per1.Rte_PAReturnSclFct_Uls_f32.value = (data) \
  )

#  define Rte_IWriteRef_ArbLmt_Per1_PAReturnSclFct_Uls_f32() \
  (&Rte_Task_4ms_10.Rte_RB.Rte_Ap_ArbLmt_ArbLmt_Per1.Rte_PAReturnSclFct_Uls_f32.value)

#  define Rte_IWrite_ArbLmt_Per1_PICmpDisableLearning_Cnt_lgc(data) \
  ( \
    Rte_Task_4ms_10.Rte_RB.Rte_Ap_ArbLmt_ArbLmt_Per1.Rte_PICmpDisableLearning_Cnt_lgc.value = (data) \
  )

#  define Rte_IWriteRef_ArbLmt_Per1_PICmpDisableLearning_Cnt_lgc() \
  (&Rte_Task_4ms_10.Rte_RB.Rte_Ap_ArbLmt_ArbLmt_Per1.Rte_PICmpDisableLearning_Cnt_lgc.value)

#  define Rte_IWrite_ArbLmt_Per1_PrkAsstSlewComplete_Cnt_lgc(data) \
  ( \
    Rte_Task_4ms_10.Rte_RB.Rte_Ap_ArbLmt_ArbLmt_Per1.Rte_PrkAsstSlewComplete_Cnt_lgc.value = (data) \
  )

#  define Rte_IWriteRef_ArbLmt_Per1_PrkAsstSlewComplete_Cnt_lgc() \
  (&Rte_Task_4ms_10.Rte_RB.Rte_Ap_ArbLmt_ArbLmt_Per1.Rte_PrkAsstSlewComplete_Cnt_lgc.value)


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (unmapped) for synchronous C/S communication
 *********************************************************************************************************************/
#  define RTE_START_SEC_WDGM_APPL_CODE
#  include "MemMap.h"
FUNC(Std_ReturnType, RTE_WDGM_APPL_CODE) WdgM_CheckpointReached(WdgM_SupervisedEntityIdType parg0, WdgM_CheckpointIdType parg1);
#  define RTE_STOP_SEC_WDGM_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_ArbLmt_Per1_CP1_CheckpointReached() (WdgM_CheckpointReached((WdgM_SupervisedEntityIdType)6, (WdgM_CheckpointIdType)1))


# endif /* !defined(RTE_CORE) */


# define RTE_START_SEC_AP_ARBLMT_APPL_CODE
# include "MemMap.h"

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

FUNC(void, RTE_AP_ARBLMT_APPL_CODE) ArbLmt_Per1(void);

# define RTE_STOP_SEC_AP_ARBLMT_APPL_CODE
# include "MemMap.h"


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

#  define RTE_E_WdgM_CheckpointReached_E_NOT_OK (1U)
# endif /* !defined(RTE_CORE) */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

/* begin Fileversion check */
# ifndef SKIP_MAGIC_NUMBER
#  ifdef RTE_MAGIC_NUMBER
#   if RTE_MAGIC_NUMBER != 1468867288
#    error "The magic number of the generated file <C:/Sankar/Chrysler/Synergy/CL/Temp_work/Chrysler_LWR_EPS_TMS570/SwProject/Source/GenDataRte/Components/Rte_Ap_ArbLmt.h> is different. Please check time and date of the generated RTE files!"
#   endif
#  else
#   define RTE_MAGIC_NUMBER 1468867288
#  endif  /* RTE_MAGIC_NUMBER */
# endif  /* SKIP_MAGIC_NUMBER */
/* end Fileversion check */

#endif /* _RTE_AP_ARBLMT_H */
