#ifndef _BSP_USART_DEGUG_H_
#define _BSP_USART_DEGUG_H_

#include "bsp.h"

void BSP_InitUart_Debug(void);
void NOVA_USART1_IRQHandler(void);
void ParsePM25Command(void);
void Open_Measurement(void);
void Close_Measurement(void);
void ParsePM25Command_CUBIC(void);
void Uart1WriteBuffer_Config(const uint8_t *pBuffer,uint32_t NumByteToWrite);
void CLR_Buf1(void);
u8 Find_usart1(char *a) ;
void UART6_WriteBuffer(const uint8_t *pBuffer,uint32_t NumByteToWrite);
void CLR_Buf6(void);
u8 Find_usart6(char *a);
#endif /* _BSP_USART_DEGUG_H_ */
