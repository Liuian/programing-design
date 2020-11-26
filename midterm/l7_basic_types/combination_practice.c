#include <stdio.h>

unsigned long long int factorial(unsigned long long int a, unsigned long long int b){
	unsigned long long int sum = 1;
	for(int i = b; i <= a; i++){
		sum = sum * i;
	}
	return sum;
}
int main(){
	unsigned long long int m, n, output;
	scanf("%lld%lld", &m, &n);
	if(n > m / 2) n = m - n;

	output = factorial(m, m - n + 1) / factorial(n, 1);
	printf("%lld", output);
	return 0;
}
