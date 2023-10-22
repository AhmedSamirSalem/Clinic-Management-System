#include"DATA.h"
#include"User.h"

extern Patient_t * Head;

void User_Mode_Operations(void)
{
	u8 User_Mode_choice=0;
	u8 new_patientid=0;
	printf("To View Patient Record Enter 1\n");
	printf("To View today ’s reservations Enter 2\n");
	printf("Your Choice:");
	scanf("%hhu",&User_Mode_choice);
	switch(User_Mode_choice)
	{
		case VIEW_PATIENT:
		{
			printf("please enter patient id ");
			scanf("%hhu",&new_patientid); 
			View_Patient_Record(new_patientid);
			break;
		}
		case VIEW_RESERVATIONS:
		{
			break;
		}
		default:
		{
			printf("invaild Choice\n");
			break;
		}
	}
}



void View_Patient_Record(u8 new_patientid)
{
	if(Head!=NULL)
	{
		Patient_t * Current_Patient=Head;
		while((Current_Patient->next!=NULL) &&(Current_Patient->Patient_id!=new_patientid))
		{
			Current_Patient=Current_Patient->next;
		}
		if(Current_Patient->Patient_id==new_patientid )
		{	
			printf("Patient id = %hhu\n",Current_Patient->Patient_id);
			printf("Patient name : %s\n",Current_Patient->Patient_name);
			printf("Patient age = %hhu\n",Current_Patient->Patient_age);	
			printf("Patient gender : %s\n",Current_Patient->Patient_gender);
		}
		else
		{
			printf("The id does not exist \n");
		}
	}
	else
	{
		//do nothing
	}
}