/* A C program to demonstrate working of memmove */
#include <stdio.h>
#include <string.h>

int main()
{
	char str1[] = "Geeks"; // Array of size 100
	char str2[] = "Quiz"; // Array of size 5

	fputs("str1 before memmove:", stdout);    //https://www.geeksforgeeks.org/puts-vs-printf-for-printing-a-string/
	puts(str1);
    printf("str2: %s\n", str2);
    printf("Address: str1: %d\n", &str1);
    printf("Address: str2: %d\n", &str2);
	

    /* Copies contents of str2 to sr1 */
	memmove(str1, str2, sizeof(str2));

	fputs("\nstr1 after memmove: ", stdout);
	puts(str1);
    
    printf("str1: %s\n", str1);
    printf("str2: %s\n", str2);
    printf("Address: str1: %d\n", &str1);
    printf("Address: str2: %d\n", &str2);

	return 0;
}
