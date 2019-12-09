/*******************************************************************************
* File Name: T4.h
* Version 1.0
*
* Description:
*  This file provides constants and parameter values for the T4
*  component.
*
********************************************************************************
* Copyright 2016-2017, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(T4_CY_TCPWM_COUNTER_PDL_H)
#define T4_CY_TCPWM_COUNTER_PDL_H

#include "cyfitter.h"
#include "tcpwm/cy_tcpwm_counter.h"

   
/*******************************************************************************
* Variables
*******************************************************************************/
/**
* \addtogroup group_globals
* @{
*/
extern uint8_t  T4_initVar;
extern cy_stc_tcpwm_counter_config_t const T4_config;
/** @} group_globals */


/***************************************
*  Conditional Compilation Parameters
***************************************/

#define T4_INIT_COMPARE_OR_CAPTURE    (0UL)


/***************************************
*        Function Prototypes
****************************************/
/**
* \addtogroup group_general
* @{
*/
void T4_Start(void);
__STATIC_INLINE cy_en_tcpwm_status_t T4_Init(cy_stc_tcpwm_counter_config_t const *config);
__STATIC_INLINE void T4_DeInit(void);
__STATIC_INLINE void T4_Enable(void);
__STATIC_INLINE void T4_Disable(void);
__STATIC_INLINE uint32_t T4_GetStatus(void);

#if(CY_TCPWM_COUNTER_MODE_CAPTURE == T4_INIT_COMPARE_OR_CAPTURE)
    __STATIC_INLINE uint32_t T4_GetCapture(void);
    __STATIC_INLINE uint32_t T4_GetCaptureBuf(void);
#else
    __STATIC_INLINE void T4_SetCompare0(uint32_t compare0);
    __STATIC_INLINE uint32_t T4_GetCompare0(void);
    __STATIC_INLINE void T4_SetCompare1(uint32_t compare1);
    __STATIC_INLINE uint32_t T4_GetCompare1(void);
    __STATIC_INLINE void T4_EnableCompareSwap(bool enable);
#endif /* (CY_TCPWM_COUNTER_MODE_CAPTURE == T4_INIT_COMPARE_OR_CAPTURE) */

__STATIC_INLINE void T4_SetCounter(uint32_t count);
__STATIC_INLINE uint32_t T4_GetCounter(void);
__STATIC_INLINE void T4_SetPeriod(uint32_t period);
__STATIC_INLINE uint32_t T4_GetPeriod(void);
__STATIC_INLINE void T4_TriggerStart(void);
__STATIC_INLINE void T4_TriggerReload(void);
__STATIC_INLINE void T4_TriggerStop(void);
__STATIC_INLINE void T4_TriggerCapture(void);
__STATIC_INLINE uint32_t T4_GetInterruptStatus(void);
__STATIC_INLINE void T4_ClearInterrupt(uint32_t source);
__STATIC_INLINE void T4_SetInterrupt(uint32_t source);
__STATIC_INLINE void T4_SetInterruptMask(uint32_t mask);
__STATIC_INLINE uint32_t T4_GetInterruptMask(void);
__STATIC_INLINE uint32_t T4_GetInterruptStatusMasked(void);
/** @} general */


/***************************************
*           API Constants
***************************************/

/**
* \addtogroup group_macros
* @{
*/
/** This is a ptr to the base address of the TCPWM instance */
#define T4_HW                 (T4_TCPWM__HW)

/** This is a ptr to the base address of the TCPWM CNT instance */
#define T4_CNT_HW             (T4_TCPWM__CNT_HW)

/** This is the counter instance number in the selected TCPWM */
#define T4_CNT_NUM            (T4_TCPWM__CNT_IDX)

/** This is the bit field representing the counter instance in the selected TCPWM */
#define T4_CNT_MASK           (1UL << T4_CNT_NUM)
/** @} group_macros */

#define T4_INPUT_MODE_MASK    (0x3U)
#define T4_INPUT_DISABLED     (7U)


