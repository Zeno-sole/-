#ifndef __BSP_H
#define __BSP_H

#include "stm32f10x.h"
#include <math.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>

#include "opt.h"
#include "stmflash.h"
#include "DWIN.h" 
/*--------------------------------- uCOS-III -------------------------------------------*/
#include "os.h"
#include "cpu.h"
#include "app_cfg.h"
#include "os_app_hooks.h"
#include "cpu_core.h"
#include "bsp_os.h" //�����ṩ�弶��ʱ����
#include "bsp_int.h" //�жϳ�ʼ��,�ṩϵͳʱ��
/* ------------------------- BSP includes ---------------------------------*/
#include "bsp_debug.h"
#include "bsp_gpio.h"
#include "bsp_debug_usart.h"
#include "bsp_config_usart.h"
#include "pwm.h"
/* ----------------------- Modbus includes --------------------------------*/
#include "mb.h"
#include "mbport.h"
#include "mbutils.h"
/*-------------------------------------------------------------------------*/
#define USART2_NVIC_PRIORITY                      0
#define USART4_NVIC_PRIORITY                      1
#define USART3_NVIC_PRIORITY                      2
/*------------------------------------------------------------------------------*/
#define FLASH_SIZE                           64    //64K(STM32F103C8T6)
#define FLASH_PAGE_SIZE                      ((uint16_t)0x400) //����ҳ��СΪ1024Byte
#define FLASH_BASE_ADDR     	               ((uint32_t)0x08000000)
#define WORD_WIDE                             2  //��д���ݿ��16λ
#define FLASH_START_ADDR                     (uint32_t)(FLASH_BASE_ADDR+((FLASH_SIZE-1)*FLASH_PAGE_SIZE)) //STM32F103C8T6(64 Kbytes of Flash memory)��ַ��Χ0x08000000~0x0800FFFF, �������1024�ֽ�����EEPROM�洢
#define USART_REC_LEN  			64  	//�����������ֽ��� 200
/*-------------------------------------------------------------*/
//���ּĴ�����ʼ��ַ
#define REG_HOLDING_START     0x0000
//���ּĴ�������
//#define REG_HOLDING_NREGS     4 //(�¶���������8bit,�¶�С������8bit,ʪ����������8bit,ʪ��С������8bit,�豸��ַ16bit,������16bit)
#define REG_HOLDING_NREGS     9 //(�¶���������8bit,�¶�С������8bit,ʪ����������8bit,ʪ��С������8bit,�豸��ַ16bit,������16bit,����)
/*-------------------------------------------------------------*/
#define DEFAULT_SLAVE_ADDR    5    //�ӻ���ַ
#define DEFAULT_BAUD_RATE     9600
/*-------------------------------------------------------------------------*/
#define FLASH_MN_ADDR           						 ((uint32_t)0x0800FFFF)
#define FLASH_KEY_ADDR           						 ((uint32_t)0x08090900)
#define FLASH_DEVICE_ID_ADDR           			 ((uint32_t)0x0800F000)
#define FLASH_PASSWORD_ADDR           			 ((uint32_t)0x080C0000)
#define FLASH_SAMPLING_ADDR           			 ((uint32_t)0x080B0000)
#define FLASH_COF0_PM2_5          			     ((uint32_t)0x0800C000)
#define FLASH_COF1_PM10          			       ((uint32_t)0x0800B000)
#define FLASH_COF2_TSP          			       ((uint32_t)0x0800A000)
#define FLASH_SPEED          			      		 ((uint32_t)0x0800D000)
#define FLASH_ZERO_CALIBRATION          		 ((uint32_t)0x0800E000)
#define COEFFICIENT									(100)

/*-------------------------------------------------------------------------*/
struct SensorDataType {
	uint16_t PM2_5;
	uint16_t PM10;
	uint16_t TSP;
	uint8_t  PM2_5_factor;
	uint8_t  PM10_factor;	
	uint8_t  TSP_factor;		
	uint16_t  Deashing_Period;   //�������
	uint16_t  Deashing_Time;   //���ʱ��	
	uint16_t  SPEED;   //���ʱ��	
	
	uint8_t RELAYS;
	uint8_t RELAYSL;	
};
extern struct SensorDataType mySensorDatas;//ȫ������
struct Times {
	uint16_t MINUTE;   //��
	uint16_t HOUR;    //ʱ
};
extern struct Times times;//ȫ������
struct AMM {

	uint8_t   LCD_modetemp;   //״̬��ģʽ��־

	
};
extern struct AMM avg_X_N;//ȫ������
struct coefficient {
	uint16_t num_0_50;
	uint16_t num_50_100;
	uint16_t num_100_500;
	uint16_t num_500_1000;
	uint16_t num_1000_1500;
	uint16_t num_1500_3000;
	uint16_t num_3000_8000;
	uint16_t num_8000_13000;
	uint16_t num_13000_20000;
	uint16_t num_20000_30000;
}; 
extern struct coefficient Cof[3];//ȫ������     PM2.5 PM10 TSP 

extern u8  USART6_RX_BUF[USART_REC_LEN]; //���ջ���,���USART_REC_LEN���ֽ�.ĩ�ֽ�Ϊ���з� 
extern u16 USART6_RX_STA;         		//����״̬���	
extern u8  USART1_RX_BUF[USART_REC_LEN]; //���ջ���,���USART_REC_LEN���ֽ�.ĩ�ֽ�Ϊ���з� 
extern u16 USART1_RX_STA;         		//����״̬���	
extern u16 Air_STATU;         		//����״̬���	
extern u8 uart_buffValid;
extern u8 DEVICE_ID;
//extern char DEVICE_ID[9];
/*-------------------------- ȫ�ֺ������� ------------------------------------*/
void BSP_Init(void);
void Soft_Reset(void);

void FLASH_ReadHalfWord(uint8_t *pBuffer, uint16_t len);
void Flash_WriteHalfWord(const uint8_t *pBuffer, uint16_t len);
void IWDG_Feed(void);
void IWDG_Config(uint8_t prv ,uint16_t rlv);
void Ping_TIM1Init(void);
void data_correction_PM2_5(void);
void data_correction_PM10(void);
void data_correction_TSP(void);
/*----------------------------------------------------------------------------*/
#endif  /*__BSP_H*/
