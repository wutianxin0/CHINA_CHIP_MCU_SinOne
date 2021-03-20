//************************************************************
//  Copyright (c) ��������Ԫ΢�������޹�˾
//	�ļ�����	: IO_Set.c
//	����		: 
//	ģ�鹦��	: IO��������
//	�ֲ������б�:
//  ����������:
// 	�汾		:
// 	���ļ�¼	:729B romǰ256byte��ֹ���,����ڱ����ʱ������keil->option for Target->BL51 Locate->Code Range:0x100
//*************************************************************
#include "h\sc91f729B_C.h"

//============================
//ģ���ں궨��
//============================
#define		BS(SFR,NUM)		(SFR|=(1<<NUM))             //λ��1
#define		BC(SFR,NUM)		(SFR&=~(1<<NUM))		  //λ��0
//============================
//�������룬ʹ��׼˫��ģʽʱ����Ҫ�л�Ϊ׼˫��ģʽ�����Ը�IO��д1,�����ѡ��ǿ����ģʽ
//============================
#define		SET(SFR,NUM)	(SFR = NUM)	

//=========================P1��P2��P3  ׼˫��IO����=========================================//
#define		P10M					(BC(P1CFG0,0),BC(P1CFG0,1))							//����P10Ϊ׼˫��IO
#define		P11M					(BC(P1CFG0,2),BC(P1CFG0,3))							 //����P11Ϊ׼˫��IO
#define		P12M					(BC(P1CFG0,4),BC(P1CFG0,5))							//����P12Ϊ׼˫��IO
#define		P13M					(BC(P1CFG0,6),BC(P1CFG0,7))							//����P13Ϊ׼˫��IO
#define		P14M					(BC(P1CFG1,0),BC(P1CFG1,1))							//����P14Ϊ׼˫��IO
#define		P15M					(BC(P1CFG1,2),BC(P1CFG1,3))							 //����P15Ϊ׼˫��IO

#define		P32M					(BC(P3CFG0,4),BC(P3CFG0,5))							//����P32Ϊ׼˫��IO
#define		P33M					(BC(P3CFG0,6),BC(P3CFG0,7))							//����P33Ϊ׼˫��IO
#define		P34M					(BC(P3CFG1,0),BC(P3CFG1,1))							//����P34Ϊ׼˫��IO
#define		P35M					(BC(P3CFG1,2),BC(P3CFG1,3))							//����P35Ϊ׼˫��IO
#define		P36M					(BC(P3CFG1,4),BC(P3CFG1,5))							//����P36Ϊ׼˫��IO
#define		P37M					(BC(P3CFG1,6),BC(P3CFG1,7))							//����P37Ϊ׼˫��IO	

//=========================P1��P2��P3  ǿ����IO����=========================================//

#define		P10PM					(BS(P1CFG0,0),BC(P1CFG0,1))							//����P10Ϊǿ����IO
#define		P11PM					(BS(P1CFG0,2),BC(P1CFG0,3))							 //����P11Ϊǿ����IO
#define		P12PM					(BS(P1CFG0,4),BC(P1CFG0,5))							//����P12Ϊǿ����IO
#define		P13PM					(BS(P1CFG0,6),BC(P1CFG0,7))							//����P13Ϊǿ����IO
#define		P14PM					(BS(P1CFG1,0),BC(P1CFG1,1))							//����P14Ϊǿ����IO
#define		P15PM					(BS(P1CFG1,2),BC(P1CFG1,3))							 //����P15Ϊǿ����IO

#define		P32PM					(BS(P3CFG0,4),BC(P3CFG0,5))							//����P32Ϊǿ����IO
#define		P33PM					(BS(P3CFG0,6),BC(P3CFG0,7))							//����P33Ϊǿ����IO
#define		P34PM					(BS(P3CFG1,0),BC(P3CFG1,1))							//����P34Ϊǿ����IO
#define		P35PM					(BS(P3CFG1,2),BC(P3CFG1,3))							//����P35Ϊǿ����IO
#define		P36PM					(BS(P3CFG1,4),BC(P3CFG1,5))							//����P36Ϊǿ����IO
#define		P37PM					(BS(P3CFG1,6),BC(P3CFG1,7))							//����P37Ϊǿ����IO

//=========================P1��P2��P3  ����̬(������)IO����=========================================//

#define		P10IM					(BC(P1CFG0,0),BS(P1CFG0,1))							//����P10Ϊ����̬IO
#define		P11IM					(BC(P1CFG0,2),BS(P1CFG0,3))							 //����P11Ϊ����̬IO
#define		P12IM					(BC(P1CFG0,4),BS(P1CFG0,5))							//����P12Ϊ����̬IO
#define		P13IM					(BC(P1CFG0,6),BS(P1CFG0,7))							//����P13Ϊ����̬IO
#define		P14IM					(BC(P1CFG1,0),BS(P1CFG1,1))							//����P14Ϊ����̬IO
#define		P15IM					(BC(P1CFG1,2),BS(P1CFG1,3))							 //����P15Ϊ����̬IO

