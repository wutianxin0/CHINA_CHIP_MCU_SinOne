#include "H/Function_Init.H"

unsigned char code *IapAddr = 0x00;

void IAPWrite(uint Addr,uchar Value);
void IAPPageErase(uint Addr);
uchar IAPRead(uint Addr);
uchar IapReadData = 0x00;   //��Ŷ�ȡ��IAP����

/*****************************************************
*�������ƣ�void IAP_Test(uchar Address)
*�������ܣ�IAP����
*��ڲ�����Address
*���ڲ�����void
*****************************************************/
void IAP_Test(uint Address)
{
    IAPPageErase(Address);   //ҳ����
	IAPWrite(Address,0xff);  //д����
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
*�������ƣ�void IAPWrite(uchar Addr,uchar Value)
*�������ܣ�IAPд��ʼ��
*��ڲ�����Addr,Value
*���ڲ�����void
*****************************************************/
//IAPд����
void IAPWrite(uint Addr,uchar Value)
{	
    bit temp = EA;
	EA = 0;
    IAPADE = 0x00;   
	IAPDAT = Value;     //д������Data
	IAPADH = (unsigned char)((Addr >> 8));   //д���ַ�ĸ�8λ
	IAPADL = (unsigned char)Addr;            //д���ַ�ĵ�8λ
	IAPKEY = 0xF0;		//IAP������������ʱ��
    IAPCTL = 0X10;      //ִ�С�д���������������󣬽���flash��̲���
	IAPCTL |= 0x02;     //ִ�С�д��������������
	_nop_();
	_nop_();
	_nop_();
	_nop_();
	_nop_();
	_nop_();
	_nop_();
	_nop_();
	IAPADE = 0x00;      //MOVCָ��ROM
	EA = temp;
}

/*****************************************************
*�������ƣ�void IAPPageErase(uint Addr)
*�������ܣ�IAPҳ����
*��ڲ�����Addr
*���ڲ�����void
*****************************************************/
void IAPPageErase(uint Addr)
{
	bit temp = EA;
	EA = 0;
	IAPADE = 0x00;
	
	IAPADH = (unsigned char)((Addr >> 8)); //д��������׵�ַ��λ
    IAPADL = (unsigned char)Addr;          //д��������׵�ַ��λ
	
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
*�������ƣ�uchar IAPRead(uchar Addr)
*�������ܣ�IAP����ʼ��
*��ڲ�����Addr
*���ڲ�����ReadValue
*****************************************************/
uchar IAPRead(uint Addr)
{
	uchar ReadValue = 0x00;
    bit temp = EA;
	EA = 0;
	IAPADE = 0x00;
	ReadValue = *(IapAddr+Addr); //��ȡ������
	IAPADE = 0x00;               //MOVCָ��ROM
	EA = temp;
	return ReadValue;
}
