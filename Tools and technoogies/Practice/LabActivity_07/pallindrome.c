#include"pallindrome.h"

int reverseNum(int n) {
	int m=n,rev=0;
	while(m!=0) {
		rev=rev*10+m%10;
		m/=10;
	}
	if(rev==n) return 1;
	else return 0;
}
