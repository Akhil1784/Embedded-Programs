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
#include "singleton.h"
#include <stdlib.h>

//***************************** Global Constants ******************************

//***************************** Local Constants *******************************

//***************************** Global Variables ******************************

//***************************** Local Variables *******************************

//***************************** Type Definitions ******************************

//******************************.FUNCTION_HEADER.******************************
// Purpose : Provides a global access point to the singleton configuration 
//           instance and ensures it is initialized exactly once.
// Inputs  : None
// Outputs : Initialized internal static structure.
// Return  : ST_SINGLETON* - Pointer to the single persistent instance.
//*****************************************************************************
ST_SINGLETON* SingletonGetInstance(void) {
    static ST_SINGLETON* gpstSingletonInstance = NULL;

    if (gpstSingletonInstance == NULL) {
        gpstSingletonInstance = (ST_SINGLETON*)malloc(sizeof(ST_SINGLETON));
        gpstSingletonInstance->lValue = 0; 
    }
    
    return gpstSingletonInstance;
}

//EOF

