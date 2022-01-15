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
 *          File:  Rte_Ap_StbCTO.h
 *     Workspace:  C:/Synergy/working_projects/ESG_Dev_65/StbCTO/StbCTO/autosar
 *     SW-C Type:  Ap_StbCTO
 *  Generated at:  Thu Jan 23 15:19:09 2014
 *
 *     Generator:  MICROSAR RTE Generator Version 2.17.2
 *       License:  License CBD1010122 valid for CBD1010122 Nexteer  GM MSR_SLP3_BSW_RTE_wGMLAN TexasInstruments TMS570 Texas Instruments
 *
 *   Description:  Application header file for SW-C <Ap_StbCTO> (Contract Phase)
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_AP_STBCTO_H
# define _RTE_AP_STBCTO_H

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

typedef P2CONST(struct Rte_CDS_Ap_StbCTO, TYPEDEF, RTE_CONST) Rte_Instance;


/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

# define Rte_InitValue_DSTActive_Cnt_lgc ((Boolean)FALSE)
# define Rte_InitValue_DSTEnableRqst_Cnt_lgc ((Boolean)FALSE)
# define Rte_InitValue_DSTErrCntrRecvLevel_Cnt_u08 ((UInt8)0u)
# define Rte_InitValue_DSTExtSystemFltActive_Cnt_lgc ((Boolean)FALSE)
# define Rte_InitValue_DSTFuncPresent_Cnt_lgc ((Boolean)FALSE)
# define Rte_InitValue_DSTRevGearValid_Cnt_lgc ((Boolean)FALSE)
# define Rte_InitValue_DSTSlewComplete_Cnt_lgc ((Boolean)TRUE)
# define Rte_InitValue_DSTSlewStart_Cnt_lgc ((Boolean)FALSE)
# define Rte_InitValue_DSTState_Cnt_u08 ((UInt8)0u)
# define Rte_InitValue_DSTTOCState_Uls_enum ((TOC_STATE)0u)
# define Rte_InitValue_DSTTrqOvCmdRqst_HwNm_f32 ((Float)0)
# define Rte_InitValue_DSTTrqOvRqstValid_Cnt_lgc ((Boolean)FALSE)
# define Rte_InitValue_DiagRedAssistLowVoltageActive_Cnt_lgc ((Boolean)FALSE)
# define Rte_InitValue_DiagStsNonRecRmpToZeroFltPres_Cnt_lgc ((Boolean)FALSE)
# define Rte_InitValue_DiagStsRecRmpToZeroFltPres_Cnt_lgc ((Boolean)FALSE)
# define Rte_InitValue_LimitPercentFiltered_Uls_f32 ((Float)0)
# define Rte_InitValue_TOEOLDisable_Cnt_lgc ((Boolean)FALSE)
# define Rte_InitValue_TrqOvReverseGearEngage_Cnt_lgc ((Boolean)FALSE)
# define Rte_InitValue_VehicleSpeed_Kph_f32 ((Float)0)
# define Rte_InitValue_VehicleSpeedValid_Cnt_lgc ((Boolean)FALSE)


# define RTE_START_SEC_CODE
# include "MemMap.h"

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/
FUNC(Rte_ModeType_StaMd_Mode, RTE_CODE) Rte_Mode_Ap_StbCTO_SystemState_Mode(void);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ap_StbCTO_NxtrDiagMgr_GetNTCActive(NTCNumber NTC_Cnt_T_enum, P2VAR(Boolean, AUTOMATIC, RTE_AP_STBCTO_APPL_VAR) NTCActive_Ptr_T_lgc);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ap_StbCTO_NxtrDiagMgr_GetNTCFailed(NTCNumber NTC_Cnt_T_enum, P2VAR(Boolean, AUTOMATIC, RTE_AP_STBCTO_APPL_VAR) NTCFailed_Ptr_T_lgc);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ap_StbCTO_NxtrDiagMgr_SetNTCStatus(NTCNumber NTC_Cnt_T_enum, UInt8 Param_Cnt_T_u08, NxtrDiagMgrStatus Status_Cnt_T_enum);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ap_StbCTO_SystemTime_DtrmnElapsedTime_mS_u16(UInt32 InitialTime, P2VAR(UInt16, AUTOMATIC, RTE_AP_STBCTO_APPL_VAR) ElapsedTime);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ap_StbCTO_SystemTime_GetSystemTime_mS_u32(P2VAR(UInt32, AUTOMATIC, RTE_AP_STBCTO_APPL_VAR) CurrentTime);

