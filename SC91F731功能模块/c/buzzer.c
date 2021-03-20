//************************************************************
//  Copyright (c) 深圳市赛元微电子有限公司
//	文件名称	: IO_Set.c
//	作者		: 
//	模块功能	: IO常用设置
//	局部函数列表:
//  最后更正日期:
// 	版本		:
// 	更改记录	:731 rom前256byte禁止查表,因此在编译的时候，设置keil->option for Target->BL51 Locate->Code Range:0x100
//*************************************************************
#include "h\sc91f731_C.h"
void main()
{
	RSTCFG=0X0B;
	WDTCR = 0x90;				//1--1 -- 00    开WDT,WDT清0,WDT 524ms溢出;烧录时，可Code Option选择ENWDT
	BUZTGPH=0X81;				//启动BUZZER功能
	BUZTGPL=0Xff;				//频率：16M/（BUZTCP[11：0]+1）=16M/（256+255+1）=3.125M
	while(1)
	{
		WDTCR = 0x90;				//1--1 -- 00    开WDT,WDT清0,WDT 524ms溢出;烧录时，可Code Option选择ENWDT
	}
}