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
****     ***    FILE: sasFuncDispatcher.h 
****    ***** 
 *     ****  ** Brief: header file used by sasFuncDispatcher.c
**    ****    *
**    ***    **
 *   ****    *  Modification History
 *******   **** 01-Jan-20120 - MOTHI
   ****/

#ifndef _SAS_FUNC_DISPATCHER_H
#define _SAS_FUNC_DISPATCHER_H

#include "sasGlobal.h"

SasRetCode
sas_FuncExecute(int numTokens, char **tokens);

#endif

#ifdef	__cplusplus
extern "C" {
#endif

#ifdef	__cplusplus
}
#endif
