#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define AVAILABLE 0
#define UNAVAILABLE 1
#define MAXNAME 30
#define cls "cls"
#include "Structure.h"

char dostudent(){
    char c, flag;
    int i=0;
    while(1){
    	for(i = 0; (c = getchar()) != '\n';flag = c,i++);
        if(i == 1){
            if(flag == '1' || flag == '2' || flag == '3' || flag == '0'){
                return flag;
            }
        }else if(i == 0){
            continue;
        }
        error("[Input the command£º 1 / 2 / 0. Select your identity]");
    }
}
int Student(){
	system(cls);  
    printf("-------------------------------------\n");
    printf("What do you want to do next£º\n\n");
    printf("[1] Borrow the book\n[2] Return the book\n[3] List library books\n");
    printf("[0] Back to the main menu\n");
    switch(dostudent()){
        case '1':
            borrowbook();
            break;
        case '2':
            returnbook();
            break;
        case '3':
            viewbook();
            break;
        case '0':
            welcome();
        default:
            error("Invalid selection");
            break;
    }
    return 1;
}

int Student_page(){
	system(cls);  
	while(1){
		printf("-------------------------------------\n");
        printf("\n[1] Login \n\n[2] Register\n\n[0] Exit\n\n");
        switch(dostudent()){
        	case '1':
        		while(1){
        			if(Student_Login()==1){
        				Student();
        				break;
					}else if(Student_Login()==0){
						break;
					} 
					else{
						break;
					}
				}
				break;
			case '2':
				while(1){
					if(Student_Register()==0){
						continue;
					}else{
						break;
					}
				}
				break;
			case '0':
				return 0;
			default:
				error("Invalid selection");
		}
	}
}

