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
         File:  Wdg_Stub.h
    Component:  Wdg Dummy
       Module:  -
    Generator:  -

  Description:  Wdg dummy implementation
**********************************************************************************************************************/

/* PROG044 */
#ifndef WDG_STUB_H
#define WDG_STUBH

/* Include Files */
#include "Std_Types.h"
#include "WdgIf_Types.h"

/* Function definitions */
extern FUNC(Std_ReturnType,WDG_CODE) Wdg_Stub_SetMode(VAR(WdgIf_ModeType,AUTOMATIC) Mod);/* 0x01 */
extern FUNC(void,WDG_CODE) Wdg_Stub_Trigger(void);/* 0x02 */


#endif /* WDG_STUB_H */
