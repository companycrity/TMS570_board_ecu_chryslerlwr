/*****************************************************************************
| Project Name: CCL Communication Control Layer
| File Name: 
|
|  Description: CCL OEM for DC
|-----------------------------------------------------------------------------
|               C O P Y R I G H T
|-----------------------------------------------------------------------------
| Copyright (c) 2000-2012 by Vector Informatik GmbH.      All rights reserved.
|
|               This software is copyright protected and proprietary 
|               to Vector Informatik GmbH. Vector Informatik GmbH 
|               grants to you only those rights as set out in the 
|               license conditions. All other rights remain with 
|               Vector Informatik GmbH.
|-----------------------------------------------------------------------------
|               A U T H O R   I D E N T I T Y
|-----------------------------------------------------------------------------
| Initials     Name                      Company
| --------     ---------------------     ------------------------------------
| Bs           Thomas Balster            Vector Informatik GmbH
| Et           Thomas Ebert              Vector Informatik GmbH
| Pet          Thomas Petrus             Vector Informatik GmbH
| Dhf          Daniel Hof                Vector Informatik GmbH
|-----------------------------------------------------------------------------
|               R E V I S I O N   H I S T O R Y
|-----------------------------------------------------------------------------
| Date        Ver      Author  Description
| ---------   ----     ------  --------------------------------------------------
| 2003-03-17  1.00.00  Pet     intitial version
| 2003-06-04  1.00.01  Pet     
| 2003-07-18  1.05     Pet     review changes
| 2003-08-11  1.05.01  Pet     ESCAN00006332: support of single channel OSEK NM 
| 2003-11-03  1.05.02  Pet     ESCAN00006932: add support for NM Basic
| 2003-09-24  1.06     Et      ESCAN00007184: EMC wake up
| 2003-12-28  1.07     Et      ESCAN00007279: rename "ApplNmBusSleep" to "ApplNmCanBusSleep"
| 2004-01-16  1.08     Et      change core version to V1.07.01
| 2004-01-23  1.09     Pet     ESCAN00007402: correct NM parameter defines
|                      Pet     change core version to V1.08.00
| 2004-02-02  1.10     Et      change core version to V1.09.00
| 2004-02-20  1.11     Pet     ESCAN00007659: change kCclBugfixVersion to kCclBugFixVersion
| 2004-03-01  1.12     Pet     change core version to V1.10.00
| 2004-06-17  1.13.00  Pet     change core version to V1.12.00
| 2004-07-30  1.14.00  Pet     change core version to V1.14.00
| 2004-09-22  1.15.00  Pet     change core version to V1.16.00
|                              ESCAN00009206: missing wake up notification for synchron NM channel
| 2004-10-04  1.16     Pet     change core version to V1.17.00
|                              ESCAN00009687: new DC OEM version bugfix define
| 2004-10-12  1.17     Pet     change core version to V1.18.00
| 2004-10-13  1.18     Pet     ESCAN00009863: DPM network restriction failed 
| 2004-12-13  1.19     Pet     change core version to V1.21.00
| 2005-02-17  1.20     Pet     change core version to V1.22.00
| 2005-02-18  1.21     Bs      change core version to V1.23.00
| 2005-03-03  1.22     Pet     ESCAN00011353: Missing multiple node handling
|                              ESCAN00011355: Wrong typed define
| 2005-03-17  1.23     Pet     change core version to V1.25.00
| 2005-04-05  1.24     Pet     change core version to V1.26.00
| 2005-04-21  1.25     Pet     ESCAN00011983: Add support for NM Basic
|                              change core version to V1.28.00
|                              ESCAN00012036: Handling for single optimized channel is missing
| 2005-04-27  1.26     Pet     ESCAN00012053: Add configuration switches
| 2005-04-27  1.27     Pet     ESCAN00012060: Add support for NM Basic in indexed version
| 2005-05-13  1.28     Pet     ESCAN00012254: No wake up is possible during active restricion in special cirrumstances.
|                              change core version to V1.29.00
| 2005-06-22  1.29     Pet     change core version to V1.32.00
| 2005-09-13  1.30     Pet     change core version to V1.37.00
| 2005-11-22  1.30.01  Pet     change core version to V1.37.01
| 2006-01-31  1.30.02  Pet     change core version to V1.37.02
| 2006-03-20  1.30.03  Pet     change core version to V1.37.03
| 2006-06-07  1.30.04  Pet     ESCAN00015685: Wrong NM channel used
| 2006-07-03  1.30.05  Pet     change core version to V1.37.04
| 2007-01-10  1.30.06  Pet     change core version to V1.37.05
| 2007-01-29  1.30.07  Pet     change core version to V1.37.06
| 2007-02-12  1.30.08  Pet     change core version to V1.37.07
| 2007-05-10  1.30.09  Pet     change core version to V1.37.08
| 2007-05-23  1.30.10  Pet     ESCAN00020863: Missing retrun value
| 2007-06-12  1.30.11  Pet     change core version to V1.37.09
| 2007-10-15  1.30.12  Pet     change core version to V1.37.10
| 2007-10-16  1.30.13  Pet     change core version to V1.37.11
|                              ESCAN00022815: Add support for DC Powertrain
| 2007-10-25  1.30.14  Pet     change core version to 1.37.12
| 2008-01-02  1.30.15  Pet     change core version to V1.37.13
| 2008-01-18  1.30.16  Pet     change core version to V1.37.14
| 2008-04-11  1.30.17  Dhf     change core version to V1.37.15
| 2008-08-25  1.30.18  Dhf     change core version to V1.37.16
|                              ESCAN00029459: update CCL to new memory qualifier
| 2008-09-03  1.30.19  Dhf     change core version to V1.37.17
| 2008-09-11  1.30.20  Dhf     change core version to V1.37.18
| 2008-09-17  1.30.21  Pet     change core version to V1.37.19
| 2009-03-16  1.30.22  Dhf     change core version to V1.37.20
| 2009-05-06  1.30.23  Dhf     change core version to V1.37.21
| 2010-01-19  1.30.24  Dhf     ESCAN00039955: changed ApplAsRequestChannelPresent()
| 2010-02-11  1.30.25  Dhf     change core version to V1.37.22
| 2010-03-30  1.30.26  Dhf     ESCAN00041427: added support of NM ASR
|                              ESCAN00035214: added implementation of ApplNmDirOsekFatalError()
|                              change core version to V1.37.23
| 2010-09-09  1.30.27  Dhf     ESCAN00045205: added error directive that Ccl_Dc does not work without DPM
| 2012-06-29  1.30.28  Pet     change core version to V1.37.24
|****************************************************************************/


/***************************************************************************/
/* CORE                                                                    */
/***************************************************************************/



/*****************************************************************************
|  File Name: CCL.C
|
|  Description: Communication Control Layer (CORE) 
|
|-----------------------------------------------------------------------------
|               C O P Y R I G H T
|-----------------------------------------------------------------------------
| Copyright (c) 2000-2012 by Vector Informatik GmbH.      All rights reserved.
|
|               This software is copyright protected and proprietary 
|               to Vector Informatik GmbH. Vector Informatik GmbH 
|               grants to you only those rights as set out in the 
|               license conditions. All other rights remain with 
|               Vector Informatik GmbH.
|-----------------------------------------------------------------------------
|               A U T H O R   I D E N T I T Y
|-----------------------------------------------------------------------------
| Initials     Name                      Company
| --------     ---------------------     ------------------------------------
| Bs           Thomas Balster            Vector Informatik GmbH
| Et           Thomas Ebert              Vector Informatik GmbH
| Zw           Werner Ziegler            Vector Informatik GmbH
| Pet          Thomas Petrus             Vector Informatik GmbH
| Dhf          Daniel Hof                Vector Informatik GmbH
|-----------------------------------------------------------------------------
|               R E V I S I O N   H I S T O R Y
|-----------------------------------------------------------------------------
| Date        Ver     Author  Description
| ---------   ----    ------  ------------------------------------------------
| 31.05.02    1.00    Et/Zw   Initial version
| 02.12.02            Pet     add support for psa
| 2002-12-03  1.01    Pet     add support for Micronas CEVF
| 2003-02-04  1.02    Pet     ESCAN00004878: add support for GMLAN (single receive channel)
| 2003-02-06          Pet     ESCAN00004881: add support for NM JUNIOR
|                     Pet     ESCAN00004886: variable task container
|                     Pet     ESCAN00005256: add internal version controll
|                     Pet     ESCAN00005188: add support for CANdesc
| 2003-03-10          Pet     ESCAN00005255: add support for DBAG OSEK
| 2003-03-24  1.03    Pet     ESCAN00005195: wrong plausibility check for GMLAN
| 2003-04-01  1.04    Pet     ESCAN00005345: separation CCL into core files and OEM extension files
| 2003-06-05  1.05    Pet     CCL DLL version change
| 2003-06-16  1.05.01 Pet     review changes
| 2003-07-25  1.05.02 Pet     optimization for PSA organ type 3
| 2003-08-11  1.05.03 Pet     new DLL bugfix version
| 2003-08-19  1.05.04 Pet     new DLL version
|                     Pet     ESCAN00006299: check return value of "CanSleep"
|                     Pet     ESCAN00006375: multiple release of network requests
| 2003-09-24  1.06    Et      ESCAN00007184: EMC wake up
|                             ESCAN00007185: network management restriction
|                             ESCAN00007187: pagging support
|                             ESCAN00007189: initialization API
|                             ESCAN00007190: reworking (algorithms and namings)
| 2003-12-28  1.07    Et      ESCAN00007258: debug access to internal states (C_COMP_ANSI_CANOE)
|                             ESCAN00007259: initialisation of "cclComHwState" and "cclComSwState"
|                             ESCAN00007260: start EMC wake up timer at power on (+30 reset)
|                             ESCAN00007261: support EMC wake up for CAN driver API
|                             ESCAN00007262: "C_SINGLE_RECEIVE_BUFFER" and "C_MULTIPLE_RECEIVE_BUFFER"
|                             ESCAN00007263: DLL compatibility defines (< V1.06)
|                             ESCAN00007264: support edge triggered transceiver port interrupt
|                             ESCAN00007265: correct network restriction handling
|                             ESCAN00007266: correct network restriction handling
|                             ESCAN00007267: conditional message reception & internal network request
| 2004-01-17  1.07.01 Et      ESCAN00007277: COSMIC compiler option -pck
| 2004-01-21  1.07.02 Pet     ESCAN00007310: wrong #endif
|                             ESCAN00007311: missing encapsulation of cclCanSleepRepetition
|                             ESCAN00007296: different parameter list by Error Hook function CclFatalError
| 2004-01-23  1.08    Pet     ESCAN00007328: add component define for DPM
|                             ESCAN00007403: dummy assignment  NM_MSG_COND_RX_PARAMETER_NAME
|                             ESCAN00007404: support MISRA compliance
| 2004-02-02  1.09    Et      ESCAN00007429: incorrect CclComRelFct notification (set network restriction)
|                             ESCAN00007481: gateway component handle
|                             ESCAN00007548: extern declaration debug variables
| 2004-03-01  1.10    Pet     ESCAN00007741: compiler error in CclInitPowerOn
|                     Et      ESCAN00007722: support no external network requests
|                             ESCAN00007763: add include v_inc.h
|                             ESCAN00007773: no cancel of repeated CanSleep by external wake up
| 2004-03-16  1.11    Pet     ESCAN00007907: function CclGetNmState now API function
|                             ESCAN00007615: support of virtual networks (only for single receive channel)
|                             ESCAN00007939: wrong assertion check
| 2004-06-17  1.12    Pet     ESCAN00008082: EMC Wakeup Time in DPM is lower than 500ms
|                             ESCAN00008379: missing datatype in the prototypes of ApplCclVnDeactivated and ApplCclVnActivated
| 2004-07-02  1.13    Pet     ESCAN00008750: wrong assertion check
| 2004-07-30  1.14    Pet     ESCAN00009037: support multiple configurations
|                     Pet     ESCAN00009074: init value of variable "cclNmState"
|                     Pet     ESCAN00009098: support for GMLAN multichannel
|                     Pet     ESCAN00009118: compiler warning: variable network not used
| 2004-09-09  1.15    Pet     ESCAN00009431: add support for VAG NM C
| 2004-09-21  1.16    Pet     ESCAN00009573: change StateOn handling
|                             ESCAN00009192: missing paging define "DRV_API_CALLBACK_TYPE" in function "ApplCanMsgCondReceived"
|                             ESCAN00009623: prevent additional CAN wake up events
| 2004-10-04  1.17    Pet     ESCAN00009634: missing defines kCclNoCanAvailable and kCclCanAvailable
|                             ESCAN00009686: new core version defines
|                             ESCAN00009693: add support for CAN driver macro CanResetWakeup
|                             ESCAN00009740: inconsistent system request/release state
|                             reject ESCAN00009623
| 2004-10-12  1.18    Pet     ESCAN00009851: add support for Fj16lx
|                             ESCAN00009856: administrative service component handle
|                             ESCAN00009857: NM user data component handle
| 2004-11-02  1.19    Pet     ESCAN00010066: encapsulate CCL software state [only GM]
|                             ESCAN00010069: add support for transceiver type NONE
| 2004-11-10  1.20    Pet     ESCAN00010181: Add support for INM-OSEK (Organ Typ 1)
|                             ESCAN00010071: Transition to network state "prepare to sleep" in spite of pending internal network requests
|                             ESCAN00010087: Transition to network state "sleep" while running communication [only DC]
| 2004-12-10  1.21    Pet     ESCAN00010140: Wrong comment for cclNmRestriction[]. [only DC]
|                             ESCAN00009061: CclGetTrcvErrorPortFct contains NULL pointer
|                             ESCAN00010588: change the visibility of the network request field
|                             ESCAN00010613: Define VGEN_ENABLE_CIOA
| 2005-02-17  1.22    Pet     ESCAN00011217: inconsistencies between DPM and CCL state handling [only DC]
|                             ESCAN00011218: wakeup via CAN bus is not possible
| 2005-02-18  1.23    Bs      ESCAN00011142: change define VGEN_ENABLE_CIOA into CCL_ENABLE_EXTENDED_STATEON
|                             ESCAN00011147: add a comment at any time the CCL changes from an indexed to a code-doubled system
|                             ESCAN00011151: function CclGetNmState() is not needed anymore
|                             ESCAN00011167: add or modify some comments
|                             ESCAN00011035: Compiler error in ccl.c CclAssert: missing parameter
|                             ESCAN00011170: some variables and functions are not necessary if assertions are not activated
|                             ESCAN00011173: change names of function parameters
|                             ESCAN00011176: use defines instead of numbers
|                             ESCAN00011177: wrong variable used in 'CclSystemShutdown()'
|                             ESCAN00011187: change name and type of 'CanECUHandle'
|                             ESCAN00011212: change type of "channel" variable
|                             ESCAN00010661: support fullpreemptive OSEK-OS
|                     Pet     ESCAN00010421: advance system shutdown handling
|                             ESCAN00011118: NULL should not be used in the component
|                             ESCAN00011273: During restriction missing EMC wake up event
| 2005-03-07  1.24    Pet     ESCAN00011382: Add define for advanced shutdown handling
|                             ESCAN00011401: Add defines CCL_ENABLE_SYSTEM_STARTUP and CCL_ENABLE_SYSTEM_SHUTDOWN
| 2005-03-14  1.25    Pet     ESCAN00011430: Remove not used variable cclEndIndex
|                     Pet     ESCAN00011453: Wrong VN handling
|                     Pet     ESCAN00011500: Non expected wake up
|                     Pet     ESCAN00011503: Non wake up able through bus event
|                     Pet     ESCAN00011508: Wrong wake up reason
| 2005-04-05  1.26    Pet     ESCAN00011709: network restriction handling for multichannel systems
|                     Pet     ESCAN00011723: Add define for CclGetNmState
| 2005-04-11  1.27    Pet     ESCAN00011832: add support for wake up registration
|                             ESCAN00011833: add support for the component FIM
| 2005-04-20  1.28    Pet     ESCAN00011977: Support wake up for conditional wake up message
| 2005-05-13  1.29    Pet     ESCAN00012254: No wake up is possible during active restricion in special cirrumstances.
| 2005-05-23  1.30    Pet     ESCAN00012399: multichannel support for network initialization
| 2005-06-08  1.31    Pet     ESCAN00012515: Missing variable encapsulation
|                             ESCAN00012538: Add support for power fail handling
|                             ESCAN00012544: Lock global interrupt during sleep mode transition
| 2005-06-21  1.32    Pet     ESCAN00012614: Add support for single channel optimized CCL with a multichannel CAN driver
|                             ESCAN00012627: Missing internal standby event notification during power fail
|                             ESCAN00012638: Wrong CanOnline call
| 2005-07-05  1.33    Pet     ESCAN00012760: Review changes
|                             ESCAN00013027: Missing excplicitly variable initialization
|                             ESCAN00013208: Wrong call of CanInit during Bus Off recovery at the end of power fail
| 2005-08-15  1.34    Pet     ESCAN00012342: Wrong IL-NI PowerOn/Reset handling
|                             ESCAN00013241: Unexpected Tx timeout error (Tx observe) on first message after PowerFail
| 2005-08-27  1.35    Et      ESCAN00013331: GAIO compiler: symbol redefinition (variable: cclInit / function: CclInit)
| 2005-09-07  1.36    Pet     ESCAN00013450: adapt CAN driver API for reference implementation 1.20
| 2005-09-12  1.37    Pet     ESCAN00013229: update wake up timer handling
|                             ESCAN00013534: Wrong state change notification
|                             ESCAN00013232: Wrong CAN Driver state check during system shutdown
|                             ESCAN00013538: Reduce interrupt locking time in the CCL task
|                             ESCAN00013609: Macro CclAssert must be external visible
| 2005-11-22  1.37.01 Pet     ESCAN00014294: Compiler error if paging is used and CCL is located in a far page
|                             ESCAN00014380: Support faster wake up
| 2006-01-31  1.37.02 Pet     ESCAN00015144: Change configuration check for transceiver and CAN wake up settings
| 2006-03-20  1.37.03 Pet     ESCAN00015744: CAN channel does not enter sleep mode
| 2006-07-03  1.37.04 Pet     ESCAN00016713: ECU is not able to wake up
| 2007-01-10  1.37.05 Pet     ESCAN00018893: Missing variable cast
| 2007-01-29  1.37.06 Pet     ESCAN00018830: Missing DPM state change notification during NM startup
| 2007-02-12  1.37.07 Pet     ESCAN00019537: Add support for different configured identities
| 2007-05-10  1.37.08 Pet     ESCAN00020295: CAN channel stay alive even if no application network request is pending
| 2007-06-12  1.37.09 Pet     ESCAN00021059: Add support of multiple configurations for older configurations
| 2007-10-15  1.37.10 Pet     ESCAN00022782: Support CAN driver configurations which does not use special banking defines
| 2007-10-16  1.37.11 Pet     ESCAN00022800: support configurations which use only non wake up able NM
|                             ESCAN00022814: Add component error code define for the DC PowerTrain component
|                             ESCAN00022819: Shutdown validation of the CAN driver Online/Offline state
| 2007-10-25  1.37.12  Pet    ESCAN00023157: Add support of muliple configurations
| 2008-01-02  1.37.13  Pet    ESCAN00022973: Added support of transciever TLE6251G
| 2008-01-18  1.37.14  Pet    ESCAN00023715: missing function declarations
|                             ESCAN00023737: compiler warning: meaningless statements deleted in optimize phase
| 2008-04-11  1.37.15  Dhf    ESCAN00026013: Added check for number of channels
| 2008-08-25  1.37.16  Dhf    ESCAN00014084: Support new memory qualifier
| 2008-09-03  1.37.17  Dhf    ESCAN00029646: wrong memory qualifier used
| 2008-09-11  1.37.18  Dhf    ESCAN00029938: added support of multiple nodes with identity manager
| 2008-09-17  1.37.19  Pet    ESCAN00030084: Compiler error because of missing kCclChannelIndex definition
| 2009-03-16  1.37.20  Dhf    ESCAN00032576: No startup to DPM external mode
| 2009-05-06  1.37.21  Dhf    ESCAN00034925: added extended initialisation
|                             ESCAN00034953: removed precompile check
|                             ESCAN00027774: Compiler Warning in case of missing cast
|                             ESCAN00031836: added else-path to avoid misra warning
| 2010-02-11  1.37.22  Dhf    ESCAN00040416: Emc timeout is too long
| 2010-03-30  1.37.23  Dhf    ESCAN00040721: added interrupt lock in CclCanNormal()
|                             ESCAN00041956: no changes in this file
| 2012-06-29  1.37.24  Pet    ESCAN00057750: ECU does not react on CAN controller bus wake ups
|****************************************************************************/

