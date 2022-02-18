/******************** (C) COPYRIGHT 2007 STMicroelectronics ********************
* File Name          : readme.txt
* Author             : MCD Application Team
* Version            : V1.0
* Date               : 10/08/2007
* Description        : Description of the NVIC Example2.
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
This example demontrates the use of the Nested Vectored Interrupt Controller (NVIC)
IRQ Channels configuration: 

- Configuration of 3 TIM (TIM2..TIM4)timers to generate an interrupt on each 
  counter update event.
- The three timers are linked to their correspondant Update IRQ channel.
- Assignment of a ascendant IRQ priority for each IRQ channel :
  TIM2 has a preemption priority of 0 and TIM4 has a preemption priority of 2.
- In each interrupt routine: 
   - TIM2 toggles a led connected to PC.06 pin each 1s 
   - TIM3 toggles a led connected to PC.07 pin each 2s 
   - TIM4 toggles a led connected to PC.08 pin each 3s 


Directory contents
==================
stm32f10x_conf.h  Library Configuration file
stm32f10x_it.c    Interrupt handlers
stm32f10x_it.h    Interrupt handlers header file
main.c            Main program


Hardware environment
====================
 - Connect three leds to pins PC.06, PC.07 and PC.08 (respectively LD1, LD2 and
   LD3 on STM3210B-EVAL board).
    
How to use it
=============
In order to make the program work, you must do the following :
- Create a project and setup all your toolchain's start-up files
- Compile the directory content files and required Library files :
  + stm32f10x_lib.c
  + stm32f10x_gpio.c
  + stm32f10x_rcc.c
  + stm32f10x_nvic.c
  + stm32f10x_tim.c
  + stm32f10x_flash.c
    
- Link all compiled files and load your image into either RAM or FLASH
- Run the example


******************* (C) COPYRIGHT 2007 STMicroelectronics *****END OF FILE******
