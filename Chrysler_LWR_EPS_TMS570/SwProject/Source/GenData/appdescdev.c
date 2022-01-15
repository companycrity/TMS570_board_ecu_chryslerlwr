/* -----------------------------------------------------------------------------
  Filename:    appdescdev.c
  Description: Implementation for development tests with CANdesc.
                
                Manufacturer: chrysler
                EcuDocFile:   E:\__SandBox__\MyCustomerProjects\Nexteer\Chrysler_LWR_EPS_TMS570-tzj9qy_synergy\Chrysler_LWR_EPS_TMS570\Tools\AsrProject\GENy\EPS_PN_41_02_002_E_VV5887.cdd
                Variant:      Common_Diagnostics

  Generated by CANdelaGen, Sun Jul 29 17:23:38 2012
 
 ----------------------------------------------------------------------------- */
/* -----------------------------------------------------------------------------
  C O P Y R I G H T
 -------------------------------------------------------------------------------
  Copyright (c) 2001-2012 by Vector Informatik GmbH. All rights reserved.
 
  This software is copyright protected and proprietary to Vector Informatik 
  GmbH.
  
  Vector Informatik GmbH grants to you only those rights as set out in the 
  license conditions.
  
  All other rights remain with Vector Informatik GmbH.
 -------------------------------------------------------------------------------
 ----------------------------------------------------------------------------- */

/* -----------------------------------------------------------------------------
    &&&~ Includes
 ----------------------------------------------------------------------------- */

/* Physical layer specific API */
#include "v_inc.h"
/* Check if CCL is available and take into account its configuration */
#if defined (VGEN_ENABLE_CCL)
# include "ccl_cfg.h"
#endif

/* Check if CCLcom is available and take into account its configuration */
#if defined (VGEN_ENABLE_CCLCOM)
# include "cclcom_cfg.h"
#endif

/* Make all CANdesc specific typedefs available */
#include "desc.h"
/* Include the implementation prototypes for prototype checks */
#include "appdesc.h"


