/******************** (C) COPYRIGHT 2007 STMicroelectronics ********************
* File Name          : readme.txt
* Author             : MCD Application Team
* Version            : V1.0
* Date               : 10/08/2007
* Description        : Description of the RCC Example.
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
This example shows how to configure the system clock source, AHB, APB2 and APB1
prescaler. The system clock frequency is set to 72MHz using the PLL. 
It shows how to use, for debug purpose, the RCC_GetClocksFreq function to retrieve
the current status and frequencies of different on chip clocks. You can see the
RCC_ClockFreq structure content, which hold the frequencies of different on chip
clocks, using your toolchain debugger.

This example handles also the High Speed External clock (HSE) failure detection:
when the HSE clock disappears (broken or disconnected external Quartz); HSE, PLL
are disabled (but no change on PLL config), HSI selected as system clock source
and an interrupt (NMI) is generated. In the NMI ISR, the HSE, HSE ready interrupt
are enabled and once HSE clock recover, the HSERDY interrupt is generated and in
the RCC ISR routine the system clock is reconfigured to its previous state (before
HSE clock failure). You can monitor the HSE clock on the MCO pin (PA.08).

Four led connected to pins PC.06, PC.07, PC.08 and PC.09 are toggled with a
frequency depending on the system clock.


Directory contents
==================
stm32f10x_conf.h  Library Configuration file
stm32f10x_it.c    Interrupt handlers
stm32f10x_it.h    Header for stm32f10x_it.c
main.c            Main program


Hardware environment
====================
 - Connect four led to pins PC.06, PC.07, PC.08 and PC.09(respectively LD1, LD2, LD3  
   and LD4 on STM3210B-EVAL board).
 - Connect the MCO pin (PA.08) to an oscilloscope (TP8 on STM3210B-EVAL board) 
 - On STM3210B-EVAL board the 8MHz external Quartz is mounted on socket so it is
   easy to disconnect it.
    
How to use it
=============
In order to make the program work, you must do the following :
- Create a project and setup all your toolchain's start-up files
- Compile the directory content files and required Library files :
  + stm32f10x_lib.c
  + stm32f10x_gpio.c
  + stm32f10x_rcc.c
  + stm32f10x_nvic.c
  + stm32f10x_flash.c
  
- Link all compiled files and load your image into either RAM or FLASH
- Run the example
   
******************* (C) COPYRIGHT 2007 STMicroelectronics *****END OF FILE******
