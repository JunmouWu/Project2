#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define AVAILABLE 0
#define UNAVAILABLE 1
#define MAXNAME 30
#define cls "cls"
#include "Structure.h"

extern unsigned int uid;
extern Library *head;

int Student_Register(){
	FILE *fpw,*fpr;
	Library *bp;
	int count;
	char *p;
	bp = (Library *)malloc(sizeof (Library));
	fpw=fopen(".\\Database\\List.txt","a");
	fpr=fopen(".\\Database\\List.txt","r");
	char name[MAXNAME];
	char pass[MAXNAME];
	int id=0;
	int size=0;
	while((count=fgetc(fpr))!=EOF){
		if(count=='\n'){
			size++;
		}
		count++;
	}
	printf("%d\n",size);
	printf("What's your name?(Q to quit)\n");
	scanf("%s\n",&name);
	if(getchar()=='q'||getchar()=='Q'){
		fflush(stdin);
		return 2;
	} 
	strcpy(bp->sname,name);
	bp->sid=size;
	printf("Your ID is %d, set your password to use the library system.\n",bp->sid);
	printf("Password: ");
	fflush(stdin);
	scanf("%s",&pass);
	strcpy(bp->spass,pass);
	fprintf(fpw,"%s,%d,%s\n",bp->sname,bp->sid,bp->spass);
	fclose(fpw);
	return 0;
}

int Student_Login(){
	FILE *fp = NULL;
	int sp;
	Library *bp;
	int i=0;
	char *temp=NULL;
	char str[25];
		char *line,*record;	
		char buffer[50];	
		if ((fp = fopen(".\\Database\\List.txt", "at+")) != NULL)	{
			char *result = NULL;
			result= (char*)malloc(sizeof(char));
			int j = 0;
			while ((line = fgets(buffer, sizeof(buffer), fp))!=NULL)
			{
				
				bp = (Library *)malloc(sizeof (Library));
				
				result=strrchr(line,',');
				result=result+1;
				strcpy(str,result);
				int asize=strlen(str);
				str[asize-1]='\0';
				int size=strlen(str);
				strcpy(bp->spass,str);
				bp->next=head;
				head=bp;
			}
			fclose(fp);					
			fp = NULL;
		}
	int Id,count=0;
	char PASS[MAXNAME]={0};
	fflush(stdin);
	printf("What's you log-in ID?(-1 to quit)\n");
	scanf("%d",&Id);
	fflush(stdin);
	if(Id==-1){
		return 0;
	}
	if(Id>=0 && Id<uid){
		printf("Password:");
		scanf("%s",&PASS);
		fflush(stdin);
		for(bp=head;bp!=NULL;bp=bp->next){
			bp->sid=count;
			if(bp->sid==(uid-Id-1)){
				if(strcmp(bp->spass,PASS)==0){
					return 1;
				}else{
					error("The password is wrong\n");
				}
			}
			count++;
		}
	}else{
		printf("Students not found! There is no such a student in the list \n");
		return 0;
	}
}

