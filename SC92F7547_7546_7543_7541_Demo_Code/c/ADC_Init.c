#include "H/Function_Init.H"

void ADC_Init(uint Channel);
unsigned int ADCValue = 0x0000;
bit AdcFlag = 0;

/***********ADC������ѡ��*************/
#if (IC_MODEL == SC92F7547 || IC_MODEL == SC92F7546)
	enum Channel {AIN0=0,AIN1,AIN2,AIN3,AIN4,AIN5,AIN6,AIN7,AIN8,AIN9,AIN10,AIN11,AIN12,AIN13,AIN14,AIN15,VDD4=31};
#endif
	
#if (IC_MODEL == SC92F7543)
	enum Channel {AIN4=4,AIN5,AIN6,AIN7,AIN8,AIN9,AIN10,AIN11,AIN12,AIN13,AIN14,AIN15,VDD4=31};
#endif

#if (IC_MODEL == SC92F7541)
enum Channel {AIN0=0,AIN1,AIN4=4,AIN5,AIN6,AIN7,AIN10=10,AIN11,VDD4=31};
#endif
	
/*****************************************************
*�������ƣ�void ADC_Test(void)
*�������ܣ�ADC����
*��ڲ�����void
*���ڲ�����void
*****************************************************/
void ADC_Test(void)
{
	ADC_Init(AIN4);
	while(1)
	{
		ADCCON |= 0X40;   //��ʼADCת��
		while(!AdcFlag);	         		 //�ȴ� ADCת�����;
		AdcFlag = 0;
		ADCValue = (ADCVH<<4)+(ADCVL>>4);
	}
}
/*****************************************************
*�������ƣ�void ADC_Init(uint Channel)
*�������ܣ�ADC��ʼ��
*��ڲ�����Channel
*���ڲ�����void
*****************************************************/
void ADC_Init(uint Channel)
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
	IE |= 0X40;        //����ADC�ж�
	EA = 1;
}


void ADC_Interrupt(void) interrupt 6
{
	ADCCON &= ~(0X20);  //���жϱ�־λ
	AdcFlag = 1;
}