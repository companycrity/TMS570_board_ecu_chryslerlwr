


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
 *          File:  Rte_Ap_VehPwrMd.h
 *     Workspace:  C:/Synergy/Chrysler_LWR_EPS_TMS570-zz4r1x/Chrysler_LWR_EPS_TMS570/SwProject/VehPwrMd/autosar
 *     SW-C Type:  Ap_VehPwrMd
 *  Generated at:  Thu Jan  3 16:14:33 2013
 *
 *     Generator:  MICROSAR RTE Generator Version 2.19.1 (Beta)
 *       License:  License CBD1010124 valid for CBD1010124 Nexteer  Package: BMW MSR SIP BAC3.0     Micro: TI TMS570 TMS570LS30306  Compiler: Code Composer Studio 4.9.0
 *
 *   Description:  Application header file for SW-C <Ap_VehPwrMd> (Contract Phase)
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_AP_VEHPWRMD_H
# define _RTE_AP_VEHPWRMD_H

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

typedef P2CONST(struct Rte_CDS_Ap_VehPwrMd, TYPEDEF, RTE_CONST) Rte_Instance;


/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

# define Rte_InitValue_ATermActive_Cnt_lgc (TRUE)
# define Rte_InitValue_CTermActive_Cnt_lgc (FALSE)
# define Rte_InitValue_DefaultVehSpd_Cnt_lgc (FALSE)
# define Rte_InitValue_EngONSrlComSvcDft_Cnt_lgc (FALSE)
# define Rte_InitValue_EngRPM_Cnt_u16 (1U)
# define Rte_InitValue_EssEngStop_Cnt_lgc (TRUE)
# define Rte_InitValue_OperRampRate_XpmS_f32 (0.0F)
# define Rte_InitValue_OperRampValue_Uls_f32 (0.0F)
# define Rte_InitValue_SpStPrsnt_Cnt_lgc (FALSE)
# define Rte_InitValue_VehSpd_Kph_f32 (0.0F)
# define Rte_InitValue_VehSpdValid_Cnt_lgc (FALSE)


# define RTE_START_SEC_CODE
# include "MemMap.h"

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ap_VehPwrMd_EpsEn_OP_GET(P2VAR(IoHwAb_BoolType, AUTOMATIC, RTE_AP_VEHPWRMD_APPL_VAR) signal);

# define RTE_STOP_SEC_CODE
# include "MemMap.h"



/**********************************************************************************************************************
 * Rte_IRead_<r>_<p>_<d>
 * Rte_IStatus_<r>_<p>_<d>
 * Rte_IWrite_<r>_<p>_<d>
 * Rte_IWriteRef_<r>_<p>_<d>
 * Rte_IInvalidate_<r>_<p>_<d>
 *********************************************************************************************************************/

# define Rte_IWrite_VehPwrMd_Init1_OperRampRate_XpmS_f32(data) \
  ( \
  Rte_Inst_Ap_VehPwrMd->VehPwrMd_Init1_OperRampRate_XpmS_f32->value = (data) \
  )

# define Rte_IWriteRef_VehPwrMd_Init1_OperRampRate_XpmS_f32() \
  (&Rte_Inst_Ap_VehPwrMd->VehPwrMd_Init1_OperRampRate_XpmS_f32->value)

# define Rte_IWrite_VehPwrMd_Init1_OperRampValue_Uls_f32(data) \
  ( \
  Rte_Inst_Ap_VehPwrMd->VehPwrMd_Init1_OperRampValue_Uls_f32->value = (data) \
  )

# define Rte_IWriteRef_VehPwrMd_Init1_OperRampValue_Uls_f32() \
  (&Rte_Inst_Ap_VehPwrMd->VehPwrMd_Init1_OperRampValue_Uls_f32->value)

# define Rte_IRead_VehPwrMd_Per1_DefaultVehSpd_Cnt_lgc() \
  (Rte_Inst_Ap_VehPwrMd->VehPwrMd_Per1_DefaultVehSpd_Cnt_lgc->value)

# define Rte_IRead_VehPwrMd_Per1_EngONSrlComSvcDft_Cnt_lgc() \
  (Rte_Inst_Ap_VehPwrMd->VehPwrMd_Per1_EngONSrlComSvcDft_Cnt_lgc->value)

# define Rte_IRead_VehPwrMd_Per1_EngRPM_Cnt_u16() \
  (Rte_Inst_Ap_VehPwrMd->VehPwrMd_Per1_EngRPM_Cnt_u16->value)

# define Rte_IRead_VehPwrMd_Per1_EssEngStop_Cnt_lgc() \
  (Rte_Inst_Ap_VehPwrMd->VehPwrMd_Per1_EssEngStop_Cnt_lgc->value)

# define Rte_IRead_VehPwrMd_Per1_SpStPrsnt_Cnt_lgc() \
  (Rte_Inst_Ap_VehPwrMd->VehPwrMd_Per1_SpStPrsnt_Cnt_lgc->value)

# define Rte_IRead_VehPwrMd_Per1_VehSpdValid_Cnt_lgc() \
  (Rte_Inst_Ap_VehPwrMd->VehPwrMd_Per1_VehSpdValid_Cnt_lgc->value)

# define Rte_IRead_VehPwrMd_Per1_VehSpd_Kph_f32() \
  (Rte_Inst_Ap_VehPwrMd->VehPwrMd_Per1_VehSpd_Kph_f32->value)

# define Rte_IWrite_VehPwrMd_Per1_ATermActive_Cnt_lgc(data) \
  ( \
  Rte_Inst_Ap_VehPwrMd->VehPwrMd_Per1_ATermActive_Cnt_lgc->value = (data) \
  )

