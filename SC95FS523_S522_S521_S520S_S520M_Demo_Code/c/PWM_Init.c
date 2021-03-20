#include "H/Function_Init.H"

#if (IC_MODEL == SC95FS523 || IC_MODEL == SC95FS522)
unsigned int xdata PWMRD0  _at_  0x1040;
unsigned int xdata PWMRD1  _at_  0x1042;
unsigned int xdata PWMRD2  _at_  0x1044;
unsigned int xdata PWMRD3  _at_  0x1046;
unsigned int xdata PWMRD4  _at_  0x1048;
unsigned int xdata PWMRD5  _at_  0x104A;
unsigned int xdata PWMRD6  _at_  0x104C;
unsigned int xdata PWMRD7  _at_  0x104E;
#endif

#if (IC_MODEL == SC95FS521)
unsigned int xdata PWMRD0  _at_  0x1040;
unsigned int xdata PWMRD1  _at_  0x1042;
unsigned int xdata PWMRD4  _at_  0x1048;
unsigned int xdata PWMRD5  _at_  0x104A;
unsigned int xdata PWMRD6  _at_  0x104C;
#endif

#if (IC_MODEL == SC95FS520S || IC_MODEL == SC95FS520M)
unsigned int xdata PWMRD4  _at_  0x1048;
#endif

unsigned int xdata PWMRD_Temp;
void PWM_Init(void);
/*****************************************************
*�������ƣ�void PWM_Test(void)
*�������ܣ�PWM����
*��ڲ�����void
*���ڲ�����void
*****************************************************/
void PWM_Test(void)
{
	PWM_Init();
	while(1)
	{
	}
}

/*****************************************************
*�������ƣ�void PWM_Init(void)
*�������ܣ�PWM����ģʽ��ʼ��
*��ڲ�����void
*���ڲ�����void
*****************************************************/
void PWM_Init(void)
{
	//����������Ϊ1ms��ռ�ձ�Ϊ50%��PWM����
    PWMCON0 = 0x00;    //����ģʽ�����ض��룬PWMʱ��=fHRC
	PWMCON1 = 0x10;    //ʹ��PWM0�������
    PWMCFG  = 0x00;    //PWM0���������
    PWMPDL  = 0xFF;    //���ڵ�8λ
    PWMPDH  = 0x7C;    //���ڸ�8λ�����ڣ�(0x7CFF+1)/32M=1ms
	PWMRD4 = 0x3E80;   //����PWM0�ڣ�����ռ�ձ�
    PWMCON0 |= 0x80;   //ʹ��PWM
    PWMFLT = 0xA1;     //ʹ�ܹ��ϼ�⣬����ģʽ�����͵�ƽ��1uS�˲�ʱ��
    IE1 |= 0x02;       //�����жϱ�־λ
    EA = 1;
}

/*****************************************************
*�������ƣ�void PWM_Init(void)
*�������ܣ�PWM����ģʽ��ʼ��
*��ڲ�����void
*���ڲ�����void
*****************************************************
void PWM_Init(void)
{
	//����������Ϊ50us��ռ�ձ�Ϊ50%��PWM����
    PWMCON0 = 0x00;    //����ģʽ�����ض��룬PWMʱ��=fHRC
	PWMCON1 = 0x03;    //ʹ��PWM0/1�������
    PWMCFG  = 0x02;    //PWM1�������
    PWMPDL  = 0xFF;    //���ڵ�8λ
    PWMPDH  = 0x7C;    //���ڸ�8λ�����ڣ�(0x7CFF+1)/32M=1ms
	PWMRD0 = 0x3E80;   //����PWM0�ڣ�����ռ�ձ�
    PWMDFR = 0x88;     //��������������ʱ�䣺4*PWMDFR[3:0]/fHRC  �����½�������ʱ�䣺4*PWMDFR[7:4]/fHRC
    PWMCON0 |= 0x80;   //ʹ��PWM
    IE1 |= 0x02;       //�����жϱ�־λ
    EA = 1;
}*/


/*****************************************************
*�������ƣ�void PWM_Interrup() interrupt 8
*�������ܣ�PWM�жϷ�����
*��ڲ�����void
*���ڲ�����void
*****************************************************/
void PWM_Interrup() interrupt 8
{
    if(PWMCON0 & 0x40)
    {
        PWMCFG &= ~0x40;  //����жϱ�־λ
        P04 = ~P04;       
    }
}