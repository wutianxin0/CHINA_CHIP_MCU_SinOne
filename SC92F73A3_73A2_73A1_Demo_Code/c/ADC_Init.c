#include "H/Function_Init.H"

void ADC_Init(uint Channel,uchar ADCFreq);
unsigned int ADCValue = 0x0000;
bit AdcFlag = 0;
/***********ADC采样频率选择*************/
enum ADCFreq {F32=0,F24,F16,F12,F8,F6,F4,F3};

/***********ADC采样口选择*************/
#if (IC_MODEL == SC92F73A3)
enum Channel {AIN0=0,AIN1,AIN2,AIN3,AIN4,AIN5,AIN6,AIN7,AIN8,AIN9,VDD4=31};
#endif

#if (IC_MODEL == SC92F73A2)
enum Channel {AIN2=2,AIN3,AIN4,AIN5,AIN8=8,AIN9,VDD4=31};
#endif

#if (IC_MODEL == SC92F73A1)
enum Channel {AIN3=3,AIN4,AIN8=8,AIN9,VDD4=31};
#endif

/*****************************************************
*函数名称：void ADC_Test(void)
*函数功能：ADC测试
*入口参数：void
*出口参数：void
*****************************************************/
void ADC_Test(void)
{
	ADC_Init(AIN3,F8);
	while(1)
	{
		ADCCON |= 0X40;   //开始ADC转换
	    while(!AdcFlag);	         		 //等待 ADC转换完成;
		AdcFlag = 0;
	    ADCValue=(ADCVH<<4)+(ADCVL>>4);
	}
}
/*****************************************************
*函数名称：void ADC_Init(uint Channel,uchar ADCFreq)
*函数功能：ADC初始化
*入口参数：void
*出口参数：void
*****************************************************/
void ADC_Init(uint Channel,uchar ADCFreq)
{
	ADCCON = 0X80|Channel;		//开启ADC，ADC采样频率为2M ,选择Channel位ADC采样口
	if(Channel<8)
	{
		ADCCFG0 = 1<<Channel;   //设置Channel作为采样口
	}
	else
	{
		ADCCFG1 = 1<<(Channel-8);   //设置Channel作为采样口
	}
	ADCCFG2 = ADCFreq;
	IE |= 0X40;        //开启ADC中断
	EA = 1;
}


void ADC_Interrupt(void) interrupt 6
{
	ADCCON&=~(0X20);  //清中断标志位
	AdcFlag = 1;
}