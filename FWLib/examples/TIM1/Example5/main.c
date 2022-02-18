/******************** (C) COPYRIGHT 2007 STMicroelectronics ********************
* File Name          : main.c
* Author             : MCD Application Team
* Version            : V1.0
* Date               : 10/08/2007
* Description        : Main program body
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
#define TIM1_CCR3Adress 0x40012C3C

/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/ 
TIM1_TimeBaseInitTypeDef  TIM1_TimeBaseStructure;
TIM1_OCInitTypeDef  TIM1_OCInitStructure;
u16 SRC_Buffer[3] = {3071, 1791, 511}; 
ErrorStatus HSEStartUpStatus;
 
/* Private function prototypes -----------------------------------------------*/
void RCC_Configuration(void);
void GPIO_Configuration(void);
void DMA_Configuration(void);  
void NVIC_Configuration(void);
  
/* Private functions ---------------------------------------------------------*/
/*******************************************************************************
* Function Name  : main
* Description    : Main program
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

  /* GPIO Configuration */
  GPIO_Configuration();

  /* DMA Configuration */
  DMA_Configuration();

  /* TIM1 DMA Transfer example -------------------------------------------------
    TIM1CLK = 72 MHz, Prescaler = 0, TIM1 counter clock = 72 MHz 
	The TIM1 Channel3 is configured to generate a complementary PWM signal with 
	a frequency equal to: TIM1 counter clock / (TIM1_Period + 1) = 17.57 KHz and 
	a variable duty cycle that is changed by the DMA after a specific number of
    Update DMA request.
	The number of this repetitive requests is defined by the TIM1 Repetion counter,
	each 3 Update Requests, the TIM1 Channel 3 Duty Cycle changes to the next new 
	value defined by the SRC_Buffer .    
  ----------------------------------------------------------------------------- */

  /* TIM1 Peripheral Configuration ----------------------------------------*/ 
  /* Time Base configuration */
  TIM1_TimeBaseStructure.TIM1_Prescaler = 0;
  TIM1_TimeBaseStructure.TIM1_CounterMode = TIM1_CounterMode_Up;
  TIM1_TimeBaseStructure.TIM1_Period = 4095;
  TIM1_TimeBaseStructure.TIM1_ClockDivision = 0;
  TIM1_TimeBaseStructure.TIM1_RepetitionCounter = 2;

  TIM1_TimeBaseInit(&TIM1_TimeBaseStructure);

  /* Channel 3 Configuration in PWM mode */
  TIM1_OCInitStructure.TIM1_OCMode = TIM1_OCMode_PWM2; 
  TIM1_OCInitStructure.TIM1_OutputState = TIM1_OutputState_Enable; 
  TIM1_OCInitStructure.TIM1_OutputNState = TIM1_OutputNState_Enable;                  
  TIM1_OCInitStructure.TIM1_Pulse = 127; 
  TIM1_OCInitStructure.TIM1_OCPolarity = TIM1_OCPolarity_Low; 
  TIM1_OCInitStructure.TIM1_OCNPolarity = TIM1_OCNPolarity_Low;         
  TIM1_OCInitStructure.TIM1_OCIdleState = TIM1_OCIdleState_Set;
  TIM1_OCInitStructure.TIM1_OCNIdleState = TIM1_OCIdleState_Reset;          
  
  TIM1_OC3Init(&TIM1_OCInitStructure); 

  /* TIM1 Update DMA Request enable */
  TIM1_DMACmd(TIM1_DMA_Update, ENABLE);

  /* TIM1 counter enable */
  TIM1_Cmd(ENABLE);

  /* Main Output Enable */
  TIM1_CtrlPWMOutputs(ENABLE);
  
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

    /* PCLK1 = HCLK/4 */
    RCC_PCLK1Config(RCC_HCLK_Div4);

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

  /* TIM1, GPIOA and GPIOB clock enable */
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM1 | RCC_APB2Periph_GPIOA |
                         RCC_APB2Periph_GPIOB, ENABLE);
  /* DMA clock enable */
  RCC_AHBPeriphClockCmd(RCC_AHBPeriph_DMA, ENABLE);
}

/*******************************************************************************
* Function Name  : GPIO_Configuration
* Description    : Configure the TIM1 Pins.
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void GPIO_Configuration(void)
{
  GPIO_InitTypeDef GPIO_InitStructure;

 /* GPIOA Configuration: Channel 3 Output */
  GPIO_InitStructure.GPIO_Pin =  GPIO_Pin_10;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOA, &GPIO_InitStructure);

  /* GPIOB Configuration: Channel 3N Output */
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_15;
  GPIO_Init(GPIOB, &GPIO_InitStructure); 
}

/*******************************************************************************
* Function Name  : DMA_Configuration
* Description    : Configures the DMA.
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void DMA_Configuration(void)
{
  DMA_InitTypeDef DMA_InitStructure;

  /* DMA Channel5 Config */
  DMA_DeInit(DMA_Channel5);

  DMA_InitStructure.DMA_PeripheralBaseAddr = (u32)TIM1_CCR3Adress;
  DMA_InitStructure.DMA_MemoryBaseAddr = (u32)SRC_Buffer; 
  DMA_InitStructure.DMA_DIR = DMA_DIR_PeripheralDST;
  DMA_InitStructure.DMA_BufferSize = 3;
  DMA_InitStructure.DMA_PeripheralInc = DMA_PeripheralInc_Disable;
  DMA_InitStructure.DMA_MemoryInc = DMA_MemoryInc_Enable;
  DMA_InitStructure.DMA_PeripheralDataSize = DMA_PeripheralDataSize_HalfWord;
  DMA_InitStructure.DMA_MemoryDataSize = DMA_MemoryDataSize_HalfWord;
  DMA_InitStructure.DMA_Mode = DMA_Mode_Circular;
  DMA_InitStructure.DMA_Priority = DMA_Priority_High;
  DMA_InitStructure.DMA_M2M = DMA_M2M_Disable;

  DMA_Init(DMA_Channel5, &DMA_InitStructure);

  /* DMA Channel5 enable */
  DMA_Cmd(DMA_Channel5, ENABLE);
}

/*******************************************************************************
* Function Name  : NVIC_Configuration
* Description    : Configures Vector Table base location.
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void NVIC_Configuration(void)
{
#ifdef  VECT_TAB_RAM  
  /* Set the Vector Table base location at 0x20000000 */ 
  NVIC_SetVectorTable(NVIC_VectTab_RAM, 0x0); 
#else  /* VECT_TAB_FLASH  */
  /* Set the Vector Table base location at 0x08000000 */ 
  NVIC_SetVectorTable(NVIC_VectTab_FLASH, 0x0);   
#endif
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

  while (1)
  {
  }	
}
#endif

/******************* (C) COPYRIGHT 2007 STMicroelectronics *****END OF FILE****/
