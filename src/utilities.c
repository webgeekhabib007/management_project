#include<stdio.h>
#include<string.h>
#include <stdlib.h>


#include "./include/utilities.h"


int password_verification(char pword[],char original[]){
    if(strlen(pword)!=10){
        return 0;
    }
    if( strcmp(pword,original)==0)return 1;
    else return 0;
}

int name_verification(char pword[],char original[]){
    if(strlen(pword) !=strlen(original)){
        return 0;
    }
    
    if( strcmp(pword,original)==0)return 1;
    else return 0;
}

