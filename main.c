#include<stdio.h>
#include"STD_TYPES.h"
#include"Admin.h"
#include"User.h"


#define ADMIN_MODE 1
#define USER_MODE 2
int main(void)
{
    u8 Mode_choice = 0;
    while (1)
    {
        printf("\t\t\t=========================\n");
        printf("\t\t\tWelcome to clinc app\n");
        printf("\t\t\tThis is made by Ahmed Samir Salem \n");
        printf("\t\t\tPLease choose mode:\n\t\t\t1- Admin Mode\n\t\t\t2- User Mode\n");
        printf("\t\t\tYour Choice:");
        scanf("%hhu", &Mode_choice);
        printf("\t\t\t=========================\n");
        switch (Mode_choice)
        {
        case ADMIN_MODE:
        {
            Admin_Mode();
            break;
        }
        case USER_MODE:
        {
            User_Mode_Operations();
            break;
        }

        default:
            printf("Invalid Choice\n");
            break;
        }
    }

    return 0;
}



