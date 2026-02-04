//**************************** TRENSER EMBEDDED ******************************
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

//***************************** Local Constants *******************************
#define ASCII_CASE_OFFSET  32U

//******************************.FUNCTION_HEADER.******************************
//Purpose : Converts all lowercase alphabetic characters to uppercase.
//Inputs  : pucString - Pointer to the character buffer to be modified.
//          ulLength  - The number of characters to process in the buffer.
//Outputs : pucString content is modified in place.
//Note    : Uses ASCII arithmetic logic (Subtracting 32).
//*****************************************************************************
void ConvertToUpper(uint8* pucString, uint32 ulLength)
{
    if (NULL != pucString)
    {
        for (uint32 ulIdx = 0; ulIdx < ulLength; ulIdx++)
        {
            if ((pucString[ulIdx] >= 'a') && (pucString[ulIdx] <= 'z'))
            {
                pucString[ulIdx] = pucString[ulIdx] - ASCII_CASE_OFFSET;
            }
        }
    }
}

//******************************.FUNCTION_HEADER.******************************
//Purpose : Converts all uppercase alphabetic characters to lowercase.
//Inputs  : pucString - Pointer to the character buffer to be modified.
//          ulLength  - The number of characters to process in the buffer.
//Outputs : pucString content is modified in place.
//Note    : Uses ASCII arithmetic logic (Adding 32).
//*****************************************************************************
void ConvertToLower(uint8* pucString, uint32 ulLength)
{
    if (NULL != pucString)
    {
        for (uint32 ulIdx = 0; ulIdx < ulLength; ulIdx++)
        {
            if ((pucString[ulIdx] >= 'A') && (pucString[ulIdx] <= 'Z'))
            {
                pucString[ulIdx] = pucString[ulIdx] + ASCII_CASE_OFFSET;
            }
        }
    }
}
// EOF