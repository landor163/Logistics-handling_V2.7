#include "bsp_Find_Num.h"

void Find_Nun_Init()
{
	GPIO_InitTypeDef  GPIO_InitStruct;																					 //����һ�� GPIO_InitTypeDef ���͵Ľṹ��
	RCC_APB2PeriphClockCmd(LED_1_GPIO_CLK|LED_2_GPIO_CLK|LED_3_GPIO_CLK|LED_4_GPIO_CLK|LED_5_GPIO_CLK, ENABLE);//����led��ӦGPIO��ʱ��
	GPIO_InitStruct.GPIO_Pin = LED_1_GPIO_PIN|LED_2_GPIO_PIN|LED_3_GPIO_PIN|LED_4_GPIO_PIN|LED_5_GPIO_PIN;//������Ҫ���Ƶ�GPIO����
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IPD;																 //����Ϊ������������
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;															 //����GPIO����
	GPIO_StructInit(&GPIO_InitStruct);
}
