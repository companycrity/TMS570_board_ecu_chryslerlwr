/*****************************************************************************
* Copyright 2010 Nexteer Automotive, All Rights Reserved.
* Nexteer Confidential
*
* Module File Name  : AppStartup.c
* Module Description: Application Startup Sequence
* Product           : Gen II Plus EA3.0
* Author            : Lucas Wendling
*****************************************************************************/
/* Version Control:
 * Date Created:      Fri May 11 12:17:00 2012
 * %version:          7 %
 * %derived_by:       czgng4 %
 * %date_modified:    Thu Oct  3 16:34:56 2013 %
 *---------------------------------------------------------------------------------------------------------------------
 * Date      Rev      Author         Change Description                                                        SCR #
 * -------   -------  --------  ---------------------------------------------------------------------------  ----------
 * 06/09/12  1        LWW       Initial Version
 * 07/06/12  2        LWW       Updates for conditional compilation, removed data abort function, corrected
 *                              FPAROVR reg value on single bit flash ECC test, updated flashBadECC pointer value,
 *                              DCAN parity test logic changes, added read on FUNCERRADD after flashecc test
 * 09/28/12	 3		  LN		Corrected anomaly 3784 by reading TCRAMs uncorrectable Error Address Register
 * 								after the initialization test causes a fault.									6350
 * 11/29/12  4        LWW       Added WdgResetHandler call
 * 02/14/13  5        LWW       Anomaly correction on ADC parity functions
 * 08/02/13  6        LWW       Anomaly 3689 correction, changes to allow thumb mode compilation
 * 10/03/13  7        LWW       Anomaly 5758 correction
 */

#include "system_regs.h"
#include "esm_regs.h"
#include "efc_regs.h"
#include "stc_regs.h"
#include "pbist_regs.h"
#include "mibspi_regs.h"
#include "n2het_regs.h"
#include "adc_regs.h"
#include "htu_regs.h"
#include "dcan_regs.h"
#include "dma_regs.h"
#include "vim_regs.h"
#include "flash_regs.h"
#include "pcr_regs.h"
#include "tcram_regs.h"
#include "ccm_regs.h"
#include "gio_regs.h"
#include "appinit_cfg.h"
#include "ResetCause.h"
#include "sys_core.h"
#include "uDiag.h"

#if (MIBADC1_PARITY_ENABLE)
static void adc1ParityCheck(void);
#define D_ADC1RAMLOC_CNT_U32		0xFF3E0000U
#define D_ADC1RAMPARLOC_CNT_U32		0xFF3E1000U
#endif

#if (MIBADC2_PARITY_ENABLE)
static void adc2ParityCheck(void);
#define D_ADC2RAMLOC_CNT_U32		0xFF3A0000U
#define D_ADC2RAMPARLOC_CNT_U32		0xFF3A1000U
#endif

#if (DCAN1_PARITY_ENABLE)
static void dcan1ParityCheck(void);
#define D_DCAN1RAMPARLOC_CNT_U32	0xFF1E0010U
#define D_DCAN1RAMLOC_CNT_U32		0xFF1E0000U
#endif

#if (DCAN2_PARITY_ENABLE)
static void dcan2ParityCheck(void);
#define D_DCAN2RAMPARLOC_CNT_U32	0xFF1C0010U
#define D_DCAN2RAMLOC_CNT_U32		0xFF1C0000U
#endif

#if (DCAN3_PARITY_ENABLE)
static void dcan3ParityCheck(void);
#define D_DCAN3RAMPARLOC_CNT_U32	0xFF1A0010U
#define D_DCAN3RAMLOC_CNT_U32		0xFF1A0000U
#endif

#if (MIBSPI1_PARITY_ENABLE)
static void mibspi1ParityCheck(void);
#define D_SPI1RAMPARLOC_CNT_U32		0xFF0E0400U
#define D_SPI1RAMLOC_CNT_U32		0xFF0E0000U
#endif

#if (MIBSPI3_PARITY_ENABLE)
static void mibspi3parityCheck(void);
#define D_SPI3RAMPARLOC_CNT_U32		0xFF0C0400U
#define D_SPI3RAMLOC_CNT_U32		0xFF0C0000U
#endif

#if (MIBSPI5_PARITY_ENABLE)
static void mibspi5ParityCheck(void);
#define D_SPI5RAMPARLOC_CNT_U32		0xFF0A0400U
#define D_SPI5RAMLOC_CNT_U32		0xFF0A0000U
#endif

#if (N2HET1_PARITY_ENABLE)
static void nhet1ParityCheck(void);
#define D_NHET1RAMPARLOC_CNT_U32	0xFF462000U
#define D_NHET1RAMLOC_CNT_U32		0xFF460000U
#endif

#if (N2HET2_PARITY_ENABLE)
static void nhet2parityCheck(void);
#define D_NHET2RAMPARLOC_CNT_U32	0xFF442000U
#define D_NHET2RAMLOC_CNT_U32		0xFF440000U
#endif

#if (N2HET1TU_PARITY_ENABLE)
static void htu1ParityCheck(void);
#define D_HTU1RAMPARLOC_CNT_U32		0xFF4E0200U
#define D_HTU1RAMLOC_CNT_U32		0xFF4E0000U
#endif

#if (N2HET2TU_PARITY_ENABLE)
static void htu2ParityCheck(void);
#define D_HTU2RAMPARLOC_CNT_U32		0xFF4C0200U
#define D_HTU2RAMLOC_CNT_U32		0xFF4C0000U
#endif

#if (VIM_PARITY_ENABLE)
static void vimParityCheck(void);
#define D_VIMRAMPARLOC_CNT_U32		0xFFF82400U
#define D_VIMRAMLOC_CNT_U32			0xFFF82000U
#endif

#if (DMA_PARITY_ENABLE)
static void dmaParityCheck(void);
#define D_DMARAMLOC_CNT_U32			0xFFF80000U
#define D_DMARAMPARLOC_CNT_U32		0xFFF80A00U
#endif

