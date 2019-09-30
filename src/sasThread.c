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
 *     ****  ** Brief: Thread operation like Init,Free and 
**    ****    * getFree threads
**    ***    **
 *   ****    *  Modification History
 *******   **** 01-Jan-20120 - MOTHI
   ****/
  
#include "sasThread.h"

SasThreadInfo TH[MAX_THREADS];

void
sas_initThr()
{
  int i=0;
  for (i=0; i<MAX_THREADS;i++)
  {
    ZERO(TH[i]);
    TH[i].inUse = SAS_FALSE;
    pthread_attr_init(&TH[i].attr);
    pthread_attr_setschedpolicy(&TH[i].attr, SCHED_RR);
  }
}

SasRetCode
sas_getFreeThr(unsigned int *index)
{
  int i=0;

  for (i=0; i<MAX_THREADS; i++)
  {
    if (! TH[i].inUse)
    {
      *index = i;
      TH[i].inUse = SAS_TRUE;
      //memcpy(&(TH[i].g), G, sizeof(SasGlobalParams));
      return SAS_SUCCESS;
    }
  }

  return SAS_FAIL;
}

void
sas_freeThr(SasThreadInfo *T)
{
  T->inUse = SAS_FALSE;
}
