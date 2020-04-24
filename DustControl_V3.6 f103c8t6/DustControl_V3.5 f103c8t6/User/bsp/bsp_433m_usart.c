#include "bsp.h"

static void UartVarInit(void);
static void USART_Configuration(void);
static void ConfigUartNVIC(void);

const char kcmd[] = "K01OK#\r\n";
const char gcmd[] = "G01OK#\r\n";

uint8_t RxBuff433m[128]; //433m接收数据缓存区
uint16_t RxBuffCnt433m;  //接收计数器
uint8_t RxState433m;     //接收完一帧数据

void BSP_InitUart_433m(void){
	UartVarInit();
	USART_Configuration();
	ConfigUartNVIC();
}

void ParseCommand_433m(void){
	
	if(RxState433m == 1){
		RxState433m = 0;
		RxBuffCnt433m = 0;

		if(memcmp((char*)RxBuff433m, kcmd, sizeof(kcmd)) == 0){
			
			LED_PORT->ODR &= ~(LED_433_PIN);//亮灯
			
		}else if(memcmp((char*)RxBuff433m, gcmd, sizeof(gcmd)) == 0){
			
			LED_PORT->ODR |= LED_433_PIN; //灭灯
			
		}
		
		memset(RxBuff433m, 0, sizeof(RxBuff433m));
	}
}

static void UartVarInit(void)
{
	RxBuffCnt433m = 0;
	RxState433m = 0;
	memset(RxBuff433m, 0, sizeof(RxBuff433m));
}

static void USART_Configuration(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	USART_InitTypeDef USART_InitStructure;

	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC | RCC_APB2Periph_AFIO, ENABLE);/* Enable GPIO clock */
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_UART4, ENABLE);/*Enable UART4 clock */

	/* Configure UART4 Rx as input floating */
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_11;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
	GPIO_Init(GPIOC, &GPIO_InitStructure);

	/* Configure UART4 Tx as alternate function push-pull */
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_Init(GPIOC, &GPIO_InitStructure);
	
  /* UART4 configured as follow:
        - BaudRate = 9600 baud  
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
  USART_InitStructure.USART_Mode = USART_Mode_Tx | USART_Mode_Rx;
	/* Configure UART4 */
  USART_Init(UART4, &USART_InitStructure);
	
  /* Enable UART4 Receive and Transmit interrupts */
	USART_ITConfig(UART4, USART_IT_IDLE, ENABLE);//空闲中断
  USART_ITConfig(UART4, USART_IT_RXNE, ENABLE);//接收中断
	
  /* Enable the UART4*/
  USART_Cmd(UART4, ENABLE);
	
	USART_ClearFlag(UART4,USART_FLAG_TC);
}

static void ConfigUartNVIC(void)
{
	NVIC_InitTypeDef NVIC_InitStructure; 
	/* Configure the NVIC Preemption Priority Bits */  
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);
	
	/* Enable the USARTy Interrupt */
	NVIC_InitStructure.NVIC_IRQChannel = UART4_IRQn;	 
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = USART4_NVIC_PRIORITY;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStructure);
}

void UartWriteBuffer_433M(const uint8_t *pBuffer,uint32_t NumByteToWrite)
{
	while(NumByteToWrite--)
	{
		USART_SendData(UART4, (uint8_t)*pBuffer++);
		while(USART_GetFlagStatus(UART4, USART_FLAG_TXE) == RESET);
	}
}
