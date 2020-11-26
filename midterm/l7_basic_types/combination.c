#include <stdio.h>
unsigned long long int factorial(unsigned long long int x,unsigned long long int y){
	unsigned long long int sum = 1;
	if(x == 0) sum = 0;
	else{
		for(int i = y; i <= x; i ++){
			sum = sum * i;
		}
	}
	return sum;
}

int main(){
	unsigned long long int input1, input2, output, value1, value2;
	scanf("%lld %lld", &input1, &input2);
	if(input2 < input1 / 2 ) input2 = input1 - input2;
	value1 = factorial(input1, input2 + 1);
	value2 = factorial((input1 - input2), 1);
	output = value1 / value2;
	printf("%lld", output);
	return 0;
}
