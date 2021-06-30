
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <unistd.h>
#include <string.h>

#include "./include/student_login_page.h"
#include "./include/utilities.h"
#include "./include/starting_page.h"
#include "./include/student_menu_page.h"


typedef struct{
    char name[11];
    char password[11];
    char test_marks[5];
} Student;

void student_login_func(){
    system("cls");
    printf(welcome_student);
    printf("...........................................\n");
    printf("Enter correct info to log in :\n (you have to enter correct name and password.\nyour password must be 10 char long");

    printf("\nIf want to go back, type name=back \nIf exit, name=exit.. \n\n");
    printf("You can find student info from\n student_name.txt file \n\n");


    char student_name_from_input[100];
    char pword_from_input[10];
    //taking info from user
    //taking name
    printf(" Enter your name : ");
    scanf("%s", student_name_from_input);
    printf("\n");

    char working_dir[PATH_MAX];
    getcwd(working_dir, sizeof(working_dir));
    strcat(working_dir, "\\info_files\\students\\");
    strcat(working_dir, student_name_from_input);
    strcat(working_dir,".txt");

    //printf("%s \n",working_dir);

    if (strcmp(student_name_from_input, "back") == 0)
    {
        welcome();
        return;
    }
    if (strcmp(student_name_from_input, "exit") == 0)
    {
        exit(0);
    }

    //taking password
    printf(" Enter your password of 10 characters : ");
    scanf("%s", pword_from_input);
    printf("\n");

    FILE *student_file;
    student_file = fopen(working_dir, "r");
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
    fclose(student_file);
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
    //printf("%s %s",admin.name,admin.password);

    

    if (password_verification(pword_from_input, student.password) == 0)
    {
       student_login_func();
        return;
    }
    student_menu_func();
}