#include "bsp.h"

/* ----------------------- Start implementation -----------------------------*/
BOOL xMBPortTimersInit( USHORT usTim1Timerout50us ){
	
  TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
  NVIC_InitTypeDef NVIC_InitStructure;
  //
  uint16_t PrescalerValue = 0;
  
  //ʹ�ܶ�ʱ��4ʱ��
  RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4, ENABLE);
  
  //��ʱ��ʱ�������˵��
  //HCLKΪ72MHz��APB1����2��ƵΪ36MHz
  //TIM4��ʱ�ӱ�Ƶ��Ϊ72MHz��Ӳ���Զ���Ƶ,�ﵽ���
  //TIM4�ķ�Ƶϵ��Ϊ3599��ʱ���Ƶ��Ϊ72 / (1 + Prescaler) = 20KHz,��׼Ϊ50us
  //TIM������ֵΪusTim1Timerout50u
  PrescalerValue = (uint16_t) (SystemCoreClock / 20000) - 1; 
  //��ʱ��1��ʼ��
  TIM_TimeBaseStructure.TIM_Period = (uint16_t) usTim1Timerout50us;
  TIM_TimeBaseStructure.TIM_Prescaler = PrescalerValue;
  TIM_TimeBaseStructure.TIM_ClockDivision = 0;
  TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;
  TIM_TimeBaseInit(TIM4, &TIM_TimeBaseStructure);
  //Ԥװ��ʹ��
  TIM_ARRPreloadConfig(TIM4, ENABLE);
	
	TIM_ITConfig(TIM4, TIM_IT_Update, ENABLE);
	
	TIM_ClearFlag(TIM4, TIM_FLAG_Update);
	
  TIM_Cmd(TIM4,  DISABLE);
	
  NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);
  //��ʱ��4�ж����ȼ�
  NVIC_InitStructure.NVIC_IRQChannel = TIM4_IRQn;
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 2;
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
  NVIC_Init(&NVIC_InitStructure);
  
  return TRUE;
}


void vMBPortTimersEnable(){
  /* Enable the timer with the timeout passed to xMBPortTimersInit( ) */
	TIM4->CNT = 0;  //�趨��ʱ��4�ĳ�ʼֵ
	TIM4->CR1 |= TIM_CR1_CEN; //��ʱ��4����
}

void vMBPortTimersDisable(){
	TIM4->CNT = 0;  //�趨��ʱ��4�ĳ�ʼֵ
	TIM4->CR1 &= (uint16_t)(~((uint16_t)TIM_CR1_CEN));//�ر�TIM4
}

void TIM4_IRQHandler(void){
	if(TIM_GetITStatus(TIM4, TIM_IT_Update) != RESET){
		TIM_ClearITPendingBit(TIM4, TIM_IT_Update);
		(void)pxMBPortCBTimerExpired();
	}
}
