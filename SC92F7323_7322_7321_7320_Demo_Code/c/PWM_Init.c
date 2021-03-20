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
	PWMCON  = 0x3A;		//PWM输出到IO，PWM时钟为Fsys/4
	PWMPRD  = 59;		//PWM周期=(59+1)*(1/6us)=10us	;
	PWMCFG  = 0x07;		//PWM输出不反向,输出至P25/P26/P27
 	PWMDTY0 = 30;		//PWM0的Duty = 30/60 =1/2
	PWMDTY1 = 15;       //PWM0的Duty = 15/60 =1/4
	PWMDTY2 = 10;       //PWM0的Duty = 10/60 =1/6
	PWMDTYA = 0x00;
	PWMCON |= 0x80;     //开启PWM
	IE1 |= 0x02;        //开启PWM中断
	EA = 1;
}

/*****************************************************
*函数名称：void PWMInt(void) interrupt 8
*函数功能：PWM中断服务函数
*入口参数：void
*出口参数：void
*****************************************************/
void PWMInt(void) interrupt 8
{	
	P20=~P20;	  
}