#include "H/Function_Init.H"

void ADC_Init(uint Channel);
unsigned int ADCValue = 0x0000;
bit AdcFlag = 0;

/***********ADC������ѡ��*************/
enum Channel {AIN0=0,AIN1,VDD4=15};
	
/*****************************************************
*�������ƣ�void ADC_Test(void)
*�������ܣ�ADC����
*��ڲ�����void
*���ڲ�����void
*****************************************************/
void ADC_Test(void)
{
	ADC_Init(AIN0);
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
	if(Channel>8 && Channel<11)
	{
		ADCCFG1 = 1<<(Channel-8);   //����Channel��Ϊ������
	}
	IE |= 0X40;        //����ADC�ж�
	EA = 1;
}


void ADC_Interrupt(void) interrupt 6
{
	ADCCON &= ~(0X10);  //���жϱ�־λ
	AdcFlag = 1;
}