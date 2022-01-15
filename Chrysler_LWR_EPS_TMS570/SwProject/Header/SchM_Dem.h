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
 *          File:  SchM_Dem.h
 *        Config:  MSR_Autosar_SLP3
 *  Generated at:  Fri Dec  3 11:04:21 2010
 *
 *     Generator:  MICROSAR SchM Generator Version 02.06.03
 *
 *   Description:  Header of BSW Scheduler for Dem
 *********************************************************************************************************************/

#ifndef SCHM_DEM_H
#define SCHM_DEM_H

#include "SchM.h"
#include "SchM_Types.h"
#include "SchM_Cfg.h"

#define DEM_ACTIVATION_POINT_0   ACT_TIMEOUT_EVENT_10MS
#define SCHM_TIMER_OFFSET_DEM    ACT_TIMEOUT_EVENT_10MS



extern const uint8 DEM_EXCLUSIVE_AREA_0;
extern const uint8 DEM_EXCLUSIVE_AREA_1;
extern const uint8 DEM_EXCLUSIVE_AREA_2;

#define SCHM_DEM_ENTER_CRITICAL_SECTION \

#define SCHM_DEM_EXIT_CRITICAL_SECTION \

#define SCHM_DEM_ENTER_MAINFUNCTION \

#define SCHM_DEM_EXIT_MAINFUNCTION \


#if defined( __SCHM__ )


SCHM_DEFINE_TIMER(DEM);

const uint8 DEM_EXCLUSIVE_AREA_0 = SCHM_EA_SUSPENDALLINTERRUPTS;
const uint8 DEM_EXCLUSIVE_AREA_1 = SCHM_EA_SUSPENDALLINTERRUPTS;
const uint8 DEM_EXCLUSIVE_AREA_2 = SCHM_EA_SUSPENDALLINTERRUPTS;

#define SCHM_TIMER_INIT_DEM   SCHM_TIMER_INIT(DEM, SCHM_TIMER_OFFSET_DEM)

#define SCHM_MAINFUNCTION_DEM  SCHM_MAINFUNCTION(Dem_MainFunction(), DEM, DEM_ACTIVATION_POINT_0)




void SchM_Enter_Dem(uint8 ExclusiveArea)
{
   SCHM_DEM_ENTER_CRITICAL_SECTION
#if defined (V_USE_DUMMY_STATEMENT)
# if (V_USE_DUMMY_STATEMENT == STD_ON)
   ExclusiveArea = ExclusiveArea;
# endif
#endif
   SCHM_ENTER_EXCLUSIVE(ExclusiveArea);
}

void SchM_Exit_Dem(uint8 ExclusiveArea)
{
   SCHM_DEM_EXIT_CRITICAL_SECTION
#if defined (V_USE_DUMMY_STATEMENT)
# if (V_USE_DUMMY_STATEMENT == STD_ON)
   ExclusiveArea = ExclusiveArea;
# endif
#endif
   SCHM_EXIT_EXCLUSIVE(ExclusiveArea);
}
#else /* __SCHM__ */


void SchM_Enter_Dem(uint8 ExclusiveArea);
void SchM_Exit_Dem(uint8 ExclusiveArea);

#endif /* __SCHM__ */

#endif /* SCHM_DEM_H */

/* STOPSINGLE_OF_MULTIPLE */
/************   Organi, Version 3.9.0 Vector-Informatik GmbH  ************/
