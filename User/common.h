#ifndef _COMMON_H_
#define _COMMON_H_

#include "stdio.h"
#include "string.h"
#include "stdlib.h"

#include <misc.h>
#include "delay.h"

#include "bsp.h"

#include <ysizet.h>
#include "stm32f4xx.h"
#include <stm32f4xx_spi.h>
#include <stm32f4xx_rcc.h>
#include <stm32f4xx_dma.h>
#include <stm32f4xx_tim.h>
#include <stm32f4xx_adc.h>
#include <stm32f4xx_dcmi.h>
#include <stm32f4xx_gpio.h>
#include <stm32f4xx_exti.h>
#include <stm32f4xx_fsmc.h>
#include <stm32f4xx_usart.h>
#include <stm32f4xx_syscfg.h>
#include <Dlib_product_string.h>



#define IAR


#ifdef IAR
#define INLINE  inline
#else
#define INLINE  __inline
#endif












#endif