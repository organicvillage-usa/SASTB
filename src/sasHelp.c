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
  
#include "sasHelp.h"

SasRetCode
sas_help(int numTokens,char **tokens)
{
    SasRetCode retVal = SAS_SUCCESS;
    if(0 == numTokens)
    {
        SAS_PRINTF("\nUsage of HELP Command \nSyntax> help <command> \
                \n\t[command]--\t<video> <audio> <demux> <lnx> \
                \n\t\"sleep\"--\tsleep <seconds>\
                \n\t\"board\"--\tno arguments- retain control back to Application\
                \n\t\"exit\" --\texit from the application \n");
    }
    else if( 0 == strcmp(tokens[0],"video"))
    {
        CMD_VID_INIT;
        CMD_VID_UNINIT;
        CMD_VID_PLAY;
        CMD_VID_PAUSE;
    }
    
    else
    {
        SAS_PRINTF("\nUsage of HELP Command \nSyntax> help <command> \
                \n\t[command]--\t<video> <audio> <demux> <lnx> \
                \n\t\"sleep\"--\tsleep <seconds>\
                \n\t\"board\"--\tno arguments- retain control back to Application\
                \n\t\"exit\" --\texit from the application \n");
    }
    return retVal;
}


