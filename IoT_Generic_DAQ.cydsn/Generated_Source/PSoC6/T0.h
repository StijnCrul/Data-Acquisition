/*******************************************************************************
* File Name: T0.h
* Version 1.0
*
* Description:
*  This file provides constants and parameter values for the T0
*  component.
*
********************************************************************************
* Copyright 2016-2017, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(T0_CY_TCPWM_COUNTER_PDL_H)
#define T0_CY_TCPWM_COUNTER_PDL_H

#include "cyfitter.h"
#include "tcpwm/cy_tcpwm_counter.h"

   
/*******************************************************************************
* Variables
*******************************************************************************/
/**
* \addtogroup group_globals
* @{
*/
extern uint8_t  T0_initVar;
extern cy_stc_tcpwm_counter_config_t const T0_config;
/** @} group_globals */


/***************************************
*  Conditional Compilation Parameters
***************************************/

#define T0_INIT_COMPARE_OR_CAPTURE    (0UL)


/***************************************
*        Function Prototypes
****************************************/
/**
* \addtogroup group_general
* @{
*/
void T0_Start(void);
__STATIC_INLINE cy_en_tcpwm_status_t T0_Init(cy_stc_tcpwm_counter_config_t const *config);
__STATIC_INLINE void T0_DeInit(void);
__STATIC_INLINE void T0_Enable(void);
__STATIC_INLINE void T0_Disable(void);
__STATIC_INLINE uint32_t T0_GetStatus(void);

#if(CY_TCPWM_COUNTER_MODE_CAPTURE == T0_INIT_COMPARE_OR_CAPTURE)
    __STATIC_INLINE uint32_t T0_GetCapture(void);
    __STATIC_INLINE uint32_t T0_GetCaptureBuf(void);
#else
    __STATIC_INLINE void T0_SetCompare0(uint32_t compare0);
    __STATIC_INLINE uint32_t T0_GetCompare0(void);
    __STATIC_INLINE void T0_SetCompare1(uint32_t compare1);
    __STATIC_INLINE uint32_t T0_GetCompare1(void);
    __STATIC_INLINE void T0_EnableCompareSwap(bool enable);
#endif /* (CY_TCPWM_COUNTER_MODE_CAPTURE == T0_INIT_COMPARE_OR_CAPTURE) */

__STATIC_INLINE void T0_SetCounter(uint32_t count);
__STATIC_INLINE uint32_t T0_GetCounter(void);
__STATIC_INLINE void T0_SetPeriod(uint32_t period);
__STATIC_INLINE uint32_t T0_GetPeriod(void);
__STATIC_INLINE void T0_TriggerStart(void);
__STATIC_INLINE void T0_TriggerReload(void);
__STATIC_INLINE void T0_TriggerStop(void);
__STATIC_INLINE void T0_TriggerCapture(void);
__STATIC_INLINE uint32_t T0_GetInterruptStatus(void);
__STATIC_INLINE void T0_ClearInterrupt(uint32_t source);
__STATIC_INLINE void T0_SetInterrupt(uint32_t source);
__STATIC_INLINE void T0_SetInterruptMask(uint32_t mask);
__STATIC_INLINE uint32_t T0_GetInterruptMask(void);
__STATIC_INLINE uint32_t T0_GetInterruptStatusMasked(void);
/** @} general */


/***************************************
*           API Constants
***************************************/

/**
* \addtogroup group_macros
* @{
*/
/** This is a ptr to the base address of the TCPWM instance */
#define T0_HW                 (T0_TCPWM__HW)

/** This is a ptr to the base address of the TCPWM CNT instance */
#define T0_CNT_HW             (T0_TCPWM__CNT_HW)

/** This is the counter instance number in the selected TCPWM */
#define T0_CNT_NUM            (T0_TCPWM__CNT_IDX)

/** This is the bit field representing the counter instance in the selected TCPWM */
#define T0_CNT_MASK           (1UL << T0_CNT_NUM)
/** @} group_macros */

#define T0_INPUT_MODE_MASK    (0x3U)
#define T0_INPUT_DISABLED     (7U)


