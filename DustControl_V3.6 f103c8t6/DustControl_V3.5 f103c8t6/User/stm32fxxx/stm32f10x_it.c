/**
  ******************************************************************************
  * @file    Project/STM32F10x_StdPeriph_Template/stm32f10x_it.c 
  * @author  MCD Application Team
  * @version V3.5.0
  * @date    08-April-2011
  * @brief   Main Interrupt Service Routines.
  *          This file provides template for all exceptions handler and 
  *          peripherals interrupt service routine.
  ******************************************************************************
  * @attention
  *
  * THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
  * WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE
  * TIME. AS A RESULT, STMICROELECTRONICS SHALL NOT BE HELD LIABLE FOR ANY
  * DIRECT, INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING
  * FROM THE CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE
  * CODING INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
  *
  * <h2><center>&copy; COPYRIGHT 2011 STMicroelectronics</center></h2>
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "bsp.h"
/** @addtogroup STM32F10x_StdPeriph_Template
  * @{
  */

///* Private typedef -----------------------------------------------------------*/
///* Private define ------------------------------------------------------------*/
///* Private macro -------------------------------------------------------------*/
///* Private variables ---------------------------------------------------------*/
extern uint8_t  RxDataBuff[256];  //配置数据接收缓存区
extern uint8_t  RxCmdBuff[128];   //配置命令接收缓存区
extern uint16_t RxDataCount;      //接收数据计数器
extern uint16_t RxCmdCount;       //接收命令计数器
extern uint8_t  RxStateConfig;    //接收完一帧数据
extern uint8_t  CmdFlag;          //0表示命令,1表示数据
u16 Air_STATU = 0;
u16 count=0;
//extern uint8_t RxBuff433m[128]; //433m接收数据缓存区
//extern uint16_t RxBuffCnt433m;  //接收计数器
//extern uint8_t RxState433m;     //接收完一帧数据
///* Private function prototypes -----------------------------------------------*/
///* Private functions ---------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
/******************************************************************************/
/*            Cortex-M3 Processor Exceptions Handlers                         */
/******************************************************************************/

void HardFault_Handler(void)
{
  /* Go to infinite loop when Hard Fault exception occurs */
  while (1)
  {
		printf("HardFault_Handler...\r\n");
  }
}

/**
  * @brief  This function handles SysTick Handler.
  * @param  None
  * @retval None
  */
void SysTick_Handler(void)
{
	CPU_SR_ALLOC();
	CPU_CRITICAL_ENTER();
	OSIntNestingCtr++;                                      /* Tell uC/OS-III that we are starting an ISR             */
	CPU_CRITICAL_EXIT();
	OSTimeTick();                                           /* Call uC/OS-III's OSTimeTick()                          */
	OSIntExit();                                            /* Tell uC/OS-III that we are leaving the ISR             */
}
/**
  * @brief  This function handles USART1 global interrupt request.
  * @param  None
  * @retval None
  */
void USART1_IRQHandler(void)
{
	CPU_SR_ALLOC();
	CPU_CRITICAL_ENTER();
  OSIntEnter();//OSIntNestingCtr++; 
	CPU_CRITICAL_EXIT();
//	BSP_GPRS_USART_IRQHandler();
	NOVA_USART1_IRQHandler();
	OSIntExit();
}
/*-------------------------------------------------*/
/*函数名：定时器1中断服务函数                      */
/*参  数：无                                       */
/*返回值：无                                       */
/*-------------------------------------------------*/
void TIM1_UP_IRQHandler(void)
{

	if(TIM_GetITStatus(TIM1, TIM_IT_Update) != RESET) //检查TIM1更新中断发生与否
	{
		count++;
		CLR_Buf6();

		if(count == 6){

			count = 0;
			mySensorDatas.RELAYS++;
			times.MINUTE++;
		}
		if(times.MINUTE == 60){
			times.MINUTE = 0;
			times.HOUR++;
			
//			RS485_RDEN_PORT->ODR |= RS485_RDEN_PIN;//High Send
//			printf("HOUR：%d\r\n",times.HOUR);
//			RS485_RDEN_PORT->ODR &= ~(RS485_RDEN_PIN);//Low Rev
			
			if(times.HOUR == 24){
				times.HOUR = 0;
			}
		}

		TIM_ClearITPendingBit(TIM1, TIM_IT_Update);    //清除TIM1更新中断标志 
	}
}
/**
  * @brief  This function handles USART2 global interrupt request.
  * @param  None
  * @retval None
  */
//void USART2_IRQHandler(void)
//{
//	CPU_SR_ALLOC();
//	CPU_CRITICAL_ENTER();
//  OSIntEnter();//OSIntNestingCtr++; 
//	CPU_CRITICAL_EXIT();
//	BSP_GPRS_USART_IRQHandler();
//	OSIntExit();
//}

/**
  * @brief  This function handles UART3 global interrupt request.
  * @param  None
  * @retval None
  */
//void USART3_IRQHandler(void)
//{
//	CPU_SR_ALLOC();
//	CPU_CRITICAL_ENTER();
//  OSIntEnter();//OSIntNestingCtr++; 
//	CPU_CRITICAL_EXIT();
//	OSIntExit();
//}


/******************************************************************************/
/*                 STM32F10x Peripherals Interrupt Handlers                   */
/*  Add here the Interrupt Handler for the used peripheral(s) (PPP), for the  */
/*  available peripheral interrupt handler's name please refer to the startup */
/*  file (startup_stm32f10x_xx.s).                                            */
/******************************************************************************/

/**
  * @brief  This function handles PPP interrupt request.
  * @param  None
  * @retval None
  */
/*void PPP_IRQHandler(void)
{
}*/

/**
  * @}
  */ 


/******************* (C) COPYRIGHT 2011 STMicroelectronics *****END OF FILE****/
