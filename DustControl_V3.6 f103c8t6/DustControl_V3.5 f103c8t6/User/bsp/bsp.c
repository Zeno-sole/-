/* Includes ------------------------------------------------------------------*/
#include "bsp.h"
/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/

//char DEVICE_ID[9];
u8  USART1_RX_BUF[USART_REC_LEN]; //���ջ���,���USART_REC_LEN���ֽ�.ĩ�ֽ�Ϊ���з� 
u16 USART1_RX_STA = 0;         		//����״̬���	
const uint8_t ucSlaveID[] = {0xAA, 0xBB, 0xCC};
uint8_t RegBuffer[REG_HOLDING_NREGS*2];//���ּĴ���Buffer
uint8_t uAddress = 0;
uint16_t uBaudrate = 0;
uint8_t DEVICE_ID=10;
struct AMM avg_X_N;//ȫ������
struct coefficient Cof[3];//ȫ������     PM2.5 PM10 TSP 
struct SensorDataType mySensorDatas;//ȫ������
struct Times times;//ȫ������
static void InitGlobalVariables(void);
//static void Config_Init(void);
static uint16_t getSlaveAddr(void);
static uint16_t getBaudrate(void);
static uint16_t getPM2_5_FA_AND_PM10_FA(void);
static uint16_t getTSP_FA(void);
static uint16_t Get_Deashing_Period(void);
static uint16_t Get_Deashing_Time(void);
void BSP_Init(void)
{
	if (OSRunning > 0u){
		BSP_Tick_Init();
		BSP_IntInit();
		BSP_GPIO_Init();
		BSP_InitUart_Debug();//��ʼ�����Դ���
		BSP_InitUart_Config();//��ʼ�����ô���
		Ping_TIM1Init();
		GENERAL_TIMx_PWM_Init(3000-1,0); //PWMƵ�ʣ�24KHZ
//		REALY_PORT->ODR &= ~(REALY1_PIN);  //����
			REALY_PORT->ODR |=  (REALY1_PIN);	//�պ�
//		Config_Init(); //��ϵͳ����
		uAddress = (uint8_t)getSlaveAddr();
		uBaudrate = getBaudrate();

//		mySensorDatas.PM2_5_factor = (getPM2_5_FA_AND_PM10_FA() & 0x00ff) >> 0;
//		mySensorDatas.PM10_factor =  (getPM2_5_FA_AND_PM10_FA() & 0xff00 ) >> 8;		
		
		eMBInit(MB_RTU, uAddress, 0x01, uBaudrate, MB_PAR_NONE); //��ʼ�� RTUģʽ ��У��  
		eMBSetSlaveID(0x34, TRUE, ucSlaveID, 3); //���ôӻ�ID��
		eMBEnable(); //ʹ��ModbusЭ��ջ
	RS485_RDEN_PORT->ODR |= RS485_RDEN_PIN;//High Send
	printf("Address:%d,Baudrate:%d\r\n", uAddress, uBaudrate);
	printf("PM2_5_factor:%d,PM10_factor:%d\r\n", mySensorDatas.PM2_5_factor, mySensorDatas.PM10_factor);	
	RS485_RDEN_PORT->ODR &= ~(RS485_RDEN_PIN);//Low Rev
	InitGlobalVariables();


	}
}

//ע�⣬��˫�»��ߣ������ǵ��»���  �������ͷ�ļ�
//__FILE__ ������ǰ�����ļ������ַ��� 
//__LINE__  ��ʾ��ǰ�кŵ����� 
//__DATE__ ������ǰ���ڵ��ַ��� 
//__STDC__  �����������ѭANSI C��׼�������Ǹ�����ֵ 
//__TIME__ ������ǰʱ����ַ��� 
//__FUNCTION__ִ�к���


