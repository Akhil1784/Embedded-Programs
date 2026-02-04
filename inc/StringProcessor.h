//**************************** TRENSER EMBEDDED ******************************
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

//***************************** Type Definitions ***************************
typedef struct _STRING_MANAGER_
{
    uint8  aucStaticBuffer[512];
    uint8* pucDynamicBuffer;
    uint32 ulStringLength;
} STRING_MANAGER;

//***************************** Global Constants ******************************
#define MAX_STATIC_SIZE 512

//**************************** Forward Declarations ***************************
void ConvertToUpper(uint8* pucString, uint32 ulLength);
void ConvertToLower(uint8* pucString, uint32 ulLength);

#endif // EOF