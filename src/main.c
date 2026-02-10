//******************* Embedded Singleton Program ******************************
//  Copyright (c) 2026 Trenser
//  All Rights Reserved
//*****************************************************************************
// 
// File    : main.c
// Summary : Application entry point to demonstrate Singleton functionality.
// Note    : Standardized for Trenser Coding Standard V1.0.
// 
//*****************************************************************************

//******************************* Include Files *******************************
#include "singleton.h"
#include <stdio.h>

//***************************** Global Constants ******************************

//***************************** Local Constants *******************************
#define DEFAULT_VALUE       (500U)

//***************************** Global Variables ******************************

//***************************** Local Variables *******************************

//***************************** Type Definitions ******************************

//******************************.FUNCTION_HEADER.******************************
// Purpose : Main execution loop to demonstrate Singleton behavior.
// Inputs  : None.
// Outputs : Prints instance data and memory addresses to the console.
// Return  : int - 0 on successful execution.
//*****************************************************************************
int main(void) 
{
    ST_SINGLETON* pstSingleton = SingletonGetInstance();
    if (NULL != pstSingleton)
    {
      pstSingleton->lValue = (int32)DEFAULT_VALUE;    
      printf("Singleton Instance Address: %p\n", (void*)pstSingleton);
      printf("Stored Value: %ld\n", (int32)pstSingleton->lValue);
    }
    else
    {
        printf("Error: Failed to initialize Singleton instance.\n");
    }
    
    return 0;
}

//EOF