static void InitGlobalVariables(void){

	 u8 conti = 0,contj = 0;
	 u16 s_address = 0X1700;
	 uint16_t *p = 0;
	
	RS485_RDEN_PORT->ODR |= RS485_RDEN_PIN;//High Send

	printf("\r\n%s\r\n%s\r\n%s\r\n%s--%d.\n",__DATE__, __TIME__, __FILE__, __FUNCTION__, __LINE__);
	printf("\n");
	RS485_RDEN_PORT->ODR &= ~(RS485_RDEN_PIN);//Low Rev

	memset(Cof, 0, sizeof(struct coefficient));

	
	avg_X_N.LCD_modetemp = 0;
  memset(&mySensorDatas, 0, sizeof(struct SensorDataType));
	memset(&times, 0, sizeof(struct Times));
	getPM2_5_FA_AND_PM10_FA();
	getTSP_FA();
//	Get_Deashing_Period();
	Get_Deashing_Time();
	RS485_RDEN_PORT->ODR |= RS485_RDEN_PIN;//High Send
	printf("PM2_5_factor:%d,PM10_factor:%d,TSP_factor:%d\r\n", mySensorDatas.PM2_5_factor, mySensorDatas.PM10_factor, mySensorDatas.TSP_factor);	
	printf("Deashing_Period:%d,Deashing_Time:%d\r\n", mySensorDatas.Deashing_Period, mySensorDatas.Deashing_Time);	
	RS485_RDEN_PORT->ODR &= ~(RS485_RDEN_PIN);//Low Rev	
	BSP_OS_TimeDly(500);
	raed_cof0_pm2_5();
	raed_cof1_pm10();
	raed_cof2_tsp();
	read_DEVICE_ID();
	read_SPEED();	
	read_Zero_Calibration();	

	for(conti = 0 ; conti < 3 ; conti++)
	{
		p = &(Cof[conti].num_0_50);
		
		for(contj = 0 ; contj < 7 ; contj++)
		{		
			data_display(s_address,*(p+contj));
			RS485_RDEN_PORT->ODR |= RS485_RDEN_PIN;//High Send
			printf("\n%X , %d\r\n",s_address,*(p+contj));
			RS485_RDEN_PORT->ODR &= ~(RS485_RDEN_PIN);//Low Rev
//			BSP_OS_TimeDly(20);
			s_address += 0X02;
		}
		s_address += 0X100 - 0X0E;
	}
	printf("*************************************\r\n");
	s_address = 0X170F;
		for(conti = 0 ; conti < 3 ; conti++)
	{
		p = &(Cof[conti].num_8000_13000);
		
		for(contj = 0 ; contj < 2 ; contj++)
		{		
			data_display(s_address,*(p+contj));
			RS485_RDEN_PORT->ODR |= RS485_RDEN_PIN;//High Send
			printf("\n%X , %d\r\n",s_address,*(p+contj));
			RS485_RDEN_PORT->ODR &= ~(RS485_RDEN_PIN);//Low Rev
//			BSP_OS_TimeDly(20);
			s_address += 0X03;
		}
		s_address += 0XFA;
	}
	printf("*************************************\r\n");
		s_address = 0X1714;
		for(conti = 0 ; conti < 3 ; conti++)
	{
		p = &(Cof[conti].num_20000_30000);
		
		for(contj = 0 ; contj < 1 ; contj++)
		{		
			data_display(s_address,*(p+contj));
			RS485_RDEN_PORT->ODR |= RS485_RDEN_PIN;//High Send
			printf("\n%X , %d\r\n",s_address,*(p+contj));
			RS485_RDEN_PORT->ODR &= ~(RS485_RDEN_PIN);//Low Rev
//			BSP_OS_TimeDly(20);
			s_address += 0X02;
		}
		s_address += 0X100 - 0X02;
	}
	
	
	
	data_display(0X1032,DEVICE_ID);
	BSP_OS_TimeDly(50);
	data_display(0X1052,mySensorDatas.SPEED);
	BSP_OS_TimeDly(50);	
	data_display(0X1062,mySensorDatas.Deashing_Period);
	BSP_OS_TimeDly(50);	
	
	mySensorDatas.RELAYS = 1;
	mySensorDatas.RELAYSL = 1;
	show_mian();
//	memset(&mySensorDatas, 0, sizeof(struct SensorDataType));
}

/**
  * @brief  �����λ.
  * @param  None.
  * @retval None.
  */
void Soft_Reset(void)
{
  __set_FAULTMASK(1);   /* �ر������ж�*/  
  NVIC_SystemReset();   /* ϵͳ��λ */
}


void FLASH_ReadHalfWord(uint8_t *pBuffer, uint16_t len){
	
	uint16_t i = 0;
	if(len > 511)return;
	while(len--){
		*pBuffer++ = (*(uint16_t*)(FLASH_START_ADDR + WORD_WIDE * i));
		i++;
	}
}

void Flash_WriteHalfWord(const uint8_t *pBuffer, uint16_t len){
	uint16_t timeout = 0;
	uint16_t i = 0;
	FLASH_Status FLASHStatus;
	
	if(len > 511)return;
	
	FLASH_Unlock();/* Flash������������� */
	FLASH_ClearFlag(FLASH_FLAG_BSY | FLASH_FLAG_EOP | FLASH_FLAG_PGERR | FLASH_FLAG_WRPRTERR);/* ������б�� */	
	
	FLASHStatus = FLASH_ErasePage(FLASH_START_ADDR); /*����FLASH */
	while((FLASHStatus != FLASH_COMPLETE) && (timeout++ < 0xffff));//�ȴ��������
	if(FLASHStatus == FLASH_COMPLETE)
	{
		while(len--){
			FLASHStatus = FLASH_ProgramHalfWord((FLASH_START_ADDR + WORD_WIDE * i), *pBuffer++);/* Flash��� */
			i++;
		}	
	}
	FLASH_Lock();  /* �������ݴ洢�� */
}
/*
 * ���� IWDG �ĳ�ʱʱ��
 * Tout = prv/40 * rlv (s)
 *      prv������[4,8,16,32,64,128,256]
 * prv:Ԥ��Ƶ��ֵ��ȡֵ���£�
 *     @arg IWDG_Prescaler_4: IWDG prescaler set to 4
 *     @arg IWDG_Prescaler_8: IWDG prescaler set to 8
 *     @arg IWDG_Prescaler_16: IWDG prescaler set to 16
 *     @arg IWDG_Prescaler_32: IWDG prescaler set to 32
 *     @arg IWDG_Prescaler_64: IWDG prescaler set to 64
 *     @arg IWDG_Prescaler_128: IWDG prescaler set to 128
 *     @arg IWDG_Prescaler_256: IWDG prescaler set to 256
 *
 * rlv:Ԥ��Ƶ��ֵ��ȡֵ��ΧΪ��0-0XFFF
 * �������þ�����
 * IWDG_Config(IWDG_Prescaler_64 ,625);  // IWDG 1s ��ʱ���
 */

