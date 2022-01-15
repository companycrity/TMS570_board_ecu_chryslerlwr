

/*****************************************************************************
| Project Name:   XCP application callback function template
|    File Name:   _xcp_appl.c
|
|  Description: 
|    Template for the XCP application callback functions.
|    This is just an example and may be modified .
|
|  Contains:
|    - Examples for FLASH programming, EEPROM programming, CalPage switching
|
|-----------------------------------------------------------------------------
|               D E M O
|-----------------------------------------------------------------------------
|
|       Please note, that the demo and example programs 
|       only show special aspects of the software. 
|       With regard to the fact that these programs are meant 
|       for demonstration purposes only,
|       Vector Informatik's liability shall be expressly excluded in cases 
|       of ordinary negligence, to the extent admissible by law or statute.
|
|-----------------------------------------------------------------------------
|               C O P Y R I G H T
|-----------------------------------------------------------------------------
| Copyright (c) 2008 by Vector Informatik GmbH.           All rights reserved.
|
|       This software is copyright protected and 
|       proporietary to Vector Informatik GmbH.
|       Vector Informatik GmbH grants to you only
|       those rights as set out in the license conditions.
|       All other rights remain with Vector Informatik GmbH.
| 
|       Diese Software ist urheberrechtlich geschuetzt. 
|       Vector Informatik GmbH raeumt Ihnen an dieser Software nur 
|       die in den Lizenzbedingungen ausdruecklich genannten Rechte ein.
|       Alle anderen Rechte verbleiben bei Vector Informatik GmbH.
|
|-----------------------------------------------------------------------------
|               A U T H O R   I D E N T I T Y
|-----------------------------------------------------------------------------
| Initials     Name                      Company
| --------     ---------------------     -------------------------------------
| Tri          Frank Triem               Vector Informatik GmbH
| Hr           Andreas Herkommer         Vector Informatik GmbH
| Svh          Sven Hesselmann           Vector Informatik GmbH
|-----------------------------------------------------------------------------
|               R E V I S I O N   H I S T O R Y
|-----------------------------------------------------------------------------
|  Date       Version  Author  Description
| ----------  -------  ------  -----------------------------------------------
| 2004-12-30  1.00.00   Tri    ESCAN00010708: Create template _xcp_appl.c
| 2005-02-21  1.01.00   Tri    Rename XcpApplInit to ApplXcpInitTemplate
| 2005-05-19  1.02.00   Tri    Support data paging on Star12X
| 2005-12-14  1.03.00   Tri    ESCAN00013899: Data acquisition not possible during cold start
| 2006-03-17  1.04.00   Tri    Compiler switch for paged memory model added
| 2006-05-30  1.05.00   Tri    Demo disclaimer added
| 2007-01-18  1.06.00   Tri    ESCAN00018808: Support data paging on Star12X / Cosmic
| 2007-07-09  1.06.01   Hr     Support AUTOSAR Memory Mapping
| 2008-04-03  1.07.00   Hr     ESCAN00025754: Missing function stubs
| 2008-07-21  1.08.00   Hr     Added new callbacks
| 2008-09-10  1.09.00   Svh    Added new callback ApplXcpReadChecksumValue
| 2010-03-24  1.10.00   Hr     Added new callback ApplXcpCalibrationWrite/Read
|***************************************************************************/


/*****************************************************************************/
/* Include files                                                             */
/*****************************************************************************/
#include "XcpProf.h"


/***************************************************************************/
/* Version check                                                           */
/***************************************************************************/
#if ( CP_XCP_VERSION < 0x0125u )
  #error "XCP Protocol Layer and XCP template are inconsistent!"
#endif
#if ( CP_XCP_VERSION < 0x00 )
 #error "XCP Protocol Layer and XCP on CAN Transport Layer are not consistent!"
#endif


/***************************************************************************/
/* Defines                                                                 */
/***************************************************************************/


/*****************************************************************************/
/* Constants                                                                 */
/*****************************************************************************/

