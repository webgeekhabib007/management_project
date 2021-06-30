
#include <stdio.h>
#include <stdlib.h>

#include "./include/student_menu_page.h"
#include "./include/starting_page.h"
#include "./include/student_test_mark_checking_page.h"

int taking_input4()
{
    int response;
    printf("Waiting for your response ...");
    scanf("%d", &response);
    return response;
}

void student_menu_func(){
    system("cls");

    printf("Welcome to teacher menu panel \nWhere admin does his stuff.. \n");
    printf(".....................................\n\n\n");

    printf("Press any number from 0 to 1   :  \n");
    printf("If you want to check your test marks, enter => 1\n");
    printf("If you want go main menu,enter => 0\n\n\n");

    int response;
level:
    response = taking_input4();

    if (response == 1)
    {
        student_test_mark_checking_func();
    }
    else if (response == 0)
    {
        welcome();
    }
    else
    {
        goto level;
    }
}