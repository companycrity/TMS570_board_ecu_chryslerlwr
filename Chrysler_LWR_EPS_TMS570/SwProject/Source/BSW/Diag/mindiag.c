/*****************************************************************************
| Project Name: FNOS Minimum Diagnostics implementation file
|    File Name: minDiag.c
|
|  Description: Provides example implementations of callbacks needed by 
|               CANdesc. 
|
|-----------------------------------------------------------------------------
|               C O P Y R I G H T
|-----------------------------------------------------------------------------
| Copyright (c) 2005 Vector CANtech, Inc.          All rights reserved.
|
|     This software is copyright protected and proprietary 
|     to Vector Informatik GmbH. Vector Informatik GmbH 
|     grants to you only those rights as set out in the 
|     license conditions. All other rights remain with 
|     Vector Informatik GmbH.
|
|-----------------------------------------------------------------------------
|               A U T H O R   I D E N T I T Y
|-----------------------------------------------------------------------------
| Initials     Name                      Company
| --------     ---------------------     ------------------------------------
| RAP          Rebecca A Pipkorn         Vector CANtech, Inc.          
| SHH          Stephan H Hoffmann        Vector CANtech, Inc.
| EJW          Eric J Winder             Vector CANtech, Inc.      
|-----------------------------------------------------------------------------
|               R E V I S I O N   H I S T O R Y
|-----------------------------------------------------------------------------
| Date         Ver   Author  Description
| ---------    ----  ------  --------------------------------------------------
| 2005-07-28    1.00  SHH     Creation
| 2006-01-13    1.01  EJW     Updates for new version of CANdesc and new template 
| 2007-08-05    1.02  SHH     Updates for new template (3.4.0a)
|************************************************************************************/



/* -----------------------------------------------------------------------------
    &&&~ Includes
 ----------------------------------------------------------------------------- */

/* Make all Vector specific typedefs available */
#include "v_inc.h"

/* Check if CCL is available and take into account its configuration */
#if defined (VGEN_ENABLE_CCL)
# include "ccl_cfg.h"
#endif

/* Make all CANdesc specific typedefs available */
#include "desc.h"
/* Include the implementation prototypes for prototype checks */
#include "appdesc.h"



/* -----------------------------------------------------------------------------
    &&&~ Function prototypes
 ----------------------------------------------------------------------------- */

#ifdef SECURITY_ACCESS
/* Function prototypes */
static void SecCalcKey( vuint8 *key );
static vuint16 ApplDescGetRandomValue(void);

/* Security algorithm helpers */
static vuint8  g_applDescSecF[8];


/* Security randomizer codes */
V_MEMROM0 static V_MEMROM1 vuint8 V_MEMROM2 kApplDescSecB2[2] = { 0x00 , 0x80 };
V_MEMROM0 static V_MEMROM1 vuint8 V_MEMROM2 kApplDescSecC2[2] = { 0x00 , 0x10 };
V_MEMROM0 static V_MEMROM1 vuint8 V_MEMROM2 kApplDescSecC1[2] = { 0x00 , 0x90 };
V_MEMROM0 static V_MEMROM1 vuint8 V_MEMROM2 kApplDescSecC0[2] = { 0x00 , 0x28 };

vuint16 randomSeed;

#endif





vuint8 DESC_API_CALLBACK_TYPE ApplDescReadDID_D100_1_Active_Diagnostic_SessionDID_D100_Active_Diagnostic_Session(void)
{
  /* CANdesc takes care of sending negative responses if requested session is not supported */
  return DescGetSessionIdOfSessionState(DescGetStateSession());
}



/*  ********************************************************************************
 * Function name:ApplDescOnTransitionSession
 * Description:Notification function for state change of the given state group, defined by CANdelaStudio.
 * Returns:  nothing
 * Parameter(s):
 *   - newState:
 *       - The state which will be set.
 *       - Access type: read
 *   - formerState:
 *       - The current state of this state group.
 *       - Access type: read
 * Particularitie(s) and limitation(s):
 *   - The function "DescProcessingDone" may not be called.
 *   - The function "DescSetNegResponse" may not be called.
 ********************************************************************************  *
void DESC_API_CALLBACK_TYPE ApplDescOnTransitionSession(DescStateGroup newState, DescStateGroup formerState)
{
  /* <<TBD>> Remove this comment once you have completely implemented this function!!! */
    /* This is only a notification function. Using the "formerState" and the "newState" 
   * parameter you can distinguish the different transitions for this state group.
   */
//SAH }



/*  ********************************************************************************
 * Function name:ApplDescOnTransitionSecurityAccess
 * Description:Notification function for state change of the given state group, defined by CANdelaStudio.
 * Returns:  nothing
 * Parameter(s):
 *   - newState:
 *       - The state which will be set.
 *       - Access type: read
 *   - formerState:
 *       - The current state of this state group.
 *       - Access type: read
 * Particularitie(s) and limitation(s):
 *   - The function "DescProcessingDone" may not be called.
 *   - The function "DescSetNegResponse" may not be called.
 ********************************************************************************  *
void DESC_API_CALLBACK_TYPE ApplDescOnTransitionSecurityAccess(DescStateGroup newState, DescStateGroup formerState)
{
  /* <<TBD>> Remove this comment once you have completely implemented this function!!! */
    /* This is only a notification function. Using the "formerState" and the "newState" 
   * parameter you can distinguish the different transitions for this state group.
   */
