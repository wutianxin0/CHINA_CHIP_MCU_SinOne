#include "H/Function_Init.H"

void PWM_Init(void);
void PWM_Dead(void);
/*****************************************************
*函数名称：void PWM_Test(void)
*函数功能：PWM测试
*入口参数：void
*出口参数：void
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
*函数名称：void PWM_Init(void)
*函数功能：PWM初始化
*入口参数：void
*出口参数：void
*注意：周期与占空比的低2位要先写值，再写高8位
*****************************************************/
void PWM_Init(void)
{
 	PWMCFG  = 0x00;		//PWM012输出不反向,PWM345输出反向
	PWMCON0 = 0X81;		//PWM时钟为系统时钟
	PWMDTYA = 0x55;		//设置PWM0123的低两位Duty
	PWMDTYB = 0XaA;     //设置PWM456的低两位Duty
 	PWMPRD  = 0x3e;		//PWM周期高8位设置
    PWMCON1 = 0X7f;     //模式设置，PWM口输出设置
	PWMDTY0 = 0x1F;     //PWM0占空比高8位设置
	PWMDTY1 = 0X1F;     //PWM1占空比高8位设置
	PWMDTY2 = 0x1F;     //PWM2占空比高8位设置
	PWMDTY3 = 0x1F;     //PWM3占空比高8位设置
	PWMDTY4 = 0X0C;     //PWM4占空比高8位设置
	PWMDTY5 = 0X0C;		//PWM5占空比高8位设置
	PWMDTY6 = 0X0C;     //PWM6占空比高8位设置
	IE1 |= 0x02;        //打开PWM中断
	EA = 1;             //打开总中断
}

/*
void PWM_Dead(void) //死区设置
{
	PWMCFG  = 0x38;		//PWM012输出不反向,PWM345输出反向
	PWMCON0 = 0X03;		//PWM时钟为系统时钟，pwm26正常输出
	PWMPRD  = 0x27;		//PWM周期高8位设置
	PWMCON1 = 0XFF;     //模式设置，PWM口输出设置
	PWMDTYA = 0x00;		//设置PWM0123的低两位Duty
 		
	PWMDTY0 = 0x14;     //PWM0占空比高8位设置
	PWMDTY1 = 0X14;     //PWM1占空比高8位设置 
	PWMDTY2 = 0x14;     //PWM2占空比高8位设置
	PWMDTY3 = 0x88;     //死区时间设置  
	PWMDTYB = 0X00;     //PWM6占空比低2位设置
	PWMDTY6 = 0X10;     //PWM6占空比高8位设置
	PWMCON0 |= 0x80;	//打开PWM使能端
}
*/

void PWMInt(void) interrupt 8
{	
	P20=~P20;	  
}