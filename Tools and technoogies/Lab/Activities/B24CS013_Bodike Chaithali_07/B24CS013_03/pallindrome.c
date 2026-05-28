#include"pallindrome.h"

int is_pallindrome(int n) {
	int m=n,rev=0;
	if(m<0) m=-m;
	while(m>0) {
		rev=rev*10+(m%10);
		m/=10;
	}
	if(n<0) rev=-rev;

	return (rev == n);
}
