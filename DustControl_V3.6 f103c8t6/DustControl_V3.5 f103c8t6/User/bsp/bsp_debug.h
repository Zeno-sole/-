#ifndef  BSP_DEBUG
#define  BSP_DEBUG

//#define FLASH_DEBUG_
//#define GPRS_DEBUG_


#ifdef FLASH_DEBUG_
		#define FLASH_DEBUG(format, ...) printf (format, ##__VA_ARGS__)
#else
    #define FLASH_DEBUG(format,...)
#endif

#ifdef GPRS_DEBUG_
		#define GPRS_DEBUG(format, ...) printf (format, ##__VA_ARGS__)
#else
    #define GPRS_DEBUG(format,...)
#endif


#endif /* BSP_DEBUG */


