#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define AVAILABLE 0
#define UNAVAILABLE 1
#define MAXNAME 30
#define cls "cls"
#include "Structure.h"
#include "CommonOperation.h"
extern Library *head; 
int borrowbook(){
    system(cls);  
    char sname[MAXNAME];
    printf("Search the book:\n");
        scanf("%s", sname);
        getchar();
        Library *bp;
        char *namep = NULL;
        if((bp = lookup(namep = strdup(sname), 0)) == NULL){
            printf("%s can't be found\n", namep);
            fflush(stdin);
            return 0;
        }else{
            printbook(bp);
            if(! bp->status){
                printf("\nDO you want to borrow it?£º Y N\n");
            }else{
                printf("The book is borrowed by others\n");
                return 0;
            }
            while(1){
                char c = '\0';
                scanf("%c", &c);
                getchar();
                if(!(c == 'Y' || c == 'y' || c == 'N' || c == 'n')){
                    fflush(stdin);
                    error("Invalid command");
                    continue;
                }
                if(c == 'Y' || c == 'y'){
                    --bp->count > -1 ? printf("Operation Succeess\n") : printf("Operation Fail\n");
                    if(! bp->count){
                        bp->status = UNAVAILABLE;
                    }
                    return bp->id;
                }else{
                    return 0;
                }
            }
        }  
    return -1;
}
int returnbook(){
    system(cls);  
    char sname[MAXNAME];
    printf("Return the book£º\n");
    scanf("%s", sname);
    getchar();
    Library *bp;
    char *namep;
    if((bp = lookup(namep = strdup(sname), 0)) == NULL){
        fflush(stdin);
        printf("This book doesn't belong to this library\n");
        return -1;
    }else{
        printbook(bp);
        printf("\nTurn back it?£º Y N\n");
        while(1){
            char c = '\0';
            scanf("%c", &c);
            getchar();
            if(!(c == 'Y' || c == 'y' || c == 'N' || c == 'n')){
                fflush(stdin);
                error("Invalid command");
            }else if(c == 'Y' || c == 'y'){
                bp->count++ ? : (bp->status = AVAILABLE);
                printf("Succeed\n");
                return bp->id;
            }else{
                return 0;
            }
        }
    }

    return -1;
}

