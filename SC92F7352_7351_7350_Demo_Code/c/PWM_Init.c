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
	PWMCON  = 0x00;  	//PWM0\PWM1\PWM2�����I/O��FsysƵ�ʣ�
 	PWMCFG0 = 0x07;		//PWM0\PWM1\PWM2������PWM3\PWM4\PWM5�����I/O
	PWMCFG1 = 0x00;     //PWM3\PWM4\PWM5������
 	PWMPRD  = 99;		//PWM����=(99+1)			 
 	PWMDTY0 = 50;		//PWM0��Duty = 50/100  =1/2
 	PWMDTY1 = 25;		//PWM1��Duty = 25/100  =1/4
 	PWMDTY2 = 10;		//PWM2��Duty = 10/100  =1/10
	PWMDTY3 = 50;		//PWM3��Duty = 50/100  =1/2
 	PWMDTY4 = 25;		//PWM4��Duty = 25/100  =1/4
 	PWMDTY5 = 10;		//PWM5��Duty = 10/100  =1/10
 	PWMCON |= 0x80;		//����PWM����
	IE1 |= 0x02;        //����PWM�ж�
	EA = 1;
}

/*****************************************************
*�������ƣ�void PWMInt(void) interrupt 8
*�������ܣ�PWM�жϷ�����
*��ڲ�����void
*���ڲ�����void
*****************************************************/
void PWMInt(void) interrupt 8
{	
	P02=~P02;	  
}