//SAH }


#if defined (DESC_ENABLE_PROGRAMMING_SESSION)
/* ********************************************************************************
 * Function name:ApplDescOnCommunicationEnabled/ApplDescOnCommunicationDisabled
 * Description: Notification function that the communication has been restored/disabled
 * Returns:  none
 * Parameter(s):none
 * Particularitie(s) and limitation(s):
 *   - The function "DescProcessingDone" may not be called.
 *   - The function "DescSetNegResponse" may not be called.
 ******************************************************************************** */
void ApplDescOnCommunicationEnabled(void)
{
  /*<<TBD>> Remove this comment once you have completely implemented this function!!!*/
  /* The requested group of messages will be able to be sent onto the communication bus. */
}

void ApplDescOnCommunicationDisabled(void)
{
  /*<<TBD>> Remove this comment once you have completely implemented this function!!!*/
  /* The requested group of messages will no more be sent onto the communication bus. */
}
#endif


/* ------------------------------------------------------------------------------
   ------------------------------------------------------------------------------
   The following callbacks need minor adjustments to be complete
   ------------------------------------------------------------------------------ */

void DESC_API_CALLBACK_TYPE ApplDescReadDID_F110_On_line_Diagnostic_Database_Reference_Number(DescMsgContext* pMsgContext)
{
  unsigned char i;

  for (i=0; i<24; i++) {
    pMsgContext->resData[i] = i;  /* Dummy data! */
  }

  pMsgContext->resDataLen = 24;
  DescProcessingDone(DESC_CONTEXT_PARAM_WRAPPER_ONLY(pMsgContext->iContext));
}


void DESC_API_CALLBACK_TYPE ApplDescReadDID_F111_ECU_Core_Assembly_Number(DescMsgContext* pMsgContext)
{
  unsigned char i;

  for (i=0; i<24; i++) {
    pMsgContext->resData[i] = i;   /* Dummy data! */
  }

  pMsgContext->resDataLen = 24;
  DescProcessingDone(DESC_CONTEXT_PARAM_WRAPPER_ONLY(pMsgContext->iContext));
}


void DESC_API_CALLBACK_TYPE ApplDescReadDID_F113_ECU_Delivery_Assembly_Number(DescMsgContext* pMsgContext)
{
  unsigned char i;

  for (i=0; i<24; i++) {
    pMsgContext->resData[i] = i;   /* Dummy data! */
  }

  pMsgContext->resDataLen = 24;
  DescProcessingDone(DESC_CONTEXT_PARAM_WRAPPER_ONLY(pMsgContext->iContext));
}


vuint8 DESC_API_CALLBACK_TYPE ApplDescReadDID_F15F_1_NOS_Generation_Tool_SupplierDID_F15F_NOS_Generation_Tool_Version_Number(void)
{
  return (vuint8)VGEN_DELIVERY_VERSION_BYTE_0;
}


void DESC_API_CALLBACK_TYPE ApplDescReadDID_F15F_2_NOS_Generation_Tool_Version_NumberDID_F15F_NOS_Generation_Tool_Version_Number(DescMsg tgtBuffer)
{
  tgtBuffer[0] = VGEN_DELIVERY_VERSION_BYTE_1;
  tgtBuffer[1] = VGEN_DELIVERY_VERSION_BYTE_2;
  tgtBuffer[2] = VGEN_DELIVERY_VERSION_BYTE_3;
  tgtBuffer[3] = VGEN_DELIVERY_VERSION_BYTE_4;
  tgtBuffer[4] = VGEN_DELIVERY_VERSION_BYTE_5;
  tgtBuffer[5] = VGEN_DELIVERY_VERSION_BYTE_6;
  tgtBuffer[6] = VGEN_DELIVERY_VERSION_BYTE_7;
  tgtBuffer[7] = VGEN_DELIVERY_VERSION_BYTE_8;
  tgtBuffer[8] = VGEN_DELIVERY_VERSION_BYTE_9;
}



/* void DESC_API_CALLBACK_TYPE ApplDescReadDID_F166_NOS_Message_Database__1_Version_Number(DescMsgContext* pMsgContext) */
void ApplDescReadNOS_Message_Database_1_Version_NumberDID_F166_NOS_Message_Database__1_Version_Number(DescMsg tgtBuffer)

{
  tgtBuffer[0] = kDBCVersion[0].kYear;     /* VersionYear   */
  tgtBuffer[1] = kDBCVersion[0].kMonth;    /* VersionMonth  */
  tgtBuffer[2] = kDBCVersion[0].kDay;      /* VersionDay    */
  tgtBuffer[3] = kDBCVersion[0].kNumber;   /* VersionNumber */
}

