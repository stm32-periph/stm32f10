/******************** (C) COPYRIGHT 2007 STMicroelectronics ********************
* File Name          : readme.txt
* Author             : MCD Application Team
* Version            : V1.0
* Date               : 10/08/2007
* Description        : Description of the USART Example10 Receive.
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
This example provides a basic communication USART3 IrDA receive mode. Four leds
are used to show which byte is received. 

  - Led connected to PC.06 toggle when 0x04 is received
  - Led connected to PC.07 toggle when 0x05 is received
  - Led connected to PC.08 toggle when 0x03 is received
  - Led connected to PC.09 toggle when 0x02 is received
  - Leds connected to PC.06, PC.07, PC.08 and PC.09 toggle when 0x01 is received        


USART3 configured as follow:
   - BaudRate = 115200 baud  
   - Word Length = 8 Bits
   - One Stop Bit
   - No parity
   - Hardware flow control disabled (RTS and CTS signals)
   - Receive and transmit enabled

The example10 provides two IrDA program: transmitter&receiver and requires two boards
to be able to run the full demonstration:
 - one board will act as IrDA transmitter
 - one board will act as IrDA receiver


Directory contents
==================
stm32f10x_conf.h  Library Configuration file
stm32f10x_it.h    Interrupt handlers header file
stm32f10x_it.c    Interrupt handlers
main.c            Main program


Hardware environment
====================
 - Use an IrDA tranceiver connected to the USART3 Tx pin (U11 on STM3210B-EVAL 
   board, JP1 jumper must is fitted).
 - Connect four led to pin PC.06, PC.07, PC.08 and PC.09 (LD1, LD2, LD3 and  LD4
   on STM3210B-EVAL board).  
  
  
How to use it
=============
In order to make the program work, you must do the following :
- Create a project and setup all your toolchain's start-up files
- Compile the directory content files and required Library files :
  + stm32f10x_lib.c
  + stm32f10x_gpio.c
  + stm32f10x_rcc.c
  + stm32f10x_usart.c
  + stm32f10x_nvic.c
  + stm32f10x_flash.c
  
- Link all compiled files and load your image into either RAM or Flash
- Run the example

******************* (C) COPYRIGHT 2007 STMicroelectronics *****END OF FILE******
