#include<stdio.h>

int main(int argc, char *argv[]){
	
	//create two arrays we care bout/
	int ages[] = {23, 43, 12, 89, 2};
	char *names[] ={"Alan", "Frank", "Mary", "John", "Lisa"};

	//safely get the size of ages
	int count = sizeof(ages)/sizeof(int);

	//printf("count: %d \n ", count);
	//printf("count: %ld \n ", sizeof(ages));
	//printf("count: %ld \n ", sizeof(*names));
	
	int i=0;

/*	
	// first way using indexing
	for(i=0;i<count;i++){
		printf("%p has %d years alive. \n", *names[i], ages[i]);
	}

	printf("----\n");

	//setup the pointers to the start of the arrays.
	int *cur_age = ages;
	char **cur_name = names;

	//second way using pointers.
	for(i=0;i<count;i++){
		printf("%s is %d years old. \n",*(cur_name + i), *(cur_age+i));
	}
*/	
	printf("------\n");

	// pointer test
	int *ag;
	char **cur_name;
	cur_name = names;
	aeg = ages;
	 
	for(i=0;i<count;i++){
		printf("\t %s is %x years old again. \n",cur_name[i], *ag);
	}
/*	
	printf("------\n");
	
	//fourth way with pointers in a stupid complex way
	for(cur_name =names, cur_age =ages; (cur_age - ages) < count; cur_name++, cur_age++){
		printf("%s lived %d years so far. \n", *cur_name, *cur_age);

	}
*/
	return 0;
}
