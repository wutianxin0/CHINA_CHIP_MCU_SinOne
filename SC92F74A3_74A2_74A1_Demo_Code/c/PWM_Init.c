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
*注意：周期与占空比的低2位要先写值，再写高8位
*****************************************************/
void PWM_Init(void)
{	
 	PWMCFG  = 0x00;		//设置PWM系统时钟，控制输出反向
	PWMCON  = 0X3f;		//控制是否输出到IO口
	PWMDTYA = 0xea;		//周期与PWM0/1/2占空比的低2位设置
 	PWMPRD  = 0x4f;		//周期高8位设置	
	PWMDTY0 = 0x28;     //PWM0占空比高8位设置
	PWMDTY1 = 0x28;     //PWM1占空比高8位设置
	PWMDTY2 = 0x28;     //PWM2占空比高8位设置
	PWMDTYB = 0X00;     //PWM3/4/5周期与占空比的低2位设置  
	PWMDTY3 = 0X14;     //PWM3占空比高8位设置
	PWMDTY4 = 0X14;		//PWM4占空比高8位设置
	PWMDTY5 = 0X14;     //PWM5占空比高8位设置
	PWMCON |= 0x80;		//打开PWM使能端
	IE1 |= 0x02;
	EA = 1;
}

/*
void PWM_Dead(void) //死区设置
{
	PWMCFG = 0X38;    //设置PWM系统时钟，控制输出反向
	PWMCON = 0X3F;	  //控制是否输出到IO口
	PWMDTYB |= 0X80;  //设置死区模式
	PWMPRD = 0X18;	  //周期高8位设置
	PWMDTYA = 0XEA;   //11 10 10 10	 周期与占空比低2位
	PWMPRD = 0X18;	  //周期与PWM0/1/2占空比的低2位设置
	PWMDTY0 = 0X0C;   //PWM0占空比高8位设置
	PWMDTY1 = 0X10;   //PWM1占空比高8位设置
	PWMDTY2 = 0X0C;   //PWM2占空比高8位设置
	PWMDTY3 = 0X00;   //死区时间设置
	PWMCON |= 0X80;	  //开PWM
}
*/

void PWMInt(void) interrupt 8
{	
	P00 = ~P00;	  
}