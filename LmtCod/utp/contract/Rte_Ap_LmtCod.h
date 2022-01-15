


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
 *          File:  Rte_Ap_LmtCod.h
 *     Workspace:  C:/cmsynergy/CBD_LmtCod_SF38/LmtCod-wz7x3j/LmtCod/autosar/Ap_LmtCod.dcf
 *     SW-C Type:  Ap_LmtCod
 *  Generated at:  Fri May 17 08:56:54 2013
 *
 *     Generator:  MICROSAR RTE Generator Version 2.19.1 (Beta)
 *       License:  License CBD1010124 valid for CBD1010124 Nexteer  Package: BMW MSR SIP BAC3.0     Micro: TI TMS570 TMS570LS30306  Compiler: Code Composer Studio 4.9.0
 *
 *   Description:  Application header file for SW-C <Ap_LmtCod> (Contract Phase)
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_AP_LMTCOD_H
# define _RTE_AP_LMTCOD_H

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

typedef P2CONST(struct Rte_CDS_Ap_LmtCod, TYPEDEF, RTE_CONST) Rte_Instance;


/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

# define Rte_InitValue_AssistEOTGain_Uls_f32 (1.0F)
# define Rte_InitValue_AssistEOTLimit_MtrNm_f32 (8.8F)
# define Rte_InitValue_AssistStallLimit_MtrNm_f32 (8.8F)
# define Rte_InitValue_AssistVehSpdLimit_MtrNm_f32 (8.8F)
# define Rte_InitValue_EOTGainLtd_Uls_f32 (1.0F)
# define Rte_InitValue_EOTLimitLtd_MtrNm_f32 (8.8F)
# define Rte_InitValue_OutputRampMult_Uls_f32 (0.0F)
# define Rte_InitValue_OutputRampMultLtd_Uls_f32 (0.0F)
# define Rte_InitValue_StallLimitLtd_MtrNm_f32 (8.8F)
# define Rte_InitValue_ThermalLimit_MtrNm_f32 (8.8F)
# define Rte_InitValue_ThermalLimitLtd_MtrNm_f32 (8.8F)
# define Rte_InitValue_VehSpdLimitLtd_MtrNm_f32 (8.8F)
# define Rte_InitValue_VehicleSpeed_Kph_f32 (0.0F)


# define RTE_START_SEC_CODE
# include "MemMap.h"

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ap_LmtCod_FltInjection_SCom_FltInjection(P2VAR(Float, AUTOMATIC, RTE_AP_LMTCOD_APPL_VAR) SignalPath_Uls_f32, FltInjectionLocType LocationKey_Cnt_enum);

# define RTE_STOP_SEC_CODE
# include "MemMap.h"



/**********************************************************************************************************************
 * Rte_IRead_<r>_<p>_<d>
 * Rte_IStatus_<r>_<p>_<d>
 * Rte_IWrite_<r>_<p>_<d>
 * Rte_IWriteRef_<r>_<p>_<d>
 * Rte_IInvalidate_<r>_<p>_<d>
 *********************************************************************************************************************/

# define Rte_IRead_LmtCod_Per1_AssistEOTGain_Uls_f32() \
  (Rte_Inst_Ap_LmtCod->LmtCod_Per1_AssistEOTGain_Uls_f32->value)

# define Rte_IRead_LmtCod_Per1_AssistEOTLimit_MtrNm_f32() \
  (Rte_Inst_Ap_LmtCod->LmtCod_Per1_AssistEOTLimit_MtrNm_f32->value)

# define Rte_IRead_LmtCod_Per1_AssistStallLimit_MtrNm_f32() \
  (Rte_Inst_Ap_LmtCod->LmtCod_Per1_AssistStallLimit_MtrNm_f32->value)

# define Rte_IRead_LmtCod_Per1_AssistVehSpdLimit_MtrNm_f32() \
  (Rte_Inst_Ap_LmtCod->LmtCod_Per1_AssistVehSpdLimit_MtrNm_f32->value)

# define Rte_IRead_LmtCod_Per1_OutputRampMult_Uls_f32() \
  (Rte_Inst_Ap_LmtCod->LmtCod_Per1_OutputRampMult_Uls_f32->value)

# define Rte_IRead_LmtCod_Per1_ThermalLimit_MtrNm_f32() \
  (Rte_Inst_Ap_LmtCod->LmtCod_Per1_ThermalLimit_MtrNm_f32->value)

# define Rte_IRead_LmtCod_Per1_VehicleSpeed_Kph_f32() \
  (Rte_Inst_Ap_LmtCod->LmtCod_Per1_VehicleSpeed_Kph_f32->value)

# define Rte_IWrite_LmtCod_Per1_EOTGainLtd_Uls_f32(data) \
  ( \
  Rte_Inst_Ap_LmtCod->LmtCod_Per1_EOTGainLtd_Uls_f32->value = (data) \
  )

# define Rte_IWriteRef_LmtCod_Per1_EOTGainLtd_Uls_f32() \
  (&Rte_Inst_Ap_LmtCod->LmtCod_Per1_EOTGainLtd_Uls_f32->value)

# define Rte_IWrite_LmtCod_Per1_EOTLimitLtd_MtrNm_f32(data) \
  ( \
  Rte_Inst_Ap_LmtCod->LmtCod_Per1_EOTLimitLtd_MtrNm_f32->value = (data) \
  )

# define Rte_IWriteRef_LmtCod_Per1_EOTLimitLtd_MtrNm_f32() \
  (&Rte_Inst_Ap_LmtCod->LmtCod_Per1_EOTLimitLtd_MtrNm_f32->value)

# define Rte_IWrite_LmtCod_Per1_OutputRampMultLtd_Uls_f32(data) \
  ( \
  Rte_Inst_Ap_LmtCod->LmtCod_Per1_OutputRampMultLtd_Uls_f32->value = (data) \
  )

