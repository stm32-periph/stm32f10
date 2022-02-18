/******************** (C) COPYRIGHT 2007 STMicroelectronics ********************
* File Name          : main.c
* Author             : MCD Application Team
* Version            : V1.0
* Date               : 10/08/2007
* Description        : Main program body.
********************************************************************************
* THE PRESENT SOFTWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
* WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE TIME.
* AS A RESULT, STMICROELECTRONICS SHALL NOT BE HELD LIABLE FOR ANY DIRECT,
* INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING FROM THE
* CONTENT OF SUCH SOFTWARE AND/OR THE USE MADE BY CUSTOMERS OF THE CODING
* INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
*******************************************************************************/

/* Includes ------------------------------------------------------------------*/
#include "stm32f10x_lib.h"

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
ErrorStatus HSEStartUpStatus;

/* Private function prototypes -----------------------------------------------*/
void RCC_Configuration(void);
void GPIO_Configuration(void);
void NVIC_Configuration(void);
void WriteToBackupReg(u16 FirstBackupData);
u8 CheckBackupReg(u16 FirstBackupData);

/* Private functions ---------------------------------------------------------*/
/*******************************************************************************
* Function Name  : main
* Description    : Main program.
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
int main(void)
{
#ifdef DEBUG
  debug();
#endif

  /* System Clocks Configuration */
  RCC_Configuration();
  
  /* NVIC configuration */
  NVIC_Configuration();

  /* GPIO configuration */
  GPIO_Configuration();
  
  /* Enable PWR and BKP clock */
  RCC_APB1PeriphClockCmd(RCC_APB1Periph_PWR | RCC_APB1Periph_BKP, ENABLE);

  /* Enable write access to Backup domain */
  PWR_BackupAccessCmd(ENABLE);

  /* Clear Tamper pin Event(TE) pending flag */
  BKP_ClearFlag();

  /* Check if the Power On Reset flag is set */
  if(RCC_GetFlagStatus(RCC_FLAG_PORRST) != RESET)
  {
    /* Clear reset flags */
    RCC_ClearFlag();

    /* Turn on led connected to PC.08 */
    GPIO_SetBits(GPIOC, GPIO_Pin_8);
   
    /* Check if Backup data registers are programmed */
    if(CheckBackupReg(0x3210) == 0x00)
    { /* Backup data registers values are correct */

      /* Turn on led connected to PC.06 */
      GPIO_SetBits(GPIOC, GPIO_Pin_6);
    }
    else
    { /* Backup data registers values are not correct or they are not yet
         programmed (when the first time the program is executed) */

      /* Write data to Backup data registers */
      WriteToBackupReg(0x3210);

      /* Turn on led connected to PC.07 */
      GPIO_SetBits(GPIOC, GPIO_Pin_7);
    }
  }

  /* Turn on led connected to PC.09 */
  GPIO_SetBits(GPIOC, GPIO_Pin_9);  
       
  while (1)
  {    
  }
}

/*******************************************************************************
* Function Name  : RCC_Configuration
* Description    : Configures the different system clocks.
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void RCC_Configuration(void)
{
  /* RCC system reset(for debug purpose) */
  RCC_DeInit();

  /* Enable HSE */
  RCC_HSEConfig(RCC_HSE_ON);

  /* Wait till HSE is ready */
  HSEStartUpStatus = RCC_WaitForHSEStartUp();

  if(HSEStartUpStatus == SUCCESS)
  {
    /* Enable Prefetch Buffer */
    FLASH_PrefetchBufferCmd(FLASH_PrefetchBuffer_Enable);

    /* Flash 2 wait state */
    FLASH_SetLatency(FLASH_Latency_2);
 
    /* HCLK = SYSCLK */
    RCC_HCLKConfig(RCC_SYSCLK_Div1); 
  
    /* PCLK2 = HCLK */
    RCC_PCLK2Config(RCC_HCLK_Div1); 

    /* PCLK1 = HCLK/2 */
    RCC_PCLK1Config(RCC_HCLK_Div2);

    /* PLLCLK = 8MHz * 9 = 72 MHz */
    RCC_PLLConfig(RCC_PLLSource_HSE_Div1, RCC_PLLMul_9);

    /* Enable PLL */ 
    RCC_PLLCmd(ENABLE);

    /* Wait till PLL is ready */
    while(RCC_GetFlagStatus(RCC_FLAG_PLLRDY) == RESET)
    {
    }

    /* Select PLL as system clock source */
    RCC_SYSCLKConfig(RCC_SYSCLKSource_PLLCLK);

    /* Wait till PLL is used as system clock source */
    while(RCC_GetSYSCLKSource() != 0x08)
    {
    }
  }

  /* Enable GPIOC clock */
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);  
}

