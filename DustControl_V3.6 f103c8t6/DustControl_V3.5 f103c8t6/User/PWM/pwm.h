#ifndef __PWM_H
#define __PWM_H
#include  "bsp.h"

/********************通用定时器TIM参数定义，只限TIM2 & TIM3 & TIM4 & TIM5************/
#define GENERAL_TIMx                        TIM3
#define GENERAL_TIM_APBxClock_FUN           RCC_APB1PeriphClockCmd
#define GENERAL_TIM_CLK                     RCC_APB1Periph_TIM3
#define GENERAL_TIM_GPIO_APBxClock_FUN      RCC_APB2PeriphClockCmd
#define GENERAL_TIM_GPIO_CLK                (RCC_APB2Periph_GPIOA |RCC_APB2Periph_GPIOB| RCC_APB2Periph_AFIO )

#define GENERAL_TIM_CH1_PORT                GPIOA         // YS-F1Pro开发板预留连接舵机的接口
#define GENERAL_TIM_CH1_PIN                 GPIO_Pin_7   // YS-F1Pro开发板预留连接舵机的接口

#define GENERAL_TIM_CH2_PORT                GPIOB         // 这些引脚也可以使用，但必须注意接线
#define GENERAL_TIM_CH2_PIN                 GPIO_Pin_3    // 这些引脚也可以使用，但必须注意接线
#define GENERAL_TIM_CH3_PORT                GPIOB         // 这些引脚也可以使用，但必须注意接线
#define GENERAL_TIM_CH3_PIN                 GPIO_Pin_10   // 这些引脚也可以使用，但必须注意接线
#define GENERAL_TIM_CH4_PORT                GPIOB         // 这些引脚也可以使用，但必须注意接线
#define GENERAL_TIM_CH4_PIN                 GPIO_Pin_11   // 这些引脚也可以使用，但必须注意接线


/* 扩展变量 ------------------------------------------------------------------*/
/* 函数声明 ------------------------------------------------------------------*/
void GENERAL_TIMx_PWM_Init(u16 arr,u16 psc);

#endif
