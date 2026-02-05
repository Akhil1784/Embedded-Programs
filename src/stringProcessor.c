//**************************** StringProcess **********************************
//  Copyright (c) 2026 Trenser
//  All Rights Reserved
//*****************************************************************************
// 
// File    : stringProcessor.c
// Summary : Logic for string casing conversion.
// Note    : Follows Trenser routine naming (CapitalizedFirstLetter).
// 
//*****************************************************************************

//******************************* Include Files *******************************
#include <stdio.h>
#include <ctype.h>
#include "stringProcessor.h"

//***************************** Global Constants ******************************

//***************************** Local Constants *******************************
#define ASCII_CASE_OFFSET  32U

//***************************** Global Variables ******************************

//******************************.FUNCTION_HEADER.******************************
// Purpose : Converts all lowercase alphabetic characters to uppercase.
// Inputs  : pucString - Pointer to the character buffer to be modified.
//           usLength  - The number of characters to process (uint16).
// Outputs : Modifies the content of pucString in-place by changing 
//           lowercase characters to uppercase.
// Return  : bool - TRUE if the string was processed successfully.
//                  FALSE if the input pointer (pucString) is NULL.
// Note    : Uses ASCII arithmetic logic (Subtracting 32).
//*****************************************************************************
bool StringProcessorConvertToUpper(uint8* pucString, uint16 usLength)
{
    bool bStatus = FALSE;
    uint16 usIdx = 0; 

    if (NULL != pucString)
    {
        for (usIdx = 0; usIdx < usLength; usIdx++)
        {
            if ((pucString[usIdx] >= 'a') && (pucString[usIdx] <= 'z'))
            {
                pucString[usIdx] = pucString[usIdx] - (uint8)ASCII_CASE_OFFSET;
            }
        }
        bStatus = TRUE;
    }

    return bStatus;
}

//******************************.FUNCTION_HEADER.******************************
// Purpose : Converts all uppercase alphabetic characters to lowercase.
// Inputs  : pucString - Pointer to the character buffer to be modified.
//           usLength  - The number of characters to process (uint16).
// Outputs : The buffer pointed to by pucString is modified in-place.
// Return  : bool - TRUE if processing was successful, 
//                  FALSE if pucString is NULL.
// Note    : Uses ASCII arithmetic logic (Adding 32).
//*****************************************************************************
bool StringProcessorConvertToLower(uint8* pucString, uint16 usLength)
{
    bool bStatus = FALSE;
    uint16 usIdx = 0;

    if (NULL != pucString)
    {
        for (usIdx = 0; usIdx < usLength; usIdx++)
        {
            if ((pucString[usIdx] >= 'A') && (pucString[usIdx] <= 'Z'))
            {
                pucString[usIdx] = pucString[usIdx] + (uint8)ASCII_CASE_OFFSET;
            }
        }
        bStatus = TRUE;
    }

    return bStatus;
}

//***************************** Local Constants *******************************
#define ASCII_CASE_OFFSET  32U

//***************************** Global Variables ******************************

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
