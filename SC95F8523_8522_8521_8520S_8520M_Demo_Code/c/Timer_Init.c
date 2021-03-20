#include "H/Function_Init.H"

void Timer_Init(void);
uint count = 0;
uint count1=0,count2=0;
uchar flag=0;
/*****************************************************
*�������ƣ�void Timer_Test(void);
*�������ܣ�T0/T1/T2����
*��ڲ�����void
*���ڲ�����void
*****************************************************/
void Timer_Test(void)
{
	Timer_Init();
	while(1)
	{
	}
}
/*****************************************************
*�������ƣ�void Timer_Init(void)
*�������ܣ�T0/T1/T2��ʼ��
*��ڲ�����void
*���ڲ�����void
*****************************************************/
void Timer_Init(void)
{ 
	TMCON = 0X07;    //------111 ;Timer0��Tiemr1��Tiemr2ѡ��ʱ��Fsys
	
	//T0����
	TMOD |= 0x01;                 //0000 0001;Timer0���ù�����ʽ1
	TL0 = (65536 - 16000)%256;    //ʱ��ΪFsys�������ʱ��=16000*��1/Fsys��;
	TH0 = (65536 - 16000)/256;
	TR0 = 0;
	ET0 = 1;//��ʱ��0����
	TR0 = 1;//�򿪶�ʱ��0
    
	//T1����
	TMOD |= 0x20;            //0010 0000;Timer1���ù�����ʽ2
	TL1 = 256 - 160;         //ʱ��ΪFsys�������ʱ��=160*��1/Fsys��;
	TH1 = 256 - 160;
	TR1 = 0;
	ET1 = 1;//��ʱ��1����
	TR1 = 1;//�򿪶�ʱ��1
    
	//T2����
	TXINX = 0x02;   //ѡ��ʱ��T2
	TXCON = 0X09;   //ʹ��EXT2��16λ����ģʽ
	TXMOD = 0X80;
	THX = 0X00;
	TLX = 0X00;
	RCAPXH = 0X00;
	RCAPXL = 0X00;
    ET2 = 1;
	TRX = 1;//�򿪶�ʱ��2

	//T3����
    TXINX = 0x03;    //ѡ��ʱ��T3
	TXMOD = 0x80;    
	TXCON = 0x00;	 //����Ϊ16λ���ؼĴ���
	RCAPXH = (65536-16000)/256;     //ʱ��ΪFsys�������ʱ��=16000*��1/Fsys��;
	RCAPXL = (65536-16000)%256;
	TRX = 0;
	IE1 |= 0x40; //��ʱ��3����
    IP1 |= 0X40;
	TRX = 1;     //�򿪶�ʱ��3	
    
    //T4����
    TXINX = 0x04;    //ѡ��ʱ��T4
	TXMOD = 0x80;    
	TXCON = 0x00;	 //����Ϊ16λ���ؼĴ���
	RCAPXH = (65536-32000)/256;     //ʱ��ΪFsys�������ʱ��=32000*��1/Fsys��;
	RCAPXL = (65536-32000)%256;
	TRX = 0;
	IE1 |= 0x80;//��ʱ��4����
    IP1 |= 0X80;
	TRX = 1;    //�򿪶�ʱ��4	
    
	EA = 1;	
}

/**************************************************
*�������ƣ�void timer0/1/2/3/4() interrupt 1/3/5/13/14
*�������ܣ���ʱ���жϲ�������
*��ڲ�����void
*���ڲ�����void
**************************************************/
void timer0() interrupt 1
{
    TL0 = (65536 - 16000)%256;
	TH0 = (65536 - 16000)/256;
	P02 = ~P02;	
}

void timer1() interrupt 3
{
	P03 = ~P03;
}

void Timer2Int(void) interrupt 5
{		
    TXINX = 0x02;            //ѡ��ʱ��T2
    if((TXCON & 0x40))
	{
        P07 = ~P07;
		TXCON &= ~0X40;      //�����־λ
		if(++flag >= 12)     
		{
			flag = 0;
			THX = 0;
			TLX = 0;
		}
		if(flag == 10)      
		{
			count1 = ((uint)(RCAPXH << 8) + RCAPXL);
		}
		if(flag == 11)
		{
			count2 = ((uint)(RCAPXH << 8) + RCAPXL);
			count = count2 - count1;      //��10���½��ص���11���½��ص�ֵ
		}
	}
}

void Timer3Int(void) interrupt 13
{		
    TXINX = 0x03;   //ѡ��ʱ��T3
	TFX = 0;        //�������
    P05 = ~P05;
}

void Timer4Int(void) interrupt 14
{		
    TXINX = 0x04;   //ѡ��ʱ��T4
	TFX = 0;        //�������
    P06 = ~P06;
}
