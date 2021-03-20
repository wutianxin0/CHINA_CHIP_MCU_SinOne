#include "H/Function_Init.H"
/*****************************************************
*�������ƣ�void IO_Init(void)
*�������ܣ�IO��ʼ��
*��ڲ�����void
*���ڲ�����void
*****************************************************/
void IO_Init(void)
{
    #if (IC_MODEL == SC92F7402)  //SC92F7402���Ŷ���
	P0CON = 0x00;  //����P0Ϊ��������ģʽ
	P0PH  = 0x00;		
	P1CON = 0x00;  //����P1Ϊ���������ģʽ
	P1PH  = 0xFF;
	P2CON = 0xFF;  //����P2Ϊǿ����ģʽ
	P2PH  = 0x00;
    #endif
    
    #if (IC_MODEL == SC92F7401)  //SC92F7401���Ŷ���
	P0CON = 0x00;  //����P0Ϊ��������ģʽ
	P0PH  = 0x00;		
	P1CON = 0x00;  //����P1Ϊ���������ģʽ
	P1PH  = 0xFF;
	P2CON = 0xFF;  //����P2Ϊǿ����ģʽ
	P2PH  = 0x00;
    SC92F7401_NIO_Init(); //δ����IO������
    #endif
}