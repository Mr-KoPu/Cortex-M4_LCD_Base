#include "gpio.h"

void GPIO_OUT_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStructure;
  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOG, ENABLE);
  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);
  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE);
  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOC, ENABLE);
  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOE, ENABLE);
  
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9|GPIO_Pin_11|GPIO_Pin_13|GPIO_Pin_14|GPIO_Pin_15;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
  GPIO_InitStructure.GPIO_OType= GPIO_OType_PP;
  GPIO_InitStructure.GPIO_Speed= GPIO_Speed_50MHz;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
  GPIO_Init(GPIOG, &GPIO_InitStructure);
  
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4|GPIO_Pin_8;
  GPIO_Init(GPIOA, &GPIO_InitStructure);
  
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3|GPIO_Pin_4|GPIO_Pin_5|GPIO_Pin_9;
  GPIO_Init(GPIOB, &GPIO_InitStructure);
  
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6;
  GPIO_Init(GPIOC, &GPIO_InitStructure);
  
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0|GPIO_Pin_4|GPIO_Pin_5;
  GPIO_Init(GPIOE, &GPIO_InitStructure);
  
  Voice_AllOFF(1);
  Voice_AllOFF(0);
}

void GPIO_Control(u8 port,u8 cmd)
{
  switch(port)
  {
   case 0: (cmd==0) ? GPIO_ResetBits(GPIOG,GPIO_Pin_9) : GPIO_SetBits(GPIOG,GPIO_Pin_9); break;   
   case 1: (cmd==0) ? GPIO_ResetBits(GPIOG,GPIO_Pin_11): GPIO_SetBits(GPIOG,GPIO_Pin_11);break;
   case 2: (cmd==0) ? GPIO_ResetBits(GPIOG,GPIO_Pin_13): GPIO_SetBits(GPIOG,GPIO_Pin_13);break;
   case 3: (cmd==0) ? GPIO_ResetBits(GPIOG,GPIO_Pin_14): GPIO_SetBits(GPIOG,GPIO_Pin_14);break;
   case 4: (cmd==0) ? GPIO_ResetBits(GPIOG,GPIO_Pin_15): GPIO_SetBits(GPIOG,GPIO_Pin_15);break;
   case 5: (cmd==0) ? GPIO_ResetBits(GPIOB,GPIO_Pin_3) : GPIO_SetBits(GPIOB,GPIO_Pin_3); break;
   case 6: (cmd==0) ? GPIO_ResetBits(GPIOB,GPIO_Pin_4) : GPIO_SetBits(GPIOB,GPIO_Pin_4); break;
   case 7: (cmd==0) ? GPIO_ResetBits(GPIOB,GPIO_Pin_5) : GPIO_SetBits(GPIOB,GPIO_Pin_5); break;   
  }
}

void Voice_Control(u8 port , u8 cmd)
{
  switch(port)
  {
   case 0: (cmd==0) ? GPIO_ResetBits(GPIOB,GPIO_Pin_9): GPIO_SetBits(GPIOB,GPIO_Pin_9); break;   
   case 1: (cmd==0) ? GPIO_ResetBits(GPIOA,GPIO_Pin_4): GPIO_SetBits(GPIOA,GPIO_Pin_4); break;
   case 2: (cmd==0) ? GPIO_ResetBits(GPIOA,GPIO_Pin_8): GPIO_SetBits(GPIOA,GPIO_Pin_8); break;
   case 3: (cmd==0) ? GPIO_ResetBits(GPIOE,GPIO_Pin_5): GPIO_SetBits(GPIOE,GPIO_Pin_5); break;
   case 4: (cmd==0) ? GPIO_ResetBits(GPIOE,GPIO_Pin_4): GPIO_SetBits(GPIOE,GPIO_Pin_4); break;
   case 5: (cmd==0) ? GPIO_ResetBits(GPIOE,GPIO_Pin_0): GPIO_SetBits(GPIOE,GPIO_Pin_0); break;
  }
}

void Voice_AllOFF(u8 port)
{
  if(port)
  {
   GPIO_SetBits(GPIOB,GPIO_Pin_9);
   GPIO_SetBits(GPIOA,GPIO_Pin_4);
   GPIO_SetBits(GPIOA,GPIO_Pin_8);
   GPIO_SetBits(GPIOE,GPIO_Pin_5);
  }
  else
  {
   GPIO_SetBits(GPIOE,GPIO_Pin_4);
   GPIO_SetBits(GPIOE,GPIO_Pin_0);
  }
}