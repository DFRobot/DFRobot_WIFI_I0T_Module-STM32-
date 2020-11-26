#ifndef __usart_H
#define __usart_H

#include "system.h" 
#include "stdio.h"
#include "DFRobot_queue.h"

#define RX_BUF_MAX_LEN  			200  	//�����������ֽ��� 200
	  	
extern char Data_RX_BUF[RX_BUF_MAX_LEN]; //���ջ���,���USART_REC_LEN���ֽ�.ĩ�ֽ�Ϊ���з� 
extern u16 USART_RX_STA;         		//����״̬���	


extern u8 readstate;
extern char *testbuf[256];
void USART1_Init(u32 bound);
void USART3_Init(u32 bound);
void Usart_SendStriong(USART_TypeDef*USARTx, char *str);


#endif


