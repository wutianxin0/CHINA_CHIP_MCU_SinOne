//************************************************************
//  Copyright (c) 深圳市赛元微电子有限公司
//	文件名称	: EX0_6.c
//	作者		: 
//	模块功能	: 外部中断的使用
//	局部函数列表:
//  最后更正日期:
// 	版本		:
// 	更改记录	: rom前256byte禁止查表,因此在编译的时候，设置keil->option for Target->BL51 Locate->Code Range:0x100
//*************************************************************

#include "h\sc91f736_C.h"
//*************************************************************
// 函数名	：void EX_init(void)
// 作者		：
// 功能		：外部中断初始化设置
// 参数		：无
// 返回值	：无
// 调用全局变量：无
// 修改全局变量：无
// 备注		：除外部中断1之外,其他外部中断均为下降沿触发
//**************************************************************
void EX_init(void)
{	
	EXIE = 0x3F;				//0011 1111  外部中断5...外部中断0使能
	EXIP = 0x00;				//0000 0000  外部中断5...外部中断0无中断优先级
	P1IT = 0x00;			//--000000		 外部 中断`选择双沿触发:	00-下降沿触发 01-无中断 10-双沿触发 11-上升沿触发	
}
//*************************************************************
// 函数名	：void EX0() interrupt	n
// 作者		：
// 功能		：外部中断
// 参数		：无
// 返回值	：无
// 调用全局变量：无
// 修改全局变量：无
// 备注		：硬件自动清除中断标志
//**************************************************************
void EX0() interrupt	7
{
}
void EX1() interrupt	8
{
}
void EX2() interrupt	9
{
}
void EX3() interrupt	10
{
}
void EX4() interrupt	11
{
}
void EX5() interrupt	12
{
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
	WDTCR = 0x90;				//1--1 -- 00    开WDT,WDT清0,WDT 262ms溢出;烧录时，可Code Option选择ENWDT
	EX_init();
	EA=1;						//开总中断
	while(1)
	{
		WDTCR = 0x90;				//1--1 -- 00    开WDT,WDT清0,WDT 262ms溢出;烧录时，可Code Option选择ENWDT
	}
}