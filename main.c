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
        printf("Welcome to clinc app\n");
        printf("PLease choose mode:\n1- Admin Mode\n2- User Mode\n");
        printf("Your Choice:");
        scanf("%hhu", &Mode_choice);
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



