#include <msp430x14x.h>
#include "Config.h"
char buffer[3];
void UART_Init()
{
  U0CTL|=SWRST;               //复位SWRST
  U0CTL|=CHAR;                //8位数据模式
  U0TCTL|=SSEL1;              //SMCLK为串口时钟
  U0BR1=baud_h;               //BRCLK=8MHZ,Baud=BRCLK/N
  U0BR0=baud_l;               //N=UBR+(UxMCTL)/8
  U0MCTL=0x00;                //微调寄存器为0，波特率9600bps
  ME1|=UTXE0+URXE0;                 //UART1发送使能
  P3SEL |= 0x30;
  P3DIR|= BIT4;               //设置IO口方向为输出
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
  while((IFG1&UTXIFG0)==0);          //发送寄存器空的时候发送数据
    U0TXBUF=data;
}
