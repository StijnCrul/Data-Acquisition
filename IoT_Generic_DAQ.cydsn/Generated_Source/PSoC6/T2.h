/*******************************************************************************
* File Name: T2.h
* Version 1.0
*
* Description:
*  This file provides constants and parameter values for the T2
*  component.
*
********************************************************************************
* Copyright 2016-2017, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(T2_CY_TCPWM_COUNTER_PDL_H)
#define T2_CY_TCPWM_COUNTER_PDL_H

#include "cyfitter.h"
#include "tcpwm/cy_tcpwm_counter.h"

   
/*******************************************************************************
* Variables
*******************************************************************************/
/**
* \addtogroup group_globals
* @{
*/
extern uint8_t  T2_initVar;
extern cy_stc_tcpwm_counter_config_t const T2_config;
/** @} group_globals */


/***************************************
*  Conditional Compilation Parameters
***************************************/

#define T2_INIT_COMPARE_OR_CAPTURE    (0UL)


/***************************************
*        Function Prototypes
****************************************/
/**
* \addtogroup group_general
* @{
*/
void T2_Start(void);
__STATIC_INLINE cy_en_tcpwm_status_t T2_Init(cy_stc_tcpwm_counter_config_t const *config);
__STATIC_INLINE void T2_DeInit(void);
__STATIC_INLINE void T2_Enable(void);
__STATIC_INLINE void T2_Disable(void);
__STATIC_INLINE uint32_t T2_GetStatus(void);

#if(CY_TCPWM_COUNTER_MODE_CAPTURE == T2_INIT_COMPARE_OR_CAPTURE)
    __STATIC_INLINE uint32_t T2_GetCapture(void);
    __STATIC_INLINE uint32_t T2_GetCaptureBuf(void);
#else
    __STATIC_INLINE void T2_SetCompare0(uint32_t compare0);
    __STATIC_INLINE uint32_t T2_GetCompare0(void);
    __STATIC_INLINE void T2_SetCompare1(uint32_t compare1);
    __STATIC_INLINE uint32_t T2_GetCompare1(void);
    __STATIC_INLINE void T2_EnableCompareSwap(bool enable);
#endif /* (CY_TCPWM_COUNTER_MODE_CAPTURE == T2_INIT_COMPARE_OR_CAPTURE) */

__STATIC_INLINE void T2_SetCounter(uint32_t count);
__STATIC_INLINE uint32_t T2_GetCounter(void);
__STATIC_INLINE void T2_SetPeriod(uint32_t period);
__STATIC_INLINE uint32_t T2_GetPeriod(void);
__STATIC_INLINE void T2_TriggerStart(void);
__STATIC_INLINE void T2_TriggerReload(void);
__STATIC_INLINE void T2_TriggerStop(void);
__STATIC_INLINE void T2_TriggerCapture(void);
__STATIC_INLINE uint32_t T2_GetInterruptStatus(void);
__STATIC_INLINE void T2_ClearInterrupt(uint32_t source);
__STATIC_INLINE void T2_SetInterrupt(uint32_t source);
__STATIC_INLINE void T2_SetInterruptMask(uint32_t mask);
__STATIC_INLINE uint32_t T2_GetInterruptMask(void);
__STATIC_INLINE uint32_t T2_GetInterruptStatusMasked(void);
/** @} general */


/***************************************
*           API Constants
***************************************/

/**
* \addtogroup group_macros
* @{
*/
/** This is a ptr to the base address of the TCPWM instance */
#define T2_HW                 (T2_TCPWM__HW)

/** This is a ptr to the base address of the TCPWM CNT instance */
#define T2_CNT_HW             (T2_TCPWM__CNT_HW)

/** This is the counter instance number in the selected TCPWM */
#define T2_CNT_NUM            (T2_TCPWM__CNT_IDX)

/** This is the bit field representing the counter instance in the selected TCPWM */
#define T2_CNT_MASK           (1UL << T2_CNT_NUM)
/** @} group_macros */

#define T2_INPUT_MODE_MASK    (0x3U)
#define T2_INPUT_DISABLED     (7U)


