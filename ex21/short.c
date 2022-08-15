#include<stdio.h>

int main(){

short int x;
int y=99999,z=999999999999999999999;

x=(y*z)*z;
printf("Size %u\n",sizeof(short));
printf("this is so %u \n",x);

}      
/*
O/P:
[root@Fedora-35 Basic-C-main]# make short
cc     short.c   -o short
short.c: In function ‘main’:
short.c:6:15: warning: integer constant is too large for its type
    6 | int y=99999,z=999999999999999999999;
      |               ^~~~~~~~~~~~~~~~~~~~~
short.c:6:15: warning: overflow in conversion from ‘long int’ to ‘int’ changes value from ‘3875820019684212735’ to ‘-559939585’ [-Woverflow]
*/
