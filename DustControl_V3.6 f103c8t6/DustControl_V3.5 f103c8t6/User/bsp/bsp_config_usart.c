#include "bsp.h"
u8  USART3_RX_BUF[USART_REC_LEN]; //接收缓冲,最大USART_REC_LEN个字节.末字节为换行符 
u16 USART3_RX_STA = 0;         		//接收状态标记	
static void UartVarInit(void);
static void USART_Configuration(void);
static void ConfigUartNVIC(void);
/*
uint8_t  RxDataBuff[256];  //配置数据接收缓存区
uint8_t  RxCmdBuff[128];   //配置命令接收缓存区
uint16_t RxDataCount;      //接收数据计数器
uint16_t RxCmdCount;       //接收命令计数器
uint8_t  RxStateConfig;    //接收完一帧数据
uint8_t  CmdFlag;          //0表示命令,1表示数据
*/
const char write_config_cmd[] = "write\r\n";
const char read_config_cmd[] = "read\r\n";

void BSP_InitUart_Config(void){
	UartVarInit();
	USART_Configuration();
	ConfigUartNVIC();
}
/*
void ParseCommand_Config(void){
	
	if(RxStateConfig == 1){
		RxStateConfig = 0;
		RxCmdCount = 0;//接收命令计数器清零
		
		if(memcmp((char*)RxCmdBuff, write_config_cmd, sizeof(write_config_cmd)) == 0){
			
			memset(RxDataBuff, 0 ,sizeof(RxDataBuff));
			RxDataCount = 0;//接收数据计数器清零
			CmdFlag = 1;//开始接收数据
			Uart3WriteBuffer_Config("请输入设备编号：\r\n", strlen("请输入设备编号：\r\n"));
			
		}else if(memcmp((char*)RxCmdBuff, read_config_cmd, sizeof(read_config_cmd)) == 0){
			
			memset(RxDataBuff, 0 ,sizeof(RxDataBuff));
			
			FLASH_ReadHalfWord(RxDataBuff, sizeof(RxDataBuff));//读出数据
			Uart3WriteBuffer_Config(RxDataBuff, strlen((char *)RxDataBuff));//发送数据
		}
		
		memset(RxCmdBuff, 0, sizeof(RxCmdBuff));
	}
}
*/
static void UartVarInit(void){
	/*
	RxDataCount = 0;
	RxCmdCount = 0;
	RxStateConfig = 0;
	CmdFlag = 0;
	memset(RxCmdBuff, 0, sizeof(RxCmdBuff));
	memset(RxDataBuff, 0, sizeof(RxDataBuff));
	*/
}

static void USART_Configuration(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	USART_InitTypeDef USART_InitStructure;

	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB | RCC_APB2Periph_AFIO, ENABLE);/* Enable GPIO clock */
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART3, ENABLE);/*Enable UART5 clock */

	/* Configure UART5 Rx as input floating */
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_11;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
	GPIO_Init(GPIOB, &GPIO_InitStructure);

	/* Configure UART5 Tx as alternate function push-pull */
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_Init(GPIOB, &GPIO_InitStructure);
	
  /* UART5 configured as follow:
        - BaudRate = 115200 baud  
        - Word Length = 8 Bits
        - One Stop Bit
        - No parity
        - Hardware flow control disabled (RTS and CTS signals)
        - Receive and transmit enabled
  */
  USART_InitStructure.USART_BaudRate = 115200;
  USART_InitStructure.USART_WordLength = USART_WordLength_8b;
  USART_InitStructure.USART_StopBits = USART_StopBits_1;
  USART_InitStructure.USART_Parity = USART_Parity_No;
  USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
  USART_InitStructure.USART_Mode = USART_Mode_Tx | USART_Mode_Rx;
	/* Configure UART5 */
  USART_Init(USART3, &USART_InitStructure);
	
  /* Enable UART5 Receive and Transmit interrupts */
//	USART_ITConfig(USART3, USART_IT_IDLE, ENABLE);//空闲中断
  USART_ITConfig(USART3, USART_IT_RXNE, ENABLE);//接收中断
	
  /* Enable the UART5*/
  USART_Cmd(USART3, ENABLE);
	
	USART_ClearFlag(USART3, USART_FLAG_TC);
}

static void ConfigUartNVIC(void){
	
	NVIC_InitTypeDef NVIC_InitStructure; 
	/* Configure the NVIC Preemption Priority Bits */  
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);
	
	/* Enable the USARTy Interrupt */
	NVIC_InitStructure.NVIC_IRQChannel = USART3_IRQn;	 
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStructure);
}

void Uart3WriteBuffer_Config(const uint8_t *pBuffer,uint32_t NumByteToWrite){
	
	while(NumByteToWrite--)
	{
		USART_SendData(USART3, (uint8_t)*pBuffer++);
		while(USART_GetFlagStatus(USART3, USART_FLAG_TXE) == RESET);
	}
}

void UART6_WriteBuffer(const uint8_t *pBuffer,uint32_t NumByteToWrite)
{
	while(NumByteToWrite--)
	{
		USART_SendData(USART3, (uint8_t)*pBuffer++);
		while(USART_GetFlagStatus(USART3, USART_FLAG_TXE) == RESET);
	}
}
void CLR_Buf6(void)
{
	u16 k;
	for(k=0;k<USART_REC_LEN;k++)      //将缓存内容清零
	{
		USART6_RX_BUF[k] = 0x00;
	}
    USART6_RX_STA = 0;              //接收字符串的起始存储位置
}
u8 Find_usart6(char *a)    //查询接收缓存数组内容 
{ 
  if(strstr((char *)USART6_RX_BUF,a)!=NULL)
	    return 1;
	else
			return 0;
}
void USART3_IRQHandler(void)                	//串口1中断服务程序
{
  
	u8 Res;
	if(USART_GetITStatus(USART3, USART_IT_RXNE) != RESET)  //接收中断(接收到的数据必须是0x0d 0x0a结尾)
	{
		Res =USART_ReceiveData(USART3);//(USART1->DR);	//读取接收到的数据
		USART6_RX_BUF[USART6_RX_STA]=Res ;
		USART6_RX_STA++;
		if(USART6_RX_STA>(USART_REC_LEN))USART6_RX_STA=0;//接收数据错误,重新开始接收
		
  } 

} 
