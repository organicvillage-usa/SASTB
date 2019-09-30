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
****     ***    FILE: sasMain.c
****    ***** 
 *     ****  ** Brief: Main program
**    ****    *
**    ***    **
 *   ****    *  Modification History
 *******   **** 01-Jan-20120 - MOTHI
   ****/

#include "sasMain.h"
#include "sasThread.h"
#include "sasDispatcher.h"

/*#define USE_EDITLINE*/

char PRINT_BUFF[MAX_LINE_SIZE];

/* Print a welcome screen */
static void 
sas_printWelcomeMessage()
{
  SAS_PRINTF("\r\n------------------------------------------------\r\n");
  SAS_PRINTF("\r\n================************====================\r\n");
  SAS_PRINTF("\r\n\t WELCOME TO SAS TEST BENCH\r\n");
  SAS_PRINTF("\r\n===============*************====================\r\n");
  SAS_PRINTF("\r\n------------------------------------------------\r\n");
}

/* Check whether an exit command has come */
static SasBool
sas_quit(char *buff)
{
  if (NULL == buff)
    return SAS_FALSE;
  else if ('z' == buff[0])
    return SAS_TRUE;
  else if (0 == strcmp("exit", buff))
    return SAS_TRUE;
  else
    return SAS_FALSE;
}

/* Reports status back to the user */
void
sas_reportStatus(SasRetCode rc, char *str)
{
  char *buff;

  if (SAS_SUCCESS == rc)
    buff = "PASS";
  else if (SAS_PNDG == rc)
    buff = "PNDG";
  else
    buff = "FAIL";

  SAS_PRINTF("%s: %s\n", buff, str);
}

/* Reads from a file until end of line */
static int
sas_readFile(FILE *fp, char *line)
{
  int nBytes=0;
  char *buff=NULL;

  ASSERT(fp);
  ASSERT(line);

  buff = fgets(line, MAX_LINE_SIZE, fp);
  if (NULL == buff)
    nBytes = SAS_FAIL;
  else
  {
    nBytes = strlen(buff)-1;
    buff[nBytes] = 0;
  }

  if (nBytes > 0)
    SAS_PRINTF("%s\n ", line);

  SAS_DEBUG("Read line : %s, %d\n", line, nBytes);
  return nBytes;
}
  

/* Reads from host interface until a new line */

static int
sas_readLine(char *line)
{
  int i=SAS_FAIL;
  char *buff=NULL, outchar[2];

  if (NULL == line)
  {
    SAS_ERROR("Cannot read to a NULL pointer\n");
    return i;
  }

  memset(line, 0, MAX_LINE_SIZE);

#ifndef USE_EDITLINE
  SAS_PROMPT();

  for(i=0; i<MAX_LINE_SIZE; i++)
  {
    line[i] = fgetc(stdin);

    if( line[i] == '\n'|| line[i] == '\r')
    {
      SAS_PRINTF("\n\r");
      SAS_FLUSH();
      break;
    }

    outchar[1] = '\0';                   
    outchar[0] = line[i];

    if (BS_CHAR == line[i])
    {
      SAS_PRINTF((char *)outchar);
      SAS_PRINTF(SPACE_CHAR);
      if (i >= 1)
      {   /* If cmd lines chars >=1, get rid of the char */
        i -= 2;
        SAS_PRINTF((char *)outchar);
        SAS_FLUSH();
      }   /* backspace at first cmd line char, just ignore */
      else
        i--;
      continue;
    }

    /* If this is not an ESC char, nor the previous one, print out char */
    if (outchar[0] != 0x1b && line[i-1] != 0x1b)
    {
      SAS_PRINTF(outchar);
      SAS_FLUSH();
    }
  }

  line[i] = 0;
#else

  buff = readline(MXL_PROMPT);
  if (NULL != buff && 0 != buff[0])
  {
    i = strlen(buff);
    strncpy(line, buff, i);
    add_history(line);
    free(buff);
  }
  else
    i=0;
#endif

  return i;
}

 
/* Parse the input line into tokens */
static int
sas_tokenize(char *buff, char **tokens)
{
  int numTokens=0;

  while((*buff != NULL) && (numTokens < MAX_TOKENS))
  {
    while((*buff == ' ') || (*buff == '\t') || (*buff =='\n'))
      *buff++ = NULL;

    if (NULL == *buff)
      break;
    
    *tokens++ = buff;
    numTokens++;

    while((*buff != NULL) && (*buff !=' ') && (*buff != '\t') && (*buff != '\n'))
      buff++;
  }

  *tokens=NULL;
  return numTokens;
}

static void
wait_for_threads()
{
  int i=0;

  for (i=0; i<MAX_THREADS; i++)
    if (TH[i].inUse)
      pthread_join(TH[i].thrId, NULL);
}

int main(int argc , char *argv[])
{
  SasRetCode rc=SAS_FAIL;
  char buff[MAX_LINE_SIZE], *parsedTokens[MAX_TOKENS];
  char lcmd[MAX_LINE_SIZE];
  
  FILE *fp=NULL;
  char *script=NULL;
  SasBool useScript=SAS_FALSE;
  int i=0, j=0, count=0, nBytes=0, numTokens=0;

  if (argc >= 3)
  {
    if (0 == strcmp(argv[1], "-s"))
    {
      script = argv[2];
      useScript = SAS_TRUE;
    }
  }

  if (useScript)
  {
    fp = fopen(script, "r");
    ASSERT(fp);
  }

  sas_initThr();

  if (!useScript)
    sas_printWelcomeMessage();

  SAS_FLUSH();

  while (SAS_TRUE)
  {
    SAS_PRINTF("\n");
    memset(buff, 0, MAX_LINE_SIZE);
    if (useScript)
      nBytes = sas_readFile(fp, buff);
    else
      nBytes = sas_readLine(buff);

    if (SAS_FAIL == nBytes)
      break;

    if ('#'==buff[0] || 0==nBytes || 0==buff[0])
      continue;
    if ('!'==buff[0])
    {
        SAS_PRINTF("Executing Linux command ......\n");
        for (i=1,j=0; i <= nBytes; i++,j++ )
            lcmd[j] = buff[i];
        lcmd[j] = '\0';
        system(lcmd);
        continue;
    }

    if ( sas_quit(buff) )
    {
      SAS_PRINTF("Exiting .......\n");
      break;
    }
    if (0 == strcmp(buff,"board"))
    {
        useScript = 0;
        sas_printWelcomeMessage();
        continue;
    }

    numTokens = sas_tokenize(buff, parsedTokens);
    if (0 == numTokens)
      continue;

    if (0 == strcmp(parsedTokens[0],"run"))
    {
        if (NULL != parsedTokens[1])
        {
            script = parsedTokens[1];
            fp =fopen(script,"r");
            if(!fp)
            {
                SAS_PRINTF("Check the file name....");
                continue;
            }
            useScript = SAS_TRUE;
        }
        continue;
    }

    if ( 0 ==  strcmp(parsedTokens[0],"sleep"))
    {
        if(parsedTokens[1])
            sleep(atoi(parsedTokens[1]));
        continue;
    }
   
    if ( 0 ==  strcmp(parsedTokens[0],"help"))
    {
        if(1 == numTokens)
        {
            rc = sas_help(numTokens,parsedTokens);
            continue;
        }

    }

    rc = sas_execute(numTokens, parsedTokens);
    sas_reportStatus(rc, parsedTokens[0]);
  }

  wait_for_threads();

  return (EXIT_SUCCESS);
}
