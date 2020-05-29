#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define AVAILABLE 0
#define UNAVAILABLE 1
#define MAXNAME 30
#define cls "cls"
#include "Structure.h"
extern Library *head;
extern int nbook;
extern int uid;
Library *lookup(char *s, int id){
    Library *bp;
    for(bp = head; bp != NULL; bp = bp->next){
        if(id == bp->id || strcmp(s, bp->name) == 0){
            return bp;
        }
    }
    return NULL;
}
void printbook(Library *bp){
    printf("Book ID£º%d\n", bp->id);
    printf("Book name£º%s\n", bp->name);
    printf("Amount of book£º%d\n", bp->count);
    printf("Status of book£º%s\n", bp->status ? "Invalid" : "Valid");
}
void printstudent(Library *bp){
	printf("Book ID£º%d\n", bp->sid);
    printf("Book name£º%s\n", bp->sname);
    printf("Amount of book£º%d\n", bp->spass);
}
int viewstudent(){
    system(cls);  ;      ///////////////////////////////////////////
    Library *bp;
    for(bp =head; bp != NULL; bp = bp->next){
        printstudent(bp);
    }
    if(uid){
        return uid;
    }else{
        printf("There is student no books in the library yet.\n");
        return 0;
    }
    return -1;
}
int viewbook(){
    system(cls);  ;      ///////////////////////////////////////////
    Library *bp;
    for(bp =head; bp != NULL; bp = bp->next){
        printbook(bp);
    }
    if(nbook){
        return nbook;
    }else{
        printf("There is been no books in the library yet.\n");
        return 0;
    }
    return -1;
}
