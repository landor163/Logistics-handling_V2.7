#include "stm32f10x.h"
#include "bsp_em_gpio.h"
#include "bsp_GeneralTim_3.h"


//****************初始化小车电机的IO口***************//
void EM_GPIO_Init()
{
	GPIO_InitTypeDef EM_GPIO_InitStruct; 																							 //定义一个 EM_GPIO_InitTypeDef 类型的结构体
	
	RCC_APB2PeriphClockCmd(EM_A_GPIO_CLK|EM_B_GPIO_CLK |EM_C_GPIO_CLK |EM_D_GPIO_CLK  , ENABLE);//开启EM对应GPIO的时钟
	EM_GPIO_InitStruct.GPIO_Mode = GPIO_Mode_Out_PP;																	 //设置为推挽输出
	
	EM_GPIO_InitStruct.GPIO_Pin = EM_A_GPIO_PIN ;																	 //配置需要控制的GPIO引脚
	EM_GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;																	 //配置引脚输出速度
	GPIO_Init(EM_A_GPIO_PORT , &EM_GPIO_InitStruct);																 //调用函数  初始化GPIO
	
	EM_GPIO_InitStruct.GPIO_Pin = EM_B_GPIO_PIN ;																	 //配置需要控制的GPIO引脚
	EM_GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;																	 //配置引脚输出速度
	GPIO_Init(EM_B_GPIO_PORT , &EM_GPIO_InitStruct);																 //调用函数  初始化GPIO
	
	EM_GPIO_InitStruct.GPIO_Pin = EM_C_GPIO_PIN ;																	 //配置需要控制的GPIO引脚
	EM_GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;																	 //配置引脚输出速度
  GPIO_Init(EM_C_GPIO_PORT , &EM_GPIO_InitStruct);																 //调用函数  初始化GPIO
	
	EM_GPIO_InitStruct.GPIO_Pin = EM_D_GPIO_PIN;																	 //配置需要控制的GPIO引脚
	EM_GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;																	 //配置引脚输出速度
	GPIO_Init(EM_D_GPIO_PORT , &EM_GPIO_InitStruct);																 //调用函数  初始化GPIO
	
}


/****************************电机状态函数************/
void EM_A_down(int x)
{
	EM_A_TURN_ANTICLOCKWISE;
	GENERAL_ccr1_Mode_Config(x);
}
void  EM_A_up(int x)
{	
	EM_A_TURN_CLOCKWISE;
	GENERAL_ccr1_Mode_Config((100-x));	
}
void  EM_C_up(int x)
{
	EM_B_TURN_ANTICLOCKWISE;
  GENERAL_ccr2_Mode_Config(x);	
}
void  EM_C_down(int x)
{
	EM_B_TURN_CLOCKWISE;
	GENERAL_ccr2_Mode_Config((100-x));	
}
void  EM_D_down(int x)
{
	EM_C_TURN_ANTICLOCKWISE;
	GENERAL_ccr3_Mode_Config(x);	
}
void  EM_D_up(int x)
{
	EM_C_TURN_CLOCKWISE;
	GENERAL_ccr3_Mode_Config((100-x));	
}

void  EM_B_down(int x)
{
	EM_D_TURN_ANTICLOCKWISE;
	GENERAL_ccr4_Mode_Config(x);	
}
void  EM_B_up(int x)
{
	EM_D_TURN_CLOCKWISE;
	GENERAL_ccr4_Mode_Config((100-x));	
}

/**************小车状态函数******************/
//	前
void	 Car_Fore(int x)								
{
	EM_A_up(x);
	EM_B_up(x);
	EM_C_up(x);
	EM_D_up(x);
}
//	后
void 	Car_Back(int x)
{
	EM_A_down(x);
	EM_B_down(x);
	EM_C_down(x);
	EM_D_down(x);
}
//	左
void 	Car_Left(int x)
{
		EM_A_up(x);
		EM_B_down(x);
		EM_C_down(x);
		EM_D_up(x);
}
// 右
void 	Car_right(int x)
{
		EM_A_down(x);
		EM_B_up(x);
		EM_C_up(x);
		EM_D_down(x);
}
//	左前
void	Car_Left_Fore(int x)
{
		EM_A_up(x);
		EM_B_up(0);
		EM_C_up(0);
		EM_D_up(x);
}
//	右后
void Car_Right_Back(int x)
{
		EM_A_down(x);
		EM_B_down(0);
		EM_C_down(0);
		EM_D_down(x);
}
//	右前
void Car_Right_Fore(int x)
{
		EM_A_up(0);
		EM_B_up(x);
		EM_C_up(x);
		EM_D_up(0);
}
//	左后
void Car_Left_Back(int x)
{
		EM_A_down(0);
		EM_B_down(x);
		EM_C_down(x);
		EM_D_down(0);
}

/*****************小车旋转**********************/
//	顺时针
void 	Car_CLOCKWISE(int x)
{
		EM_A_down(x);
		EM_B_up(x);
		EM_C_down(x);
		EM_D_up(x);
}
//	逆时针
void  Car_ANTICLOCKWISE(int x)
{
		EM_A_up(x);
		EM_B_down(x+10);
		EM_C_up(x);
		EM_D_down(x);
}	



