#include "bsp.h"
u8 uart_buffValid = 0;
void Air720D_Init(void)
{	
	char temp[50] = {0};
	u16 times = 10;
	Air720D_CFUN();
	while(times)
	{
		times--;
		CLR_Buf4();
		if(Air720D_Send_AT("AT\r\n","OK",10))
		{
			printf("In response to success!\r\n");
			break;
		}
	}
	Air720D_Send_AT("AT+MDISCONNECT\r\n","OK",50);
	Air720D_Send_AT("AT+MIPCLOSE\r\n","OK",50);
	Air720D_Send_AT("AT+CIPSHUT\r\n","OK",10);	
	Air720D_CSQ();
	times = 10;
	sprintf(temp, "AT+MCONFIG=\"%s\",\"123\",\"123\",\"0\",\"0\",\"456\",\"456\"\r\n", DEVICE_ID );
	while(times)
	{
		times--;
		CLR_Buf4();
		if(Air720D_Send_AT(temp,"OK",50))
		{
			printf("MCONFIG Success!\r\n");
			break;
		}
	}
		times = 10;
	while(times)
	{
		times--;
		CLR_Buf4();
		if(Air720D_Send_AT("AT+MIPSTART=\"39.98.40.237\",\"1883\"\r\n","CONNECT OK",10))
		{
			printf("MIPSTART Success!\r\n");
			break;
		}
	}
		times = 10;
	while(times)
	{
		times--;
		CLR_Buf4();
		if(Air720D_Send_AT("AT+MCONNECT=\"1\",\"60\"\r\n","OK",10))
		{
			printf("MCONNECT Success!\r\n");
			break;
		}
	}
		times = 10;
	sprintf(temp, "AT+MSUB=\"%s\",\"0\"\r\n", DEVICE_ID );
	while(times)
	{
		times--;
		CLR_Buf4();
		if(Air720D_Send_AT(temp,"SUBACK",10))
		{
			printf("MSUB Success!\r\n");
			break;
		}
	}
			times = 10;
	sprintf(temp, "AT+MPUB=\"%s1\",\"0\",\"1\",\"Success!\"\r\n", DEVICE_ID);
	while(times)
	{
		times--;
		CLR_Buf4();
		if(Air720D_Send_AT(temp,"OK",50))
		{
			printf("MPUB Success!\r\n");
			LED_PORT->ODR &= ~ (LED_NETOK_PIN);
			uart_buffValid = 2;
			break;
		}
	}

//	Air720D_MPUB("1000001",50);
}
u8 Air720D_CFUN(void)
{
		u16 times = 10,suc_flag=0;
	
	Air720D_Send_AT("AT+CFUN=1,1\r\n","SMS READY:",50);
	while(times)
	{
		times--;
		BSP_OS_TimeDly(2000);
		if(Find_usart4("SMS"))
		{
			printf("Restart the success!\r\n");
			suc_flag = 1;
			break;
		}
		printf("retry %d\r\n",times);
	}
		if(suc_flag)
	{
		return 1;
	}
	else
	{
		return 0;
	}

}
void Air720D_MQTTSTATU(void)   //查询MQTT连接状态
{
//	BSP_OS_TimeDly(1000*10);
	if(Air720D_Send_AT("AT+MQTTSTATU\r\n","+MQTTSTATU :1",100))
	{	
				CLR_Buf4();
	}	
	else
	{
			 Soft_Reset();
	}
//	if(Air720D_Send_AT("AT+MQTTSTATU\r\n","+MQTTSTATU :0",10))
//	{	
//				Sys_Soft_Reset();
//	}
//	if(Air720D_Send_AT("AT+MQTTSTATU\r\n","ERROR",10))
//	{	
//				Sys_Soft_Reset();
//	}
//	if(Air720D_Send_AT("AT+MQTTSTATU\r\n","+MQTTSTATU :2",10))
//	{	
//				Sys_Soft_Reset();
//	}
//				CLR_Buf4();
}
u8 Air720D_CSQ(void)
{
		u16 times = 10,suc_flag=0;
	
	Air720D_Send_AT("AT+CSQ\r\n","SMS READY:",50);
	while(times)
	{
		times--;
		
		BSP_OS_TimeDly(1000);
		if(Air720D_Send_AT("AT+CSQ\r\n","+CSQ",50))
		{
			if(Find_usart4("+CSQ: 0,99") != 1)
			{
				
				printf("CSQ the success!\r\n");
				suc_flag = 1;				
				break;
			}
		}
		printf("retry %d\r\n",times);
	}
		if(suc_flag)
	{
		return 1;
	}
	else
	{
		return 0;
	}

}
u8 Air720D_MPUB(char *cmd, uint32_t waittime)
{
	  u16 time = 0,suc_flag=0;	//超时计数器
		char temp[300] = {0};
		sprintf(temp, "AT+MPUB=\"%s1\",\"0\",\"1\",\"%s\"\r\n",DEVICE_ID,cmd);
		UartWriteBuffer_Config((u8 *)temp,strlen(temp));
		while(time<waittime)
	{
		if(Find_usart4("OK"))
		{
			CLR_Buf4();
			suc_flag = 1;
			break;
		}
				if(Find_usart4("ERROR"))
		{
			Soft_Reset();
		}
		BSP_OS_TimeDly(50);
		time++;
		
	}
	if(suc_flag)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
u8 Air720D_Send_AT(char *cmd, char *reply, uint32_t waittime)
{
	u16 time = 0,suc_flag=0;	//超时计数器
	
	UartWriteBuffer_Config((u8 *)cmd,strlen(cmd));
	while(time<waittime)
	{
		if(Find_usart4(reply))
		{
			CLR_Buf4();
			suc_flag = 1;
			break;
		}
		BSP_OS_TimeDly(50);
		time++;
		
	}
	if(suc_flag)
	{
		return 1;
	}
	else
	{
		return 0;
	}
	
}
//+MSUB: "100002",2 byte,k1
void Air720D_Poll(void)
{

	if(Find_usart4("byte,k1"))
	{

				CLR_Buf4();
				REALY_PORT->ODR |= (REALY1_PIN);// Relay Off 继电器闭合 LED灭
				printf("+MSUB: \"k1\"\r\n");
				Air720D_MPUB("open k1",50);

		
	}
	else if(Find_usart4("byte,g1"))
	{

				CLR_Buf4();
				REALY_PORT->ODR &= ~ (REALY1_PIN);//继电器打开
				printf("+MSUB: \"g1\"\r\n");
				Air720D_MPUB("close g1",50);
	}
	else if(Find_usart4("byte,k2"))
	{

				CLR_Buf4();
				REALY_PORT->ODR |= (REALY2_PIN);// Relay Off 继电器闭合 LED灭

				printf("+MSUB: \"k2\"\r\n");
				Air720D_MPUB("open k2",50);

	
	}
	else if(Find_usart4("byte,g2"))
	{

				CLR_Buf4();
				REALY_PORT->ODR &= ~ (REALY2_PIN);//继电器打开
				printf("+MSUB: \"g2\"\r\n");
				Air720D_MPUB("close g2",50);
	}	
	else if(Find_usart4("CLOSED"))
	{					
		LED_PORT->ODR |= (LED_LINK_PIN | LED_NETOK_PIN);//All LED Off
		uart_buffValid = 0;
		Soft_Reset();
		Air720D_Init();
	}		
}


/**
 * @brief  上传传感器数据
 * @retval 无
 */
void UploadData(void){



}
