/*--------------------------------------------------------------------------
SC91F7312_ASM.H

ASM Header file for SC91F7312 microcontroller.
Copyright (c) 2015 Shenzhen SinOne Chip Electronic CO., Ltd.
All rights reserved.
深圳市赛元微电子有限公司
版本号：V1.0    
日期：2015.7.16
--------------------------------------------------------------------------*/
#ifndef _SC91F7312_H_
#define _SC91F7312_H_

/* ------------------- 字节寄存器-------------------- */
/*CPU*/
ACC	EQU  	0xE0	//累加器Ａ	
B	EQU  	0xF0	//通用寄存器B 
PSW	EQU  	0xD0	//程序状态字
DPH	EQU  	0x83	//数据指针高8位
DPL	EQU  	0x82	//数据指针低8位
SP	EQU  	0x81	//堆栈指针

/*system*/
PCON	EQU	0x87	//电源管理控制寄存器

/*interrupt*/
IP	EQU  	0xB8	//中断优先权控制寄存器
IE	EQU  	0xA8	//中断控制寄存器
	
/*PORT*/
P4CFG0	EQU	0xC2	//P4口模式控制寄存器0		00:准双向IO口	01:强制 P4x口有很强的输出高驱动能力	10:高阻仅输入模式	11:开漏输出模式
P4	EQU	0xC0	//P4口数据寄存器
P3CFG0	EQU	0xB2	//P3口模式控制寄存器0		00:准双向IO口	01:强制 P3x口有很强的输出高驱动能力	10:高阻仅输入模式	11:N型开漏模式
P3CFG1	EQU	0xB1	//P3口模式控制寄存器1		00:准双向IO口	01:强制 P3x口有很强的输出高驱动能力	10:高阻仅输入模式	11:N型开漏模式
P3	EQU	0xB0	//P3口数据寄存器
P2CFG0	EQU	0xA2	//P2口模式控制寄存器0		00:准双向IO口	01:强制 P2x口有很强的输出高驱动能力	10:高阻仅输入模式	11:N型开漏模式
P2CFG1	EQU	0xA1	//P2口模式控制寄存器1		00:准双向IO口	01:强制 P2x口有很强的输出高驱动能力	10:高阻仅输入模式	11:开漏输出模式
P2	EQU	0xA0	//P2口数据寄存器
P1CFG0	EQU	0x92	//P1口模式控制寄存器0		00:准双向IO口	01:强制 P1x口有很强的输出高驱动能力	10:高阻仅输入模式	11:N型开漏模式
P1CFG1	EQU	0x91	//P1口模式控制寄存器1		00:准双向IO口	01:强制 P1x口有很强的输出高驱动能力	10:高阻仅输入模式	11:N型开漏模式
P1	EQU	0x90	//P1口数据寄存器	

/*TIMER*/
TMCON	EQU  	0x8E	//定时器频率控制寄存器
TH1	EQU  	0x8D	//定时器1高8位
TH0	EQU  	0x8C	//定时器0高8位
TL1	EQU  	0x8B	//定时器1低8位
TL0	EQU  	0x8A	//定时器0低8位
TMOD	EQU  	0x89	//定时器工作模式寄存器
TCON	EQU  	0x88	//定时器控制寄存器
	
/*ADC*/
ADCVL	EQU  	0xC7	//ADC 结果寄存器， 储存转化后的结果 ADCV[1:0]
ADCVH	EQU  	0xC6	//ADC 结果寄存器， 储存转化后的结果 ADCV[9:2]
ADCCR	EQU  	0xC5	//ADC控制寄存器
ADCCFG1	EQU	0xBE	//P3口ADC功能配置寄存器
ADCCFG0	EQU	0xBD	//P2口ADC功能配置寄存器
	
/*PWM*/

PWMCFG	EQU     0xFC;		//PWM设置寄存器
PWMDTY0	EQU     0xFB;		//PWM高电平设置寄存器
PWMDTY1	EQU     0xFA;		//PWM高电平设置寄存器
PWMDTY2	EQU     0xFD;		//PWM高电平设置寄存器
PWMPRD	EQU     0xF9;		//PWM周期设置寄存器
PWMCR	EQU     0xF8;		//PWM控制寄存器

