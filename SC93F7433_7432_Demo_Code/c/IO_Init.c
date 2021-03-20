#include "H/Function_Init.H"
/*****************************************************
*�������ƣ�void IO_Init(void)
*�������ܣ�IO��ʼ��
*��ڲ�����void
*���ڲ�����void
*****************************************************/
void IO_Init(void)
{
    #if (IC_MODEL == SC93F7433)  //SC93F7433���Ŷ���
	P0CON = 0x00;  //����P0Ϊ���������ģʽ
	P0PH  = 0xFF;
	P1CON = 0x00;  //����P1Ϊ��������ģʽ
	P1PH  = 0x00;
	P2CON = 0xFF;  //����P2Ϊǿ����ģʽ
	P2PH  = 0x00;
	P5CON = 0xFF;  //����P5Ϊǿ����ģʽ
	P5PH  = 0x00;
	#endif
    
    #if (IC_MODEL == SC93F7432)  //SC93F7432���Ŷ���
	P0CON = 0x00;  //����P0Ϊ���������ģʽ
	P0PH  = 0xFF;
	P1CON = 0x00;  //����P1Ϊ��������ģʽ
	P1PH  = 0x00;
	P2CON = 0xFF;  //����P2Ϊǿ����ģʽ
	P2PH  = 0x00;
	SC93F7432_NIO_Init(); //δ����IO������
	#endif
}