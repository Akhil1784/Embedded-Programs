//**************************** ClockManager ***********************************
//  Copyright (c) 2026 Trenser
//  All Rights Reserved
//*****************************************************************************
// 
// File     : clockManager.c
// Summary  : Implementation of the Clock Manager singleton.
// Note     : Adheres to Trenser Coding Standard V1.0.
// 
//*****************************************************************************

//******************************* Include Files *******************************
#include "clockManager.h"

//***************************** Global Constants ******************************

//***************************** Local Constants *******************************
#define DEFAULT_CLOCK_FREQUENCY    1000000

//***************************** Global Variables ******************************

//***************************** Local Variables *******************************
static GPIO_REG s_stMockPort = { .ucRawByte = 0x00 };

//***************************** Type Definitions ******************************

//******************************.FUNCTION_HEADER.******************************
//Purpose : Provides a global point of access to the Clock Manager instance.
//Inputs  : None
//Outputs : Initializes the static clock manager instance on first call.
//Return  : CLOCK_MANAGER* - Pointer to the persistent Clock Manager.
//*****************************************************************************
CLOCK_MANAGER* GetClockManager(void)
{
    static CLOCK_MANAGER s_stInstance;
    static uint8         s_ucIsInitialized = 0;

    if (0 == s_ucIsInitialized)
    {
        s_stInstance.pstPort = &s_stMockPort;
        s_stInstance.stConfig.ulFrequency = DEFAULT_CLOCK_FREQUENCY;
        s_stInstance.stConfig.eState = CLK_OFF;
        
        s_ucIsInitialized = 1;
    }

    return &s_stInstance;
}

//******************************** End of File ********************************