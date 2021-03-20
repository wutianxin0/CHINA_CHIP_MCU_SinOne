#include "H/Function_Init.H"

//选择三合一模式：
#define  Uart1  0
#define  TWI    1
#define  SPI    2

#define  SSI_Mode  Uart1

void Uart1_Init(uint Freq,unsigned long int baud);
void TWI_Init(void);
void SPI_Init(void);

bit Uart1SendFlag = 0;    //Uart发送中断标志位
bit Uart1ReceiveFlag = 0; //Uart接收中断标志位
bit SPIFlag = 0;         //SPI数据传输完成标志位
bit TWIFlag = 0;         //中断标志位
/*****************************************************
*函数名称：void SSI_Test(void)
*函数功能：SSI测试
*入口参数：void
*出口参数：void
*****************************************************/
void SSI_Test(void)
{
#if (SSI_Mode == Uart1)
	Uart1_Init(16,9600);
	while(1)
	{
		SSDAT = 0xAA;
		while(!Uart1SendFlag);
		Uart1SendFlag = 0;
	}
#endif
	
#if (SSI_Mode == TWI)
	TWI_Init();
	while(1)
	{
	}
#endif

#if (SSI_Mode == SPI)
	SPI_Init();
	while(1)
	{
		SSDAT = 0xAA;
		while(!SPIFlag);
		SPIFlag = 0;
	}
#endif	
}
/*****************************************************
*函数名称：void Uart1_Init(uint Freq,unsigned long int baud)
*函数功能：Uart1中断初始化
*入口参数：Freq-主频，baud-波特率
*出口参数：void
*****************************************************/
void Uart1_Init(uint Freq,unsigned long int baud)
{
	P1CON &= 0xF5;   //TX/RX设置为输入带上拉
	P1PH  |= 0x0A;
	
	OTCON |= 0xC0;    //串行接口SSI选择Uart1通信
	SSCON0 = 0x50;   //设置通信方式为模式一，允许接收
	SSCON1 = Freq*1000000/baud;   //波特率低位控制
	SSCON2 = (Freq*1000000/baud)>>8;   //波特率高位控制
	IE1 |= 0x01;      //开启SSI中断
    EA = 1;	
}

/*****************************************************
*函数名称：void TWI_Init(void)
*函数功能：TWI初始化
*入口参数：void
*出口参数：void
*****************************************************/
void TWI_Init(void)
{
	OTCON |= 0x80;  //选择TWI模式
	SSCON0 = 0x80;  // ---- x---  0为不允许接收，1为允许接收
	SSCON1 = 0x01;  //xxxx xxxy  x为地址寄存器，y为0禁止/1允许通用地址响应
	IE1 |= 0x01;
	EA = 1;
}

/*****************************************************
*函数名称：void SPI_Init(void)
*函数功能：SPI初始化
*入口参数：void
*出口参数：void
*****************************************************/
void SPI_Init(void)
{
	OTCON |= 0X40;  //选择SPI模式
	SSCON0 = 0x2F; //设置SPI为主设备，SCK空闲时间为低电平，SCK周期第二沿采集数据，时钟速率为Fsys/512
	SSCON1 = 0x01;   //允许发送中断
	SSCON0 |= 0x80; //开启SPI
	IE1 |= 0x01;
	EA = 1;
}


/*****************************************************
*函数名称：void TWI/SPI/UART1_Int() interrupt 7
*函数功能：SSI中断函数
*入口参数：void
*出口参数：void
*****************************************************/
#if (SSI_Mode == Uart1)
void Uart1_Int() interrupt 7   //Uart1中断函数
{
	if(SSCON0&0x02)    //发送标志位判断
	{
		SSCON0 &= 0xFD;
		Uart1SendFlag = 1;
	}
	if((SSCON0&0x01))  //接收标志位判断
	{
		SSCON0 &= 0xFE;
		Uart1ReceiveFlag = 1;
	}	
}
#endif

#if (SSI_Mode == TWI)
void TWI_Int() interrupt 7     //TWI中断函数
{
	if(SSCON0&0x40)
	{
		SSCON0 &= 0xbf;  //中断清零
		TWIFlag = 1;
	}	
}
#endif 

#if (SSI_Mode == SPI)
void SpiInt(void) interrupt 7    //SPI中断函数
{	  
	if(SSCON1&0X08)    //发送缓存器空标志判断
	{
		SSCON1 &= ~0X08;
	}
	if(SSCON1&0X80)    //数据传输标志位判断
	{
		SSCON1 &= ~0X80;
		SPIFlag = 1;
	}
}
#endif 