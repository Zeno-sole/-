#include "DWIN.h" 
u8	temp_00[10]={0X5A,0XA5,0X07,0X82,0X00,0X84,0X5A,0X01,0X00,0X00}; //屏幕切换指令
u8	temp_02[10]={0X5A,0XA5,0X07,0X82,0X00,0X84,0X5A,0X01,0X00,0X02}; //屏幕切换指令
u8	temp_03[10]={0X5A,0XA5,0X07,0X82,0X00,0X84,0X5A,0X01,0X00,0X03}; //屏幕切换指令
u8	temp_01[10]={0X5A,0XA5,0X07,0X82,0X00,0X84,0X5A,0X01,0X00,0X01}; //屏幕切换指令
u8	temp_04[10]={0X5A,0XA5,0X07,0X82,0X00,0X84,0X5A,0X01,0X00,0X04}; //屏幕切换指令
u8	temp_05[10]={0X5A,0XA5,0X07,0X82,0X00,0X84,0X5A,0X01,0X00,0X05}; //屏幕切换指令
u8	temp_06[10]={0X5A,0XA5,0X07,0X82,0X00,0X84,0X5A,0X01,0X00,0X06}; //屏幕切换指令
u8	temp_07[10]={0X5A,0XA5,0X07,0X82,0X00,0X84,0X5A,0X01,0X00,0X07}; //屏幕切换指令
//u8	temp_14[10]={0X5A,0XA5,0X07,0X82,0X00,0X84,0X5A,0X01,0X00,0X0E}; //屏幕切换指令
//u8	temp_15[10]={0X5A,0XA5,0X07,0X82,0X00,0X84,0X5A,0X01,0X00,0X0F}; //屏幕切换指令
//u8	temp_16[10]={0X5A,0XA5,0X07,0X82,0X00,0X84,0X5A,0X01,0X00,0X10}; //屏幕切换指令
//u8	temp_17[10]={0X5A,0XA5,0X07,0X82,0X00,0X84,0X5A,0X01,0X00,0X11}; //屏幕切换指令
//u8	temp_20[10]={0X5A,0XA5,0X07,0X82,0X00,0X84,0X5A,0X01,0X00,0X14}; //屏幕切换指令
//u8	temp_21[10]={0X5A,0XA5,0X07,0X82,0X00,0X84,0X5A,0X01,0X00,0X15}; //屏幕切换指令
//u8	USART_send_GBK_ID[22]={0x5a,0xa5,0x13,0x82,0x16,0x0C,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0X00,0X00,0X00,0X00,0X00,0X00};
//u8	USART_send_GBK_PAS[22]={0x5a,0xa5,0x13,0x82,0x46,0x0C,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0X00,0X00,0X00,0X00,0X00,0X00};	
u8 falsh_temp[8]={11,12,13,14,15,16,17,18};
u16 falsh_DEVICE_ID[2];	//write flash 缓存数组
u16 falsh_threshold[4] = {0};
u16 temp[10] = {0};
//u16 temp_threshold[4] = {0};
//u16 falsh_SAMPLING[4] = {0};  u16 falsh_sampling[4] = {0};  
  /*
 * 函数名：RTC_time
 * 描述  ：获取时间参数   
 * 输入  ：
 *         
 *        
 *         
 * 输出  ：无
 * 返回  ：无
 * 调用  ：
 */
 void RTC_time(void)
{
	/*
		u8  i=0;
		u16 times = 10;
		char temp[50] = {0};
		sprintf(temp, "AT+CCLK?\r\n");
		UartWriteBuffer_Config((u8 *)temp,strlen(temp));
			while(times--)
		{
			if(Find_usart4("+CCLK:"))
			{
					i = StringFind((char *)USART_RX_BUF4,(const char *)"+CCLK:");
					mytime.year = (USART_RX_BUF4[i+8] - '0') * 10 +  (USART_RX_BUF4[i+9] - '0');
					mytime.month = (USART_RX_BUF4[i+11] - '0') * 10 +  (USART_RX_BUF4[i+12] - '0');
					mytime.day = (USART_RX_BUF4[i+14] - '0') * 10 +  (USART_RX_BUF4[i+15] - '0');
					mytime.hour = (USART_RX_BUF4[i+17] - '0') * 10 +  (USART_RX_BUF4[i+18] - '0');
					mytime.minute = (USART_RX_BUF4[i+20] - '0') * 10 +  (USART_RX_BUF4[i+21] - '0');
					mytime.second = (USART_RX_BUF4[i+23] - '0') * 10 +  (USART_RX_BUF4[i+24] - '0');
					CLR_Buf4();
					break;				

			}
			
//			BSP_OS_TimeDly(500);
		}
//		Air720D_GetTime();
		*/
}
 /*
 * 函数名：data_display_network_state
 * 描述  ：网络状态显示   
 * 输入  ：state 0离线 1在线
 *         
 *        
 *         
 * 输出  ：无
 * 返回  ：无
 * 调用  ：
 */
//0x5a,0xa5,0x13,0x82,0x16,0x0C,0xD0,0xDE,0xB8,0xC4,0xB3,0xC9,0xB9,0xA6,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
void data_display_network_state(u8 state)
{
u8	USART_send_off_line[10] ={0x5a,0xa5,0x07,0x82,0xA7,0x34,0xC0,0XEB,0XCF,0XDF};   //离线
u8	USART_send_on_line[10]  ={0x5a,0xa5,0x07,0x82,0xA7,0x34,0xD4,0XDA,0XCF,0XDF};   //在线
u8	USART_send_on_clear[10] ={0x5a,0xa5,0x07,0x82,0xA7,0x34,0x00,0X00,0X00,0X00};   //清零
u8	USART_send_on_nosim[12] ={0x5a,0xa5,0x09,0x82,0xA7,0x34,0xCE,0XDE,0XB7,0XFE,0XCE,0XF1};   //清零
   if(state == 1)
	 {
		UART6_WriteBuffer((uint8_t *)USART_send_on_clear,10);	
		CLR_Buf6();	
		BSP_OS_TimeDly(10);
		UART6_WriteBuffer((uint8_t *)USART_send_on_line,10);	
		CLR_Buf6();	
		BSP_OS_TimeDly(10);
	 }
	 else if(state == 0)
	 {
		UART6_WriteBuffer((uint8_t *)USART_send_on_clear,10);	
		CLR_Buf6();	
		BSP_OS_TimeDly(10);		 
		UART6_WriteBuffer((uint8_t *)USART_send_off_line,10);	
		CLR_Buf6();	
		BSP_OS_TimeDly(10);	 
	 }
	 	 else if(state == 2)
	 {
		UART6_WriteBuffer((uint8_t *)USART_send_on_clear,10);	
		CLR_Buf6();	
		BSP_OS_TimeDly(10);		 
		UART6_WriteBuffer((uint8_t *)USART_send_on_nosim,12);	
		CLR_Buf6();	
		BSP_OS_TimeDly(10);	 
	 }
}
 /*
 * 函数名：data_display_Threshold_parameter
 * 描述  ：1734地址清屏   
 * 输入  ：
 *         
 *        
 *         
 * 输出  ：无
 * 返回  ：无
 * 调用  ：
 */
void data_display_sampling_set(void)
{
u8	USART_send6[18]={0x5a,0xa5,0x0F,0x82,0xF0,0x36,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0X00,0X00};

		UART6_WriteBuffer((uint8_t *)USART_send6,18);	
		CLR_Buf6();	
}
void data_display_sampling(void)
{
u8	USART_send6[18]={0x5a,0xa5,0x0F,0x82,0x17,0x34,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0X00,0X00};
     
		UART6_WriteBuffer((uint8_t *)USART_send6,18);	
		CLR_Buf6();	
}
void data_display_warning(void)
{
u8	USART_send6[18]={0x5a,0xa5,0x0F,0x82,0x10,0x36,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0X00,0X00};

		UART6_WriteBuffer((uint8_t *)USART_send6,18);	
		CLR_Buf6();	
}
/*
 * 函数名：Change_variable_color
 * 描述  ：给DWIN发送颜色数据
 * 输入  ：Structure_pointer  描述指针+0X03
 *         color 颜色指针
 *        
 *         
 * 输出  ：无
 * 返回  ：无
 * 调用  ：被data_display_temp()调用
 */
void Change_variable_color(u8 Structure_pointer,u16 color)
{

		u8	USART_send5[8]={0X5A,0XA5,0X05,0X82,0X50,0X03,0XFF,0XFF};  
		USART_send5[4]=Structure_pointer;
	  USART_send5[6]=(color & 0XFF00) >> 8 ;
	  USART_send5[7]=(color & 0X00FF) >> 0 ;
		BSP_OS_TimeDly(5);
		UART6_WriteBuffer((uint8_t *)USART_send5,8);
		CLR_Buf6();	

}
/*
 * 函数名：LCD_mode
 * 描述  ：获取主界面键值，优先级最高
 * 输入  ：
 *         
 *        
 *         
 * 输出  ：无
 * 返回  ：无
 * 调用  ：
 */
void LCD_mode(void){
	   //5A A5 06 83 18 0A 01 00 0A   采样设置按键返回值
	//5A A5 06 83 18 0B 01 00 0B      报警设置按键返回值
			//5A A5 06 83 10 41 01 00 07   采样设置界面确定按键返回值
	  //
	
	char	temp_09[]={0X5A,0XA5,0X06,0X83,0X10,0X71,0X01,0X00,0X09};     //参数设置按键返回值
	char	temp_0A[]={0X5A,0XA5,0X06,0X83,0X10,0X13,0X01,0X00,0X0A};     //参数设置按键返回值
//	u8	temp_01[10]={0X5A,0XA5,0X07,0X82,0X00,0X84,0X5A,0X01,0X00,0X01}; //屏幕切换指令


//	u8	USART_send5[18]={0x5a,0xa5,0x0F,0x82,0x17,0x34,0xB2,0xCE,0xCA,0xFD,0xC9,0xE8,0XD6,0XC3,0XB3,0XC9,0XB9,0XA6};


	  if(Find_usart6((char *)temp_09))
		{

				avg_X_N.LCD_modetemp=1;
				UART6_WriteBuffer((uint8_t *)temp_01,10);
				CLR_Buf6();
		}
		else if(Find_usart6((char *)temp_0A))	
		{

				avg_X_N.LCD_modetemp=0;
				UART6_WriteBuffer((uint8_t *)temp_00,10);
				CLR_Buf6();
		}			


}
/*
 * 函数名：setting_mode
 * 描述  ：获取子界面键值，优先级其次
 * 输入  ：
 *         
 *        
 *         
 * 输出  ：无
 * 返回  ：无
 * 调用  ：
 */
void setting_mode(void)
{

	   //5A A5 06 83 18 0A 01 00 0A   采样设置按键返回值
	//5A A5 06 83 18 0B 01 00 0B      报警设置按键返回值
	//5A A5 06 83 18 0C 01 00 0C        系统设置按键返回值
	//5A A5 06 83 13 A0 01 00 0A       系统设置界面内返回按键
	//5A A5 08 83 13 00 02 00 05 17 62   密码返回值  333666
	u8	USART_send_GBK[34]={0x5a,0xa5,0x13,0x82,0x13,0x04,
												0XC7,0XEB,0XB5,0XE3,0XBB,0XF7,
												0XB7,0XBD,0XBF,0XF2,0XC8,0XBB,
												0XBA,0XF3,0XCA,0XE4,0XC8,0XEB,
												0XC1,0XF9,0XCE,0XBB,0XCA,0XFD,
												0XC3,0XDC,0XC2,0XEB};   //系统设置界面汉字

char	temp_0A[]={0X5A,0XA5,0X06,0X83,0X18,0XFA,0X01,0X00,0X0A};     //TSP校准
char	temp_0B[]={0X5A,0XA5,0X06,0X83,0X18,0X0B,0X01,0X00,0X0B};     //PM2.5校准
char	temp_08[]={0X5A,0XA5,0X06,0X83,0X17,0X12,0X01,0X00,0X08};     //PM10校准
//char	temp_06[]={0X5A,0XA5,0X06,0X83,0X10,0X2A,0X01,0X00,0X06};     //
char	temp_0F[]={0X5A,0XA5,0X06,0X83,0X18,0XFF,0X01,0X00,0X0A};     //采样周期

char	temp_A0[]={0X5A,0XA5,0X06,0X83,0X20,0X0C,0X01,0X00,0X0C};     //系统设置按键返回值
char	temp_FF[]={0X5A,0XA5,0X06,0X83,0X18,0XFF,0X01,0X00,0X0A};     //系统设置按键返回值
char	temp_BF[]={0X5A,0XA5,0X06,0X83,0X18,0XBF,0X01,0X00,0X0A};     //系统设置按键返回值
char	temp_CF[]={0X5A,0XA5,0X06,0X83,0X18,0XCF,0X01,0X00,0X0A};     //系统设置按键返回值
			if(Find_usart6((char *)temp_A0)) {
				
				data_display_sampling();
				avg_X_N.LCD_modetemp=2;	
				UART6_WriteBuffer((uint8_t *)temp_03,10);	
				CLR_Buf6();	
				
		}
		else if(Find_usart6((char *)temp_0B)){
			
				data_display_sampling();
				avg_X_N.LCD_modetemp=3;	
				UART6_WriteBuffer((uint8_t *)temp_02,10);	
				CLR_Buf6();	
	
		
		
		}

				else if(Find_usart6((char *)temp_0A))
		{
			  data_display_sampling();
				avg_X_N.LCD_modetemp=4;	
				UART6_WriteBuffer((uint8_t *)temp_04,10);	
				CLR_Buf6();	
			
		}
				else if(Find_usart6((char *)temp_FF))
		{
			  data_display_sampling();
				avg_X_N.LCD_modetemp=5;	
				UART6_WriteBuffer((uint8_t *)temp_05,10);	
				CLR_Buf6();	
			
		}
						else if(Find_usart6((char *)temp_BF))
		{
			  data_display_sampling();
				avg_X_N.LCD_modetemp=6;	
				UART6_WriteBuffer((uint8_t *)temp_06,10);	
				CLR_Buf6();	
			
		}
						else if(Find_usart6((char *)temp_CF))
		{
			  data_display_sampling();
				avg_X_N.LCD_modetemp=7;	
				UART6_WriteBuffer((uint8_t *)temp_07,10);	
				CLR_Buf6();	
			
		}		
		
}
/*
 * 函数名：data_display_temp
 * 描述  ：温度显示
 * 输入  ：温度结构体变量
 *         
 *        
 *         
 * 输出  ：无
 * 返回  ：无
 * 调用  ：
 */
void data_display_temp(u16 data)
{
	/*
//static u16 DATA_TEMP = 0;
static u16 datas = 0;
u8	USART_send[8]={0x5a,0xa5,0x05,0x82,0x10,0x04,0x00,0x00};

  datas = data/100;
	USART_send[6]=(data & 0XFF00) >> 8 ;
	USART_send[7]=(data & 0X00FF) >> 0 ;
	UART6_WriteBuffer((uint8_t *)USART_send,8);
	CLR_Buf6();
	if(datas>=sampling_data.temp_threshold_value)
	{

			
		avg_X_N.max_TEMP_day = datas;    	//对比是否大于上次数据的值，大于就赋值给结构体变量	
//    DATA_TEMP = datas;                  //保存上一次数据的值

		avg_X_N.TEMP_Threshold_Value_BEGIN = 1 ;
		avg_X_N.TEMP_Threshold_Value_BEGINS++;
		if(avg_X_N.TEMP_Threshold_Value_BEGINS > 10) avg_X_N.TEMP_Threshold_Value_BEGINS = 10;
						
//		RELAY_SEL_PORT->ODR |= (relay3);  //Hight   继电器
		Change_variable_color(0x50,0XF800);
	}
	else 
	{
		
						if(avg_X_N.TEMP_Threshold_Value_BEGIN == 1 )
		{

			avg_X_N.TEMP_Threshold_Value_END = 1;
		}
		
//		RELAY_SEL_PORT->ODR &= ~(relay3);  //low
		Change_variable_color(0x50,0X0418);
	}
	
	Threshold_Value_Record_TEMP();
  BSP_OS_TimeDly(5);
*/

}
/*
 * 函数名：Threshold_Value_Record_TEMP
 * 描述  ：报警记录函数，缓存变量超过阈值的时间和结束时间
 * 输入  ：
 *         
 *        
 *         
 * 输出  ：无
 * 返回  ：无
 * 调用  ：
 */
void Threshold_Value_Record_TEMP(void){
	/*
	//报警记录 时间修改格式  5A A5 16 82 12 02 32 30 31 38 2D 31 31 2D 32 32 2D 31 31 3A 34 39 3A 34 35 
	//报警最高值	5a a5 05 82 12 AB 00 A2
		if((avg_X_N.TEMP_Threshold_Value_BEGIN == 1) && (avg_X_N.TEMP_Threshold_Value_BEGINS == 1))
		{	
				RTC_time();
			
						switch(avg_X_N.TEMP_Threshold_Value_ENDS)
			{				 
				case 0:	//
				Threshold_Value_Record_(0x1202,mytime.year,mytime.month,mytime.day,mytime.hour,mytime.minute,mytime.second);
				
					break;
				case 1:	//
				Threshold_Value_Record_(0x1302,mytime.year,mytime.month,mytime.day,mytime.hour,mytime.minute,mytime.second);
				
					break;
				case 2:	//
				Threshold_Value_Record_(0x1402,mytime.year,mytime.month,mytime.day,mytime.hour,mytime.minute,mytime.second);					
	
					break;
				case 3:	//
				Threshold_Value_Record_(0x1502,mytime.year,mytime.month,mytime.day,mytime.hour,mytime.minute,mytime.second);	
				
					break;
				case 4:	//
				Threshold_Value_Record_(0x1602,mytime.year,mytime.month,mytime.day,mytime.hour,mytime.minute,mytime.second);	
			
					break;
				case 5:	//
				Threshold_Value_Record_(0x1702,mytime.year,mytime.month,mytime.day,mytime.hour,mytime.minute,mytime.second);	
			

					break;
				case 6:	//
				Threshold_Value_Record_(0x1802,mytime.year,mytime.month,mytime.day,mytime.hour,mytime.minute,mytime.second);	
			
					break;				
			}

			

//			printf("TEMP_Threshold_Value_BEGIN\r\n");


		}
		if(avg_X_N.TEMP_Threshold_Value_END == 1)
		{
			RTC_time();
			
						switch(avg_X_N.TEMP_Threshold_Value_ENDS)
			{				 
				case 0:	//
			Threshold_Value_Record_(0x3222,mytime.year,mytime.month,mytime.day,mytime.hour,mytime.minute,mytime.second);
			Threshold_Value_Record_data(0x122B,avg_X_N.max_TEMP_day);
		
					break;
				case 1:	//
			Threshold_Value_Record_(0x3322,mytime.year,mytime.month,mytime.day,mytime.hour,mytime.minute,mytime.second);
			Threshold_Value_Record_data(0x132B,avg_X_N.max_TEMP_day);	

				
					break;
				case 2:	//
			Threshold_Value_Record_(0x3422,mytime.year,mytime.month,mytime.day,mytime.hour,mytime.minute,mytime.second);
			Threshold_Value_Record_data(0x142B,avg_X_N.max_TEMP_day);					
	
					break;
				case 3:	//
			Threshold_Value_Record_(0X3522,mytime.year,mytime.month,mytime.day,mytime.hour,mytime.minute,mytime.second);
			Threshold_Value_Record_data(0x152B,avg_X_N.max_TEMP_day);			
	
					break;
				case 4:	//
			Threshold_Value_Record_(0X3622,mytime.year,mytime.month,mytime.day,mytime.hour,mytime.minute,mytime.second);
			Threshold_Value_Record_data(0x162B,avg_X_N.max_TEMP_day);
			
					break;
			case 5:	//
			Threshold_Value_Record_(0X3722,mytime.year,mytime.month,mytime.day,mytime.hour,mytime.minute,mytime.second);
			Threshold_Value_Record_data(0x172B,avg_X_N.max_TEMP_day);
			
					break;
			case 6:	//
			Threshold_Value_Record_(0X3822,mytime.year,mytime.month,mytime.day,mytime.hour,mytime.minute,mytime.second);
			Threshold_Value_Record_data(0x182B,avg_X_N.max_TEMP_day);
			
					break;
			}
		

				/*
//			printf("avg_X_N.max_TEMP_day = %d\r\n",avg_X_N.max_TEMP_day);
//			printf("avg_X_N.TEMP_Threshold_Value_ENDS = %d\r\n",avg_X_N.TEMP_Threshold_Value_ENDS);
			avg_X_N.TEMP_Threshold_Value_BEGIN = 0;
		  avg_X_N.TEMP_Threshold_Value_END = 0;
			avg_X_N.TEMP_Threshold_Value_BEGINS = 0;
			avg_X_N.TEMP_Threshold_Value_ENDS++;
			if(avg_X_N.TEMP_Threshold_Value_ENDS == 7)  avg_X_N.TEMP_Threshold_Value_ENDS = 0;
*/
		//}

}
/*
 * 函数名：data_display_humi
 * 描述  ：显示湿度函数
 * 输入  ：湿度结构体变量
 *         
 *        
 *         
 * 输出  ：无
 * 返回  ：无
 * 调用  ：
 */
