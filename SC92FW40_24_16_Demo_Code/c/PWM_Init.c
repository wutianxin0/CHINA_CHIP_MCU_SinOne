#include "H/Function_Init.H"

#if (IC_MODEL == SC92FW40)
unsigned int xdata PWMRD[40]  _at_  0x700;
#endif

#if (IC_MODEL == SC92FW24)
unsigned int xdata PWMRD_00_03[4]  _at_  0x700;
unsigned int xdata PWMRD_11  _at_  0x712;
unsigned int xdata PWMRD_13  _at_  0x716;
unsigned int xdata PWMRD_20_25[6]  _at_  0x720;
unsigned int xdata PWMRD_30_33[4]  _at_  0x730;
unsigned int xdata PWMRD_40_43[4]  _at_  0x740;
unsigned int xdata PWMRD_50_53[4]  _at_  0x748;
#endif

#if (IC_MODEL == SC92FW16)
unsigned int xdata PWMRD_06  _at_  0x70C;
unsigned int xdata PWMRD_07  _at_  0x70E;
unsigned int xdata PWMRD_10_13[4]  _at_  0x710;
unsigned int xdata PWMRD_20_25[6]  _at_  0x720;
unsigned int xdata PWMRD_40_43[4]  _at_  0x740;
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
	//����������Ϊ100us��ռ�ձ�Ϊ50%��PWM����
	PWMCON0 = 0x7F;    //�������õ�8λ,100us
    PWMCFG0 = 0x8C;    //7:����  5-4��ʱ��Դѡ��  3-0���������ø�4λ
	PWMCON1 = 0x7F;    //�������õ�8λ,200us
    PWMCFG1 = 0x8C;    //7:����  5-4��ʱ��Դѡ��  3-0���������ø�4λ
	
	PWMRD_Temp = 0x8000 | 0x0640;  //PWM��ռ�ձȵ��ڼĴ�ֻ��д,���Կɽ��ñ���PWMRD_temp����дռ�ձȵ�ֵ
	
	#if (IC_MODEL == SC92FW40)
	PWMRD[0] = PWMRD_Temp;
	PWMRD[39] = PWMRD_Temp;
	#endif
	
	#if (IC_MODEL == SC92FW24 || IC_MODEL == SC92FW16)
	PWMRD_20_25[0] = PWMRD_Temp;
	PWMRD_40_43[0] = PWMRD_Temp;	
	#endif
	
}