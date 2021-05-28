#ifndef PID_H
#define PID_H

//PID�ṹ��ָ��
 typedef struct 
 {
		volatile double   Proportion;             // ��������   P
		volatile double   Integral;               // ���ֲ���   I
		volatile double   Derivative;             // ΢�ֲ���   D
		volatile int      Error1;                 // Error[n-1]
		volatile int      Error2;                 // Error[n-2]
		volatile int      iError;                 // Error[n]
}PID;
 
float IncPIDCalc(int CurrentPoint,int SetPoint,PID* sptr);




#endif /* PID_H */
