/*
	Lab 3 Test Program
	
	Nothing much done here.  Just printing out what was passed into this program when launched.
	
	This program will tell you whether you've passed the params through exec*() system calls correctly.
*/

#include <stdio.h>

int main(int argc, char* argv[])
{
	printf("\n\n\nThis is the Lab 3 Test Program\n");
	printf("==============================\n\n");
	printf("You've launched this test program with the following input parameters: \n");
	
	for(int i = 0; i < argc; i++)
	{
		printf("Parameter %d: %s\n", i, argv[i]);
	}
	
	printf("\n==============================\n");
	printf("End of the Lab 3 Test Program\n\n\n");
	
	return 0;
}
