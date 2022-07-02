#include<stdio.h>

int main()
{
	volatile int T;

	int x=T;

	int y=T;

	int *n=&T;
	printf("before IF%d \n", T);
	if ( *n%2 == 0 ){
      printf("%p is an even number\n", *n);
	  printf("%d \n", T);
	}else{ 
      printf("%p is an odd number", *n);
	  printf("%d ", T);
	}
	return 0;
}