# define RTE_STOP_SEC_CODE
# include "MemMap.h"



/**********************************************************************************************************************
 * Rte_IRead_<r>_<p>_<d>
 * Rte_IStatus_<r>_<p>_<d>
 * Rte_IWrite_<r>_<p>_<d>
 * Rte_IWriteRef_<r>_<p>_<d>
 * Rte_IInvalidate_<r>_<p>_<d>
 *********************************************************************************************************************/

# define Rte_IWrite_StbCTO_Init1_DSTActive_Cnt_lgc(data) \
  ( \
  Rte_Inst_Ap_StbCTO->StbCTO_Init1_DSTActive_Cnt_lgc->value = (data) \
  )

# define Rte_IWriteRef_StbCTO_Init1_DSTActive_Cnt_lgc() \
  (&Rte_Inst_Ap_StbCTO->StbCTO_Init1_DSTActive_Cnt_lgc->value)

# define Rte_IWrite_StbCTO_Init1_DSTSlewStart_Cnt_lgc(data) \
  ( \
  Rte_Inst_Ap_StbCTO->StbCTO_Init1_DSTSlewStart_Cnt_lgc->value = (data) \
  )

# define Rte_IWriteRef_StbCTO_Init1_DSTSlewStart_Cnt_lgc() \
  (&Rte_Inst_Ap_StbCTO->StbCTO_Init1_DSTSlewStart_Cnt_lgc->value)

# define Rte_IRead_StbCTO_Per1_DSTEnableRqst_Cnt_lgc() \
  (Rte_Inst_Ap_StbCTO->StbCTO_Per1_DSTEnableRqst_Cnt_lgc->value)

# define Rte_IRead_StbCTO_Per1_DSTErrCntrRecvLevel_Cnt_u08() \
  (Rte_Inst_Ap_StbCTO->StbCTO_Per1_DSTErrCntrRecvLevel_Cnt_u08->value)

# define Rte_IRead_StbCTO_Per1_DSTExtSystemFltActive_Cnt_lgc() \
  (Rte_Inst_Ap_StbCTO->StbCTO_Per1_DSTExtSystemFltActive_Cnt_lgc->value)

# define Rte_IRead_StbCTO_Per1_DSTFuncPresent_Cnt_lgc() \
  (Rte_Inst_Ap_StbCTO->StbCTO_Per1_DSTFuncPresent_Cnt_lgc->value)

# define Rte_IRead_StbCTO_Per1_DSTRevGearValid_Cnt_lgc() \
  (Rte_Inst_Ap_StbCTO->StbCTO_Per1_DSTRevGearValid_Cnt_lgc->value)

# define Rte_IRead_StbCTO_Per1_DSTSlewComplete_Cnt_lgc() \
  (Rte_Inst_Ap_StbCTO->StbCTO_Per1_DSTSlewComplete_Cnt_lgc->value)

# define Rte_IRead_StbCTO_Per1_DSTTOCState_Uls_enum() \
  (Rte_Inst_Ap_StbCTO->StbCTO_Per1_DSTTOCState_Uls_enum->value)

# define Rte_IRead_StbCTO_Per1_DSTTrqOvCmdRqst_HwNm_f32() \
  (Rte_Inst_Ap_StbCTO->StbCTO_Per1_DSTTrqOvCmdRqst_HwNm_f32->value)

# define Rte_IRead_StbCTO_Per1_DSTTrqOvRqstValid_Cnt_lgc() \
  (Rte_Inst_Ap_StbCTO->StbCTO_Per1_DSTTrqOvRqstValid_Cnt_lgc->value)

# define Rte_IRead_StbCTO_Per1_DiagRedAssistLowVoltageActive_Cnt_lgc() \
  (Rte_Inst_Ap_StbCTO->StbCTO_Per1_DiagRedAssistLowVoltageActive_Cnt_lgc->value)

# define Rte_IRead_StbCTO_Per1_DiagStsNonRecRmpToZeroFltPres_Cnt_lgc() \
  (Rte_Inst_Ap_StbCTO->StbCTO_Per1_DiagStsNonRecRmpToZeroFltPres_Cnt_lgc->value)