/* ------------------------------------------------------------------------------
   ------------------------------------------------------------------------------
   The following callbacks are as generated and need to be implemented. They are
   provided to allow the generated software to link. 
   ------------------------------------------------------------------------------ */


void DESC_API_CALLBACK_TYPE ApplDescResethardReset(DescMsgContext* pMsgContext)
{
    /* This demo implementation does not perform a reset */
    /* It just puts diagnostics back into the default session */ 
    DescSetStateSession(kDescStateSessionDefault);
    DescProcessingDone(DESC_CONTEXT_PARAM_WRAPPER_ONLY(pMsgContext->iContext));
}

void DESC_API_CALLBACK_TYPE ApplDescRead_DTC_Count_by_StatusDTCs(DescMsgContext* pMsgContext)
{
  /* <<TBD>> Remove this comment once you have completely implemented this function!!! */
  /* Dummy example how to access the request data. */
  /* Assumming the FIRST DATA byte contains important data which has to be less than a constant value. */
  if(pMsgContext->reqData[0] < 0xFF)
  {
    /* Received data is in range process further. */
    /* Dummy example of how to write the response data. */
    pMsgContext->resData[0] = 0x28;
    /* Always set the correct length of the response data. */
    pMsgContext->resDataLen = 1;
  }
  else
  {
    /* Request contains invalid data - send negative response! */
    DescSetNegResponse(DESC_CONTEXT_PARAM_WRAPPER_FIRST(pMsgContext->iContext) kDescNrcRequestOutOfRange);
  }
  DescProcessingDone(DESC_CONTEXT_PARAM_WRAPPER_ONLY(pMsgContext->iContext));
}


void DESC_API_CALLBACK_TYPE ApplDescRead_DTCs_by_StatusDTCs(DescMsgContext* pMsgContext)
{
  /* <<TBD>> Remove this comment once you have completely implemented this function!!! */
  /* Dummy example how to access the request data. */
  /* Assumming the FIRST DATA byte contains important data which has to be less than a constant value. */
  if(pMsgContext->reqData[0] < 0xFF)
  {
    /* Received data is in range process further. */
    /* Dummy example of how to write the response data. */
    pMsgContext->resData[0] = 0xFF;
    /* Always set the correct length of the response data. */
    pMsgContext->resDataLen = 1;
  }
  else
  {
    /* Request contains invalid data - send negative response! */
    DescSetNegResponse(DESC_CONTEXT_PARAM_WRAPPER_FIRST(pMsgContext->iContext) kDescNrcRequestOutOfRange);
  }
  DescProcessingDone(DESC_CONTEXT_PARAM_WRAPPER_ONLY(pMsgContext->iContext));
}


void DESC_API_CALLBACK_TYPE ApplDescRead_Extended_DataDTCs(DescMsgContext* pMsgContext)
{
  /* <<TBD>> Remove this comment once you have completely implemented this function!!! */
  /* Dummy example how to access the request data. */
  /* Assumming the FIRST DATA byte contains important data which has to be less than a constant value. */
  if(pMsgContext->reqData[0] < 0xFF)
  {
    /* Received data is in range process further. */
    /* Dummy example of how to write the response data. */
    pMsgContext->resData[0] = 0xFF;
    /* Always set the correct length of the response data. */
    pMsgContext->resDataLen = 1;
  }
  else
  {
    /* Request contains invalid data - send negative response! */
    DescSetNegResponse(DESC_CONTEXT_PARAM_WRAPPER_FIRST(pMsgContext->iContext) kDescNrcRequestOutOfRange);
  }
  /* User service processing finished. */
  DescProcessingDone(DESC_CONTEXT_PARAM_WRAPPER_ONLY(pMsgContext->iContext));
}


void DESC_API_CALLBACK_TYPE ApplDescRead_Mirror_Extended_DataDTCs(DescMsgContext* pMsgContext)
{
  /* <<TBD>> Remove this comment once you have completely implemented this function!!! */
  /* Dummy example how to access the request data. */
  /* Assumming the FIRST DATA byte contains important data which has to be less than a constant value. */
  if(pMsgContext->reqData[0] < 0xFF)
  {
    /* Received data is in range process further. */
    /* Dummy example of how to write the response data. */
    pMsgContext->resData[0] = 0xFF;
    /* Always set the correct length of the response data. */
    pMsgContext->resDataLen = 1;
  }
  else
  {
    /* Request contains invalid data - send negative response! */
    DescSetNegResponse(DESC_CONTEXT_PARAM_WRAPPER_FIRST(pMsgContext->iContext) kDescNrcRequestOutOfRange);
  }
  /* User service processing finished. */
  DescProcessingDone(DESC_CONTEXT_PARAM_WRAPPER_ONLY(pMsgContext->iContext));
}

