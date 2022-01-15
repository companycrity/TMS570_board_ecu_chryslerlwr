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
 *          File:  Rte_Ap_WhlImbRej.h
 *     Workspace:  C:/Synergy/WhlImbRej-zz4r1x/WhlImbRej/autosar
 *     SW-C Type:  Ap_WhlImbRej
 *  Generated at:  Tue Nov 13 09:04:53 2012
 *
 *     Generator:  MICROSAR RTE Generator Version 2.17.2
 *       License:  License CBD1010122 valid for CBD1010122 Nexteer  GM MSR_SLP3_BSW_RTE_wGMLAN TexasInstruments TMS570 Texas Instruments
 *
 *   Description:  Application header file for SW-C <Ap_WhlImbRej> (Contract Phase)
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_AP_WHLIMBREJ_H
# define _RTE_AP_WHLIMBREJ_H

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

typedef P2CONST(struct Rte_CDS_Ap_WhlImbRej, TYPEDEF, RTE_CONST) Rte_Instance;


/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

# define Rte_InitValue_DiagStsWIRDisable_Cnt_lgc ((Boolean)FALSE)
# define Rte_InitValue_HwTrq_HwNm_f32 ((Float)0)
# define Rte_InitValue_QualWhlFreqL_Hz_f32 ((Float)0)
# define Rte_InitValue_QualWhlFreqR_Hz_f32 ((Float)0)
# define Rte_InitValue_VehSpd_Kph_f32 ((Float)0)
# define Rte_InitValue_VehSpdValid_Cnt_lgc ((Boolean)FALSE)
# define Rte_InitValue_WIRCmdAmpBlnd_MtrNm_f32 ((Float)0)
# define Rte_InitValue_WIRMfgEnable_Cnt_lgc ((Boolean)FALSE)
# define Rte_InitValue_WhlFreqQualified_Cnt_lgc ((Boolean)TRUE)
# define Rte_InitValue_WhlImbRejCmd_MtrNm_f32 ((Float)0)


# define RTE_START_SEC_CODE
# include "MemMap.h"

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/
FUNC(Rte_ModeType_StaMd_Mode, RTE_CODE) Rte_Mode_Ap_WhlImbRej_SystemState_Mode(void);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ap_WhlImbRej_NxtrDiagMgr_SetNTCStatus(NTCNumber NTC_Cnt_T_enum, UInt8 Param_Cnt_T_u08, NxtrDiagMgrStatus Status_Cnt_T_enum);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ap_WhlImbRej_SystemTime_DtrmnElapsedTime_mS_u16(UInt32 InitialTime, P2VAR(UInt16, AUTOMATIC, RTE_AP_WHLIMBREJ_APPL_VAR) ElapsedTime);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ap_WhlImbRej_SystemTime_DtrmnElapsedTime_mS_u32(UInt32 InitialTime, P2VAR(UInt32, AUTOMATIC, RTE_AP_WHLIMBREJ_APPL_VAR) ElapsedTime);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ap_WhlImbRej_SystemTime_GetSystemTime_mS_u32(P2VAR(UInt32, AUTOMATIC, RTE_AP_WHLIMBREJ_APPL_VAR) CurrentTime);

# define RTE_STOP_SEC_CODE
# include "MemMap.h"



/**********************************************************************************************************************
 * Rte_IRead_<r>_<p>_<d>
 * Rte_IStatus_<r>_<p>_<d>
 * Rte_IWrite_<r>_<p>_<d>
 * Rte_IWriteRef_<r>_<p>_<d>
 * Rte_IInvalidate_<r>_<p>_<d>
 *********************************************************************************************************************/

# define Rte_IRead_WhlImbRej_Per1_DiagStsWIRDisable_Cnt_lgc() \
  (Rte_Inst_Ap_WhlImbRej->WhlImbRej_Per1_DiagStsWIRDisable_Cnt_lgc->value)

# define Rte_IRead_WhlImbRej_Per1_HwTrq_HwNm_f32() \
  (Rte_Inst_Ap_WhlImbRej->WhlImbRej_Per1_HwTrq_HwNm_f32->value)

# define Rte_IRead_WhlImbRej_Per1_QualWhlFreqL_Hz_f32() \
  (Rte_Inst_Ap_WhlImbRej->WhlImbRej_Per1_QualWhlFreqL_Hz_f32->value)

# define Rte_IRead_WhlImbRej_Per1_QualWhlFreqR_Hz_f32() \
  (Rte_Inst_Ap_WhlImbRej->WhlImbRej_Per1_QualWhlFreqR_Hz_f32->value)

