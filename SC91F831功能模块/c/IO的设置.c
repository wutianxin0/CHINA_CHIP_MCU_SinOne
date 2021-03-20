//************************************************************
//  Copyright (c) ��������Ԫ΢�������޹�˾
//	�ļ�����	: IO_Set.c
//	����		: 
//	ģ�鹦��	: IO��������
//	�ֲ������б�:
//  ����������:
// 	�汾		:
// 	���ļ�¼	:831 romǰ256byte��ֹ���,����ڱ����ʱ������keil->option for Target->BL51 Locate->Code Range:0x100
//*************************************************************
#include "h\sc91f831_C.h"

//============================
//ģ���ں궨��
//============================
#define		BS(SFR,NUM)		(SFR|=(1<<NUM))             //λ��1
#define		BC(SFR,NUM)		(SFR&=~(1<<NUM))		    //λ��0
//============================
//�������룬ʹ��׼˫��ģʽʱ����Ҫ�л�Ϊ׼˫��ģʽ�����Ը�IO��д1,�����ѡ��ǿ����ģʽ
//============================
#define		SET(SFR,NUM)	(SFR = NUM)	

//=========================P1��P2��P3��P4 ׼˫��IO����=========================================//
#define		P10M					(BC(P1CFG0,0),BC(P1CFG0,1))							//����P10Ϊ׼˫��IO
#define		P11M					(BC(P1CFG0,2),BC(P1CFG0,3))							//����P11Ϊ׼˫��IO
#define		P12M					(BC(P1CFG0,4),BC(P1CFG0,5))							//����P12Ϊ׼˫��IO
#define		P13M					(BC(P1CFG0,6),BC(P1CFG0,7))							//����P13Ϊ׼˫��IO
#define		P14M					(BC(P1CFG1,0),BC(P1CFG1,1))							//����P14Ϊ׼˫��IO
#define		P15M					(BC(P1CFG1,2),BC(P1CFG1,3))							//����P15Ϊ׼˫��IO
#define		P16M					(BC(P1CFG1,4),BC(P1CFG1,5))							//����P16Ϊ׼˫��IO
#define		P17M					(BC(P1CFG1,6),BC(P1CFG1,7))							//����P17Ϊ׼˫��IO

#define		P20M					(BC(P2CFG0,0),BC(P2CFG0,1))							//����P20Ϊ׼˫��IO
#define		P21M					(BC(P2CFG0,2),BC(P2CFG0,3))							//����P21Ϊ׼˫��IO
#define		P22M					(BC(P2CFG0,4),BC(P2CFG0,5))							//����P22Ϊ׼˫��IO
#define		P23M					(BC(P2CFG0,6),BC(P2CFG0,7))							//����P23Ϊ׼˫��IO
#define		P24M					(BC(P2CFG1,0),BC(P2CFG1,1))							//����P24Ϊ׼˫��IO
#define		P25M					(BC(P2CFG1,2),BC(P2CFG1,3))							//����P25Ϊ׼˫��IO
#define		P26M					(BC(P2CFG1,4),BC(P2CFG1,5))							//����P26Ϊ׼˫��IO
#define		P27M					(BC(P2CFG1,6),BC(P2CFG1,7))							//����P27Ϊ׼˫��IO

#define		P30M					(BC(P3CFG0,0),BC(P3CFG0,1))							//����P30Ϊ׼˫��IO
#define		P31M					(BC(P3CFG0,2),BC(P3CFG0,3))							//����P31Ϊ׼˫��IO
#define		P32M					(BC(P3CFG0,4),BC(P3CFG0,5))							//����P32Ϊ׼˫��IO
#define		P33M					(BC(P3CFG0,6),BC(P3CFG0,7))							//����P33Ϊ׼˫��IO
#define		P34M					(BC(P3CFG1,0),BC(P3CFG1,1))							//����P34Ϊ׼˫��IO
#define		P35M					(BC(P3CFG1,2),BC(P3CFG1,3))							//����P35Ϊ׼˫��IO
#define		P36M					(BC(P3CFG1,4),BC(P3CFG1,5))							//����P36Ϊ׼˫��IO
#define		P37M					(BC(P3CFG1,6),BC(P3CFG1,7))							//����P37Ϊ׼˫��IO

#define		P40M					(BC(P4CFG0,0),BC(P4CFG0,1))							//����P40Ϊ׼˫��IO
#define		P41M					(BC(P4CFG0,2),BC(P4CFG0,3))							//����P41Ϊ׼˫��IO

//=========================P1��P2��P3��P4  ǿ����IO����=========================================//

