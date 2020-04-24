#include "bsp.h"

OS_TCB				  AppTaskStartTCB;
OS_TCB          AppTaskParseTCB;
OS_TCB          AppTaskLEDTCB;
OS_TCB          AppTask1TCB;

static CPU_STK  AppTaskStartStk[APP_CFG_TASK_START_STK_SIZE];
static CPU_STK  AppTaskParseStk[APP_CFG_TASK_PARSE_STK_SIZE];
static CPU_STK  AppTaskLEDStk[APP_CFG_TASK_LED_STK_SIZE];
static CPU_STK  AppTask1Stk[APP_CFG_TASK_1_STK_SIZE];

static void	  	AppTaskStart(void  *p_arg); //主应用程序任务
static void			AppTaskParse(void  *p_arg); //解析任务
static void			AppTaskLED(void  *p_arg); //解析任务
static void			AppTask1(void  *p_arg); //解析任务
//OS_MUTEX     AppTaskObjMutex;//互斥信号量对象

int main(void){
	
    OS_ERR   err;
#if (CPU_CFG_NAME_EN == DEF_ENABLED)
    CPU_ERR  cpu_err;
#endif
		//.....
    Mem_Init();                                                 /* Initialize Memory Managment Module                   */

#if (CPU_CFG_NAME_EN == DEF_ENABLED)
    CPU_NameSet((CPU_CHAR *)"STM32F103VC",(CPU_ERR*)&cpu_err);
#endif

    BSP_IntDisAll();                                            /* Disable all Interrupts.                              */

    OSInit(&err);                                               /* Init uC/OS-III.                                      */
    App_OS_SetAllHooks();

    OSTaskCreate(&AppTaskStartTCB,                              /* Create the start task                                */
                  "App Task Start",
                  AppTaskStart,
                  0,
                  APP_CFG_TASK_START_PRIO,
                  &AppTaskStartStk[0u],
                  AppTaskStartStk[APP_CFG_TASK_START_STK_SIZE / 10u],
                  APP_CFG_TASK_START_STK_SIZE,
                  0,
                  0,
                  0,
                  (OS_OPT_TASK_STK_CHK | OS_OPT_TASK_STK_CLR),
                  &err);

    OSStart(&err);                                              /* Start multitasking (i.e. give control to uC/OS-III). */

    while(1){                                                   /* Should Never Get Here.                               */
    }
}

/**
 * @brief  应用程序GPRS Poll任务
 * @param  无
 * @retval 无
 */
static  void  AppTaskStart (void *p_arg){
	
	OS_ERR  os_err;
	(void)p_arg;

	
	BSP_Init();                                                 /* Initialize BSP functions                             */
	CPU_Init();                                                 /* Initialize the uC/CPU services                       */

	#if OS_CFG_STAT_TASK_EN > 0u
		OSStatTaskCPUUsageInit(&os_err);                          /* CPU统计任务初始化 */
	#endif

	#ifdef CPU_CFG_INT_DIS_MEAS_EN
		CPU_IntDisMeasMaxCurReset();
	#endif
	
	//OSMutexCreate(&AppTaskObjMutex,"Mutex Test",&os_err);//创建互斥信号量
	/*-------------------------------------------------------------------------------*/
	OSTaskCreate(&AppTaskParseTCB,
								"App Task Parse TCB",
								AppTaskParse,
								0,
								APP_CFG_TASK_PARSE_PRIO,
								&AppTaskParseStk[0],
								AppTaskParseStk[APP_CFG_TASK_PARSE_STK_SIZE / 10u],
								APP_CFG_TASK_PARSE_STK_SIZE,
								0,
								0,
								0,
								(OS_OPT_TASK_STK_CHK | OS_OPT_TASK_STK_CLR),
								&os_err);
	/*-------------------------------------------------------------------------------*/
		OSTaskCreate(&AppTaskLEDTCB,
								"App Task LED TCB",
								AppTaskLED,
								0,
								APP_CFG_TASK_LED_PRIO,
								&AppTaskLEDStk[0],
								AppTaskLEDStk[APP_CFG_TASK_LED_STK_SIZE / 10u],
								APP_CFG_TASK_LED_STK_SIZE,
								0,
								0,
								0,
								(OS_OPT_TASK_STK_CHK | OS_OPT_TASK_STK_CLR),
								&os_err);
	/*-------------------------------------------------------------------------------*/
		OSTaskCreate(&AppTask1TCB,
								"App Task 1 TCB",
								AppTask1,
								0,
								APP_CFG_TASK_1_PRIO,
								&AppTask1Stk[0],
								AppTask1Stk[APP_CFG_TASK_1_STK_SIZE / 10u],
								APP_CFG_TASK_1_STK_SIZE,
								0,
								0,
								0,
								(OS_OPT_TASK_STK_CHK | OS_OPT_TASK_STK_CLR),
								&os_err);
	/*-------------------------------------------------------------------------------*/
	printf("Wait the module power on...\r\n");

	IWDG_Config(IWDG_Prescaler_128 ,2000);    //6s
	while(1){                                                  /* Task body, always written as an infinite loop.       */
//	  ParsePM25Command();
//		TIM_SetCompare2(GENERAL_TIMx,300);
		TIM_SetCompare2(GENERAL_TIMx,3000 - (mySensorDatas.SPEED*30));     //mySensorDatas.SPEED*30 
		LCD_mode();	
		eMBPoll();//Modbus Poll
		IWDG_Feed();	
//		printf("AppTaskStart...\r\n");
//		BSP_OS_TimeDly(1000);	
		OSTimeDlyHMSM(0u, 0u, 0u, 10u, OS_OPT_TIME_HMSM_STRICT, &os_err);		
	}
}

