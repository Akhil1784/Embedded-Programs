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

//******************************.FUNCTION_HEADER.******************************
//Purpose : Handles user input and performs the 32-bit binary conversion.
//Inputs  : None
//Outputs : Prints conversion results directly to standard output.
//Return  : bool - TRUE if conversion was successful, FALSE if input failed.
//*****************************************************************************
static bool ConvertDecimalToBinaryStream(void)
{
    uint32 ulUserValue = 0;
    int32  lIdx        = 0;
    bool   blIsSuccess = FALSE;

    printf("Enter a decimal number: ");

    if (1 == scanf("%u", &ulUserValue))
    {
        printf("Decimal: %u | Binary: ", ulUserValue);

        for (lIdx = START_BIT_INDEX; lIdx >= 0; lIdx--)
        {
            printf("%c", (ulUserValue & (1U << lIdx)) ? '1' : '0');

            if (0 == (lIdx % BITS_PER_BYTE))
            {
                printf(" ");
            }
        }

        printf("\n");
        blIsSuccess = TRUE;
    }
    else
    {
        printf("Error: Invalid decimal input.\n");
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
    if (TRUE == ConvertDecimalToBinaryStream())
    {
        printf("Success: Process finished.\n");
    }
    else
    {
        printf("Failure: Process terminated unexpectedly.\n");
    }

    return 0;
}