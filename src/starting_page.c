#include <stdio.h>
#include <stdlib.h>

#include "./include/admin_login_page.h"
#include "./include/teacher_login_page.h"
#include "./include/student_login_page.h"

int taking_input(){
    int response;
    printf("Waiting for your response ...");
    scanf("%d", &response);
    return response;
}

void welcome(){
    system("cls");

    printf("Welcome to Batch 2k19 management software.. \n where one can create/update teacher/student info.\n");
    printf(".......................................................");
    printf("\n\n\n");

    printf("Press any number from 0 to 3   :  \n");
    printf("If you are the admin of this software, enter => 1\n");
    printf("If you are a teacher, enter => 2\n");
    printf("If you are a student, enter => 3\n");
    printf("If you want exit, enter => 0\n\n\n");

    int response;
    level:
    response=taking_input();
    
    if (response == 1)
    {
        admin_logging_func();
    }
    else if (response == 2)
    {
        teacher_login_func();
    }
    else if (response == 3)
    {
        student_login_func();
    }
    else if(response==0)
    {
        exit(0);
    }
    else{
        goto level;
    }
}
