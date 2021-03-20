#include "H/Function_Init.H"

void ADC_Init(uint Channel);
unsigned int ADCValue = 0x0000;
bit AdcFlag = 0;

/***********ADC������ѡ��*************/
#if (IC_MODEL == SC92F7402)
    enum Channel {AIN0=0,AIN1,AIN2,AIN3,AIN4,AIN5,AIN6,VDD4=31};
#endif
    
#if (IC_MODEL == SC92F7401)
    enum Channel {AIN0=0,AIN1,AIN4=4,AIN5,AIN6,VDD4=31};
#endif
    
/*****************************************************
*�������ƣ�void ADC_Test(void)
*�������ܣ�ADC����
*��ڲ�����void
*���ڲ�����void
*****************************************************/
void ADC_Test(void)
{
	ADC_Init(AIN6);
	while(1)
	{
		ADCCON |= 0X40;   //��ʼADCת��
	    while(!AdcFlag);	//�ȴ� ADCת�����;
		AdcFlag = 0;
	    ADCValue=(ADCVH<<4)+(ADCVL>>4);  //ADC����ֵ
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
	ADCCON = 0X80|Channel;		//����ADC,ѡ��ChannelλADC������
	if(Channel<8)
	{
		ADCCFG0 = 1<<Channel;   //����Channel��Ϊ������
	}
	ADCCFG1 = 0x04;           //����ADCʱ��Ƶ��ΪFosc/8
	IE |= 0X40;                //����ADC�ж�
	EA = 1;
}


void ADC_Interrupt(void) interrupt 6
{
	ADCCON&=~(0X20);  //���жϱ�־λ
	AdcFlag = 1;
}