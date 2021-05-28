#ifndef  __BSP_EM_GPIO_H
#define  __BSP_EM_GPIO_H


//****************���һ�͵����GPIO����������****************//

#define EM_A_GPIO_PORT   GPIOA
#define EM_A_GPIO_CLK    RCC_APB2Periph_GPIOA
#define EM_A_GPIO_PIN    GPIO_Pin_2

#define EM_B_GPIO_PORT   GPIOA
#define EM_B_GPIO_CLK    RCC_APB2Periph_GPIOA
#define EM_B_GPIO_PIN    GPIO_Pin_3

#define EM_C_GPIO_PORT   GPIOA
#define EM_C_GPIO_CLK    RCC_APB2Periph_GPIOA
#define EM_C_GPIO_PIN    GPIO_Pin_4

#define EM_D_GPIO_PORT   GPIOA
#define EM_D_GPIO_CLK    RCC_APB2Periph_GPIOA
#define EM_D_GPIO_PIN    GPIO_Pin_5


//****************���ת������ĵ�����****************//
#define EM_A_TURN_CLOCKWISE   		GPIO_SetBits(EM_A_GPIO_PORT,EM_A_GPIO_PIN)
#define EM_A_TURN_ANTICLOCKWISE   GPIO_ResetBits(EM_A_GPIO_PORT,EM_A_GPIO_PIN)

#define EM_B_TURN_CLOCKWISE   		GPIO_SetBits(EM_B_GPIO_PORT,EM_B_GPIO_PIN)
#define EM_B_TURN_ANTICLOCKWISE   GPIO_ResetBits(EM_B_GPIO_PORT,EM_B_GPIO_PIN)

#define EM_C_TURN_CLOCKWISE   	  GPIO_SetBits(EM_C_GPIO_PORT,EM_C_GPIO_PIN)	
#define EM_C_TURN_ANTICLOCKWISE   GPIO_ResetBits(EM_C_GPIO_PORT,EM_C_GPIO_PIN)

#define EM_D_TURN_CLOCKWISE   	  GPIO_SetBits(EM_D_GPIO_PORT,EM_D_GPIO_PIN)	
#define EM_D_TURN_ANTICLOCKWISE   GPIO_ResetBits(EM_D_GPIO_PORT,EM_D_GPIO_PIN)
//���״̬
void 	EM_GPIO_Init(void);						//���IO��ʼ��


void 	EM_A_up(int x);								//���A��ת
void  EM_A_down(int x);						  //���A��ת


void  EM_B_dowm(int x);							//���D��ת
void  EM_B_up(int x);								//���D��ת


void  EM_D_down(int x);							//���C��ת 
void  EM_D_up(int x);								//���C��ת


void  EM_C_up(int x);								//���B��ת
void  EM_C_down(int x);							//���B��ת


//С��׬ֱ��
void 	Car_Fore(int x);							//С����ǰ��
void 	Car_Back(int x);							//С��������
void 	Car_Left(int x);							//С��������
void 	Car_right(int x);							//С��������
//С��б����
void	Car_Left_Fore(int x);					//С������ǰ����
void 	Car_Right_Back(int x);				//С�����Һ���
void 	Car_Right_Fore(int x);				//С������ǰ����
void 	Car_Left_Back(int x);					//С���������
//С����ת
void 	Car_CLOCKWISE(int x);					//С����ʱ��ת��
void  Car_ANTICLOCKWISE(int x);			//С��˳ʱ��ת��
#endif

