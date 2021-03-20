#include "H/Function_Init.H"
/*****************************************************
*�������ƣ�void IO_Init(void)
*�������ܣ�IO��ʼ��
*��ڲ�����void
*���ڲ�����void
*****************************************************/
void IO_Init(void)
{
	#if (IC_MODEL == SC92F8447)  //SC92F8447���Ŷ���
	P0CON = 0xFF;  //����P0Ϊǿ����ģʽ
	P0PH  = 0x00;
	P1CON = 0x00;  //����P1Ϊ��������ģʽ
	P1PH  = 0x00;
	P2CON = 0x00;  //����P2Ϊ���������ģʽ
	P2PH  = 0xFF;
	P3CON = 0xFF;  //����P3Ϊǿ����ģʽ
	P3PH  = 0x00;
	P4CON = 0xFF;  //����P4Ϊǿ����ģʽ
	P4PH  = 0x01;
	P5CON = 0xFF;  //����P5Ϊǿ����ģʽ
	P5PH  = 0x00;
	#endif
	
	#if (IC_MODEL == SC92F8446)  //SC92F8446���Ŷ���
	P0CON = 0xFF;  //����P0Ϊǿ����ģʽ
	P0PH  = 0x00;
	P1CON = 0x00;  //����P1Ϊ��������ģʽ
	P1PH  = 0x00;
	P2CON = 0x00;  //����P2Ϊ���������ģʽ
	P2PH  = 0xFF;
	P3CON = 0xFF;  //����P3Ϊǿ����ģʽ
	P3PH  = 0x00;
	P4CON = 0xFF;  //����P4Ϊǿ����ģʽ
	P4PH  = 0x01;
	P5CON = 0xFF;  //����P5Ϊǿ����ģʽ
	P5PH  = 0x00;
	SC92F8446_NIO_Init(); //δ����IO������
	#endif
	
	#if (IC_MODEL == SC92F8445)  //SC92F8543���Ŷ���
	P0CON = 0xFF;  //����P0Ϊǿ����ģʽ
	P0PH  = 0x00;
	P1CON = 0x00;  //����P1Ϊ��������ģʽ
	P1PH  = 0x00;
	P2CON = 0x00;  //����P2Ϊ���������ģʽ
	P2PH  = 0xFF;
	P4CON = 0xFF;  //����P4Ϊǿ����ģʽ
	P4PH  = 0x01;
	SC92F8445_NIO_Init(); //δ����IO������
	#endif
}