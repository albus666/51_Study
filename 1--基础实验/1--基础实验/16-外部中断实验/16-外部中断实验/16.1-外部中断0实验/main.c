/**************************************************************************************
深圳市普中科技有限公司（PRECHIN 普中）
技术支持：www.prechin.net

实验名称：外部中断0实验
接线说明：	
实验现象：下载程序后，当按下K3键可控制D1指示灯亮灭
注意事项：将红外接收传感器取下，防止对P3.2口干扰																				  
***************************************************************************************/
#include "reg52.h"

typedef unsigned int u16;	//对系统默认数据类型进行重定义
typedef unsigned char u8;

//定义LED1管脚
sbit LED1=P2^0;

//定义独立按键K3控制脚
sbit KEY3=P3^2;


/*******************************************************************************
* 函 数 名       : delay_10us
* 函数功能		 : 延时函数，ten_us=1时，大约延时10us
* 输    入       : ten_us
* 输    出    	 : 无
*******************************************************************************/
void delay_10us(u16 ten_us)
{
	while(ten_us--);	
}

/*******************************************************************************
* 函 数 名       : exti0_init
* 函数功能		 : 外部中断0配置函数
* 输    入       : 无
* 输    出    	 : 无
*******************************************************************************/
void exti0_init(void)
{
	IT0=1;//跳变沿触发方式（下降沿）
	EX0=1;//打开INT0的中断允许
	EA=1;//打开总中断
}

/*******************************************************************************
* 函 数 名       : main
* 函数功能		 : 主函数
* 输    入       : 无
* 输    出    	 : 无
*******************************************************************************/
void main()
{	
	exti0_init();//外部中断0配置

	while(1)
	{			
							
	}		
}

void exti0() interrupt 0 //外部中断0中断函数
{
	delay_10us(1000);//消斗
	if(KEY3==0)//再次判断K3键是否按下
		LED1=!LED1;//LED1状态翻转					
}