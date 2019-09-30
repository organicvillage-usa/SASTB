/***     ***
***    ***** 
 *     ****  ** Copyright (c) 2020 SaS Inc. 
**    ****    * ALL RIGHTS RESERVED
**    ***    **
 *   ****    *  Use the software for the sole purpose of
 *******   **** implementing SaS Inc licensee product. 
   ****          
    **          Strictly no other rights to reproduce this
  ******   **   program whether in part or as whole.
 **   ***  **** 
**     **     * SaS Inc. makes no representation/warranties
 *     *     ** and specifically disclaims any responsibility
  ************* for any damages, special or consequential
*************   connected with the use of this program.
**
****     ***    FILE: sasHelp.h 
****    ***** 
 *     ****  ** Brief: 
**    ****    *
**    ***    **
 *   ****    *  Modification History
 *******   **** 01-Jan-20120 - MOTHI
   ****/


#ifndef _SAS_VIDL_H
#define _SAS_VID_H
#include "SasGlobal.h"

SasRetCode
sas_vidInit(int numtokens, char **tokens);

SasRetCode
sas_vidUninit(int numtokens, char **tokens);

SasRetCode
sas_vidPlay(int numtokens, char **tokens);

SasRetCode
sas_vidPause(int numtokens, char **tokens);

SasRetCode
sas_vidStop(int numtokens, char **tokens);

#endif	/* _SAS_VID_H */

#ifdef	__cplusplus
extern "C" {
#endif

#ifdef	__cplusplus
}
#endif



