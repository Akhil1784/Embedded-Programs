//******************* Embedded Singleton Program ******************************
//  Copyright (c) 2026 Trenser
//  All Rights Reserved
//*****************************************************************************
// 
// File    : singleton.h
// Summary : Singleton logic for device configuration management.
// Note    : Standardized for Trenser Coding Standard V1.0.
// 
//*****************************************************************************

#ifndef SINGLETON_H
#define SINGLETON_H

//******************************* Include Files *******************************
#include "platformTypes.h"

//***************************** Global Constants ******************************

//***************************** Local Constants *******************************

//***************************** Global Variables ******************************

//***************************** Local Variables *******************************

//***************************** Type Definitions ******************************
typedef struct 
{
    int32 lValue;
} ST_SINGLETON;

//**************************** Forward Declarations ***************************
ST_SINGLETON* SingletonGetInstance(void);

#endif /* SINGLETON_H */