# define Rte_IWriteRef_LmtCod_Per1_OutputRampMultLtd_Uls_f32() \
  (&Rte_Inst_Ap_LmtCod->LmtCod_Per1_OutputRampMultLtd_Uls_f32->value)

# define Rte_IWrite_LmtCod_Per1_StallLimitLtd_MtrNm_f32(data) \
  ( \
  Rte_Inst_Ap_LmtCod->LmtCod_Per1_StallLimitLtd_MtrNm_f32->value = (data) \
  )

# define Rte_IWriteRef_LmtCod_Per1_StallLimitLtd_MtrNm_f32() \
  (&Rte_Inst_Ap_LmtCod->LmtCod_Per1_StallLimitLtd_MtrNm_f32->value)

# define Rte_IWrite_LmtCod_Per1_ThermalLimitLtd_MtrNm_f32(data) \
  ( \
  Rte_Inst_Ap_LmtCod->LmtCod_Per1_ThermalLimitLtd_MtrNm_f32->value = (data) \
  )

# define Rte_IWriteRef_LmtCod_Per1_ThermalLimitLtd_MtrNm_f32() \
  (&Rte_Inst_Ap_LmtCod->LmtCod_Per1_ThermalLimitLtd_MtrNm_f32->value)

# define Rte_IWrite_LmtCod_Per1_VehSpdLimitLtd_MtrNm_f32(data) \
  ( \
  Rte_Inst_Ap_LmtCod->LmtCod_Per1_VehSpdLimitLtd_MtrNm_f32->value = (data) \
  )

# define Rte_IWriteRef_LmtCod_Per1_VehSpdLimitLtd_MtrNm_f32() \
  (&Rte_Inst_Ap_LmtCod->LmtCod_Per1_VehSpdLimitLtd_MtrNm_f32->value)


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (C/S invocation)
 *********************************************************************************************************************/
# define Rte_Call_FltInjection_SCom_FltInjection Rte_Call_Ap_LmtCod_FltInjection_SCom_FltInjection




# define RTE_START_SEC_AP_LMTCOD_APPL_CODE
# include "MemMap.h"


/**********************************************************************************************************************
 *
 * Runnable Entity Name: LmtCod_Per1
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
 *   Float Rte_IRead_LmtCod_Per1_AssistEOTGain_Uls_f32(void)
 *   Float Rte_IRead_LmtCod_Per1_AssistEOTLimit_MtrNm_f32(void)
 *   Float Rte_IRead_LmtCod_Per1_AssistStallLimit_MtrNm_f32(void)
 *   Float Rte_IRead_LmtCod_Per1_AssistVehSpdLimit_MtrNm_f32(void)
 *   Float Rte_IRead_LmtCod_Per1_OutputRampMult_Uls_f32(void)
 *   Float Rte_IRead_LmtCod_Per1_ThermalLimit_MtrNm_f32(void)
 *   Float Rte_IRead_LmtCod_Per1_VehicleSpeed_Kph_f32(void)
 *
 * Output Interfaces:
 * ==================
 *   Implicit S/R API:
 *   -----------------
 *   void Rte_IWrite_LmtCod_Per1_EOTGainLtd_Uls_f32(Float data)
 *   Float *Rte_IWriteRef_LmtCod_Per1_EOTGainLtd_Uls_f32(void)
 *   void Rte_IWrite_LmtCod_Per1_EOTLimitLtd_MtrNm_f32(Float data)
 *   Float *Rte_IWriteRef_LmtCod_Per1_EOTLimitLtd_MtrNm_f32(void)
 *   void Rte_IWrite_LmtCod_Per1_OutputRampMultLtd_Uls_f32(Float data)
 *   Float *Rte_IWriteRef_LmtCod_Per1_OutputRampMultLtd_Uls_f32(void)
 *   void Rte_IWrite_LmtCod_Per1_StallLimitLtd_MtrNm_f32(Float data)
 *   Float *Rte_IWriteRef_LmtCod_Per1_StallLimitLtd_MtrNm_f32(void)
 *   void Rte_IWrite_LmtCod_Per1_ThermalLimitLtd_MtrNm_f32(Float data)
 *   Float *Rte_IWriteRef_LmtCod_Per1_ThermalLimitLtd_MtrNm_f32(void)
 *   void Rte_IWrite_LmtCod_Per1_VehSpdLimitLtd_MtrNm_f32(Float data)
 *   Float *Rte_IWriteRef_LmtCod_Per1_VehSpdLimitLtd_MtrNm_f32(void)
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_FltInjection_SCom_FltInjection(Float *SignalPath_Uls_f32, FltInjectionLocType LocationKey_Cnt_enum)
 *     Synchronous Server Invocation. Timeout: None
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_LMTCOD_APPL_CODE) LmtCod_Per1(void);

# define RTE_STOP_SEC_AP_LMTCOD_APPL_CODE
# include "MemMap.h"

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

/* begin Fileversion check */
# ifndef SKIP_MAGIC_NUMBER
#  ifdef RTE_MAGIC_NUMBER
#   if RTE_MAGIC_NUMBER != 1368799705
#    error "The magic number of the generated file <C:/cmsynergy/CBD_LmtCod_SF38/LmtCod-wz7x3j/LmtCod/utp/contract/Ap_LmtCod/Rte_Ap_LmtCod.h> is different. Please check time and date of the generated RTE files!"
#   endif
#  else
#   define RTE_MAGIC_NUMBER 1368799705
#  endif  /* RTE_MAGIC_NUMBER */
# endif  /* SKIP_MAGIC_NUMBER */
/* end Fileversion check */

#endif /* _RTE_AP_LMTCOD_H */
