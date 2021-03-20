#include "H/Function_Init.H" 

void Uart_Init(uint Freq,unsigned long int baud);
bit UartSendFlag = 0; //�����жϱ�־λ
bit UartReceiveFlag = 0; //�����жϱ�־λ
/*****************************************************
*�������ƣ�void Uart_Test(void)
*�������ܣ�Uart����
*��ڲ�����void
*���ڲ�����void
*****************************************************/
void Uart_Test(void)
{
	Uart_Init(32,9600);
	while(1)
	{
		SBUF = 0x55;
		while(!UartSendFlag);
		UartSendFlag = 0;
	}
}
/*****************************************************
*�������ƣ�void Uart_Init(uint Freq,unsigned long int baud)
*�������ܣ�Uart�жϳ�ʼ��
*��ڲ�����Freq-��Ƶ��baud-������
*���ڲ�����void
*****************************************************/
void Uart_Init(uint Freq,unsigned long int baud)    //ѡ��Timer1��Ϊ�������źŷ�����
{
	P2CON &= 0xFC;   //TX/RX����Ϊ���������
	P2PH  |= 0x03;
	
	SCON  |= 0X50;   //����ͨ�ŷ�ʽΪģʽһ���������
	TMCON |= 0X02;
	TH1 = (Freq*1000000/baud)>>8;	  //������ΪT1�����ʱ�䣻
	TL1 = Freq*1000000/baud;
	TR1 = 0;
	ET1 = 0;
	EUART = 1;     //����Uart�ж�
	EA = 1;
}

/*
void Uart_Init(uint Freq,unsigned long int baud)    //ѡ��Timer2��Ϊ�������źŷ�����
{
	P2CON &= 0xFC;   //TX/RX����Ϊ���������
	P2PH  |= 0x03;

	SCON  |= 0X50;   //����ͨ�ŷ�ʽΪģʽһ���������
    TXINX = 0x02;
	TMCON |= 0X04;
	TXMOD = 0X00;
	TXCON = 0X30;
	RCAPXH = Freq*1000000/baud/256;
	RCAPXL = Freq*1000000/baud%256;
	TRX = 0;
	ET2 = 0;
	EUART = 1;     //����Uart�ж�
	EA = 1;
}
*/

/*****************************************************
*�������ƣ�void UartInt(void) interrupt 4
*�������ܣ�Uart�жϺ���
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
