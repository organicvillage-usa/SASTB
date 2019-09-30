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
****     ***    FILE: sasDispatcher.h 
****    ***** 
 *     ****  ** Brief: Header file used by dispatcher.c
**    ****    *
**    ***    **
 *   ****    *  Modification History
 *******   **** 01-Jan-20120 - MOTHI
   ****/

#ifndef _SAS_DISPATCHER_H
#define _SAS_DISPATCHER_H

#include "sasGlobal.h"

#define CMD_POS         (0)

SasRetCode
sas_Execute(int cmd, char **tokens);

#endif

#ifdef	__cplusplus
extern "C" {
#endif

#ifdef	__cplusplus
}
#endif

