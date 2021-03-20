//************************************************************
//  Copyright (c) ��������Ԫ΢�������޹�˾
//	�ļ�����	: master_8_1.c
//	����		: 
//	ģ�鹦��	: SIF master 8+1��дͨѶ
//	�ֲ������б�:
//  ����������:
// 	�汾		:
// 	���ļ�¼	:SIF master ����date,�ٽ���slave��date,������ɣ�����Noack,����stop
//*************************************************************
#include "H\SC91F831_C.H"
#include "H\Master_8_1.H"

//============================
//��̬�ֲ���������
//============================

static	unsigned char send_dat_buff[3]={0x31,0x5a,0xa5};
static	unsigned char receive_dat_buff[3]={0x00,0x00,0x00};

//============================
//ģ���ڳ�������
//============================

#define	false					0
#define	ture					1


//============================
//�ڲ���������
//============================
bit Sif_Writ_Read_Byte(void);
void I2C_Usdelay(unsigned int delay);

//******************************************************************
// ������	��void I2C_Usdelay(unsigned int delay)
// ����		��
// ����		��ͨ����ʱ����
// ����		����
// ����ֵ	����
// ����ȫ�ֱ�������
// �޸�ȫ�ֱ�������
// ��ע		��
//******************************************************************
void I2C_Usdelay(unsigned int delay)
{
	while(delay)
	{
		delay--;
	}
}
//*************************************************************
// ������	��void Sif_Read_Writ_Byte(void))
// ����		��
// ����		�����ֽڶ�д������������д���
// ����		����
// ����ֵ	��0/1
// ����ȫ�ֱ�������
// �޸�ȫ�ֱ�������
// ��ע		��		  
//**************************************************************
bit Sif_Writ_Read_Byte(void)
{
	send_start();
	send_byte(send_dat_buff[0]);			//����1byte-> send_dat_buff[0]
	if(!sif_waitack())						//�ж��Ƿ�����Ӧ,���û����Ӧ������Stop
		{
			send_stop();
			I2C_Usdelay(50);				//��������׼��
			return	(false);			
		}
	 sif_noack();							//���üĴ���������������Ӧ��
	 receive_dat_buff[0]=receive_byte();	//��ȡ1byte,�ֽڴ���receive_dat_buff[0]	 
	 send_stop();							//����ֹͣ�ź�
	 I2C_Usdelay(50);						//��������׼��
	 return	(ture);
}
void main()
{
	RSTCFG = 0x20;
	sif_init();						  //SIF��ʼ��
	for(;;)
	{			
		Sif_Writ_Read_Byte();		//��д���	
	}
}