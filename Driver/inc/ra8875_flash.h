/*
*********************************************************************************************************
*
*	ģ������ : �ȴ������ĳ������
*	�ļ����� : ra8875_flash.h
*	��    �� : V1.0
*	˵    �� : ͷ�ļ�
*
*	Copyright (C), 2013-2014, ���������� www.armfly.com
*
*********************************************************************************************************
*/

#ifndef __RA8875_FLASH_H
#define __RA8875_FLASH_H

#define NOR_SECTOR_SIZE		(128 * 1024)	
#define NOR_SECTOR_COUNT	128			
#define NOR_FLASH_SIZE		(NOR_SECTOR_SIZE * NOR_SECTOR_COUNT)

typedef enum
{
    NOR_SUCCESS = 0,
    NOR_ONGOING = 1,
    NOR_ERROR   = 2,
    NOR_TIMEOUT = 3
}NOR_STATUS;

void RA8875FlashMain(void);

#endif

