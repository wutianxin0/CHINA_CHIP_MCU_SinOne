#include "H/Function_Init.H"

//ѡ������һģʽ��
#define  Uart1  0
#define  TWI1    1
#define  SPI1    2

#define  SSI1_Mode  SPI1

void Uart1_Init(uint Freq,unsigned long int baud);
void TWI1_Init(void);
void SPI1_Init(void);

bit Uart1SendFlag = 0;     //Uart1�����жϱ�־λ
bit Uart1ReceiveFlag = 0;  //Uart1�����жϱ�־λ
bit SPI1Flag = 0;          //SPI1���ݴ�����ɱ�־λ
bit TWI1Flag = 0;          //TWI1�жϱ�־λ

/*****************************************************
*�������ƣ�void SSI1_Test(void)
*�������ܣ�SSI1����
*��ڲ�����void
*���ڲ�����void
*****************************************************/
void SSI1_Test(void)
{
#if (SSI1_Mode == Uart1)
	Uart1_Init(16,9600);
	while(1)
	{
		SS1DAT = 0xAA;
		while(!Uart1SendFlag);
		Uart1SendFlag = 0;
	}
#endif
	
#if (SSI1_Mode == TWI1)
	TWI1_Init();
	while(1)
	{
	}
#endif

#if (SSI1_Mode == SPI1)
	SPI1_Init();
	while(1)
	{
		SS1DAT = 0xAA;
		while(!SPI1Flag);
		SPI1Flag = 0;
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
	P2CON &= 0xFC;                      //TX/RX����Ϊ���������
	P2PH  |= 0x03;
	
	OTCON |= 0xC0;                       //���нӿ�SSI1ѡ��Uart1ͨ��
	SS1CON0 = 0x50;                     //����ͨ�ŷ�ʽΪģʽһ���������
	SS1CON1 = Freq*1000000/baud;        //�����ʵ�λ����
	SS1CON2 = (Freq*1000000/baud)>>8;   //�����ʸ�λ����
	IE1 |= 0x01;                        //����SSI�ж�
    EA = 1;	
}

/*****************************************************
*�������ƣ�void TWI1_Init(void)
*�������ܣ�TWI1��ʼ��
*��ڲ�����void
*���ڲ�����void
*****************************************************/
void TWI1_Init(void)
{
	OTCON |= 0x80;    //ѡ��TWI1ģʽ
	SS1CON0 = 0x80;  // ---- x---  0Ϊ��������գ�1Ϊ�������
	SS1CON1 = 0x01;  //xxxx xxxy  xΪ��ַ�Ĵ�����yΪ0��ֹ/1����ͨ�õ�ַ��Ӧ
	IE1 |= 0x01;
	EA = 1;
}

/*****************************************************
*�������ƣ�void SPI1_Init(void)
*�������ܣ�SPI1��ʼ��
*��ڲ�����void
*���ڲ�����void
*****************************************************/
void SPI1_Init(void)
{
	OTCON |= 0X40;     //ѡ��SPI1ģʽ
	SS1CON0 = 0x2f;   //����SPI1Ϊ���豸��SCK����ʱ��Ϊ�͵�ƽ��SCK���ڵڶ��زɼ����ݣ�ʱ������ΪFsys/128
	SS1CON1 = 0x01;   //�������ж�
	SS1CON0 |= 0x80;  //����SPI1
	IE1 |= 0x01;
	EA = 1;
    
    SS1DAT = 0xAA;
}


/*****************************************************
*�������ƣ�void TWI1/SPI1/UART1_Int() interrupt 7
*�������ܣ�SSI�жϺ���
*��ڲ�����void
*���ڲ�����void
*****************************************************/
#if (SSI1_Mode == Uart1)
void Uart1_Int() interrupt 7   //Uart1�жϺ���
{
	if(SS1CON0&0x02)    //���ͱ�־λ�ж�
	{
		SS1CON0 &= 0xFD;
		Uart1SendFlag = 1;
	}
	if((SS1CON0&0x01))  //���ձ�־λ�ж�
	{
		SS1CON0 &= 0xFE;
		Uart1ReceiveFlag = 1;
	}	
}
#endif

#if (SSI1_Mode == TWI1)
void TWI1_Int() interrupt 7     //TWI�жϺ���
{
	if(SS1CON0&0x40)
	{
		SS1CON0 &= 0xbf;  //�ж�����
		TWI1Flag = 1;
	}	
}
#endif 

#if (SSI1_Mode == SPI1)
void SPI1INT(void) interrupt 7    //SPI�жϺ���
{	  
	if(SS1CON1&0X08)    //���ͻ������ձ�־�ж�
	{
		SS1CON1 &= ~0X08;
	}
	if(SS1CON1&0X80)    //���ݴ����־λ�ж�
	{
		SS1CON1 &= ~0X80;
		SPI1Flag = 1;
	}
}
#endif 