#include "H/Function_Init.H"
/*****************************************************
*�������ƣ�void IO_Init(void)
*�������ܣ�IO��ʼ��
*��ڲ�����void
*���ڲ�����void
*****************************************************/
void IO_Init(void)
{
	#if (IC_MODEL == SC92F8545)  //SC92F8545���Ŷ���
	P0CON = 0xFF;  //����P0Ϊǿ����ģʽ
	P0PH  = 0x00;
	P1CON = 0x00;  //����P1Ϊ��������ģʽ
	P1PH  = 0x00;
	P2CON = 0x00;  //����P2Ϊ���������ģʽ
	P2PH  = 0xFF;
	P4CON = 0xFF;  //����P4Ϊǿ����ģʽ
	P4PH  = 0x00;
	SC92F8545_NIO_Init(); //δ����IO������
	#endif
	
	#if (IC_MODEL == SC92F8542)  //SC92F8542���Ŷ���
	P0CON = 0xFF;  //����P0Ϊǿ����ģʽ
	P0PH  = 0x00;
	P1CON = 0x00;  //����P1Ϊ��������ģʽ
	P1PH  = 0x00;
	P2CON = 0x00;  //����P2Ϊ���������ģʽ
	P2PH  = 0xFF;
	P4CON = 0xFF;  //����P4Ϊǿ����ģʽ
	P4PH  = 0x00;
	SC92F8542_NIO_Init(); //δ����IO������
	#endif
}