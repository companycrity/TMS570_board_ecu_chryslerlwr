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
 *          File:  Rte_Ap_ArbLmt.h
 *     Workspace:  C:/Synergy_projects/ArbLmt-lz4p8n1/ArbLmt/autosar
 *     SW-C Type:  Ap_ArbLmt
 *  Generated at:  Wed Jul 10 16:37:52 2013
 *
 *     Generator:  MICROSAR RTE Generator Version 2.17.2
 *       License:  License CBD1010122 valid for CBD1010122 Nexteer  GM MSR_SLP3_BSW_RTE_wGMLAN TexasInstruments TMS570 Texas Instruments
 *
 *   Description:  Application header file for SW-C <Ap_ArbLmt> (Contract Phase)
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_AP_ARBLMT_H
# define _RTE_AP_ARBLMT_H

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

typedef P2CONST(struct Rte_CDS_Ap_ArbLmt, TYPEDEF, RTE_CONST) Rte_Instance;


/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

# define Rte_InitValue_ActiveFunctionBits_Cnt_u08 ((UInt8)0u)
# define Rte_InitValue_DSTActive_Cnt_lgc ((Boolean)FALSE)
# define Rte_InitValue_DSTSlewComplete_Cnt_lgc ((Boolean)FALSE)
# define Rte_InitValue_DSTState_Cnt_u08 ((UInt8)0u)
# define Rte_InitValue_DSTTrqOvCmdRqst_HwNm_f32 ((Float)0)
# define Rte_InitValue_HaLFActive_Cnt_lgc ((Boolean)FALSE)
# define Rte_InitValue_HaLFSlewComplete_Cnt_lgc ((Boolean)FALSE)
# define Rte_InitValue_HaLFTOState_Cnt_u08 ((UInt8)0u)
# define Rte_InitValue_HaLFTrqOvCmdRqst_MtrNm_f32 ((Float)0)
# define Rte_InitValue_IpTrqOvr_HwNm_f32 ((Float)0)
# define Rte_InitValue_OpTrqOvr_MtrNm_f32 ((Float)0)
# define Rte_InitValue_PAReturnSclFct_Uls_f32 ((Float)1)
# define Rte_InitValue_PATrqOvCmdRqst_HwNm_f32 ((Float)0)
# define Rte_InitValue_PICmpDisableLearning_Cnt_lgc ((Boolean)FALSE)
# define Rte_InitValue_PrkAssistState_Cnt_u08 ((UInt8)0u)
# define Rte_InitValue_PrkAsstSlewComplete_Cnt_lgc ((Boolean)FALSE)
# define Rte_InitValue_VehicleSpeed_Kph_f32 ((Float)0)



/**********************************************************************************************************************
 * Rte_IRead_<r>_<p>_<d>
 * Rte_IStatus_<r>_<p>_<d>
 * Rte_IWrite_<r>_<p>_<d>
 * Rte_IWriteRef_<r>_<p>_<d>
 * Rte_IInvalidate_<r>_<p>_<d>
 *********************************************************************************************************************/

# define Rte_IRead_ArbLmt_Per1_DSTActive_Cnt_lgc() \
  (Rte_Inst_Ap_ArbLmt->ArbLmt_Per1_DSTActive_Cnt_lgc->value)

# define Rte_IRead_ArbLmt_Per1_DSTState_Cnt_u08() \
  (Rte_Inst_Ap_ArbLmt->ArbLmt_Per1_DSTState_Cnt_u08->value)

# define Rte_IRead_ArbLmt_Per1_DSTTrqOvCmdRqst_HwNm_f32() \
  (Rte_Inst_Ap_ArbLmt->ArbLmt_Per1_DSTTrqOvCmdRqst_HwNm_f32->value)

# define Rte_IRead_ArbLmt_Per1_HaLFActive_Cnt_lgc() \
  (Rte_Inst_Ap_ArbLmt->ArbLmt_Per1_HaLFActive_Cnt_lgc->value)

# define Rte_IRead_ArbLmt_Per1_HaLFTOState_Cnt_u08() \
  (Rte_Inst_Ap_ArbLmt->ArbLmt_Per1_HaLFTOState_Cnt_u08->value)

# define Rte_IRead_ArbLmt_Per1_HaLFTrqOvCmdRqst_MtrNm_f32() \
  (Rte_Inst_Ap_ArbLmt->ArbLmt_Per1_HaLFTrqOvCmdRqst_MtrNm_f32->value)

