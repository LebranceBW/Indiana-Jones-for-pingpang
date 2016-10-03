#include <msp430x14x.h>
#include "Config.h"
char buffer[3];
void UART_Init()
{
  U0CTL|=SWRST;               //��λSWRST
  U0CTL|=CHAR;                //8λ����ģʽ
  U0TCTL|=SSEL1;              //SMCLKΪ����ʱ��
  U0BR1=baud_h;               //BRCLK=8MHZ,Baud=BRCLK/N
  U0BR0=baud_l;               //N=UBR+(UxMCTL)/8
  U0MCTL=0x00;                //΢���Ĵ���Ϊ0��������9600bps
  ME1|=UTXE0+URXE0;                 //UART1����ʹ��
  P3SEL |= 0x30;
  P3DIR|= BIT4;               //����IO�ڷ���Ϊ���
  U0CTL&=~SWRST;
}

void Motor_Init()
{
	P5DIR=0xff;
	P5OUT=0x00;
}
void Motor_Stop()
{
	P5OUT=0x00;
}
void Motor_Back()
{
	P5OUT=0x55;
}
void Motor_Ahead()
{
	P5OUT=0xaa;
}
void Motor_Left()
{
	P5OUT=0x5a;
}
void Motor_Right()
{
	P5OUT=0xa5;
}
void Send_Byte(uchar data)
{
  while((IFG1&UTXIFG0)==0);          //���ͼĴ����յ�ʱ��������
    U0TXBUF=data;
}