#define CCL_MODULE

/***************************************************************************/
/* Include files                                                           */
/***************************************************************************/
#include "v_cfg.h"

#if defined( VGEN_GENY )
#include "v_inc.h"
#endif

#include "ccl.h"

/***************************************************************************/
/* Version check                                                           */
/***************************************************************************/
#if( CCL__CORE_VERSION != 0x0137)
#  error "CCL core: incorrect main or sub version"
#endif

#if( CCL__CORE_RELEASE_VERSION != 0x24)
#  error "CCL core: incorrect release version"
#endif

/***************************************************************************/
/* Plausibility checks                                                     */
/***************************************************************************/
#if( CCL_DLL_VERSION < 0x0106 )
#  if((defined(CCL_USE_REQUEST_SETCOM_FCT) && !defined(CCL_USE_REQUEST_CLEARCOM_FCT)) || \
      (!defined(CCL_USE_REQUEST_SETCOM_FCT) && defined(CCL_USE_REQUEST_CLEARCOM_FCT)))
#    error "CCL_USE_REQUEST_SETCOM_FCT and CCL_USE_REQUEST_CLEARCOM_FCT has to be defined !!"
#  endif
#else
#  if((((defined(CCL_USE_REQUEST_SETINTCOM_FCT) || defined(CCL_USE_REQUEST_SETEXTCOM_FCT)) && !defined(CCL_USE_REQUEST_CLEARCOM_FCT)) || \
      (!defined(CCL_USE_REQUEST_SETINTCOM_FCT) || !defined(CCL_USE_REQUEST_SETEXTCOM_FCT)) && defined(CCL_USE_REQUEST_CLEARCOM_FCT)))
#    error "CCL_USE_REQUEST_SETINTCOM_FCT, CCL_USE_REQUEST_SETEXTCOM_FCT and CCL_USE_REQUEST_CLEARCOM_FCT has to be defined !!"
#  endif
#endif


#if (defined(CCL_ENABLE_MULTIPLE_CONFIG)) && defined(CCL_ENABLE_MULTIPLE_NODES)
#  error "It is not possible to use multiple configuration and multiple ECU in the same configuration."
#endif

/* ESCAN00026013 */
#if( kCclNrOfChannels > 8)
#  error "The CCL does not support more than 8 channels!"
#endif


#if defined (CCL_ENABLE_EXTENDED_INITIALIZATION)
#  if defined (CCL_ENABLE_CANBEDDED_HANDLING)
#    error "The CANbedded handling must be switched off for extended initialization!"
#  endif
#  if (defined(CCL_ENABLE_MULTIPLE_CONFIG) || defined(CCL_ENABLE_MULTIPLE_NODES))
#    error "It is not possible to use multiple configuration, multiple ECU or multiple nodes with extended initialisation!"
#  endif 
#endif


/***************************************************************************/
/* Defines                                                                 */
/***************************************************************************/


#if defined( CCL_ENABLE_EMC_WAKEUP )
#  define cclExtWakeUpReq     cclExtEmcWakeUpReq
#  if(kCclNrOfChannels > 1)
#    define CclExtComReqFctTbl CclExtEmcComReqFctTbl
#  else
#    define CclExtComReqFct    CclExtEmcComReqFct
#  endif
#else
#  define cclExtWakeUpReq     cclExtCanWakeUpReq
#  if(kCclNrOfChannels > 1)
#    define CclExtComReqFctTbl CclExtCanComReqFctTbl
#  else
#    define CclExtComReqFct    CclExtCanComReqFct
#  endif
#endif

#if( CCL_DLL_VERSION < 0x0106 )
#  define CCL_ENABLE_CANBEDDED_HANDLING
#endif

#if( C_VERSION_REF_IMPLEMENTATION < 0x130 )
# define CanGlobalInterruptDisable  CanInterruptDisable
# define CanGlobalInterruptRestore  CanInterruptRestore
#endif

/***************************************************************************/
/* Macros                                                                  */
/***************************************************************************/
#if !defined(CAN_RESET_WAKEUP)
#  if defined(C_MULTIPLE_RECEIVE_CHANNEL)
#    define CanResetWakeup(a) ((void)CanWakeUp((a)))
#  else
#    define CanResetWakeup() ((void)CanWakeUp())
#  endif
#endif

/***************************************************************************/
/* Constants                                                               */
/***************************************************************************/


/***************************************************************************/
/* Local data definitions                                                  */
/***************************************************************************/
#if defined( CCL_ENABLE_EXTERNAL_REQUEST )
#  if defined( CCL_ENABLE_EMC_WAKEUP )
V_MEMRAM0 static V_MEMRAM1 vuint8 V_MEMRAM2 cclExtEmcWakeUpReq[kCclNrOfChannels];
 /*
 * Description        : flag to handle external channel wake up by EMC
 * Access rights      : r/w
 * Val. range / Coding: kCclNoExtEmcChWupReq / kCclExtEmcChWupReq
           (Hint: for downward compatibility these defines are used 
            instead of kCclNoExtChWupReq / kCclExtChWupReq)
 */

V_MEMRAM0 static V_MEMRAM1 vuint8 V_MEMRAM2 cclEmcWakeUpTimer[kCclNrOfChannels];
 /*
 * Description        : timer to force state transition to sleep after
 *                      after an invalid external channel wake up by EMC
 * Access rights      : r/w
 * Val. range / Coding: 0..kCclEmcWakeUpTime
 */
#  endif

V_MEMRAM0 static V_MEMRAM1 vuint8 V_MEMRAM2 cclExtCanWakeUpReq[kCclNrOfChannels];
 /*
 * Description        : flag to handle external channel wake up by CAN
 * Access rights      : r/w
 * Val. range / Coding: kCclNoExtCanChWupReq / kCclExtCanChWupReq
 */

#  if defined( CCL_ENABLE_EMC_WAKEUP )
V_MEMRAM0 static V_MEMRAM1 vuint8 V_MEMRAM2 cclEmcWakeUpActive[kCclNrOfChannels];
 /*
 * Description        : timer flag to check if the wake up timer is running
 * Access rights      : r/w
 * Val. range / Coding: kCclEmcWakeUpTimerActive
 *                      kCclEmcWakeUpTimerDeactive
 */
#  endif

#  if defined(CCL_ENABLE_SLEEP_REPETITION)
V_MEMRAM0 static V_MEMRAM1 vuint8 V_MEMRAM2 cclCanSleepRepetition[kCclNrOfChannels];
#  endif
 /*
 * Description        : flag to handle repetition of function "CanSleep"
 *                      due to failed transition from NORMAL to SLEEP mode
 * Access rights      : r/w
 * Val. range / Coding: kCclNoRepeatCanSleep / kCclRepeatCanSleep
 */


V_MEMRAM0 static V_MEMRAM1 vuint8 V_MEMRAM2 cclCanSleepReturnCode[kCclNrOfChannels];
 /*
 * Description        : return value of function "CanSleep" to ask
 *                      the application about the following handling
 * Access rights      : r/w
 * Val. range / Coding: kCclNoRepeatCanSleep / kCclRepeatCanSleep
 */

#  if defined( CCL_ENABLE_EMC_WAKEUP )
V_MEMRAM0 static V_MEMRAM1 vuint8 V_MEMRAM2 cclEmcWakeUpExp[kCclNrOfChannels];
 /*
 * Description        : timer flag to check if the emc wake up timer is 
 *                      expiered
 * Access rights      : r/w
 * Val. range / Coding: kCclEmcWakeUpTimerRunning / kCclEmcWakeUpTimerDeactive
 */
#  endif
#endif

#if defined( CCL_ENABLE_INTERNAL_REQUEST )
V_MEMRAM0 static V_MEMRAM1 vuint8 V_MEMRAM2 cclIntNetReq[kCclNrOfNetworks];
 /*
 * Description        : flag to handle internal network request
 * Access rights      : r/w
 * Val. range / Coding: 0..kCclNrOfNetworks
 */

V_MEMRAM0 static V_MEMRAM1 vuint8 V_MEMRAM2 cclIntNetRel[kCclNrOfNetworks];
 /*
 * Description        : flag to handle internal network release
 * Access rights      : r/w
 * Val. range / Coding: 0..kCclNrOfNetworks
 */

V_MEMRAM0 static V_MEMRAM1 vuint8 V_MEMRAM2 cclIntNetRelHistory[kCclNrOfNetworks];
 /*
 * Description        : flag to handle internal network release
 * Access rights      : r/w
 * Val. range / Coding: 0..kCclNrOfNetworks
 */

V_MEMRAM0 volatile V_MEMRAM1 vuint8 V_MEMRAM2 cclIntNetState[kCclNetReqTableSize];
 /*
 * Description        : state of internal network request/release
 * Access rights      : r/w
 * Val. range / Coding: 0: network released
 *                      1: network requested
 */


#  if defined(CCL_ENABLE_WAKEUP_EV)
V_MEMRAM0 static V_MEMRAM1 vuint8 V_MEMRAM2 cclWakeUpEvent[kCclNrOfChannels][4];
 /*
 * Description        : content of user data to indication wakeup event
 * Access rights      : r/w
 * Val. range / Coding: s. OEM definition of AUDI/VW
 */

#  endif
#endif

V_MEMRAM0 static V_MEMRAM1 vuint8 V_MEMRAM2 cclNmState[kCclNrOfChannels];
 /*
 * Description        : state of network management depending
 *                      on external channel requests and
 *                      internal network requests or releases
 * Access rights      : r/w
 * Val. range / Coding: 0: kCclNmStateSleep (neither external nor internal request)
 *                      1: kCclNmStateGoToSleep (only external request)
 *                      2: kCclNmStateActive (at least internal request)
 *                      3: kCclNmPowerFail (power fail is active)
 */

#if defined( CCL_ENABLE_NET_STATE_RESTRICTION )
V_MEMRAM0 static V_MEMRAM1 vuint8 V_MEMRAM2 cclNmRestriction[kCclNrOfChannels];
 /*
 * Description        : restriction state of network management to force the
 *                      transition from ACTIVE to GO TO SLEEP and vice versa
 *                      depending on the internal requests and releases.
 * Access rights      : r/w
 * Val. range / Coding: 0: kCclNmRestrictionOn  (state is restricted to GO TO SLEEP)
                        1: kCclNmRestrictionOff (no state restriction)
 */
#endif

V_MEMRAM0 static V_MEMRAM1 vuint8 V_MEMRAM2 cclComHwState[kCclNrOfChannels];
 /*
 * Description        : state of HW to make communication possible
 *                      (PLL, CAN controller, CAN transceiver)
 * Access rights      : r/w
 * Val. range / Coding: 0: kCclComHwEnabled  (HW is enabled by power management)
 *                      1: kCclComHwDisabled (HW is disabled by power management)
 */

V_MEMRAM0 static V_MEMRAM1 vuint8 V_MEMRAM2 cclBusState[kCclNrOfChannels];
 /*
 * Description        : Bus state 
 * Access rights      : r/w
 * Val. range / Coding: 0: kCclBusOn
 *                      1: kCclBusOff
 */

#if defined(C_ENABLE_APPLCANPREWAKEUP_FCT)
V_MEMRAM0 static V_MEMRAM1 vuint8 V_MEMRAM2 cclBusTrcvState[kCclNrOfChannels];
 /*
 * Description        : Trcv state 
 * Access rights      : r/w
 * Val. range / Coding: 0: kCclBusOn  Trcv is in normal
 *                      1: kCclBusOff  Trcv is in standby or sleep
 */
#endif

#if defined(CCL_ENABLE_TRCV_PORT_INT)
V_MEMRAM0 static V_MEMRAM1 vuint8 V_MEMRAM2 cclWakeUpIntState[kCclNrOfChannels];
 /*
 * Description        : state of wake up interrupt by IO port
 * Access rights      : r/w
 * Val. range / Coding: 0: kCclDisableWakeUpInt (port INT is disabled)
 *                      1: kCclEnableWakeUpInt  (port INT is enabled)
 */
#endif

#if( CCL_DLL_VERSION < 0x0106 )
#else
#  if defined( CCL_ENABLE_CANBEDDED_HANDLING )
V_MEMRAM0 static V_MEMRAM1 vuint8 V_MEMRAM2 cclStackInit;
 /*
 * Description        : flag to distinguish between the system specific and
 *                      channel specific CANbedded stack intialisation
 * Access rights      : r/w
 * Val. range / Coding: 0: system specific initialisation
 *                      1: channel specific initialisation
 */
#  endif
#endif







/***************************************************************************/
/* Global data definitions                                                 */
/***************************************************************************/
#if defined( CCL_ENABLE_ERROR_HOOK)
V_MEMRAM0 V_MEMRAM1 vuint8 V_MEMRAM2 cclChannelNumber;
 /*
 * Description        : channel number to identify the occured assertion
 * Access rights      : r/w
 * Val. range / Coding: 0..kCclNrOfChannels
 */

V_MEMRAM0 V_MEMRAM1 vuint16 V_MEMRAM2 cclErrorCode;
 /*
 * Description        : error code to identify the occured assertion
 * Access rights      : r/w
 * Val. range / Coding: s. CCL_INC.H
 */

V_MEMRAM0 V_MEMRAM1 vuint16 V_MEMRAM2 cclErrorLine;
 /*
 * Description        : error line to identify the occured assertion
 * Access rights      : r/w
 * Val. range / Coding: s. DRV, IL, NM, TP or DIAG
 */

V_MEMRAM0 V_MEMRAM1 vuint16 V_MEMRAM2 cclComponentID;
 /*
 * Description        : component identifier to identify the occured assertion
 * Access rights      : r/w
 * Val. range / Coding: s. CCL_INC.H
 */
#endif

#if defined( CCL_ENABLE_SW_COM_STATE )
V_MEMRAM0 V_MEMRAM1 vuint8 V_MEMRAM2 cclComSwState[kCclNrOfChannels];
 /*
 * Description        : communication state of CANbedded stack (DRV, IL, NM)
 * Access rights      : r/w
 * Val. range / Coding: 0: kCclComSwOff  (communication is switched off by CCL)
 *                      1: kCclComSwOn   (communication is switched on by CCL)
 */
#endif

#if defined( CCL_ENABLE_EXTENDED_STATEON )
V_MEMRAM0 volatile V_MEMRAM1 vuint8 V_MEMRAM2 cclStateOn[kCclNrOfChannels];
 /*
 * Description        : communication state of CAN HW
 * Access rights      : r/w
 * Val. range / Coding: 0: kCclCanHwOff  (CAN HW is switched off by CCL)
 *                      1: kCclCanHwOn   (CAN HW is switched on by CCL)
 */
#endif


#if defined ( CCL_ENABLE_EXTENDED_INITIALIZATION )
#else
/***************************************************************************/
/* Local function prototypes                                               */
/***************************************************************************/
static void CclInitPorts(CCL_CHANNEL_CCLTYPE_ONLY);
#endif

/***************************************************************************/
/* Local functions                                                         */
/***************************************************************************/

#if defined(CCL_ENABLE_ERROR_HOOK)
/************************************************************************
| NAME:               CclFatalError
| PROTOTYPE:          void CCL_API_CALL_TYPE CclFatalError(vuint8 ChannelNumber, vuint16 ErrorCode, vuint16 ErrorLine, vuint8 ComponentID)
| CALLED BY:          assertions within the CANbedded stack and/or CCL
|                     re-directe the call of the "FatalError"-functions
|                     Application is NOT ALLOWED to call this function!
| PRECONDITIONS:      'use CCL ErrorHook' has to be activated in the used generation tool to notify the application
| INPUT PARAMETERS:   bChannelNumber: 0-255    (255 default for 'NO_CHANNEL_INFO_AVAILABLE')
|                     wErrorCode    : 0-65.535 (individual specified in each layer)
|                     wErrorLine    : __LINE__ (0 if no information is available)
|                     bComponentID  : s. CCL_INC.H
| RETURN VALUE:       void
| DESCRIPTION:        Convert the given error information to the global error handling
|                     variables and call a application function to handle the error.
|*************************************************************************/
void CCL_API_CALL_TYPE CclFatalError(CanChannelHandle ChannelNumber, vuint16 ErrorCode, vuint16 ErrorLine, vuint8 ComponentID)
 {
   /* pin assertion information */
   cclChannelNumber = (vuint8)ChannelNumber; /* channel number */
   cclErrorCode     = ErrorCode;     /* error code */
   cclErrorLine     = ErrorLine;     /* error line */
   cclComponentID   = ComponentID;   /* component ID */

   /* error hook (assertions) */
   ApplCclFatalError();
 }
#endif

#if defined ( CCL_ENABLE_EXTENDED_INITIALIZATION )
#else
/************************************************************************
| NAME:               CclInitPorts
| PROTOTYPE:          void CclInitPorts(CanChannelHandle channel)
|                     or
|                     void CclInitPorts(void)
| CALLED BY:          CclInitPowerOn
|                     Application is NOT ALLOWED to call this function!
| PRECONDITIONS:      to be called in loop for each channel
| INPUT PARAMETERS:   channel (multiple channel)
|                     or
|                     void (single channel)
| RETURN VALUE:       void
| DESCRIPTION:        calls function container to inizialise all HW ports
|                     (both the transceiver port register and the
|                     transceiver port interrupt) with the channel specific
|                     parameters.
|*************************************************************************/
static void CclInitPorts(CCL_CHANNEL_CCLTYPE_ONLY)
 {
# if defined(CCL_ENABLE_MULTIPLE_CONFIG)
   if((cclIdChMap[V_ACTIVE_IDENTITY_LOG] & (vuint8)((vuint8)1 << (CCL_CHANNEL_CCLINDEX))) > (vuint8)0x00)
   {
# endif
# if defined( CCL_ENABLE_TRCV_TYPE_NONE )
   /* nothing to do */
# else
   /* init transceiver port register */
#  if(kCclNrOfChannels > 1)
   if( CclInitTrcvFctTbl[CCL_CHANNEL_CCLINDEX] != V_NULL)
   {
     /* By using the following table of function calls, code-doubled functions 
     * are called from the indexed CCL. This is done to simplify the called 
     * functions (no distinction of the parameter 'channel' is necessary). */
     (CclInitTrcvFctTbl[CCL_CHANNEL_CCLINDEX])();
   }
#   else
   CclInitTrcvFct();
#   endif
# endif

# if defined(CCL_ENABLE_TRCV_PORT_INT)
#   if defined(CCL_ENABLE_EXTERNAL_REQUEST)
   /* init transceiver port interrupt */
#     if(kCclNrOfChannels > 1)
   /* By using the following tables of function calls, code-doubled functions 
  * are called from the indexed CCL. This is done to simplify the called 
  * functions (no distinction of the parameter 'channel' is necessary). */
   (CclConfigTrcvIntFctTbl[CCL_CHANNEL_CCLINDEX])();
   (CclDisableTrcvIntFctTbl[CCL_CHANNEL_CCLINDEX])();
   (CclClearTrcvIntFctTbl[CCL_CHANNEL_CCLINDEX])();
#     else
   CclConfigTrcvIntFct();
   CclDisableTrcvIntFct();
   CclClearTrcvIntFct();
#     endif
   /* set INT state to "disable" */
   cclWakeUpIntState[CCL_CHANNEL_CCLINDEX] = kCclDisableWakeUpInt;
#   endif
# endif
# if defined(CCL_ENABLE_MULTIPLE_CONFIG)
   }
# endif
 }
