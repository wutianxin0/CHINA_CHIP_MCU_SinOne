//73_IOÄ£Äâ(Ö÷)
#include"SC91F73_C.H"
#define sda  P15
#define scl  P14
void GPIO_init()
{
	RSTCFG=0X0B;
	P1CFG0=0X00;
	P1CFG1=0X00;
	P3CFG0=0X55;
	P3CFG1=0X55;
}
void delay()
{
	unsigned int i,j;
	for(i=0;i<700;i++)
		for(j=0;j<700;j++);
}
void init()
{
	sda=1;
	scl=1;	
}
void start()
{
	sda=1;
	scl=1;
	sda=0;
	scl=0;
}
void send(unsigned char Sdata)
{
	unsigned char i;
	for(i=0;i<8;i++)
	{
		Sdata=(Sdata<<1);
		scl=0;		
		sda=CY;	
		scl=1;		
	}
	scl=0;
	sda=1;	
}
unsigned char read()
{
	unsigned char i,Rdata;
	scl=0;
	for(i=0;i<8;i++)
	{
		scl=1;
		Rdata=(Rdata<<1)|sda;		
		scl=0;		
	}
	sda=1;
	return Rdata;	
}
void stop()
{
	scl=0;
	sda=0;
	scl=1;
	sda=1;
}
void master_respond()
{
	sda=0;
	scl=1;
	scl=0;
	sda=1;
}
void slave_respond()
{
	unsigned char i;
	scl=1;
	while((sda==1)&&(i<1))  i++;
	scl=0;
}
void main()
{
	unsigned char temp=0;
	GPIO_init();
	init();
	while(1)
	{
		start();
		send(0x02);
		slave_respond();
		stop();
//		delay();
//		temp=read();
//		if(temp==0x88)
//			P3=temp;
//		master_respond();
/*		stop();
		delay();
		start();
		delay();
		temp=read();
		if(temp==0x11)
			P3=temp;
		master_respond();
		stop();
		delay();*/	
	}			
}
