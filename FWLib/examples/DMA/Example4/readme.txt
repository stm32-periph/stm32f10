/******************** (C) COPYRIGHT 2007 STMicroelectronics ********************
* File Name          : readme.txt
* Author             : MCD Application Team
* Version            : V1.0
* Date               : 10/08/2007
* Description        : Description of the DMA Example4.
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
This example provides a description of how to use a DMA channel to transfer
continuously a data from a peripheral (ADC) to another (TIM1) supporting DMA transfer.

The ADC channel 14 is configured to be converted continuously. TIM1_CH1 is configured
to generate a PWM signal on its output.
The dedicated DMA channel5 is configured to transfer in circular mode the last ADC 
channel14 converted value to the TIM1_CCR1 register. The DMA channel request is driven
by the TIM1 update EVENT. The duty cycle of TIM1_CH1 output signal is then changed
each time the input voltage value on ADC channel 14 pin is modified.
The duty cycle variation can be visualized on oscilloscope on the TIM1_CH1 pin
PA.08 while changing the analog input on ADC channel 14 using the potentiometer.


Directory contents
==================
stm32f10x_conf.h  Library Configuration file
stm32f10x_it.c    Interrupt handlers
stm32f10x_it.h    Interrupt handlers header file
main.c            Main program


Hardware environment
====================
 - Connect a variable power supply 0-3.3V to ADC Channel14 mapped on pin PC.04
   (potentiometer RV1 on STM3210B-EVAL board)
 - Connect an oscilloscope to TIM1_CH1 (PA.08) pin  
      

How to use it
=============
In order to make the program work, you must do the following :
- Create a project and setup all your toolchain's start-up files
- Compile the directory content files and required Library files :
  + stm32f10x_lib.c
  + stm32f10x_dma.c
  + stm32f10x_rcc.c
  + stm32f10x_gpio.c
  + stm32f10x_adc.c
  + stm32f10x_tim1.c
  + stm32f10x_nvic.c
  + stm32f10x_flash.c
    
- Link all compiled files and load your image into either RAM or FLASH
- Run the example


******************* (C) COPYRIGHT 2007 STMicroelectronics *****END OF FILE******
