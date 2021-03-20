#include "H/Function_Init.H"

void Uart0_Init(void);
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
    Uart0_Init();
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
*入口参数：void
*出口参数：void
*****************************************************/
void Uart0_Init(void)     //选择Timer1作为波特率发生器
{
    P1CON &= 0x9F;
	P1PH |= 0X60;	 //TX/RX为带上拉输入；

    PCON |= 0x80;    //SMOD = 1；
	SCON = 0X50;     //设置通信方式为模式一，允许接收
	T2CON = 0x00;    //使用定时器1作UART时钟
	TMCON = 0X03;    //定时器时钟为Fsys
	TMOD = 0X20;     //8位重载
	TH1 = 0xf6;      //19200波特率，TH1=256 - (Freq*250000/BaudRate/16);
	TR1 = 1;
	EUART = 1;       //开启Uart0中断
	EA = 1;
}
/*
void Uart0_Init(void)       //选择Timer2作为波特率发生器
{
    P1CON &= 0x9F;
	P1PH = 0X60;	 //TX为强推输出，RX为带上拉输入；

    PCON |= 0x80;    //SMOD = 1；
	SCON = 0X50;     //设置通信方式为模式一，允许接收
	TMCON |= 0X04;
	T2MOD = 0X00;
	T2CON = 0X30;
	RCAP2H = 0xFF;   //波特率19200，高位存放RCAP2H = (65536-Freq*1000000/BaudRate/128)/256;
	RCAP2L = 0xFB;   //波特率19200，低位存放RCAP2L = (65536-Freq*1000000/BaudRate/128)%256;
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
