/***********************************************************
酷学之家 http://simcom.taobao.com/
联系方式：15296811438 林工
*************************************************************/

#include "sys.h"
   
		    
//LED IO初始化
void LED_Init(void)
{
    GPIO_InitTypeDef GPIO_InitStructure; 
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA | RCC_APB2Periph_AFIO, ENABLE);//LED
    GPIO_PinRemapConfig(GPIO_Remap_SWJ_Disable,ENABLE);

    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_14; //PA14 red led
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;   
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; 
    GPIO_Init(GPIOA, &GPIO_InitStructure);
    //GPIO_SetBits(GPIOA,GPIO_Pin_14);
    //GPIO_ResetBits(GPIOA,GPIO_Pin_14);

	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);				//BL_rs

    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_11 | GPIO_Pin_4;     //PC11,bluetooth reset; PC4 power on
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;   
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; 
    GPIO_Init(GPIOC, &GPIO_InitStructure);

    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOD, ENABLE);				//blue led

    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2; 
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;   
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; 
    GPIO_Init(GPIOD, &GPIO_InitStructure);
    //GPIO_SetBits(GPIOD,GPIO_Pin_2);
    //GPIO_ResetBits(GPIOD,GPIO_Pin_2);
}
 
