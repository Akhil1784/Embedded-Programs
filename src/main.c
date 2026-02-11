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
#include "platformTypes.h"

//***************************** Local Constants *******************************
#define CLK_SIM_CYCLES      (4U)
#define CLK_PIN_HIGH        (1U)
#define CLK_PIN_LOW         (0U)
#define CLK_MASK            (1U << 0)

//*********************** Local Function Prototypes ***************************
static bool RunClockSimulation(void);

//******************************.FUNCTION_HEADER.******************************
// Purpose : Executes the clock toggling simulation.
// Inputs  : None.
// Outputs : None.
// Return  : bool - TRUE if simulation ran, FALSE if manager instance is NULL.
//*****************************************************************************
static bool RunClockSimulation(void)
{
    CLOCK_MANAGER* pstClk = ClockManagerGet();
    uint8 ucIdx = 0;
    bool blIsSuccess = FALSE;

    if( NULL != pstClk )
    {
        pstClk->pstPort->stPins.ucClkPin = CLK_PIN_LOW; 
        printf("Starting Clock Signal Simulation...\n");

        for( ucIdx = 0; ucIdx < CLK_SIM_CYCLES; ucIdx++ )
        {
            pstClk->pstPort->stPins.ucClkPin = CLK_PIN_HIGH;
            printf("Reg: 0x%02X | Clock: HIGH\n", pstClk->pstPort->ucRawByte);
            
            pstClk->pstPort->ucRawByte &= ~CLK_MASK; 
            printf("Reg: 0x%02X | Clock: LOW\n", pstClk->pstPort->ucRawByte);
        }

        pstClk->stConfig.eState = CLOCK_STATE_ON; 
        printf("\nFinal System Freq: %lu Hz\n", pstClk->stConfig.ulFrequency);    
        blIsSuccess = TRUE;
    }

    return blIsSuccess;
}

//******************************.FUNCTION_HEADER.******************************
// Purpose : Main entry point for the clock simulation application.
// Inputs  : None.
// Outputs : None.
// Return  : int - 0 on successful execution.
//*****************************************************************************
int main(void)
{
    if( TRUE == RunClockSimulation() )
    {
        printf("Simulation status: SUCCESS\n");
    }
    else
    {
        printf("Simulation status: FAILURE (Instance not found)\n");
    }

    return 0;
}

//******************************** End of File ********************************