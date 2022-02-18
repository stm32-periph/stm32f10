/******************** (C) COPYRIGHT 2007 STMicroelectronics ********************
* File Name          : readme.txt
* Author             : MCD Application Team
* Version            : V1.0
* Date               : 10/08/2007
* Description        : Description of the BKP Example1.
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
This example shows how to write/read data to/from Backup data registers and 
demonstrates the Tamper detection feature.

The associated firmware performs the following:
1. It configures the ANTI_TAMP pin to be active low, and enables the Tamper interrupt.
2. It writes the data to all Backup data registers, then check whether the data were
correctly written. If yes, the LED connected to PC.06 turns on, otherwise the LED
connected to PC.07 turns on.
3. On applying a low level on the ANTI_TAMP pin (PC.13), the Backup data registers
are reset and the Tamper interrupt is generated. The corresponding ISR then checks
whether the Backup data registers are cleared. If yes, the LED connected to PC.08
turns on, otherwise the LED connected to PC.09 is turns on.


Directory contents
==================
stm32f10x_conf.h  Library Configuration file
stm32f10x_it.c    Interrupt handlers
stm32f10x_it.h    Header for stm32f10x_it.c
main.c            Main program
main.h            Header for main.c


Hardware environment
====================
 - Connect four leds to pins PC.06, PC.07, PC.08 and PC.09 (respectively LD1, LD2,
   LD3 and LD4 on STM3210B-EVAL board).
 - Connect a push-button to pin PC.13 (ANTI_TAMP) (Tamper push-button on
   STM3210B-EVAL board).

    
How to use it
=============
In order to make the program work, you must do the following :
- Create a project and setup all your toolchain's start-up files
- Compile the directory content files and required Library files :
  + stm32f10x_lib.c
  + stm32f10x_pwr.c
  + stm32f10x_bkp.c
  + stm32f10x_gpio.c
  + stm32f10x_rcc.c
  + stm32f10x_nvic.c
  + stm32f10x_flash.c
  
- Link all compiled files and load your image into either RAM or FLASH
- Run the example
   
******************* (C) COPYRIGHT 2007 STMicroelectronics *****END OF FILE******
