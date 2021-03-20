//************************************************************
//  Copyright (c) 深圳市赛元微电子有限公司
//	文件名称	: IO_Set.c
//	作者		: 
//	模块功能	: IO常用设置
//	局部函数列表:
//  最后更正日期:
// 	版本		:
// 	更改记录	:rom前256byte禁止查表,因此在编译的时候，设置keil->option for Target->BL51 Locate->Code Range:0x100
//*************************************************************
#include "h\sc91f735_C.h"

//============================
//模块内宏定义
//============================
#define		BS(SFR,NUM)		(SFR|=(1<<NUM))             //位置1
#define		BC(SFR,NUM)		(SFR&=~(1<<NUM))		    //位清0
//============================
//按键输入，使用准双向模式时，需要切换为准双向模式，并对该IO口写1,输出则选择强推挽模式
//============================
#define		SET(SFR,NUM)	(SFR = NUM)	

//=========================P1、P2、P3、P4 准双向IO设置=========================================//
#define		P10M					(BC(P1CFG0,0),BC(P1CFG0,1))							//设置P10为准双向IO
#define		P11M					(BC(P1CFG0,2),BC(P1CFG0,3))							//设置P11为准双向IO
#define		P12M					(BC(P1CFG0,4),BC(P1CFG0,5))							//设置P12为准双向IO
#define		P13M					(BC(P1CFG0,6),BC(P1CFG0,7))							//设置P13为准双向IO
#define		P14M					(BC(P1CFG1,0),BC(P1CFG1,1))							//设置P14为准双向IO
#define		P15M					(BC(P1CFG1,2),BC(P1CFG1,3))							//设置P15为准双向IO
#define		P16M					(BC(P1CFG1,4),BC(P1CFG1,5))							//设置P16为准双向IO
#define		P17M					(BC(P1CFG1,6),BC(P1CFG1,7))							//设置P17为准双向IO

#define		P20M					(BC(P2CFG0,0),BC(P2CFG0,1))							//设置P20为准双向IO
#define		P21M					(BC(P2CFG0,2),BC(P2CFG0,3))							//设置P21为准双向IO
#define		P22M					(BC(P2CFG0,4),BC(P2CFG0,5))							//设置P22为准双向IO
#define		P23M					(BC(P2CFG0,6),BC(P2CFG0,7))							//设置P23为准双向IO
#define		P24M					(BC(P2CFG1,0),BC(P2CFG1,1))							//设置P24为准双向IO
#define		P25M					(BC(P2CFG1,2),BC(P2CFG1,3))							//设置P25为准双向IO
#define		P26M					(BC(P2CFG1,4),BC(P2CFG1,5))							//设置P26为准双向IO
#define		P27M					(BC(P2CFG1,6),BC(P2CFG1,7))							//设置P27为准双向IO

#define		P30M					(BC(P3CFG0,0),BC(P3CFG0,1))							//设置P30为准双向IO
#define		P31M					(BC(P3CFG0,2),BC(P3CFG0,3))							//设置P31为准双向IO
#define		P32M					(BC(P3CFG0,4),BC(P3CFG0,5))							//设置P32为准双向IO
#define		P33M					(BC(P3CFG0,6),BC(P3CFG0,7))							//设置P33为准双向IO
#define		P34M					(BC(P3CFG1,0),BC(P3CFG1,1))							//设置P34为准双向IO
#define		P35M					(BC(P3CFG1,2),BC(P3CFG1,3))							//设置P35为准双向IO
#define		P36M					(BC(P3CFG1,4),BC(P3CFG1,5))							//设置P36为准双向IO
#define		P37M					(BC(P3CFG1,6),BC(P3CFG1,7))							//设置P37为准双向IO

#define		P40M					(BC(P4CFG0,0),BC(P4CFG0,1))							//设置P40为准双向IO
#define		P41M					(BC(P4CFG0,2),BC(P4CFG0,3))							//设置P41为准双向IO
#define		P42M					(BC(P4CFG0,4),BC(P4CFG0,5))							//设置P42为准双向IO
#define		P43M					(BC(P4CFG0,6),BC(P4CFG0,7))							//设置P43为准双向IO
#define		P44M					(BC(P4CFG1,0),BC(P4CFG1,1))							//设置P44为准双向IO
#define		P45M					(BC(P4CFG1,2),BC(P4CFG1,3))							//设置P45为准双向IO

//=========================P1、P2、P3、P4  强推挽IO设置=========================================//

