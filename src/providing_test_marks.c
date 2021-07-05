
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <unistd.h>
#include <dirent.h>

#include "./include/providing_test_marks.h"
#include "./include/starting_page.h"
#include "./include/count_of_student.h"
#include "./include/finding_student.h"

int taking_input7()
{
    int response;
    printf("Waiting for your response ...");
    scanf("%d", &response);
    return response;
}

typedef struct
{
    char name[11];
    char password[11];
    char email[100];
    char test_marks1[5];
    char test_marks2[5];
    char roll_no[100];
} Student;

void providing_test_marks_func(){
    system("cls");
    printf("This is test marks for last class test of every student: \n");
    printf(".................................................\n\n");
    
    DIR *d;
    struct dirent *dir;
    d = opendir("./info_files/students/");
    if (d)
    {
        while ((dir = readdir(d)) != NULL)
        {
            if (dir->d_name[0] != '.')
            {
                char working_dir[PATH_MAX];
                getcwd(working_dir, sizeof(working_dir));
                strcat(working_dir, "\\info_files\\students\\");
                strcat(working_dir, dir->d_name);
                FILE *student_info = fopen(working_dir, "r");
                if (student_info == NULL)
                {
                    printf("Failed to load student info..");
                    exit(EXIT_FAILURE);
                }
                char s[100][100];
                char ch;
                int i = 0, j = 0;
                while ((ch = fgetc(student_info)) != EOF)
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
                    printf("\tName : %s\tCourse 1201 : %s\tCourse 1202 : %s\n", student.name, student.test_marks1, student.test_marks2);
            }
        }
        closedir(d);
    }

    printf("\n\n\n");

    printf("Press any number from 0 to 3   :  \n");
    printf("If you want to provide test mark again, enter => 1\n");
    printf("If you wnat find student by first name, enter => 2\n");
    printf("If you want count number of students, enter => 3\n");
    printf("If you want go main menu,enter => 0\n\n\n");

    int response;
level:
    response = taking_input7();

    if (response == 1)
    {
        providing_test_marks_func();
        return ;
    }
    else if (response == 2)
    {
        finding_student_func();
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