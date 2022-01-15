/*****************************************************************************
* Copyright 2010 Nexteer Automotive, All Rights Reserved.
* Nexteer Confidential
*
* Module File Name  : MtrCtrl_Irq.c
* Module Description: Motor Control Interrupt Request Service
* Product           : Gen II Plus - EA3.0
* Author            : Jeremy Warmbier
*****************************************************************************/
/* Version Control:
 * Date Created:      Wed Apr 13 12:17:00 2011
 * %version:          6.1.1 %
 * %derived_by:       jzh87w %
 * %date_modified:    Wed Jan 29 12:54:59 2014 %
 *---------------------------------------------------------------------------------------------------------------------
 * Date      Rev      Author         Change Description                                                        SCR #
 * -------   -------  --------  ---------------------------------------------------------------------------  ----------
 * 04/13/11  1        LWW       Initial K2xx Synergy Version
 * 11/03/11  2        LWW       Added anomaly patch for ADC sampling
 * 03/01/12	 3		  RR		Added Function Calls for Current Mode 
 * 04/18/12	 4		  RR		Changes for IPM	
 * 02/21/13	 '3		  SAH		Added ePWM_Per1 function
 * 05/13/13	 5		  SAH		Updated MtrlCtrl function name
 * 05/21/13	 6		  SAH		Added MtrVel3_Per1
 * 01/18/14	6.1.1	  SAH		Changed vim.h to vim_regs.h
 */


/*****************************************************************************
* Include files
*****************************************************************************/
#include "Std_Types.h"
#include "MtrCtrl_Irq.h"
#include "Os.h"
#include "Adc2.h"
#include "vim_regs.h"
#include "CDD_Const.h"
#include "Sa_MtrVel.h"
#include "Ap_MtrCtrl.h"
#include "PwmCdd.h"
#include "ePWM.h"
#include "CDD_Func.h"
#include "Metrics.h"
#include "Ap_MtrCtrl.h"


#include "Adc.h"
#include "CDD_Data.h"
#define D_ADC_FWDPATH_FLAGCLR_U08	0xFE
#define D_ADC_FDBKPATH_FLAGCLR_U08	0xEF

/* TODO: Determine if this INTERRUPT pragma is required when using the  */
/*        interrupt keyword.                                            */
#pragma INTERRUPT(Isr_MtrCtrl, IRQ);
STATIC VAR(uint16, AUTOMATIC) Loop125usCounter_Cnt_M_u16;

/*****************************************************************************
* Local Functions
*****************************************************************************/
FUNC(void, MTRCTRL_CODE) MtrCtrlTaskList(void);


/*****************************************************************************
  * Name:        EnableIrq
  * Description: 
  * Inputs:      None 
  * Outputs:     None
*****************************************************************************/
MTRCTRL_COMPILER_ISR void Isr_MtrCtrl(void)
{
	Metrics_TaskStart(D_MTRCTRLID_CNT_U08);
	
	if( CDD_Adc_ConvFlag_Uls_u08 == 0x01 )
	{
		Adc_StartGroupConversion ( AdcFwdPath );
		CDD_Adc_ConvFlag_Uls_u08 &= D_ADC_FWDPATH_FLAGCLR_U08;	/* Clear Flag */
	}
	else if( CDD_Adc_ConvFlag_Uls_u08 == 0x10) 
	{
   		Adc_StartGroupConversion ( AdcFdbkPath );
		CDD_Adc_ConvFlag_Uls_u08 &= D_ADC_FDBKPATH_FLAGCLR_U08; /* Clear Flag */
	}
		

	MtrCtrlTaskList();
	
	/* ADC2 Event (Group 0) EOC Interrupt Flag Clear */
	adcREG2->GxINTFLG[adcGROUP0] = (1U << 3U);


	Metrics_TaskEnd(D_MTRCTRLID_CNT_U08);
	}

FUNC(void, MTRCTRL_CODE) MtrCtrlTaskList(void)
{
	MtrPos_Per1();
	MtrVel3_Per1();
	Loop125usCounter_Cnt_M_u16 = (Loop125usCounter_Cnt_M_u16 ^ 1U);
	if( Loop125usCounter_Cnt_M_u16 == 1U )
	{

		CurrDQPer1();
		TrqCogCancRefPer1();

		PICurrCntrl_Per1();
		MicroDiag_Per1();



	}

	PwmCdd_Per1();
	ePWM_Per1();
	
}

