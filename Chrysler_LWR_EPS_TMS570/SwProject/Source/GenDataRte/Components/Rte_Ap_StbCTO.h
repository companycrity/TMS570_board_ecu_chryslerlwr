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
 *          File:  Components/Rte_Ap_StbCTO.h
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
#ifndef _RTE_AP_STBCTO_H
# define _RTE_AP_STBCTO_H

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

#  define Rte_InitValue_DSTActive_Cnt_lgc (FALSE)
#  define Rte_InitValue_DSTEnableRqst_Cnt_lgc (FALSE)
#  define Rte_InitValue_DSTErrCntrRecvLevel_Cnt_u08 (0U)
#  define Rte_InitValue_DSTExtSystemFltActive_Cnt_lgc (FALSE)
#  define Rte_InitValue_DSTFuncPresent_Cnt_lgc (FALSE)
#  define Rte_InitValue_DSTRevGearValid_Cnt_lgc (FALSE)
#  define Rte_InitValue_DSTSlewComplete_Cnt_lgc (FALSE)
#  define Rte_InitValue_DSTSlewStart_Cnt_lgc (FALSE)
#  define Rte_InitValue_DSTState_Cnt_u08 (0U)
#  define Rte_InitValue_DSTTOCState_Uls_enum (0U)
#  define Rte_InitValue_DSTTrqOvCmdRqst_HwNm_f32 (0.0F)
#  define Rte_InitValue_DSTTrqOvRqstValid_Cnt_lgc (FALSE)
#  define Rte_InitValue_DiagRedAssistLowVoltageActive_Cnt_lgc (FALSE)
#  define Rte_InitValue_DiagStsNonRecRmpToZeroFltPres_Cnt_lgc (FALSE)
#  define Rte_InitValue_DiagStsRecRmpToZeroFltPres_Cnt_lgc (FALSE)
#  define Rte_InitValue_LimitPercentFiltered_Uls_f32 (0.0F)
#  define Rte_InitValue_TOEOLDisable_Cnt_lgc (FALSE)
#  define Rte_InitValue_TrqOvReverseGearEngage_Cnt_lgc (FALSE)
#  define Rte_InitValue_VehicleSpeed_Kph_f32 (0.0F)
#  define Rte_InitValue_VehicleSpeedValid_Cnt_lgc (FALSE)
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

#  define Rte_IWrite_StbCTO_Init1_DSTActive_Cnt_lgc(data) \
  ( \
    Rte_Task_Init_10.Rte_RB.Rte_Ap_StbCTO_StbCTO_Init1.Rte_DSTActive_Cnt_lgc.value = (data) \
  )

#  define Rte_IWriteRef_StbCTO_Init1_DSTActive_Cnt_lgc() \
  (&Rte_Task_Init_10.Rte_RB.Rte_Ap_StbCTO_StbCTO_Init1.Rte_DSTActive_Cnt_lgc.value)

#  define Rte_IWrite_StbCTO_Init1_DSTSlewStart_Cnt_lgc(data) \
  ( \
    Rte_Task_Init_10.Rte_RB.Rte_Ap_StbCTO_StbCTO_Init1.Rte_DSTSlewStart_Cnt_lgc.value = (data) \
  )

#  define Rte_IWriteRef_StbCTO_Init1_DSTSlewStart_Cnt_lgc() \
  (&Rte_Task_Init_10.Rte_RB.Rte_Ap_StbCTO_StbCTO_Init1.Rte_DSTSlewStart_Cnt_lgc.value)

#  define Rte_IRead_StbCTO_Per1_DSTEnableRqst_Cnt_lgc() \
  (Rte_Task_2ms_10.Rte_RB.Rte_Ap_StbCTO_StbCTO_Per1.Rte_DSTEnableRqst_Cnt_lgc.value)

#  define Rte_IRead_StbCTO_Per1_DSTErrCntrRecvLevel_Cnt_u08() \
  (Rte_Task_2ms_10.Rte_RB.Rte_Ap_StbCTO_StbCTO_Per1.Rte_DSTErrCntrRecvLevel_Cnt_u08.value)

#  define Rte_IRead_StbCTO_Per1_DSTExtSystemFltActive_Cnt_lgc() \
  (Rte_Task_2ms_10.Rte_RB.Rte_Ap_StbCTO_StbCTO_Per1.Rte_DSTExtSystemFltActive_Cnt_lgc.value)

#  define Rte_IRead_StbCTO_Per1_DSTFuncPresent_Cnt_lgc() \
  (Rte_Task_2ms_10.Rte_RB.Rte_Ap_StbCTO_StbCTO_Per1.Rte_DSTFuncPresent_Cnt_lgc.value)

#  define Rte_IRead_StbCTO_Per1_DSTRevGearValid_Cnt_lgc() \
  (Rte_Task_2ms_10.Rte_RB.Rte_Ap_StbCTO_StbCTO_Per1.Rte_DSTRevGearValid_Cnt_lgc.value)