void data_display_humi(u16 data)
{

u8	USART_send[8]={0x5a,0xa5,0x05,0x82,0x10,0x06,0x00,0x00};

	USART_send[6]=(data & 0XFF00) >> 8 ;
	USART_send[7]=(data & 0X00FF) >> 0 ;
	
	UART6_WriteBuffer((uint8_t *)USART_send,8);
	CLR_Buf6();
	BSP_OS_TimeDly(5);


}
/*
 * 函数名：data_display_WIND_LEVEL
 * 描述  ：显示风级函数
 * 输入  ：风级结构体变量
 *         
 *        
 *         
 * 输出  ：无
 * 返回  ：无
 * 调用  ：
 */
void data_display_WIND_LEVEL(u16 data)
{

u8	USART_send[8]={0x5a,0xa5,0x05,0x82,0x10,0x5F,0x00,0x00};

	USART_send[6]=(data & 0XFF00) >> 8 ;
	USART_send[7]=(data & 0X00FF) >> 0 ;
	
	UART6_WriteBuffer((uint8_t *)USART_send,8);
	CLR_Buf6();
	BSP_OS_TimeDly(5);


}
/*
 * 函数名：data_display_press
 * 描述  ：显示大气压函数
 * 输入  ：大气压结构体变量
 *         
 *        
 *         
 * 输出  ：无
 * 返回  ：无
 * 调用  ：
 */
void data_display_press(u16 data)
{

u8	USART_send[8]={0x5a,0xa5,0x05,0x82,0x10,0x08,0x00,0x00};

	USART_send[6]=(data & 0XFF00) >> 8 ;
	USART_send[7]=(data & 0X00FF) >> 0 ;
	
	UART6_WriteBuffer((uint8_t *)USART_send,8);
	CLR_Buf6();
	BSP_OS_TimeDly(5);


}
/*
 * 函数名：data_display_Noise
 * 描述  ：显示噪声函数
 * 输入  ：噪声结构体变量
 *         
 *        
 *         
 * 输出  ：无
 * 返回  ：无
 * 调用  ：
 */
void data_display_Noise(u8 data)  //现为noise
{

u8	USART_send[8]={0x5a,0xa5,0x05,0x82,0x10,0x65,0x00,0x00};

		USART_send[7]=data;
		UART6_WriteBuffer((uint8_t *)USART_send,8);	
		CLR_Buf6();
		BSP_OS_TimeDly(5);
}
/*
 * 函数名：data_display_wind_speed
 * 描述  ：显示风速函数
 * 输入  ：风速结构体变量
 *         
 *        
 *         
 * 输出  ：无
 * 返回  ：无
 * 调用  ：
 */
void data_display_wind_speed(uint16_t data)
{
u8	USART_send[8]={0x5a,0xa5,0x05,0x82,0x10,0x16,0x00,0x00};

			USART_send[6]=(data & 0XFF00) >> 8 ;
			USART_send[7]=(data & 0X00FF) >> 0 ;
			UART6_WriteBuffer((uint8_t *)USART_send,8);	
			CLR_Buf6();
			BSP_OS_TimeDly(5);


}
/*
 * 函数名：data_display_wind_direction
 * 描述  ：显示风向函数
 * 输入  ：风向结构体变量
 *         
 *        
 *         
 * 输出  ：无
 * 返回  ：无
 * 调用  ：
 */
void data_display_wind_direction(uint16_t data)
{
	/*
u8	USART_send[12]={0x5a,0xa5,0x09,0x82,0x10,0x38,0x00,0x00,0x00,0x00,0xB7,0xE7};

switch(data)
	{
		case 1:
			USART_send[6]=0XD5;     //正北风
			USART_send[7]=0XFD;  
			USART_send[8]=0XB1;    
			USART_send[9]=0XB1;		
			break;	
		case 2:
			USART_send[6]=0XB6;     //东北风
			USART_send[7]=0XAB;  
			USART_send[8]=0XB1;    
			USART_send[9]=0XB1;	
			break;
		case 3:
			USART_send[6]=0XD5;     //正东风
			USART_send[7]=0XFD;  
			USART_send[8]=0XB6;    
			USART_send[9]=0XAB;	
			break;
		case 4:
			USART_send[6]=0xb6;     //东南风
			USART_send[7]=0XAB;  
			USART_send[8]=0XC4;    
			USART_send[9]=0XCF;	
			break;
		case 5:
			USART_send[6]=0XD5;     //正南风
			USART_send[7]=0XFD;  
			USART_send[8]=0XC4;    
			USART_send[9]=0XCF;	
			break;
		case 6:
			USART_send[6]=0XCE;     //西南风
			USART_send[7]=0XF7;  
			USART_send[8]=0XC4;    
			USART_send[9]=0XCF;	
			break;
		case 7:
			USART_send[6]=0XD5;     //正西风
			USART_send[7]=0XFD;  
			USART_send[8]=0XCE;    
			USART_send[9]=0XF7;	
			break;
		case 8:
			USART_send[6]=0XCE;     //西北风
			USART_send[7]=0XF7;  
			USART_send[8]=0XB1;    
			USART_send[9]=0XB1;	
		  break;
    default:
			USART_send[6]=0XD5;     //正北风
			USART_send[7]=0XFD;  
			USART_send[8]=0XB1;    
			USART_send[9]=0XB1;	
			break;
	}
		UART6_WriteBuffer((uint8_t *)USART_send,12);
	  CLR_Buf6();
		BSP_OS_TimeDly(5);
*/
}
/*
 * 函数名：data_display_PM25
 * 描述  ：显示PM25函数
 * 输入  ：
 *         
 *        
 *         
 * 输出  ：无
 * 返回  ：无
 * 调用  ：
 */
void data_display_PM25(uint16_t data)
{
//static u16 DATA_PM25 = 0;
u8	USART_send[8]={0x5a,0xa5,0x05,0x82,0x10,0x0a,0x00,0x00};
//u16  temp_data_PM25[60] = {0};

			USART_send[6]=(data & 0XFF00) >> 8 ;
			USART_send[7]=(data & 0X00FF) >> 0 ;
	
		UART6_WriteBuffer((uint8_t *)USART_send,8);
		CLR_Buf6();
/*
	if(data>=sampling_data.pm25_threshold_value)
	{
//		temp_data_PM25[count++] = data;
				if(data > DATA_PM25)
				avg_X_N.max_PM25_day = data;    	//对比是否大于上次数据的值，大于就赋值给结构体变量
				
     DATA_PM25 = data;                  //保存上一次数据的值
		
		avg_X_N.PM25_Threshold_Value_BEGIN = 1 ;
		avg_X_N.PM25_Threshold_Value_BEGINS++;
		if(avg_X_N.PM25_Threshold_Value_BEGINS > 10) avg_X_N.PM25_Threshold_Value_BEGINS = 10;
//		RELAY_SEL_PORT->ODR |= (relay2);  //Hight   继电器
//		Change_variable_color(0x80,0XF800);
				

	}
	else if(data>0)
	{
		if(avg_X_N.PM25_Threshold_Value_BEGIN == 1 )
		{

			avg_X_N.PM25_Threshold_Value_END = 1;
		}
//		RELAY_SEL_PORT->ODR &= ~(relay2);  //low
//		Change_variable_color(0x80,0X0418);
	}
	
	Threshold_Value_Record();
*/
	
		BSP_OS_TimeDly(5);


}
/*
 * 函数名：Threshold_Value_Record
 * 描述  ：PM2.5报警值开始时间记录
 * 输入  ：
 *         
 *        
 *         
 * 输出  ：无
 * 返回  ：无
 * 调用  ：
 */
void Threshold_Value_Record(void){
	/*
	//报警记录 时间修改格式  5A A5 16 82 12 02 32 30 31 38 2D 31 31 2D 32 32 2D 31 31 3A 34 39 3A 34 35 
	//报警最高值	5a a5 05 82 12 AB 00 A2
		if((avg_X_N.PM25_Threshold_Value_BEGIN == 1) && (avg_X_N.PM25_Threshold_Value_BEGINS == 1))
		{	
				RTC_time();
			
						switch(avg_X_N.PM25_Threshold_Value_ENDS)
			{				 
				case 0:	//
				Threshold_Value_Record_(0x1232,mytime.year,mytime.month,mytime.day,mytime.hour,mytime.minute,mytime.second);
				
					break;
				case 1:	//
				Threshold_Value_Record_(0x1332,mytime.year,mytime.month,mytime.day,mytime.hour,mytime.minute,mytime.second);
				
					break;
				case 2:	//
				Threshold_Value_Record_(0x1432,mytime.year,mytime.month,mytime.day,mytime.hour,mytime.minute,mytime.second);					
	
					break;
				case 3:	//
				Threshold_Value_Record_(0x1532,mytime.year,mytime.month,mytime.day,mytime.hour,mytime.minute,mytime.second);	
				
					break;
				case 4:	//
				Threshold_Value_Record_(0x1632,mytime.year,mytime.month,mytime.day,mytime.hour,mytime.minute,mytime.second);	
			
					break;
				case 5:	//
				Threshold_Value_Record_(0x1732,mytime.year,mytime.month,mytime.day,mytime.hour,mytime.minute,mytime.second);	
			
					break;
				case 6:	//
				Threshold_Value_Record_(0x1832,mytime.year,mytime.month,mytime.day,mytime.hour,mytime.minute,mytime.second);	
			
					break;				
			}

			

//			printf("PM25_Threshold_Value_BEGIN\r\n");


		}
		if(avg_X_N.PM25_Threshold_Value_END == 1)
		{
			RTC_time();
			
						switch(avg_X_N.PM25_Threshold_Value_ENDS)
			{				 
				case 0:	//
			Threshold_Value_Record_(0x1242,mytime.year,mytime.month,mytime.day,mytime.hour,mytime.minute,mytime.second);
			Threshold_Value_Record_data(0x12AB,avg_X_N.max_PM25_day);
		
					break;
				case 1:	//
			Threshold_Value_Record_(0x1342,mytime.year,mytime.month,mytime.day,mytime.hour,mytime.minute,mytime.second);
			Threshold_Value_Record_data(0x13AB,avg_X_N.max_PM25_day);	

				
					break;
				case 2:	//
			Threshold_Value_Record_(0x1442,mytime.year,mytime.month,mytime.day,mytime.hour,mytime.minute,mytime.second);
			Threshold_Value_Record_data(0x14AB,avg_X_N.max_PM25_day);					
	
					break;
				case 3:	//
			Threshold_Value_Record_(0x1542,mytime.year,mytime.month,mytime.day,mytime.hour,mytime.minute,mytime.second);
			Threshold_Value_Record_data(0x15AB,avg_X_N.max_PM25_day);			
	
					break;
				case 4:	//
			Threshold_Value_Record_(0x1642,mytime.year,mytime.month,mytime.day,mytime.hour,mytime.minute,mytime.second);
			Threshold_Value_Record_data(0x16AB,avg_X_N.max_PM25_day);
			
					break;
			case 5:	//
			Threshold_Value_Record_(0x1742,mytime.year,mytime.month,mytime.day,mytime.hour,mytime.minute,mytime.second);
			Threshold_Value_Record_data(0x17AB,avg_X_N.max_PM25_day);
			
					break;
			case 6:	//
			Threshold_Value_Record_(0x1842,mytime.year,mytime.month,mytime.day,mytime.hour,mytime.minute,mytime.second);
			Threshold_Value_Record_data(0x18AB,avg_X_N.max_PM25_day);
			
					break;
			}
		

				
//			printf("avg_X_N.max_PM25_day = %d\r\n",avg_X_N.max_PM25_day);
//			printf("avg_X_N.PM25_Threshold_Value_ENDS = %d\r\n",avg_X_N.PM25_Threshold_Value_ENDS);
			avg_X_N.PM25_Threshold_Value_BEGIN = 0;
		  avg_X_N.PM25_Threshold_Value_END = 0;
			avg_X_N.PM25_Threshold_Value_BEGINS = 0;
			avg_X_N.PM25_Threshold_Value_ENDS++;
			if(avg_X_N.PM25_Threshold_Value_ENDS == 7)  avg_X_N.PM25_Threshold_Value_ENDS = 0;

		}
		*/
}
/*
 * 函数名：Threshold_Value_Record_
 * 描述  ：报警值时间显示(公用)
 * 输入  ：地址，时间结构体变量
 *         
 *        
 *         
 * 输出  ：无
 * 返回  ：无
 * 调用  ：
 */
void Threshold_Value_Record_(u16 address,u8 year,u8 month, u8 day,u8 hour,u8 minute,u8 second){
	u8	USART_send_Record[]  ={0x5A,0xA5,0x16,0x82,0x12,0x32,0x32,0x30,0x31,0x38,0x2D,0x31,0x31,0x2D,0x32,0x32,0x2D,0x31,0x31,0x3A,0x34,0x39,0x3A,0x34,0x35};
			USART_send_Record[4]=(address & 0XFF00) >> 8 ;
			USART_send_Record[5]=(address & 0X00FF) >> 0 ; 
			
				USART_send_Record[8]  = (year/10)+'0';
				USART_send_Record[9]  = (year%10)+'0';	
				USART_send_Record[11] = (month/10)+'0';
				USART_send_Record[12] = (month%10)+'0';	
				USART_send_Record[14] = (day/10)+'0';
				USART_send_Record[15] = (day%10)+'0';	
				USART_send_Record[17] = (hour/10)+'0';
				USART_send_Record[18] = (hour%10)+'0';	
				USART_send_Record[20] = (minute/10)+'0';
				USART_send_Record[21] = (minute%10)+'0';	
				USART_send_Record[23] = (second/10)+'0';
				USART_send_Record[24] = (second%10)+'0';	
				UART6_WriteBuffer((uint8_t *)USART_send_Record,strlen((char *)USART_send_Record));
				BSP_OS_TimeDly(5);
		    CLR_Buf6();
		   
}
/*
 * 函数名：Threshold_Value_Record_data
 * 描述  ：PM2.5报警值最大值显示
 * 输入  ：地址，构体变量
 *         
 *        
 *         
 * 输出  ：无
 * 返回  ：无
 * 调用  ：
 */
void Threshold_Value_Record_data(u16 address,u16 data){
				u8	USART_send_Record2[] ={0x5a,0xa5,0x05,0x82,0x12,0xAB,0x00,0x00};
				
				USART_send_Record2[4]=(address & 0XFF00) >> 8 ;
				USART_send_Record2[5]=(address & 0X00FF) >> 0 ; 
				USART_send_Record2[6]=(data & 0XFF00) >> 8 ;
				USART_send_Record2[7]=(data & 0X00FF) >> 0 ; 	
				
				UART6_WriteBuffer((uint8_t *)USART_send_Record2,8);
				BSP_OS_TimeDly(5);
		    CLR_Buf6();
		   
}
/*
 * 函数名：data_display_PM10
 * 描述  ：PM10显示函数
 * 输入  ：地址，构体变量
 *         
 *        
 *         
 * 输出  ：无
 * 返回  ：无
 * 调用  ：
 */
void data_display_PM10(uint16_t data)
{
//static u16 DATA_PM10 = 0;
u8	USART_send[8]={0x5a,0xa5,0x05,0x82,0x10,0x12,0x00,0x00};
	
			USART_send[6]=(data & 0XFF00) >> 8 ;
			USART_send[7]=(data & 0X00FF) >> 0 ;
	
		UART6_WriteBuffer((uint8_t *)USART_send,8);

		CLR_Buf6();
/*
			if(data>=sampling_data.pm10_threshold_value)
	{
						if(data > DATA_PM10)
							
					avg_X_N.max_PM10_day = data;    	//对比是否大于上次数据的值，大于就赋值给结构体变量
						
		     DATA_PM10 = data;                  //保存上一次数据的值
		avg_X_N.PM10_Threshold_Value_BEGIN = 1 ;
		avg_X_N.PM10_Threshold_Value_BEGINS++;
		if(avg_X_N.PM10_Threshold_Value_BEGINS > 10) avg_X_N.PM10_Threshold_Value_BEGINS = 10;
						
//		RELAY_SEL_PORT->ODR |= (relay1);  //Hight   继电器
		Change_variable_color(0x90,0XF800);
	}
	else if(data>0)
	{
				if(avg_X_N.PM10_Threshold_Value_BEGIN == 1 )
		{

			avg_X_N.PM10_Threshold_Value_END = 1;
		}
		
//		avg_X_N.max_PM10_day = 0;
//		RELAY_SEL_PORT->ODR &= ~(relay1);  //low
		Change_variable_color(0x90,0X0418);
	}
Threshold_Value_Record_PM10();	
*/
BSP_OS_TimeDly(5);


}
/*
 * 函数名：Threshold_Value_Record_PM10
 * 描述  ：PM10报警记录
 * 输入  ：地址，构体变量
 *         
 *        
 *         
 * 输出  ：无
 * 返回  ：无
 * 调用  ：
 */
