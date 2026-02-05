//**************************** StringProcess **********************************
//  Copyright (c) 2026 Trenser
//  All Rights Reserved
//*****************************************************************************
// 
// File    : Main.c
// Summary : Entry point for the string program simulation.
// Note    : Demonstrates static/dynamic arrays and Trenser variable naming.
// 
//*****************************************************************************

//******************************* Include Files *******************************
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "StringApp.h"
#include "StringProcessor.h"

//***************************** Global Constants ******************************

//***************************** Local Constants *******************************

//***************************** Global Variables ******************************

//******************************.FUNCTION_HEADER.******************************
//Purpose : Main entry point for the application.
//Return  : 0 on success.
//*****************************************************************************

int main(void)
{
    STRING_MANAGER stManager;
    const char* pInput = "Trenser String Test";

    stManager.ulStringLength = (uint32)strlen(pInput);
    stManager.pucDynamicBuffer = NULL;

    StringAppProcessStatic(&stManager, pInput);
    StringAppProcessDynamic(&stManager, pInput);

    return 0;
}//EOF