#define		P10PM					(BS(P1CFG0,0),BC(P1CFG0,1))							//设置P10为强推挽IO
#define		P11PM					(BS(P1CFG0,2),BC(P1CFG0,3))							//设置P11为强推挽IO
#define		P12PM					(BS(P1CFG0,4),BC(P1CFG0,5))							//设置P12为强推挽IO
#define		P13PM					(BS(P1CFG0,6),BC(P1CFG0,7))							//设置P13为强推挽IO
#define		P14PM					(BS(P1CFG1,0),BC(P1CFG1,1))							//设置P14为强推挽IO
#define		P15PM					(BS(P1CFG1,2),BC(P1CFG1,3))							//设置P15为强推挽IO
#define		P16PM					(BS(P1CFG1,4),BC(P1CFG1,5))							//设置P16为强推挽IO
#define		P17PM					(BS(P1CFG1,6),BC(P1CFG1,7))							//设置P17为强推挽IO

#define		P20PM					(BS(P2CFG0,0),BC(P2CFG0,1))							//设置P20为强推挽IO
#define		P21PM					(BS(P2CFG0,2),BC(P2CFG0,3))							//设置P21为强推挽IO
#define		P22PM					(BS(P2CFG0,4),BC(P2CFG0,5))							//设置P22为强推挽IO
#define		P23PM					(BS(P2CFG0,6),BC(P2CFG0,7))							//设置P23为强推挽IO
#define		P24PM					(BS(P2CFG1,0),BC(P2CFG1,1))							//设置P24为强推挽IO
#define		P25PM					(BS(P2CFG1,2),BC(P2CFG1,3))							//设置P25为强推挽IO
#define		P26PM					(BS(P2CFG1,4),BC(P2CFG1,5))							//设置P26为强推挽IO
#define		P27PM					(BS(P2CFG1,6),BC(P2CFG1,7))							//设置P27为强推挽IO

#define		P30PM					(BS(P3CFG0,0),BC(P3CFG0,1))							//设置P30为强推挽IO
#define		P31PM					(BS(P3CFG0,2),BC(P3CFG0,3))							//设置P31为强推挽IO
#define		P32PM					(BS(P3CFG0,4),BC(P3CFG0,5))							//设置P32为强推挽IO
#define		P33PM					(BS(P3CFG0,6),BC(P3CFG0,7))							//设置P33为强推挽IO
#define		P34PM					(BS(P3CFG1,0),BC(P3CFG1,1))							//设置P34为强推挽IO
#define		P35PM					(BS(P3CFG1,2),BC(P3CFG1,3))							//设置P35为强推挽IO
#define		P36PM					(BS(P3CFG1,4),BC(P3CFG1,5))							//设置P36为强推挽IO
#define		P37PM					(BS(P3CFG1,6),BC(P3CFG1,7))							//设置P37为强推挽IO

#define		P40PM					(BS(P4CFG0,0),BC(P4CFG0,1))							//设置P40为强推挽IO
#define		P41PM					(BS(P4CFG0,2),BC(P4CFG0,3))							//设置P41为强推挽IO
#define		P42PM					(BS(P4CFG0,4),BC(P4CFG0,5))							//设置P42为强推挽IO
#define		P43PM					(BS(P4CFG0,6),BC(P4CFG0,7))							//设置P43为强推挽IO
#define		P44PM					(BS(P4CFG1,0),BC(P4CFG1,1))							//设置P44为强推挽IO
#define		P45PM					(BS(P4CFG1,2),BC(P4CFG1,3))							//设置P45为强推挽IO

//=========================P1、P2、P3、P4  高阻态(仅输入)IO设置=========================================//

#define		P10IM					(BC(P1CFG0,0),BS(P1CFG0,1))							//设置P10为高阻态IO
#define		P11IM					(BC(P1CFG0,2),BS(P1CFG0,3))							//设置P11为高阻态IO
#define		P12IM					(BC(P1CFG0,4),BS(P1CFG0,5))							//设置P12为高阻态IO
#define		P13IM					(BC(P1CFG0,6),BS(P1CFG0,7))							//设置P13为高阻态IO
#define		P14IM					(BC(P1CFG1,0),BS(P1CFG1,1))							//设置P14为高阻态IO
#define		P15IM					(BC(P1CFG1,2),BS(P1CFG1,3))							//设置P15为高阻态IO
#define		P16IM					(BC(P1CFG1,4),BS(P1CFG1,5))							//设置P16为高阻态IO
#define		P17IM					(BC(P1CFG1,6),BS(P1CFG1,7))							//设置P17为高阻态IO