#define		P10PM					(BS(P1CFG0,0),BC(P1CFG0,1))							//����P10Ϊǿ����IO
#define		P11PM					(BS(P1CFG0,2),BC(P1CFG0,3))							//����P11Ϊǿ����IO
#define		P12PM					(BS(P1CFG0,4),BC(P1CFG0,5))							//����P12Ϊǿ����IO
#define		P13PM					(BS(P1CFG0,6),BC(P1CFG0,7))							//����P13Ϊǿ����IO
#define		P14PM					(BS(P1CFG1,0),BC(P1CFG1,1))							//����P14Ϊǿ����IO
#define		P15PM					(BS(P1CFG1,2),BC(P1CFG1,3))							//����P15Ϊǿ����IO
#define		P16PM					(BS(P1CFG1,4),BC(P1CFG1,5))							//����P16Ϊǿ����IO
#define		P17PM					(BS(P1CFG1,6),BC(P1CFG1,7))							//����P17Ϊǿ����IO

#define		P20PM					(BS(P2CFG0,0),BC(P2CFG0,1))							//����P20Ϊǿ����IO
#define		P21PM					(BS(P2CFG0,2),BC(P2CFG0,3))							//����P21Ϊǿ����IO
#define		P22PM					(BS(P2CFG0,4),BC(P2CFG0,5))							//����P22Ϊǿ����IO
#define		P23PM					(BS(P2CFG0,6),BC(P2CFG0,7))							//����P23Ϊǿ����IO
#define		P24PM					(BS(P2CFG1,0),BC(P2CFG1,1))							//����P24Ϊǿ����IO
#define		P25PM					(BS(P2CFG1,2),BC(P2CFG1,3))							//����P25Ϊǿ����IO
#define		P26PM					(BS(P2CFG1,4),BC(P2CFG1,5))							//����P26Ϊǿ����IO
#define		P27PM					(BS(P2CFG1,6),BC(P2CFG1,7))							//����P27Ϊǿ����IO

#define		P30PM					(BS(P3CFG0,0),BC(P3CFG0,1))							//����P30Ϊǿ����IO
#define		P31PM					(BS(P3CFG0,2),BC(P3CFG0,3))							//����P31Ϊǿ����IO
#define		P32PM					(BS(P3CFG0,4),BC(P3CFG0,5))							//����P32Ϊǿ����IO
#define		P33PM					(BS(P3CFG0,6),BC(P3CFG0,7))							//����P33Ϊǿ����IO
#define		P34PM					(BS(P3CFG1,0),BC(P3CFG1,1))							//����P34Ϊǿ����IO
#define		P35PM					(BS(P3CFG1,2),BC(P3CFG1,3))							//����P35Ϊǿ����IO
#define		P36PM					(BS(P3CFG1,4),BC(P3CFG1,5))							//����P36Ϊǿ����IO
#define		P37PM					(BS(P3CFG1,6),BC(P3CFG1,7))							//����P37Ϊǿ����IO

#define		P40PM					(BS(P4CFG0,0),BC(P4CFG0,1))							//����P40Ϊǿ����IO
#define		P41PM					(BS(P4CFG0,2),BC(P4CFG0,3))							//����P41Ϊǿ����IO

//=========================P1��P2��P3��P4  ����̬(������)IO����=========================================//

#define		P10IM					(BC(P1CFG0,0),BS(P1CFG0,1))							//����P10Ϊ����̬IO
#define		P11IM					(BC(P1CFG0,2),BS(P1CFG0,3))							//����P11Ϊ����̬IO
#define		P12IM					(BC(P1CFG0,4),BS(P1CFG0,5))							//����P12Ϊ����̬IO
#define		P13IM					(BC(P1CFG0,6),BS(P1CFG0,7))							//����P13Ϊ����̬IO
#define		P14IM					(BC(P1CFG1,0),BS(P1CFG1,1))							//����P14Ϊ����̬IO
#define		P15IM					(BC(P1CFG1,2),BS(P1CFG1,3))							//����P15Ϊ����̬IO
#define		P16IM					(BC(P1CFG1,4),BS(P1CFG1,5))							//����P16Ϊ����̬IO
#define		P17IM					(BC(P1CFG1,6),BS(P1CFG1,7))							//����P17Ϊ����̬IO

#define		P20IM					(BC(P2CFG0,0),BS(P2CFG0,1))							//����P20Ϊ����̬IO
#define		P21IM					(BC(P2CFG0,2),BS(P2CFG0,3))							//����P21Ϊ����̬IO
#define		P22IM					(BC(P2CFG0,4),BS(P2CFG0,5))							//����P22Ϊ����̬IO
#define		P23IM					(BC(P2CFG0,6),BS(P2CFG0,7))							//����P23Ϊ����̬IO
#define		P24IM					(BC(P2CFG1,0),BS(P2CFG1,1))							//����P24Ϊ����̬IO
#define		P25IM					(BC(P2CFG1,2),BS(P2CFG1,3))							//����P25Ϊ����̬IO
#define		P26IM					(BC(P2CFG1,4),BS(P2CFG1,5))							//����P26Ϊ����̬IO
#define		P27IM					(BC(P2CFG1,6),BS(P2CFG1,7))							//����P27Ϊ����̬IO

