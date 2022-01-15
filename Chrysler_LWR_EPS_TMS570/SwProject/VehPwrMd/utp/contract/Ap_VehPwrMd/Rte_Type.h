


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
 *          File:  Rte_Type.h
 *     Workspace:  C:/Synergy/Chrysler_LWR_EPS_TMS570-zz4r1x/Chrysler_LWR_EPS_TMS570/SwProject/VehPwrMd/autosar
 *     SW-C Type:  Ap_VehPwrMd
 *  Generated at:  Thu Jan  3 16:14:33 2013
 *
 *     Generator:  MICROSAR RTE Generator Version 2.19.1 (Beta)
 *       License:  License CBD1010124 valid for CBD1010124 Nexteer  Package: BMW MSR SIP BAC3.0     Micro: TI TMS570 TMS570LS30306  Compiler: Code Composer Studio 4.9.0
 *
 *   Description:  Header file containing user defined AUTOSAR types and RTE structures (Contract Phase)
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_TYPE_H
# define _RTE_TYPE_H

# include "Rte.h"


/**********************************************************************************************************************
 * Data type definitions
 *********************************************************************************************************************/

# define Rte_TypeDef_Boolean
typedef boolean Boolean;

# define Rte_TypeDef_Float
typedef float32 Float;
# define Float_LowerLimit (-FLT_MAX)
# define Float_UpperLimit (FLT_MAX)

# define Rte_TypeDef_IoHwAb_BoolType
typedef uint8 IoHwAb_BoolType;
# define IoHwAb_BoolType_LowerLimit (0U)
# define IoHwAb_BoolType_UpperLimit (1U)

# define Rte_TypeDef_UInt16
typedef uint16 UInt16;
# define UInt16_LowerLimit (0U)
# define UInt16_UpperLimit (65535U)