void IWDG_Config(uint8_t prv ,uint16_t rlv)
{	
	// ʹ�� Ԥ��Ƶ�Ĵ���PR����װ�ؼĴ���RLR��д
	IWDG_WriteAccessCmd( IWDG_WriteAccess_Enable );
	
	// ����Ԥ��Ƶ��ֵ
	IWDG_SetPrescaler( prv );
	
	// ������װ�ؼĴ���ֵ
	IWDG_SetReload( rlv );
	
	// ����װ�ؼĴ�����ֵ�ŵ���������
	IWDG_ReloadCounter();
	
	// ʹ�� IWDG
	IWDG_Enable();	
}

// ι��
void IWDG_Feed(void)
{
	// ����װ�ؼĴ�����ֵ�ŵ��������У�ι������ֹIWDG��λ
	// ����������ֵ����0��ʱ������ϵͳ��λ
	IWDG_ReloadCounter();
}

/*-------------------------------------------------*/
eMBErrorCode eMBRegInputCB(UCHAR * pucRegBuffer, USHORT usAddress, USHORT usNRegs ){
	eMBErrorCode    eStatus = MB_ENOERR;
	return eStatus;
}
/**
 * @brief  ��ȡ�ӻ���ַ
 * @param  ��
 * @retval ���ص�ַ 0 ~ 255,����0��ַ������
 */
static uint16_t getSlaveAddr(void){
	uint16_t addr = 0;
	addr = ((uint8_t)(*(uint16_t*)(FLASH_START_ADDR + WORD_WIDE * 1)) << 8) | ((uint8_t)(*(uint16_t*)(FLASH_START_ADDR + WORD_WIDE * 0)));
	if(!(addr > 0 && addr < 256)){ //�жϵ�ַ�Ƿ�Ϸ���������Ϸ������ó�Ĭ��ֵ
		addr = DEFAULT_SLAVE_ADDR;
	}
	return addr; 
}

/**
 * @brief  ��ȡ������
 * @param  ��
 * @retval ���ز�����
 */
static uint16_t getBaudrate(void){
	uint16_t bd = 0;
	bd = ((uint8_t)(*(uint16_t*)(FLASH_START_ADDR + WORD_WIDE * 3)) << 8) | ((uint8_t)(*(uint16_t*)(FLASH_START_ADDR + WORD_WIDE * 2)));
	if(!((bd == 2400) || (bd == 4800) || (bd == 9600) || (bd == 19200))){ //�жϵ�ַ�Ƿ�Ϸ���������Ϸ������ó�Ĭ��ֵ
		bd = DEFAULT_BAUD_RATE;
	}
	return bd; 
}
/**
 * @brief  ��ȡpm2.5ϵ��
 * @param  ��
 * @retval ����ϵ��ֵ
 */
static uint16_t getPM2_5_FA_AND_PM10_FA(void){
	uint16_t FA = 0;
	uint8_t FAH=0,FAL=0;
	FA = ((uint8_t)(*(uint16_t*)(FLASH_START_ADDR + WORD_WIDE * 5)) << 8) | ((uint8_t)(*(uint16_t*)(FLASH_START_ADDR + WORD_WIDE * 4)));
	FAH = (FA & 0xff00) >> 8;
	FAL = (FA & 0x00ff) >> 0;
	/*
	RS485_RDEN_PORT->ODR |= RS485_RDEN_PIN;//High Send
	printf("PM2_5_FA_AND_PM10_FA:%#04X,FAH = %#04X,FAL = %#04X\r\n",FA,FAH,FAL);	
	RS485_RDEN_PORT->ODR &= ~(RS485_RDEN_PIN);//Low Rev	
	*/
	if((FAH > 0XFE) || (FAH < 0X01) || (FAL > 0XFE) ||  (FAL < 0X01) ){ //�ж�ϵ���Ƿ�Ϸ���������Ϸ������ó�Ĭ��ֵ
//		FA = 10;
		mySensorDatas.PM2_5_factor = 10;
		mySensorDatas.PM10_factor  = 10;
	}
	else
	{
			mySensorDatas.PM2_5_factor = (FA & 0x00ff) >> 0;
			mySensorDatas.PM10_factor =  (FA & 0xff00) >> 8;		
	
	}
	return FA; 
}
/**
 * @brief  ��ȡtspϵ��
 * @param  ��
 * @retval ����ϵ��ֵ
 */