#define		P20IM					(BC(P2CFG0,0),BS(P2CFG0,1))							//设置P20为高阻态IO
#define		P21IM					(BC(P2CFG0,2),BS(P2CFG0,3))							//设置P21为高阻态IO
#define		P22IM					(BC(P2CFG0,4),BS(P2CFG0,5))							//设置P22为高阻态IO
#define		P23IM					(BC(P2CFG0,6),BS(P2CFG0,7))							//设置P23为高阻态IO
#define		P24IM					(BC(P2CFG1,0),BS(P2CFG1,1))							//设置P24为高阻态IO
#define		P25IM					(BC(P2CFG1,2),BS(P2CFG1,3))							//设置P25为高阻态IO
#define		P26IM					(BC(P2CFG1,4),BS(P2CFG1,5))							//设置P26为高阻态IO
#define		P27IM					(BC(P2CFG1,6),BS(P2CFG1,7))							//设置P27为高阻态IO

#define		P30IM					(BC(P3CFG0,0),BS(P3CFG0,1))							//设置P30为高阻态IO
#define		P31IM					(BC(P3CFG0,2),BS(P3CFG0,3))							//设置P31为高阻态IO
#define		P32IM					(BC(P3CFG0,4),BS(P3CFG0,5))							//设置P32为高阻态IO
#define		P33IM					(BC(P3CFG0,6),BS(P3CFG0,7))							//设置P33为高阻态IO
#define		P34IM					(BC(P3CFG1,0),BS(P3CFG1,1))							//设置P34为高阻态IO
#define		P35IM					(BC(P3CFG1,2),BS(P3CFG1,3))							//设置P35为高阻态IO
#define		P36IM					(BC(P3CFG1,4),BS(P3CFG1,5))							//设置P36为高阻态IO
#define		P37IM					(BC(P3CFG1,6),BS(P3CFG1,7))							//设置P37为高阻态IO

#define		P40IM					(BC(P4CFG0,0),BS(P4CFG0,1))							//设置P40为高阻态IO
#define		P41IM					(BC(P4CFG0,2),BS(P4CFG0,3))							//设置P41为高阻态IO
#define		P42IM					(BC(P4CFG0,4),BS(P4CFG0,5))							//设置P42为高阻态IO
#define		P43IM					(BC(P4CFG0,6),BS(P4CFG0,7))							//设置P43为高阻态IO
#define		P44IM					(BC(P4CFG1,0),BS(P4CFG1,1))							//设置P44为高阻态IO
#define		P45IM					(BC(P4CFG1,2),BS(P4CFG1,3))							//设置P45为高阻态IO

//=========================P1、P2、P3、P4  开漏输出IO设置=========================================//

#define		P10OM					(BS(P1CFG0,0),BS(P1CFG0,1))							//设置P10为开漏输出IO
#define		P11OM					(BS(P1CFG0,2),BS(P1CFG0,3))							//设置P11为开漏输出IO
#define		P12OM					(BS(P1CFG0,4),BS(P1CFG0,5))							//设置P12为开漏输出IO
#define		P13OM					(BS(P1CFG0,6),BS(P1CFG0,7))							//设置P13为开漏输出IO
#define		P14OM					(BS(P1CFG1,0),BS(P1CFG1,1))							//设置P14为开漏输出IO
#define		P15OM					(BS(P1CFG1,2),BS(P1CFG1,3))							//设置P15为开漏输出IO
#define		P16OM					(BS(P1CFG1,4),BS(P1CFG1,5))							//设置P16为开漏输出IO
#define		P17OM					(BS(P1CFG1,6),BS(P1CFG1,7))							//设置P17为开漏输出IO

#define		P20OM					(BS(P2CFG0,0),BS(P2CFG0,1))							//设置P20为开漏输出IO
#define		P21OM					(BS(P2CFG0,2),BS(P2CFG0,3))							//设置P21为开漏输出IO
#define		P22OM					(BS(P2CFG0,4),BS(P2CFG0,5))							//设置P22为开漏输出IO
#define		P23OM					(BS(P2CFG0,6),BS(P2CFG0,7))							//设置P23为开漏输出IO
#define		P24OM					(BS(P2CFG1,0),BS(P2CFG1,1))							//设置P24为开漏输出IO
#define		P25OM					(BS(P2CFG1,2),BS(P2CFG1,3))							//设置P25为开漏输出IO
#define		P26OM					(BS(P2CFG1,4),BS(P2CFG1,5))							//设置P26为开漏输出IO
#define		P27OM					(BS(P2CFG1,6),BS(P2CFG1,7))							//设置P27为开漏输出IO

