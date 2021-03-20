#include "H/Function_Init.H"

//#define IapROM  0x00	  //0x00：选择ROM区操作  0x02：选择EEPROM区操作
//#define IapEPPROM  0x02	  //0x00：选择ROM区操作  0x02：选择EEPROM区操作
unsigned char code *IapAddr = 0x00;

void IAPWrite(uint Addr,uchar Value,uchar IAPArea);
uchar IAPRead(uint Addr,uchar IAPArea);
uchar IapReadData = 0x00;   //存放读取的IAP数据

/*****************************************************
*函数名称：void IAP_Test(uchar Address,uchar IAPArea)
*函数功能：IAP测试
*入口参数：Address,IAPArea
*出口参数：void
*****************************************************/
void IAP_Test(uint Address,uchar IAPArea)
{
	IAPWrite(Address,0xff,IAPArea);
	IapReadData = IAPRead(Address,IAPArea);
	IAPADE = 0x00;       //IAP指针指回ROM区
	while(1)
	{
		if(IapReadData == 0xff)
		{
			P20 = ~P20;
		}
		else
		{
			P21 = ~P21;
		}
	}
}

/*****************************************************
*函数名称：void IAPWrite(uchar Addr,uchar Value,uchar IAPArea)
*函数功能：IAP写初始化
*入口参数：Addr,Value,IAPArea
*出口参数：void
*****************************************************/
//IAP写操作
void IAPWrite(uint Addr,uchar Value,uchar IAPArea)
{	
	EA = 0;
	IAPDAT = Value;      //写入数据Data
	IAPADH = ((Addr>>8)&0X7F);   //写入地址的高5位
	IAPADL = Addr;               //写入地址的低8位
	
	IAPADE = IAPArea;  //IAPArea=0x00：选择ROM区操作  IAPArea=0x02：选择EEPROM区操作
	IAPKEY = 240;		   //IAP开启保护控制时间
	IAPCTL = 0x06;     //CPU hold time为2ms，写入操作命令
	_nop_();
	_nop_();
	_nop_();
	_nop_();
	_nop_();
	_nop_();
	_nop_();
	_nop_();
	IAPADE = 0x00;      //MOVC指向ROM
	EA = 1;
}
/*****************************************************
*函数名称：uchar IAPRead(uchar Addr,uchar IAPArea)
*函数功能：IAP读初始化
*入口参数：Addr,IAPArea
*出口参数：ReadValue
*****************************************************/
uchar IAPRead(uint Addr,uchar IAPArea)
{
	uchar ReadValue = 0x00;
	EA = 0;
	IAPADE = IAPArea;
	ReadValue = *(IapAddr+Addr); //读取的数据
	IAPADE = 0x00;               //MOVC指向ROM
	EA = 1;
	return ReadValue;
}
