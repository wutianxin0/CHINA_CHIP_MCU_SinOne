#include "H/Function_Init.H"

void Timer_Init(void);
/*****************************************************
*函数名称：void Timer_Test(void);
*函数功能：T0/T1/T2测试
*入口参数：void
*出口参数：void
*****************************************************/
void Timer_Test(void)
{
	Timer_Init();
	while(1)
	{
	}
}
/*****************************************************
*函数名称：void Timer_Init(void)
*函数功能：T0/T1/T2初始化
*入口参数：void
*出口参数：void
*****************************************************/
void Timer_Init(void)
{ 
	TMCON = 0X07;    //------111 ;Timer0、Tiemr1和Tiemr2选择时钟Fsys
	//T0设置
	TMOD = 0x11;     //0001 0001  ;Timer0和Timer1设置工作方式1
	TL0 = (65536 - 16000)%256;    //溢出时间：时钟为Fsys，则6000*（1/Fsys）=250us;
	TH0 = (65536 - 16000)/256;
	TR0 = 0;
	ET0 = 1;//定时器0允许
	TR0 = 1;//打开定时器0
	//T1设置
	TL1 = (65536 - 48000)%256;   //溢出时间：时钟为Fsys，则24000*（1/Fsys）=1ms;
	TH1 = (65536 - 48000)/256;
	TR1 = 0;
	ET1 = 1;//定时器1允许
	TR1 = 1;//打开定时器1
	//T2设置
	T2MOD=0x00;
	T2CON=0x00;	 //设置为16位重载寄存器
	RCAP2H=(65536-32000)/256;     //溢出时间：时钟为Fsys，则12000*（1/Fsys）=0.5ms;
	RCAP2L=(65536-32000)%256;
	TR2 = 0;
	ET2 = 1;//定时器2允许
	TR2 = 1;//打开定时器2	
	EA = 1;	
}

/**************************************************
*函数名称：void timer0/1() interrupt 1/3
*函数功能：定时器中断产生方波
*入口参数：void
*出口参数：void
**************************************************/
void timer0() interrupt 1
{
    TL0 = (65536 - 16000)%256;
	TH0 = (65536 - 16000)/256;
	P20 = ~P20;	
}

void timer1() interrupt 3
{
    TL1 = (65536 - 48000)%256;
	TH1 = (65536 - 48000)/256;
	P21 = ~P21;
}

void Timer2Int(void) interrupt 5
{		
	TF2 = 0;   //溢出清零
    P22=~P22;
}
