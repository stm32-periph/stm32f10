/******************** (C) COPYRIGHT 2007 STMicroelectronics ********************
* File Name          : readme.txt
* Author             : MCD Application Team
* Version            : V1.0
* Date               : 10/08/2007
* Description        : Description of the PWR Example2.
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
This example shows how to enters the system to STANDBY mode and wake-up from this
mode using: external RESET, RTC Alarm or WKUP pin.

In the associated software, the system clock is set to 72 MHz, the EXTI line9(PB.09)
is configured to generate an interrupt on falling edge and the SysTick is programmed
to generate an interrupt each 250 ms. In the SysTick interrupt handler, a led 
connected to PC.06 pin is toggled, this is used to indicate whether the MCU is 
in STANDBY or RUN mode.
When a falling edge is detected on EXTI line9 an interrupt is generated. In the 
EXTI handler routine the RTC is configured to generate an Alarm event in 3 second
then the system enters STANDBY mode causing the PC.06 pin to stop toggling. 
A rising edge on WKUP pin or an external RESET will wake-up the system from
STANDBY. If within 3 second neither rising edge on WKUP pin nor external RESET
are generated, the RTC Alarm will wake-up the system. 
After wake-up from STANDBY mode, program execution restarts in the same way as after
a RESET, the PC.06 pin restarts toggling, PC.07 pin is set to high level and the RTC
configuration (clock source, enable, prescaler,...) is kept. As result there is no
need to configure the RTC.

Two leds connected to PC.06(LD1) and PC.07(LD2) pins are used to monitor the system
state as following:
 - LD1 toggling: system in RUN mode
 - LD1 off / LD2 off: system in STANDBY mode
 - LD2 on: system resumed from STANDBY mode

 
Directory contents
==================
stm32f10x_conf.h  Library Configuration file
stm32f10x_it.c    Interrupt handlers
stm32f10x_it.h    Header for stm32f10x_it.c
main.c            Main program


Hardware environment
====================
 - Connect two leds to pins PC.06 and PC.07 (respectively LD1 and LD2 on STM3210B-EVAL board).
 - Connect a push-button to pin PB.09 (Key push-button on STM3210B-EVAL board).
 - Connect a push-button to WKUP(PA.00) pin  (Wakep push-button on STM3210B-EVAL board).
    
How to use it
=============
In order to make the program work, you must do the following :
- Create a project and setup all your toolchain's start-up files
- Compile the directory content files and required Library files:
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
