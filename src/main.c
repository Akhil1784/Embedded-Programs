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
#include <stdio.h>
#include "deviceConfig.h"

//***************************** Global Constants ******************************

//***************************** Local Constants *******************************

//***************************** Global Variables ******************************

//***************************** Local Variables *******************************
static DEVICE_CONFIG stDeviceInstance;
static uint8 ucIsInitialized = FALSE;

//***************************** Type Definitions ******************************

//******************************.FUNCTION_HEADER.******************************
// Purpose : Main execution loop to demonstrate Singleton behavior.
// Inputs  : None.
// Outputs : Prints instance data and memory addresses to the console.
// Return  : int - 0 on successful execution.
//*****************************************************************************
int main(void) 
{
    DEVICE_CONFIG *pstObjA = NULL;
    DEVICE_CONFIG *pstObjB = NULL;
    pstObjA = DeviceConfig_GetInstance();
    pstObjB = DeviceConfig_GetInstance();
    
    if ((NULL != pstObjA) && (NULL != pstObjB))
    {
        pstObjB->lData = 100;
        printf("Object A Data (reflected): %ld\n", *(pstObjA->plDataPtr));
        printf("Address A: %p | Address B: %p\n", (void*)pstObjA, (void*)pstObjB);
    }

    return 0;
}

//EOF