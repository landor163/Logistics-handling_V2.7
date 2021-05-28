#include "stm32f10x.h" 
#include "bsp_em_gpio.h"
#include "bsp_GeneralTim_3.h"
#include "bsp_usart.h"
#include "bsp_Find_Num.h"
#include "bsp_Car_Oper.h"
#include "bsp_SysTick.h"
#include "bsp_GeneralTim_2.h"

unsigned	int	time = 0; // ms 计时变量

int main(void)
{
	EM_GPIO_Init();
	GENERAL_TIM_2_Init();
	GENERAL_TIM_3_Init();	
	USART_Config();
	Find_Nun_Init();
//	Car_Fore(30);
//	SysTick_Delay_Ms(1500);
	while(1)
	{
		time=0;
		if(time%1==0)
		{
			Follow_line();
//			Identify();//识别
//			control();//控制
		}
	}//while
}//main