#define D_TCRAMA1BITERROR_CNT_U32	0x08400000
#define D_TCRAMA2BITERROR_CNT_U32 	0x08400010
#define D_TCRAMB1BITERROR_CNT_U32	0x08400008
#define D_TCRAMB2BITERROR_CNT_U32 	0x08400018
#define D_TCRAMA1BIT_CNT_U32		0x08000000
#define D_TCRAMA2BIT_CNT_U32		0x08000010
#define D_TCRAMB1BIT_CNT_U32		0x08000008
#define D_TCRAMB2BIT_CNT_U32		0x08000018
#define D_FLASHBADECC_CNT_U32		0x20000020

static void checkB0RAMECC(void);
static void checkB1RAMECC(void);
static void checkFlashECC(void);
static void DiagFailed(void);
static void AppInit(void);
static void Startup(void);

typedef void (*handler_fptr)(const unsigned char *in, unsigned char *out);

#pragma WEAK(__TI_Handler_Table_Base)
#pragma WEAK(__TI_Handler_Table_Limit)
#pragma WEAK(__TI_CINIT_Base)
#pragma WEAK(__TI_CINIT_Limit)

extern unsigned   __TI_Handler_Table_Base;
extern unsigned   __TI_Handler_Table_Limit;
extern unsigned   __TI_CINIT_Base;
extern unsigned   __TI_CINIT_Limit;
extern unsigned   __TI_PINIT_Base;
extern unsigned   __TI_PINIT_Limit;
extern unsigned * __binit__;

extern void main(void);
extern void AppStartupCallout1(void);
extern void AppStartupCallout2(void);

#pragma INTERRUPT(Startup, RESET)
#pragma INTERRUPT(_c_int00, RESET)
#pragma CODE_STATE(_c_int00, 32);

void _c_int00()
{
	Startup();
}
static void Startup(void)
{
	/* Initialize Application Stack Pointers */
	 _coreInitRegisters_();

	 /* Callout for Application Specific processing */
	 AppStartupCallout1();

	/* Release the MibSPIx modules from local reset.
	 * This will cause the MibSPIx RAMs to get initialized along with the parity memory.
	 */
#if (MIBSPI1_ENABLE)
	mibspiREG1->GCR0 = 0x1;
#endif
#if (MIBSPI3_ENABLE)
	mibspiREG3->GCR0 = 0x1;
#endif
#if (MIBSPI5_ENABLE)
	mibspiREG5->GCR0 = 0x1;
#endif
#if (GIO_ENABLE)
    gioCTRL->GCR0 = 1; /* This is the Offset of the GIO module */
#endif

    if (DEBUGRESET == ResetCause_Cnt_Enum)
    {
    	asm(" B $");
    }

    /* Determine Type of Watchdog Reset */
    if (WDGFAIL == ResetCause_Cnt_Enum)
    {
    	WdgResetHandler();
    }

/***************************** INITIALIZATION STEP 29 ****************************/
	/* Test the CPU ECC mechanism for RAM accesses.
	 * The checkBxRAMECC functions cause deliberate single-bit and double-bit errors in TCRAM accesses
	 * by corrupting 1 or 2 bits in the ECC. Reading from the TCRAM location with a 2-bit error
	 * in the ECC causes a data abort exception. The data abort handler is written to look for
	 * deliberately caused exception and to return the code execution to the instruction
	 * following the one that caused the abort.
	 */

    if (PWRONRESET == ResetCause_Cnt_Enum)
    {
		checkB0RAMECC();
		checkB1RAMECC();

/***************************** INITIALIZATION STEP 30 ****************************/
		/* Test the CPU ECC mechanism for Flash accesses.
		 * The checkFlashECC function uses the flash interface module's diagnostic mode 7
		 * to create single-bit and double-bit errors in CPU accesses to the flash. A double-bit
		 * error on reading from flash causes a data abort exception.
		 * The data abort handler is written to look for deliberately caused exception and
		 * to return the code execution to the instruction following the one that was aborted.
		 *
		 */
		checkFlashECC();
		flashWREG->FDIAGCTRL = 0x000A0007;					/* disable flash diagnostic mode */

/***************************** INITIALIZATION STEP 36A ***************************/

		#if (N2HET1_PARITY_ENABLE)
			nhet1ParityCheck();
		#endif
		#if (N2HET1TU_PARITY_ENABLE)
			htu1ParityCheck();
		#endif
		#if (N2HET2_PARITY_ENABLE)
			nhet2parityCheck();
		#endif
		#if (N2HET2TU_PARITY_ENABLE)
			htu2ParityCheck();
		#endif
		#if (MIBADC1_PARITY_ENABLE)
			adc1ParityCheck();
		#endif
		#if (MIBADC2_PARITY_ENABLE)
			adc2ParityCheck();
		#endif
		#if (DCAN1_PARITY_ENABLE)
			dcan1ParityCheck();
		#endif
		#if (DCAN2_PARITY_ENABLE)
			dcan2ParityCheck();
		#endif
		#if (DCAN3_PARITY_ENABLE)
			dcan3ParityCheck();
		#endif
		#if (VIM_PARITY_ENABLE)
			vimParityCheck();
		#endif
		#if (DMA_PARITY_ENABLE)
			dmaParityCheck();
		#endif

		/***************************** INITIALIZATION STEP 35 ****************************/
		/* Wait for MibSPIx memory initialization to complete */
		#if (MIBSPI1_ENABLE)
			while (mibspiREG1->BUFINIT);
		#endif
		#if (MIBSPI3_ENABLE)
			while (mibspiREG3->BUFINIT);
		#endif
		#if (MIBSPI5_ENABLE)
			while (mibspiREG5->BUFINIT);
		#endif

		/***************************** INITIALIZATION STEP 36B ***************************/
		#if (MIBSPI1_PARITY_ENABLE)
			mibspi1ParityCheck();
		#endif
		#if (MIBSPI3_PARITY_ENABLE)
			mibspi3parityCheck();
		#endif
		#if (MIBSPI5_PARITY_ENABLE)
			mibspi5ParityCheck();
		#endif
    }
	else
	{
		#if (VIM_PARITY_ENABLE)
			VIMPAR->PARCTL = 0x0000000A;
		#endif
		#if (DMA_PARITY_ENABLE)
			DMACTRLREG->DMAPCR = 0x0000000A;
		#endif
		#if (N2HET1_PARITY_ENABLE)
			NHET0->NHETPCR = 0x0000000A;
		#endif
		#if (N2HET1TU_PARITY_ENABLE)
			htuREG1->PCR = 0x0000000A;
		#endif
		#if (N2HET2_PARITY_ENABLE)
			NHET1->NHETPCR = 0x0000000A;
		#endif
		#if (N2HET2TU_PARITY_ENABLE)
			htuREG2->PCR = 0x0000000A;
		#endif
		#if (MIBADC1_PARITY_ENABLE)
			adcREG1->PARCR = 0x0000000A;
		#endif
		#if (MIBADC2_PARITY_ENABLE)
			adcREG2->PARCR = 0x0000000A;
		#endif
		#if (DCAN1_PARITY_ENABLE)
			DCAN1REG->CTL = 0x00002800;
		#endif
		#if (DCAN2_PARITY_ENABLE)
			DCAN2REG->CTL = 0x00002800;
		#endif
		#if (DCAN3_PARITY_ENABLE)
			DCAN3REG->CTL = 0x00002800;
		#endif
		#if (MIBSPI1_PARITY_ENABLE)
			mibspiREG1->MIBSPIE = 0x1;
			mibspiREG1->EDEN = 0xA;
		#endif
		#if (MIBSPI3_PARITY_ENABLE)
			mibspiREG3->MIBSPIE = 0x1;
			mibspiREG3->EDEN = 0xA;
		#endif
		#if (MIBSPI5_PARITY_ENABLE)
			mibspiREG5->MIBSPIE = 0x1;
			mibspiREG5->EDEN = 0xA;
		#endif
	}

    AppInit();

}

