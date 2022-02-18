/******************** (C) COPYRIGHT 2007 STMicroelectronics ********************
* File Name          : readme.txt
* Author             : MCD Application Team
* Version            : V1.0
* Date               : 10/08/2007
* Description        : Description of the IWDG Example.
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
This example shows how to reload at regulate period the IWDG counter using the
SysTick interrupt. The IWDG timeout is set to 280 ms (the timeout may varies due
to LSI frequency dispersion).

SysTick is configured to generate an interrupt every 250 ms. In the SysTick interrupt
service routine (ISR), the IWDG counter is reloaded to prevent an IWDG reset, and the
LED connected to PC.07 is toggled.
EXTI Line9 is connected to the PB.09 pin and configured to generate an interrupt on
its falling edge.
In the NVIC, the EXTI line[9:5] interrupt vector is enabled with a priority equal to 0,
and the SysTick interrupt vector priority is set to 1 (EXTI IT > SysTick IT).

The EXTI Line9 is used to simulate a software failure: when the EXTI Line9 event is
triggered (by pressing the Key push-button on the STM3210B-EVAL board), the
corresponding interrupt is served. In the ISR, the LED connected to PC.07 turns off
and the EXTI line9 pending bit is not cleared. So the CPU executes the EXTI line9 ISR
indefinitely and the SysTick ISR is never entered (IWDG counter not reloaded).
As a result, when the IWDG counter reaches 00h, the IWDG generates a reset.
If the IWDG reset is generated, the LED connected to PC6 turns on after the system
resumes operation.

If the EXTI Line9 event does not occur, the IWDG counter is indefinitely reloaded in
the SysTick ISR, which prevents any IWDG reset.

In this example the system is clocked by the high-speed external (HSE) clock (8 MHz).


Directory contents
==================
stm32f10x_conf.h  Library Configuration file
stm32f10x_it.c    Interrupt handlers
stm32f10x_it.h    Header for stm32f10x_it.c
main.c            Main program


Hardware environment
====================
 - Connect two leds to pins PC.06 and PC.07 (respectively LD1 and LD2 on
   STM3210B-EVAL board).
 - Connect a push-button to pin PB.09 (EXTI line9) (Key push-button on
   STM3210B-EVAL board).

    
How to use it
=============
In order to make the program work, you must do the following :
- Create a project and setup all your toolchain's start-up files
- Compile the directory content files and required Library files :
  + stm32f10x_lib.c
  + stm32f10x_gpio.c
  + stm32f10x_rcc.c
  + stm32f10x_nvic.c
  + stm32f10x_iwdg.c
  + stm32f10x_flash.c
  + stm32f10x_exti.c  
  + stm32f10x_systick.c  

- Link all compiled files and load your image in Flash
- Run the example in standalone mode (without debugger connection)

******************* (C) COPYRIGHT 2007 STMicroelectronics *****END OF FILE******
