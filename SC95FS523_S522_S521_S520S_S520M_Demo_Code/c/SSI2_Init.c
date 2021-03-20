#include "H/Function_Init.H"

//ѡ������һģʽ��
#define  Uart2   0
#define  TWI2    1
#define  SPI2    2

#define  SSI2_Mode  TWI2

void Uart2_Init(uint Freq,unsigned long int baud);
void TWI2_Init(void);
void SPI2_Init(void);

bit Uart2SendFlag = 0;    //Uart2�����жϱ�־λ
bit Uart2ReceiveFlag = 0; //Uart2�����жϱ�־λ
bit SPI2Flag = 0;         //SPI2���ݴ�����ɱ�־λ
bit TWI2Flag = 0;         //TWI2�жϱ�־λ

/*****************************************************
*�������ƣ�void SSI2_Test(void)
*�������ܣ�SSI2����
*��ڲ�����void
*���ڲ�����void
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
		US2CON1 |= 0x20;    //������ʼ����
		while(!TWI2Flag);
        TWI2Flag = 0;		
		US2CON3 = 0x10;	    //���͵�ַ��������
        while(!TWI2Flag);
        TWI2Flag = 0;
        US2CON3 = 0x55;	    //���͵�ַ��������
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
*�������ƣ�void Uart2_Init(uint Freq,unsigned long int baud)
*�������ܣ�Uart2�жϳ�ʼ��
*��ڲ�����Freq-��Ƶ��baud-������
*���ڲ�����void
*****************************************************/
void Uart2_Init(uint Freq,unsigned long int baud)
{
	P1CON &= 0xCF;    //TX/RX����Ϊ���������
	P1PH  |= 0x30;
	
	TMCON |= 0xC0;    //���нӿ�SSI2ѡ��Uart2ͨ��
	US2CON0 = 0x50;   //����ͨ�ŷ�ʽΪģʽһ���������
	US2CON1 = Freq*1000000/baud;   //�����ʵ�λ����
	US2CON2 = (Freq*1000000/baud)>>8;   //�����ʸ�λ����
	IE2 |= 0x02;      //����SSI2�ж�
    EA = 1;	
}

/*****************************************************
*�������ƣ�void TWI2_Init(void)
*�������ܣ�TWI2��ʼ��
*��ڲ�����void
*���ڲ�����void
*****************************************************/
void TWI2_Init(void)
{
	TMCON |= 0x80;   //ѡ��TWI2ģʽ
	US2CON0 = 0x80;  //��ģʽ�� ʹ��Ӧ���־λ
	US2CON1 = 0x05;  //---- xxxx  xΪʱ������
	IE2 |= 0x02;
	EA = 1;
}

/*****************************************************
*�������ƣ�void SPI2_Init(void)
*�������ܣ�SPI2��ʼ��
*��ڲ�����void
*���ڲ�����void
*****************************************************/
void SPI2_Init(void)
{
	TMCON |= 0X40;    //ѡ��SPI2ģʽ
	US2CON0 = 0x3F;   //����SPI2Ϊ���豸��SCK����ʱ��Ϊ�ߵ�ƽ��SCK���ڵڶ��زɼ����ݣ�ʱ������ΪFsys/128
	US2CON1 = 0x01;   //MSB���ȷ��ͣ�8λ���䣬�������ж�
	US2CON0 |= 0x80;  //����SPI2
	IE2 |= 0x02;
	EA = 1;
}


/*****************************************************
*�������ƣ�void TWI2/PI/UART1_Int() interrupt 16
*�������ܣ�SSI2�жϺ���
*��ڲ�����void
*���ڲ�����void
*****************************************************/
#if (SSI2_Mode == Uart2)
void Uart2_Int() interrupt 16   //Uart2�жϺ���
{
	if(US2CON0&0x02)    //���ͱ�־λ�ж�
	{
		US2CON0 &= 0xFD;
		Uart2SendFlag = 1;
	}
	if((US2CON0&0x01))  //���ձ�־λ�ж�
	{
		US2CON0 &= 0xFE;
		Uart2ReceiveFlag = 1;
	}	
}
#endif

#if (SSI2_Mode == TWI2)
void TWI2_Int() interrupt 16     //TWI2�жϺ���
{
	if(US2CON0&0x40)
	{
		US2CON0 &= 0xbf;  //�ж�����
		TWI2Flag = 1;
	}	
}
#endif 

#if (SSI2_Mode == SPI2)
void SpiInt(void) interrupt 16    //SPI2�жϺ���
{	  
	if(US2CON1&0X08)    //���ͻ������ձ�־�ж�
	{
		US2CON1 &= ~0X08;
	}
	if(US2CON1&0X80)    //���ݴ����־λ�ж�
	{
		US2CON1 &= ~0X80;
		SPI2Flag = 1;
	}
}
#endif 