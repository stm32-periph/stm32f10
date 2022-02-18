/******************** (C) COPYRIGHT 2007 STMicroelectronics ********************
* File Name          : readme.txt
* Author             : MCD Application Team
* Version            : V1.0
* Date               : 10/08/2007
* Description        : Description of the PWR Example1.
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
This example shows how to enter the system to STOP mode and wake-up using EXTI
Line interrupts. The EXTI Line sources are PB.09 and RTC Alarm.

The EXTI line9(PB.09) is configured to generate interrupt on falling edge.
The EXTI line17(RTC Alarm) is configured to generate interrupt on rising edge and
the RTC time base is set to 1 second using the external low speed oscillator(LSE).

The system clock is set to 72 MHz using the external high speed oscillator(HSE).

The system enters and exits STOP mode as following:
After 2 second from system start-up, the RTC is configured to generate an Alarm
event in 3 second then the system enters STOP mode. To wake-up from STOP mode you
have to apply a rising edge on EXTI line9, otherwise the  RTC Alarm will wake-up
the system within 3 second. After exit from STOP the system clock is reconfigured
to its previous state (as HSE and PLL are disabled in STOP mode).
Then after a delay the system will enter again in STOP mode and exit in the way
described above. This behavior is repeated in an infinite loop.

Four leds connected to PC.06(LD1), PC.07(LD2), PC.08(LD3) and PC.09(LD4) pins are
used to monitor the system state as following:
 - LD1 on / LD4 off: system in RUN mode
 - LD1 off / LD4 on: system in STOP mode
 - LD2 is toggled if EXTI Line9 is used to exit from STOP 
 - LD3 is toggled if EXTI line17(RTC Alarm) is used to exit from STOP 


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
 - Connect a push-button to pin PB.09 (Key push-button on STM3210B-EVAL board).

    
How to use it
=============
In order to make the program work, you must do the following :
- Create a project and setup all your toolchain's start-up files
- Compile the directory content files and required Library files :
  + stm32f10x_nvic.c
  + stm32f10x_rcc.c
  + stm32f10x_lib.c
  + stm32f10x_gpio.c
  + stm32f10x_rtc.c  
  + stm32f10x_pwr.c  
  + stm32f10x_bkp.c
  + stm32f10x_exti.c
  + stm32f10x_flash.c
  + stm32f10x_systick.c             
- Link all compiled files and load your image in Flash
- Run the example in standalone mode (without debugger connection)

******************* (C) COPYRIGHT 2007 STMicroelectronics *****END OF FILE******