#  define Rte_IRead_StbCTO_Per1_DSTSlewComplete_Cnt_lgc() \
  (Rte_Task_2ms_10.Rte_RB.Rte_Ap_StbCTO_StbCTO_Per1.Rte_DSTSlewComplete_Cnt_lgc.value)

#  define Rte_IRead_StbCTO_Per1_DSTTOCState_Uls_enum() \
  (Rte_Task_2ms_10.Rte_RB.Rte_Ap_StbCTO_StbCTO_Per1.Rte_DSTTOCState_Uls_enum.value)

#  define Rte_IRead_StbCTO_Per1_DSTTrqOvCmdRqst_HwNm_f32() \
  (Rte_Task_2ms_10.Rte_RB.Rte_Ap_StbCTO_StbCTO_Per1.Rte_DSTTrqOvCmdRqst_HwNm_f32.value)

#  define Rte_IRead_StbCTO_Per1_DSTTrqOvRqstValid_Cnt_lgc() \
  (Rte_Task_2ms_10.Rte_RB.Rte_Ap_StbCTO_StbCTO_Per1.Rte_DSTTrqOvRqstValid_Cnt_lgc.value)

#  define Rte_IRead_StbCTO_Per1_DiagRedAssistLowVoltageActive_Cnt_lgc() \
  (Rte_Task_2ms_10.Rte_RB.Rte_Ap_StbCTO_StbCTO_Per1.Rte_DiagRedAssistLowVoltageActive_Cnt_lgc.value)

#  define Rte_IRead_StbCTO_Per1_DiagStsNonRecRmpToZeroFltPres_Cnt_lgc() \
  (Rte_Task_2ms_10.Rte_RB.Rte_Ap_StbCTO_StbCTO_Per1.Rte_DiagStsNonRecRmpToZeroFltPres_Cnt_lgc.value)

#  define Rte_IRead_StbCTO_Per1_DiagStsRecRmpToZeroFltPres_Cnt_lgc() \
  (Rte_Task_2ms_10.Rte_RB.Rte_Ap_StbCTO_StbCTO_Per1.Rte_DiagStsRecRmpToZeroFltPres_Cnt_lgc.value)

#  define Rte_IRead_StbCTO_Per1_LimitPercentFiltered_Uls_f32() \
  (Rte_Task_2ms_10.Rte_RB.Rte_Ap_StbCTO_StbCTO_Per1.Rte_LimitPercentFiltered_Uls_f32.value)

#  define Rte_IRead_StbCTO_Per1_TOEOLDisable_Cnt_lgc() \
  (Rte_Task_2ms_10.Rte_RB.Rte_Ap_StbCTO_StbCTO_Per1.Rte_TOEOLDisable_Cnt_lgc.value)

#  define Rte_IRead_StbCTO_Per1_TrqOvReverseGearEngage_Cnt_lgc() \
  (Rte_Task_2ms_10.Rte_RB.Rte_Ap_StbCTO_StbCTO_Per1.Rte_TrqOvReverseGearEngage_Cnt_lgc.value)

#  define Rte_IRead_StbCTO_Per1_VehicleSpeedValid_Cnt_lgc() \
  (Rte_Task_2ms_10.Rte_RB.Rte_Ap_StbCTO_StbCTO_Per1.Rte_VehicleSpeedValid_Cnt_lgc.value)

#  define Rte_IRead_StbCTO_Per1_VehicleSpeed_Kph_f32() \
  (Rte_Task_2ms_10.Rte_RB.Rte_Ap_StbCTO_StbCTO_Per1.Rte_VehicleSpeed_Kph_f32.value)

#  define Rte_IWrite_StbCTO_Per1_DSTActive_Cnt_lgc(data) \
  ( \
    Rte_Task_2ms_10.Rte_RB.Rte_Ap_StbCTO_StbCTO_Per1.Rte_DSTActive_Cnt_lgc.value = (data) \
  )

#  define Rte_IWriteRef_StbCTO_Per1_DSTActive_Cnt_lgc() \
  (&Rte_Task_2ms_10.Rte_RB.Rte_Ap_StbCTO_StbCTO_Per1.Rte_DSTActive_Cnt_lgc.value)

#  define Rte_IWrite_StbCTO_Per1_DSTSlewStart_Cnt_lgc(data) \
  ( \
    Rte_Task_2ms_10.Rte_RB.Rte_Ap_StbCTO_StbCTO_Per1.Rte_DSTSlewStart_Cnt_lgc.value = (data) \
  )

#  define Rte_IWriteRef_StbCTO_Per1_DSTSlewStart_Cnt_lgc() \
  (&Rte_Task_2ms_10.Rte_RB.Rte_Ap_StbCTO_StbCTO_Per1.Rte_DSTSlewStart_Cnt_lgc.value)

