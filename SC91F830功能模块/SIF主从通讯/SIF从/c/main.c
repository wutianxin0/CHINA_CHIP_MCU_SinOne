//************************************************************
//  Copyright (c) ��������Ԫ΢�������޹�˾
//	�ļ�����	: slave_8_1.c
//	����		: 
//	ģ�鹦��	: SIF slave 8+1���ա�������ģ��
//	�ֲ������б�:
//  ����������:
// 	�汾		:
// 	���ļ�¼	: 
//*************************************************************
#include "H\SC91F830_C.H"
#include "H\Slave_8_1.H"

//=====================================
//������Ҫ���õ�ȫ�ֱ���
//=====================================

unsigned char Sif_Send_dat ;	//�ӻ����͵�����
unsigned char Sif_Rece_dat;		//�ӻ����յ�����
unsigned char Sif_Send_dat_1;
unsigned char Sif_Send_dat_2;
unsigned char Sif_Send_dat_3;
unsigned char Sif_Rec_dat_1 ;
unsigned char Sif_Rec_dat_2 ;
unsigned char Sif_Rec_dat_3 ;

unsigned char Rece_Date_Cnt;	 //�������ݱ�־ 
unsigned char Send_Date_Cnt;

//*************************************************************
// ������	��void main()
// ����		��
// ����		��SIF ��ģʽ��������
// ����		����
// ����ֵ	����
// ����ȫ�ֱ�������
// �޸�ȫ�ֱ�������
// ��ע		��
//**************************************************************
void main()
{
	RSTCFG = 0x20;
	sif_init();
//	Sif_Send_dat_1 = 0x31;
//	Sif_Send_dat_2 = 0x13;
//	Sif_Send_dat_3 = 0x51;
//	Sif_Send_dat = 0x31;
	EA = 1;						//�����ж�
	for(; ; )
	{
		
	}
}