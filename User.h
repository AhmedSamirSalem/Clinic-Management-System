#ifndef _USER_H_
#define _USER_H_

#include<stdio.h>
#include"STD_TYPES.h"

void User_Mode_Operations(void);

void View_Patient_Record(u8 new_patientid);


#define VIEW_PATIENT  	  1
#define VIEW_RESERVATIONS 2



#endif