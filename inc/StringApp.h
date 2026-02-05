//**************************** StringProcess **********************************
//  Copyright (c) 2026 Trenser
//  All Rights Reserved
//*****************************************************************************
// 
// File    : StringApp.h
// Summary : Application layer logic for buffer processing.
// Note    : Standardized for Trenser Coding Standard V1.0.
// 
//*****************************************************************************

#ifndef STRING_APP_H
#define STRING_APP_H

//******************************* Include Files *******************************
#include "StringProcessor.h"

//***************************** Global Constants ******************************

//***************************** Local Constants *******************************

//***************************** Global Variables ******************************

//***************************** Type Definitions ******************************

//**************************** Forward Declarations ***************************
void StringAppProcessStatic(STRING_MANAGER* pstManager, const char* pcInput);
void StringAppProcessDynamic(STRING_MANAGER* pstManager, const char* pcInput);

#endif // EOF