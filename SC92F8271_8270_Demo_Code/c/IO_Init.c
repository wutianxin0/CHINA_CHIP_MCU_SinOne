#include "H/Function_Init.H"
/*****************************************************
*�������ƣ�void IO_Init(void)
*�������ܣ�IO��ʼ��
*��ڲ�����void
*���ڲ�����void
*****************************************************/
void IO_Init(void)
{	
	#if (IC_MODEL == SC92F8271)  //SC92F8271���Ŷ���
	P0CON = 0xFF;  //����P0Ϊǿ����ģʽ
	P0PH  = 0x00;
	P1CON = 0x00;  //����P1Ϊ��������ģʽ
	P1PH  = 0x00;
	P2CON = 0x00;  //����P2Ϊ���������ģʽ
	P2PH  = 0xFF;
	SC92F8271_NIO_Init(); //δ����IO������
	#endif
	
	#if (IC_MODEL == SC92F8270)  //SC92F8270���Ŷ���
	P0CON = 0xFF;  //����P0Ϊǿ����ģʽ
	P0PH  = 0x00;
	P1CON = 0x00;  //����P1Ϊ��������ģʽ
	P1PH  = 0x00;
	P2CON = 0x00;  //����P2Ϊ���������ģʽ
	P2PH  = 0xFF;
	SC92F8270_NIO_Init(); //δ����IO������
	#endif
	
}