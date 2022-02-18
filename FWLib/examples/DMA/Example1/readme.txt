/******************** (C) COPYRIGHT 2007 STMicroelectronics ********************
* File Name          : readme.txt
* Author             : MCD Application Team
* Version            : V1.0
* Date               : 10/08/2007
* Description        : Description of the DMA Example1.
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
This example provides a description of how to use a DMA channel to transfer a 
word data buffer from memory (Flash) to memory (RAM).

DMA Channel6 is configured to transfer the contents of a 32-word data buffer stored in
Flash memory to the reception buffer declared in RAM. Trigger is done by software. DMA
Channel6 memory-to-memory transfer is enabled. Source and destination address
incrementing is also enabled. The transfer is started by setting the Channel enable bit for
DMA Channel6. At the end of the transfer a Transfer Complete interrupt is generated if
enabled. In the routine, the remaining data to be transferred is read, it must be equal to 0.
The Transfer Complete Interrupt pending bit is then cleared. A comparison between the
source buffer and the destination buffer is done to check that all data have been correctly
transferred.


Directory contents
==================
stm32f10x_conf.h  Library Configuration file
stm32f10x_it.c    Interrupt handlers
stm32f10x_it.h    Interrupt handlers header file
main.c            Main program


Hardware environment
====================
No hardware connection needed.

      
How to use it
=============
In order to make the program work, you must do the following :
- Create a project and setup all your toolchain's start-up files
- Compile the directory content files and required Library files :
  + stm32f10x_lib.c
  + stm32f10x_dma.c
  + stm32f10x_rcc.c
  + stm32f10x_nvic.c
  + stm32f10x_flash.c  

- Link all compiled files and load your image into either RAM or FLASH
- Run the example


******************* (C) COPYRIGHT 2007 STMicroelectronics *****END OF FILE******