#if defined ( XCP_ENABLE_VECTOR_MAPNAMES )
V_MEMROM0 static const vuint8 xcpMapNames[14] = { '1','2','3','4','5','6','7','8','9','0','A','B','C','D' };
#endif



/*****************************************************************************/
/* Local data definitions                                                    */
/*****************************************************************************/

#if defined ( XCP_ENABLE_CALIBRATION_PAGE )
static vuint8 xcpCalPage; /* 0-Ram,1-Flash */
#endif

#if defined ( XCP_ENABLE_SEED_KEY )
vuint8 xcpResource;
#endif





/*****************************************************************************/
/*                                                                           */
/* Implementation                                                            */
/*                                                                           */
/*****************************************************************************/


#if defined ( XCP_ENABLE_SEED_KEY ) || defined ( XCP_ENABLE_CALIBRATION_PAGE )

void ApplXcpInitTemplate( void )
{
  #if defined ( XCP_ENABLE_SEED_KEY )
  /* Part of the example implementation for Seed & Key. */
  xcpResource = 0;
  #endif


  #if defined ( XCP_ENABLE_CALIBRATION_PAGE )
  /* Part of the example implementation for page switching */
  xcpCalPage = 0;                         /* 0-Ram,1-Flash */
  #endif
}

#endif



#if defined (XCP_ENABLE_DAQ)

  #if defined (XCP_ENABLE_DAQ_RESUME)
/*****************************************************************************/
/* DAQ list resume feature                                                   */
/*****************************************************************************/

void ApplXcpDaqResumeStore( const tXcpDaq * daq )
{
  /* something has to be done here */
}


void ApplXcpDaqResumeClear( void )
{
  /* something has to be done here */
}


vuint8 ApplXcpDaqResume( tXcpDaq * daq )
{
  /* something has to be done here */
  return (vuint8)0u;
}

vuint8 ApplXcpCalResumeStore( void )
{
  /* something has to be done here */
  return (vuint8)0u;
}

  #endif /* XCP_ENABLE_DAQ_RESUME */


  #if defined ( XCP_ENABLE_DAQ_TIMESTAMP )
/****************************************************************************/
/* DAQ Timestamp                                                            */
/****************************************************************************/

XcpDaqTimestampType ApplXcpGetTimestamp( void )
{
  return (XcpDaqTimestampType)0u;
}
  #endif /* XCP_ENABLE_DAQ_TIMESTAMP */

#endif /* XCP_ENABLE_DAQ */



#if defined ( XCP_ENABLE_CALIBRATION_PAGE )

/*****************************************************************************/
/* Page switching                                                            */
/* This is just an example how the page switching could be implemented.      */
/*****************************************************************************/

/*****************************************************************************
| NAME:             ApplXcpGetCalPage
| CALLED BY:        XcpCommand
| PRECONDITIONS:    RAM / ROM switching enabled
| INPUT PARAMETERS: segment : 
|                   mode    : 
| RETURN VALUES:    
| DESCRIPTION:      
******************************************************************************/
vuint8 ApplXcpGetCalPage( vuint8 segment, vuint8 mode ) 
{
  return (vuint8)xcpCalPage;
}

/*****************************************************************************
| NAME:             ApplXcpSetCalPage
| CALLED BY:        XcpCommand
| PRECONDITIONS:    RAM / ROM switching enabled
| INPUT PARAMETERS: segment : 
|                   page    :
|                   mode    : CAL_ECU and/or CAL_XCP or CAL_ALL
| RETURN VALUES:    
| DESCRIPTION:      
******************************************************************************/
vuint8 ApplXcpSetCalPage( vuint8 segment, vuint8 page, vuint8 mode ) 
{
  if (segment!=0)
  {
    return CRC_OUT_OF_RANGE; /* Only one segment supported */
  }
  if (page>1)
  {
    return CRC_PAGE_NOT_VALID; 
  }
  if ((mode&0x03)!=0x03)
  {
    return CRC_PAGE_MODE_NOT_VALID; /* Only one segment supported */
  }
  xcpCalPage = page;

  return (vuint8)0;
}


  #if defined ( XCP_ENABLE_PAGE_COPY )
