#ifndef PID_H
#define PID_H

//PID结构体指针
 typedef struct 
 {
		volatile double   Proportion;             // 比例参数   P
		volatile double   Integral;               // 积分参数   I
		volatile double   Derivative;             // 微分参数   D
		volatile int      Error1;                 // Error[n-1]
		volatile int      Error2;                 // Error[n-2]
		volatile int      iError;                 // Error[n]
}PID;
 
float IncPIDCalc(int CurrentPoint,int SetPoint,PID* sptr);




#endif /* PID_H */
