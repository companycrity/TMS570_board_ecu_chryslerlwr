/* STARTSINGLE_OF_MULTIPLE */


/*****************************************************************************
 * Project Name: SysService_AsrSchM
 *    File Name: SchM_EcuM.h
 *
 *  Description: Header of BSW Scheduler for the EcuM
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
 * 2007-07-09  0.02.02  Jk      Include structure changed
 * 2008-07-24  0.02.03  Krt     Added second exclusive area
 *****************************************************************************/

#ifndef SCHM_ECUM_H
#define SCHM_ECUM_H

#include "SchM.h"
#include "SchM_Types.h"
#include "SchM_Cfg.h"

#define ECUM_ACTIVATION_POINT_0   ACT_TIMEOUT_EVENT_10MS

extern const uint8 ECUM_EXCLUSIVE_AREA_0;
extern const uint8 ECUM_EXCLUSIVE_AREA_1;

#if defined( __SCHM__ )

SCHM_DEFINE_TIMER(ECUM);

const uint8 ECUM_EXCLUSIVE_AREA_0 = SCHM_EA_SUSPENDALLINTERRUPTS;
const uint8 ECUM_EXCLUSIVE_AREA_1 = SCHM_EA_SUSPENDALLINTERRUPTS;

#define SCHM_TIMER_INIT_ECUM    SCHM_TIMER_INIT(ECUM, ECUM_ACTIVATION_POINT_0)
  
#define SCHM_MAINFUNCTION_ECUM  SCHM_MAINFUNCTION(EcuM_MainFunction(), ECUM, ECUM_ACTIVATION_POINT_0)

Std_ReturnType SchM_ActMainFunction_EcuM(uint8 activation)
{
   return SCHM_MAINFUNCTION_ACTIVATE(ECUM, activation);
}

Std_ReturnType SchM_CancelMainFunction_EcuM(uint8 activation)
{
   return SCHM_MAINFUNCTION_CANCEL(ECUM);
}

void SchM_Enter_EcuM(uint8 ExclusiveArea)
{
   SCHM_ENTER_EXCLUSIVE(ExclusiveArea);
}

void SchM_Exit_EcuM(uint8 ExclusiveArea)
{
   SCHM_EXIT_EXCLUSIVE(ExclusiveArea);
}
#else /* __SCHM__ */

SCHM_EXTERN_TIMER(ECUM);

Std_ReturnType SchM_ActMainFunction_EcuM(uint8 activation);
Std_ReturnType SchM_CancelMainFunction_EcuM(uint8 activation);
void SchM_Enter_EcuM(uint8 ExclusiveArea);
void SchM_Exit_EcuM(uint8 ExclusiveArea);
#endif /* __SCHM__ */

#endif /* SCHM_ECUM_H */

/* STOPSINGLE_OF_MULTIPLE */
/************   Organi, Version 3.9.0 Vector-Informatik GmbH  ************/
