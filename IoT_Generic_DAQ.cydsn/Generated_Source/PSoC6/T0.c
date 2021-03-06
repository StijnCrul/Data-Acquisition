/*******************************************************************************
* File Name: T0.c
* Version 1.0
*
* Description:
*  This file provides the source code to the API for the T0
*  component
*
********************************************************************************
* Copyright 2016-2017, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "T0.h"

/** Indicates whether or not the T0 has been initialized. 
*  The variable is initialized to 0 and set to 1 the first time 
*  T0_Start() is called. This allows the Component to 
*  restart without reinitialization after the first call to 
*  the T0_Start() routine.
*/
uint8_t T0_initVar = 0U;

/** The instance-specific configuration structure. This should be used in the 
*  associated T0_Init() function.
*/ 
cy_stc_tcpwm_counter_config_t const T0_config =
{
        .period = 1100UL,
        .clockPrescaler = 0UL,
        .runMode = 0UL,
        .countDirection = 0UL,
        .compareOrCapture = 0UL,
        .compare0 = 1100UL,
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
* Function Name: T0_Start
****************************************************************************//**
*
*  Calls the T0_Init() when called the first time and enables 
*  the T0. For subsequent calls the configuration is left 
*  unchanged and the component is just enabled.
*
* \globalvars
*  \ref T0_initVar
*
*******************************************************************************/
void T0_Start(void)
{
    if (0U == T0_initVar)
    {
        (void)Cy_TCPWM_Counter_Init(T0_HW, T0_CNT_NUM, &T0_config); 

        T0_initVar = 1U;
    }

    Cy_TCPWM_Enable_Multiple(T0_HW, T0_CNT_MASK);
    
    #if (T0_INPUT_DISABLED == 7UL)
        Cy_TCPWM_TriggerStart(T0_HW, T0_CNT_MASK);
    #endif /* (T0_INPUT_DISABLED == 7UL) */    
}


/* [] END OF FILE */
