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
 *          File:  Rte_Ap_HaLFTO.h
 *     Workspace:  C:/SynergyWorkspace/WorkingProjects/HaLFTO-008.0_NoUTP/HaLFTO/autosar
 *     SW-C Type:  Ap_HaLFTO
 *  Generated at:  Tue May 20 13:31:11 2014
 *
 *     Generator:  MICROSAR RTE Generator Version 2.17.2
 *       License:  License CBD1010122 valid for CBD1010122 Nexteer  GM MSR_SLP3_BSW_RTE_wGMLAN TexasInstruments TMS570 Texas Instruments
 *
 *   Description:  Application header file for SW-C <Ap_HaLFTO> (Contract Phase)
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_AP_HALFTO_H
# define _RTE_AP_HALFTO_H

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

typedef P2CONST(struct Rte_CDS_Ap_HaLFTO, TYPEDEF, RTE_CONST) Rte_Instance;


/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

# define Rte_InitValue_DSTState_Cnt_u08 ((UInt8)0u)
# define Rte_InitValue_DiagStsNonRecRmpToZeroFltPres_Cnt_lgc ((Boolean)FALSE)
# define Rte_InitValue_DiagStsRecRmpToZeroFltPres_Cnt_lgc ((Boolean)FALSE)
# define Rte_InitValue_HaLFActive_Cnt_lgc ((Boolean)FALSE)
# define Rte_InitValue_HaLFEnableRqst_Cnt_lgc ((Boolean)FALSE)
# define Rte_InitValue_HaLFErrInterfaceActive_Cnt_lgc ((Boolean)FALSE)
# define Rte_InitValue_HaLFExtSystemFltActive_Cnt_lgc ((Boolean)FALSE)
# define Rte_InitValue_HaLFFuncPresent_Cnt_lgc ((Boolean)FALSE)
# define Rte_InitValue_HaLFIntSystemFltActive_Cnt_lgc ((Boolean)FALSE)
# define Rte_InitValue_HaLFSWATrqFail_Cnt_lgc ((Boolean)FALSE)
# define Rte_InitValue_HaLFSlewComplete_Cnt_lgc ((Boolean)FALSE)
# define Rte_InitValue_HaLFState_Cnt_u08 ((UInt8)0u)
# define Rte_InitValue_HaLFSuspend_Cnt_lgc ((Boolean)FALSE)
# define Rte_InitValue_HaLFTrqOvReverseGearEngage_Cnt_lgc ((Boolean)FALSE)
# define Rte_InitValue_HwTorque_HwNm_f32 ((Float)0)
# define Rte_InitValue_LimitPercentFiltered_Uls_f32 ((Float)0)
# define Rte_InitValue_PrevHaLFEnableRqst_Cnt_lgc ((Boolean)FALSE)
# define Rte_InitValue_PrevHaLFTrqOvCmdRqst_MtrNm_f32 ((Float)0)
# define Rte_InitValue_TOEOLDisable_Cnt_lgc ((Boolean)FALSE)
# define Rte_InitValue_VehicleSpeed_Kph_f32 ((Float)0)


# define RTE_START_SEC_CODE
# include "MemMap.h"

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/
FUNC(Rte_ModeType_StaMd_Mode, RTE_CODE) Rte_Mode_Ap_HaLFTO_SystemState_Mode(void);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ap_HaLFTO_HaLFState_SCom_Transition(UInt8 State_Cnt_T_u08);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ap_HaLFTO_NxtrDiagMgr_GetNTCFailed(NTCNumber NTC_Cnt_T_enum, P2VAR(Boolean, AUTOMATIC, RTE_AP_HALFTO_APPL_VAR) NTCFailed_Ptr_T_lgc);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ap_HaLFTO_NxtrDiagMgr_SetNTCStatus(NTCNumber NTC_Cnt_T_enum, UInt8 Param_Cnt_T_u08, NxtrDiagMgrStatus Status_Cnt_T_enum);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ap_HaLFTO_SystemTime_DtrmnElapsedTime_mS_u16(UInt32 InitialTime, P2VAR(UInt16, AUTOMATIC, RTE_AP_HALFTO_APPL_VAR) ElapsedTime);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ap_HaLFTO_SystemTime_GetSystemTime_mS_u32(P2VAR(UInt32, AUTOMATIC, RTE_AP_HALFTO_APPL_VAR) CurrentTime);

