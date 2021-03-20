#include "H/Function_Init.H" 

void Uart0_Init(uint Freq,unsigned long int baud);
bit UartSendFlag = 0; //�����жϱ�־λ
bit UartReceiveFlag = 0; //�����жϱ�־λ
/*****************************************************
*�������ƣ�void Uart0_Test(void)
*�������ܣ�Uart0����
*��ڲ�����void
*���ڲ�����void
*****************************************************/
void Uart0_Test(void)
{
	Uart0_Init(16,9600);
	while(1)
	{
		SBUF = 0x55;
		while(!UartSendFlag);
		UartSendFlag = 0;
	}
}
/*****************************************************
*�������ƣ�void Uart0_Init(uint Freq,unsigned long int baud)
*�������ܣ�Uart0�жϳ�ʼ��
*��ڲ�����Freq-��Ƶ��baud-������
*���ڲ�����void
*****************************************************/
void Uart0_Init(uint Freq,unsigned long int baud)    //ѡ��Timer1��Ϊ�������źŷ�����
{
	P1CON &= 0x9F;   //TX/RX����Ϊ���������
	P1PH  |= 0x60;
	
	SCON  |= 0X50;   //����ͨ�ŷ�ʽΪģʽһ���������
	TMCON |= 0X02;
	TMOD  |= 0X20;
	PCON  |= 0X80;	//SMOD=1
	TH1 = (Freq*1000000/baud)>>8;	  //������ΪT1�����ʱ�䣻
	TL1 = Freq*1000000/baud;
	TR1 = 0;
	ET1 = 0;
	EUART = 1;     //����Uart0�ж�
	EA = 1;
}
/*
void Uart0_Init(uint Freq,unsigned long int baud)    //ѡ��Timer2��Ϊ�������źŷ�����
{
    P1CON &= 0xF3;   //TX����Ϊǿ��������ߣ�RX����Ϊ���������
	P1CON |= 0x08;
	P1PH  |= 0x04;
	P13 = 1;

	SCON  |= 0X50;   //����ͨ�ŷ�ʽΪģʽһ���������
	TMCON |= 0X04;
	T2MOD = 0X00;
	T2CON = 0X30;
	RCAP2H = Freq*1000000/baud/256;
	RCAP2L = Freq*1000000/baud%256;
	TR2 = 0;
	ET2 = 0;
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
		TI = 0;	
		UartSendFlag = 1;		
	}
	if(RI)
	{
		RI = 0;	
		UartReceiveFlag = 1;
	}	
}
