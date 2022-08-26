//Try to pass pointers to these functions so that they work on the data.

#include<stdio.h>

void fn_ages(int *ages ); //declaring or prototye 

//function defination 
void fn_ages(int *ages){
	
	(*ages)++;

    int i;

    int count = sizeof(ages)/sizeof(int *);
	
    for(i=0;i<count;i++){
		printf("&&&age[%d]:: [%d] \n",i, *ages);
	}
}

int main(int argc, char *argv[]){
	
	int *ages[] = {23, 43, 12, 89, 2};
   
    fn_ages(ages);

return 0;
}