#if (VIM_PARITY_ENABLE)
/* Routine to check VIM RAM parity error detection and signaling mechanism */
static void vimParityCheck(void)
{
	volatile uint32 vimramread_Cnt_T_u32;

	VIMPAR->PARCTL = 0x0000010A;				/* Enable parity checking and parity test mode */
	(*(volatile uint32 *)D_VIMRAMPARLOC_CNT_U32) ^= 0x1;					/* flip a bit in the VIM RAM parity location */
	VIMPAR->PARCTL = 0x0000000A;				/* disable parity test mode */

	vimramread_Cnt_T_u32 = *(volatile uint32 *)D_VIMRAMLOC_CNT_U32;					/* cause parity error */

	if (0x1 != VIMPAR->PARFLG)
	{
		ResetCause_Cnt_Enum = VIMPARFLGFAILED;
		ESMREGS->ESMSR1 = 0x8000;		/* clear ESM group1 channel 15 flag */
		*(volatile uint32 *)D_VIMRAMLOC_CNT_U32 = 0U;		/* Nexteer Added: Correct parity error */
		DiagFailed();

	}
	else if (D_VIMRAMLOC_CNT_U32 != VIMPAR->ADDERR)
	{
		ResetCause_Cnt_Enum = VIMPARADDERRFAILED;
		VIMPAR->PARFLG = 0x1;					/* clear VIM RAM parity error flag in VIM */
		ESMREGS->ESMSR1 = 0x8000;		/* clear ESM group1 channel 15 flag */
		*(volatile uint32 *)D_VIMRAMLOC_CNT_U32 = 0U;		/* Nexteer Added: Correct parity error */
		DiagFailed();
	}
	else if (0U == (ESMREGS->ESMSR1 & 0x8000))	/* check if ESM group1 channel 15 is flagged */
	{
		/* VIM RAM parity error was not flagged to ESM. */
		ResetCause_Cnt_Enum = VIMPARESMFAILED;
		VIMPAR->PARFLG = 0x1;					/* clear VIM RAM parity error flag in VIM */
		*(volatile uint32 *)D_VIMRAMLOC_CNT_U32 = 0U;		/* Nexteer Added: Correct parity error */
		DiagFailed();
	}
	else
	{
		VIMPAR->PARFLG = 0x1;					/* clear VIM RAM parity error flag in VIM */
		ESMREGS->ESMSR1 = 0x8000;		/* clear ESM group1 channel 15 flag */
		*(volatile uint32 *)D_VIMRAMLOC_CNT_U32 = 0U;		/* Nexteer Added: Correct parity error */
	}
}
#endif

#if (DMA_PARITY_ENABLE)
/* Routine to check DMA control packet RAM parity error detection and signaling mechanism */
static void dmaParityCheck(void)
{
	volatile uint32 dmaread_Cnt_T_u32;

	DMACTRLREG->DMAPCR = 0x0000010A;					/* Enable parity checking and parity test mode */
	(*(volatile uint32 *)D_DMARAMPARLOC_CNT_U32) ^= 0x1;					/* Flip a bit in DMA RAM parity location */
	DMACTRLREG->DMAPCR = 0x0000000A;					/* Disable parity test mode */

	dmaread_Cnt_T_u32 = *(volatile uint32 *)D_DMARAMLOC_CNT_U32;					/* Cause parity error */

	if (0U == (ESMREGS->ESMSR1 & 0x8))		/* Check if ESM group1 channel 3 is flagged */
	{
		/* DMA RAM parity error was not flagged to ESM. */
		ResetCause_Cnt_Enum = DMAPARESMFAILED;
		DMACTRLREG->DMAPAR = 0x01000000;			/* clear DMA parity error flag in DMA */
		*(volatile uint32 *)D_DMARAMLOC_CNT_U32 = 0U;		/* Nexteer Added: Correct parity error */
		DiagFailed();
	}
	else
	{
		DMACTRLREG->DMAPAR = 0x01000000;			/* clear DMA parity error flag in DMA */
		ESMREGS->ESMSR1 = 0x8;			/* clear ESM group1 channel 3 flag */
		*(volatile uint32 *)D_DMARAMLOC_CNT_U32 = 0U;		/* Nexteer Added: Correct parity error */
	}
}
#endif

