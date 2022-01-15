/* -----------------------------------------------------------------------------
  Filename:    v_inc.h
  Description: Toolversion: 01.00.35.01.21.00.21.01.00.00
               
               Serial Number: CBD1210021
               Customer Info: Nexteer
                              Package: CBD_Chrysler_SLP1_UDS_Sgl
                              Micro: TexasInstruments TMS570 - TMX570LS0805APGEQQ1
                              Compiler: Texas Instruments 4.9.5
               
               
               Generator Fwk   : GENy 
               Generator Module: GenTool_GenyVcfgNameDecorator
               
               Configuration   : C:\Synergy\Chrysler_LWR_EPS_TMS570-zz4r1x\Chrysler_LWR_EPS_TMS570\Tools\AsrProject\GENy\Chrsyler_SLP1_EPS.gny
               
               ECU: 
                       TargetSystem: Hw_Tms470/570Cpu (Dcan)
                       Compiler:     TexasInstruments
                       Derivates:    TMS570PSFC66
               
               Channel "Channel0":
                       Databasefile: C:\Synergy\Chrysler_LWR_EPS_TMS570-zz4r1x\Chrysler_LWR_EPS_TMS570\Tools\AsrProject\GENy\CAN C v1232 EPS.dbc
                       Bussystem:    CAN
                       Manufacturer: DaimlerChrysler
                       Node:         EPS

  Generated by , 2012-12-11  16:14:27
 ----------------------------------------------------------------------------- */
/* -----------------------------------------------------------------------------
  C O P Y R I G H T
 -------------------------------------------------------------------------------
  Copyright (c) 2001-2011 by Vector Informatik GmbH. All rights reserved.
 
  This software is copyright protected and proprietary to Vector Informatik 
  GmbH.
  
  Vector Informatik GmbH grants to you only those rights as set out in the 
  license conditions.
  
  All other rights remain with Vector Informatik GmbH.
 -------------------------------------------------------------------------------
 ----------------------------------------------------------------------------- */

#if !defined(__V_INC_H__)
#define __V_INC_H__

#include "can_inc.h"

#include "v_cfg.h"
#include "drv_par.h"

#include "xcp_cfg.h"
#include "nm_cfg.h"
#include "nm_udcfg.h"
#include "tpmc.h"
#include "dbk_cfg.h"

#include "v_par.h"
#include "xcp_par.h"
#include "can_par.h"
#include "dbk_par.h"

/* begin Fileversion check */
#ifndef SKIP_MAGIC_NUMBER
#ifdef MAGIC_NUMBER
  #if MAGIC_NUMBER != 103168731
      #error "The magic number of the generated file <C:\Synergy_WorkArea\ESG_Dev_65\Chrysler_LWR_EPS_TMS570-tzj9qy\Chrysler_LWR_EPS_TMS570\SwProject\Source\_GenData\v_inc.h> is different. Please check time and date of generated files!"
  #endif
#else
  #define MAGIC_NUMBER 103168731
#endif  /* MAGIC_NUMBER */
#endif  /* SKIP_MAGIC_NUMBER */

/* end Fileversion check */

#endif /* __V_INC_H__ */