#define		P30IM					(BC(P3CFG0,0),BS(P3CFG0,1))							//����P30Ϊ����̬IO
#define		P31IM					(BC(P3CFG0,2),BS(P3CFG0,3))							//����P31Ϊ����̬IO
#define		P32IM					(BC(P3CFG0,4),BS(P3CFG0,5))							//����P32Ϊ����̬IO
#define		P33IM					(BC(P3CFG0,6),BS(P3CFG0,7))							//����P33Ϊ����̬IO
#define		P34IM					(BC(P3CFG1,0),BS(P3CFG1,1))							//����P34Ϊ����̬IO
#define		P35IM					(BC(P3CFG1,2),BS(P3CFG1,3))							//����P35Ϊ����̬IO
#define		P36IM					(BC(P3CFG1,4),BS(P3CFG1,5))							//����P36Ϊ����̬IO
#define		P37IM					(BC(P3CFG1,6),BS(P3CFG1,7))							//����P37Ϊ����̬IO

#define		P40IM					(BC(P4CFG0,0),BS(P4CFG0,1))							//����P40Ϊ����̬IO
#define		P41IM					(BC(P4CFG0,2),BS(P4CFG0,3))							//����P41Ϊ����̬IO

//=========================P1��P2��P3��P4  ��©���IO����=========================================//

#define		P10OM					(BS(P1CFG0,0),BS(P1CFG0,1))							//����P10Ϊ��©���IO
#define		P11OM					(BS(P1CFG0,2),BS(P1CFG0,3))							//����P11Ϊ��©���IO
#define		P12OM					(BS(P1CFG0,4),BS(P1CFG0,5))							//����P12Ϊ��©���IO
#define		P13OM					(BS(P1CFG0,6),BS(P1CFG0,7))							//����P13Ϊ��©���IO
#define		P14OM					(BS(P1CFG1,0),BS(P1CFG1,1))							//����P14Ϊ��©���IO
#define		P15OM					(BS(P1CFG1,2),BS(P1CFG1,3))							//����P15Ϊ��©���IO
#define		P16OM					(BS(P1CFG1,4),BS(P1CFG1,5))							//����P16Ϊ��©���IO
#define		P17OM					(BS(P1CFG1,6),BS(P1CFG1,7))							//����P17Ϊ��©���IO

#define		P20OM					(BS(P2CFG0,0),BS(P2CFG0,1))							//����P20Ϊ��©���IO
#define		P21OM					(BS(P2CFG0,2),BS(P2CFG0,3))							//����P21Ϊ��©���IO
#define		P22OM					(BS(P2CFG0,4),BS(P2CFG0,5))							//����P22Ϊ��©���IO
#define		P23OM					(BS(P2CFG0,6),BS(P2CFG0,7))							//����P23Ϊ��©���IO
#define		P24OM					(BS(P2CFG1,0),BS(P2CFG1,1))							//����P24Ϊ��©���IO
#define		P25OM					(BS(P2CFG1,2),BS(P2CFG1,3))							//����P25Ϊ��©���IO
#define		P26OM					(BS(P2CFG1,4),BS(P2CFG1,5))							//����P26Ϊ��©���IO
#define		P27OM					(BS(P2CFG1,6),BS(P2CFG1,7))							//����P27Ϊ��©���IO

#define		P30OM					(BS(P3CFG0,0),BS(P3CFG0,1))							//����P30Ϊ��©���IO
#define		P31OM					(BS(P3CFG0,2),BS(P3CFG0,3))							//����P31Ϊ��©���IO
#define		P32OM					(BS(P3CFG0,4),BS(P3CFG0,5))							//����P32Ϊ��©���IO
#define		P33OM					(BS(P3CFG0,6),BS(P3CFG0,7))							//����P33Ϊ��©���IO
#define		P34OM					(BS(P3CFG1,0),BS(P3CFG1,1))							//����P34Ϊ��©���IO
#define		P35OM					(BS(P3CFG1,2),BS(P3CFG1,3))							//����P35Ϊ��©���IO
#define		P36OM					(BS(P3CFG1,4),BS(P3CFG1,5))							//����P36Ϊ��©���IO
#define		P37OM					(BS(P3CFG1,6),BS(P3CFG1,7))							//����P37Ϊ��©���IO

