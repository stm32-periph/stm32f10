/******************** (C) COPYRIGHT 2007 STMicroelectronics ********************
* File Name          : readme.txt
* Author             : MCD Application Team
* Version            : V1.0
* Date               : 10/08/2007
* Description        : Description of the USART Example10 Transmit.
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
This example provides a basic communication USART3 IrDA transmit mode. Five pins,
configured in input floating mode, are used to select the byte to be send at 
each pin state change. 

These bytes are:
  - 0x00 if no key pressed
  - 0x01 if PD.12 pin state change
  - 0x02 if PE.00 pin state change 
  - 0x03 if PE.01 pin state change 
  - 0x04 if PD.08 pin state change 
  - 0x05 if PD.14 pin state change 
  
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
 - Connect a push-button to pin PD.14 (DOWN push-button on STM3210B-EVAL board).
 - Connect a push-button to pin PD.08 (UP push-button on STM3210B-EVAL board).
 - Connect a push-button to pin PD.12 (SEL push-button on STM3210B-EVAL board).
 - Connect a push-button to pin PE.00 (RIGHT push-button on STM3210B-EVAL board).
 - Connect a push-button to pin PE.01 (LEFT push-button on STM3210B-EVAL board).
 - Use an IrDA tranceiver connected to the USART3 Tx pin (U11 on STM3210B-EVAL 
   board, JP1 jumper must is fitted).
  
  
How to use it
=============
In order to make the program work, you must do the following:
- Create a project and setup all your toolchain's start-up files
- Compile the directory content files and required Library files:
  + stm32f10x_lib.c
  + stm32f10x_gpio.c
  + stm32f10x_rcc.c
  + stm32f10x_usart.c
  + stm32f10x_nvic.c
  + stm32f10x_flash.c
      
- Link all compiled files and load your image into either RAM or Flash
- Run the example

******************* (C) COPYRIGHT 2007 STMicroelectronics *****END OF FILE******