/*******************************************************************************
* Function Name: T0_Init
****************************************************************************//**
*
* Invokes the Cy_TCPWM_Counter_Init() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE cy_en_tcpwm_status_t T0_Init(cy_stc_tcpwm_counter_config_t const *config)
{
    return(Cy_TCPWM_Counter_Init(T0_HW, T0_CNT_NUM, config));
}


/*******************************************************************************
* Function Name: T0_DeInit
****************************************************************************//**
*
* Invokes the Cy_TCPWM_Counter_DeInit() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void T0_DeInit(void)                   
{
    Cy_TCPWM_Counter_DeInit(T0_HW, T0_CNT_NUM, &T0_config);
}

/*******************************************************************************
* Function Name: T0_Enable
****************************************************************************//**
*
* Invokes the Cy_TCPWM_Enable_Multiple() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void T0_Enable(void)                   
{
    Cy_TCPWM_Enable_Multiple(T0_HW, T0_CNT_MASK);
}


/*******************************************************************************
* Function Name: T0_Disable
****************************************************************************//**
*
* Invokes the Cy_TCPWM_Disable_Multiple() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void T0_Disable(void)                  
{
    Cy_TCPWM_Disable_Multiple(T0_HW, T0_CNT_MASK);
}


/*******************************************************************************
* Function Name: T0_GetStatus
****************************************************************************//**
*
* Invokes the Cy_TCPWM_Counter_GetStatus() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE uint32_t T0_GetStatus(void)                
{
    return(Cy_TCPWM_Counter_GetStatus(T0_HW, T0_CNT_NUM));
}


#if(CY_TCPWM_COUNTER_MODE_CAPTURE == T0_INIT_COMPARE_OR_CAPTURE)
    /*******************************************************************************
    * Function Name: T0_GetCapture
    ****************************************************************************//**
    *
    * Invokes the Cy_TCPWM_Counter_GetCapture() PDL driver function.
    *
    *******************************************************************************/
    __STATIC_INLINE uint32_t T0_GetCapture(void)               
    {
        return(Cy_TCPWM_Counter_GetCapture(T0_HW, T0_CNT_NUM));
    }


    /*******************************************************************************
    * Function Name: T0_GetCaptureBuf
    ****************************************************************************//**
    *
    * Invokes the Cy_TCPWM_Counter_GetCaptureBuf() PDL driver function.
    *
    *******************************************************************************/
    __STATIC_INLINE uint32_t T0_GetCaptureBuf(void)            
    {
        return(Cy_TCPWM_Counter_GetCaptureBuf(T0_HW, T0_CNT_NUM));
    }
#else
    /*******************************************************************************
    * Function Name: T0_SetCompare0
    ****************************************************************************//**
    *
    * Invokes the Cy_TCPWM_Counter_SetCompare0() PDL driver function.
    *
    *******************************************************************************/
    __STATIC_INLINE void T0_SetCompare0(uint32_t compare0)      
    {
        Cy_TCPWM_Counter_SetCompare0(T0_HW, T0_CNT_NUM, compare0);
    }


    /*******************************************************************************
    * Function Name: T0_GetCompare0
    ****************************************************************************//**
    *
    * Invokes the Cy_TCPWM_Counter_GetCompare0() PDL driver function.
    *
    *******************************************************************************/
    __STATIC_INLINE uint32_t T0_GetCompare0(void)              
    {
        return(Cy_TCPWM_Counter_GetCompare0(T0_HW, T0_CNT_NUM));
    }


    /*******************************************************************************
    * Function Name: T0_SetCompare1
    ****************************************************************************//**
    *
    * Invokes the Cy_TCPWM_Counter_SetCompare1() PDL driver function.
    *
    *******************************************************************************/
    __STATIC_INLINE void T0_SetCompare1(uint32_t compare1)      
    {
        Cy_TCPWM_Counter_SetCompare1(T0_HW, T0_CNT_NUM, compare1);
    }


    /*******************************************************************************
    * Function Name: T0_GetCompare1
    ****************************************************************************//**
    *
    * Invokes the Cy_TCPWM_Counter_GetCompare1() PDL driver function.
    *
    *******************************************************************************/
    __STATIC_INLINE uint32_t T0_GetCompare1(void)              
    {
        return(Cy_TCPWM_Counter_GetCompare1(T0_HW, T0_CNT_NUM));
    }


    /*******************************************************************************
    * Function Name: T0_EnableCompareSwap
    ****************************************************************************//**
    *
    * Invokes the Cy_TCPWM_Counter_EnableCompareSwap() PDL driver function.
    *
    *******************************************************************************/
    __STATIC_INLINE void T0_EnableCompareSwap(bool enable)  
    {
        Cy_TCPWM_Counter_EnableCompareSwap(T0_HW, T0_CNT_NUM, enable);
    }
#endif /* (CY_TCPWM_COUNTER_MODE_CAPTURE == T0_INIT_COMPARE_OR_CAPTURE) */


