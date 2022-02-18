/******************** (C) COPYRIGHT 2007 STMicroelectronics ********************
* File Name          : readme.txt
* Author             : MCD Application Team
* Version            : V1.0
* Date               : 10/08/2007
* Description        : Description of the NVIC Example1.
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
This example demontrates the use of the Nested Vectored Interrupt Controller (NVIC): 

- Configuration of 2 EXTI Lines (Line0 & Line9)to generate an interrupt on each 
  falling edge and use the SysTick interrupt.
- These interrupts are configured with the following parameters:
  EXTI Line0: o PreemptionPriority = PreemptionPriorityValue
              o SubPriority = 0
  EXTI Line9: o PreemptionPriority = 0
              o SubPriority = 1           
  SysTick Handler: o PreemptionPriority = !PreemptionPriorityValue
                   o SubPriority = 0             
First, the PreemptionPriorityValue is equal to 0, the EXTI Line0 has higher 
preemption priority than the SysTick handler. 

In the EXTI Line9 interrupt routine the EXTI Line0 and SysTick preemption priorities
are inverted. 
In the EXTI Line0 interrupt routine the pending bit of the SysTick interrupt is
set this will cause SysTick ISR to preempt the EXTI Line0 ISR only if it has
higher preemption priority.

The system behaves as following: 
1) The first time EXTI Line9 interrupt occurs the SysTick preemption became higher
than  EXTI Line0 one. So when the EXTI Line0 interrupt occurs, the SysTick ISR is
executed and the PreemptionOccured variable became TRUE and the four leds connected
to pins PC.06, PC.07, PC.08 and PC.09 start toggling.

2) When the next EXTI Line9 interrupt occurs the SysTick preemption became lower than
EXTI Line0 one. So when the EXTI Line0 interrupt occurs, the PreemptionOccured
variable became FALSE and the four leds connected to pins PC.06, PC.07, PC.08 and
PC.09 stop toggling.

Then this behavior is repeated from point 1) in an infinite loop.


Directory contents
==================
stm32f10x_conf.h  Library Configuration file
stm32f10x_it.c    Interrupt handlers
stm32f10x_it.h    Interrupt handlers header file
main.c          Main program


Hardware environment
====================
 - Connect four leds to pins PC.06, PC.07, PC.08 and PC.09 (respectively LD1, LD2,
   LD3 and LD4 on STM3210B-EVAL board).
 - Connect a push-button to pin PA.00 (EXTI Line0) (Wakeup push-button on
   STM3210B-EVAL board).  
 - Connect a push-button to pin PB.09 (EXTI Line9) (Key push-button on
   STM3210B-EVAL board). 
    
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
  + stm32f10x_flash.c
    
- Link all compiled files and load your image into either RAM or FLASH
- Run the example


******************* (C) COPYRIGHT 2007 STMicroelectronics *****END OF FILE******
