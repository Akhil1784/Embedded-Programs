//**************************** StringProcess **********************************
//  Copyright (c) 2026 Trenser
//  All Rights Reserved
//*****************************************************************************
// 
// File    : StringApp.c
// Summary : Implementation of static and dynamic buffer processing.
// 
//*****************************************************************************

//******************************* Include Files *******************************
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "StringApp.h"

//***************************** Global Constants ******************************

//***************************** Local Constants *******************************

//***************************** Global Variables ******************************

//******************************.FUNCTION_HEADER.******************************
// Purpose : Handles string processing using the internal static buffer.
// Inputs  : pstManager - Pointer to the STRING_MANAGER structure.
//           pcInput    - Pointer to the source constant string.
// Outputs : None.
// Note    : Validates buffer size against MAX_STATIC_SIZE before copy.
//*****************************************************************************
void StringAppProcessStatic(STRING_MANAGER* pstManager, const char* pcInput)
{
    bool bSuccess = FALSE;

    if ((NULL != pstManager) && (NULL != pcInput) && 
        (pstManager->ulStringLength < MAX_STATIC_SIZE))
    {
        memcpy(pstManager->pucStaticBuffer, pcInput, pstManager->ulStringLength + 1);
        bSuccess = StringProcessorConvertToUpper(pstManager->pucStaticBuffer, 
                                           (uint16)pstManager->ulStringLength);
                                  
        if (TRUE == bSuccess)
        {
            printf("Static Upper : %s\n", pstManager->pucStaticBuffer);
        }
        else
        {
            printf("Error: Static string conversion failed.\n");
        }
    }
}

//******************************.FUNCTION_HEADER.******************************
// Purpose : Handles string processing using dynamic memory allocation.
// Inputs  : pstManager - Pointer to the STRING_MANAGER structure.
//           pcInput    - Pointer to the source constant string.
// Outputs : None.
// Note    : Responsibly allocates and frees memory; checks conversion status.
//*****************************************************************************
void StringAppProcessDynamic(STRING_MANAGER* pstManager, const char* pcInput)
{
    bool bSuccess = FALSE;

    if ((NULL != pstManager) && (NULL != pcInput))
    {
        pstManager->pucDynamicBuffer = (uint8*)malloc((pstManager->ulStringLength + 1) 
                                                      * sizeof(uint8));

        if (NULL != pstManager->pucDynamicBuffer)
        {
            memcpy(pstManager->pucDynamicBuffer, pcInput, pstManager->ulStringLength + 1);
            bSuccess = StringProcessorConvertToLower(pstManager->pucDynamicBuffer,
                                           (uint16)pstManager->ulStringLength);
            
            if (TRUE == bSuccess)
            {
                printf("Dynamic Lower: %s\n", pstManager->pucDynamicBuffer);
            }
            else
            {
                printf("Error: Dynamic string conversion failed.\n");
            }
            free(pstManager->pucDynamicBuffer);
            pstManager->pucDynamicBuffer = NULL;
        }
        else
        {
            printf("Error: Memory allocation failed.\n");
        }
    }
}
// EOF