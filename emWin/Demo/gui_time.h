#ifndef __GUI_TIME_H
#define __GUI_TIME_H

#include "gui.h"
#include "common.h" 

void TIM3_Init();
void TIM3_Pwm_Init(u16 arr,u16 psc);
void TIM5_PwmRemap_Init(u16 arr,u16 psc); 

#endif
