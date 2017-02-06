#ifndef __LED_H
#define __LED_H	 

#include "sys.h"

//LED端口定义
#define LED1 PAout(14)// PA14
#define LED2 PDout(2)// PD2	


#define LED1_ON LED1=1// PA14
#define LED2_ON LED2=1// PD2	


#define LED1_OFF LED1=0// PA14
#define LED2_OFF LED2=0// PD2	

	
void LED_Init(void);//初始化

		 				    
#endif
