//**************************** TRENSER EMBEDDED ******************************
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
#include "StringProcessor.h"

//******************************.FUNCTION_HEADER.******************************
//Purpose : Main entry point for the application.
//Return  : 0 on success.
//*****************************************************************************

int main(void)
{
    STRING_MANAGER stManager;
    const char* pInput = "Trenser String Test";

    stManager.ulStringLength = (uint32)strlen(pInput);

    /* Static Buffer Logic */
    if (stManager.ulStringLength < MAX_STATIC_SIZE)
    {
        memcpy(stManager.aucStaticBuffer, pInput, stManager.ulStringLength + 1);
        
        ConvertToUpper(stManager.aucStaticBuffer, stManager.ulStringLength);
        
        printf("Static Upper: %s\n", stManager.aucStaticBuffer);
    }

    /* Dynamic Buffer Logic */
    stManager.pucDynamicBuffer = (uint8*)malloc((stManager.ulStringLength + 1) * sizeof(uint8));

    if (NULL != stManager.pucDynamicBuffer)
    {
        memcpy(stManager.pucDynamicBuffer, pInput, stManager.ulStringLength + 1);
        
        ConvertToLower(stManager.pucDynamicBuffer, stManager.ulStringLength);
        
        printf("Dynamic Lower: %s\n", stManager.pucDynamicBuffer);

        free(stManager.pucDynamicBuffer);
        stManager.pucDynamicBuffer = NULL;
    }

    return 0;
}//EOF