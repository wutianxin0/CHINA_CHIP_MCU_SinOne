#include "H/Function_Init.H"

unsigned char code *IapAddr = 0x00;

void IAPWrite(uint Addr,uchar Value);
void IAPPageErase(uint Addr);
uchar IAPRead(uint Addr);
uchar IapReadData = 0x00;   //存放读取的IAP数据

/*****************************************************
*函数名称：void IAP_Test(uchar Address)
*函数功能：IAP测试
*入口参数：Address
*出口参数：void
*****************************************************/
void IAP_Test(uint Address)
{
    IAPPageErase(Address);   //页擦除
	IAPWrite(Address,0xff);  //写数据
	IapReadData = IAPRead(Address);
	while(1)
	{
		if(IapReadData == 0xff)
		{
			P02 = ~P02;
		}
		else
		{
			P03 = ~P03;
		}
	}
}

/*****************************************************
*函数名称：void IAPWrite(uchar Addr,uchar Value)
*函数功能：IAP写初始化
*入口参数：Addr,Value
*出口参数：void
*****************************************************/
//IAP写操作
void IAPWrite(uint Addr,uchar Value)
{	
    bit temp = EA;
	EA = 0;
    IAPADE = 0x00;   
	IAPDAT = Value;     //写入数据Data
	IAPADH = (unsigned char)((Addr >> 8));   //写入地址的高8位
	IAPADL = (unsigned char)Addr;            //写入地址的低8位
	IAPKEY = 0xF0;		//IAP开启保护控制时间
    IAPCTL = 0X10;      //执行“写入或快擦除操作命令”后，进入flash编程操作
	IAPCTL |= 0x02;     //执行“写入或快擦除操作命令”
	_nop_();
	_nop_();
	_nop_();
	_nop_();
	_nop_();
	_nop_();
	_nop_();
	_nop_();
	IAPADE = 0x00;      //MOVC指向ROM
	EA = temp;
}

/*****************************************************
*函数名称：void IAPPageErase(uint Addr)
*函数功能：IAP页擦除
*入口参数：Addr
*出口参数：void
*****************************************************/
void IAPPageErase(uint Addr)
{
	bit temp = EA;
	EA = 0;
	IAPADE = 0x00;
	
	IAPADH = (unsigned char)((Addr >> 8)); //写入待擦除首地址高位
    IAPADL = (unsigned char)Addr;          //写入待擦除首地址低位
	
	IAPKEY = 0XF0;
	IAPCTL = 0X20;
	IAPCTL |= 0X02;
	_nop_();
	_nop_();
	_nop_();
	_nop_();
    _nop_();
	_nop_();
	_nop_();
	_nop_();
	IAPADE = 0x00;
	EA = temp;		
}

/*****************************************************
*函数名称：uchar IAPRead(uchar Addr)
*函数功能：IAP读初始化
*入口参数：Addr
*出口参数：ReadValue
*****************************************************/
uchar IAPRead(uint Addr)
{
	uchar ReadValue = 0x00;
    bit temp = EA;
	EA = 0;
	IAPADE = 0x00;
	ReadValue = *(IapAddr+Addr); //读取的数据
	IAPADE = 0x00;               //MOVC指向ROM
	EA = temp;
	return ReadValue;
}
