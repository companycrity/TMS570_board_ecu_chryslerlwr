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
 *          File:  Rte_Ap_WIRInputQual.h
 *     Workspace:  C:/SynergyWorkArea/GMK2XXRT2.0/GM_K2XX_EPS_TMS570/SwProject/WIRInputQual/autosar
 *     SW-C Type:  Ap_WIRInputQual
 *  Generated at:  Sun Nov 11 10:32:55 2012
 *
 *     Generator:  MICROSAR RTE Generator Version 2.19.1
 *       License:  License CBD1010124 valid for CBD1010124 Nexteer  Package: BMW MSR SIP BAC3.0     Micro: TI TMS570 TMS570LS30306  Compiler: Code Composer Studio 4.9.0
 *
 *   Description:  Application header file for SW-C <Ap_WIRInputQual> (Contract Phase)
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_AP_WIRINPUTQUAL_H
# define _RTE_AP_WIRINPUTQUAL_H

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

typedef P2CONST(struct Rte_CDS_Ap_WIRInputQual, TYPEDEF, RTE_CONST) Rte_Instance;


/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

# define Rte_InitValue_QualWhlFreqL_Hz_f32 (0.0F)
# define Rte_InitValue_QualWhlFreqR_Hz_f32 (0.0F)
# define Rte_InitValue_SrlComLWhlSpd_Hz_f32 (0.0F)
# define Rte_InitValue_SrlComLWhlSpdVld_Cnt_lgc (FALSE)
# define Rte_InitValue_SrlComRWhlSpd_Hz_f32 (0.0F)
# define Rte_InitValue_SrlComRWhlSpdVld_Cnt_lgc (FALSE)
# define Rte_InitValue_WhlFreqQualified_Cnt_lgc (TRUE)


# define RTE_START_SEC_CODE
# include "MemMap.h"

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ap_WIRInputQual_SystemTime_DtrmnElapsedTime_mS_u16(UInt32 InitialTime, P2VAR(UInt16, AUTOMATIC, RTE_AP_WIRINPUTQUAL_APPL_VAR) ElapsedTime);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ap_WIRInputQual_SystemTime_GetSystemTime_mS_u32(P2VAR(UInt32, AUTOMATIC, RTE_AP_WIRINPUTQUAL_APPL_VAR) CurrentTime);

# define RTE_STOP_SEC_CODE
# include "MemMap.h"



/**********************************************************************************************************************
 * Rte_IRead_<r>_<p>_<d>
 * Rte_IStatus_<r>_<p>_<d>
 * Rte_IWrite_<r>_<p>_<d>
 * Rte_IWriteRef_<r>_<p>_<d>
 * Rte_IInvalidate_<r>_<p>_<d>
 *********************************************************************************************************************/

# define Rte_IRead_WIRInputQual_Per1_SrlComLWhlSpdVld_Cnt_lgc() \
  (Rte_Inst_Ap_WIRInputQual->WIRInputQual_Per1_SrlComLWhlSpdVld_Cnt_lgc->value)

# define Rte_IRead_WIRInputQual_Per1_SrlComLWhlSpd_Hz_f32() \
  (Rte_Inst_Ap_WIRInputQual->WIRInputQual_Per1_SrlComLWhlSpd_Hz_f32->value)

# define Rte_IRead_WIRInputQual_Per1_SrlComRWhlSpdVld_Cnt_lgc() \
  (Rte_Inst_Ap_WIRInputQual->WIRInputQual_Per1_SrlComRWhlSpdVld_Cnt_lgc->value)

# define Rte_IRead_WIRInputQual_Per1_SrlComRWhlSpd_Hz_f32() \
  (Rte_Inst_Ap_WIRInputQual->WIRInputQual_Per1_SrlComRWhlSpd_Hz_f32->value)

# define Rte_IWrite_WIRInputQual_Per1_QualWhlFreqL_Hz_f32(data) \
  ( \
  Rte_Inst_Ap_WIRInputQual->WIRInputQual_Per1_QualWhlFreqL_Hz_f32->value = (data) \
  )

# define Rte_IWriteRef_WIRInputQual_Per1_QualWhlFreqL_Hz_f32() \
  (&Rte_Inst_Ap_WIRInputQual->WIRInputQual_Per1_QualWhlFreqL_Hz_f32->value)

