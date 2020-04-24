#include "bsp.h"
u8  USART6_RX_BUF[USART_REC_LEN]; //接收缓冲,最大USART_REC_LEN个字节.末字节为换行符 
u16 USART6_RX_STA = 0;         		//接收状态标记	
static void USART_Configuration(void);

void BSP_InitUart_Debug(void){
	USART_Configuration();
}

static void USART_Configuration(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	USART_InitTypeDef USART_InitStructure;
	NVIC_InitTypeDef NVIC_InitStructure;
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA | RCC_APB2Periph_AFIO, ENABLE);/* Enable GPIO clock */
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1, ENABLE);/*Enable USART1 clock */

	/* Configure USART1 Rx as input floating */
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
	GPIO_Init(GPIOA, &GPIO_InitStructure);

	/* Configure USART1 Tx as alternate function push-pull */
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	
  /* USART1 configured as follow:
        - BaudRate = 115200 baud  
        - Word Length = 8 Bits
        - One Stop Bit
        - No parity
        - Hardware flow control disabled (RTS and CTS signals)
        - Receive and transmit enabled
  */
  USART_InitStructure.USART_BaudRate = 9600;
  USART_InitStructure.USART_WordLength = USART_WordLength_8b;
  USART_InitStructure.USART_StopBits = USART_StopBits_1;
  USART_InitStructure.USART_Parity = USART_Parity_No;
  USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
  USART_InitStructure.USART_Mode = USART_Mode_Tx|USART_Mode_Rx;//
	/* Configure USART1 */
  USART_Init(USART1, &USART_InitStructure);
	
  /* Enable USART1 Receive and Transmit interrupts */
  USART_ITConfig(USART1, USART_IT_RXNE, ENABLE);//接收中断
                //清除标志位
  /* Enable the USART1*/
  USART_Cmd(USART1, ENABLE);
	USART_ClearFlag(USART1,USART_FLAG_TC);
	
	NVIC_InitStructure.NVIC_IRQChannel = USART1_IRQn;       //串口2中断
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=2; //抢占优先级2
	NVIC_InitStructure.NVIC_IRQChannelSubPriority =2;		//子优先级3
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;			//中断通道使能
	NVIC_Init(&NVIC_InitStructure);	                        //根据配置设置
}
void Uart1WriteBuffer_Config(const uint8_t *pBuffer,uint32_t NumByteToWrite){
	
	while(NumByteToWrite--)
	{
		USART_SendData(USART1, (uint8_t)*pBuffer++);
		while(USART_GetFlagStatus(USART1, USART_FLAG_TXE) == RESET);
	}
}
void CLR_Buf1(void)
{

		memset(USART1_RX_BUF, 0, sizeof(USART1_RX_BUF));
    USART1_RX_STA = 0;              //接收字符串的起始存储位置
}
u8 Find_usart1(char *a)    //查询接收缓存数组内容 
{ 
  if(strstr((char *)USART1_RX_BUF,a)!=NULL)
	    return 1;
	else
			return 0;
}
/*
*********************************************************************************************************
*	函 数 名: fputc
*	功能说明: 重定义putc函数，这样可以使用printf函数从串口1打印输出
*	形    参: 无
*	返 回 值: 无
*********************************************************************************************************
*/
int fputc(int ch, FILE *f)
{
//	RS485_RDEN_PORT->ODR |= RS485_RDEN_PIN;//High Send
	/* 写一个字节到USART1 */
	USART_SendData(USART2, (uint8_t) ch);

	/* 等待发送结束 */
	while (USART_GetFlagStatus(USART2, USART_FLAG_TXE) == RESET);		
//	RS485_RDEN_PORT->ODR &= ~(RS485_RDEN_PIN);//Low Rev
	return ch;
}
/*
*********************************************************************************************************
*	函 数 名: NOVA_USART1_IRQHandler
*	功能说明: 串口1获取诺方传感器参数
*	形    参: 无
*	返 回 值: 无
*********************************************************************************************************
*/
void NOVA_USART1_IRQHandler(void)                	//串口1中断服务程序
{

		u8 Res;
	if(USART_GetITStatus(USART1, USART_IT_RXNE) != RESET)  //接收中断(接收到的数据必须是0x0d 0x0a结尾)
	{
		Res =USART_ReceiveData(USART1);//(USART1->DR);	//读取接收到的数据
		USART1_RX_BUF[USART1_RX_STA]=Res ;
		USART1_RX_STA++;
		if(USART1_RX_STA>(USART_REC_LEN))USART1_RX_STA=0;//接收数据错误,重新开始接收
		
  } 
	
	
}
void ParsePM25Command(void){
	uint16_t i;
	for(i = 0; i < USART_REC_LEN; i++){
		if(USART1_RX_BUF[i] == 0xAA && USART1_RX_BUF[i+1] == 0xC0 && USART1_RX_BUF[i+9] == 0xAB){

			mySensorDatas.PM2_5 = ((USART1_RX_BUF[i+3] << 8) | USART1_RX_BUF[i+2])/10;//PM2.5
			mySensorDatas.PM10  = ((USART1_RX_BUF[i+5] << 8) | USART1_RX_BUF[i+4])/10;//PM10
			mySensorDatas.TSP   = ((mySensorDatas.PM10) * 14)/10;//TSP
			printf("PM2_5 = %d\r\n",mySensorDatas.PM2_5);
			printf("PM10 = %d\r\n",mySensorDatas.PM10);
			printf("TSP = %d\r\n",mySensorDatas.TSP);
			USART1_RX_STA = 0;
			memset(USART1_RX_BUF, 0, sizeof(USART1_RX_BUF));

			break;
		}
	}

}

void Open_Measurement(void){
	//16 02 0C 02 DA 

	
	u8 open_[]  ={0x11,0x03,0x0c,0x02,0x1e,0xc0};
	u8 open_1[] ={0x16,0x02,0x0c,0x02,0xda};		
	Uart1WriteBuffer_Config(open_,strlen((char *)open_));
	BSP_OS_TimeDly(400);
	

		if(Find_usart1((char *)open_1)){
			
			CLR_Buf1();
//			printf("开启测量成功！\r\n");
		
		}
	
	

}
void Close_Measurement(void){
	//16 02 0C 01 DB
//	u8 open_cont = 5;
	
	u8 open_[6]  ={0x11,0x03,0x0c,0x01,0x1e,0xc1};
	u8 open_1[] ={0x16,0x02,0x0c,0x01,0xdb};		
	Uart1WriteBuffer_Config(open_,6);

	BSP_OS_TimeDly(500);

		if(Find_usart1((char *)open_1)){
			
			CLR_Buf1();
			printf("关闭测量成功！\r\n");

		}

	
	

}