void DESC_API_CALLBACK_TYPE ApplDescRead_Mirror_DTCs_by_StatusDTCs(DescMsgContext* pMsgContext)
{
  /* <<TBD>> Remove this comment once you have completely implemented this function!!! */
  /* Dummy example how to access the request data. */
  /* Assumming the FIRST DATA byte contains important data which has to be less than a constant value. */
  if(pMsgContext->reqData[0] < 0xFF)
  {
    /* Received data is in range process further. */
    /* Dummy example of how to write the response data. */
    pMsgContext->resData[0] = 0xFF;
    /* Always set the correct length of the response data. */
    pMsgContext->resDataLen = 1;
  }
  else
  {
    /* Request contains invalid data - send negative response! */
    DescSetNegResponse(DESC_CONTEXT_PARAM_WRAPPER_FIRST(pMsgContext->iContext) kDescNrcRequestOutOfRange);
  }
  /* User service processing finished. */
  DescProcessingDone(DESC_CONTEXT_PARAM_WRAPPER_ONLY(pMsgContext->iContext));
}


void DESC_API_CALLBACK_TYPE ApplDescRead_All_Supported_DTCsDTCs(DescMsgContext* pMsgContext)
{
  
  /* This implementation is only intended to provide a long response to the tester, */
  /*  not to provide an example of reading supported DTCs                           */
	
  vuint8 i, numDTCs, dtcData;
  numDTCs = 28;
  dtcData = 4*numDTCs;

  pMsgContext->resData[0] = 0xff;  /* Status Availability Mask */

  for ( i = 1; i < dtcData; i += 4)
  {
    pMsgContext->resData[i] = i;       /* Dummy DTC Byte */
    pMsgContext->resData[i+1] = i+1;   /* Dummy DTC Byte */
    pMsgContext->resData[i+2] = i+2;   /* Dummy DTC Byte */
    pMsgContext->resData[i+3] = 0xff;  /* Status Mask */
  }

  pMsgContext->resDataLen = dtcData + 1;   /* (4 * Number of DTCs) + 1) */
  DescProcessingDone(DESC_CONTEXT_PARAM_WRAPPER_ONLY(pMsgContext->iContext));
}

void DESC_API_CALLBACK_TYPE ApplDescStartRTN_0202_On_Demand_Self_Test(DescMsgContext* pMsgContext)
{
  /* <<TBD>> Remove this comment once you have completely implemented this function!!! */
  if(pMsgContext->reqDataLen <= (DescMsgLen)0x0FFF)
  {
    /* Dummy example how to access the request data. */
    /* Assumming the FIRST DATA byte contains important data which has to be less than a constant value. */
    if(pMsgContext->reqData[0] < 0xFF)
    {
      /* Received data is in range process further. */
      /* Dummy example of how to write the response data. */
      pMsgContext->resData[0] = 0xFF;
      /* Always set the correct length of the response data. */
      pMsgContext->resDataLen = 1;
    }
    else
    {
      /* Request contains invalid data - send negative response! */
      DescSetNegResponse(DESC_CONTEXT_PARAM_WRAPPER_FIRST(pMsgContext->iContext) kDescNrcRequestOutOfRange);
    }
  }
  else
  {
    /* Request length invalid - send negative response! */
    DescSetNegResponse(DESC_CONTEXT_PARAM_WRAPPER_FIRST(pMsgContext->iContext) kDescNrcInvalidFormat);
  }
  DescProcessingDone(DESC_CONTEXT_PARAM_WRAPPER_ONLY(pMsgContext->iContext));
}


void DESC_API_CALLBACK_TYPE ApplDescStopRTN_0202_On_Demand_Self_Test(DescMsgContext* pMsgContext)
{
  /* <<TBD>> Remove this comment once you have completely implemented this function!!! */
  if(pMsgContext->reqDataLen <= (DescMsgLen)0x0FFF)
  {
    /* Dummy example how to access the request data. */
    /* Assumming the FIRST DATA byte contains important data which has to be less than a constant value. */
    if(pMsgContext->reqData[0] < 0xFF)
    {
      /* Received data is in range process further. */
      /* Dummy example of how to write the response data. */
      pMsgContext->resData[0] = 0xFF;
      /* Always set the correct length of the response data. */
      pMsgContext->resDataLen = 1;
    }
    else
    {
      /* Request contains invalid data - send negative response! */
      DescSetNegResponse(DESC_CONTEXT_PARAM_WRAPPER_FIRST(pMsgContext->iContext) kDescNrcRequestOutOfRange);
    }
  }
  else
  {
    /* Request length invalid - send negative response! */
    DescSetNegResponse(DESC_CONTEXT_PARAM_WRAPPER_FIRST(pMsgContext->iContext) kDescNrcInvalidFormat);
  }
  DescProcessingDone(DESC_CONTEXT_PARAM_WRAPPER_ONLY(pMsgContext->iContext));
}


