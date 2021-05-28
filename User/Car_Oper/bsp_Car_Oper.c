#include "bsp_Car_Oper.h"
#include "bsp_em_gpio.h"
#include "bsp_Find_Num.h"
#include "bsp_usart.h"
#include "bsp_SysTick.h"


int LED_1=1,LED_2=1,LED_3=1,LED_4=1,LED_5=1,i=0,status=0;
static int Resources=1;


 void Follow_line()//巡线
{
//车上红灯亮为1，灭为0;
//不踩黑线红(1)，踩黑线灭(0);
	LED_1=LED_1_out;//A
	LED_2=LED_2_out;//A
	LED_3=LED_3_out;//B
	LED_4=LED_4_out;//A
	LED_5=LED_5_out;//B


	if((LED_1==1)&(LED_5==1))//2、3、4全部压线
	{
		
		Car_Fore(Car_Speed_Str);//直行
		status=1;
		
	}

	if((LED_1==1)&(LED_3==0)&(LED_5==0))//2丢线了，向左转一下
	{
		
		Car_CLOCKWISE(Car_Speed_Turn+20);//向左转
		status=2;
	}

	if((LED_1==0)&(LED_3==0)&(LED_5==1))//4丢线了，向右转一下
	{
		Car_ANTICLOCKWISE(Car_Speed_Turn);//向右转
		
		status=3;
	}
	//printf("LED_1=%d LED_2=%d LED_3=%d LED_4=%d LED_5=%d\n",LED_1,LED_2,LED_3,LED_4,LED_5);
}




void Identify()//模式识别
{
//	if((LED_1==0)&(LED_2==0)&(LED_3==0)&(LED_4==0)&(LED_5==0)&(Resources==6))//上坡
//	{
//		status=6;
//		Car_Fore(80);//直行通过
//		SysTick_Delay_Ms(4000);
//		Resources=7;
//	}
	
	if((LED_1==0)&(LED_2==0)&(LED_3==0)&(LED_4==0)&(LED_5==0)&(Resources==5))//第三个重生点
	{
		status=6;
		Car_Fore(30);//直行通过
		SysTick_Delay_Ms(1500);
		Resources=6;
	}
	
	if((LED_1==0)&(LED_2==0)&(LED_3==0)&(LED_4==0)&(LED_5==0)&(Resources==4))//Z_2
	{
		status=6;
		Car_Fore(30);
		SysTick_Delay_Ms(300);
		Car_ANTICLOCKWISE(Car_Speed_Turn);//右转
		SysTick_Delay_Ms(650);
		Resources=5;
	}
	
	if((LED_1==0)&(LED_2==0)&(LED_3==0)&(LED_4==0)&(LED_5==0)&(Resources==3))//Z_1
	{
		status=6;
		Car_CLOCKWISE(Car_Speed_Turn);//左转
		SysTick_Delay_Ms(1700);
		Resources=4;
	}
	
	if((LED_1==0)&(LED_2==0)&(LED_3==0)&(LED_4==0)&(LED_5==0)&(Resources==2))//第二个重生点
	{
		status=6;
		Car_Fore(30);//直行通过
		SysTick_Delay_Ms(1500);
		Resources=3;
	}
	
	if((LED_1==0)&(LED_2==0)&(LED_3==0)&(LED_4==0)&(LED_5==0)&(Resources==1))//第一个重生点
	{
		status=5;
		Car_Fore(30);//直行通过
		SysTick_Delay_Ms(1700);
		Resources=2;
	}
	
	if((LED_1==0)&(LED_2==0)&(LED_3==0)&(LED_4==0)&(LED_5==0)&(Resources==0))//丁字路口
	{
		status=4;
		Car_Fore(30);//直行一会
		SysTick_Delay_Ms(400);
		Car_ANTICLOCKWISE(50);//左转一会
		SysTick_Delay_Ms(900);
		Car_Fore(30);//再直行一会
		SysTick_Delay_Ms(1000);
		Resources=1;
	}
	
	printf("status=%d Resources=%d\n",status,Resources);
}

