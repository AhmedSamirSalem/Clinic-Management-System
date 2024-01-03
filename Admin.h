#ifndef _ADMIN_H_
#define _ADMIN_H_

#include<stdio.h>
#include<stdlib.h>
#include"STD_TYPES.h"



void Admin_Mode(void);

void Admin_Mode_operations(void);

void Add_Patient(u8 new_patientid);

void Edit_Patient(u8 new_patientid);

void Patient_Reserve_Slot(u8 new_patientid);

void Patient_Cancel_Reserve(u8 new_patientid);

void print(void); // function to make sure i working correctly will not be available in the last version of this app

#define ADMIN_PASS         1234
#define WRONG_PASS_COUNTER 3



#define ADD_PATIENT	   1
#define EDIT_PATIENT   2
#define RESERVE_SLOT   3
#define CANCEL_RESERVE 4
#define PRINT_PATIENT  5


#endif
