#include "bsp.h"

/* ----------------------- Variables ----------------------------------------*/
static eMBEventType eQueuedEvent;
static BOOL xEventInQueue;

/* ----------------------- Start implementation -----------------------------*/
/**
  * @brief  �¼���ʼ��
  * @param  None
  * @retval None
  */
BOOL xMBPortEventInit(void){
    xEventInQueue = FALSE;
    return TRUE;
}

/**
  * @brief  �¼�����
  * @param  None
  * @retval None
  */
BOOL xMBPortEventPost(eMBEventType eEvent){
    xEventInQueue = TRUE;  //���¼���־����
    eQueuedEvent = eEvent; //�趨�¼���־
    return TRUE;
}

/**
  * @brief  �¼�����
  * @param  None
  * @retval None
  */
BOOL xMBPortEventGet(eMBEventType * eEvent){
    BOOL xEventHappened = FALSE;
		//�����¼�����
    if(xEventInQueue){
        *eEvent = eQueuedEvent; //����¼�
        xEventInQueue = FALSE;
        xEventHappened = TRUE;
    }
    return xEventHappened;
}
