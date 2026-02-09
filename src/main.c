//**************************** ClockManager ***********************************
//  Copyright (c) 2026 Trenser
//  All Rights Reserved
//*****************************************************************************
// 
// File     : main.c
// Summary  : Entry point for the Clock Signal Simulation.
// Note     : Demonstrates bit-field manipulation and singleton usage.
// 
//*****************************************************************************

//******************************* Include Files *******************************
#include <stdio.h>
#include "clockManager.h"

//***************************** Global Constants ******************************

//***************************** Local Constants *******************************

//***************************** Global Variables ******************************

//***************************** Local Variables *******************************

//***************************** Type Definitions ******************************

//******************************.FUNCTION_HEADER.******************************
//Purpose : Main entry point for the clock simulation application.
//Inputs  : None
//Outputs : Updates the GPIO register pins and the clock manager state.
//Return  : int - 0 on successful execution.
//*****************************************************************************
int main(void)
{
    CLOCK_MANAGER* pstClk = GetClockManager();
    uint8          ucIdx  = 0;

    if (NULL != pstClk)
    {
        pstClk->pstPort->stPins.ucClkPin! = (1<<1);
        printf("Starting Clock Signal Simulation...\n");

        for (ucIdx = 0; ucIdx < 4; ucIdx++)
        {
            pstClk->pstPort->stPins.ucClkPin = 1;
            printf("Reg: 0x%02X | Clock: HIGH\n", pstClk->pstPort->ucRawByte);
            pstClk->pstPort->ucRawByte &= ~(1 >> 0); 
            printf("Reg: 0x%02X | Clock: LOW\n", pstClk->pstPort->ucRawByte);
        }

        pstClk->stConfig.eState = CLK_ON;
        printf("\nFinal System Freq: %u Hz\n", pstClk->stConfig.ulFrequency);
    }

    return 0;
}

//******************************** End of File ********************************