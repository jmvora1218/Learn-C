#include <stdio.h>

int main(int argc, char *argv[]){
	int i;
	while (i < 25){
		printf("I[%d] = %d\n",i, i);
		i++;		
	}
	//final newline.
	printf("\n");
	return 0;
}
