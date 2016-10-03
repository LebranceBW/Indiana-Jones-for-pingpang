#include <msp430.h> 
#include "Config.h"
//��� 45����ͣ�80����ߣ�
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
TBCTL |= MC0; // TB ������ģʽ
TBCCR1 = 70; // ռ�ձ� 384/512=0.75
TBCCR3 = 42; // ռ�ձ� 128/512=0.25
}
void Arm_Catch()
{
	TBCCR3 = 55;
	delay_ms(300);
	TBCCR1 = 47;
	delay_ms(300);
	TBCCR3=55;
	delay_ms(300);
	TBCCR3 = 42;
	delay_ms(300);
	TBCCR1 = 75;
}
void Arm_release()
{
	TBCCR3 = 55;
}
