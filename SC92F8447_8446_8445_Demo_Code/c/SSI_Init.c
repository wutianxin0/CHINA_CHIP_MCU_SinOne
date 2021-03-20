#include "H/Function_Init.H"

//ѡ������һģʽ��
#define  Uart1  0
#define  TWI    1
#define  SPI    2

#define  SSI_Mode  Uart1

void Uart1_Init(uint Freq,unsigned long int baud);
void TWI_Init(void);
void SPI_Init(void);

bit Uart1SendFlag = 0;    //Uart�����жϱ�־λ
bit Uart1ReceiveFlag = 0; //Uart�����жϱ�־λ
bit SPIFlag = 0;         //SPI���ݴ�����ɱ�־λ
bit TWIFlag = 0;         //�жϱ�־λ
/*****************************************************
*�������ƣ�void SSI_Test(void)
*�������ܣ�SSI����
*��ڲ�����void
*���ڲ�����void
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
*�������ƣ�void Uart1_Init(uint Freq,unsigned long int baud)
*�������ܣ�Uart1�жϳ�ʼ��
*��ڲ�����Freq-��Ƶ��baud-������
*���ڲ�����void
*****************************************************/
void Uart1_Init(uint Freq,unsigned long int baud)
{
	P1CON &= 0xF5;   //TX/RX����Ϊ���������
	P1PH  |= 0x0A;
	
	OTCON |= 0xC0;    //���нӿ�SSIѡ��Uart1ͨ��
	SSCON0 = 0x50;   //����ͨ�ŷ�ʽΪģʽһ���������
	SSCON1 = Freq*1000000/baud;   //�����ʵ�λ����
	SSCON2 = (Freq*1000000/baud)>>8;   //�����ʸ�λ����
	IE1 |= 0x01;      //����SSI�ж�
    EA = 1;	
}

/*****************************************************
*�������ƣ�void TWI_Init(void)
*�������ܣ�TWI��ʼ��
*��ڲ�����void
*���ڲ�����void
*****************************************************/
void TWI_Init(void)
{
	OTCON |= 0x80;  //ѡ��TWIģʽ
	SSCON0 = 0x80;  // ---- x---  0Ϊ��������գ�1Ϊ�������
	SSCON1 = 0x01;  //xxxx xxxy  xΪ��ַ�Ĵ�����yΪ0��ֹ/1����ͨ�õ�ַ��Ӧ
	IE1 |= 0x01;
	EA = 1;
}

/*****************************************************
*�������ƣ�void SPI_Init(void)
*�������ܣ�SPI��ʼ��
*��ڲ�����void
*���ڲ�����void
*****************************************************/
void SPI_Init(void)
{
	OTCON |= 0X40;  //ѡ��SPIģʽ
	SSCON0 = 0x2F; //����SPIΪ���豸��SCK����ʱ��Ϊ�͵�ƽ��SCK���ڵڶ��زɼ����ݣ�ʱ������ΪFsys/512
	SSCON1 = 0x01;   //�������ж�
	SSCON0 |= 0x80; //����SPI
	IE1 |= 0x01;
	EA = 1;
}


/*****************************************************
*�������ƣ�void TWI/SPI/UART1_Int() interrupt 7
*�������ܣ�SSI�жϺ���
*��ڲ�����void
*���ڲ�����void
*****************************************************/
#if (SSI_Mode == Uart1)
void Uart1_Int() interrupt 7   //Uart1�жϺ���
{
	if(SSCON0&0x02)    //���ͱ�־λ�ж�
	{
		SSCON0 &= 0xFD;
		Uart1SendFlag = 1;
	}
	if((SSCON0&0x01))  //���ձ�־λ�ж�
	{
		SSCON0 &= 0xFE;
		Uart1ReceiveFlag = 1;
	}	
}
#endif

#if (SSI_Mode == TWI)
void TWI_Int() interrupt 7     //TWI�жϺ���
{
	if(SSCON0&0x40)
	{
		SSCON0 &= 0xbf;  //�ж�����
		TWIFlag = 1;
	}	
}
#endif 

#if (SSI_Mode == SPI)
void SpiInt(void) interrupt 7    //SPI�жϺ���
{	  
	if(SSCON1&0X08)    //���ͻ������ձ�־�ж�
	{
		SSCON1 &= ~0X08;
	}
	if(SSCON1&0X80)    //���ݴ����־λ�ж�
	{
		SSCON1 &= ~0X80;
		SPIFlag = 1;
	}
}
#endif 