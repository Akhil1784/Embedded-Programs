//******************* Embedded Singleton Program ******************************
//  Copyright (c) 2026 Trenser
//  All Rights Reserved
//*****************************************************************************
// 
// File    : deviceConfig.h
// Summary : Singleton logic for device configuration management.
// Note    : Standardized for Trenser Coding Standard V1.0.
// 
//*****************************************************************************

#ifndef DEVICE_CONFIG_H
#define DEVICE_CONFIG_H

//******************************* Include Files *******************************
#include "platformTypes.h"

//***************************** Global Constants ******************************

//***************************** Local Constants *******************************

//***************************** Global Variables ******************************

//***************************** Local Variables *******************************

//***************************** Type Definitions ******************************
typedef struct 
{
    int32  lData;      
    int32* plDataPtr;  
} DEVICE_CONFIG;

//**************************** Forward Declarations ***************************
DEVICE_CONFIG* DeviceConfig_GetInstance(void);

#endif /* DEVICE_CONFIG_H */