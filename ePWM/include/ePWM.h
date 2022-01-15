/*****************************************************************************
* Copyright 2013 Nexteer Automotive, All Rights Reserved.
* Nexteer Confidential
*
* Module File Name  : ePWM.h
* Module Description: eTPWM Complex Device Driver
* Product           : Gen II Plus - EA3.0
* Author            : Owen Tosh
*****************************************************************************/
/*---------------------------------------------------------------------------
* Version Control:
* Date Created:      Thu Jan 31 13:14:15 2013
* %version:          1 %
* %derived_by:       nzt9hv %
* %date_modified:    Thu Feb 14 13:15:26 2013 % 
*---------------------------------------------------------------------------*/
/*****************************************************************************

CHANGE HISTORY:

Date      Rev      Author    Change Description                          SCR #
--------  -------  --------  ------------------------------------------  -----
02/01/13  1        Selva        Initial Version
******************************************************************************/

/** file reg_etpwm.h
*   brief ETPWM Register Layer Header File
*   date 7.January.2013
*   version 03.04.00
*/
/* (c) Texas Instruments 2009-2013, All rights reserved. */

#ifndef EPWM_H
#define EPWM_H


#include "Std_Types.h"


FUNC(void, EPWM_CODE) ePWM_Init1(void);
FUNC(void, EPWM_CODE) ePWM_Per1(void);


typedef struct etpwmBASE
{
    uint16 TBSTS;           /**< Time-Base Status Register*/
    uint16 TBCTL;           /**< Time-Base Control Register*/
    uint16 TBPHS;           /**< Time-Base Phase Register*/
    uint16 TBPHSHR;         /**< Extension for HRPWM Phase Register*/
    uint16 TBPRD;           /**< Time-Base Period Register*/
    uint16 TBCTR;           /**< Time-Base Counter Register*/
    uint16 CMPCTL;          /**< Counter-Compare Control Register*/
    uint16 TBPRDHR;         /**< Time Base Period High Resolution Register*/
    uint16 CMPA;            /**< Counter-Compare A Register*/
    uint16 CMPAHR;          /**< Extension for HRPWM Counter-Compare A Register*/
    uint16 AQCTLA;          /**< Action-Qualifier Control Register for Output A (ETPWMxA)*/
    uint16 CMPB;            /**< Counter-Compare B Register*/
    uint16 AQSFRC;          /**< Action-Qualifier Software Force Register*/
    uint16 AQCTLB;          /**< Action-Qualifier Control Register for Output B (EETPWMxB)*/
    uint16 DBCTL;           /**< Dead-Band Generator Control Register*/
    uint16 AQCSFRC;         /**< Action-Qualifier Continuous S/W Force Register Set*/
    uint16 DBFED;           /**< Dead-Band Generator Falling Edge Delay Count Register*/
    uint16 DBRED;           /**< Dead-Band Generator Rising Edge Delay Count Register*/
    uint16 TZDCSEL;         /**< Trip Zone Digital Compare Select Register*/
    uint16 TZSEL;           /**< Trip-Zone Select Register*/
    uint16 TZEINT;          /**< Trip-Zone Enable Interrupt Register*/
    uint16 TZCTL;           /**< Trip-Zone Control Register*/
    uint16 TZCLR;           /**< Trip-Zone Clear Register*/
    uint16 TZFLG;           /**< Trip-Zone Flag Register*/
    uint16 ETSEL;           /**< Event-Trigger Selection Register*/
    uint16 TZFRC;           /**< Trip-Zone Force Register*/
    uint16 ETFLG;           /**< Event-Trigger Flag Register*/
    uint16 ETPS;            /**< Event-Trigger Pre-Scale Register*/
    uint16 ETFRC;           /**< Event-Trigger Force Register*/
    uint16 ETCLR;           /**< Event-Trigger Clear Register*/
    uint16   rsvd_1;        /**< Reserved*/
    uint16 PCCTL;           /**< PWM-Chopper Control Register*/
    uint16 HRPWR;           /**< HRPWM Power Register*/
    uint16 HRCNFG;          /**< HRPWM Configuration Register*/
    uint16   rsvd_3;        /**< Reserved*/
    uint16   rsvd_2;        /**< Reserved*/
    uint16   rsvd_5;        /**< Reserved*/
    uint16   rsvd_4;        /**< Reserved*/
    uint16   rsvd_6;        /**< Reserved*/
    uint16 HRMSTEP;         /**< HRPWM MEP Step Register*/
    uint16   rsvd_7;        /**< Reserved*/
    uint16 HRPCTL;          /**< High Resolution Period Control Register*/
    uint16 TBPRDM;          /**< Time Base Period Register Mirror*/
    uint16 TBPRDHRM;        /**< Time Base Period High Resolution Register Mirror*/
    uint16 CMPAM;           /**< Compare A Register Mirror*/
    uint16 CMPAHRM;         /**< Compare A High Resolution Register Mirror*/
    uint16 DCACTL;          /**< Digital Compare A Control Register*/
    uint16 DCTRIPSEL;       /**< Digital Compare Trip Select Register*/
    uint16 DCFCTL;          /**< Digital Compare Filter Control Register*/
    uint16 DCBCTL;          /**< Digital Compare B Control Register*/
    uint16 DCFOFFSET;       /**< Digital Compare Filter Offset Register*/
    uint16 DCCAPCTL;        /**< Digital Compare Capture Control Register*/
    uint16 DCFWINDOW;       /**< Digital Compare Filter Window Register*/
    uint16 DCFOFFSETCNT;    /**< Digital Compare Filter Offset Counter Register*/
    uint16 DCCAP;           /**< Digital Compare Counter Capture Register*/
    uint16 DCFWINDOWCNT;    /**< Digital Compare Filter Window Counter Register*/
} etpwmBASE_t;


/* ePWM Register Base Addresses */
#define ePWM1 ((etpwmBASE_t *)0xFCF78C00UL)
#define ePWM2 ((etpwmBASE_t *)0xFCF78D00UL)
#define ePWM3 ((etpwmBASE_t *)0xFCF78E00UL)
#define ePWM4 ((etpwmBASE_t *)0xFCF78F00UL)
#define ePWM5 ((etpwmBASE_t *)0xFCF79000UL)
#define ePWM6 ((etpwmBASE_t *)0xFCF79100UL)
#define ePWM7 ((etpwmBASE_t *)0xFCF79200UL)



/* Disable PWM Outputs */
#define ePWM_DisableOutputs()        \
{                                    \
	ePWM1->AQCSFRC = 5U;         \
	ePWM1->DBCTL &= 0xFFFCU; \
	ePWM2->AQCSFRC = 5U;         \
	ePWM2->DBCTL &= 0xFFFCU; \
	ePWM3->AQCSFRC = 5U;         \
	ePWM3->DBCTL &= 0xFFFCU; \
}



/* Enable PWM Outputs */
#define ePWM_EnableOutputs() \
{                            \
	ePWM1->AQCSFRC = 0U; \
	ePWM1->DBCTL |= 3U;  \
	ePWM2->AQCSFRC = 0U; \
	ePWM2->DBCTL |= 3U;  \
	ePWM3->AQCSFRC = 0U; \
	ePWM3->DBCTL |= 3U;  \
}


#endif  /* end of EPWM_H definition */
