#ifndef __GPRS_H
#define __GPRS_H

#include "bsp.h"

typedef enum{
    GPRS_TRUE,
    GPRS_FALSE,
}gprs_res_e;

void UploadData(void);
void Air720D_Init(void);
u8 Air720D_CFUN(void);
u8 Air720D_CSQ(void);
u8 Air720D_MPUB(char *cmd, uint32_t waittime);
u8 Air720D_Send_AT(char *cmd, char *reply, uint32_t waittime);
void Air720D_Poll(void);
void Air720D_MQTTSTATU(void);

#endif