# define Rte_TypeDef_EcuM_StateType
typedef uint8 EcuM_StateType;
# define EcuM_StateType_LowerLimit (16U)
# define EcuM_StateType_UpperLimit (255U)
# if (defined RTE_CONST_ECUM_STATE_STARTUP) || (defined ECUM_STATE_STARTUP)
#  if (!defined RTE_CONST_ECUM_STATE_STARTUP) || (RTE_CONST_ECUM_STATE_STARTUP != 16U)
#   error "Enumeration constant <ECUM_STATE_STARTUP> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_ECUM_STATE_STARTUP (16U)
#  define ECUM_STATE_STARTUP (16U)
# endif
# if (defined RTE_CONST_ECUM_STATE_STARTUP_ONE) || (defined ECUM_STATE_STARTUP_ONE)
#  if (!defined RTE_CONST_ECUM_STATE_STARTUP_ONE) || (RTE_CONST_ECUM_STATE_STARTUP_ONE != 17U)
#   error "Enumeration constant <ECUM_STATE_STARTUP_ONE> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_ECUM_STATE_STARTUP_ONE (17U)
#  define ECUM_STATE_STARTUP_ONE (17U)
# endif
# if (defined RTE_CONST_ECUM_STATE_STARTUP_TWO) || (defined ECUM_STATE_STARTUP_TWO)
#  if (!defined RTE_CONST_ECUM_STATE_STARTUP_TWO) || (RTE_CONST_ECUM_STATE_STARTUP_TWO != 18U)
#   error "Enumeration constant <ECUM_STATE_STARTUP_TWO> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_ECUM_STATE_STARTUP_TWO (18U)
#  define ECUM_STATE_STARTUP_TWO (18U)
# endif
# if (defined RTE_CONST_ECUM_STATE_WAKEUP) || (defined ECUM_STATE_WAKEUP)
#  if (!defined RTE_CONST_ECUM_STATE_WAKEUP) || (RTE_CONST_ECUM_STATE_WAKEUP != 32U)
#   error "Enumeration constant <ECUM_STATE_WAKEUP> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_ECUM_STATE_WAKEUP (32U)
#  define ECUM_STATE_WAKEUP (32U)
# endif
# if (defined RTE_CONST_ECUM_STATE_WAKEUP_ONE) || (defined ECUM_STATE_WAKEUP_ONE)
#  if (!defined RTE_CONST_ECUM_STATE_WAKEUP_ONE) || (RTE_CONST_ECUM_STATE_WAKEUP_ONE != 33U)
#   error "Enumeration constant <ECUM_STATE_WAKEUP_ONE> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_ECUM_STATE_WAKEUP_ONE (33U)
#  define ECUM_STATE_WAKEUP_ONE (33U)
# endif
# if (defined RTE_CONST_ECUM_STATE_WAKEUP_VALIDATION) || (defined ECUM_STATE_WAKEUP_VALIDATION)
#  if (!defined RTE_CONST_ECUM_STATE_WAKEUP_VALIDATION) || (RTE_CONST_ECUM_STATE_WAKEUP_VALIDATION != 34U)
#   error "Enumeration constant <ECUM_STATE_WAKEUP_VALIDATION> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_ECUM_STATE_WAKEUP_VALIDATION (34U)
#  define ECUM_STATE_WAKEUP_VALIDATION (34U)
# endif
# if (defined RTE_CONST_ECUM_STATE_WAKEUP_REACTION) || (defined ECUM_STATE_WAKEUP_REACTION)
#  if (!defined RTE_CONST_ECUM_STATE_WAKEUP_REACTION) || (RTE_CONST_ECUM_STATE_WAKEUP_REACTION != 35U)
#   error "Enumeration constant <ECUM_STATE_WAKEUP_REACTION> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_ECUM_STATE_WAKEUP_REACTION (35U)
#  define ECUM_STATE_WAKEUP_REACTION (35U)
# endif
# if (defined RTE_CONST_ECUM_STATE_WAKEUP_TWO) || (defined ECUM_STATE_WAKEUP_TWO)
#  if (!defined RTE_CONST_ECUM_STATE_WAKEUP_TWO) || (RTE_CONST_ECUM_STATE_WAKEUP_TWO != 36U)
#   error "Enumeration constant <ECUM_STATE_WAKEUP_TWO> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_ECUM_STATE_WAKEUP_TWO (36U)
#  define ECUM_STATE_WAKEUP_TWO (36U)
# endif
# if (defined RTE_CONST_ECUM_STATE_WAKEUP_WAKESLEEP) || (defined ECUM_STATE_WAKEUP_WAKESLEEP)
#  if (!defined RTE_CONST_ECUM_STATE_WAKEUP_WAKESLEEP) || (RTE_CONST_ECUM_STATE_WAKEUP_WAKESLEEP != 37U)
#   error "Enumeration constant <ECUM_STATE_WAKEUP_WAKESLEEP> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_ECUM_STATE_WAKEUP_WAKESLEEP (37U)
#  define ECUM_STATE_WAKEUP_WAKESLEEP (37U)
# endif
# if (defined RTE_CONST_ECUM_STATE_WAKEUP_TTII) || (defined ECUM_STATE_WAKEUP_TTII)
#  if (!defined RTE_CONST_ECUM_STATE_WAKEUP_TTII) || (RTE_CONST_ECUM_STATE_WAKEUP_TTII != 38U)
#   error "Enumeration constant <ECUM_STATE_WAKEUP_TTII> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_ECUM_STATE_WAKEUP_TTII (38U)
#  define ECUM_STATE_WAKEUP_TTII (38U)
# endif
# if (defined RTE_CONST_ECUM_STATE_RUN) || (defined ECUM_STATE_RUN)
#  if (!defined RTE_CONST_ECUM_STATE_RUN) || (RTE_CONST_ECUM_STATE_RUN != 48U)
#   error "Enumeration constant <ECUM_STATE_RUN> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_ECUM_STATE_RUN (48U)
#  define ECUM_STATE_RUN (48U)
# endif
# if (defined RTE_CONST_ECUM_STATE_APP_RUN) || (defined ECUM_STATE_APP_RUN)
#  if (!defined RTE_CONST_ECUM_STATE_APP_RUN) || (RTE_CONST_ECUM_STATE_APP_RUN != 50U)
#   error "Enumeration constant <ECUM_STATE_APP_RUN> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_ECUM_STATE_APP_RUN (50U)
#  define ECUM_STATE_APP_RUN (50U)
# endif
# if (defined RTE_CONST_ECUM_STATE_APP_POST_RUN) || (defined ECUM_STATE_APP_POST_RUN)
#  if (!defined RTE_CONST_ECUM_STATE_APP_POST_RUN) || (RTE_CONST_ECUM_STATE_APP_POST_RUN != 51U)
#   error "Enumeration constant <ECUM_STATE_APP_POST_RUN> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_ECUM_STATE_APP_POST_RUN (51U)
#  define ECUM_STATE_APP_POST_RUN (51U)
# endif
# if (defined RTE_CONST_ECUM_STATE_SHUTDOWN) || (defined ECUM_STATE_SHUTDOWN)
#  if (!defined RTE_CONST_ECUM_STATE_SHUTDOWN) || (RTE_CONST_ECUM_STATE_SHUTDOWN != 64U)
#   error "Enumeration constant <ECUM_STATE_SHUTDOWN> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_ECUM_STATE_SHUTDOWN (64U)
#  define ECUM_STATE_SHUTDOWN (64U)
# endif
# if (defined RTE_CONST_ECUM_STATE_PREP_SHUTDOWN) || (defined ECUM_STATE_PREP_SHUTDOWN)
#  if (!defined RTE_CONST_ECUM_STATE_PREP_SHUTDOWN) || (RTE_CONST_ECUM_STATE_PREP_SHUTDOWN != 68U)
#   error "Enumeration constant <ECUM_STATE_PREP_SHUTDOWN> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_ECUM_STATE_PREP_SHUTDOWN (68U)
#  define ECUM_STATE_PREP_SHUTDOWN (68U)
# endif
# if (defined RTE_CONST_ECUM_STATE_GO_SLEEP) || (defined ECUM_STATE_GO_SLEEP)
#  if (!defined RTE_CONST_ECUM_STATE_GO_SLEEP) || (RTE_CONST_ECUM_STATE_GO_SLEEP != 73U)
#   error "Enumeration constant <ECUM_STATE_GO_SLEEP> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_ECUM_STATE_GO_SLEEP (73U)
#  define ECUM_STATE_GO_SLEEP (73U)
# endif
# if (defined RTE_CONST_ECUM_STATE_GO_OFF_ONE) || (defined ECUM_STATE_GO_OFF_ONE)
#  if (!defined RTE_CONST_ECUM_STATE_GO_OFF_ONE) || (RTE_CONST_ECUM_STATE_GO_OFF_ONE != 77U)
#   error "Enumeration constant <ECUM_STATE_GO_OFF_ONE> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_ECUM_STATE_GO_OFF_ONE (77U)
#  define ECUM_STATE_GO_OFF_ONE (77U)
# endif
# if (defined RTE_CONST_ECUM_STATE_GO_OFF_TWO) || (defined ECUM_STATE_GO_OFF_TWO)
#  if (!defined RTE_CONST_ECUM_STATE_GO_OFF_TWO) || (RTE_CONST_ECUM_STATE_GO_OFF_TWO != 78U)
#   error "Enumeration constant <ECUM_STATE_GO_OFF_TWO> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_ECUM_STATE_GO_OFF_TWO (78U)
#  define ECUM_STATE_GO_OFF_TWO (78U)
# endif
# if (defined RTE_CONST_ECUM_STATE_SLEEP) || (defined ECUM_STATE_SLEEP)
#  if (!defined RTE_CONST_ECUM_STATE_SLEEP) || (RTE_CONST_ECUM_STATE_SLEEP != 80U)
#   error "Enumeration constant <ECUM_STATE_SLEEP> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_ECUM_STATE_SLEEP (80U)
#  define ECUM_STATE_SLEEP (80U)
# endif
# if (defined RTE_CONST_ECUM_STATE_OFF) || (defined ECUM_STATE_OFF)
#  if (!defined RTE_CONST_ECUM_STATE_OFF) || (RTE_CONST_ECUM_STATE_OFF != 128U)
#   error "Enumeration constant <ECUM_STATE_OFF> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_ECUM_STATE_OFF (128U)
#  define ECUM_STATE_OFF (128U)
# endif
# if (defined RTE_CONST_ECUM_STATE_RESET) || (defined ECUM_STATE_RESET)
#  if (!defined RTE_CONST_ECUM_STATE_RESET) || (RTE_CONST_ECUM_STATE_RESET != 144U)
#   error "Enumeration constant <ECUM_STATE_RESET> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_ECUM_STATE_RESET (144U)
#  define ECUM_STATE_RESET (144U)
# endif
# if (defined RTE_CONST_ECUM_STATE_ERROR) || (defined ECUM_STATE_ERROR)
#  if (!defined RTE_CONST_ECUM_STATE_ERROR) || (RTE_CONST_ECUM_STATE_ERROR != 255U)
#   error "Enumeration constant <ECUM_STATE_ERROR> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_ECUM_STATE_ERROR (255U)
#  define ECUM_STATE_ERROR (255U)
# endif


