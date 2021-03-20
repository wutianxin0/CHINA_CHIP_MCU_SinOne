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
*ע�⣺������ռ�ձȵĵ�2λҪ��дֵ����д��8λ
*****************************************************/
void PWM_Init(void)
{	
 	PWMCFG  = 0x00;		//����PWMϵͳʱ�ӣ������������
	PWMCON  = 0X3f;		//�����Ƿ������IO��
	PWMDTYA = 0xea;		//������PWM0/1/2ռ�ձȵĵ�2λ����
 	PWMPRD  = 0x4f;		//���ڸ�8λ����	
	PWMDTY0 = 0x28;     //PWM0ռ�ձȸ�8λ����
	PWMDTY1 = 0x28;     //PWM1ռ�ձȸ�8λ����
	PWMDTY2 = 0x28;     //PWM2ռ�ձȸ�8λ����
	PWMDTYB = 0X00;     //PWM3/4/5������ռ�ձȵĵ�2λ����  
	PWMDTY3 = 0X14;     //PWM3ռ�ձȸ�8λ����
	PWMDTY4 = 0X14;		//PWM4ռ�ձȸ�8λ����
	PWMDTY5 = 0X14;     //PWM5ռ�ձȸ�8λ����
	PWMCON |= 0x80;		//��PWMʹ�ܶ�
	IE1 |= 0x02;
	EA = 1;
}

/*
void PWM_Dead(void) //��������
{
	PWMCFG = 0X38;    //����PWMϵͳʱ�ӣ������������
	PWMCON = 0X3F;	  //�����Ƿ������IO��
	PWMDTYB |= 0X80;  //��������ģʽ
	PWMPRD = 0X18;	  //���ڸ�8λ����
	PWMDTYA = 0XEA;   //11 10 10 10	 ������ռ�ձȵ�2λ
	PWMPRD = 0X18;	  //������PWM0/1/2ռ�ձȵĵ�2λ����
	PWMDTY0 = 0X0C;   //PWM0ռ�ձȸ�8λ����
	PWMDTY1 = 0X10;   //PWM1ռ�ձȸ�8λ����
	PWMDTY2 = 0X0C;   //PWM2ռ�ձȸ�8λ����
	PWMDTY3 = 0X00;   //����ʱ������
	PWMCON |= 0X80;	  //��PWM
}
*/

void PWMInt(void) interrupt 8
{	
	P00 = ~P00;	  
}