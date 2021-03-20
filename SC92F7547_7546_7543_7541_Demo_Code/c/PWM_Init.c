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
*函数名称：void PWM_Test(void)
*函数功能：PWM测试
*入口参数：void
*出口参数：void
*****************************************************/
void PWM_Test(void)
{
	PWM_Init();
	while(1)
	{
	}
}
/*****************************************************
*函数名称：void PWM_Init(void)
*函数功能：PWM初始化
*入口参数：void
*出口参数：void
*****************************************************/
void PWM_Init(void)
{
	//设置了周期为200us，占空比为50%的PWM波形
	PWMCON = 0x7F;           //周期设置低8位,200us
    PWMCFG = 0x8C;           //7:开关  5-4：时钟源选择  3-0：周期设置高4位	
	PWMRD_Temp = 0x8000 | 0x640;     //PWM的占空比调节寄存只可写,所以可借用变量PWMRD_temp来读写占空比的值
	PWMRD_41 = PWMRD_Temp;
}