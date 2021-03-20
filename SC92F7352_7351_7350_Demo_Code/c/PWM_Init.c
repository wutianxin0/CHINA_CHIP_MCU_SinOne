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
	PWMCON  = 0x00;  	//PWM0\PWM1\PWM2输出到I/O，Fsys频率；
 	PWMCFG0 = 0x07;		//PWM0\PWM1\PWM2不反向，PWM3\PWM4\PWM5输出到I/O
	PWMCFG1 = 0x00;     //PWM3\PWM4\PWM5不反向
 	PWMPRD  = 99;		//PWM周期=(99+1)			 
 	PWMDTY0 = 50;		//PWM0的Duty = 50/100  =1/2
 	PWMDTY1 = 25;		//PWM1的Duty = 25/100  =1/4
 	PWMDTY2 = 10;		//PWM2的Duty = 10/100  =1/10
	PWMDTY3 = 50;		//PWM3的Duty = 50/100  =1/2
 	PWMDTY4 = 25;		//PWM4的Duty = 25/100  =1/4
 	PWMDTY5 = 10;		//PWM5的Duty = 10/100  =1/10
 	PWMCON |= 0x80;		//启动PWM工作
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
	P02=~P02;	  
}