#endif


#if defined(CCL_ENABLE_EXTERNAL_REQUEST)
 /************************************************************************
 | NAME:               ApplCanWakeUp
 | PROTOTYPE:          void ApplCanWakeUp(CanChannelHandle channel)
 |                     or
 |                     void ApplCanWakeUp(void)
 | CALLED BY:          CANdrv:  CanWakeUpInt / CanWakeUpTask (internal wake up INT)
 |                     CCL:     CclCanWakeUpInt (external wake up INT)
 |                     Application is NOT ALLOWED to call this function!
 | PRECONDITIONS:      -
 | INPUT PARAMETERS:   channel (multiple channel)
 |                     or
 |                     void (single channel)
 | RETURN VALUE:       void
 | DESCRIPTION:        Function notifies WakeUp over RX/INH transceiver port
 |                     (handled in CCL) or WakeUp over CAN controller
 |                     (handled in CAN driver), sets the external channel
 |                     wakeup request flag and requests the power manager state.
 |*************************************************************************/
void DRV_API_CALLBACK_TYPE ApplCanWakeUp(CAN_CHANNEL_CANTYPE_ONLY)
 {
#  if defined(C_MULTIPLE_RECEIVE_CHANNEL)
#    if( kCclNrOfChannels == 1)
   if(channel == (CanChannelHandle)kCclChannelIndex)
#    endif
#  endif
   {
#  if defined(CCL_ENABLE_NET_STATE_RESTRICTION)
     if( (cclIntNetReq[CCL_CHANNEL_CCLINDEX] == kCclNoIntNetReq) ||
         (cclNmRestriction[CCL_CHANNEL_CCLINDEX] == kCclNmRestrictionOn) )  /* ESCAN00011217, ESCAN00011218 and ESCAN00011273 */
#  else
     if(cclIntNetReq[CCL_CHANNEL_CCLINDEX] == kCclNoIntNetReq) /* ESCAN00011217 and ESCAN00011218 */
#  endif
     {
       if(cclBusState[CCL_CHANNEL_CCLINDEX] == kCclBusOff)
       {
         /* set external EMC or CAN wake up request */
         cclExtWakeUpReq[CCL_CHANNEL_CCLINDEX] = kCclExtChWupReq;

#  if defined(CCL_ENABLE_WAKEUP_IN_IRQ)
         if( cclNmState[CCL_CHANNEL_CCLINDEX] == kCclNmStateSleep )
         {
           /* set CAN communication (HW and SW) to NORMAL mode within the wake up interrupt to permit a fast ack */
            CclCanNormal(CCL_CHANNEL_CCLPARA_ONLY);
         }
#  endif

#  if defined(CCL_USE_REQUEST_SETEXTCOM_FCT)
         /* external EMC or CAN communication request notification */
         if( cclNmState[CCL_CHANNEL_CCLINDEX] == kCclNmStateSleep )
         {
#    if(kCclNrOfChannels > 1)
           if (CclExtComReqFctTbl[CCL_CHANNEL_CCLINDEX] != V_NULL)
           {
             /* By using the following table of function calls, code-doubled functions 
              * are called from the indexed CCL. This is done to simplify the called 
              * functions (no distinction of the parameter 'channel' is necessary). */
             (CclExtComReqFctTbl[CCL_CHANNEL_CCLINDEX])();
           }
#    else
           CclExtComReqFct();
#    endif
         }
#  endif
       }
     }
   }
 }

#  if defined(C_ENABLE_APPLCANPREWAKEUP_FCT)
 /************************************************************************
 | NAME:               ApplCanPreWakeUp
 | PROTOTYPE:          void ApplCanPreWakeUp(CanChannelHandle channel)
 |                     or
 |                     void ApplCanPreWakeUp(void)
 | CALLED BY:          CANdrv:  CanWakeUpInt / CanWakeUpTask (internal wake up INT)
 |                     Application is NOT ALLOWED to call this function!
 | PRECONDITIONS:      -
 | INPUT PARAMETERS:   channel (multiple channel)
 |                     or
 |                     void (single channel)
 | RETURN VALUE:       void
 | DESCRIPTION:        Function sets the transceiver in normal mode
 |*************************************************************************/
void DRV_API_CALLBACK_TYPE ApplCanPreWakeUp(CAN_CHANNEL_CANTYPE_ONLY)
{
#    if defined(C_MULTIPLE_RECEIVE_CHANNEL)
#      if( kCclNrOfChannels == 1)
   if(channel == (CanChannelHandle)kCclChannelIndex)
#      endif
#    endif
  {
      /* check the actual bus state, to prevent multiple activations */
      if(cclBusTrcvState[CCL_CHANNEL_CCLINDEX] == kCclBusOff)
      {
        /* the bus state is off */
#   if defined( CCL_ENABLE_TRCV_TYPE_NONE )
       /* nothing to do */
#   else
       /* set transceiver to NORMAL mode by port register */
#     if(kCclNrOfChannels > 1)
       if( CclWakeUpTrcvFctTbl[CCL_CHANNEL_CCLINDEX] != V_NULL)
       {
         /* By using the following table of function calls, code-doubled functions 
          * are called from the indexed CCL. This is done to simplify the called 
          * functions (no distinction of the parameter 'channel' is necessary). */
         (CclWakeUpTrcvFctTbl[CCL_CHANNEL_CCLINDEX])();
       }
#     else
       CclWakeUpTrcvFct();
#     endif
       cclBusTrcvState[CCL_CHANNEL_CCLINDEX] = kCclBusOn;
#   endif
      }
  }
}
#  endif
#endif





/************************************************************************
 | NAME:               CclCanNormal
 | PROTOTYPE:          void CclCanNormal(CanChannelHandle channel)
 |                     or
 |                     void CclCanNormal(void)
 | CALLED BY:          CCL
 |                     Application is NOT ALLOWED to call this function!
 | PRECONDITIONS:      -
 | INPUT PARAMETERS:   channel (multiple channel)
 |                     or
 |                     void (single channel)
 | RETURN VALUE:       void
 | DESCRIPTION:        set CAN transceiver and CAN controller to NORMAL mode
 |*************************************************************************/
void CclCanNormal(CCL_CHANNEL_CCLTYPE_ONLY)
{

#if defined(CCL_ENABLE_EXTERNAL_REQUEST)
#  if defined(CCL_ENABLE_SLEEP_REPETITION)
  /* stop sleep repetition handling */
  cclCanSleepRepetition[CCL_CHANNEL_CCLINDEX] = kCclNoRepeatCanSleep;
#  endif
#endif

  {
    if(cclBusState[CCL_CHANNEL_CCLINDEX] == kCclBusOff)
    {
#if defined( CCL_ENABLE_TRCV_TYPE_NONE )
   /* nothing to do */
#else
#  if defined(C_ENABLE_APPLCANPREWAKEUP_FCT)
      /* check the actual transceiver state, to prevent multiple activations */
      if(cclBusTrcvState[CCL_CHANNEL_CCLINDEX] == kCclBusOff)
      {
#endif
         /* set transceiver to NORMAL mode by port register */
#  if(kCclNrOfChannels > 1)
         if( CclWakeUpTrcvFctTbl[CCL_CHANNEL_CCLINDEX] != V_NULL)
        {
           /* By using the following table of function calls, code-doubled functions 
            * are called from the indexed CCL. This is done to simplify the called 
            * functions (no distinction of the parameter 'channel' is necessary). */
           (CclWakeUpTrcvFctTbl[CCL_CHANNEL_CCLINDEX])();
         }
#  else
         CclWakeUpTrcvFct();
#  endif
#  if defined(C_ENABLE_APPLCANPREWAKEUP_FCT)
         cclBusTrcvState[CCL_CHANNEL_CCLINDEX] = kCclBusOn;
      }
#  endif
#endif

#  if defined(CCL_ENABLE_EXTERNAL_REQUEST)
#    if(kCclNrOfChannels > 1)
   /* check wake up / sleep support */
       if((cclNmWakeUpAble & (vuint8)((vuint8)1 << (CCL_CHANNEL_CCLINDEX))) != kCclNoWakeUpAble)
#    endif
       {
         CanGlobalInterruptDisable();

         /* set CAN controller to NORMAL mode */
#    if defined(C_MULTIPLE_RECEIVE_CHANNEL)
         CanResetWakeup(CCL_CHANNEL_CANPARA_ONLY);
#    else
         CanResetWakeup();
#    endif

         CanGlobalInterruptRestore();
       }
#  endif
       cclBusState[CCL_CHANNEL_CCLINDEX] = kCclBusOn;
     }
#  if defined(CCL_ENABLE_EXTERNAL_REQUEST)
    else if(cclCanSleepReturnCode[CCL_CHANNEL_CCLINDEX] == kCanFailed)
    {
#    if(kCclNrOfChannels > 1)
      /* check wake up / sleep support */
      if((cclNmWakeUpAble & (vuint8)((vuint8)1 << (CCL_CHANNEL_CCLINDEX))) != kCclNoWakeUpAble)
#    endif
      {
        CanGlobalInterruptDisable();

        /* set CAN controller to NORMAL mode */
#    if defined(C_MULTIPLE_RECEIVE_CHANNEL)
        CanResetWakeup(CCL_CHANNEL_CANPARA_ONLY);
#    else
        CanResetWakeup();
#    endif

        CanGlobalInterruptRestore();
      }
    }
    /* ESCAN00031836 */
    else
    {
      /* This else-path exists to satisfy QAC */
    }

    /* reset the CanSleep return value */
    cclCanSleepReturnCode[CCL_CHANNEL_CCLINDEX] = kCanOk;
#  endif


#  if defined( CCL_ENABLE_EXTENDED_STATEON )
     /* CAN HW state to on */
     cclStateOn[CCL_CHANNEL_CCLINDEX] = kCclCanHwOn;
#  endif
  }
}

 /************************************************************************
 | NAME:                CclCanStandby
 | PROTOTYPE:           void CclCanStandby(CanChannelHandle channel)
 |                      or
 |                      void CclCanStandby(void)
 | CALLED BY:           CCL
 |                      Application is NOT ALLOWED to call this function!
 | PRECONDITIONS:       -
 | INPUT PARAMETERS:    channel (multiple channel)
 |                      or
 |                      void (single channel)
 | RETURN VALUE:        void
 | DESCRIPTION:         set CAN controller and CAN transceiver to SLEEP mode,
 |                      release the power manager state and enable the
 |                      external wakeup port INT
 |*************************************************************************/
