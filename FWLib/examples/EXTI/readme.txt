/******************** (C) COPYRIGHT 2007 STMicroelectronics ********************
* File Name          : readme.txt
* Author             : MCD Application Team
* Version            : V1.0
* Date               : 10/08/2007
* Description        : Description of the EXTI Example.
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
This example shows how to configure an external interrupt line.
In this example, the EXTI line 9 is configured to generate an interrupt on each
falling edge. In the interrupt routine a led connected to PC.06 is toggled.
This led will be toggled due to the softawre interrupt generated on EXTI Line9 
then at each falling edge.


Directory contents
==================
stm32f10x_conf.h  Library Configuration file
stm32f10x_it.h    Interrupt handlers header file
stm32f10x_it.c    Interrupt handlers
main.c          Main program


Hardware environment
====================
 - Connect a led to pin PC.06 (LD1 on STM3210B-EVAL board).
 - Connect a push-button to pin PB.09 (EXTI Line9) (Key push-button on STM3210B-EVAL board).


How to use it
=============
In order to make the program work, you must do the following:
- Create a project and setup all your toolchain's start-up files
- Compile the directory content files and required Library files:
  + stm32f10x_lib.c
  + stm32f10x_gpio.c
  + stm32f10x_rcc.c
  + stm32f10x_exti.c
  + stm32f10x_nvic.c
  + stm32f10x_flash.c
  
- Link all compiled files and load your image into either RAM or Flash
- Run the example


******************* (C) COPYRIGHT 2007 STMicroelectronics *****END OF FILE******
