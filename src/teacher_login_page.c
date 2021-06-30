
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <unistd.h>

#include "./include/teacher_login_page.h"
#include "./include/utilities.h"
#include "./include/starting_page.h"
#include "./include/teacher_menu_page.h"

typedef struct{
    char name[11];
    char password[11];
    char course[11];
} Teacher;

void teacher_login_func(){
    system("cls");
    printf(welcome_teacher);
    printf("...........................................\n");
    printf("Enter correct info to log in :\n (you have to enter correct name and password.\nyour password must be 10 char long");

    printf("\nIf want to go back, type name=back \nIf exit, name=exit.. \n\n");
    printf("You can find teacher info from\n teacher_name.txt file \n\n");

    char teacher_name_from_input[100];
    char pword_from_input[10];
    //char course_from_input[10];
    //taking info from user
    //taking name
    printf(" Enter your name : ");
    scanf("%s", teacher_name_from_input);
    

    char working_dir[PATH_MAX];
    getcwd(working_dir, sizeof(working_dir));
    strcat(working_dir, "\\info_files\\teachers\\");
    strcat(working_dir, teacher_name_from_input);
    strcat(working_dir, ".txt");

    if (strcmp(teacher_name_from_input, "back") == 0)
    {
        welcome();
        return;
    }
    if (strcmp(teacher_name_from_input, "exit") == 0)
    {
        exit(0);
    }

    //taking password
    printf(" Enter your password (must be 10 char) : ");
    scanf("%s", pword_from_input);
    printf("\n");

    //printf("%s\n",working_dir);
    FILE *teacher_file;
    teacher_file = fopen(working_dir, "r");
    char s[100][100];
    char ch;
    int i = 0, j = 0;
    while ((ch = fgetc(teacher_file)) != EOF)
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
    Teacher teacher;
    /* for(int i=0;i<2;i++){
        for(int j=0;j<strlen(s[i]);j++){
            printf("%c",s[i][j]);
        }
        printf(" %d \n",strlen(s[i]));
    } */
    i = 0;
    for (; i < strlen(s[0]); i++)
    {
        teacher.name[i] = s[0][i];
    }
    teacher.name[i] = '\0';
    i = 0;
    for (; i < strlen(s[1]); i++)
    {
        teacher.password[i] = s[1][i];
    }
    teacher.password[i] = '\0';
    i = 0;
    for (; i < strlen(s[2]); i++)
    {
        teacher.course[i] = s[2][i];
    }
    teacher.course[i] = '\0';
    //printf("%s %s",admin.name,admin.password);

    

    if (password_verification(pword_from_input, teacher.password) == 0)
    {
        printf("Enter correct password to log in..");
        teacher_login_func();
        return;
    }
    teacher_menu_func();
    //printf("%s %s %s",teacher.name,teacher.password,teacher.course);
}

