/******************** (C) COPYRIGHT 2007 STMicroelectronics ********************
* File Name          : readme.txt
* Author             : MCD Application Team
* Version            : V1.0
* Date               : 10/08/2007
* Description        : Description of the BKP Example2.
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
This example shows how to store user data in the Backup data registers.
As the Backup (BKP) domain still powered by VBAT when VDD is switched off, its
contents are not lost if a battery is connected to VBAT pin.

The program behaves as follows:
1. After startup the program checks if the board has been powered up. If yes, 
the values in the BKP data registers are checked:
   – if a battery is connected to the VBAT pin, the values in the BKP data registers
     are retained
   – if no battery is connected to the VBAT pin, the values in the BKP data registers
     are lost
2. After an external reset, the BKP data registers’ contents are not checked.

Four LEDs connected to the PC.06 (LD1), PC.07 (LD2), PC.08 (LD3) and PC.09 (LD4)
pins are used to monitor the system state as follows:
1. LD3 on / LD1 on: a Power On Reset occurred and the values in the BKP data
   registers are correct
2. LD3 on / LD2 on: a Power On Reset occurred and the values in the BKP data
   registers are not correct or they have not yet been programmed (if it is the
   first time the program is executed)
3. LD3 off / LD1 off / LD2 off: no Power On Reset occurred
4. LD4 on: program running


Directory contents
==================
stm32f10x_conf.h  Library Configuration file
stm32f10x_it.c    Interrupt handlers
stm32f10x_it.h    Header for stm32f10x_it.c
main.c            Main program


Hardware environment
====================
 - Connect four leds to pins PC.06, PC.07, PC.08 and PC.09 (respectively LD1, LD2,
   LD3 and LD4 on STM3210B-EVAL board).
 - Connect a 3V battery on Vbat pin (already mounted on STM3210B-EVAL board)

    
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
  
- Link all compiled files and load your image in FLASH
- Run the example in standalone mode (without debugger connection)
- Power on/off the board and check that the BKP contents are not lost
   
******************* (C) COPYRIGHT 2007 STMicroelectronics *****END OF FILE******