static uint16_t getTSP_FA(void){
	uint16_t FA = 0;
	uint8_t FAH=0,FAL=0;
	FA = ((uint8_t)(*(uint16_t*)(FLASH_START_ADDR + WORD_WIDE * 7)) << 8) | ((uint8_t)(*(uint16_t*)(FLASH_START_ADDR + WORD_WIDE * 6)));

	FAH = (FA & 0xff00) >> 8;
	FAL = (FA & 0x00ff) >> 0;
	/*
	RS485_RDEN_PORT->ODR |= RS485_RDEN_PIN;//High Send
	printf("TSP_FA:%#04X,FAH = %#04X,FAL = %#04X\r\n",FA,FAH,FAL);	
	RS485_RDEN_PORT->ODR &= ~(RS485_RDEN_PIN);//Low Rev	
	*/
	if((FA > 0XFE ) || (FA < 0X01 )){ //�ж�ϵ���Ƿ�Ϸ���������Ϸ������ó�Ĭ��ֵ
//		FA = 10;
		mySensorDatas.TSP_factor = 10;

	}
	else
	{
			mySensorDatas.TSP_factor = (FA & 0x00ff) >> 0;

	
	}
	return FA; 
}
/**
 * @brief  ��ȡDeashing_Period
 * @param  ��
 * @retval ����ϵ��ֵ
 */
static uint16_t Get_Deashing_Period(void){
	uint16_t FA = 0;
	FA = ((uint8_t)(*(uint16_t*)(FLASH_START_ADDR + WORD_WIDE * 9)) << 8) | ((uint8_t)(*(uint16_t*)(FLASH_START_ADDR + WORD_WIDE * 8)));
	
	RS485_RDEN_PORT->ODR |= RS485_RDEN_PIN;//High Send
	printf("Deashing_Period:%#04X\r\n",FA);	
	RS485_RDEN_PORT->ODR &= ~(RS485_RDEN_PIN);//Low Rev	
	
	if((FA > 24) || (FA < 1)){ //�ж�ϵ���Ƿ�Ϸ���������Ϸ������ó�Ĭ��ֵ
//		FA = 10;
		mySensorDatas.Deashing_Period = 10;

	}
	else
	{
			mySensorDatas.Deashing_Period = FA ;

	
	}
	return FA; 
}
/**
 * @brief  ��ȡDeashing_Time
 * @param  ��
 * @retval ����ϵ��ֵ
 */
static uint16_t Get_Deashing_Time(void){
	uint16_t FA = 0;
	FA = ((uint8_t)(*(uint16_t*)(FLASH_START_ADDR + WORD_WIDE * 11)) << 8) | ((uint8_t)(*(uint16_t*)(FLASH_START_ADDR + WORD_WIDE * 10)));
	RS485_RDEN_PORT->ODR |= RS485_RDEN_PIN;//High Send
	printf("Deashing_Time:%#04X\r\n",FA);	
	RS485_RDEN_PORT->ODR &= ~(RS485_RDEN_PIN);//Low Rev	
	if(FA > 300){ //�ж�ϵ���Ƿ�Ϸ���������Ϸ������ó�Ĭ��ֵ
//		FA = 10;
		mySensorDatas.Deashing_Time = 60;

	}
	else
	{
			mySensorDatas.Deashing_Time = FA ;

	
	}
	return FA; 
}
/**
  * @brief  ���ּĴ��������������ּĴ����ɶ����ɶ���д
  * @param  pucRegBuffer  ������ʱ--��������ָ�룬д����ʱ--��������ָ��
  *         usAddress     �Ĵ�����ʼ��ַ
  *         usNRegs       �Ĵ�������
  *         eMode         ������ʽ��������д
  * @retval eStatus       �Ĵ���״̬
  */
