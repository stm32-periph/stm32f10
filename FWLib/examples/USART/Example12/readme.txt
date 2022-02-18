/******************** (C) COPYRIGHT 2007 STMicroelectronics ********************
* File Name          : readme.txt
* Author             : MCD Application Team
* Version            : V1.0
* Date               : 10/08/2007
* Description        : Description of the USART Example12.
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
This example provides a description of how  to use the USART in Smart Card mode. 
The example gives only the possibility to read the ATR and decode it into 
predefined buffer.
First, the code is waiting for an card insertion. If card detected through an 
EXTI Line interrupt, a reset signal is applied to the card through its reset pin.
As response to this reset, the card transmit the ATR which will be stored in 
predefined buffer. Once the ATR is received, it is decoded and stored in a specific
structure (SC_A2R) and the card protocol type is stored in a variable.

The used smart card is ISO7816-3 T=0 compatible.

USART3 configured as follow:
  - Word Length = 9 Bits
  - 0.5 Stop Bit
  - Even parity
  - BaudRate = 12096 baud
  - Hardware flow control disabled (RTS and CTS signals)
  - Tx and Rx enabled
  - USART Clock enabled
  - USART CPOL: Clock is active low
  - USART CPHA: Data is captured on the second edge 
  - USART LastBit: The clock pulse of the last data bit is not output to 
                   the SCLK pin


Directory contents
==================
stm32f10x_conf.h  Library Configuration file
stm32f10x_it.h    Interrupt handlers header file
stm32f10x_it.c    Interrupt handlers
main.c            Main program


Hardware environment
====================
 - In the STM3210B-EVAL board, plug a smart card (ISO7816-3 T=0 compatible) into  
   the dedicated smart card connector CN16.   

  
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
  + stm32f10x_exti.c
        
- Link all compiled files and load your image into either RAM or Flash
- Run the example

******************* (C) COPYRIGHT 2007 STMicroelectronics *****END OF FILE******
