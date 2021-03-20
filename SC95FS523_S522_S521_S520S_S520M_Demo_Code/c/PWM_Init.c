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
*函数名称：void PWM_Test(void)
*函数功能：PWM测试
*入口参数：void
*出口参数：void
*****************************************************/
void PWM_Test(void)
{
	PWM_Init();
	while(1)
	{
	}
}

/*****************************************************
*函数名称：void PWM_Init(void)
*函数功能：PWM独立模式初始化
*入口参数：void
*出口参数：void
*****************************************************/
void PWM_Init(void)
{
	//设置了周期为1ms，占空比为50%的PWM波形
    PWMCON0 = 0x00;    //独立模式，边沿对齐，PWM时钟=fHRC
	PWMCON1 = 0x10;    //使能PWM0波形输出
    PWMCFG  = 0x00;    //PWM0输出不反向
    PWMPDL  = 0xFF;    //周期低8位
    PWMPDH  = 0x7C;    //周期高8位，周期：(0x7CFF+1)/32M=1ms
	PWMRD4 = 0x3E80;   //开启PWM0口，设置占空比
    PWMCON0 |= 0x80;   //使能PWM
    PWMFLT = 0xA1;     //使能故障检测，立即模式，检测低电平，1uS滤波时间
    IE1 |= 0x02;       //开启中断标志位
    EA = 1;
}

/*****************************************************
*函数名称：void PWM_Init(void)
*函数功能：PWM互补模式初始化
*入口参数：void
*出口参数：void
*****************************************************
void PWM_Init(void)
{
	//设置了周期为50us，占空比为50%的PWM波形
    PWMCON0 = 0x00;    //独立模式，边沿对齐，PWM时钟=fHRC
	PWMCON1 = 0x03;    //使能PWM0/1波形输出
    PWMCFG  = 0x02;    //PWM1输出反向
    PWMPDL  = 0xFF;    //周期低8位
    PWMPDH  = 0x7C;    //周期高8位，周期：(0x7CFF+1)/32M=1ms
	PWMRD0 = 0x3E80;   //开启PWM0口，设置占空比
    PWMDFR = 0x88;     //设置上升沿死区时间：4*PWMDFR[3:0]/fHRC  设置下降沿死区时间：4*PWMDFR[7:4]/fHRC
    PWMCON0 |= 0x80;   //使能PWM
    IE1 |= 0x02;       //开启中断标志位
    EA = 1;
}*/


/*****************************************************
*函数名称：void PWM_Interrup() interrupt 8
*函数功能：PWM中断服务函数
*入口参数：void
*出口参数：void
*****************************************************/
void PWM_Interrup() interrupt 8
{
    if(PWMCON0 & 0x40)
    {
        PWMCFG &= ~0x40;  //清除中断标志位
        P04 = ~P04;       
    }
}