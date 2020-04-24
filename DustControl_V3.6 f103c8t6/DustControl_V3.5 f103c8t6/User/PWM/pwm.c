#include "pwm.h"
/*		
 *		 PWMƵ�ʣ�24KHZ
 *     TIM_SetCompare1(TIM1,100);	//ռ�ձ�90
 *		 TIM_SetCompare1(TIM1,1500);			//ռ�ձ�50
 *		 TIM_SetCompare1(TIM1,3000);			//0
 *		 TIM_SetCompare1(TIM1,2700);  	 //10
 *		 TIM_SetCompare1(TIM1,2400);     //20
 *		 TIM_SetCompare1(TIM1,2100);     //30
 *		 TIM_SetCompare1(TIM1,1800);     //40
 *		 TIM_SetCompare1(TIM1,1500);     //50
 *		 TIM_SetCompare1(TIM1,1200);     //60
 *		 TIM_SetCompare1(TIM1,900);     //70
 *		 TIM_SetCompare1(TIM1,600);     //80
 *		 TIM_SetCompare1(TIM1,300);     //90 
 *		 TIM_SetCompare1(TIM1,0);     //100  
 *		 PWMƵ�ʣ�60KHZ
 *     TIM_SetCompare1(TIM1,100);	//ռ�ձ�50
 *		 TIM_SetCompare1(TIM1,200);			//0
 *		 TIM_SetCompare1(TIM1,180);  	 //10
 *		 TIM_SetCompare1(TIM1,160);     //20
 *		 TIM_SetCompare1(TIM1,140);     //30
 *		 TIM_SetCompare1(TIM1,120);     //40
 *		 TIM_SetCompare1(TIM1,100);     //50
 *		 TIM_SetCompare1(TIM1,80);     //60
 *		 TIM_SetCompare1(TIM1,60);     //70
 *		 TIM_SetCompare1(TIM1,40);     //80
 *		 TIM_SetCompare1(TIM1,20);     //90 
 *		 TIM_SetCompare1(TIM1,0);     //100  
 */

/* ˽�����Ͷ��� --------------------------------------------------------------*/
/* ˽�к궨�� ----------------------------------------------------------------*/
/* ˽�б��� ------------------------------------------------------------------*/
/* ��չ���� ------------------------------------------------------------------*/
/* ˽�к���ԭ�� --------------------------------------------------------------*/
/* ������ --------------------------------------------------------------------*/
/**
  * ��������: ����TIMx�������PWMʱ�õ���I/O
  * �������: ��
  * �� �� ֵ: ��
  * ˵    ������
  */
static void GENERAL_TIMx_GPIO_Config(void) 
{
  GPIO_InitTypeDef GPIO_InitStructure;

	/* ʹ�ܶ�ʱ��ʼ�գ�����TIM3CLK Ϊ 72MHZ */
	GENERAL_TIM_APBxClock_FUN (GENERAL_TIM_CLK, ENABLE);

  /* ʹ�ܶ�ʱ��ͨ������GPIOʱ�� */
  GENERAL_TIM_GPIO_APBxClock_FUN(GENERAL_TIM_GPIO_CLK, ENABLE); 

  /* ���ö�ʱ��ͨ��1�������ģʽ�������������ģʽ */
  GPIO_InitStructure.GPIO_Pin =  GENERAL_TIM_CH1_PIN;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GENERAL_TIM_CH1_PORT, &GPIO_InitStructure);
	
  #if 0
    /* ���ö�ʱ��ͨ��2�������ģʽ */
  GPIO_InitStructure.GPIO_Pin =  GENERAL_TIM_CH2_PIN;
  GPIO_Init(GENERAL_TIM_CH2_PORT, &GPIO_InitStructure);

  /* ���ö�ʱ��ͨ��3�������ģʽ */
  GPIO_InitStructure.GPIO_Pin =  GENERAL_TIM_CH3_PIN;
  GPIO_Init(GENERAL_TIM_CH3_PORT, &GPIO_InitStructure);
	
  /* ���ö�ʱ��ͨ��4�������ģʽ */
  GPIO_InitStructure.GPIO_Pin =  GENERAL_TIM_CH4_PIN;
  GPIO_Init(GENERAL_TIM_CH4_PORT, &GPIO_InitStructure);
	
  #endif
	
	
  /* Disable the Serial Wire Jtag Debug Port SWJ-DP */
  /* ����JTAG���� */
  GPIO_PinRemapConfig(GPIO_Remap_SWJ_JTAGDisable, ENABLE);
  /* ��ʱ��ͨ��������ӳ�� */
  GPIO_PinRemapConfig(GPIO_FullRemap_TIM2,ENABLE);
}

