/******************** (C) COPYRIGHT 2007 STMicroelectronics ********************
* File Name          : readme.txt
* Author             : MCD Application Team
* Version            : V1.0
* Date               : 10/08/2007
* Description        : Description of the FLASH Example2.
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
This example provides a description of how to enable and disable the write protection
for the STM32F10x FLASH:

- Enable Write protection:
(Uncomment the line "#define WriteProtection_Enable" to Enable the Write Protection.)
To protect a set of pages, the user has to call the function FLASH_EnableWriteProtection.
The parameter of this function will define the number of pages to be protected, in our case 
we choose to protect 8 pages: from 24 to 31, so the parameter is 
"FLASH_WRProt_Pages24to27 | FLASH_WRProt_Pages28to31".
To load the new option byte values, a system Reset is necessary, for this, the function 
NVIC_GenerateSystemReset() is used.
 
- Disable Write protection:
(Uncomment the line "#define WriteProtection_Disable" to Disable the Write Protection) 
To disable the write protection of the STM32F10x Flash, an erase of the small information block
is necessary. This operation is supported by the function FLASH_EraseOptionBytes.
To load the new option byte values, a system Reset is necessary, for this, the function 
NVIC_GenerateSystemReset() is used.


If the desired pages are not write protected, an erase and a write operation are performed.


Directory contents
==================
stm32F10x_conf.h  Library Configuration file
stm32F10x_it.c    Interrupt handlers
stm32F10x_it.h    Interrupt handlers header file
main.c            Main program
 
  
How to use it
=============
In order to make the program work, you must do the following:
- Create a project and setup all your toolchain's start-up files
- Compile the directory content files and required Library files:
  + stm32F10x_lib.c
  + stm32F10x_flash.c
  + stm32F10x_rcc.c
  + stm32F10x_nvic.c

- Link all compiled files and load your image into either RAM or Flash
- Run the example


******************* (C) COPYRIGHT 2007 STMicroelectronics *****END OF FILE******
