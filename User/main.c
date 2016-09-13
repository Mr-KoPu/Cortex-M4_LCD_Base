#include "common.h"
#include "gpio.h"

extern TOUCH_T g_tTP;
extern const unsigned char gImage_bmp[320000];

void LCD_BaseTest(void)
{
  LCD_ClrScr(CL_BLUE);  		
  LCD_SetBackLight(BRIGHT_DEFAULT);  
  
  RA8875_SetFrontColor(CL_YELLOW);
  RA8875_SetBackColor(CL_BLUE);
  
  //��ʾ����
  RA8875_SetFont(RA_FONT_24, 0, 0);   
  RA8875_SetTextZoom(RA_SIZE_X1, RA_SIZE_X1);
  RA8875_DispStr(0, 0, "LCD��������");
  
  //����
  RA8875_DrawLine(300,10,700,10,CL_YELLOW);
  //������
  RA8875_DrawRect(0,60,80,90,CL_YELLOW);
  //���������
  RA8875_FillRect(150,60,80,90,CL_YELLOW);
  //��Բ
  RA8875_DrawCircle(40,200,40,CL_YELLOW);
  //���Բ
  RA8875_FillCircle(195,200,40,CL_YELLOW);
  //��ʾͼƬ
  RA8875_DrawBMP(350,50,400,400,(u16*)gImage_bmp);
}
void Touch_Test(void)
{
  char buf[64];
  u16 x,y;
  x = g_tTP.usAdcNowX;
  y = g_tTP.usAdcNowY;
  sprintf(buf, "����X:%3d  ", x);
  RA8875_SetFont(RA_FONT_16, 0, 0);
  RA8875_SetTextZoom(RA_SIZE_X1, RA_SIZE_X1);	
  RA8875_DispStr(10, 320, buf);
  
  sprintf(buf, "����Y:%3d  ", y);
  RA8875_SetFont(RA_FONT_16, 0, 0);
  RA8875_SetTextZoom(RA_SIZE_X1, RA_SIZE_X1);	
  RA8875_DispStr(10, 360, buf);
}
int main()
{
  SystemInit();
  bsp_Init();
 // TOUCH_Calibration();
  LCD_BaseTest();
  while(1)
  {
   TOUCH_Scan();
   Touch_Test(); 
  }
}


