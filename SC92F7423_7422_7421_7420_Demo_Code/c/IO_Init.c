#include "H/Function_Init.H"
/*****************************************************
*�������ƣ�void IO_Init(void)
*�������ܣ�IO��ʼ��
*��ڲ�����void
*���ڲ�����void
*****************************************************/
void IO_Init(void)
{
	#if (IC_MODEL == SC92F7423)  //SC92F7423���Ŷ���
	P0CON = 0x00;  //����P0Ϊ���������ģʽ
	P0PH  = 0xFF;
	P1CON = 0x00;  //����P1Ϊ��������ģʽ
	P1PH  = 0x00;
	P2CON = 0xFF;  //����P2Ϊǿ����ģʽ
	P2PH  = 0x00;
	P5CON = 0xFF;  //����P5Ϊǿ����ģʽ
	P5PH  = 0x00;
	#endif
	
	#if (IC_MODEL == SC92F7422)  //SC92F7423���Ŷ���
	P0CON = 0x00;  //����P0Ϊ���������ģʽ
	P0PH  = 0xFF;
	P1CON = 0x00;  //����P1Ϊ��������ģʽ
	P1PH  = 0x00;
	P2CON = 0xFF;  //����P2Ϊǿ����ģʽ
	P2PH  = 0x00;
	SC92F7422_NIO_Init(); //δ����IO������
	#endif
	
	#if (IC_MODEL == SC92F7421)  //SC92F7421���Ŷ���
	P0CON = 0x00;  //����P0Ϊ���������ģʽ
	P0PH  = 0xFF;
	P1CON = 0x00;  //����P1Ϊ��������ģʽ
	P1PH  = 0x00;
	P2CON = 0xFF;  //����P2Ϊǿ����ģʽ
	P2PH  = 0x00;
	SC92F7421_NIO_Init(); //δ����IO������
	#endif
	
	#if (IC_MODEL == SC92F7420)  //SC92F7420���Ŷ���
	P1CON = 0x00;  //����P1Ϊ��������ģʽ
	P1PH  = 0x00;
	P2CON = 0xFF;  //����P2Ϊǿ����ģʽ
	P2PH  = 0x00;
	SC92F7420_NIO_Init(); //δ����IO������
	#endif
}