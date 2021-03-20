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
 	PWMCFG  = 0x00;		//输出不反向，系统时钟
	PWMCON  = 0X0f;
 	PWMPRD  = 0x63;	    //PWM周期=(99+1)*(1/Fosc)
 	PWMDTY0 = 0x32;		//PWM0的Duty = 50/100 =1/2
	PWMDTY1 = 0x16;       
	PWMDTY2 = 0x32;
	PWMDTY3 = 0x16;      
	PWMCON |= 0x80;		//打开PWM使能端
}