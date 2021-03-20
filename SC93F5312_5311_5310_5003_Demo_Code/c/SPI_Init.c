#include "H/Function_Init.H"

void SPI_Init(void);

bit SPIFlag = 0;         //SPI���ݴ�����ɱ�־λ
/*****************************************************
*�������ƣ�void SPI_Test(void)
*�������ܣ�SPI����
*��ڲ�����void
*���ڲ�����void
*****************************************************/
void SPI_Test(void)
{
	SPI_Init();
	while(1)
	{
		SPDAT = 0xAA;
		while(!SPIFlag);
		SPIFlag = 0;
	}
}

/*****************************************************
*�������ƣ�void SPI_Init(void)
*�������ܣ�SPI��ʼ��
*��ڲ�����void
*���ڲ�����void
*****************************************************/
void SPI_Init(void)
{
	SPCON = 0x3F; //����SPIΪ���豸��SCK����ʱ��Ϊ�ߵ�ƽ��SCK���ڵڶ��زɼ����ݣ�ʱ������ΪFsys/512
	SPSTA = 0x01;   //�������ж�
	SPCON |= 0x80; //����SPI
	IE1 |= 0x01;
	EA = 1;
}


/*****************************************************
*�������ƣ�void SpiInt() interrupt 7
*�������ܣ�SPI�жϺ���
*��ڲ�����void
*���ڲ�����void
*****************************************************/
void SpiInt(void) interrupt 7    //SPI�жϺ���
{	  
	if(SPSTA&0X08)    //���ͻ������ձ�־�ж�
	{
		SPSTA &= ~0X08;
	}
	if(SPSTA&0X80)    //���ݴ����־λ�ж�
	{
		SPSTA &= ~0X80;
		SPIFlag = 1;
	}
}