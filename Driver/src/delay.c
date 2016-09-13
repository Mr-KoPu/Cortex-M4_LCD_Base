#include "delay.h"


void delay_us(u16 us)
{
  u16 i,j;
  for(i=us;i>0;i--)
    for(j=23;j>0;j--);
}

void delay_ms(u32 ms)
{
  u32 j,i;
  for(i=ms;i>0;i--)
    for(j=42500;j>0;j--);
}