void DESC_API_CALLBACK_TYPE ApplDescResultsRTN_0202_On_Demand_Self_Test(DescMsgContext* pMsgContext)
{
  /* <<TBD>> Remove this comment once you have completely implemented this function!!! */
  /* Contains no request data */
  /* Dummy example of how to write the response data. */
  pMsgContext->resData[0] = 0xFF;
  /* Always set the correct length of the response data. */
  pMsgContext->resDataLen = 1;
  DescProcessingDone(DESC_CONTEXT_PARAM_WRAPPER_ONLY(pMsgContext->iContext));
}



void DESC_API_CALLBACK_TYPE ApplDescSwitchOnControl_DTC_Setting(DescMsgContext* pMsgContext)
{
  /* <<TBD>> Remove this comment once you have completely implemented this function!!! */
  /* Contains no request data */
  /* Contains no response data */
  DescProcessingDone(DESC_CONTEXT_PARAM_WRAPPER_ONLY(pMsgContext->iContext));
}


void DESC_API_CALLBACK_TYPE ApplDescSwitchOffControl_DTC_Setting(DescMsgContext* pMsgContext)
{
  /* <<TBD>> Remove this comment once you have completely implemented this function!!! */
  /* Contains no request data */
  /* Contains no response data */
  DescProcessingDone(DESC_CONTEXT_PARAM_WRAPPER_ONLY(pMsgContext->iContext));
}



//SAH void DESC_API_CALLBACK_TYPE ApplDescCheckSessionTransition(DescStateGroup newState, DescStateGroup formerState)
//{
  /* Implement checks and  set negative response here if necessary */
  //DescSessionTransitionChecked(DESC_CONTEXT_PARAM_ONLY);
//}


#ifdef SECURITY_ACCESS
/******************************************************************************/
/*                Security Access Code Below                                  */
/******************************************************************************/

/* -----------------------------------------------------------------------------
    &&&~ Preprocessor constants (defines)
 ----------------------------------------------------------------------------- */

/*****************************************************************************/
/****     N O T E:      ******************************************************/
/*                                                                           */
/*  User adaptable section. Change your parameters here.                     */
/*                                                                           */
/*****************************************************************************/
/* The values below are used to generate a random seed         */
/* Seed is based on a timer value read from FBL_HW.            */
/* The seed s generated by:                                    */
/*
 *  for (i=0 ; i<kApplDescSecMaxSeedLoops;i++) seed = seed * kApplDescSecSeedA + kApplDescSecSeedB
 */
/* The algorithm above is repeated, if the result of           */
/* seed is 0. This is limited to "kApplDescSecMaxSeedRetries".         */
/* In case of SeedRetries is exceeded and the values           */
/* is still 0, the default values kApplDescSecSeedA..C are used.       */
#define kApplDescSecMaxSeedLoops                                     5
#define kApplDescSecMaxSeedRetries                                   5

/* Default values and parameters for the SEED-generation.       */
#define kApplDescSecSeedA                                            ((vuint8)0x03)
#define kApplDescSecSeedB                                            ((vuint8)0x1D)
#define kApplDescSecSeedC                                            ((vuint8)0x65)

/* These are fixed constants and can be changed if needed */
#define kApplDescSecInitA1                                           ((vuint8)0xA9)
#define kApplDescSecInitA2                                           ((vuint8)0x41)
#define kApplDescSecInitA3                                           ((vuint8)0xC5)


/* ********************************************************************************
 * Function name:ApplDescSecurityAccessGetSeed
 * Description: Each time called must generate a different value (e.g. current free running timer value).
 * Returns:  Random value
 * Parameter(s):
 *   - iContext:(not available in single context systems)
 *       - Use this call-back handle for all API which need it.
 *       - Access type: read
 *   - securityLevel:
 *       - The current security level represented by the generated contsants (e.g kDescStateSecurityAccessLevel1e etc.).
 *       - Access type: read
 *   - seed:
 *       - A pointer where the generated seed must be written by the application.
 *       - Access type: write
 *   - seedLen:
 *       - The length of the written seed.
 *       - Access type: write
 * Particularitie(s) and limitation(s):
 *   - The function "DescProcessingDone" is NOT allowed to be called.
 *   - The function "DescSetNegResponse" is NOT allowed to be called.
 ******************************************************************************** */
