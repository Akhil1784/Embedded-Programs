//************************** Health Monitor ***********************************
//  Copyright (c) 2026 Trenser
//  All Rights Reserved
//*****************************************************************************
// 
// File    : main.c
// Summary : Health monitor simulation. 
// 
//*****************************************************************************

//******************************* Include Files *******************************
#include <stdio.h>
#include "platformTypes.h"

//***************************** Global Constants ******************************

//***************************** Local Constants *******************************
#define BUFFER_SIZE          (5U) 
#define SENSOR_VAL_INITIAL   (100U)
#define SENSOR_VAL_SECONDARY (200U)
#define SENSOR_VAL_REPEATED  (50U)
#define AVG_SAMPLE_COUNT     (2U)
#define LOOP_LIMIT_EXTENDED  (5U)
#define TRUE                 ((bool)1)
#define FALSE                ((bool)0)

//***************************** Local Variables *******************************
static int16 spSensorReading[BUFFER_SIZE] = {0}; 
static uint8 ucHistoryIndex = 0U;

//***************************** Global Variables ******************************

//***************************** Local Function ********************************
static bool AddReading(uint32 ulValue);
static float GetAverage(uint8 ucCount);

//***************************** Type Definitions ******************************

//******************************.FUNCTION_HEADER.******************************
// Purpose  : Adds a new sensor reading to the internal history buffer while 
//            preventing buffer overflow. 
// Inputs   : ulValue - The 32-bit unsigned sensor reading to be stored.
// Outputs  : Updates the spSensorReading array and increments ucHistoryIndex.
// Return   : blStatus - TRUE if successful; FALSE if buffer is full. 
//*****************************************************************************
static bool AddReading(uint32 ulValue)
{
    bool blStatus = FALSE;

    if (ucHistoryIndex < BUFFER_SIZE)
    {
        spSensorReading[ucHistoryIndex] = (int16)ulValue;
        ucHistoryIndex++;
        blStatus = TRUE;
    }
    else
    {
        printf("Error: Buffer overflow attempt detected.\n");
    }

    return blStatus;
}

//******************************.FUNCTION_HEADER.******************************
// Purpose  : Calculates the average of specified previous sensor readings.
// Inputs   : ucCount - The number of historical samples to include. 
// Outputs  : None. 
// Return   : fSum - The calculated average. Returns 0.0f if count is invalid.
//*****************************************************************************
static float GetAverage(uint8 ucCount)
{
    float fSum    = 0.0f;
    uint8 ucIdx   = 0U; 

    if ((0U < ucCount) && (ucCount <= ucHistoryIndex))
    {
        for (ucIdx = 0U; ucIdx < ucCount; ucIdx++)
        {
            fSum += (float)spSensorReading[ucIdx];
        }
        fSum = fSum / (float)ucCount;
    }

    return fSum;
}

//******************************.FUNCTION_HEADER.******************************
// Purpose  : Main entry point. Executes the health monitor simulation logic.
// Inputs   : None. 
// Outputs  : None. 
// Return   : int - 0 on success. 
//*****************************************************************************
int main(void)
{
    int32 lInitialVal = 0; 
    const int32 * plSafePtr = &lInitialVal; 
    uint8 ucJIdx = 0U; 

    printf("--- Health Monitor Simulation ---\n\n");  
    (void)AddReading(SENSOR_VAL_INITIAL);
    (void)AddReading(SENSOR_VAL_SECONDARY);   
    
    float fAvg = GetAverage(AVG_SAMPLE_COUNT);
    printf("Calculated Avg: %.2f\n", (double)fAvg);

    for (ucJIdx = 0U; ucJIdx < LOOP_LIMIT_EXTENDED; ucJIdx++)
    {
        (void)AddReading(SENSOR_VAL_REPEATED); 
    }

    printf("\nPointer Access (Safe): %ld\n", *plSafePtr);

    return 0;
}
