#include <stdio.h>
#include <math.h>

long long int factorial(long long int x){
	long long int sum = 1;
	for(int i = 1; i <= x; i ++){
		sum = sum * i;
	}
	return sum;
}

int main(){
	long long int n, unit, tens, hund, thous, ten_thous, sum2;
	scanf("%lld", &n);

	unit = n % 10;
	tens = (n / 10) % 10;
	hund = (n / 100) % 10;
	thous = (n / 1000 ) % 10;
	ten_thous = (n / 10000) % 10;
	
	sum2 = factorial(unit) + factorial(tens) + factorial(hund) + factorial(thous) + factorial(ten_thous);
	
	
	if(n < 10) sum2 = sum2 - 4;
	else if(n >= 10 && n < 100) sum2 = sum2 - 3;
	else if(n >= 100 && n < 1000) sum2 = sum2 - 2;
	else if(n >= 1000 && n < 10000) sum2 = sum2 - 1;

	if(sum2 == n){
		printf("%lld is a strong number.", n);
	}
	else{
		printf("%lld is not a strong number.", n);
	}
	return 0;
}
