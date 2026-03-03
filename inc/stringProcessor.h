//**************************** STRING EMBEDDED ********************************
//  Copyright (c) 2026 Trenser
//  All Rights Reserved
//*****************************************************************************
//
// File    : stringProcessor.h
// Summary : Type definitions and function prototypes for string manipulation 
//           using a table-driven task dispatcher.
// Note    : Adheres to Trenser Embedded Coding Standard V1.0.
//
//*****************************************************************************

#ifndef _STRING_PROCESSOR_H_
#define _STRING_PROCESSOR_H_

//******************************* Include Files *******************************
#include <stdbool.h>
#include "platformTypes.h"

//******************************** Global Types *******************************
typedef enum
{
    OPTION_UPPER = 1,
    OPTION_LOWER,
    OPTION_CONCAT,
    OPTION_COMPARE,
    OPTION_EXIT
} OPTION_TYPE;

typedef struct 
{
    OPTION_TYPE eOption;
    bool (*pFuncHandler)(uint8* pucInpStr);
} MY_STRUCT; 

//***************************** Global Constants ******************************
#define MAX_STR_SIZE 100 

//***************************** Local Constants *******************************

//***************************** Global Variables ******************************

//****************************** Local Variables ******************************

//***************************** Type Definitions ******************************

//*************************** Forward Declarations ****************************
bool StringProcessorExecutionManager(void); 
bool StringProcessorConvertToUpper(uint8* pucInpStr);
bool StringProcessorConvertToLower(uint8* pucInpStr);
bool StringProcessorConcatenate(uint8* pucInpStr);
bool StringProcessorCompare(uint8* pucInpStr);

#endif // _STRING_PROCESSOR_H_

//******************************** End of File ********************************