#if (N2HET1_PARITY_ENABLE)
static void nhet1ParityCheck(void)
{
	volatile uint32 nhetread_Cnt_T_u32;

	NHET0->NHETPCR = 0x0000010A;			/* Set TEST mode and enable parity checking */
	(*(volatile uint32 *)D_NHET1RAMPARLOC_CNT_U32) ^= 0x1;					/* flip parity bit */
	NHET0->NHETPCR = 0x0000000A;			/* Disable TEST mode */

	nhetread_Cnt_T_u32 = *(volatile uint32 *)D_NHET1RAMLOC_CNT_U32;					/* read to cause parity error */

	if (0U == (ESMREGS->ESMSR1 & 0x80))		/* check if ESM group1 channel 7 is flagged */
	{
		/* NHET1 RAM parity error was not flagged to ESM. */
		ResetCause_Cnt_Enum = N2HET1PARESMFAILED;
		*(volatile uint32 *)D_NHET1RAMLOC_CNT_U32 = 0U;		/* Nexteer Added: Correct parity error */
		DiagFailed();
	}
	else
	{
		ESMREGS->ESMSR1 = 0x80;			/* clear ESM group1 channel 7 flag */
		*(volatile uint32 *)D_NHET1RAMLOC_CNT_U32 = 0U;		/* Nexteer Added: Correct parity error */
	}
}
#endif

#if (N2HET1TU_PARITY_ENABLE)
static void htu1ParityCheck(void)
{
	volatile uint32 hturead_Cnt_T_u32;

	htuREG1->PCR = 0x0000010A;				/* Enable parity and TEST mode */
	(*(volatile uint32 *)D_HTU1RAMPARLOC_CNT_U32) ^= 0x1;						/* flip parity bit */
	htuREG1->PCR = 0x0000000A;				/* Disable parity RAM test mode */

	hturead_Cnt_T_u32 = *(volatile uint32 *)D_HTU1RAMLOC_CNT_U32;					/* read to cause parity error */

	if (0U == (ESMREGS->ESMSR1 & 0x100))		/* check if ESM group1 channel 8 is flagged */
	{
		/* HTU1 RAM parity error was not flagged to ESM. */
		ResetCause_Cnt_Enum = N2HET1TUPARESMFAILED;
		htuREG1->PAR = 0x00010000;			/* Clear HTU parity error flag */
		*(volatile uint32 *)D_HTU1RAMLOC_CNT_U32 = 0U;		/* Nexteer Added: Correct parity error */
		DiagFailed();
	}
	else
	{
		htuREG1->PAR = 0x00010000;			/* Clear HTU parity error flag */
		ESMREGS->ESMSR1 = 0x100;
		*(volatile uint32 *)D_HTU1RAMLOC_CNT_U32 = 0U;		/* Nexteer Added: Correct parity error */
	}

}
#endif

#if (N2HET2_PARITY_ENABLE)
static void nhet2parityCheck(void)
{
	volatile uint32 nhetread_Cnt_T_u32;

	NHET1->NHETPCR = 0x0000010A;			/* Set TEST mode and enable parity checking */
	(*(volatile uint32 *)D_NHET2RAMPARLOC_CNT_U32) ^= 0x1;					/* flip parity bit */
	NHET1->NHETPCR = 0x0000000A;			/* Disable TEST mode */

	nhetread_Cnt_T_u32 = *(volatile uint32 *)D_NHET2RAMLOC_CNT_U32;					/* read to cause parity error */

	if ((0U == (ESMREGS->ESMSR1 & 0x80)) && (0U == (ESMREGS->ESTATUS4[0] & 0x4)))		/* check if ESM group1 channel 7 or 34 is flagged */
	{
		/* NHET2 RAM parity error was not flagged to ESM. */
		ResetCause_Cnt_Enum = N2HET2PARESMFAILED;
		*(volatile uint32 *)D_NHET2RAMLOC_CNT_U32 = 0U;		/* Nexteer Added: Correct parity error */
		DiagFailed();
	}
	else
	{
		ESMREGS->ESMSR1 = 0x80;			/* clear ESM group1 channel 7 flag */
		ESMREGS->ESTATUS4[0] = 0x4;			/* clear ESM group1 channel 34 flag */
		*(volatile uint32 *)D_NHET2RAMLOC_CNT_U32 = 0U;		/* Nexteer Added: Correct parity error */
	}
}
#endif

#if (N2HET2TU_PARITY_ENABLE)
static void htu2ParityCheck(void)
{
	volatile uint32 hturead_Cnt_T_u32;

	htuREG2->PCR = 0x0000010A;				/* Enable parity and TEST mode */
	(*(volatile uint32 *)D_HTU2RAMPARLOC_CNT_U32) ^= 0x1;						/* flip parity bit */
	htuREG2->PCR = 0x0000000A;				/* Disable parity RAM test mode */

	hturead_Cnt_T_u32 = *(volatile uint32 *)D_HTU2RAMLOC_CNT_U32;					/* read to cause parity error */

	if (0U == (ESMREGS->ESMSR1 & 0x100))		/* check if ESM group1 channel 8 is flagged */
	{
		/* HTU2 RAM parity error was not flagged to ESM. */
		ResetCause_Cnt_Enum = N2HET2TUPARESMFAILED;
		htuREG2->PAR = 0x00010000;			/* Clear HTU parity error flag */
		*(volatile uint32 *)D_HTU2RAMLOC_CNT_U32 = 0U;		/* Nexteer Added: Correct parity error */
		DiagFailed();
	}
	else
	{
		htuREG2->PAR = 0x00010000;			/* Clear HTU parity error flag */
		ESMREGS->ESMSR1 = 0x100;
		*(volatile uint32 *)D_HTU2RAMLOC_CNT_U32 = 0U;		/* Nexteer Added: Correct parity error */
	}

}
#endif

