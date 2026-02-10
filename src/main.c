//**************************** Binary Converter *******************************
//  Copyright (c) 2026 Trenser
//  All Rights Reserved
//*****************************************************************************
// 
// File    : main.c
// Summary : Encapsulated binary conversion application using bitwise masking.
// Note    : Adheres to Trenser Coding Standard V1.0.
// 
//*****************************************************************************

//******************************* Include Files *******************************
#include <stdio.h>
#include "platformTypes.h"

//***************************** Global Constants ******************************

//***************************** Local Constants *******************************
#define TOTAL_BITS    (32)
#define BITS_PER_BYTE (8)

//***************************** Global Variables ******************************

//***************************** Local Variables *******************************

//***************************** Type Definitions ******************************
static bool PrintBinary(uint32 ulValue);
static bool RunBinaryManipulation(void);

//******************************.FUNCTION_HEADER.******************************
// Purpose  : Prints the 32-bit binary representation of a given value with
//            byte-wise grouping for readability.
// Inputs   : ulValue - The 32-bit unsigned integer to be printed.
// Outputs  : None.
// Return   : bool - TRUE if printing completed successfully, else FALSE.
//*****************************************************************************
static bool PrintBinary(uint32 ulValue)
{
    int32 lIdx = 0;
    bool  blStatus = TRUE;
    for (lIdx = (TOTAL_BITS - 1); lIdx >= 0; lIdx--)
    {
        printf("%c", (ulValue & (1U << lIdx)) ? '1' : '0');
        if ((0 == (lIdx % BITS_PER_BYTE)) && (0 != lIdx)) 
        {
            printf(" ");
        }
    }
    
    printf("\n");

    return blStatus;
}

//******************************.FUNCTION_HEADER.******************************
// Purpose  : Handles user input and performs smart bitwise operations 
//            (SET if 0, CLEAR if 1, and TOGGLE).
// Inputs   : None.
// Outputs  : None.
// Return   : bool - TRUE if input is valid and manipulation succeeds, 
//                   else FALSE.
//*****************************************************************************
static bool RunBinaryManipulation(void)
{
    uint32 ulData   = 0;
    uint32 ulMask   = 0;
    bool   blStatus = FALSE;

    printf("Enter a decimal number: ");
    if (1 == scanf("%u", &ulData))
    {
        printf("\nOriginal Binary   : ");
        (void)PrintBinary(ulData);
        ulMask = (1U << 0);
        if (0 == (ulData & ulMask))
        {
            ulData |= ulMask; 
            printf("Action: SET to 1   (Bit 0 was 0)\n");
        }
        else
        {
            ulData &= ~ulMask; 
            printf("Action: CLEAR to 0 (Bit 0 was 1)\n");
        }
        (void)PrintBinary(ulData);
        ulMask = (1U << 3);
        if (0 == (ulData & ulMask))
        {
            ulData ^= ulMask; 
            printf("Action: TOGGLE to 1 (Bit 3 was 0)\n");
        }
        else
        {
            ulData ^= ulMask; 
            printf("Action: TOGGLE to 0 (Bit 3 was 1)\n");
        }
        (void)PrintBinary(ulData);
        blStatus = TRUE;
    }
    else
    {
        printf("Error: Invalid decimal input.\n");
    }

    return blStatus;
}

//******************************.FUNCTION_HEADER.******************************
// Purpose  : Main entry point. Executes the binary manipulation logic and
//            monitors the execution success status.
// Inputs   : None.
// Outputs  : None.
// Return   : int - 0 on successful execution, non-zero on failure.
//*****************************************************************************
int main(void)
{
    int iRetVal = 0;
    if (TRUE == RunBinaryManipulation())
    {
        printf("\nBinary manipulation completed successfully.\n");
        iRetVal = 0;
    }
    else
    {
        printf("\nBinary manipulation failed.\n");
        iRetVal = 1;
    }

    return iRetVal;
}