#define		P30OM					(BS(P3CFG0,0),BS(P3CFG0,1))							//设置P30为开漏输出IO
#define		P31OM					(BS(P3CFG0,2),BS(P3CFG0,3))							//设置P31为开漏输出IO
#define		P32OM					(BS(P3CFG0,4),BS(P3CFG0,5))							//设置P32为开漏输出IO
#define		P33OM					(BS(P3CFG0,6),BS(P3CFG0,7))							//设置P33为开漏输出IO
#define		P34OM					(BS(P3CFG1,0),BS(P3CFG1,1))							//设置P34为开漏输出IO
#define		P35OM					(BS(P3CFG1,2),BS(P3CFG1,3))							//设置P35为开漏输出IO
#define		P36OM					(BS(P3CFG1,4),BS(P3CFG1,5))							//设置P36为开漏输出IO
#define		P37OM					(BS(P3CFG1,6),BS(P3CFG1,7))							//设置P37为开漏输出IO

#define		P40OM					(BS(P4CFG0,0),BS(P4CFG0,1))							//设置P40为开漏输出IO
#define		P41OM					(BS(P4CFG0,2),BS(P4CFG0,3))							//设置P41为开漏输出IO
#define		P42OM					(BS(P4CFG0,4),BS(P4CFG0,5))							//设置P42为开漏输出IO
#define		P43OM					(BS(P4CFG0,6),BS(P4CFG0,7))							//设置P43为开漏输出IO
#define		P44OM					(BS(P4CFG1,0),BS(P4CFG1,1))							//设置P44为开漏输出IO
#define		P45OM					(BS(P4CFG1,2),BS(P4CFG1,3))							//设置P45为开漏输出IO

//=========================P1、P2、P3、P4  准双向IO设置输入=========================================//
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
#define		P22MI					(BC(P2CFG0,4),BC(P2CFG0,5),SET(P22,1))			 	//设置P22为准双向IO输入
#define		P23MI					(BC(P2CFG0,6),BC(P2CFG0,7),SET(P23,1))				//设置P23为准双向IO输入
#define		P24MI					(BC(P2CFG1,0),BC(P2CFG1,1),SET(P24,1))				//设置P24为准双向IO输入
#define		P25MI					(BC(P2CFG1,2),BC(P2CFG1,3),SET(P25,1))				//设置P25为准双向IO输入
#define		P26MI					(BC(P2CFG1,4),BC(P2CFG1,5),SET(P26,1))				//设置P26为准双向IO输入
#define		P27MI					(BC(P2CFG1,6),BC(P2CFG1,7),SET(P27,1))				//设置P27为准双向IO输入

#define		P30MI					(BC(P3CFG0,0),BC(P3CFG0,1),SET(P30,1))				//设置P30为准双向IO输入
#define		P31MI					(BC(P3CFG0,2),BC(P3CFG0,3),SET(P31,1))				//设置P31为准双向IO输入
#define		P32MI					(BC(P3CFG0,4),BC(P3CFG0,5),SET(P32,1))			 	//设置P32为准双向IO输入
#define		P33MI					(BC(P3CFG0,6),BC(P3CFG0,7),SET(P33,1))				//设置P33为准双向IO输入
#define		P34MI					(BC(P3CFG1,0),BC(P3CFG1,1),SET(P34,1))				//设置P34为准双向IO输入
#define		P35MI					(BC(P3CFG1,2),BC(P3CFG1,3),SET(P35,1))				//设置P35为准双向IO输入
#define		P36MI					(BC(P3CFG1,4),BC(P3CFG1,5),SET(P36,1))				//设置P36为准双向IO输入
#define		P37MI					(BC(P3CFG1,6),BC(P3CFG1,7),SET(P37,1))				//设置P37为准双向IO输入

#define		P40MI					(BC(P4CFG0,0),BC(P4CFG0,1),SET(P40,1))				//设置P40为准双向IO输入
#define		P41MI					(BC(P4CFG0,2),BC(P4CFG0,3),SET(P41,1))				//设置P41为准双向IO输入
#define		P42MI					(BC(P4CFG0,4),BC(P4CFG0,5),SET(P32,1))			 	//设置P42为准双向IO输入
#define		P43MI					(BC(P4CFG0,6),BC(P4CFG0,7),SET(P33,1))				//设置P43为准双向IO输入
#define		P44MI					(BC(P4CFG1,0),BC(P4CFG1,1),SET(P34,1))				//设置P44为准双向IO输入
#define		P45MI					(BC(P4CFG1,2),BC(P4CFG1,3),SET(P35,1))				//设置P45为准双向IO输入

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
	RSTCFG=0X09;	  			 //切换RstPin为GPIO,lvr选择3.95V复位
	WDTCR = 0x90;				//1--1 -- 00    开WDT,WDT清0,WDT 524ms溢出;烧录时，可Code Option选择ENWDT
	P11MI;					   //按键输入
	P11PM;     				   //显示输出
	while(1)
	{
		WDTCR = 0x90;				//1--1 -- 00    开WDT,WDT清0,WDT 524ms溢出;烧录时，可Code Option选择ENWDT
	}
}