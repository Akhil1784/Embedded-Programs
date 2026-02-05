//**************************** StringProcess **********************************
//  Copyright (c) 2026 Trenser
//  All Rights Reserved
//*****************************************************************************
// 
// Summary : String manipulation types and routine declarations.
// Note    : Standardized for Trenser Coding Standard V1.0.
// 
//*****************************************************************************

#ifndef _STRING_PROCESSOR_H
#define _STRING_PROCESSOR_H

//******************************* Include Files *******************************
#include "PlatformTypes.h"

//***************************** Global Constants ******************************
#define MAX_STATIC_SIZE 512

//***************************** Local Constants *******************************

//***************************** Global Variables ******************************

//***************************** Type Definitions ******************************
typedef struct _STRING_MANAGER_
{
    uint8  pucStaticBuffer[MAX_STATIC_SIZE];
    uint8* pucDynamicBuffer;
    uint32 ulStringLength;
} STRING_MANAGER;

//**************************** Forward Declarations ***************************
bool StringProcessorConvertToUpper(uint8* pucString, uint16 usLength);
bool StringProcessorConvertToLower(uint8* pucString, uint16 usLength);

#endif // EOF