# define Rte_IRead_ArbLmt_Per1_PATrqOvCmdRqst_HwNm_f32() \
  (Rte_Inst_Ap_ArbLmt->ArbLmt_Per1_PATrqOvCmdRqst_HwNm_f32->value)

# define Rte_IRead_ArbLmt_Per1_PrkAssistState_Cnt_u08() \
  (Rte_Inst_Ap_ArbLmt->ArbLmt_Per1_PrkAssistState_Cnt_u08->value)

# define Rte_IRead_ArbLmt_Per1_VehicleSpeed_Kph_f32() \
  (Rte_Inst_Ap_ArbLmt->ArbLmt_Per1_VehicleSpeed_Kph_f32->value)

# define Rte_IWrite_ArbLmt_Per1_ActiveFunctionBits_Cnt_u08(data) \
  ( \
  Rte_Inst_Ap_ArbLmt->ArbLmt_Per1_ActiveFunctionBits_Cnt_u08->value = (data) \
  )

# define Rte_IWriteRef_ArbLmt_Per1_ActiveFunctionBits_Cnt_u08() \
  (&Rte_Inst_Ap_ArbLmt->ArbLmt_Per1_ActiveFunctionBits_Cnt_u08->value)

# define Rte_IWrite_ArbLmt_Per1_DSTSlewComplete_Cnt_lgc(data) \
  ( \
  Rte_Inst_Ap_ArbLmt->ArbLmt_Per1_DSTSlewComplete_Cnt_lgc->value = (data) \
  )

# define Rte_IWriteRef_ArbLmt_Per1_DSTSlewComplete_Cnt_lgc() \
  (&Rte_Inst_Ap_ArbLmt->ArbLmt_Per1_DSTSlewComplete_Cnt_lgc->value)

# define Rte_IWrite_ArbLmt_Per1_HaLFSlewComplete_Cnt_lgc(data) \
  ( \
  Rte_Inst_Ap_ArbLmt->ArbLmt_Per1_HaLFSlewComplete_Cnt_lgc->value = (data) \
  )

# define Rte_IWriteRef_ArbLmt_Per1_HaLFSlewComplete_Cnt_lgc() \
  (&Rte_Inst_Ap_ArbLmt->ArbLmt_Per1_HaLFSlewComplete_Cnt_lgc->value)

# define Rte_IWrite_ArbLmt_Per1_IpTrqOvr_HwNm_f32(data) \
  ( \
  Rte_Inst_Ap_ArbLmt->ArbLmt_Per1_IpTrqOvr_HwNm_f32->value = (data) \
  )

# define Rte_IWriteRef_ArbLmt_Per1_IpTrqOvr_HwNm_f32() \
  (&Rte_Inst_Ap_ArbLmt->ArbLmt_Per1_IpTrqOvr_HwNm_f32->value)

# define Rte_IWrite_ArbLmt_Per1_OpTrqOvr_MtrNm_f32(data) \
  ( \
  Rte_Inst_Ap_ArbLmt->ArbLmt_Per1_OpTrqOvr_MtrNm_f32->value = (data) \
  )

# define Rte_IWriteRef_ArbLmt_Per1_OpTrqOvr_MtrNm_f32() \
  (&Rte_Inst_Ap_ArbLmt->ArbLmt_Per1_OpTrqOvr_MtrNm_f32->value)

# define Rte_IWrite_ArbLmt_Per1_PAReturnSclFct_Uls_f32(data) \
  ( \
  Rte_Inst_Ap_ArbLmt->ArbLmt_Per1_PAReturnSclFct_Uls_f32->value = (data) \
  )

# define Rte_IWriteRef_ArbLmt_Per1_PAReturnSclFct_Uls_f32() \
  (&Rte_Inst_Ap_ArbLmt->ArbLmt_Per1_PAReturnSclFct_Uls_f32->value)

# define Rte_IWrite_ArbLmt_Per1_PICmpDisableLearning_Cnt_lgc(data) \
  ( \
  Rte_Inst_Ap_ArbLmt->ArbLmt_Per1_PICmpDisableLearning_Cnt_lgc->value = (data) \
  )

# define Rte_IWriteRef_ArbLmt_Per1_PICmpDisableLearning_Cnt_lgc() \
  (&Rte_Inst_Ap_ArbLmt->ArbLmt_Per1_PICmpDisableLearning_Cnt_lgc->value)