/*****************************************************************************
| NAME:             ApplXcpCopyCalPage
| CALLED BY:        XcpCommand
| PRECONDITIONS:    RAM / ROM switching enabled
| INPUT PARAMETERS: srcSeg   : 
|                   srcPage  :
|                   destSeg  : 
|                   destPage :
| RETURN VALUES:    
| DESCRIPTION:      
******************************************************************************/
vuint8 ApplXcpCopyCalPage(vuint8 srcSeg, vuint8 srcPage, vuint8 destSeg, vuint8 destPage)
{

  /* something has to be done here */

  return (vuint8)1u;
}
  #endif

#endif /* XCP_ENABLE_CALIBRATION_PAGE */


#if defined ( XCP_ENABLE_PAGE_FREEZE )
/*****************************************************************************
| NAME:             ApplXcpSetFreezeMode
| CALLED BY:        XcpCommand
| PRECONDITIONS:    RAM / ROM switching enabled
| INPUT PARAMETERS: segment : 
|                   mode    :
| RETURN VALUES:    
| DESCRIPTION:      
******************************************************************************/
void ApplXcpSetFreezeMode( vuint8 segment, vuint8 mode )
{
  /* something has to be done here */
}

/*****************************************************************************
| NAME:             ApplXcpGetFreezeMode
| CALLED BY:        XcpCommand
| PRECONDITIONS:    RAM / ROM switching enabled
| INPUT PARAMETERS: segment : 
| RETURN VALUES: mode    
| DESCRIPTION:      
******************************************************************************/
vuint8 ApplXcpGetFreezeMode( vuint8 segment )
{
  /* something has to be done here */

  return (vuint8)0u;
}
#endif /* XCP_ENABLE_PAGE_FREEZE */



#if defined ( XCP_ENABLE_PROGRAM )

/*****************************************************************************/
/* Flash Programming                                                         */
/* Used only if Flash Programming is required                                */
/*****************************************************************************/

/*****************************************************************************
| NAME:             ApplXcpProgramStart
| CALLED BY:        XcpCommand
| PRECONDITIONS:    flash programming required
| INPUT PARAMETERS: none
| RETURN VALUES:    XCP_CMD_OK or XCP_CMD_ERROR
| DESCRIPTION:      Prepare for Flash programming
******************************************************************************/
vuint8 ApplXcpProgramStart( void )
{
  /* something has to be done here */

  return (vuint8)XCP_CMD_OK;
}


/*****************************************************************************
| NAME:             ApplXcpFlashClear
| CALLED BY:        XcpCommand
| PRECONDITIONS:    flash programming required
| INPUT PARAMETERS: address : pointer to memory address
|                   size    : memory size
| RETURN VALUES:    XCP_CMD_OK or XCP_CMD_ERROR
| DESCRIPTION:      Clear a flash are specified by the address and size.
******************************************************************************/
vuint8 ApplXcpFlashClear( MTABYTEPTR address, vuint32 size )
{
  /* something has to be done here */

  return (vuint8)XCP_CMD_OK;
}

/*****************************************************************************
| NAME:             ApplXcpFlashProgram
| CALLED BY:        XcpCommand
| PRECONDITIONS:    flash programming required
| INPUT PARAMETERS: data    : pointer to data
|                   address : pointer to memory address
|                   size    : memory size
| RETURN VALUES:    XCP_CMD_OK or XCP_CMD_ERROR
| DESCRIPTION:      Program a flash area specified by address and size with data.
******************************************************************************/
vuint8 ApplXcpFlashProgram( const BYTEPTR data, MTABYTEPTR address, vuint8 size )
{
  /* something has to be done here */

  return (vuint8)XCP_CMD_OK;
}


/*****************************************************************************
| NAME:             ApplXcpReset
| CALLED BY:        XcpCommand
| PRECONDITIONS:    flash programming required
| INPUT PARAMETERS: none
| RETURN VALUES:    none
| DESCRIPTION:      
******************************************************************************/
void ApplXcpReset( void )
{
  /* something has to be done here */

}

