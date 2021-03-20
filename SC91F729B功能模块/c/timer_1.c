//************************************************************
//  Copyright (c) 深圳市赛元微电子有限公司
//	文件名称	: timer_1.c
//	作者		: 
//	模块功能	: timer0工作方式1(16位定时器)的使用
//	局部函数列表:
//  最后更正日期:
// 	版本		:
// 	更改记录	:729B rom前256byte禁止查表,因此在编译的时候，设置keil->option for Target->BL51 Locate->Code Range:0x100
//*************************************************************

#include "h\sc91f729B_C.h"
#define		tst		P11
//*************************************************************
// 函数名	：void timer0init(void)
// 作者		：
// 功能		：Timer工作方式1，16位定时器初始化
// 参数		：无
// 返回值	：无
// 调用全局变量：无
// 修改全局变量：无
// 备注		：装入初值,125us定时
//**************************************************************
void timer0init(void)
{	
	TMCON=0x01;							//选择时钟分频,Fosc/4=4Mhz;1/4us
	TMOD=0x01;  						//设置工作方式1
	TH0=(65536-500)/256;       			//500*1/4us=125us
	TL0=(65536-500)%256;
 	TR0=0;					
   	ET0=1;								//Timer0使能
   	TR0=1;								//启动Timer0
}
//*************************************************************
// 函数名	：void timer0()interrupt 1
// 作者		：
// 功能		：Timer0中断
// 参数		：无
// 返回值	：无
// 调用全局变量：无
// 修改全局变量：无
// 备注		：硬件自动清除中断标志,16位定时器,需再次加载初值
//**************************************************************
void timer0()interrupt 1
{
	TH0=(65536-500)/256;   				//再次装入初值
	TL0=(65536-500)%256;
	tst =~tst;
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
	RSTCFG=0x0b;				//RSTpin切换GPIO,lvr 选择3.5V复位
	WDTCR = 0x90;				//1--1 -- 00    开WDT,WDT清0,WDT 524.288ms溢出;烧录时，可Code Option选择ENWDT
	timer0init();
	EA=1;						//开总中断

	for(; ;);
}