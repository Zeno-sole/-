#ifndef __DWIN_H
#define __DWIN_H
#include "bsp.h"

void LCD_mode(void);
void LCD_mode_select(void);
void GUI_showData(void);
void data_display_wind_direction(uint16_t data);
void Get_sampling_Data(void);
void Get_PM2_5_0_50(void);
void Get_PM2_5_51_150(void);
void Get_PM2_5_151_300(void);
void Get_PM2_5_300(void);
void Get_PM10_0_50(void);
void Get_PM10_51_150(void);
void Get_PM10_151_300(void);
void Get_PM10_300(void);
void Get_temp_threshold_value(void);
void Get_PM25_threshold_value(void);
void Get_PM10_threshold_value(void);

void Get_sampling_data(void);
void Get_sampling_flow(void);
void Get_sampling_humi(void);

void Get_password(void);
void Get_Data(void);
void write_flash(void);
void raed_flash(void);
void write_threshold(void);
void read_threshold(void);
void data_display_sampling(void);
void data_display_warning(void);

void data_display_sampling_set(void);

void ParsePM25(void);

void write_sampling(void);
void read_sampling(void);

void show_mian(void);
void data_display(u16 address,u16 data);   //写数据
void data_display_day(u16 address,u16 data);   //写数据
void data_display_password_8byte(u16 address,u32 data);   //写数据
void RTC_time(void);
 
void Threshold_Value_Record_(u16 address,u8 year,u8 month, u8 day,u8 hour,u8 minute,u8 second);
void Threshold_Value_Record(void);         //PM2.5
void Threshold_Value_Record_data(u16 address,u16 data);   

void Threshold_Value_Record_PM10(void); 
void Threshold_Value_Record_TEMP(void);

void Historical_ata_shows(void);//历史数据显示
void Historical_ata(u16 address,u8 month, u8 day,u8 hour,u8 minute);


void Get_password_POLL(void);

void Get_PASSWORD_Modify(void);

void Get_sampling_set(void);


void Sys_set(void);

void data_display_network_state(u8 state);

void raed_cof0_pm2_5(void);
void write_flash_cof0_pm2_5(void);
void raed_cof1_pm10(void);
void write_flash_cof1_pm10(void);
void raed_cof2_tsp(void);
void write_flash_cof2_tsp(void);

void Get_cof0_pm2_5_data(void);
void Get_cof0_PM2_5_0_50(void);
void Get_cof0_PM2_5_50_100(void);
void Get_cof0_PM2_5_100_500(void);
void Get_cof0_PM2_5_500_1000(void);
void Get_cof0_PM2_5_1000_1500(void);
void Get_cof0_PM2_5_1500_3000(void);
void Get_cof0_PM2_5_3000_8000(void);
void Get_cof0_PM2_5_8000_13000(void);
void Get_cof0_PM2_5_13000_20000(void);
void Get_cof0_PM2_5_20000_30000(void);

void Get_cof1_PM10_data(void);
void Get_cof1_PM10_0_50(void);
void Get_cof1_PM10_50_100(void);
void Get_cof1_PM10_100_500(void);
void Get_cof1_PM10_500_1000(void);
void Get_cof1_PM10_1000_1500(void);
void Get_cof1_PM10_1500_3000(void);
void Get_cof1_PM10_3000_8000(void);
void Get_cof1_PM10_8000_13000(void);
void Get_cof1_PM10_13000_20000(void);
void Get_cof1_PM10_20000_30000(void);

void Get_cof2_tsp_data(void);
void Get_cof2_tsp_0_50(void);
void Get_cof2_tsp_50_100(void);
void Get_cof2_tsp_100_500(void);
void Get_cof2_tsp_500_1000(void);
void Get_cof2_tsp_1000_1500(void);
void Get_cof2_tsp_1500_3000(void);
void Get_cof2_tsp_3000_8000(void);
void Get_cof2_tsp_8000_13000(void);
void Get_cof2_tsp_13000_20000(void);
void Get_cof2_tsp_20000_30000(void);

void Get_Sampling_period_data(void);
void Get_Sampling_Speed_regulation_data(void);
void Get_Sampling_Zero_Calibration(void);
void Get_Sampling_period(void);
void Get_Speed_period(void);
void Get_Zero_Calibration(void);


void write_DEVICE_ID(void);
void read_DEVICE_ID(void);

void read_SPEED(void);
void write_SPEED(void);

void read_Zero_Calibration(void);
void write_Zero_Calibration(void);
#endif
