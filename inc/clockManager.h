//**************************** ClockManager ***********************************
//  Copyright (c) 2026 Trenser
//  All Rights Reserved
//*****************************************************************************
// 
// File    : clockManager.h
// Summary : Clock signal generation management and GPIO mapping.
// Note    : Standardized for Trenser Coding Standard V1.0.
// 
//*****************************************************************************

#ifndef CLOCK_MANAGER_H
#define CLOCK_MANAGER_H

//******************************* Include Files *******************************
#include "platformTypes.h"

//***************************** Global Constants ******************************

//***************************** Local Constants *******************************

//***************************** Global Variables ******************************

//***************************** Type Definitions ******************************

typedef enum 
{ 
    CLOCK_STATE_OFF = 0, 
    CLOCK_STATE_ON  = 1 
} CLOCK_STATE;

typedef union 
{
    struct 
    {
        uint8 ucClkPin  : 1; 
        uint8 ucDataPin : 1; 
        uint8 ucUnused  : 6; 
    } stPins;
    uint8 ucRawByte;
} GPIO_REG;

typedef struct 
{
    struct 
    {
        uint32 ulFrequency; 
        CLOCK_STATE eState;      
    } stConfig; 
    
    GPIO_REG *pstPort;           
} CLOCK_MANAGER;

//**************************** Forward Declarations ***************************

CLOCK_MANAGER* ClockManagerGet(void);

#endif /* CLOCK_MANAGER_H */
//******************************** End of File ********************************