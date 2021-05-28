#ifndef __CAR_OPER_H
#define __CAR_OPER_H


#define Car_Speed_Str      30		//直线
#define Car_Speed_Turn      50	//转弯


void control(void);//状态控制
void Identify(void);//模式识别
void Follow_line(void);//巡线

#endif
