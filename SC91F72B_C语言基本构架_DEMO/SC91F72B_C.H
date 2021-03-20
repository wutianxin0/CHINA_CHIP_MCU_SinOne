/*--------------------------------------------------------------------------
SC91F72B_C.H

C Header file for SC91F72B microcontroller.
Copyright (c) 2011 Shenzhen SinOne Chip Electronic CO., Ltd.
All rights reserved.
深圳市赛元微电子有限公司
版本号:  V1.0    
日期:  2011.6.21
--------------------------------------------------------------------------*/
#ifndef _SC91F72B_H_
#define _SC91F72B_H_

/* ------------------- 字节寄存器-------------------- */
/*CPU*/
sfr 	ACC	= 0xE0;		//累加器Ａ
sfr 	B	= 0xF0;		//通用寄存器B
sfr 	PSW	= 0xD0;		//程序状态字
sfr 	DPH	= 0x83;		//数据指针高8位
sfr 	DPL	= 0x82;		//数据指针低8位
sfr 	SP	= 0x81;		//堆栈指针

/*system*/
sfr 	PCON	= 0x87;		//电源管理控制寄存器

/*interrupt*/
sfr 	IP	= 0xB8;		//中断优先权控制寄存器
sfr 	IE	= 0xA8;		//中断控制寄存器

/*PORT*/
sfr 	P3CFG0	= 0xB2;		//P3口模式配置寄存器		00:准双向IO口	01:强制 P3x口有很强的输出高驱动能力	10:高阻仅输入模式	11:N型开漏模式
sfr	P3CFG1	= 0xB1;		//P3口模式配置寄存器		00:准双向IO口	01:强制 P3x口有很强的输出高驱动能力	10:高阻仅输入模式	11:N型开漏模式
sfr 	P3	= 0xB0;		//P3口数据寄存器
sfr 	P2CFG0	= 0xA2;		//P2口模式配置寄存器		00:准双向IO口	01:强制 P2x口有很强的输出高驱动能力	10:高阻仅输入模式	11:N型开漏模式
sfr 	P2	= 0xA0;		//P2口数据寄存器
sfr 	P1CFG0	= 0x92;		//P1口模式配置寄存器		00:准双向IO口	01:强制 P1x口有很强的输出高驱动能力	10:高阻仅输入模式	11:N型开漏模式
sfr	P1CFG1	= 0x91;		//P1口模式配置寄存器		00:准双向IO口	01:强制 P1x口有很强的输出高驱动能力	10:高阻仅输入模式	11:N型开漏模式
sfr 	P1	= 0x90;		//P1口数据寄存器

/*TIMER*/
sfr 	TMCON	= 0x8E;		//定时器频率控制寄存器
sfr 	TH1	= 0x8D;		//定时器1高8位
sfr 	TH0	= 0x8C;		//定时器0高8位
sfr 	TL1	= 0x8B;		//定时器1低8位
sfr 	TL0	= 0x8A;		//定时器0低8位
sfr 	TMOD	= 0x89;		//定时器工作模式寄存器
sfr 	TCON	= 0x88;		//定时器控制寄存器

/*ADC*/
sfr 	ADCVL	= 0xC7;		//ADC 结果寄存器， 储存转化后的结果 ADCV[1:0]
sfr 	ADCVH	= 0xC6;		//ADC 结果寄存器， 储存转化后的结果 ADCV[9:2]
sfr 	ADCCR	= 0xC5;		//ADC控制寄存器
sfr 	ADCCFG	= 0xC4;		//ADC参考电压选择寄存器		00:设定VREF 为 VDD	01:设定VREF 为 内部准确的2.4V		10:设定VREF 为 Vref pin，并自动把 P1.6内部的上拉电阻去掉
sfr 	P3ADC	= 0xB6;		//P3/ADC切换控制寄存器		0:PORT3.x口为GPIO	1:PORT3.x口为ADC输入口

/*PWM*/
sfr 	PWMCFG	= 0xFC;		//PWM设置寄存器
sfr 	PWMDTY0	= 0xFB;		//PWM0高电平设置寄存器
sfr 	PWMDTY1	= 0xFA;		//PWM1高电平设置寄存器
sfr 	PWMPRD	= 0xF9;		//PWM周期设置寄存器
sfr 	PWMCR	= 0xF8;		//PWM控制寄存器

/*WatchDog*/
sfr 	WDTCR	= 0xC1;		//WDT控制寄存器

/*RST*/
sfr 	RSTCFG	= 0xF6;		//复位设置寄存器

/*EX */
sfr 	EXIP	= 0xB5;		//外部中断优先权设定寄存器	0:外部中断INTn(n=0~7) 的中断优先级是 “低”		1:外部中断INTn(n=0~7) 的中断优先级是 “高”
sfr 	EXIE	= 0xB4;		//外部中断使能控制寄存器	0:关闭外部中断 INTx(x=0~7) 的中断			1:允许外部中断INTx(x=0~7) 发生中断
sfr	INT4IT	= 0x93;		//INT4中断类型寄存器		00：下降沿中断  01：无中断  10：双沿中断  11：上升沿中断

/*IAP */
sfr	IAPCTL	= 0xEE;		//IAP控制寄存器
sfr	IAPDAT	= 0xED;		//IAP数据寄存器
sfr	IAPADR	= 0xEC;		//IAP写入地址低8位寄存器
sfr	IAPKEY	= 0xEA;		//IAP保护寄存器

/* ------------------- 位寄存器-------------------- */

/*PWMCR*/
sbit 	ENPWM	= PWMCR^7;	//PWM模块开关控制	0:关闭 PWM 单元的工作		1:允许Clock进到 PWM 单元， 开始PWM的工作
sbit 	PWMIF	= PWMCR^6;	//PWM中断请求标志位	当PWM 计数器溢出时， 此位会被硬件自动设定成 1,若使能中断，产生中断后，用户需软清0
sbit 	DTY18	= PWMCR^3;	//强制PWM1固定输出高	0:PWM1 的输出由 PWM计数器以及 PWMDTY1 来决定		1:强制把 PWM1 的输出固定为 1
sbit 	ENPWM1O	= PWMCR^2;	//PWM1和P1.1口的切换	0:P1.1维持 GPIO 的功能		1:P1.1作为PWM1 的输出
sbit 	DTY08	= PWMCR^1;	//强制PWM0固定输出高	0:PWM0 的输出由 PWM计数器以及 PWMDTY0 来决定		1:强制把 PWM0的输出固定为 1
sbit 	ENPWM0O	= PWMCR^0;	//PWM0和P1.2口的切换	0:P1.2维持 GPIO 的功能		1:P1.2作为PWM0的输出

/*PSW*/
sbit 	CY	= PSW^7;	//标志位		0:加法运算最高位无进位，或者减法运算最高位无借位时		1:加法运算最高位有进位，或者减法运算最高位有借位时
sbit 	AC	= PSW^6;	//进位辅助标志位	0:无借位、进位		1:加法运算时在bit3位有进位，或减法运算在bit3位有借位时
sbit 	F0	= PSW^5;	//用户标志位
sbit 	RS1	= PSW^4;	//工作寄存器组选择位
sbit 	RS0	= PSW^3;	//工作寄存器组选择位
sbit 	OV	= PSW^2;	//溢出标志位
sbit 	P	= PSW^0;	//奇偶标志位		0:ACC中1的个数为偶数（包括0个）		1:ACC中1的个数为奇数

/*IP*/
sbit 	IPADC	= IP^6;		//ADC中断优先控制位	0:设定 ADC的中断优先权是 “低”		1:设定 ADC的中断优先权是 “高”
sbit 	IPPWM	= IP^5;		//PWM中断优先控制位	0:设定 PWM的中断优先权是 “低”		1:设定 PWM 的中断优先权是 “高”
sbit 	IPT1	= IP^3;		//Timer1中断优先控制位	0:设定 Timer 1的中断优先权是 “低”	1:设定 Timer 1的中断优先权是 “高”
sbit 	IPT0	= IP^1;		//Timer0中断优先控制位	0:设定 Timer 0的中断优先权是 “低”	1:设定 Timer 0的中断优先权是 “高”

/*IE*/
sbit 	EA	= IE^7;		//中断使能的总控制	0:关闭所有的中断	1:打开所有的中断
sbit 	EADC	= IE^6;		//ADC中断使能控制	0:关闭ADC中断		1:打开ADC中断
sbit 	EPWM	= IE^5;		//PWM中断使能控制	0:关闭PWM中断		1:打开PWM中断
sbit 	ET1	= IE^3;		//Timer1中断使能控制	0:关闭TIMER1中断	1:打开TIMER1中断
sbit 	ET0	= IE^1;		//Timer0中断使能控制	0:关闭TIMER0中断	1:打开TIMER0中断

/*TCON*/
sbit 	TF1	= TCON^7;	//T1溢出中断请求标志位	T1产生溢出，发生中断时，硬件将TF1置为“1”，申请中断，CPU响应时，硬件清“0”。
sbit 	TR1	= TCON^6;	//定时器T1的运行控制位	0:Timer1禁止计数		1:Timer1开始计数
sbit 	TF0	= TCON^5;	//T0溢出中断请求标志位	T0产生溢出，发生中断时，硬件将TF0置为“1”，申请中断，CPU响应时，硬件清“0”。
sbit 	TR0	= TCON^4;	//定时器T0的运行控制位	0:Timer0禁止计数		1:Timer0开始计数

/* P1 */
sbit 	P17	= P1^7;
sbit 	P16	= P1^6;
sbit 	P15	= P1^5;
sbit 	P14	= P1^4;
sbit 	P13	= P1^3;
sbit 	P12	= P1^2;
sbit 	P11	= P1^1;
sbit 	P10	= P1^0;

/* P2 */
sbit 	P21	= P2^1;
sbit 	P20	= P2^0;

/* P3 */
sbit 	P37	= P3^7;
sbit 	P36	= P3^6;
sbit 	P35	= P3^5;
sbit 	P34	= P3^4;
sbit 	P33	= P3^3;
sbit 	P32	= P3^2;
sbit 	P31	= P3^1;
sbit 	P30	= P3^0;

#endif