
/*****************************************************************************
* Copyright 2010 Nexteer Automotive, All Rights Reserved.
* Nexteer Confidential
*
* Module File Name  : Sa_MtrPos_Cfg.h
* Module Description: Configuration file of MtrPos module
* Product           : Gen II Plus - EA3.0
* Generator         : artt 2.0.2.0
* Generation Time   : 29.01.2013 15:01:36
*****************************************************************************/
/* Version Control:
 * Date Created:      Fri Jul 13 18:34:17 2012
 * %version:          1 %
 * %date_modified:    Fri May 24 14:36:16 2013 %
 *---------------------------------------------------------------------------------------------------------------------
 * Date      Rev      Author    Change Description                                                           SCR #
 * --------  -------  --------  ---------------------------------------------------------------------------  ----------
 * 02/27/13  1        OT        Initial version
 * 04/29/13  2        OT        Changed ActvDblBuf source to sync with ADC reads in IoHwAb_FwdPathAdc (anomaly 4910)
 */

#ifndef SA_MTRPOS_CFG_H
#define SA_MTRPOS_CFG_H

#include "IoHwAbstractionUsr.h"
/*******************************************************************************
**                      Define Section                                       **
*******************************************************************************/

#define CDD_Read_MtrPos_ActvDblBuf_Cnt_u08( ptr )		*(ptr) = FwdPathAdcActvDblBuf_Cnt_G_u08
   
#endif /* SA_MTRPOS_CFG_H */

/*** End of file **************************************************************/