void ApplDescSecurityAccessGetSeed(DescSecurityAccessContext* pDescSecurityAccessContext)
{
  vuint8   i, k;
  vuint16  tmpTime;

  k = 0;
  do
  {
    /* Level accepted, generate a random SEED */
    tmpTime = ApplDescGetRandomValue();
  
    for (i=0 ; i < kApplDescSecMaxSeedLoops ; i++)
    {
      tmpTime = (kApplDescSecSeedA * tmpTime) + kApplDescSecSeedB;
    }
    pDescSecurityAccessContext->dataPtr[2] = (vuint8)(tmpTime >> 8);
    pDescSecurityAccessContext->dataPtr[1] = (vuint8)(tmpTime);
  
    /* Level accepted, generate a random SEED */
    tmpTime = ApplDescGetRandomValue();
  
    for (i=0 ; i < kApplDescSecMaxSeedLoops ; i++)
    {
      tmpTime = (kApplDescSecSeedB * tmpTime) + kApplDescSecSeedA;
    }
    pDescSecurityAccessContext->dataPtr[1] ^= (vuint8)(tmpTime >> 8);
    pDescSecurityAccessContext->dataPtr[0] = (vuint8)(tmpTime);
    k++;
  
    if ( (pDescSecurityAccessContext->dataPtr[0]==0) && (pDescSecurityAccessContext->dataPtr[1]==0) && (pDescSecurityAccessContext->dataPtr[2]==0) )
    {
      if (k >= kApplDescSecMaxSeedRetries)
      {
        pDescSecurityAccessContext->dataPtr[0] = kApplDescSecSeedA;
        pDescSecurityAccessContext->dataPtr[1] = kApplDescSecSeedB;
        pDescSecurityAccessContext->dataPtr[2] = kApplDescSecSeedC; 
      }
    }
    else
    {
      /* Valid SEED found */
      break;
    }
  
  } while ( (k < kApplDescSecMaxSeedRetries) );

  g_applDescSecF[0] = pDescSecurityAccessContext->dataPtr[0];      /* Copy generated seed-value */
  g_applDescSecF[1] = pDescSecurityAccessContext->dataPtr[1];
  g_applDescSecF[2] = pDescSecurityAccessContext->dataPtr[2];

  /* Prepare constants for Key-calculation - use the challenge bytes */
  DescSecurityAccessGetChallengeBytes(pDescSecurityAccessContext->securityLevel, &g_applDescSecF[3]);

  /* Currently the example will calculate always a 3 Byte SEED */
  /* dataLen parameter is already initialized with the seed length from the CDD file */
  pDescSecurityAccessContext->dataLen = 3;

  /* Call this function to confirm the process end now or outside of this call-back */
  DescSecurityAccessSeedReady(DESC_CONTEXT_PARAM_WRAPPER_ONLY(pDescSecurityAccessContext->iContext));
}

/******************************************************************************
* Name         :  SecCalcKey  
* Called by    :  SendKey
* Preconditions:  None
* Parameters   :  None
* Description  :  
******************************************************************************/
static void SecCalcKey(vuint8 *key )
{
  vuint8 idx, i;
  vuint8 mask, x;
  static vuint8 secC[3];

  mask = 0x01;
  x    = 0;

  secC[0] = kApplDescSecInitA1;
  secC[1] = kApplDescSecInitA2;
  secC[2] = kApplDescSecInitA3;


  for ( i=0 ; i < 64 ; i++)
  {
    idx = (vuint8)(((mask & g_applDescSecF[x])!=0) ? (1) : (0));

    idx ^= (secC[0] & 0x01);
    if (mask==0x80) 
    {
       mask = 0x01;
       x++;
    }
    else
    {
       mask <<= 1;
    }


    secC[0] >>= 1;
    if ((secC[1] & 0x01)!=0) {secC[0] |= 0x80;}
    secC[1] >>= 1;
    if ((secC[2] & 0x01)!=0) {secC[1] |= 0x80;}
  
    secC[2] = (secC[2]>>1) | kApplDescSecB2[idx];

    secC[0] ^= kApplDescSecC0[idx];
    secC[1] ^= kApplDescSecC1[idx];
    secC[2] ^= kApplDescSecC2[idx];

  }

  key[0]  = (secC[0] >> 4);
  key[0] |= (secC[1] << 4);

  key[1]  = (secC[2] >> 4);
  key[1] |= (secC[1] & 0xF0);

  key[2]  = (secC[2] & 0x0f);
  key[2] |= (secC[0] << 4);
}

/* ********************************************************************************
 * Function name:ApplDescSecurityAccessCheckKey
 * Description: The application must validate the received security key.
 * Returns:  Random value
 * Parameter(s):
 *   - iContext:(not available in single context systems)
 *       - Use this call-back handle for all API which need it.
 *       - Access type: read
 *   - securityLevel:
 *       - The current security level represented by the generated contsants (e.g kDescStateSecurityAccessLevel1e etc.).
 *       - Access type: read
 *   - key:
 *       - A pointer where the received key must be read from by the application.
 *       - Access type: read
 *   - keyLength:
 *       - The length of the received key.
 *       - Access type: read
 * Particularitie(s) and limitation(s):
 *   - The function "DescProcessingDone" is NOT allowed be called.
 *   - The function "DescSetNegResponse" is NOT allowed be called. 
 ******************************************************************************** */
