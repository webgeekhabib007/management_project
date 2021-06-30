
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <unistd.h>

#include "./include/creating_teacher.h"
#include "./include/starting_page.h"
#include "./include/creating_student.h"
#include "./include/updating_student.h"
#include "./include/updating_teacher.h"

int taking_input9()
{
    int response;
    printf("Waiting for your response ...");
    scanf("%d", &response);
    return response;
}

void creating_teacher_func(){
    system("cls");
    printf("\n\nThis panel is for creating new teacher account .. \n\n");
    printf("You should provide teacher name,\nTeacher account password,course title\n\n");
    printf("If teacher already exist,it will just update the info\n");
    printf("........................................................\n\n\n");
    char teacher_name[100],pword[100],course[100];
    printf("Enter teacher's name : ");
    scanf("%s",teacher_name);
    printf("\n");

    printf("Enter teacher's password (must be 10 char long): ");
    scanf("%s", pword);
    printf("\n");
    if(strlen(pword)!=10){
        creating_teacher_func();
        return ;
    }
    printf("Enter teacher's course : ");
    scanf("%s", course);
    printf("\n");

    char data[300],filename[100];
    int cnt=0;
    for(int i=0;i<strlen(teacher_name);i++){
        data[i]=teacher_name[i];
        filename[i]=teacher_name[i];
        cnt++;
    }
    data[cnt]='\0';
    filename[cnt]='\0';
    
    strcat(data, " ");
    strcat(data,pword);
    strcat(data, " ");
    strcat(data,course);
    
    strcat(filename,".txt");

    char working_dir[PATH_MAX];
    getcwd(working_dir,sizeof(working_dir));
    strcat(working_dir,"\\info_files\\teachers\\");
    strcat(working_dir,filename);

    char cmd[PATH_MAX]="echo ";
    strcat(cmd,data);
    strcat(cmd," > ");
    strcat(cmd,working_dir);
    
    system(cmd);

    printf("\nTeacher info is successfully updated..");

    printf("\n\n");

    printf("Press any number from 0 to 4   :  \n");
    printf("If you want to create a new teacher id, enter => 1\n");
    printf("If you wnat to create a new student id, enter => 2\n");
    printf("If you want update teacher info, enter => 3\n");
    printf("If you want update student info, enter => 4\n");
    printf("If you want go main menu,enter => 0\n\n");

    int response;
level:
    response = taking_input9();

    if (response == 1)
    {
        creating_teacher_func();
        return;
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