void Threshold_Value_Record_PM10(void){
	/*
	//报警记录 时间修改格式  5A A5 16 82 12 02 32 30 31 38 2D 31 31 2D 32 32 2D 31 31 3A 34 39 3A 34 35 
	//报警最高值	5a a5 05 82 12 AB 00 A2
		if((avg_X_N.PM10_Threshold_Value_BEGIN == 1) && (avg_X_N.PM10_Threshold_Value_BEGINS == 1))
		{	
				RTC_time();
			
						switch(avg_X_N.PM10_Threshold_Value_ENDS)
			{				 
				case 0:	//
				Threshold_Value_Record_(0x1252,mytime.year,mytime.month,mytime.day,mytime.hour,mytime.minute,mytime.second);
				
					break;
				case 1:	//
				Threshold_Value_Record_(0x1352,mytime.year,mytime.month,mytime.day,mytime.hour,mytime.minute,mytime.second);
				
					break;
				case 2:	//
				Threshold_Value_Record_(0x1452,mytime.year,mytime.month,mytime.day,mytime.hour,mytime.minute,mytime.second);					
	
					break;
				case 3:	//
				Threshold_Value_Record_(0x1552,mytime.year,mytime.month,mytime.day,mytime.hour,mytime.minute,mytime.second);	
				
					break;
				case 4:	//
				Threshold_Value_Record_(0x1652,mytime.year,mytime.month,mytime.day,mytime.hour,mytime.minute,mytime.second);	
			
					break;
				case 5:	//
				Threshold_Value_Record_(0x1752,mytime.year,mytime.month,mytime.day,mytime.hour,mytime.minute,mytime.second);	
			

					break;
				case 6:	//
				Threshold_Value_Record_(0x1852,mytime.year,mytime.month,mytime.day,mytime.hour,mytime.minute,mytime.second);	
			
					break;				
			}

			

//			printf("PM10_Threshold_Value_BEGIN\r\n");


		}
		if(avg_X_N.PM10_Threshold_Value_END == 1)
		{
			RTC_time();
			
						switch(avg_X_N.PM10_Threshold_Value_ENDS)
			{				 
				case 0:	//
			Threshold_Value_Record_(0x2262,mytime.year,mytime.month,mytime.day,mytime.hour,mytime.minute,mytime.second);
			Threshold_Value_Record_data(0x12CB,avg_X_N.max_PM10_day);
		
					break;
				case 1:	//
			Threshold_Value_Record_(0x2362,mytime.year,mytime.month,mytime.day,mytime.hour,mytime.minute,mytime.second);
			Threshold_Value_Record_data(0x13CB,avg_X_N.max_PM10_day);	

				
					break;
				case 2:	//
			Threshold_Value_Record_(0x2462,mytime.year,mytime.month,mytime.day,mytime.hour,mytime.minute,mytime.second);
			Threshold_Value_Record_data(0x14CB,avg_X_N.max_PM10_day);					
	
					break;
				case 3:	//
			Threshold_Value_Record_(0x2562,mytime.year,mytime.month,mytime.day,mytime.hour,mytime.minute,mytime.second);
			Threshold_Value_Record_data(0x15CB,avg_X_N.max_PM10_day);			
	
					break;
				case 4:	//
			Threshold_Value_Record_(0x2662,mytime.year,mytime.month,mytime.day,mytime.hour,mytime.minute,mytime.second);
			Threshold_Value_Record_data(0x16CB,avg_X_N.max_PM10_day);
			
					break;
			case 5:	//
			Threshold_Value_Record_(0x2762,mytime.year,mytime.month,mytime.day,mytime.hour,mytime.minute,mytime.second);
			Threshold_Value_Record_data(0x17CB,avg_X_N.max_PM10_day);
			
					break;
			case 6:	//
			Threshold_Value_Record_(0x2862,mytime.year,mytime.month,mytime.day,mytime.hour,mytime.minute,mytime.second);
			Threshold_Value_Record_data(0x18CB,avg_X_N.max_PM10_day);
			
					break;
			}
		

				
//			printf("avg_X_N.max_PM10_day = %d\r\n",avg_X_N.max_PM10_day);
//			printf("avg_X_N.PM10_Threshold_Value_ENDS = %d\r\n",avg_X_N.PM10_Threshold_Value_ENDS);
			avg_X_N.PM10_Threshold_Value_BEGIN = 0;
		  avg_X_N.PM10_Threshold_Value_END = 0;
			avg_X_N.PM10_Threshold_Value_BEGINS = 0;
			avg_X_N.PM10_Threshold_Value_ENDS++;
			if(avg_X_N.PM10_Threshold_Value_ENDS == 7)  avg_X_N.PM10_Threshold_Value_ENDS = 0;

		}
		*/
	}
/*
 * 函数名：data_display_TSP
 * 描述  ：TSP显示
 * 输入  ：地址，构体变量
 *         
 *        
 *         
 * 输出  ：无
 * 返回  ：无
 * 调用  ：
 */
void data_display_TSP(uint16_t data)
{

u8	USART_send[8]={0x5a,0xa5,0x05,0x82,0x10,0x18,0x00,0x00};

			USART_send[6]=(data & 0XFF00) >> 8 ;
			USART_send[7]=(data & 0X00FF) >> 0 ;
	
		UART6_WriteBuffer((uint8_t *)USART_send,8);
		CLR_Buf6();
		BSP_OS_TimeDly(5);


}
/*
 * 函数名：Get_Data
 * 描述  ：获取数据
 * 输入  ：
 *         
 *        
 *         
 * 输出  ：无
 * 返回  ：无
 * 调用  ：
 */
void Get_Data(void){

	 ParsePM25Command_CUBIC();
//	if(sampling_data.RELAYSF)
//	{
//		
//	 ParsePM25Command_CUBIC();
//		
//	}
	
//	 ParsePM25Command();
	
//	 getWindDirection();   //风速 风向  温湿度 噪声 通过485主机获取		

//   getNoise();   //Noise temp Humi

//	 getWindSpeed();

}
/*
 * 函数名：Get_sampling_Data
 * 描述  ：获取sampling数据
 * 输入  ：
 *         
 *        
 *         
 * 输出  ：无
 * 返回  ：无
 * 调用  ：
 */
void Get_sampling_Data(void){
	/*
   //5A A5 06 83 10 41 01 00 07   采样设置确定按键返回值
	 //5A A5 06 83 17 12 01 00 08     返回按键
u8	USART_send5[18]={0x5a,0xa5,0x0F,0x82,0x17,0x34,0xB2,0xCE,0xCA,0xFD,0xC9,0xE8,0XD6,0XC3,0XB3,0XC9,0XB9,0XA6};
u8	USART_send_GBK[22]={0x5a,0xa5,0x13,0x82,0x17,0x34,0xB2,0xCE,0xCA,0xFD,0xD0,0xB4,0XC8,0XEB,0XD6,0XD0,0XC7,0XEB,0XC9,0XD4,0XB5,0XC8};
u8	USART_send_GBK_0[22]={0x5a,0xa5,0x13,0x82,0x17,0x34,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0X00,0X00,0X00,0X00,0X00,0X00};	
char	temp_0A[]={0X5A,0XA5,0X06,0X83,0X10,0X41,0X01,0X00,0X07};     //参数设置按键返回值
char	temp_08[]={0X5A,0XA5,0X06,0X83,0X17,0X12,0X01,0X00,0X08};     //参数设置按键返回值
	  if(Find_usart6((char *)temp_0A))
		{
							printf("get....\r\n");
							CLR_Buf6();
							Get_PM2_5_0_50();
							Get_PM2_5_51_150();
							Get_PM2_5_151_300();
							Get_PM2_5_300();
							Get_PM10_0_50();
					    Get_PM10_51_150();
							Get_PM10_151_300();
							Get_PM10_300();
							UART6_WriteBuffer((uint8_t *)USART_send_GBK,22);
							printf("PM2_5_0_50:%d\r\n", sampling_data.PM2_5_0_50);
							printf("PM2_5_51_150:%d\r\n", sampling_data.PM2_5_51_150);				
							printf("PM2_5_151_300:%d\r\n", sampling_data.PM2_5_151_300);
							printf("PM2_5_300:%d\r\n", sampling_data.PM2_5_300);	
							printf("PM10_0_50:%d\r\n", sampling_data.PM10_0_50);
							printf("PM10_51_150:%d\r\n", sampling_data.PM10_51_150);				
							printf("PM10_151_300:%d\r\n", sampling_data.PM10_151_300);
							printf("PM10_300:%d\r\n", sampling_data.PM10_300);						
					if((sampling_data.PM2_5_0_50 != 0)&(sampling_data.PM2_5_51_150 != 0)&(sampling_data.PM2_5_151_300 != 0))
					{	

						
						write_flash();
						UART6_WriteBuffer((uint8_t *)USART_send_GBK_0,22);
						CLR_Buf6();	
						UART6_WriteBuffer((uint8_t *)USART_send5,18);
						BSP_OS_TimeDly(100);
						UART6_WriteBuffer((uint8_t *)temp_01,10);
						printf("get succeed\r\n");	
						avg_X_N.LCD_modetemp=1;	
						CLR_Buf6();						
//          raed_flash();						
			
					}
		}
			else if(Find_usart6((char *)temp_08))
			{
				UART6_WriteBuffer((uint8_t *)temp_17,10);
				avg_X_N.LCD_modetemp=7;
				CLR_Buf6();
			}
*/
}
/*
 * 函数名：write_flash
 * 描述  ：数据写入flash
 * 输入  ：
 *         
 *        
 *         
 * 输出  ：无
 * 返回  ：无
 * 调用  ：
 */
void write_flash(void)    //sampling coefficient
{

		temp[0] = Cof[0].num_0_50;
		temp[1] = Cof[0].num_50_100;	
		temp[2] = Cof[0].num_100_500;
		temp[3] = Cof[0].num_500_1000;
		temp[4] = Cof[0].num_1000_1500;
		temp[5] = Cof[0].num_1500_3000;
		temp[6] = Cof[0].num_3000_8000;
		temp[7] = Cof[0].num_8000_13000;	
		temp[8] = Cof[0].num_13000_20000;	
		temp[9] = Cof[0].num_20000_30000;	

		STMFLASH_Write(FLASH_START_ADDR,(u16*)falsh_temp,10);
	  
}
/*
 * 函数名：raed_flash
 * 描述  ：读取flash数据
 * 输入  ：
 *         
 *        
 *         
 * 输出  ：无
 * 返回  ：无
 * 调用  ：
 */
void raed_flash(void){

		u8 t;
		STMFLASH_Read(FLASH_START_ADDR,(u16*)temp,10);

	
		 Cof[0].num_0_50 				= temp[0];
		 Cof[0].num_50_100 			= temp[1];	
		 Cof[0].num_100_500			= temp[2];
		 Cof[0].num_500_1000 		= temp[3];
		 Cof[0].num_1000_1500 	= temp[4];
		 Cof[0].num_1500_3000 	= temp[5];
		 Cof[0].num_3000_8000 	= temp[6];
		 Cof[0].num_8000_13000 	= temp[7];
		 Cof[0].num_13000_20000 = temp[8];
		 Cof[0].num_20000_30000 = temp[9];	
		if(temp[0] > 0XFE)	
		{
		
		 Cof[0].num_0_50 				= COEFFICIENT;
		 Cof[0].num_50_100 			= COEFFICIENT;	
		 Cof[0].num_100_500			= COEFFICIENT;
		 Cof[0].num_500_1000 		= COEFFICIENT;
		 Cof[0].num_1000_1500 	= COEFFICIENT;
		 Cof[0].num_1500_3000 	= COEFFICIENT;
		 Cof[0].num_3000_8000 	= COEFFICIENT;
		 Cof[0].num_8000_13000 	= COEFFICIENT;
		 Cof[0].num_13000_20000 = COEFFICIENT;
		 Cof[0].num_20000_30000 = COEFFICIENT;	
		
		 printf("Parameters are not written using default parameters\r\n");		
		}
	 else{
	
		for(t=0;t<10;t++)
		{
		
			printf("sampling_data:%d\r\n",temp[t]);
		
		}

	}

}
/*
 * 函数名：write_flash_cof0_pm2_5
 * 描述  ：数据写入flash
 * 输入  ：
 *         
 *        
 *         
 * 输出  ：无
 * 返回  ：无
 * 调用  ：
 */
void write_flash_cof0_pm2_5(void)    //sampling coefficient
{

		temp[0] = Cof[0].num_0_50;
		temp[1] = Cof[0].num_50_100;	
		temp[2] = Cof[0].num_100_500;
		temp[3] = Cof[0].num_500_1000;
		temp[4] = Cof[0].num_1000_1500;
		temp[5] = Cof[0].num_1500_3000;
		temp[6] = Cof[0].num_3000_8000;
		temp[7] = Cof[0].num_8000_13000;	
		temp[8] = Cof[0].num_13000_20000;	
		temp[9] = Cof[0].num_20000_30000;	

		STMFLASH_Write(FLASH_COF0_PM2_5,(u16*)temp,10);
	  
}

/*
 * 函数名：raed_cof0_pm2_5
 * 描述  ：读取flash数据
 * 输入  ：
 *         
 *        
 *         
 * 输出  ：无
 * 返回  ：无
 * 调用  ：
 */
void raed_cof0_pm2_5(void){

				u8 t;
		STMFLASH_Read(FLASH_COF0_PM2_5,(u16*)temp,10);

	
		 Cof[0].num_0_50 				= temp[0];
		 Cof[0].num_50_100 			= temp[1];	
		 Cof[0].num_100_500			= temp[2];
		 Cof[0].num_500_1000 		= temp[3];
		 Cof[0].num_1000_1500 	= temp[4];
		 Cof[0].num_1500_3000 	= temp[5];
		 Cof[0].num_3000_8000 	= temp[6];
		 Cof[0].num_8000_13000 	= temp[7];
		 Cof[0].num_13000_20000 = temp[8];
		 Cof[0].num_20000_30000 = temp[9];	
		if(temp[0] > 0XFFFE)	
		{
		
		 Cof[0].num_0_50 		    = COEFFICIENT;
		 Cof[0].num_50_100 		  = COEFFICIENT;	
		 Cof[0].num_100_500		  = COEFFICIENT;
		 Cof[0].num_500_1000 	  = COEFFICIENT;
		 Cof[0].num_1000_1500 	= COEFFICIENT;
		 Cof[0].num_1500_3000 	= COEFFICIENT;
		 Cof[0].num_3000_8000 	= COEFFICIENT;
		 Cof[0].num_8000_13000 	= COEFFICIENT;
		 Cof[0].num_13000_20000 = COEFFICIENT;
		 Cof[0].num_20000_30000 = COEFFICIENT;	
		
		 RS485_RDEN_PORT->ODR |= RS485_RDEN_PIN;//High Send
		 printf("Parameters are not written using default parameters\r\n");		
		 RS485_RDEN_PORT->ODR &= ~(RS485_RDEN_PIN);//Low Rev	
		}
	 else{
	
		for(t=0;t<10;t++)
		{
			RS485_RDEN_PORT->ODR |= RS485_RDEN_PIN;//High Send
			printf("Cof0_%d:%d\r\n",t,temp[t]);
			RS485_RDEN_PORT->ODR &= ~(RS485_RDEN_PIN);//Low Rev
			
		
		}

	}

}
/*
 * 函数名：write_flash_cof0_pm2_5
 * 描述  ：数据写入flash
 * 输入  ：
 *         
 *        
 *         
 * 输出  ：无
 * 返回  ：无
 * 调用  ：
 */
void write_flash_cof1_pm10(void)    //sampling coefficient
{

		temp[0] = Cof[1].num_0_50;
		temp[1] = Cof[1].num_50_100;	
		temp[2] = Cof[1].num_100_500;
		temp[3] = Cof[1].num_500_1000;
		temp[4] = Cof[1].num_1000_1500;
		temp[5] = Cof[1].num_1500_3000;
		temp[6] = Cof[1].num_3000_8000;
		temp[7] = Cof[1].num_8000_13000;	
		temp[8] = Cof[1].num_13000_20000;	
		temp[9] = Cof[1].num_20000_30000;	

		STMFLASH_Write(FLASH_COF1_PM10,(u16*)temp,10);
	  
}

/*
 * 函数名：raed_cof0_pm2_5
 * 描述  ：读取flash数据
 * 输入  ：
 *         
 *        
 *         
 * 输出  ：无
 * 返回  ：无
 * 调用  ：
 */
void raed_cof1_pm10(void){

		u8 t;
		STMFLASH_Read(FLASH_COF1_PM10,(u16*)temp,10);

	
		 Cof[1].num_0_50 				= temp[0];
		 Cof[1].num_50_100 			= temp[1];	
		 Cof[1].num_100_500			= temp[2];
		 Cof[1].num_500_1000 		= temp[3];
		 Cof[1].num_1000_1500 	= temp[4];
		 Cof[1].num_1500_3000 	= temp[5];
		 Cof[1].num_3000_8000 	= temp[6];
		 Cof[1].num_8000_13000 	= temp[7];
		 Cof[1].num_13000_20000 = temp[8];
		 Cof[1].num_20000_30000 = temp[9];	
		if(temp[0] > 0XFFFE)	
		{
		
		 Cof[1].num_0_50 				= COEFFICIENT;
		 Cof[1].num_50_100 			= COEFFICIENT;	
		 Cof[1].num_100_500			= COEFFICIENT;
		 Cof[1].num_500_1000 		= COEFFICIENT;
		 Cof[1].num_1000_1500 	= COEFFICIENT;
		 Cof[1].num_1500_3000 	= COEFFICIENT;
		 Cof[1].num_3000_8000 	= COEFFICIENT;
		 Cof[1].num_8000_13000 	= COEFFICIENT;
		 Cof[1].num_13000_20000 = COEFFICIENT;
		 Cof[1].num_20000_30000 = COEFFICIENT;
		
		 RS485_RDEN_PORT->ODR |= RS485_RDEN_PIN;//High Send
		 printf("Parameters are not written using default parameters\r\n");		
		 RS485_RDEN_PORT->ODR &= ~(RS485_RDEN_PIN);//Low Rev
		}
	 else{
	
		for(t=0;t<10;t++)
		{
			RS485_RDEN_PORT->ODR |= RS485_RDEN_PIN;//High Send
			printf("Cof1_%d:%d\r\n",t,temp[t]);
			RS485_RDEN_PORT->ODR &= ~(RS485_RDEN_PIN);//Low Rev
			
		
		}

	}

}
/*
 * 函数名：write_flash_cof0_pm2_5
 * 描述  ：数据写入flash
 * 输入  ：
 *         
 *        
 *         
 * 输出  ：无
 * 返回  ：无
 * 调用  ：
 */
void write_flash_cof2_tsp(void)    //sampling coefficient
{

		temp[0] = Cof[2].num_0_50;
		temp[1] = Cof[2].num_50_100;	
		temp[2] = Cof[2].num_100_500;
		temp[3] = Cof[2].num_500_1000;
		temp[4] = Cof[2].num_1000_1500;
		temp[5] = Cof[2].num_1500_3000;
		temp[6] = Cof[2].num_3000_8000;
		temp[7] = Cof[2].num_8000_13000;	
		temp[8] = Cof[2].num_13000_20000;	
		temp[9] = Cof[2].num_20000_30000;	

		STMFLASH_Write(FLASH_COF2_TSP,(u16*)temp,10);
	  
}

/*
 * 函数名：raed_cof0_pm2_5
 * 描述  ：读取flash数据
 * 输入  ：
 *         
 *        
 *         
 * 输出  ：无
 * 返回  ：无
 * 调用  ：
 */
