#include <stdio.h>

int main(int argc, char *argv[])
{
	//for(i=65; i<=97;i++ )
	{
	
	for (int i=65 ; argv[1][i] != '\0';i++){
	char letter =argv[1][i];

	letter = argv[1][i] +26;
	
	printf("%d %c \n", i,letter);
	
	}
}
}