#define		P32IM					(BC(P3CFG0,4),BS(P3CFG0,5))							//����P32Ϊ����̬IO
#define		P33IM					(BC(P3CFG0,6),BS(P3CFG0,7))							//����P33Ϊ����̬IO
#define		P34IM					(BC(P3CFG1,0),BS(P3CFG1,1))							//����P34Ϊ����̬IO
#define		P35IM					(BC(P3CFG1,2),BS(P3CFG1,3))							//����P35Ϊ����̬IO
#define		P36IM					(BC(P3CFG1,4),BS(P3CFG1,5))							//����P36Ϊ����̬IO
#define		P37IM					(BC(P3CFG1,6),BS(P3CFG1,7))							//����P37Ϊ����̬IO

//=========================P1��P2��P3  ��©���IO����=========================================//

#define		P10OM					(BS(P1CFG0,0),BS(P1CFG0,1))							//����P10Ϊ��©���IO
#define		P11OM					(BS(P1CFG0,2),BS(P1CFG0,3))							 //����P11Ϊ��©���IO
#define		P12OM					(BS(P1CFG0,4),BS(P1CFG0,5))							//����P12Ϊ��©���IO
#define		P13OM					(BS(P1CFG0,6),BS(P1CFG0,7))							//����P13Ϊ��©���IO
#define		P14OM					(BS(P1CFG1,0),BS(P1CFG1,1))							//����P14Ϊ��©���IO
#define		P15OM					(BS(P1CFG1,2),BS(P1CFG1,3))							 //����P15Ϊ��©���IO

#define		P32OM					(BS(P3CFG0,4),BS(P3CFG0,5))							//����P32Ϊ��©���IO
#define		P33OM					(BS(P3CFG0,6),BS(P3CFG0,7))							//����P33Ϊ��©���IO
#define		P34OM					(BS(P3CFG1,0),BS(P3CFG1,1))							//����P34Ϊ��©���IO
#define		P35OM					(BS(P3CFG1,2),BS(P3CFG1,3))							//����P35Ϊ��©���IO
#define		P36OM					(BS(P3CFG1,4),BS(P3CFG1,5))							//����P36Ϊ��©���IO
#define		P37OM					(BS(P3CFG1,6),BS(P3CFG1,7))							//����P37Ϊ��©���IO

//=========================P1��P2��P3 ׼˫��IO��������=========================================//
#define		P10MI					(BC(P1CFG0,0),BC(P1CFG0,1),SET(P10,1))				//����P10Ϊ׼˫��IO����
#define		P11MI					(BC(P1CFG0,2),BC(P1CFG0,3),SET(P11,1))				//����P11Ϊ׼˫��IO����
#define		P12MI					(BC(P1CFG0,4),BC(P1CFG0,5),SET(P12,1))			 	//����P12Ϊ׼˫��IO����
#define		P13MI					(BC(P1CFG0,6),BC(P1CFG0,7),SET(P13,1))				//����P13Ϊ׼˫��IO����
#define		P14MI					(BC(P1CFG1,0),BC(P1CFG1,1),SET(P14,1))				//����P14Ϊ׼˫��IO����
#define		P15MI					(BC(P1CFG1,2),BC(P1CFG1,3),SET(P15,1))				//����P15Ϊ׼˫��IO����

#define		P32MI					(BC(P3CFG0,4),BC(P3CFG0,5),SET(P32,1))			 	//����P32Ϊ׼˫��IO����
#define		P33MI					(BC(P3CFG0,6),BC(P3CFG0,7),SET(P33,1))				//����P33Ϊ׼˫��IO����
#define		P34MI					(BC(P3CFG1,0),BC(P3CFG1,1),SET(P34,1))				//����P34Ϊ׼˫��IO����
#define		P35MI					(BC(P3CFG1,2),BC(P3CFG1,3),SET(P35,1))				//����P35Ϊ׼˫��IO����
#define		P36MI					(BC(P3CFG1,4),BC(P3CFG1,5),SET(P36,1))				//����P36Ϊ׼˫��IO����
#define		P37MI					(BC(P3CFG1,6),BC(P3CFG1,7),SET(P37,1))				//����P37Ϊ׼˫��IO����

//*************************************************************
// ������	��void main()
// ����		��
// ����		��������
// ����		����
// ����ֵ	����
// ����ȫ�ֱ�������
// �޸�ȫ�ֱ�������
// ��ע		��
//**************************************************************
void main()
{
	RSTCFG=0x0b;				//RSTpin�л�GPIO,lvr ѡ��3.5V��λ
	WDTCR = 0x90;				//1--1 -- 00    ��WDT,WDT��0,WDT 524.288ms���;��¼ʱ����Code Optionѡ��ENWDT
	P11MI;					   //��������
	P11PM;     				   //��ʾ���
	for(; ;);
}