void CclCanStandby(CCL_CHANNEL_CCLTYPE_ONLY)
{
  CanGlobalInterruptDisable();

  {
    {
#if defined( CCL_ENABLE_EMC_WAKEUP )
      /* check EMC wake up timer */
      if(cclEmcWakeUpTimer[CCL_CHANNEL_CCLINDEX] == kCclEmcWakeUpTimerStopped)
#endif
      {
#  if defined(CCL_ENABLE_EXTERNAL_REQUEST)
#    if(kCclNrOfChannels > 1)
        /* check wake up / sleep support */
        if((cclNmWakeUpAble & (vuint8)((vuint8)1 << (CCL_CHANNEL_CCLINDEX))) != kCclNoWakeUpAble )
#    endif
        {
          /* set CAN controller to SLEEP mode */
          cclCanSleepReturnCode[CCL_CHANNEL_CCLINDEX] = CanSleep(CCL_CHANNEL_CANPARA_ONLY);
        }

       /* check "CanSleep" return code */
       if(cclCanSleepReturnCode[CCL_CHANNEL_CCLINDEX] != kCanFailed)
#  endif
       {
#if defined(CCL_ENABLE_EXTERNAL_REQUEST)
#  if defined(CCL_ENABLE_SLEEP_REPETITION)
         /* stop sleep repetition handling */
         cclCanSleepRepetition[CCL_CHANNEL_CCLINDEX] = kCclNoRepeatCanSleep;
#  endif
#endif

#  if defined( CCL_ENABLE_TRCV_TYPE_NONE )
         /* nothing to do */
#  else
         /* set transceiver to SLEEP or STANDBY mode by port register */
#    if(kCclNrOfChannels > 1)
         if( CclSleepTrcvFctTbl[CCL_CHANNEL_CCLINDEX] != V_NULL)
         {
           /* By using the following table of function calls, code-doubled functions 
           * are called from the indexed CCL. This is done to simplify the called 
           * functions (no distinction of the parameter 'channel' is necessary). */
           (CclSleepTrcvFctTbl[CCL_CHANNEL_CCLINDEX])();
         }
#    else
         CclSleepTrcvFct();
#    endif
#  endif

#if defined( CCL_ENABLE_EXTENDED_STATEON )
         /* CAN HW state to off */
         cclStateOn[CCL_CHANNEL_CCLINDEX] = kCclCanHwOff;
#endif

         /* set network management state to SLEEP */
         cclNmState[CCL_CHANNEL_CCLINDEX] = kCclNmStateSleep;

         cclBusState[CCL_CHANNEL_CCLINDEX] = kCclBusOff;

#if defined(C_ENABLE_APPLCANPREWAKEUP_FCT)
         cclBusTrcvState[CCL_CHANNEL_CCLINDEX] = kCclBusOff;
#endif


#if defined(CCL_USE_REQUEST_CLEARCOM_FCT)
         /* communication release notification */
#  if(kCclNrOfChannels > 1)
         if(CclComRelFctTbl[CCL_CHANNEL_CCLINDEX] != V_NULL)
         {
           /* By using the following table of function calls, code-doubled functions 
           * are called from the indexed CCL. This is done to simplify the called 
           * functions (no distinction of the parameter 'channel' is necessary). */
           (CclComRelFctTbl[CCL_CHANNEL_CCLINDEX])();
         }
#  else
         CclComRelFct();
#  endif
#endif

#if defined(CCL_ENABLE_TRCV_PORT_INT)
#  if defined(CCL_ENABLE_NET_STATE_RESTRICTION)
         if( (cclIntNetReq[CCL_CHANNEL_CCLINDEX] == kCclNoIntNetReq) ||
             (cclNmRestriction[CCL_CHANNEL_CCLINDEX] == kCclNmRestrictionOn) )
         {
           /* no internal request is pending or the network restriction is active */
#  else
         if(cclIntNetReq[CCL_CHANNEL_CCLINDEX] == kCclNoIntNetReq)
         {
           /* no internal request is pending */
#  endif
           /* enable transceiver port interrupt */
#  if( kCclNrOfChannels > 1 )
           /* By using the following table of function calls, code-doubled functions 
            * are called from the indexed CCL. This is done to simplify the called 
            * functions (no distinction of the parameter 'channel' is necessary). */
           /* Wtihin the following function calls a maybe pending 
            *  Transceiver interrupt will be cleared! */
           (CclClearTrcvIntFctTbl[CCL_CHANNEL_CCLINDEX])();
           (CclEnableTrcvIntFctTbl[CCL_CHANNEL_CCLINDEX])();
#  else
           /* Wtihin the following function calls a maybe pending 
            *  Transceiver interrupt will be cleared! */
           CclClearTrcvIntFct();
           CclEnableTrcvIntFct();
#  endif

           /* set INT state to "enable" */
           cclWakeUpIntState[CCL_CHANNEL_CCLINDEX] = kCclEnableWakeUpInt;

#  if defined(CCL_ENABLE_TRCV_PORT_EDGE_TRIGGER)
           /* check transceiver port register */
#    if( kCclNrOfChannels > 1 )
           if(CclCheckTrcvIntFctTbl[CCL_CHANNEL_CCLINDEX]() == kCclTrcvWakeIntPending)
           {
             /* By using the following table of function calls, code-doubled functions 
              * are called from the indexed CCL. This is done to simplify the called 
              * functions (no distinction of the parameter 'channel' is necessary). */

             /* disable transceiver port interrupt */
             (CclDisableTrcvIntFctTbl[CCL_CHANNEL_CCLINDEX])();
#    else
             if(CclCheckTrcvIntFct() == kCclTrcvWakeIntPending)
             {
               /* disable transceiver port interrupt */
               CclDisableTrcvIntFct();
#    endif

               /* check INT state */
               if(cclWakeUpIntState[CCL_CHANNEL_CCLINDEX] == kCclEnableWakeUpInt)
               {
                 /* external EMC/CAN wake up notification */
                 CclCanWakeUpInt(CCL_CHANNEL_CCLPARA_ONLY);
               }
             }
#  endif
           }
#endif
       }

#if defined(CCL_ENABLE_EXTERNAL_REQUEST)
#  if defined(CCL_ENABLE_SLEEP_REPETITION)
       cclCanSleepRepetition[CCL_CHANNEL_CCLINDEX] = ApplCclCanStandby(CCL_CHANNEL_CCLPARA_FIRST cclCanSleepReturnCode[CCL_CHANNEL_CCLINDEX]);

       CclAssert( ( ((cclCanSleepRepetition[CCL_CHANNEL_CCLINDEX] == kCclNoRepeatCanSleep) && (cclCanSleepReturnCode[CCL_CHANNEL_CCLINDEX] == kCanOk)) || \
                        ((cclCanSleepRepetition[CCL_CHANNEL_CCLINDEX] == kCclNoRepeatCanSleep) && (cclCanSleepReturnCode[CCL_CHANNEL_CCLINDEX] == kCanNotSupported)) || \
                        ((cclCanSleepRepetition[CCL_CHANNEL_CCLINDEX] == kCclRepeatCanSleep) && (cclCanSleepReturnCode[CCL_CHANNEL_CCLINDEX] == kCanFailed)) \
                       ), kWrongReturnValue)

#  else
       (void)ApplCclCanStandby(CCL_CHANNEL_CCLPARA_FIRST cclCanSleepReturnCode[CCL_CHANNEL_CCLINDEX]);
#  endif
#endif

#if defined( CCL_USE_REQUEST_SETINTCOM_FCT )
#  if defined(CCL_ENABLE_EXTERNAL_REQUEST)
       /* check "CanSleep" return code */
       if(cclCanSleepReturnCode[CCL_CHANNEL_CCLINDEX] != kCanFailed)
#  endif
       {
#  if defined(CCL_ENABLE_NET_STATE_RESTRICTION)
         if( (cclIntNetReq[CCL_CHANNEL_CCLINDEX] != kCclNoIntNetReq) &&
             (cclNmRestriction[CCL_CHANNEL_CCLINDEX] == kCclNmRestrictionOff) )
         {
           /* min. one internal request is pending and the network restriction is off */
#  else
         if(cclIntNetReq[CCL_CHANNEL_CCLINDEX] != kCclNoIntNetReq)
         {
           /* min. one internal request is pending */
#  endif
           /* internal communication request notification */
#  if ( kCclNrOfChannels > 1 )
           if (CclIntComReqFctTbl[CCL_CHANNEL_CCLINDEX] != V_NULL)
           {
             /* By using the following table of function calls, code-doubled functions 
              * are called from the indexed CCL. This is done to simplify the called 
              * functions (no distinction of the parameter 'channel' is necessary). */
             (CclIntComReqFctTbl[CCL_CHANNEL_CCLINDEX])();
           }
#  else
           CclIntComReqFct();
#  endif
         }
       }
#endif
      }
    }
  }

  CanGlobalInterruptRestore();
 }


#if (defined( CCL_ENABLE_EXTERNAL_REQUEST) ||\
     defined( CCL_ENABLE_INTERNAL_REQUEST))
/************************************************************************
| NAME:               CclTask
| PROTOTYPE:          void CclTask( void )
| CALLED BY:          generated task container function
|                     Application is NOT ALLOWED to call this function!
| PRECONDITIONS:
| INPUT PARAMETERS:   void
| RETURN VALUE:       void
| DESCRIPTION:        internal network request handling
|                     internal network release handling
|                     external channel request handling
|                     EMC wake up timeout handling
|                     sleep repetition handling
|*************************************************************************/
void CCL_API_CALL_TYPE CclTask(void)
 {
#  if(kCclNrOfChannels > 1)
   CanChannelHandle channel; /* number of physical channels */
#  endif

#  if(kCclNrOfNetworks > 1)
   vuint8 network; /* number of logical networks */
#  endif


#  if(kCclNrOfChannels > 1)
   channel = 0;
#  endif


#  if(kCclNrOfNetworks > 1)
   network = 0;
#  endif

#  if(kCclNrOfNetworks > 1)
   for(network=0; network<kCclNrOfNetworks; network++)
#  endif
   {
     /* ESCAN00010661 
      *  Disable the global interrupt to guarantee data consistency 
      *  if this function is called from interrupt insted of task level. */
     CanGlobalInterruptDisable();

#    if(kCclNrOfChannels > 1)
     channel = (CanChannelHandle)network;
#    endif

#    if defined(CCL_ENABLE_MULTIPLE_CONFIG)
     if((cclIdChMap[V_ACTIVE_IDENTITY_LOG] & (vuint8)((vuint8)1 << (CCL_CHANNEL_CCLINDEX))) > (vuint8)0x00)
     {
#    endif
       /* check HW communication state */
       if(cclComHwState[CCL_CHANNEL_CCLINDEX] == kCclComHwEnabled)
       {
#  if defined( CCL_ENABLE_INTERNAL_REQUEST )
         {
/* ===================================================================== */
/* = begin "internal network request handling" ========================= */
/* ===================================================================== */
#    if defined(CCL_ENABLE_NET_STATE_RESTRICTION)
           /* check network management restriction */
           if((cclNmRestriction[CCL_CHANNEL_CCLINDEX]) == kCclNmRestrictionOff)
#    endif
          {
             /* pending internal network request? */
             if((cclIntNetReq[CCL_NET_CCLINDEX] != kCclNoIntNetReq))
             {
              {
#    if defined( CCL_ENABLE_EMC_WAKEUP )
                 /* reject message reception notification */
                 CanResetMsgReceivedCondition(CCL_CHANNEL_CANPARA_ONLY);
#    endif

                /* container function for transition from SLEEP or GO TO SLEEP to ACTIVE */
#      if(kCclNrOfChannels > 1)
                 /* By using the following table of function calls, code-doubled functions 
                 * are called from the indexed CCL. This is done to simplify the called 
                 * functions (no distinction of the parameter 'channel' is necessary). */
                 (void)CclNmActiveReqFctTbl[CCL_NET_CCLINDEX](cclIntNetReq[CCL_NET_CCLINDEX]);
#      else
                (void)CclNmActiveReqFct(cclIntNetReq[CCL_NET_CCLINDEX]);
#      endif
              }

               /* set network management state to ACTIVE */
               cclNmState[CCL_CHANNEL_CCLINDEX] = kCclNmStateActive;

               /* clear internal network request */
               cclIntNetReq[CCL_NET_CCLINDEX] = kCclNoIntNetReq;

               /* clear internal network release history flag */
               cclIntNetRelHistory[CCL_NET_CCLINDEX] = kCclNoIntNetRel;


#    if defined( CCL_ENABLE_EXTERNAL_REQUEST )
#      if defined( CCL_ENABLE_EMC_WAKEUP )
               /* clear external EMC channel request */
               cclExtEmcWakeUpReq[CCL_CHANNEL_CCLINDEX] = kCclNoExtChWupReq;

               /* stop EMC wake up timer */
               cclEmcWakeUpTimer[CCL_CHANNEL_CCLINDEX] = kCclEmcWakeUpTimerStopped;
               cclEmcWakeUpActive[CCL_CHANNEL_CCLINDEX] = kCclEmcWakeUpTimerDeactive;
               cclEmcWakeUpExp[CCL_CHANNEL_CCLINDEX] = kCclEmcWakeUpTimerDeactive;
             
#      endif

               /* clear external CAN channel request */
               cclExtCanWakeUpReq[CCL_CHANNEL_CCLINDEX] = kCclNoExtChWupReq;

#      if defined(CCL_ENABLE_SLEEP_REPETITION)
               /* stop sleep repetition handling */
               cclCanSleepRepetition[CCL_CHANNEL_CCLINDEX] = kCclNoRepeatCanSleep;
#      endif
#    endif
           }
         }
/* ===================================================================== */
/* = end "internal network request handling" =========================== */
/* ===================================================================== */

/* ===================================================================== */
/* = begin "internal network release handling" ========================= */
/* ===================================================================== */
           if( (cclIntNetRel[CCL_NET_CCLINDEX] != kCclNoIntNetRel) )
           {
             /* set network management state to GO TO SLEEP */
             cclNmState[CCL_CHANNEL_CCLINDEX] = kCclNmStateGoToSleep;

             /* container function for transition from ACTIVE to GO TO SLEEP */
#    if ( kCclNrOfChannels > 1 )
             /* By using the following table of function calls, code-doubled functions 
             * are called from the indexed CCL. This is done to simplify the called 
             * functions (no distinction of the parameter 'channel' is necessary). */
             (CclNmSleepReqFctTbl[CCL_NET_CCLINDEX])(cclIntNetRel[CCL_NET_CCLINDEX]);
#    else
            CclNmSleepReqFct(cclIntNetRel[CCL_NET_CCLINDEX]);
#    endif

             /* clear internal network release */
             cclIntNetRel[CCL_NET_CCLINDEX] = kCclNoIntNetRel;
             cclIntNetRelHistory[CCL_NET_CCLINDEX] = kCclNoIntNetRel;

         }
/* ===================================================================== */
/* = end "internal network release handling" =========================== */
/* ===================================================================== */
#  endif

#  if defined(CCL_ENABLE_EXTERNAL_REQUEST)
/* ===================================================================== */
/* = begin "external channel request handling" ========================= */
/* ===================================================================== */
#    if defined( CCL_ENABLE_EMC_WAKEUP )
           /* pending external EMC channel request? */
           if(cclExtEmcWakeUpReq[CCL_CHANNEL_CCLINDEX] == kCclExtChWupReq)
           {
             if( cclNmState[CCL_CHANNEL_CCLINDEX] == kCclNmStateSleep )
             {
               /* set CAN communication (HW and SW) to NORMAL mode */
                CclCanNormal(CCL_CHANNEL_CCLPARA_ONLY);

               /* start EMC wake up timer */
               cclEmcWakeUpTimer[CCL_CHANNEL_CCLINDEX] = (vuint8)kCclEmcWakeUpTime; /* ESCAN00040416 */
               cclEmcWakeUpActive[CCL_CHANNEL_CCLINDEX] = kCclEmcWakeUpTimerActive;
             }

             /* clear external EMC channel request */
             cclExtEmcWakeUpReq[CCL_CHANNEL_CCLINDEX] = kCclNoExtChWupReq;
           }
#    endif

           /* pending external CAN channel request? */
           if(cclExtCanWakeUpReq[CCL_CHANNEL_CCLINDEX] == kCclExtChWupReq)
           {
             if( cclNmState[CCL_CHANNEL_CCLINDEX] == kCclNmStateSleep )
             {
#    if defined( CCL_ENABLE_EMC_WAKEUP )
               /* stop EMC wake up timer */
               cclEmcWakeUpTimer[CCL_CHANNEL_CCLINDEX] = kCclEmcWakeUpTimerStopped;
               cclEmcWakeUpActive[CCL_CHANNEL_CCLINDEX] = kCclEmcWakeUpTimerDeactive;
               cclEmcWakeUpExp[CCL_CHANNEL_CCLINDEX] = kCclEmcWakeUpTimerDeactive;
#    endif

               /* set network management state to GO TO SLEEP */
               cclNmState[CCL_CHANNEL_CCLINDEX] = kCclNmStateGoToSleep;

               /* container function for transition from SLEEP to GO TO SLEEP */
#    if(kCclNrOfChannels > 1)
               /* By using the following table of function calls, code-doubled functions 
               * are called from the indexed CCL. This is done to simplify the called 
               * functions (no distinction of the parameter 'channel' is necessary). */
               (CclNmPrepareSleepReqFctTbl[CCL_CHANNEL_CCLINDEX])();
#    else
               CclNmPrepareSleepReqFct();
#    endif


#    if defined(CCL_ENABLE_WAKEUP_EV)
               /* set the wake up reason CAN */
               CclSetWakeUpReasonCAN(CCL_CHANNEL_CCLPARA_ONLY);
#    endif

#    if defined(CCL_ENABLE_SLEEP_REPETITION)         
               /* stop sleep repetition handling */
               cclCanSleepRepetition[CCL_CHANNEL_CCLINDEX] = kCclNoRepeatCanSleep;
#    endif
            }

             /* clear external CAN channel request */
             cclExtCanWakeUpReq[CCL_CHANNEL_CCLINDEX] = kCclNoExtChWupReq;
          }
/* ===================================================================== */
/* = end "external channel request handling" =========================== */
/* ===================================================================== */

#    if defined( CCL_ENABLE_EMC_WAKEUP )
/* ===================================================================== */
/* = begin "EMC wake up timeout handling" ============================== */
/* ===================================================================== */
           /* EMC wake up timer is active? */         
           if(cclEmcWakeUpActive[CCL_CHANNEL_CCLINDEX] < kCclEmcWakeUpTimerDeactive)
           {
             /* EMC wake up timer is running */
             if(cclEmcWakeUpTimer[CCL_CHANNEL_CCLINDEX] > kCclEmcWakeUpTimerStopped)
             {
               /* decrement EMC wake up timer */
               cclEmcWakeUpTimer[CCL_CHANNEL_CCLINDEX]--;
             }
             else
             {
               /* EMC wake up timer is expired */
               cclEmcWakeUpExp[CCL_CHANNEL_CCLINDEX] = kCclEmcWakeUpTimerExpired;
             }

             /* EMC wake up timer is expired? */
             if(cclEmcWakeUpExp[CCL_CHANNEL_CCLINDEX] < kCclEmcWakeUpTimerRunning)
             {
               /* set CAN communication (HW and SW) to SLEEP */
               CclCanStandby(CCL_CHANNEL_CCLPARA_ONLY);
               /* deactive the EMC wake up timer */
               cclEmcWakeUpActive[CCL_CHANNEL_CCLINDEX] = kCclEmcWakeUpTimerDeactive;
               cclEmcWakeUpExp[CCL_CHANNEL_CCLINDEX] = kCclEmcWakeUpTimerDeactive;
             }
           }
#      if defined( CCL_ENABLE_DEBUG)
           if(cclEmcWakeUpActive[CCL_CHANNEL_CCLINDEX] == kCclEmcWakeUpTimerDeactive)
           {
             CclAssert(cclEmcWakeUpTimer[CCL_CHANNEL_CCLINDEX] == kCclEmcWakeUpTimerStopped, kCclErrEMCTimerHdlgFailed);
           }
           if(cclEmcWakeUpActive[CCL_CHANNEL_CCLINDEX] == kCclEmcWakeUpTimerDeactive)
           {
             CclAssert(cclEmcWakeUpExp[CCL_CHANNEL_CCLINDEX] == kCclEmcWakeUpTimerDeactive , kCclErrEMCTimerHdlgFailed);
           }
#      endif
/* ===================================================================== */
/* = end "sleep repetition handling" =================================== */
/* ===================================================================== */
#    endif

#    if defined(CCL_ENABLE_SLEEP_REPETITION)
           /* check sleep repetition handling */
           if(cclCanSleepRepetition[CCL_CHANNEL_CCLINDEX] != kCclNoRepeatCanSleep)
           {
             /* set CAN communication (HW and SW) to SLEEP */
             CclCanStandby(CCL_CHANNEL_CCLPARA_ONLY);
           }
#    endif

#  endif
         }
       }
#if defined(CCL_ENABLE_MULTIPLE_CONFIG)
    }
#endif
     /* ESCAN00010661 
     *  Disable the global interrupt to guarantee data consistency 
     *  if this function is called from interrupt insted of task level. */
     CanGlobalInterruptRestore();
   }
}
#endif


/***************************************************************************/
/* Global functions                                                        */
/***************************************************************************/

/************************************************************************
| NAME:               CclInit
| PROTOTYPE:          void CclInit(CanChannelHandle channel)
|                     or
|                     void CclInit(void)
| CALLED BY:          Application during startup the system or while runtime
| PRECONDITIONS:      -
| INPUT PARAMETERS:   channel (multiple channel)
|                     or
|                     void (single channel)
| RETURN VALUE:       void
| DESCRIPTION:        channel specific initialisation of CCL and CANbedded stack
|*************************************************************************/
#if defined(CCL_ENABLE_EXTENDED_INITIALIZATION)
void CCL_API_CALL_TYPE CclInit(CCL_CHANNEL_CCLTYPE_FIRST tCclInitParaType cclInitValue)
#else
void CCL_API_CALL_TYPE CclInit(CCL_CHANNEL_CCLTYPE_ONLY)
#endif
{

#if defined( CCL_ENABLE_INTERNAL_REQUEST)
   vuint8 count;
   count = 0;
#endif

#if defined( CCL_ENABLE_ERROR_HOOK)
   cclChannelNumber = 0; /* init channel number */
   cclErrorCode     = 0; /* init error code */
   cclErrorLine     = 0; /* init error line */
   cclComponentID   = 0; /* init component ID */
#endif


#if defined( CCL_ENABLE_EXTERNAL_REQUEST )
#  if defined( CCL_ENABLE_EMC_WAKEUP )
     /* clear external EMC channel request */
     cclExtEmcWakeUpReq[CCL_CHANNEL_CCLINDEX] = kCclNoExtChWupReq;
#  endif
     /* clear external CAN channel request */
     cclExtCanWakeUpReq[CCL_CHANNEL_CCLINDEX] = kCclNoExtChWupReq;

#    if defined CCL_ENABLE_SLEEP_REPETITION
    cclCanSleepRepetition[CCL_CHANNEL_CCLINDEX] = kCclNoRepeatCanSleep;
#    endif
    cclCanSleepReturnCode[CCL_CHANNEL_CCLINDEX] = kCanOk;
#endif

#if defined(CCL_ENABLE_EXTENDED_INITIALIZATION)
    if( cclInitValue == kCclInitNormal )
    {
      cclNmState[CCL_CHANNEL_CCLINDEX] = kCclNmStateActive;

#if defined( CCL_ENABLE_SW_COM_STATE )
      cclComSwState[CCL_CHANNEL_CCLINDEX] = kCclComSwOn;
#endif

#if defined( CCL_ENABLE_EXTENDED_STATEON )
      cclStateOn[CCL_CHANNEL_CCLINDEX] = kCclCanHwOn;
#endif
    }
    else
#endif
    {
      cclNmState[CCL_CHANNEL_CCLINDEX] = kCclNmStateSleep;

#if defined( CCL_ENABLE_SW_COM_STATE )
       cclComSwState[CCL_CHANNEL_CCLINDEX] = kCclComSwOff;
#endif

#if defined( CCL_ENABLE_EXTENDED_STATEON )
       cclStateOn[CCL_CHANNEL_CCLINDEX] = kCclCanHwOff;
#endif
     }

#if defined(CCL_ENABLE_MULTIPLE_CONFIG)
   if((cclIdChMap[V_ACTIVE_IDENTITY_LOG] & (vuint8)((vuint8)1 << (CCL_CHANNEL_CCLINDEX))) > (vuint8)0x00)
   {
#endif

#if defined( CCL_ENABLE_EXTERNAL_REQUEST )
#  if defined( CCL_ENABLE_EMC_WAKEUP )
#    if defined(CCL_ENABLE_EXTENDED_INITIALIZATION)
     if( cclInitValue == kCclInitNormal)
     {
       CanResetMsgReceivedCondition(CCL_CHANNEL_CANPARA_ONLY);
     }
     else
     {
       CanSetMsgReceivedCondition(CCL_CHANNEL_CANPARA_ONLY);
     }
     
     if( cclInitValue != kCclInitEmc )
     {
       /* start EMC wake up timer */
       cclEmcWakeUpTimer[CCL_CHANNEL_CCLINDEX] = kCclEmcWakeUpTimerStopped;
       cclEmcWakeUpActive[CCL_CHANNEL_CCLINDEX] = kCclEmcWakeUpTimerDeactive;
       cclEmcWakeUpExp[CCL_CHANNEL_CCLINDEX] = kCclEmcWakeUpTimerDeactive;
     }
     else
#    endif
     {
       /* start EMC wake up timer */
       cclEmcWakeUpTimer[CCL_CHANNEL_CCLINDEX] = (vuint8)kCclEmcWakeUpTime;
       cclEmcWakeUpActive[CCL_CHANNEL_CCLINDEX] = kCclEmcWakeUpTimerActive;
       cclEmcWakeUpExp[CCL_CHANNEL_CCLINDEX] = kCclEmcWakeUpTimerRunning;
     }
#  endif
#endif

     /* set communication HW state to enable */
     cclComHwState[CCL_CHANNEL_CCLINDEX] = kCclComHwEnabled;

#if defined(CCL_ENABLE_EXTENDED_INITIALIZATION)
     if( cclInitValue == kCclInitSleep )
     {
       /* set ccl bus state to off */
       cclBusState[CCL_CHANNEL_CCLINDEX] = kCclBusOff;
#if defined(C_ENABLE_APPLCANPREWAKEUP_FCT)
       cclBusTrcvState[CCL_CHANNEL_CCLINDEX] = kCclBusOff;
#endif
     }
     else
#endif
     {
       /* set ccl bus state to on */
       cclBusState[CCL_CHANNEL_CCLINDEX] = kCclBusOn;
#if defined(C_ENABLE_APPLCANPREWAKEUP_FCT)
       cclBusTrcvState[CCL_CHANNEL_CCLINDEX] = kCclBusOn;
#endif
     }

#if defined(CCL_ENABLE_MULTIPLE_CONFIG)
   }
   else
   {
#if defined( CCL_ENABLE_EXTERNAL_REQUEST )
#  if defined( CCL_ENABLE_EMC_WAKEUP )
     /* stop EMC wake up timer */
     cclEmcWakeUpTimer[CCL_CHANNEL_CCLINDEX] = kCclEmcWakeUpTimerStopped;
     cclEmcWakeUpActive[CCL_CHANNEL_CCLINDEX] = kCclEmcWakeUpTimerDeactive;
     cclEmcWakeUpExp[CCL_CHANNEL_CCLINDEX] = kCclEmcWakeUpTimerDeactive;
#  endif
#endif

     /* set communication HW state to disable */
     cclComHwState[CCL_CHANNEL_CCLINDEX] = kCclComHwDisabled;

     /* set ccl bus state to off */
     cclBusState[CCL_CHANNEL_CCLINDEX] = kCclBusOff;

#if defined(C_ENABLE_APPLCANPREWAKEUP_FCT)
       cclBusTrcvState[CCL_CHANNEL_CCLINDEX] = kCclBusOff;
#endif
   }
#endif


#if defined( CCL_ENABLE_INTERNAL_REQUEST )

   {
     {
       for(count=cclStartIndex[CCL_NET_CCLINDEX]; count<=cclStopIndex[CCL_NET_CCLINDEX]; count++)
       {
         /* clear internal network state */
         cclIntNetState[count] = 0x00;
       }

       /* clear internal network request */
       cclIntNetReq[CCL_NET_CCLINDEX] = kCclNoIntNetReq;

       /* clear internal network release */
       cclIntNetRel[CCL_NET_CCLINDEX] = kCclNoIntNetRel;
       cclIntNetRelHistory[CCL_NET_CCLINDEX] = kCclNoIntNetRel;
     }
   }

#if defined(CCL_ENABLE_NET_STATE_RESTRICTION)
   /* clear network management restriction */
   cclNmRestriction[CCL_CHANNEL_CCLINDEX] = kCclNmRestrictionOff;
#endif

#  if defined( CCL_ENABLE_WAKEUP_EV )
   for(count=0; count<4; count++)
   {
     /* init wake up event */
     cclWakeUpEvent[CCL_CHANNEL_CCLINDEX][count] = 0;
   }
#  endif

#endif




#if( CCL_DLL_VERSION < 0x0106 )
#else
   /* check repeated initialisation flag */
#  if defined( CCL_ENABLE_CANBEDDED_HANDLING )
   if(cclStackInit == kCclChannelSpecificInit)
   {
     /* container function for CANbedded "Init" */
#    if(kCclNrOfChannels > 1)
     /* By using the following table of function calls, code-doubled functions 
     * are called from the indexed CCL. This is done to simplify the called 
     * functions (no distinction of the parameter 'channel' is necessary). */
     (CclInitFctTbl[CCL_CHANNEL_CCLINDEX])();
#    else
     CclInitFct();
#    endif

   }
#  endif
#endif
 }

/************************************************************************
| NAME:               CclInitPowerOn
| PROTOTYPE:          void CclInitPowerOn(cclECUHandle handle)
|                     or
|                     void CclInitPowerOn(void)
| CALLED BY:          Application during startup the system or while runtime
| PRECONDITIONS:      global interrupts have to be disabled
| INPUT PARAMETERS:   handle (multiple ECU)
|                     or
|                     void (single ECU)
|                     and/or
|                     cclInitPointer (extended initialization)
| RETURN VALUE:       void
| DESCRIPTION:        system specific initialisation of CCL and CANbedded stack
|*************************************************************************/
#if defined(CCL_ENABLE_EXTENDED_INITIALIZATION)
void CCL_API_CALL_TYPE CclInitPowerOn(CCL_ECUS_NODESTYPE_FIRST const tCclInitParaListType* cclInitPointer)
#else
void CCL_API_CALL_TYPE CclInitPowerOn(CCL_ECUS_NODESTYPE_ONLY)
#endif
 {
#if(kCclNrOfChannels > 1)
   CanChannelHandle channel;
#endif


#if( CCL_DLL_VERSION < 0x0106 )
#else
#  if defined( CCL_ENABLE_CANBEDDED_HANDLING )
   /* clear repeated initialisation flag */
   cclStackInit = kCclSystemSpecificInit;
#  endif
#endif

#if defined( CCL_ENABLE_CANBEDDED_HANDLING )
#  if defined(CCL_ENABLE_MULTIPLE_CONFIG) || defined(CCL_ENABLE_MULTIPLE_NODES_IDM)
   VSetActiveIdentity(CCL_ECUS_NODESPARA_ONLY);
#  endif
#endif

#if(kCclNrOfChannels > 1)
   /* init channel parameters */
   for(channel=0; channel<(CanChannelHandle)kCclNrOfChannels; channel++)
#endif
   {

#if defined ( CCL_ENABLE_EXTENDED_INITIALIZATION )
#  if(kCclNrOfChannels > 1)
     switch (channel)
     {
       case 0:
         CclInit(CCL_CHANNEL_CCLPARA_FIRST cclInitPointer->cclInit_0);
         break;

       case 1:
         CclInit(CCL_CHANNEL_CCLPARA_FIRST cclInitPointer->cclInit_1);
         break;
#    if(kCclNrOfChannels > 2)
       case 2:
         CclInit(CCL_CHANNEL_CCLPARA_FIRST cclInitPointer->cclInit_2);
         break;
#    endif

#    if(kCclNrOfChannels > 3)
       case 3:
         CclInit(CCL_CHANNEL_CCLPARA_FIRST cclInitPointer->cclInit_3);
         break;
#    endif

#    if(kCclNrOfChannels > 4)
       case 4:
         CclInit(CCL_CHANNEL_CCLPARA_FIRST cclInitPointer->cclInit_4);
         break;
#    endif

#    if(kCclNrOfChannels > 5)
       case 5:
         CclInit(CCL_CHANNEL_CCLPARA_FIRST cclInitPointer->cclInit_5);
         break;
#    endif

#    if(kCclNrOfChannels > 6)
       case 6:
         CclInit(CCL_CHANNEL_CCLPARA_FIRST cclInitPointer->cclInit_6);
         break;
#    endif

#    if(kCclNrOfChannels > 7)
       case 7:
         CclInit(CCL_CHANNEL_CCLPARA_FIRST cclInitPointer->cclInit_7);
         break;
#    endif
       default:
         break;
     }
#  else
     CclInit(CCL_CHANNEL_CCLPARA_FIRST cclInitPointer->cclInit_0);
#  endif
#else
     /* init transceiver ports */
     CclInitPorts(CCL_CHANNEL_CCLPARA_ONLY);

     /* init communication control layer */
     CclInit(CCL_CHANNEL_CCLPARA_ONLY);
#endif
   }



#if ( defined( CCL_ENABLE_CANBEDDED_HANDLING ) || defined (CCL_ENABLE_REDUCED_CANBEDDED_HANDLING))
#  if defined(CCL_ENABLE_MULTIPLE_NODES)
   /* set common multiple ECU handle for CAN modules */
   ComSetCurrentECU(CCL_ECUS_NODESPARA_ONLY);
#  endif


   /* container function for CANbedded "InitPowerOn" */
   CclInitPowerOnFct();
#endif

#if defined( CCL_ENABLE_TRCV_PORT_INT )
   CclAssert(cclNmWakeUpAble!=0,kExtAndIntWakeUp);
#endif

#if( CCL_DLL_VERSION < 0x0106 )
#else
#  if defined( CCL_ENABLE_CANBEDDED_HANDLING )
   /* set repeated initialisation flag */
   cclStackInit = kCclChannelSpecificInit;
#  endif
#endif


 }

#if defined( CCL_ENABLE_SYSTEM_STARTUP )
/************************************************************************
| NAME:               CclSystemStartup
| PROTOTYPE:          void CclSystemStartup(void)
| CALLED BY:          Application
| PRECONDITIONS:
| INPUT PARAMETERS:   void
| RETURN VALUE:       void
| DESCRIPTION:        startup handling of CANbedded stack
|*************************************************************************/
void CCL_API_CALL_TYPE CclSystemStartup(void)
 {
#if(kCclNrOfChannels > 1)
   CanChannelHandle channel;

   /* init channel parameters */
   for(channel=0; channel<(CanChannelHandle)kCclNrOfChannels; channel++)
   {
     /* By using the following table of function calls, code-doubled functions 
     * are called from the indexed CCL. This is done to simplify the called 
     * functions (no distinction of the parameter 'channel' is necessary). */

     /* system startup notification */
     (CclSystemStartupFctTbl[CCL_CHANNEL_CCLINDEX])();
   }
#else
   /* system startup notification */
   CclSystemStartupFct();
#endif
 }
#endif


#if defined(CCL_ENABLE_SYSTEM_SHUTDOWN)
/************************************************************************
| NAME:               CclSystemShutdown
| PROTOTYPE:          vuint8 CclSystemShutdown(void)
| CALLED BY:          Application
| PRECONDITIONS:      This function has to be called with disabled global
|                     interrupts.
| INPUT PARAMETERS:   void
| RETURN VALUE:       vuint8
| DESCRIPTION:        shutdown handling of CANbedded stack
|*************************************************************************/
#  if defined( CCL_ENABLE_ADV_SHUTDOWN )
vuint8 CCL_API_CALL_TYPE CclSystemShutdown(void)
#  else
void CCL_API_CALL_TYPE CclSystemShutdown(void)
#  endif
 {
#  if defined( CCL_ENABLE_ADV_SHUTDOWN )
   vuint8 intNetState;
   vuint8 retState;

#    if(kCclNetReqTableSize > 1)
   vuint8 index;
#    endif
#  endif

#  if(kCclNrOfChannels > 1)
   CanChannelHandle channel;
#  endif

#  if defined( CCL_ENABLE_ADV_SHUTDOWN )
   intNetState = 0;
   retState = (vuint8)kCclOk;
#  endif

#  if(kCclNrOfChannels > 1)
   /* init channel parameters */
   for(channel=0; channel<(CanChannelHandle)kCclNrOfChannels; channel++)
#  endif
   {
#  if defined(CCL_ENABLE_MULTIPLE_CONFIG)
     if((cclIdChMap[V_ACTIVE_IDENTITY_LOG] & (vuint8)((vuint8)1 << (CCL_CHANNEL_CCLINDEX))) > (vuint8)0x00)
     {
#  endif
#  if defined( CCL_ENABLE_ADV_SHUTDOWN )
       /* shutdown consistency checks */
       /* check the CAN driver*/
#    if defined(C_ENABLE_EXTENDED_STATUS) && defined(C_ENABLE_SLEEP_WAKEUP)
       if( (CanGetStatus(CCL_CHANNEL_CANPARA_ONLY) & kCclCanDrvCheckMask) != kCclCanDrvCheckMask )
#    else
       if( (CanGetStatus(CCL_CHANNEL_CANPARA_ONLY) & kCanTxOn) != kCclCanDrvCheckMask )
#    endif
       {
         retState = (vuint8)kCclFailed;
       }
       /* check if the network management is in sleep mode */
#    if(kCclNrOfChannels > 1)
       if( CclNmStateCheckFctTbl[CCL_CHANNEL_CCLINDEX]() == kCclNmNotInSleep )
#    else
       if( CclNmStateCheckFct() == kCclNmNotInSleep)
#    endif
       {
         retState = (vuint8)kCclFailed;
       }
       /* check if the CCL is in sleep mode */
       if( cclNmState[CCL_CHANNEL_CCLINDEX] != kCclNmStateSleep )
       {
         retState = (vuint8)kCclFailed;
       }
       /* check if no network request is pending */
#    if defined(CCL_ENABLE_NET_STATE_RESTRICTION)
       if(cclNmRestriction[CCL_CHANNEL_CCLINDEX] == kCclNmRestrictionOff)
#    endif
       {
#    if(kCclNetReqTableSize > 1)
          for(index=cclStartIndex[CCL_CHANNEL_CCLINDEX]; index<=cclStopIndex[CCL_CHANNEL_CCLINDEX]; index++)
          {
            intNetState |= cclIntNetState[index];
          }
#    else
          intNetState = cclIntNetState[0];
#    endif
          if( intNetState != kCclNoNetRequest)
          {
            retState = (vuint8)kCclFailed;
          }
       }
#  endif
#  if defined(CCL_ENABLE_NET_STATE_RESTRICTION)
#    if defined( CCL_ENABLE_ADV_SHUTDOWN )
       else
       {
#    endif
#      if(kCclNrOfChannels > 1)
          /* clear network state restriction */
          cclNmRestriction[CCL_CHANNEL_CCLINDEX] = kCclNmRestrictionOff;  /* ESCAN00011176 and ESCAN00011177 */
#      endif
#    if defined( CCL_ENABLE_ADV_SHUTDOWN )
       }
#    endif
#  endif
     /* By using the following table of function calls, code-doubled functions 
     * are called from the indexed CCL. This is done to simplify the called 
     * functions (no distinction of the parameter 'channel' is necessary). */
#  if(kCclNrOfChannels > 1)
#    if defined( CCL_ENABLE_ADV_SHUTDOWN )
       if(retState == (vuint8)kCclOk)
       {
#    endif
         /* system shutdown notification */
         (CclSystemShutdownFctTbl[CCL_CHANNEL_CCLINDEX])();
#    if defined( CCL_ENABLE_ADV_SHUTDOWN )
       }
#    endif
#  endif
#  if defined(CCL_ENABLE_MULTIPLE_CONFIG)
     }
#  endif
   }
#  if(kCclNrOfChannels > 1)
#  else
#  if defined(CCL_ENABLE_MULTIPLE_CONFIG)
   if((cclIdChMap[V_ACTIVE_IDENTITY_LOG] & (vuint8)((vuint8)1 << (CCL_CHANNEL_CCLINDEX))) > (vuint8)0x00)
   {
#  endif
#    if defined(CCL_ENABLE_NET_STATE_RESTRICTION)
     /* clear network state restriction */
     cclNmRestriction[CCL_CHANNEL_CCLINDEX] = kCclNmRestrictionOff;
#    endif

#    if defined( CCL_ENABLE_ADV_SHUTDOWN )
     /* system shutdown notification */
     if(retState == (vuint8)kCclOk)
     {
#    endif
       CclSystemShutdownFct();
#    if defined( CCL_ENABLE_ADV_SHUTDOWN )
     }
#    endif
#    if defined(CCL_ENABLE_MULTIPLE_CONFIG)
   }
#    endif
#  endif

#  if defined( CCL_ENABLE_ADV_SHUTDOWN )
  return retState;
#  endif
 }
#endif


#if defined(CCL_ENABLE_ERROR_PIN)
/************************************************************************
| NAME:               CclGetErrorPort
| PROTOTYPE:          vuint8 CclGetErrorPort(CanChannelHandle channel)
|                     or
|                     vuint8 CclGetErrorPort(void)
| CALLED BY:          Application
| PRECONDITIONS:
| INPUT PARAMETERS:   channel (multiple channel)
|                     or
|                     void (single channel)
| RETURN VALUE:       state of transceiver error port
| DESCRIPTION:        returns the current error port state from transceiver
|*************************************************************************/
vuint8 CCL_API_CALL_TYPE CclGetErrorPort(CCL_CHANNEL_CCLTYPE_ONLY)
 {
   /* get transceiver error port value */
#if(kCclNrOfChannels > 1)
   /* By using the following table of function calls, code-doubled functions 
   * are called from the indexed CCL. This is done to simplify the called 
   * functions (no distinction of the parameter 'channel' is necessary). */
   if(CclGetTrcvErrorPortFctTbl[CCL_CHANNEL_CCLINDEX] != V_NULL)
   {
     return (CclGetTrcvErrorPortFctTbl[CCL_CHANNEL_CCLINDEX])();
   }
   else
   {
     return kCclNoErrPort;
   }
#  else
   return CclGetTrcvErrorPortFct();
#  endif
 }
#endif


/************************************************************************
| NAME:               CclGetChannelState
| PROTOTYPE:          vuint8 CclGetChannelState(CanChannelHandle channel)
|                     or
|                     vuint8 CclGetChannelState(void)
| CALLED BY:          Application
| PRECONDITIONS:
| INPUT PARAMETERS:   channel (multiple channel)
|                     or
|                     void (single channel)
| RETURN VALUE:       state of CCL (active, go to sleep, sleep)
| DESCRIPTION:        returns the current CCL state
|*************************************************************************/
vuint8 CCL_API_CALL_TYPE CclGetChannelState(CCL_CHANNEL_CCLTYPE_ONLY)
{
  return cclNmState[CCL_CHANNEL_CCLINDEX];
}


#if (defined(CCL_ENABLE_EXTERNAL_REQUEST) &&\
     defined(CCL_ENABLE_TRCV_PORT_INT))
/************************************************************************
| NAME:               CclCanWakeUpInt
| PROTOTYPE:          void CclCanWakeUpInt(CanChannelHandle channel)
|                     or
|                     void CclCanWakeUpInt(void)
| CALLED BY:          WakeUp-ISR "CclCanWakeUpIsr"
| PRECONDITIONS:      external wakeup port INT via RX/INH of CAN transceiver
| INPUT PARAMETERS:   channel (multiple channel)
|                     or
|                     void (single channel)
| RETURN VALUE:       void
| DESCRIPTION:        disable the external wakeup port INT and notify CCL
|*************************************************************************/
void CclCanWakeUpInt(CCL_CHANNEL_CCLTYPE_ONLY)
{
   CclAssert(cclWakeUpIntState[CCL_CHANNEL_CCLINDEX]==kCclDisablePortIRQ, kAssertNotSleepAndTRCVINTactive);

   /* disable transceiver port interrupt */
#  if (kCclNrOfChannels > 1)
   /* By using the following table of function calls, code-doubled functions 
   * are called from the indexed CCL. This is done to simplify the called 
   * functions (no distinction of the parameter 'channel' is necessary). */
   (CclDisableTrcvIntFctTbl[CCL_CHANNEL_CCLINDEX])();
#  else
   CclDisableTrcvIntFct();
#  endif

   /* set INT state to "disable" */
   cclWakeUpIntState[CCL_CHANNEL_CCLINDEX] = kCclDisableWakeUpInt;

   ApplCanWakeUp(CCL_CHANNEL_CANPARA_ONLY);
}
#endif


#if defined( CCL_ENABLE_INTERNAL_REQUEST )
/************************************************************************
| NAME:               CclRequestNetwork
| PROTOTYPE:          void CCL_API_CALL_TYPE CclRequestNetwork(vuint8 channel, vuint8 logNetwork, vuint8 netOffset, vuint8 netMask)
|                     or
|                     void CCL_API_CALL_TYPE CclRequestNetwork(vuint8 logNetwork, vuint8 netOffset, vuint8 netMask)
| CALLED BY:          Application
| PRECONDITIONS:      Not to be called within ISR
| INPUT PARAMETERS:   channel   : channel of requested network (in case of multiple channel)
|                     network   : handle of requested network (only GMLAN-NM)
|                     logNetwork: unique number of requested network (only GMLAN-NM)
|                     netOffset : offset of request/release in bit array
|                     netMask   : mask of request/release in bit array
| RETURN VALUE:       -
| DESCRIPTION:        request the communication on a specific network
|*************************************************************************/
#  if( CCL_DLL_VERSION < 0x0106 )
void CCL_API_CALL_TYPE CclSetNetRequest(CCL_CHANNEL_CCLTYPE_FIRST vuint8 network, vuint8 logNetwork)
#  else
void CCL_API_CALL_TYPE CclRequestNetwork(CCL_CHANNEL_CCLTYPE_FIRST vuint8 network, vuint8 logNetwork, vuint8 netOffset, vuint8 netMask)
#  endif
 {
   vuint8 intNetState;


#  if(kCclNetReqTableSize > 1)
   vuint8 index;
#  endif


   /* ESCAN00010661 
   *  Disable the global interrupt to guarantee data consistency 
   *  if this function is called from interrupt insted of task level. */
   CanGlobalInterruptDisable();

   intNetState = 0;


#  if (kCclNetReqTableSize > 1)
   index    = 0;
#  endif

#  if( CCL_DLL_VERSION < 0x0106 )
#  else
   {
#    if defined(CCL_ENABLE_MULTIPLE_CONFIG)
     if((cclIdChMap[V_ACTIVE_IDENTITY_LOG] & (vuint8)((vuint8)1 << (network))) > (vuint8)0x00)
     {
#endif
         /* check internal network state */
         if((cclIntNetState[netOffset] & netMask) == kCclNoNetRequest)
#  endif
         {
           /* first internal network request? */
#  if(kCclNetReqTableSize > 1)
           for(index=cclStartIndex[network]; index<=cclStopIndex[network]; index++)
           {
             intNetState |= cclIntNetState[index];
           }
#  else
#    if defined ( V_ENABLE_USE_DUMMY_STATEMENT )
           network = network;
#    endif
           intNetState = cclIntNetState[0];
#  endif

#  if( CCL_DLL_VERSION < 0x0106 )
#  else
           /* set internal network state (request) */
           cclIntNetState[netOffset] |= netMask;
#  endif

           if( intNetState == kCclNoNetRequest )
           {


             if(cclNmState[CCL_CHANNEL_CCLINDEX] == kCclNmStateSleep)
             {
#  if defined( CCL_ENABLE_NET_STATE_RESTRICTION )
               /* check network management restriction */
               if((cclNmRestriction[CCL_CHANNEL_CCLINDEX]) == kCclNmRestrictionOff)
#  endif
               {
#  if defined(CCL_ENABLE_TRCV_PORT_INT)
                 /* disable transceiver port interrupt */
#    if(kCclNrOfChannels > 1)
                 /* By using the following table of function calls, code-doubled functions 
                 * are called from the indexed CCL. This is done to simplify the called 
                 * functions (no distinction of the parameter 'channel' is necessary). */
                 (CclDisableTrcvIntFctTbl[CCL_CHANNEL_CCLINDEX])();
#    else
                 CclDisableTrcvIntFct();
#    endif

                 /* set INT state to "disable" */
                 cclWakeUpIntState[CCL_CHANNEL_CCLINDEX] = kCclDisableWakeUpInt;
#  endif


#  if defined(CCL_ENABLE_EXTERNAL_REQUEST)
                 /* clear external network request */
                 cclExtWakeUpReq[CCL_CHANNEL_CCLINDEX] = kCclNoExtChWupReq; /* ESCAN00011217, ESCAN00011218 and ESCAN00012254*/
#  endif
               }
             }

#  if defined( CCL_USE_REQUEST_SETINTCOM_FCT )
#    if defined(CCL_ENABLE_EXTERNAL_REQUEST)
             if( (cclNmState[CCL_CHANNEL_CCLINDEX] == kCclNmStateSleep) || 
                 (cclCanSleepReturnCode[CCL_CHANNEL_CCLINDEX] == kCanFailed) )
#    else
             if( cclNmState[CCL_CHANNEL_CCLINDEX] == kCclNmStateSleep )
#    endif
             {
#    if defined( CCL_ENABLE_NET_STATE_RESTRICTION )
               /* check network management restriction */
               if((cclNmRestriction[CCL_CHANNEL_CCLINDEX]) == kCclNmRestrictionOff)
#    endif
               {
                 /* internal communication request notification */
#    if ( kCclNrOfChannels > 1 )
                 if (CclIntComReqFctTbl[CCL_CHANNEL_CCLINDEX] != V_NULL)
                 {
                   /* By using the following table of function calls, code-doubled functions 
                   * are called from the indexed CCL. This is done to simplify the called 
                   * functions (no distinction of the parameter 'channel' is necessary). */
                   (CclIntComReqFctTbl[CCL_CHANNEL_CCLINDEX])();
                 }
#    else
                 CclIntComReqFct();
#    endif
               }
             }
#  endif

#  if defined(CCL_ENABLE_EXTERNAL_REQUEST)
             /* clear external CAN network request */
             cclExtCanWakeUpReq[CCL_CHANNEL_CCLINDEX] = kCclNoExtChWupReq; /* ESCAN00011500 */
#  endif

             /* clear internal network release */
             cclIntNetRel[CCL_NET_CCLINDEX] = kCclNoIntNetReq;

             /* set internal network request */
             cclIntNetReq[CCL_NET_CCLINDEX] = logNetwork;
           }
         }
#  if( CCL_DLL_VERSION < 0x0106 )
#  else
#    if defined(CCL_ENABLE_MULTIPLE_CONFIG)
     }
#    endif
   }
#  endif

   /* ESCAN00010661 
   *  Enable the global interrupt before leaving the function. */
   CanGlobalInterruptRestore();
}


/************************************************************************
| NAME:               CclReleaseNetwork
| PROTOTYPE:          void CCL_API_CALL_TYPE CclReleaseNetwork(vuint8 channel, vuint8 logNetwork, vuint8 netOffset, vuint8 netMask)
|                     or
|                     void CCL_API_CALL_TYPE CclReleaseNetwork(vuint8 logNetwork, vuint8 netOffset, vuint8 netMask)
| CALLED BY:          Application
| PRECONDITIONS:      Not to be called within ISR
| INPUT PARAMETERS:   channel   : channel of requested network
|                     network   : handle of requested network (only GMLAN-NM)
|                     logNetwork: unique number of requested network (only GMLAN-NM)
|                     netOffset : offset of request/release in bit array
|                     netMask   : mask of request/release in bit array
| RETURN VALUE:       -
| DESCRIPTION:        release the communication on specific network
|*************************************************************************/
#if( CCL_DLL_VERSION < 0x0106 )
void CCL_API_CALL_TYPE CclRelNetRequest(CCL_CHANNEL_CCLTYPE_FIRST vuint8 network, vuint8 logNetwork)
#else
void CCL_API_CALL_TYPE CclReleaseNetwork(CCL_CHANNEL_CCLTYPE_FIRST vuint8 network, vuint8 logNetwork, vuint8 netOffset, vuint8 netMask)
#endif
{
   vuint8 intNetState;
#  if (kCclNetReqTableSize > 1)
   vuint8 index;
#  endif

/* ESCAN00010661 
   *  Disable the global interrupt to guarantee data consistency 
   *  if this function is called from interrupt insted of task level. */
   CanGlobalInterruptDisable();
#  if defined V_ENABLE_USE_DUMMY_STATEMENT
   network = network;            /* dummy assignment to avoid compiler warning */
#  endif

   intNetState = 0;

#  if(kCclNetReqTableSize > 1)
   index    = 0;
#  endif

#  if( CCL_DLL_VERSION < 0x0106 )
#  else
   {
#    if defined(CCL_ENABLE_MULTIPLE_CONFIG)
     if((cclIdChMap[V_ACTIVE_IDENTITY_LOG] & (vuint8)((vuint8)1 << (CCL_CHANNEL_CCLINDEX))) > (vuint8)0x00)
     {
#endif
     /* check internal network state */
     if( (cclIntNetState[netOffset] & netMask) != kCclNoNetRequest )
#  endif
     {
#  if( CCL_DLL_VERSION < 0x0106 )
#  else
       /* clear internal network state (release) */
       cclIntNetState[netOffset] &= (vuint8)(~netMask);
#  endif

     /* last internal network release? */
#  if(kCclNetReqTableSize > 1)
       for(index=cclStartIndex[network]; index<=cclStopIndex[network]; index++)
       {
         intNetState |= cclIntNetState[index];
       }
#  else
       intNetState = cclIntNetState[0];
#  endif

       if(intNetState == kCclNoNetRequest)
       {
#    if defined( CCL_ENABLE_NET_STATE_RESTRICTION )
         /* check network management restriction */
         if((cclNmRestriction[CCL_CHANNEL_CCLINDEX]) == kCclNmRestrictionOff)
#    endif
         {
           if(cclIntNetReq[CCL_NET_CCLINDEX] == kCclNoIntNetReq) /* no internal request is pending */
           {
             /* internal release network */
             cclIntNetRel[CCL_NET_CCLINDEX] = logNetwork;
             cclIntNetRelHistory[CCL_NET_CCLINDEX] = logNetwork;
           }
           else /* internal request is pending*/
           {
             if(cclNmState[CCL_CHANNEL_CCLINDEX] == kCclNmStateSleep) /* ccl state is sleep*/
             {
               /* communication release notification*/
#    if defined(CCL_USE_REQUEST_CLEARCOM_FCT)
#      if(kCclNrOfChannels > 1)
                 if(CclComRelFctTbl[CCL_CHANNEL_CCLINDEX] != V_NULL)
                 {
                   (CclComRelFctTbl[CCL_CHANNEL_CCLINDEX])();
                 }
#      else
                 CclComRelFct();
#      endif
#    endif
               
             }
             else
             {
               if(cclIntNetRelHistory[CCL_NET_CCLINDEX] != kCclNoIntNetRel)
               {
                 /* ESCAN00020286 */
                 /* internal release network */
                 cclIntNetRel[CCL_NET_CCLINDEX] = logNetwork;
               }
             }
           }
         }
         /* clear internal network request */
         cclIntNetReq[CCL_NET_CCLINDEX] = kCclNoIntNetReq; /* ESCAN00011503 */
       }
     }
#  if( CCL_DLL_VERSION < 0x0106 )
#  else
#    if defined(CCL_ENABLE_MULTIPLE_CONFIG)
     }
#endif
   }
#  endif

   /* ESCAN00010661 
   *  Enable the global interrupt before leaving the function. */
   CanGlobalInterruptRestore();
 }


#  if defined(CCL_ENABLE_NET_STATE_RESTRICTION)
/************************************************************************
| NAME:               CclSetNetworkRestriction
| PROTOTYPE:          void CclSetNetworkRestriction(CCL_NET_CCLTYPE_ONLY)  ESCAN00011167
| CALLED BY:          Application
| PRECONDITIONS:      Not to be called within ISR
| INPUT PARAMETERS:   network (multiple network)
|                     or
|                     void (single network)
| RETURN VALUE:       -
| DESCRIPTION:        enable the restriction of the network management state
|                     and force a transition from ACTIVE to GO TO SLEEP
|                     if at least on internal network request is waiting
|*************************************************************************/
void CCL_API_CALL_TYPE CclSetNetworkRestriction(CCL_NET_CCLTYPE_ONLY)
 {
  /*  Disable the global interrupt to guarantee data consistency 
   *  if this function is called from interrupt insted of task level. */
   CanGlobalInterruptDisable();

#if defined(CCL_ENABLE_MULTIPLE_CONFIG)
   if((cclIdChMap[V_ACTIVE_IDENTITY_LOG] & (vuint8)((vuint8)1 << (CCL_CHANNEL_CCLINDEX))) > (vuint8)0x00)
   {
#endif

     /* check network management restriction */
   if(cclNmRestriction[CCL_CHANNEL_CCLINDEX] == kCclNmRestrictionOff)
   {
     /* set network management restriction */
     cclNmRestriction[CCL_CHANNEL_CCLINDEX] = kCclNmRestrictionOn;


#    if defined(CCL_USE_REQUEST_CLEARCOM_FCT)
     /* check network management state */
     if(cclNmState[CCL_CHANNEL_CCLINDEX]==kCclNmStateSleep)
     {
       /* pending internal network request? */
       if(cclIntNetReq[CCL_NET_CCLINDEX] != kCclNoIntNetReq)
       {
         /* communication release notification */
#      if(kCclNrOfChannels > 1)
         if(CclComRelFctTbl[CCL_CHANNEL_CCLINDEX] != V_NULL)
         {
           /* By using the following table of function calls, code-doubled functions 
           * are called from the indexed CCL. This is done to simplify the called 
           * functions (no distinction of the parameter 'channel' is necessary). */
           (CclComRelFctTbl[CCL_CHANNEL_CCLINDEX])();
         }
#      else
         CclComRelFct();
#      endif
       }
     }
#    endif

     /* check network management state */
     if(cclNmState[CCL_CHANNEL_CCLINDEX]==kCclNmStateActive)
     {
       /* set internal network request */
       /* ESCAN00011167:
       *  At least one communication request is active while the network is restricted.
       *  This request is stored here and will be restored after the restriction phase is over. */
       cclIntNetReq[CCL_NET_CCLINDEX] = (vuint8)CCL_NET_CCLINDEX;

       /* set internal network release */
       cclIntNetRel[CCL_NET_CCLINDEX] = (vuint8)CCL_NET_CCLINDEX;
     }
   }

#if defined(CCL_ENABLE_MULTIPLE_CONFIG)
   }
#endif

   /*  Enable the global interrupt before leaving the function. */
   CanGlobalInterruptRestore();
 }

/************************************************************************
| NAME:               CclClearNetworkRestriction
| PROTOTYPE:          void CclClearNetworkRestriction(vuint8 network)
|                     or
|                     void CclClearNetworkRestriction(void)
| CALLED BY:          Application
| PRECONDITIONS:      Not to be called within ISR
| INPUT PARAMETERS:   network (multiple network)
|                     or
|                     void (single network)
| RETURN VALUE:       -
| DESCRIPTION:        enable the restriction of the network management state
|                     and force a transition from SLEEP to ACTIVE
|                     if at least on internal network request is pending
|*************************************************************************/
void CCL_API_CALL_TYPE CclClearNetworkRestriction(CCL_NET_CCLTYPE_ONLY)
 {
  /*  Disable the global interrupt to guarantee data consistency 
   *  if this function is called from interrupt insted of task level. */
   CanGlobalInterruptDisable();

#if defined(CCL_ENABLE_MULTIPLE_CONFIG)
   if((cclIdChMap[V_ACTIVE_IDENTITY_LOG] & (vuint8)((vuint8)1 << (CCL_CHANNEL_CCLINDEX))) > (vuint8)0x00)
   {
#endif

     /* check network management restriction */
   if(cclNmRestriction[CCL_CHANNEL_CCLINDEX] == kCclNmRestrictionOn)
   {
     /* clear network management restriction */
     cclNmRestriction[CCL_NET_CCLINDEX] = kCclNmRestrictionOff;


     /* pending internal network request? */
     if(cclIntNetReq[CCL_NET_CCLINDEX] != kCclNoIntNetRel)
     {
#  if defined(CCL_ENABLE_TRCV_PORT_INT)
       if(cclWakeUpIntState[CCL_CHANNEL_CCLINDEX] == kCclEnableWakeUpInt)
       {
          /* disable transceiver port interrupt */
#    if(kCclNrOfChannels > 1)
          /* By using the following table of function calls, code-doubled functions 
          * are called from the indexed CCL. This is done to simplify the called 
          * functions (no distinction of the parameter 'channel' is necessary). */
          (CclDisableTrcvIntFctTbl[CCL_CHANNEL_CCLINDEX])();
#    else
          CclDisableTrcvIntFct();
#    endif

          /* set INT state to "disable" */
          cclWakeUpIntState[CCL_CHANNEL_CCLINDEX] = kCclDisableWakeUpInt;
       }
#  endif

#    if defined(CCL_USE_REQUEST_SETINTCOM_FCT)
       /* internal communication request notification */
       if(cclNmState[CCL_CHANNEL_CCLINDEX]==kCclNmStateSleep)
       {
#        if(kCclNrOfChannels > 1)
         if (CclIntComReqFctTbl[CCL_CHANNEL_CCLINDEX] != V_NULL)
         {
           /* By using the following table of function calls, code-doubled functions 
           * are called from the indexed CCL. This is done to simplify the called 
           * functions (no distinction of the parameter 'channel' is necessary). */
           (CclIntComReqFctTbl[CCL_CHANNEL_CCLPARA_ONLY])();
         }
#        else
         CclIntComReqFct();
#        endif
       }
#    endif
     }

     /* clear internal network release */
     cclIntNetRel[CCL_NET_CCLINDEX] = kCclNoIntNetRel;
   }

#if defined(CCL_ENABLE_MULTIPLE_CONFIG)
   }
#endif

   /*  Enable the global interrupt before leaving the function. */
   CanGlobalInterruptRestore();
 }

#    if defined( CCL_ENABLE_EMC_WAKEUP )
#      if defined (C_ENABLE_COND_RECEIVE_FCT)
/************************************************************************
| NAME:               ApplCanMsgCondReceived
| PROTOTYPE:          void ApplCanMsgCondReceived(CanRxInfoStructPtr rxStruct)
| CALLED BY:          CAN driver
| PRECONDITIONS:
| INPUT PARAMETERS:   rxStruct
| RETURN VALUE:       -
| DESCRIPTION:        notification about a conditional message reception
|                     to detect a valid CAN message after an EMC wakeup event
|*************************************************************************/
void DRV_API_CALLBACK_TYPE ApplCanMsgCondReceived(NM_MSG_COND_RX_PARAMETER_TYPE NM_MSG_COND_RX_PARAMETER_NAME)
 {

#if defined(C_MULTIPLE_RECEIVE_CHANNEL)
   CanChannelHandle channel;

   channel = NM_MSG_COND_RX_CHANNEL;
#endif


#if defined( C_MULTIPLE_RECEIVE_CHANNEL )  || \
    defined( C_SINGLE_RECEIVE_CHANNEL )
#  if defined( V_ENABLE_USE_DUMMY_STATEMENT )
   /* dummy assignment to avoid compiler warning */
   NM_MSG_COND_RX_PARAMETER_NAME = NM_MSG_COND_RX_PARAMETER_NAME;
#  endif
#endif

#if defined(C_MULTIPLE_RECEIVE_CHANNEL)
#  if( kCclNrOfChannels == 1)
   if(channel == (CanChannelHandle)kCclChannelIndex)
#  endif
#endif
   {
#  if defined(CCL_ENABLE_NET_STATE_RESTRICTION)
     if( (cclIntNetReq[CCL_CHANNEL_CCLINDEX] == kCclNoIntNetReq) ||
         (cclNmRestriction[CCL_CHANNEL_CCLINDEX] == kCclNmRestrictionOn) )  /* ESCAN00011508 */
#  else
     if(cclIntNetReq[CCL_CHANNEL_CCLINDEX] == kCclNoIntNetReq) /* ESCAN00011508 */
#endif
     {

       {

         /* set external CAN network request */
         cclExtCanWakeUpReq[CCL_CHANNEL_CCLINDEX] = kCclExtChWupReq;

#        if defined (CCL_USE_REQUEST_SETEXTCOM_FCT)
         /* external CAN communication request notification */
#          if(kCclNrOfChannels > 1)
         if (CclExtCanComReqFctTbl[CCL_CHANNEL_CCLINDEX] != V_NULL)
         {
           /* By using the following table of function calls, code-doubled functions 
            * are called from the indexed CCL. This is done to simplify the called 
            * functions (no distinction of the parameter 'channel' is necessary). */
           (CclExtCanComReqFctTbl[CCL_CHANNEL_CCLINDEX])();
         }
#          else
         CclExtCanComReqFct();
#          endif
#        endif
       }
     }

   }
     {

#        if defined( CCL_ENABLE_EXTENDED_STATEON )
     /* CAN HW state to on */
     cclStateOn[CCL_CHANNEL_CCLINDEX] = kCclCanHwOn;
#        endif

     /* reject message reception notification */
     CanResetMsgReceivedCondition(CAN_CHANNEL_CANPARA_ONLY); /* ESCAN00032576 */
   }
 }
#      else
#        error "conditional received function must be activated for 'EMC wakeup' algorithm"
#      endif
#    endif
#  endif

#endif /* CCL_ENABLE_INTERNAL_REQUEST */

/************************************************************************
| NAME:               CclEnableCommunication
| PROTOTYPE:          void CclEnableCommunication(vuint8 channel)
|                     or
|                     void CclEnableCommunication(void)
| CALLED BY:          DPM
| PRECONDITIONS:      Not to be called within ISR
| INPUT PARAMETERS:   channel (multiple channel)
|                     or
|                     void (single channel)
| RETURN VALUE:       -
| DESCRIPTION:        enable the HW communication state of CAN controller
|                     CAN transceiver and allow the communication (caused
|                     by external channel and internal network requests)
|*************************************************************************/
void CCL_API_CALL_TYPE CclEnableCommunication(CCL_CHANNEL_CCLTYPE_ONLY)
 {
   /* set HW communication state to enable */
   cclComHwState[CCL_CHANNEL_CCLINDEX] = kCclComHwEnabled;
 }

/************************************************************************
| NAME:               CclDisableCommunication
| PROTOTYPE:          void CclDisableCommunication(vuint8 channel)
|                     or
|                     void CclDisableCommunication(void)
| CALLED BY:          DPM
| PRECONDITIONS:      Not to be called within ISR
| INPUT PARAMETERS:   channel (multiple channel)
|                     or
|                     void (single channel)
| RETURN VALUE:       -
| DESCRIPTION:        disable the HW communication state of CAN controller
|                     CAN transceiver and prevent the communication (caused
|                     by external channel and internal network requests)
|*************************************************************************/
void CCL_API_CALL_TYPE CclDisableCommunication(CCL_CHANNEL_CCLTYPE_ONLY)
 {
   /* set HW communication state to disable */
   cclComHwState[CCL_CHANNEL_CCLINDEX] = kCclComHwDisabled;
 }


#if defined (CCL_ENABLE_TRCV_TYPE_TLE6251G) /* ESCAN00022973 */
/************************************************************************
| NAME:               CclSetTrcvRxOnlyMode
| PROTOTYPE:          void CclSetTrcvRxOnlyMode(CanChannelHandle channel)
| CALLED BY:          Application from task level
| PRECONDITIONS:
| INPUT PARAMETERS:   channel (multiple receive channel)
|                     or
|                     void (single receive channel)
| RETURN VALUE:       kCclTrcvStateChangePerformed
|                     or
|                     kCclTrcvStateChangeNotPerformed
| DESCRIPTION:        informs the CCL to set the transceiver into the receive
|                     only mode
|*************************************************************************/
vuint8 CclSetTrcvRxOnlyMode(CCL_CHANNEL_CCLTYPE_ONLY)
{
  vuint8 retVal;

  retVal = kCclTrcvStateChangePerformed;
  
  /* CCL must be in state Active or GoToSleep: */
  CclAssert( (cclNmState[CCL_CHANNEL_CCLINDEX] > kCclNmStateSleep), kCclErrWrongCclState);

  if(cclNmState[CCL_CHANNEL_CCLINDEX] > kCclNmStateSleep)
  {
#  if(kCclNrOfChannels > 1)
    if (CclSetTrcvRxOnlyModeFctTbl[CCL_CHANNEL_CCLINDEX] != V_NULL)
    {
      /* By using the following table of function calls, code-doubled functions 
      * are called from the indexed CCL. This is done to simplify the called 
      * functions (no distinction of the parameter 'channel' is necessary). */
      (CclSetTrcvRxOnlyModeFctTbl[CCL_CHANNEL_CCLINDEX])();
    }
#  else
    CclSetTrcvRxOnlyModeFct();
#  endif
  }
  else
  {
    retVal = kCclTrcvStateChangeNotPerformed;
  }

  return retVal;
}

/************************************************************************
| NAME:               CclLeaveTrcvRxOnlyMode
| PROTOTYPE:          void CclLeaveTrcvRxOnlyMode(CanChannelHandle channel)
| CALLED BY:          Application from task level
| PRECONDITIONS:
| INPUT PARAMETERS:   channel (multiple receive channel)
|                     or
|                     void (single receive channel)
| RETURN VALUE:       kCclTrcvStateChangePerformed
|                     or
|                     kCclTrcvStateChangeNotPerformed
| DESCRIPTION:        informs the CCL to set the transceiver back to normal mode
|*************************************************************************/
vuint8 CclLeaveTrcvRxOnlyMode(CCL_CHANNEL_CCLTYPE_ONLY)
{ 
  vuint8 retVal;

  retVal = kCclTrcvStateChangePerformed;

  /* CCL must be in state Active or GoToSleep: */
  CclAssert( (cclNmState[CCL_CHANNEL_CCLINDEX] > kCclNmStateSleep), kCclErrWrongCclState);

  if(cclNmState[CCL_CHANNEL_CCLINDEX] > kCclNmStateSleep)
  {
#  if(kCclNrOfChannels > 1)
    if (CclLeaveTrcvRxOnlyModeFctTbl[CCL_CHANNEL_CCLINDEX] != V_NULL)
    {
      /* By using the following table of function calls, code-doubled functions 
      * are called from the indexed CCL. This is done to simplify the called 
      * functions (no distinction of the parameter 'channel' is necessary). */
      (CclLeaveTrcvRxOnlyModeFctTbl[CCL_CHANNEL_CCLINDEX])();
    }
#  else
    CclLeaveTrcvRxOnlyModeFct();
#  endif
  }
  else
  {
    retVal = kCclTrcvStateChangeNotPerformed;
  }

  return retVal;
}
#endif






/****************************************************************************/
/* CCL feature configuration                                                */
/****************************************************************************/
/*  CCL_ENABLE_MULTIPLE_CFG   DISABLED  */
/* CCL_ENABLE_ADV_SHUTDOWN   ENABLED */
/* CCL_ENABLE_ADV_COND_MSG   DISABLED */


/***************************************************************************/
/* Version check                                                           */
/***************************************************************************/
#if (CCL_DC_VERSION != 0x0130)
#  error "CCL DC OEM: incorrect main or sub version"
#endif

#if (CCL_DC_RELEASE_VERSION != 0x28)
#  error "CCL DC OEM: incorrect release version"
#endif

V_MEMROM0 V_MEMROM1 vuint8 V_MEMROM2 kCclMainVersion  =(vuint8)(CCL_DC_VERSION >> 8);
V_MEMROM0 V_MEMROM1 vuint8 V_MEMROM2 kCclSubVersion   =(vuint8)( (CCL_DC_VERSION) & 0xFF);
V_MEMROM0 V_MEMROM1 vuint8 V_MEMROM2 kCclBugFixVersion=(vuint8)( (CCL_DC_RELEASE_VERSION) & 0xFF);
/***************************************************************************/ 
/* Plausibility checks                                                     */ 
/***************************************************************************/
#if defined( NM_TYPE_DBAG_OSEK )
#  if !defined(NM_ENABLE_EXTENDED_CALLBACK)
#    error "No extended callbacks activated in CCL-Layer !!"
#  endif
#endif

#if defined ( VGEN_ENABLE_NM_ASRNMCANWRAPPEREXT )
#  if defined (CCL_ENABLE_NM_COORDINATOR)
#    error "NM Coordinator is not supported by CCL!"
#  endif
#  if defined( CCL_DISABLE_NM_CBD_IF )
#    if ( defined( NM_TYPE_DBAG_OSEK ) || defined( NM_TYPE_NMBASIC ) || defined( NM_TYPE_BASIC ) )
#      error "The CCL does not support NM ASR and NM OSEK or NM BASIC in the same configuration!"
#    endif
#  endif
#endif

#if defined ( VGEN_ENABLE_DPM )
#else
#  error "The CCL does not support configurations without DPM!"
#endif

/***************************************************************************/ 
/* defines                                                                 */ 
/***************************************************************************/
#if defined (VGEN_ENABLE_NM_ASRNMCANWRAPPEREXT)
#  if defined(CCL_DISABLE_NM_CBD_IF)
#    if defined( C_SINGLE_RECEIVE_CHANNEL )
#     define CCL_CBDWRP_CHANNEL_CANPARA_ONLY
#    else
#      if( CANNM_NUMBER_OF_CANNM_CHANNELS == kCanNumberOfChannels )
#        define CCL_CBDWRP_CHANNEL_CANPARA_ONLY         (CanChannelHandle)nmChannelHandle
#      else
#        if ( CANNM_NUMBER_OF_CANNM_CHANNELS == 1 )
#          define CCL_CBDWRP_CHANNEL_CANPARA_ONLY         ((CanChannelHandle)CanNm_NmToCanChannelInd[0])
#        else
#          define CCL_CBDWRP_CHANNEL_CANPARA_ONLY         ((CanChannelHandle)CanNm_NmToCanChannelInd[nmChannelHandle])
#        endif
#     endif
#    endif

#    if (kCclNrOfChannels > 1)
#      if ( CANNM_NUMBER_OF_CANNM_CHANNELS == 1 )
#        define CCL_CBDWRP_CHANNEL_CCLPARA_ONLY  (CanChannelHandle) CanNm_NmToCanChannelInd[0]
#        define CCL_CBDWRP_CHANNEL_INDEX         (CanChannelHandle) CanNm_NmToCanChannelInd[0]
#      else
#        define CCL_CBDWRP_CHANNEL_CCLPARA_ONLY  (CanChannelHandle)nmChannelHandle
#        define CCL_CBDWRP_CHANNEL_INDEX         (CanChannelHandle)nmChannelHandle
#      endif
#    else
#      define CCL_CBDWRP_CHANNEL_CCLPARA_ONLY
#      define CCL_CBDWRP_CHANNEL_INDEX          0
#    endif
#  endif
#endif




/***************************************************************************/
/* callback functions                                                      */
/***************************************************************************/

#if defined( NM_TYPE_DBAG_OSEK )
/************************************************************************
| NAME:                ApplNmCanNormal
| PROTOTYPE:           void ApplNmCanNormal(CanChannelHandle channel)
|                      or
|                      void ApplNmCanNormal(void)
| CALLED BY:           OSEK-NM
| PRECONDITIONS:       state transition to "NORMAL"
| INPUT PARAMETERS:    channel (multiple channel)
|                      or
|                      void (single channel)
| RETURN VALUE:        void
| DESCRIPTION:         set CAN controller and CAN transceiver in NORMAL mode
|                      disable the external wakeup port INT  
|*************************************************************************/
void NM_API_CALLBACK_TYPE ApplNmCanNormal(NM_CHANNEL_APPLTYPE_ONLY)
 {
#  if(kCclNrOfChannels > 1)
#    if defined(NM_ENABLE_INDEXED_NM)
  CclCanNormal(CCL_CHANNEL_CCLPARA_ONLY);
#    else
   CclCanNormal(NM_CAN_CHANNEL);
#    endif
#  else
   CclCanNormal(CCL_CHANNEL_CCLPARA_ONLY);
#  endif
}

/************************************************************************
| NAME:                ApplNmCanSleep
| PROTOTYPE:           void ApplNmCanSleep(CanChannelHandle channel)
|                      or
|                      void ApplNmCanSleep(void)
| CALLED BY:           OSEK-NM
| PRECONDITIONS:       state transition to "GO TO SLEEP"
| INPUT PARAMETERS:    channel (multiple channel)
|                      or
|                      void (single channel)
| RETURN VALUE:        void
| DESCRIPTION:         set CAN controller and CAN transceiver in SLEEP mode
|                      enable the external wakeup port INT
|*************************************************************************/
void NM_API_CALLBACK_TYPE ApplNmCanSleep(NM_CHANNEL_APPLTYPE_ONLY)
 {
#  if(kCclNrOfChannels > 1)
#    if defined(NM_ENABLE_INDEXED_NM)
   CclCanStandby(CCL_CHANNEL_CCLPARA_ONLY);
#    else
   CclCanStandby(NM_CAN_CHANNEL);
#    endif
#  else
   CclCanStandby(CCL_CHANNEL_CCLPARA_ONLY);
#  endif
 }


/************************************************************************
| NAME:                ApplNmBusSleep
| PROTOTYPE:           void ApplNmBusSleep(CanChannelHandle channel)
|                      or
|                      void ApplNmBusSleep(void)
| CALLED BY:           OSEK-NM
| PRECONDITIONS:       state transition to "GO TO SLEEP"
| INPUT PARAMETERS:    channel (multiple channel)
|                      or
|                      void (single channel)
| RETURN VALUE:        void
| DESCRIPTION:         s. ApplNmCanSleep  
|*************************************************************************/
void NM_API_CALLBACK_TYPE ApplNmCanBusSleep(NM_CHANNEL_APPLTYPE_ONLY)
 {
 }


 /************************************************************************
| NAME:               ApplNmBusOff
| PROTOTYPE:          void ApplNmBusOff(CanChannelHandle channel)
|                     or
|                     void ApplNmBusOff(void)
| CALLED BY:          OSEK-NM
| PRECONDITIONS:      event "BusOff"
| INPUT PARAMETERS:   channel (multiple channel)
|                     or
|                     void (single channel)
| RETURN VALUE:       void
| DESCRIPTION:        start CCL busoff handling
|*************************************************************************/
void NM_API_CALLBACK_TYPE ApplNmBusOff(NM_CHANNEL_APPLTYPE_ONLY)
 {
#  if(kCclNrOfChannels > 1)
#    if defined(NM_ENABLE_INDEXED_NM)
   CclBusOffStart(CCL_CHANNEL_CCLPARA_ONLY);
#    else
   CclBusOffStart(NM_CAN_CHANNEL);
#    endif
#  else
   CclBusOffStart(CCL_CHANNEL_CCLPARA_ONLY);
#  endif
 }

/************************************************************************
| NAME:               ApplNmBusOffEnd
| PROTOTYPE:          void ApplNmBusOffEnd(CanChannelHandle channel)
|                     or
|                     void ApplNmBusOffEnd(void)
| CALLED BY:          OSEK-NM
| PRECONDITIONS:      event "BusOff"
| INPUT PARAMETERS:   channel (multiple channel)
|                     or
|                     void (single channel)
| RETURN VALUE:       void
| DESCRIPTION:        stop CCL busoff handling
|*************************************************************************/
void NM_API_CALLBACK_TYPE ApplNmBusOffEnd(NM_CHANNEL_APPLTYPE_ONLY)
 {
#  if(kCclNrOfChannels > 1)
#    if defined(NM_ENABLE_INDEXED_NM)
   CclBusOffEnd(CCL_CHANNEL_CCLPARA_ONLY);
#    else
   CclBusOffEnd(NM_CAN_CHANNEL);
#    endif
#  else
   CclBusOffEnd(CCL_CHANNEL_CCLPARA_ONLY);
#  endif
 }

/************************************************************************
| NAME:               ApplNmBusStart
| PROTOTYPE:          void ApplNmBusStart(CanChannelHandle channel)
|                     or
|                     void ApplNmBusStart(void)
| CALLED BY :         OSEK-NM
| PRECONDITIONS :     enable "extended callbacks"
| INPUT PARAMETERS:   channel (multiple channel)
|                     or
|                     void (single channel)
| RETURN VALUE:       void
| DESCRIPTION:        start communication
|*************************************************************************/
void NM_API_CALLBACK_TYPE ApplNmBusStart(NM_CHANNEL_APPLTYPE_ONLY)
 {
#  if(kCclNrOfChannels > 1)
#    if defined(NM_ENABLE_INDEXED_NM)
   CclComStart(CCL_CHANNEL_CCLPARA_ONLY);
#    else
   CclComStart(NM_CAN_CHANNEL);
#    endif
#  else
   CclComStart(CCL_CHANNEL_CCLPARA_ONLY);
#  endif
 }


/************************************************************************
| NAME:               ApplNmWaitBusSleep
| PROTOTYPE:          void ApplNmWaitBusSleep(CanChannelHandle channel)
|                     or
|                     void ApplNmWaitBusSleep(void)
| CALLED BY :         OSEK-NM
| PRECONDITIONS :     enable "extended callbacks"
| INPUT PARAMETERS:   channel (multiple channel)
|                     or
|                     void (single channel)
| RETURN VALUE :      void
| DESCRIPTION :       start communication
|*************************************************************************/
void NM_API_CALLBACK_TYPE ApplNmWaitBusSleep(NM_CHANNEL_APPLTYPE_ONLY)
 {
#  if(kCclNrOfChannels > 1)
#    if defined(NM_ENABLE_INDEXED_NM)
   CclComStop(CCL_CHANNEL_CCLPARA_ONLY);
#    else
   CclComStop(NM_CAN_CHANNEL);
#    endif
#  else
   CclComStop(CCL_CHANNEL_CCLPARA_ONLY);
#  endif
 }

/************************************************************************
| NAME:               ApplNmWaitBusSleepCancel
| PROTOTYPE:          void ApplNmWaitBusSleepCancel(CanChannelHandle channel)
|                     or
|                     void ApplNmWaitBusSleepCancel(void)
| CALLED BY :         OSEK-NM
| PRECONDITIONS :     enable "extended callbacks"
| INPUT PARAMETERS:   channel (multiple channel)
|                     or
|                     void (single channel)
| RETURN VALUE :      void
| DESCRIPTION :       start communication and notify DPM about
|                     repeated external channel or internal network request
|*************************************************************************/
void NM_API_CALLBACK_TYPE ApplNmWaitBusSleepCancel(NM_CHANNEL_APPLTYPE_ONLY)
 {
#  if defined (CCL_USE_REQUEST_SETEXTCOM_FCT)
   /* external CAN communication request notification */
#    if(kCclNrOfChannels > 1)
#      if defined(NM_ENABLE_INDEXED_NM)
   if (CclIntComReqFctTbl[CCL_CHANNEL_CCLINDEX] != V_NULL)
   {
     (CclIntComReqFctTbl[CCL_CHANNEL_CCLINDEX])(); 
   }
#      else
   if (CclIntComReqFctTbl[NM_CAN_CHANNEL] != V_NULL)
   {
     (CclIntComReqFctTbl[NM_CAN_CHANNEL])(); 
   }
#      endif
#    else
   CclIntComReqFct();
#    endif
#  endif

#  if(kCclNrOfChannels > 1)
#    if defined(NM_ENABLE_INDEXED_NM)
    CclComStart(CCL_CHANNEL_CCLPARA_ONLY);
#    else
    CclComStart(NM_CAN_CHANNEL);
#    endif
#  else
  CclComStart(CCL_CHANNEL_CCLPARA_ONLY);
#  endif
 }

#  if defined ( NM_ENABLE_ASSERTIONS )
#    if defined(CCL_ENABLE_ERROR_HOOK)
/* ESCAN00035214 */
/************************************************************************
| NAME:               ApplNmDirOsekFatalError
| PROTOTYPE:          void ApplNmDirOsekFatalError(vuint8 error)
| CALLED BY:          NM task
| PRECONDITIONS:      -
| INPUT PARAMETERS:   error code
| RETURN VALUE:       void
| DESCRIPTION :       Notifies the CCL about a fatal error in NM Osek
|*************************************************************************/
void NM_API_CALLBACK_TYPE ApplNmDirOsekFatalError( vuint8 error )
{
  CclFatalError(CCL_NO_CHANNEL_INFO_AVAILABLE, (vuint16)error, 0, kComponentNm);
}
#    endif
#  endif
#endif

#if defined( NM_TYPE_NMBASIC ) || defined( NM_TYPE_BASIC )
/************************************************************************
| NAME:               ApplNmBasicBusOffStart
| PROTOTYPE:          void ApplNmBasicBusOffStart(CanChannelHandle channel)
|                     or
|                     void ApplNmBasicBusOffStart(void)
| CALLED BY :         NM Basic
| PRECONDITIONS:      event "BusOff"
| INPUT PARAMETERS:   channel (multiple channel)
|                     or
|                     void (single channel)
| RETURN VALUE:       void
| DESCRIPTION:        start CCL busoff handling
|*************************************************************************/
 void ApplNmBasicBusOffStart(NMBASIC_CHANNEL_NMTYPE_ONLY)
{
#  if(kCclNrOfChannels > 1)
#    if defined(NMBASIC_ENABLE_INDEXED_NM)
   CclBusOffStart(NMBASIC_CHANNEL_NMPARA_ONLY);
#    else
   CclBusOffStart(NMBASIC_CAN_CHANNEL);
#    endif  
#  else
   CclBusOffStart(CCL_CHANNEL_CCLPARA_ONLY);
#  endif
}


/************************************************************************
| NAME:               ApplNmBasicBusOffEnd
| PROTOTYPE:          void ApplNmBasicBusOffEnd(CanChannelHandle channel)
|                     or
|                     void ApplNmBasicBusOffEnd(void)
| CALLED BY :         NM Basic
| PRECONDITIONS:      event "BusOff"
| INPUT PARAMETERS:   channel (multiple channel)
|                     or
|                     void (single channel)
| RETURN VALUE:       void
| DESCRIPTION:        stop CCL busoff handling
|*************************************************************************/
 void ApplNmBasicBusOffEnd(NMBASIC_CHANNEL_NMTYPE_ONLY)
{
#  if(kCclNrOfChannels > 1)
#    if defined(NMBASIC_ENABLE_INDEXED_NM)
   CclBusOffEnd(NMBASIC_CHANNEL_NMPARA_ONLY);
#    else
   CclBusOffEnd(NMBASIC_CAN_CHANNEL);
#    endif
#  else
   CclBusOffEnd(CCL_CHANNEL_CCLPARA_ONLY);
#  endif
}


/************************************************************************
| NAME:               ApplNmBasicEnabledCom
| PROTOTYPE:          void ApplNmBasicEnabledCom(CanChannelHandle channel)
|                     or
|                     void ApplNmBasicEnabledCom(void)
| CALLED BY:          Network management
| PRECONDITIONS:      -
| INPUT PARAMETERS:   channel (multiple channel)
|                     or
|                     void (single channel)
| RETURN VALUE:       void
| DESCRIPTION:        start communication
|*************************************************************************/
 void ApplNmBasicEnabledCom(NMBASIC_CHANNEL_NMTYPE_ONLY)
{
#  if(kCclNrOfChannels > 1)
#    if defined(NMBASIC_ENABLE_INDEXED_NM)
   CclComStart(NMBASIC_CHANNEL_NMPARA_ONLY);
#    else
   CclComStart(NMBASIC_CAN_CHANNEL);
#    endif
#  else
   CclComStart(CCL_CHANNEL_CCLPARA_ONLY);
#  endif
}


/************************************************************************
| NAME:               ApplNmBasicDisabledCom
| PROTOTYPE:          void ApplNmBasicDisabledCom(CanChannelHandle channel)
|                     or
|                     void ApplNmBasicDisabledCom(void)
| CALLED BY:          Network management
| PRECONDITIONS:      -
| INPUT PARAMETERS:   channel (multiple channel)
|                     or
|                     void (single channel)
| RETURN VALUE:       void
| DESCRIPTION:        stop communication
|*************************************************************************/
 void ApplNmBasicDisabledCom(NMBASIC_CHANNEL_NMTYPE_ONLY)
{
#  if(kCclNrOfChannels > 1)
#    if defined(NMBASIC_ENABLE_INDEXED_NM)
   CclComStop(NMBASIC_CHANNEL_NMPARA_ONLY);
#    else
   CclComStop(NMBASIC_CAN_CHANNEL);
#    endif
#  else
   CclComStop(CCL_CHANNEL_CCLPARA_ONLY);
#  endif

}


/************************************************************************
| NAME:               ApplNmBasicSwitchTransceiverOn
| PROTOTYPE:          void ApplNmBasicSwitchTransceiverOn(CanChannelHandle channel)
|                     or
|                     void ApplNmBasicSwitchTransceiverOn(void)
| CALLED BY:          Network management
| PRECONDITIONS:      -
| INPUT PARAMETERS:   channel (multiple channel)
|                     or
|                     void (single channel)
| RETURN VALUE:       void
| DESCRIPTION:        switch the transceiver on
|*************************************************************************/
void ApplNmBasicSwitchTransceiverOn(NMBASIC_CHANNEL_NMTYPE_ONLY)
{
#  if(kCclNrOfChannels > 1)
#    if defined(NMBASIC_ENABLE_INDEXED_NM)
   CclCanNormal(NMBASIC_CHANNEL_NMPARA_ONLY);
#    else
   CclCanNormal(NMBASIC_CAN_CHANNEL);
#    endif
#  else
   CclCanNormal(CCL_CHANNEL_CCLPARA_ONLY);
#  endif
}


/************************************************************************
| NAME:               ApplNmBasicSwitchTransceiverOff
| PROTOTYPE:          void ApplNmBasicSwitchTransceiverOff(CanChannelHandle channel)
|                     or
|                     void ApplNmBasicSwitchTransceiverOff(void)
| CALLED BY:          Network management
| PRECONDITIONS:      -
| INPUT PARAMETERS:   channel (multiple channel)
|                     or
|                     void (single channel)
| RETURN VALUE:       void
| DESCRIPTION:        switch the transceiver off
|*************************************************************************/
vuint8 ApplNmBasicSwitchTransceiverOff(NMBASIC_CHANNEL_NMTYPE_ONLY)
{
#  if(kCclNrOfChannels > 1)
#    if defined(NMBASIC_ENABLE_INDEXED_NM)
   CclCanStandby(NMBASIC_CHANNEL_NMPARA_ONLY);
#    else
   CclCanStandby(NMBASIC_CAN_CHANNEL);
#    endif
#  else
   CclCanStandby(CCL_CHANNEL_CCLPARA_ONLY);
#  endif

   return kCanNotSupported;
}


 #  if defined(NMBASIC_ENABLE_SOFTWARE_CHECK) && defined(CCL_ENABLE_ERROR_HOOK)
/************************************************************************
| NAME:               ApplNmBasicFatalError
| PROTOTYPE:          void ApplNmBasicFatalError(CanChannelHandle channel, vuint8 error)
|                     or
|                     void ApplNmBasicFatalError(vuint8 error)
| CALLED BY :         NM Basic
| PRECONDITIONS:      error occure
| INPUT PARAMETERS:   channel (multiple channel)
|                     or
|                     void (single channel)
| RETURN VALUE:       void
| DESCRIPTION:        call CCL error handler
|*************************************************************************/
void ApplNmBasicFatalError(NMBASIC_CHANNEL_APPLTYPE_FIRST vuint8 error)
{
#    if(kCclNrOfChannels > 1)
#      if defined(NMBASIC_ENABLE_INDEXED_NM)
  CclFatalError(NMBASIC_CHANNEL_NMPARA_FIRST (vuint16)error, 0, kComponentNmBasic);
#      else
  CclFatalError(NMBASIC_CAN_CHANNEL, (vuint16)error, 0, kComponentNmBasic);
#      endif
#    else
  CclFatalError(CCL_NO_CHANNEL_INFO_AVAILABLE, (vuint16)error, 0, kComponentNmBasic);
#    endif
}
#  endif

#endif

#if defined(VGEN_ENABLE_GW_AS_DC)
/************************************************************************
| NAME:               ApplAsRequestChannelPresent
| PROTOTYPE:          vuint8 ApplAsRequestChannelPresent(CanChannelHandle channel)
| CALLED BY:          administrative services
| PRECONDITIONS:      -
| INPUT PARAMETERS:   channel (multiple channel)
| RETURN VALUE:       kCclCanAvailable,
|                     kCclNoCanAvailable
| DESCRIPTION:        
|*************************************************************************/
vuint8 GW_API_CALLBACK_TYPE ApplAsRequestChannelPresent(CanChannelHandle channel)
{
  vuint8 req;
  
  req = kCclNoCanAvailable;

#  if defined(CCL_USE_REQUEST_SETEXTCOM_FCT)
  if(cclNmState[CCL_CHANNEL_CCLINDEX] == kCclNmStateSleep)
  {
    /* ESCAN00039955: synchronous wake up: internal wake up triggered by Gw_Admin_Dc:  */
#    if(kCclNrOfChannels > 1)
    if (CclIntComReqFctTbl[CCL_CHANNEL_CCLINDEX] != V_NULL)
    {
      (CclIntComReqFctTbl[CCL_CHANNEL_CCLINDEX])();
    }
#    else
    CclIntComReqFct();
#    endif
  }
#  endif

  if(cclComHwState[CCL_CHANNEL_CCLINDEX] == kCclComHwEnabled)
  {
    if(cclNmState[CCL_CHANNEL_CCLINDEX] == kCclNmStateSleep)
    {
      /* stop EMC wake up timer */
      cclEmcWakeUpTimer[CCL_CHANNEL_CCLINDEX] = 0;

      /* set CCL state to GO TO SLEEP */
      cclNmState[CCL_CHANNEL_CCLINDEX] = kCclNmStateGoToSleep;

      /* clear external EMC channel request */
      cclExtEmcWakeUpReq[CCL_CHANNEL_CCLINDEX] = kCclNoExtChWupReq;

      /* clear external CAN channel request */
      cclExtCanWakeUpReq[CCL_CHANNEL_CCLINDEX] = kCclNoExtChWupReq;

      /* stop sleep repetition handling */
      cclCanSleepRepetition[CCL_CHANNEL_CCLINDEX] = kCclNoRepeatCanSleep;    
    }

    req = kCclCanAvailable;
  }

  return req;
}
#endif

#if defined ( CCL_ENABLE_ERROR_HOOK )
#  if defined(DCPT_ENABLE_USER_CHECK)
/************************************************************************
| NAME:               ApplDcptFatalError
| PROTOTYPE:          void ApplDcptFatalError(vuint8 errorNumber)
| CALLED BY:          CWM
| PRECONDITIONS:      
| INPUT PARAMETERS:   error code of he DcPt component
| RETURN VALUE:       void
| DESCRIPTION:        Fatal error handling
|*************************************************************************/
void DCPT_API_CALLBACK_TYPE ApplDcptFatalError(vuint8 errorNumber)
{
  CclFatalError(CCL_NO_CHANNEL_INFO_AVAILABLE, (vuint16)errorNumber, 0, kComponentDcPt);
}
#  endif
#endif

#if defined (VGEN_ENABLE_NM_ASRNMCANWRAPPEREXT)
#  if defined(CCL_DISABLE_NM_CBD_IF)
/************************************************************************
| NAME:                ApplCbdWrpNetworkStartIndication
| PROTOTYPE:           void ApplCbdWrpNetworkStartIndication( void ) or
|                      void ApplCbdWrpNetworkStartIndication( const Nm_ChannelHandleType nmChannelHandle )
| CALLED BY:           NM CANbedded Wrapper (task level)
| PRECONDITIONS:
| INPUT PARAMETERS:    nmChannelHandle:  NM channel
| RETURN VALUE:        void
| DESCRIPTION:         Informs the CCL about the event wake up via a NM message
|*************************************************************************/
void ApplCbdWrpNetworkStartIndication( CBDWRP_CHANNEL_APPLTYPE_ONLY )
{
  /* notify DPM and set wake up flag: */
  ApplCanWakeUp(CCL_CBDWRP_CHANNEL_CANPARA_ONLY);
}


/************************************************************************
| NAME:                ApplCbdWrpBusSleep
| PROTOTYPE:           void ApplCbdWrpBusSleep( void ) or
|                      void ApplCbdWrpBusSleep( const Nm_ChannelHandleType nmChannelHandle )
| CALLED BY:           NM CANbedded Wrapper (task level)
| PRECONDITIONS:
| INPUT PARAMETERS:    nmChannelHandle:  NM channel
| RETURN VALUE:        void
| DESCRIPTION:         Set the CAN controller and the CAN transceiver in SLEEP mode
|                      and enables the external wakeup port INT.
|*************************************************************************/
void ApplCbdWrpBusSleep( CBDWRP_CHANNEL_APPLTYPE_ONLY )
{
  CclCanStandby(CCL_CBDWRP_CHANNEL_CCLPARA_ONLY);
}

/************************************************************************
| NAME:                ApplCbdWrpNetStart
| PROTOTYPE:           void ApplCbdWrpNetStart( void )
|                      void ApplCbdWrpNetStart( const Nm_ChannelHandleType channel )
| CALLED BY:           NM CANbedded Wrapper (task level)
| PRECONDITIONS:
| INPUT PARAMETERS:    nmChannelHandle:  NM channel
| RETURN VALUE:        void
| DESCRIPTION:         Set the CAN controller and the CAN transceiver in NORMAL mode
|                      and disable the external wakeup port INT.
|*************************************************************************/
void ApplCbdWrpNetStart( CBDWRP_CHANNEL_APPLTYPE_ONLY )
{
#  if defined(CCL_USE_REQUEST_SETEXTCOM_FCT)
#    if(kCclNrOfChannels > 1)
  if (CclIntComReqFctTbl[CCL_CBDWRP_CHANNEL_INDEX] != V_NULL)
  {
    /* By using the following table of function calls, code-doubled functions 
     * are called from the indexed CCL. This is done to simplify the called 
     * functions (no distinction of the parameter 'channel' is necessary). */
    (CclIntComReqFctTbl[CCL_CBDWRP_CHANNEL_INDEX])();
  }
#    else
  CclIntComReqFct();
#    endif  
#  endif
   
  CclCanNormal(CCL_CBDWRP_CHANNEL_CCLPARA_ONLY);
}

/************************************************************************
| NAME:                ApplCbdWrpEnableCom
| PROTOTYPE:           void ApplCbdWrpEnableCom( void )
|                      void ApplCbdWrpEnableCom( const Nm_ChannelHandleType channel )
| CALLED BY:           NM CANbedded Wrapper (task level)
| PRECONDITIONS:
| INPUT PARAMETERS:    nmChannelHandle:  NM channel
| RETURN VALUE:        void
| DESCRIPTION:         Start the communication via interaction layer.
|*************************************************************************/
void ApplCbdWrpEnableCom( CBDWRP_CHANNEL_APPLTYPE_ONLY )
{
  CclComStart(CCL_CBDWRP_CHANNEL_CCLPARA_ONLY);
}

/************************************************************************
| NAME:                ApplCbdWrpDisableCom
| PROTOTYPE:           void ApplCbdWrpDisableCom( void )
|                      void ApplCbdWrpDisableCom( const Nm_ChannelHandleType channel )
| CALLED BY:           NM CANbedded Wrapper (task level)
| PRECONDITIONS:
| INPUT PARAMETERS:    nmChannelHandle:  NM channel
| RETURN VALUE:        void
| DESCRIPTION:         Stop the communication via interaction layer.
|*************************************************************************/
void ApplCbdWrpDisableCom( CBDWRP_CHANNEL_APPLTYPE_ONLY )
{
  CclComStop(CCL_CBDWRP_CHANNEL_CCLPARA_ONLY);
}


/************************************************************************
| NAME:                ApplCbdWrpNetStop
| PROTOTYPE:           void ApplCbdWrpNetStop( void ) or
|                      void ApplCbdWrpNetStop( const Nm_ChannelHandleType channel )
| CALLED BY:           NM CANbedded Wrapper (task level)
| PRECONDITIONS:
| INPUT PARAMETERS:    nmChannelHandle:  NM channel
| RETURN VALUE:        void
| DESCRIPTION:         s. ApplCbdWrpDisableCom
|*************************************************************************/
void ApplCbdWrpNetStop( CBDWRP_CHANNEL_APPLTYPE_ONLY )
{
}

/************************************************************************
| NAME:                ApplCbdWrpBusOffStart
| PROTOTYPE:           void ApplCbdWrpBusOffStart( void ) or
|                      void ApplCbdWrpBusOffStart( const Nm_ChannelHandleType channel )
| CALLED BY:           NM CANbedded Wrapper (task level)
| PRECONDITIONS:
| INPUT PARAMETERS:    nmChannelHandle:  NM channel
| RETURN VALUE:        void
| DESCRIPTION:         The CCL handles the configured interaction layer in
|                      dependency of the CCL configuration.
|*************************************************************************/
void ApplCbdWrpBusOffStart( CBDWRP_CHANNEL_APPLTYPE_ONLY )
{
  CclBusOffStart(CCL_CBDWRP_CHANNEL_CCLPARA_ONLY);
}

/************************************************************************
| NAME:                ApplCbdWrpBusOffEnd
| PROTOTYPE:           void ApplCbdWrpBusOffEnd( void ) or
|                      void ApplCbdWrpBusOffEnd( const Nm_ChannelHandleType channel )
| CALLED BY:           NM CANbedded Wrapper (task level)
| PRECONDITIONS:
| INPUT PARAMETERS:    nmChannelHandle:  NM channel
| RETURN VALUE:        void
| DESCRIPTION:         The CCL handles the configured interaction layer in
|                      dependency of the CCL configuration.
|*************************************************************************/
void ApplCbdWrpBusOffEnd( CBDWRP_CHANNEL_APPLTYPE_ONLY )
{
  CclBusOffEnd(CCL_CBDWRP_CHANNEL_CCLPARA_ONLY);
}

#    if defined(CBDWRP_ENABLE_ASSERTIONS) && defined(CCL_ENABLE_ERROR_HOOK)
/************************************************************************
| NAME:                ApplCbdWrpFatalError
| PROTOTYPE:           void ApplCbdWrpFatalError( void ) or
|                      void ApplCbdWrpFatalError( const Nm_ChannelHandleType channel )
| CALLED BY:           NM CANbedded Wrapper (task level)
| PRECONDITIONS:
| INPUT PARAMETERS:    nmChannelHandle:  NM channel
| RETURN VALUE:        void
| DESCRIPTION:         Call the CCL error handler
|*************************************************************************/
void ApplCbdWrpFatalError( CBDWRP_CHANNEL_APPLTYPE_FIRST  V_MEMROM1 vuint8 V_MEMROM2 moduleId, V_MEMROM1 vuint8 V_MEMROM2 errorCode )
{
  switch(moduleId)
  {
    case kCbdWrpModuleIdNm:
      CclFatalError(CCL_CBDWRP_CHANNEL_INDEX, (vuint16)errorCode, 0, kComponentNmAsrIf);
      break;

    case kCbdWrpModuleIdCanNm:
      CclFatalError(CCL_CBDWRP_CHANNEL_INDEX, (vuint16)errorCode, 0, kComponentNmAsrCan);
      break;

    case kCbdWrpModuleIdCbdWrp:
      CclFatalError(CCL_CBDWRP_CHANNEL_INDEX, (vuint16)errorCode, 0, kComponentNmCbdWrp);
      break;
  }
}
#    endif
#  endif
#endif

/************   Organi, Version 2.1.16 Vector-Informatik GmbH  ************/
