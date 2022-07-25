#include<stdio.h>
#include<ctype.h>
#include<string.h>

//forward declarations

int can_print_it(char ch);
void print_letters(char arg[],int length);

void print_arguments(int argc, char *argv[])
{
	int i=0;
	//Have print_arguments figure out how long each argument string is by using the strlen function,
	int length;
     /*for(i = 0; i < argc; i++)
     {
          length = strlen(argv[i]);  
          printf(" Length is %d\n", length); 
          print_letters(argv[i], length); //does "i" arrive as "char arg"
	 }
*/
	for(i =0; i<argc ; i++){
		printf("INSIDE_FOR::lenth of argv[%lu]\n",strlen(argv[i]));
		print_letters(argv[i],length);
	}
	printf("OUT_LOOP: argc::%d \n",argc);
	length=strlen(argv[i-1]);
	printf("lenth of argv[%d] \n",length);
}

void print_letters(char arg[], int length)
{
	int i=0;
	for(i=0; arg[i] <= length; i++){
		char ch =arg[i];
		// if(can_print_it(ch)) instead of function we can use below syntex.
		//if (isalpha((int)ch) || isdigit((int)ch)){
		
		printf("'%c' == %d", ch, ch);
		/*
		if (can_print_it(ch)){
			printf("'%c' == %d", ch, ch);
		}*/
	printf("\n");
	}
	
}

int can_print_it(char ch)
{
	return isalpha((int)ch) || isblank((int)ch) || isdigit((int)ch);
}

int main(int argc, char *argv[])
{
	print_arguments(argc,argv);      
	// adding +1(print_arguments(argc+1,argv);) is accessing the memory which is not allocated. and due to that getting coredump
	return 0;
}