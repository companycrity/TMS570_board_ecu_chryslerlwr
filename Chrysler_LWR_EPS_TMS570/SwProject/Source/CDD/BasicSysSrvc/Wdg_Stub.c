/**********************************************************************************************************************
  COPYRIGHT
-----------------------------------------------------------------------------------------------------------------------
  Copyright (c) by Vector Informatik GmbH.                                                  All rights reserved.
 
                This software is copyright protected and proprietary to Vector Informatik GmbH.
                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
                All other rights remain with Vector Informatik GmbH.
-----------------------------------------------------------------------------------------------------------------------
  FILE DESCRIPTION
-----------------------------------------------------------------------------------------------------------------------
         File:  Wdg_Stub.c
    Component:  Wdg Dummy
       Module:  -
    Generator:  -

  Description:  Wdg dummy implementation
**********************************************************************************************************************/

/* Include Files */
#include "Wdg_Stub.h"
#include "Dem.h"


/*************************************************************************/
/* Function Name: Wdg_Stub_SetMode                                            */
/*                                                                       */
/* [WDG004]: By choosing one of a limited number of statically configured*/
/* settings (e.g. toggle or window watchdog, different timeout periods)  */
/* the watchdog driver and hardware can be switched between the following*/
/* three different watchdog modes:                                       */
/*     WDGIF_OFF_MODE, WDGIF_SLOW_MODE or WDGIF_FAST_MODE                */
/*                                                                       */
/* - Parameters (in):  WdgIf_ModeType - One of the following statically  */
/*                     configured modes:                                 */
/*                     WDGIF_OFF_MODE, WDGIF_SLOW_MODE or WDGIF_FAST_MODE*/
/* - Parameters (out): None                                              */
/* - Return value:     Std_ReturnType                                    */
/*                                                                       */
/* - Caveats:          None                                              */
/*************************************************************************/
FUNC(Std_ReturnType,WDG_CODE) Wdg_Stub_SetMode(VAR(WdgIf_ModeType,AUTOMATIC) Mode)
{
	VAR(StatusType, AUTOMATIC) tempExit = E_OK;
	return(tempExit);
}



/************************************************************************/
/* Function Name: Wdg_Stub_Trigger                                           */
/*                                                                      */
/*                                                                      */
/* - Parameters (in):  None                                             */
/* - Parameters (out): None                                             */
/* - Return value:     None                                             */
/*                                                                      */
/************************************************************************/
FUNC(void,WDG_CODE) Wdg_Stub_Trigger(void)
{
 
}
