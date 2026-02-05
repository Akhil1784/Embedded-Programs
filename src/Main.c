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
    bool bStaticStatus  = FALSE;
    bool bDynamicStatus = FALSE;
    int iReturnStatus   = 0;
    stManager.ulStringLength = (uint32)strlen(pInput);
    stManager.pucDynamicBuffer = NULL;
    bStaticStatus  = StringAppProcessStatic(&stManager, pInput);
    bDynamicStatus = StringAppProcessDynamic(&stManager, pInput);
    
    if ((TRUE != bStaticStatus) || (TRUE != bDynamicStatus))
    {
        printf("Application finished with processing errors.\n");
        iReturnStatus = 1;
    }
    else
    {
        printf("Application finished successfully.\n");
        iReturnStatus = 0;
    }

    return iReturnStatus;
}
// EOF
