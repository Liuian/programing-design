#include <stdio.h>
#define N 32

int main(){
	int num1[N], num2[N], num3[N], temp, temp2;
	int temp3 = 0;

	for(int i = 0; i < 32; i++){
		scanf("%d", &num1[i]);
	}
	for(int i = 0; i < 32; i ++){
		scanf("%d", &num2[i]);
	}
	for(int i = 31; i >= 0; i--){
		temp = num1[i] + num2[i] + temp3;
		temp2 = temp % 2;
		temp3 = temp / 2;
		num3[i] = temp2;
	}
	for(int i = 0; i < 32; i++){
		printf("%d ", num3[i]);
	}
	
	return 0;
}