/**
  * ��������: ����TIM3�����PWM�źŵ�ģʽ�������ڡ����ԡ�ռ�ձ�
  * �������: ��
  * �� �� ֵ: ��
  * ˵    ������
  */
/*
 * TIMxCLK/CK_PSC --> TIMxCNT --> TIMx_ARR --> TIMxCNT ���¼���
 *                    TIMx_CCR(��ƽ�����仯)
 * �ź�����=(TIMx_ARR +1 ) * ʱ������
 * ռ�ձ�=TIMx_CCR/(TIMx_ARR +1)
 */
static void GENERAL_TIMx_Configuration(u16 arr,u16 psc)
{
  TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
	TIM_OCInitTypeDef  TIM_OCInitStructure;

	/* PWM�źŵ�ƽ����ֵ */
// 	uint16_t CCR1_Val = 150;       
//  uint16_t CCR2_Val = 150; 
//  uint16_t CCR3_Val = 150; 
//  uint16_t CCR4_Val = 150;   

/* ----------------------------------------------------------------------- 
    GENERAL_TIMx Channel1 duty cycle = (GENERAL_TIMx_CCR1/ GENERAL_TIMx_ARR+1)* 100% = 50%
    GENERAL_TIMx Channel2 duty cycle = (GENERAL_TIMx_CCR2/ GENERAL_TIMx_ARR+1)* 100% = 37.5%
    GENERAL_TIMx Channel3 duty cycle = (GENERAL_TIMx_CCR3/ GENERAL_TIMx_ARR+1)* 100% = 25%
    GENERAL_TIMx Channel4 duty cycle = (GENERAL_TIMx_CCR4/ GENERAL_TIMx_ARR+1)* 100% = 12.5%
  ----------------------------------------------------------------------- */

  /* ��ʱ����������ʼ�� */		 
  /* ����ʱ����0������999����Ϊ1000�Σ�Ϊһ����ʱ���� */
  TIM_TimeBaseStructure.TIM_Period = arr; 
  /* ����Ԥ��Ƶ����Ԥ��Ƶ����Ϊ72MHz,�������Ƶ�ʣ�72MHz/720 */
  /* ͬһ����ʱ���Ĳ�ͬͨ��PWM��Ƶ��ֻ������ͬ�ģ���ͬͨ����������Ϊ��ͬ��ռ�ձ� */
  TIM_TimeBaseStructure.TIM_Prescaler = psc;
  /* ����ʱ�ӷ�Ƶϵ��������Ƶ(�����ò���) */
  TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1 ;
  /* ���ϼ���ģʽ */
  TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;
  TIM_TimeBaseInit(GENERAL_TIMx, &TIM_TimeBaseStructure);

  /* ��ʱ�����ͨ��1ģʽ���� */
  /* ģʽ���ã�PWMģʽ1 */
  TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM2;
  /* ���״̬���ã�ʹ����� */
  TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;	
  /* ��������ֵ�������������������ֵʱ����ƽ�������� */
  TIM_OCInitStructure.TIM_Pulse = 0;
  /* ����ʱ������ֵС��CCR1_ValʱΪ�ߵ�ƽ */
  TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;

  /* ��ʱ�����ͨ��2ģʽ���� */
  /* ����ͨ��2�ĵ�ƽ����ֵ���������һ��ռ�ձȵ�PWM */
  TIM_OCInitStructure.TIM_Pulse = 0;
  /* ��ʼ����ʱ��ͨ��2���PWM */
  TIM_OC2Init(GENERAL_TIMx, &TIM_OCInitStructure);
  /* ��ʱ���Ƚ����ͨ��2Ԥװ�����ã�ʹ��Ԥװ�� */
  TIM_OC2PreloadConfig(GENERAL_TIMx, TIM_OCPreload_Enable);


  
  /* ʹ�ܶ�ʱ�����ؼĴ���ARR */
  TIM_ARRPreloadConfig(GENERAL_TIMx, ENABLE);

  /* ʹ�ܶ�ʱ�� */
  TIM_Cmd(GENERAL_TIMx, ENABLE);
}

/**
  * ��������: TIMx ���PWM�źų�ʼ��
  * �������: ��
  * �� �� ֵ: ��
  * ˵    ����ֻҪ�����������TIMx���ĸ�ͨ���ͻ���PWM�ź����
  */
void GENERAL_TIMx_PWM_Init(u16 arr,u16 psc)
{
	GENERAL_TIMx_GPIO_Config();
	GENERAL_TIMx_Configuration(arr,psc);	
}
/******************* (C) COPYRIGHT 2015-2020 ӲʯǶ��ʽ�����Ŷ� *****END OF FILE****/