# define Rte_IWrite_ArbLmt_Per1_PrkAsstSlewComplete_Cnt_lgc(data) \
  ( \
  Rte_Inst_Ap_ArbLmt->ArbLmt_Per1_PrkAsstSlewComplete_Cnt_lgc->value = (data) \
  )

# define Rte_IWriteRef_ArbLmt_Per1_PrkAsstSlewComplete_Cnt_lgc() \
  (&Rte_Inst_Ap_ArbLmt->ArbLmt_Per1_PrkAsstSlewComplete_Cnt_lgc->value)




# define RTE_START_SEC_AP_ARBLMT_APPL_CODE
# include "MemMap.h"


/**********************************************************************************************************************
 *
 * Runnable Entity Name: ArbLmt_Per1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 4ms
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Implicit S/R API:
 *   -----------------
 *   Boolean Rte_IRead_ArbLmt_Per1_DSTActive_Cnt_lgc(void)
 *   UInt8 Rte_IRead_ArbLmt_Per1_DSTState_Cnt_u08(void)
 *   Float Rte_IRead_ArbLmt_Per1_DSTTrqOvCmdRqst_HwNm_f32(void)
 *   Boolean Rte_IRead_ArbLmt_Per1_HaLFActive_Cnt_lgc(void)
 *   UInt8 Rte_IRead_ArbLmt_Per1_HaLFTOState_Cnt_u08(void)
 *   Float Rte_IRead_ArbLmt_Per1_HaLFTrqOvCmdRqst_MtrNm_f32(void)
 *   Float Rte_IRead_ArbLmt_Per1_PATrqOvCmdRqst_HwNm_f32(void)
 *   UInt8 Rte_IRead_ArbLmt_Per1_PrkAssistState_Cnt_u08(void)
 *   Float Rte_IRead_ArbLmt_Per1_VehicleSpeed_Kph_f32(void)
 *
 * Output Interfaces:
 * ==================
 *   Implicit S/R API:
 *   -----------------
 *   void Rte_IWrite_ArbLmt_Per1_ActiveFunctionBits_Cnt_u08(UInt8 data)
 *   UInt8 *Rte_IWriteRef_ArbLmt_Per1_ActiveFunctionBits_Cnt_u08(void)
 *   void Rte_IWrite_ArbLmt_Per1_DSTSlewComplete_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_ArbLmt_Per1_DSTSlewComplete_Cnt_lgc(void)
 *   void Rte_IWrite_ArbLmt_Per1_HaLFSlewComplete_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_ArbLmt_Per1_HaLFSlewComplete_Cnt_lgc(void)
 *   void Rte_IWrite_ArbLmt_Per1_IpTrqOvr_HwNm_f32(Float data)
 *   Float *Rte_IWriteRef_ArbLmt_Per1_IpTrqOvr_HwNm_f32(void)
 *   void Rte_IWrite_ArbLmt_Per1_OpTrqOvr_MtrNm_f32(Float data)
 *   Float *Rte_IWriteRef_ArbLmt_Per1_OpTrqOvr_MtrNm_f32(void)
 *   void Rte_IWrite_ArbLmt_Per1_PAReturnSclFct_Uls_f32(Float data)
 *   Float *Rte_IWriteRef_ArbLmt_Per1_PAReturnSclFct_Uls_f32(void)
 *   void Rte_IWrite_ArbLmt_Per1_PICmpDisableLearning_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_ArbLmt_Per1_PICmpDisableLearning_Cnt_lgc(void)
 *   void Rte_IWrite_ArbLmt_Per1_PrkAsstSlewComplete_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_ArbLmt_Per1_PrkAsstSlewComplete_Cnt_lgc(void)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_ARBLMT_APPL_CODE) ArbLmt_Per1(void);

# define RTE_STOP_SEC_AP_ARBLMT_APPL_CODE
# include "MemMap.h"

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

/* begin Fileversion check */
# ifndef SKIP_MAGIC_NUMBER
#  ifdef RTE_MAGIC_NUMBER
#   if RTE_MAGIC_NUMBER != 1373494855
#    error "The magic number of the generated file <C:/Synergy_projects/ArbLmt-lz4p8n1/ArbLmt/utp/contract/Ap_ArbLmt/Rte_Ap_ArbLmt.h> is different. Please check time and date of the generated RTE files!"
#   endif
#  else
#   define RTE_MAGIC_NUMBER 1373494855
#  endif  /* RTE_MAGIC_NUMBER */
# endif  /* SKIP_MAGIC_NUMBER */
/* end Fileversion check */

#endif /* _RTE_AP_ARBLMT_H */
