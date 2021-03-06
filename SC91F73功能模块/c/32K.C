//************************************************************
//  Copyright (c) 深圳市赛元微电子有限公司
//	文件名称	: IO_Set.c
//	作者		: 
//	模块功能	: IO常用设置
//	局部函数列表:
//  最后更正日期:
// 	版本		:
// 	更改记录	:73 rom前256byte禁止查表,因此在编译的时候，设置keil->option for Target->BL51 Locate->Code Range:0x100
//*************************************************************
#include "h\sc91f73_C.h"
unsigned int count;
//*************************************************************
// 函数名	：void X32K_init(void)
// 作者		：
// 功能		：32K初始化设置
// 参数		：无
// 返回值	：无
// 调用全局变量：无
// 修改全局变量：无
// 备注		：烧录时，Code Option请选择USEX32
//**************************************************************
void X32K_init()
{
	EX32K=0;	 //关闭32K中断
	X32CTL=0x82; //启动32K，不使能快速起振，每1秒产生一个interrupt;
	EX32K=1;	 //允许32K中断
}
//*************************************************************
// 函数名	：void X32K() interrupt 2
// 作者		：
// 功能		：每次中断，计数器加1
// 参数		：无
// 返回值	：无
// 调用全局变量：无
// 修改全局变量：无
// 备注		：
//**************************************************************
void X32K() interrupt 2
{
	count++;					 //计数器加1；
	if(count==3600)	
		count=0;						
}
void main()
{
	RSTCFG=0X0B;	  			 //切换RstPin为GPIO,lvr选择3.5V复位
	WDTCR = 0x90;				//1--1 -- 00    开WDT,WDT清0,WDT 524ms溢出;烧录时，可Code Option选择ENWDT
	X32K_init();
	EA=1;						//开总中断
	while(1)
	{
		WDTCR = 0x90;				//1--1 -- 00    开WDT,WDT清0,WDT 524ms溢出;烧录时，可Code Option选择ENWDT		
	}
}