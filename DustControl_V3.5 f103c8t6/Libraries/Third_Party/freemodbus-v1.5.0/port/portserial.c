#include "bsp.h"

/* ----------------------- Start implementation -----------------------------*/
/**
  * @brief  控制接收和发送状态
  * @param  xRxEnable 接收使能、
  *         xTxEnable 发送使能
  * @retval None
  */
void vMBPortSerialEnable( BOOL xRxEnable, BOOL xTxEnable ){

  if(xRxEnable){
		RS485_RDEN_PORT->ODR &= ~(RS485_RDEN_PIN);
  }
  if(xTxEnable){
		RS485_RDEN_PORT->ODR |= (RS485_RDEN_PIN);
  }
}

/**
  * @brief  串口初始化
  * @param  ucPORT      串口号
  *         ulBaudRate  波特率
  *         ucDataBits  数据位
  *         eParity     校验位 
  * @retval None
  */
BOOL xMBPortSerialInit(UCHAR ucPORT, ULONG ulBaudRate, UCHAR ucDataBits, eMBParity eParity){
 
	GPIO_InitTypeDef GPIO_InitStructure;
	USART_InitTypeDef USART_InitStructure;
	NVIC_InitTypeDef NVIC_InitStructure;
	
	(void)ucPORT;     //固定端口号
	(void)ucDataBits; //固定数据位长度
	(void)eParity;    //固定校验位长度
	/*----------------------------------------------------------------------------------------------*/
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA | RCC_APB2Periph_AFIO, ENABLE);/* Enable GPIO clock */
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART2, ENABLE);/*Enable USART2 clock */

	/* Configure USART2 Rx as input floating */
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
	GPIO_Init(GPIOA, &GPIO_InitStructure);

	/* Configure USART2 Tx as alternate function push-pull */
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	
  /* USART2 configured as follow:
        - BaudRate = 115200 baud  
        - Word Length = 8 Bits
        - One Stop Bit
        - No parity
        - Hardware flow control disabled (RTS and CTS signals)
        - Receive and transmit enabled
  */
  USART_InitStructure.USART_BaudRate = ulBaudRate;
  USART_InitStructure.USART_WordLength = USART_WordLength_8b;
  USART_InitStructure.USART_StopBits = USART_StopBits_1;
  USART_InitStructure.USART_Parity = USART_Parity_No;
  USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
  USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;
	USART_Init(USART2, &USART_InitStructure);/* Configure USART2 */
	/* Configure USART2 */
  USART_Init(USART2, &USART_InitStructure);
	
	USART_ITConfig(USART2, USART_IT_RXNE, ENABLE);//接收中断
	USART_ITConfig(USART2, USART_IT_TC, ENABLE);//发送完成中断
  /* Enable the USART2*/
  USART_Cmd(USART2, ENABLE);
	
	USART_ClearFlag(USART2,USART_FLAG_TC);
	/*--------------------------------------------------------------------------------------*/
	/* Configure the NVIC Preemption Priority Bits */  
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);
	
	/* Enable the UART4 Interrupt */
	NVIC_InitStructure.NVIC_IRQChannel = USART2_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = USART2_NVIC_PRIORITY;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStructure);
	
  return TRUE;
}

/**
  * @brief  通过串口发送数据
  * @param  None
  * @retval None
  */
BOOL xMBPortSerialPutByte(CHAR ucByte){

	USART_SendData(USART2, ucByte);
	while(USART_GetFlagStatus(USART2, USART_FLAG_TXE) == RESET);
	return TRUE;
}

/**
  * @brief  从串口获得数据
  * @param  None
  * @retval None
  */
BOOL xMBPortSerialGetByte(CHAR * pucByte){
  *pucByte = USART2->DR;
	return TRUE;
}

void USART2_IRQHandler(void){
	if(USART_GetITStatus(USART2, USART_IT_RXNE) != RESET){
		pxMBFrameCBByteReceived();//接收中断
		USART_ClearITPendingBit(USART2,USART_IT_RXNE);
	}else if(USART_GetITStatus(USART2, USART_IT_TC) != RESET){
		pxMBFrameCBTransmitterEmpty();//发送中断
		USART_ClearITPendingBit(USART2,USART_IT_TC);
	}
}