/*WatchDog*/
WDTCR	EQU  	0xC9	//WDT控制寄存器
	
/*RST*/
RSTCFG	EQU  	0xF6	//复位设置寄存器

/*EX */
EXIE	EQU	0xB5	//外部中断使能控制寄存器	0:关闭外部中断 INTx(x=0~7) 的中断			1:允许外部中断INTx(x=0~7) 发生中断
EXIP	EQU	0xB4	//外部中断优先权设定寄存器	0:外部中断INTn(n=0~7) 的中断优先级是 “低”		1:外部中断INTn(n=0~7) 的中断优先级是 “高”
INT1IT	EQU	0x93	//INT1中断类型寄存器		00：下降沿中断  01：无中断  10：双沿中断  11：上升沿中断

/*BUZZER*/
BUZTGPL	EQU	0xC4	//蜂鸣器反转输出计数器低位
BUZTGPH	EQU	0xC3	//蜂鸣器反转输出计数器高位

/*32K OSC*/
X32CTL	EQU	0xCA	//32K BaseTimer控制寄存器

/*SIF*/
SIFSTA	EQU	0xD8	//SIF状态寄存器
SIFRXD	EQU	0xD7	//SIF数据接收状态寄存器		
SIFTXD	EQU	0xD6	//SIF数据发送状态寄存器
SIFCTL	EQU	0xD5	//SIF控制寄存器
SIFCFG	EQU	0xD4	//SIF配置寄存器

/*IAP */
IAPCTL	EQU	0xEE	//IAP控制寄存器
IAPDAT	EQU	0xED	//IAP数据寄存器
IAPADL	EQU	0xEC	//IAP写入地址低8位寄存器
IAPKEY	EQU	0xEA	//IAP保护寄存器


/*LCD*/
P1LCDVO EQU	 0x96   //P1口LCD电压输出寄存器
P2LCDVO EQU	 0xA6   //P2口LCD电压输出寄存器
P3LCDVO EQU	 0xB6   //P3口LCD电压输出寄存器
P4LCDVO EQU	 0xA5   //P4口LCD电压输出寄存器
LCDVOS  EQU	 0xA7   //LCD配置寄存器

/*USERCODE*/
USERCODE  EQU	 0xF4; //用户CODE寄存器

/* ------------------- 位寄存器-------------------- */

/*SIFSTA*/
RTNACK	EQU	SIFSTA.7 //ACK返回信号位RTNACK
STPIF	EQU	SIFSTA.3 //SIF STOP信号中断请求标志STPIF
TXIF	EQU	SIFSTA.2 //SIF发送完成中断标志TXIF
RXIF	EQU	SIFSTA.1 //SIF接收完成中断标志RXIF
STRIF	EQU	SIFSTA.0 //SIF START信号中断标志 STRIF 

/*PWMCR*/
ENPWM	EQU  	PWMCR.7 //PWM模块开关控制	0:关闭 PWM 单元的工作		1:允许Clock进到 PWM 单元， 开始PWM的工作
PWMIF	EQU  	PWMCR.6 //PWM中断请求标志位	当PWM 计数器溢出时， 此位会被硬件自动设定成 1,若使能中断，产生中断后，用户需软清0
EN2O    EQU  	PWMCR.5 //PWM2使能输出
DTY28   EQU  	PWMCR.4 //强制PWM2固定输出高
EN1O    EQU  	PWMCR.3 //PWM1使能输出
DTY18	EQU  	PWMCR.2 //强制PWM1固定输出高
EN0O	EQU  	PWMCR.1 //PWM0使能输出	
DTY08	EQU  	PWMCR.0 //强制PWM0固定输出高