#if (MIBADC1_PARITY_ENABLE)
static void adc1ParityCheck(void)
{
	volatile uint32 adcramread_Cnt_T_u32;

	adcREG1->PARCR = 0x0000010A;					/* Set the TEST bit in the PARCR and enable parity checking */
	(*(volatile uint32 *)D_ADC1RAMPARLOC_CNT_U32) ^= 0x1;	/* flip parity bit */
	adcREG1->PARCR = 0x0000000A;					/* clear the TEST bit */

	adcramread_Cnt_T_u32 = *(volatile uint32 *)D_ADC1RAMLOC_CNT_U32;					/* This read is expected to trigger a parity error */

	adcREG1->PARCR = 0x0000010A;					/* Set the TEST bit in the PARCR and enable parity checking */
	(*(volatile uint32 *)D_ADC1RAMPARLOC_CNT_U32) ^= 0x1;	/* flip parity bit to correct error */
	adcREG1->PARCR = 0x0000000A;					/* clear the TEST bit */

	if (0U == (ESMREGS->ESMSR1 & 0x80000))	/* Check for ESM group1 channel 19 to be flagged */
	{
		/* no ADC1 RAM parity error was flagged to ESM */
		ResetCause_Cnt_Enum = MIBADC1PARESMFAILED;
		DiagFailed();
	}
	else
	{
		ESMREGS->ESMSR1 = 0x80000;		/* clear ADC1 RAM parity error flag */
	}
}
#endif

#if (MIBADC2_PARITY_ENABLE)
static void adc2ParityCheck(void)
{
	volatile uint32 adcramread_Cnt_T_u32;

	adcREG2->PARCR = 0x0000010A;					/* Set the TEST bit in the PARCR and enable parity checking */
	(*(volatile uint32 *)D_ADC2RAMPARLOC_CNT_U32) ^= 0x1;	/* flip parity bit */
	adcREG2->PARCR = 0x0000000A;					/* clear the TEST bit */

	adcramread_Cnt_T_u32 = *(volatile uint32 *)D_ADC2RAMLOC_CNT_U32;					/* This read is expected to trigger a parity error */

	adcREG2->PARCR = 0x0000010A;					/* Set the TEST bit in the PARCR and enable parity checking */
	(*(volatile uint32 *)D_ADC2RAMPARLOC_CNT_U32) ^= 0x1;	/* flip parity bit to correct error */
	adcREG2->PARCR = 0x0000000A;					/* clear the TEST bit */

	if (0U == (ESMREGS->ESMSR1 & 0x2))		/* Check for ESM group1 channel 1 to be flagged */
	{
		/* no ADC2 RAM parity error was flagged to ESM */
		ResetCause_Cnt_Enum = MIBADC2PARESMFAILED;
		DiagFailed();
	}
	else
	{
		ESMREGS->ESMSR1 = 0x2;			/* clear ADC2 RAM parity error flag */
	}
}
#endif

#if (DCAN1_PARITY_ENABLE)
static void dcan1ParityCheck(void)
{
	volatile uint32 dcanread_Cnt_T_u32;

	DCAN1REG->CTL = 0x00001481;				/* Disable parity, init mode, TEST mode */
	DCAN1REG->TEST = 0x00000200;			/* Enable RAM Direct Access mode */

	(*(volatile uint32 *)D_DCAN1RAMPARLOC_CNT_U32) ^= 0x00001000;				/* flip the parity bit */

	DCAN1REG->CTL = 0x00002880;				/* Enable parity, disable init, still TEST mode */

	dcanread_Cnt_T_u32 = *(volatile uint32 *)D_DCAN1RAMLOC_CNT_U32;					/* Read location with parity error */
	*(volatile uint32 *)D_DCAN1RAMLOC_CNT_U32 = dcanread_Cnt_T_u32;		/* Nexteer Added: Correct parity error */

	if (0U == (ESMREGS->ESMSR1 & 0x00200000))	/* check if ESM group1 channel 21 is flagged */
	{
		/* No DCAN1 RAM parity error was flagged to ESM */
		ResetCause_Cnt_Enum = DCAN1PARESMFAILED;
		DCAN1REG->ES = DCAN1REG->ES;		/* LWW Edit to clear parity error status register */
		DCAN1REG->CTL = 0x00002800;			/* disable TEST mode */
		DiagFailed();
	}
	else
	{
		DCAN1REG->ES = DCAN1REG->ES;		/* LWW Edit to clear parity error status register */
		ESMREGS->ESMSR1 = 0x00200000;	/* clear ESM group1 channel 21 flag */
		DCAN1REG->CTL = 0x00002800;			/* disable TEST mode */
	}

}
#endif

#if (DCAN2_PARITY_ENABLE)
static void dcan2ParityCheck(void)
{
	volatile uint32 dcanread_Cnt_T_u32;

	DCAN2REG->CTL = 0x00001481;				/* Disable parity, init mode, TEST mode */
	DCAN2REG->TEST = 0x00000200;			/* Enable RAM Direct Access mode */

	(*(volatile uint32 *)D_DCAN2RAMPARLOC_CNT_U32) ^= 0x00001000;				/* flip the parity bit */

	DCAN2REG->CTL = 0x00002880;				/* Enable parity, disable init, still TEST mode */

	dcanread_Cnt_T_u32 = *(volatile uint32 *)D_DCAN2RAMLOC_CNT_U32;					/* Read location with parity error */
	*(volatile uint32 *)D_DCAN2RAMLOC_CNT_U32 = dcanread_Cnt_T_u32;		/* Nexteer Added: Correct parity error */

	if (0U == (ESMREGS->ESMSR1 & 0x00800000))	/* check if ESM group1 channel 23 is flagged */
	{
		/* No DCAN2 RAM parity error was flagged to ESM */
		ResetCause_Cnt_Enum = DCAN2PARESMFAILED;
		DCAN2REG->ES = DCAN2REG->ES;		/* LWW Edit to clear parity error status register */
		DCAN2REG->CTL = 0x00002800;			/* disable TEST mode */
		DiagFailed();
	}
	else
	{
		DCAN2REG->ES = DCAN2REG->ES;		/* LWW Edit to clear parity error status register */
		ESMREGS->ESMSR1 = 0x00800000;	/* clear ESM group1 channel 23 flag */
		DCAN2REG->CTL = 0x00002800;			/* disable TEST mode */
	}

}
#endif

