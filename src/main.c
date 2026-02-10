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
#define TOTAL_BITS          (32)
#define BITS_PER_BYTE       (8)
#define START_BIT_INDEX     (TOTAL_BITS - 1)

//***************************** Global Variables ******************************

//***************************** Local Variables *******************************

//***************************** Type Definitions ******************************
static void PrintBinary(uint32 ulValue);
static bool RunBinaryManipulation(void);

//******************************.FUNCTION_HEADER.******************************
//Purpose : Prints the 32-bit binary representation of a given value.
//Inputs  : ulValue - The 32-bit unsigned integer to be printed.
//Outputs : Binary string with spaces every 8 bits to standard output.
//Return  : None
//*****************************************************************************
static void PrintBinary(uint32 ulValue)
{
    int32 lIdx = 0;

    for (lIdx = START_BIT_INDEX; lIdx >= 0; lIdx--)
    {
        /* Check bit at current index and print character */
        printf("%c", (ulValue & (1U << lIdx)) ? '1' : '0');

        /* Print space after every 8 bits, but not after the last bit (0) */
        if ((0 == (lIdx % BITS_PER_BYTE)) && (0 != lIdx))
        {
            printf(" ");
        }
    }
    printf("\n");
}

//******************************.FUNCTION_HEADER.******************************
//Purpose : Performs sequential bitwise SET, CLEAR, and TOGGLE operations.
//Inputs  : None (Takes decimal input from user).
//Outputs : Displays binary state after each manipulation.
//Return  : bool - TRUE if input was valid and operations completed.
//*****************************************************************************
static bool RunBinaryManipulation(void)
{
    uint32 ulUserValue = 0;
    bool   blIsSuccess = FALSE;

    printf("Enter a decimal number: ");
    
    if (1 == scanf("%u", &ulUserValue))
    {
        printf("\nOriginal Binary   : ");
        PrintBinary(ulUserValue);

        ulUserValue |= (1U << 0);
        printf("After SET Bit 0   : ");
        PrintBinary(ulUserValue);

        ulUserValue &= ~(1U << 3);
        printf("After CLEAR Bit 3 : ");
        PrintBinary(ulUserValue);

        ulUserValue ^= (1U << 7);
        printf("After TOGGLE Bit 7: ");
        PrintBinary(ulUserValue);

        blIsSuccess = TRUE;
    }
    else
    {
        printf("Error: Invalid Input.\n");
    }
    
    return blIsSuccess;
}

//******************************.FUNCTION_HEADER.******************************
//Purpose : Main entry point. Monitors conversion success status.
//Inputs  : None
//Outputs : Prints conversion results directly to standard output.
//Return  : int - 0 on successful execution.
//*****************************************************************************
int main(void)
{
    if (TRUE == RunBinaryManipulation())
    {
        printf("\nManipulation Complete.\n");
    }
    else
    {
        printf("\nManipulation Failed.\n"); 
    }
    return 0;
}