#endif /* XCP_ENABLE_PROGRAM */



/*****************************************************************************/
/* Platform and implementation specific functions for XCP                    */
/*****************************************************************************/

/*****************************************************************************
| NAME:             ApplXcpGetPointer
| CALLED BY:        XcpCommand
| PRECONDITIONS:    none
| INPUT PARAMETERS: addr_ext : 8  bit address extension
|                   addr     : 32 bit address
| RETURN VALUES:    Pointer to the address specified by the parameters. 
| DESCRIPTION:      Convert a memory address from XCP format 8/32bit into a C pointer.
|                   Used for memory transfers like DOWNLOAD, UPLOAD (MTA)
******************************************************************************/
#if defined ( ApplXcpGetPointer )
 /* defined as macro */
#else
MTABYTEPTR ApplXcpGetPointer( vuint8 addr_ext, vuint32 addr )
{

  #if defined ( V_ENABLE_USE_DUMMY_STATEMENT )
  /* avoid compiler warning due to unused parameters */
  addr_ext = addr_ext;
  #endif

  /* Example C16x: DDP1 used for XCP_RAM/XCP_ROM selection */
  #if defined ( CANBOX ) || defined ( PHYTEC_MM167 )
    #if defined ( XCP_ENABLE_CALIBRATION_PAGE )
  if (xcpCalPage==1 && addr>=0x14000 && addr<0x18000)  /* CALRAM */
  {
    return (MTABYTEPTR) ( addr + 0x30000UL );
  }
    #endif
  #endif


  return (MTABYTEPTR) addr;
}

#endif /* ApplXcpGetPointer */


#if defined ( XCP_ENABLE_MEM_ACCESS_BY_APPL )

/*****************************************************************************
| NAME:             ApplXcpRead
| CALLED BY:        XCP Protocol Layer
| PRECONDITIONS:    none
| INPUT PARAMETERS: addr : 32 bit address
| RETURN VALUES:    Value specified by the address parameters. 
| DESCRIPTION:      Read a single byte from the memory.
******************************************************************************/
vuint8 ApplXcpRead( vuint32 addr )
{
  return *((vuint8*)addr);
}  

/*****************************************************************************
| NAME:             ApplXcpWrite
| CALLED BY:        XCP Protocol Layer
| PRECONDITIONS:    none
| INPUT PARAMETERS: addr : 32 bit address
|                   data : data to be written to memory
| RETURN VALUES:    none
| DESCRIPTION:      Write a single byte to RAM.
******************************************************************************/
void XCP_FAR ApplXcpWrite( vuint32 addr, vuint8 data )
{
  *((vuint8*)addr) = data;
}
#endif

#if defined ( XCP_ENABLE_CALIBRATION_MEM_ACCESS_BY_APPL ) || defined ( XCP_ENABLE_MEM_ACCESS_BY_APPL )
  #if defined ( XCP_ENABLE_CHECKSUM )
     #if ( kXcpChecksumMethod == XCP_CHECKSUM_TYPE_ADD22 ) || \
         ( kXcpChecksumMethod == XCP_CHECKSUM_TYPE_ADD24 ) || \
         ( kXcpChecksumMethod == XCP_CHECKSUM_TYPE_ADD44 ) || \
         defined ( XCP_ENABLE_CALIBRATION_MEM_ACCESS_BY_APPL )
/*****************************************************************************
| NAME:             ApplXcpReadChecksumValue
| CALLED BY:        XCP Protocol Layer
| PRECONDITIONS:    none
| INPUT PARAMETERS: addr : 32 bit address
| RETURN VALUES:    Pointer to the address specified by the parameters. 
| DESCRIPTION:      Read and return memory with size of tXcpChecksumAddType.
******************************************************************************/
tXcpChecksumAddType ApplXcpReadChecksumValue( vuint32 addr )
{
  return *((tXcpChecksumAddType*)addr);
}  
    #endif
  #endif
#endif