void raed_cof2_tsp(void){

				u8 t;
		STMFLASH_Read(FLASH_COF2_TSP,(u16*)temp,10);

	
		 Cof[2].num_0_50 				= temp[0];
		 Cof[2].num_50_100 			= temp[1];	
		 Cof[2].num_100_500			= temp[2];
		 Cof[2].num_500_1000 		= temp[3];
		 Cof[2].num_1000_1500 	= temp[4];
		 Cof[2].num_1500_3000 	= temp[5];
		 Cof[2].num_3000_8000 	= temp[6];
		 Cof[2].num_8000_13000 	= temp[7];
		 Cof[2].num_13000_20000 = temp[8];
		 Cof[2].num_20000_30000 = temp[9];	
		if(temp[0] > 0XFFFE)	
		{
		
		 Cof[2].num_0_50 				= COEFFICIENT;
		 Cof[2].num_50_100 			= COEFFICIENT;	
		 Cof[2].num_100_500			= COEFFICIENT;
		 Cof[2].num_500_1000 		= COEFFICIENT;
		 Cof[2].num_1000_1500 	= COEFFICIENT;
		 Cof[2].num_1500_3000 	= COEFFICIENT;
		 Cof[2].num_3000_8000 	= COEFFICIENT;
		 Cof[2].num_8000_13000 	= COEFFICIENT;
		 Cof[2].num_13000_20000 = COEFFICIENT;
		 Cof[2].num_20000_30000 = COEFFICIENT;	
		 RS485_RDEN_PORT->ODR |= RS485_RDEN_PIN;//High Send
		 printf("Parameters are not written using default parameters\r\n");		
		 RS485_RDEN_PORT->ODR &= ~(RS485_RDEN_PIN);//Low Rev
		}
	 else{
	
		for(t=0;t<10;t++)
		{
			RS485_RDEN_PORT->ODR |= RS485_RDEN_PIN;//High Send
			printf("Cof2_%d:%d\r\n",t,temp[t]);
			RS485_RDEN_PORT->ODR &= ~(RS485_RDEN_PIN);//Low Rev
			
		}

	}

}
void write_Zero_Calibration(void)
{
		falsh_DEVICE_ID[0] = 	mySensorDatas.Deashing_Period;
		falsh_DEVICE_ID[1] =  10;
 		STMFLASH_Write(FLASH_ZERO_CALIBRATION ,(u16*)falsh_DEVICE_ID,2);

}
void write_SPEED(void)
{
		falsh_DEVICE_ID[0] = 	mySensorDatas.SPEED;
		falsh_DEVICE_ID[1] =  10;
 		STMFLASH_Write(FLASH_SPEED ,(u16*)falsh_DEVICE_ID,2);

}
void write_DEVICE_ID(void)
{
		falsh_DEVICE_ID[0] = 	DEVICE_ID;
		falsh_DEVICE_ID[1] =  10;
 		STMFLASH_Write(FLASH_DEVICE_ID_ADDR ,(u16*)falsh_DEVICE_ID,2);

}
void read_DEVICE_ID(void)
{
		
		STMFLASH_Read(FLASH_DEVICE_ID_ADDR,(u16*)falsh_DEVICE_ID,2);
		DEVICE_ID = 	falsh_DEVICE_ID[0];
		if(DEVICE_ID > 0XFE)
		{
			DEVICE_ID = 30;
		 RS485_RDEN_PORT->ODR |= RS485_RDEN_PIN;//High Send
		 printf("Parameters are not written using default parameters\r\n");		
		 RS485_RDEN_PORT->ODR &= ~(RS485_RDEN_PIN);//Low Rev
		}
			RS485_RDEN_PORT->ODR |= RS485_RDEN_PIN;//High Send
			printf("Sampling_period:%d\r\n",DEVICE_ID);
			RS485_RDEN_PORT->ODR &= ~(RS485_RDEN_PIN);//Low Rev

//		data_display_password_8byte(0X15AF,DEVICE_ID);
		BSP_OS_TimeDly(100);
}
void read_SPEED(void)
{
		
		STMFLASH_Read(FLASH_SPEED,(u16*)falsh_DEVICE_ID,2);
		mySensorDatas.SPEED = falsh_DEVICE_ID[0];
		if(mySensorDatas.SPEED > 0XFE)
		{
		 mySensorDatas.SPEED = 90;
		 RS485_RDEN_PORT->ODR |= RS485_RDEN_PIN;//High Send
		 printf("Parameters are not written using default parameters\r\n");		
		 RS485_RDEN_PORT->ODR &= ~(RS485_RDEN_PIN);//Low Rev
		}
			RS485_RDEN_PORT->ODR |= RS485_RDEN_PIN;//High Send
			printf("SPEED:%d\r\n",mySensorDatas.SPEED);
			RS485_RDEN_PORT->ODR &= ~(RS485_RDEN_PIN);//Low Rev

//		data_display_password_8byte(0X15AF,DEVICE_ID);
		BSP_OS_TimeDly(100);
}

void read_Zero_Calibration(void)
{
		
		STMFLASH_Read(FLASH_ZERO_CALIBRATION,(u16*)falsh_DEVICE_ID,2);
		mySensorDatas.Deashing_Period = falsh_DEVICE_ID[0];
		if(mySensorDatas.Deashing_Period > 0XFE)
		{
		 mySensorDatas.Deashing_Period = 10;
		 RS485_RDEN_PORT->ODR |= RS485_RDEN_PIN;//High Send
		 printf("Parameters are not written using default parameters\r\n");		
		 RS485_RDEN_PORT->ODR &= ~(RS485_RDEN_PIN);//Low Rev
		}
			RS485_RDEN_PORT->ODR |= RS485_RDEN_PIN;//High Send
			printf("Zero_Calibration:%d\r\n",mySensorDatas.Deashing_Period);
			RS485_RDEN_PORT->ODR &= ~(RS485_RDEN_PIN);//Low Rev

//		data_display_password_8byte(0X15AF,DEVICE_ID);
		BSP_OS_TimeDly(100);
}
/*
 * 函数名：Get_PM2_5_0_50
 * 描述  ：获取PM2_5系数数据
 * 输入  ：
 *         
 *        
 *         
 * 输出  ：无
 * 返回  ：无
 * 调用  ：
 */
void Get_PM2_5_0_50(void){

/*
u8	USART_send1[7]={0x5a,0xa5,0x04,0x83,0x17,0x00,0x01};

		CLR_Buf6();
		UART6_WriteBuffer((uint8_t *)USART_send1,7);
		
		BSP_OS_TimeDly(10);


				if((USART6_RX_BUF[0]==0x5A)&(USART6_RX_BUF[1]==0xA5)&(USART6_RX_BUF[4]==0x17)&(USART6_RX_BUF[5]==0x00)&(USART6_RX_BUF[8]!=0x00))
				{
				
				     sampling_data.PM2_5_0_50 = USART6_RX_BUF[8];
						 CLR_Buf6();
	
				
				}
*/
					
}
/*
 * 函数名：Get_PM2_5_51_150
 * 描述  ：获取PM2_5系数数据
 * 输入  ：
 *         
 *        
 *         
 * 输出  ：无
 * 返回  ：无
 * 调用  ：
 */
void Get_PM2_5_51_150(void){

/*
u8	USART_send1[7]={0x5a,0xa5,0x04,0x83,0x17,0x02,0x01};

		CLR_Buf6();
		UART6_WriteBuffer((uint8_t *)USART_send1,7);
		BSP_OS_TimeDly(10);


				if((USART6_RX_BUF[0]==0x5A)&(USART6_RX_BUF[1]==0xA5)&(USART6_RX_BUF[4]==0x17)&(USART6_RX_BUF[5]==0x02))
				{
				
				     sampling_data.PM2_5_51_150 = USART6_RX_BUF[8];
						 CLR_Buf6();
						
				
				}

	*/	
					   
}
/*
 * 函数名：Get_PM2_5_151_300
 * 描述  ：获取PM2_5系数数据
 * 输入  ：
 *         
 *        
 *         
 * 输出  ：无
 * 返回  ：无
 * 调用  ：
 */
void Get_PM2_5_151_300(void){
/*

u8	USART_send1[7]={0x5a,0xa5,0x04,0x83,0x17,0x08,0x01};

		CLR_Buf6();
		UART6_WriteBuffer((uint8_t *)USART_send1,7);
		BSP_OS_TimeDly(10);


				if((USART6_RX_BUF[0]==0x5A)&(USART6_RX_BUF[1]==0xA5)&(USART6_RX_BUF[4]==0x17)&(USART6_RX_BUF[5]==0x08))
				{
				
				     sampling_data.PM2_5_151_300 = USART6_RX_BUF[8];
						 CLR_Buf6();
					   
			
				
				}

	*/		
}
/*
 * 函数名：Get_PM2_5_300
 * 描述  ：获取PM2_5系数数据
 * 输入  ：
 *         
 *        
 *         
 * 输出  ：无
 * 返回  ：无
 * 调用  ：
 */
void Get_PM2_5_300(void){

/*
u8	USART_send1[7]={0x5a,0xa5,0x04,0x83,0x17,0x0C,0x01};

		CLR_Buf6();
		UART6_WriteBuffer((uint8_t *)USART_send1,7);
		BSP_OS_TimeDly(10);


				if((USART6_RX_BUF[0]==0x5A)&(USART6_RX_BUF[1]==0xA5)&(USART6_RX_BUF[4]==0x17)&(USART6_RX_BUF[5]==0x0C))
				{
				
				     sampling_data.PM2_5_300 = USART6_RX_BUF[8];
						 CLR_Buf6();
					   
				
				
				}
				
	*/		
}
/*
 * 函数名：Get_PM10_0_50
 * 描述  ：获取PM2_5系数数据
 * 输入  ：
 *         
 *        
 *         
 * 输出  ：无
 * 返回  ：无
 * 调用  ：
 */
void Get_PM10_0_50(void){
/*

u8	USART_send1[7]={0x5a,0xa5,0x04,0x83,0x17,0x04,0x01};

		CLR_Buf6();
		UART6_WriteBuffer((uint8_t *)USART_send1,7);
		BSP_OS_TimeDly(10);


				if((USART6_RX_BUF[0]==0x5A)&(USART6_RX_BUF[1]==0xA5)&(USART6_RX_BUF[4]==0x17)&(USART6_RX_BUF[5]==0x04))
				{
				
				     sampling_data.PM10_0_50 = USART6_RX_BUF[8];
						 CLR_Buf6();
					   
				
				
				}
*/
			
}
/*
 * 函数名：Get_PM10_51_150
 * 描述  ：获取PM2_5系数数据
 * 输入  ：
 *         
 *        
 *         
 * 输出  ：无
 * 返回  ：无
 * 调用  ：
 */
void Get_PM10_51_150(void){
/*

u8	USART_send1[7]={0x5a,0xa5,0x04,0x83,0x17,0x06,0x01};

		CLR_Buf6();
		UART6_WriteBuffer((uint8_t *)USART_send1,7);
		BSP_OS_TimeDly(10);


				if((USART6_RX_BUF[0]==0x5A)&(USART6_RX_BUF[1]==0xA5)&(USART6_RX_BUF[4]==0x17)&(USART6_RX_BUF[5]==0x06))
				{
				
				     sampling_data.PM10_51_150 = USART6_RX_BUF[8];
						 CLR_Buf6();
					   
	
				
				}
*/
			
}
/*
 * 函数名：Get_PM10_151_300
 * 描述  ：获取PM2_5系数数据
 * 输入  ：
 *         
 *        
 *         
 * 输出  ：无
 * 返回  ：无
 * 调用  ：
 */
void Get_PM10_151_300(void){

/*
u8	USART_send1[7]={0x5a,0xa5,0x04,0x83,0x17,0x0A,0x01};

		CLR_Buf6();
		UART6_WriteBuffer((uint8_t *)USART_send1,7);
		BSP_OS_TimeDly(10);


				if((USART6_RX_BUF[0]==0x5A)&(USART6_RX_BUF[1]==0xA5)&(USART6_RX_BUF[4]==0x17)&(USART6_RX_BUF[5]==0x0A))
				{
				
				     sampling_data.PM10_151_300 = USART6_RX_BUF[8];
						 CLR_Buf6();
					   
		
				
				}
*/
			
}
void Get_PM10_300(void){

/*
u8	USART_send1[7]={0x5a,0xa5,0x04,0x83,0x17,0x0E,0x01};

		CLR_Buf6();
		UART6_WriteBuffer((uint8_t *)USART_send1,7);
		BSP_OS_TimeDly(10);


				if((USART6_RX_BUF[0]==0x5A)&(USART6_RX_BUF[1]==0xA5)&(USART6_RX_BUF[4]==0x17)&(USART6_RX_BUF[5]==0x0E))
				{
				
				     sampling_data.PM10_300 = USART6_RX_BUF[8];
						 CLR_Buf6();
					   
		
				
				}
*/
			
}
void Get_Sampling_Zero_Calibration(void){

		//5A A5 06 83 10 28 01 00 05 报警设置界面确定按键返回值
	  //5A A5 06 83 10 2A 01 00 06  返回按键

u8	USART_send5[18]={0x5a,0xa5,0x0F,0x82,0x17,0x34,0xB2,0xCE,0xCA,0xFD,0xC9,0xE8,0XD6,0XC3,0XB3,0XC9,0XB9,0XA6};
u8	USART_send_GBK[22]={0x5a,0xa5,0x13,0x82,0x17,0x34,0xB2,0xCE,0xCA,0xFD,0xD0,0xB4,0XC8,0XEB,0XD6,0XD0,0XC7,0XEB,0XC9,0XD4,0XB5,0XC8};
u8	USART_send_GBK_0[22]={0x5a,0xa5,0x13,0x82,0x17,0x34,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0X00,0X00,0X00,0X00,0X00,0X00};	
char	temp_0A[]={0X5A,0XA5,0X06,0X83,0X10,0X41,0X01,0X00,0X07};     //参数设置按键返回值
char	temp_08[]={0X5A,0XA5,0X06,0X83,0XFF,0X12,0X01,0X00,0X08};     //参数设置按键返回值
char	temp_14[]={0X5A,0XA5,0X06,0X83,0XFF,0X14,0X01,0X00,0X08};     //参数设置按键返回值
		  if(Find_usart6((char *)temp_0A))
			{
				CLR_Buf6();
				
				UART6_WriteBuffer((uint8_t *)USART_send_GBK,22);	
				printf("get....\r\n");
				
				Get_Zero_Calibration();
				
				printf("Get_Zero_Calibration:%d\r\n",mySensorDatas.Deashing_Period);	
				
        if(mySensorDatas.Deashing_Period !=0 )	
				{

				write_Zero_Calibration();
				UART6_WriteBuffer((uint8_t *)USART_send_GBK_0,22);
				BSP_OS_TimeDly(50);
				CLR_Buf6();					
				UART6_WriteBuffer((uint8_t *)USART_send5,18);		
				BSP_OS_TimeDly(50);
				UART6_WriteBuffer((uint8_t *)temp_01,10);					
				printf("get succeed\r\n");					
				avg_X_N.LCD_modetemp=1;	
				CLR_Buf6();
				}
			
			}
			else if(Find_usart6((char *)temp_08))
			{
				
				UART6_WriteBuffer((uint8_t *)temp_01,10);			
				avg_X_N.LCD_modetemp=1;	
				CLR_Buf6();
			}
			else if(Find_usart6((char *)temp_14))
			{
				
				UART6_WriteBuffer((uint8_t *)temp_01,10);			
				times.HOUR = mySensorDatas.Deashing_Period;
				avg_X_N.LCD_modetemp=1;	
				CLR_Buf6();
			}



}
void Get_Sampling_Speed_regulation_data(void){

		//5A A5 06 83 10 28 01 00 05 报警设置界面确定按键返回值
	  //5A A5 06 83 10 2A 01 00 06  返回按键

u8	USART_send5[18]={0x5a,0xa5,0x0F,0x82,0x17,0x34,0xB2,0xCE,0xCA,0xFD,0xC9,0xE8,0XD6,0XC3,0XB3,0XC9,0XB9,0XA6};
u8	USART_send_GBK[22]={0x5a,0xa5,0x13,0x82,0x17,0x34,0xB2,0xCE,0xCA,0xFD,0xD0,0xB4,0XC8,0XEB,0XD6,0XD0,0XC7,0XEB,0XC9,0XD4,0XB5,0XC8};
u8	USART_send_GBK_0[22]={0x5a,0xa5,0x13,0x82,0x17,0x34,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0X00,0X00,0X00,0X00,0X00,0X00};	
char	temp_0A[]={0X5A,0XA5,0X06,0X83,0X10,0X41,0X01,0X00,0X07};     //参数设置按键返回值
char	temp_08[]={0X5A,0XA5,0X06,0X83,0XFF,0X12,0X01,0X00,0X08};     //参数设置按键返回值
		  if(Find_usart6((char *)temp_0A))
			{
				CLR_Buf6();
				
				UART6_WriteBuffer((uint8_t *)USART_send_GBK,22);	
				printf("get....\r\n");
				
				Get_Speed_period();
				
				printf("SPEED:%d\r\n",mySensorDatas.SPEED);	
				
        if(DEVICE_ID !=0 )	
				{

				write_SPEED();
				UART6_WriteBuffer((uint8_t *)USART_send_GBK_0,22);
				BSP_OS_TimeDly(50);
				CLR_Buf6();					
				UART6_WriteBuffer((uint8_t *)USART_send5,18);		
				BSP_OS_TimeDly(50);
				UART6_WriteBuffer((uint8_t *)temp_01,10);					
				printf("get succeed\r\n");					
				avg_X_N.LCD_modetemp=1;	
				CLR_Buf6();
				}
			
			}
			else if(Find_usart6((char *)temp_08))
			{
				
				UART6_WriteBuffer((uint8_t *)temp_01,10);			
				avg_X_N.LCD_modetemp=1;	
				CLR_Buf6();
			}



}

void Get_Sampling_period_data(void){

		//5A A5 06 83 10 28 01 00 05 报警设置界面确定按键返回值
	  //5A A5 06 83 10 2A 01 00 06  返回按键

u8	USART_send5[18]={0x5a,0xa5,0x0F,0x82,0x17,0x34,0xB2,0xCE,0xCA,0xFD,0xC9,0xE8,0XD6,0XC3,0XB3,0XC9,0XB9,0XA6};
u8	USART_send_GBK[22]={0x5a,0xa5,0x13,0x82,0x17,0x34,0xB2,0xCE,0xCA,0xFD,0xD0,0xB4,0XC8,0XEB,0XD6,0XD0,0XC7,0XEB,0XC9,0XD4,0XB5,0XC8};
u8	USART_send_GBK_0[22]={0x5a,0xa5,0x13,0x82,0x17,0x34,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0X00,0X00,0X00,0X00,0X00,0X00};	
char	temp_0A[]={0X5A,0XA5,0X06,0X83,0X10,0X41,0X01,0X00,0X07};     //参数设置按键返回值
char	temp_08[]={0X5A,0XA5,0X06,0X83,0XFF,0X12,0X01,0X00,0X08};     //参数设置按键返回值
		  if(Find_usart6((char *)temp_0A))
			{
				CLR_Buf6();
				
				UART6_WriteBuffer((uint8_t *)USART_send_GBK,22);	
				printf("get....\r\n");
				Get_Sampling_period();
				printf("Sampling_period:%d\r\n",DEVICE_ID);	
				
        if(DEVICE_ID !=0 )	
				{

				write_DEVICE_ID();
				UART6_WriteBuffer((uint8_t *)USART_send_GBK_0,22);
				BSP_OS_TimeDly(50);
				CLR_Buf6();					
				UART6_WriteBuffer((uint8_t *)USART_send5,18);		
				BSP_OS_TimeDly(50);
				UART6_WriteBuffer((uint8_t *)temp_01,10);					
				printf("get succeed\r\n");					
				avg_X_N.LCD_modetemp=1;	
				CLR_Buf6();
				}
			
			}
			else if(Find_usart6((char *)temp_08))
			{
				
				UART6_WriteBuffer((uint8_t *)temp_01,10);			
				avg_X_N.LCD_modetemp=1;	
				CLR_Buf6();
			}



}
/*
 * 函数名：Get_Zero_Calibration
 * 描述  ：获取自动校零时间数据
 * 输入  ：
 *         
 *        
 *         
 * 输出  ：无
 * 返回  ：无
 * 调用  ：
 */
void Get_Zero_Calibration(void)
{

u8	USART_send1[7]={0x5a,0xa5,0x04,0x83,0x10,0x62,0x01};

		CLR_Buf6();
		UART6_WriteBuffer((uint8_t *)USART_send1,7);
		
		BSP_OS_TimeDly(10);


				if((USART6_RX_BUF[0]==0x5A)&(USART6_RX_BUF[1]==0xA5)&(USART6_RX_BUF[4]==0x10)&(USART6_RX_BUF[5]==0x62)&(USART6_RX_BUF[8]!=0x00))
				{
				
				     mySensorDatas.Deashing_Period = USART6_RX_BUF[8];
						 CLR_Buf6();
	
				
				}


}


/*
 * 函数名：Get_Speed_period
 * 描述  ：获取PWM占空比数据
 * 输入  ：
 *         
 *        
 *         
 * 输出  ：无
 * 返回  ：无
 * 调用  ：
 */
void Get_Speed_period(void){


u8	USART_send1[7]={0x5a,0xa5,0x04,0x83,0x10,0x52,0x01};

		CLR_Buf6();
		UART6_WriteBuffer((uint8_t *)USART_send1,7);
		
		BSP_OS_TimeDly(10);


				if((USART6_RX_BUF[0]==0x5A)&(USART6_RX_BUF[1]==0xA5)&(USART6_RX_BUF[4]==0x10)&(USART6_RX_BUF[5]==0x52)&(USART6_RX_BUF[8]!=0x00))
				{
				
				     mySensorDatas.SPEED = USART6_RX_BUF[8];
						 CLR_Buf6();
	
				
				}

					
}
/*
 * 函数名：Get_Sampling_period
 * 描述  ：获取PM2_5系数数据
 * 输入  ：
 *         
 *        
 *         
 * 输出  ：无
 * 返回  ：无
 * 调用  ：
 */
