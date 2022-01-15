/*****************************************************************************
|  File Name: CCL.H 
|
|  Description: Communication Control Layer Header (CORE)
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
| ---------   ----    ------  --------------------------------------------------
| 26.02.02    1.00    Zw      Initial version 
| 02.12.02            Pet     add support for psa
| 2002-12-03  1.01    Pet     add support for Micronas CEVF
| 2003-02-04  1.02    Pet     ESCAN00004878: add support for GMLAN (single receive channel)
| 2003-02-06          Pet     ESCAN00004881: add support for NM JUNIOR
| 2003-03-24  1.03    Pet     version changed
| 2003-04-01  1.04    Pet     ESCAN00005345: separation CCL into core files and OEM extension files
| 2003-06-05  1.05    Pet     CCL DLL version change
| 2003-06-16  1.05.01 Pet     version changed
| 2003-07-25  1.05.02 Pet     version changed
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
| 2004-06-17  1.12    Pet     ESCAN00008082: EMC Wakeup Time in DPM is lower than 500ms
|                             ESCAN00008379: missing datatype in the prototypes of ApplCclVnDeactivated and ApplCclVnActivated
| 2004-07-02  1.13    Pet     ESCAN00008750: wrong assertion check
| 2004-07-30  1.14    Pet     ESCAN00009037: support multiple configurations
|                     Pet     ESCAN00009074: init value of variable "cclNmState"
|                     Pet     ESCAN00009098: support for GMLAN multichannel
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
| 2005-02-18  1.23.00 Bs      only the version number changed in this file
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
| 2009-05-07  1.37.21  Dhf    ESCAN00034925: added extended initialisation
|                             ESCAN00034953: removed precompile check
|                             ESCAN00027774: Compiler Warning in case of missing cast
|                             ESCAN00031836: added else-path to avoid misra warning
| 2010-02-11  1.37.22  Dhf    ESCAN00040416: Emc timeout is too long
| 2010-03-30  1.37.23  Dhf    ESCAN00040721: no changes in this file
|                             ESCAN00041956: no changes in this file
| 2012-06-29  1.37.24  Pet    ESCAN00057750: no changes in this file
|****************************************************************************/


/* Check if information is already included */
#ifndef CCL_H
#define CCL_H

/***************************************************************************/
/* HEADER-FILES (Only those that are needed in this file)                  */ 
/***************************************************************************/
/* System-headerfiles */
#include "ccl_par.h"
#include "ccl_inc.h"   /* Public definitions and types */


/***************************************************************************/ 
/* Include files                                                           */ 
/***************************************************************************/ 

/***************************************************************************/ 
/* Version                  (abcd: Main version ab Sub Version cd )        */ 
/***************************************************************************/ 
#if( CCL__CORE_VERSION != 0x0137)
 #error "CCL core version number are inconsistent!"
#endif

#if( CCL__CORE_RELEASE_VERSION != 0x24)
 #error "CCL core release number are inconsistent!"
#endif


/***************************************************************************/ 
/* Defines                                                                 */ 
/***************************************************************************/ 
#define kCclExtChWupReq           0x01
#define kCclNoExtChWupReq         0xFF

#define kCclNoIntNetReq           0xFF
#define kCclNoIntNetRel           0xFF

#define kCclDisablePortIRQ        0x00
#define kCclEnablePortIRQ         0x01

/***************************************************************************/ 
/* Default switches                                                        */ 
/***************************************************************************/ 


/***************************************************************************/ 
/* Memory qualifier                                                        */ 
/***************************************************************************/ 


/***************************************************************************/ 
/* return values                                                           */ 
/***************************************************************************/ 


/***************************************************************************/ 
/* error codes                                                             */ 
/***************************************************************************/ 


/***************************************************************************/ 
/* macros                                                                  */ 
/***************************************************************************/ 


/***************************************************************************/ 
/* compatibility defines                                                   */ 
/***************************************************************************/ 


/***************************************************************************/ 
/* function prototypes internal                                            */ 
/***************************************************************************/ 


/***************************************************************************/ 
/* data types                                                              */ 
/***************************************************************************/ 



/***************************************************************************/ 
/* External Declarations                                                   */ 
/***************************************************************************/ 


/***************************************************************************/ 
/* Callback functions                                                      */ 
/***************************************************************************/ 


#endif /* ifndef CCL_H */
/************************** end of file ***************************************/ 
/************   Organi, Version 2.1.16 Vector-Informatik GmbH  ************/
