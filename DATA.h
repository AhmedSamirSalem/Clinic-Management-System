#ifndef _DATA_H_
#define _DATA_H_
#include"STD_TYPES.h"
typedef struct Patient
{
	u8 Patient_name[30];
	u8 Patient_age;
	u8 Patient_gender[7];
	u8 Patient_id;
	s8 Patient_time;
	struct Patient * next;
}Patient_t;

#endif
