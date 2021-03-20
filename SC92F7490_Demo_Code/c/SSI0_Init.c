#include "H/Function_Init.H"

//ѡ������һģʽ��
#define  Uart0   0
#define  TWI0    1
#define  SPI0    2

#define  SSI0_Mode  SPI0

void Uart0_Init(uint Freq,unsigned long int baud);
void TWI0_Init(void);
void SPI0_Init(void);

bit Uart0SendFlag = 0;    //Uart0�����жϱ�־λ
bit Uart0ReceiveFlag = 0; //Uart0�����жϱ�־λ
bit SPI0Flag = 0;          //SPI0���ݴ�����ɱ�־λ
bit TWI0Flag = 0;          //TWI0�жϱ�־λ

/*****************************************************
*�������ƣ�void SSI0_Test(void)
*�������ܣ�SSI0����
*��ڲ�����void
*���ڲ�����void
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
*�������ƣ�void Uart0_Init(uint Freq,unsigned long int baud)
*�������ܣ�Uart0�жϳ�ʼ��
*��ڲ�����Freq-��Ƶ��baud-������
*���ڲ�����void
*****************************************************/
void Uart0_Init(uint Freq,unsigned long int baud)
{
	P1CON &= 0xF3;   //TX/RX����Ϊ���������
	P1PH  |= 0x0C;
	
	OTCON |= 0x30;    //���нӿ�SSIѡ��Uart0ͨ��
	SS0CON0 = 0x50;   //����ͨ�ŷ�ʽΪģʽһ���������
	SS0CON1 = Freq*1000000/baud;   //�����ʵ�λ����
	SS0CON2 = (Freq*1000000/baud)>>8;   //�����ʸ�λ����
	IE |= 0x10;       //����SSI�ж�
    EA = 1;	
}

/*****************************************************
*�������ƣ�void TWI0_Init(void)
*�������ܣ�TWI0��ʼ��
*��ڲ�����void
*���ڲ�����void
*****************************************************/
void TWI0_Init(void)
{
	OTCON |= 0x20;  //ѡ��TWI0ģʽ
	SS0CON0 = 0x80;  // ---- x---  0Ϊ��������գ�1Ϊ�������
	SS0CON1 = 0x01;  //xxxx xxxy  xΪ��ַ�Ĵ�����yΪ0��ֹ/1����ͨ�õ�ַ��Ӧ
	IE |= 0x10;
	EA = 1;
}

/*****************************************************
*�������ƣ�void SPI0_Init(void)
*�������ܣ�SPI0��ʼ��
*��ڲ�����void
*���ڲ�����void
*****************************************************/
void SPI0_Init(void)
{
	OTCON |= 0X10;  //ѡ��SPI0ģʽ
	SS0CON0 = 0x2f; //����SPI0Ϊ���豸��SCK����ʱ��Ϊ�͵�ƽ��SCK���ڵڶ��زɼ����ݣ�ʱ������ΪFsys/128
	SS0CON1 = 0x01;   //�������ж�
	SS0CON0 |= 0x80; //����SPI
	IE |= 0x10;
	EA = 1;
}


/*****************************************************
*�������ƣ�void TWI0/SPI0/UART0_Int() interrupt 7
*�������ܣ�SSI0�жϺ���
*��ڲ�����void
*���ڲ�����void
*****************************************************/
#if (SSI0_Mode == Uart0)
void Uart0_INT() interrupt 4   //Uart1�жϺ���
{
	if(SS0CON0&0x02)    //���ͱ�־λ�ж�
	{
		SS0CON0 &= 0xFD;
		Uart0SendFlag = 1;
	}
	if((SS0CON0&0x01))  //���ձ�־λ�ж�
	{
		SS0CON0 &= 0xFE;
		Uart0ReceiveFlag = 1;
	}	
}
#endif

#if (SSI0_Mode == TWI0)
void TWI0_INT() interrupt 4     //TWI�жϺ���
{
	if(SS0CON0&0x40)
	{
		SS0CON0 &= 0xbf;  //�ж�����
		TWI0Flag = 1;
	}	
}
#endif 

#if (SSI0_Mode == SPI0)
void SPI0INT(void) interrupt 4    //SPI�жϺ���
{	  
	if(SS0CON1&0X08)    //���ͻ������ձ�־�ж�
	{
		SS0CON1 &= ~0X08;
	}
	if(SS0CON1&0X80)    //���ݴ����־λ�ж�
	{
		SS0CON1 &= ~0X80;
		SPI0Flag = 1;
	}
}
#endif 