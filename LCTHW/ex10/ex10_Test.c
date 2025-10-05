#include <stdio.h>

int main(int argc, char *argv[]){
	if(argc != 2){
		printf("ERROR: You need one argumet.\n");
		// This is how you abort a program
		return 1;
	}

	int i = 0;
	for(i = 0; argv[1][i] != '\0'; i++){
	
	//char letter = argv[1][i];
	//printf("check: %c\n",argv[1][i]);

	switch (argv[1][i] <= 90 && argv[1][i] >=65){
		case 1:
		argv[1][i]+=32;
		printf("modified value is: %c\n\n",argv[1][i]);
		break;
		}

	}
		//argv+=1;
		//++argv;
		printf("string is: %s\n\n",*(++argv));

return 0;
}
