// C program to demonstrate use of *s
#include <stdio.h>
int main()
{
	int  a;
	scanf("%*s %*s %*s %*s %s", &a);
	printf("Input value read : a=%s", a);
	return 0;
}