void Get_Sampling_period(void){


u8	USART_send1[7]={0x5a,0xa5,0x04,0x83,0x10,0x32,0x01};

		CLR_Buf6();
		UART6_WriteBuffer((uint8_t *)USART_send1,7);
		
		BSP_OS_TimeDly(10);


				if((USART6_RX_BUF[0]==0x5A)&(USART6_RX_BUF[1]==0xA5)&(USART6_RX_BUF[4]==0x10)&(USART6_RX_BUF[5]==0x32)&(USART6_RX_BUF[8]!=0x00))
				{
				
				     DEVICE_ID = USART6_RX_BUF[8];
						 CLR_Buf6();
	
				
				}

					
}
void Get_cof0_pm2_5_data(void){

		//5A A5 06 83 10 28 01 00 05 报警设置界面确定按键返回值
	  //5A A5 06 83 10 2A 01 00 06  返回按键

u8	USART_send5[18]={0x5a,0xa5,0x0F,0x82,0x17,0x34,0xB2,0xCE,0xCA,0xFD,0xC9,0xE8,0XD6,0XC3,0XB3,0XC9,0XB9,0XA6};
u8	USART_send_GBK[22]={0x5a,0xa5,0x13,0x82,0x17,0x34,0xB2,0xCE,0xCA,0xFD,0xD0,0xB4,0XC8,0XEB,0XD6,0XD0,0XC7,0XEB,0XC9,0XD4,0XB5,0XC8};
u8	USART_send_GBK_0[22]={0x5a,0xa5,0x13,0x82,0x17,0x34,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0X00,0X00,0X00,0X00,0X00,0X00};	
char	temp_0A[]={0X5A,0XA5,0X06,0X83,0X10,0X41,0X01,0X00,0X07};     //参数设置按键返回值
char	temp_08[]={0X5A,0XA5,0X06,0X83,0XFF,0X12,0X01,0X00,0X08};     //参数设置按键返回值
		  if(Find_usart6((char *)temp_0A))
			{
				CLR_Buf6();
				
				UART6_WriteBuffer((uint8_t *)USART_send_GBK,22);	
				printf("get....\r\n");
				
//						 Cof[0].num_0_50 				= 10;
//						 Cof[0].num_50_100 			= 10;	
//						 Cof[0].num_100_500			= 10;
//						 Cof[0].num_500_1000 		= 10;
//						 Cof[0].num_1000_1500 	= 10;
//						 Cof[0].num_1500_3000 	= 10;
//						 Cof[0].num_3000_8000 	= 10;
//						 Cof[0].num_8000_13000 	= 10;
//						 Cof[0].num_13000_20000 = 10;
//						 Cof[0].num_20000_30000 = 10;	
				Get_cof0_PM2_5_0_50();
				Get_cof0_PM2_5_50_100();
				Get_cof0_PM2_5_100_500();
				Get_cof0_PM2_5_500_1000();
				Get_cof0_PM2_5_1000_1500();
				Get_cof0_PM2_5_1500_3000();
				Get_cof0_PM2_5_3000_8000();
				Get_cof0_PM2_5_8000_13000();
				Get_cof0_PM2_5_13000_20000();
				Get_cof0_PM2_5_20000_30000();
		
				printf("Cof[0].num_0_50:%d\r\n",Cof[0].num_0_50);	
				printf("Cof[0].num_50_100:%d\r\n",Cof[0].num_50_100);	
				printf("Cof[0].num_100_500:%d\r\n",Cof[0].num_100_500);	
				printf("Cof[0].num_500_1000:%d\r\n",Cof[0].num_500_1000);	
				printf("Cof[0].num_1000_1500:%d\r\n",Cof[0].num_1000_1500);	
				printf("Cof[0].num_1500_3000:%d\r\n",Cof[0].num_1500_3000);	
				printf("Cof[0].num_3000_8000:%d\r\n",Cof[0].num_3000_8000);	
				printf("Cof[0].num_8000_13000:%d\r\n",Cof[0].num_8000_13000);	
				printf("Cof[0].num_13000_20000:%d\r\n",Cof[0].num_13000_20000);	
				printf("Cof[0].num_20000_30000:%d\r\n",Cof[0].num_20000_30000);					
        if((Cof[0].num_50_100 !=0 ) & (Cof[0].num_100_500 !=0 ) & (Cof[0].num_20000_30000 !=0 ))	
				{

				write_flash_cof0_pm2_5();
				UART6_WriteBuffer((uint8_t *)USART_send_GBK_0,22);
				BSP_OS_TimeDly(50);
				CLR_Buf6();					
				UART6_WriteBuffer((uint8_t *)USART_send5,18);		
				BSP_OS_TimeDly(50);
				UART6_WriteBuffer((uint8_t *)temp_01,10);					
				printf("get succeed\r\n");					
				avg_X_N.LCD_modetemp=1;	
				CLR_Buf6();
				}
			
			}
			else if(Find_usart6((char *)temp_08))
			{
				
				UART6_WriteBuffer((uint8_t *)temp_01,10);			
				avg_X_N.LCD_modetemp=1;	
				CLR_Buf6();
			}



}
void Get_cof1_pm10_data(void){

		//5A A5 06 83 10 28 01 00 05 报警设置界面确定按键返回值
	  //5A A5 06 83 10 2A 01 00 06  返回按键

u8	USART_send5[18]={0x5a,0xa5,0x0F,0x82,0x17,0x34,0xB2,0xCE,0xCA,0xFD,0xC9,0xE8,0XD6,0XC3,0XB3,0XC9,0XB9,0XA6};
u8	USART_send_GBK[22]={0x5a,0xa5,0x13,0x82,0x17,0x34,0xB2,0xCE,0xCA,0xFD,0xD0,0xB4,0XC8,0XEB,0XD6,0XD0,0XC7,0XEB,0XC9,0XD4,0XB5,0XC8};
u8	USART_send_GBK_0[22]={0x5a,0xa5,0x13,0x82,0x17,0x34,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0X00,0X00,0X00,0X00,0X00,0X00};	
char	temp_0A[]={0X5A,0XA5,0X06,0X83,0X10,0X41,0X01,0X00,0X07};     //参数设置按键返回值
char	temp_08[]={0X5A,0XA5,0X06,0X83,0XFF,0X12,0X01,0X00,0X08};     //参数设置按键返回值
		  if(Find_usart6((char *)temp_0A))
			{
				CLR_Buf6();
				
				UART6_WriteBuffer((uint8_t *)USART_send_GBK,22);	
				printf("get....\r\n");
				
				Get_cof1_PM10_0_50();
				Get_cof1_PM10_50_100();
				Get_cof1_PM10_100_500();
				Get_cof1_PM10_500_1000();
				Get_cof1_PM10_1000_1500();
				Get_cof1_PM10_1500_3000();
				Get_cof1_PM10_3000_8000();
				Get_cof1_PM10_8000_13000();
				Get_cof1_PM10_13000_20000();
				Get_cof1_PM10_20000_30000();
		
				printf("Cof[1].num_0_50:%d\r\n",Cof[1].num_0_50);	
				printf("Cof[1].num_50_100:%d\r\n",Cof[1].num_50_100);	
				printf("Cof[1].num_100_500:%d\r\n",Cof[1].num_100_500);	
				printf("Cof[1].num_500_1000:%d\r\n",Cof[1].num_500_1000);	
				printf("Cof[1].num_1000_1500:%d\r\n",Cof[1].num_1000_1500);	
				printf("Cof[1].num_1500_3000:%d\r\n",Cof[1].num_1500_3000);	
				printf("Cof[1].num_3000_8000:%d\r\n",Cof[1].num_3000_8000);	
				printf("Cof[1].num_8000_13000:%d\r\n",Cof[1].num_8000_13000);	
				printf("Cof[1].num_13000_20000:%d\r\n",Cof[1].num_13000_20000);	
				printf("Cof[1].num_20000_30000:%d\r\n",Cof[1].num_20000_30000);					
        if((Cof[1].num_50_100 !=0 ) & (Cof[1].num_100_500 !=0 ) & (Cof[1].num_20000_30000 !=0 ))	
				{

				write_flash_cof1_pm10();
				UART6_WriteBuffer((uint8_t *)USART_send_GBK_0,22);
				BSP_OS_TimeDly(50);
				CLR_Buf6();					
				UART6_WriteBuffer((uint8_t *)USART_send5,18);		
				BSP_OS_TimeDly(50);
				UART6_WriteBuffer((uint8_t *)temp_01,10);					
				printf("get succeed\r\n");					
				avg_X_N.LCD_modetemp=1;	
				CLR_Buf6();
				}
			
			}
			else if(Find_usart6((char *)temp_08))
			{
				
				UART6_WriteBuffer((uint8_t *)temp_01,10);			
				avg_X_N.LCD_modetemp=1;	
				CLR_Buf6();
			}



}
void Get_cof2_tsp_data(void){

		//5A A5 06 83 10 28 01 00 05 报警设置界面确定按键返回值
	  //5A A5 06 83 10 2A 01 00 06  返回按键

u8	USART_send5[18]={0x5a,0xa5,0x0F,0x82,0x17,0x34,0xB2,0xCE,0xCA,0xFD,0xC9,0xE8,0XD6,0XC3,0XB3,0XC9,0XB9,0XA6};
u8	USART_send_GBK[22]={0x5a,0xa5,0x13,0x82,0x17,0x34,0xB2,0xCE,0xCA,0xFD,0xD0,0xB4,0XC8,0XEB,0XD6,0XD0,0XC7,0XEB,0XC9,0XD4,0XB5,0XC8};
u8	USART_send_GBK_0[22]={0x5a,0xa5,0x13,0x82,0x17,0x34,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0X00,0X00,0X00,0X00,0X00,0X00};	
char	temp_0A[]={0X5A,0XA5,0X06,0X83,0X10,0X41,0X01,0X00,0X07};     //参数设置按键返回值
char	temp_08[]={0X5A,0XA5,0X06,0X83,0XFF,0X12,0X01,0X00,0X08};     //参数设置按键返回值
		  if(Find_usart6((char *)temp_0A))
			{
				CLR_Buf6();
				
				UART6_WriteBuffer((uint8_t *)USART_send_GBK,22);	
				printf("get....\r\n");
				
				Get_cof2_tsp_0_50();
				Get_cof2_tsp_50_100();
				Get_cof2_tsp_100_500();
				Get_cof2_tsp_500_1000();
				Get_cof2_tsp_1000_1500();
				Get_cof2_tsp_1500_3000();
				Get_cof2_tsp_3000_8000();
				Get_cof2_tsp_8000_13000();
				Get_cof2_tsp_13000_20000();
				Get_cof2_tsp_20000_30000();
		
				printf("Cof[2].num_0_50:%d\r\n",Cof[2].num_0_50);	
				printf("Cof[2].num_50_100:%d\r\n",Cof[2].num_50_100);	
				printf("Cof[2].num_100_500:%d\r\n",Cof[2].num_100_500);	
				printf("Cof[2].num_500_1000:%d\r\n",Cof[2].num_500_1000);	
				printf("Cof[2].num_1000_1500:%d\r\n",Cof[2].num_1000_1500);	
				printf("Cof[2].num_1500_3000:%d\r\n",Cof[2].num_1500_3000);	
				printf("Cof[2].num_3000_8000:%d\r\n",Cof[2].num_3000_8000);	
				printf("Cof[2].num_8000_13000:%d\r\n",Cof[2].num_8000_13000);	
				printf("Cof[2].num_13000_20000:%d\r\n",Cof[2].num_13000_20000);	
				printf("Cof[2].num_20000_30000:%d\r\n",Cof[2].num_20000_30000);					
        if((Cof[2].num_50_100 !=0 ) & (Cof[2].num_100_500 !=0 ) & (Cof[2].num_20000_30000 !=0 ))	
				{

				write_flash_cof2_tsp();
				UART6_WriteBuffer((uint8_t *)USART_send_GBK_0,22);
				BSP_OS_TimeDly(50);
				CLR_Buf6();					
				UART6_WriteBuffer((uint8_t *)USART_send5,18);		
				BSP_OS_TimeDly(50);
				UART6_WriteBuffer((uint8_t *)temp_01,10);					
				printf("get succeed\r\n");					
				avg_X_N.LCD_modetemp=1;	
				CLR_Buf6();
				}
			
			}
			else if(Find_usart6((char *)temp_08))
			{
				
				UART6_WriteBuffer((uint8_t *)temp_01,10);			
				avg_X_N.LCD_modetemp=1;	
				CLR_Buf6();
			}



}
/*
 * 函数名：Get_cof0_PM2_5_0_50
 * 描述  ：获取PM2_5系数数据
 * 输入  ：
 *         
 *        
 *         
 * 输出  ：无
 * 返回  ：无
 * 调用  ：
 */
void Get_cof0_PM2_5_0_50(void){


u8	USART_send1[7]={0x5a,0xa5,0x04,0x83,0x17,0x00,0x01};

		CLR_Buf6();
		UART6_WriteBuffer((uint8_t *)USART_send1,7);
		
		BSP_OS_TimeDly(10);


				if((USART6_RX_BUF[0]==0x5A)&(USART6_RX_BUF[1]==0xA5)&(USART6_RX_BUF[4]==0x17)&(USART6_RX_BUF[5]==0x00)&(USART6_RX_BUF[8]!=0x00))
				{

				     Cof[0].num_0_50 = (USART6_RX_BUF[7] << 8) |USART6_RX_BUF[8];
						 CLR_Buf6();
	
				
				}

					
}
/*
 * 函数名：Get_cof1_PM10_0_50
 * 描述  ：获取PM2_5系数数据
 * 输入  ：
 *         
 *        
 *         
 * 输出  ：无
 * 返回  ：无
 * 调用  ：
 */
void Get_cof1_PM10_0_50(void){


u8	USART_send1[7]={0x5a,0xa5,0x04,0x83,0x18,0x00,0x01};

		CLR_Buf6();
		UART6_WriteBuffer((uint8_t *)USART_send1,7);
		
		BSP_OS_TimeDly(10);


				if((USART6_RX_BUF[0]==0x5A)&(USART6_RX_BUF[1]==0xA5)&(USART6_RX_BUF[4]==0x18)&(USART6_RX_BUF[5]==0x00)&(USART6_RX_BUF[8]!=0x00))
				{
				
				     Cof[1].num_0_50 = (USART6_RX_BUF[7] << 8) |USART6_RX_BUF[8];
						 CLR_Buf6();
	
				
				}

					
}
/*
 * 函数名：Get_cof2_tsp_0_50
 * 描述  ：获取PM2_5系数数据
 * 输入  ：
 *         
 *        
 *         
 * 输出  ：无
 * 返回  ：无
 * 调用  ：
 */
void Get_cof2_tsp_0_50(void){


u8	USART_send1[7]={0x5a,0xa5,0x04,0x83,0x19,0x00,0x01};

		CLR_Buf6();
		UART6_WriteBuffer((uint8_t *)USART_send1,7);
		
		BSP_OS_TimeDly(10);


				if((USART6_RX_BUF[0]==0x5A)&(USART6_RX_BUF[1]==0xA5)&(USART6_RX_BUF[4]==0x19)&(USART6_RX_BUF[5]==0x00)&(USART6_RX_BUF[8]!=0x00))
				{
				
				     Cof[2].num_0_50 = (USART6_RX_BUF[7] << 8) |USART6_RX_BUF[8];
						 CLR_Buf6();
	
				
				}

					
}
/*
 * 函数名：Get_cof0_PM2_5_50_100
 * 描述  ：获取PM2_5系数数据
 * 输入  ：
 *         
 *        
 *         
 * 输出  ：无
 * 返回  ：无
 * 调用  ：
 */
void Get_cof0_PM2_5_50_100(void){


u8	USART_send1[7]={0x5a,0xa5,0x04,0x83,0x17,0x02,0x01};

		CLR_Buf6();
		UART6_WriteBuffer((uint8_t *)USART_send1,7);
		
		BSP_OS_TimeDly(10);


				if((USART6_RX_BUF[0]==0x5A)&(USART6_RX_BUF[1]==0xA5)&(USART6_RX_BUF[4]==0x17)&(USART6_RX_BUF[5]==0x02)&(USART6_RX_BUF[8]!=0x00))
				{
				
				     Cof[0].num_50_100 = (USART6_RX_BUF[7] << 8) |USART6_RX_BUF[8];
						 CLR_Buf6();
	
				
				}

					
}
/*
 * 函数名：Get_cof1_PM10_50_100
 * 描述  ：获取PM2_5系数数据
 * 输入  ：
 *         
 *        
 *         
 * 输出  ：无
 * 返回  ：无
 * 调用  ：
 */
void Get_cof1_PM10_50_100(void){


u8	USART_send1[7]={0x5a,0xa5,0x04,0x83,0x18,0x02,0x01};

		CLR_Buf6();
		UART6_WriteBuffer((uint8_t *)USART_send1,7);
		
		BSP_OS_TimeDly(10);


				if((USART6_RX_BUF[0]==0x5A)&(USART6_RX_BUF[1]==0xA5)&(USART6_RX_BUF[4]==0x18)&(USART6_RX_BUF[5]==0x02)&(USART6_RX_BUF[8]!=0x00))
				{
				
				     Cof[1].num_50_100 = (USART6_RX_BUF[7] << 8) |USART6_RX_BUF[8];
						 CLR_Buf6();
	
				
				}

					
}
/*
 * 函数名：Get_cof2_tsp_50_100
 * 描述  ：获取PM2_5系数数据
 * 输入  ：
 *         
 *        
 *         
 * 输出  ：无
 * 返回  ：无
 * 调用  ：
 */
void Get_cof2_tsp_50_100(void){


u8	USART_send1[7]={0x5a,0xa5,0x04,0x83,0x19,0x02,0x01};

		CLR_Buf6();
		UART6_WriteBuffer((uint8_t *)USART_send1,7);
		
		BSP_OS_TimeDly(10);


				if((USART6_RX_BUF[0]==0x5A)&(USART6_RX_BUF[1]==0xA5)&(USART6_RX_BUF[4]==0x19)&(USART6_RX_BUF[5]==0x02)&(USART6_RX_BUF[8]!=0x00))
				{
				
				     Cof[2].num_50_100 = (USART6_RX_BUF[7] << 8) |USART6_RX_BUF[8];
						 CLR_Buf6();
	
				
				}

					
}
/*
 * 函数名：Get_cof0_PM2_5_0_50
 * 描述  ：获取PM2_5系数数据
 * 输入  ：
 *         
 *        
 *         
 * 输出  ：无
 * 返回  ：无
 * 调用  ：
 */
void Get_cof0_PM2_5_100_500(void){


u8	USART_send1[7]={0x5a,0xa5,0x04,0x83,0x17,0x04,0x01};

		CLR_Buf6();
		UART6_WriteBuffer((uint8_t *)USART_send1,7);
		
		BSP_OS_TimeDly(10);


				if((USART6_RX_BUF[0]==0x5A)&(USART6_RX_BUF[1]==0xA5)&(USART6_RX_BUF[4]==0x17)&(USART6_RX_BUF[5]==0x04)&(USART6_RX_BUF[8]!=0x00))
				{
				
				     Cof[0].num_100_500 = (USART6_RX_BUF[7] << 8) |USART6_RX_BUF[8];
						 CLR_Buf6();
	
				
				}

					
}
/*
 * 函数名：Get_cof1_PM10_100_500
 * 描述  ：获取PM2_5系数数据
 * 输入  ：
 *         
 *        
 *         
 * 输出  ：无
 * 返回  ：无
 * 调用  ：
 */
void Get_cof1_PM10_100_500(void){


u8	USART_send1[7]={0x5a,0xa5,0x04,0x83,0x18,0x04,0x01};

		CLR_Buf6();
		UART6_WriteBuffer((uint8_t *)USART_send1,7);
		
		BSP_OS_TimeDly(10);


				if((USART6_RX_BUF[0]==0x5A)&(USART6_RX_BUF[1]==0xA5)&(USART6_RX_BUF[4]==0x18)&(USART6_RX_BUF[5]==0x04)&(USART6_RX_BUF[8]!=0x00))
				{
				
				     Cof[1].num_100_500 = (USART6_RX_BUF[7] << 8) |USART6_RX_BUF[8];
						 CLR_Buf6();
	
				
				}

					
}
/*
 * 函数名：Get_cof1_PM10_100_500
 * 描述  ：获取PM2_5系数数据
 * 输入  ：
 *         
 *        
 *         
 * 输出  ：无
 * 返回  ：无
 * 调用  ：
 */
