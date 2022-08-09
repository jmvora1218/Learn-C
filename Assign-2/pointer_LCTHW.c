#include<stdio.h>

int main (int argc,char *argv[]){
//int a =10;
int i;

char *jay[]={"akan","mub","bali"};
char **p=jay;

int size = sizeof(jay)/sizeof(char);
//int count = sizeof(ages)/sizeof(int);

printf("size od jay: [%d] \n",size);

for (i=0 ;i<=3;i++)
{
    printf("address of pointer::[%d] print address of pointer to value:[%d] and value::%s \n ",*(&p),p,*(&p));
    //printf("print value::%d \n ",**p);
}

return 0;
}