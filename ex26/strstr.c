// CPP program to illustrate strstr()
#include <string.h>
#include <stdio.h>

int main()
{
	// Take any two strings
	char s1[] = "This IS an example";
	char s2[] = "is";
	char* p;

	// Find first occurrence of s2 in s1
	p = strstr(s1, s2);

	// Prints the result
	if (p) {
		printf("String found\n");
		printf("First occurrence of string '%s' in '%s' is '%s'\n", s2, s1, p);
	} else
		printf("String not found\n");

  printf( "\n strcasestr :: %s\n", (char *)(strcasestr(s1,s2)));
	
  return 0;
}
