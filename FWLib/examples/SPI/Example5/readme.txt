/******************** (C) COPYRIGHT 2007 STMicroelectronics ********************
* File Name          : readme.txt
* Author             : MCD Application Team
* Version            : V1.0
* Date               : 10/08/2007
* Description        : Description of the SPI Example5.
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
This example provides a basic example of how to use the SPI firmware library
and an associate SPI FLASH driver to communicate with an M25P64 FLASH.
The first step consist on reading the SPI Flash ID. A comparison between the ID 
read from SPI flash and the expected one is done and the pin PC.06 is set in case
of success otherwise pin PC.07 is set.  
Using this driver the program performs an erase of the sector to be accessed, a 
write of a Tx_Buffer, defined in the main.c file, to the memory followed by a read
of the written data. Then data read from the memory stored in the Rx_Buffer are
compared with the expected values of the Tx_Buffer. The result of this comparison
is stored in the "TransferStatus1" variable.
A second sector erase is done at the end, and a check of the Tx_Buffer data write 
location on SPI flash is made to be sure that all the data written there are erased
further to the sector erase. All the data location are read and checked with 0xFF
value whcih indicates its erase. The result of this test is stored in "TransferStatus2"
variable which is FAILED in case of error.
The SPI1 is configured as Master with an 8bits data size. The SPI1_NSS pin is used
as output push-pull to drive the SPI Flash chip select pin.  
The FLASH_WriteAddress and the FLASH_ReadAddress where the program start the write 
and the read operations are defined in the main.c file. 
The system clock is set to 72MHz and SPI1 baudrate to 18 Mbit/s.


Directory contents
==================
stm32f10x_conf.h   Library Configuration file
stm32f10x_it.c     Interrupt handlers
stm32f10x_it.h     Header for stm32f10x_it.c
main.c             Main program
spi_flash.c        SPI FLASH driver
spi_flash.h        Header for the spi_flash.c file


Hardware environment
====================
 - Connect both SPI1 and SPI FLASH pins as following:
    - Connect SPI1_NSS (PA.04) pin to SPI Flash chip select (pin1).
    - Connect SPI1_SCLK (PA.05) pin to SPI Flash serial clock (pin6).
    - Connect SPI1_MISO (PA.06) pin to SPI Flash serial data output (pin2).
    - Connect SPI1_MOSI (PA.07) pin to SPI Flash serial data input (pin5).
    - Connect SPI Flash Write Protect (pin3) to Vdd
    - Connect SPI Flash Hold (pin7) to Vdd
    - Connect SPI Flash Vcc (pin8) to Vdd
    - Connect SPI Flash Vss (pin4) to Vss
Note: This SPI Flash is already available on the STM3210B-EVAL board (and there 
      is no need for extra hardware connection).
 - Connect two leds to pins PC.06 and PC.07 (respectively LD1 and LD2 on
   STM3210B-EVAL board). 


How to use it
=============
In order to make the program work, you must do the following :
- Create a project and setup all your toolchain's start-up files
- Compile the directory content files and required Library files :
  + stm32f10x_lib.c
  + stm32f10x_spi.c
  + stm32f10x_rcc.c
  + stm32f10x_gpio.c
  + stm32f10x_nvic.c
  + stm32f10x_flash.c
    
- Link all compiled files and load your image into either RAM or FLASH
- Run the example


******************* (C) COPYRIGHT 2007 STMicroelectronics *****END OF FILE******
