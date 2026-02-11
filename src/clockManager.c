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
#define CLK_DEFAULT_CLOCK_FREQUENCY    (1000000U)
#define CLK_INITIALIZED                (1U)
#define CLK_NOT_INITIALIZED            (0U)

//***************************** Global Variables ******************************

//***************************** Local Variables *******************************
static GPIO_REG s_stMockPort = {0};

//***************************** Type Definitions ******************************

//******************************.FUNCTION_HEADER.******************************
// Purpose : Provides a global point of access to the Clock Manager instance.
// Inputs  : None.
// Outputs : None.
// Return  : CLOCK_MANAGER* - Pointer to the persistent Clock Manager.
//*****************************************************************************
CLOCK_MANAGER* ClockManagerGet(void)
{
    static CLOCK_MANAGER s_stInstance;
    static uint8 s_ucIsInitialized = CLK_NOT_INITIALIZED;

    if(CLK_NOT_INITIALIZED == s_ucIsInitialized)
    {
        s_stInstance.pstPort = &s_stMockPort;
        s_stInstance.stConfig.ulFrequency = CLK_DEFAULT_CLOCK_FREQUENCY;
        s_stInstance.stConfig.eState = CLOCK_STATE_OFF;
        s_ucIsInitialized = CLK_INITIALIZED;
    }

    return &s_stInstance;
}

//******************************** End of File ********************************