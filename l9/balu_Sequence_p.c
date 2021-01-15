#include <stdio.h>

long long int balu(int);
int main(void){
	long long int b;
	scanf("%lld", &b);
	printf("%lld", balu(b));
	return 0;
}

long long int balu(int x){
	if(x <= 2) return 1;
	else return (2 * balu(x - 1) + 3 * balu(x - 2)) % 1000000007;
}

