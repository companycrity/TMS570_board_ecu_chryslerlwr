/*****************************************************************************
* Copyright 2010 Nexteer Automotive, All Rights Reserved.
* Nexteer Confidential
*
* Module File Name  : Interrupts.h
* Module Description: Interrupts external definitions
* Product           : Gen II Plus - EA3.0
* Author            : Jeremy Warmbier
*****************************************************************************/
/*---------------------------------------------------------------------------
* Version Control:
* Date Created:      Tue Apr 12 14:52:50 2011
* %version:          5 %
* %derived_by:       xz0btk %
* %date_modified:    Mon Jul  8 16:38:01 2013 % 
*---------------------------------------------------------------------------*/
#ifndef INTERRUPTS_H
#define INTERRUPTS_H

FUNC(void, EXCEPTION_HANDLER_CODE) Isr_ESMH(void);
FUNC(void, INTERRUPT_CODE) EnableSysTickInterrupt(void);

FUNC(void, INTERRUPT_CODE) EnableCRCInterrupt(void);
FUNC(void, INTERRUPT_CODE) EnableEeSpiInterrupt(void);

FUNC(void, INTERRUPT_CODE) EnableCanInterrupt(void);
FUNC(void, INTERRUPT_CODE) EnableMtrCtlInterrupt(void);
FUNC(void, INTERRUPT_CODE) EnableEeSpiInterrupt(void);
FUNC(void, INTERRUPT_CODE) EnableESMLInterrupt(void);

FUNC(void, INTERRUPT_CODE) DisableSysTickInterrupt(void);
FUNC(void, INTERRUPT_CODE) DisableMtrCtlInterrupt(void);
FUNC(void, INTERRUPT_CODE) EnableFIQInterrupts(void);
#endif

/*****************************************************************************

CHANGE HISTORY:

 Date      Rev      Author         Change Description              SCR #
-------   -------  --------  -----------------------------------  ----------
04/13/11   1        JJW      Initial Creation
05/31/11   2        LWW      Added FIQ enable function
08/10/12   3        SAH       Added ESML enable, removed Turns counter enable
01/16/13   4        SAH       removed externs
******************************************************************************/
