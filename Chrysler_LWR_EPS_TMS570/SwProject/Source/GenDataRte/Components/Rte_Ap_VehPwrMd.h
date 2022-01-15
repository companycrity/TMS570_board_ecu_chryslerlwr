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
 *          File:  Components/Rte_Ap_VehPwrMd.h
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
#ifndef _RTE_AP_VEHPWRMD_H
# define _RTE_AP_VEHPWRMD_H

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

#  define Rte_InitValue_ATermActive_Cnt_lgc (TRUE)
#  define Rte_InitValue_CTermActive_Cnt_lgc (FALSE)
#  define Rte_InitValue_DefaultVehSpd_Cnt_lgc (FALSE)
#  define Rte_InitValue_EngONSrlComSvcDft_Cnt_lgc (FALSE)
#  define Rte_InitValue_EngRPM_Cnt_u16 (1U)
#  define Rte_InitValue_EssEngStop_Cnt_lgc (TRUE)
#  define Rte_InitValue_OperRampRate_XpmS_f32 (0.0F)
#  define Rte_InitValue_OperRampValue_Uls_f32 (0.0F)
#  define Rte_InitValue_SpStPrsnt_Cnt_lgc (FALSE)
#  define Rte_InitValue_VehSpd_Kph_f32 (0.0F)
#  define Rte_InitValue_VehSpdValid_Cnt_lgc (FALSE)
# endif


# ifndef RTE_CORE
#  define RTE_START_SEC_VAR_NOINIT_UNSPECIFIED
#  include "MemMap.h"

/**********************************************************************************************************************
 * Buffers for implicit communication
 *********************************************************************************************************************/

extern VAR(Rte_tsTask_Init_9, RTE_VAR_NOINIT) Rte_Task_Init_9;

extern VAR(Rte_tsTask_2ms_9, RTE_VAR_NOINIT) Rte_Task_2ms_9;

#  define RTE_STOP_SEC_VAR_NOINIT_UNSPECIFIED
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

#  define Rte_IWrite_VehPwrMd_Init1_OperRampRate_XpmS_f32(data) \
  ( \
    Rte_Task_Init_9.Rte_RB.Rte_Ap_VehPwrMd_VehPwrMd_Init1.Rte_OperRampRate_XpmS_f32.value = (data) \
  )

#  define Rte_IWriteRef_VehPwrMd_Init1_OperRampRate_XpmS_f32() \
  (&Rte_Task_Init_9.Rte_RB.Rte_Ap_VehPwrMd_VehPwrMd_Init1.Rte_OperRampRate_XpmS_f32.value)

#  define Rte_IWrite_VehPwrMd_Init1_OperRampValue_Uls_f32(data) \
  ( \
    Rte_Task_Init_9.Rte_RB.Rte_Ap_VehPwrMd_VehPwrMd_Init1.Rte_OperRampValue_Uls_f32.value = (data) \
  )

#  define Rte_IWriteRef_VehPwrMd_Init1_OperRampValue_Uls_f32() \
  (&Rte_Task_Init_9.Rte_RB.Rte_Ap_VehPwrMd_VehPwrMd_Init1.Rte_OperRampValue_Uls_f32.value)

#  define Rte_IRead_VehPwrMd_Per1_DefaultVehSpd_Cnt_lgc() \
  (Rte_Task_2ms_9.Rte_RB.Rte_Ap_VehPwrMd_VehPwrMd_Per1.Rte_DefaultVehSpd_Cnt_lgc.value)

#  define Rte_IRead_VehPwrMd_Per1_EngONSrlComSvcDft_Cnt_lgc() \
  (Rte_Task_2ms_9.Rte_RB.Rte_Ap_VehPwrMd_VehPwrMd_Per1.Rte_EngONSrlComSvcDft_Cnt_lgc.value)

#  define Rte_IRead_VehPwrMd_Per1_EngRPM_Cnt_u16() \
  (Rte_Task_2ms_9.Rte_RB.Rte_Ap_VehPwrMd_VehPwrMd_Per1.Rte_EngRPM_Cnt_u16.value)

#  define Rte_IRead_VehPwrMd_Per1_EssEngStop_Cnt_lgc() \
  (Rte_Task_2ms_9.Rte_RB.Rte_Ap_VehPwrMd_VehPwrMd_Per1.Rte_EssEngStop_Cnt_lgc.value)

#  define Rte_IRead_VehPwrMd_Per1_SpStPrsnt_Cnt_lgc() \
  (Rte_Task_2ms_9.Rte_RB.Rte_Ap_VehPwrMd_VehPwrMd_Per1.Rte_SpStPrsnt_Cnt_lgc.value)

#  define Rte_IRead_VehPwrMd_Per1_VehSpdValid_Cnt_lgc() \
  (Rte_Task_2ms_9.Rte_RB.Rte_Ap_VehPwrMd_VehPwrMd_Per1.Rte_VehSpdValid_Cnt_lgc.value)

#  define Rte_IRead_VehPwrMd_Per1_VehSpd_Kph_f32() \
  (Rte_Task_2ms_9.Rte_RB.Rte_Ap_VehPwrMd_VehPwrMd_Per1.Rte_VehSpd_Kph_f32.value)

