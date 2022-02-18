/******************** (C) COPYRIGHT 2007 STMicroelectronics ********************
* File Name          : readme.txt
* Author             : MCD Application Team
* Version            : V1.0
* Date               : 10/08/2007
* Description        : Description of the TIM Example4.
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

This example shows how to configure the TIM peripheral in PWM (Pulse Width Modulation) 
mode.
The TIMxCLK frequency is set to 36 MHz, the Prescaler is 0 so the TIM3 counter clock is
36 MHz. 

The TIM3 is running at 36 KHz: TIM3 Frequency = TIM3 counter clock/(ARR + 1) 


The TIM3 CC1 register value is equal to 500, so the TIM3 Channel 1 generates a 
PWM signal with a frequency equal to 36 KHz and a duty cycle equal to 50%:
TIM3 Channel1 duty cycle = (TIM3_CCR1/ TIM3_ARR + 1)* 100 = 50%

The TIM3 CC2 register value is equal to 375, so the TIM3 Channel 2 generates a 
PWM signal with a frequency equal to 36 KHz and a duty cycle equal to 37.5%:
TIM3 Channel2 duty cycle = (TIM3_CCR2/ TIM3_ARR + 1)* 100 = 37.5%

The TIM3 CC3 register value is equal to 250, so the TIM3 Channel 3 generates a 
PWM signal with a frequency equal to 36 KHz and a duty cycle equal to 25%:
TIM3 Channel3 duty cycle = (TIM3_CCR3/ TIM3_ARR + 1)* 100 = 25%

The TIM3 CC4 register value is equal to 125, so the TIM3 Channel 4 generates a 
PWM signal with a frequency equal to 36 KHz and a duty cycle equal to 12.5%:
TIM3 Channel4 duty cycle = (TIM3_CCR4/ TIM3_ARR + 1)* 100 = 12.5%

The PWM waveform can be displayed using an oscilloscope.



Directory contents
==================
stm32F10x_conf.h  Library Configuration file
stm32F10x_it.c    Interrupt handlers
stm32F10x_it.h    Interrupt handlers header file
main.c            Main program
 

Hardware environment
====================
Connect an oscilloscope on:
- PA.06: (TIM3_CH1)
- PA.07: (TIM3_CH2)
- PB.00: (TIM3_CH3)
- PB.01: (TIM3_CH4) 
to show the four different signals.
  
  
How to use it
=============
In order to make the program work, you must do the following:
- Create a project and setup all your toolchain's start-up files
- Compile the directory content files and required Library files:
  + stm32F10x_lib.c
  + stm32F10x_tim.c
  + stm32F10x_gpio.c
  + stm32F10x_rcc.c
  + stm32F10x_nvic.c
  + stm32F10x_flash.c

- Link all compiled files and load your image into either RAM or Flash
- Run the example


******************* (C) COPYRIGHT 2007 STMicroelectronics *****END OF FILE******
