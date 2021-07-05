

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <unistd.h>

#include "./include/updating_teacher.h"
#include "./include/creating_student.h"
#include "./include/creating_teacher.h"
#include "./include/starting_page.h"
#include "./include/updating_student.h"

typedef struct
{
    char name[11];
    char password[11];
    char email[100];
    char test_marks1[5];
    char test_marks2[5];
    char roll_no[100];
} Student;
int taking_input12()
{
    int response;
    printf("Waiting for your response ...");
    scanf("%d", &response);
    return response;
}

void updating_student_func()
{
    system("cls");
    printf("This panel for updating teacher info ..\n\n");
    printf("You will enter a student name,\nthen programe will look for the existance\nof that student.\nif doesn't exist,you wil be asked again\nelse you will update password and test marks of that student\n\n");
    printf("....................................................\n");

    printf("Enter the name of student : ");
    char student_name[100];
    scanf("%s", student_name);

    char working_dir[PATH_MAX];
    getcwd(working_dir, sizeof(working_dir));
    strcat(working_dir, "\\info_files\\students\\");
    strcat(working_dir, student_name);
    strcat(working_dir, ".txt");
    //printf("this : %s",working_dir);

    FILE *student_file;
    student_file = fopen(working_dir, "r");
    if (student_file == NULL)
    {
        updating_student_func();
        return;
    }
    char s[100][100];
    char ch;
    int i = 0, j = 0;
    while ((ch = fgetc(student_file)) != EOF)
    {
        s[i][j] = ch;
        if (ch == ' ')
        {
            s[i][j] = '\0';
            i++;
            j = 0;
        }
        else
        {
            j++;
        }
    }
    Student student;
    /* for(int i=0;i<2;i++){
        for(int j=0;j<strlen(s[i]);j++){
            printf("%c",s[i][j]);
        }
        printf(" %d \n",strlen(s[i]));
    } */
    i = 0;
    for (; i < strlen(s[0]); i++)
    {
        student.name[i] = s[0][i];
    }
    student.name[i] = '\0';
    i = 0;
    for (; i < strlen(s[1]); i++)
    {
        student.password[i] = s[1][i];
    }
    student.password[i] = '\0';
    i = 0;
    for (; i < strlen(s[2]); i++)
    {
        student.roll_no[i] = s[2][i];
    }
    student.roll_no[i] = '\0';
    i = 0;
    for (; i < strlen(s[3]); i++)
    {
        student.email[i] = s[3][i];
    }
    student.email[i] = '\0';
    i=0;
    for (; i < strlen(s[4]); i++)
    {
        student.test_marks1[i] = s[4][i];
    }
    student.test_marks1[i] = '\0';
    i = 0;
    for (; i < strlen(s[5]); i++)
    {
        student.test_marks2[i] = s[5][i];
    }
    student.test_marks2[i] = '\0';
    //printf("%s %s",teacher.course,teacher.password);

    printf("Enter password (must be 10 char) : ");
    char pword[100];
    scanf("%s", pword);
    //printf("\n");

    if (strlen(pword) != 10)
    {
        updating_student_func();
        return;
    }

    printf("Enter test marks of course 1201 : ");
    char test_marks1[100];
    scanf("%s", test_marks1);
   
    printf("Enter test marks of course 1202 : ");
    char test_marks2[100];
    scanf("%s", test_marks2);
    printf("\n");

    int cnt = 0;
    for (int i = 0; i < strlen(pword); i++)
    {
        student.password[i] = pword[i];
        cnt++;
    }
    student.password[cnt] = '\0';
    cnt = 0;
    for (int i = 0; i < strlen(test_marks1); i++)
    {
        student.test_marks1[i] = test_marks1[i];
        cnt++;
    }
    student.test_marks1[cnt] = '\0';

    cnt = 0;
    for (int i = 0; i < strlen(test_marks2); i++)
    {
        student.test_marks2[i] = test_marks2[i];
        cnt++;
    }
    student.test_marks2[cnt] = '\0';

    char data[300];
    cnt = 0;
    for (int i = 0; i < strlen(student_name); i++)
    {
        data[i] = student_name[i];
        cnt++;
    }
    data[cnt] = '\0';

    strcat(data, " ");
    strcat(data, pword);
    strcat(data, " ");
    strcat(data, student.roll_no);
    strcat(data, " ");
    strcat(data, student.email);
    strcat(data, " ");
    strcat(data, student.test_marks1);
    strcat(data, " ");
    strcat(data, student.test_marks2);
    //printf("%s",data);

    char cmd[PATH_MAX] = "echo ";
    strcat(cmd, data);
    strcat(cmd, " > ");
    strcat(cmd, working_dir);

    system(cmd);
    //printf("%s",cmd);

    printf("\n Student info is updated successfully..");

    printf("\n\n");

    printf("Press any number from 0 to 4   :  \n");
    printf("If you want to create a new teacher id, enter => 1\n");
    printf("If you wnat to create a new student id, enter => 2\n");
    printf("If you want update teacher info, enter => 3\n");
    printf("If you want update student info, enter => 4\n");
    printf("If you want go main menu,enter => 0\n\n");

    int response;
level:
    response = taking_input12();

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
    else if (response == 4)
    {
        updating_student_func();
        return;
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