# define Rte_IRead_StbCTO_Per1_DiagStsRecRmpToZeroFltPres_Cnt_lgc() \
  (Rte_Inst_Ap_StbCTO->StbCTO_Per1_DiagStsRecRmpToZeroFltPres_Cnt_lgc->value)

# define Rte_IRead_StbCTO_Per1_LimitPercentFiltered_Uls_f32() \
  (Rte_Inst_Ap_StbCTO->StbCTO_Per1_LimitPercentFiltered_Uls_f32->value)

# define Rte_IRead_StbCTO_Per1_TOEOLDisable_Cnt_lgc() \
  (Rte_Inst_Ap_StbCTO->StbCTO_Per1_TOEOLDisable_Cnt_lgc->value)

# define Rte_IRead_StbCTO_Per1_TrqOvReverseGearEngage_Cnt_lgc() \
  (Rte_Inst_Ap_StbCTO->StbCTO_Per1_TrqOvReverseGearEngage_Cnt_lgc->value)

# define Rte_IRead_StbCTO_Per1_VehicleSpeedValid_Cnt_lgc() \
  (Rte_Inst_Ap_StbCTO->StbCTO_Per1_VehicleSpeedValid_Cnt_lgc->value)

# define Rte_IRead_StbCTO_Per1_VehicleSpeed_Kph_f32() \
  (Rte_Inst_Ap_StbCTO->StbCTO_Per1_VehicleSpeed_Kph_f32->value)

# define Rte_IWrite_StbCTO_Per1_DSTActive_Cnt_lgc(data) \
  ( \
  Rte_Inst_Ap_StbCTO->StbCTO_Per1_DSTActive_Cnt_lgc->value = (data) \
  )

# define Rte_IWriteRef_StbCTO_Per1_DSTActive_Cnt_lgc() \
  (&Rte_Inst_Ap_StbCTO->StbCTO_Per1_DSTActive_Cnt_lgc->value)

# define Rte_IWrite_StbCTO_Per1_DSTSlewStart_Cnt_lgc(data) \
  ( \
  Rte_Inst_Ap_StbCTO->StbCTO_Per1_DSTSlewStart_Cnt_lgc->value = (data) \
  )

# define Rte_IWriteRef_StbCTO_Per1_DSTSlewStart_Cnt_lgc() \
  (&Rte_Inst_Ap_StbCTO->StbCTO_Per1_DSTSlewStart_Cnt_lgc->value)

# define Rte_IWrite_StbCTO_Per1_DSTState_Cnt_u08(data) \
  ( \
  Rte_Inst_Ap_StbCTO->StbCTO_Per1_DSTState_Cnt_u08->value = (data) \
  )

# define Rte_IWriteRef_StbCTO_Per1_DSTState_Cnt_u08() \
  (&Rte_Inst_Ap_StbCTO->StbCTO_Per1_DSTState_Cnt_u08->value)


/**********************************************************************************************************************
 * Rte_Mode_<p>_<m>
 *********************************************************************************************************************/
# define Rte_Mode_SystemState_Mode Rte_Mode_Ap_StbCTO_SystemState_Mode


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (C/S invocation)
 *********************************************************************************************************************/
# define Rte_Call_NxtrDiagMgr_GetNTCActive Rte_Call_Ap_StbCTO_NxtrDiagMgr_GetNTCActive
# define Rte_Call_NxtrDiagMgr_GetNTCFailed Rte_Call_Ap_StbCTO_NxtrDiagMgr_GetNTCFailed
# define Rte_Call_NxtrDiagMgr_SetNTCStatus Rte_Call_Ap_StbCTO_NxtrDiagMgr_SetNTCStatus
# define Rte_Call_SystemTime_DtrmnElapsedTime_mS_u16 Rte_Call_Ap_StbCTO_SystemTime_DtrmnElapsedTime_mS_u16
# define Rte_Call_SystemTime_GetSystemTime_mS_u32 Rte_Call_Ap_StbCTO_SystemTime_GetSystemTime_mS_u32




# define RTE_START_SEC_AP_STBCTO_APPL_CODE
# include "MemMap.h"


