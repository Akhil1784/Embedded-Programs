//**************************** StringProcess **********************************
//  Copyright (c) 2026 Trenser
//  All Rights Reserved
//*****************************************************************************
// 
// File    : main.c
// Summary : Entry point for the string program simulation.
// Note    : Demonstrates static/dynamic arrays and Trenser variable naming.
// 
//*****************************************************************************

//******************************* Include Files *******************************
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stringProcessor.h"

//**************************** Forward Declarations ***************************
static bool StringProcessorStatic(STRING_MANAGER* pstManager, 
                                                          const char* pcInput);
static bool StringProcessorDynamic(STRING_MANAGER* pstManager, 
                                                          const char* pcInput);

//***************************** Global Constants ******************************

//***************************** Local Constants *******************************
#define TEST_INPUT_STRING    "Trenser String Test"

//***************************** Global Variables ******************************

//******************************.FUNCTION_HEADER.******************************
// Purpose : Main entry point for the application.
// Inputs  : None.
// Outputs : Console logs of string processing results.
// Return  : int - 0 on successful execution, 1 if processing errors occurred.
//*****************************************************************************

int main(void)
{
    STRING_MANAGER stManager;
    const char* pcInput = TEST_INPUT_STRING;
    bool bStaticStatus  = FALSE;
    bool bDynamicStatus = FALSE;
    int iReturnStatus   = 0;
    stManager.ulStringLength = (uint32)strlen(pcInput);
    stManager.pucDynamicBuffer = NULL;
    bStaticStatus  = StringProcessorStatic(&stManager, pcInput);
    bDynamicStatus = StringProcessorDynamic(&stManager, pcInput);
    
    if ((TRUE != bStaticStatus) || (TRUE != bDynamicStatus))
    {
        printf("Application finished with processing errors.\n");
        iReturnStatus = 1;
    }
    else
    {
        printf("Application finished successfully.\n");
        iReturnStatus = 0;
    }

    return iReturnStatus;
}

//******************************.FUNCTION_HEADER.******************************
// Purpose : Handles string processing using the internal static buffer.
// Inputs  : pstManager - Pointer to the STRING_MANAGER structure.
//           pcInput    - Pointer to the source constant string.
// Outputs : Returns TRUE if processed successfully, FALSE otherwise.
// Note    : Validates buffer size against MAX_STATIC_SIZE before copy.
//*****************************************************************************
bool StringProcessorStatic(STRING_MANAGER* pstManager, const char* pcInput)
{
    bool bStatus = FALSE;

    if ((NULL != pstManager) && (NULL != pcInput) && 
        (pstManager->ulStringLength < MAX_STATIC_SIZE))
    {
        memcpy(pstManager->pucStaticBuffer, pcInput, pstManager->ulStringLength + 1);
        bStatus = StringProcessorConvertToUpper(pstManager->pucStaticBuffer, 
                                           (uint16)pstManager->ulStringLength);
                                  
        if (TRUE == bStatus)
        {
            printf("Static Upper : %s\n", pstManager->pucStaticBuffer);
        }
        else
        {
            printf("Error: Static string conversion logic failed.\n");
        }
    }
    else
    {
        printf("Error: Invalid static buffer parameters or size overflow.\n");
    }

    return bStatus;
}

//******************************.FUNCTION_HEADER.******************************
// Purpose : Handles string processing using dynamic memory allocation.
// Inputs  : pstManager - Pointer to the STRING_MANAGER structure.
//           pcInput    - Pointer to the source constant string.
// Outputs : Returns TRUE if processed successfully, FALSE otherwise.
// Note    : Responsibly allocates and frees memory; checks conversion status.
//*****************************************************************************
bool StringProcessorDynamic(STRING_MANAGER* pstManager, const char* pcInput)
{
    bool bStatus = FALSE;

    if ((NULL != pstManager) && (NULL != pcInput))
    {
        pstManager->pucDynamicBuffer = (uint8*)malloc((pstManager->ulStringLength + 1) 
                                                      * sizeof(uint8));

        if (NULL != pstManager->pucDynamicBuffer)
        {
            memcpy(pstManager->pucDynamicBuffer, pcInput, pstManager->ulStringLength + 1);
            bStatus = StringProcessorConvertToLower(pstManager->pucDynamicBuffer,
                                           (uint16)pstManager->ulStringLength);
            
            if (TRUE == bStatus)
            {
                printf("Dynamic Lower: %s\n", pstManager->pucDynamicBuffer);
            }
            else
            {
                printf("Error: Dynamic string conversion logic failed.\n");
            }
            free(pstManager->pucDynamicBuffer);
            pstManager->pucDynamicBuffer = NULL;
        }
        else
        {
            printf("Error: Memory allocation failed.\n");
        }
    }

    return bStatus;
}

// EOF
