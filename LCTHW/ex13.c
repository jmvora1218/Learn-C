#include <stdio.h>

int main(int argc, char *argv[]){

/*
for ( INITIALIZER ; TEST ; INCREMENTER) {
CODE;
}

Here’s how the for-loop works:
• The INITIALIZER is code that’s run to set up the loop, which in this case is i = 0.
• Next, the TEST Boolean expression is checked. If it’s false (0), then CODE is skipped, doing
nothing.
• The CODE runs and does whatever it does.
After the CODE runs, the INCREMENTER part is run, usually incrementing something, such
as in i++.
• And it continues again with step 2 until the TEST is false (0).

*/
	int i=0;
	// go through each string in argv 
	for(i=0; i <=argc; i++){
		printf("argc [%d]: %s \n", i, argv[i]);
	}
/*
	for(i=1; i<argc; i++){
		printf("argc: [%d], Argv: %s\n",i,argv[i]);
	}	
	*/
	//let's make out own array of strins.
	char *states [] = {"California","Oregon","Washington", "Texa"};
	//char *states [] = {"California","Oregon","NULL","Texa"};
	
	//printf("Size of states:: %lu\n", sizeof(states[0]));
	
	int num_states = 4;
	for(i=0;i< num_states; i++){
		printf("State %d: %s \n",i, states[i]);
//			for(int j=0; i<10; j++){
//				printf("Stat char[%d][%d]: %d",i,j,states[j]);
//			}
	}
	
	for(i=0; i< num_states; i++){
		argv[i]=states[i];
        printf("State from argv:[%d]: [%s] \n",i, argv[i]);
    }		
	return 0;
}