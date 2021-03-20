#include "H/Function_Init.H"

void ADC_Init(uint Channel);
unsigned int ADCValue = 0x0000;
bit AdcFlag = 0;

/***********ADC采样口选择*************/
#if (IC_MODEL == SC92F7402)
    enum Channel {AIN0=0,AIN1,AIN2,AIN3,AIN4,AIN5,AIN6,VDD4=31};
#endif
    
#if (IC_MODEL == SC92F7401)
    enum Channel {AIN0=0,AIN1,AIN4=4,AIN5,AIN6,VDD4=31};
#endif
    
/*****************************************************
*函数名称：void ADC_Test(void)
*函数功能：ADC测试
*入口参数：void
*出口参数：void
*****************************************************/
void ADC_Test(void)
{
	ADC_Init(AIN6);
	while(1)
	{
		ADCCON |= 0X40;   //开始ADC转换
	    while(!AdcFlag);	//等待 ADC转换完成;
		AdcFlag = 0;
	    ADCValue=(ADCVH<<4)+(ADCVL>>4);  //ADC采样值
	}
}
/*****************************************************
*函数名称：void ADC_Init(uint Channel)
*函数功能：ADC初始化
*入口参数：Channel
*出口参数：void
*****************************************************/
void ADC_Init(uint Channel)
{
	ADCCON = 0X80|Channel;		//开启ADC,选择Channel位ADC采样口
	if(Channel<8)
	{
		ADCCFG0 = 1<<Channel;   //设置Channel作为采样口
	}
	ADCCFG1 = 0x04;           //设置ADC时钟频率为Fosc/8
	IE |= 0X40;                //开启ADC中断
	EA = 1;
}


void ADC_Interrupt(void) interrupt 6
{
	ADCCON&=~(0X20);  //清中断标志位
	AdcFlag = 1;
}