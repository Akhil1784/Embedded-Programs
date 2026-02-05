//**************************** StringProcess **********************************
//  Copyright (c) 2026 Trenser
//  All Rights Reserved
//*****************************************************************************
// 
// File    : StringProcessor.c
// Summary : Logic for string casing conversion.
// Note    : Follows Trenser routine naming (CapitalizedFirstLetter).
// 
//*****************************************************************************

//******************************* Include Files *******************************
#include <stdio.h>
#include <ctype.h>
#include "StringProcessor.h"

//***************************** Global Constants ******************************

//***************************** Local Constants *******************************
#define ASCII_CASE_OFFSET  32U

//***************************** Global Variables ******************************

//******************************.FUNCTION_HEADER.******************************
// Purpose : Converts all lowercase alphabetic characters to uppercase.
// Inputs  : pucString - Pointer to the character buffer to be modified.
//           usLength  - The number of characters to process (uint16).
// Outputs : Returns TRUE if processing was successful, FALSE if pucString is NULL.
// Note    : Uses ASCII arithmetic logic (Subtracting 32).
//*****************************************************************************
bool StringProcessorConvertToUpper(uint8* pucString, uint16 usLength)
{
    bool bStatus = FALSE;
    uint16 usIdx = 0; /* Declared at start of function */

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
// Outputs : Returns TRUE if processing was successful, FALSE if pucString is NULL.
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
// EOF