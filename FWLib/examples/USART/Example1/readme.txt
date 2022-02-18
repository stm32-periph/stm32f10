/******************** (C) COPYRIGHT 2007 STMicroelectronics ********************
* File Name          : readme.txt
* Author             : MCD Application Team
* Version            : V1.0
* Date               : 10/08/2007
* Description        : Description of the USART Example1.
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
This example provides a description of how  to use the USART with hardware flow
control and communicate with the Hyperterminal.
First, the USART2 sends the TxBuffer to the hyperterminal and still waiting for
a string from the hyperterminal that you must enter which must end by '\r'
character (keypad ENTER button). Each byte received is retransmitted to the
Hyperterminal. 
The string that you have entered is stored in the RxBuffer array. The receive
buffer have a RxBufferSize bytes as maximum.

The USART2 is configured as follow:
    - BaudRate = 115200 baud  
    - Word Length = 8 Bits
    - One Stop Bit
    - No parity
    - Hardware flow control enabled (RTS and CTS signals)
    - Receive and transmit enabled


Directory contents
==================
stm32f10x_conf.h  Library Configuration file
stm32f10x_it.h    Interrupt handlers header file
stm32f10x_it.c    Interrupt handlers source file
main.c            Main program


Hardware environment
====================
 - All the USART2 signals (Rx, Tx, RTS and CTS) must be connected to a DB9 
   connector using a RS232 transceiver.

 - Connect a null-modem female/female RS232 cable between the DB9 connector 
   (CN5 on STM3210B-EVAL board) and PC serial port.  

 - Hyperterminal configuration:
    - Word Length = 8 Bits
    - One Stop Bit
    - No parity
    - BaudRate = 115200 baud
    - flow control: Hardware 
  
  
How to use it
=============
In order to make the program work, you must do the following :
- Create a project and setup all your toolchain's start-up files
- Compile the directory content files and required Library files :
  + stm32f10x_lib.c
  + stm32f10x_usart.c
  + stm32f10x_gpio.c
  + stm32f10x_nvic.c
  + stm32f10x_rcc.c
  + stm32f10x_flash.c
    
- Link all compiled files and load your image into either RAM or Flash
- Run the example

******************* (C) COPYRIGHT 2007 STMicroelectronics *****END OF FILE******
