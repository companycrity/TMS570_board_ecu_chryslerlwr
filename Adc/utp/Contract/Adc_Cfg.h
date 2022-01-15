/*****************************************************************************
* Copyright 2012 Nexteer Automotive, All Rights Reserved.
* Nexteer Confidential
*
* Module File Name  : Adc_Cfg.h
* Module Description: Adc Driver configuration
* Product           : Gen II Plus - EA3.0
* Author            : Jeremy Warmbier
*****************************************************************************/
/*---------------------------------------------------------------------------
* Version Control:
* Date Created:      Sat Jul 28 18:03:04 2012
* %version:          1 %
* %derived_by:       nzt9hv %
* %date_modified:    Mon Apr 29 09:29:17 2013 %
*---------------------------------------------------------------------------*/


#ifndef ADC_CFG_H
#define ADC_CFG_H


/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#include "Adc.h"

#define D_ADC1CURRENTMODE_ULS_LGC

/* Map user defined group conversion names to appropriate group indexer */
#define AdcFwdPath     		D_GROUP1_CNT_U8
#define AdcFdbkPath     	D_GROUP2_CNT_U8
#define adcGROUP0			D_GROUPEV_CNT_U8


#define D_ADC1NUMEVTCH_CNT_U08	0U				/* Number of channels sampled (e.g. number of bits set in D_ADC1EVTCH_CNT_U32) */
#define D_ADC1EVTCH_CNT_U32		0x0000U
#define D_ADC1EVTBUFSZ_CNT_U08	52U				/* Number of results allocated in ADC RAM, must be even */

#define D_ADC1NUMG1CH_CNT_U08	2U				/* Number of channels sampled (e.g. number of bits set in D_ADC1G1CH_CNT_U32) */
#define D_ADC1G1CH_CNT_U32		0xC000U
#define D_ADC1G1BUFSZ_CNT_U08	2U				/* Number of results allocated in ADC RAM, must be even */

#define D_ADC1NUMG2CH_CNT_U08	10U				/* Number of channels sampled (e.g. number of bits set in D_ADC1G2CH_CNT_U32) */
#define D_ADC1G2CH_CNT_U32		0x3F65U
#define D_ADC1G2BUFSZ_CNT_U08	10U				/* Number of results allocated in ADC RAM, must be even */

#define ADC1_REPORTERRORSTATUS(event, param, status)		(void)0

#define ADC_EVENT_PASSED				TRUE
#define ADC_EVENT_FAILED				FALSE
#define  D_TRUE_CNT_LGC                 TRUE
#define  D_FALSE_CNT_LGC                FALSE

typedef uint8	Adc_ConfigType;

#endif
