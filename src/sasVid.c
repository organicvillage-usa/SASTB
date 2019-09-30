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
****     ***    FILE: sasVid.c 
****    ***** 
 *     ****  ** Brief:  Run video operations like play, pause
**    ****    * stop, init etc.,
**    ***    **
 *   ****    *  Modification History
 *******   **** 01-Jan-20120 - MOTHI
   ****/
  
#include "sasVid.h"
#include <pthread.h>
SasRetCode
sas_vidInit(int numTokens, char **token)
{
    SasRetCode retVal = SAS_FAIL;
    int vid_status = 0;
    
    if(vid_status != SAS_SUCCESS)
    {
        SAS_ERROR("------Video Intialization failed ------\n");
        return SAS_FAIL;
    }
    return vid_status;
}

SasRetCode
sas_vidUninit(int numTokens, char **token)
{
    SasRetCode retVal = SAS_FAIL;
    int vid_status = 0;
    
    if(vid_status != SAS_SUCCESS)
    {
        SAS_ERROR("------Video UnIntialization failed ------\n");
        return SAS_FAIL;
    }
    return vid_status;
}

SasRetCode
sas_vidPlay(int numTokens, char **token)
{
    SasRetCode retVal = SAS_FAIL;
    int vid_status = 0;
    
    if(vid_status != SAS_SUCCESS)
    {
        SAS_ERROR("------Video Play failed ------\n");
        return SAS_FAIL;
    }
    return vid_status;
}

SasRetCode
sas_vidPause(int numTokens, char **token)
{
    SasRetCode retVal = SAS_FAIL;
    int vid_status = 0;
    
    if(vid_status != SAS_SUCCESS)
    {
        SAS_ERROR("------Video Pause failed ------\n");
        return SAS_FAIL;
    }
    return vid_status;
}

SasRetCode
sas_vidStop(int numTokens, char **token)
{
    SasRetCode retVal = SAS_FAIL;
    int vid_status = 0;
    
    if(vid_status != SAS_SUCCESS)
    {
        SAS_ERROR("------Video Stop failed ------\n");
        return SAS_FAIL;
    }
    return vid_status;
}