void Get_cof2_tsp_100_500(void){


u8	USART_send1[7]={0x5a,0xa5,0x04,0x83,0x19,0x04,0x01};

		CLR_Buf6();
		UART6_WriteBuffer((uint8_t *)USART_send1,7);
		
		BSP_OS_TimeDly(10);


				if((USART6_RX_BUF[0]==0x5A)&(USART6_RX_BUF[1]==0xA5)&(USART6_RX_BUF[4]==0x19)&(USART6_RX_BUF[5]==0x04)&(USART6_RX_BUF[8]!=0x00))
				{
				
				     Cof[2].num_100_500 = (USART6_RX_BUF[7] << 8) |USART6_RX_BUF[8];
						 CLR_Buf6();
	
				
				}

					
}
/*
 * 函数名：Get_cof0_PM2_5_500_1000
 * 描述  ：获取PM2_5系数数据
 * 输入  ：
 *         
 *        
 *         
 * 输出  ：无
 * 返回  ：无
 * 调用  ：
 */
void Get_cof0_PM2_5_500_1000(void){


u8	USART_send1[7]={0x5a,0xa5,0x04,0x83,0x17,0x06,0x01};

		CLR_Buf6();
		UART6_WriteBuffer((uint8_t *)USART_send1,7);
		
		BSP_OS_TimeDly(10);


				if((USART6_RX_BUF[0]==0x5A)&(USART6_RX_BUF[1]==0xA5)&(USART6_RX_BUF[4]==0x17)&(USART6_RX_BUF[5]==0x06)&(USART6_RX_BUF[8]!=0x00))
				{
				
				     Cof[0].num_500_1000 = (USART6_RX_BUF[7] << 8) |USART6_RX_BUF[8];
						 CLR_Buf6();
	
				
				}

					
}
/*
 * 函数名：Get_cof1_PM10_500_1000
 * 描述  ：获取PM2_5系数数据
 * 输入  ：
 *         
 *        
 *         
 * 输出  ：无
 * 返回  ：无
 * 调用  ：
 */
void Get_cof1_PM10_500_1000(void){


u8	USART_send1[7]={0x5a,0xa5,0x04,0x83,0x18,0x06,0x01};

		CLR_Buf6();
		UART6_WriteBuffer((uint8_t *)USART_send1,7);
		
		BSP_OS_TimeDly(10);


				if((USART6_RX_BUF[0]==0x5A)&(USART6_RX_BUF[1]==0xA5)&(USART6_RX_BUF[4]==0x18)&(USART6_RX_BUF[5]==0x06)&(USART6_RX_BUF[8]!=0x00))
				{
				
				     Cof[1].num_500_1000 = (USART6_RX_BUF[7] << 8) |USART6_RX_BUF[8];
						 CLR_Buf6();
	
				
				}

					
}
/*
 * 函数名：Get_cof2_tsp_500_1000
 * 描述  ：获取PM2_5系数数据
 * 输入  ：
 *         
 *        
 *         
 * 输出  ：无
 * 返回  ：无
 * 调用  ：
 */
void Get_cof2_tsp_500_1000(void){


u8	USART_send1[7]={0x5a,0xa5,0x04,0x83,0x19,0x06,0x01};

		CLR_Buf6();
		UART6_WriteBuffer((uint8_t *)USART_send1,7);
		
		BSP_OS_TimeDly(10);


				if((USART6_RX_BUF[0]==0x5A)&(USART6_RX_BUF[1]==0xA5)&(USART6_RX_BUF[4]==0x19)&(USART6_RX_BUF[5]==0x06)&(USART6_RX_BUF[8]!=0x00))
				{
				
				     Cof[2].num_500_1000 = (USART6_RX_BUF[7] << 8) |USART6_RX_BUF[8];
						 CLR_Buf6();
	
				
				}

					
}
/*
 * 函数名：Get_cof0_PM2_5_0_50
 * 描述  ：获取PM2_5系数数据
 * 输入  ：
 *         
 *        
 *         
 * 输出  ：无
 * 返回  ：无
 * 调用  ：
 */
void Get_cof0_PM2_5_1000_1500(void){


u8	USART_send1[7]={0x5a,0xa5,0x04,0x83,0x17,0x08,0x01};

		CLR_Buf6();
		UART6_WriteBuffer((uint8_t *)USART_send1,7);
		
		BSP_OS_TimeDly(10);


				if((USART6_RX_BUF[0]==0x5A)&(USART6_RX_BUF[1]==0xA5)&(USART6_RX_BUF[4]==0x17)&(USART6_RX_BUF[5]==0x08)&(USART6_RX_BUF[8]!=0x00))
				{
				
				     Cof[0].num_1000_1500 = (USART6_RX_BUF[7] << 8) |USART6_RX_BUF[8];
						 CLR_Buf6();
	
				
				}

					
}
/*
 * 函数名：Get_cof1_PM10_1000_1500
 * 描述  ：获取PM2_5系数数据
 * 输入  ：
 *         
 *        
 *         
 * 输出  ：无
 * 返回  ：无
 * 调用  ：
 */
void Get_cof1_PM10_1000_1500(void){


u8	USART_send1[7]={0x5a,0xa5,0x04,0x83,0x18,0x08,0x01};

		CLR_Buf6();
		UART6_WriteBuffer((uint8_t *)USART_send1,7);
		
		BSP_OS_TimeDly(10);


				if((USART6_RX_BUF[0]==0x5A)&(USART6_RX_BUF[1]==0xA5)&(USART6_RX_BUF[4]==0x18)&(USART6_RX_BUF[5]==0x08)&(USART6_RX_BUF[8]!=0x00))
				{
				
				     Cof[1].num_1000_1500 = (USART6_RX_BUF[7] << 8) |USART6_RX_BUF[8];
						 CLR_Buf6();
	
				
				}

					
}
/*
 * 函数名：Get_cof2_tsp_1000_1500
 * 描述  ：获取PM2_5系数数据
 * 输入  ：
 *         
 *        
 *         
 * 输出  ：无
 * 返回  ：无
 * 调用  ：
 */
void Get_cof2_tsp_1000_1500(void){


u8	USART_send1[7]={0x5a,0xa5,0x04,0x83,0x19,0x08,0x01};

		CLR_Buf6();
		UART6_WriteBuffer((uint8_t *)USART_send1,7);
		
		BSP_OS_TimeDly(10);


				if((USART6_RX_BUF[0]==0x5A)&(USART6_RX_BUF[1]==0xA5)&(USART6_RX_BUF[4]==0x19)&(USART6_RX_BUF[5]==0x08)&(USART6_RX_BUF[8]!=0x00))
				{
				
				     Cof[2].num_1000_1500 = (USART6_RX_BUF[7] << 8) |USART6_RX_BUF[8];
						 CLR_Buf6();
	
				
				}

					
}
/*
 * 函数名：Get_cof0_PM2_5_0_50
 * 描述  ：获取PM2_5系数数据
 * 输入  ：
 *         
 *        
 *         
 * 输出  ：无
 * 返回  ：无
 * 调用  ：
 */
void Get_cof0_PM2_5_1500_3000(void){


u8	USART_send1[7]={0x5a,0xa5,0x04,0x83,0x17,0x0A,0x01};

		CLR_Buf6();
		UART6_WriteBuffer((uint8_t *)USART_send1,7);
		
		BSP_OS_TimeDly(10);


				if((USART6_RX_BUF[0]==0x5A)&(USART6_RX_BUF[1]==0xA5)&(USART6_RX_BUF[4]==0x17)&(USART6_RX_BUF[5]==0x0A)&(USART6_RX_BUF[8]!=0x00))
				{
				
				     Cof[0].num_1500_3000 = (USART6_RX_BUF[7] << 8) |USART6_RX_BUF[8];
						 CLR_Buf6();
	
				
				}

					
}
/*
 * 函数名：Get_cof0_PM2_5_0_50
 * 描述  ：获取PM2_5系数数据
 * 输入  ：
 *         
 *        
 *         
 * 输出  ：无
 * 返回  ：无
 * 调用  ：
 */
void Get_cof1_PM10_1500_3000(void){


u8	USART_send1[7]={0x5a,0xa5,0x04,0x83,0x18,0x0A,0x01};

		CLR_Buf6();
		UART6_WriteBuffer((uint8_t *)USART_send1,7);
		
		BSP_OS_TimeDly(10);


				if((USART6_RX_BUF[0]==0x5A)&(USART6_RX_BUF[1]==0xA5)&(USART6_RX_BUF[4]==0x18)&(USART6_RX_BUF[5]==0x0A)&(USART6_RX_BUF[8]!=0x00))
				{
				
				     Cof[1].num_1500_3000 = (USART6_RX_BUF[7] << 8) |USART6_RX_BUF[8];
						 CLR_Buf6();
	
				
				}

					
}
/*
 * 函数名：Get_cof2_tsp_1500_3000
 * 描述  ：获取PM2_5系数数据
 * 输入  ：
 *         
 *        
 *         
 * 输出  ：无
 * 返回  ：无
 * 调用  ：
 */
void Get_cof2_tsp_1500_3000(void){


u8	USART_send1[7]={0x5a,0xa5,0x04,0x83,0x19,0x0A,0x01};

		CLR_Buf6();
		UART6_WriteBuffer((uint8_t *)USART_send1,7);
		
		BSP_OS_TimeDly(10);


				if((USART6_RX_BUF[0]==0x5A)&(USART6_RX_BUF[1]==0xA5)&(USART6_RX_BUF[4]==0x19)&(USART6_RX_BUF[5]==0x0A)&(USART6_RX_BUF[8]!=0x00))
				{
				
				     Cof[2].num_1500_3000 = (USART6_RX_BUF[7] << 8) |USART6_RX_BUF[8];
						 CLR_Buf6();
	
				
				}

					
}
/*
 * 函数名：Get_cof0_PM2_5_3000_8000
 * 描述  ：获取PM2_5系数数据
 * 输入  ：
 *         
 *        
 *         
 * 输出  ：无
 * 返回  ：无
 * 调用  ：
 */
void Get_cof0_PM2_5_3000_8000(void){


u8	USART_send1[7]={0x5a,0xa5,0x04,0x83,0x17,0x0C,0x01};

		CLR_Buf6();
		UART6_WriteBuffer((uint8_t *)USART_send1,7);
		
		BSP_OS_TimeDly(10);


				if((USART6_RX_BUF[0]==0x5A)&(USART6_RX_BUF[1]==0xA5)&(USART6_RX_BUF[4]==0x17)&(USART6_RX_BUF[5]==0x0C)&(USART6_RX_BUF[8]!=0x00))
				{
				
				     Cof[0].num_3000_8000 = (USART6_RX_BUF[7] << 8) |USART6_RX_BUF[8];
						 CLR_Buf6();
	
				
				}

					
}
/*
 * 函数名：Get_cof1_PM10_3000_8000
 * 描述  ：获取PM2_5系数数据
 * 输入  ：
 *         
 *        
 *         
 * 输出  ：无
 * 返回  ：无
 * 调用  ：
 */
void Get_cof1_PM10_3000_8000(void){


u8	USART_send1[7]={0x5a,0xa5,0x04,0x83,0x18,0x0C,0x01};

		CLR_Buf6();
		UART6_WriteBuffer((uint8_t *)USART_send1,7);
		
		BSP_OS_TimeDly(10);


				if((USART6_RX_BUF[0]==0x5A)&(USART6_RX_BUF[1]==0xA5)&(USART6_RX_BUF[4]==0x18)&(USART6_RX_BUF[5]==0x0C)&(USART6_RX_BUF[8]!=0x00))
				{
				
				     Cof[1].num_3000_8000 = (USART6_RX_BUF[7] << 8) |USART6_RX_BUF[8];
						 CLR_Buf6();
	
				
				}

					
}
/*
 * 函数名：Get_cof2_tsp_3000_8000
 * 描述  ：获取PM2_5系数数据
 * 输入  ：
 *         
 *        
 *         
 * 输出  ：无
 * 返回  ：无
 * 调用  ：
 */
void Get_cof2_tsp_3000_8000(void){


u8	USART_send1[7]={0x5a,0xa5,0x04,0x83,0x19,0x0C,0x01};

		CLR_Buf6();
		UART6_WriteBuffer((uint8_t *)USART_send1,7);
		
		BSP_OS_TimeDly(10);


				if((USART6_RX_BUF[0]==0x5A)&(USART6_RX_BUF[1]==0xA5)&(USART6_RX_BUF[4]==0x19)&(USART6_RX_BUF[5]==0x0C)&(USART6_RX_BUF[8]!=0x00))
				{
				
				     Cof[2].num_3000_8000 = (USART6_RX_BUF[7] << 8) |USART6_RX_BUF[8];
						 CLR_Buf6();
	
				
				}

					
}
/*
 * 函数名：Get_cof0_PM2_5_0_50
 * 描述  ：获取PM2_5系数数据
 * 输入  ：
 *         
 *        
 *         
 * 输出  ：无
 * 返回  ：无
 * 调用  ：
 */
void Get_cof0_PM2_5_8000_13000(void){


u8	USART_send1[7]={0x5a,0xa5,0x04,0x83,0x17,0x0F,0x01};

		CLR_Buf6();
		UART6_WriteBuffer((uint8_t *)USART_send1,7);
		
		BSP_OS_TimeDly(10);


				if((USART6_RX_BUF[0]==0x5A)&(USART6_RX_BUF[1]==0xA5)&(USART6_RX_BUF[4]==0x17)&(USART6_RX_BUF[5]==0x0F)&(USART6_RX_BUF[8]!=0x00))
				{
				
				     Cof[0].num_8000_13000 = (USART6_RX_BUF[7] << 8) |USART6_RX_BUF[8];
						 CLR_Buf6();
	
				
				}

					
}
/*
 * 函数名：Get_cof1_PM10_8000_13000
 * 描述  ：获取PM2_5系数数据
 * 输入  ：
 *         
 *        
 *         
 * 输出  ：无
 * 返回  ：无
 * 调用  ：
 */
void Get_cof1_PM10_8000_13000(void){


u8	USART_send1[7]={0x5a,0xa5,0x04,0x83,0x18,0x0F,0x01};

		CLR_Buf6();
		UART6_WriteBuffer((uint8_t *)USART_send1,7);
		
		BSP_OS_TimeDly(10);


				if((USART6_RX_BUF[0]==0x5A)&(USART6_RX_BUF[1]==0xA5)&(USART6_RX_BUF[4]==0x18)&(USART6_RX_BUF[5]==0x0F)&(USART6_RX_BUF[8]!=0x00))
				{
				
				     Cof[1].num_8000_13000 = (USART6_RX_BUF[7] << 8) |USART6_RX_BUF[8];
						 CLR_Buf6();
	
				
				}

					
}
/*
 * 函数名：Get_cof2_tsp_8000_13000
 * 描述  ：获取PM2_5系数数据
 * 输入  ：
 *         
 *        
 *         
 * 输出  ：无
 * 返回  ：无
 * 调用  ：
 */
void Get_cof2_tsp_8000_13000(void){


u8	USART_send1[7]={0x5a,0xa5,0x04,0x83,0x19,0x0F,0x01};

		CLR_Buf6();
		UART6_WriteBuffer((uint8_t *)USART_send1,7);
		
		BSP_OS_TimeDly(10);


				if((USART6_RX_BUF[0]==0x5A)&(USART6_RX_BUF[1]==0xA5)&(USART6_RX_BUF[4]==0x19)&(USART6_RX_BUF[5]==0x0F)&(USART6_RX_BUF[8]!=0x00))
				{
				
				     Cof[2].num_8000_13000 = (USART6_RX_BUF[7] << 8) |USART6_RX_BUF[8];
						 CLR_Buf6();
	
				
				}

					
}
/*
 * 函数名：Get_cof0_PM2_5_13000_20000
 * 描述  ：获取PM2_5系数数据
 * 输入  ：
 *         
 *        
 *         
 * 输出  ：无
 * 返回  ：无
 * 调用  ：
 */
void Get_cof0_PM2_5_13000_20000(void){


u8	USART_send1[7]={0x5a,0xa5,0x04,0x83,0x17,0x12,0x01};

		CLR_Buf6();
		UART6_WriteBuffer((uint8_t *)USART_send1,7);
		
		BSP_OS_TimeDly(10);


				if((USART6_RX_BUF[0]==0x5A)&(USART6_RX_BUF[1]==0xA5)&(USART6_RX_BUF[4]==0x17)&(USART6_RX_BUF[5]==0x12)&(USART6_RX_BUF[8]!=0x00))
				{
				
				     Cof[0].num_13000_20000 = (USART6_RX_BUF[7] << 8) |USART6_RX_BUF[8];
						 CLR_Buf6();
	
				
				}

					
}
/*
 * 函数名：Get_cof0_PM2_5_13000_20000
 * 描述  ：获取PM2_5系数数据
 * 输入  ：
 *         
 *        
 *         
 * 输出  ：无
 * 返回  ：无
 * 调用  ：
 */
void Get_cof1_PM10_13000_20000(void){


u8	USART_send1[7]={0x5a,0xa5,0x04,0x83,0x18,0x12,0x01};

		CLR_Buf6();
		UART6_WriteBuffer((uint8_t *)USART_send1,7);
		
		BSP_OS_TimeDly(10);


				if((USART6_RX_BUF[0]==0x5A)&(USART6_RX_BUF[1]==0xA5)&(USART6_RX_BUF[4]==0x18)&(USART6_RX_BUF[5]==0x12)&(USART6_RX_BUF[8]!=0x00))
				{
				
				     Cof[1].num_13000_20000 = (USART6_RX_BUF[7] << 8) |USART6_RX_BUF[8];
						 CLR_Buf6();
	
				
				}

					
}
/*
 * 函数名：Get_cof2_tsp_13000_20000
 * 描述  ：获取PM2_5系数数据
 * 输入  ：
 *         
 *        
 *         
 * 输出  ：无
 * 返回  ：无
 * 调用  ：
 */
void Get_cof2_tsp_13000_20000(void){


u8	USART_send1[7]={0x5a,0xa5,0x04,0x83,0x19,0x12,0x01};

		CLR_Buf6();
		UART6_WriteBuffer((uint8_t *)USART_send1,7);
		
		BSP_OS_TimeDly(10);


				if((USART6_RX_BUF[0]==0x5A)&(USART6_RX_BUF[1]==0xA5)&(USART6_RX_BUF[4]==0x19)&(USART6_RX_BUF[5]==0x12)&(USART6_RX_BUF[8]!=0x00))
				{
				
				     Cof[2].num_13000_20000 = (USART6_RX_BUF[7] << 8) |USART6_RX_BUF[8];
						 CLR_Buf6();
	
				
				}

					
}
/*
 * 函数名：Get_cof0_PM2_5_20000_30000
 * 描述  ：获取PM2_5系数数据
 * 输入  ：
 *         
 *        
 *         
 * 输出  ：无
 * 返回  ：无
 * 调用  ：
 */
void Get_cof0_PM2_5_20000_30000(void){


u8	USART_send1[7]={0x5a,0xa5,0x04,0x83,0x17,0x14,0x01};

		CLR_Buf6();
		UART6_WriteBuffer((uint8_t *)USART_send1,7);
		
		BSP_OS_TimeDly(10);


				if((USART6_RX_BUF[0]==0x5A)&(USART6_RX_BUF[1]==0xA5)&(USART6_RX_BUF[4]==0x17)&(USART6_RX_BUF[5]==0x14)&(USART6_RX_BUF[8]!=0x00))
				{
				
				     Cof[0].num_20000_30000 = (USART6_RX_BUF[7] << 8) |USART6_RX_BUF[8];
						 CLR_Buf6();
	
				
				}

					
}
/*
 * 函数名：Get_cof1_PM10_20000_30000
 * 描述  ：获取PM2_5系数数据
 * 输入  ：
 *         
 *        
 *         
 * 输出  ：无
 * 返回  ：无
 * 调用  ：
 */
