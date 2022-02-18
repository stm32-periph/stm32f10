/******************** (C) COPYRIGHT 2007 STMicroelectronics ********************
* File Name          : readme.txt
* Author             : MCD Application Team
* Version            : V1.0
* Date               : 10/08/2007
* Description        : Description of the WWDG Example.
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
This example shows how to update at regulate period the WWDG counter using the
Early Wakeup interrupt (EWI).

The WWDG timeout is set to 262 ms, the refresh window is set to 65 and the EWI is
enabled. When the WWDG counter reaches 64, the EWI is generated. In the WWDG ISR,
the counter is refreshed to prevent a WWDG reset and the LED connected to PC.07 is
toggled.
EXTI Line9 is connected to the PB.09 pin, and configured to generate an interrupt
on the falling edge of the signal.
In the NVIC (nested vectored interrupt controller), the EXTI Line[9:5] interrupt
vector is enabled with a priority equal to 0 and the WWDG interrupt vector is
enabled with a priority equal to 1 (EXTI IT > WWDG IT).

EXTI Line9 is used to simulate a software failure: once the EXTI Line9 event occurs
(by pressing the Key push-button on the STM3210B-EVAL board), the corresponding
interrupt is served. In the ISR, the LED connected to PC.07 is turned off and the
EXTI Line9 pending bit is not cleared. So the CPU executes the EXTI Line9 ISR
indefinitely and the WWDG ISR is never executed (the WWDG counter is not updated).
As a result, when the WWDG counter falls to 63, the WWDG reset occurs.
If the WWDG reset is generated, after the system resumes from reset, the LED connected
to PC.06 turns on.

If the EXTI Line9 event does not occur, the WWDG counter is indefinitely refreshed
in the WWDG ISR, and there is no WWDG reset.

In this example the system is clocked by HSE, the high-speed external clock (8 MHz).


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
  + stm32f10x_wwdg.c
  + stm32f10x_flash.c
  + stm32f10x_exti.c  
- Link all compiled files and load your image in Flash
- Run the example in standalone mode (without debugger connection)

******************* (C) COPYRIGHT 2007 STMicroelectronics *****END OF FILE******
