#include "H/Function_Init.H"

void PWM_Init(void);
/*****************************************************
*�������ƣ�void PWM_Test(void)
*�������ܣ�PWM����
*��ڲ�����void
*���ڲ�����void
*****************************************************/
void PWM_Test(void)
{
	PWM_Init();
	while(1)
	{
	}
}
/*****************************************************
*�������ƣ�void PWM_Init(void)
*�������ܣ�PWM��ʼ��
*��ڲ�����void
*���ڲ�����void
*****************************************************/
void PWM_Init(void)
{
 	PWMCFG  = 0x00;		//���������ϵͳʱ��
	PWMCON  = 0X0f;
 	PWMPRD  = 0x63;	    //PWM����=(99+1)*(1/Fosc)
 	PWMDTY0 = 0x32;		//PWM0��Duty = 50/100 =1/2
	PWMDTY1 = 0x16;       
	PWMDTY2 = 0x32;
	PWMDTY3 = 0x16;      
	PWMCON |= 0x80;		//��PWMʹ�ܶ�
}