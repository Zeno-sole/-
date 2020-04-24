#ifndef _BSP_USART_433M_H_
#define _BSP_USART_433M_H_

#include "bsp.h"

void BSP_InitUart_433m(void);
void ParseCommand_433m(void);
void UartWriteBuffer_433M(const uint8_t *pBuffer,uint32_t NumByteToWrite);

#endif /* _BSP_USART_433M_H_ */
