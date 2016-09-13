/*
*********************************************************************************************************
*
*	模块名称 : 底层硬件驱动
*	文件名称 : bsp.h
*	说    明 : 这是底层驱动模块所有的h文件的汇总文件。 应用程序只需 #include bsp.h 即可，
*			  不需要#include 每个模块的 h 文件  
*
*	浙江亚龙教育装备股份有限公司    www.yalong.cn
*
*********************************************************************************************************
*/

#ifndef _BSP_H_
#define _BSP_H

/* 定义 BSP 版本号 */
#define __STM32F4_BSP_VERSION		"1.0"

/* 开关全局中断的宏 */
#define ENABLE_INT()	__set_PRIMASK(0)	/* 使能全局中断 */
#define DISABLE_INT()	__set_PRIMASK(1)	/* 禁止全局中断 */

/* 这个宏仅用于调试阶段排错 */
#define BSP_Printf		printf

#include "common.h"

#ifndef TRUE
	#define TRUE  1
#endif

#ifndef FALSE
	#define FALSE 0
#endif

#include "bsp_timer.h"


#include "LCD_RA8875.h"
#include "LCD_SPFD5420.h"
#include "bsp_tft_lcd.h"
#include "bsp_ra8875_flash.h"
#include "bsp_ra8875_port.h"
#include "ra8875_flash.h"
#include "bsp_touch.h"
#include "bsp_spi_flash.h"


/* 提供给其他C文件调用的函数 */
void bsp_Init(void);
void bsp_Idle(void);

#endif