#if defined ( XCP_ENABLE_CALIBRATION_MEM_ACCESS_BY_APPL ) && !defined ( XCP_ENABLE_MEM_ACCESS_BY_APPL )
/*****************************************************************************
| NAME:             ApplXcpCalibrationWrite
| CALLED BY:        XCP Protocol Layer
| PRECONDITIONS:    none
| INPUT PARAMETERS: addr : destination address
|                   size : length of data to write
|                   data : data to write
| RETURN VALUES:    XCP_CMD_OK or XCP_CMD_ERROR
| DESCRIPTION:      Write memory with size
******************************************************************************/
vuint8 ApplXcpCalibrationWrite(MTABYTEPTR addr, vuint8 size, const BYTEPTR data)
{
  while(size > (vuint8)0)
  {
    *addr = *data;
    addr++;
    data++;
    size--;
  }
  return (vuint8)XCP_CMD_OK;
}
/*****************************************************************************
| NAME:             ApplXcpCalibrationRead
| CALLED BY:        XCP Protocol Layer
| PRECONDITIONS:    none
| INPUT PARAMETERS: addr : source address
|                   size : length of data to read
|                   data : read data
| RETURN VALUES:    XCP_CMD_OK or XCP_CMD_ERROR
| DESCRIPTION:      Read and return memory with size
******************************************************************************/
vuint8 ApplXcpCalibrationRead(MTABYTEPTR addr, vuint8 size, BYTEPTR data)
{
  while(size > (vuint8)0)
  {
    *data = *addr;
    addr++;
    data++;
    size--;
  }
  return (vuint8)XCP_CMD_OK;
}
#endif



#if defined ( XCP_ENABLE_WRITE_PROTECTION )
/*****************************************************************************
| NAME:             ApplXcpCheckWriteAccess
| CALLED BY:        XcpWriteMta
| PRECONDITIONS:    none
| INPUT PARAMETERS: address : address
|                   size    : size of memory area
| RETURN VALUES:    XCP_CMD_DENIED : if access is denied
|                   XCP_CMD_OK     : if access is granted
| DESCRIPTION:      Check addresses for valid write access
|                   Used only, if write protection of memory areas is required
******************************************************************************/
  #if defined ( ApplXcpCheckWriteAccess ) /* defined as macro */
  #else

vuint8 ApplXcpCheckWriteAccess( const MTABYTEPTR address, vuint8 size )
{
  /* Protect variable xcp */
  vuint8 xcp;

  if (address+size>=(MTABYTEPTR)&xcp && address<(MTABYTEPTR)&xcp+sizeof(xcp))
  {
    return (vuint8)XCP_CMD_DENIED;
  }

  return (vuint8)XCP_CMD_OK;
}
  #endif  /* ApplXcpCheckWriteAccess */

#endif /* XCP_ENABLE_WRITE_PROTECTION */

#if defined ( XCP_ENABLE_READ_PROTECTION )
/*****************************************************************************
| NAME:             ApplXcpCheckReadAccess
| CALLED BY:        XcpReadMta
| PRECONDITIONS:    none
| INPUT PARAMETERS: address : address
|                   size    : size of memroy area
| RETURN VALUES:    XCP_CMD_DENIED : if access is denied
|                   XCP_CMD_OK     : if access is granted
| DESCRIPTION:      Check addresses for valid write access
|                   Used only, if write protection of memory areas is required
******************************************************************************/
  #if defined ( ApplXcpCheckReadAccess ) /* defined as macro */
  #else

vuint8 ApplXcpCheckReadAccess( const MTABYTEPTR address, vuint16 size )
{
  /* Protect variable xcp */
  vuint8 xcp;

  if (address+size>=(MTABYTEPTR)&xcp && address<(MTABYTEPTR)&xcp+sizeof(xcp))
  {
    return (vuint8)XCP_CMD_DENIED;
  }

  return (vuint8)XCP_CMD_OK;
}
  #endif  /* ApplXcpCheckReadAccess */
#endif /* XCP_ENABLE_READ_PROTECTION */


