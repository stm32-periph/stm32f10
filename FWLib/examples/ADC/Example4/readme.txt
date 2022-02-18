/******************** (C) COPYRIGHT 2007 STMicroelectronics ********************
* File Name          : readme.txt
* Author             : MCD Application Team
* Version            : V1.0
* Date               : 10/08/2007
* Description        : Description of the ADC Example4.
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
This example describes how to trigger ADC regular and injected groups channels 
conversion using two external line event. Discontinuous mode is enabled for regular
group channel conversion and configured to convert one regular channel on each 
external trigger.
ADC1 configured to start regular group channel conversion on EXTI11 event.
On detection of the first rising on PE.11 pin, the conversion of the first regular
channel (ADC channel4) is done and its converted value is transfered by DMA to 
ADC_RegularConvertedValueTab table. On the following edge detection, the second 
regular channel (ADC channel14) is automatically converted and its converted value
is stored by DMA in the same table. The number of transmitted data by DMA, in this 
example is limited to 64 data.
The procedure is repeated for both regular channels on each EXTI11 event.
ADC1 is configured to start injected group channel conversion on EXTI15 event.
On detection of the first rising edge on PE.15 pin all selected injected channel, which
are two in this example (ADC channel10 and channel11), are converted and an interrupt 
is generated on JEOC flag rising at the end of all injected channels conversion. 
Both injected channels converted results are stored in ADC_InjectedConvertedValueTab 
table inside the interrupt routine.
The procedure is repeated for injected channels on each EXTI15 event.
The ADC1 clock is set to 14 MHz.


Directory contents
==================
stm32f10x_conf.h  Library Configuration file
stm32f10x_it.c    Interrupt handlers
stm32f10x_it.h    Interrupt handlers header file
main.c            Main program


Hardware environment
====================
 - Connect a known voltage, between 0-3.3V, to ADC Channel14 mapped on pin PC.04
   (potentiometer RV1 on STM3210B-EVAL board), ADC Channel4 mapped on pin PA.04,
   ADC Channel10 mapped on pin PC.00 and ADC Channel11 mapped on pin PC.01.
 - Connect a push-button to pin PE.11 (EXTI Line11) and Connect a push-button to 
   pin PE.15 (EXTI Line15).      
   
How to use it
=============
In order to make the program work, you must do the following :
- Create a project and setup all your toolchain's start-up files
- Compile the directory content files and required Library files :
  + stm32f10x_lib.c
  + stm32f10x_adc.c
  + stm32f10x_dma.c
  + stm32f10x_exti.c
  + stm32f10x_gpio.c
  + stm32f10x_rcc.c
  + stm32f10x_nvic.c
  + stm32f10x_flash.c
    
- Link all compiled files and load your image into either RAM or FLASH
- Run the example


******************* (C) COPYRIGHT 2007 STMicroelectronics *****END OF FILE******
