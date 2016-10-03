#include <msp430.h> 
#include "Config.h"
//大臂 45（最低）80（最高）
/*小臂 20（最靠后）-50（最靠前）
 * 爪子40（闭合）-55张开
 * main.c
 */
void Arm_Init(void)
{
TBCTL = TBSSEL0 + TBCLR; // ACLK, 清除 TBR
TBCCR0 = 512 - 1; // PWM 周期
TBCCTL1 = OUTMOD_7;
TBCCTL2 = OUTMOD_7;
TBCCTL3 = OUTMOD_7;
P4DIR |= 0x0f; // P1.2 输出
P4SEL |= 0x0f; // P1.2 TB1
TBCTL |= MC0; // TB 增计数模式
TBCCR1 = 70; // 占空比 384/512=0.75
TBCCR3 = 42; // 占空比 128/512=0.25
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
