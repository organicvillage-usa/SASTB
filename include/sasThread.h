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
****     ***    FILE: sasThread.h 
****    ***** 
 *     ****  ** Brief: struct 
**    ****    *
**    ***    **
 *   ****    *  Modification History
 *******   **** 01-Jan-20120 - MOTHI
   ****/

#ifndef _SAS_THREAD_H
#define _SAS_THREAD_H

#include "SasGlobal.h"
#include <pthread.h>

#define MAX_THREADS             (5)

typedef struct
{
  SasBool inUse;
  pthread_t thrId;
  pthread_attr_t attr;
  /*SasGlobalParams g;*/
  FILE *sourceFp;
  FILE *targetFp;  
} SasThreadInfo;

extern SasThreadInfo TH[MAX_THREADS];

void
sas_initThr();

SasRetCode
sas_getFreeThr(unsigned int *index);

void
sas_freeThr(SasThreadInfo *T);

#endif

#ifdef	__cplusplus
extern "C" {
#endif

#ifdef	__cplusplus
}
#endif

