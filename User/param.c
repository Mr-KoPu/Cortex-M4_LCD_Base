/*
*********************************************************************************************************
*
*	ģ������ : Ӧ�ó������ģ��
*	�ļ����� : param.c
*	��    �� : V1.0
*	˵    �� : ��ȡ�ͱ���Ӧ�ó���Ĳ���
*	�޸ļ�¼ :
*
*********************************************************************************************************
*/

#include "bsp.h"
#include "param.h"

PARAM_T g_tParam;

/* ��16KB һ�������Ŀռ�Ԥ��������Ϊ������ For MDK */
//const uint8_t para_flash_area[16*1024] __attribute__((at(ADDR_FLASH_SECTOR_3)));

/*
*********************************************************************************************************
*	�� �� ��: LoadParam
*	����˵��: ��Flash��������g_tParam
*	��    �Σ���
*	�� �� ֵ: ��
*********************************************************************************************************
*/
void LoadParam(void)
{
#ifdef PARAM_SAVE_TO_FLASH
	/* ��ȡCPU Flash�еĲ��� */
	bsp_ReadCpuFlash(PARAM_ADDR, (uint8_t *)&g_tParam, sizeof(PARAM_T));
#endif
	
#ifdef PARAM_SAVE_TO_EEPROM
	/* ��ȡEEPROM�еĲ��� */	
	ee_ReadBytes((uint8_t *)&g_tParam, PARAM_ADDR, sizeof(PARAM_T));
#endif
		
	/* ���ȱʡ���� */
	if (g_tParam.ParamVer != PARAM_VER)
	{
		g_tParam.ParamVer = PARAM_VER;
		
		g_tParam.ucBackLight = 200;

		/* uip  ����IP��ַ */
		g_tParam.uip_ip[0] = 192;
		g_tParam.uip_ip[1] = 168;
		g_tParam.uip_ip[2] = 1;
		g_tParam.uip_ip[3] = 11;
		
		/* uip  �������� */
		g_tParam.uip_net_mask[0] = 255;
		g_tParam.uip_net_mask[1] = 255;
		g_tParam.uip_net_mask[2] = 255;
		g_tParam.uip_net_mask[3] = 0;
		
		/* uip  Ĭ������ */
		g_tParam.uip_net_gate[0] = 192;
		g_tParam.uip_net_gate[1] = 168;
		g_tParam.uip_net_gate[2] = 1;
		g_tParam.uip_net_gate[3] = 1;

		/* lwip  ����IP��ַ */
		g_tParam.lwip_ip[0] = 192;
		g_tParam.lwip_ip[1] = 168;
		g_tParam.lwip_ip[2] = 1;
		g_tParam.lwip_ip[3] = 12;
		
		/* lwip  �������� */
		g_tParam.lwip_net_mask[0] = 255;
		g_tParam.lwip_net_mask[1] = 255;
		g_tParam.lwip_net_mask[2] = 255;
		g_tParam.lwip_net_mask[3] = 0;
		
		/* lwip  Ĭ������ */
		g_tParam.lwip_net_gate[0] = 192;
		g_tParam.lwip_net_gate[1] = 168;
		g_tParam.lwip_net_gate[2] = 1;
		g_tParam.lwip_net_gate[3] = 1;

		g_tParam.ucRadioMode     = 0;				/* 1 = AM �� 0 = FM */
		g_tParam.ucRadioListType = 0;				/* ��̨�б����͡�0�人������1ȫ�� */
		g_tParam.ucIndexFM       = 0;				/* ��ǰFM��̨���� */
		g_tParam.ucIndexAM       = 0;				/* ��ǰ��̨���� */
		g_tParam.ucRadioVolume   = 36;				/* ���� */
		g_tParam.ucSpkOutEn      = 1;				/* ���������ʹ�� */

		SaveParam();							/* ���²���д��Flash */
	}	
}

/*
*********************************************************************************************************
*	�� �� ��: SaveParam
*	����˵��: ��ȫ�ֱ���g_tParam д�뵽CPU�ڲ�Flash
*	��    ��: ��
*	�� �� ֵ: ��
*********************************************************************************************************
*/
void SaveParam(void)
{
#ifdef PARAM_SAVE_TO_FLASH
	/* ��ȫ�ֵĲ����������浽 CPU Flash */
	bsp_WriteCpuFlash(PARAM_ADDR, (unsigned char *)&g_tParam, sizeof(PARAM_T));
#endif
	
#ifdef PARAM_SAVE_TO_EEPROM
	/* ��ȫ�ֵĲ����������浽EEPROM */
	ee_WriteBytes((uint8_t *)&g_tParam, PARAM_ADDR, sizeof(PARAM_T));
#endif	
}