void Get_cof1_PM10_20000_30000(void){


u8	USART_send1[7]={0x5a,0xa5,0x04,0x83,0x18,0x14,0x01};

		CLR_Buf6();
		UART6_WriteBuffer((uint8_t *)USART_send1,7);
		
		BSP_OS_TimeDly(10);


				if((USART6_RX_BUF[0]==0x5A)&(USART6_RX_BUF[1]==0xA5)&(USART6_RX_BUF[4]==0x18)&(USART6_RX_BUF[5]==0x14)&(USART6_RX_BUF[8]!=0x00))
				{
				
				     Cof[1].num_20000_30000 = (USART6_RX_BUF[7] << 8) |USART6_RX_BUF[8];
						 CLR_Buf6();
	
				
				}

					
}
/*
 * 函数名：Get_cof2_tsp_20000_30000
 * 描述  ：获取PM2_5系数数据
 * 输入  ：
 *         
 *        
 *         
 * 输出  ：无
 * 返回  ：无
 * 调用  ：
 */
void Get_cof2_tsp_20000_30000(void){


u8	USART_send1[7]={0x5a,0xa5,0x04,0x83,0x19,0x14,0x01};

		CLR_Buf6();
		UART6_WriteBuffer((uint8_t *)USART_send1,7);
		
		BSP_OS_TimeDly(10);


				if((USART6_RX_BUF[0]==0x5A)&(USART6_RX_BUF[1]==0xA5)&(USART6_RX_BUF[4]==0x19)&(USART6_RX_BUF[5]==0x14)&(USART6_RX_BUF[8]!=0x00))
				{
				
				     Cof[2].num_20000_30000 = (USART6_RX_BUF[7] << 8) |USART6_RX_BUF[8];
						 CLR_Buf6();
	
				
				}

					
}
void Get_warning_data(void){
/*
		//5A A5 06 83 10 28 01 00 05 报警设置界面确定按键返回值
	  //5A A5 06 83 10 2A 01 00 06  返回按键

u8	USART_send5[18]={0x5a,0xa5,0x0F,0x82,0x10,0x36,0xB2,0xCE,0xCA,0xFD,0xC9,0xE8,0XD6,0XC3,0XB3,0XC9,0XB9,0XA6};
u8	USART_send_GBK[22]={0x5a,0xa5,0x13,0x82,0x10,0x36,0xB2,0xCE,0xCA,0xFD,0xD0,0xB4,0XC8,0XEB,0XD6,0XD0,0XC7,0XEB,0XC9,0XD4,0XB5,0XC8};
u8	USART_send_GBK_0[22]={0x5a,0xa5,0x13,0x82,0x10,0x36,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0X00,0X00,0X00,0X00,0X00,0X00};
//u8	temp_01[10]={0X5A,0XA5,0X07,0X82,0X00,0X84,0X5A,0X01,0X00,0X01}; //屏幕切换指令
//u8	USART_send6[18]={0x5a,0xa5,0x0F,0x82,0x10,0x36,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0X00,0X00};
	char	temp_05[]={0X5A,0XA5,0X06,0X83,0X10,0X28,0X01,0X00,0X05};     //参数设置按键返回值
	char	temp_06[]={0X5A,0XA5,0X06,0X83,0X10,0X2A,0X01,0X00,0X06};     //参数设置按键返回值
		  if(Find_usart6((char *)temp_05))
			{
				CLR_Buf6();
				Get_temp_threshold_value();
				Get_PM25_threshold_value();
				Get_PM10_threshold_value();
				UART6_WriteBuffer((uint8_t *)USART_send_GBK,22);	
				printf("get....\r\n");
				printf("Get_temp_threshold_value:%d\r\n",sampling_data.temp_threshold_value);	
				printf("Get_PM25_threshold_value:%d\r\n",sampling_data.pm25_threshold_value);	
				printf("Get_PM10_threshold_value:%d\r\n",sampling_data.pm10_threshold_value);	
				
        if((sampling_data.temp_threshold_value!=0)&(sampling_data.pm25_threshold_value!=0)&(sampling_data.pm10_threshold_value!=0))	
				{

				write_threshold();
				UART6_WriteBuffer((uint8_t *)USART_send_GBK_0,22);
				CLR_Buf6();					
				UART6_WriteBuffer((uint8_t *)USART_send5,18);		
				BSP_OS_TimeDly(100);
				UART6_WriteBuffer((uint8_t *)temp_01,10);					
				printf("get succeed\r\n");					
				avg_X_N.LCD_modetemp=1;	
				CLR_Buf6();
				}
			
			}
			else if(Find_usart6((char *)temp_06))
			{
				
				UART6_WriteBuffer((uint8_t *)temp_01,10);			
				avg_X_N.LCD_modetemp=1;	
				CLR_Buf6();
			}


*/
}
/**
 * 系统设置界面轮询
 * @brief  
 * @param  无
 * @retval 
 */
void Sys_set(void){
	/*
	char	temp_SET[]={0X5A,0XA5,0X06,0X83,0XFA,0X0A,0X01,0X00,0X0A};     //参数设置按键返回值
	char	temp_SEA[]={0X5A,0XA5,0X06,0X83,0XFA,0X1A,0X01,0X00,0X0A};     //参数设置按键返回值
	char	temp_RET[]={0X5A,0XA5,0X06,0X83,0XFA,0X2A,0X01,0X00,0X0A};     //参数设置按键返回值
	char	temp_PAS[]={0X5A,0XA5,0X06,0X83,0XFA,0X3A,0X01,0X00,0X0A};     //参数设置按键返回值
	char	temp_ID []={0X5A,0XA5,0X06,0X83,0XFA,0X4A,0X01,0X00,0X0A};     //参数设置按键返回值		
					if(Find_usart6((char *)temp_SET))    //数据校准界面
			{
					
				avg_X_N.LCD_modetemp=2;				
				UART6_WriteBuffer((uint8_t *)temp_02,10);
				CLR_Buf6();	
				data_display_sampling();		
			}
		else if(Find_usart6((char *)temp_SEA)){
	
				UART6_WriteBuffer((uint8_t *)temp_16,10);
				CLR_Buf6();	
				data_display_sampling();	
				avg_X_N.LCD_modetemp=6;						
		}
		else if(Find_usart6((char *)temp_PAS)){
	  		UART6_WriteBuffer((uint8_t *)USART_send_GBK_PAS,22);
				BSP_OS_TimeDly(100);	
				CLR_Buf6();				
				UART6_WriteBuffer((uint8_t *)temp_14,10);
				CLR_Buf6();		
				avg_X_N.LCD_modetemp=5;						
		}
		else if(Find_usart6((char *)temp_ID)){
	  		UART6_WriteBuffer((uint8_t *)USART_send_GBK_ID,22);
				BSP_OS_TimeDly(100);	
				CLR_Buf6();			
				UART6_WriteBuffer((uint8_t *)temp_15,10);
				CLR_Buf6();	
				avg_X_N.LCD_modetemp=8;						
		}
		else if(Find_usart6((char *)temp_RET)){
					UART6_WriteBuffer((uint8_t *)temp_01,10);
					avg_X_N.LCD_modetemp=1;									
					CLR_Buf6();			
		}
	
*/
}
void Get_sampling_set(void){
/*
		//5A A5 06 83 10 28 01 00 05 报警设置界面确定按键返回值
	  //5A A5 06 83 10 2A 01 00 06  返回按键

u8	USART_send5[18]={0x5a,0xa5,0x0F,0x82,0xF0,0x36,0xB2,0xCE,0xCA,0xFD,0xC9,0xE8,0XD6,0XC3,0XB3,0XC9,0XB9,0XA6};
u8	USART_send_GBK[22]={0x5a,0xa5,0x13,0x82,0xF0,0x36,0xB2,0xCE,0xCA,0xFD,0xD0,0xB4,0XC8,0XEB,0XD6,0XD0,0XC7,0XEB,0XC9,0XD4,0XB5,0XC8};
u8	USART_send_GBK_0[22]={0x5a,0xa5,0x13,0x82,0xF0,0x36,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0X00,0X00,0X00,0X00,0X00,0X00};
//u8	temp_01[10]={0X5A,0XA5,0X07,0X82,0X00,0X84,0X5A,0X01,0X00,0X01}; //屏幕切换指令
//u8	USART_send6[18]={0x5a,0xa5,0x0F,0x82,0x10,0x36,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0X00,0X00};
	char	temp_05[]={0X5A,0XA5,0X06,0X83,0XF0,0X28,0X01,0X00,0X05};     //参数设置按键返回值
	char	temp_06[]={0X5A,0XA5,0X06,0X83,0XF0,0X2A,0X01,0X00,0X06};     //参数设置按键返回值
//	char	temp_SET[]={0X5A,0XA5,0X06,0X83,0XFA,0X0A,0X01,0X00,0X0A};     //参数设置按键返回值	
		  if(Find_usart6((char *)temp_05))
			{
				CLR_Buf6();
				Get_sampling_data();
				Get_sampling_flow();
				Get_sampling_humi();
				
				UART6_WriteBuffer((uint8_t *)USART_send_GBK,22);	
				printf("get....\r\n");
				printf("sampling_time:%d\r\n",sampling_data.sampling_time);	
				printf("sampling_flow:%d\r\n",sampling_data.sampling_flow);	
				printf("sampling_humi:%d\r\n",sampling_data.sampling_humi);	
				
        if((sampling_data.temp_threshold_value!=0)&(sampling_data.pm25_threshold_value!=0)&(sampling_data.pm10_threshold_value!=0))	
				{

				write_sampling();
				UART6_WriteBuffer((uint8_t *)USART_send_GBK_0,22);
				CLR_Buf6();					
				UART6_WriteBuffer((uint8_t *)USART_send5,18);		
				BSP_OS_TimeDly(100);
				UART6_WriteBuffer((uint8_t *)temp_01,10);					
				printf("get succeed\r\n");					
				avg_X_N.LCD_modetemp=1;	
				CLR_Buf6();
				}
			
			}
			else if(Find_usart6((char *)temp_06))
			{
				
				UART6_WriteBuffer((uint8_t *)temp_17,10);			
				avg_X_N.LCD_modetemp=7;	
				CLR_Buf6();
			}
*/

}
void write_sampling(void)
{
	/*
		falsh_SAMPLING[0] = sampling_data.sampling_time;
		falsh_SAMPLING[1] = sampling_data.sampling_flow;	
		falsh_SAMPLING[2] = sampling_data.sampling_humi;
		falsh_SAMPLING[3] = 3;
		STMFLASH_Write(FLASH_SAMPLING_ADDR,(u32*)falsh_SAMPLING,4);
	*/
}
void read_sampling(void)
{
	/*
		u8 t;
		STMFLASH_Read(FLASH_SAMPLING_ADDR,(u32*)falsh_sampling,4);
	
		 sampling_data.sampling_time    = falsh_sampling[0];
		 sampling_data.sampling_flow  = falsh_sampling[1];	
		 sampling_data.sampling_humi = falsh_sampling[2];
//		 sampling_data.PM2_5_300 		 = temp_threshold[3];
     if(falsh_sampling[0] > 0XFFFE)
		 {
		 
		 sampling_data.sampling_time    = 90;
		 sampling_data.sampling_flow  = 300;	
		 sampling_data.sampling_humi = 300;
			printf("sampling_data-->Parameters are not written using default parameters\r\n");		
		 }
		 else{
						for(t=0;t<4;t++)
						{
						
							printf("sampling_data-->:%d\r\n",falsh_sampling[t]);
						
						}
					}
					*/
}
void write_threshold(void)
{
	/*
		falsh_threshold[0] = sampling_data.temp_threshold_value;
		falsh_threshold[1] = sampling_data.pm25_threshold_value;	
		falsh_threshold[2] = sampling_data.pm10_threshold_value;
		falsh_threshold[3] = 3;
		STMFLASH_Write(FLASH_threshold_value_ADDR,(u32*)falsh_threshold,4);
	*/
}
void read_threshold(void)
{
	/*
		u8 t;
		STMFLASH_Read(FLASH_threshold_value_ADDR,(u32*)temp_threshold,4);
	
		 sampling_data.temp_threshold_value    = temp_threshold[0];
		 sampling_data.pm25_threshold_value  = temp_threshold[1];	
		 sampling_data.pm10_threshold_value = temp_threshold[2];
//		 sampling_data.PM2_5_300 		 = temp_threshold[3];
     if(temp_threshold[0] > 0XFFFE)
		 {
		 
		 sampling_data.temp_threshold_value    = 90;
		 sampling_data.pm25_threshold_value  = 300;	
		 sampling_data.pm10_threshold_value = 300;
		 printf("warning-->Parameters are not written using default parameters\r\n");				 
		 }
		 else{
						for(t=0;t<4;t++)
						{
						
							printf("sampling_data_threshold_value:%d\r\n",temp_threshold[t]);
						
						}
					}
					*/
}
void Get_sampling_data(void)    //sampling_time
{
	/*
u8	USART_send1[7]={0x5a,0xa5,0x04,0x83,0xF0,0x32,0x01};  //temp_threshold_value
char	temp_000[]={0X5A,0XA5,0X06,0X83,0XF0,0X32,0X01,0X00};     //返回值
									//5A A5 06 83 10 32 01 00 2A    返回值  2A DEC 42 
		CLR_Buf6();
		UART6_WriteBuffer((uint8_t *)USART_send1,7);
		BSP_OS_TimeDly(10);

		  if(Find_usart6((char *)temp_000))
			{
					sampling_data.sampling_time = USART6_RX_BUF[8];
					printf("sampling_time-USART6_RX_BUF:%d\r\n",sampling_data.sampling_time);
					CLR_Buf6();
			}
*/
}
void Get_sampling_flow(void)    //sampling_time
{
	/*
u8	USART_send1[7]={0x5a,0xa5,0x04,0x83,0xF0,0x24,0x01};  //temp_threshold_value
char	temp_000[]={0X5A,0XA5,0X06,0X83,0XF0,0X24,0X01,0X00};     //返回值
									//5A A5 06 83 10 32 01 00 2A    返回值  2A DEC 42 
		CLR_Buf6();
		UART6_WriteBuffer((uint8_t *)USART_send1,7);
		BSP_OS_TimeDly(10);

		  if(Find_usart6((char *)temp_000))
			{
					sampling_data.sampling_flow = USART6_RX_BUF[8];
					printf("sampling_flow-USART6_RX_BUF:%d\r\n",sampling_data.sampling_flow);
					CLR_Buf6();
			}
*/
}
void Get_sampling_humi(void)    //sampling_time
{
	/*
u8	USART_send1[7]={0x5a,0xa5,0x04,0x83,0xF0,0x26,0x01};  //temp_threshold_value
char	temp_000[]={0X5A,0XA5,0X06,0X83,0XF0,0x26,0X01,0X00};     //返回值
									//5A A5 06 83 10 32 01 00 2A    返回值  2A DEC 42 
		CLR_Buf6();
		UART6_WriteBuffer((uint8_t *)USART_send1,7);
		BSP_OS_TimeDly(10);

		  if(Find_usart6((char *)temp_000))
			{
					sampling_data.sampling_humi = USART6_RX_BUF[8];
					printf("sampling_humi-USART6_RX_BUF:%d\r\n",sampling_data.sampling_humi);
					CLR_Buf6();
			}
*/
}
void Get_temp_threshold_value(void)
{
	/*
u8	USART_send1[7]={0x5a,0xa5,0x04,0x83,0x10,0x32,0x01};  //temp_threshold_value
char	temp_000[]={0X5A,0XA5,0X06,0X83,0X10,0X32,0X01,0X00};     //返回值
									//5A A5 06 83 10 32 01 00 2A    返回值  2A DEC 42 
		CLR_Buf6();
		UART6_WriteBuffer((uint8_t *)USART_send1,7);
		BSP_OS_TimeDly(10);

		  if(Find_usart6((char *)temp_000))
			{
					sampling_data.temp_threshold_value = USART6_RX_BUF[8];
					printf("temp_threshold_value-USART6_RX_BUF:%d\r\n",sampling_data.temp_threshold_value);
					CLR_Buf6();
			}
*/
}

void Get_PM25_threshold_value(void)
{
	/*
u8	USART_send2[7]={0x5a,0xa5,0x04,0x83,0x10,0x24,0x01};
char	temp_50[]={0X5A,0XA5,0X06,0X83,0X10,0X24,0X01};     //返回值
									//5A A5 06 83 10 24 01 00 50    返回值  50 DEC 80
		CLR_Buf6();
		UART6_WriteBuffer((uint8_t *)USART_send2,7);
		BSP_OS_TimeDly(10);

		  if(Find_usart6((char *)temp_50))
			{
					sampling_data.pm25_threshold_value = (USART6_RX_BUF[7] << 8) | USART6_RX_BUF[8];
					printf("pm25_threshold_value-USART6_RX_BUF:%d\r\n",sampling_data.pm25_threshold_value);
					CLR_Buf6();
			}
*/
}
void Get_PM10_threshold_value(void)
{
	/*
u8	USART_send3[7]={0x5a,0xa5,0x04,0x83,0x10,0x26,0x01};
char	temp_50[]={0X5A,0XA5,0X06,0X83,0X10,0X26,0X01};     //返回值
									//5A A5 06 83 10 26 01 00 50    返回值  50 DEC 80
		CLR_Buf6();
		UART6_WriteBuffer((uint8_t *)USART_send3,7);
		BSP_OS_TimeDly(10);

		  if(Find_usart6((char *)temp_50))
			{
					sampling_data.pm10_threshold_value = (USART6_RX_BUF[7] << 8) | USART6_RX_BUF[8];
					printf("pm10_threshold_value-USART6_RX_BUF:%d\r\n",sampling_data.pm10_threshold_value);
					CLR_Buf6();
			}
*/
}
/**
 * @time   4.25   获取密码
 * @brief  
 * @param  无
 * @retval 
 */