/**
 * @brief  串口指令解析任务
 * @param  无
 * @retval 无
 */
static void AppTaskParse(void* p_arg)
{
	OS_ERR  os_err;

	while(1){
		LCD_mode_select();
		

//		printf("AppTaskParse...\r\n");	
//		BSP_OS_TimeDly(1000);		
		OSTimeDlyHMSM(0u, 0u, 0u, 10u, OS_OPT_TIME_HMSM_STRICT, &os_err);
	}
}
/**
 * @brief  led
 * @param  无
 * @retval 无
 */
static void AppTaskLED(void* p_arg)
{
	OS_ERR  os_err;

	while(1){
		
		if( mySensorDatas.Deashing_Period==times.HOUR ){
			mySensorDatas.RELAYSL = 0;
			times.HOUR = 0;
			REALY_PORT->ODR &= ~(REALY2_PIN);	  //Low Rev  电磁阀
			REALY_PORT->ODR &= ~(REALY3_PIN);	  //清灰	
			
			mySensorDatas.PM2_5 =  0;//PM2.5
		
			mySensorDatas.PM10  =  0;//PM10		
		
			mySensorDatas.TSP  =   0;//PM10						
			
			BSP_OS_TimeDly(1000 * (mySensorDatas.Deashing_Time+1));
			
			
			REALY_PORT->ODR |=  (REALY2_PIN);  //电磁阀
			REALY_PORT->ODR |=  (REALY3_PIN);	  //  清灰	
			mySensorDatas.RELAYSL = 1;
		}
		
		OSTimeDlyHMSM(0u, 0u, 0u, 10u, OS_OPT_TIME_HMSM_STRICT, &os_err);
	}
}
/**
 * @brief  led
 * @param  无
 * @retval 无
 */
static void AppTask1(void* p_arg)
{
	OS_ERR  os_err;

	while(1){

	
					if((mySensorDatas.RELAYS == 1) && (mySensorDatas.RELAYSL == 1))
		{		

			
				mySensorDatas.RELAYS = 0;

				REALY_PORT->ODR |=  (REALY1_PIN);	//闭合
			
			  BSP_OS_TimeDly(1000 * (DEVICE_ID+1));  
			
				REALY_PORT->ODR &= ~(REALY1_PIN);  //常开	近气
			
				ParsePM25Command_CUBIC();

		}
		

		OSTimeDlyHMSM(0u, 0u, 0u, 10u, OS_OPT_TIME_HMSM_STRICT, &os_err);
	}
}

