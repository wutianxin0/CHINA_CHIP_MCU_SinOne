#include "H/Function_Init.H"

//选择三合一模式：
#define  Uart0   0
#define  TWI0    1
#define  SPI0    2

#define  SSI0_Mode  SPI0

void Uart0_Init(uint Freq,unsigned long int baud);
void TWI0_Init(void);
void SPI0_Init(void);

bit Uart0SendFlag = 0;    //Uart0发送中断标志位
bit Uart0ReceiveFlag = 0; //Uart0接收中断标志位
bit SPI0Flag = 0;          //SPI0数据传输完成标志位
bit TWI0Flag = 0;          //TWI0中断标志位

/*****************************************************
*函数名称：void SSI0_Test(void)
*函数功能：SSI0测试
*入口参数：void
*出口参数：void
*****************************************************/
void SSI0_Test(void)
{
#if (SSI0_Mode == Uart0)
	Uart0_Init(16,9600);
	while(1)
	{
		SS0DAT = 0xAA;
		while(!Uart0SendFlag);
		Uart0SendFlag = 0;
	}
#endif
	
#if (SSI0_Mode == TWI0)
	TWI0_Init();
	while(1)
	{
	}
#endif

#if (SSI0_Mode == SPI0)
	SPI0_Init();
	while(1)
	{
		SS0DAT = 0xAA;
		while(!SPI0Flag);
		SPI0Flag = 0;
	}
#endif	
}

/*****************************************************
*函数名称：void Uart0_Init(uint Freq,unsigned long int baud)
*函数功能：Uart0中断初始化
*入口参数：Freq-主频，baud-波特率
*出口参数：void
*****************************************************/
void Uart0_Init(uint Freq,unsigned long int baud)
{
	P1CON &= 0xF3;   //TX/RX设置为输入带上拉
	P1PH  |= 0x0C;
	
	OTCON |= 0x30;    //串行接口SSI选择Uart0通信
	SS0CON0 = 0x50;   //设置通信方式为模式一，允许接收
	SS0CON1 = Freq*1000000/baud;   //波特率低位控制
	SS0CON2 = (Freq*1000000/baud)>>8;   //波特率高位控制
	IE |= 0x10;       //开启SSI中断
    EA = 1;	
}

/*****************************************************
*函数名称：void TWI0_Init(void)
*函数功能：TWI0初始化
*入口参数：void
*出口参数：void
*****************************************************/
void TWI0_Init(void)
{
	OTCON |= 0x20;  //选择TWI0模式
	SS0CON0 = 0x80;  // ---- x---  0为不允许接收，1为允许接收
	SS0CON1 = 0x01;  //xxxx xxxy  x为地址寄存器，y为0禁止/1允许通用地址响应
	IE |= 0x10;
	EA = 1;
}

/*****************************************************
*函数名称：void SPI0_Init(void)
*函数功能：SPI0初始化
*入口参数：void
*出口参数：void
*****************************************************/
void SPI0_Init(void)
{
	OTCON |= 0X10;  //选择SPI0模式
	SS0CON0 = 0x2f; //设置SPI0为主设备，SCK空闲时间为低电平，SCK周期第二沿采集数据，时钟速率为Fsys/128
	SS0CON1 = 0x01;   //允许发送中断
	SS0CON0 |= 0x80; //开启SPI
	IE |= 0x10;
	EA = 1;
}


/*****************************************************
*函数名称：void TWI0/SPI0/UART0_Int() interrupt 7
*函数功能：SSI0中断函数
*入口参数：void
*出口参数：void
*****************************************************/
#if (SSI0_Mode == Uart0)
void Uart0_INT() interrupt 4   //Uart1中断函数
{
	if(SS0CON0&0x02)    //发送标志位判断
	{
		SS0CON0 &= 0xFD;
		Uart0SendFlag = 1;
	}
	if((SS0CON0&0x01))  //接收标志位判断
	{
		SS0CON0 &= 0xFE;
		Uart0ReceiveFlag = 1;
	}	
}
#endif

#if (SSI0_Mode == TWI0)
void TWI0_INT() interrupt 4     //TWI中断函数
{
	if(SS0CON0&0x40)
	{
		SS0CON0 &= 0xbf;  //中断清零
		TWI0Flag = 1;
	}	
}
#endif 

#if (SSI0_Mode == SPI0)
void SPI0INT(void) interrupt 4    //SPI中断函数
{	  
	if(SS0CON1&0X08)    //发送缓存器空标志判断
	{
		SS0CON1 &= ~0X08;
	}
	if(SS0CON1&0X80)    //数据传输标志位判断
	{
		SS0CON1 &= ~0X80;
		SPI0Flag = 1;
	}
}
#endif 