eMBErrorCode eMBRegHoldingCB( UCHAR * pucRegBuffer, USHORT usAddress, USHORT usNRegs, eMBRegisterMode eMode ){

	//����״̬
	eMBErrorCode    eStatus = MB_ENOERR;
	//ƫ����
	uint16_t iRegIndex = (uint16_t)usAddress;
	uint16_t timeout = 0;
	FLASH_Status FLASHStatus;
	//�жϼĴ����ǲ����ڷ�Χ��
	if( ((int16_t)usAddress >= REG_HOLDING_START ) && ( usAddress + usNRegs <= REG_HOLDING_START + REG_HOLDING_NREGS )){
		
		switch ( eMode ){
			//��������  
			case MB_REG_READ:
				
				RegBuffer[6] = (*(uint16_t*)(FLASH_START_ADDR + WORD_WIDE * 0));
				RegBuffer[7] = (*(uint16_t*)(FLASH_START_ADDR + WORD_WIDE * 1));
				RegBuffer[8] = (*(uint16_t*)(FLASH_START_ADDR + WORD_WIDE * 2));
				RegBuffer[9] = (*(uint16_t*)(FLASH_START_ADDR + WORD_WIDE * 3));
				RegBuffer[10] = (*(uint16_t*)(FLASH_START_ADDR + WORD_WIDE * 4));		
				RegBuffer[11] = (*(uint16_t*)(FLASH_START_ADDR + WORD_WIDE * 5));			
				RegBuffer[12] = (*(uint16_t*)(FLASH_START_ADDR + WORD_WIDE * 6));		
				RegBuffer[13] = (*(uint16_t*)(FLASH_START_ADDR + WORD_WIDE * 7));		
				RegBuffer[14] = (*(uint16_t*)(FLASH_START_ADDR + WORD_WIDE * 8));
				RegBuffer[15] = (*(uint16_t*)(FLASH_START_ADDR + WORD_WIDE * 9));		
				RegBuffer[16] = (*(uint16_t*)(FLASH_START_ADDR + WORD_WIDE * 10));		
				RegBuffer[17] = (*(uint16_t*)(FLASH_START_ADDR + WORD_WIDE * 11));				
				while(usNRegs--){
					*pucRegBuffer++ = RegBuffer[iRegIndex*2+1];
					*pucRegBuffer++ = RegBuffer[iRegIndex*2+0];
					iRegIndex++;
				}
			break;

			//д������ 
			case MB_REG_WRITE:
				//д֮ǰ����������ȶ�����
				RegBuffer[6] = (*(uint16_t*)(FLASH_START_ADDR + WORD_WIDE * 0));
				RegBuffer[7] = (*(uint16_t*)(FLASH_START_ADDR + WORD_WIDE * 1));
				RegBuffer[8] = (*(uint16_t*)(FLASH_START_ADDR + WORD_WIDE * 2));
				RegBuffer[9] = (*(uint16_t*)(FLASH_START_ADDR + WORD_WIDE * 3));
				RegBuffer[10] = (*(uint16_t*)(FLASH_START_ADDR + WORD_WIDE * 4));		
				RegBuffer[11] = (*(uint16_t*)(FLASH_START_ADDR + WORD_WIDE * 5));		
				RegBuffer[12] = (*(uint16_t*)(FLASH_START_ADDR + WORD_WIDE * 6));		
				RegBuffer[13] = (*(uint16_t*)(FLASH_START_ADDR + WORD_WIDE * 7));		
				RegBuffer[14] = (*(uint16_t*)(FLASH_START_ADDR + WORD_WIDE * 8));
				RegBuffer[15] = (*(uint16_t*)(FLASH_START_ADDR + WORD_WIDE * 9));		
				RegBuffer[16] = (*(uint16_t*)(FLASH_START_ADDR + WORD_WIDE * 10));		
				RegBuffer[17] = (*(uint16_t*)(FLASH_START_ADDR + WORD_WIDE * 11));				
				while(usNRegs--){
					RegBuffer[iRegIndex*2+1] = *pucRegBuffer++;
					RegBuffer[iRegIndex*2+0] = *pucRegBuffer++;
					iRegIndex++;
				}
				
				FLASH_Unlock();/* Flash������������� */
				
				FLASH_ClearFlag(FLASH_FLAG_BSY | FLASH_FLAG_EOP | FLASH_FLAG_PGERR | FLASH_FLAG_WRPRTERR);/* ������б�� */	
				
				FLASHStatus = FLASH_ErasePage(FLASH_START_ADDR); /*����FLASH */
				while((FLASHStatus != FLASH_COMPLETE) && (timeout++ < 0xffff));//�ȴ��������
				
				FLASHStatus = FLASH_ProgramHalfWord((FLASH_START_ADDR + WORD_WIDE * 0), RegBuffer[6]);/* Flash��� */
				while((FLASHStatus != FLASH_COMPLETE) && (timeout++ < 0xffff));//�ȴ�������
				
				FLASHStatus = FLASH_ProgramHalfWord((FLASH_START_ADDR + WORD_WIDE * 1), RegBuffer[7]);/* Flash��� */
				while((FLASHStatus != FLASH_COMPLETE) && (timeout++ < 0xffff));//�ȴ�������
				
				FLASHStatus = FLASH_ProgramHalfWord((FLASH_START_ADDR + WORD_WIDE * 2), RegBuffer[8]);/* Flash��� */
				while((FLASHStatus != FLASH_COMPLETE) && (timeout++ < 0xffff));//�ȴ�������
				
				FLASHStatus = FLASH_ProgramHalfWord((FLASH_START_ADDR + WORD_WIDE * 3), RegBuffer[9]);/* Flash��� */
				while((FLASHStatus != FLASH_COMPLETE) && (timeout++ < 0xffff));//�ȴ�������
				
				FLASHStatus = FLASH_ProgramHalfWord((FLASH_START_ADDR + WORD_WIDE * 4), RegBuffer[10]);/* Flash��� */
				while((FLASHStatus != FLASH_COMPLETE) && (timeout++ < 0xffff));//�ȴ�������				

				FLASHStatus = FLASH_ProgramHalfWord((FLASH_START_ADDR + WORD_WIDE * 5), RegBuffer[11]);/* Flash��� */
				while((FLASHStatus != FLASH_COMPLETE) && (timeout++ < 0xffff));//�ȴ�������			
				
				FLASHStatus = FLASH_ProgramHalfWord((FLASH_START_ADDR + WORD_WIDE * 6), RegBuffer[12]);/* Flash��� */
				while((FLASHStatus != FLASH_COMPLETE) && (timeout++ < 0xffff));//�ȴ�������				

				FLASHStatus = FLASH_ProgramHalfWord((FLASH_START_ADDR + WORD_WIDE * 7), RegBuffer[13]);/* Flash��� */
				while((FLASHStatus != FLASH_COMPLETE) && (timeout++ < 0xffff));//�ȴ�������		
				
				FLASHStatus = FLASH_ProgramHalfWord((FLASH_START_ADDR + WORD_WIDE * 8), RegBuffer[14]);/* Flash��� */
				while((FLASHStatus != FLASH_COMPLETE) && (timeout++ < 0xffff));//�ȴ�������						
				
				FLASHStatus = FLASH_ProgramHalfWord((FLASH_START_ADDR + WORD_WIDE * 9), RegBuffer[15]);/* Flash��� */
				while((FLASHStatus != FLASH_COMPLETE) && (timeout++ < 0xffff));//�ȴ�������		

				FLASHStatus = FLASH_ProgramHalfWord((FLASH_START_ADDR + WORD_WIDE * 10), RegBuffer[16]);/* Flash��� */
				while((FLASHStatus != FLASH_COMPLETE) && (timeout++ < 0xffff));//�ȴ�������		
				
				FLASHStatus = FLASH_ProgramHalfWord((FLASH_START_ADDR + WORD_WIDE * 11), RegBuffer[17]);/* Flash��� */
				while((FLASHStatus != FLASH_COMPLETE) && (timeout++ < 0xffff));//�ȴ�������	
				
				FLASH_Lock();  /* �������ݴ洢�� */

			break;
		}
	}else{
		//���ش���״̬
		eStatus = MB_ENOREG;
	}

  return eStatus;
}

