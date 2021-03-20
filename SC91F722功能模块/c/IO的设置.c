//************************************************************
//  Copyright (c) 深圳市赛元微电子有限公司
//	文件名称	: IO_Set.c
//	作者		: 
//	模块功能	: IO常用设置
//	局部函数列表:
//  最后更正日期:
// 	版本		:
// 	更改记录	:722 rom前256byte禁止查表,因此在编译的时候，设置keil->option for Target->BL51 Locate->Code Range:0x100
//*************************************************************
#include "h\sc91f722_C.h"

//============================
//模块内宏定义
//============================
#define		BS(SFR,NUM)		(SFR|=(1<<NUM))             //位置1
#define		BC(SFR,NUM)		(SFR&=~(1<<NUM))		  //位清0
//============================
//按键输入，使用准双向模式时，需要切换为准双向模式，并对该IO口写1,输出则选择强推挽模式
//============================
#define		SET(SFR,NUM)	(SFR = NUM)	

//=========================P1、P2、P3  准双向IO设置=========================================//
#define		P10M					(BC(P1CFG0,0),BC(P1CFG0,1))							//设置P10为准双向IO
#define		P11M					(BC(P1CFG0,2),BC(P1CFG0,3))							 //设置P11为准双向IO
#define		P12M					(BC(P1CFG0,4),BC(P1CFG0,5))							//设置P12为准双向IO
#define		P13M					(BC(P1CFG0,6),BC(P1CFG0,7))							//设置P13为准双向IO
#define		P14M					(BC(P1CFG1,0),BC(P1CFG1,1))							//设置P14为准双向IO
#define		P15M					(BC(P1CFG1,2),BC(P1CFG1,3))							 //设置P15为准双向IO
#define		P16M					(BC(P1CFG1,4),BC(P1CFG1,5))							//设置P16为准双向IO
#define		P17M					(BC(P1CFG1,6),BC(P1CFG1,7))							//设置P17为准双向IO

#define		P20M					(BC(P2CFG0,0),BC(P2CFG0,1))							//设置P20为准双向IO
#define		P21M					(BC(P2CFG0,2),BC(P2CFG0,3))							//设置P21为准双向IO

#define		P30M					(BC(P3CFG0,0),BC(P3CFG0,1))							//设置P30为准双向IO
#define		P31M					(BC(P3CFG0,2),BC(P3CFG0,3))							//设置P31为准双向IO
#define		P32M					(BC(P3CFG0,4),BC(P3CFG0,5))							//设置P32为准双向IO
#define		P33M					(BC(P3CFG0,6),BC(P3CFG0,7))							//设置P33为准双向IO
#define		P34M					(BC(P3CFG1,0),BC(P3CFG1,1))							//设置P34为准双向IO
#define		P35M					(BC(P3CFG1,2),BC(P3CFG1,3))							//设置P35为准双向IO
#define		P36M					(BC(P3CFG1,4),BC(P3CFG1,5))							//设置P36为准双向IO
#define		P37M					(BC(P3CFG1,6),BC(P3CFG1,7))							//设置P37为准双向IO	

//=========================P1、P2、P3  强推挽IO设置=========================================//

#define		P10PM					(BS(P1CFG0,0),BC(P1CFG0,1))							//设置P10为强推挽IO
#define		P11PM					(BS(P1CFG0,2),BC(P1CFG0,3))							 //设置P11为强推挽IO
#define		P12PM					(BS(P1CFG0,4),BC(P1CFG0,5))							//设置P12为强推挽IO
#define		P13PM					(BS(P1CFG0,6),BC(P1CFG0,7))							//设置P13为强推挽IO
#define		P14PM					(BS(P1CFG1,0),BC(P1CFG1,1))							//设置P14为强推挽IO
#define		P15PM					(BS(P1CFG1,2),BC(P1CFG1,3))							 //设置P15为强推挽IO
#define		P16PM					(BS(P1CFG1,4),BC(P1CFG1,5))							//设置P16为强推挽IO
#define		P17PM					(BS(P1CFG1,6),BC(P1CFG1,7))							//设置P17为强推挽IO

#define		P20PM					(BS(P2CFG0,0),BC(P2CFG0,1))							//设置P20为强推挽IO
#define		P21PM					(BS(P2CFG0,2),BC(P2CFG0,3))							//设置P21为强推挽IO