/*******************************************************************************
* Function Name: T2_Init
****************************************************************************//**
*
* Invokes the Cy_TCPWM_Counter_Init() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE cy_en_tcpwm_status_t T2_Init(cy_stc_tcpwm_counter_config_t const *config)
{
    return(Cy_TCPWM_Counter_Init(T2_HW, T2_CNT_NUM, config));
}


/*******************************************************************************
* Function Name: T2_DeInit
****************************************************************************//**
*
* Invokes the Cy_TCPWM_Counter_DeInit() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void T2_DeInit(void)                   
{
    Cy_TCPWM_Counter_DeInit(T2_HW, T2_CNT_NUM, &T2_config);
}

/*******************************************************************************
* Function Name: T2_Enable
****************************************************************************//**
*
* Invokes the Cy_TCPWM_Enable_Multiple() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void T2_Enable(void)                   
{
    Cy_TCPWM_Enable_Multiple(T2_HW, T2_CNT_MASK);
}


/*******************************************************************************
* Function Name: T2_Disable
****************************************************************************//**
*
* Invokes the Cy_TCPWM_Disable_Multiple() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void T2_Disable(void)                  
{
    Cy_TCPWM_Disable_Multiple(T2_HW, T2_CNT_MASK);
}


/*******************************************************************************
* Function Name: T2_GetStatus
****************************************************************************//**
*
* Invokes the Cy_TCPWM_Counter_GetStatus() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE uint32_t T2_GetStatus(void)                
{
    return(Cy_TCPWM_Counter_GetStatus(T2_HW, T2_CNT_NUM));
}


#if(CY_TCPWM_COUNTER_MODE_CAPTURE == T2_INIT_COMPARE_OR_CAPTURE)
    /*******************************************************************************
    * Function Name: T2_GetCapture
    ****************************************************************************//**
    *
    * Invokes the Cy_TCPWM_Counter_GetCapture() PDL driver function.
    *
    *******************************************************************************/
    __STATIC_INLINE uint32_t T2_GetCapture(void)               
    {
        return(Cy_TCPWM_Counter_GetCapture(T2_HW, T2_CNT_NUM));
    }


    /*******************************************************************************
    * Function Name: T2_GetCaptureBuf
    ****************************************************************************//**
    *
    * Invokes the Cy_TCPWM_Counter_GetCaptureBuf() PDL driver function.
    *
    *******************************************************************************/
    __STATIC_INLINE uint32_t T2_GetCaptureBuf(void)            
    {
        return(Cy_TCPWM_Counter_GetCaptureBuf(T2_HW, T2_CNT_NUM));
    }
#else
    /*******************************************************************************
    * Function Name: T2_SetCompare0
    ****************************************************************************//**
    *
    * Invokes the Cy_TCPWM_Counter_SetCompare0() PDL driver function.
    *
    *******************************************************************************/
    __STATIC_INLINE void T2_SetCompare0(uint32_t compare0)      
    {
        Cy_TCPWM_Counter_SetCompare0(T2_HW, T2_CNT_NUM, compare0);
    }


    /*******************************************************************************
    * Function Name: T2_GetCompare0
    ****************************************************************************//**
    *
    * Invokes the Cy_TCPWM_Counter_GetCompare0() PDL driver function.
    *
    *******************************************************************************/
    __STATIC_INLINE uint32_t T2_GetCompare0(void)              
    {
        return(Cy_TCPWM_Counter_GetCompare0(T2_HW, T2_CNT_NUM));
    }


    /*******************************************************************************
    * Function Name: T2_SetCompare1
    ****************************************************************************//**
    *
    * Invokes the Cy_TCPWM_Counter_SetCompare1() PDL driver function.
    *
    *******************************************************************************/
    __STATIC_INLINE void T2_SetCompare1(uint32_t compare1)      
    {
        Cy_TCPWM_Counter_SetCompare1(T2_HW, T2_CNT_NUM, compare1);
    }


    /*******************************************************************************
    * Function Name: T2_GetCompare1
    ****************************************************************************//**
    *
    * Invokes the Cy_TCPWM_Counter_GetCompare1() PDL driver function.
    *
    *******************************************************************************/
    __STATIC_INLINE uint32_t T2_GetCompare1(void)              
    {
        return(Cy_TCPWM_Counter_GetCompare1(T2_HW, T2_CNT_NUM));
    }


    /*******************************************************************************
    * Function Name: T2_EnableCompareSwap
    ****************************************************************************//**
    *
    * Invokes the Cy_TCPWM_Counter_EnableCompareSwap() PDL driver function.
    *
    *******************************************************************************/
    __STATIC_INLINE void T2_EnableCompareSwap(bool enable)  
    {
        Cy_TCPWM_Counter_EnableCompareSwap(T2_HW, T2_CNT_NUM, enable);
    }
#endif /* (CY_TCPWM_COUNTER_MODE_CAPTURE == T2_INIT_COMPARE_OR_CAPTURE) */