/**********************************************************************************************************************
 * Constant value definitions
 *********************************************************************************************************************/

# if (defined RTE_CONST_D_FALSE_CNT_LGC) || (defined D_FALSE_CNT_LGC)
#  if (!defined RTE_CONST_D_FALSE_CNT_LGC) || (RTE_CONST_D_FALSE_CNT_LGC != FALSE)
#   error "Constant value <D_FALSE_CNT_LGC> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_FALSE_CNT_LGC (FALSE)
#  define D_FALSE_CNT_LGC (FALSE)
# endif

# if (defined RTE_CONST_D_TRUE_CNT_LGC) || (defined D_TRUE_CNT_LGC)
#  if (!defined RTE_CONST_D_TRUE_CNT_LGC) || (RTE_CONST_D_TRUE_CNT_LGC != TRUE)
#   error "Constant value <D_TRUE_CNT_LGC> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_TRUE_CNT_LGC (TRUE)
#  define D_TRUE_CNT_LGC (TRUE)
# endif

# if (defined RTE_CONST_D_ONE_ULS_F32) || (defined D_ONE_ULS_F32)
#  if (!defined RTE_CONST_D_ONE_ULS_F32) || (RTE_CONST_D_ONE_ULS_F32 != 1.0F)
#   error "Constant value <D_ONE_ULS_F32> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_ONE_ULS_F32 (1.0F)
#  define D_ONE_ULS_F32 (1.0F)
# endif

