#include <stdio.h>

int main(){
	int input;
	scanf("%d", &input);

	for(int i = 1; i <= input; i++) {
		for(int k = input; k > i; k--){
			printf(" ");
		}
		for(int j = 0; j < i * 2 - 1; j ++){
			printf("*");
		}
		printf("\n");
	}
	return 0;
}
