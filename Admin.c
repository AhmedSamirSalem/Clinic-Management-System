#include"DATA.h"
#include"Admin.h"


Patient_t * Head=NULL;

u8 available_sloats[5]={1,1,1,1,1};
void Admin_Mode(void)
{
	u8 Pass_counter=0;
	u16 Admin_Password=0;
	for(Pass_counter=0;Pass_counter<3;Pass_counter++)
	{
		printf("Please Enter Password: ");
		scanf("%hu",&Admin_Password);
		if(ADMIN_PASS==Admin_Password)
		{
			printf("Welcome to clinc App Dr Ahmed\n");
			break;
		}
		else
		{
			printf("Wrong Password Please Try Again\n");
		}
	}
	if(WRONG_PASS_COUNTER==Pass_counter)
	{
		printf("You Enter Password Wrong for 3 times \n");
	}
	else
	{
		Admin_Mode_operations();
	}
}


void Admin_Mode_operations(void)
{
	u8 Admin_Mode_choice;
	u8 new_patientid;
	while(1)
	{
	    printf("\t\t\t=========================\n");
		printf("\t\t\tTo Add New Patient Enter 1\n");
		printf("\t\t\tTo Edit Patient record Enter 2\n");
		printf("\t\t\tTo Reserve a slot with the doctor Enter 3\n");
		printf("\t\t\tTo Cancel reservation Enter 4\n");
		printf("\t\t\tTo view Patient Enter 5\n");
		printf("\t\t\tTo Log Out Enter 6\n");
		printf("\t\t\tYour Choice:");
		scanf("%hhu",&Admin_Mode_choice);
		printf("\t\t\t=========================\n");
		if(Admin_Mode_choice==6)
		{
			break;
		}
		switch(Admin_Mode_choice)
		{
			case ADD_PATIENT:
			{
				printf("please enter patient id \"it must be unique\" ");
				scanf("%hhu",&new_patientid);
				Add_Patient(new_patientid);
				break;
			}
			case EDIT_PATIENT:
			{
				printf("please enter patient id : ");
				scanf("%hhu",&new_patientid);
				Edit_Patient(new_patientid);
				break;
			}
			case RESERVE_SLOT:
            {
				printf("please enter patient id : ");
				scanf("%hhu",&new_patientid);
                Patient_Reserve_Slot(new_patientid);
                break;
            }
			case CANCEL_RESERVE:
            {
				printf("please enter patient id : ");
				scanf("%hhu",&new_patientid);
                Patient_Cancel_Reserve(new_patientid);
                break;

            }
			case PRINT_PATIENT:
			{
				printf("please enter patient id : ");
				scanf("%hhu",&new_patientid);
				print(new_patientid);
				break;
			}
			default:printf("invaild Choice\n");break;
		}
	}

}
void Add_Patient(u8 new_patientid)
{
	Patient_t * New_Patient=(Patient_t * )malloc(sizeof(Patient_t ));
	New_Patient->next=NULL;
	New_Patient->Patient_time=-1;
	if(NULL==Head)
	{
		Head=New_Patient;
		New_Patient->Patient_id=new_patientid;
		fflush(stdin);
		printf("Please Enter Patient name : ");
		scanf("%[^\n]%*c",&New_Patient->Patient_name);
		printf("Please Enter Patient age = ");
		scanf("%d",&New_Patient->Patient_age);
		fflush(stdin);
		printf("Please Enter Patient gender : ");
		scanf("%[^\n]%*c",&New_Patient->Patient_gender);
	}
	else
	{
		Patient_t * Current_Patient=Head;
		while((Current_Patient->next!=NULL) &&(Current_Patient->Patient_id!=new_patientid))
		{
			Current_Patient=Current_Patient->next;
		}
		if(Current_Patient->Patient_id==new_patientid)
		{
			printf("id exists please enter unique id\n");
			free(New_Patient);
		}
		else
		{
			Current_Patient->next=New_Patient;
			New_Patient->Patient_id=new_patientid;
			fflush(stdin);
			printf("Please Enter Patient name : ");
			scanf("%[^\n]%*c",&New_Patient->Patient_name);
			printf("Please Enter Patient age = ");
			scanf("%d",&New_Patient->Patient_age);
			fflush(stdin);
			printf("Please Enter Patient gender : ");
			scanf("%[^\n]%*c",&New_Patient->Patient_gender);
		}
	}
}
void Edit_Patient(u8 new_patientid)
{
	Patient_t * Current_Patient=Head;
	if(Head!=NULL)
    {
       	while((Current_Patient->next!=NULL) &&(Current_Patient->Patient_id!=new_patientid))
        {
            Current_Patient=Current_Patient->next;
        }
        if(Current_Patient->Patient_id==new_patientid)
        {
            fflush(stdin);
            printf("Please Enter Patient name : ");
            scanf("%[^\n]%*c",&Current_Patient->Patient_name);
            printf("Please Enter Patient age = ");
            scanf("%d",&Current_Patient->Patient_age);
            fflush(stdin);
            printf("Please Enter Patient gender : ");
            scanf("%[^\n]%*c",&Current_Patient->Patient_gender);
        }
        else
        {
            printf("The id does not exist \n");
        }
    }
    else
    {
        printf("The id does not exist \n");
    }
}