# if (defined RTE_CONST_D_ZERO_ULS_F32) || (defined D_ZERO_ULS_F32)
#  if (!defined RTE_CONST_D_ZERO_ULS_F32) || (RTE_CONST_D_ZERO_ULS_F32 != 0.0F)
#   error "Constant value <D_ZERO_ULS_F32> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_ZERO_ULS_F32 (0.0F)
#  define D_ZERO_ULS_F32 (0.0F)
# endif

# if (defined RTE_CONST_D_ONE_CNT_U16) || (defined D_ONE_CNT_U16)
#  if (!defined RTE_CONST_D_ONE_CNT_U16) || (RTE_CONST_D_ONE_CNT_U16 != 1U)
#   error "Constant value <D_ONE_CNT_U16> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_ONE_CNT_U16 (1U)
#  define D_ONE_CNT_U16 (1U)
# endif



/**********************************************************************************************************************
 * Type definitions for implicit access to S/R communication
 *********************************************************************************************************************/
/* Types for Data Handles section */

typedef struct
{
  Float value;
} Rte_DE_Float;

typedef struct
{
  Boolean value;
} Rte_DE_Boolean;

typedef struct
{
  UInt16 value;
} Rte_DE_UInt16;


/**********************************************************************************************************************
 * Component Data Structures and Port Data Structures
 *********************************************************************************************************************/

