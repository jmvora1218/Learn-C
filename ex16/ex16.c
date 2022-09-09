#include<stdio.h>
#include<assert.h> //https://www.geeksforgeeks.org/assertions-cc/
#include<stdlib.h> //Some of the functions in stdlib.h are malloc ,  free ,abort , exit ,etc
#include<string.h>

struct Person{
	char *name;
	int age;
	int height;
	int weight;
};

//prototype
struct Person *Person_create(char *name, int age, int height, int weight)
{
	struct Person *who = malloc(sizeof(struct Person));
	assert(who != NULL);
	//assert(who->name != NULL);

	who->name = name;
	who->name = strdup(name);
	who->age = age;
	who->height = height;
	who->weight = weight;

	return who;
}

void Person_destroy(struct Person *who)
{
	assert(who !=NULL);
	
	free(who->name);
	free(who);

}

void Person_print(struct Person *who)
{
	printf("Name: %s \n", who->name);
	printf("\t Age: %d \n", who->age);
	printf("\t Height: %d \n", who->height);
	printf("\t Weight: %d \n", who->weight);
}

int main(int argc, char *argv[]){
	// make two people structures
	
	struct Person *joe = Person_create("Joe test", 32, 64, 140);
	struct Person *frank = Person_create("Frank Blank", 20, 72, 180);
	
	//print them out and where they are in memory

	printf("Joe is at memory location %p: \n", joe);
	Person_print(joe);

	printf("Frank is at memory localtion %p: \n", frank);
	Person_print(frank);

	// make everyone age 20 years and print again 
	joe->age += 20;
	joe->height -=2;
	joe->weight +=40;
	Person_print(joe);

	frank->age +=20;
	frank->weight +=20;
	Person_print(frank);

	//destroy them both so we clean up
	Person_destroy(joe);
	Person_destroy(frank);       // to create leak add comment
	
	return 0;
}