/**********************************************************************************************************************
 *
 * Runnable Entity Name: StbCTO_Init1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 **********************************************************************************************************************
 *
 * Output Interfaces:
 * ==================
 *   Implicit S/R API:
 *   -----------------
 *   void Rte_IWrite_StbCTO_Init1_DSTActive_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_StbCTO_Init1_DSTActive_Cnt_lgc(void)
 *   void Rte_IWrite_StbCTO_Init1_DSTSlewStart_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_StbCTO_Init1_DSTSlewStart_Cnt_lgc(void)
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
 *   Std_ReturnType Rte_Call_SystemTime_GetSystemTime_mS_u32(UInt32 *CurrentTime)
 *     Synchronous Service Invocation. Timeout: None
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_STBCTO_APPL_CODE) StbCTO_Init1(void);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: StbCTO_Per1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 2ms
 *     and not in Mode(s) <OFF>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Implicit S/R API:
 *   -----------------
 *   Boolean Rte_IRead_StbCTO_Per1_DSTEnableRqst_Cnt_lgc(void)
 *   UInt8 Rte_IRead_StbCTO_Per1_DSTErrCntrRecvLevel_Cnt_u08(void)
 *   Boolean Rte_IRead_StbCTO_Per1_DSTExtSystemFltActive_Cnt_lgc(void)
 *   Boolean Rte_IRead_StbCTO_Per1_DSTFuncPresent_Cnt_lgc(void)
 *   Boolean Rte_IRead_StbCTO_Per1_DSTRevGearValid_Cnt_lgc(void)
 *   Boolean Rte_IRead_StbCTO_Per1_DSTSlewComplete_Cnt_lgc(void)
 *   TOC_STATE Rte_IRead_StbCTO_Per1_DSTTOCState_Uls_enum(void)
 *   Float Rte_IRead_StbCTO_Per1_DSTTrqOvCmdRqst_HwNm_f32(void)
 *   Boolean Rte_IRead_StbCTO_Per1_DSTTrqOvRqstValid_Cnt_lgc(void)
 *   Boolean Rte_IRead_StbCTO_Per1_DiagRedAssistLowVoltageActive_Cnt_lgc(void)
 *   Boolean Rte_IRead_StbCTO_Per1_DiagStsNonRecRmpToZeroFltPres_Cnt_lgc(void)
 *   Boolean Rte_IRead_StbCTO_Per1_DiagStsRecRmpToZeroFltPres_Cnt_lgc(void)
 *   Float Rte_IRead_StbCTO_Per1_LimitPercentFiltered_Uls_f32(void)
 *   Boolean Rte_IRead_StbCTO_Per1_TOEOLDisable_Cnt_lgc(void)
 *   Boolean Rte_IRead_StbCTO_Per1_TrqOvReverseGearEngage_Cnt_lgc(void)
 *   Boolean Rte_IRead_StbCTO_Per1_VehicleSpeedValid_Cnt_lgc(void)
 *   Float Rte_IRead_StbCTO_Per1_VehicleSpeed_Kph_f32(void)
 *
 * Output Interfaces:
 * ==================
 *   Implicit S/R API:
 *   -----------------
 *   void Rte_IWrite_StbCTO_Per1_DSTActive_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_StbCTO_Per1_DSTActive_Cnt_lgc(void)
 *   void Rte_IWrite_StbCTO_Per1_DSTSlewStart_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_StbCTO_Per1_DSTSlewStart_Cnt_lgc(void)
 *   void Rte_IWrite_StbCTO_Per1_DSTState_Cnt_u08(UInt8 data)
 *   UInt8 *Rte_IWriteRef_StbCTO_Per1_DSTState_Cnt_u08(void)
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
 *   Std_ReturnType Rte_Call_NxtrDiagMgr_GetNTCActive(NTCNumber NTC_Cnt_T_enum, Boolean *NTCActive_Ptr_T_lgc)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NxtrDiagMgr_E_NOT_OK
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

FUNC(void, RTE_AP_STBCTO_APPL_CODE) StbCTO_Per1(void);

# define RTE_STOP_SEC_AP_STBCTO_APPL_CODE
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
#   if RTE_MAGIC_NUMBER != 1390508905
#    error "The magic number of the generated file <C:/Synergy/working_projects/ESG_Dev_65/StbCTO/StbCTO/utp/contract/Ap_StbCTO/Rte_Ap_StbCTO.h> is different. Please check time and date of the generated RTE files!"
#   endif
#  else
#   define RTE_MAGIC_NUMBER 1390508905
#  endif  /* RTE_MAGIC_NUMBER */
# endif  /* SKIP_MAGIC_NUMBER */
/* end Fileversion check */

#endif /* _RTE_AP_STBCTO_H */
