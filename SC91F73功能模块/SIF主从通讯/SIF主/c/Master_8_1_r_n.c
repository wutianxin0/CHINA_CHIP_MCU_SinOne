//************************************************************
//  Copyright (c) 深圳市赛元微电子有限公司
//	文件名称	: master_8_1.c
//	作者		: 
//	模块功能	: SIF master 8+1读写通讯
//	局部函数列表:
//  最后更正日期:
// 	版本		:
// 	更改记录	:SIF master (单）多字节读，最后一个字节读完，发送NoAck,之后,进入stop
//*************************************************************
#include "H\SC91F73_C.H"
#include "H\Master_8_1.H"

//============================
//静态局部变量定义
//============================

static	unsigned char receive_dat_buff[3]={0x00,0x00,0x00};

//============================
//模块内常量定义
//============================
#define	SIF_RDat_Num			3			//读字节的个数
#define	false					0
#define	ture					1


//============================
//内部函数声明
//============================

void Sif_Read_N_Byte(void);
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
// 函数名	：void Sif_Read_N_Byte(void)
// 作者		：
// 功能		：(单)多字节读
// 参数		：无
// 返回值	：0/1
// 调用全局变量：无
// 修改全局变量：无
// 备注		：
//**************************************************************
void Sif_Read_N_Byte(void)
{
	unsigned char i=0;
	for(i=0;i<SIF_RDat_Num;i++)
		{
//先判断是否给应答位,该bit位作为通讯控制位使用
			if(i==(SIF_RDat_Num-1))				//最后一个byte读取完成，发送NOACK
				{
					sif_noack();				//不发送应答
				}
			else
				{
					sif_ack();					//发送应答
				}
//完成判断，接收数据后，可完成应答位控制					
			receive_dat_buff[i]=receive_byte();	//读取字节		
		}
	  send_stop();				//发送stop命令
	  I2C_Usdelay(50);			//方便资料准备
			
}
void main()
{
	RSTCFG = 0x0b;
	sif_init();						  //SIF初始化
	for(;;)
	{			
		send_start();				//SIF通讯start,写Nbyte，读Nbyte会用到
		Sif_Read_N_Byte();			//读N byte数据
		
	}
}