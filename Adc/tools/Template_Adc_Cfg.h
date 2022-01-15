/*****************************************************************************
* Copyright 2012 Nexteer Automotive, All Rights Reserved.
* Nexteer Confidential
*
* Module File Name  : Template_Adc_Cfg.h
* Module Description: Adc Driver configuration
* Product           : Gen II Plus - EA3.0
* Author            : Selva Sengottaiyan
*****************************************************************************/
/*---------------------------------------------------------------------------
* Version Control:
* Date Created:      Sat Jul 28 18:03:04 2012
* %version:          1 %
* %derived_by:       nzt9hv %
* %date_modified:    Tue Apr 30 12:57:33 2013 %
*---------------------------------------------------------------------------*/


#ifndef ADC_CFG_H
#define ADC_CFG_H


/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#include "Adc.h"

/*** For 33E ADc (Current mode) define the following macro ***/
#define D_ADC1CURRENTMODE_ULS_LGC

/* Map user defined group conversion names to appropriate group indexer */
#define AdcFwdPath     		??
#define AdcFdbkPath     	??
#define adcGROUP0		??


#define D_ADC1NUMEVTCH_CNT_U08	??				/* Number of channels sampled (e.g. number of bits set in D_ADC1EVTCH_CNT_U32) */
#define D_ADC1EVTCH_CNT_U32		??
#define D_ADC1EVTBUFSZ_CNT_U08	??				/* Number of results allocated in ADC RAM, must be even */

#define D_ADC1NUMG1CH_CNT_U08	??				/* Number of channels sampled (e.g. number of bits set in D_ADC1G1CH_CNT_U32) */
#define D_ADC1G1CH_CNT_U32		??
#define D_ADC1G1BUFSZ_CNT_U08	??				/* Number of results allocated in ADC RAM, must be even */

#define D_ADC1NUMG2CH_CNT_U08	??				/* Number of channels sampled (e.g. number of bits set in D_ADC1G2CH_CNT_U32) */
#define D_ADC1G2CH_CNT_U32		??
#define D_ADC1G2BUFSZ_CNT_U08	??				/* Number of results allocated in ADC RAM, must be even */

#define ADC1_REPORTERRORSTATUS(event, param, status)		??

#define ADC_EVENT_PASSED				??
#define ADC_EVENT_FAILED				??
#define  D_TRUE_CNT_LGC                 ??
#define  D_FALSE_CNT_LGC                ??

typedef uint8	Adc_ConfigType;

#endif
