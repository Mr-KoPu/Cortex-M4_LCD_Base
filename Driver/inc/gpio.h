#ifndef _GPIO_H_
#define _GPIO_H_

#include "common.h"

#define OFF 1
#define ON  0

void GPIO_OUT_Init(void);

void Voice_AllOFF(u8 port);
void GPIO_Control(u8 port,u8 cmd);
void Voice_Control(u8 port,u8 cmd);





#endif 