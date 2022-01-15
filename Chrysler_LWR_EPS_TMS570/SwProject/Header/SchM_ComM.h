/* STARTSINGLE_OF_MULTIPLE */


/*****************************************************************************
 * Project Name: SysService_AsrSchM
 *    File Name: SchM_ComM.h
 *
 *  Description: Header of BSW Scheduler for the ComM
 *
 ******************************************************************************
 *               C O P Y R I G H T
 ******************************************************************************
 * Copyright (c) 2008 by Vector Informatik GmbH.      All rights reserved.
 *
 *       Please note, that this file contains example configuration used by the
 *       MICROSAR BSW modules. This code may influence the behaviour of the
 *       MICROSAR BSW modules in principle. Therefore, great care must be taken
 *       to verify the correctness of the implementation.
 *       
 *       The contents of the originally delivered files are only examples resp. 
 *       implementation proposals. With regard to the fact that these functions 
 *       are meant for demonstration purposes only, Vector Informatik's 
 *       liability shall be expressly excluded in cases of ordinary negligence, 
 *       to the extent admissible by law or statute.                            
 *
 ******************************************************************************
 *               A U T H O R   I D E N T I T Y
 ******************************************************************************
 * Initials     Name                      Company
 * ********     *********************     *************************************
 * Om           Oliver Meili              Vector Informatik GmbH
 * Jk           Joachim Kalmbach          Vector Informatik GmbH
 ******************************************************************************
 *               R E V I S I O N   H I S T O R Y
 ******************************************************************************
 * Date        Version  Author  Description
 * **********  *******  ******  ***********************************************
 * 2006-11-14  0.01.00  Om      Creation
 * 2007-01-19  0.02.00  Jk      Code for critical sections added
 * 2007-02-06  0.02.01  Jk      Remove parameter instance in exclusive area functions
 * 2007-03-26  0.02.02  Jk      Code for multi channel ComM added
 * 2007-07-09  0.02.02  Jk      Include structure changed
 *****************************************************************************/

#ifndef SCHM_COMM_H
#define SCHM_COMM_H

#include "SchM.h"
#include "SchM_Types.h"
#include "SchM_Cfg.h"

#define COMM_ACTIVATION_POINT_0   ACT_TIMEOUT_EVENT_10MS

extern const uint8 COMM_EXCLUSIVE_AREA_0;
extern const uint8 COMM_EXCLUSIVE_AREA_1;

#if defined( __SCHM__ )

SCHM_DEFINE_TIMER(COMM);

#if COMM_ACTIVE_CHANNEL > 0
   #define SCHM_COMM_MAINFUNCTION_0    ComM_MainFunction_0()
#else
   #define SCHM_COMM_MAINFUNCTION_0
#endif


#define SCHM_COMM_MAINFUNCTIONS {                                                \
                                   SCHM_COMM_MAINFUNCTION_0;               \
                                }

const uint8 COMM_EXCLUSIVE_AREA_0 = SCHM_EA_SUSPENDALLINTERRUPTS;
const uint8 COMM_EXCLUSIVE_AREA_1 = SCHM_EA_SUSPENDALLINTERRUPTS;

#  define SCHM_TIMER_INIT_COMM     SCHM_TIMER_INIT(COMM, COMM_ACTIVATION_POINT_0)
  
#  define SCHM_MAINFUNCTION_COMM   SCHM_MAINFUNCTION(SCHM_COMM_MAINFUNCTIONS, COMM, COMM_ACTIVATION_POINT_0)

Std_ReturnType SchM_ActMainFunction_ComM(uint8 activation)
{
   return SCHM_MAINFUNCTION_ACTIVATE(COMM, activation);
}

Std_ReturnType SchM_CancelMainFunction_ComM(uint8 activation)
{
   return SCHM_MAINFUNCTION_CANCEL(COMM);
}

void SchM_Enter_ComM(uint8 ExclusiveArea)
{
   SCHM_ENTER_EXCLUSIVE(ExclusiveArea);
}

void SchM_Exit_ComM(uint8 ExclusiveArea)
{
   SCHM_EXIT_EXCLUSIVE(ExclusiveArea);
}
#else /* __SCHM__ */

SCHM_EXTERN_TIMER(COMM);

Std_ReturnType SchM_ActMainFunction_ComM(uint8 activation);
Std_ReturnType SchM_CancelMainFunction_ComM(uint8 activation);
void SchM_Enter_ComM(uint8 ExclusiveArea);
void SchM_Exit_ComM(uint8 ExclusiveArea);
#endif /* __SCHM__ */

#endif /* SCHM_COMM_H */

/* STOPSINGLE_OF_MULTIPLE */
/************   Organi, Version 3.9.0 Vector-Informatik GmbH  ************/
