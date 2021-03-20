
//************************************************************
//  Copyright (c) 深圳市赛元微电子有限公司
//	文件名称	: ADC.c
//	作者		: 
//	模块功能	: ADC转换的使用
//	局部函数列表:
//  最后更正日期:
// 	版本		:
// 	更改记录	:rom前256byte禁止查表,因此在编译的时候，设置keil->option for Target->BL51 Locate->Code Range:0x100
//*************************************************************
#include "h\sc91f8312_C.h"
unsigned char	 ValueH;
unsigned char	 ValueL;
unsigned int	 adcdat;
//*************************************************************
// 函数名	：void ADC_init(void)
// 作者		：
// 功能		：ADC转换初始化
// 参数		：无
// 返回值	：无
// 调用全局变量：无
// 修改全局变量：无
// 备注		：选择参考电压;选择ADC输入口;开ADC电源;设置2M;选通ADC通道;开始转换;完成转换,清EOC标志.
//**************************************************************	
void ADC_init()
{
	ADCCFG=0x80;						//选择ADD为参考电压VDD，选择P15作ADC输入口.
	ADCCR=0x87;							//打开ADC电源,选通P15通道
}
//*************************************************************
// 函数名	：void  ADC_Convert(void)
// 作者		：
// 功能		：ADC转换过程
// 参数		：无
// 返回值	：无
// 调用全局变量：无
// 修改全局变量：无
// 备注		：
//**************************************************************	
void  ADC_Convert(void)						
{													
	ADCCR |= 0x40;	   						 //开始转换，ADCS置1
	while(!(ADCCR&0x10));	         		 //等待 ADC转换完成;
	adcdat=ADCVH;		   					 //ADC高8位存入8位寄存器
	adcdat = (adcdat<<4)+(ADCVL>>4);			 //取得adc的值
	ADCCR &= 0xEF;   						 //转换完毕，清EOC		
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
	RSTCFG=0x2A;				//LVR=3.5V,P1.0切换为IO
	WDTCR = 0x90;				//1--1 -- 00    开WDT,WDT清0,WDT 262ms溢出;烧录时，可Code Option选择ENWDT
	ADC_init();
	while(1)
	{
		ADC_Convert();		//ADC转换
		WDTCR = 0x90;				//1--1 -- 00    开WDT,WDT清0,WDT 262ms溢出;烧录时，可Code Option选择ENWDT
	}	 	
		

}