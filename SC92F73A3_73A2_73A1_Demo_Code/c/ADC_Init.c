#include "H/Function_Init.H"

void ADC_Init(uint Channel,uchar ADCFreq);
unsigned int ADCValue = 0x0000;
bit AdcFlag = 0;
/***********ADC����Ƶ��ѡ��*************/
enum ADCFreq {F32=0,F24,F16,F12,F8,F6,F4,F3};

/***********ADC������ѡ��*************/
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
*�������ƣ�void ADC_Test(void)
*�������ܣ�ADC����
*��ڲ�����void
*���ڲ�����void
*****************************************************/
void ADC_Test(void)
{
	ADC_Init(AIN3,F8);
	while(1)
	{
		ADCCON |= 0X40;   //��ʼADCת��
	    while(!AdcFlag);	         		 //�ȴ� ADCת�����;
		AdcFlag = 0;
	    ADCValue=(ADCVH<<4)+(ADCVL>>4);
	}
}
/*****************************************************
*�������ƣ�void ADC_Init(uint Channel,uchar ADCFreq)
*�������ܣ�ADC��ʼ��
*��ڲ�����void
*���ڲ�����void
*****************************************************/
void ADC_Init(uint Channel,uchar ADCFreq)
{
	ADCCON = 0X80|Channel;		//����ADC��ADC����Ƶ��Ϊ2M ,ѡ��ChannelλADC������
	if(Channel<8)
	{
		ADCCFG0 = 1<<Channel;   //����Channel��Ϊ������
	}
	else
	{
		ADCCFG1 = 1<<(Channel-8);   //����Channel��Ϊ������
	}
	ADCCFG2 = ADCFreq;
	IE |= 0X40;        //����ADC�ж�
	EA = 1;
}


void ADC_Interrupt(void) interrupt 6
{
	ADCCON&=~(0X20);  //���жϱ�־λ
	AdcFlag = 1;
}