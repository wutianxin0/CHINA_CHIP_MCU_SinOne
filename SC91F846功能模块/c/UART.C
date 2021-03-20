//************************************************************
//  Copyright (c) 深圳市赛元微电子有限公司
//	文件名称	:
//	作者		: 
//	模块功能	: 
//	局部函数列表:
//  最后更正日期:
// 	版本		:
// 	更改记录	:rom前256byte禁止查表,因此在编译的时候，设置keil->option for Target->BL51 Locate->Code Range:0x100
//*************************************************************
/****************************************************************/
//SM0=0  工作模式1  1起始位 8数据位 1停止位  波特率可变
//SM0=1  工作模式3  1起始位 8数据位 1个可编程的第9位1停止位  波特率可变
//SM2 	只对工作模式3有效，
//TI：发送中断位  TI=1 发送完成，软件置0
//RI：接收中断位  RI=1 接收完成，软件置0
//REN：接收使能	  0:不允许接收数据 1:允许接收数据
//SBUF：数据缓冲区	 一个发送移位寄存器和一个接收锁存器
//BAUDGL/BAUDGH 共14位 总大小16384 
//BAUDGH=x/256;		//16M 9600波特率 则BAUDG=417;
//BAUDGL=x%256;			  4800波特率 则BAUDG=844;
//						 19200波特率 则BAUDG=209;
//RXD P12
//TXD P13
/****************************************************************/

#include "h\sc91f846_C.h"
#define uchar unsigned char 
#define LED0 P02
#define LED1 P03
#define LED2 P04
#define LED3 P05
bit flag;			
bit RI_FLAG=0; 
unsigned char i; 

void IOinit(void )
{	
	P0CFG0=0x55;	  //P02,P03强推挽输出
	P0CFG1=0x05;	  //P04,P05强推挽输出
	P1CFG0=0X40;	  //RXD准双向输出高  TXD强推挽
	P12=1;
}

void init_uart_mode1(void)
{
	SM0=0;						//模式1
	REN=1;						//允许接收
	EA=1; 						//打开总中断
	EUART=1;  					//开启串口中断
	BAUDGH=417/256;				//16M 9600波特率 则BAUDG=417（392~443）;
	BAUDGL=417%256;				//设置波特率的值
	BAUDGH=BAUDGH|0x80;			//开启波特率
}
void uart()interrupt 4
{	
	if(TI)
	{
		TI=0;		//中断进来要把TI清0
	}
	if(RI)			//接收中断
	{
		RI=0;		//中断进来要把RI清0	
		RI_FLAG=1;
	}
}
void main()
{
	RSTCFG=0X2A;	  			 //切换RstPin为GPIO,lvr选择3.5V复位
	WDTCR = 0x90;				//1--1 -- 00    开WDT,WDT清0,WDT 262ms溢出;烧录时，可Code Option选择ENWDT
	IOinit();
	init_uart_mode1();
	while(1)
	{
		WDTCR = 0x90;				//1--1 -- 00    开WDT,WDT清0,WDT 262ms溢出;烧录时，可Code Option选择ENWDT		
		if(RI_FLAG)			//接收中断
		{
			RI_FLAG=0;
			i=SBUF;		//把SBUF 数据赋值给i		
			switch(i)	//判断接收的值是否正确
			{
				case 0x01: LED0=~LED0;break;
				case 0x02: LED1=~LED1;break;
				case 0x03: LED2=~LED2;break;
				case 0x04: LED3=~LED3;break;
				default: break; 
			} 
			flag=1;		//收完一帧数据时则进行发送
		}	

		if(flag==1)
		{
			EUART=0; 		//发送数据之前要把串口中断关掉
			flag=0;	 		//让接收下一数据时置1
			SBUF=i;  		//把i数据发送到SBUF中
			while(!TI);		//等待发送完成
			EUART=1; 		//打开中断进行下一个数据的接收
		}

	}
}