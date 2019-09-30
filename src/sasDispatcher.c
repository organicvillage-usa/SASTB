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
****     ***    FILE: sasDispatcher.c 
****    ***** 
 *     ****  ** Brief: Parse instruction into dispatchable 
**    ****    * command tokens 
**    ***    **
 *   ****    *  Modification History
 *******   **** 01-Jan-20120 - MOTHI
   ****/

#include "sasDispatcher.h"
#include "sasVid.h"
#include "sasHelp.h"

typedef SasRetCode (* sasCmd)(int numTokens, char **tokens);

typedef struct
{
    char key[MAX_NAME_LEN];
    char cmdName[MAX_NAME_LEN];
    sasCmd dptr;
} SasExecTable;

static SasExecTable sasCmdArr[] =
{
    {"video", "init", sas_vidInit},
    {"video", "uninit", sas_vidUninit},
    {"video", "play", sas_vidPlay},
    {"video", "pause", sas_vidPause},
    {"video", "stop", sas_vidStop},
    /*Service Information modules*/
    /* Scanning the channel/information */
    /*{"play", "audvid", sas_playAudVid},*/

    /* Application Specific functionalities */
    
};

unsigned int SAS_CMD_NUM = sizeof(sasCmdArr)/sizeof(SasExecTable);

SasRetCode
sas_execute(int numTokens, char **tokens)
{
    SasRetCode retVal=SAS_FAIL;
    int i=0;
    if (numTokens <= 1)
    {
        retVal = sas_help(numTokens,tokens);
        return retVal;
    }
    else if(0 == strcmp(*tokens,"help"))
    {
        retVal = sas_help(numTokens-1, ++tokens);
        return retVal;
    }
    else
    {
        for (i=0; i<SAS_CMD_NUM; i++)
        {
            if (0 == strcmp(*tokens, sasCmdArr[i].key))
            {
                if (0 == strcmp("ignore", sasCmdArr[i].cmdName))
                {
                    if (NULL == sasCmdArr[i].dptr)
                        retVal = SAS_NOTSUPPORTED;
                    else
                        retVal = sasCmdArr[i].dptr(numTokens-1, ++tokens);
                    return retVal;
                }
                if (0 == strcmp(tokens[1], sasCmdArr[i].cmdName))
                {
                    if (NULL == sasCmdArr[i].dptr)
                        retVal = SAS_NOTSUPPORTED;
                    else
                        retVal = sasCmdArr[i].dptr(numTokens-1, ++tokens);
                    return retVal;
                }
            }
        }
    }

    SAS_ERROR("Command <%s> invalid\n", *tokens);
    return retVal;
}
