#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <unistd.h>

#include "./include/providing_test_marks.h"
#include "./include/starting_page.h"
#include "./include/count_of_student.h"
#include "./include/finding_student.h"

typedef struct
{
    char name[11];
    char password[11];
    char test_marks[5];
} Student;

int taking_input8()
{
    int response;
    printf("Waiting for your response ...");
    scanf("%d", &response);
    return response;
}

void finding_student_func(){
    system("cls");

    printf("This panel is for finding a student info..\n\n");
    printf("......................................................\n\n");
    printf("\n\n Enter the name of the student : ");
    char student_name[100];
    scanf("%s",student_name);

    char working_dir[PATH_MAX];
    getcwd(working_dir, sizeof(working_dir));
    strcat(working_dir, "\\info_files\\students\\");
    strcat(working_dir,student_name);
    strcat(working_dir,".txt");

    //printf(" this :: %s \n", working_dir);

    FILE* student_file;
    student_file=fopen(working_dir,"r");
    if(student_file==NULL){
        printf("This student does not exist..\n\n");
        printf("\n\n\n");

        printf("Press any number from 0 to 3   :  \n");
        printf("If you want to provide test mark, enter => 1\n");
        printf("If you wnat find another student by first name, enter => 2\n");
        printf("If you want count number of students, enter => 3\n");
        printf("If you want go main menu,enter => 0\n\n\n");

        int response;
    level1:
        response = taking_input8();

        if (response == 1)
        {
            providing_test_marks_func();
        }
        else if (response == 2)
        {
            finding_student_func();
            return;
        }
        else if (response == 3)
        {
            count_of_student_func();
        }
        else if (response == 0)
        {
            welcome();
        }
        else
        {
            goto level1;
        }
    }
    else{
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
        for (; i < strlen(s[2]); i++)
        {
            student.test_marks[i] = s[2][i];
        }
        student.test_marks[i] = '\0';

        printf("\n \n Name : %s \nTest marks : %s \n",student.name,student.test_marks);
        printf("\n\n\n");

        printf("Press any number from 0 to 3   :  \n");
        printf("If you want to provide test mark, enter => 1\n");
        printf("If you wnat find another student by first name, enter => 2\n");
        printf("If you want count number of students, enter => 3\n");
        printf("If you want go main menu,enter => 0\n\n\n");

        int response;
    level:
        response = taking_input8();

        if (response == 1)
        {
            providing_test_marks_func();
        }
        else if (response == 2)
        {
            finding_student_func();
            return;
        }
        else if (response == 3)
        {
            count_of_student_func();
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
}

