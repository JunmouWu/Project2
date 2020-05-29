#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define AVAILABLE 0
#define UNAVAILABLE 1
#define MAXNAME 30
#define cls "cls"
#include "Structure.h"
extern Library *head; 
char domanager(){
    char c, flag;
    int i=0;
    while(1){
    	for(i=0; (c = getchar()) != '\n';flag = c,i++);
        if(i==1){
            if(flag=='1'||flag=='2'||flag=='3'||flag=='4'||flag=='0'){
                return flag;
            }
        }else if(i==0){
            continue;
        }
        error("[Input the command£º 1 / 2 / 0. Select your identity]");   
    }
}
char Manager_Login(){
	int Punish=0;
	char id[MAXNAME]={0},pass[MAXNAME]={0};
	Try:
	printf("Manager ID: \n");
	scanf("%s",id);
	fflush(stdin);
	printf("Password: \n");
	scanf("%s",pass);
	fflush(stdin);
	printf("\n");
		if(Punish==5){
			error("The maximum times of tring inputing have reached.");
			exit(0);
		}
	if(!strcmp("Iefan", id) && !strcmp("Aa123456",pass)){
		return 1;
	}
	else if(strcmp("Iefan",id )!=0 && strcmp("Aa123456",pass )==0){
		error("The ID is not correct\n");
		Punish++;
		goto Try;
	}
	else if(strcmp("Aa123456",pass )!=0 && strcmp("Iefan",id )==0 ){
		error("The password is not correct\n");
		Punish++;
		goto Try;
	}
	else if(strcmp("Iefan",id )!=0 && strcmp("Aa123456",pass )!=0){
		error("Sorry, only the manager can use the system\n\n");
		return 0;
	}
	else{
		error("Sorry, only the manager can use the system\n\n");
		return 0;
	}
}
int Manager(){
    printf("-------------------------------------\n");
    printf("What do you want to do next£º\n\n");
    printf("[1] List the stored book\n[2] Add the new book\n[3] Remove the stored book\n[4] List the student information\n");
    printf("[0] Back to the first page\n");
    switch(domanager()){
        case '1':
            viewbook();
            break;
        case '2':
            addbook();
            break;
        case '3':
            delbook();
            break;
        case '4':
        	viewstudent();
        	break;
        case '0':
            return 0;
        default:
            error("Invalid selection");
            break;
    }
    return 1;

}

