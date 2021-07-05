#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<limits.h>
#include<unistd.h>

#include "./include/count_of_student.h"
#include "./include/starting_page.h"
#include "./include/providing_test_marks.h"
#include "./include/finding_student.h"

int taking_input6()
{
    int response;
    printf("Waiting for your response ...");
    scanf("%d", &response);
    return response;
}

void count_of_student_func(){
    system("cls");

    //reading current working directory 
    // concatenate with students directtory
    char working_dir[PATH_MAX];
    getcwd(working_dir,sizeof(working_dir));
    strcat(working_dir,"\\info_files\\students");

    printf(" this :: %s \n",working_dir);

    //creating system command to create new student_name.txt file
    char cmd_to_find_num[PATH_MAX]="dir /a:-d /s /b \"";
    strcat(cmd_to_find_num,working_dir);
    strcat(cmd_to_find_num,"\" | find /v /c \"::\"");
    printf("\n\nThe Total number of students is :  ");
    system(cmd_to_find_num);

    printf("\n\n\n");


    printf("Press any number from 0 to 3   :  \n");
    printf("If you want to provide test mark, enter => 1\n");
    printf("If you wnat find student by first name, enter => 2\n");
    printf("If you want count number of students again, enter => 3\n");
    printf("If you want go main menu,enter => 0\n\n\n");

    int response;
level:
    response = taking_input6();

    if (response == 1)
    {
        providing_test_marks_func();
    }
    else if (response == 2)
    {
        finding_student_func();
    }
    else if (response == 3)
    {
        count_of_student_func();
        return ;
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