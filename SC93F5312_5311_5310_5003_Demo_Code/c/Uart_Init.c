#include "H/Function_Init.H"

void Uart0_Init(void);
bit Uart0SendFlag = 0; //�����жϱ�־λ
bit Uart0ReceiveFlag = 0; //�����жϱ�־λ

/****************************************************
*�������ƣ�void Uart0_Test(void)
*�������ܣ�Uart0����
*��ڲ�����void
*���ڲ�����void
*****************************************************/
void Uart0_Test(void)
{
    Uart0_Init();
    while(1)
    {
        SBUF = 0x55;
        while(!(Uart0SendFlag));
        Uart0SendFlag = 0;
    }
}

/*****************************************************
*�������ƣ�void Uart0_Init(void)
*�������ܣ�Uart0�жϳ�ʼ��
*��ڲ�����void
*���ڲ�����void
*****************************************************/
void Uart0_Init(void)     //ѡ��Timer1��Ϊ�����ʷ�����
{
    P1CON &= 0x9F;
	P1PH |= 0X60;	 //TX/RXΪ���������룻

    PCON |= 0x80;    //SMOD = 1��
	SCON = 0X50;     //����ͨ�ŷ�ʽΪģʽһ���������
	T2CON = 0x00;    //ʹ�ö�ʱ��1��UARTʱ��
	TMCON = 0X03;    //��ʱ��ʱ��ΪFsys
	TMOD = 0X20;     //8λ����
	TH1 = 0xf6;      //19200�����ʣ�TH1=256 - (Freq*250000/BaudRate/16);
	TR1 = 1;
	EUART = 1;       //����Uart0�ж�
	EA = 1;
}
/*
void Uart0_Init(void)       //ѡ��Timer2��Ϊ�����ʷ�����
{
    P1CON &= 0x9F;
	P1PH = 0X60;	 //TXΪǿ�������RXΪ���������룻

    PCON |= 0x80;    //SMOD = 1��
	SCON = 0X50;     //����ͨ�ŷ�ʽΪģʽһ���������
	TMCON |= 0X04;
	T2MOD = 0X00;
	T2CON = 0X30;
	RCAP2H = 0xFF;   //������19200����λ���RCAP2H = (65536-Freq*1000000/BaudRate/128)/256;
	RCAP2L = 0xFB;   //������19200����λ���RCAP2L = (65536-Freq*1000000/BaudRate/128)%256;
	TR2 = 0;
	ET2 = 1;
	TR2 = 1;
	EUART = 1;     //����Uart0�ж�
	EA = 1;
}
*/

/*****************************************************
*�������ƣ�void UartInt(void) interrupt 4
*�������ܣ�Uart0�жϺ���
*��ڲ�����void
*���ڲ�����void
*****************************************************/
void UartInt(void) interrupt 4
{
	if(TI)
	{
		TI=0;	
	    Uart0SendFlag = 1;
	}
	if(RI)
	{
		RI=0;
        Uart0ReceiveFlag = 1;
	}
}
