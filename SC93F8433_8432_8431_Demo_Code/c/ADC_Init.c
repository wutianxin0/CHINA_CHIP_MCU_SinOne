#include "H/Function_Init.H"

void ADC_Init(uint Channel);
void Delay(uint time);
uchar Read_IFB_Data(uchar AddOffset);
uint ADCValue = 0x0000;
uint AD_TS25H = 0x00;
uint AD_TS25L = 0x00;
bit AdcFlag = 0x00;
unsigned char code *POINT=0x0000 ;	//定义一个指针

/***********ADC采样口选择*************/
#if (IC_MODEL == SC93F8433)
	enum Channel {AIN0=0,AIN1,AIN2,AIN3,AIN4,AIN5,AIN6,AIN7,AIN8,AIN9,TS_AIN=14,VDD4};
#endif

#if (IC_MODEL == SC93F8432)
	enum Channel {AIN2=2,AIN3,AIN4,AIN5,AIN8=8,AIN9,TS_AIN=14,VDD4};
#endif
	
#if (IC_MODEL == SC93F8431)
	enum Channel {AIN3=3,AIN4,AIN8=8,AIN9,TS_AIN=14,VDD4};
#endif

/****************************************
*函数名称：void ADC_Test(void)
*函数功能：ADC测试
*入口参数：void
*出口参数：void
****************************************/
void ADC_Test(void)
{
    ADC_Init(AIN4);
    while(1)
    {
        AD_TS25H = Read_IFB_Data(0x3E);      //读取IC在25°时的温度值（高位）
	    AD_TS25L = Read_IFB_Data(0x3F);      //读取IC在25°时的温度值（低位）
        
        ADCCON |= 0X40;                      //开始ADC转换
	    while(!(AdcFlag));	         		 //等待 ADC转换完成;
        AdcFlag = 0;
        ADCValue = ADCVH;
        ADCValue = (ADCValue<<4)+(ADCVL>>4);      
    }
}

/*****************************************************
*函数名称：void ADC_Init(void)
*函数功能：ADC初始化
*入口参数：Channel
*出口参数：void
*****************************************************/
void ADC_Init(uint Channel)
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
	IE |= 0X40;        //开启ADC中断
	EA = 1;
}

/*****************************************************
*函数名称：void ADC_Interrupt(void) interrupt 6
*函数功能：ADC中断函数
*入口参数：void
*出口参数：void
*****************************************************/
void ADC_Interrupt(void) interrupt 6
{
	ADCCON &= ~(0X10);  //清中断标志位
	AdcFlag = 1;
}

/*****************************************************
*函数名称：void ADC_TS_Test(void)
*函数功能：ADC采集温度传感器电压值
*入口参数：void
*出口参数：void
*注意：测试温度时，ADC参考电压要用2.4V
*****************************************************/
void ADC_TS_Test(void)
{
	uint AD_TS0=0,AD_TS1=0,AD_TSSUM=0;
	
	ADCCON = 0x8E;		//开启ADC，ADC采样频率为2M ,ADC输入为温度传感器输出
	ADCCFG0 = 0x00;   //
	ADCCFG1 = 0X00;   //
    TSCFG = 0X80;     //使能温度传感器   
	while(1)
	{	
        Delay(5);
        TSCFG &= 0xFE;
		ADCCON |= 0x40;   //开始ADC转换		
		while(!(ADCCON&0x10));
		ADCCON &= 0xEF;   //清中断标志位
        AD_TS0 = ADCVH;
		AD_TS0 = (AD_TS0<<4)+(ADCVL>>4);  //第一次温度传感器数值
		
		TSCFG |= 0X01;
		ADCCON |= 0x40;   //开始ADC转换		
		while(!(ADCCON&0x10));
		ADCCON &= 0xEF;   //清中断标志位
        AD_TS1 = ADCVH;
		AD_TS1 = (AD_TS1<<4)+(ADCVL>>4);  //第二次温度传感器数值
		
		AD_TSSUM = (AD_TS0+AD_TS1)/2;    //温度传感器数值    
	}
}

/*****************************************************
*函数名称：uchar Read_IFB_Data(uchar AddOffset)
*函数功能：读取IC在25°的ADC温度采样值
*入口参数：AddOffset
*出口参数：Val
*****************************************************/
uchar Read_IFB_Data(uchar AddOffset)
{
	uchar Val;

	EA = 0;				//关总中断
	IAPADE = 0x01;		//选择EEPROM区域进行读写操作
	Val = *(POINT+AddOffset);	
	IAPADE = 0x00;		//返回ROM区域
	EA = 1;				//开总中断
	return Val;	
}

void Delay(uint time)
{
    uint i = 0;
    for(i=0; i<10; i++)
    for(; time>0; time--)
    ;
}