#include <stdio.h>

int main(){
	int array1[32], array2[32], array3[32], temp = 0;
	for(int i = 0; i < 32; i++){
		scanf("%d", &array1[i]);
	}
	for(int i = 0; i < 32; i++){
		scanf("%d", &array2[i]);
	}
	for(int i = 31; i >= 0; i--){
		temp = temp + array1[i] + array2[i];
		array3[i] = temp % 2;
		temp = temp / 2;
	}
	for(int i = 0; i < 32; i++){
		printf("%d ", array3[i]);
	}
	return 0;
}
