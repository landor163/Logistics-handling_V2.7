#ifndef  __BSP_EM_GPIO_H
#define  __BSP_EM_GPIO_H


//****************电机一和电机四GPIO的引脚配置****************//

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


//****************电机转动方向的的配置****************//
#define EM_A_TURN_CLOCKWISE   		GPIO_SetBits(EM_A_GPIO_PORT,EM_A_GPIO_PIN)
#define EM_A_TURN_ANTICLOCKWISE   GPIO_ResetBits(EM_A_GPIO_PORT,EM_A_GPIO_PIN)

#define EM_B_TURN_CLOCKWISE   		GPIO_SetBits(EM_B_GPIO_PORT,EM_B_GPIO_PIN)
#define EM_B_TURN_ANTICLOCKWISE   GPIO_ResetBits(EM_B_GPIO_PORT,EM_B_GPIO_PIN)

#define EM_C_TURN_CLOCKWISE   	  GPIO_SetBits(EM_C_GPIO_PORT,EM_C_GPIO_PIN)	
#define EM_C_TURN_ANTICLOCKWISE   GPIO_ResetBits(EM_C_GPIO_PORT,EM_C_GPIO_PIN)

#define EM_D_TURN_CLOCKWISE   	  GPIO_SetBits(EM_D_GPIO_PORT,EM_D_GPIO_PIN)	
#define EM_D_TURN_ANTICLOCKWISE   GPIO_ResetBits(EM_D_GPIO_PORT,EM_D_GPIO_PIN)
//电机状态
void 	EM_GPIO_Init(void);						//电机IO初始化


void 	EM_A_up(int x);								//电机A正转
void  EM_A_down(int x);						  //电机A反转


void  EM_B_dowm(int x);							//电机D反转
void  EM_B_up(int x);								//电机D正转


void  EM_D_down(int x);							//电机C正转 
void  EM_D_up(int x);								//电机C反转


void  EM_C_up(int x);								//电机B正转
void  EM_C_down(int x);							//电机B反转


//小车赚直走
void 	Car_Fore(int x);							//小车往前跑
void 	Car_Back(int x);							//小车往后跑
void 	Car_Left(int x);							//小车往左跑
void 	Car_right(int x);							//小车往右跑
//小车斜着走
void	Car_Left_Fore(int x);					//小车往左前方跑
void 	Car_Right_Back(int x);				//小车往右后方跑
void 	Car_Right_Fore(int x);				//小车往右前方跑
void 	Car_Left_Back(int x);					//小车往左后方跑
//小车旋转
void 	Car_CLOCKWISE(int x);					//小车逆时针转动
void  Car_ANTICLOCKWISE(int x);			//小车顺时针转动
#endif

