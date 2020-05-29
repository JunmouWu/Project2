#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define AVAILABLE 0
#define UNAVAILABLE 1
#define MAXNAME 30
#define cls "cls"
#include "Structure.h"
#include "CommonOperation.h"
extern int nbook;
extern Library *head;

int addbook(){
    system(cls);  
	FILE *fpw;///////////////////////////////////////////
    char sname[MAXNAME];
    int id, count;
    char *namep;
	fpw=fopen(".\\Database\\BookList.txt","a");
	
	
    while(1){
        id = 0;
        count = 0;
        namep = NULL;
        printf("Input the name of the book：\n");
        scanf("%s", sname);
        
        ID:
        printf("Input the book ID within 1000：\n");
        scanf("%d", &id);
        getchar();
        if(!(id > 0 && id < 1000)){
            error("Input invalid");
            fflush(stdin);
            goto ID;
        }
        
        NUM:
        printf("Input the amount of book within 50：\n");
        scanf("%d", &count);
        getchar();
        if(!(count > 0 && count < 50)){
            error("Invalid input");
            fflush(stdin);
            goto NUM;
        }
        
        Library *bp;        
        if((bp = lookup(namep = strdup(sname), id)) == NULL){
            bp = (Library *)malloc(sizeof (Library));
            if(bp == NULL || (bp->name = namep) == NULL){
                error("Fail to register the book");
                fflush(stdin);
                continue;
            }
            bp->id = id;
            bp->count = count;
            bp->status = AVAILABLE;
            ++nbook;
            
            fprintf(fpw,"%d,%d,%d,%s\n",bp->status,bp->id,bp->count,bp->name);
            bp->next = head;
            head = bp;
            printf("Successfully registering the new book\n", sname);
            fclose(fpw);
            return id;
        }else{
            fflush(stdin);
            error("The name or the ID has been uesed");
        }
    }

    return -1;
}
int delbook(){
    system(cls);        
    Library *bp, *fbp;
    
    int id = 0;
    printf("Please input the ID of the target book：\n");
    scanf("%d", &id);
    getchar();
    if(!(id > 0 && id < 1000)){
        fflush(stdin);
        error("The ID is invalid\n");
        return -1;
    }
    for(fbp = bp = head; bp != NULL; fbp = bp, bp = bp->next){
        if(bp->id == id){
            printbook(bp);
            break;
        }
    }
    if(bp != NULL){
        while(1){
            printf("Ensure to delete this book：Y  N\n");
            char YN;
            scanf("%c", &YN);
            getchar();
            if(!((YN == 'Y' || YN == 'y') || (YN == 'N' || YN == 'n'))){
                fflush(stdin);
                error("Command invalid\n");
                continue;
            }
            if(YN == 'Y' || YN == 'y'){
                bp == head ? head = bp->next : (fbp->next = bp->next);
                free(bp->name);                                         //2018-05-26修改：添加释放name这块内存//bp内存的只是指向name的指针
                free(bp);
                bp = NULL;
                printf("Successful delete\n");
                break;
            }else{
                printf("Give up deleting\n");
                return 0;
            }
        }  
        return id;
    }else{
        printf("The ID doesn't occur\n");
        return -1;
    }
    return -1;
}

