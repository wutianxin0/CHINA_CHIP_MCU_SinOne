#include "H/Function_Init.H"
/*****************************************************
*�������ƣ�void IO_Init(void)
*�������ܣ�IO��ʼ��
*��ڲ�����void
*���ڲ�����void
*****************************************************/
void IO_Init(void)
{
	#if (IC_MODEL == SC92WL463)  //SC92F8463�Ŷ���
	P0CON = 0x00;  //����P0Ϊ��������ģʽ
	P0PH  = 0x00;		
	P1CON = 0x00;  //����P1Ϊ���������ģʽ
	P1PH  = 0xFF;
	P2CON = 0xFF;  //����P2Ϊǿ����ģʽ
	P2PH  = 0x00;
	P5CON = 0xFF;  //����P4Ϊǿ����ģʽ
	P5PH  = 0x00;
	#endif
	
	#if (IC_MODEL == SC92WL462)  //SC92F8462�Ŷ���
	P0CON = 0x00;  //����P0Ϊ��������ģʽ
	P0PH  = 0x00;		
	P1CON = 0x00;  //����P1Ϊ���������ģʽ
	P1PH  = 0xFF;
	P2CON = 0xFF;  //����P2Ϊǿ����ģʽ
	P2PH  = 0x00;
	SC92F8462_NIO_Init(); //δ����IO������
	#endif
	
	#if (IC_MODEL == SC92WL461)  //SC92F8461�Ŷ���
	P0CON = 0x00;  //����P0Ϊ��������ģʽ
	P0PH  = 0x00;		
	P1CON = 0x00;  //����P1Ϊ���������ģʽ
	P1PH  = 0xFF;
	P2CON = 0xFF;  //����P2Ϊǿ����ģʽ
	P2PH  = 0x00;
	SC92F8461_NIO_Init(); //δ����IO������
	#endif
}