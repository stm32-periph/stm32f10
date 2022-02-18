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
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/ 
TIM1_TimeBaseInitTypeDef  TIM1_TimeBaseStructure;
TIM1_OCInitTypeDef  TIM1_OCInitStructure;
TIM1_BDTRInitTypeDef TIM1_BDTRInitStructure;
TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;
TIM_OCInitTypeDef TIM_OCInitStructure;
ErrorStatus HSEStartUpStatus;
  
/* Private function prototypes -----------------------------------------------*/
void RCC_Configuration(void);
void GPIO_Configuration(void);
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

  /* TIM1 and Timers(TIM3 and TIM4) synchronisation in parallel mode -----------
     1/TIM1 is configured as Master Timer:
	    - PWM Mode is used
	    - The TIM1 Update event is used as Trigger Output
	   
	 2/TIM3 and TIM4 are slaves for TIM1,
	    - PWM Mode is used
	    - The ITR0(TIM1) is used as input trigger for both slaves
	    - Gated mode is used, so starts and stops of slaves counters
	      are controlled by the Master trigger output signal(update event).

	 TIM1CLK = 72 MHz, Prescaler = 0, TIM1 counter clock = 72 MHz
	 The Master Timer TIM1 is running at:
	 TIM1 frequency = TIM1 counter clock / (TIM1_Period + 1) = 281.250 KHz
	 and the duty cycle is equal to:
	 TIM1_CCR1/(TIM1_ARR + 1) = 50%
	 
	 The TIM3 is running:
	 - At (TIM1 frequency)/((TIM3 period + 1)* (Repetion_Counter+1)) = 18.750 KHz
   and a duty cycle equal to TIM3_CCR1/(TIM3_ARR + 1) = 33.3%
	 The TIM4 is running:
	 - At (TIM1 frequency)/((TIM4 period + 1)* (Repetion_Counter+1)) = 28.125 KHz
   and a duty cycle equal to TIM4_CCR1/(TIM4_ARR + 1) = 50%
  --------------------------------------------------------------------------- */


  /* TIM3 Peripheral Configuration ----------------------------------------*/ 
  /* TIM3 Slave Configuration: PWM1 Mode */
  TIM_TimeBaseStructure.TIM_Period = 2;          
  TIM_TimeBaseStructure.TIM_Prescaler = 0;       
  TIM_TimeBaseStructure.TIM_ClockDivision = 0;    
  TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;

  TIM_TimeBaseInit(TIM3, &TIM_TimeBaseStructure);

  TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;          
  TIM_OCInitStructure.TIM_Channel = TIM_Channel_1;          
  TIM_OCInitStructure.TIM_Pulse = 1;  

  TIM_OCInit(TIM3, &TIM_OCInitStructure);
  
  /* Slave Mode selection: TIM3 */  
  TIM_SelectSlaveMode(TIM3, TIM_SlaveMode_Gated);
  TIM_SelectInputTrigger(TIM3, TIM_TS_ITR0);


  /* TIM4 Peripheral Configuration ----------------------------------------*/
  /* TIM4 Slave Configuration: PWM1 Mode */
  TIM_TimeBaseStructure.TIM_Period = 1;          
  TIM_TimeBaseStructure.TIM_Prescaler = 0;       
  TIM_TimeBaseStructure.TIM_ClockDivision = 0;    
  TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;

  TIM_TimeBaseInit(TIM4, &TIM_TimeBaseStructure);

  TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;          
  TIM_OCInitStructure.TIM_Channel = TIM_Channel_1;          
  TIM_OCInitStructure.TIM_Pulse = 1; 
  
  TIM_OCInit(TIM4, &TIM_OCInitStructure);
  
  /* Slave Mode selection: TIM4 */ 
  TIM_SelectSlaveMode(TIM4, TIM_SlaveMode_Gated);
  TIM_SelectInputTrigger(TIM4, TIM_TS_ITR0);

  /* TIM1 Peripheral Configuration ----------------------------------------*/ 
  /* Time Base configuration */
  TIM1_TimeBaseStructure.TIM1_Prescaler = 0;
  TIM1_TimeBaseStructure.TIM1_CounterMode = TIM1_CounterMode_Up;
  TIM1_TimeBaseStructure.TIM1_Period = 255;
  TIM1_TimeBaseStructure.TIM1_ClockDivision = 0;
  TIM1_TimeBaseStructure.TIM1_RepetitionCounter = 4;

  TIM1_TimeBaseInit(&TIM1_TimeBaseStructure);

  /* Channel 1 Configuration in PWM mode */
  TIM1_OCInitStructure.TIM1_OCMode = TIM1_OCMode_PWM2; 
  TIM1_OCInitStructure.TIM1_OutputState = TIM1_OutputState_Enable; 
  TIM1_OCInitStructure.TIM1_OutputNState = TIM1_OutputNState_Enable;                  
  TIM1_OCInitStructure.TIM1_Pulse = 127; 
  TIM1_OCInitStructure.TIM1_OCPolarity = TIM1_OCPolarity_Low; 
  TIM1_OCInitStructure.TIM1_OCNPolarity = TIM1_OCNPolarity_Low;         
  TIM1_OCInitStructure.TIM1_OCIdleState = TIM1_OCIdleState_Set;
  TIM1_OCInitStructure.TIM1_OCNIdleState = TIM1_OCIdleState_Reset;          
  
  TIM1_OC1Init(&TIM1_OCInitStructure); 

  /* Automatic Output enable, Break, dead time and lock configuration*/
  TIM1_BDTRInitStructure.TIM1_OSSRState = TIM1_OSSRState_Enable;
  TIM1_BDTRInitStructure.TIM1_OSSIState = TIM1_OSSIState_Enable;
  TIM1_BDTRInitStructure.TIM1_LOCKLevel = TIM1_LOCKLevel_1; 
  TIM1_BDTRInitStructure.TIM1_DeadTime = 5;
  TIM1_BDTRInitStructure.TIM1_Break = TIM1_Break_Disable;
  TIM1_BDTRInitStructure.TIM1_BreakPolarity = TIM1_BreakPolarity_High;
  TIM1_BDTRInitStructure.TIM1_AutomaticOutput = TIM1_AutomaticOutput_Disable;

  TIM1_BDTRConfig(&TIM1_BDTRInitStructure);

  /* Master Mode selection */
  TIM1_SelectOutputTrigger(TIM1_TRGOSource_Update);

  /* TIM1 counter enable */
  TIM1_Cmd(ENABLE);

  /* TIM enable counter */
  TIM_Cmd(TIM3, ENABLE); 
  TIM_Cmd(TIM4, ENABLE);

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

  /* TIM3 and TIM4 clock enable */
  RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3 | RCC_APB1Periph_TIM4, ENABLE);
}

/*******************************************************************************
* Function Name  : GPIO_Configuration
* Description    : Configures TIM1, TIM3 and TIM4 Pins.
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void GPIO_Configuration(void)
{
  GPIO_InitTypeDef GPIO_InitStructure;

 /* GPIOA Configuration: TIM1 Channel1 and TIM3 Channel1 Output */
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6 | GPIO_Pin_8;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOA, &GPIO_InitStructure);

  /* GPIOB Configuration: TIM4 Channel1 Output  */
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6;
  GPIO_Init(GPIOB, &GPIO_InitStructure); 
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