#if (DCAN3_PARITY_ENABLE)
static void dcan3ParityCheck(void)
{
	volatile uint32 dcanread_Cnt_T_u32;

	DCAN3REG->CTL = 0x00001481;				/* Disable parity, init mode, TEST mode */
	DCAN3REG->TEST = 0x00000200;			/* Enable RAM Direct Access mode */

	(*(volatile uint32 *)D_DCAN3RAMPARLOC_CNT_U32) ^= 0x00001000;				/* flip the parity bit */

	DCAN3REG->CTL = 0x00002880;				/* Enable parity, disable init, still TEST mode */

	dcanread_Cnt_T_u32 = *(volatile uint32 *)D_DCAN3RAMLOC_CNT_U32;					/* Read location with parity error */
	*(volatile uint32 *)D_DCAN3RAMLOC_CNT_U32 = dcanread_Cnt_T_u32;		/* Nexteer Added: Correct parity error */

	if (0U == (ESMREGS->ESMSR1 & 0x00400000))	/* check if ESM group1 channel 22 is flagged */
	{
		/* No DCAN3 RAM parity error was flagged to ESM */
		ResetCause_Cnt_Enum = DCAN3PARESMFAILED;
		DCAN3REG->ES = DCAN3REG->ES;		/* LWW Edit to clear parity error status register */
		DCAN3REG->CTL = 0x00002800;			/* disable TEST mode */
		DiagFailed();
	}
	else
	{
		DCAN3REG->ES = DCAN3REG->ES;		/* LWW Edit to clear parity error status register */
		ESMREGS->ESMSR1 = 0x00400000;	/* clear ESM group1 channel 22 flag */
		DCAN3REG->CTL = 0x00002800;			/* disable TEST mode... LWW Edit to enable init mode */
	}
}
#endif

#if (MIBSPI1_PARITY_ENABLE)
static void mibspi1ParityCheck(void)
{
	volatile uint32 spiread_Cnt_T_u32;

	mibspiREG1->MIBSPIE = 0x1;				/* enable multi-buffered mode */

	mibspiREG1->EDEN = 0xA;					/* enable parity error detection */
	mibspiREG1->PTESTEN = 1;				/* enable parity test mode */
	(*(volatile uint32 *)D_SPI1RAMPARLOC_CNT_U32) ^= 0x1;					/* flip bit 0 of the parity location */

	mibspiREG1->PTESTEN = 0;				/* disable parity test mode */

	spiread_Cnt_T_u32 = *(volatile uint32 *)D_SPI1RAMLOC_CNT_U32;					/* read from MibSPI1 RAM to cause parity error */

	if (0U == (ESMREGS->ESMSR1 & 0x20000))	/* check if ESM group1 channel 17 is flagged */
	{
		/* No MibSPI1 RAM parity error was flagged to ESM. */
		ResetCause_Cnt_Enum = MIBSPI1PARESMFAILED;
		mibspiREG1->UERRSTAT = 0x3;			/* clear parity error flags */
		mibspiREG1->PTESTEN = 1;							/* enable parity test mode */
		(*(volatile uint32 *)D_SPI1RAMPARLOC_CNT_U32) ^= 0x1;		/* flip bit 0 of the parity location (correct error) */
		mibspiREG1->PTESTEN = 0;							/* disable parity test mode */
		DiagFailed();
	}
	else
	{
		mibspiREG1->UERRSTAT = 0x3;			/* clear parity error flags */
		ESMREGS->ESMSR1 = 0x20000;		/* clear ESM group1 channel 17 flag */
		mibspiREG1->PTESTEN = 1;							/* enable parity test mode */
		(*(volatile uint32 *)D_SPI1RAMPARLOC_CNT_U32) ^= 0x1;		/* flip bit 0 of the parity location (correct error) */
		mibspiREG1->PTESTEN = 0;							/* disable parity test mode */
	}
}
#endif

#if (MIBSPI3_PARITY_ENABLE)
static void mibspi3parityCheck(void)
{
	volatile uint32 spiread_Cnt_T_u32;

	mibspiREG3->MIBSPIE = 0x1;				/* enable multi-buffered mode */

	mibspiREG3->EDEN = 0xA;					/* enable parity error detection */
	mibspiREG3->PTESTEN = 1;				/* enable parity test mode */
	(*(volatile uint32 *)D_SPI3RAMPARLOC_CNT_U32) ^= 0x1;					/* flip bit 0 of the parity location */

	mibspiREG3->PTESTEN = 0;				/* disable parity test mode */

	spiread_Cnt_T_u32 = *(volatile uint32 *)D_SPI3RAMLOC_CNT_U32;					/* read from MibSPI3 RAM to cause parity error */

	if (0U == (ESMREGS->ESMSR1 & 0x40000))	/* check if ESM group1 channel 18 is flagged */
	{
		/* No MibSPI3 RAM parity error was flagged to ESM. */
		ResetCause_Cnt_Enum = MIBSPI3PARESMFAILED;
		mibspiREG3->UERRSTAT = 0x3;			/* clear parity error flags */
		mibspiREG3->PTESTEN = 1;							/* enable parity test mode */
		(*(volatile uint32 *)D_SPI3RAMPARLOC_CNT_U32) ^= 0x1;		/* flip bit 0 of the parity location (correct error) */
		mibspiREG3->PTESTEN = 0;							/* disable parity test mode */
		DiagFailed();
	}
	else
	{
		mibspiREG3->UERRSTAT = 0x3;			/* clear parity error flags */
		ESMREGS->ESMSR1 = 0x40000;		/* clear ESM group1 channel 18 flag */
		mibspiREG3->PTESTEN = 1;							/* enable parity test mode */
		(*(volatile uint32 *)D_SPI3RAMPARLOC_CNT_U32) ^= 0x1;		/* flip bit 0 of the parity location (correct error) */
		mibspiREG3->PTESTEN = 0;							/* disable parity test mode */
	}
}
#endif

