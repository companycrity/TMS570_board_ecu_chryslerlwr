/* STARTSINGLE_OF_MULTIPLE */


/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  Copyright (c) 2008-2010 by Vector Informatik GmbH.                                             All rights reserved.
 *
 *                Please note, that this file contains example configuration used by the
 *                MICROSAR BSW modules. This code may influence the behaviour of the
 *                MICROSAR BSW modules in principle. Therefore, great care must be taken
 *                to verify the correctness of the implementation.
 *
 *                The contents of the originally delivered files are only examples resp.
 *                implementation proposals. With regard to the fact that these functions
 *                are meant for demonstration purposes only, Vector Informatik's
 *                liability shall be expressly excluded in cases of ordinary negligence,
 *                to the extent admissible by law or statute.
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  SchM_Can.h
 *        Config:  MSR_Autosar_SLP3
 *  Generated at:  Fri Dec  3 11:04:21 2010
 *
 *     Generator:  MICROSAR SchM Generator Version 02.06.03
 *
 *   Description:  Header of BSW Scheduler for Can
 *********************************************************************************************************************/

#ifndef SCHM_DBK_H
#define SCHM_DBK_H

#include "SchM.h"
#include "SchM_Types.h"
#include "SchM_Cfg.h"


#define DBKRX_ACTIVATION_POINT_TASK   ACT_TIMEOUT_EVENT_10MS
#define SCHM_TIMER_OFFSET_DBKRX_TASK    ACT_TIMEOUT_EVENT_10MS

#define DBKTX_ACTIVATION_POINT_TASK   ACT_TIMEOUT_EVENT_10MS
#define SCHM_TIMER_OFFSET_DBKTX_TASK    ACT_TIMEOUT_EVENT_10MS

extern const uint8 DBK_EXCLUSIVE_AREA_0;

#define SCHM_DBK_ENTER_CRITICAL_SECTION \

#define SCHM_DBK_EXIT_CRITICAL_SECTION \

#define SCHM_DBKRX_TASK_ENTER_MAINFUNCTION \

#define SCHM_DBKRX_TASK_EXIT_MAINFUNCTION \

#define SCHM_DBKTX_TASK_ENTER_MAINFUNCTION \

#define SCHM_DBKTX_TASK_EXIT_MAINFUNCTION \

#if defined( __SCHM__ )

SCHM_DEFINE_TIMER(DBKRX);
SCHM_DEFINE_TIMER(DBKTX);
/*
SCHM_DEFINE_TIMER(CAN_BUSOFF);
SCHM_DEFINE_TIMER(CAN_READ);
SCHM_DEFINE_TIMER(CAN_WAKEUP);
SCHM_DEFINE_TIMER(CAN_WRITE);
*/
const uint8 DBK_EXCLUSIVE_AREA_0 = SCHM_EA_SUSPENDALLINTERRUPTS;


/*
#define SCHM_TIMER_INIT_CAN_BUSOFF   SCHM_TIMER_INIT(CAN_BUSOFF, SCHM_TIMER_OFFSET_CAN_BUSOFF)
#define SCHM_TIMER_INIT_CAN_READ   SCHM_TIMER_INIT(CAN_READ, SCHM_TIMER_OFFSET_CAN_READ)
#define SCHM_TIMER_INIT_CAN_WAKEUP   SCHM_TIMER_INIT(CAN_WAKEUP, SCHM_TIMER_OFFSET_CAN_WAKEUP)
#define SCHM_TIMER_INIT_CAN_WRITE   SCHM_TIMER_INIT(CAN_WRITE, SCHM_TIMER_OFFSET_CAN_WRITE)
*/
#define SCHM_TIMER_INIT_DBKRX_TASK   SCHM_TIMER_INIT(DBKRX, SCHM_TIMER_OFFSET_DBKRX_TASK)
#define SCHM_TIMER_INIT_DBKTX_TASK   SCHM_TIMER_INIT(DBKTX, SCHM_TIMER_OFFSET_DBKTX_TASK)
/*#define SCHM_MAINFUNCTION_CAN_BUSOFF  SCHM_MAINFUNCTION(Can_MainFunction_BusOff(), CAN_BUSOFF, CAN_ACTIVATION_POINT_BUSOFF)

#define SCHM_MAINFUNCTION_CAN_READ  SCHM_MAINFUNCTION(Can_MainFunction_Read(), CAN_READ, CAN_ACTIVATION_POINT_READ)

#define SCHM_MAINFUNCTION_CAN_WAKEUP  SCHM_MAINFUNCTION(Can_MainFunction_Wakeup(), CAN_WAKEUP, CAN_ACTIVATION_POINT_WAKEUP)

#define SCHM_MAINFUNCTION_CAN_WRITE  SCHM_MAINFUNCTION(Can_MainFunction_Write(), CAN_WRITE, CAN_ACTIVATION_POINT_WRITE)
*/
#define SCHM_MAINFUNCTION_DBKRX_TASK  SCHM_MAINFUNCTION(dbkRxTask(), DBKRX, DBKRX_ACTIVATION_POINT_TASK) 
#define SCHM_MAINFUNCTION_DBKTX_TASK  SCHM_MAINFUNCTION(dbkTxTask(), DBKTX, DBKTX_ACTIVATION_POINT_TASK)


void SchM_Enter_DBK(uint8 ExclusiveArea)
{
   SCHM_DBK_ENTER_CRITICAL_SECTION
#if defined (V_USE_DUMMY_STATEMENT)
# if (V_USE_DUMMY_STATEMENT == STD_ON)
   ExclusiveArea = ExclusiveArea;
# endif
#endif
   SCHM_ENTER_EXCLUSIVE(ExclusiveArea);
}

void SchM_Exit_DBK(uint8 ExclusiveArea)
{
   SCHM_DBK_EXIT_CRITICAL_SECTION
#if defined (V_USE_DUMMY_STATEMENT)
# if (V_USE_DUMMY_STATEMENT == STD_ON)
   ExclusiveArea = ExclusiveArea;
# endif
#endif
   SCHM_EXIT_EXCLUSIVE(ExclusiveArea);
}
#else /* __SCHM__ */


void SchM_Enter_DBK(uint8 ExclusiveArea);
void SchM_Exit_DBK(uint8 ExclusiveArea);

#endif /* __SCHM__ */

#endif /* SCHM_CAN_H */

/* STOPSINGLE_OF_MULTIPLE */
/************   Organi, Version 3.9.0 Vector-Informatik GmbH  ************/