#define		P30PM					(BS(P3CFG0,0),BC(P3CFG0,1))							//设置P30为强推挽IO
#define		P31PM					(BS(P3CFG0,2),BC(P3CFG0,3))							//设置P31为强推挽IO
#define		P32PM					(BS(P3CFG0,4),BC(P3CFG0,5))							//设置P32为强推挽IO
#define		P33PM					(BS(P3CFG0,6),BC(P3CFG0,7))							//设置P33为强推挽IO
#define		P34PM					(BS(P3CFG1,0),BC(P3CFG1,1))							//设置P34为强推挽IO
#define		P35PM					(BS(P3CFG1,2),BC(P3CFG1,3))							//设置P35为强推挽IO
#define		P36PM					(BS(P3CFG1,4),BC(P3CFG1,5))							//设置P36为强推挽IO
#define		P37PM					(BS(P3CFG1,6),BC(P3CFG1,7))							//设置P37为强推挽IO

//=========================P1、P2、P3  高阻态(仅输入)IO设置=========================================//

#define		P10IM					(BC(P1CFG0,0),BS(P1CFG0,1))							//设置P10为高阻态IO
#define		P11IM					(BC(P1CFG0,2),BS(P1CFG0,3))							 //设置P11为高阻态IO
#define		P12IM					(BC(P1CFG0,4),BS(P1CFG0,5))							//设置P12为高阻态IO
#define		P13IM					(BC(P1CFG0,6),BS(P1CFG0,7))							//设置P13为高阻态IO
#define		P14IM					(BC(P1CFG1,0),BS(P1CFG1,1))							//设置P14为高阻态IO
#define		P15IM					(BC(P1CFG1,2),BS(P1CFG1,3))							 //设置P15为高阻态IO
#define		P16IM					(BC(P1CFG1,4),BS(P1CFG1,5))							//设置P16为高阻态IO
#define		P17IM					(BC(P1CFG1,6),BS(P1CFG1,7))							//设置P17为高阻态IO

#define		P20IM					(BC(P2CFG0,0),BS(P2CFG0,1))							//设置P20为高阻态IO
#define		P21IM					(BC(P2CFG0,2),BS(P2CFG0,3))							//设置P21为高阻态IO

#define		P30IM					(BC(P3CFG0,0),BS(P3CFG0,1))							//设置P30为高阻态IO
#define		P31IM					(BC(P3CFG0,2),BS(P3CFG0,3))							//设置P31为高阻态IO
#define		P32IM					(BC(P3CFG0,4),BS(P3CFG0,5))							//设置P32为高阻态IO
#define		P33IM					(BC(P3CFG0,6),BS(P3CFG0,7))							//设置P33为高阻态IO
#define		P34IM					(BC(P3CFG1,0),BS(P3CFG1,1))							//设置P34为高阻态IO
#define		P35IM					(BC(P3CFG1,2),BS(P3CFG1,3))							//设置P35为高阻态IO
#define		P36IM					(BC(P3CFG1,4),BS(P3CFG1,5))							//设置P36为高阻态IO
#define		P37IM					(BC(P3CFG1,6),BS(P3CFG1,7))							//设置P37为高阻态IO

//=========================P1、P2、P3  开漏输出IO设置=========================================//

#define		P10OM					(BS(P1CFG0,0),BS(P1CFG0,1))							//设置P10为开漏输出IO
#define		P11OM					(BS(P1CFG0,2),BS(P1CFG0,3))							 //设置P11为开漏输出IO
#define		P12OM					(BS(P1CFG0,4),BS(P1CFG0,5))							//设置P12为开漏输出IO
#define		P13OM					(BS(P1CFG0,6),BS(P1CFG0,7))							//设置P13为开漏输出IO
#define		P14OM					(BS(P1CFG1,0),BS(P1CFG1,1))							//设置P14为开漏输出IO
#define		P15OM					(BS(P1CFG1,2),BS(P1CFG1,3))							 //设置P15为开漏输出IO
#define		P16OM					(BS(P1CFG1,4),BS(P1CFG1,5))							//设置P16为开漏输出IO
#define		P17OM					(BS(P1CFG1,6),BS(P1CFG1,7))							//设置P17为开漏输出IO

