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
****     ***    FILE: sasFuncDispatcher.c 
****    ***** 
 *     ****  ** Brief: File to dispatch all the functional commands
**    ****    *
**    ***    **
 *   ****    *  Modification History
 *******   **** 01-Jan-20120 - MOTHI
   ****/
   
#include "sasFuncDispatcher.h"
#include "sasThread.h"
#include <pthread.h>

typedef enum sasCmd 
{
  VIDDEC,
  VIDENC,
  AUDDEC,
  SPHDEC,
  SPHENC,
  MAX_FUNC_CMDS
} SasCmd;


SasRetCode
sas_funcExecute(int numTokens, char **tokens)
{
  SasRetCode retval=SAS_FAIL;
  int i=0;
  unsigned int thIndex=0;
  
  SAS_ERROR("Command <%s> need to support\n", *tokens);
  return retval;
}
