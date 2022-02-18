/**
  ******************************************************************************
  * @file    FLASH/Program/main.c 
  * @author  MCD Application Team
  * @version V3.2.0
  * @date    03/01/2010
  * @brief   Main program body
  ******************************************************************************
  * @copy
  *
  * THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
  * WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE
  * TIME. AS A RESULT, STMICROELECTRONICS SHALL NOT BE HELD LIABLE FOR ANY
  * DIRECT, INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING
  * FROM THE CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE
  * CODING INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
  *
  * <h2><center>&copy; COPYRIGHT 2010 STMicroelectronics</center></h2>
  */ 

/* Includes ------------------------------------------------------------------*/
#include "stm32f10x.h"


/** @addtogroup STM32F10x_StdPeriph_Examples
  * @{
  */

/** @addtogroup FLASH_Program
  * @{
  */ 

/* Private typedef -----------------------------------------------------------*/
typedef enum {FAILED = 0, PASSED = !FAILED} TestStatus;

/* Private define ------------------------------------------------------------*/
/* Define the STM32F10x FLASH Page Size depending on the used STM32 device */
#ifdef STM32F10X_LD_VL
  #define FLASH_PAGE_SIZE    ((uint16_t)0x400)
#elif defined STM32F10X_LD
  #define FLASH_PAGE_SIZE    ((uint16_t)0x400)
#elif defined STM32F10X_MD_VL
  #define FLASH_PAGE_SIZE    ((uint16_t)0x400)
#elif defined STM32F10X_MD
  #define FLASH_PAGE_SIZE    ((uint16_t)0x400)
#elif defined STM32F10X_HD
  #define FLASH_PAGE_SIZE    ((uint16_t)0x800)
#elif defined STM32F10X_CL
  #define FLASH_PAGE_SIZE    ((uint16_t)0x800)  
#endif /* STM32F10X_LD_VL */

#define StartAddr  ((uint32_t)0x08008000)
#define EndAddr    ((uint32_t)0x0800C000)

/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/  
uint32_t EraseCounter = 0x00, Address = 0x00;
uint32_t Data;
__IO uint32_t NbrOfPage = 0x00;
volatile FLASH_Status FLASHStatus;
volatile TestStatus MemoryProgramStatus;

/* Private function prototypes -----------------------------------------------*/   
/* Private functions ---------------------------------------------------------*/

/**
  * @brief   Main program
  * @param  None
  * @retval None
  */
int main(void)
{
  /*!< At this stage the microcontroller clock setting is already configured, 
       this is done through SystemInit() function which is called from startup
       file (startup_stm32f10x_xx.s) before to branch to application main.
       To reconfigure the default setting of SystemInit() function, refer to
       system_stm32f10x.c file
     */     
       
  FLASHStatus = FLASH_COMPLETE;
  MemoryProgramStatus = PASSED;
  Data = 0x15041979;

  /* Unlock the Flash Program Erase controller */
  FLASH_Unlock();

  /* Define the number of page to be erased */
  NbrOfPage = (EndAddr - StartAddr) / FLASH_PAGE_SIZE;

  /* Clear All pending flags */
  FLASH_ClearFlag(FLASH_FLAG_EOP | FLASH_FLAG_PGERR | FLASH_FLAG_WRPRTERR);	

  /* Erase the FLASH pages */
  for(EraseCounter = 0; (EraseCounter < NbrOfPage) && (FLASHStatus == FLASH_COMPLETE); EraseCounter++)
  {
    FLASHStatus = FLASH_ErasePage(StartAddr + (FLASH_PAGE_SIZE * EraseCounter));
  }
  
  /*  FLASH Word program of data 0x15041979 at addresses defined by StartAddr and EndAddr*/
  Address = StartAddr;

  while((Address < EndAddr) && (FLASHStatus == FLASH_COMPLETE))
  {
    FLASHStatus = FLASH_ProgramWord(Address, Data);
    Address = Address + 4;
  }
  
  /* Check the corectness of written data */
  Address = StartAddr;

  while((Address < EndAddr) && (MemoryProgramStatus != FAILED))
  {
    if((*(__IO uint32_t*) Address) != Data)
    {
      MemoryProgramStatus = FAILED;
    }
    Address += 4;
  }
  
  
  while (1)
  {
  }
}

#ifdef  USE_FULL_ASSERT

/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t* file, uint32_t line)
{ 
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */

  while (1)
  {
  }
}
#endif

/**
  * @}
  */ 

/**
  * @}
  */ 

/******************* (C) COPYRIGHT 2010 STMicroelectronics *****END OF FILE****/