/*******************************************************************************
* Function Name: T0_SetCounter
****************************************************************************//**
*
* Invokes the Cy_TCPWM_Counter_SetCounter() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void T0_SetCounter(uint32_t count)          
{
    Cy_TCPWM_Counter_SetCounter(T0_HW, T0_CNT_NUM, count);
}


/*******************************************************************************
* Function Name: T0_GetCounter
****************************************************************************//**
*
* Invokes the Cy_TCPWM_Counter_GetCounter() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE uint32_t T0_GetCounter(void)               
{
    return(Cy_TCPWM_Counter_GetCounter(T0_HW, T0_CNT_NUM));
}


/*******************************************************************************
* Function Name: T0_SetPeriod
****************************************************************************//**
*
* Invokes the Cy_TCPWM_Counter_SetPeriod() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void T0_SetPeriod(uint32_t period)          
{
    Cy_TCPWM_Counter_SetPeriod(T0_HW, T0_CNT_NUM, period);
}


/*******************************************************************************
* Function Name: T0_GetPeriod
****************************************************************************//**
*
* Invokes the Cy_TCPWM_Counter_GetPeriod() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE uint32_t T0_GetPeriod(void)                
{
    return(Cy_TCPWM_Counter_GetPeriod(T0_HW, T0_CNT_NUM));
}


/*******************************************************************************
* Function Name: T0_TriggerStart
****************************************************************************//**
*
* Invokes the Cy_TCPWM_TriggerStart() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void T0_TriggerStart(void)             
{
    Cy_TCPWM_TriggerStart(T0_HW, T0_CNT_MASK);
}


/*******************************************************************************
* Function Name: T0_TriggerReload
****************************************************************************//**
*
* Invokes the Cy_TCPWM_TriggerReloadOrIndex() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void T0_TriggerReload(void)     
{
    Cy_TCPWM_TriggerReloadOrIndex(T0_HW, T0_CNT_MASK);
}


/*******************************************************************************
* Function Name: T0_TriggerStop
****************************************************************************//**
*
* Invokes the Cy_TCPWM_TriggerStopOrKill() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void T0_TriggerStop(void)
{
    Cy_TCPWM_TriggerStopOrKill(T0_HW, T0_CNT_MASK);
}


/*******************************************************************************
* Function Name: T0_TriggerCapture
****************************************************************************//**
*
* Invokes the Cy_TCPWM_TriggerCaptureOrSwap() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void T0_TriggerCapture(void)     
{
    Cy_TCPWM_TriggerCaptureOrSwap(T0_HW, T0_CNT_MASK);
}


/*******************************************************************************
* Function Name: T0_GetInterruptStatus
****************************************************************************//**
*
* Invokes the Cy_TCPWM_GetInterruptStatus() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE uint32_t T0_GetInterruptStatus(void)       
{
    return(Cy_TCPWM_GetInterruptStatus(T0_HW, T0_CNT_NUM));
}


/*******************************************************************************
* Function Name: T0_ClearInterrupt
****************************************************************************//**
*
* Invokes the Cy_TCPWM_ClearInterrupt() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void T0_ClearInterrupt(uint32_t source)     
{
    Cy_TCPWM_ClearInterrupt(T0_HW, T0_CNT_NUM, source);
}


/*******************************************************************************
* Function Name: T0_SetInterrupt
****************************************************************************//**
*
* Invokes the Cy_TCPWM_SetInterrupt() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void T0_SetInterrupt(uint32_t source)
{
    Cy_TCPWM_SetInterrupt(T0_HW, T0_CNT_NUM, source);
}


/*******************************************************************************
* Function Name: T0_SetInterruptMask
****************************************************************************//**
*
* Invokes the Cy_TCPWM_SetInterruptMask() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void T0_SetInterruptMask(uint32_t mask)     
{
    Cy_TCPWM_SetInterruptMask(T0_HW, T0_CNT_NUM, mask);
}


/*******************************************************************************
* Function Name: T0_GetInterruptMask
****************************************************************************//**
*
* Invokes the Cy_TCPWM_GetInterruptMask() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE uint32_t T0_GetInterruptMask(void)         
{
    return(Cy_TCPWM_GetInterruptMask(T0_HW, T0_CNT_NUM));
}


/*******************************************************************************
* Function Name: T0_GetInterruptStatusMasked
****************************************************************************//**
*
* Invokes the Cy_TCPWM_GetInterruptStatusMasked() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE uint32_t T0_GetInterruptStatusMasked(void)
{
    return(Cy_TCPWM_GetInterruptStatusMasked(T0_HW, T0_CNT_NUM));
}

#endif /* T0_CY_TCPWM_COUNTER_PDL_H */


/* [] END OF FILE */
