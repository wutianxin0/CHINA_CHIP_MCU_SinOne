//************************************************************
//  Copyright (c) ��������Ԫ΢�������޹�˾
//	�ļ�����	: IO_Set.c
//	����		: 
//	ģ�鹦��	: IO��������
//	�ֲ������б�:
//  ����������:
// 	�汾		:
// 	���ļ�¼	:731 romǰ256byte��ֹ���,����ڱ����ʱ������keil->option for Target->BL51 Locate->Code Range:0x100
//*************************************************************
#include "h\sc91f731_C.h"
void main()
{
	RSTCFG=0X0B;
	WDTCR = 0x90;				//1--1 -- 00    ��WDT,WDT��0,WDT 524ms���;��¼ʱ����Code Optionѡ��ENWDT
	BUZTGPH=0X81;				//����BUZZER����
	BUZTGPL=0Xff;				//Ƶ�ʣ�16M/��BUZTCP[11��0]+1��=16M/��256+255+1��=3.125M
	while(1)
	{
		WDTCR = 0x90;				//1--1 -- 00    ��WDT,WDT��0,WDT 524ms���;��¼ʱ����Code Optionѡ��ENWDT
	}
}