eMBErrorCode eMBRegCoilsCB( UCHAR * pucRegBuffer, USHORT usAddress, USHORT usNCoils, eMBRegisterMode eMode){

	//����״̬
	eMBErrorCode    eStatus = MB_ENOERR;
	return eStatus;
}

eMBErrorCode eMBRegDiscreteCB( UCHAR * pucRegBuffer, USHORT usAddress, USHORT usNDiscrete ){
	//����״̬
	eMBErrorCode    eStatus = MB_ENOERR;
	return eStatus;
}
void ParsePM25Command_CUBIC(void){
	u8 get_data[]={0x11,0x02,0x0b,0x07,0xdb};
	u8 get_start[] ={0x16,0x35,0x0b};
//	uint8_t PM10[20]={20,10,15,16,18,18,17,15,20,21,22,23,24,25,26,27,28,29,30,34};	
	Open_Measurement();
	CLR_Buf1();
	Uart1WriteBuffer_Config(get_data,strlen((char *)get_data));
	BSP_OS_TimeDly(500);	
	if(Find_usart1((char *)get_start)){

			
//			mySensorDatas.PM2_5 = (USART1_RX_BUF[7] << 24) | (USART1_RX_BUF[8] << 16) | (USART1_RX_BUF[9] << 8) | USART1_RX_BUF[10];//PM2.5
//		
//			mySensorDatas.PM10  = (USART1_RX_BUF[11] << 24) | (USART1_RX_BUF[12] << 16) | (USART1_RX_BUF[13] << 8) | USART1_RX_BUF[14];//PM10		
//		
//			mySensorDatas.TSP  = (USART1_RX_BUF[15] << 24) | (USART1_RX_BUF[16] << 16) | (USART1_RX_BUF[17] << 8) | USART1_RX_BUF[18];//PM10		
		
			mySensorDatas.PM2_5 =  (USART1_RX_BUF[9]  << 8) | USART1_RX_BUF[10];//PM2.5
		
			mySensorDatas.PM10  =  (USART1_RX_BUF[13] << 8) | USART1_RX_BUF[14];//PM10		
		
			mySensorDatas.TSP  =   (USART1_RX_BUF[17] << 8) | USART1_RX_BUF[18];//PM10				
		
			mySensorDatas.PM2_5 = (mySensorDatas.PM2_5 * mySensorDatas.PM2_5_factor) / 10;
			mySensorDatas.PM10  = (mySensorDatas.PM10 * mySensorDatas.PM10_factor) / 10;
			mySensorDatas.TSP  = (mySensorDatas.TSP * mySensorDatas.TSP_factor) / 10;		

		
//			mySensorDatas.TSP   = ((mySensorDatas.PM10) * 12)/10;//TSP
			data_correction_PM2_5();
			data_correction_PM10();
			data_correction_TSP();
		
		RegBuffer[0] = (mySensorDatas.PM2_5 & 0x00ff) >> 0;
		RegBuffer[1] = (mySensorDatas.PM2_5 & 0xff00) >> 8;
		
		RegBuffer[2] = (mySensorDatas.PM10 & 0x00ff) >> 0;
		RegBuffer[3] = (mySensorDatas.PM10 & 0xff00) >> 8;

		RegBuffer[4] = (mySensorDatas.TSP & 0x00ff) >> 0;
		RegBuffer[5] = (mySensorDatas.TSP & 0xff00) >> 8;
		
		
//			RS485_RDEN_PORT->ODR |= RS485_RDEN_PIN;//High Send
//			printf("PM2_5 = %d\r\n",mySensorDatas.PM2_5);
//			printf("PM10 = %d\r\n",mySensorDatas.PM10);
//			printf("TSP = %d\r\n",mySensorDatas.TSP);
//			RS485_RDEN_PORT->ODR &= ~(RS485_RDEN_PIN);//Low Rev

		
			CLR_Buf1();

		}
			else{
			
//			mySensorDatas.PM10  =	PM10[rand()%(20)];

		}


}
/*-------------------------------------------------*/
/*����������ʱ��1��ʼ�� 10s                        */
/*��  ������                                       */
/*����ֵ����                                       */
/*-------------------------------------------------*/
void Ping_TIM1Init(void)
{
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStructure;
	NVIC_InitTypeDef NVIC_InitStructure;

	TIM_Cmd(TIM1,DISABLE);                                        //�ض�ʱ��1
	TIM_SetCounter(TIM1, 0);
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM1,ENABLE);           //ʹ��TIM1ʱ��	
//	 TIM_TimeBaseInitStructure.TIM_Period = 24000-1; 	          //�Զ���װ��ֵ
//	TIM_TimeBaseInitStructure.TIM_Prescaler=36000-1;              //��ʱ����Ƶ
	
  TIM_TimeBaseInitStructure.TIM_Period = 800-1; 	              //�Զ���װ��ֵ   ��Լ10��
	TIM_TimeBaseInitStructure.TIM_Prescaler=7200-1;               //��ʱ����Ƶ
	
	TIM_TimeBaseInitStructure.TIM_CounterMode=TIM_CounterMode_Up; //���ϼ���ģʽ
	TIM_TimeBaseInitStructure.TIM_ClockDivision=TIM_CKD_DIV1;     //1��Ƶ
	TIM_TimeBaseInit(TIM1,&TIM_TimeBaseInitStructure);            //����������TIM1	
		
   TIM_ClearITPendingBit(TIM1,TIM_IT_Update);                    //����жϱ�־λ
	TIM_ITConfig(TIM1,TIM_IT_Update,ENABLE);                      //����ʱ��1�����ж�
	TIM_Cmd(TIM1,ENABLE);                                         //����ʱ��1  
	
	NVIC_InitStructure.NVIC_IRQChannel=TIM1_UP_IRQn;              //��ʱ��1�ж�
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=2;       //��ռ���ȼ�1
	NVIC_InitStructure.NVIC_IRQChannelSubPriority=0;              //�����ȼ�0
	NVIC_InitStructure.NVIC_IRQChannelCmd=ENABLE;                 //ʹ���ж�
	NVIC_Init(&NVIC_InitStructure);                               //���������� 	
	
}
void data_correction_PM2_5(void)
{
 
 
  if(mySensorDatas.PM2_5<=30)
	{

				mySensorDatas.PM2_5 =  (mySensorDatas.PM2_5 *  Cof[0].num_0_50) / COEFFICIENT;
	}
	else if((mySensorDatas.PM2_5>30)&(mySensorDatas.PM2_5<=60))
	{

				mySensorDatas.PM2_5 =  (mySensorDatas.PM2_5 *  Cof[0].num_50_100) / COEFFICIENT;

	}
	else if((mySensorDatas.PM2_5>60)&(mySensorDatas.PM2_5<=80))
	{
	
				mySensorDatas.PM2_5 =  (mySensorDatas.PM2_5 * Cof[0].num_100_500)/ COEFFICIENT;
	}
	else if((mySensorDatas.PM2_5>80)&(mySensorDatas.PM2_5<=100))
	{
	
				mySensorDatas.PM2_5 =  (mySensorDatas.PM2_5 * Cof[0].num_500_1000)/ COEFFICIENT;
	}
		else if((mySensorDatas.PM2_5>100)&(mySensorDatas.PM2_5<=120))
	{
	
				mySensorDatas.PM2_5 =  (mySensorDatas.PM2_5 * Cof[0].num_1000_1500)/ COEFFICIENT;
	}
		else if((mySensorDatas.PM2_5>120)&(mySensorDatas.PM2_5<=150))
	{
	
				mySensorDatas.PM2_5 =  (mySensorDatas.PM2_5 * Cof[0].num_1500_3000)/ COEFFICIENT;
	}
		else if((mySensorDatas.PM2_5>150)&(mySensorDatas.PM2_5<=200))
	{
	
				mySensorDatas.PM2_5 =  (mySensorDatas.PM2_5 * Cof[0].num_3000_8000)/ COEFFICIENT;
	}
		else if((mySensorDatas.PM2_5>200)&(mySensorDatas.PM2_5<=250))
	{
	
				mySensorDatas.PM2_5 =  (mySensorDatas.PM2_5 * Cof[0].num_8000_13000)/ COEFFICIENT;
	}
			else if((mySensorDatas.PM2_5>250)&(mySensorDatas.PM2_5<=400))
	{
	
				mySensorDatas.PM2_5 =  (mySensorDatas.PM2_5 * Cof[0].num_13000_20000)/ COEFFICIENT;
	}
				else if((mySensorDatas.PM2_5>400)&(mySensorDatas.PM2_5<=1000))
	{
	
				mySensorDatas.PM2_5 =  (mySensorDatas.PM2_5 * Cof[0].num_20000_30000)/ COEFFICIENT;
	}
}

