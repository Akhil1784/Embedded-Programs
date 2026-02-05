//******************* Embedded Singleton Program ******************************
//  Copyright (c) 2026 Trenser
//  All Rights Reserved
//*****************************************************************************
// 
// File    : deviceConfig.c
// Summary : Implementation of the Device Configuration Singleton.
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
// Purpose : Returns the unique pointer to Singleton Device Config instance.
// Inputs  : None.
// Outputs : Pointer to the static DEVICE_CONFIG structure.
//*****************************************************************************
DEVICE_CONFIG* DeviceConfig_GetInstance(void) 
{
    if (FALSE == ucIsInitialized) 
    {
        stDeviceInstance.lData     = 42;
        stDeviceInstance.plDataPtr = &stDeviceInstance.lData;
        ucIsInitialized = TRUE;     
        printf("--- Singleton Instance Initialized ---\n");
    }
    
    return &stDeviceInstance;
}

//EOF