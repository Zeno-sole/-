#include "bsp.h"

/* ----------------------- Variables ----------------------------------------*/
static eMBEventType eQueuedEvent;
static BOOL xEventInQueue;

/* ----------------------- Start implementation -----------------------------*/
/**
  * @brief  事件初始化
  * @param  None
  * @retval None
  */
BOOL xMBPortEventInit(void){
    xEventInQueue = FALSE;
    return TRUE;
}

/**
  * @brief  事件发送
  * @param  None
  * @retval None
  */
BOOL xMBPortEventPost(eMBEventType eEvent){
    xEventInQueue = TRUE;  //有事件标志更新
    eQueuedEvent = eEvent; //设定事件标志
    return TRUE;
}

/**
  * @brief  事件接收
  * @param  None
  * @retval None
  */
BOOL xMBPortEventGet(eMBEventType * eEvent){
    BOOL xEventHappened = FALSE;
		//若有事件更新
    if(xEventInQueue){
        *eEvent = eQueuedEvent; //获得事件
        xEventInQueue = FALSE;
        xEventHappened = TRUE;
    }
    return xEventHappened;
}
