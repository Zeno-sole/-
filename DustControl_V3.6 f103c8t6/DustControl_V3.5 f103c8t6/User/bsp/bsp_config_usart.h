#ifndef _BSP_USART_CONFIG_H_
#define _BSP_USART_CONFIG_H_

#include "bsp.h"

void BSP_InitUart_Config(void);
//void ParseCommand_Config(void);
void Uart3WriteBuffer_Config(const uint8_t *pBuffer,uint32_t NumByteToWrite);

#endif /* _BSP_USART_CONFIG_H_ */