/*******************************************************************************
* Function Name: T4_Init
****************************************************************************//**
*
* Invokes the Cy_TCPWM_Counter_Init() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE cy_en_tcpwm_status_t T4_Init(cy_stc_tcpwm_counter_config_t const *config)
{
    return(Cy_TCPWM_Counter_Init(T4_HW, T4_CNT_NUM, config));
}


/*******************************************************************************
* Function Name: T4_DeInit
****************************************************************************//**
*
* Invokes the Cy_TCPWM_Counter_DeInit() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void T4_DeInit(void)                   
{
    Cy_TCPWM_Counter_DeInit(T4_HW, T4_CNT_NUM, &T4_config);
}

/*******************************************************************************
* Function Name: T4_Enable
****************************************************************************//**
*
* Invokes the Cy_TCPWM_Enable_Multiple() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void T4_Enable(void)                   
{
    Cy_TCPWM_Enable_Multiple(T4_HW, T4_CNT_MASK);
}


/*******************************************************************************
* Function Name: T4_Disable
****************************************************************************//**
*
* Invokes the Cy_TCPWM_Disable_Multiple() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void T4_Disable(void)                  
{
    Cy_TCPWM_Disable_Multiple(T4_HW, T4_CNT_MASK);
}


/*******************************************************************************
* Function Name: T4_GetStatus
****************************************************************************//**
*
* Invokes the Cy_TCPWM_Counter_GetStatus() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE uint32_t T4_GetStatus(void)                
{
    return(Cy_TCPWM_Counter_GetStatus(T4_HW, T4_CNT_NUM));
}


#if(CY_TCPWM_COUNTER_MODE_CAPTURE == T4_INIT_COMPARE_OR_CAPTURE)
    /*******************************************************************************
    * Function Name: T4_GetCapture
    ****************************************************************************//**
    *
    * Invokes the Cy_TCPWM_Counter_GetCapture() PDL driver function.
    *
    *******************************************************************************/
    __STATIC_INLINE uint32_t T4_GetCapture(void)               
    {
        return(Cy_TCPWM_Counter_GetCapture(T4_HW, T4_CNT_NUM));
    }


    /*******************************************************************************
    * Function Name: T4_GetCaptureBuf
    ****************************************************************************//**
    *
    * Invokes the Cy_TCPWM_Counter_GetCaptureBuf() PDL driver function.
    *
    *******************************************************************************/
    __STATIC_INLINE uint32_t T4_GetCaptureBuf(void)            
    {
        return(Cy_TCPWM_Counter_GetCaptureBuf(T4_HW, T4_CNT_NUM));
    }
#else
    /*******************************************************************************
    * Function Name: T4_SetCompare0
    ****************************************************************************//**
    *
    * Invokes the Cy_TCPWM_Counter_SetCompare0() PDL driver function.
    *
    *******************************************************************************/
    __STATIC_INLINE void T4_SetCompare0(uint32_t compare0)      
    {
        Cy_TCPWM_Counter_SetCompare0(T4_HW, T4_CNT_NUM, compare0);
    }


    /*******************************************************************************
    * Function Name: T4_GetCompare0
    ****************************************************************************//**
    *
    * Invokes the Cy_TCPWM_Counter_GetCompare0() PDL driver function.
    *
    *******************************************************************************/
    __STATIC_INLINE uint32_t T4_GetCompare0(void)              
    {
        return(Cy_TCPWM_Counter_GetCompare0(T4_HW, T4_CNT_NUM));
    }


    /*******************************************************************************
    * Function Name: T4_SetCompare1
    ****************************************************************************//**
    *
    * Invokes the Cy_TCPWM_Counter_SetCompare1() PDL driver function.
    *
    *******************************************************************************/
    __STATIC_INLINE void T4_SetCompare1(uint32_t compare1)      
    {
        Cy_TCPWM_Counter_SetCompare1(T4_HW, T4_CNT_NUM, compare1);
    }


    /*******************************************************************************
    * Function Name: T4_GetCompare1
    ****************************************************************************//**
    *
    * Invokes the Cy_TCPWM_Counter_GetCompare1() PDL driver function.
    *
    *******************************************************************************/
    __STATIC_INLINE uint32_t T4_GetCompare1(void)              
    {
        return(Cy_TCPWM_Counter_GetCompare1(T4_HW, T4_CNT_NUM));
    }


    /*******************************************************************************
    * Function Name: T4_EnableCompareSwap
    ****************************************************************************//**
    *
    * Invokes the Cy_TCPWM_Counter_EnableCompareSwap() PDL driver function.
    *
    *******************************************************************************/
    __STATIC_INLINE void T4_EnableCompareSwap(bool enable)  
    {
        Cy_TCPWM_Counter_EnableCompareSwap(T4_HW, T4_CNT_NUM, enable);
    }
#endif /* (CY_TCPWM_COUNTER_MODE_CAPTURE == T4_INIT_COMPARE_OR_CAPTURE) */


