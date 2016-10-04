#include <msp430x14x.h>
#include "Config.h"
#include "BlueTooth.h"
#include "Arm.h"
void main(void)
{
   WDT_Init();                         //���Ź�����
  Clock_Init();                       //ϵͳʱ������
  Arm_Init();
  UART_Init();                        //�������ó�ʼ��
  IE1=IE1|URXIE0;            //�ҵ������� IE1������ֵ,���IE1ֻ��������������ı䣡������������������
  _EINT();//���ж�
  Motor_Init();
  while(1)
  {
		  switch(buffer[2])
		  {
		  	  case 'A':Motor_Ahead();break;
		  	  case 'F':Motor_Stop();break;
		  	  case 'B':Motor_Back();break;
		  	  case 'C':Motor_Left();break;
		  	  case 'D':Motor_Right();break;
		  	  case '1':Arm_Catch();break;
		  	  case '2':Arm_release();break;
		  }
  }
}

#pragma vector=USART0RX_VECTOR
__interrupt void UART0_RX_ISR(void)
{
	  buffer[2]=U0RXBUF;
}


#pragma vector=USART0TX_VECTOR
__interrupt void UART0_TX_ISR(void)
{

}
