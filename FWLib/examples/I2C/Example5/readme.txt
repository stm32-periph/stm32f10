/******************** (C) COPYRIGHT 2007 STMicroelectronics ********************
* File Name          : readme.txt
* Author             : MCD Application Team
* Version            : V1.0
* Date               : 10/08/2007
* Description        : Description of the I2C Example5.
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
This example provides a basic example of how to use the I2C software library
and an associate I2C EEPROM driver to communicate with an M24C08 EEPROM.

I2C1 is configured in Master transmitter during write operation and in Master 
receiver during read operation from I2C EEPROM.  The Own I2C address is defined
to 0xA0 in the I2c_ee.c file.
The speed is set to the maximum frequency of 400kHz. This value is defined in 
the I2c_ee.c file, which could be in the range of 0 to 400KHZ.
One I2C EEPROM Block address where the program will write the buffer have to be
selected from the four address available and defined in the I2c_ee.c file. 
The EEPROM address where the program start the write and the read operations is
defined in the main.c file. 


First, the contents of Tx1_Buffer are written to the EEPROM_WriteAddress1 and the
written data are read. The written and the read buffer data are then compared.
After a time, the EEPROM reverts to its Standby state. Then, a second write
operation is performed and this time, Tx2_Buffer is written to EEPROM_WriteAddress2,
that is the address that comes just after the last written address. After completion
of the operation, the written data are read. The contents of the written and the read
buffers are compared. Once this is done, the two written buffers are read starting
from EEPROM_WriteAddress1, and stored into a unique buffer. The contents of the
unique buffer are then read and compared to the data in Tx1_Buffer and Tx2_Buffer.


Directory contents
==================
stm32f10x_conf.h  Library Configuration file
stm32f10x_it.c    Interrupt handlers
stm32f10x_it.h    Interrupt handlers header file
main.c            Main program
i2c_ee.c          I2C EEPROM driver
i2c_ee.h          Header for the i2c_ee.c file


Hardware environment
====================
 - Connect I2C1 SCL pin (PB.06) to I2C EEPROM SCL (pin6)
 - Connect I2C1 SDA pin (PB.07) to I2C EEPROM SDA (pin5)
 - Check that a pull-up resistor is connected on one I2C SDA pin
 - Check that a pull-up resistor is connected on one I2C SCL pin
 - Connect I2C EEPROM Vcc (pin8) to Vdd
 - Connect I2C EEPROM Vss (pin4) to Vss


How to use it
=============
In order to make the program work, you must do the following :
- Create a project and setup all your toolchain's start-up files
- Compile the directory content files and required Library files :
  + stm32f10x_lib.c
  + stm32f10x_i2c.c
  + stm32f10x_rcc.c
  + stm32f10x_nvic.c
  + stm32f10x_gpio.c
  + stm32f10x_flash.c
    
- Link all compiled files and load your image in FLASH
- Run the example


******************* (C) COPYRIGHT 2007 STMicroelectronics *****END OF FILE******
