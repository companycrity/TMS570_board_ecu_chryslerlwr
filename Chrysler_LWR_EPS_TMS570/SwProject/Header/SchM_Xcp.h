/* STARTSINGLE_OF_MULTIPLE */


/*****************************************************************************
 * Project Name: SysService_AsrSchM
 *    File Name: SchM_Xcp.h
 *
 *  Description: Header of BSW Scheduler for Xcp
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
 * 2008-08-26  0.01.00  Jk      Creation
 *****************************************************************************/

#ifndef SCHM_XCP_H
#define SCHM_XCP_H

#include "SchM.h"
#include "SchM_Types.h"
#include "SchM_Cfg.h"

#define XCP_ACTIVATION_POINT_0   ACT_TIMEOUT_EVENT_10MS

extern const uint8 XCP_EXCLUSIVE_AREA_0;

#define SCHM_XCP_ENTER_CRITICAL_SECTION \

#define SCHM_XCP_EXIT_CRITICAL_SECTION \

#define SCHM_XCP_ENTER_MAINFUNCTION \

#define SCHM_XCP_EXIT_MAINFUNCTION  \


#if defined( __SCHM__ )

SCHM_DEFINE_TIMER(XCP);

const uint8 XCP_EXCLUSIVE_AREA_0 = SCHM_EA_SUSPENDALLINTERRUPTS;

#define SCHM_TIMER_INIT_XCP   SCHM_TIMER_INIT(XCP, XCP_ACTIVATION_POINT_0)
  
#define SCHM_MAINFUNCTION_XCP  SCHM_MAINFUNCTION(XcpBackground(), XCP, XCP_ACTIVATION_POINT_0)

Std_ReturnType SchM_ActMainFunction_Xcp(uint8 activation)
{
   return SCHM_MAINFUNCTION_ACTIVATE(XCP, activation);
}
Std_ReturnType SchM_CancelMainFunction_Xcp(uint8 activation)
{
   return SCHM_MAINFUNCTION_CANCEL(XCP);
}

void SchM_Enter_Xcp(uint8 ExclusiveArea)
{
   SCHM_XCP_ENTER_CRITICAL_SECTION
   SCHM_ENTER_EXCLUSIVE(ExclusiveArea);
}

void SchM_Exit_Xcp(uint8 ExclusiveArea)
{
   SCHM_XCP_EXIT_CRITICAL_SECTION
   SCHM_EXIT_EXCLUSIVE(ExclusiveArea);
}
#else /* __SCHM__ */

SCHM_EXTERN_TIMER(XCP);

Std_ReturnType SchM_ActMainFunction_Xcp(uint8 activation);
Std_ReturnType SchM_CancelMainFunction_Xcp(uint8 activation);

void SchM_Enter_Xcp(uint8 ExclusiveArea);
void SchM_Exit_Xcp(uint8 ExclusiveArea);
#endif /* __SCHM__ */  

#endif /* SCHM_XCP_H */

/* STOPSINGLE_OF_MULTIPLE */
/************   Organi, Version 3.9.0 Vector-Informatik GmbH  ************/
