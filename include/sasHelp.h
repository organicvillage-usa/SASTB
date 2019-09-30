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
 *     ****  ** Brief: Syntax help used in SAS-TB (test bench)
**    ****    *
**    ***    **
 *   ****    *  Modification History
 *******   **** 01-Jan-20120 - MOTHI
   ****/

#ifndef _SAS_HELP_H
#define _SAS_HELP_H

#include "SasGlobal.h"
/*Command usage for Video component*/
#define CMD_VID_INIT          SAS_PRINTF("Syntax> video init\n")
#define CMD_VID_UNINIT        SAS_PRINTF("Syntax> video uninit\n")
#define CMD_VID_PAUSE         SAS_PRINTF("Syntax> video pause\n")
#define CMD_VID_PLAY          SAS_PRINTF("Syntax> video play\n")

/*Command usage for debug print and assert*/
#define CMD_DEBUG_PRINT       SAS_PRINTF("Syntax> debug print\n")
#define CMD_DEBUG_ASSERT      SAS_PRINTF("Syntax> debug assert\n")

/*SasRetCode sas_help(int numTokens,char **tokens);*/

#endif	/* _SAS_HELP_H */

#ifdef	__cplusplus
extern "C" {
#endif

#ifdef	__cplusplus
}
#endif