void Patient_Reserve_Slot(u8 new_patientid)
{
    u8 Patient_Time;
    u8 Time_flag=-1;

    if(available_sloats[0]==1)
    {
        printf("To reserve from 2pm to 2:30pm Enter 1\n");
        Time_flag=0;
    }
    if(available_sloats[1]==1)
    {
        printf("To reserve from 2:30pm  to 3pm Enter 2\n");
        Time_flag=0;
    }
    if(available_sloats[2]==1)
    {
        printf("To reserve from 3pm to 3:30pm Enter 3\n");
        Time_flag=0;
    }
    if(available_sloats[3]==1)
    {
        printf("To reserve from 4pm to 4:30pm Enter 4\n");
        Time_flag=0;
    }
    if(available_sloats[4]==1)
    {
        printf("To reserve from 4:30pm to 5pm Enter 5\n");
        Time_flag=0;
    }
    if(0==Time_flag)
    {
        printf("Your choice: ");
        scanf("%hhu",&Patient_Time);
    }
    else
    {
        //do nothing
    }


    Patient_t * Current_Patient=Head;
    if(Current_Patient!=NULL)
    {
        while((Current_Patient->next!=NULL) &&(Current_Patient->Patient_id!=new_patientid))
        {
            Current_Patient=Current_Patient->next;
        }
        if(Current_Patient->Patient_id==new_patientid)
        {
            if(Current_Patient->Patient_time==-1)
            {
                if(available_sloats[Patient_Time-1]==1)
                {
                    Current_Patient->Patient_time=Patient_Time;
                    available_sloats[Patient_Time-1]=0;
                }
                else
                {
                    printf("You entered wrong time\n");
                }

            }
            else
            {
                printf("The patient already have an appointment with the doctor \n");
            }
        }
        else
        {
            printf("The id does not exist \n");
        }
    }
    else
    {
        printf("The id does not exist \n");
    }
}


void Patient_Cancel_Reserve(u8 new_patientid)
{
    Patient_t * Current_Patient=Head;
    if(Current_Patient!=NULL)
    {
        while((Current_Patient->next!=NULL) &&(Current_Patient->Patient_id!=new_patientid))
        {
            Current_Patient=Current_Patient->next;
        }
        if(Current_Patient->Patient_id==new_patientid)
        {
            if(Current_Patient->Patient_time==-1)
            {
                printf("The patient doesnot have an appointment with the doctor \n");

            }
            else
            {
                available_sloats[Current_Patient->Patient_time-1]=1;
                Current_Patient->Patient_time=-1;
                printf("The appointment has been canceled\n");
            }
        }
        else
        {
            printf("The id does not exist \n");
        }
    }
    else
    {
        printf("The id does not exist \n");
    }

}




void print(u8 new_patientid)
{
		Patient_t * Current_Patient=Head;
	if(Head!=NULL)
    {
       	while((Current_Patient->next!=NULL) &&(Current_Patient->Patient_id!=new_patientid))
        {
            Current_Patient=Current_Patient->next;
        }
        if(Current_Patient->Patient_id==new_patientid)
        {
			printf("Patient id = %d\n",Current_Patient->Patient_id);
			printf("Patient name : %s\n",Current_Patient->Patient_name);
			printf("Patient age = %d\n",Current_Patient->Patient_age);
			printf("Patient gender : %s\n",Current_Patient->Patient_gender);
			if(Current_Patient->Patient_time!=-1)
			{
				printf("Time = %d\n",Current_Patient->Patient_time);
			}
		}
        else
        {
            printf("The id does not exist \n");
        }
    }
    else
    {
        printf("The id does not exist \n");
    }
	
}
