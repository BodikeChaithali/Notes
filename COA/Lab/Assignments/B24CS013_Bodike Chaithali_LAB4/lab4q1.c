#include <stdio.h>

extern int roll;

int getRank() {
	return 30000;
}


void print(char *first, char *last, int rank) {
	
	printf("First Name: %s\n", first);
	printf("Last Name: %s\n", last);
	printf("Roll number: %d\n", roll);
	printf("Rank: %d\n", rank);

}
