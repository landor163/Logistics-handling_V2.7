#include "stm32f10x.h"
#include "bsp_em_gpio.h"
#include "bsp_GeneralTim_3.h"


//****************��ʼ��С�������IO��***************//
void EM_GPIO_Init()
{
	GPIO_InitTypeDef EM_GPIO_InitStruct; 																							 //����һ�� EM_GPIO_InitTypeDef ���͵Ľṹ��
	
	RCC_APB2PeriphClockCmd(EM_A_GPIO_CLK|EM_B_GPIO_CLK |EM_C_GPIO_CLK |EM_D_GPIO_CLK  , ENABLE);//����EM��ӦGPIO��ʱ��
	EM_GPIO_InitStruct.GPIO_Mode = GPIO_Mode_Out_PP;																	 //����Ϊ�������
	
	EM_GPIO_InitStruct.GPIO_Pin = EM_A_GPIO_PIN ;																	 //������Ҫ���Ƶ�GPIO����
	EM_GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;																	 //������������ٶ�
	GPIO_Init(EM_A_GPIO_PORT , &EM_GPIO_InitStruct);																 //���ú���  ��ʼ��GPIO
	
	EM_GPIO_InitStruct.GPIO_Pin = EM_B_GPIO_PIN ;																	 //������Ҫ���Ƶ�GPIO����
	EM_GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;																	 //������������ٶ�
	GPIO_Init(EM_B_GPIO_PORT , &EM_GPIO_InitStruct);																 //���ú���  ��ʼ��GPIO
	
	EM_GPIO_InitStruct.GPIO_Pin = EM_C_GPIO_PIN ;																	 //������Ҫ���Ƶ�GPIO����
	EM_GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;																	 //������������ٶ�
  GPIO_Init(EM_C_GPIO_PORT , &EM_GPIO_InitStruct);																 //���ú���  ��ʼ��GPIO
	
	EM_GPIO_InitStruct.GPIO_Pin = EM_D_GPIO_PIN;																	 //������Ҫ���Ƶ�GPIO����
	EM_GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;																	 //������������ٶ�
	GPIO_Init(EM_D_GPIO_PORT , &EM_GPIO_InitStruct);																 //���ú���  ��ʼ��GPIO
	
}


/****************************���״̬����************/
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

/**************С��״̬����******************/
//	ǰ
void	 Car_Fore(int x)								
{
	EM_A_up(x);
	EM_B_up(x);
	EM_C_up(x);
	EM_D_up(x);
}
//	��
void 	Car_Back(int x)
{
	EM_A_down(x);
	EM_B_down(x);
	EM_C_down(x);
	EM_D_down(x);
}
//	��
void 	Car_Left(int x)
{
		EM_A_up(x);
		EM_B_down(x);
		EM_C_down(x);
		EM_D_up(x);
}
// ��
void 	Car_right(int x)
{
		EM_A_down(x);
		EM_B_up(x);
		EM_C_up(x);
		EM_D_down(x);
}
//	��ǰ
void	Car_Left_Fore(int x)
{
		EM_A_up(x);
		EM_B_up(0);
		EM_C_up(0);
		EM_D_up(x);
}
//	�Һ�
void Car_Right_Back(int x)
{
		EM_A_down(x);
		EM_B_down(0);
		EM_C_down(0);
		EM_D_down(x);
}
//	��ǰ
void Car_Right_Fore(int x)
{
		EM_A_up(0);
		EM_B_up(x);
		EM_C_up(x);
		EM_D_up(0);
}
//	���
void Car_Left_Back(int x)
{
		EM_A_down(0);
		EM_B_down(x);
		EM_C_down(x);
		EM_D_down(0);
}

/*****************С����ת**********************/
//	˳ʱ��
void 	Car_CLOCKWISE(int x)
{
		EM_A_down(x);
		EM_B_up(x);
		EM_C_down(x);
		EM_D_up(x);
}
//	��ʱ��
void  Car_ANTICLOCKWISE(int x)
{
		EM_A_up(x);
		EM_B_down(x+10);
		EM_C_up(x);
		EM_D_down(x);
}	



