/******************** (C) COPYRIGHT 2007 STMicroelectronics ********************
* File Name          : readme.txt
* Author             : MCD Application Team
* Version            : V1.0
* Date               : 10/08/2007
* Description        : Description of the GPIO Example2.
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
This example provides a short description of how to use the JTAG IOs as standard 
GPIOs and gives a configuration sequence. 

First, the SWJ-DP is disabled. The SWJ-DP pins are configured as output push-pull.
Five LEDs connected to the PA.13(JTMS/SWDAT), PA.14(JTCK/SWCLK), PA.15(JTDI), 
PB.03(JTDO) and PB.04(JTRST) pins are toggled in an infinite loop.

Note that once the JTAG IOs are disabled, the connection with the host debugger is
lost and cannot be re-established as long as the JTAG IOs remain disabled. 
To avoid this situation, the PB09 pin is connected to a push-button that is used to
disable or not the JTAG IOs:
 1. push-button pressed at reset: JTAG IOs disabled
 2. push-button not pressed at reset: JTAG IOs unchanged


Directory contents
==================
stm32f10x_conf.h  Library Configuration file
stm32f10x_it.c    Interrupt handlers
stm32f10x_it.h    Header for stm32f10x_it.c
main.c            Main program


Hardware environment
====================
 - Connect five leds to pins PA.13, PA.14, PA.15, PB.03 and PB.04. 
 - Connect a push button to pin PB.09 (Key push button on STM3210B-EVAL board).

      
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
    
- Link all compiled files and load your image into either RAM or Flash
- Run the example


******************* (C) COPYRIGHT 2007 STMicroelectronics *****END OF FILE******
