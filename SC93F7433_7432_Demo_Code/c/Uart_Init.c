#include "H/Function_Init.H"

void Uart0_Init(uint Freq, unsigned long int BaudRate);
bit Uart0SendFlag = 0; //发送中断标志位
bit Uart0ReceiveFlag = 0; //接收中断标志位

/****************************************************
*函数名称：void Uart0_Test(void)
*函数工能：Uart0测试
*入口参数：void
*出口参数：void
*****************************************************/
void Uart0_Test(void)
{
    Uart0_Init(12,19200);
    while(1)
    {
        SBUF = 0x55;
        while(!(Uart0SendFlag));
        Uart0SendFlag = 0;
    }
}

/*****************************************************
*函数名称：void Uart0_Init(void)
*函数功能：Uart0中断初始化
*入口参数：Freq-主频(M)，baud-波特率
*出口参数：void
*****************************************************/
void Uart0_Init(uint Freq, unsigned long int BaudRate)     //选择Timer1作为波特率发生器
{
    P1CON &= 0xF3;
	P1PH |= 0X0C;	 //TX/RX为带上拉输入；

    PCON |= 0x80;    //SMOD = 1；
	SCON = 0X50;     //设置通信方式为模式一，允许接收
	T2CON = 0x00;    //使用定时器1作UART时钟
	TMCON = 0X03;    //定时器时钟为Fsys
	TMOD = 0X20;     //8位重载
	TH1 = 256 - (Freq*1000000/BaudRate/16);	     //在24M时，波特率为9600；
	TR1 = 1;
	EUART = 1;       //开启Uart0中断
	EA = 1;
}
/*
void Uart0_Init(uint Freq, unsigned long int BaudRate)       //选择Timer2作为波特率发生器
{
    P1CON &= 0xF3;
	P1PH |= 0X0C;	 //TX/RX为带上拉输入；
    PCON |= 0x80;    //SMOD = 1；
	SCON = 0X50;     //设置通信方式为模式一，允许接收
	TMCON |= 0X04;
	T2MOD = 0X00;
	T2CON = 0X30;
	RCAP2H = (65536-Freq*1000000/BaudRate/32)/256;
	RCAP2L = (65536-Freq*1000000/BaudRate/32)%256;
	TR2 = 0;
	ET2 = 1;
	TR2 = 1;
	EUART = 1;     //开启Uart0中断
	EA = 1;
}
*/

/*****************************************************
*函数名称：void UartInt(void) interrupt 4
*函数功能：Uart0中断函数
*入口参数：void
*出口参数：void
*****************************************************/
void UartInt(void) interrupt 4
{
	if(TI)
	{
		TI=0;	
	    Uart0SendFlag = 1;
	}
	if(RI)
	{
		RI=0;
        Uart0ReceiveFlag = 1;
	}
}
