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
 *          File:  Rte_Ap_AbsHwPosScom.h
 *     Workspace:  C:/Synergy/AbsHwPosScom-zz4r1x/AbsHwPosScom/autosar
 *     SW-C Type:  Ap_AbsHwPosScom
 *  Generated at:  Wed Oct 24 15:44:52 2012
 *
 *     Generator:  MICROSAR RTE Generator Version 2.17.2
 *       License:  License CBD1010122 valid for CBD1010122 Nexteer  GM MSR_SLP3_BSW_RTE_wGMLAN TexasInstruments TMS570 Texas Instruments
 *
 *   Description:  Application header file for SW-C <Ap_AbsHwPosScom> (Contract Phase)
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_AP_ABSHWPOSSCOM_H
# define _RTE_AP_ABSHWPOSSCOM_H

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

typedef P2CONST(struct Rte_CDS_Ap_AbsHwPosScom, TYPEDEF, RTE_CONST) Rte_Instance;


/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

# define Rte_InitValue_CRFCumMtrPos_Deg_f32 ((Float)0)
# define Rte_InitValue_CRFMtrTrqCmd_MtrNm_f32 ((Float)0)
# define Rte_InitValue_CRFMtrVel_MtrRadpS_f32 ((Float)0)
# define Rte_InitValue_DiagStsHwPosDis_Cnt_lgc ((Boolean)FALSE)
# define Rte_InitValue_HwPos_HwDeg_f32 ((Float)0)
# define Rte_InitValue_HwPosAuthority_Uls_f32 ((Float)0)
# define Rte_InitValue_HwTrq_HwNm_f32 ((Float)0)
# define Rte_InitValue_KinIntDiagSrlComSvcDft_Cnt_lgc ((Boolean)FALSE)
# define Rte_InitValue_SComInpHwA_HwDeg_f32 ((Float)0)
# define Rte_InitValue_SComInpHwAValid_Cnt_lgc ((Boolean)FALSE)
# define Rte_InitValue_VehicleSpeed_Kph_f32 ((Float)0)
# define Rte_InitValue_VehicleSpeedValid_Cnt_lgc ((Boolean)FALSE)


# define RTE_START_SEC_CODE
# include "MemMap.h"

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ap_AbsHwPosScom_NxtrDiagMgr_SetNTCStatus(NTCNumber NTC_Cnt_T_enum, UInt8 Param_Cnt_T_u08, NxtrDiagMgrStatus Status_Cnt_T_enum);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ap_AbsHwPosScom_SystemTime_DtrmnElapsedTime_mS_u16(UInt32 InitialTime, P2VAR(UInt16, AUTOMATIC, RTE_AP_ABSHWPOSSCOM_APPL_VAR) ElapsedTime);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ap_AbsHwPosScom_SystemTime_GetSystemTime_mS_u32(P2VAR(UInt32, AUTOMATIC, RTE_AP_ABSHWPOSSCOM_APPL_VAR) CurrentTime);

# define RTE_STOP_SEC_CODE
# include "MemMap.h"



/**********************************************************************************************************************
 * Rte_IRead_<r>_<p>_<d>
 * Rte_IStatus_<r>_<p>_<d>
 * Rte_IWrite_<r>_<p>_<d>
 * Rte_IWriteRef_<r>_<p>_<d>
 * Rte_IInvalidate_<r>_<p>_<d>
 *********************************************************************************************************************/

# define Rte_IRead_AbsHwPosScom_Per1_CRFCumMtrPos_Deg_f32() \
  (Rte_Inst_Ap_AbsHwPosScom->AbsHwPosScom_Per1_CRFCumMtrPos_Deg_f32->value)

# define Rte_IRead_AbsHwPosScom_Per1_CRFMtrTrqCmd_MtrNm_f32() \
  (Rte_Inst_Ap_AbsHwPosScom->AbsHwPosScom_Per1_CRFMtrTrqCmd_MtrNm_f32->value)

# define Rte_IRead_AbsHwPosScom_Per1_CRFMtrVel_MtrRadpS_f32() \
  (Rte_Inst_Ap_AbsHwPosScom->AbsHwPosScom_Per1_CRFMtrVel_MtrRadpS_f32->value)

# define Rte_IRead_AbsHwPosScom_Per1_DiagStsHwPosDis_Cnt_lgc() \
  (Rte_Inst_Ap_AbsHwPosScom->AbsHwPosScom_Per1_DiagStsHwPosDis_Cnt_lgc->value)

