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
		    View_today_Reservations();
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


void View_today_Reservations(void)
{
    if(Head!=NULL)
	{
		Patient_t * Current_Patient=Head;
		while((Current_Patient->next!=NULL) )
		{
			if(Current_Patient->Patient_time!=-1)
            {
                switch(Current_Patient->Patient_time)
                {
                    case 1:
                    {
                        printf("Patient id = %hhu have appointment from 2pm to 2:30pm\n",Current_Patient->Patient_id);
                        break;
                    }
                    case 2:
                    {
                        printf("Patient id = %hhu have appointment from 2:30pm to 3pm\n",Current_Patient->Patient_id);
                        break;
                    }
                    case 3:
                    {
                        printf("Patient id = %hhu have appointment from 3pm to 3:30pm\n",Current_Patient->Patient_id);
                        break;
                    }
                    case 4:
                    {
                        printf("Patient id = %hhu have appointment from 4pm to 4:30pm\n",Current_Patient->Patient_id);
                        break;
                    }
                    case 5:
                    {
                        printf("Patient id = %hhu have appointment from 4:30pm to 5pm\n",Current_Patient->Patient_id);
                        break;
                    }
                    default :break;// do nothing
                }
            }
            Current_Patient=Current_Patient->next;
		}
			if(Current_Patient->Patient_time!=-1)
            {
                switch(Current_Patient->Patient_time)
                {
                    case 1:
                    {
                        printf("Patient id = %hhu have appointment from 2pm to 2:30pm\n",Current_Patient->Patient_id);
                        break;
                    }
                    case 2:
                    {
                        printf("Patient id = %hhu have appointment from 2:30pm to 3pm\n",Current_Patient->Patient_id);
                        break;
                    }
                    case 3:
                    {
                        printf("Patient id = %hhu have appointment from 3pm to 3:30pm\n",Current_Patient->Patient_id);
                        break;
                    }
                    case 4:
                    {
                        printf("Patient id = %hhu have appointment from 4pm to 4:30pm\n",Current_Patient->Patient_id);
                        break;
                    }
                    case 5:
                    {
                        printf("Patient id = %hhu have appointment from 4:30pm to 5pm\n",Current_Patient->Patient_id);
                        break;
                    }
                    default :break;// do nothing
                }
            }
	}
	else
	{
		//do nothing
	}



}
