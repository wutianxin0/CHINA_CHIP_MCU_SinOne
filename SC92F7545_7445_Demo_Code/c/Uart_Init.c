#include "H/Function_Init.H" 

void Uart0_Init(uint Freq,unsigned long int baud);
bit UartSendFlag = 0; //发送中断标志位
bit UartReceiveFlag = 0; //接收中断标志位
/*****************************************************
*函数名称：void Uart0_Test(void)
*函数功能：Uart0测试
*入口参数：void
*出口参数：void
*****************************************************/
void Uart0_Test(void)
{
	Uart0_Init(16,9600);
	while(1)
	{
		SBUF = 0x55;
		while(!UartSendFlag);
		UartSendFlag = 0;
	}
}
/*****************************************************
*函数名称：void Uart0_Init(uint Freq,unsigned long int baud)
*函数功能：Uart0中断初始化
*入口参数：Freq-主频，baud-波特率
*出口参数：void
*****************************************************/
void Uart0_Init(uint Freq,unsigned long int baud)    //选择Timer1作为波特率信号发生器
{
	P0CON &= 0xF3;   //TX/RX设置为输入带上拉
	P0PH  |= 0x0C;
    
	SCON  |= 0X50;   //设置通信方式为模式一，允许接收
	TMCON |= 0X02;
	TH1 = (Freq*1000000/baud)>>8;	  //波特率为T1的溢出时间；
	TL1 = Freq*1000000/baud;
	TR1 = 0;
	ET1 = 0;
	EUART = 1;     //开启Uart0中断
	EA = 1;
}
/*
void Uart0_Init(uint Freq,unsigned long int baud)    //选择Timer2作为波特率信号发生器
{
    P0CON &= 0xF3;   //TX/RX设置为输入带上拉
	P0PH  |= 0x0C;

	SCON  |= 0X50;   //设置通信方式为模式一，允许接收
	TMCON |= 0X04;
	T2MOD = 0X00;
	T2CON = 0X30;
	RCAP2H = Freq*1000000/baud/256;
	RCAP2L = Freq*1000000/baud%256;
	TR2 = 0;
	ET2 = 0;
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
		TI = 0;	
		UartSendFlag = 1;		
	}
	if(RI)
	{
		RI = 0;	
		UartReceiveFlag = 1;
	}	
}
