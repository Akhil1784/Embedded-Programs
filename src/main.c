//**************************** String Sort ************************************
//  Copyright (c) 2026 Trenser
//  All Rights Reserved
//*****************************************************************************

//******************************* Include Files *******************************
#include <stdio.h>
#include <string.h>
#include <strings.h>  
#include "platformTypes.h"

//***************************** Global Constants ******************************

//***************************** Local Constants *******************************
#define STR_MAX_NAMES        (5U)
#define STR_MAX_NAME_LEN     (50U)
#define STR_NO_VALUE         (0)    
#define STR_INDEX_START      (0U)
#define STR_LIMIT_VAL        49
#define STR_HELPER(x)        #x
#define STR_TO_STR(x)        STR_HELPER(x)
#define STR_FMT_SPEC         "%" STR_TO_STR(STR_LIMIT_VAL) "s"

//***************************** Global Variables ******************************

//***************************** Type Definitions ******************************
static void SortNames(const char* apcNames[], uint32 ulCount);
static bool RunStringDemo(void);

//******************************.FUNCTION_HEADER.******************************
// Purpose  : Sorts an array of string pointers in ascending order using 
//            case-insensitive comparison.
// Inputs   : apcNames - Array of pointers to the strings.
//            ulCount  - Total number of elements to be sorted.
// Outputs  : None.
// Return   : None.
//*****************************************************************************
static void SortNames(const char* apcNames[], uint32 ulCount)
{
    uint32  ulOuter = STR_INDEX_START;
    uint32  ulInner = STR_INDEX_START;
    const char* pcTemp  = NULL;

    for( ulOuter = STR_INDEX_START; ulOuter < (ulCount - 1); ulOuter++ )
    {
        for( ulInner = STR_INDEX_START; ulInner < (ulCount - ulOuter - 1); ulInner++ )
        {
            if( strcasecmp(apcNames[ulInner], apcNames[ulInner + 1]) > STR_NO_VALUE )
            {
                pcTemp = apcNames[ulInner];
                apcNames[ulInner] = apcNames[ulInner + 1];
                apcNames[ulInner + 1] = pcTemp;
            }
        }
    }
}

//******************************.FUNCTION_HEADER.******************************
// Purpose  : Coordinates user input for names, maps them to pointers, 
//            and triggers the sorting demonstration.
// Inputs   : None.
// Outputs  : None.
// Return   : bool - TRUE if all inputs were valid and process completed, 
//                   else FALSE.
//*****************************************************************************
static bool RunStringDemo(void)
{
    char acNameStorage[STR_MAX_NAMES][STR_MAX_NAME_LEN] = {{STR_NO_VALUE}};
    const char* apcNames[STR_MAX_NAMES];
    uint32 ulIdx    = STR_INDEX_START;
    bool blStatus = FALSE; 

    printf("Enter %u names:\n", STR_MAX_NAMES);

    for( ulIdx = STR_INDEX_START; ulIdx < STR_MAX_NAMES; ulIdx++ )
    {
        printf("Name %u: ", ulIdx + 1);

        if( 1 == scanf(STR_FMT_SPEC, acNameStorage[ulIdx]) )
        {
            apcNames[ulIdx] = acNameStorage[ulIdx];
            blStatus = TRUE;
        }
        else
        {
            blStatus = FALSE;
            break;
        }
    }

    if( TRUE == blStatus )
    {
        SortNames(apcNames, STR_MAX_NAMES);

        printf("\nSorted Names (Ascending):\n");
        for ( ulIdx = STR_INDEX_START; ulIdx < STR_MAX_NAMES; ulIdx++ )
        {
            printf("%u. %s\n", ulIdx + 1, apcNames[ulIdx]);
        }
    }

    return blStatus;
}

//******************************.FUNCTION_HEADER.******************************
// Purpose  : Main entry point. Executes simulation and monitors success.
// Inputs   : None.
// Outputs  : None.
// Return   : int - 0 (STR_NO_VALUE) on successful execution.
//*****************************************************************************
int main(void)
{
    int iRetVal = STR_NO_VALUE;

    if ( TRUE != RunStringDemo() )
    {
        printf("Error: Input processing failed.\n");
        iRetVal = 1; 
    }

    return iRetVal;
}