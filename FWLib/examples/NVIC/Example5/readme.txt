/******************** (C) COPYRIGHT 2007 STMicroelectronics ********************
* File Name          : readme.txt
* Author             : MCD Application Team
* Version            : V1.0
* Date               : 10/08/2007
* Description        : Description of the NVIC Example5.
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
This example shows how to enters the system to WFI mode with DMA transfer enabled
and wake-up from this mode by the DMA End of Transfer interrupt.

In the associated software, the system clock is set to 72 MHz, the DMA Channel5
is configured to transfer 10 data from the USART1 data register to a predefined 
buffer, DST_Buffer, and to generate an interrupt at the end of the transfer.
The USART1 receives data from Hyperterminal.
A led connected to PC.06 pin is toggled with a frequency depending on the system
clock, this is used to indicate whether the MCU is in WFI or RUN mode. 

A falling edge on EXTI Line 9 will put the core in the WFI mode, causing the PC.06
pin to stop toggling.
To wake-up from WFI mode you have to send the sequence (0, 1, 2, 3, 4, 5, 6, 7, 8, 9)
from the Hyperterminal to the USART1. These bytes will be transferred by the DMA from
the USART1 receive data register to the predefined buffer, then generates an interrupt
which exits the system from WFI mode. 
The Led connected to PC.06 pin restarts toggling and a LED connected to PC.07 will
toggle if the buffer is correctly received else a LED connected to PC.08 is toggled.


Directory contents
==================
stm32f10x_conf.h  Library Configuration file
stm32f10x_it.c    Interrupt handlers
stm32f10x_it.h    Interrupt handlers header file
main.c            Main program


Hardware environment
====================
 - Connect t leds to pins PC6, PC7 and PC8(respectively LD1, LD2 and LD3 on
   STM3210B-EVAL board).
 - The USART1 signals (Rx, Tx) must be connected to a DB9 connector using a RS232
   transceiver.
 - Connect a null-modem female/female RS232 cable between the DB9 connector 
   (CN6 on STM3210B-EVAL board) and PC serial port.   
 - Hyperterminal configuration:
    - Word Length = 8 Bits
    - One Stop Bit
    - No parity
    - BaudRate = 9600 baud
    - flow control: None   
 - Connect a push-button to pin PB.09 (EXTI Line9) (Key push-button on STM3210B-EVAL board).
     
How to use it
=============
In order to make the program work, you must do the following :
- Create a project and setup all your toolchain's start-up files
- Compile the directory content files and required Library files :
  + stm32f10x_lib.c
  + stm32f10x_exti.c
  + stm32f10x_gpio.c
  + stm32f10x_rcc.c
  + stm32f10x_nvic.c
  + stm32f10x_flash.c
  + stm32f10x_dma.c
  + stm32f10x_usart.c
    
- Link all compiled files and load your image into either RAM or FLASH
- Run the example


******************* (C) COPYRIGHT 2007 STMicroelectronics *****END OF FILE******
