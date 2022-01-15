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
 *          File:  Components/Rte_Ap_LmtCod.h
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
#ifndef _RTE_AP_LMTCOD_H
# define _RTE_AP_LMTCOD_H

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

#  define Rte_InitValue_AssistEOTGain_Uls_f32 (1.0F)
#  define Rte_InitValue_AssistEOTLimit_MtrNm_f32 (8.8F)
#  define Rte_InitValue_AssistStallLimit_MtrNm_f32 (8.8F)
#  define Rte_InitValue_AssistVehSpdLimit_MtrNm_f32 (8.8F)
#  define Rte_InitValue_EOTGainLtd_Uls_f32 (1.0F)
#  define Rte_InitValue_EOTLimitLtd_MtrNm_f32 (8.8F)
#  define Rte_InitValue_OutputRampMult_Uls_f32 (0.0F)
#  define Rte_InitValue_OutputRampMultLtd_Uls_f32 (0.0F)
#  define Rte_InitValue_StallLimitLtd_MtrNm_f32 (8.8F)
#  define Rte_InitValue_ThermalLimit_MtrNm_f32 (8.8F)
#  define Rte_InitValue_ThermalLimitLtd_MtrNm_f32 (8.8F)
#  define Rte_InitValue_VehSpdLimitLtd_MtrNm_f32 (8.8F)
#  define Rte_InitValue_VehicleSpeed_Kph_f32 (0.0F)
# endif


# ifndef RTE_CORE
#  define RTE_START_SEC_VAR_NOINIT_UNSPECIFIED
#  include "MemMap.h"

/**********************************************************************************************************************
 * Buffers for implicit communication
 *********************************************************************************************************************/

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

#  define Rte_IRead_LmtCod_Per1_AssistEOTGain_Uls_f32() \
  (Rte_Task_2ms_9.Rte_RB.Rte_Ap_LmtCod_LmtCod_Per1.Rte_AssistEOTGain_Uls_f32.value)

#  define Rte_IRead_LmtCod_Per1_AssistEOTLimit_MtrNm_f32() \
  (Rte_Task_2ms_9.Rte_RB.Rte_Ap_LmtCod_LmtCod_Per1.Rte_AssistEOTLimit_MtrNm_f32.value)

#  define Rte_IRead_LmtCod_Per1_AssistStallLimit_MtrNm_f32() \
  (Rte_Task_2ms_9.Rte_RB.Rte_Ap_LmtCod_LmtCod_Per1.Rte_AssistStallLimit_MtrNm_f32.value)

#  define Rte_IRead_LmtCod_Per1_AssistVehSpdLimit_MtrNm_f32() \
  (Rte_Task_2ms_9.Rte_TB.Rte_I_VehSpdLmt_AstVehSpdLimit_MtrNm_f32.value)

#  define Rte_IRead_LmtCod_Per1_OutputRampMult_Uls_f32() \
  (Rte_Task_2ms_9.Rte_RB.Rte_Ap_LmtCod_LmtCod_Per1.Rte_OutputRampMult_Uls_f32.value)

#  define Rte_IRead_LmtCod_Per1_ThermalLimit_MtrNm_f32() \
  (Rte_Task_2ms_9.Rte_RB.Rte_Ap_LmtCod_LmtCod_Per1.Rte_ThermalLimit_MtrNm_f32.value)

#  define Rte_IRead_LmtCod_Per1_VehicleSpeed_Kph_f32() \
  (Rte_Task_2ms_9.Rte_TB.Rte_I_Ap_SignlCondn_VehicleSpeed_Kph_f32.value)

#  define Rte_IWrite_LmtCod_Per1_EOTGainLtd_Uls_f32(data) \
  ( \
    Rte_Task_2ms_9.Rte_RB.Rte_Ap_LmtCod_LmtCod_Per1.Rte_EOTGainLtd_Uls_f32.value = (data) \
  )

#  define Rte_IWriteRef_LmtCod_Per1_EOTGainLtd_Uls_f32() \
  (&Rte_Task_2ms_9.Rte_RB.Rte_Ap_LmtCod_LmtCod_Per1.Rte_EOTGainLtd_Uls_f32.value)

#  define Rte_IWrite_LmtCod_Per1_EOTLimitLtd_MtrNm_f32(data) \
  ( \
    Rte_Task_2ms_9.Rte_RB.Rte_Ap_LmtCod_LmtCod_Per1.Rte_EOTLimitLtd_MtrNm_f32.value = (data) \
  )

