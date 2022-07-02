#include <stdio.h>

int main(int argc, char *argv[])
{
	int distance = 100;
	float power = 2.345f;
	double super_power = 56789.4532;
	char initial = 'A';
	char first_name[] ="Zed";
	char last_name[] = "Shaw";

	first_name[2] = 1;

	printf("you are %d miles away.\n", distance);
	printf("you have %f levels of power. \n", power);
	printf("you have %f awesome super powers\n ", super_power);
	printf("I have initial %c. \n ", initial);
	printf("I have a first name %s. \n", first_name);
	printf("I have a last name %s. \n", last_name);
	printf("\n ***My whole name is %s %c. %s. ***\n", first_name,initial, last_name);

	int bugs = 900;
	double bug_rate = 1.2;
	printf("You have %d bugs at the imaginary rate of %f. \n",bugs, bug_rate);
	
	unsigned long universe_of_defects = 1L * 1024L * 1024L * 23L;
	printf("The entire Universe has %ld bugs. \n",universe_of_defects);
	//printf("The entire Universe has %s bugs. \n",'\0');

	double expected_bugs = bugs * bug_rate;
	printf("You are expected to have %f bugs.\n",expected_bugs);

	double part_of_universe = expected_bugs / universe_of_defects;
	printf("Thant is only a %e portion of the universe. \n", part_of_universe);

	// just for demo of something weird.
	printf("EXTRA CRADIT \n\n");
	char nul_byte ='\0';
	int care_percentage = bugs * nul_byte;
	printf("Which means you should care %d%%. \n", care_percentage);
	//printf("PRINT \\NULL %s \n",'A'*2);
	
	// Extra cradit 
	int mul_ci = distance * initial;

	printf("\n int :%d \n", distance);
	printf("\nChar:A :%d \n", initial);
	printf("\nchar int multiply:%d \n", mul_ci);

printf("\n int :%ld \n",sizeof(int));

return 0;	
}