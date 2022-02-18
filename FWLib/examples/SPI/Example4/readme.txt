/******************** (C) COPYRIGHT 2007 STMicroelectronics ********************
* File Name          : readme.txt
* Author             : MCD Application Team
* Version            : V1.0
* Date               : 10/08/2007
* Description        : Description of the SPI Example4.
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
This example provides a description of how to set a communication between the two
SPIs in simplex mode and performs a transfer from Master in polling mode to the
Slave in DMA receive mode. The NSS pin is managed by hardware.
Both SPIs are configured with 8bit data frame and a 18Mbit/s communication speed.
The dedicated DMA channel2 is configured for SPI1 Rx request to store received data
in SPI1_Buffer_Rx. The master SPI2 is configured in bidirectional mode as transmitter
only. The slave SPI1 is also configured in bidirectional but as receiver only. 
Both master and slave NSS pins are managed by hardware. The SS output is enabled 
for SPI2 to set it as a master and SPI1 as a slave.
After transfering the first SPI2 data an SPI1 RxNE request on DMA channel2 is generated
and the received data is stored in SPI1_Buffer_Rx. The same action is done for the rest 
of the buffer.
Once the transfer is completed a comparison is done and TransferStatus gives the
data transfer status for where it is PASSED if transmitted and received data 
are the same otherwise it is FAILED.


Directory contents
==================
stm32f10x_conf.h  Library Configuration file
stm32f10x_it.c    Interrupt handlers
stm32f10x_it.h    Interrupt handlers header file
main.c            Main program


Hardware environment
====================
 - Connect SPI1 NSS pin (PA.04) to SPI2 NSS pin	(PB.12)
 - Connect SPI1 SCK pin (PA.05) to SPI2 SCK pin (PB.13)
 - Connect SPI1 MISO pin (PA.06) to SPI2 MOSI pin (PB.15)


How to use it
=============
In order to make the program work, you must do the following :
- Create a project and setup all your toolchain's start-up files
- Compile the directory content files and required Library files :
  + stm32f10x_lib.c
  + stm32f10x_spi.c
  + stm32f10x_rcc.c
  + stm32f10x_gpio.c
  + stm32f10x_dma.c
  + stm32f10x_nvic.c
  + stm32f10x_flash.c
    
- Link all compiled files and load your image into either RAM or FLASH
- Run the example


******************* (C) COPYRIGHT 2007 STMicroelectronics *****END OF FILE******
