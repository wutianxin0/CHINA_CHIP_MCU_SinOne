#include "H/Function_Init.H"

//选择三合一模式：
#define  Uart2   0
#define  TWI2    1
#define  SPI2    2

#define  SSI2_Mode  TWI2

void Uart2_Init(uint Freq,unsigned long int baud);
void TWI2_Init(void);
void SPI2_Init(void);

bit Uart2SendFlag = 0;    //Uart2发送中断标志位
bit Uart2ReceiveFlag = 0; //Uart2接收中断标志位
bit SPI2Flag = 0;         //SPI2数据传输完成标志位
bit TWI2Flag = 0;         //TWI2中断标志位

/*****************************************************
*函数名称：void SSI2_Test(void)
*函数功能：SSI2测试
*入口参数：void
*出口参数：void
*****************************************************/
void SSI2_Test(void)
{
#if (SSI2_Mode == Uart2)
	Uart2_Init(32,9600);
	while(1)
	{
		US2CON3 = 0xAA;
		while(!Uart2SendFlag);
		Uart2SendFlag = 0;
	}
#endif
	
#if (SSI2_Mode == TWI2)
	TWI2_Init();
	while(1)
	{
		US2CON1 |= 0x20;    //产生起始条件
		while(!TWI2Flag);
        TWI2Flag = 0;		
		US2CON3 = 0x10;	    //发送地址及读命令
        while(!TWI2Flag);
        TWI2Flag = 0;
        US2CON3 = 0x55;	    //发送地址及读命令
        while(!TWI2Flag);
        TWI2Flag = 0;
		Delay(100);
		US2CON1 |= 0x10;
		Delay(100);
	}
#endif

#if (SSI2_Mode == SPI2)
	SPI2_Init();
	while(1)
	{
		US2CON2 = 0xAA;
		while(!SPI2Flag);
		SPI2Flag = 0;
        Delay(1000);
	}
#endif	
}
/*****************************************************
*函数名称：void Uart2_Init(uint Freq,unsigned long int baud)
*函数功能：Uart2中断初始化
*入口参数：Freq-主频，baud-波特率
*出口参数：void
*****************************************************/
void Uart2_Init(uint Freq,unsigned long int baud)
{
	P1CON &= 0xCF;    //TX/RX设置为输入带上拉
	P1PH  |= 0x30;
	
	TMCON |= 0xC0;    //串行接口SSI2选择Uart2通信
	US2CON0 = 0x50;   //设置通信方式为模式一，允许接收
	US2CON1 = Freq*1000000/baud;   //波特率低位控制
	US2CON2 = (Freq*1000000/baud)>>8;   //波特率高位控制
	IE2 |= 0x02;      //开启SSI2中断
    EA = 1;	
}

/*****************************************************
*函数名称：void TWI2_Init(void)
*函数功能：TWI2初始化
*入口参数：void
*出口参数：void
*****************************************************/
void TWI2_Init(void)
{
	TMCON |= 0x80;   //选择TWI2模式
	US2CON0 = 0x80;  //主模式， 使能应答标志位
	US2CON1 = 0x05;  //---- xxxx  x为时钟速率
	IE2 |= 0x02;
	EA = 1;
}

/*****************************************************
*函数名称：void SPI2_Init(void)
*函数功能：SPI2初始化
*入口参数：void
*出口参数：void
*****************************************************/
void SPI2_Init(void)
{
	TMCON |= 0X40;    //选择SPI2模式
	US2CON0 = 0x3F;   //设置SPI2为主设备，SCK空闲时间为高电平，SCK周期第二沿采集数据，时钟速率为Fsys/128
	US2CON1 = 0x01;   //MSB优先发送，8位传输，允许发送中断
	US2CON0 |= 0x80;  //开启SPI2
	IE2 |= 0x02;
	EA = 1;
}


/*****************************************************
*函数名称：void TWI2/PI/UART1_Int() interrupt 16
*函数功能：SSI2中断函数
*入口参数：void
*出口参数：void
*****************************************************/
#if (SSI2_Mode == Uart2)
void Uart2_Int() interrupt 16   //Uart2中断函数
{
	if(US2CON0&0x02)    //发送标志位判断
	{
		US2CON0 &= 0xFD;
		Uart2SendFlag = 1;
	}
	if((US2CON0&0x01))  //接收标志位判断
	{
		US2CON0 &= 0xFE;
		Uart2ReceiveFlag = 1;
	}	
}
#endif

#if (SSI2_Mode == TWI2)
void TWI2_Int() interrupt 16     //TWI2中断函数
{
	if(US2CON0&0x40)
	{
		US2CON0 &= 0xbf;  //中断清零
		TWI2Flag = 1;
	}	
}
#endif 

#if (SSI2_Mode == SPI2)
void SpiInt(void) interrupt 16    //SPI2中断函数
{	  
	if(US2CON1&0X08)    //发送缓存器空标志判断
	{
		US2CON1 &= ~0X08;
	}
	if(US2CON1&0X80)    //数据传输标志位判断
	{
		US2CON1 &= ~0X80;
		SPI2Flag = 1;
	}
}
#endif 