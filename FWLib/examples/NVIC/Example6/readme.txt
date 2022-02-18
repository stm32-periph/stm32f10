/******************** (C) COPYRIGHT 2007 STMicroelectronics ********************
* File Name          : readme.txt
* Author             : MCD Application Team
* Version            : V1.0
* Date               : 10/08/2007
* Description        : Description of the NVIC Example6.
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
This example describes how to use the NVIC firmware library to set the CortexM3 
vector table in a specific address other than default.

This can be used to build program which will be loaded into Flash memory by an
application previously programmed from the Flash memory base address. 
Such application can be In-Application Programming (IAP, through USART) or
Device Firmware Upgrade (DFU, through USB).
These applications are available for download from the ST microcontrollers website: www.st.com/stm32

The associated program implements a "Delay" function based on SysTick end of count
interrupt, and toggles four led connected to PC.06, PC.07, PC.08 and PC.09 pins 
with timing defined by the "Delay" function.

When using the IAP to load your porgram, the vector table must be relocated at
address 0x08002000.
When using the DFU to load your porgram, the vector table must be relocated at
address 0x08003000.


Directory contents
==================
stm32f10x_conf.h         Library Configuration file
stm32f10x_it.c           Interrupt handlers
stm32f10x_it.h           Interrupt handlers header file
main.c                   Main program
main.h                   Header for main.c
lnkarm_flash_offset.xcl  XLINK command file template for EWARM
stm32f10x_flash.ld       linker script for RIDE


Hardware environment
====================
 - Connect four led to pins PC6, PC7, PC8 and PC9(respectively LD1, LD2, LD3 and
   LD4 on STM3210B-EVAL board).

    
How to use it
=============
In order to make the program work, you must do the following :
- Create a project and setup all your toolchain's start-up files:
 + RVMDK
	   - in the project option menu, select 'Target' window and enter 0x08002000 
	     as IROM start address
	   - in the project option menu, select 'Linker' window and enter 0x08002000 
	     as R/O base address                    

 + EWARM
    - use "lnkarm_flash_offset.xcl" as linker file

 + RIDE7:
      - in the Application options -> script menu, select:
         * Use Default Script File : No
         * Script File : "stm32f10x_flash.ld"    

- Compile the directory content files and required Library files:
  + stm32f10x_lib.c
  + stm32f10x_systick.c
  + stm32f10x_gpio.c
  + stm32f10x_rcc.c
  + stm32f10x_nvic.c
  + stm32f10x_flash.c

- In the main.c and linker files, the vector table is relocated at address 0x08002000.
  You can modify this address depending on the requirement of your application. 
    
- Rebuild all files 

- Convert the program image to a binary file, *.bin, then you can download and
  run it using the IAP or DFU application.

******************* (C) COPYRIGHT 2007 STMicroelectronics *****END OF FILE******
