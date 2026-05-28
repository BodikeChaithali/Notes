#include <stdio.h>


extern int concat(char *, char *);
extern char result[];


int main() {
	char *s1 = "Deadline is ";
	char *s2 = "today itself!!!";
	int len = concat(s1, s2);
	printf("string 1: %s\n", s1);
	printf("string 2: %s\n", s2);
	printf("concatenated string: %s, length=%d\n", result, len);
	return 0;
}
