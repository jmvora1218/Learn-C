#include<stdio.h>

int main(int argc, char *argv[])
{
	
	//create two arrays we care bout/
	int ages[] = {23, 43, 12, 89, 2};
	char *names[] ={"Alan", "Frank", "Mary", "John", "Lisa","Mubarak"};

	//safely get the size of ages
	int count = sizeof(ages)/sizeof(int);
	int i=0;

	// first way using indexing ARRAY PRINT
	for(i=0;i<count;i++){
		printf("ARRAY_ADDRESS NAMES:[%d] and AGES:[%d] >> [%s] has [%d] years alive. \n",names[i], ages[i], names[i], ages[i]);
		//printf("ARRAY_ADDRESS &NAMES:[%d] and &AGES:[%d] >> [%s] has [%d] years alive. \n",&names[i], &ages[i], names[i], ages[i]);
	}

	printf("----\n");

	//setup the pointers to the start of the arrays.
	int *cur_age = ages;
	char **cur_name = names;
	/*
	int count_2 = sizeof(names)/sizeof(char*);   // https://stackoverflow.com/questions/9522760/find-the-number-of-strings-in-an-array-of-strings-in-c
	int count_2 = sizeof(names)/sizeof(names[0]); 
	printf("Print count: %d\n",count);
	printf("*****Print count_2: %d\n\n",count_2);
	printf("Print name[ ]: %d \n\n",sizeof(names[0]));
	*/

	//second way using pointers.
	for(i=0;i<count;i++){
		printf("cur_name_addr:%d || cur_name_value:%s \n",*(cur_name + i),*(cur_name + i));
		
		printf("cur_name_addr:%d || cur_name_value:%s \n");

		//printf("POINTER_ADDRESS NAMES:[%p] and AGES:[%p] >> [%s] is [%d] years old. \n",*(cur_name + i), *(cur_age+i), *(cur_name + i), *(cur_age+i));
	}
/*	
	printf("------\n");

	//Third way, pointers are just arrays.
	for(i=0;i<count;i++){
		printf("%s is %d years old again. \n",cur_name[i], cur_age[i]);
	}
	
	printf("------\n");
	
	//fourth way with pointers in a stupid complex way
	for(cur_name =names, cur_age =ages; (cur_age - ages) < count; cur_name++, cur_age++){
		printf("%s lived %d years so far. \n", *cur_name, *cur_age);
	}
*/
	return 0;
}
