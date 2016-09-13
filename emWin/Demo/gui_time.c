#include "gui_time.h"


extern volatile int OS_TimeMS;

void TIM3_Init()
{
   TIM_TimeBaseInitTypeDef TIM_BaseInitStructure;
   NVIC_InitTypeDef NVIC_InitStructure;

   RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE);

    //NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);				   
   NVIC_InitStructure.NVIC_IRQChannel = TIM3_IRQn; 			//更新事件
   NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 2; 	
   NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1; 			
   NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE; 			//允许中断
   NVIC_Init(&NVIC_InitStructure); 							//写入设置
    
   TIM_BaseInitStructure.TIM_Prescaler = (SystemCoreClock/2)/ 100000-1;              //1M;
   TIM_BaseInitStructure.TIM_Period = 100;    //10us每中断
   TIM_BaseInitStructure.TIM_ClockDivision = 0;
   TIM_BaseInitStructure.TIM_CounterMode = TIM_CounterMode_Up;
   TIM_BaseInitStructure.TIM_RepetitionCounter = 0;
   TIM_TimeBaseInit(TIM3,&TIM_BaseInitStructure);
            
    //TIM_PrescalerConfig(TIM1, 72-1, TIM_PSCReloadMode_Immediate);
   TIM_ClearFlag(TIM3,TIM_IT_Update);
   TIM_ITConfig(TIM3,TIM_IT_Update,ENABLE);			
   TIM_Cmd(TIM3,ENABLE);
}
//void GUI_TOUCH_Exec(void);

void TIM3_IRQHandler(void)
{
    if(TIM_GetITStatus(TIM3,TIM_IT_Update)!=RESET)
	{
	   TIM_ClearITPendingBit(TIM3,TIM_IT_Update);
	   OS_TimeMS++;
	   if(OS_TimeMS%20==0)
	   {
	    GUI_TOUCH_Exec();
	   }
	}
}   

int GUI_TOUCH_X_MeasureX(void) 
{
 /* unsigned char t=0,t1,count=0;
  unsigned short int databuffer[10]={5,7,9,3,2,6,4,0,3,1};//数据组
  unsigned short temp=0,X=0;	
 */ 
  //while(/*GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_0)==0&&*/count<10)//循环读数10次
 /* {	   	  
    databuffer[count]=TPReadX();
    count++; 
  }  
  if(count==10)//一定要读到10次数据,否则丢弃
  {  
    do
    {	
      t1=0;		  
      for(t=0;t<count-1;t++)
      {
        if(databuffer[t]>databuffer[t+1])//升序排列
        {
          temp=databuffer[t+1];
          databuffer[t+1]=databuffer[t];
          databuffer[t]=temp;
          t1=1; 
        }  
      }
    }while(t1); 	    		 	 		  
    X=(databuffer[3]+databuffer[4]+databuffer[5])/3;	   
  }*/
 // return(X);  
  return(0);  
}

int GUI_TOUCH_X_MeasureY(void) 
{
  /* unsigned char t=0,t1,count=0;
   unsigned short int databuffer[10]={5,7,9,3,2,6,4,0,3,1};//数据组
   unsigned short temp=0,Y=0;	
 */
  // while(/*GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_0)==0&&*/count<10)	//循环读数10次
  /* {	   	  
    databuffer[count]=TPReadY();
    count++;  
   }  
    if(count==10)//一定要读到10次数据,否则丢弃
    {  
      do//将数据X升序排列
      {	
        t1=0;		  
        for(t=0;t<count-1;t++)
        {
         if(databuffer[t]>databuffer[t+1])//升序排列
         {
          temp=databuffer[t+1];
          databuffer[t+1]=databuffer[t];
          databuffer[t]=temp;
          t1=1; 
         }  
        }
      }while(t1); 	    		 	 		  
     Y=(databuffer[3]+databuffer[4]+databuffer[5])/3;	    
    }
   return(Y); */
  return(0);
}

void GUI_TOUCH_X_ActivateX(void)
{
  
}

void GUI_TOUCH_X_ActivateY(void)
{
  
}