#include "H/Function_Init.H"

#if (IC_MODEL == SC95F8517 || IC_MODEL == SC95F8516 || IC_MODEL == SC95F8515)
unsigned int xdata PWMRD_40  _at_  0x1040;
unsigned int xdata PWMRD_41  _at_  0x1042;
unsigned int xdata PWMRD_42  _at_  0x1044;
unsigned int xdata PWMRD_43  _at_  0x1046;
unsigned int xdata PWMRD_50  _at_  0x1048;
unsigned int xdata PWMRD_51  _at_  0x104A;
unsigned int xdata PWMRD_52  _at_  0x104C;
unsigned int xdata PWMRD_53  _at_  0x104E;
#endif

#if (IC_MODEL == SC95F8513)
unsigned int xdata PWMRD_40  _at_  0x1040;
unsigned int xdata PWMRD_41  _at_  0x1042;
unsigned int xdata PWMRD_42  _at_  0x1044;
unsigned int xdata PWMRD_43  _at_  0x1046;
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
	//����������Ϊ50us��ռ�ձ�Ϊ50%��PWM����
    PWMMOD = 0x00;           //����ģʽ�����ض���
	PWMCON = 0x3F;           //�������õ�8λ,50us
    PWMCFG = 0x86;           //7:����  5-4��ʱ��Դѡ��  3-0���������ø�4λ	
	PWMRD_41 = 0x8000 | 0x320;     //����PWM�ڣ�����ռ�ձ�
    IE1 |= 0x02;        //�����жϱ�־λ
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
    PWMMOD = 0x0C;           //����ģʽ�����Ķ���
	PWMCON = 0x3F;           //�������õ�8λ,50us
    PWMCFG = 0x86;           //7:����  5-4��ʱ��Դѡ��  3-0���������ø�4λ	
	PWMRD_40 = 0x8000 | 0x320;     //����PWM40�ڣ�����ռ�ձ�
    PWMRD_41 = 0xC000 ;            //����PWM41�ڣ��������
    PWMDFR = 0x88;                 //��������������ʱ�䣺4*PWMDFR[3:0]/fHRC  �����½�������ʱ�䣺4*PWMDFR[7:4]/fHRC
    IE1 |= 0x02;        //�����жϱ�־λ
    EA = 1;
}
*/

/*****************************************************
*�������ƣ�void PWM_Interrup() interrupt 8
*�������ܣ�PWM�жϷ�����
*��ڲ�����void
*���ڲ�����void
*****************************************************/
void PWM_Interrup() interrupt 8
{
    if(PWMCFG & 0x40)
    {
        PWMCFG &= ~0x40;  //����жϱ�־λ
        P04 = ~P04;       
    }
}