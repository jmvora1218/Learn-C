#include <stdio.h>

int main (int argc, char *argv[]){
	
	//type name[] = {initializer};      Array initializer
	
	
	char full_name[] = { 'Z', 'e', 'd', ' ', 'A', '.', ' ', 'S', 'h', 'a', 'w', '\0'};
	//int areas[] = { 10, 12, 13, 14, 20};
	int areas[] = { 'A', 'B', 13, 14, 20};
	char name[] = "Zed";
	//char full_name[] = { 'Z', 'e', 'd', ' ', 'A', '.', ' ', 'S', 'h', 'a', 'w', '\0'};    // total size 12 
	
	// WARNING: On some systems you may have to change the
	// %ld in this code to a %u since it will use unsigned ints
	//size of never in minius(-), so that is always UNSIGNED

	//printf("The size of an int[ld]: %ld \n", sizeof(long int));
	printf("The size of an int[d]: %ld \n", sizeof(int));
	//printf("The size of an int[ul]: %lu \n\n", sizeof(unsigned long int));

	printf("The size of an Areas (int[]: %ld) \n", sizeof(areas));
	printf("The number of ints in areas: %ld \n \n", sizeof(areas)/sizeof(int));

	printf("The first Area is:%d, the 2nd is:%d \n\n", areas[0], areas[1]);

	printf("The size of an char: %ld \n", sizeof(char));
	printf("The size of name (char[]): %ld \n", sizeof(name));
	printf("The number of chars: %ld \n", sizeof(name)/sizeof(char));
	/*
	 * The string is a collection of characters, an array of a string is an array of arrays of characters. 
	 * Each string is terminated with a null character. 
	 * An array of a string is one of the most common applications of two-dimensional arrays.
	 * scanf( ) is the input function with %s format specifier to read a string as input from the terminal. 
	 * But the drawback is it terminates as soon as it encounters the space. To avoid this gets( ) function which can read any number of strings including white spaces.
	 * Sting is an array of characters terminated with the special character known as the null character (“\0”)
	*/
	printf("The characters 1st:%c, 2nd:%c, 3rd:%c, 4th:%d \n\n\n ", name[0], name[1],name[2],name[3]);

	printf("The size of full_name(char[]): %ld\n", sizeof(full_name));
	printf("The number of chars: %ld\n \n", sizeof(full_name) / sizeof(char));

	//full_name [2] ='X';
	printf("name=\"%s\" and full_name=\"%s\" \nand full_name[11] is %c \nfull_name[12] is %s\n", name, full_name, full_name[10], full_name[130]);

return 0;
}
