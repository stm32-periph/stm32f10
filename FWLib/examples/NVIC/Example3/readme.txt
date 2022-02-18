/******************** (C) COPYRIGHT 2007 STMicroelectronics ********************
* File Name          : readme.txt
* Author             : MCD Application Team
* Version            : V1.0
* Date               : 10/08/2007
* Description        : Description of the NVIC Example3.
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
This example demontrates the use of the Nested Vectored Interrupt Controller (NVIC) 
and system handlers: 

- Assignment of a descendant system handlers preemption priority for each system
handler:
   - NMI has -1 as preemption priority
   - PSV has 0 preemption priority
   - SVCall has 1 preemption priority
   - SysTick has 2 preemption priority

- Configuration of SysTick timer to generate an interrupt on each end of count

- In the Systick handler routine: a led connected to PC.06 pin toggle each 1s and
the SVC instruction is executed. This will activate the SVCall handler to preempt 
the current instruction stream. In the SVCall handler routine, a led connected to 
PC.07 pin is toggling and the pending bit of the PSV handler is set by software.
The PSV which has a higher preemption priority will preempt the SVCall handler and 
will toggle a led connected to PC.08 pin. Also, in this handler routine, the NMI 
pending bit is set and the NMI handler is activated and the led connected to PC.09
pin is toggling.



Directory contents
==================
stm32f10x_conf.h  Library Configuration file
stm32f10x_it.c    Interrupt handlers
stm32f10x_it.h    Interrupt handlers header file
main.c            Main program


Hardware environment
====================
 - Connect four leds to pins PC.06, PC.07, PC.08 and PC.09(respectively LD1, LD2, LD3 and LD4
   on STM3210B-EVAL board).

    
How to use it
=============
In order to make the program work, you must do the following :
- Create a project and setup all your toolchain's start-up files
- Compile the directory content files and required Library files :
  + stm32f10x_lib.c
  + stm32f10x_systick.c
  + stm32f10x_gpio.c
  + stm32f10x_rcc.c
  + stm32f10x_nvic.c
  
- Link all compiled files and load your image into either RAM or FLASH
- Run the example


******************* (C) COPYRIGHT 2007 STMicroelectronics *****END OF FILE******
