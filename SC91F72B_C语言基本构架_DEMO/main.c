/*******************************************************
项目： SC91F72B Demo code C语言的基本构架；
*******************************************************/
#include"sc91F72B_C.h"				//include进MCU的头文件
#include "Hex2Bin.h"				//include进十六进制对应二进制的头文件

/*===================
	  宏定义
=====================*/
#define  uchar  unsigned char 		//无符号char类型
#define  uint   unsigned int 		//无符号int类型

/*===================
	  变量定义
=====================*/					
unsigned char TusCounter;
uchar 		ValueL;
uchar 		ValueH;
uint	 	ADC16;
uint 		ADC_AVG;
float	 	Checksum;				//浮点类型
bit bdata	FLGms;					//位变量
bit bdata	FLG;					//位变量

unsigned char code LEDTABLE[ ]={	//定义一个数组，常量类型（不可变类型），把数组定义在Flash ROM
0xC0,0xf9,0x24,0x70,0x59,0x52,0x42,
0xf8,0x40,0x50,0x48,0x43,0xc6,0x61,
0x46,0x4e};

void IO_init();						//各子函数原型；
void timer0_init(void);				//在定义各个子函数前，把所有子函数先声明；
void timer1_init(void);				//该步骤不是必须的，不过建议养成这个好习惯。
void INT_init();					
void ADC_init(void);
void PWM_init();
void PWM_set();


/*===================
	GPIO的初始化
=====================*/
void IO_init()						//GPIO的各个模式，各个状态，视乎产品具体功能决定，以下举例，仅供参考
{
	P1CFG1=_b00000000;				//PxCFGx为GPIO模式配置寄存器，上电默认为准双向模式
	P1CFG0=_b01010101;				//将P10、P11、P12、P13都设为强推挽模式
	P2CFG0=_b10101010;				//将P20、P21都设为高阻输入模式
	P3CFG1=_b10101010; 				//将P34、P35、P36、P37都设高阻输入模式
	P3CFG0=_b01010101;			  	//将P30、P31、P32、P33都设强推挽模式

	P1=0;							//譬如讲P1设为0，（由产品功能决定）
	P2=0;							//譬如讲P2设为0，（由产品功能决定）
	P3=_b11111111;					//譬如讲P3设为， （由产品功能决定）
}

/*===================
	定时器0程序区
=====================*/
void timer0_init(void)
{
	TMCON=0x01;						//定时器timer0的时钟频率选择为Fosc/4
	TMOD=0x02;						//timer0选择自动重载模式
	TL0=(256-200);		   			//定时50uS
	TH0=(256-200);		

	TR0=0;							//定时器T0的运行控制位。打开timer0前，先清TR0
	ET0=1;							//允许timer0中断
	TR0=1;							//允许timer0开始计数	
}

/*===================
	定时器1程序区
=====================*/
void timer1_init(void)
{
	TMCON=0x03;						//定时器timer1的时钟频率选择为Fosc/4（timer0的时钟频率也选择为Fosc/4）
	TMOD=0x22;						//timer1选择自动重载模式 (timer0选择自动重载模式)
	TL1=(256-200);		   			//定时50uS
	TH1=(256-200);		

	TR1=0;							//定时器T1的运行控制位。打开timer1前，先清TRO
	ET1=1;							//允许timer1中断
	TR1=1;							//允许timer1开始计数	
}

/*===================
 外部中断初始化程序区
=====================*/
void INT_init()
{
	EXIE=_b00000001;				//只允许外部中断INT0发生中断
	EXIP=_b00000000;				//外部中断优先权选择
	INT4IT=_b00000010;				//外部中断类型选择为：双沿中断（即上升沿中断，下降沿中断）
}

/*===================
  AD转化初始化程序区
=====================*/
void ADC_init(void)
{
	ADCCFG=0x00;					//VDD作参考电压
	P3ADC=0x01;						//P3.0作ADC输入口
	ADCCR=0x60;						//011000000, Fosc/6,打开ADC电源
}

