#include <stdio.h>
#include <stdlib.h>

#include "./include/admin_menu_page.h"
#include "./include/starting_page.h"
#include "./include/creating_teacher.h"
#include "./include/creating_student.h"
#include "./include/updating_teacher.h"
#include "./include/updating_student.h"

int taking_input2()
{
    int response;
    printf("Waiting for your response ...");
    scanf("%d", &response);
    return response;
}

void admin_menu_func(){
    system("cls");

    printf("Welcome to admin menu panel \nWhere admin does his stuff.. \n");
    printf(".....................................\n\n\n");

    printf("Press any number from 0 to 4   :  \n");
    printf("If you want to create a new teacher id, enter => 1\n");
    printf("If you wnat to create a new student id, enter => 2\n");
    printf("If you want update teacher info, enter => 3\n");
    printf("If you want update student info, enter => 4\n");
    printf("If you want go main menu,enter => 0\n\n");

    //taking response and selecting next step

    int response;
    level:
    response=taking_input2();
    
    if (response == 1)
    {
        creating_teacher_func();
    }
    else if (response == 2)
    {
        creating_student_func();
    }
    else if (response == 3)
    {
        updating_teacher_func();
    }
    else if(response==4)
    {
        updating_student_func();
    }
    else if(response==0){
        welcome();
    }
    else{
        goto level;
    }
}