/*PSW*/
CY	EQU  	PSW.7	//标志位		0:加法运算最高位无进位，或者减法运算最高位无借位时	1:加法运算最高位有进位，或者减法运算最高位有借位时
AC	EQU  	PSW.6	//进位辅助标志位	0:无借位、进位		1:加法运算时在bit3位有进位，或减法运算在bit3位有借位时		
F0	EQU  	PSW.5	//用户标志位
RS1	EQU  	PSW.4	//工作寄存器组选择位
RS0	EQU  	PSW.3	//工作寄存器组选择位
OV	EQU  	PSW.2	//溢出标志位
P	EQU  	PSW.0	//奇偶标志位		0:ACC中1的个数为偶数（包括0个）			1:ACC中1的个数为奇数

/*IP*/
IPADC	EQU	IP.6	//ADC中断优先控制位	0:设定 ADC的中断优先权是 “低”		1:设定 ADC的中断优先权是 “高”
IPSIF	EQU	IP.5	//SIF中断优先控制位	0:设定 SIF的中断优先权是 “低”		1:设定 SIF的中断优先权是 “高”
IPPWM	EQU	IP.4	//PWM中断优先控制位	0:设定 PWM的中断优先权是 “低”		1:设定 PWM 的中断优先权是 “高”
IPT1	EQU	IP.3	//Timer1中断优先控制位	0:设定 Timer 1的中断优先权是 “低”	1:设定 Timer 1的中断优先权是 “高”
IPX32K	EQU	IP.2	//32K Base Timer中断优先控制位		0:设定 32K的中断优先权是 “低”		1:设定 32K的中断优先权是 “高”
IPT0	EQU	IP.1	//Timer0中断优先控制位	0:设定 Timer 0的中断优先权是 “低”	1:设定 Timer 0的中断优先权是 “高”

/*IE*/
EA	EQU	IE.7	//中断使能的总控制	0:关闭所有的中断	1:打开所有的中断
EADC	EQU	IE.6	//ADC中断使能控制	0:关闭ADC中断		1:打开ADC中断
ESIF	EQU	IE.5	//SIF中断使能控制	0:关闭SIF中断		1:打开SIF中断
EPWM	EQU	IE.4	//PWM中断使能控制	0:关闭PWM中断		1:打开PWM中断
ET1	EQU	IE.3	//Timer1中断使能控制	0:关闭TIMER1中断	1:打开TIMER1中断
EX32K	EQU	IE.2	//32K Base Timer中断使能控制	0:关闭32K中断		1:打开32K中断	
ET0	EQU	IE.1	//Timer0中断使能控制	0:关闭TIMER0中断	1:打开TIMER0中断

	
/*TCON*/
TF1	EQU  	TCON.7	//T1溢出中断请求标志位	T1产生溢出，发生中断时，硬件将TF1置为“1”，申请中断，CPU响应时，硬件清“0”。
TR1	EQU  	TCON.6	//定时器T1的运行控制位	0:Timer1禁止计数				1:Timer1开始计数
TF0	EQU  	TCON.5	//T0溢出中断请求标志位	T0产生溢出，发生中断时，硬件将TF0置为“1”，申请中断，CPU响应时，硬件清“0”。
TR0	EQU  	TCON.4	//定时器T0的运行控制位	0:Timer0禁止计数				1:Timer0开始计数

/* P1 */
P17	EQU  	P1.7
P16	EQU  	P1.6
P15	EQU  	P1.5
P14	EQU  	P1.4
P13	EQU  	P1.3
P12	EQU  	P1.2
P11	EQU  	P1.1
P10	EQU  	P1.0  
	
/* P2 */  
P27	EQU  	P2.7  
P26	EQU  	P2.6
P25	EQU  	P2.5  
P24	EQU  	P2.4
P23	EQU  	P2.3  
P22	EQU  	P2.2
P21	EQU  	P2.1  
P20	EQU  	P2.0
	
/* P3 */
P37	EQU  	P3.7
P36	EQU  	P3.6
P35	EQU  	P3.5
P34	EQU  	P3.4
P33	EQU  	P3.3
P32	EQU  	P3.2
P31	EQU  	P3.1  
P30	EQU  	P3.0  

/* P4 */
P41	EQU  	P4.1
P40	EQU  	P4.0	  	  
#endif