/*===================
    PWM初始化程序区
=====================*/
void PWM_init()
{
  	PWMCR=_b00000101;				//P1.1设为PWM1的输出；P1.2设为PWM0的输出;PWM波形不强制输出为高（DTY08=DTY18=0）.
  	PWMCFG=_b00000111;				//设置PWM时钟为Fosc/256，即fosc每32个clock，PWM计算器加1；
                    				//PWM的输出不反向（INV0=INV1=0）；
  	PWMPRD=255;						//即将PWM输出为（周期-1）*PWM时钟，也即PWM时钟周期为256个PWM时钟。
  	PWMDTY0=128;					//PWM0的占空比长度为128，128:256=1:2;
  	PWMDTY1=128;					//PWM1的占空比长度为128，128:256=1:2；
}

/*===================
    PWM功能程序区
=====================*/
void PWM_set()	
{	
  	 ENPWM=1;						//打开PWM模块，允许Clock进到PWM单元，开始PWM的工作。
	 EPWM=0;						//PWM中断使能，若EPWM=1即打开PWM中断使能
} 

/*===================
     AD转换程序区
=====================*/
void  ADC_Convert(void)				// ADC转换，无返回值
{	
	unsigned char i;
	Checksum=0;						//每次开始采样前，Checksum清0
	for(i=0;i<10;i++)				//ADC采样循环做10次，
	{												
		ADCCR |= 0x88;	   			//开启ADC模块电源,ADCS置1，开始ADC转换
		while(!(ADCCR&0x10));		//判断ADC是否转换完毕
	
		ValueH=ADCVH;		   		//ADC高8位存入8位寄存器
		ValueL=ADCVL;		   		//ADC低2位存入8位寄存器
	
		ADCCR &= 0xEF;   			//ADC转换完毕，清EOC	
		ADCCR &= 0x7F; 	 			//关闭ADC

		/*将10位ADC存入16bit register*/
		ADC16=ValueH<<8|ValueL<<6;	//2个8位寄存器合并为16位寄存器
		ADC16>>=6;					//获得10bitADC值
	 	Checksum +=ADC16;
	}			 
	
	ADC_AVG=Checksum/10;			//ADC采样，取平均值
}

/*===================
 定时器0中断服务程序区
=====================*/
void timer0()interrupt 1
{	
	TusCounter++;
	if(TusCounter==100)	 			//50us*100=5ms
	{
		TusCounter=0;
		FLGms=1;
	}
}

/*===================
 定时器1中断服务程序区
=====================*/
void timer1()interrupt 3
{
}

/*===================
 PWM中断服务程序区
=====================*/
void PWM()interrupt 5
{
}

/*===================
  ADC中断服务程序区
=====================*/
void ADC()interrupt 6
{
}

/*===================
  外部中断服务程序区
=====================*/
void INT0()interrupt 7				//外部中断0
{
}
void INT1()interrupt 8				//外部中断1
{
}
void INT2()interrupt 9				//外部中断2
{
}
void INT3()interrupt 10				//外部中断3
{
}
void INT4()interrupt 11				//外部中断4
{
}
void INT5()interrupt 12				//外部中断5
{
}
void INT6()interrupt 13				//外部中断6
{
}
void INT7()interrupt 14				//外部中断7
{
}


/******************************
		主函数程序区
*******************************/
void main()
{						
	/******系统初始化***********
	****************/
	RSTCFG=_b00001011;				//P1.0需切换为IO口。LVR（低电复位）设为3.5V
	WDTCR=0x90;						//打开看门狗，设WDTCKS[1:0]=00，即在524.288ms内要喂狗一次（建议做法）
	/****************
	*******以上是系统初始化****/


	/***产品功能模块的初始化***/
	/******譬如以下的函数******/
	IO_init();
	timer0_init(); 					//timer0初始化
	ADC_init(); 					//ADC初始化
	PWM_init();						//PWM初始化
    /***************************
	以上是产品功能模块的初始化*/

	EA=1;							//开总中断

	/***打开MCU某一功能函数***/
	/******譬如PWM_set()******/
	PWM_set();						//打开PWM模块，开始PWM的工作

	do{
	   WDTCR=0x90;					//WDTCKS[1:0]=00，即在524.288ms内喂狗(建议做法)

	   /************** ****************************
	   ************插入其他代码，函数等************
	   ***譬如以上的ADC_Convert(),或是其他函数等***	  
	   ***************** *************************/
	   ADC_Convert();
	}while(1);
	
}