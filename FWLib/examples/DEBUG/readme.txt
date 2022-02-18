/******************** (C) COPYRIGHT 2007 STMicroelectronics ********************
* File Name          : readme.txt
* Author             : MCD Application Team
* Version            : V1.0
* Date               : 10/08/2007
* Description        : Description of the DEBUG Example.
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
This example demonstrates the STM32F10x Firmware Library DEBUG mode.  

To enter Debug mode you have to define the label DEBUG in the stm32f10x_conf.h file.
This creates a pointer to the peripheral structure in SRAM. Debugging consequently
becomes easier and all register settings can be obtained by dumping a peripheral variable.
When the Debug mode is selected, the assert_param macro is expanded and run-time checking 
is enabled in the firmware library code. The run-time checking allows checking that
all the library functions input value lies within the parameter allowed values.

The associated program simulates wrong parameter passed to library function and the
source of the error is printed on Hyperterminal (through USART1).


Note:
The Debug mode increases the code size and reduces the code performance. For this
reason, it is recommended to used it only when debugging the application and to
remove it from the final application code.


Directory contents
==================
stm32f10x_conf.h  Library Configuration file
stm32f10x_it.c    Interrupt handlers
stm32f10x_it.h    Header for stm32f10x_it.c
main.c            Main program


Hardware environment
====================
 - The USART1 signals (Rx, Tx) must be connected to a DB9 connector using a RS232
   transceiver.
 - Connect a null-modem female/female RS232 cable between the DB9 connector 
   (CN6 on STM3210B-EVAL board) and PC serial port.   
 - Hyperterminal configuration:
    - Word Length = 8 Bits
    - One Stop Bit
    - No parity
    - BaudRate = 115200 baud
    - flow control: None

      
How to use it
=============
In order to make the program work, you must do the following:
- Create a project and setup all your toolchain's start-up files
- Compile the directory content files and required Library files:
  + stm32f10x_lib.c
  + stm32f10x_gpio.c
  + stm32f10x_rcc.c
  + stm32f10x_nvic.c
  + stm32f10x_flash.c
  + stm32f10x_usart.c
      
- Link all compiled files and load your image into either RAM or Flash
- Run the example


******************* (C) COPYRIGHT 2007 STMicroelectronics *****END OF FILE******
