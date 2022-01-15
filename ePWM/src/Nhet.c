/*****************************************************************************
* Copyright 2010 Nexteer Automotive, All Rights Reserved.
* Nexteer Confidential
*
* Module File Name  : Nhet.c
* Module Description: NHET PWM Driver
* Product           : Gen II Plus - EA3.0
* Author            : Owen Tosh
*****************************************************************************/
/* Version Control:
 * Date Created:      Wed Apr 13 12:17:00 2011
 * %version:          1 %
 * %derived_by:       nzt9hv %
 * %date_modified:    Fri Feb 15 13:37:34 2013 %
 *---------------------------------------------------------------------------------------------------------------------
 * Date      Rev      Author         Change Description                                                        SCR #
 * -------   -------  --------  ---------------------------------------------------------------------------  ----------
 * 04/13/11  1        LWW       Initial Synergy Version
 * 01/27/12  2        JJW       Add NHET 2 Initialization to support Hercules parts
 * 01/31/12  3        OT        Updated to latest FDD (enabled suppression filters)
 * 01/31/12  4        JJW       Changed NHET reg names to match those defined in Nhet.h
 * 04/24/12  5        LWW       Updated NHET1 prescale and suppression filter
 * 07/27/12  6        JJW       HTU init added to support runtime optimization
 *								Global Pwm Control Command structure defined to be used as HTU source buffer 
 * 09/25/12  7		  SAH		Set pwm relay pin(28) to an output. 
 * 02/01/13  8		  Selva		Updates for ePWM
 */


/******************************************************************************
 *  INCLUDES
 ******************************************************************************/
#include "Nhet.h"
#include <string.h> /* provide memset() and memcpy() definitions */  


#define NHET_START_SEC_CODE
#include "MemMap.h"
/*****************************************************************************
  * Name:        Nhet_Init
  * Description: NHET primary initialization  
  * Inputs:      None 
  * Outputs:     None
  *
*****************************************************************************/
FUNC(void, NHET_CODE) Nhet_Init1(void)
{
	
	/* Start initialization of NHET 1 Peripheral */
	NHET1->NHETGCR = 
	(0 <<24) | /* 0: Disable channel disable feature */
	(0 <<18) | /* 0: All masters can read and write the program fields.. */
	(1 <<17) | /* 1: NHET doesn't stop when a software breakpoint is encountered.*/
	(1 <<16) | /* 1: NHET is master */
	(0 << 0);  /* 0: Stop NHET */


	if ((NHET1->NHETGCR & 0x1) == 0)
	{
		/* copy the HET1 program */
		memcpy((void *) &e_HETPROGRAM1_UN, (const void *) HET_INIT1_PST, sizeof(HET_INIT1_PST));
		
		
		NHET1->NHETPFR =					/* Timer Prescale */
			(4 << 8) | /* 7 -> lr=16 */
			(0 << 0);  /* 0 -> hr=1 */
					   /* ts = 16*1 = 16 */
		
		NHET1->NHETINTENAC = 0xFFFFFFFFUL;	/* Disable all interrupts */
		NHET1->NHETEXC1 = 0;					/* Disable exceptions */
		NHET1->NHETPRY = 0;					/* Interrupt priority level 2 */
		NHET1->NHETAND = 0;					/* No channels are AND shared */
		
		NHET1->NHETHRSH =					/* HR (input) Sharing */
			(0 << 15) | /* Do not share ch 30 and 31  */    
			(0 << 14) | /* Do not share ch 28 and 29  */    
			(0 << 13) | /* Do not share ch 26 and 27  */    
			(0 << 12) | /* Do not share ch 24 and 25  */    
			(0 << 11) | /* Do not share ch 22 and 23  */    
			(0 << 10) | /* Do not share ch 20 and 21  */    
			(0 <<  9) | /* Do not share ch 18 and 19  */    
			(0 <<  8) | /* Do not share ch 16 and 17  */    
			(1 <<  7) | /* Share ch 14 and 15  */    
			(1 <<  6) | /* Share ch 12 and 13  */    
			(1 <<  5) | /* Share ch 10 and 11  */          
			(1 <<  4) | /* Share ch 8 and 9  */          
			(0 <<  3) | /* Do not share ch 6 and 7  */
			(1 <<  2) | /* Share ch 4 and 5  */
			(0 <<  1) | /* Do not share ch 2 and 3  */
			(0 <<  0);  /* Do not share ch 0 and 1  */
		
		NHET1->NHETXOR = 0;					/* No channels are XOR shared */
		NHET1->NHETREQENC = 0xFFU;			/* Disable all request lines */
		NHET1->NHETREQDS = 0;				/* Assign request lines to HTU */
		NHET1->NHETDIR = 0;					/* All channels are inputs */
		NHET1->NHETPULDIS = 0;				/* Pull functionality enabled on all channels */
		NHET1->NHETPSL = 0;					/* All channels are set to pull down */
		NHET1->NHETPCR = 0xAU;				/* Disable parity bit mapping, enable parity checking */
		NHET1->NHETPPR = 0;					/* No channels are affected by a parity error */
		
		NHET1->NHETSFPRLD =					/* Set suppression filter to 1.7us */
			(0x0U  << 16) | /* Scaling factor of 1 */
			(0x6U << 0);   /* Counter preload value */
							/* 0x6 * 1 * 12.5ns = 0.075us */
		
		NHET1->NHETSFENA =					/* Enable suppression Filter */
			(1 << 15) | /* Enable on ch 15 */
			(1 << 14) | /* Enable on ch 14 */
			(1 << 13) | /* Enable on ch 13 */
			(1 << 12) | /* Enable on ch 12 */
			(1 << 11) | /* Enable on ch 11 */
			(1 << 10) | /* Enable on ch 10 */
			(1 <<  9) | /* Enable on ch 9 */
			(1 <<  8) | /* Enable on ch 8 */
			(0 <<  7) | /* Disable on ch 7 */
			(0 <<  6) | /* Disable on ch 6 */
			(1 <<  5) | /* Enable on ch 5 */
			(1 <<  4) | /* Enable on ch 4 */
			(0 <<  3) | /* Disable on ch 3 */
			(0 <<  2) | /* Disable on ch 2 */
			(0 <<  1) | /* Disable on ch 1 */
			(0 <<  0);  /* Disable on ch 0 */
		
		NHET1->NHETPINDIS = 0;				/* Output buffer enable is controlled by HETDIR */
		
		
		(NHET1->NHETGCR |= 0x01U); /* Enable NHET */
		NHET1->NHETDIR |= 0x10000000;					/* Enable relay PWM output */

	}
	/* End initialization of NHET 1 Peripheral */

}

#define NHET_STOP_SEC_CODE
#include "MemMap.h"