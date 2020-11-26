#include <stdio.h>

int factorial(int x){
	int sum = 1;
	//if (x == 0) sum = 1;
	//else{
		for(int i = 1; i <= x; i++){
			sum = sum * i;
		}
	//}
	return sum;
}

int main(){
	int input, output, one, two ,three, four, five;
	scanf("%d", &input);
	
	one = input % 10;
	two = (input / 10) % 10;
	three = (input / 100) % 10;
	four = (input / 1000) % 10;
	five = (input / 10000) % 10;

	if(input > 0 && input < 10){
		output = factorial(one);
	}
	else if(input >= 10 && input < 100){
		output = factorial(one) + factorial(two);
	}
	else if(input >= 100 && input < 1000){
		output = factorial(one) + factorial(two) + factorial(three);
		}
	else if(input >= 1000 && input < 10000){
		output = factorial(one) + factorial(two) + factorial(three) + factorial(four);
	}
	else{
		output = factorial(one) + factorial(two) + factorial(three) + factorial(four) + factorial(five);
	}
	if(output == input) printf("%d is a strong number.", input);
	else printf("%d is not a strong number.", input);
	return 0;
}