void Get_password(void){
	/*
//	
//	发→◇5A A5 04 83 13 00 02          //获取密码采用查询方式
//收←◆5A A5 08 83 13 00 02 00 05 17 62 
	//5A A5 06 83 18 0C 01 00 0C        系统设置按键返回值
	//5A A5 06 83 13 A0 01 00 0A       系统设置界面内返回按键
	//5A A5 08 83 13 00 02 00 05 17 62   密码返回值  333666
		//5a a5 13 82 13 04 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
  //5a a5 0B 82 13 04 C3 DC C2 EB B4 ED CE F3
u32 password = 0;
u8  num = 0;
u8	USART_send_password[7]={0x5a,0xa5,0x04,0x83,0x13,0x00,0x02};
//char	temp_1762[]={0X5A,0XA5,0X08,0X83,0X13,0X00,0X02,0X00,0X05,0x17,0x62};     //返回值
char	temp_0A[]={0X5A,0XA5,0X06,0X83,0X13,0XA0,0X01,0X00,0X0A};     //返回值
//char	temp_62[]={0X5A,0XA5,0X08,0X83,0X13,0X00,0X02,0X00,0X05,0X17,0X62};     //返回值
char	temp_62[]={0X5A,0XA5,0X08,0X83,0X13,0X00,0x02};     //返回值
u8	USART_send_GBK[22]={0x5a,0xa5,0x13,0x82,0x13,0x04,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0X00,0X00,0X00,0X00,0X00,0X00};
u8	USART_send_GBK_0[14]={0x5a,0xa5,0x0B,0x82,0x13,0X04,0xC3,0xDC,0xC2,0xEB,0xB4,0xED,0xCE,0xF3};



			
		if(Find_usart6((char *)temp_62))
		{
		CLR_Buf6();
		UART6_WriteBuffer((uint8_t *)USART_send_password,7);
		BSP_OS_TimeDly(10);
					  if(Find_usart6((char *)temp_62))
			{
			  num = StringFind((char *)USART6_RX_BUF,(const char *)temp_62);
				password = (USART6_RX_BUF[num+8] << 16) | (USART6_RX_BUF[num+9] <<8) | USART6_RX_BUF[num+10];
				printf("password: %d\r\n",password);
				if(password == PASSWORD)
					{
						
						
//					avg_X_N.LCD_modetemp=2;				
//					UART6_WriteBuffer((uint8_t *)temp_02,10);
//					CLR_Buf6();
						
//				data_display(0X15A0,DEVICE_ID);
//				
//				UART6_WriteBuffer((uint8_t *)USART_send_GBK_ID,22);
//				BSP_OS_TimeDly(100);	
//				CLR_Buf6();				
//				UART6_WriteBuffer((uint8_t *)temp_14,10);	
//				CLR_Buf6();			
//				avg_X_N.LCD_modetemp=5;								


					BSP_OS_TimeDly(100);	
					CLR_Buf6();				
					UART6_WriteBuffer((uint8_t *)temp_17,10);	
					CLR_Buf6();			
					avg_X_N.LCD_modetemp=7;			
						
//					data_display_sampling();		
						
						
					}
							else {
								printf("password error\r\n");
								UART6_WriteBuffer((uint8_t *)USART_send_GBK,22);
								CLR_Buf6();
								UART6_WriteBuffer((uint8_t *)USART_send_GBK_0,14);
								CLR_Buf6();			
			
				
							}
		
			}

		}
				  if(Find_usart6((char *)temp_0A)){
					avg_X_N.LCD_modetemp=1;
					UART6_WriteBuffer((uint8_t *)temp_01,10);
					CLR_Buf6();
				
			}
		
			avg_X_N.vlear++;				
		if(avg_X_N.vlear > 1000) {
			
				avg_X_N.vlear = 0;
				CLR_Buf6();		
			
		}	

*/
}
/**
 * 时间4.14   DWIN触摸屏配置DEVICE_ID功能
 * @brief  
 * @param  无
 * @retval 
 */
void Get_DEVICE_ID(void){
	/*
//5A A5 08 83 15 00 02 00 00 1A 0A 
//0x5a,0xa5,0x13,0x82,0x16,0x0C,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
//0x5a,0xa5,0x13,0x82,0x16,0x0C,0xC7,0xEB,0xC9,0xD4,0xB5,0xC8,0x2E,0x2E,0x2E,0x00,0x00,0x00,0x00,0x00,0x00,0x00   请稍等...
//0x5a,0xa5,0x13,0x82,0x16,0x0C,0xD0,0xDE,0xB8,0xC4,0xB3,0xC9,0xB9,0xA6,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00		修改成功
u8  num = 0;
u8	USART_send_password[7]={0x5a,0xa5,0x04,0x83,0x15,0x00,0x04};
char	temp_08[]={0X5A,0XA5,0X06,0X83,0X16,0X0D,0X01,0X00,0X08};     //返回值
char	temp_62[]={0X5A,0XA5,0X0C,0X83,0X15,0X00,0x04};     //返回值
//u8	USART_send_GBK[22]={0x5a,0xa5,0x13,0x82,0x16,0x0C,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0X00,0X00,0X00,0X00,0X00,0X00};
u8	USART_send_GBK_0[22]={0x5a,0xa5,0x13,0x82,0x16,0x0C,0xC7,0xEB,0xC9,0xD4,0xB5,0xC8,0x2E,0x2E,0x2E,0x00,0x00,0x00,0x00,0x00,0x00,0x00};
u8	USART_send_GBK_1[22]={0x5a,0xa5,0x13,0x82,0x16,0x0C,0xD0,0xDE,0xB8,0xC4,0xB3,0xC9,0xB9,0xA6,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00};		
	 if(Find_usart6((char *)temp_62))
		{
		CLR_Buf6();
		UART6_WriteBuffer((uint8_t *)USART_send_password,7);
		BSP_OS_TimeDly(10);
					  if(Find_usart6((char *)temp_62))
			{
			  num = StringFind((char *)USART6_RX_BUF,(const char *)temp_62);
				DEVICE_ID = (USART6_RX_BUF[num+12] <<16) | (USART6_RX_BUF[num+13] <<8) | USART6_RX_BUF[num+14];
				
			  UART6_WriteBuffer((uint8_t *)USART_send_GBK_0,22);    //写入中请稍等
				
				printf("DEVICE_ID: %d\r\n",DEVICE_ID);
				printf("编号写入中请稍等...\r\n");		
				write_DEVICE_ID();
				printf("写入成功!编号为:%d\r\n",DEVICE_ID);		
				data_display_password_8byte(0X15AF,DEVICE_ID);
				
			  UART6_WriteBuffer((uint8_t *)USART_send_GBK_1,22);    //写入中成功			

		
			}

		}
						  if(Find_usart6((char *)temp_08)){

					UART6_WriteBuffer((uint8_t *)temp_17,10);
					avg_X_N.LCD_modetemp=7;								
								
					CLR_Buf6();
				
			}
			avg_X_N.vlear++;				
		if(avg_X_N.vlear > 1000) {
			
				avg_X_N.vlear = 0;
				CLR_Buf6();		
			
		}					
*/
}

/**
 * 时间4.14   修改密码
 * @brief  
 * @param  无
 * @retval 
 */
void Get_PASSWORD_Modify(void){
	/*
//5A A5 0C 83 45 00 04 00 00 00 00 00 0E B5 0C 
//0x5a,0xa5,0x13,0x82,0x16,0x0C,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
//0x5a,0xa5,0x13,0x82,0x16,0x0C,0xC7,0xEB,0xC9,0xD4,0xB5,0xC8,0x2E,0x2E,0x2E,0x00,0x00,0x00,0x00,0x00,0x00,0x00   请稍等...
//0x5a,0xa5,0x13,0x82,0x16,0x0C,0xD0,0xDE,0xB8,0xC4,0xB3,0xC9,0xB9,0xA6,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00		修改成功
u8  num = 0;
u8	USART_send_password[7]={0x5a,0xa5,0x04,0x83,0x45,0x00,0x04};
char	temp_08[]={0X5A,0XA5,0X06,0X83,0X46,0X0D,0X01,0X00,0X08};     //返回值
char	temp_62[]={0X5A,0XA5,0X0C,0X83,0X45,0X00,0x04};     //返回值
//u8	USART_send_GBK[22]={0x5a,0xa5,0x13,0x82,0x16,0x0C,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0X00,0X00,0X00,0X00,0X00,0X00};
u8	USART_send_GBK_0[22]={0x5a,0xa5,0x13,0x82,0x46,0x0C,0xC7,0xEB,0xC9,0xD4,0xB5,0xC8,0x2E,0x2E,0x2E,0x00,0x00,0x00,0x00,0x00,0x00,0x00};
u8	USART_send_GBK_1[22]={0x5a,0xa5,0x13,0x82,0x46,0x0C,0xD0,0xDE,0xB8,0xC4,0xB3,0xC9,0xB9,0xA6,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00};		
	 if(Find_usart6((char *)temp_62))
		{
		CLR_Buf6();
		UART6_WriteBuffer((uint8_t *)USART_send_password,7);
		BSP_OS_TimeDly(10);
					  if(Find_usart6((char *)temp_62))
			{
			  num = StringFind((char *)USART6_RX_BUF,(const char *)temp_62);
				PASSWORD = (USART6_RX_BUF[num+12] <<16) | (USART6_RX_BUF[num+13] <<8) | USART6_RX_BUF[num+14];
				
			  UART6_WriteBuffer((uint8_t *)USART_send_GBK_0,22);    //写入中请稍等
				
				printf("PASSWORD: %d\r\n",PASSWORD);
				printf("密码写入中请稍等...\r\n");		
				write_Password();
				printf("写入成功!编号为:%d\r\n",PASSWORD);		
				data_display_password_8byte(0X45A0,PASSWORD);
				
			  UART6_WriteBuffer((uint8_t *)USART_send_GBK_1,22);    //写入中成功			

		
			}

		}
						  if(Find_usart6((char *)temp_08)){

					UART6_WriteBuffer((uint8_t *)temp_17,10);
					avg_X_N.LCD_modetemp=7;								
								
					CLR_Buf6();
				
			}
			avg_X_N.vlear++;				
		if(avg_X_N.vlear > 1000) {
			
				avg_X_N.vlear = 0;
				CLR_Buf6();		
			
		}					
*/
}
void Get_password_POLL(void){
	/*
//	
//	发→◇5A A5 04 83 13 00 02          //获取密码采用查询方式
//收←◆5A A5 08 83 13 00 02 00 05 17 62 
	//5A A5 06 83 18 0C 01 00 0C        系统设置按键返回值
	//5A A5 06 83 13 A0 01 00 0A       系统设置界面内返回按键
	//5A A5 08 83 13 00 02 00 05 17 62   密码返回值  333666
		//5a a5 13 82 13 04 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
  //5a a5 0B 82 13 04 C3 DC C2 EB B4 ED CE F3
u32 password = 0;
u8  num = 0;
u8	USART_send_password[7]={0x5a,0xa5,0x04,0x83,0x13,0x00,0x02};
//char	temp_1762[]={0X5A,0XA5,0X08,0X83,0X13,0X00,0X02,0X00,0X05,0x17,0x62};     //返回值
//char	temp_0A[]={0X5A,0XA5,0X06,0X83,0X13,0XA0,0X01,0X00,0X0A};     //返回值
//char	temp_62[]={0X5A,0XA5,0X08,0X83,0X13,0X00,0X02,0X00,0X05,0X17,0X62};     //返回值
char	temp_62[]={0X5A,0XA5,0X08,0X83,0X13,0X00,0x02};     //返回值
u8	USART_send_GBK[22]={0x5a,0xa5,0x13,0x82,0x13,0x04,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0X00,0X00,0X00,0X00,0X00,0X00};
u8	USART_send_GBK_0[14]={0x5a,0xa5,0x0B,0x82,0x13,0X04,0xC3,0xDC,0xC2,0xEB,0xB4,0xED,0xCE,0xF3};


			
	 if(Find_usart6((char *)temp_62))
		{
		CLR_Buf6();
		UART6_WriteBuffer((uint8_t *)USART_send_password,7);
		BSP_OS_TimeDly(10);
					  if(Find_usart6((char *)temp_62))
			{
			  num = StringFind((char *)USART6_RX_BUF,(const char *)temp_62);
				password = (USART6_RX_BUF[num+8] << 16) | (USART6_RX_BUF[num+9] <<8) | USART6_RX_BUF[num+10];
				printf("password: %d\r\n",password);
				if(password == 333666)
					{
					avg_X_N.LCD_modetemp=2;				
					UART6_WriteBuffer((uint8_t *)temp_02,10);
					CLR_Buf6();
					data_display_sampling();		
					}
							else {
								printf("password error\r\n");
								UART6_WriteBuffer((uint8_t *)USART_send_GBK,22);
								CLR_Buf6();
								UART6_WriteBuffer((uint8_t *)USART_send_GBK_0,14);
								CLR_Buf6();			
			
				
							}
		
			}

		}
//		else {
//				CLR_Buf6();		
//		}
		

*/
}
void data_display(u16 address,u16 data)   //写数据
{

u8	USART_send_data[8]={0x5a,0xa5,0x05,0x82,0x17,0x00,0x00,0x00};
  USART_send_data[4]=(address & 0XFF00) >> 8 ;
  USART_send_data[5]=(address & 0X00FF) >> 0 ;

	USART_send_data[6]=(data & 0XFF00) >> 8 ;
	USART_send_data[7]=(data & 0X00FF) >> 0 ;

	UART6_WriteBuffer((uint8_t *)USART_send_data,8);
//	avg_X_N.DATA_flag = 0;
	CLR_Buf6();	

	BSP_OS_TimeDly(5);
	
}
void data_display_password_8byte(u16 address,u32 data)   //写数据
{
//5A A5 0B 82 45 A0  00 00 00 00 00 05 17 62
u8	USART_send_data[]={0x5a,0xa5,0x0B,0x82,0x17,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0X00};
  USART_send_data[4]=(address & 0XFF00) >> 8 ;
  USART_send_data[5]=(address & 0X00FF) >> 0 ;


	USART_send_data[11]=(data & 0X00FF0000) >> 16 ;
	USART_send_data[12]=(data & 0X0000FF00) >> 8 ;
	USART_send_data[13]=(data & 0X000000FF) >> 0 ;

	UART6_WriteBuffer((uint8_t *)USART_send_data,14);
//	avg_X_N.DATA_flag = 0;
	CLR_Buf6();	

	BSP_OS_TimeDly(5);
	
}
void data_display_day(u16 address,u16 data)   //写数据
{

u8	USART_send_data[8]={0x5a,0xa5,0x05,0x82,0x17,0x00,0x00,0x00};
  USART_send_data[4]=(address & 0XFF00) >> 8 ;
  USART_send_data[5]=(address & 0X00FF) >> 0 ;

	USART_send_data[6]=(data & 0XFF00) >> 8 ;
	USART_send_data[7]=(data & 0X00FF) >> 0 ;

	UART6_WriteBuffer((uint8_t *)USART_send_data,8);
//	avg_X_N.max_NOISE_day = 0;
	CLR_Buf6();	
	BSP_OS_TimeDly(5);
	
}
void Historical_ata_shows(void){
	/*
//5A A5 0E 82 18 02  31 31 2D 32 32 2D 31 31 3A 34 39   //历史数据时间参数修改

			switch(avg_X_N.Historical)
			{				 
				case 1:	//
	RTC_time();
	Historical_ata(0x8802,mytime.month,mytime.day,mytime.hour,mytime.minute);
	data_display(0X1902,mySensorDatas.PM2_5);
	Historical_ata(0x882E,mytime.month,mytime.day,mytime.hour,mytime.minute);
	data_display(0X190A,mySensorDatas.PM10);
	Historical_ata(0x885A,mytime.month,mytime.day,mytime.hour,mytime.minute);
	data_display(0X1912,mySensorDatas.NOISE);
					break;
				case 2:	//
	RTC_time();
	Historical_ata(0x880D,mytime.month,mytime.day,mytime.hour,mytime.minute);
	data_display(0X1904,mySensorDatas.PM2_5);
	Historical_ata(0x8839,mytime.month,mytime.day,mytime.hour,mytime.minute);
	data_display(0X190C,mySensorDatas.PM10);
	Historical_ata(0x8865,mytime.month,mytime.day,mytime.hour,mytime.minute);
	data_display(0X1914,mySensorDatas.NOISE);					
					
					break;
				case 3:	//
	RTC_time();
	Historical_ata(0x8818,mytime.month,mytime.day,mytime.hour,mytime.minute);
	data_display(0X1906,mySensorDatas.PM2_5);
	Historical_ata(0x8844,mytime.month,mytime.day,mytime.hour,mytime.minute);
	data_display(0X190E,mySensorDatas.PM10);
	Historical_ata(0x8870,mytime.month,mytime.day,mytime.hour,mytime.minute);
	data_display(0X1916,mySensorDatas.NOISE);
			
					break;
				case 4:	//

	RTC_time();
	Historical_ata(0x8823,mytime.month,mytime.day,mytime.hour,mytime.minute);
	data_display(0X1908,mySensorDatas.PM2_5);
	Historical_ata(0x884F,mytime.month,mytime.day,mytime.hour,mytime.minute);
	data_display(0X1910,mySensorDatas.PM10);
	Historical_ata(0x887B,mytime.month,mytime.day,mytime.hour,mytime.minute);
	data_display(0X1918,mySensorDatas.NOISE);							
					break;
			}
			*/
}
void Historical_ata(u16 address,u8 month, u8 day,u8 hour,u8 minute){
	/*
	u8	USART_send_Record[]  ={0X5A,0XA5,0X0E,0X82,0X18,0X02,0X31,0X31,0X2D,0X32,0X32,0X2D,0X31,0X31,0X3A,0X34,0X39};
			USART_send_Record[4]=(address & 0XFF00) >> 8 ;
			USART_send_Record[5]=(address & 0X00FF) >> 0 ; 
			

				USART_send_Record[6] = (month/10)+'0';
				USART_send_Record[7] = (month%10)+'0';	
				USART_send_Record[9] = (day/10)+'0';
				USART_send_Record[10] = (day%10)+'0';	
				USART_send_Record[12] = (hour/10)+'0';
				USART_send_Record[13] = (hour%10)+'0';	
				USART_send_Record[15] = (minute/10)+'0';
				USART_send_Record[16] = (minute%10)+'0';	
				UART6_WriteBuffer((uint8_t *)USART_send_Record,strlen((char *)USART_send_Record));
				BSP_OS_TimeDly(5);
		    CLR_Buf6();
		 */  
}
void show_mian(void){
	
				avg_X_N.LCD_modetemp=0;
				UART6_WriteBuffer((uint8_t *)temp_00,10);
				CLR_Buf6();

}
void GUI_showData(void){

//	data_display_wind_direction(mySensorDatas.WIND_DIRECTION_CLASS);
//	data_display_Noise(mySensorDatas.NOISE);
//	data_display_wind_speed(mySensorDatas.WIND_SPEED*10); //810显示8.10 m/s
//	mySensorDatas.PM2_5 = 30000;
//	mySensorDatas.PM10 = 30000;
//	mySensorDatas.TSP = 30000;	
	data_display_PM25(mySensorDatas.PM2_5);
	BSP_OS_TimeDly(50);
	data_display_PM10(mySensorDatas.PM10);
	BSP_OS_TimeDly(50);
	data_display_TSP(mySensorDatas.TSP);
	BSP_OS_TimeDly(50);
//	data_display_temp(mySensorDatas.TEMP);
//	data_display_humi(mySensorDatas.HUMI);
//	data_display_press(mySensorDatas.PRESS);	
//	data_display_WIND_LEVEL(mySensorDatas.WIND_LEVEL);
	/*
			if(avg_X_N.DATA_flag == 1)
	{
	Historical_ata_shows();
	data_display(0X1F02,avg_X_N.min_PM25);
	data_display(0X1F04,avg_X_N.avg_PM25);
	data_display(0X1F06,avg_X_N.max_PM25);
	data_display(0X1F08,avg_X_N.min_PM10);
	data_display(0X1F0A,avg_X_N.avg_PM10);
	data_display(0X1F0C,avg_X_N.max_PM10);
	data_display(0X1F0E,avg_X_N.min_NOISE);
	data_display(0X1F10,avg_X_N.avg_NOISE);
	data_display(0X1F12,avg_X_N.max_NOISE);
		avg_X_N.DATA_flag = 0;
	}
		if(avg_X_N.max_NOISE_day == 1)
	{
	data_display_day(0X1402,avg_X_N.min_PM25);
	data_display_day(0X1404,avg_X_N.avg_PM25);
	data_display_day(0X1406,avg_X_N.max_PM25);
	data_display_day(0X1408,avg_X_N.min_PM10);
	data_display_day(0X140A,avg_X_N.avg_PM10);
	data_display_day(0X140C,avg_X_N.max_PM10);
	data_display_day(0X140E,avg_X_N.min_NOISE);
	data_display_day(0X1410,avg_X_N.avg_NOISE);
	data_display_day(0X1412,avg_X_N.max_NOISE);	
		avg_X_N.max_NOISE_day = 0;
	}
	*/
//	data_display_temp(0X463);
//	data_display_humi(0X463);
}


void LCD_mode_select(void)
{


			switch(avg_X_N.LCD_modetemp)
			{				 
				case 0:	//

				GUI_showData();

					break;
				case 1:	//
	
				setting_mode();    

					break;
				case 2:	//
				Get_cof1_pm10_data();	

					
					break;
				case 3:	//
				Get_cof0_pm2_5_data();
			
					break;
				case 4:	//
				Get_cof2_tsp_data();	
		
					break;
				case 5:	//		

				Get_Sampling_period_data();
					break;	
				case 6:	//		

				Get_Sampling_Speed_regulation_data();
					break;					
				case 7:	//		

				Get_Sampling_Zero_Calibration();
					break;	
			}



}
