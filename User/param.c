/*
*********************************************************************************************************
*
*	模块名称 : 应用程序参数模块
*	文件名称 : param.c
*	版    本 : V1.0
*	说    明 : 读取和保存应用程序的参数
*	修改记录 :
*
*********************************************************************************************************
*/

#include "bsp.h"
#include "param.h"

PARAM_T g_tParam;

/* 将16KB 一个扇区的空间预留出来做为参数区 For MDK */
//const uint8_t para_flash_area[16*1024] __attribute__((at(ADDR_FLASH_SECTOR_3)));

/*
*********************************************************************************************************
*	函 数 名: LoadParam
*	功能说明: 从Flash读参数到g_tParam
*	形    参：无
*	返 回 值: 无
*********************************************************************************************************
*/
void LoadParam(void)
{
#ifdef PARAM_SAVE_TO_FLASH
	/* 读取CPU Flash中的参数 */
	bsp_ReadCpuFlash(PARAM_ADDR, (uint8_t *)&g_tParam, sizeof(PARAM_T));
#endif
	
#ifdef PARAM_SAVE_TO_EEPROM
	/* 读取EEPROM中的参数 */	
	ee_ReadBytes((uint8_t *)&g_tParam, PARAM_ADDR, sizeof(PARAM_T));
#endif
		
	/* 填充缺省参数 */
	if (g_tParam.ParamVer != PARAM_VER)
	{
		g_tParam.ParamVer = PARAM_VER;
		
		g_tParam.ucBackLight = 200;

		/* uip  本机IP地址 */
		g_tParam.uip_ip[0] = 192;
		g_tParam.uip_ip[1] = 168;
		g_tParam.uip_ip[2] = 1;
		g_tParam.uip_ip[3] = 11;
		
		/* uip  子网掩码 */
		g_tParam.uip_net_mask[0] = 255;
		g_tParam.uip_net_mask[1] = 255;
		g_tParam.uip_net_mask[2] = 255;
		g_tParam.uip_net_mask[3] = 0;
		
		/* uip  默认网关 */
		g_tParam.uip_net_gate[0] = 192;
		g_tParam.uip_net_gate[1] = 168;
		g_tParam.uip_net_gate[2] = 1;
		g_tParam.uip_net_gate[3] = 1;

		/* lwip  本机IP地址 */
		g_tParam.lwip_ip[0] = 192;
		g_tParam.lwip_ip[1] = 168;
		g_tParam.lwip_ip[2] = 1;
		g_tParam.lwip_ip[3] = 12;
		
		/* lwip  子网掩码 */
		g_tParam.lwip_net_mask[0] = 255;
		g_tParam.lwip_net_mask[1] = 255;
		g_tParam.lwip_net_mask[2] = 255;
		g_tParam.lwip_net_mask[3] = 0;
		
		/* lwip  默认网关 */
		g_tParam.lwip_net_gate[0] = 192;
		g_tParam.lwip_net_gate[1] = 168;
		g_tParam.lwip_net_gate[2] = 1;
		g_tParam.lwip_net_gate[3] = 1;

		g_tParam.ucRadioMode     = 0;				/* 1 = AM 或 0 = FM */
		g_tParam.ucRadioListType = 0;				/* 电台列表类型。0武汉地区或1全国 */
		g_tParam.ucIndexFM       = 0;				/* 当前FM电台索引 */
		g_tParam.ucIndexAM       = 0;				/* 当前电台索引 */
		g_tParam.ucRadioVolume   = 36;				/* 音量 */
		g_tParam.ucSpkOutEn      = 1;				/* 扬声器输出使能 */

		SaveParam();							/* 将新参数写入Flash */
	}	
}

/*
*********************************************************************************************************
*	函 数 名: SaveParam
*	功能说明: 将全局变量g_tParam 写入到CPU内部Flash
*	形    参: 无
*	返 回 值: 无
*********************************************************************************************************
*/
void SaveParam(void)
{
#ifdef PARAM_SAVE_TO_FLASH
	/* 将全局的参数变量保存到 CPU Flash */
	bsp_WriteCpuFlash(PARAM_ADDR, (unsigned char *)&g_tParam, sizeof(PARAM_T));
#endif
	
#ifdef PARAM_SAVE_TO_EEPROM
	/* 将全局的参数变量保存到EEPROM */
	ee_WriteBytes((uint8_t *)&g_tParam, PARAM_ADDR, sizeof(PARAM_T));
#endif	
}
