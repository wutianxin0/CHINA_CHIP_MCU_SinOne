//************************************************************
//  Copyright (c) 深圳市赛元微电子有限公司
//	文件名称	: timer_1.c
//	作者		: 
//	模块功能	: timer0工作方式1(16位定时器)的使用
//	局部函数列表:
//  最后更正日期:
// 	版本		:
// 	更改记录	:rom前256byte禁止查表,因此在编译的时候，设置keil->option for Target->BL51 Locate->Code Range:0x100
//*************************************************************

#include "h\sc91f846_C.h"
#define		tst0		P06
#define		tst1		P07
//*************************************************************
// 函数名	：void timerinit(void)
// 作者		：
// 功能		：Timer定时器初始化
// 参数		：无
// 返回值	：无
// 调用全局变量：无
// 修改全局变量：无
// 备注		：Timer0初始化125us,Timer1初始化1ms
//**************************************************************
void timerinit(void)
{	
	TMCON=0x03;							//------ 11 ;Timer0和Tiemr1选择时钟分频,Fosc/4=4Mhz;1/4us
	TMOD=0x11;  						//0001 0001  ;Timer0和Timer1设置工作方式1	
//T0设置	
	TH0=(65536-500)/256;       			//500*1/4us=125us
	TL0=(65536-500)%256;
 	TR0=0;					
   	ET0=1;								//Timer0使能
   	TR0=1;								//启动Timer0
//T1设置   	
   	TH1 = (65536 - 4000)/256;		//4000*1/4us=1ms
   	TL1 = (65536 - 4000)%256;
   	TR1 = 0;
   	ET1 = 1;
   	TR1 =1;
}

//*************************************************************
// 函数名	：void timer0()interrupt 1
// 作者		：
// 功能		：Timer0中断定时125us
// 参数		：无
// 返回值	：无
// 调用全局变量：无
// 修改全局变量：无
// 备注		：硬件自动清除中断标志,16位定时器,需再次加载初值
//**************************************************************
void timer0()interrupt 1					//Timer0向量号 1
{
	TH0=(65536-500)/256;   				//再次装入初值
	TL0=(65536-500)%256;
	tst0 =~tst0;
}

//*************************************************************
// 函数名	：void timer1()interrupt 3
// 作者		：
// 功能		：Timer1中断定时1ms
// 参数		：无
// 返回值	：无
// 调用全局变量：无
// 修改全局变量：无
// 备注		：硬件自动清除中断标志,16位定时器,需再次加载初值
//**************************************************************
void timer1()interrupt 3				//Timer1向量号 3
{
	TH1 = (65536 - 4000)/256;		//再次装入初值
   	TL1 = (65536 - 4000)%256;
	tst1 =~tst1;
}
//*************************************************************
// 函数名	：void main()
// 作者		：
// 功能		：主函数
// 参数		：无
// 返回值	：无
// 调用全局变量：无
// 修改全局变量：无
// 备注		：
//**************************************************************
void main()
{
	RSTCFG=0x2A;				//RSTpin切换GPIO,lvr 选择3.5V复位
	P0CFG1=0X00;
	WDTCR = 0x90;				//1--1 -- 00    开WDT,WDT清0,WDT 262ms溢出;烧录时，可Code Option选择ENWDT
	timerinit();
	EA=1;						//开总中断

	while(1)
	{
		WDTCR = 0x90;				//1--1 -- 00    开WDT,WDT清0,WDT 262ms溢出;烧录时，可Code Option选择ENWDT
	}
}