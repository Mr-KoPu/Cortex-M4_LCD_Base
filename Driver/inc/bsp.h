/*
*********************************************************************************************************
*
*	ģ������ : �ײ�Ӳ������
*	�ļ����� : bsp.h
*	˵    �� : ���ǵײ�����ģ�����е�h�ļ��Ļ����ļ��� Ӧ�ó���ֻ�� #include bsp.h ���ɣ�
*			  ����Ҫ#include ÿ��ģ��� h �ļ�  
*
*	�㽭��������װ���ɷ����޹�˾    www.yalong.cn
*
*********************************************************************************************************
*/

#ifndef _BSP_H_
#define _BSP_H

/* ���� BSP �汾�� */
#define __STM32F4_BSP_VERSION		"1.0"

/* ����ȫ���жϵĺ� */
#define ENABLE_INT()	__set_PRIMASK(0)	/* ʹ��ȫ���ж� */
#define DISABLE_INT()	__set_PRIMASK(1)	/* ��ֹȫ���ж� */

/* ���������ڵ��Խ׶��Ŵ� */
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


/* �ṩ������C�ļ����õĺ��� */
void bsp_Init(void);
void bsp_Idle(void);

#endif
