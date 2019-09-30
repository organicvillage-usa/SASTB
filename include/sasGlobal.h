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
****     ***    FILE: sasGlobal.h
****    ***** 
 *     ****  ** Brief: Contains enumerates, Macros, struct and
**    ****    * SAS prompt definitions  etc.,
**    ***    **
 *   ****    *  Modification History
 *******   **** 01-Jan-20120 - MOTHI
   ****/

#ifndef _SAS_GLOBAL_H
#define _SAS_GLOBAL_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include "readline.h"
#include "sasHelp.h"

#define MAX_KEY_SIZE            (16)
#define MAX_NAME_LEN            (64)
#define MAX_TOKENS              (2*4)
#define MAX_LINE_SIZE           (512)
#define MAX_MAL_BUFS            (3)
#define BS_CHAR                 (0x8)
#define SPACE_CHAR              (" ")

#define SAS_TB_PROMPT            "<SAS-TB> $ "
#define SOURCE_FILE_OPTION      "-s"
#define TARGET_FILE_OPTION      "-t"

#define ZERO(_x)                memset(&(_x), 0, sizeof(_x))

#define DIM(_x)                 (sizeof(_x)/sizeof(_x[0]))

/* Macro Definitions for logging */

#ifdef _SAS_DEBUG_
#define SAS_DEBUG(STR...)       printf("[SAS-DEBUG]: "__FILE__": " STR)
#else
#define SAS_DEBUG(STR...)
#endif
FILE *fp_log;


#define SAS_PROMPT()       printf("\n" SAS_TB_PROMPT)
#define SAS_FLUSH()        fflush(stdout)
#define SAS_PRINTF(STR...)      printf(STR)
#define SAS_OUT(STR...)         printf("[SAS-LOG]: "__FILE__": " STR)
#define SAS_ERROR(STR...)       fprintf(stderr, "[SAS-ERROR]: "__FILE__": " STR)
#define SAS_LOG(STR...)         fprintf(fp_log, STR)
#define SAS_PERROR(STR...)      { fprintf(stderr, "[SAS-ERROR]: " STR); \
                                  perror("Error :"); }

#define ASSERT(_x)              { if (!(_x)) { SAS_ERROR("Assertion Failed :"); SAS_PRINTF(#_x); SAS_PRINTF("\n"); return SAS_FAIL; } }
                                
typedef enum 
{
  SAS_FAIL         = -1,
  SAS_SUCCESS      = 0,
  SAS_PNDG         = 2,
  SAS_NOTSUPPORTED
} SasRetCode;

typedef enum
{
  SAS_FALSE = 0,
  SAS_TRUE = 1
} SasBool;

typedef enum
{
  SAS_PLAY = 0,
  SAS_CAPTURE = 1
} SasMode;

typedef struct
{
  unsigned int size;
  char *start;
} SasBuffer;

typedef struct
{
  unsigned int numBufs;
  char *bufs[MAX_MAL_BUFS];
  int bufSizes[MAX_MAL_BUFS];
} SasMalBuffer;

typedef SasRetCode (* SasDispatcher)(int numTokens, char **tokens);

typedef struct
{
  char key[MAX_KEY_SIZE];
  SasDispatcher dptr;
} SasExecInfo;

extern int errno;
extern char PRINT_BUFF[MAX_LINE_SIZE];

void
sas_ReportStatus(SasRetCode rc, char *str);

#endif

#ifdef	__cplusplus
extern "C" {
#endif

#ifdef	__cplusplus
}
#endif
