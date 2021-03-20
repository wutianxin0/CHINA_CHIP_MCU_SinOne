#include"sc91F72B_C.h"			//include SC91F72B的头文件

/*===================
	  宏定义
=====================*/
#define COM1  P37			//定义P37为COM1		   
#define COM2  P20			//定义P20为COM2	
#define COM3  P21			//定义P21为COM3	
#define	Key_ADJUST	P10		//定义P10为按键调整，即Key_ADJUST
#define Key_SCREEN	P11		//
#define K_ADJUST	1
#define K_SCREEN	2

/*===================
	  变量定义
=====================*/
unsigned char i;				
unsigned char KeyValue;		//键值
unsigned char KeyBounce;	//消抖用	
unsigned char TusCounter;
unsigned char Handle_com;	//数码管COM口
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
void ADC_Convert(void);		//ADC转换