void ApplDescSecurityAccessCheckKey(DescSecurityAccessContext* pDescSecurityAccessContext)
{
  /* The size of this array may vary and depends on the security key definition in the CDD file. */
  vuint8 tmpKey[3];     /* Store Key on the stack, invisible for extern access */
  vuintx iter = pDescSecurityAccessContext->dataLen;

  /* Key is OK */
  pDescSecurityAccessContext->status = kDescSaStatusOk;

  /* Calculate the Key */
  SecCalcKey(tmpKey);

  /* Compare results with Key from tester */
  while(iter != 0)
  {
    iter--;
    if (tmpKey[iter] != pDescSecurityAccessContext->dataPtr[iter])
    {
      iter = 0;
      /* Key is INVALID */
      pDescSecurityAccessContext->status = kDescSaStatusNok;
    }
  }

  /* Call this function to confirm the process end now or outside of this call-back */
  DescSecurityAccessKeyChecked(DESC_CONTEXT_PARAM_WRAPPER_ONLY(pDescSecurityAccessContext->iContext));
}



vuint16 ApplDescGetRandomValue(void)
{
  return randomSeed++;/* This is not a good example of very random generation :o) */
}
#endif




void DESC_API_CALLBACK_TYPE ApplDescReadDID_0202_Number_of_Trouble_Codes_Set_due_to_Diagnostic_Test(DescMsgContext* pMsgContext)
{
  /* <<TBD>> Remove this comment once you have completely implemented this function!!! */
  /* Contains no request data */
  /* Dummy example of how to write the response data. */
  pMsgContext->resData[0] = 0xFF;
  /* Always set the correct length of the response data. */
  pMsgContext->resDataLen = 1;
  /* User service processing finished. */
  DescProcessingDone(DESC_CONTEXT_PARAM_WRAPPER_ONLY(pMsgContext->iContext));
}



void DESC_API_CALLBACK_TYPE ApplDescClear_AllDTCs(DescMsgContext* pMsgContext)
{
  /* <<TBD>> Remove this comment once you have completely implemented this function!!! */
  /* Contains no request data */
  /* Contains no response data */
  /* User service processing finished. */
  DescProcessingDone(DESC_CONTEXT_PARAM_WRAPPER_ONLY(pMsgContext->iContext));
}

void DESC_API_CALLBACK_TYPE ApplDesc_23_ReadMemoryByAddress_24_Long_block_length_parameter(DescMsgContext* pMsgContext)
{
  /* <<TBD>> Remove this comment once you have completely implemented this function!!! */
  vuint32 param;
  if(pMsgContext->reqDataLen >= 4)
  {
    /* Copy the requested service sub-parameter. */
    param = DescMake32Bit(pMsgContext->reqData[0], pMsgContext->reqData[1], pMsgContext->reqData[2], pMsgContext->reqData[3]);
    switch(param)
    {
      case 0xFFFFFFFF:
      {
        if(pMsgContext->reqDataLen <= (DescMsgLen)0x0FFF)
        {
          /* Dummy example how to access the request data. */
          /* Assumming the FIRST DATA byte contains important data which has to be less than a constant value. */
          if(pMsgContext->reqData[4] < 0xFF)
          {
            /* Received data is in range process further. */
            /* Dummy example of how to write the response data. */
            pMsgContext->resData[0] = 0xFF;
            /* Always set the correct length of the response data. */
            pMsgContext->resDataLen = 1;
          }
          else
          {
            /* Request contains invalid data - send negative response! */
            DescSetNegResponse(DESC_CONTEXT_PARAM_WRAPPER_FIRST(pMsgContext->iContext) kDescNrcRequestOutOfRange);
          }
        }
        else
        {
          /* Request length invalid - send negative response! */
          DescSetNegResponse(DESC_CONTEXT_PARAM_WRAPPER_FIRST(pMsgContext->iContext) kDescNrcInvalidFormat);
        }
      }
      break;
      default:
      {
        /* Requested sub-parameter is not supported - send negative response! */
        DescSetNegResponse(DESC_CONTEXT_PARAM_WRAPPER_FIRST(pMsgContext->iContext) kDescNrcRequestOutOfRange);
      }
      break;
    }
  }
  else
  {
    /* Request length invalid - send negative response! */
    DescSetNegResponse(DESC_CONTEXT_PARAM_WRAPPER_FIRST(pMsgContext->iContext) kDescNrcInvalidFormat);
  }
  /* User service processing finished. */
  DescProcessingDone(DESC_CONTEXT_PARAM_WRAPPER_ONLY(pMsgContext->iContext));
}




void DESC_API_CALLBACK_TYPE ApplDescRead_Snapshot_IdentificationDTCs(DescMsgContext* pMsgContext)
{
  /* <<TBD>> Remove this comment once you have completely implemented this function!!! */
  /* Contains no request data */
  /* Dummy example of how to write the response data. */
  pMsgContext->resData[0] = 0xFF;
  /* Always set the correct length of the response data. */
  pMsgContext->resDataLen = 1;
  /* User service processing finished. */
  DescProcessingDone(DESC_CONTEXT_PARAM_WRAPPER_ONLY(pMsgContext->iContext));
}




void DESC_API_CALLBACK_TYPE ApplDescRead_Snapshot_10DTCs(DescMsgContext* pMsgContext)
{
  /* <<TBD>> Remove this comment once you have completely implemented this function!!! */
  /* Dummy example how to access the request data. */
  /* Assumming the FIRST DATA byte contains important data which has to be less than a constant value. */
  if(pMsgContext->reqData[0] < 0xFF)
  {
    /* Received data is in range process further. */
    /* Dummy example of how to write the response data. */
    pMsgContext->resData[0] = 0xFF;
    /* Always set the correct length of the response data. */
    pMsgContext->resDataLen = 5;
  }
  else
  {
    /* Request contains invalid data - send negative response! */
    DescSetNegResponse(DESC_CONTEXT_PARAM_WRAPPER_FIRST(pMsgContext->iContext) kDescNrcRequestOutOfRange);
  }
  /* User service processing finished. */
  DescProcessingDone(DESC_CONTEXT_PARAM_WRAPPER_ONLY(pMsgContext->iContext));
}




void DESC_API_CALLBACK_TYPE ApplDescRead_Freeze_Frame_DataDTCs(DescMsgContext* pMsgContext)
{
  /* <<TBD>> Remove this comment once you have completely implemented this function!!! */
  /* Dummy example how to access the request data. */
  /* Assumming the FIRST DATA byte contains important data which has to be less than a constant value. */
  if(pMsgContext->reqData[0] < 0xFF)
  {
    /* Received data is in range process further. */
    /* Dummy example of how to write the response data. */
    pMsgContext->resData[0] = 0xFF;
    /* Always set the correct length of the response data. */
    pMsgContext->resDataLen = 1;
  }
  else
  {
    /* Request contains invalid data - send negative response! */
    DescSetNegResponse(DESC_CONTEXT_PARAM_WRAPPER_FIRST(pMsgContext->iContext) kDescNrcRequestOutOfRange);
  }
  /* User service processing finished. */
  DescProcessingDone(DESC_CONTEXT_PARAM_WRAPPER_ONLY(pMsgContext->iContext));
}



void DESC_API_CALLBACK_TYPE ApplDescPostResethardReset(DESC_CONTEXT_FORMAL_PARAM_DEF_FIRST vuint8 status)
{
  /* <<TBD>> Remove this comment once you have completely implemented this function!!! */
    /* Avoid warnings */
  DESC_CONTEXT_PARAM_DUMMY_USE;

  /* Check if this service may be executed (condition checks). This one is dummy check please remove it!. */
  if(status == kDescPostHandlerStateOk)
  {
    /* Do post processing since everything ran without errors (the positive response (process finalization)
     * was successfully sent (closed). 
     */
  }
  else
  {
    /* Optional code if the failure reason is from importance. */

    /* The ... */
    if((status & kDescPostHandlerStateNegResSent) != 0)
    {
      /* ... negative response ... */
    }
    else
    {
      /* ... positive response ... */
    }

    if((status & kDescPostHandlerStateTxFailed) != 0)
    {
      /* ... transmission has failed. */
    }
    else
    {
      /* ... transmission has been successfully accomplished. */
    }
  }
;
}


void DESC_API_CALLBACK_TYPE ApplDescAbort_TransferMemory_Area_Transfer(DescMsgContext* pMsgContext)
{
  /* <<TBD>> Remove this comment once you have completely implemented this function!!! */
  /* Contains no request data */
  /* Dummy example of how to write the response data. */
  pMsgContext->resData[0] = 0xFF;
  /* Always set the correct length of the response data. */
  pMsgContext->resDataLen = 2;
  /* User service processing finished. */
  DescProcessingDone(DESC_CONTEXT_PARAM_WRAPPER_ONLY(pMsgContext->iContext));
}


void DESC_API_CALLBACK_TYPE ApplDescTransfer_DataMemory_Area_Transfer(DescMsgContext* pMsgContext)
{
  /* <<TBD>> Remove this comment once you have completely implemented this function!!! */
  /* The application must check the requested data length. */
  if(pMsgContext->reqDataLen <= (DescMsgLen)0x0FFF)
  {
    /* Dummy example how to access the request data. */
    /* Assumming the FIRST DATA byte contains important data which has to be less than a constant value. */
    if(pMsgContext->reqData[0] < 0xFF)
    {
      /* Received data is in range process further. */
      /* Dummy example of how to write the response data. */
      pMsgContext->resData[0] = 0xFF;
      /* Always set the correct length of the response data. */
      pMsgContext->resDataLen = 1;
    }
    else
    {
      /* Request contains invalid data - send negative response! */
      DescSetNegResponse(DESC_CONTEXT_PARAM_WRAPPER_FIRST(pMsgContext->iContext) kDescNrcRequestOutOfRange);
    }
  }
  else
  {
    /* Request length invalid - send negative response! */
    DescSetNegResponse(DESC_CONTEXT_PARAM_WRAPPER_FIRST(pMsgContext->iContext) kDescNrcInvalidFormat);
  }
  /* User service processing finished. */
  DescProcessingDone(DESC_CONTEXT_PARAM_WRAPPER_ONLY(pMsgContext->iContext));
}