#define		P40OM					(BS(P4CFG0,0),BS(P4CFG0,1))							//����P40Ϊ��©���IO
#define		P41OM					(BS(P4CFG0,2),BS(P4CFG0,3))							//����P41Ϊ��©���IO

//=========================P1��P2��P3��P4  ׼˫��IO��������=========================================//
#define		P10MI					(BC(P1CFG0,0),BC(P1CFG0,1),SET(P10,1))				//����P10Ϊ׼˫��IO����
#define		P11MI					(BC(P1CFG0,2),BC(P1CFG0,3),SET(P11,1))				//����P11Ϊ׼˫��IO����
#define		P12MI					(BC(P1CFG0,4),BC(P1CFG0,5),SET(P12,1))			 	//����P12Ϊ׼˫��IO����
#define		P13MI					(BC(P1CFG0,6),BC(P1CFG0,7),SET(P13,1))				//����P13Ϊ׼˫��IO����
#define		P14MI					(BC(P1CFG1,0),BC(P1CFG1,1),SET(P14,1))				//����P14Ϊ׼˫��IO����
#define		P15MI					(BC(P1CFG1,2),BC(P1CFG1,3),SET(P15,1))				//����P15Ϊ׼˫��IO����
#define		P16MI					(BC(P1CFG1,4),BC(P1CFG1,5),SET(P16,1))				//����P16Ϊ׼˫��IO����
#define		P17MI					(BC(P1CFG1,6),BC(P1CFG1,7),SET(P17,1))				//����P17Ϊ׼˫��IO����

#define		P20MI					(BC(P2CFG0,0),BC(P2CFG0,1),SET(P20,1))				//����P20Ϊ׼˫��IO����
#define		P21MI					(BC(P2CFG0,2),BC(P2CFG0,3),SET(P21,1))				//����P21Ϊ׼˫��IO����
#define		P22MI					(BC(P2CFG0,4),BC(P2CFG0,5),SET(P22,1))			 	//����P22Ϊ׼˫��IO����
#define		P23MI					(BC(P2CFG0,6),BC(P2CFG0,7),SET(P23,1))				//����P23Ϊ׼˫��IO����
#define		P24MI					(BC(P2CFG1,0),BC(P2CFG1,1),SET(P24,1))				//����P24Ϊ׼˫��IO����
#define		P25MI					(BC(P2CFG1,2),BC(P2CFG1,3),SET(P25,1))				//����P25Ϊ׼˫��IO����
#define		P26MI					(BC(P2CFG1,4),BC(P2CFG1,5),SET(P26,1))				//����P26Ϊ׼˫��IO����
#define		P27MI					(BC(P2CFG1,6),BC(P2CFG1,7),SET(P27,1))				//����P27Ϊ׼˫��IO����

#define		P30MI					(BC(P3CFG0,0),BC(P3CFG0,1),SET(P30,1))				//����P30Ϊ׼˫��IO����
#define		P31MI					(BC(P3CFG0,2),BC(P3CFG0,3),SET(P31,1))				//����P31Ϊ׼˫��IO����
#define		P32MI					(BC(P3CFG0,4),BC(P3CFG0,5),SET(P32,1))			 	//����P32Ϊ׼˫��IO����
#define		P33MI					(BC(P3CFG0,6),BC(P3CFG0,7),SET(P33,1))				//����P33Ϊ׼˫��IO����
#define		P34MI					(BC(P3CFG1,0),BC(P3CFG1,1),SET(P34,1))				//����P34Ϊ׼˫��IO����
#define		P35MI					(BC(P3CFG1,2),BC(P3CFG1,3),SET(P35,1))				//����P35Ϊ׼˫��IO����
#define		P36MI					(BC(P3CFG1,4),BC(P3CFG1,5),SET(P36,1))				//����P36Ϊ׼˫��IO����
#define		P37MI					(BC(P3CFG1,6),BC(P3CFG1,7),SET(P37,1))				//����P37Ϊ׼˫��IO����

#define		P40MI					(BC(P4CFG0,0),BC(P4CFG0,1),SET(P40,1))				//����P40Ϊ׼˫��IO����
#define		P41MI					(BC(P4CFG0,2),BC(P4CFG0,3),SET(P41,1))				//����P41Ϊ׼˫��IO����

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
	RSTCFG=0x2A;				//RSTpin�л�GPIO,lvr ѡ��3.5V��λ
	WDTCR = 0x90;				//1--1 -- 00    ��WDT,WDT��0,WDT 262ms���;��¼ʱ����Code Optionѡ��ENWDT
	P12MI;					   //��������
	P12PM;     				   //��ʾ���
	while(1)
	{
		WDTCR = 0x90;				//1--1 -- 00    ��WDT,WDT��0,WDT 262ms���;��¼ʱ����Code Optionѡ��ENWDT
	}
}