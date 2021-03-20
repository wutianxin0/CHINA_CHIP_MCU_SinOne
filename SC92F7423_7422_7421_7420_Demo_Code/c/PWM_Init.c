#include "H/Function_Init.H"

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
	PWMCFG0 = 0X07;	//PWM2/1/0输出不反向，PWM5/4/3输出到IO口
	PWMCFG1 = 0X00;	//PWM5/4/3输出不反向
	PWMCON  = 0X3b;	//PWM2/1/0输出到IO口，PWM时钟源为fsys/8	
	PWMPRD  = 199;	//周期100us
	PWMDTY0 = 100;	//占空比50%
	PWMDTY1 = 100;
	PWMDTY2 = 100;
	PWMDTY3 = 100;
	PWMDTY4 = 100;
	PWMDTY5 = 100;
	PWMCON |= 0x80;     //开启PWM
	IE1 |= 0x02;        //开启PWM中断
	EA = 1;
}

/*****************************************************
*函数名称：void PWMInt(void) interrupt 8
*函数功能：PWM中断函数
*入口参数：void
*出口参数：void
*****************************************************/
void PWMInt(void) interrupt 8
{	
	P20=~P20;	  
}