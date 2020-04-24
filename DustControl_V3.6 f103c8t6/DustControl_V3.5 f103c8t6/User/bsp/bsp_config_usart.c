#include "bsp.h"
u8  USART3_RX_BUF[USART_REC_LEN]; //���ջ���,���USART_REC_LEN���ֽ�.ĩ�ֽ�Ϊ���з� 
u16 USART3_RX_STA = 0;         		//����״̬���	
static void UartVarInit(void);
static void USART_Configuration(void);
static void ConfigUartNVIC(void);
/*
uint8_t  RxDataBuff[256];  //�������ݽ��ջ�����
uint8_t  RxCmdBuff[128];   //����������ջ�����
uint16_t RxDataCount;      //�������ݼ�����
uint16_t RxCmdCount;       //�������������
uint8_t  RxStateConfig;    //������һ֡����
uint8_t  CmdFlag;          //0��ʾ����,1��ʾ����
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
		RxCmdCount = 0;//�����������������
		
		if(memcmp((char*)RxCmdBuff, write_config_cmd, sizeof(write_config_cmd)) == 0){
			
			memset(RxDataBuff, 0 ,sizeof(RxDataBuff));
			RxDataCount = 0;//�������ݼ���������
			CmdFlag = 1;//��ʼ��������
			Uart3WriteBuffer_Config("�������豸��ţ�\r\n", strlen("�������豸��ţ�\r\n"));
			
		}else if(memcmp((char*)RxCmdBuff, read_config_cmd, sizeof(read_config_cmd)) == 0){
			
			memset(RxDataBuff, 0 ,sizeof(RxDataBuff));
			
			FLASH_ReadHalfWord(RxDataBuff, sizeof(RxDataBuff));//��������
			Uart3WriteBuffer_Config(RxDataBuff, strlen((char *)RxDataBuff));//��������
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
//	USART_ITConfig(USART3, USART_IT_IDLE, ENABLE);//�����ж�
  USART_ITConfig(USART3, USART_IT_RXNE, ENABLE);//�����ж�
	
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
	for(k=0;k<USART_REC_LEN;k++)      //��������������
	{
		USART6_RX_BUF[k] = 0x00;
	}
    USART6_RX_STA = 0;              //�����ַ�������ʼ�洢λ��
}
u8 Find_usart6(char *a)    //��ѯ���ջ����������� 
{ 
  if(strstr((char *)USART6_RX_BUF,a)!=NULL)
	    return 1;
	else
			return 0;
}
void USART3_IRQHandler(void)                	//����1�жϷ������
{
  
	u8 Res;
	if(USART_GetITStatus(USART3, USART_IT_RXNE) != RESET)  //�����ж�(���յ������ݱ�����0x0d 0x0a��β)
	{
		Res =USART_ReceiveData(USART3);//(USART1->DR);	//��ȡ���յ�������
		USART6_RX_BUF[USART6_RX_STA]=Res ;
		USART6_RX_STA++;
		if(USART6_RX_STA>(USART_REC_LEN))USART6_RX_STA=0;//�������ݴ���,���¿�ʼ����
		
  } 

} 
