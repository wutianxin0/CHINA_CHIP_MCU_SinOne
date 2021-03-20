//************************************************************
//  Copyright (c) 深圳市赛元微电子有限公司
//	文件名称	: master_8_1.c
//	作者		: 
//	模块功能	: SIF master 8+1读写通讯
//	局部函数列表:
//  最后更正日期:
// 	版本		:
// 	更改记录	:SIF master 发送date,再接收slave的date,接收完成，发送Noack,进入stop
//*************************************************************
#include "H\SC91F831_C.H"
#include "H\Master_8_1.H"

//============================
//静态局部变量定义
//============================

static	unsigned char send_dat_buff[3]={0x31,0x5a,0xa5};
static	unsigned char receive_dat_buff[3]={0x00,0x00,0x00};

//============================
//模块内常量定义
//============================

#define	false					0
#define	ture					1


//============================
//内部函数声明
//============================
bit Sif_Writ_Read_Byte(void);
void I2C_Usdelay(unsigned int delay);

//******************************************************************
// 函数名	：void I2C_Usdelay(unsigned int delay)
// 作者		：
// 功能		：通信延时函数
// 参数		：无
// 返回值	：无
// 调用全局变量：无
// 修改全局变量：无
// 备注		：
//******************************************************************
void I2C_Usdelay(unsigned int delay)
{
	while(delay)
	{
		delay--;
	}
}
//*************************************************************
// 函数名	：void Sif_Read_Writ_Byte(void))
// 作者		：
// 功能		：单字节读写连续操作：先写后读
// 参数		：无
// 返回值	：0/1
// 调用全局变量：无
// 修改全局变量：无
// 备注		：		  
//**************************************************************
bit Sif_Writ_Read_Byte(void)
{
	send_start();
	send_byte(send_dat_buff[0]);			//发送1byte-> send_dat_buff[0]
	if(!sif_waitack())						//判断是否有响应,如果没有响应，进入Stop
		{
			send_stop();
			I2C_Usdelay(50);				//方便资料准备
			return	(false);			
		}
	 sif_noack();							//设置寄存器，表明不发送应答
	 receive_dat_buff[0]=receive_byte();	//读取1byte,字节存入receive_dat_buff[0]	 
	 send_stop();							//发送停止信号
	 I2C_Usdelay(50);						//方便资料准备
	 return	(ture);
}
void main()
{
	RSTCFG = 0x20;
	sif_init();						  //SIF初始化
	for(;;)
	{			
		Sif_Writ_Read_Byte();		//先写后读	
	}
}