struct Rte_CDS_Ap_VehPwrMd
{
  /* Data Handles section */
  P2VAR(Rte_DE_Float, TYPEDEF, RTE_AP_VEHPWRMD_APPL_VAR) VehPwrMd_Init1_OperRampRate_XpmS_f32;
  P2VAR(Rte_DE_Float, TYPEDEF, RTE_AP_VEHPWRMD_APPL_VAR) VehPwrMd_Init1_OperRampValue_Uls_f32;
  P2VAR(Rte_DE_Boolean, TYPEDEF, RTE_AP_VEHPWRMD_APPL_VAR) VehPwrMd_Per1_ATermActive_Cnt_lgc;
  P2VAR(Rte_DE_Boolean, TYPEDEF, RTE_AP_VEHPWRMD_APPL_VAR) VehPwrMd_Per1_CTermActive_Cnt_lgc;
  P2VAR(Rte_DE_Boolean, TYPEDEF, RTE_AP_VEHPWRMD_APPL_VAR) VehPwrMd_Per1_DefaultVehSpd_Cnt_lgc;
  P2VAR(Rte_DE_Boolean, TYPEDEF, RTE_AP_VEHPWRMD_APPL_VAR) VehPwrMd_Per1_EngONSrlComSvcDft_Cnt_lgc;
  P2VAR(Rte_DE_UInt16, TYPEDEF, RTE_AP_VEHPWRMD_APPL_VAR) VehPwrMd_Per1_EngRPM_Cnt_u16;
  P2VAR(Rte_DE_Boolean, TYPEDEF, RTE_AP_VEHPWRMD_APPL_VAR) VehPwrMd_Per1_EssEngStop_Cnt_lgc;
  P2VAR(Rte_DE_Float, TYPEDEF, RTE_AP_VEHPWRMD_APPL_VAR) VehPwrMd_Per1_OperRampRate_XpmS_f32;
  P2VAR(Rte_DE_Float, TYPEDEF, RTE_AP_VEHPWRMD_APPL_VAR) VehPwrMd_Per1_OperRampValue_Uls_f32;
  P2VAR(Rte_DE_Boolean, TYPEDEF, RTE_AP_VEHPWRMD_APPL_VAR) VehPwrMd_Per1_SpStPrsnt_Cnt_lgc;
  P2VAR(Rte_DE_Boolean, TYPEDEF, RTE_AP_VEHPWRMD_APPL_VAR) VehPwrMd_Per1_VehSpdValid_Cnt_lgc;
  P2VAR(Rte_DE_Float, TYPEDEF, RTE_AP_VEHPWRMD_APPL_VAR) VehPwrMd_Per1_VehSpd_Kph_f32;
  /* Vendor specific section */
};

# define RTE_START_SEC_CONST_UNSPECIFIED
# include "MemMap.h"

extern CONSTP2CONST(struct Rte_CDS_Ap_VehPwrMd, RTE_CONST, RTE_CONST) Rte_Inst_Ap_VehPwrMd;

# define RTE_STOP_SEC_CONST_UNSPECIFIED
# include "MemMap.h"

/* begin Fileversion check */
# ifndef SKIP_MAGIC_NUMBER
#  ifdef RTE_MAGIC_NUMBER
#   if RTE_MAGIC_NUMBER != 1357242696
#    error "The magic number of the generated file <C:/Synergy/Chrysler_LWR_EPS_TMS570-zz4r1x/Chrysler_LWR_EPS_TMS570/SwProject/VehPwrMd/utp/contract/Ap_VehPwrMd/Rte_Type.h> is different. Please check time and date of the generated RTE files!"
#   endif
#  else
#   define RTE_MAGIC_NUMBER 1357242696
#  endif  /* RTE_MAGIC_NUMBER */
# endif  /* SKIP_MAGIC_NUMBER */
/* end Fileversion check */

#endif /* _RTE_TYPE_H */
