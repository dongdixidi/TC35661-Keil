#include "sys.h"
#include "common.h"
//#include "drivers/uart.h"
#include <string.h>

#include "plusc2c.h"
#include "bt.h"
#include "sys.h"
#include "usart.h"

uint8_t device_id[11]={0,1,2,3,4,5,6,7,8,9,10};
volatile uint8_t Uart3_pos=0;

// ��ȡϵͳʱ�Ӻ�������Ϊpan1026.cpp״̬������ʱʱ��
uint32_t task_get_ms_tick(void)
{
	return ms_timer;
}

volatile cfg_t config;


void GetID_str(char * id) //23 b
{
	uint8_t * b = device_id;

	sprintf(id, PSTR("%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X"), b[0], b[1], b[2], b[3], b[4], b[5], b[6], b[7], b[8], b[9], b[10]);
}

//reset�������ߣ��ظ�����
void reset_pin_high(void)
{
	PCout(11) = 1;
}

//reset�������ͣ�������λ
void reset_pin_low(void)
{
	PCout(11) = 0;
}


void GpioWrite(uint8_t Port, uint8_t Stat)
{
// LOW			0
// HIGH			1
// BT_EN		2
// BT_RESET		3
// BT_RTS		4
	if(Port == BT_RESET)
	{
		if(Stat){
			reset_pin_high();
		}else{
			reset_pin_low();
		}
	}
	
}



//���ڻ����ʼ��
void Usart::InitBuffers(uint8_t rx_size, uint8_t tx_size)
{
	Uart3_RcvCnt = 0;
	Uart3_pos = 0; 
}

//���ڿռ��
bool Usart::isRxBufferEmpty()
{
	return !(Uart3_RcvCnt - Uart3_pos);
}

//������
void Usart::ClearRxBuffer()
{
	Uart3_RcvCnt = 0;
	Uart3_pos = 0; 
}

//�պ���
void Usart::SetInterruptPriority(uint8_t p)
{ 
}
 
//д���ݵ�tc35661��rx����
void Usart::Write(uint8_t c)
{
	Uart3SendHex(c); 
}

//��ȡ���ڻ���������
uint8_t Usart::Read()
{
	uint8_t c;
	
	c = Uart3_Buff[Uart3_pos++];
	
	if(Uart3_RcvCnt == Uart3_pos){
		Uart3_RcvCnt = Uart3_pos = 0;
	}

	return c;

}

//�����������������tc35661���յ������ݣ�����Э�����������ݡ�
void BtRecDataToHost(uint8_t *BtRecdata, uint16_t len)
{
	while(len--){
		Uart1SendHex(*(BtRecdata++));
	}
}



//������ʼ��
void C_bt_init(void)
{
	bt_init();
}

//����ֹͣ
void C_bt_stop(void)
{
	bt_stop();
}

//����ģ��״̬�����ýӿ�
void C_bt_step(void)
{
	bt_step();
}
//����ģ�鸴λ
void C_bt_module_reset(void)
{
	bt_module_reset();
}
//����ģ���ʼ��
void C_bt_module_init(void)
{
	bt_module_init();
}

//ע������ģ��
void C_bt_module_deinit(void)
{
	bt_module_deinit();
}
//��ʼ��״̬
uint8_t C_bt_device_active(void)
{
	return bt_device_active();
}
//�������ݸ�����rx����
void C_bt_send(char * str, uint16_t len)
{
	bt_send(str,len);
}


//�Բ�״̬�Ƿ���������
uint8_t C_bt_selftest(void)
{
	return bt_selftest();
}





Usart::Usart()
{
	
}


Usart::~Usart()
{ 
	
}

///**
// * Initialize usart
// *
// * \param usart Usart structure
// * \param port Port structure
// * \param tx Number of tx pin
// * \param n Object index for ISR handling
// * \param baud Baudrate
// *
// * \note There are predefined usart modules like usart0, usart1 which contains usart and port structure, tx pin number and module index
// */
void Usart::Init(uint8_t usart,uint32_t baud)
{ 
	
}

void Usart::Stop()
{
//	return (this->rx_len == 0);
}

void Usart::TxComplete()
{
	
}