# define Rte_IWriteRef_VehPwrMd_Per1_ATermActive_Cnt_lgc() \
  (&Rte_Inst_Ap_VehPwrMd->VehPwrMd_Per1_ATermActive_Cnt_lgc->value)

# define Rte_IWrite_VehPwrMd_Per1_CTermActive_Cnt_lgc(data) \
  ( \
  Rte_Inst_Ap_VehPwrMd->VehPwrMd_Per1_CTermActive_Cnt_lgc->value = (data) \
  )

# define Rte_IWriteRef_VehPwrMd_Per1_CTermActive_Cnt_lgc() \
  (&Rte_Inst_Ap_VehPwrMd->VehPwrMd_Per1_CTermActive_Cnt_lgc->value)

# define Rte_IWrite_VehPwrMd_Per1_OperRampRate_XpmS_f32(data) \
  ( \
  Rte_Inst_Ap_VehPwrMd->VehPwrMd_Per1_OperRampRate_XpmS_f32->value = (data) \
  )

# define Rte_IWriteRef_VehPwrMd_Per1_OperRampRate_XpmS_f32() \
  (&Rte_Inst_Ap_VehPwrMd->VehPwrMd_Per1_OperRampRate_XpmS_f32->value)

# define Rte_IWrite_VehPwrMd_Per1_OperRampValue_Uls_f32(data) \
  ( \
  Rte_Inst_Ap_VehPwrMd->VehPwrMd_Per1_OperRampValue_Uls_f32->value = (data) \
  )

# define Rte_IWriteRef_VehPwrMd_Per1_OperRampValue_Uls_f32() \
  (&Rte_Inst_Ap_VehPwrMd->VehPwrMd_Per1_OperRampValue_Uls_f32->value)


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (C/S invocation)
 *********************************************************************************************************************/
# define Rte_Call_EpsEn_OP_GET Rte_Call_Ap_VehPwrMd_EpsEn_OP_GET




# define RTE_START_SEC_AP_VEHPWRMD_APPL_CODE
# include "MemMap.h"


/**********************************************************************************************************************
 *
 * Runnable Entity Name: VehPwrMd_Init1
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
 *   void Rte_IWrite_VehPwrMd_Init1_OperRampRate_XpmS_f32(Float data)
 *   Float *Rte_IWriteRef_VehPwrMd_Init1_OperRampRate_XpmS_f32(void)
 *   void Rte_IWrite_VehPwrMd_Init1_OperRampValue_Uls_f32(Float data)
 *   Float *Rte_IWriteRef_VehPwrMd_Init1_OperRampValue_Uls_f32(void)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_VEHPWRMD_APPL_CODE) VehPwrMd_Init1(void);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: VehPwrMd_Per1
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
 *   Boolean Rte_IRead_VehPwrMd_Per1_DefaultVehSpd_Cnt_lgc(void)
 *   Boolean Rte_IRead_VehPwrMd_Per1_EngONSrlComSvcDft_Cnt_lgc(void)
 *   UInt16 Rte_IRead_VehPwrMd_Per1_EngRPM_Cnt_u16(void)
 *   Boolean Rte_IRead_VehPwrMd_Per1_EssEngStop_Cnt_lgc(void)
 *   Boolean Rte_IRead_VehPwrMd_Per1_SpStPrsnt_Cnt_lgc(void)
 *   Boolean Rte_IRead_VehPwrMd_Per1_VehSpdValid_Cnt_lgc(void)
 *   Float Rte_IRead_VehPwrMd_Per1_VehSpd_Kph_f32(void)
 *
 * Output Interfaces:
 * ==================
 *   Implicit S/R API:
 *   -----------------
 *   void Rte_IWrite_VehPwrMd_Per1_ATermActive_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_VehPwrMd_Per1_ATermActive_Cnt_lgc(void)
 *   void Rte_IWrite_VehPwrMd_Per1_CTermActive_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_VehPwrMd_Per1_CTermActive_Cnt_lgc(void)
 *   void Rte_IWrite_VehPwrMd_Per1_OperRampRate_XpmS_f32(Float data)
 *   Float *Rte_IWriteRef_VehPwrMd_Per1_OperRampRate_XpmS_f32(void)
 *   void Rte_IWrite_VehPwrMd_Per1_OperRampValue_Uls_f32(Float data)
 *   Float *Rte_IWriteRef_VehPwrMd_Per1_OperRampValue_Uls_f32(void)
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_EpsEn_OP_GET(IoHwAb_BoolType *signal)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_EpsEn_E_NOT_OK
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_VEHPWRMD_APPL_CODE) VehPwrMd_Per1(void);

# define RTE_STOP_SEC_AP_VEHPWRMD_APPL_CODE
# include "MemMap.h"


/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

# define RTE_E_EpsEn_E_NOT_OK (1U)

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

/* begin Fileversion check */
# ifndef SKIP_MAGIC_NUMBER
#  ifdef RTE_MAGIC_NUMBER
#   if RTE_MAGIC_NUMBER != 1357242696
#    error "The magic number of the generated file <C:/Synergy/Chrysler_LWR_EPS_TMS570-zz4r1x/Chrysler_LWR_EPS_TMS570/SwProject/VehPwrMd/utp/contract/Ap_VehPwrMd/Rte_Ap_VehPwrMd.h> is different. Please check time and date of the generated RTE files!"
#   endif
#  else
#   define RTE_MAGIC_NUMBER 1357242696
#  endif  /* RTE_MAGIC_NUMBER */
# endif  /* SKIP_MAGIC_NUMBER */
/* end Fileversion check */

#endif /* _RTE_AP_VEHPWRMD_H */
