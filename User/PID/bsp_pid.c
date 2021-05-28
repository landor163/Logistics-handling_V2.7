#include "bsp_pid.h"

float IncPIDCalc(int CurrentPoint,int SetPoint,PID* sptr) 
{
  float	iIncpid;
  sptr->iError=SetPoint-CurrentPoint;                                     
  iIncpid=sptr->Proportion * (sptr->iError-sptr->Error1)                  // P
         +sptr->Integral * sptr->iError                                   // I
         +sptr->Derivative * (sptr->iError-2*sptr->Error1+sptr->Error2);  // D
             
  sptr->Error2=sptr->Error1;                          
  sptr->Error1=sptr->iError;										
		
  return iIncpid;                                    
}
 


