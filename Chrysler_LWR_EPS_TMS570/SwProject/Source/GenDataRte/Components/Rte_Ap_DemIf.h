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
 *          File:  Components/Rte_Ap_DemIf.h
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
#ifndef _RTE_AP_DEMIF_H
# define _RTE_AP_DEMIF_H

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
extern VAR(UInt8, RTE_VAR_INIT) Rte_SrlComInput_CMDIgnStat_Cnt_u08;
extern VAR(UInt16, RTE_VAR_INIT) Rte_SrlComInput_NET_CFG_STAT_PT_Cnt_u16;

#  define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#  include "MemMap.h"

# endif /* !defined(RTE_CORE) */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

#  define Rte_InitValue_CMDIgnStat_Cnt_u08 (0U)
#  define Rte_InitValue_DemLocalVoltage_Volt_f32 (5.0F)
#  define Rte_InitValue_DemSystemVoltage_Volt_f32 (5.0F)
#  define Rte_InitValue_NET_CFG_STAT_PT_Cnt_u16 (0U)
#  define Rte_InitValue_NWCONFIG_STATUS_EC6_DE_NET_CFG_STAT_PT (3U)
# endif


# ifndef RTE_CORE
#  define RTE_START_SEC_VAR_NOINIT_UNSPECIFIED
#  include "MemMap.h"

/**********************************************************************************************************************
 * Buffers for implicit communication
 *********************************************************************************************************************/

extern VAR(Rte_tsTask_10ms_9, RTE_VAR_NOINIT) Rte_Task_10ms_9;

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

#  define Rte_IRead_DemIf_SetInputsConditions_DemLocalVoltage_Volt_f32() \
  (Rte_Task_10ms_9.Rte_TB.Rte_I_BatteryVoltage_Vecu_Volt_f32.value)

#  define Rte_IRead_DemIf_SetInputsConditions_DemSystemVoltage_Volt_f32() \
  (Rte_Task_10ms_9.Rte_TB.Rte_I_BatteryVoltage_Vecu_Volt_f32.value)

#  define Rte_IRead_DemIf_SetInputsConditions_NET_CFG_STAT_PT_Cnt_u16() \
  (Rte_Task_10ms_9.Rte_RB.Rte_Ap_DemIf_DemIf_SetInputsConditions.Rte_NET_CFG_STAT_PT_Cnt_u16.value)

#  define Rte_IRead_DemIf_SetInputsConditions_NWCONFIG_STATUS_EC6_DE_NET_CFG_STAT_PT() \
  (3U)


/**********************************************************************************************************************
 * Rte_Read_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Read_CMDIgnStat_Cnt_u08 Rte_Read_Ap_DemIf_CMDIgnStat_Cnt_u08
#  define Rte_Read_Ap_DemIf_CMDIgnStat_Cnt_u08(data) (*(data) = Rte_SrlComInput_CMDIgnStat_Cnt_u08, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_NET_CFG_STAT_PT_Cnt_u16 Rte_Read_Ap_DemIf_NET_CFG_STAT_PT_Cnt_u16
#  define Rte_Read_Ap_DemIf_NET_CFG_STAT_PT_Cnt_u16(data) (*(data) = Rte_SrlComInput_NET_CFG_STAT_PT_Cnt_u16, ((Std_ReturnType)RTE_E_OK))


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (unmapped) for synchronous C/S communication
 *********************************************************************************************************************/
#  define RTE_START_SEC_AP_DIAGMGR9_APPL_CODE
#  include "MemMap.h"
FUNC(Std_ReturnType, RTE_AP_DIAGMGR9_APPL_CODE) NxtrDiagMgr9_GetNTCFailed(NTCNumber NTC_Cnt_T_enum, P2VAR(Boolean, AUTOMATIC, RTE_AP_DIAGMGR9_APPL_VAR) NTCFailed_Ptr_T_lgc);
#  define RTE_STOP_SEC_AP_DIAGMGR9_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_NxtrDiagMgr_GetNTCFailed NxtrDiagMgr9_GetNTCFailed
#  define RTE_START_SEC_AP_DIAGMGR9_APPL_CODE
#  include "MemMap.h"
FUNC(Std_ReturnType, RTE_AP_DIAGMGR9_APPL_CODE) NxtrDiagMgr9_GetNTCStatus(NTCNumber NTC_Cnt_T_enum, P2VAR(UInt8, AUTOMATIC, RTE_AP_DIAGMGR9_APPL_VAR) Status_Ptr_T_u08);
#  define RTE_STOP_SEC_AP_DIAGMGR9_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_NxtrDiagMgr_GetNTCStatus NxtrDiagMgr9_GetNTCStatus
#  define RTE_START_SEC_DEM_APPL_CODE
#  include "MemMap.h"
FUNC(Std_ReturnType, RTE_DEM_APPL_CODE) Dem_SetOperationCycleState(Dem_OperationCycleIdType parg0, Dem_OperationCycleStateType CycleState);
#  define RTE_STOP_SEC_DEM_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_OperationCycle_SetOperationCycleState(arg1) (Dem_SetOperationCycleState((Dem_OperationCycleIdType)0, arg1))


# endif /* !defined(RTE_CORE) */


# define RTE_START_SEC_AP_DEMIF_APPL_CODE
# include "MemMap.h"

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

FUNC(void, RTE_AP_DEMIF_APPL_CODE) DemIf_Init(void);

FUNC(void, RTE_AP_DEMIF_APPL_CODE) DemIf_RestartDem(void);

FUNC(Std_ReturnType, RTE_AP_DEMIF_APPL_CODE) DemIf_SetEventStatus(UInt8 EventId, NxtrDiagMgrStatus EventStatus);

FUNC(void, RTE_AP_DEMIF_APPL_CODE) DemIf_SetInputsConditions(void);

FUNC(void, RTE_AP_DEMIF_APPL_CODE) DemIf_SetOperationCycleState(NxtrOpCycle NxtrOperationCycleId, NxtrOpCycleState NxtrCycleState);

FUNC(void, RTE_AP_DEMIF_APPL_CODE) Dem_Shutdown(void);

# define RTE_STOP_SEC_AP_DEMIF_APPL_CODE
# include "MemMap.h"


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

#  define RTE_E_DemIf_E_NOT_OK (1U)

#  define RTE_E_NxtrDiagMgr_E_NOT_OK (1U)

#  define RTE_E_OperationCycle_DEM_E_QUEUE_OVERFLOW (15U)

#  define RTE_E_OperationCycle_E_NOT_OK (1U)
# endif /* !defined(RTE_CORE) */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

/* begin Fileversion check */
# ifndef SKIP_MAGIC_NUMBER
#  ifdef RTE_MAGIC_NUMBER
#   if RTE_MAGIC_NUMBER != 1468867288
#    error "The magic number of the generated file <C:/Sankar/Chrysler/Synergy/CL/Temp_work/Chrysler_LWR_EPS_TMS570/SwProject/Source/GenDataRte/Components/Rte_Ap_DemIf.h> is different. Please check time and date of the generated RTE files!"
#   endif
#  else
#   define RTE_MAGIC_NUMBER 1468867288
#  endif  /* RTE_MAGIC_NUMBER */
# endif  /* SKIP_MAGIC_NUMBER */
/* end Fileversion check */

#endif /* _RTE_AP_DEMIF_H */