#  define Rte_IWrite_StbCTO_Per1_DSTState_Cnt_u08(data) \
  ( \
    Rte_Task_2ms_10.Rte_RB.Rte_Ap_StbCTO_StbCTO_Per1.Rte_DSTState_Cnt_u08.value = (data) \
  )

#  define Rte_IWriteRef_StbCTO_Per1_DSTState_Cnt_u08() \
  (&Rte_Task_2ms_10.Rte_RB.Rte_Ap_StbCTO_StbCTO_Per1.Rte_DSTState_Cnt_u08.value)


/**********************************************************************************************************************
 * Rte_Mode_<p>_<m>
 *********************************************************************************************************************/
#  define Rte_Mode_SystemState_Mode() Rte_ModeMachine_StaMd_SystemState_Mode


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (unmapped) for synchronous C/S communication
 *********************************************************************************************************************/
#  define RTE_START_SEC_AP_DIAGMGR10_APPL_CODE
#  include "MemMap.h"
FUNC(Std_ReturnType, RTE_AP_DIAGMGR10_APPL_CODE) NxtrDiagMgr10_GetNTCActive(NTCNumber NTC_Cnt_T_enum, P2VAR(Boolean, AUTOMATIC, RTE_AP_DIAGMGR10_APPL_VAR) NTCActive_Ptr_T_lgc);
#  define RTE_STOP_SEC_AP_DIAGMGR10_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_NxtrDiagMgr_GetNTCActive NxtrDiagMgr10_GetNTCActive
#  define RTE_START_SEC_AP_DIAGMGR10_APPL_CODE
#  include "MemMap.h"
FUNC(Std_ReturnType, RTE_AP_DIAGMGR10_APPL_CODE) NxtrDiagMgr10_GetNTCFailed(NTCNumber NTC_Cnt_T_enum, P2VAR(Boolean, AUTOMATIC, RTE_AP_DIAGMGR10_APPL_VAR) NTCFailed_Ptr_T_lgc);
#  define RTE_STOP_SEC_AP_DIAGMGR10_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_NxtrDiagMgr_GetNTCFailed NxtrDiagMgr10_GetNTCFailed
#  define RTE_START_SEC_AP_DIAGMGR10_APPL_CODE
#  include "MemMap.h"
FUNC(Std_ReturnType, RTE_AP_DIAGMGR10_APPL_CODE) NxtrDiagMgr10_SetNTCStatus(NTCNumber NTC_Cnt_T_enum, UInt8 Param_Cnt_T_u08, NxtrDiagMgrStatus Status_Cnt_T_enum);
#  define RTE_STOP_SEC_AP_DIAGMGR10_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_NxtrDiagMgr_SetNTCStatus NxtrDiagMgr10_SetNTCStatus
#  define RTE_START_SEC_NEXTEERLIBS_APPL_CODE
#  include "MemMap.h"
FUNC(void, RTE_NEXTEERLIBS_APPL_CODE) DtrmnElapsedTime_mS_u16(UInt32 InitialTime, P2VAR(UInt16, AUTOMATIC, RTE_NEXTEERLIBS_APPL_VAR) ElapsedTime);
#  define RTE_STOP_SEC_NEXTEERLIBS_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_SystemTime_DtrmnElapsedTime_mS_u16(arg1, arg2) (DtrmnElapsedTime_mS_u16(arg1, arg2), ((Std_ReturnType)RTE_E_OK))
#  define RTE_START_SEC_NEXTEERLIBS_APPL_CODE
#  include "MemMap.h"
FUNC(void, RTE_NEXTEERLIBS_APPL_CODE) GetSystemTime_mS_u32(P2VAR(UInt32, AUTOMATIC, RTE_NEXTEERLIBS_APPL_VAR) CurrentTime);
#  define RTE_STOP_SEC_NEXTEERLIBS_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_SystemTime_GetSystemTime_mS_u32(arg1) (GetSystemTime_mS_u32(arg1), ((Std_ReturnType)RTE_E_OK))


# endif /* !defined(RTE_CORE) */


# define RTE_START_SEC_AP_STBCTO_APPL_CODE
# include "MemMap.h"

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

FUNC(void, RTE_AP_STBCTO_APPL_CODE) StbCTO_Init1(void);

FUNC(void, RTE_AP_STBCTO_APPL_CODE) StbCTO_Per1(void);

# define RTE_STOP_SEC_AP_STBCTO_APPL_CODE
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
#    error "The magic number of the generated file <C:/Sankar/Chrysler/Synergy/CL/Temp_work/Chrysler_LWR_EPS_TMS570/SwProject/Source/GenDataRte/Components/Rte_Ap_StbCTO.h> is different. Please check time and date of the generated RTE files!"
#   endif
#  else
#   define RTE_MAGIC_NUMBER 1468867288
#  endif  /* RTE_MAGIC_NUMBER */
# endif  /* SKIP_MAGIC_NUMBER */
/* end Fileversion check */

#endif /* _RTE_AP_STBCTO_H */