/*******************************************************************************
* Function Name  : GPIO_Configuration
* Description    : Configures the different GPIO ports.
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void GPIO_Configuration(void)
{
  GPIO_InitTypeDef GPIO_InitStructure;

  /* Configure PC.06, PC.07, PC.08 and PC.09 as Output push-pull */
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6 | GPIO_Pin_7 | GPIO_Pin_8 | GPIO_Pin_9;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
  GPIO_Init(GPIOC, &GPIO_InitStructure);
}

/*******************************************************************************
* Function Name  : NVIC_Configuration
* Description    : Configures NVIC and Vector Table base location.
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void NVIC_Configuration(void)
{
  /* Set the Vector Table base location at 0x08000000 */ 
  NVIC_SetVectorTable(NVIC_VectTab_FLASH, 0x0);
}

#ifdef  DEBUG
/*******************************************************************************
* Function Name  : assert_failed
* Description    : Reports the name of the source file and the source line number
*                  where the assert_param error has occurred.
* Input          : - file: pointer to the source file name
*                  - line: assert_param error line source number
* Output         : None
* Return         : None
*******************************************************************************/
void assert_failed(u8* file, u32 line)
{ 
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */

  /* Infinite loop */
  while (1)
  {
  }
}
#endif

/*******************************************************************************
* Function Name  : WriteToBackupReg
* Description    : Writes data Backup DRx registers.
* Input          : FirstBackupData: data to be written to Backup data registers.
* Output         : None
* Return         : None
*******************************************************************************/
void WriteToBackupReg(u16 FirstBackupData)
{
  BKP_WriteBackupRegister(BKP_DR1, FirstBackupData);
  BKP_WriteBackupRegister(BKP_DR2, BKP->DR1 + 0x5A);
  BKP_WriteBackupRegister(BKP_DR3, BKP->DR2 + 0x3C);
  BKP_WriteBackupRegister(BKP_DR4, BKP->DR3 + 0xA5);
  BKP_WriteBackupRegister(BKP_DR5, BKP->DR4 + 0x06);
  BKP_WriteBackupRegister(BKP_DR6, BKP->DR5 + 0x78);
  BKP_WriteBackupRegister(BKP_DR7, BKP->DR6 + 0xFF);
  BKP_WriteBackupRegister(BKP_DR8, BKP->DR7 + 0xB4);
  BKP_WriteBackupRegister(BKP_DR9, BKP->DR8 + 0x1E);
  BKP_WriteBackupRegister(BKP_DR10, BKP->DR9 + 0xD4);
}

/*******************************************************************************
* Function Name  : CheckBackupReg
* Description    : Checks if the Backup DRx registers values are correct or not.
* Input          : FirstBackupData: data to be compared with Backup data registers.
* Output         : None
* Return         : - 0: All Backup DRx registers values are correct
*                  - Value different from 0: Number of the first Backup register
*                    which value is not correct
*******************************************************************************/
u8 CheckBackupReg(u16 FirstBackupData)
{
  if(BKP_ReadBackupRegister(BKP_DR1) != FirstBackupData) return 1;
  if(BKP_ReadBackupRegister(BKP_DR2) != (BKP->DR1 + 0x5A)) return 2;
  if(BKP_ReadBackupRegister(BKP_DR3) != (BKP->DR2 + 0x3C)) return 3;
  if(BKP_ReadBackupRegister(BKP_DR4) != (BKP->DR3 + 0xA5)) return 4;
  if(BKP_ReadBackupRegister(BKP_DR5) != (BKP->DR4 + 0x06)) return 5;
  if(BKP_ReadBackupRegister(BKP_DR6) != (BKP->DR5 + 0x78)) return 6;
  if(BKP_ReadBackupRegister(BKP_DR7) != (BKP->DR6 + 0xFF)) return 7;
  if(BKP_ReadBackupRegister(BKP_DR8) != (BKP->DR7 + 0xB4)) return 8;
  if(BKP_ReadBackupRegister(BKP_DR9) != (BKP->DR8 + 0x1E)) return 9;
  if(BKP_ReadBackupRegister(BKP_DR10) != (BKP->DR9 + 0xD4)) return 10;

  return 0;
}

/******************* (C) COPYRIGHT 2007 STMicroelectronics *****END OF FILE****/