#if defined ( XCP_ENABLE_PROGRAMMING_WRITE_PROTECTION )
/*****************************************************************************
| NAME:             ApplXcpCheckProgramAccess
| CALLED BY:        XcpWriteMta
| PRECONDITIONS:    none
| INPUT PARAMETERS: address : address
|                   size    : size of memory area
| RETURN VALUES:    XCP_CMD_DENIED : if access is denied
|                   XCP_CMD_OK     : if access is granted
| DESCRIPTION:      Check addresses for valid programming access
|                   Used only, if programming write protection of memory areas is required
******************************************************************************/
  #if defined ( ApplXcpCheckProgramAccess ) /* defined as macro */
  #else
vuint8 ApplXcpCheckProgramAccess( MTABYTEPTR address, vuint32 size )
{
  /* something has to be done here */
  return (vuint8)XCP_CMD_OK;
}
  #endif  /* XcpHal_CheckProgramAccess */
#endif /* XCP_ENABLE_PROGRAMMING_WRITE_PROTECTION */


#if defined ( XCP_ENABLE_BOOTLOADER_DOWNLOAD )

/*****************************************************************************
| NAME:             ApplXcpDisableNormalOperation
| CALLED BY:        XcpCommand
| PRECONDITIONS:    none
| INPUT PARAMETERS: a    : address
|                   size : number of bytes
| RETURN VALUES:    XCP_CMD_OK or XCP_CMD_DENIED
| DESCRIPTION:      Initiate Flash Download
|                   Used only if Download of the Flash Kernel is required
******************************************************************************/
vuint8 ApplXcpDisableNormalOperation( MTABYTEPTR a, vuint16 size )
{
  /*
    CANape attempts to download the flash kernel to XCP_RAM.
    Address is a
    Size is size bytes
  */

  /* ... */

  /* return XCP_CMD_DENIED;    Refused */
  return (vuint8)XCP_CMD_OK;     /* Ok */
}


/*****************************************************************************
| NAME:             ApplXcpStartBootLoader
| CALLED BY:        XcpCommand
| PRECONDITIONS:    none
| INPUT PARAMETERS: none
| RETURN VALUES:    
| DESCRIPTION:      
******************************************************************************/
vuint8 ApplXcpStartBootLoader( void )
{

  /* ... */

  return (vuint8)XCP_CMD_DENIED;
}

#endif /* XCP_ENABLE_BOOTLOADER_DOWNLOAD */


#if defined ( XCP_ENABLE_WRITE_EEPROM )
/*****************************************************************************
| NAME:             ApplXcpCheckWriteEEPROM
| CALLED BY:        XcpWriteMta
| PRECONDITIONS:    none
| INPUT PARAMETERS: addr : address
|                   size : number of bytes
|                   data : pointer to data
| RETURN VALUES:    XCP_CMD_OK      : EEPROM written
|                   XCP_CMD_DENIED  : This is not EEPROM
|                   XCP_CMD_PENDING : EEPROM write in progress, call XcpSendCrm when done
| DESCRIPTION:      EEPROM Programming
******************************************************************************/
vuint8 ApplXcpCheckWriteEEPROM( MTABYTEPTR addr, vuint8 size, const BYTEPTR data )
{
  /* something has to be done here */

  return (vuint8)XCP_CMD_DENIED;
}
#endif

#if defined ( XCP_ENABLE_READ_EEPROM )
/*****************************************************************************
| NAME:             ApplXcpCheckReadEEPROM
| CALLED BY:        XcpReadMta
| PRECONDITIONS:    none
| INPUT PARAMETERS: addr : address
|                   size : number of bytes
|                   data : pointer to data
| RETURN VALUES:    0 (FALSE) : This is not EEPROM
|                   1 (TRUE)  : EEPROM read
| DESCRIPTION:      Read EEPROM
******************************************************************************/
vuint8 ApplXcpCheckReadEEPROM( MTABYTEPTR addr, vuint8 size, BYTEPTR data )
{
  /* something has to be done here */

  return (vuint8)XCP_CMD_DENIED;
}
#endif



/*****************************************************************************/
/* Seed & Key                                                                */
/* This is just an example how seed & key could be implemented.              */
/*****************************************************************************/
#if defined ( XCP_ENABLE_SEED_KEY )

