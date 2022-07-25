/*
Extra Credit
• Assign the characters into numbers, and then use printf to print them one character at
a time. What kind of compiler warnings do you get?
• Do the inverse for name, trying to treat it like an array of int and print it out one int at
a time. What does the debugger think of that?
• In how many other ways can you print this out?
• If an array of characters is 4 bytes long, and an integer is 4 bytes long, then can you treat
the whole name array like it’s just an integer? How might you accomplish this crazy hack?
• Take out a piece of paper and draw each of these arrays as a row of boxes. Then do the
operations you just did on paper to see if you get them right.
• Convert name to be in the style of another and see if the code keeps working.
*/

#include<stdio.h>

int main(int argc, char *argv[]){
	int i =0;
	for(int i=0; i<=argc; i++){
		
		printf("argc: [%d], argv: [%s] \n", i, argv[i]);
	}

	int numbers[4] = { };
	char name[4] = {'A','b'};

	// first, print them out raw
	printf("[1]Number: %d %d %d %d \n", numbers[0], numbers[1], numbers[2], numbers[3]);
	printf("[2]name each: [%d] %c %c %c \n", name[0],name[1],name[2],name[3]);
	printf("[3]name: %s \n", name);

	//setup numbers

	numbers[0] = 1;
	numbers[1] = 2;
	numbers[2] = 3;
	numbers[3] = 4;
	for(int i =0; i<=numbers[i];i++){
		printf("FOR_LOOP: setup number if[%d]: [%d] \n", i,numbers[i]);
		//printf("setup number: %d %d %d %d \n", numbers[0], numbers[1], numbers[2], numbers[3]);
	}
	//setup the name
	name[0] = 'Z';
	name[1] = 'e';
	name[2] = 'd';
	name[3] = '\0';
	/*

Do the inverse for name, trying to treat it like an array of int and print it out one int at
a time. What does the debugger think of that?
	i=0;
	while(name[i]!='\0'){

		printf("WHILE: setup name each: [%d]: [%c] \n", i,name[i]);
		printf("WHILE: setup name each: %c %c %c %c \n", name[0],name[1],name[2],name[3]);
		//printf("test print of I %d",i);

		i++;
	}
	//printf("REVERS of NAME[%d]: %d",i,NAME[i]);
*/
	for(i=3; i>=0; i--){
	printf("INSIDE_FOR name[%d]: %d \n", i,name[i]);
	}
	
	/*
	char *another ="Zed";
	printf("another: %s \n", another);
	printf("name each: %c %c %c %c \n", another[0], another[1],another[2],another[3]);
	*/
	return 0;

}
