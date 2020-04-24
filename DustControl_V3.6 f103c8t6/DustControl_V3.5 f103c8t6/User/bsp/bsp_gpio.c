#include  "bsp.h"

static void BSP_GPIO_Config(void);

void BSP_GPIO_Init(void){
	BSP_GPIO_Config();
}

static void BSP_GPIO_Config(void){
	GPIO_InitTypeDef GPIO_InitStructure;
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA | RCC_APB2Periph_GPIOB  |  RCC_APB2Periph_GPIOC |  RCC_APB2Periph_GPIOE, ENABLE);/* Enable GPIO clock */
	
	/* Configure Relay for PD13 PD14 PD15 Pin  */
	GPIO_InitStructure.GPIO_Pin = REALY1_PIN | REALY2_PIN | REALY3_PIN;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_Init(REALY_PORT, &GPIO_InitStructure);
	
			REALY_PORT->ODR |=  (REALY2_PIN);  //电磁阀
//			REALY_PORT->ODR &= ~(REALY2_PIN);	  //Low Rev  电磁阀
			REALY_PORT->ODR |=  (REALY3_PIN);	  //  清灰
	

	
	
//	REALY_PORT->ODR |=  (REALY2_PIN);	//闭合  High
//	REALY_PORT->ODR &= ~(REALY2_PIN);	  //Low Rev   
	
//	REALY_PORT->ODR |=  (REALY1_PIN);	//闭合
//	REALY_PORT->ODR &= ~(REALY1_PIN);
	/* Configure LED for PE11 PE12 Pin  */
	GPIO_InitStructure.GPIO_Pin = (LED_LINK_PIN | LED_NETOK_PIN);
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_Init(LED_PORT, &GPIO_InitStructure);
	LED_PORT->ODR |= (LED_LINK_PIN | LED_NETOK_PIN);//All LED Off
//	LED_PORT->ODR &= ~ (LED_LINK_PIN | LED_NETOK_PIN);//All LED ON   
	/* Configure GPRS PWR for PC6 Pin  */
	GPIO_InitStructure.GPIO_Pin = (GPRS_PWR_PIN);
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_Init(GPRS_PWR_PORT, &GPIO_InitStructure);
	GPRS_PWR_PORT->ODR &= ~(GPRS_PWR_PIN);//Set GPRS PWR Pin High
	
		/* Configure RS485 RDEN for PA1 Pin  */
	GPIO_InitStructure.GPIO_Pin = RS485_RDEN_PIN;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_Init(RS485_RDEN_PORT, &GPIO_InitStructure);
	RS485_RDEN_PORT->ODR &= ~(RS485_RDEN_PIN);//Low Rev
}