#define		P20OM					(BS(P2CFG0,0),BS(P2CFG0,1))							//设置P20为开漏输出IO
#define		P21OM					(BS(P2CFG0,2),BS(P2CFG0,3))							//设置P21为开漏输出IO

#define		P30OM					(BS(P3CFG0,0),BS(P3CFG0,1))							//设置P30为开漏输出IO
#define		P31OM					(BS(P3CFG0,2),BS(P3CFG0,3))							//设置P31为开漏输出IO
#define		P32OM					(BS(P3CFG0,4),BS(P3CFG0,5))							//设置P32为开漏输出IO
#define		P33OM					(BS(P3CFG0,6),BS(P3CFG0,7))							//设置P33为开漏输出IO
#define		P34OM					(BS(P3CFG1,0),BS(P3CFG1,1))							//设置P34为开漏输出IO
#define		P35OM					(BS(P3CFG1,2),BS(P3CFG1,3))							//设置P35为开漏输出IO
#define		P36OM					(BS(P3CFG1,4),BS(P3CFG1,5))							//设置P36为开漏输出IO
#define		P37OM					(BS(P3CFG1,6),BS(P3CFG1,7))							//设置P37为开漏输出IO

//=========================P1、P2、P3 准双向IO设置输入=========================================//
#define		P10MI					(BC(P1CFG0,0),BC(P1CFG0,1),SET(P10,1))				//设置P10为准双向IO输入
#define		P11MI					(BC(P1CFG0,2),BC(P1CFG0,3),SET(P11,1))				//设置P11为准双向IO输入
#define		P12MI					(BC(P1CFG0,4),BC(P1CFG0,5),SET(P12,1))			 	//设置P12为准双向IO输入
#define		P13MI					(BC(P1CFG0,6),BC(P1CFG0,7),SET(P13,1))				//设置P13为准双向IO输入
#define		P14MI					(BC(P1CFG1,0),BC(P1CFG1,1),SET(P14,1))				//设置P14为准双向IO输入
#define		P15MI					(BC(P1CFG1,2),BC(P1CFG1,3),SET(P15,1))				//设置P15为准双向IO输入
#define		P16MI					(BC(P1CFG1,4),BC(P1CFG1,5),SET(P16,1))				//设置P16为准双向IO输入
#define		P17MI					(BC(P1CFG1,6),BC(P1CFG1,7),SET(P17,1))				//设置P17为准双向IO输入

#define		P20MI					(BC(P2CFG0,0),BC(P2CFG0,1),SET(P20,1))				//设置P20为准双向IO输入
#define		P21MI					(BC(P2CFG0,2),BC(P2CFG0,3),SET(P21,1))				//设置P21为准双向IO输入

#define		P30MI					(BC(P3CFG0,0),BC(P3CFG0,1),SET(P30,1))				//设置P30为准双向IO输入
#define		P31MI					(BC(P3CFG0,2),BC(P3CFG0,3),SET(P31,1))				//设置P31为准双向IO输入
#define		P32MI					(BC(P3CFG0,4),BC(P3CFG0,5),SET(P32,1))			 	//设置P32为准双向IO输入
#define		P33MI					(BC(P3CFG0,6),BC(P3CFG0,7),SET(P33,1))				//设置P33为准双向IO输入
#define		P34MI					(BC(P3CFG1,0),BC(P3CFG1,1),SET(P34,1))				//设置P34为准双向IO输入
#define		P35MI					(BC(P3CFG1,2),BC(P3CFG1,3),SET(P35,1))				//设置P35为准双向IO输入
#define		P36MI					(BC(P3CFG1,4),BC(P3CFG1,5),SET(P36,1))				//设置P36为准双向IO输入
#define		P37MI					(BC(P3CFG1,6),BC(P3CFG1,7),SET(P37,1))				//设置P37为准双向IO输入

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
	WDTCR = 0x90;				//1--1 -- 00    开WDT,WDT清0,8M WDT 524.288ms溢出;烧录时，可Code Option选择ENWDT
	P17MI;					   //按键输入
	P17PM;     				   //显示输出
	while(1)
	{
		WDTCR = 0x90;				//1--1 -- 00    开WDT,WDT清0,8M WDT 524.288ms溢出;烧录时，可Code Option选择ENWDT	
	}
}