#ifndef  BSP_GPIO_
#define  BSP_GPIO_

#include "stm32f10x.h"

/*---------------------------- Relay define --------------------------*/
#define REALY1_PIN                 (uint16_t)GPIO_Pin_6      //抽气
#define REALY2_PIN                 (uint16_t)GPIO_Pin_7     //加热
#define REALY3_PIN                 (uint16_t)GPIO_Pin_5     //清灰
#define REALY_PORT                  GPIOB
/*---------------------------- LED define ----------------------------*/
#define LED_LINK_PIN              (uint16_t)GPIO_Pin_8
#define LED_NETOK_PIN               (uint16_t)GPIO_Pin_11
#define LED_PORT                   GPIOA
/*---------------------------- RS485 RDEN define --------------------------*/
#define RS485_RDEN_PIN                 (uint16_t)GPIO_Pin_4
#define RS485_RDEN_PORT                 GPIOA
/*-------------------------- GPRS PWR define -------------------------*/
#define GPRS_PWR_PIN              (uint16_t)GPIO_Pin_7
#define GPRS_PWR_PORT              GPIOA
/*------------------------------------------------------------------------*/

void BSP_GPIO_Init(void);

#endif /* BSP_GPIO_ */

