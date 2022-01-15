/* STARTSINGLE_OF_MULTIPLE */

/*****************************************************************************
 * Project Name: SysService_AsrSchM
 *    File Name: SchM_IoHwAb.h
 *
 *  Description: Header of BSW Scheduler for the IOHWAB
 *
 ******************************************************************************
 *               C O P Y R I G H T
 ******************************************************************************
 * Copyright (c) 2008 by Vector Informatik GmbH.      All rights reserved.
 *
 *       Please note, that this file contains example configuration used by the
 *       MICROSAR BSW modules. This code may influence the behaviour of the
 *       MICROSAR BSW modules in principle. Therefore, great care must be taken
 *       to verify the correctness of the implementation.
 *       
 *       The contents of the originally delivered files are only examples resp. 
 *       implementation proposals. With regard to the fact that these functions 
 *       are meant for demonstration purposes only, Vector Informatik's 
 *       liability shall be expressly excluded in cases of ordinary negligence, 
 *       to the extent admissible by law or statute.                            
 *
 ******************************************************************************
 *               A U T H O R   I D E N T I T Y
 ******************************************************************************
 * Initials     Name                      Company
 * ********     *********************     *************************************
 * Om           Oliver Meili              Vector Informatik GmbH
 * Jk           Joachim Kalmbach          Vector Informatik GmbH
 * Get          Matthias Gette            Vector Informatik GmbH
 ******************************************************************************
 *               R E V I S I O N   H I S T O R Y
 ******************************************************************************
 * Date        Version  Author  Description
 * **********  *******  ******  ***********************************************
 * 2008-09-09  0.01.00  Jk      Creation
 *****************************************************************************/

#ifndef SCHM_IOHWAB_H
#define SCHM_IOHWAB_H

#include "SchM.h"
#include "SchM_Types.h"
#include "SchM_Cfg.h"

extern const uint8 IOHWAB_EXCLUSIVE_AREA_0;

#if defined( __SCHM__ )

const uint8 IOHWAB_EXCLUSIVE_AREA_0 = SCHM_EA_SUSPENDALLINTERRUPTS;

void SchM_Enter_IoHwAb(uint8 ExclusiveArea)
{
   SCHM_ENTER_EXCLUSIVE(ExclusiveArea);
}

void SchM_Exit_IoHwAb(uint8 ExclusiveArea)
{
   SCHM_EXIT_EXCLUSIVE(ExclusiveArea);
}
#else /* __SCHM__ */

void SchM_Enter_IoHwAb(uint8 ExclusiveArea);
void SchM_Exit_IoHwAb(uint8 ExclusiveArea);
#endif /* __SCHM__ */

#endif /* SCHM_IOHWAB_H */

/* STOPSINGLE_OF_MULTIPLE */
/************   Organi, Version 3.9.0 Vector-Informatik GmbH  ************/
