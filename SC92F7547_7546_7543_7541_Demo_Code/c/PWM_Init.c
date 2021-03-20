#include "H/Function_Init.H"

#if (IC_MODEL == SC92F7547 || IC_MODEL == SC92F7546)
unsigned int xdata PWMRD_40  _at_  0x740;
unsigned int xdata PWMRD_41  _at_  0x742;
unsigned int xdata PWMRD_42  _at_  0x744;
unsigned int xdata PWMRD_43  _at_  0x746;
unsigned int xdata PWMRD_50  _at_  0x748;
unsigned int xdata PWMRD_51  _at_  0x74A;
unsigned int xdata PWMRD_52  _at_  0x74C;
unsigned int xdata PWMRD_53  _at_  0x74E;
#endif

#if (IC_MODEL == SC92F7543)
unsigned int xdata PWMRD_41  _at_  0x742;
unsigned int xdata PWMRD_42  _at_  0x744;
unsigned int xdata PWMRD_43  _at_  0x746;
#endif

unsigned int xdata PWMRD_Temp;
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
	//����������Ϊ200us��ռ�ձ�Ϊ50%��PWM����
	PWMCON = 0x7F;           //�������õ�8λ,200us
    PWMCFG = 0x8C;           //7:����  5-4��ʱ��Դѡ��  3-0���������ø�4λ	
	PWMRD_Temp = 0x8000 | 0x640;     //PWM��ռ�ձȵ��ڼĴ�ֻ��д,���Կɽ��ñ���PWMRD_temp����дռ�ձȵ�ֵ
	PWMRD_41 = PWMRD_Temp;
}