/*******************************************************************************
* Function Name: T2_SetCounter
****************************************************************************//**
*
* Invokes the Cy_TCPWM_Counter_SetCounter() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void T2_SetCounter(uint32_t count)          
{
    Cy_TCPWM_Counter_SetCounter(T2_HW, T2_CNT_NUM, count);
}


/*******************************************************************************
* Function Name: T2_GetCounter
****************************************************************************//**
*
* Invokes the Cy_TCPWM_Counter_GetCounter() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE uint32_t T2_GetCounter(void)               
{
    return(Cy_TCPWM_Counter_GetCounter(T2_HW, T2_CNT_NUM));
}


/*******************************************************************************
* Function Name: T2_SetPeriod
****************************************************************************//**
*
* Invokes the Cy_TCPWM_Counter_SetPeriod() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void T2_SetPeriod(uint32_t period)          
{
    Cy_TCPWM_Counter_SetPeriod(T2_HW, T2_CNT_NUM, period);
}


/*******************************************************************************
* Function Name: T2_GetPeriod
****************************************************************************//**
*
* Invokes the Cy_TCPWM_Counter_GetPeriod() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE uint32_t T2_GetPeriod(void)                
{
    return(Cy_TCPWM_Counter_GetPeriod(T2_HW, T2_CNT_NUM));
}


/*******************************************************************************
* Function Name: T2_TriggerStart
****************************************************************************//**
*
* Invokes the Cy_TCPWM_TriggerStart() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void T2_TriggerStart(void)             
{
    Cy_TCPWM_TriggerStart(T2_HW, T2_CNT_MASK);
}


/*******************************************************************************
* Function Name: T2_TriggerReload
****************************************************************************//**
*
* Invokes the Cy_TCPWM_TriggerReloadOrIndex() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void T2_TriggerReload(void)     
{
    Cy_TCPWM_TriggerReloadOrIndex(T2_HW, T2_CNT_MASK);
}


/*******************************************************************************
* Function Name: T2_TriggerStop
****************************************************************************//**
*
* Invokes the Cy_TCPWM_TriggerStopOrKill() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void T2_TriggerStop(void)
{
    Cy_TCPWM_TriggerStopOrKill(T2_HW, T2_CNT_MASK);
}


/*******************************************************************************
* Function Name: T2_TriggerCapture
****************************************************************************//**
*
* Invokes the Cy_TCPWM_TriggerCaptureOrSwap() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void T2_TriggerCapture(void)     
{
    Cy_TCPWM_TriggerCaptureOrSwap(T2_HW, T2_CNT_MASK);
}


/*******************************************************************************
* Function Name: T2_GetInterruptStatus
****************************************************************************//**
*
* Invokes the Cy_TCPWM_GetInterruptStatus() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE uint32_t T2_GetInterruptStatus(void)       
{
    return(Cy_TCPWM_GetInterruptStatus(T2_HW, T2_CNT_NUM));
}


/*******************************************************************************
* Function Name: T2_ClearInterrupt
****************************************************************************//**
*
* Invokes the Cy_TCPWM_ClearInterrupt() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void T2_ClearInterrupt(uint32_t source)     
{
    Cy_TCPWM_ClearInterrupt(T2_HW, T2_CNT_NUM, source);
}


/*******************************************************************************
* Function Name: T2_SetInterrupt
****************************************************************************//**
*
* Invokes the Cy_TCPWM_SetInterrupt() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void T2_SetInterrupt(uint32_t source)
{
    Cy_TCPWM_SetInterrupt(T2_HW, T2_CNT_NUM, source);
}


/*******************************************************************************
* Function Name: T2_SetInterruptMask
****************************************************************************//**
*
* Invokes the Cy_TCPWM_SetInterruptMask() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void T2_SetInterruptMask(uint32_t mask)     
{
    Cy_TCPWM_SetInterruptMask(T2_HW, T2_CNT_NUM, mask);
}


/*******************************************************************************
* Function Name: T2_GetInterruptMask
****************************************************************************//**
*
* Invokes the Cy_TCPWM_GetInterruptMask() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE uint32_t T2_GetInterruptMask(void)         
{
    return(Cy_TCPWM_GetInterruptMask(T2_HW, T2_CNT_NUM));
}


/*******************************************************************************
* Function Name: T2_GetInterruptStatusMasked
****************************************************************************//**
*
* Invokes the Cy_TCPWM_GetInterruptStatusMasked() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE uint32_t T2_GetInterruptStatusMasked(void)
{
    return(Cy_TCPWM_GetInterruptStatusMasked(T2_HW, T2_CNT_NUM));
}

#endif /* T2_CY_TCPWM_COUNTER_PDL_H */


/* [] END OF FILE */
