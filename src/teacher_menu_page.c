#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "./include/teacher_menu_page.h"
#include "./include/starting_page.h"
#include "./include/count_of_student.h"
#include "./include/providing_test_marks.h"
#include "./include/finding_student.h"

int taking_input3()
{
    int response;
    printf("Waiting for your response ...");
    scanf("%d", &response);
    return response;
}

void teacher_menu_func(){
    system("cls");

    printf("Welcome to teacher menu panel \nWhere admin does his stuff.. \n");
    printf(".....................................\n\n\n");

    printf("Press any number from 0 to 3   :  \n");
    printf("If you want to provide test mark, enter => 1\n");
    printf("If you wnat find student by first name, enter => 2\n");
    printf("If you want count number of students, enter => 3\n");
    printf("If you want go main menu,enter => 0\n\n\n");

    int response;
level:
    response = taking_input3();

    if (response == 1)
    {
        providing_test_marks_func();
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