void data_correction_PM10(void)
{
	   if(mySensorDatas.PM10<=30)
	{

				mySensorDatas.PM10 =  (mySensorDatas.PM10 *  Cof[1].num_0_50)/ COEFFICIENT;
	}
	else if((mySensorDatas.PM10>30)&(mySensorDatas.PM10<=60))
	{

				mySensorDatas.PM10 =  (mySensorDatas.PM10 *  Cof[1].num_50_100) / COEFFICIENT;

	}
	else if((mySensorDatas.PM10>60)&(mySensorDatas.PM10<=80))
	{
	
				mySensorDatas.PM10 =  (mySensorDatas.PM10 * Cof[1].num_100_500)/ COEFFICIENT;
	}
	else if((mySensorDatas.PM10>80)&(mySensorDatas.PM10<=100))
	{
	
				mySensorDatas.PM10 =  (mySensorDatas.PM10 * Cof[1].num_500_1000)/ COEFFICIENT;
	}
		else if((mySensorDatas.PM10>100)&(mySensorDatas.PM10<=120))
	{
	
				mySensorDatas.PM10 =  (mySensorDatas.PM10 * Cof[1].num_1000_1500)/ COEFFICIENT;
	}
		else if((mySensorDatas.PM10>120)&(mySensorDatas.PM10<=150))
	{
	
				mySensorDatas.PM10 =  (mySensorDatas.PM10 * Cof[1].num_1500_3000)/ COEFFICIENT;
	}
		else if((mySensorDatas.PM10>150)&(mySensorDatas.PM10<=200))
	{
	
				mySensorDatas.PM10 =  (mySensorDatas.PM10 * Cof[1].num_3000_8000)/ COEFFICIENT;
	}
		else if((mySensorDatas.PM10>200)&(mySensorDatas.PM10<=250))
	{
	
				mySensorDatas.PM10 =  (mySensorDatas.PM10 * Cof[1].num_8000_13000)/ COEFFICIENT;
	}
			else if((mySensorDatas.PM10>250)&(mySensorDatas.PM10<=400))
	{
	
				mySensorDatas.PM10 =  (mySensorDatas.PM10 * Cof[1].num_13000_20000)/ COEFFICIENT;
	}
				else if((mySensorDatas.PM10>400)&(mySensorDatas.PM10<=1000))
	{
	
				mySensorDatas.PM10 =  (mySensorDatas.PM10 * Cof[1].num_20000_30000)/ COEFFICIENT;
	}
	
}
void data_correction_TSP(void)
{
	   if(mySensorDatas.TSP<=30)
	{

				mySensorDatas.TSP =  (mySensorDatas.TSP *  Cof[2].num_0_50)/ COEFFICIENT;
	}
	else if((mySensorDatas.TSP>30)&(mySensorDatas.TSP<=60))
	{

				mySensorDatas.TSP =  (mySensorDatas.TSP *  Cof[2].num_50_100) / COEFFICIENT;

	}
	else if((mySensorDatas.TSP>60)&(mySensorDatas.TSP<=80))
	{
	
				mySensorDatas.TSP =  (mySensorDatas.TSP * Cof[2].num_100_500)/ COEFFICIENT;
	}
	else if((mySensorDatas.TSP>80)&(mySensorDatas.TSP<=100))
	{
	
				mySensorDatas.TSP =  (mySensorDatas.TSP * Cof[2].num_500_1000)/ COEFFICIENT;
	}
		else if((mySensorDatas.TSP>100)&(mySensorDatas.TSP<=120))
	{
	
				mySensorDatas.TSP =  (mySensorDatas.TSP * Cof[2].num_1000_1500)/ COEFFICIENT;
	}
		else if((mySensorDatas.TSP>120)&(mySensorDatas.TSP<=150))
	{
	
				mySensorDatas.TSP =  (mySensorDatas.TSP * Cof[2].num_1500_3000)/ COEFFICIENT ;
	}
		else if((mySensorDatas.TSP>150)&(mySensorDatas.TSP<=200))
	{
	
				mySensorDatas.TSP =  (mySensorDatas.TSP * Cof[2].num_3000_8000)/ COEFFICIENT;
	}
		else if((mySensorDatas.TSP>200)&(mySensorDatas.TSP<=250))
	{
	
				mySensorDatas.TSP =  (mySensorDatas.TSP * Cof[2].num_8000_13000)/ COEFFICIENT;
	}
			else if((mySensorDatas.TSP>250)&(mySensorDatas.TSP<=400))
	{
	
				mySensorDatas.TSP =  (mySensorDatas.TSP * Cof[2].num_13000_20000)/ COEFFICIENT;
	}
				else if((mySensorDatas.TSP>400)&(mySensorDatas.TSP<=1000))
	{
	
				mySensorDatas.TSP =  (mySensorDatas.TSP * Cof[2].num_20000_30000)/ COEFFICIENT;
	}
	
}