# define Rte_IRead_AbsHwPosScom_Per1_HwTrq_HwNm_f32() \
  (Rte_Inst_Ap_AbsHwPosScom->AbsHwPosScom_Per1_HwTrq_HwNm_f32->value)

# define Rte_IRead_AbsHwPosScom_Per1_SComInpHwAValid_Cnt_lgc() \
  (Rte_Inst_Ap_AbsHwPosScom->AbsHwPosScom_Per1_SComInpHwAValid_Cnt_lgc->value)

# define Rte_IRead_AbsHwPosScom_Per1_SComInpHwA_HwDeg_f32() \
  (Rte_Inst_Ap_AbsHwPosScom->AbsHwPosScom_Per1_SComInpHwA_HwDeg_f32->value)

# define Rte_IRead_AbsHwPosScom_Per1_VehicleSpeedValid_Cnt_lgc() \
  (Rte_Inst_Ap_AbsHwPosScom->AbsHwPosScom_Per1_VehicleSpeedValid_Cnt_lgc->value)

# define Rte_IRead_AbsHwPosScom_Per1_VehicleSpeed_Kph_f32() \
  (Rte_Inst_Ap_AbsHwPosScom->AbsHwPosScom_Per1_VehicleSpeed_Kph_f32->value)

# define Rte_IWrite_AbsHwPosScom_Per1_HwPosAuthority_Uls_f32(data) \
  ( \
  Rte_Inst_Ap_AbsHwPosScom->AbsHwPosScom_Per1_HwPosAuthority_Uls_f32->value = (data) \
  )

# define Rte_IWriteRef_AbsHwPosScom_Per1_HwPosAuthority_Uls_f32() \
  (&Rte_Inst_Ap_AbsHwPosScom->AbsHwPosScom_Per1_HwPosAuthority_Uls_f32->value)

# define Rte_IWrite_AbsHwPosScom_Per1_HwPos_HwDeg_f32(data) \
  ( \
  Rte_Inst_Ap_AbsHwPosScom->AbsHwPosScom_Per1_HwPos_HwDeg_f32->value = (data) \
  )

# define Rte_IWriteRef_AbsHwPosScom_Per1_HwPos_HwDeg_f32() \
  (&Rte_Inst_Ap_AbsHwPosScom->AbsHwPosScom_Per1_HwPos_HwDeg_f32->value)

# define Rte_IRead_AbsHwPosScom_Per2_KinIntDiagSrlComSvcDft_Cnt_lgc() \
  (Rte_Inst_Ap_AbsHwPosScom->AbsHwPosScom_Per2_KinIntDiagSrlComSvcDft_Cnt_lgc->value)

# define Rte_IRead_AbsHwPosScom_Per3_CRFMtrTrqCmd_MtrNm_f32() \
  (Rte_Inst_Ap_AbsHwPosScom->AbsHwPosScom_Per3_CRFMtrTrqCmd_MtrNm_f32->value)

# define Rte_IRead_AbsHwPosScom_Per3_HwTrq_HwNm_f32() \
  (Rte_Inst_Ap_AbsHwPosScom->AbsHwPosScom_Per3_HwTrq_HwNm_f32->value)


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (C/S invocation)
 *********************************************************************************************************************/
# define Rte_Call_NxtrDiagMgr_SetNTCStatus Rte_Call_Ap_AbsHwPosScom_NxtrDiagMgr_SetNTCStatus
# define Rte_Call_SystemTime_DtrmnElapsedTime_mS_u16 Rte_Call_Ap_AbsHwPosScom_SystemTime_DtrmnElapsedTime_mS_u16
# define Rte_Call_SystemTime_GetSystemTime_mS_u32 Rte_Call_Ap_AbsHwPosScom_SystemTime_GetSystemTime_mS_u32




# define RTE_START_SEC_AP_ABSHWPOSSCOM_APPL_CODE
# include "MemMap.h"


