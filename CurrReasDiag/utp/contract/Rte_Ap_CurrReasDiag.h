


/*
   !! B E T A   V E R S I O N !!

  These programs are fully operative programs.
  However, they are not thoroughly tested yet (beta-version).
  With regard to the fact that the programs are a beta-version only,
  Vector Informatik's liability shall be expressly excluded in cases of ordinary negligence,
  to the extent admissible by law or statute.
*/



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
 *          File:  Rte_Ap_CurrReasDiag.h
 *     Workspace:  C:/SynergyProjects/CBD/CurrReasDiag/autosar/Ap_CurrReasDiag.dcf
 *     SW-C Type:  Ap_CurrReasDiag
 *  Generated at:  Thu Aug  9 10:13:43 2012
 *
 *     Generator:  MICROSAR RTE Generator Version 2.19.1 (Beta)
 *       License:  License CBD1010124 valid for CBD1010124 Nexteer  Package: BMW MSR SIP BAC3.0     Micro: TI TMS570 TMS570LS30306  Compiler: Code Composer Studio 4.9.0
 *
 *   Description:  Application header file for SW-C <Ap_CurrReasDiag> (Contract Phase)
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_AP_CURRREASDIAG_H
# define _RTE_AP_CURRREASDIAG_H

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

typedef P2CONST(struct Rte_CDS_Ap_CurrReasDiag, TYPEDEF, RTE_CONST) Rte_Instance;


/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

# define Rte_InitValue_ModIdx_Uls_f32 (0.0F)
# define Rte_InitValue_MtrCurrQax_Amp_f32 (0.0F)
# define Rte_InitValue_MtrCurrQaxRef_IPM_Amp_f32 (0.0F)
# define Rte_InitValue_MtrCurrQaxRef_SPM_Amp_f32 (0.0F)
# define Rte_InitValue_Vecu_Volt_f32 (5.0F)


# define RTE_START_SEC_CODE
# include "MemMap.h"

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/
FUNC(Rte_ModeType_StaMd_Mode, RTE_CODE) Rte_Mode_Ap_CurrReasDiag_SystemState_Mode(void);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ap_CurrReasDiag_NxtrDiagMgr_SetNTCStatus(NTCNumber NTC, UInt8 Param, NxtrDiagMgrStatus Status);

# define RTE_STOP_SEC_CODE
# include "MemMap.h"



/**********************************************************************************************************************
 * Rte_IRead_<r>_<p>_<d>
 * Rte_IStatus_<r>_<p>_<d>
 * Rte_IWrite_<r>_<p>_<d>
 * Rte_IWriteRef_<r>_<p>_<d>
 * Rte_IInvalidate_<r>_<p>_<d>
 *********************************************************************************************************************/

# define Rte_IRead_CurrReasDiag_Per1_ModIdx_Uls_f32() \
  (Rte_Inst_Ap_CurrReasDiag->CurrReasDiag_Per1_ModIdx_Uls_f32->value)

# define Rte_IRead_CurrReasDiag_Per1_MtrCurrQaxRef_IPM_Amp_f32() \
  (Rte_Inst_Ap_CurrReasDiag->CurrReasDiag_Per1_MtrCurrQaxRef_IPM_Amp_f32->value)

# define Rte_IRead_CurrReasDiag_Per1_MtrCurrQaxRef_SPM_Amp_f32() \
  (Rte_Inst_Ap_CurrReasDiag->CurrReasDiag_Per1_MtrCurrQaxRef_SPM_Amp_f32->value)

# define Rte_IRead_CurrReasDiag_Per1_MtrCurrQax_Amp_f32() \
  (Rte_Inst_Ap_CurrReasDiag->CurrReasDiag_Per1_MtrCurrQax_Amp_f32->value)

# define Rte_IRead_CurrReasDiag_Per1_Vecu_Volt_f32() \
  (Rte_Inst_Ap_CurrReasDiag->CurrReasDiag_Per1_Vecu_Volt_f32->value)


/**********************************************************************************************************************
 * Rte_Mode_<p>_<m>
 *********************************************************************************************************************/
# define Rte_Mode_SystemState_Mode Rte_Mode_Ap_CurrReasDiag_SystemState_Mode


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (C/S invocation)
 *********************************************************************************************************************/
# define Rte_Call_NxtrDiagMgr_SetNTCStatus Rte_Call_Ap_CurrReasDiag_NxtrDiagMgr_SetNTCStatus




# define RTE_START_SEC_AP_CURRREASDIAG_APPL_CODE
# include "MemMap.h"


/**********************************************************************************************************************
 *
 * Runnable Entity Name: CurrReasDiag_Per1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 2ms
 *     and not in Mode(s) <WARMINIT, DISABLE, OFF>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Implicit S/R API:
 *   -----------------
 *   Float Rte_IRead_CurrReasDiag_Per1_ModIdx_Uls_f32(void)
 *   Float Rte_IRead_CurrReasDiag_Per1_MtrCurrQaxRef_IPM_Amp_f32(void)
 *   Float Rte_IRead_CurrReasDiag_Per1_MtrCurrQaxRef_SPM_Amp_f32(void)
 *   Float Rte_IRead_CurrReasDiag_Per1_MtrCurrQax_Amp_f32(void)
 *   Float Rte_IRead_CurrReasDiag_Per1_Vecu_Volt_f32(void)
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
 *   Std_ReturnType Rte_Call_NxtrDiagMgr_SetNTCStatus(NTCNumber NTC, UInt8 Param, NxtrDiagMgrStatus Status)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NxtrDiagMgr_E_NOT_OK
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_CURRREASDIAG_APPL_CODE) CurrReasDiag_Per1(void);

# define RTE_STOP_SEC_AP_CURRREASDIAG_APPL_CODE
# include "MemMap.h"


/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

# define RTE_E_NxtrDiagMgr_E_NOT_OK (1U)

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

/* begin Fileversion check */
# ifndef SKIP_MAGIC_NUMBER
#  ifdef RTE_MAGIC_NUMBER
#   if RTE_MAGIC_NUMBER != 1344524345
#    error "The magic number of the generated file <C:/Documents and Settings/nzx5jd/Desktop/DVOutput/Ap_CurrReasDiag/Rte_Ap_CurrReasDiag.h> is different. Please check time and date of the generated RTE files!"
#   endif
#  else
#   define RTE_MAGIC_NUMBER 1344524345
#  endif  /* RTE_MAGIC_NUMBER */
# endif  /* SKIP_MAGIC_NUMBER */
/* end Fileversion check */

#endif /* _RTE_AP_CURRREASDIAG_H */
