#ifndef  APP_CFG_MODULE_PRESENT
#define  APP_CFG_MODULE_PRESENT

/*
*********************************************************************************************************
*                                            TASK PRIORITIES
*********************************************************************************************************
*/

#define  APP_CFG_TASK_START_PRIO                2 //注意优先级0和1是系统保留的，不要使用
#define  APP_CFG_TASK_PARSE_PRIO                3
#define  APP_CFG_TASK_LED_PRIO                  4
#define  APP_CFG_TASK_1_PRIO                  	5

/*
*********************************************************************************************************
*                                            TASK STACK SIZES
*                             Size of the task stacks (# of OS_STK entries)
*********************************************************************************************************
*/

#define  APP_CFG_TASK_START_STK_SIZE            512u
#define  APP_CFG_TASK_PARSE_STK_SIZE            512u
#define  APP_CFG_TASK_LED_STK_SIZE              512u
#define  APP_CFG_TASK_1_STK_SIZE              	512u
#endif
