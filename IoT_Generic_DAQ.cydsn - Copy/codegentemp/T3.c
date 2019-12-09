/*******************************************************************************
* File Name: T3.c
* Version 1.0
*
* Description:
*  This file provides the source code to the API for the T3
*  component
*
********************************************************************************
* Copyright 2016-2017, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "T3.h"

/** Indicates whether or not the T3 has been initialized. 
*  The variable is initialized to 0 and set to 1 the first time 
*  T3_Start() is called. This allows the Component to 
*  restart without reinitialization after the first call to 
*  the T3_Start() routine.
*/
uint8_t T3_initVar = 0U;

/** The instance-specific configuration structure. This should be used in the 
*  associated T3_Init() function.
*/ 
cy_stc_tcpwm_counter_config_t const T3_config =
{
        .period = 1133UL,
        .clockPrescaler = 0UL,
        .runMode = 0UL,
        .countDirection = 0UL,
        .compareOrCapture = 0UL,
        .compare0 = 1133UL,
        .compare1 = 16384UL,
        .enableCompareSwap = false,
        .interruptSources = 0UL,
        .captureInputMode = 3UL,
        .captureInput = CY_TCPWM_INPUT_CREATOR,
        .reloadInputMode = 3UL,
        .reloadInput = CY_TCPWM_INPUT_CREATOR,
        .startInputMode = 3UL,
        .startInput = CY_TCPWM_INPUT_CREATOR,
        .stopInputMode = 3UL,
        .stopInput = CY_TCPWM_INPUT_CREATOR,
        .countInputMode = 3UL,
        .countInput = CY_TCPWM_INPUT_CREATOR,
};


/*******************************************************************************
* Function Name: T3_Start
****************************************************************************//**
*
*  Calls the T3_Init() when called the first time and enables 
*  the T3. For subsequent calls the configuration is left 
*  unchanged and the component is just enabled.
*
* \globalvars
*  \ref T3_initVar
*
*******************************************************************************/
void T3_Start(void)
{
    if (0U == T3_initVar)
    {
        (void)Cy_TCPWM_Counter_Init(T3_HW, T3_CNT_NUM, &T3_config); 

        T3_initVar = 1U;
    }

    Cy_TCPWM_Enable_Multiple(T3_HW, T3_CNT_MASK);
    
    #if (T3_INPUT_DISABLED == 7UL)
        Cy_TCPWM_TriggerStart(T3_HW, T3_CNT_MASK);
    #endif /* (T3_INPUT_DISABLED == 7UL) */    
}


/* [] END OF FILE */
