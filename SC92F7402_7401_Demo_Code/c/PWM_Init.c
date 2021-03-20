#include "H/Function_Init.H"

void PWM_Init(void);
void PWM_Dead(void);
/*****************************************************
*�������ƣ�void PWM_Test(void)
*�������ܣ�PWM����
*��ڲ�����void
*���ڲ�����void
*****************************************************/
void PWM_Test(void)
{
	PWM_Init();
//	PWM_Dead();
	while(1)
	{
	}
}
/*****************************************************
*�������ƣ�void PWM_Init(void)
*�������ܣ�PWM��ʼ��
*��ڲ�����void
*���ڲ�����void
*ע�⣺������ռ�ձȵĵ�2λҪ��дֵ����д��8λ
*****************************************************/
void PWM_Init(void)
{
 	PWMCFG  = 0x00;		//PWM012���������,PWM345�������
	PWMCON0 = 0X81;		//PWMʱ��Ϊϵͳʱ��
	PWMDTYA = 0x55;		//����PWM0123�ĵ���λDuty
	PWMDTYB = 0XaA;     //����PWM456�ĵ���λDuty
 	PWMPRD  = 0x3e;		//PWM���ڸ�8λ����
    PWMCON1 = 0X7f;     //ģʽ���ã�PWM���������
	PWMDTY0 = 0x1F;     //PWM0ռ�ձȸ�8λ����
	PWMDTY1 = 0X1F;     //PWM1ռ�ձȸ�8λ����
	PWMDTY2 = 0x1F;     //PWM2ռ�ձȸ�8λ����
	PWMDTY3 = 0x1F;     //PWM3ռ�ձȸ�8λ����
	PWMDTY4 = 0X0C;     //PWM4ռ�ձȸ�8λ����
	PWMDTY5 = 0X0C;		//PWM5ռ�ձȸ�8λ����
	PWMDTY6 = 0X0C;     //PWM6ռ�ձȸ�8λ����
	IE1 |= 0x02;        //��PWM�ж�
	EA = 1;             //�����ж�
}

/*
void PWM_Dead(void) //��������
{
	PWMCFG  = 0x38;		//PWM012���������,PWM345�������
	PWMCON0 = 0X03;		//PWMʱ��Ϊϵͳʱ�ӣ�pwm26�������
	PWMPRD  = 0x27;		//PWM���ڸ�8λ����
	PWMCON1 = 0XFF;     //ģʽ���ã�PWM���������
	PWMDTYA = 0x00;		//����PWM0123�ĵ���λDuty
 		
	PWMDTY0 = 0x14;     //PWM0ռ�ձȸ�8λ����
	PWMDTY1 = 0X14;     //PWM1ռ�ձȸ�8λ���� 
	PWMDTY2 = 0x14;     //PWM2ռ�ձȸ�8λ����
	PWMDTY3 = 0x88;     //����ʱ������  
	PWMDTYB = 0X00;     //PWM6ռ�ձȵ�2λ����
	PWMDTY6 = 0X10;     //PWM6ռ�ձȸ�8λ����
	PWMCON0 |= 0x80;	//��PWMʹ�ܶ�
}
*/

void PWMInt(void) interrupt 8
{	
	P20=~P20;	  
}