/*
*********************************************************************************************************
*
*	ģ������ : Ӧ�ó������ģ��
*	�ļ����� : param.h
*	��    �� : V1.0
*	˵    �� : ͷ�ļ�
*
*	Copyright (C), 2012-2013, ���������� www.armfly.com
*
*********************************************************************************************************
*/

#ifndef __PARAM_H
#define __PARAM_H

//#define PARAM_SAVE_TO_EEPROM		/* �����洢���ⲿ��EEPROM */
//#define PARAM_SAVE_TO_FLASH		/* �����洢��CPU�ڲ�Flash */

#ifdef PARAM_SAVE_TO_EEPROM
	#define PARAM_ADDR	0       /* ��������ַ */
#endif

#ifdef PARAM_SAVE_TO_FLASH
	#define PARAM_ADDR		ADDR_FLASH_SECTOR_3	/* 0x0800C000 �м��16KB����������Ų��� */
	//#define PARAM_ADDR	 ADDR_FLASH_SECTOR_11		/* 0x080E0000 Flash���128K����������Ų��� */
#endif

#define PARAM_VER			0x00000102		/* �����汾 */

/* ȫ�ֲ��� */
__packed typedef struct
{
	uint32_t ParamVer;			/* �������汾���ƣ������ڳ�������ʱ�������Ƿ�Բ��������������� */

	/* LCD�������� */
	uint8_t ucBackLight;

	/* ������У׼���� */
	uint16_t usAdcX1;	/* ���Ͻ� */
	uint16_t usAdcY1;
	uint16_t usAdcX2;	/* ���½� */
	uint16_t usAdcY2;
	uint16_t usAdcX3;	/* ���½� */
	uint16_t usAdcY3;
	uint16_t usAdcX4;	/* ���Ͻ� */
	uint16_t usAdcY4;
	uint16_t XYChange;	/* X, Y �Ƿ񽻻�  */

	/* uip ip ��ַ���� */
	uint8_t uip_ip[4];			/* ����IP��ַ */
	uint8_t uip_net_mask[4];	/* �������� */
	uint8_t uip_net_gate[4];	/* Ĭ������ */

	/* lwip ip ��ַ���� */
	uint8_t lwip_ip[4];			/* ����IP��ַ */
	uint8_t lwip_net_mask[4];	/* �������� */
	uint8_t lwip_net_gate[4];	/* Ĭ������ */

	/* ���������� */
	uint8_t ucRadioMode;		/* AM �� FM */
	uint8_t ucRadioListType;		/* ��̨�б����͡��人������ȫ�� */
	uint8_t ucIndexFM;			/* ��ǰFM��̨���� */
	uint8_t ucIndexAM;			/* ��ǰ��̨���� */
	uint8_t ucRadioVolume;		/* ���� */
	uint8_t ucSpkOutEn;			/* ���������ʹ�� */

	/* ʾ�������� */
	uint8_t BackColor;			/* ���α������� */
	uint8_t WaveColor;			/* ����������ɫ */

	uint8_t DrawMode;				/* ��ǰ��ͼģʽ��0��ʾ��㣬1��ʾ���� */
	uint8_t PenSize;				/* ��ǰ�ʻ���С��0��ʾ1�����أ�1��ʾ2�����أ�2��ʾ4������ */
}
PARAM_T;

extern PARAM_T g_tParam;

void LoadParam(void);
void SaveParam(void);

#endif
