#include<stdio.h>
//#define t 10

void jay_fn();

void jay_fn()
{
	int a[]={1,2,3,4};
	char *b[]={"abc","cde","fgh","ijk"};

	for(int i=0;i<(sizeof(b)/sizeof(char*));i++){
	//for(int i =0 ; i<4;i++){
		printf("%s \n",*(b+i));
		printf("%d \n",b+i);
	}

int x=10; 
int *y=&x;		// *Y stored the value of &X 
int **z = y;    // pointer to pointer with *z reaching to *y || with **z reaching address of &x
int c = *y;	

printf("\n\nValue of X:%d \n",x);
printf("&&&&Address of X:%d \n\n",&x);

printf("PLAIN Y:: %d \n",y);
printf("**** Y::%d \n",*y);
printf("&&&& Y::%d \n\n",&y);

printf("PLAIN Z:: %d \n",z);
printf("**** Z::%d \n",*z);
printf("&&&& Z::%d \n\n",&z);

printf("Pointer to Y: %d \n",c);

}

int main(){
	jay_fn();
return 0;
}
