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
	PWMCFG0 = 0X07;	//PWM2/1/0���������PWM5/4/3�����IO��
	PWMCFG1 = 0X00;	//PWM5/4/3���������
	PWMCON  = 0X3b;	//PWM2/1/0�����IO�ڣ�PWMʱ��ԴΪfsys/8	
	PWMPRD  = 199;	//����100us
	PWMDTY0 = 100;	//ռ�ձ�50%
	PWMDTY1 = 100;
	PWMDTY2 = 100;
	PWMDTY3 = 100;
	PWMDTY4 = 100;
	PWMDTY5 = 100;
	PWMCON |= 0x80;     //����PWM
	IE1 |= 0x02;        //����PWM�ж�
	EA = 1;
}

/*****************************************************
*�������ƣ�void PWMInt(void) interrupt 8
*�������ܣ�PWM�жϺ���
*��ڲ�����void
*���ڲ�����void
*****************************************************/
void PWMInt(void) interrupt 8
{	
	P20=~P20;	  
}