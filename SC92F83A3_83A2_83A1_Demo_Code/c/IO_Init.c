#include "H/Function_Init.H"
/*****************************************************
*�������ƣ�void IO_Init(void)
*�������ܣ�IO��ʼ��
*��ڲ�����void
*���ڲ�����void
*****************************************************/
void IO_Init(void)
{
	#if (IC_MODEL == SC92F83A3)  //SC92F83A3�Ŷ���
	P0CON = 0x00;  //����P0Ϊ��������ģʽ
	P0PH  = 0x00;		
	P1CON = 0x00;  //����P1Ϊ���������ģʽ
	P1PH  = 0xFF;
	P2CON = 0xFF;  //����P2Ϊǿ����ģʽ
	P2PH  = 0x00;
	P5CON = 0xFF;  //����P4Ϊǿ����ģʽ
	P5PH  = 0x00;
	#endif
	
	#if (IC_MODEL == SC92F83A2)  //SC92F83A2�Ŷ���
	P0CON = 0x00;  //����P0Ϊ��������ģʽ
	P0PH  = 0x00;		
	P1CON = 0x00;  //����P1Ϊ���������ģʽ
	P1PH  = 0xFF;
	P2CON = 0xFF;  //����P2Ϊǿ����ģʽ
	P2PH  = 0x00;
	SC92F83A2_NIO_Init(); //δ����IO������
	#endif
	
	#if (IC_MODEL == SC92F83A1)  //SC92F83A1�Ŷ���
	P0CON = 0x00;  //����P0Ϊ��������ģʽ
	P0PH  = 0x00;		
	P1CON = 0x00;  //����P1Ϊ���������ģʽ
	P1PH  = 0xFF;
	P2CON = 0xFF;  //����P2Ϊǿ����ģʽ
	P2PH  = 0x00;
	SC92F83A1_NIO_Init(); //δ����IO������
	#endif
}