#  define Rte_IWriteRef_LmtCod_Per1_EOTLimitLtd_MtrNm_f32() \
  (&Rte_Task_2ms_9.Rte_RB.Rte_Ap_LmtCod_LmtCod_Per1.Rte_EOTLimitLtd_MtrNm_f32.value)

#  define Rte_IWrite_LmtCod_Per1_OutputRampMultLtd_Uls_f32(data) \
  ( \
    Rte_Task_2ms_9.Rte_RB.Rte_Ap_LmtCod_LmtCod_Per1.Rte_OutputRampMultLtd_Uls_f32.value = (data) \
  )

#  define Rte_IWriteRef_LmtCod_Per1_OutputRampMultLtd_Uls_f32() \
  (&Rte_Task_2ms_9.Rte_RB.Rte_Ap_LmtCod_LmtCod_Per1.Rte_OutputRampMultLtd_Uls_f32.value)

#  define Rte_IWrite_LmtCod_Per1_StallLimitLtd_MtrNm_f32(data) \
  ( \
    Rte_Task_2ms_9.Rte_RB.Rte_Ap_LmtCod_LmtCod_Per1.Rte_StallLimitLtd_MtrNm_f32.value = (data) \
  )

#  define Rte_IWriteRef_LmtCod_Per1_StallLimitLtd_MtrNm_f32() \
  (&Rte_Task_2ms_9.Rte_RB.Rte_Ap_LmtCod_LmtCod_Per1.Rte_StallLimitLtd_MtrNm_f32.value)

#  define Rte_IWrite_LmtCod_Per1_ThermalLimitLtd_MtrNm_f32(data) \
  ( \
    Rte_Task_2ms_9.Rte_RB.Rte_Ap_LmtCod_LmtCod_Per1.Rte_ThermalLimitLtd_MtrNm_f32.value = (data) \
  )

#  define Rte_IWriteRef_LmtCod_Per1_ThermalLimitLtd_MtrNm_f32() \
  (&Rte_Task_2ms_9.Rte_RB.Rte_Ap_LmtCod_LmtCod_Per1.Rte_ThermalLimitLtd_MtrNm_f32.value)

#  define Rte_IWrite_LmtCod_Per1_VehSpdLimitLtd_MtrNm_f32(data) \
  ( \
    Rte_Task_2ms_9.Rte_RB.Rte_Ap_LmtCod_LmtCod_Per1.Rte_VehSpdLimitLtd_MtrNm_f32.value = (data) \
  )

#  define Rte_IWriteRef_LmtCod_Per1_VehSpdLimitLtd_MtrNm_f32() \
  (&Rte_Task_2ms_9.Rte_RB.Rte_Ap_LmtCod_LmtCod_Per1.Rte_VehSpdLimitLtd_MtrNm_f32.value)


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (unmapped) for synchronous C/S communication
 *********************************************************************************************************************/
#  define RTE_START_SEC_AP_SRLCOMINPUT_APPL_CODE
#  include "MemMap.h"
FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) FaultInjection_FltInjection(P2VAR(Float, AUTOMATIC, RTE_AP_SRLCOMINPUT_APPL_VAR) SignalPath_Uls_f32, FltInjectionLocType LocationKey_Cnt_enum);
#  define RTE_STOP_SEC_AP_SRLCOMINPUT_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_FltInjection_SCom_FltInjection(arg1, arg2) (FaultInjection_FltInjection(arg1, arg2), ((Std_ReturnType)RTE_E_OK))


# endif /* !defined(RTE_CORE) */


# define RTE_START_SEC_AP_LMTCOD_APPL_CODE
# include "MemMap.h"

/**********************************************************************************************************************
 * Runnable entities
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
#   if RTE_MAGIC_NUMBER != 1468867288
#    error "The magic number of the generated file <C:/Sankar/Chrysler/Synergy/CL/Temp_work/Chrysler_LWR_EPS_TMS570/SwProject/Source/GenDataRte/Components/Rte_Ap_LmtCod.h> is different. Please check time and date of the generated RTE files!"
#   endif
#  else
#   define RTE_MAGIC_NUMBER 1468867288
#  endif  /* RTE_MAGIC_NUMBER */
# endif  /* SKIP_MAGIC_NUMBER */
/* end Fileversion check */

#endif /* _RTE_AP_LMTCOD_H */
