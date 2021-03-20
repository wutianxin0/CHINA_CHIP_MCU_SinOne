#include "H/Function_Init.H"

void ADC_Init(uint Channel);
void Delay(uint time);
uint ADCValue = 0x0000;
bit AdcFlag = 0x00;

/***********ADC������ѡ��*************/
#if (IC_MODEL == SC93F5312)
	enum Channel {AIN0=0,AIN1,AIN2,AIN3,AIN4,AIN5,AIN6,AIN7,AIN8};
#endif

#if (IC_MODEL == SC93F5311)
	enum Channel {AIN2=2,AIN3,AIN4,AIN5,AIN6,AIN7,AIN8};
#endif
	
#if (IC_MODEL == SC93F5310)
	enum Channel {AIN5=5,AIN6,AIN7,AIN8};
#endif

/****************************************
*�������ƣ�void ADC_Test(void)
*�������ܣ�ADC����
*��ڲ�����void
*���ڲ�����void
****************************************/
void ADC_Test(void)
{
    ADC_Init(AIN4);
    while(1)
    {
        ADCCON |= 0X40;                      //��ʼADCת��
	    while(!(AdcFlag));	         		 //�ȴ� ADCת�����;
        AdcFlag = 0;
        ADCValue = ADCVH;
        ADCValue = (ADCValue<<4)+(ADCVL>>4);      
    }
}

/*****************************************************
*�������ƣ�void ADC_Init(void)
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

/*****************************************************
*�������ƣ�void ADC_Interrupt(void) interrupt 6
*�������ܣ�ADC�жϺ���
*��ڲ�����void
*���ڲ�����void
*****************************************************/
void ADC_Interrupt(void) interrupt 6
{
	ADCCON &= ~(0X10);  //���жϱ�־λ
	AdcFlag = 1;
}
