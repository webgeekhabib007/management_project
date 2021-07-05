
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "./include/student_test_mark_checking_page.h"
#include "./include/starting_page.h"

typedef struct
{
    char name[11];
    char password[11];
    char email[100];
    char test_marks1[5];
    char test_marks2[5];
    char roll_no[100];
} Student;

int taking_input5()
{
    int response;
    printf("Waiting for your response ...");
    scanf("%d", &response);
    return response;
}

void student_test_mark_checking_func(){
    system("cls");
    printf("Here you can see your test result : .. \n");
    printf("...............................................\n");
    printf("If you enter a wrong name,\nYou will be asked again\n\n\n");
    

    char student_name_from_input[11];
    printf("Enter your name correctly to see your marks : ");
    scanf("%s",student_name_from_input);
    printf("\n");

    char students_file_dir[100]= "./info_files/students/";
    strcat(students_file_dir,student_name_from_input);
    strcat(students_file_dir,".txt");

    //printf("%s",students_file_dir);

    FILE *student_file;
    student_file = fopen(students_file_dir, "r");
    if(student_file==NULL){
        student_test_mark_checking_func();
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
    i = 0;
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
    printf("Here is your test marks :  \n");
    printf("Course 1201  : %s\nCourse 1202  : %s \n\n",student.test_marks1,student.test_marks2);

    printf("Press any number from 0 to 1   :  \n");
    printf("If you want to check test marks again, enter => 1\n");
    printf("If you want go main menu,enter => 0\n\n\n");

    int response;
level:
    response = taking_input5();

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