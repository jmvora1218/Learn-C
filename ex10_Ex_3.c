#include <stdio.h>

int main(int argc, char *argv[])
{
	int i = 0, j =0;
	for(i = 1; i<argc; i++){
		for(j = 0; argv[i][j] != '\0'; j++){
			switch (argv[i][j] <= 90 && argv[i][j] >=65){
			case 1:
			argv[i][j]+=32;
			printf("modified value is: %c\n\n",argv[i][j]);
			break;
			}
		}
	}
	for(i=1; i<argc-1; i++){
		printf("string is: %s\n\n",argv[i]);
	}
}