/******************** (C) COPYRIGHT 2007 STMicroelectronics ********************
* File Name          : readme.txt
* Author             : MCD Application Team
* Version            : V1.0
* Date               : 10/08/2007
* Description        : Description of the NVIC Example4.
********************************************************************************
* THE PRESENT SOFTWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
* WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE TIME.
* AS A RESULT, STMICROELECTRONICS SHALL NOT BE HELD LIABLE FOR ANY DIRECT,
* INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING FROM THE
* CONTENT OF SUCH SOFTWARE AND/OR THE USE MADE BY CUSTOMERS OF THE CODING
* INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
*******************************************************************************/

Example description
===================
This example describes how to use the NVIC firmware library to demonstrate the 
Cortex-M3 low power modes capabilities (WFE and WFI). 

This example uses three EXTI lines(Line0, Line9 & Line13)to generate interrupts
and event on each falling edge. The EXTI Line 0 and Line 13 are configured in 
interrupt mode and the EXTI Line 9 in event mode. The user has to select which 
low power mode would execute through a five define in the main code.

These choices are:

   - Wait For Interrupt (WFI) Sleep On Exit: in this mode the WFI instruction is
    excecuted automatically on an exception Return. The exception will be executed
    if has enough priority to run and the core will return in the WFI mode. 
    To run this behaviour proceed as following:
      
      * Choose the #WFISLEEPONEXIT define and comment others defines
      * run the example
      * The EXTI Line 0 toggles LED connected to PC.08 pin.
      * Push the EXTI Line 13, the SLEEPONEXIT function is selected
      Any edge on the EXTI Line 0 or Line 13 will execute the EXTI interrupt, when
      exit from the ISR the core will enter WFI mode. Any time you push the EXTI Line 0
      the core exit from WFI mode, the LED connected to the PC.08 is toggled then the
      core enters again in WFI mode.
      This behavior is repeated in an infinite loop.

    - Wait For Interrupt (WFI) Sleep Now: in this mode the WFI instruction is 
      excecuted directly. To run this behaviour proceed as following:

      * Choose the #WFISLEEPNOW define and comment others defines
      * run the example
      * The EXTI Line 13 will toggle LED connected to PC.06 and put the core in the WFI mode.  
      * To wakeup the Core use the EXTI Line 0 that will toggle the LED connected
        to PC.08 pin
      This behavior is repeated in an infinite loop.
  
   - Wait For Event (WFE) SEV ON PEND: in this mode the WFE instruction is excecuted
     directly and the main instruction stream (execution priority) is boosted by the
     register PRIMASK (main priority = 0).
     To run this behaviour proceed as following:

     * Choose the #WFESEVONPEND define and comment others defines
     * run the example
     * The EXTI Line 13 will boost the execution priority to 0 (no interrupt will be
       executed after due to the priority boosting), toggle LED connected to PC.06 and
       put the core in WFE mode. 
     * To wakeUp the Core use the EXTI Line 0 that will not toggle the LED connected
       to PC.08 pin but will only wakeup the core from the WFE (SEV ON PEND). 
       This EXTI Line interrupt has passed from unpended state to a pended state which
       wakeup the core from the WFE.
     * To wakeup the core also you can use the EXTI Line 9 configured in event
       mode.
     * if the #RTC_Alarm_WFEWakeUp define is enabled, the RTC alarm will wakeUp the Core 
       after 6 seconds (if none of EXTI Line 13 and EXTI Line 9 was used before this delay
       to wakeUp the Core)
  
   - Wait For Event (WFE) SEV ON EVENT: in this mode the WFE instruction is 
     excecuted directly. To run this behaviour proceed as following:

    * Choose the #WFESEVONEVENT define and comment others defines
    * run the example
    * The EXTI Line 13 will toggle LED connected to PC.06 and put the core in the WFE mode. 
    * To wakeup the Core use the EXTI Line 0 that will toggle the LED connected
      to PC.08 pin.
    * To wakeup the core also you can use the EXTI Line 9 configured in event mode.
    * if the #RTC_Alarm_WFEWakeUp define is enabled, the RTC alarm will wakeUp the Core 
      after 6 seconds (if none of EXTI Line 13 and EXTI Line 9 was used before this delay
      to wakeup the Core)
      This behavior is repeated in an infinite loop.

A LED connected to PC.09 is toggled to indicate whether the MCU is in RUN or in low power mode.

Directory contents
==================
stm32f10x_conf.h  Library Configuration file
stm32f10x_it.c    Interrupt handlers
stm32f10x_it.h    Interrupt handlers header file
main.c            Main program


Hardware environment
====================
 - Connect four leds to pins PC.06, PC.07, PC.08 and PC.09(respectively LD1, LD2, LD3 and LD4
   on STM3210B-EVAL board).
 - Connect a push-button to pin PB.09 (EXTI Line9) (Key push-button on STM3210B-EVAL board).
 - Connect a push-button to pin PA.00 (EXTI Line0) (Wakeup push-button on STM3210B-EVAL board).
 - Connect a push-button to pin PC.13 (EXTI Line13) (Tamper push-button on STM3210B-EVAL board).
       
How to use it
=============
In order to make the program work, you must do the following :
- Create a project and setup all your toolchain's start-up files
- Compile the directory content files and required Library files :
  + stm32f10x_lib.c
  + stm32f10x_exti.c
  + stm32f10x_gpio.c
  + stm32f10x_rcc.c
  + stm32f10x_nvic.c
  + stm32f10x_rtc.c
  + stm32f10x_pwr.c
  + stm32f10x_bkp.c
  + stm32f10x_flash.c
    
- Link all compiled files and load your image into either RAM or FLASH
- Run the example


******************* (C) COPYRIGHT 2007 STMicroelectronics *****END OF FILE******
