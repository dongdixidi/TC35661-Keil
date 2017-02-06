//***********************************************************

#include "sys.h"
#include "plusc2c.h"

//***********************************************************
#define BT_RST PCout(11)
#define STR(A) 	(unsigned char*)(A)



int main ( void )
{
	
	uint8_t static ledstat;
	SystemInit();//ϵͳʱ�ӵȳ�ʼ��
	if(SysTick_Config(72000*1))	 //���ô��󷵻�1,max 16777216   Ĭ��72Mhz ʱ�� ,1ms��ʱ
	{							
		while(1);
	}
	
	LED_Init();	 //LED�˿ڳ�ʼ��
    PCout(4)=1;
	NVIC_Configuration();//����NVIC�жϷ���2:2λ��ռ���ȼ���2λ��Ӧ���ȼ�
	Uart1Init ( 115200 ); //���ڳ�ʼ��Ϊ115200
	Uart2Init ( 115200 ); //���ڳ�ʼ��Ϊ115200
	Uart3Init ( 115200 );//���ڳ�ʼ��Ϊ115200

//	Uart1SendStr(STR("uart1 init\r\n"));
//	Uart2SendStr(STR("uart2 init\r\n"));
//	Uart3SendStr(STR("uart3 init\r\n"));
	
	C_bt_init();
	C_bt_module_reset();
	C_bt_module_init();
	
	BT_RST = 1;	//��������ģ��
	LED1_ON;
	LED2_ON;
	delay_ms ( 500 );
	LED1_OFF;
	LED2_OFF; 

	while(1)
	{
		//���е�
		if( ms_delay_counter >500 ){
			ms_delay_counter = 0;
			if( ledstat ){
				LED1_ON;
			}else{
				LED1_OFF;
			}
			ledstat = !ledstat;
		}
		
		//�����ٶ��ر��ᵼ�³�ʼ��ʧ��
		if((ms_timer %10) == 0){
			C_bt_step();
		}
		
		//ģ���ʼ���ɹ����
		if(C_bt_selftest()){
			LED2_ON;
		}else{
			LED2_OFF;
		}
		
		//ģ����Ժ�ͨ������ok
		if(C_bt_device_active()){
			LED2_ON;
			if(Uart1_RcvCnt){
				delay_ms(100);
				//��������
				C_bt_send((char*)Uart1_Buff,Uart1_RcvCnt);
				Uart1_RcvCnt = 0;				
			}
		}else{
			LED2_OFF;
		}

	}
}