# define RTE_STOP_SEC_CODE
# include "MemMap.h"



/**********************************************************************************************************************
 * Rte_IRead_<r>_<p>_<d>
 * Rte_IStatus_<r>_<p>_<d>
 * Rte_IWrite_<r>_<p>_<d>
 * Rte_IWriteRef_<r>_<p>_<d>
 * Rte_IInvalidate_<r>_<p>_<d>
 *********************************************************************************************************************/

# define Rte_IRead_HaLFTO_Per1_DSTState_Cnt_u08() \
  (Rte_Inst_Ap_HaLFTO->HaLFTO_Per1_DSTState_Cnt_u08->value)

# define Rte_IRead_HaLFTO_Per1_DiagStsNonRecRmpToZeroFltPres_Cnt_lgc() \
  (Rte_Inst_Ap_HaLFTO->HaLFTO_Per1_DiagStsNonRecRmpToZeroFltPres_Cnt_lgc->value)

# define Rte_IRead_HaLFTO_Per1_DiagStsRecRmpToZeroFltPres_Cnt_lgc() \
  (Rte_Inst_Ap_HaLFTO->HaLFTO_Per1_DiagStsRecRmpToZeroFltPres_Cnt_lgc->value)

# define Rte_IRead_HaLFTO_Per1_HaLFEnableRqst_Cnt_lgc() \
  (Rte_Inst_Ap_HaLFTO->HaLFTO_Per1_HaLFEnableRqst_Cnt_lgc->value)

# define Rte_IRead_HaLFTO_Per1_HaLFErrInterfaceActive_Cnt_lgc() \
  (Rte_Inst_Ap_HaLFTO->HaLFTO_Per1_HaLFErrInterfaceActive_Cnt_lgc->value)

# define Rte_IRead_HaLFTO_Per1_HaLFExtSystemFltActive_Cnt_lgc() \
  (Rte_Inst_Ap_HaLFTO->HaLFTO_Per1_HaLFExtSystemFltActive_Cnt_lgc->value)

# define Rte_IRead_HaLFTO_Per1_HaLFFuncPresent_Cnt_lgc() \
  (Rte_Inst_Ap_HaLFTO->HaLFTO_Per1_HaLFFuncPresent_Cnt_lgc->value)

# define Rte_IRead_HaLFTO_Per1_HaLFIntSystemFltActive_Cnt_lgc() \
  (Rte_Inst_Ap_HaLFTO->HaLFTO_Per1_HaLFIntSystemFltActive_Cnt_lgc->value)

# define Rte_IRead_HaLFTO_Per1_HaLFSWATrqFail_Cnt_lgc() \
  (Rte_Inst_Ap_HaLFTO->HaLFTO_Per1_HaLFSWATrqFail_Cnt_lgc->value)

# define Rte_IRead_HaLFTO_Per1_HaLFSlewComplete_Cnt_lgc() \
  (Rte_Inst_Ap_HaLFTO->HaLFTO_Per1_HaLFSlewComplete_Cnt_lgc->value)

# define Rte_IRead_HaLFTO_Per1_HaLFTrqOvReverseGearEngage_Cnt_lgc() \
  (Rte_Inst_Ap_HaLFTO->HaLFTO_Per1_HaLFTrqOvReverseGearEngage_Cnt_lgc->value)

# define Rte_IRead_HaLFTO_Per1_HwTorque_HwNm_f32() \
  (Rte_Inst_Ap_HaLFTO->HaLFTO_Per1_HwTorque_HwNm_f32->value)

# define Rte_IRead_HaLFTO_Per1_LimitPercentFiltered_Uls_f32() \
  (Rte_Inst_Ap_HaLFTO->HaLFTO_Per1_LimitPercentFiltered_Uls_f32->value)

# define Rte_IRead_HaLFTO_Per1_PrevHaLFEnableRqst_Cnt_lgc() \
  (Rte_Inst_Ap_HaLFTO->HaLFTO_Per1_PrevHaLFEnableRqst_Cnt_lgc->value)

# define Rte_IRead_HaLFTO_Per1_PrevHaLFTrqOvCmdRqst_MtrNm_f32() \
  (Rte_Inst_Ap_HaLFTO->HaLFTO_Per1_PrevHaLFTrqOvCmdRqst_MtrNm_f32->value)

