#include <msp430.h> 
#include "Config.h"
//���35����ͣ�49����ߣ�
/*С�� 20�����-50���ǰ��
 * צ��40���պϣ�-55�ſ�
 * main.c
 */
void Arm_Init(void)
{
TBCTL = TBSSEL0 + TBCLR; // ACLK, ��� TBR
TBCCR0 = 512 - 1; // PWM ����
TBCCTL1 = OUTMOD_7;
TBCCTL2 = OUTMOD_7;
TBCCTL3 = OUTMOD_7;
P4DIR |= 0x0f; // P1.2 ���
P4SEL |= 0x0f; // P1.2 TB1
TBCCR1=45;
TBCCR2=21;
TBCCR3=43;
delay_ms(300);
TBCCR1 = 0; // ռ�ձ� 384/512=0.75
TBCCR2 = 0;
TBCCR3 = 0; // ռ�ձ� 128/512=0.25
TBCTL |= MC0; // TB ������ģʽ
}
void Arm_Catch()
{
	TBCCR3 = 55;
	delay_ms(300);
	TBCCR1 = 35;
	delay_ms(300);
	TBCCR2 = 40;
	delay_ms(300);
	TBCCR3 = 55;
	delay_ms(300);
	TBCCR3 = 43;
	delay_ms(300);
	TBCCR1 = 45;
	delay_ms(300);
	TBCCR2 = 21;
}
void Arm_release()
{
	TBCCR3 = 55;
}