/*******************************************************************************
* Function Name: T4_SetCounter
****************************************************************************//**
*
* Invokes the Cy_TCPWM_Counter_SetCounter() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void T4_SetCounter(uint32_t count)          
{
    Cy_TCPWM_Counter_SetCounter(T4_HW, T4_CNT_NUM, count);
}


/*******************************************************************************
* Function Name: T4_GetCounter
****************************************************************************//**
*
* Invokes the Cy_TCPWM_Counter_GetCounter() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE uint32_t T4_GetCounter(void)               
{
    return(Cy_TCPWM_Counter_GetCounter(T4_HW, T4_CNT_NUM));
}


/*******************************************************************************
* Function Name: T4_SetPeriod
****************************************************************************//**
*
* Invokes the Cy_TCPWM_Counter_SetPeriod() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void T4_SetPeriod(uint32_t period)          
{
    Cy_TCPWM_Counter_SetPeriod(T4_HW, T4_CNT_NUM, period);
}


/*******************************************************************************
* Function Name: T4_GetPeriod
****************************************************************************//**
*
* Invokes the Cy_TCPWM_Counter_GetPeriod() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE uint32_t T4_GetPeriod(void)                
{
    return(Cy_TCPWM_Counter_GetPeriod(T4_HW, T4_CNT_NUM));
}


/*******************************************************************************
* Function Name: T4_TriggerStart
****************************************************************************//**
*
* Invokes the Cy_TCPWM_TriggerStart() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void T4_TriggerStart(void)             
{
    Cy_TCPWM_TriggerStart(T4_HW, T4_CNT_MASK);
}


/*******************************************************************************
* Function Name: T4_TriggerReload
****************************************************************************//**
*
* Invokes the Cy_TCPWM_TriggerReloadOrIndex() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void T4_TriggerReload(void)     
{
    Cy_TCPWM_TriggerReloadOrIndex(T4_HW, T4_CNT_MASK);
}


/*******************************************************************************
* Function Name: T4_TriggerStop
****************************************************************************//**
*
* Invokes the Cy_TCPWM_TriggerStopOrKill() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void T4_TriggerStop(void)
{
    Cy_TCPWM_TriggerStopOrKill(T4_HW, T4_CNT_MASK);
}


/*******************************************************************************
* Function Name: T4_TriggerCapture
****************************************************************************//**
*
* Invokes the Cy_TCPWM_TriggerCaptureOrSwap() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void T4_TriggerCapture(void)     
{
    Cy_TCPWM_TriggerCaptureOrSwap(T4_HW, T4_CNT_MASK);
}


/*******************************************************************************
* Function Name: T4_GetInterruptStatus
****************************************************************************//**
*
* Invokes the Cy_TCPWM_GetInterruptStatus() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE uint32_t T4_GetInterruptStatus(void)       
{
    return(Cy_TCPWM_GetInterruptStatus(T4_HW, T4_CNT_NUM));
}


/*******************************************************************************
* Function Name: T4_ClearInterrupt
****************************************************************************//**
*
* Invokes the Cy_TCPWM_ClearInterrupt() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void T4_ClearInterrupt(uint32_t source)     
{
    Cy_TCPWM_ClearInterrupt(T4_HW, T4_CNT_NUM, source);
}


/*******************************************************************************
* Function Name: T4_SetInterrupt
****************************************************************************//**
*
* Invokes the Cy_TCPWM_SetInterrupt() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void T4_SetInterrupt(uint32_t source)
{
    Cy_TCPWM_SetInterrupt(T4_HW, T4_CNT_NUM, source);
}


/*******************************************************************************
* Function Name: T4_SetInterruptMask
****************************************************************************//**
*
* Invokes the Cy_TCPWM_SetInterruptMask() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void T4_SetInterruptMask(uint32_t mask)     
{
    Cy_TCPWM_SetInterruptMask(T4_HW, T4_CNT_NUM, mask);
}


/*******************************************************************************
* Function Name: T4_GetInterruptMask
****************************************************************************//**
*
* Invokes the Cy_TCPWM_GetInterruptMask() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE uint32_t T4_GetInterruptMask(void)         
{
    return(Cy_TCPWM_GetInterruptMask(T4_HW, T4_CNT_NUM));
}


/*******************************************************************************
* Function Name: T4_GetInterruptStatusMasked
****************************************************************************//**
*
* Invokes the Cy_TCPWM_GetInterruptStatusMasked() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE uint32_t T4_GetInterruptStatusMasked(void)
{
    return(Cy_TCPWM_GetInterruptStatusMasked(T4_HW, T4_CNT_NUM));
}

#endif /* T4_CY_TCPWM_COUNTER_PDL_H */


/* [] END OF FILE */