# define Rte_IRead_HaLFTO_Per1_TOEOLDisable_Cnt_lgc() \
  (Rte_Inst_Ap_HaLFTO->HaLFTO_Per1_TOEOLDisable_Cnt_lgc->value)

# define Rte_IRead_HaLFTO_Per1_VehicleSpeed_Kph_f32() \
  (Rte_Inst_Ap_HaLFTO->HaLFTO_Per1_VehicleSpeed_Kph_f32->value)

# define Rte_IWrite_HaLFTO_Per1_HaLFActive_Cnt_lgc(data) \
  ( \
  Rte_Inst_Ap_HaLFTO->HaLFTO_Per1_HaLFActive_Cnt_lgc->value = (data) \
  )

# define Rte_IWriteRef_HaLFTO_Per1_HaLFActive_Cnt_lgc() \
  (&Rte_Inst_Ap_HaLFTO->HaLFTO_Per1_HaLFActive_Cnt_lgc->value)

# define Rte_IWrite_HaLFTO_Per1_HaLFState_Cnt_u08(data) \
  ( \
  Rte_Inst_Ap_HaLFTO->HaLFTO_Per1_HaLFState_Cnt_u08->value = (data) \
  )

# define Rte_IWriteRef_HaLFTO_Per1_HaLFState_Cnt_u08() \
  (&Rte_Inst_Ap_HaLFTO->HaLFTO_Per1_HaLFState_Cnt_u08->value)

# define Rte_IWrite_HaLFTO_Per1_HaLFSuspend_Cnt_lgc(data) \
  ( \
  Rte_Inst_Ap_HaLFTO->HaLFTO_Per1_HaLFSuspend_Cnt_lgc->value = (data) \
  )

# define Rte_IWriteRef_HaLFTO_Per1_HaLFSuspend_Cnt_lgc() \
  (&Rte_Inst_Ap_HaLFTO->HaLFTO_Per1_HaLFSuspend_Cnt_lgc->value)


/**********************************************************************************************************************
 * Rte_Mode_<p>_<m>
 *********************************************************************************************************************/
# define Rte_Mode_SystemState_Mode Rte_Mode_Ap_HaLFTO_SystemState_Mode


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (C/S invocation)
 *********************************************************************************************************************/
# define Rte_Call_HaLFState_SCom_Transition Rte_Call_Ap_HaLFTO_HaLFState_SCom_Transition
# define Rte_Call_NxtrDiagMgr_GetNTCFailed Rte_Call_Ap_HaLFTO_NxtrDiagMgr_GetNTCFailed
# define Rte_Call_NxtrDiagMgr_SetNTCStatus Rte_Call_Ap_HaLFTO_NxtrDiagMgr_SetNTCStatus
# define Rte_Call_SystemTime_DtrmnElapsedTime_mS_u16 Rte_Call_Ap_HaLFTO_SystemTime_DtrmnElapsedTime_mS_u16
# define Rte_Call_SystemTime_GetSystemTime_mS_u32 Rte_Call_Ap_HaLFTO_SystemTime_GetSystemTime_mS_u32




# define RTE_START_SEC_AP_HALFTO_APPL_CODE
# include "MemMap.h"


