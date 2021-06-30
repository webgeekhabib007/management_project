
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <unistd.h>

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

void providing_test_marks_func(){
    system("cls");
    printf("This is your test marks for last class test: \n");
    printf(".................................................\n\n");

    FILE* marks;
    marks=fopen("./info_files/test_marks.txt","r");
    char ch;
    char mark[6];
    int roll=1,idx=0;
    while((ch=fgetc(marks)) != EOF){
        //printf("%c",ch);
        if(ch==' '){
            printf("Roll %d => %s\n",roll,mark);
            mark[0]='\0';
            idx=0;
            roll++;
        }
        else{
            mark[idx]=ch;
            idx++;
        }
    }
    fclose(marks);

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