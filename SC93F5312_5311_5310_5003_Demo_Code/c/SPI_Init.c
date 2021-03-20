#include "H/Function_Init.H"

void SPI_Init(void);

bit SPIFlag = 0;         //SPI数据传输完成标志位
/*****************************************************
*函数名称：void SPI_Test(void)
*函数功能：SPI测试
*入口参数：void
*出口参数：void
*****************************************************/
void SPI_Test(void)
{
	SPI_Init();
	while(1)
	{
		SPDAT = 0xAA;
		while(!SPIFlag);
		SPIFlag = 0;
	}
}

/*****************************************************
*函数名称：void SPI_Init(void)
*函数功能：SPI初始化
*入口参数：void
*出口参数：void
*****************************************************/
void SPI_Init(void)
{
	SPCON = 0x3F; //设置SPI为主设备，SCK空闲时间为高电平，SCK周期第二沿采集数据，时钟速率为Fsys/512
	SPSTA = 0x01;   //允许发送中断
	SPCON |= 0x80; //开启SPI
	IE1 |= 0x01;
	EA = 1;
}


/*****************************************************
*函数名称：void SpiInt() interrupt 7
*函数功能：SPI中断函数
*入口参数：void
*出口参数：void
*****************************************************/
void SpiInt(void) interrupt 7    //SPI中断函数
{	  
	if(SPSTA&0X08)    //发送缓存器空标志判断
	{
		SPSTA &= ~0X08;
	}
	if(SPSTA&0X80)    //数据传输标志位判断
	{
		SPSTA &= ~0X80;
		SPIFlag = 1;
	}
}