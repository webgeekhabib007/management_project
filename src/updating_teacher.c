

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <unistd.h>


#include "./include/updating_teacher.h"
#include "./include/creating_student.h"
#include "./include/creating_teacher.h"
#include "./include/starting_page.h"


typedef struct
{
    char name[11];
    char password[11];
    char course[11];
} Teacher;

int taking_input11()
{
    int response;
    printf("Waiting for your response ...");
    scanf("%d", &response);
    return response;
}

void updating_teacher_func(){
    system("cls");
    printf("This panel for updating teacher info ..\n\n");
    printf("You will enter a teacher name,\nthen programe will look for the existance\nof that teacher.\nif doesn't exist,you wil be asked again\nelse you will update password and course title of that teacher\n\n");
    printf("....................................................\n");
    printf("Enter the name of teacher : ");
    char teacher_name[100];
    scanf("%s",teacher_name);

    char working_dir[PATH_MAX];
    getcwd(working_dir, sizeof(working_dir));
    strcat(working_dir, "\\info_files\\teachers\\");
    strcat(working_dir, teacher_name);
    strcat(working_dir,".txt");
    //printf("this : %s",working_dir);

    FILE *teacher_file;
    teacher_file=fopen(working_dir,"r");
    if(teacher_file==NULL){
        updating_teacher_func();
        return;
    }
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
    
    /* for(int i=0;i<2;i++){
        for(int j=0;j<strlen(s[i]);j++){
            printf("%c",s[i][j]);
        }
        printf(" %d \n",strlen(s[i]));
    } */
    Teacher teacher;
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
    //printf("%s %s",teacher.course,teacher.password);

    printf("Enter password (must be 10 char) : ");
    char pword[100];
    scanf("%s",pword);

    if(strlen(pword)!=10){
        updating_teacher_func();
        return;
    }

    printf("Enter course : ");
    char course[100];
    scanf("%s", course);
    printf("\n");

    int cnt=0;
    for(int i=0;i<strlen(pword);i++){
        teacher.password[i]=pword[i];
        cnt++;
    }
    teacher.password[cnt]='\0';
    cnt=0;
    for(int i=0;i<strlen(course);i++){
        teacher.course[i]=course[i];
        cnt++;
    }
    teacher.course[cnt]='\0';


    char data[300];
    cnt=0;
    for(int i=0;i<strlen(teacher_name);i++){
        data[i]=teacher_name[i];
        cnt++;
    }
    data[cnt]='\0';
    
    strcat(data, " ");
    strcat(data,pword);
    strcat(data, " ");
    strcat(data,course);
    //printf("%s",data);

    char cmd[PATH_MAX] = "echo ";
    strcat(cmd, data);
    strcat(cmd, " > ");
    strcat(cmd, working_dir);

    system(cmd);

    printf("\n teacher info is updated successfully..");

    printf("\n\n");

    printf("Press any number from 0 to 4   :  \n");
    printf("If you want to create a new teacher id, enter => 1\n");
    printf("If you wnat to create a new student id, enter => 2\n");
    printf("If you want update teacher info, enter => 3\n");
    printf("If you want update student info, enter => 4\n");
    printf("If you want go main menu,enter => 0\n\n");

    int response;
level:
    response = taking_input11();

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
        return;
    }
    else if (response == 4)
    {
        printf("student update page");
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