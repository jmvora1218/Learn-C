#include<stdio.h>

int main(){
    enum logic {false,true}gate;

        int x=3;
        int *p=&x;

        if(*p%2==0)
        {
            printf("this is so %d \n",true);
        }
        else 
        printf("this is so %d \n",false);
}
//https://www.geeksforgeeks.org/enumeration-enum-c/