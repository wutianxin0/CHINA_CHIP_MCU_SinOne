#include"sc91F72B_C.h"			//include SC91F72B��ͷ�ļ�

/*===================
	  �궨��
=====================*/
#define COM1  P37			//����P37ΪCOM1		   
#define COM2  P20			//����P20ΪCOM2	
#define COM3  P21			//����P21ΪCOM3	
#define	Key_ADJUST	P10		//����P10Ϊ������������Key_ADJUST
#define Key_SCREEN	P11		//
#define K_ADJUST	1
#define K_SCREEN	2

/*===================
	  ��������
=====================*/
unsigned char i;				
unsigned char KeyValue;		//��ֵ
unsigned char KeyBounce;	//������	
unsigned char TusCounter;
unsigned char Handle_com;	//�����COM��
unsigned char ValueL;
unsigned char ValueH;
unsigned char VALUE_1;
unsigned char VALUE_2;
unsigned char VALUE_3;
unsigned int ADC16;
unsigned int ADC_AVG;
float Checksum;
bit bdata	FLGms;
bit bdata	FLG;

void AD_Date_DIV(void);		//
void ADC_Convert(void);		//ADCת��

