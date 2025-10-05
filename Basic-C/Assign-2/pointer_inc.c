#include<stdio.h>
void main(){
    int a[] ={7,2,3,4,5};
    int *p = a;
    int q;
    *p+2;

    printf("pointer P++: %d\n", q);
    q=*p;
        printf("2.) pointer P++: %d\n", q);

    //printf("address of a[2]:%d",p[2]);

}