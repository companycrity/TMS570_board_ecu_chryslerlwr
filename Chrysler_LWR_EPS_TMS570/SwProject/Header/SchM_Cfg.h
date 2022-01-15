/*****************************************************************************
* Copyright 2010 Nexteer Automotive, All Rights Reserved.
* Nexteer Confidential
*
* Module File Name  : EcuStartup.c
* Module Description: AUTOSAR BSW Scheduler Configuration
* Product           : Gen II Plus - EA3.0
* Author            : Jeremy Warmbier
*****************************************************************************/
/*---------------------------------------------------------------------------
* Version Control:
* Date Created:      Thu Nov 11 16:33:22 2010
* %version:          2 %
* %derived_by:       jzh87w %
* %date_modified:    Mon Aug 13 08:49:26 2012 % 
*---------------------------------------------------------------------------*/
#ifndef SCHM_CFG_H
#define SCHM_CFG_H

#  include "Os.h"

#define ACT_DEACTIVATE          0xFF
#if 0
/*value of ACT_TIMEOUT_EVENT_xxMS = xx/SCHM_TASK_CYCLE_TIME - 1 */
#define ACT_TIMEOUT_EVENT_1MS    0u
#define ACT_TIMEOUT_EVENT_5MS    4u
#define ACT_TIMEOUT_EVENT_10MS   9u
#define ACT_TIMEOUT_EVENT_20MS   19u
#define ACT_TIMEOUT_EVENT_50MS   49u
#define ACT_TIMEOUT_EVENT_100MS  99u

 /*the value of SCHM_TASK_CYCLE_TIME defines the SchM_Task cycle time in ms and have to be a integer value
   if this value vas changed the values for ACT_TIMEOUT_EVENT_xxMS above also have to be adapted*/
#define SCHM_TASK_CYCLE_TIME      1
#endif

/*value of ACT_TIMEOUT_EVENT_xxMS = xx/SCHM_TASK_CYCLE_TIME - 1 */
#define ACT_TIMEOUT_EVENT_10MS   0u
#define ACT_TIMEOUT_EVENT_20MS   1u
#define ACT_TIMEOUT_EVENT_50MS   4u
#define ACT_TIMEOUT_EVENT_100MS  9u

 /*the value of SCHM_TASK_CYCLE_TIME defines the SchM_Task cycle time in ms and have to be a integer value
   if this value vas changed the values for ACT_TIMEOUT_EVENT_xxMS above also have to be adapted*/
#define SCHM_TASK_CYCLE_TIME      10

#define SCHM_INTERRUPTLOCKS_AS_FUNCTION    STD_ON

#define SCHM_VERSION_INFO_API   (STD_ON)
#define SCHM_DEV_ERROR_DETECT   (STD_ON)

#endif /* SCHM_CFG_H */

/*****************************************************************************

CHANGE HISTORY:

 Date      Rev      Author         Change Description              SCR #
                                    (MDD Rev & Date)
-------   -------  --------  -----------------------------------  ----------
08/10/12   1.0      SAH      Initial Chrysler creation.
******************************************************************************/
