#include "H/Function_Init.H"
/*****************************************************
*�������ƣ�void IO_Init(void)
*�������ܣ�IO��ʼ��
*��ڲ�����void
*���ڲ�����void
*****************************************************/
void IO_Init(void)
{
    #if (IC_MODEL == SC93F5312)  //SC93F5312���Ŷ���
	P0CON = 0x00;  //����P0Ϊ���������ģʽ
	P0PH  = 0xFF;
	P1CON = 0x00;  //����P1Ϊ��������ģʽ
	P1PH  = 0x00;
	P2CON = 0xFF;  //����P2Ϊǿ����ģʽ
	P2PH  = 0x00;
	#endif
    
    #if (IC_MODEL == SC93F5311)  //SC93F5311���Ŷ���
	P0CON = 0x00;  //����P0Ϊ���������ģʽ
	P0PH  = 0xFF;
	P1CON = 0x00;  //����P1Ϊ��������ģʽ
	P1PH  = 0x00;
	P2CON = 0xFF;  //����P2Ϊǿ����ģʽ
	P2PH  = 0x00;
	SC93F5311_NIO_Init(); //δ����IO������
	#endif
    
    #if (IC_MODEL == SC93F5310)  //SC93F5310���Ŷ���
	P1CON = 0x00;  //����P1Ϊ��������ģʽ
	P1PH  = 0x00;
	P2CON = 0xFF;  //����P2Ϊǿ����ģʽ
	P2PH  = 0x00;
	SC93F5310_NIO_Init(); //δ����IO������
	#endif
}