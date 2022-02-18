/******************** (C) COPYRIGHT 2007 STMicroelectronics ********************
* File Name          : readme.txt
* Author             : MCD Application Team
* Version            : V1.0
* Date               : 10/08/2007
* Description        : Description of the DMA Example3.
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
This example provides a description of how to use four DMA channels to transfer a 
data buffer from memory to SPI2 through SPI1 and a second data buffer from memory
to SPI1 through SPI2 in ful-duplex mode.

The NSS pins are configured by software to set SPI1 as the master and SPI2, as the slave.
DMA Channel2 and Channel4 are configured to store the data received from SPI1 into the
SPI1 Rx buffer and the data received from SPI2 into the SPI2 Rx buffer. DMA Channel3 is
configured to transfer data from the SPI1 Tx buffer to the SPI1_DR register for transmission
to SPI2. DMA Channel5 is configured to transfer data from the SPI2 Tx buffer to the
SPI2_DR register for transmission to SPI1.

As soon as the two SPI TxDMAEN and RxDMAEN bits are set in the SPI1_CR2 and
SPI2_CR2 registers, DMA Channel3 and Channel5 start transmitting the SPI1 and SPI2 Tx
buffers, respectively, at the same time. At the same moment, the data received on SPI1 and
SPI2 are transferred by DMA Channel2 and Channel4 to the SPI1 and SPI2 Rx buffers,
respectively. Then the system checks that all the data were transmitted and received by the
DMA Channels. The last received data on SPI1 and SPI2 are the CRC values sent by SPI2
and SPI1, respectively. The transmitted buffer and the received buffer are compared to
check that all data have been correctly transferred.


Directory contents
==================
stm32f10x_conf.h  Library Configuration file
stm32f10x_it.c    Interrupt handlers
stm32f10x_it.h    Interrupt handlers header file
main.c            Main program


Hardware environment
====================
 - Connect SPI1 SCK pin (PA.05) to SPI2 SCK pin	(PB.13)
 - Connect SPI1 MISO pin (PA.06) to SPI2 MISO pin (PB.14)
 - Connect SPI1 MOSI pin (PA.07) to SPI2 MOSI pin (PB.15)
      

How to use it
=============
In order to make the program work, you must do the following :
- Create a project and setup all your toolchain's start-up files
- Compile the directory content files and required Library files :
  + stm32f10x_lib.c
  + stm32f10x_dma.c
  + stm32f10x_rcc.c
  + stm32f10x_spi.c
  + stm32f10x_nvic.c
  + stm32f10x_gpio.c
  + stm32f10x_flash.c
    
- Link all compiled files and load your image into either RAM or FLASH
- Run the example


******************* (C) COPYRIGHT 2007 STMicroelectronics *****END OF FILE******