# define Rte_IWrite_WIRInputQual_Per1_QualWhlFreqR_Hz_f32(data) \
  ( \
  Rte_Inst_Ap_WIRInputQual->WIRInputQual_Per1_QualWhlFreqR_Hz_f32->value = (data) \
  )

# define Rte_IWriteRef_WIRInputQual_Per1_QualWhlFreqR_Hz_f32() \
  (&Rte_Inst_Ap_WIRInputQual->WIRInputQual_Per1_QualWhlFreqR_Hz_f32->value)

# define Rte_IWrite_WIRInputQual_Per1_WhlFreqQualified_Cnt_lgc(data) \
  ( \
  Rte_Inst_Ap_WIRInputQual->WIRInputQual_Per1_WhlFreqQualified_Cnt_lgc->value = (data) \
  )

# define Rte_IWriteRef_WIRInputQual_Per1_WhlFreqQualified_Cnt_lgc() \
  (&Rte_Inst_Ap_WIRInputQual->WIRInputQual_Per1_WhlFreqQualified_Cnt_lgc->value)


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (C/S invocation)
 *********************************************************************************************************************/
# define Rte_Call_SystemTime_DtrmnElapsedTime_mS_u16 Rte_Call_Ap_WIRInputQual_SystemTime_DtrmnElapsedTime_mS_u16
# define Rte_Call_SystemTime_GetSystemTime_mS_u32 Rte_Call_Ap_WIRInputQual_SystemTime_GetSystemTime_mS_u32




# define RTE_START_SEC_AP_WIRINPUTQUAL_APPL_CODE
# include "MemMap.h"


/**********************************************************************************************************************
 *
 * Runnable Entity Name: WIRInputQual_Per1
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
 *   Boolean Rte_IRead_WIRInputQual_Per1_SrlComLWhlSpdVld_Cnt_lgc(void)
 *   Float Rte_IRead_WIRInputQual_Per1_SrlComLWhlSpd_Hz_f32(void)
 *   Boolean Rte_IRead_WIRInputQual_Per1_SrlComRWhlSpdVld_Cnt_lgc(void)
 *   Float Rte_IRead_WIRInputQual_Per1_SrlComRWhlSpd_Hz_f32(void)
 *
 * Output Interfaces:
 * ==================
 *   Implicit S/R API:
 *   -----------------
 *   void Rte_IWrite_WIRInputQual_Per1_QualWhlFreqL_Hz_f32(Float data)
 *   Float *Rte_IWriteRef_WIRInputQual_Per1_QualWhlFreqL_Hz_f32(void)
 *   void Rte_IWrite_WIRInputQual_Per1_QualWhlFreqR_Hz_f32(Float data)
 *   Float *Rte_IWriteRef_WIRInputQual_Per1_QualWhlFreqR_Hz_f32(void)
 *   void Rte_IWrite_WIRInputQual_Per1_WhlFreqQualified_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_WIRInputQual_Per1_WhlFreqQualified_Cnt_lgc(void)
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

FUNC(void, RTE_AP_WIRINPUTQUAL_APPL_CODE) WIRInputQual_Per1(void);

# define RTE_STOP_SEC_AP_WIRINPUTQUAL_APPL_CODE
# include "MemMap.h"

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

/* begin Fileversion check */
# ifndef SKIP_MAGIC_NUMBER
#  ifdef RTE_MAGIC_NUMBER
#   if RTE_MAGIC_NUMBER != 1352651398
#    error "The magic number of the generated file <C:/SynergyWorkArea/GMK2XXRT2.0/GM_K2XX_EPS_TMS570/SwProject/WIRInputQual/utp/contract/Ap_WIRInputQual/Rte_Ap_WIRInputQual.h> is different. Please check time and date of the generated RTE files!"
#   endif
#  else
#   define RTE_MAGIC_NUMBER 1352651398
#  endif  /* RTE_MAGIC_NUMBER */
# endif  /* SKIP_MAGIC_NUMBER */
/* end Fileversion check */

#endif /* _RTE_AP_WIRINPUTQUAL_H */