/*****************************************************************************
| NAME:             ApplXcpGetSeed
| CALLED BY:        XcpCommand
| PRECONDITIONS:    none
| INPUT PARAMETERS: resource : resource
|                              (either RM_CAL_PAG or RM_DAQ or RM_STIM or RM_PGM)
|                   seed     : pointer to the generated seed.
| RETURN VALUES:    the length of the seed.
| DESCRIPTION:      Generates a seed.
|                   Attention: The seed has a maximum length of MAX_CTO-2 bytes.
******************************************************************************/
vuint8 ApplXcpGetSeed( const vuint8 resource, vuint8 *seed )
{
  /* Store resource mask */
  xcpResource = resource;

  /* Generate a seed */
  seed[0] = 0;
  seed[1] = 1;
  seed[2] = 2;
  seed[3] = 3;
  seed[4] = 4;
  seed[5] = 5;

  return (vuint8)6u;
}

/*****************************************************************************
| NAME:             ApplXcpUnlock
| CALLED BY:        XcpCommand
| PRECONDITIONS:    none
| INPUT PARAMETERS: key    : pointer to the key 
|                   length : length of the key
| RETURN VALUES:    0 : if the key is not valid
|                   RM_CAL_PAG, RM_DAQ, RM_STIM, RM_PGM : for valid keys
| DESCRIPTION:      Check key and return the resource that has to be unlocked.
******************************************************************************/
vuint8 ApplXcpUnlock( const vuint8 *key, const vuint8 length )
{
  /*
    Ckeck the key
    key[0],key[1],key[2],key[3],key[4],key[5]
  */

  return xcpResource;
}

#endif /* XCP_ENABLE_SEED_KEY */


/****************************************************************************/
/* GET_ID service                                                           */
/****************************************************************************/
#if defined ( XCP_ENABLE_VECTOR_MAPNAMES )

/*****************************************************************************
| NAME:             ApplXcpGetIdData
| CALLED BY:        XcpCommand
| PRECONDITIONS:    none
| INPUT PARAMETERS: pData : pointer to pointer of the MAP file names
| RETURN VALUES:    length of the MAP file names
| DESCRIPTION:      Returns a pointer to a pointer of MAP file names
******************************************************************************/
vuint32 ApplXcpGetIdData( MTABYTEPTR *pData)
{
    *pData = (MTABYTEPTR)xcpMapNames;

    return (vuint32)sizeof(xcpMapNames);
}

#endif /* XCP_ENABLE_VECTOR_MAPNAMES */


/****************************************************************************/
/* User defined service                                                     */
/****************************************************************************/
#if defined ( XCP_ENABLE_USER_COMMAND )

vuint8 ApplXcpUserService( const BYTEPTR pCmd )
{

  /* something has to be done here */

  return (vuint8)XCP_CMD_OK;
}

#endif


/****************************************************************************/
/* Open Command Interface                                                   */
/****************************************************************************/
#if defined ( XCP_ENABLE_OPENCMDIF )

vuint8 ApplXcpOpenCmdIf( const BYTEPTR pCmd, BYTEPTR pRes, BYTEPTR pLength )
{
  if(0xC1 == pCmd[0])
  {
    /* Implementation for XCP command 0xC1 has to be done here */
    pRes[1]  = 0x11; /* Set response */
    pRes[2]  = 0x22;
    *pLength = 3; /* Set response length */
    return (vuint8)XCP_CMD_OK;
  }
  return (vuint8)XCP_CMD_UNKNOWN;
}

#endif





/****************************************************************************/
/* ApplXcpSendStall                                                             */
/****************************************************************************/

#if defined ( XCP_ENABLE_SEND_EVENT ) || defined ( XCP_ENABLE_SERV_TEXT_PUTCHAR )
  #if defined ( ApplXcpSendStall )
 /* ApplXcpSendStall is already defined or a macro */
  #else
vuint8 ApplXcpSendStall( void )
{
  /* something has to be done here */

  return( (vuint8) 1u );
}
  #endif
#endif


