

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include "./include/admin_login_page.h"
#include "./include/utilities.h"
#include "./include/admin_menu_page.h"
#include "./include/starting_page.h"


typedef struct{
    char name[10];
    char password[11];
} Admin;

void admin_logging_func(){
    system("cls");
    printf(welcome_admin);
    printf("...........................................\n");
    printf("Enter correct info to log in :\n (you have to enter correct name and password.\nyour password must be 10 char long");

    printf("\nIf want to go back, type name=back \nIf exit, name=exit.. \n\n");
    printf("You can find admin info from\n admin_info.txt file \n\n");

    char admin_name_from_input[100];
    char pword_from_input[10];
    //taking info from user
    //taking name
    printf(" Enter your name : ");
    scanf("%s",admin_name_from_input);
    printf("\n");

    if(strcmp(admin_name_from_input,"back")==0){
        welcome();
        return;
    }
    if(strcmp(admin_name_from_input,"exit")==0){
        exit(0);
    }

    //taking password
    printf(" Enter your password of 10 characters : ");
    scanf("%s", pword_from_input);
    printf("\n");



    FILE* admin_file;
    admin_file=fopen("./info_files/admin_info.txt","r");
    char s[100][100];
    char ch;
    int i=0,j=0;
    while((ch=fgetc(admin_file))!=EOF){
        s[i][j]=ch;
        if(ch==' '){
            s[i][j] = '\0';
            i++;
            j=0;
        }
        else{
            j++;
        }
    }
    Admin admin;
    /* for(int i=0;i<2;i++){
        for(int j=0;j<strlen(s[i]);j++){
            printf("%c",s[i][j]);
        }
        printf(" %d \n",strlen(s[i]));
    } */
     i=0;
    for(;i<strlen(s[0]);i++){
        admin.name[i]=s[0][i];
    }
    admin.name[i]='\0';
    i=0;
    for(;i<strlen(s[1]);i++){
        admin.password[i]=s[1][i];
    }
    admin.password[i]='\0';
    //printf("%s %s",admin.name,admin.password);


    if(strcmp(admin_name_from_input,"back")==0){
        welcome();
        return ;
    }

    if(strcmp(admin_name_from_input,"exit")==0){
        exit(0);
    }

    if(password_verification(pword_from_input,admin.password)==0){
        admin_logging_func();
        return;
    }
    admin_menu_func();

}