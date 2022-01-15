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

#ifndef SCHM_CANDESC_H
#define SCHM_CANDESC_H

#include "SchM.h"
#include "SchM_Types.h"
#include "SchM_Cfg.h"



#define DESC_ACTIVATION_POINT   ACT_TIMEOUT_EVENT_10MS
#define SCHM_TIMER_OFFSET_DESC    ACT_TIMEOUT_EVENT_10MS




extern const uint8 CANDESC_EXCLUSIVE_AREA;


#define SCHM_CANDESC_ENTER_CRITICAL_SECTION \

#define SCHM_CANDESC_EXIT_CRITICAL_SECTION \

#define SCHM_DESC_ENTER_MAINFUNCTION \

#define SCHM_DESC_EXIT_MAINFUNCTION \




#if defined( __SCHM__ )



SCHM_DEFINE_TIMER(DESC);





const uint8 CANDESC_EXCLUSIVE_AREA = SCHM_EA_SUSPENDALLINTERRUPTS;

#define SCHM_TIMER_INIT_DESC   SCHM_TIMER_INIT(DESC, SCHM_TIMER_OFFSET_DESC)




  

#define SCHM_MAINFUNCTION_DESC  SCHM_MAINFUNCTION(DescTask(), DESC, DESC_ACTIVATION_POINT)




void SchM_Enter_Candesc(uint8 ExclusiveArea)
{
   SCHM_CANDESC_ENTER_CRITICAL_SECTION
#if defined (V_USE_DUMMY_STATEMENT)
# if (V_USE_DUMMY_STATEMENT == STD_ON)
   ExclusiveArea = ExclusiveArea;
# endif
#endif
   SCHM_ENTER_EXCLUSIVE(ExclusiveArea);
}

void SchM_Exit_Candesc(uint8 ExclusiveArea)
{
   SCHM_CANDESC_EXIT_CRITICAL_SECTION
#if defined (V_USE_DUMMY_STATEMENT)
# if (V_USE_DUMMY_STATEMENT == STD_ON)
   ExclusiveArea = ExclusiveArea;
# endif
#endif
   SCHM_EXIT_EXCLUSIVE(ExclusiveArea);
}
#else /* __SCHM__ */


void SchM_Enter_Candesc(uint8 ExclusiveArea);
void SchM_Exit_Candesc(uint8 ExclusiveArea);

#endif /* __SCHM__ */



#endif /* SCHM_TPISO15765_H */

/* STOPSINGLE_OF_MULTIPLE */
/************   Organi, Version 3.9.0 Vector-Informatik GmbH  ************/