#if (MIBSPI5_PARITY_ENABLE)
static void mibspi5ParityCheck(void)
{
	volatile uint32 spiread_Cnt_T_u32;

	mibspiREG5->MIBSPIE = 0x1;				/* enable multi-buffered mode */

	mibspiREG5->EDEN = 0xA;					/* enable parity error detection */
	mibspiREG5->PTESTEN = 1;				/* enable parity test mode */
	(*(volatile uint32 *)D_SPI5RAMPARLOC_CNT_U32) ^= 0x1;					/* flip bit 0 of the parity location */

	mibspiREG5->PTESTEN = 0;				/* disable parity test mode */

	spiread_Cnt_T_u32 = *(volatile uint32 *)D_SPI5RAMLOC_CNT_U32;					/* read from MibSPI5 RAM to cause parity error */

	if (0U == (ESMREGS->ESMSR1 & 0x01000000))	/* check if ESM group1 channel 24 is flagged */
	{
		/* No MibSPI5 RAM parity error was flagged to ESM. */
		ResetCause_Cnt_Enum = MIBSPI5PARESMFAILED;
		mibspiREG5->UERRSTAT = 0x3;			/* clear parity error flags */
		mibspiREG5->PTESTEN = 1;							/* enable parity test mode */
		(*(volatile uint32 *)D_SPI5RAMPARLOC_CNT_U32) ^= 0x1;		/* flip bit 0 of the parity location (correct error) */
		mibspiREG5->PTESTEN = 0;							/* disable parity test mode */
		DiagFailed();
	}
	else
	{
		mibspiREG5->UERRSTAT = 0x3;			/* clear parity error flags */
		ESMREGS->ESMSR1 = 0x01000000;		/* clear ESM group1 channel 24 flag */
		mibspiREG5->PTESTEN = 1;							/* enable parity test mode */
		(*(volatile uint32 *)D_SPI5RAMPARLOC_CNT_U32) ^= 0x1;		/* flip bit 0 of the parity location (correct error) */
		mibspiREG5->PTESTEN = 0;							/* disable parity test mode */
	}
}
#endif

static void checkB0RAMECC(void)
{
	volatile uint32 ramread_Cnt_T_u32;

	TCRAM0->RAMCTRL = 0x0005010A;			/* enable writes to ECC RAM, enable ECC error response */
	TCRAM0->RAMTHRESHOLD = 0x1;				/* the first 1-bit error will cause an error response */
	TCRAM0->RAMINTCTRL = 0x1;				/* allow SERR to be reported to ESM */

	_coreDisableRamEcc_();
	(*(volatile uint32 *)D_TCRAMA1BITERROR_CNT_U32) ^= 0x1;						/* cause a 1-bit ECC error */
	_coreEnableRamEcc_();
	TCRAM0->RAMCTRL = 0x0005000A;			/* disable writes to ECC RAM */

	ramread_Cnt_T_u32 = *(volatile uint32 *)D_TCRAMA1BIT_CNT_U32;						/* read from location with 1-bit ECC error */
	(*(volatile uint64 *)D_TCRAMA1BIT_CNT_U32) = 0x0;                   /* write to fix ECC errors, although hardware should do this already for 1 bit error */

	if ((0U == (TCRAM0->RAMERRSTATUS & 1)) || (0U == (ESMREGS->ESMSR1 & 0x04000000)))	/* SERR not set in TCRAM1 or TCRAM2 modules */
	{
		/* TCRAM module does not reflect 1-bit error reported by CPU */
		ResetCause_Cnt_Enum = B0SNGBITRAMECCDETFAILED;
		ESMREGS->ESMSR1 = 0x04000000;
		TCRAM0->RAMERRSTATUS = 0x1;						/* clear SERR flag */
		DiagFailed();
	}
	else
	{
		TCRAM0->RAMERRSTATUS = 0x1;			/* clear SERR flag */
		ESMREGS->ESMSR1 = 0x04000000;		/* clear status flags for ESM group1 channels 26 and 28 */
	}

	TCRAM0->RAMCTRL = 0x0005010A;			/* enable writes to ECC RAM, enable ECC error response */

	_coreDisableRamEcc_();
	(*(volatile uint32 *)D_TCRAMA2BITERROR_CNT_U32) ^= 0x3;						/* cause a 2-bit ECC error */
	_coreEnableRamEcc_();
	ramread_Cnt_T_u32 = TCRAM0->RAMCTRL;

	ResetCause_Cnt_Enum = B0MULBITRAMECCDETFAILED;
	ramread_Cnt_T_u32 = *(volatile uint32 *)D_TCRAMA2BIT_CNT_U32;	/* read from location with 2-bit ECC error */
															/* this will cause a data abort to be generated */
	(*(volatile uint64 *)D_TCRAMA2BIT_CNT_U32) = 0x0;				/* write to fix ECC errors */
	TCRAM0->RAMCTRL &= ~(0x00000100);						/* disable writes to ECC RAM */

	if (PWRONRESET != ResetCause_Cnt_Enum)
	{
		DiagFailed();
	}

	/* Read register to allow further errors to be detected */
	ramread_Cnt_T_u32 = TCRAM0->RAMUERRADDR;
}

