#include"DATA.h"
#include"Admin.h"


Patient_t * Head=NULL;
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
		printf("To Add New Patient Enter 1\n");
		printf("To Edit Patient record Enter 2\n");
		printf("To Reserve a slot with the doctor Enter 3\n");
		printf("To Cancel reservation Enter 4\n");
		printf("To view Patient Enter5\n");
		printf("To Log Out Enter6\n");
		printf("Your Choice:");
		scanf("%hhu",&Admin_Mode_choice);
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
			case CANCEL_RESERVE:
			case PRINT_PATIENT:
			{
				// print();
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


/*void print(void)
{
	Patient_t * Current_Patient=Head;
	while(Current_Patient->next!=NULL)
	{
		printf("Patient id = %d\n",Current_Patient->Patient_id);
		printf("Patient name : %s\n",Current_Patient->Patient_name);
		printf("Patient age = %d\n",Current_Patient->Patient_age);	
		printf("Patient gender : %s\n",Current_Patient->Patient_gender);
		Current_Patient=Current_Patient->next;
	}
		printf("Patient id = %d\n",Current_Patient->Patient_id);
		printf("Patient name : %s\n",Current_Patient->Patient_name);
		printf("Patient age = %d\n",Current_Patient->Patient_age);	
		printf("Patient gender : %s\n",Current_Patient->Patient_gender);	
		
}*/