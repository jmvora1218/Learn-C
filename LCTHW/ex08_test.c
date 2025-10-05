#include<stdio.h>
int main(){

	int i = 25;
	// while(1)::execute untill killed by user
	while(i!=0)
	{
	i--;
	//int a=printf("Hello");
	printf("I[%d] = %d \n",i,i);
	//while(0)::never execute
	while(0){
		printf("inside while..... \n\n");
	}
	}
}