static void checkB1RAMECC(void)
{
	volatile uint32 ramread_Cnt_T_u32;

	TCRAM1->RAMCTRL = 0x0005010A;
	TCRAM1->RAMTHRESHOLD = 0x1;				/* the first 1-bit error will cause an error response */
	TCRAM1->RAMINTCTRL = 0x1;				/* allow SERR to be reported to ESM */

	_coreDisableRamEcc_();
	(*(volatile uint32 *)D_TCRAMB1BITERROR_CNT_U32) ^= 0x1;						/* cause a 1-bit ECC error */
	_coreEnableRamEcc_();
	TCRAM1->RAMCTRL = 0x0005000A;			/* disable writes to ECC RAM */

	ramread_Cnt_T_u32 = *(volatile uint32 *)D_TCRAMB1BIT_CNT_U32;						/* read from location with 1-bit ECC error */
	(*(volatile uint64 *)D_TCRAMB1BIT_CNT_U32) = 0x0;       /* write to fix ECC errors, although hardware should do this already for 1 bit error */

	if ((0U == (TCRAM1->RAMERRSTATUS & 1)) || (0U == (ESMREGS->ESMSR1 & 0x10000000)))	/* SERR not set in TCRAM1 or TCRAM2 modules */
	{
		/* TCRAM module does not reflect 1-bit error reported by CPU */
		ResetCause_Cnt_Enum = B1SNGBITRAMECCDETFAILED;
		TCRAM1->RAMERRSTATUS = 0x1;						/* clear SERR flag */
		ESMREGS->ESMSR1 = 0x10000000;
		DiagFailed();
	}
	else
	{
		TCRAM1->RAMERRSTATUS = 0x1;			/* clear SERR flag */
		ESMREGS->ESMSR1 = 0x10000000;		/* clear status flags for ESM group1 channels 26 and 28 */
	}

	TCRAM0->RAMCTRL = 0x0005010A;
	TCRAM1->RAMCTRL = 0x0005010A;			/* enable writes to ECC RAM, enable ECC error response */

	_coreDisableRamEcc_();
	(*(volatile uint32 *)D_TCRAMB2BITERROR_CNT_U32) ^= 0x3;						/* cause a 2-bit ECC error */
	_coreEnableRamEcc_();
	ramread_Cnt_T_u32 = TCRAM1->RAMCTRL;

	ResetCause_Cnt_Enum = B1MULBITRAMECCDETFAILED;
	ramread_Cnt_T_u32 = *(volatile uint32 *)D_TCRAMB2BIT_CNT_U32;		/* read from location with 2-bit ECC error */
													/* this will cause a data abort to be generated */
	(*(volatile uint64 *)D_TCRAMB2BIT_CNT_U32) = 0x0;		/* write to fix ECC errors */
	TCRAM1->RAMCTRL &= ~(0x00000100);				/* disable writes to ECC RAM */
	TCRAM0->RAMCTRL &= ~(0x00000100);				/* disable writes to ECC RAM */
	if (PWRONRESET != ResetCause_Cnt_Enum)
	{
		DiagFailed();
	}

	/* Read register to allow further errors to be detected */
	ramread_Cnt_T_u32 = TCRAM1->RAMUERRADDR;
}

static void checkFlashECC(void)
{
	/* Routine to check operation of ECC logic inside CPU for accesses to program flash */

	volatile uint32 flashread_Cnt_T_u32;

	flashWREG->FEDACCTRL1 = 0x000A060A;			/* Flash Module ECC Response enabled */

	flashWREG->FDIAGCTRL = 0x00050007;			/* Enable diagnostic mode and select diag mode 7 */
	flashWREG->FPAROVR = 0x00005A01;			/* Select ECC diagnostic mode, single-bit to be corrupted */
	flashWREG->FDIAGCTRL |= 0x01000000;			/* Set the trigger for the diagnostic mode */

	flashread_Cnt_T_u32 = *(volatile uint32*)D_FLASHBADECC_CNT_U32;					/* read a flash location from the mirrored memory map */
	flashWREG->FDIAGCTRL = 0x000A0007;			/* disable diagnostic mode */

	/* this will have caused a single-bit error to be generated and corrected by CPU */
	if ((0U == (flashWREG->FEDACSTATUS & 0x2)) || (0 == (ESMREGS->ESMSR1 & 0x40)))		/* single-bit error not captured in flash module */
	{
		/* TCRAM module does not reflect 1-bit error reported by CPU */
		ResetCause_Cnt_Enum = SNGBITFLSECCDETFAILED;
		flashWREG->FEDACSTATUS = 0x2;				/* clear single-bit error flag */
		ESMREGS->ESMSR1 = 0x40;					/* clear ESM flag */
		DiagFailed();
	}
	else
	{
		flashWREG->FEDACSTATUS = 0x2;				/* clear single-bit error flag */
		ESMREGS->ESMSR1 = 0x40;					/* clear ESM flag */

		flashWREG->FDIAGCTRL = 0x00050007;			/* Enable diagnostic mode and select diag mode 7 */
		flashWREG->FPAROVR = 0x00005A03;			/* Select ECC diagnostic mode, two bits of ECC to be corrupted */
		flashWREG->FDIAGCTRL |= 0x01000000;			/* Set the trigger for the diagnostic mode */

		ResetCause_Cnt_Enum = MULBITFLSECCDETFAILED;
		flashread_Cnt_T_u32 = *(volatile uint32*)D_FLASHBADECC_CNT_U32;					/* read from flash location from mirrored memory map */
													/* this will cause a data abort */
		if (PWRONRESET != ResetCause_Cnt_Enum)
		{
			DiagFailed();
		}

		/* Read register to allow further errors to be detected */
		flashread_Cnt_T_u32 = flashWREG->FUNCERRADD;
	}

}

static void DiagFailed(void)
{
	ESMREGS->ESMEKR = 0xAU;  			/* Force error pin for safety */
	AppInit();
}

static void AppInit(void)
{
	/***************************** INITIALIZATION STEP 43 ****************************/
	/* initalise copy table */
	if ((uint32 *)&__binit__ != (uint32 *)0xFFFFFFFFU)
	{
		extern void copy_in(void *binit);
		copy_in((void *)&__binit__);
	}

	/* initalise the C global variables */
	if (&__TI_Handler_Table_Base < &__TI_Handler_Table_Limit)
	{
		uint8 **tablePtr   = (uint8 **)&__TI_CINIT_Base;
		uint8 **tableLimit = (uint8 **)&__TI_CINIT_Limit;

		while (tablePtr < tableLimit)
		{
			uint8 *loadAdr = *tablePtr++;
			uint8 *runAdr  = *tablePtr++;
			uint8  idx     = *loadAdr++;
			handler_fptr   handler = (handler_fptr)(&__TI_Handler_Table_Base)[idx];

			(*handler)((const uint8 *)loadAdr, runAdr);
		}
	}

	/* Initialize constructors */
	if (__TI_PINIT_Base < __TI_PINIT_Limit)
	{
		void (**p0)() = (void *)__TI_PINIT_Base;

		while ((uint32)p0 < __TI_PINIT_Limit)
		{
			void (*p)() = *p0++;
			p();
		}
	}

	/* Callout for Application Specific processing */
	AppStartupCallout2();
	main();
}