# define Rte_IRead_WhlImbRej_Per1_VehSpdValid_Cnt_lgc() \
  (Rte_Inst_Ap_WhlImbRej->WhlImbRej_Per1_VehSpdValid_Cnt_lgc->value)

# define Rte_IRead_WhlImbRej_Per1_VehSpd_Kph_f32() \
  (Rte_Inst_Ap_WhlImbRej->WhlImbRej_Per1_VehSpd_Kph_f32->value)

# define Rte_IRead_WhlImbRej_Per1_WIRMfgEnable_Cnt_lgc() \
  (Rte_Inst_Ap_WhlImbRej->WhlImbRej_Per1_WIRMfgEnable_Cnt_lgc->value)

# define Rte_IRead_WhlImbRej_Per1_WhlFreqQualified_Cnt_lgc() \
  (Rte_Inst_Ap_WhlImbRej->WhlImbRej_Per1_WhlFreqQualified_Cnt_lgc->value)

# define Rte_IWrite_WhlImbRej_Per1_WIRCmdAmpBlnd_MtrNm_f32(data) \
  ( \
  Rte_Inst_Ap_WhlImbRej->WhlImbRej_Per1_WIRCmdAmpBlnd_MtrNm_f32->value = (data) \
  )

# define Rte_IWriteRef_WhlImbRej_Per1_WIRCmdAmpBlnd_MtrNm_f32() \
  (&Rte_Inst_Ap_WhlImbRej->WhlImbRej_Per1_WIRCmdAmpBlnd_MtrNm_f32->value)

# define Rte_IWrite_WhlImbRej_Per1_WhlImbRejCmd_MtrNm_f32(data) \
  ( \
  Rte_Inst_Ap_WhlImbRej->WhlImbRej_Per1_WhlImbRejCmd_MtrNm_f32->value = (data) \
  )

# define Rte_IWriteRef_WhlImbRej_Per1_WhlImbRejCmd_MtrNm_f32() \
  (&Rte_Inst_Ap_WhlImbRej->WhlImbRej_Per1_WhlImbRejCmd_MtrNm_f32->value)

# define Rte_IWrite_WhlImbRej_Per3_WhlImbRejCmd_MtrNm_f32(data) \
  ( \
  Rte_Inst_Ap_WhlImbRej->WhlImbRej_Per3_WhlImbRejCmd_MtrNm_f32->value = (data) \
  )

# define Rte_IWriteRef_WhlImbRej_Per3_WhlImbRejCmd_MtrNm_f32() \
  (&Rte_Inst_Ap_WhlImbRej->WhlImbRej_Per3_WhlImbRejCmd_MtrNm_f32->value)


/**********************************************************************************************************************
 * Rte_Mode_<p>_<m>
 *********************************************************************************************************************/
# define Rte_Mode_SystemState_Mode Rte_Mode_Ap_WhlImbRej_SystemState_Mode


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (C/S invocation)
 *********************************************************************************************************************/
# define Rte_Call_NxtrDiagMgr_SetNTCStatus Rte_Call_Ap_WhlImbRej_NxtrDiagMgr_SetNTCStatus
# define Rte_Call_SystemTime_DtrmnElapsedTime_mS_u16 Rte_Call_Ap_WhlImbRej_SystemTime_DtrmnElapsedTime_mS_u16
# define Rte_Call_SystemTime_DtrmnElapsedTime_mS_u32 Rte_Call_Ap_WhlImbRej_SystemTime_DtrmnElapsedTime_mS_u32
# define Rte_Call_SystemTime_GetSystemTime_mS_u32 Rte_Call_Ap_WhlImbRej_SystemTime_GetSystemTime_mS_u32




# define RTE_START_SEC_AP_WHLIMBREJ_APPL_CODE
# include "MemMap.h"