#  define Rte_IWrite_VehPwrMd_Per1_ATermActive_Cnt_lgc(data) \
  ( \
    Rte_Task_2ms_9.Rte_RB.Rte_Ap_VehPwrMd_VehPwrMd_Per1.Rte_ATermActive_Cnt_lgc.value = (data) \
  )

#  define Rte_IWriteRef_VehPwrMd_Per1_ATermActive_Cnt_lgc() \
  (&Rte_Task_2ms_9.Rte_RB.Rte_Ap_VehPwrMd_VehPwrMd_Per1.Rte_ATermActive_Cnt_lgc.value)

#  define Rte_IWrite_VehPwrMd_Per1_CTermActive_Cnt_lgc(data) \
  ( \
    Rte_Task_2ms_9.Rte_RB.Rte_Ap_VehPwrMd_VehPwrMd_Per1.Rte_CTermActive_Cnt_lgc.value = (data) \
  )

#  define Rte_IWriteRef_VehPwrMd_Per1_CTermActive_Cnt_lgc() \
  (&Rte_Task_2ms_9.Rte_RB.Rte_Ap_VehPwrMd_VehPwrMd_Per1.Rte_CTermActive_Cnt_lgc.value)

#  define Rte_IWrite_VehPwrMd_Per1_OperRampRate_XpmS_f32(data) \
  ( \
    Rte_Task_2ms_9.Rte_RB.Rte_Ap_VehPwrMd_VehPwrMd_Per1.Rte_OperRampRate_XpmS_f32.value = (data) \
  )

#  define Rte_IWriteRef_VehPwrMd_Per1_OperRampRate_XpmS_f32() \
  (&Rte_Task_2ms_9.Rte_RB.Rte_Ap_VehPwrMd_VehPwrMd_Per1.Rte_OperRampRate_XpmS_f32.value)

#  define Rte_IWrite_VehPwrMd_Per1_OperRampValue_Uls_f32(data) \
  ( \
    Rte_Task_2ms_9.Rte_RB.Rte_Ap_VehPwrMd_VehPwrMd_Per1.Rte_OperRampValue_Uls_f32.value = (data) \
  )

#  define Rte_IWriteRef_VehPwrMd_Per1_OperRampValue_Uls_f32() \
  (&Rte_Task_2ms_9.Rte_RB.Rte_Ap_VehPwrMd_VehPwrMd_Per1.Rte_OperRampValue_Uls_f32.value)


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (unmapped) for synchronous C/S communication
 *********************************************************************************************************************/
#  define RTE_START_SEC_IOHWABSTRACTION_APPL_CODE
#  include "MemMap.h"
FUNC(Std_ReturnType, RTE_IOHWABSTRACTION_APPL_CODE) IoHwAb_GetEpsEn(P2VAR(IoHwAb_BoolType, AUTOMATIC, RTE_IOHWABSTRACTION_APPL_VAR) signal);
#  define RTE_STOP_SEC_IOHWABSTRACTION_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_EpsEn_OP_GET IoHwAb_GetEpsEn
#  define RTE_START_SEC_WDGM_APPL_CODE
#  include "MemMap.h"
FUNC(Std_ReturnType, RTE_WDGM_APPL_CODE) WdgM_CheckpointReached(WdgM_SupervisedEntityIdType parg0, WdgM_CheckpointIdType parg1);
#  define RTE_STOP_SEC_WDGM_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_VehPwrMd_Per1_CP1_CheckpointReached() (WdgM_CheckpointReached((WdgM_SupervisedEntityIdType)8, (WdgM_CheckpointIdType)1))


# endif /* !defined(RTE_CORE) */


# define RTE_START_SEC_AP_VEHPWRMD_APPL_CODE
# include "MemMap.h"

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

FUNC(void, RTE_AP_VEHPWRMD_APPL_CODE) VehPwrMd_Init1(void);

FUNC(void, RTE_AP_VEHPWRMD_APPL_CODE) VehPwrMd_Per1(void);

# define RTE_STOP_SEC_AP_VEHPWRMD_APPL_CODE
# include "MemMap.h"


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

#  define RTE_E_EpsEn_E_NOT_OK (1U)

#  define RTE_E_WdgM_CheckpointReached_E_NOT_OK (1U)
# endif /* !defined(RTE_CORE) */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

/* begin Fileversion check */
# ifndef SKIP_MAGIC_NUMBER
#  ifdef RTE_MAGIC_NUMBER
#   if RTE_MAGIC_NUMBER != 1468867288
#    error "The magic number of the generated file <C:/Sankar/Chrysler/Synergy/CL/Temp_work/Chrysler_LWR_EPS_TMS570/SwProject/Source/GenDataRte/Components/Rte_Ap_VehPwrMd.h> is different. Please check time and date of the generated RTE files!"
#   endif
#  else
#   define RTE_MAGIC_NUMBER 1468867288
#  endif  /* RTE_MAGIC_NUMBER */
# endif  /* SKIP_MAGIC_NUMBER */
/* end Fileversion check */

#endif /* _RTE_AP_VEHPWRMD_H */
