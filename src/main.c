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
static bool ExecuteSingleton(void);

//******************************.FUNCTION_HEADER.******************************
// Purpose  : Executes the Singleton demonstration logic.
// Inputs   : None.
// Outputs  : Prints memory address and stored value to console.
// Return   : bool - TRUE if instance was retrieved successfully, else FALSE.
//*****************************************************************************
static bool ExecuteSingletonDemo(void)
{
    bool blStatus = FALSE;
    ST_SINGLETON* pstSingleton = SingletonGetInstance();


    if(NULL != pstSingleton)
    {
        pstSingleton->lValue = (int32)DEFAULT_VALUE; 
        printf("Singleton Instance Address: %p\n", (void*)pstSingleton);
        printf("Stored Value: %ld\n", (long int)pstSingleton->lValue);    
        blStatus = TRUE;
    }
    else
    {
        printf("Error: Failed to initialize Singleton instance.\n");
    }

    return blStatus;
}

//******************************.FUNCTION_HEADER.******************************
// Purpose : Main execution loop to demonstrate Singleton behavior.
// Inputs  : None.
// Outputs : Prints instance data and memory addresses to the console.
// Return  : int - 0 on successful execution.
//*****************************************************************************
int main(void) 
{
    int iRetVal = 0;

    if(TRUE == ExecuteSingletonDemo())
    {
       iRetVal = 0;
    }
    else
    {
       iRetVal = 1;
    }
    
    return iRetVal;
}

//EOF