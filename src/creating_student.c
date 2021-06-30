
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <unistd.h>

#include "./include/creating_student.h"
#include "./include/starting_page.h"
#include "./include/creating_teacher.h"
#include "./include/updating_student.h"
#include "./include/updating_teacher.h"

int taking_input10()
{
    int response;
    printf("Waiting for your response ...");
    scanf("%d", &response);
    return response;
}

void creating_student_func()
{
    system("cls");
    printf("\n\nThis panel is for creating new student account .. \n\n");
    printf("You should provide student name,\nStudent account password,test marks\n\n");
    printf("If student already exist,it will just update the info\n");
    printf("........................................................\n\n\n");
    char student_name[100], pword[100], test_marks[100];
    printf("Enter student's name : ");
    scanf("%s", student_name);
    printf("\n");

    printf("Enter student's password (10 char only): ");
    scanf("%s", pword);
    printf("\n");
    if (strlen(pword) != 10)
    {
        creating_student_func();
        return;
    }
    printf("Enter student's test_marks : ");
    scanf("%s", test_marks);
    printf("\n");

    char data[300], filename[100];
    int cnt = 0;
    for (int i = 0; i < strlen(student_name); i++)
    {
        data[i] = student_name[i];
        filename[i] = student_name[i];
        cnt++;
    }
    data[cnt] = '\0';
    filename[cnt] = '\0';

    strcat(data, " ");
    strcat(data, pword);
    strcat(data, " ");
    strcat(data, test_marks);

    strcat(filename, ".txt");

    char working_dir[PATH_MAX];
    getcwd(working_dir, sizeof(working_dir));
    strcat(working_dir, "\\info_files\\students\\");
    strcat(working_dir, filename);

    char cmd[PATH_MAX] = "echo ";
    strcat(cmd, data);
    strcat(cmd, " > ");
    strcat(cmd, working_dir);

    system(cmd);

    printf("\nStudent info is successfully updated\n");

    printf("\n\n");

    printf("Press any number from 0 to 4   :  \n");
    printf("If you want to create a new teacher id, enter => 1\n");
    printf("If you wnat to create a new student id, enter => 2\n");
    printf("If you want update teacher info, enter => 3\n");
    printf("If you want update student info, enter => 4\n");
    printf("If you want go main menu,enter => 0");

    int response;
level:
    response = taking_input10();

    if (response == 1)
    {
        creating_teacher_func();
    }
    else if (response == 2)
    {
        creating_student_func();
        return ;
    }
    else if (response == 3)
    {
        updating_teacher_func();
    }
    else if (response == 4)
    {
        updating_student_func();
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