/**********************************************************************************************************************
 *
 * Runnable Entity Name: WhlImbRej_Init1
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

FUNC(void, RTE_AP_WHLIMBREJ_APPL_CODE) WhlImbRej_Init1(void);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: WhlImbRej_Per1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 2ms
 *     and not in Mode(s) <OFF, DISABLE, WARMINIT>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Implicit S/R API:
 *   -----------------
 *   Boolean Rte_IRead_WhlImbRej_Per1_DiagStsWIRDisable_Cnt_lgc(void)
 *   Float Rte_IRead_WhlImbRej_Per1_HwTrq_HwNm_f32(void)
 *   Float Rte_IRead_WhlImbRej_Per1_QualWhlFreqL_Hz_f32(void)
 *   Float Rte_IRead_WhlImbRej_Per1_QualWhlFreqR_Hz_f32(void)
 *   Boolean Rte_IRead_WhlImbRej_Per1_VehSpdValid_Cnt_lgc(void)
 *   Float Rte_IRead_WhlImbRej_Per1_VehSpd_Kph_f32(void)
 *   Boolean Rte_IRead_WhlImbRej_Per1_WIRMfgEnable_Cnt_lgc(void)
 *   Boolean Rte_IRead_WhlImbRej_Per1_WhlFreqQualified_Cnt_lgc(void)
 *
 * Output Interfaces:
 * ==================
 *   Implicit S/R API:
 *   -----------------
 *   void Rte_IWrite_WhlImbRej_Per1_WIRCmdAmpBlnd_MtrNm_f32(Float data)
 *   Float *Rte_IWriteRef_WhlImbRej_Per1_WIRCmdAmpBlnd_MtrNm_f32(void)
 *   void Rte_IWrite_WhlImbRej_Per1_WhlImbRejCmd_MtrNm_f32(Float data)
 *   Float *Rte_IWriteRef_WhlImbRej_Per1_WhlImbRejCmd_MtrNm_f32(void)
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
 *   Std_ReturnType Rte_Call_SystemTime_DtrmnElapsedTime_mS_u32(UInt32 InitialTime, UInt32 *ElapsedTime)
 *     Synchronous Service Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_SystemTime_GetSystemTime_mS_u32(UInt32 *CurrentTime)
 *     Synchronous Service Invocation. Timeout: None
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_WHLIMBREJ_APPL_CODE) WhlImbRej_Per1(void);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: WhlImbRej_Per2
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 4ms
 *     and not in Mode(s) <DISABLE, WARMINIT, OFF>
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

FUNC(void, RTE_AP_WHLIMBREJ_APPL_CODE) WhlImbRej_Per2(void);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: WhlImbRej_Per3
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 2ms
 *     and not in Mode(s) <OPERATE>
 *
 **********************************************************************************************************************
 *
 * Output Interfaces:
 * ==================
 *   Implicit S/R API:
 *   -----------------
 *   void Rte_IWrite_WhlImbRej_Per3_WhlImbRejCmd_MtrNm_f32(Float data)
 *   Float *Rte_IWriteRef_WhlImbRej_Per3_WhlImbRejCmd_MtrNm_f32(void)
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

FUNC(void, RTE_AP_WHLIMBREJ_APPL_CODE) WhlImbRej_Per3(void);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: WhlImbRej_SCom_GetWIRInfo
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <GetWIRInfo> of PortPrototype <WhlImbRej_SCom>
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
 *   void WhlImbRej_SCom_GetWIRInfo(UInt32 *WIRCmpActRng1Ptr_Cnt_u32, UInt32 *WIRCmpActRng2Ptr_Cnt_u32, UInt32 *WIRCmpActRng3Ptr_Cnt_u32, UInt16 *AlgFltStatusPtr_Cnt_b16, Float *WIRMaxCompPtr_Pct_f32)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_WHLIMBREJ_APPL_CODE) WhlImbRej_SCom_GetWIRInfo(P2VAR(UInt32, AUTOMATIC, RTE_AP_WHLIMBREJ_APPL_VAR) WIRCmpActRng1Ptr_Cnt_u32, P2VAR(UInt32, AUTOMATIC, RTE_AP_WHLIMBREJ_APPL_VAR) WIRCmpActRng2Ptr_Cnt_u32, P2VAR(UInt32, AUTOMATIC, RTE_AP_WHLIMBREJ_APPL_VAR) WIRCmpActRng3Ptr_Cnt_u32, P2VAR(UInt16, AUTOMATIC, RTE_AP_WHLIMBREJ_APPL_VAR) AlgFltStatusPtr_Cnt_b16, P2VAR(Float, AUTOMATIC, RTE_AP_WHLIMBREJ_APPL_VAR) WIRMaxCompPtr_Pct_f32);

# define RTE_STOP_SEC_AP_WHLIMBREJ_APPL_CODE
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
#   if RTE_MAGIC_NUMBER != 1352810908
#    error "The magic number of the generated file <C:/Synergy/WhlImbRej-zz4r1x/WhlImbRej/utp/contract/Rte_Ap_WhlImbRej.h> is different. Please check time and date of the generated RTE files!"
#   endif
#  else
#   define RTE_MAGIC_NUMBER 1352810908
#  endif  /* RTE_MAGIC_NUMBER */
# endif  /* SKIP_MAGIC_NUMBER */
/* end Fileversion check */

#endif /* _RTE_AP_WHLIMBREJ_H */
