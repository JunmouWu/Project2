#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define AVAILABLE 0
#define UNAVAILABLE 1
#define MAXNAME 30
#define cls "cls"
#include "Structure.h"
extern Library *head; 
extern unsigned int uid;
void BookIni();

void Initial(){
	int Scount,Ssize=0;
	
	int bid,bname[10],bcount,bstatus;
	
	FILE *fps,*fpb;
	Library *bp;
	fps=fopen(".\\Database\\List.txt","r");
	fpb=fopen(".\\Database\\BookList.txt","at+");
	char str[25];
	char *lines,*record;	
	char buffer[50];	
	if ((fpb = fopen(".\\Database\\List.txt", "at+")) != NULL)	{
	char *result = NULL;
	result= (char*)malloc(sizeof(char));
	int j = 0;
		while ((lines = fgets(buffer, sizeof(buffer), fpb))!=NULL)
			{
				
				bp = (Library *)malloc(sizeof (Library));
				result=strrchr(lines,',');
				result=result+1;
				strcpy(str,result);
				int asize=strlen(str);
				str[asize-1]='\0';
				bp->name=str;
				bp->next=head;
				head=bp;
			}
			fclose(fpb);					
			fpb= NULL;
		}
		
	
	//BookIni();
	///////////////////////////////
	while((Scount=fgetc(fps))!=EOF){
		if(Scount=='\n'){
			Ssize++;
		}
		Scount++;
	}
	uid=Ssize;
	printf("%d\n",uid);
	
}//

void BookIni(){
	int Bcount,Bsize=0,line=0,n=0;
	int id, status, amount;
	FILE *fpb=fopen(".\\Database\\BookList.txt","at+");
	Library *bp;
	while((Bcount=fgetc(fpb))!=EOF){
		printf("%d",Bcount);
		status=Bcount;//´ò±ê¼Ç 

		
		start:
		if(Bcount==','){
			Bsize++;
			if(Bsize==4*line+1){
				Bcount++;
				for(n=0;n<3;n++){
					id=10*(3-n)*Bcount+id;
					Bcount++;
				}
			}
			if(Bsize==4*line+2){
				Bcount++;
				for(n=0;n<2;n++){
					amount=amount+10*(2-n)*Bcount;
					Bcount++;
				}
			}
			if(Bsize==4*line+3){
				Bcount++;
			}
			goto start;
		}
		if(Bcount=='\n'){
			Bsize++;
			Bcount++;
		}
		if(Bsize%4==0){
			line++;	
		}
		bp->id=id;
		
	}
}
void error(char *s){
    fprintf(stderr, "%s\n", s);
}


char stage(){
    char c, flag;
    int i=0;
    while(1){
		for(i = 0; (c = getchar()) != '\n';flag = c,i++);
        if(i == 1){
            if(flag == '1' || flag == '2' || flag == '0'){
                return flag;
            }
        }else if(i == 0){
            continue;
        }
        error("[Input the command£º 1 / 2 / 0. Select your identity]");
    }
    return '\0';
}
void welcome(){
	Library *bp;
	Initial();
    printf("*************************Welcome using library information system*************************\n");
    while(1){
        printf("-------------------------------------\n");
        printf("Command what do you what to do:\n");
        printf("\n[1] Manager entrance\n\n[2] Student entrance\n\n[0] Exit\n\n");
        switch(stage()){
            case '1':
            	if(Manager_Login()==1){
	                while(1){
    	            	if(Manager()){
        	        		continue;
						}else{
							break;
						}
					}
				}
                break;
            case '2':
	                while(1){
    	            	if(Student_page()){
        	        		continue;
						}else{
							break;
						}
					}
                break;
            case '0':
                exit(0);
            default:
                error("Invalid selection");
        }
    }
} 