/**********************************************************************************************************************
 *
 * Runnable Entity Name: AbsHwPosScom_Init1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 **********************************************************************************************************************
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
 *   Std_ReturnType Rte_Call_SystemTime_GetSystemTime_mS_u32(UInt32 *CurrentTime)
 *     Synchronous Service Invocation. Timeout: None
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_ABSHWPOSSCOM_APPL_CODE) AbsHwPosScom_Init1(void);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: AbsHwPosScom_Per1
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
 *   Float Rte_IRead_AbsHwPosScom_Per1_CRFCumMtrPos_Deg_f32(void)
 *   Float Rte_IRead_AbsHwPosScom_Per1_CRFMtrTrqCmd_MtrNm_f32(void)
 *   Float Rte_IRead_AbsHwPosScom_Per1_CRFMtrVel_MtrRadpS_f32(void)
 *   Boolean Rte_IRead_AbsHwPosScom_Per1_DiagStsHwPosDis_Cnt_lgc(void)
 *   Float Rte_IRead_AbsHwPosScom_Per1_HwTrq_HwNm_f32(void)
 *   Boolean Rte_IRead_AbsHwPosScom_Per1_SComInpHwAValid_Cnt_lgc(void)
 *   Float Rte_IRead_AbsHwPosScom_Per1_SComInpHwA_HwDeg_f32(void)
 *   Boolean Rte_IRead_AbsHwPosScom_Per1_VehicleSpeedValid_Cnt_lgc(void)
 *   Float Rte_IRead_AbsHwPosScom_Per1_VehicleSpeed_Kph_f32(void)
 *
 * Output Interfaces:
 * ==================
 *   Implicit S/R API:
 *   -----------------
 *   void Rte_IWrite_AbsHwPosScom_Per1_HwPosAuthority_Uls_f32(Float data)
 *   Float *Rte_IWriteRef_AbsHwPosScom_Per1_HwPosAuthority_Uls_f32(void)
 *   void Rte_IWrite_AbsHwPosScom_Per1_HwPos_HwDeg_f32(Float data)
 *   Float *Rte_IWriteRef_AbsHwPosScom_Per1_HwPos_HwDeg_f32(void)
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

FUNC(void, RTE_AP_ABSHWPOSSCOM_APPL_CODE) AbsHwPosScom_Per1(void);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: AbsHwPosScom_Per2
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 10ms
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Implicit S/R API:
 *   -----------------
 *   Boolean Rte_IRead_AbsHwPosScom_Per2_KinIntDiagSrlComSvcDft_Cnt_lgc(void)
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_NxtrDiagMgr_SetNTCStatus(NTCNumber NTC_Cnt_T_enum, UInt8 Param_Cnt_T_u08, NxtrDiagMgrStatus Status_Cnt_T_enum)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NxtrDiagMgr_E_NOT_OK
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_ABSHWPOSSCOM_APPL_CODE) AbsHwPosScom_Per2(void);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: AbsHwPosScom_Per3
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 10ms
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Implicit S/R API:
 *   -----------------
 *   Float Rte_IRead_AbsHwPosScom_Per3_CRFMtrTrqCmd_MtrNm_f32(void)
 *   Float Rte_IRead_AbsHwPosScom_Per3_HwTrq_HwNm_f32(void)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_ABSHWPOSSCOM_APPL_CODE) AbsHwPosScom_Per3(void);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: AbsHwPosScom_Scom_HwPosSrvRead
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <HwPosSrvRead> of PortPrototype <AbsHwPosScom_Scom>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void AbsHwPosScom_Scom_HwPosSrvRead(Boolean *Par)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_ABSHWPOSSCOM_APPL_CODE) AbsHwPosScom_Scom_HwPosSrvRead(P2VAR(Boolean, AUTOMATIC, RTE_AP_ABSHWPOSSCOM_APPL_VAR) Par);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: AbsHwPosScom_Scom_HwPosSrvSetToZero
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <HwPosSrvSetToZero> of PortPrototype <AbsHwPosScom_Scom>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void AbsHwPosScom_Scom_HwPosSrvSetToZero(Boolean Par)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_ABSHWPOSSCOM_APPL_CODE) AbsHwPosScom_Scom_HwPosSrvSetToZero(Boolean Par);

# define RTE_STOP_SEC_AP_ABSHWPOSSCOM_APPL_CODE
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
#   if RTE_MAGIC_NUMBER != 1351111679
#    error "The magic number of the generated file <C:/Synergy/AbsHwPosScom-zz4r1x/AbsHwPosScom/utp/contract/Rte_Ap_AbsHwPosScom.h> is different. Please check time and date of the generated RTE files!"
#   endif
#  else
#   define RTE_MAGIC_NUMBER 1351111679
#  endif  /* RTE_MAGIC_NUMBER */
# endif  /* SKIP_MAGIC_NUMBER */
/* end Fileversion check */

#endif /* _RTE_AP_ABSHWPOSSCOM_H */
