#include "H/Function_Init.H"

void EX_Init(void);
uchar INT2_flag = 0x00;
/*****************************************************
*�������ƣ�void EXTI_Test(void)
*�������ܣ��ⲿ�жϲ���
*��ڲ�����void
*���ڲ�����void
*****************************************************/
void EXTI_Test(void)
{
	EX_Init();
	while(1)
	{					
	}
}
/*****************************************************
*�������ƣ�void EX_Init(void)
*�������ܣ��ⲿ�жϳ�ʼ��
*��ڲ�����void
*���ڲ�����void
*****************************************************/
void EX_Init(void)
{	
	//�����жϿ�INT03��INT24/25
	P1CON &= 0XF7;     //�ж�IO������Ϊ��������
	P1PH  |= 0x08;     //�ж�IO������Ϊ���������
	P2CON &= 0XFC;     //�ж�IO������Ϊ��������
	P2PH  |= 0x03;     //�ж�IO������Ϊ���������
 
	//����INT03�������жϡ�INT24/25�½����ж�
    //�½�������	
	INT0F = 0X00 ;    //xxxx 0000  0�ر� 1ʹ��
    INT2F = 0X30 ;    //0000 xxxx  0�ر� 1ʹ��
    //����������	
	INT0R = 0X08 ;    //xxxx 0000  0�ر� 1ʹ�� 
	INT2R = 0X00 ;    //0000 xxxx  0�ر� 1ʹ��	
	
	//�ⲿ�ж����ȼ�����
	IE  |= 0x01;	//0000 0x0x
	IE1 |= 0x08;	//0000 x000  INT2ʹ��
	IP  |= 0X00;
	IP1 |= 0X00;
	EA = 1;
}

/*****************************************************
*�������ƣ�void EX0/2() interrupt	0/10
*�������ܣ��ⲿ�жϷ�����
*��ڲ�����void
*���ڲ�����void
*****************************************************/
void EX0() interrupt	0
{
    P02 = ~P02;
}

void EX2() interrupt	10
{
    P03 = ~P03;
	if(P20 == 0)
	{
		INT2_flag = 0x10; //INT12�����ж�
	}
	if(P21 == 0)
	{
		INT2_flag = 0x20; //INT13�����ж�
	}
}