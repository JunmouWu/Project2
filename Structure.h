#include <stdio.h>
#ifndef STRUCTURE_H
#define STRUCTURE_H
typedef struct book{
    char *name;
    int id;
    int count;
    int status;
    int sid;
    int Check;
    char spass[MAXNAME];
    char sname[MAXNAME];
    struct book *next;
}Library;
#endif 

