/* STARTSINGLE_OF_MULTIPLE */

/*****************************************************************************
 * Project Name: SysService_AsrSchM
 *    File Name: SchM_Types.h
 *
 *  Description: Configuration of BSW Scheduler
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
 * 2007-02-26  0.02.01  Jk      delete brackets around function in macro SCHM_MAINFUNCTION 
 * 2007-07-06  0.02.02  Jk      change implementation of critical sections 
 *                              the parameter ExlusiveArea will be ignored now
 * 2009-03-26  0.02.03  Jk      ESCAN00033957
 *****************************************************************************/

#ifndef SCHM_TYPES_H
#define SCHM_TYPES_H


#define SCHM_E_OK E_OK

#define SCHM_TIMER(module) \
  SCHM_TIMER_##module

#define SCHM_DEFINE_TIMER(module) \
  uint8 SCHM_TIMER_##module
  
#define SCHM_EXTERN_TIMER(module) \
  extern uint8 SCHM_TIMER_##module

#define SCHM_TIMER_INIT(module, activation) \
  SCHM_TIMER(module) = (activation)

#define SCHM_INIT_TIMER(module) \
  SCHM_TIMER_INIT_##module

#define SCHM_MAINFUNCTION(function, module, activation) \
  if (0 == SCHM_TIMER(module)) {                        \
    function;                                           \
    SCHM_TIMER(module) = (activation);                  \
  }                                                     \
  else {                                                \
    if (0xFF != SCHM_TIMER(module)) {                   \
      SCHM_TIMER(module)--;                             \
    }                                                   \
  }

#define SCHM_MAINFUNCTION_CALL(module) \
   SCHM_MAINFUNCTION_##module

#define SCHM_MAINFUNCTION_ACTIVATE(module, activation)  \
   (SCHM_TIMER(module) = (activation), SCHM_E_OK)

#define SCHM_MAINFUNCTION_CANCEL(module)  \
   (SCHM_TIMER(module) = ACT_DEACTIVATE, SCHM_E_OK)

#define SCHM_EA_SUSPENDALLINTERRUPTS 0

#if defined( VECTOR_POLYSPACE_TEST )
#   define SCHM_ENTER_EXCLUSIVE(ExclusiveArea)
#   define SCHM_EXIT_EXCLUSIVE(ExclusiveArea)
#else /*VECTOR_POLYSPACE_TEST*/
#      define SCHM_ENTER_EXCLUSIVE(ExclusiveArea) \
         SuspendAllInterrupts()

#      define SCHM_EXIT_EXCLUSIVE(ExclusiveArea) \
         ResumeAllInterrupts()
#endif /*VECTOR_POLYSPACE_TEST*/

#endif /* SCHM_TYPES_H */

/* STOPSINGLE_OF_MULTIPLE */
/************   Organi, Version 3.9.0 Vector-Informatik GmbH  ************/
