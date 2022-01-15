/* -----------------------------------------------------------------------------
  Filename:    ccl_cfg.h
  Description: Toolversion: 01.00.35.01.21.00.21.01.00.00
               
               Serial Number: CBD1210021
               Customer Info: Nexteer
                              Package: CBD_Chrysler_SLP1_UDS_Sgl
                              Micro: TexasInstruments TMS570 - TMX570LS0805APGEQQ1
                              Compiler: Texas Instruments 4.9.5
               
               
               Generator Fwk   : GENy 
               Generator Module: Ccl__core
               
               Configuration   : C:\ccm_wa\EPS\570\LWR\Chrysler_LWR_EPS_TMS570\Tools\AsrProject\GENy\Chrsyler_SLP1_EPS.gny
               
               ECU: 
                       TargetSystem: Hw_Tms470/570Cpu (Dcan)
                       Compiler:     TexasInstruments
                       Derivates:    TMS570PSFC66
               
               Channel "Channel0":
                       Databasefile: C:\cmsynergy\My_ePWM_LWR\Chrysler_LWR_EPS_TMS570\Tools\AsrProject\GENy\CAN C v1313 15LXMod.dbc
                       Bussystem:    CAN
                       Manufacturer: DaimlerChrysler
                       Node:         EPS

  Generated by , 2013-08-07  13:41:40
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

#if !defined(__CCL_CFG_H__)
#define __CCL_CFG_H__

#include "can_inc.h"
#include "dbk_def.h"
#include "n_onmdef.h"
#include "tpmc.h"
#include "Desc.h"
#include "AppDesc.h"
#include "dpm.h"
#include "xcpprof.h"
#include "frfm.h"
/***************************************************************************/ 
/* Version                  (abcd: Main version ab Sub Version cd )        */ 
/***************************************************************************/ 

#define CCL_DLL_VERSION  0x0201
#define CCL_DLL_BUGFIX_VERSION  0x00
#define CCL__COREDLL_VERSION                 0x0205
#define CCL__COREDLL_RELEASE_VERSION         0x43
/***************************************************************************/ 
/* Defines                                                                 */ 
/***************************************************************************/ 

#define C_ENABLE_CCL 

#define CCL_DISABLE_ERROR_HOOK  /* CclFatalError function is disabled */ 

#define CCL_DISABLE_DEBUG /* disables the debug mode and switches the assertions to on */ 

#define CCL_ENABLE_EMC_WAKEUP

#define CCL_DISABLE_WAKEUP_REG
#define CCL_ENABLE_INTERNAL_REQUEST
#define CCL_ENABLE_EXTERNAL_REQUEST
#define CCL_ENABLE_SLEEP_REPETITION

#define CCL_ENABLE_CANBEDDED_HANDLING
#define CCL_DISABLE_SCHEDULE_TASK
#define CCL_ENABLE_CONTAINER_TASK
#define CCL_ENABLE_STOP_MODE_ECU
#define CCL_DISABLE_POWER_DOWN_MODE_ECU
#define CCL_DISABLE_CUSTOMER_MODE_ECU
#define CCL_ENABLE_NET_STATE_RESTRICTION

#define CCL_DISABLE_TRCV_PORT_INT

#define CCL_ENABLE_SYSTEM_SHUTDOWN

#define CCL_ENABLE_ADV_SHUTDOWN

#define CCL_DISABLE_FIM

#define CCL_ENABLE_SW_COM_STATE

#define CCL_DISABLE_EXTENDED_INITIALIZATION

#define CCL_DISABLE_NM_CBD_IF

#define kCclNrOfChannels 1  /* number of used channels */

#define kCclNrOfNetworks 1  /* number of used networks */ 

#define CCL_DISABLE_MULTIPLE_NODES  /* no multiple nodes */ 

#define CCL_ENABLE_BUSOFF_START

#define CCL_ENABLE_BUSOFF_END

#define CCL_ENABLE_BUSSTART

#define kCclNetReqTableSize 1  /* size of network request tabless */
#define kCclEmcWakeUpTime 25   /* value depends on the CCL cycle time */
/***************************************************************************/ 
/* Macros                                                                  */ 
/***************************************************************************/ 


  /* *** Network Request access macros *** */
#define CclSet_Sys_User1_CH0()                              CclRequestNetwork(0, 0, 0x0, 0x1)


#define CclSet_DPM_EPS()                        CclRequestNetwork(0, 0, 0x0, 0x2)

  /* *** Release Network access macros *** */
#define CclRel_Sys_User1_CH0()                              CclReleaseNetwork(0, 0, 0x0, 0x1)


#define CclRel_DPM_EPS()                        CclReleaseNetwork(0, 0, 0x0, 0x2)

extern void CclComStart(void);
extern void CclComStop(void);
extern void CCL_API_CALLBACK_TYPE ApplCclComStop(void);
extern void CclBusOffStart(void);
extern void CclBusOffEnd(void);
extern void CCL_API_CALLBACK_TYPE ApplCclBusOffStart(void);
extern void CCL_API_CALLBACK_TYPE ApplCclBusOffEnd(void);
extern void CCL_API_CALLBACK_TYPE ApplCclInit(void);
extern void CCL_API_CALL_TYPE CclPollingTask(void); 
extern void CCL_API_CALLBACK_TYPE ApplCclInitTrcv(void);
extern void CCL_API_CALLBACK_TYPE ApplCclWakeUpTrcv(void);
extern void CCL_API_CALLBACK_TYPE ApplCclStandbyTrcv(void);
extern void CCL_API_CALL_TYPE  Ccl_2_0msTaskCont(void); 
extern void CCL_API_CALL_TYPE  Ccl_10_0msTaskCont(void); 
extern void CCL_API_CALL_TYPE  Ccl_20_0msTaskCont(void); 
extern void CCL_API_CALL_TYPE  Ccl_10_2msTaskCont(void);

/* begin Fileversion check */
#ifndef SKIP_MAGIC_NUMBER
#ifdef MAGIC_NUMBER
  #if MAGIC_NUMBER != 103168731
      #error "The magic number of the generated file <C:\Synergy\Chrysler_LWR_EPS_TMS570-zz4r1x\Chrysler_LWR_EPS_TMS570\SwProject\Source\_GenData\ccl_cfg.h> is different. Please check time and date of generated files!"
  #endif
#else
  #define MAGIC_NUMBER 103168731
#endif  /* MAGIC_NUMBER */
#endif  /* SKIP_MAGIC_NUMBER */

/* end Fileversion check */

#endif /* __CCL_CFG_H__ */
