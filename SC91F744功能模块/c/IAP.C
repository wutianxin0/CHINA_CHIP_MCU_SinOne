//************************************************************
//  Copyright (c) 深圳市赛元微电子有限公司
//	文件名称	: IAP.c
//	作者		: 
//	模块功能	:IAP( 256byte EEPROM)的使用
//	局部函数列表:
//  最后更正日期:
// 	版本		:
// 	更改记录	:744 rom前256byte禁止查表,因此在编译的时候，设置keil->option for Target->BL51 Locate->Code Range:0x100
//*************************************************************

#include "h\SC91F744_C.h"
#include <intrins.h>
//============================
//模块局部变量定义
//============================
unsigned char WDat,RDat;
unsigned char Addr;
unsigned char code  *POINTER = 0x03F00;								//定义ROM指针地址：0x03F00

//*************************************************************
// 函数名	：void IAPWrite(void)
// 作者		：
// 功能		：IAP写操作
// 参数		：无
// 返回值	：无
// 调用全局变量：无
// 修改全局变量：无
// 备注		：
//**************************************************************
void IAPWrite(void)
{
 	IAPDAT = WDat;			//送数据Dat1到IAP数据寄存器
 	IAPADL = Addr;			//写入地址值Addr1(0~256)
 	IAPKEY = 0xf0;			//此值可根据实际调整;保证本条指令执行后到对IAPCTL赋值前时间间隔小于240(0xf0)个系统时钟，否则IAP功能关闭
 	IAPCTL = 0x0a;			//执行IAP写入操作，同时CPU 16M Hold 1ms
 	_nop_();
 	_nop_();
 	_nop_();
 	_nop_();
}
//*************************************************************
// 函数名	：void IAPRead(void)
// 作者		：
// 功能		：IAP读操作
// 参数		：无
// 返回值	：无
// 调用全局变量：无
// 修改全局变量：无
// 备注		：
//**************************************************************
void IAPRead(void)
{
		RDat = *(POINTER+Addr);
}
void main()
{
	RSTCFG=0x2A;     			 //切换RstPin为GPIO,lvr选择3.5V复位
	WDTCR = 0x90;				//1--1 -- 00    开WDT,WDT清0,WDT=280MS溢出;烧录时，可Code Option选择ENWDT
	while(1)
	{
		IAPWrite();
		IAPRead();
		WDTCR = 0x90;				//1--1 -- 00    开WDT,WDT清0,WDT=280MS溢出;烧录时，可Code Option选择ENWDT	
	}
}