/**********************************************************************************************************************
 *
 * Runnable Entity Name: HaLFTO_Init1
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
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_HaLFState_SCom_Transition(UInt8 State_Cnt_T_u08)
 *     Synchronous Server Invocation. Timeout: None
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_SystemTime_GetSystemTime_mS_u32(UInt32 *CurrentTime)
 *     Synchronous Service Invocation. Timeout: None
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_HALFTO_APPL_CODE) HaLFTO_Init1(void);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: HaLFTO_Per1
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
 *   UInt8 Rte_IRead_HaLFTO_Per1_DSTState_Cnt_u08(void)
 *   Boolean Rte_IRead_HaLFTO_Per1_DiagStsNonRecRmpToZeroFltPres_Cnt_lgc(void)
 *   Boolean Rte_IRead_HaLFTO_Per1_DiagStsRecRmpToZeroFltPres_Cnt_lgc(void)
 *   Boolean Rte_IRead_HaLFTO_Per1_HaLFEnableRqst_Cnt_lgc(void)
 *   Boolean Rte_IRead_HaLFTO_Per1_HaLFErrInterfaceActive_Cnt_lgc(void)
 *   Boolean Rte_IRead_HaLFTO_Per1_HaLFExtSystemFltActive_Cnt_lgc(void)
 *   Boolean Rte_IRead_HaLFTO_Per1_HaLFFuncPresent_Cnt_lgc(void)
 *   Boolean Rte_IRead_HaLFTO_Per1_HaLFIntSystemFltActive_Cnt_lgc(void)
 *   Boolean Rte_IRead_HaLFTO_Per1_HaLFSWATrqFail_Cnt_lgc(void)
 *   Boolean Rte_IRead_HaLFTO_Per1_HaLFSlewComplete_Cnt_lgc(void)
 *   Boolean Rte_IRead_HaLFTO_Per1_HaLFTrqOvReverseGearEngage_Cnt_lgc(void)
 *   Float Rte_IRead_HaLFTO_Per1_HwTorque_HwNm_f32(void)
 *   Float Rte_IRead_HaLFTO_Per1_LimitPercentFiltered_Uls_f32(void)
 *   Boolean Rte_IRead_HaLFTO_Per1_PrevHaLFEnableRqst_Cnt_lgc(void)
 *   Float Rte_IRead_HaLFTO_Per1_PrevHaLFTrqOvCmdRqst_MtrNm_f32(void)
 *   Boolean Rte_IRead_HaLFTO_Per1_TOEOLDisable_Cnt_lgc(void)
 *   Float Rte_IRead_HaLFTO_Per1_VehicleSpeed_Kph_f32(void)
 *
 * Output Interfaces:
 * ==================
 *   Implicit S/R API:
 *   -----------------
 *   void Rte_IWrite_HaLFTO_Per1_HaLFActive_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_HaLFTO_Per1_HaLFActive_Cnt_lgc(void)
 *   void Rte_IWrite_HaLFTO_Per1_HaLFState_Cnt_u08(UInt8 data)
 *   UInt8 *Rte_IWriteRef_HaLFTO_Per1_HaLFState_Cnt_u08(void)
 *   void Rte_IWrite_HaLFTO_Per1_HaLFSuspend_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_HaLFTO_Per1_HaLFSuspend_Cnt_lgc(void)
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
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_HaLFState_SCom_Transition(UInt8 State_Cnt_T_u08)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_NxtrDiagMgr_GetNTCFailed(NTCNumber NTC_Cnt_T_enum, Boolean *NTCFailed_Ptr_T_lgc)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NxtrDiagMgr_E_NOT_OK
 *   Std_ReturnType Rte_Call_NxtrDiagMgr_SetNTCStatus(NTCNumber NTC_Cnt_T_enum, UInt8 Param_Cnt_T_u08, NxtrDiagMgrStatus Status_Cnt_T_enum)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NxtrDiagMgr_E_NOT_OK
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_SystemTime_DtrmnElapsedTime_mS_u16(UInt32 InitialTime, UInt16 *ElapsedTime)
 *     Synchronous Service Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_SystemTime_GetSystemTime_mS_u32(UInt32 *CurrentTime)
 *     Synchronous Service Invocation. Timeout: None
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_HALFTO_APPL_CODE) HaLFTO_Per1(void);

# define RTE_STOP_SEC_AP_HALFTO_APPL_CODE
# include "MemMap.h"


/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

# define RTE_E_NxtrDiagMgr_E_NOT_OK (1u)

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

/* begin Fileversion check */
# ifndef SKIP_MAGIC_NUMBER
#  ifdef RTE_MAGIC_NUMBER
#   if RTE_MAGIC_NUMBER != 1400613794
#    error "The magic number of the generated file <C:/SynergyWorkspace/WorkingProjects/HaLFTO-008.0_NoUTP/HaLFTO/utp/contract/Ap_HaLFTO/Rte_Ap_HaLFTO.h> is different. Please check time and date of the generated RTE files!"
#   endif
#  else
#   define RTE_MAGIC_NUMBER 1400613794
#  endif  /* RTE_MAGIC_NUMBER */
# endif  /* SKIP_MAGIC_NUMBER */
/* end Fileversion check */

#endif /* _RTE_AP_HALFTO_H */
