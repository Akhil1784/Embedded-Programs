//**************************** STRING EMBEDDED ********************************
//  Copyright (c) 2026 Trenser
//  All Rights Reserved
//*****************************************************************************
//
// File    : stringProcessor.c
// Summary : Implementation of string routines and task dispatcher.
// Note    : Adheres to Trenser Embedded Coding Standard V1.0.
//
//*****************************************************************************

//******************************* Include Files *******************************
#include <stdio.h>
#include <string.h>
#include "stringProcessor.h"

//******************************* Global Types ********************************

//***************************** Global Constants ******************************

//***************************** Local Constants *******************************
#define ASCII_CASE_OFFSET 32U 

//***************************** Global Variables ******************************

//****************************** Local Variables ******************************
static MY_STRUCT s_astTaskTable[] = 
{
    {OPTION_UPPER,   StringProcessorConvertToUpper},
    {OPTION_LOWER,   StringProcessorConvertToLower},
    {OPTION_CONCAT,  StringProcessorConcatenate},
    {OPTION_COMPARE, StringProcessorCompare}
}; 

//***************************** Type Definitions ******************************

//******************************.FUNCTION_HEADER.******************************
//Purpose: Manages user interaction and table-driven task execution for string operations.
//Inputs: None (Uses void for no arguments).
//Outputs: Displays menu, prompts for user input, and prints processing results to the console.
//Return: Returns true on successful completion of the routine.
//*****************************************************************************
bool StringProcessorExecutionManager(void)
{
    uint8  aucBuffer[MAX_STR_SIZE] = {0}; 
    uint32 unChoice = 0; 
    uint32 ulIdx = 0;    
    uint32 ulTaskCount = (sizeof(s_astTaskTable) / sizeof(s_astTaskTable[0]));
    bool   blStatus = false;

    do 
    {
        printf("\n1.Upper 2.Lower 3.Concat 4.Compare 5.Exit\nChoice: ");
        
        if (1 != scanf("%lu", &unChoice)) 
        {
            while ('\n' != getchar()); 
            continue; 
        }

        for (ulIdx = 0; ulIdx < ulTaskCount; ulIdx++)
        {
            if (s_astTaskTable[ulIdx].eOption == (OPTION_TYPE)unChoice)  
            {
                printf("Enter String: ");
                scanf(" %[^\n]s", aucBuffer);
                blStatus = s_astTaskTable[ulIdx].pFuncHandler(aucBuffer);

                if ((OPTION_COMPARE != (OPTION_TYPE)unChoice) && (true == blStatus))
                {
                    printf("Result: %s\n", aucBuffer);
                }
                break;
            }
        }

    } while (OPTION_EXIT != (OPTION_TYPE)unChoice); 

    return true;
}

//******************************.FUNCTION_HEADER.******************************
//Purpose: Converts all lowercase alphabetic characters in a string to uppercase.
//Inputs: pucInpStr - Pointer to the character buffer to be modified.
//Outputs: The string at pucInpStr is modified in-place to uppercase.
//Return: Returns true if the input pointer is not NULL, false otherwise.
//*****************************************************************************
bool StringProcessorConvertToUpper(uint8* pucInpStr)
{
    uint32 ulI = 0;
    if (NULL != pucInpStr) 
    {
        for (ulI = 0; '\0' != pucInpStr[ulI]; ulI++)
        {
            if ((pucInpStr[ulI] >= 'a') && (pucInpStr[ulI] <= 'z'))
            {
                pucInpStr[ulI] -= ASCII_CASE_OFFSET;
            }
        }
        return true;
    }
    return false;
}

//******************************.FUNCTION_HEADER.******************************
//Purpose: Converts all uppercase alphabetic characters in a string to lowercase.
//Inputs: pucInpStr - Pointer to the character buffer to be modified.
//Outputs: The string at pucInpStr is modified in-place to lowercase.
//Return: Returns true if the input pointer is not NULL, false otherwise.
//*****************************************************************************
bool StringProcessorConvertToLower(uint8* pucInpStr)
{
    uint32 ulI = 0;
    if (NULL != pucInpStr)
    {
        for (ulI = 0; '\0' != pucInpStr[ulI]; ulI++)
        {
            if ((pucInpStr[ulI] >= 'A') && (pucInpStr[ulI] <= 'Z'))
            {
                pucInpStr[ulI] += ASCII_CASE_OFFSET;
            }
        }
        return true;
    }
    return false;
}

//******************************.FUNCTION_HEADER.******************************
//Purpose: Appends a user-provided string to the end of an existing string.
//Inputs: pucInpStr - Pointer to the base string buffer.
//Outputs: Modifies pucInpStr by appending the additional user input string.
//Return: Returns true if the input pointer is valid and operation succeeds.
//*****************************************************************************
bool StringProcessorConcatenate(uint8* pucInpStr)
{
    uint8 aucExtra[MAX_STR_SIZE] = {0};
    if (NULL != pucInpStr)
    {
        printf("Enter string to append: ");
        scanf(" %[^\n]s", aucExtra);
        strcat((char*)pucInpStr, (char*)aucExtra);
        return true;
    }
    return false;
}

//******************************.FUNCTION_HEADER.******************************
//Purpose: Compares the current string buffer against a second string.
//Inputs: pucInpStr - Pointer to the first string to compare.
//Outputs: Prints "Match" or "No Match" to the console based on the result.
//Return: Returns true if the comparison was performed successfully.
//*****************************************************************************
bool StringProcessorCompare(uint8* pucInpStr)
{
    uint8 aucCmp[MAX_STR_SIZE] = {0};
    if (NULL != pucInpStr)
    {
        printf("Compare with: ");
        scanf(" %[^\n]s", aucCmp);
        printf("Result: %s\n", (0 == strcmp((char*)pucInpStr, (char*)aucCmp)) 
                                                       ? "Match" : "No Match");
        return true;
    }
    return false;
}

//******************************** End of File ********************************
