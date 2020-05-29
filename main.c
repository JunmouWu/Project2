#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define AVAILABLE 0
#define UNAVAILABLE 1
#define MAXNAME 30
#include "Structure.h"
#include "StudentLogin.h"
#include "ManagerLogin.h"
#include "MainPage.h"
#include "StudentPage.h"
#include "StudentMode.h"
#include "ManagerMode.h"
#include "CommonOperation.h"

unsigned int uid;
unsigned char password[20][10];
Library *head = NULL;
unsigned int nbook=0;

int main(){
    welcome();
    return 0;
}







