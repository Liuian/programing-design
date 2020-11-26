//對比的那個過程要想清楚
//ij ji 寫反
#include <stdio.h>
#include <stdlib.h>

int main(){
	int input, input_num;
	
	scanf("%d", &input);
	int matrix[input][input];

	for(int i = 0; i < input; i++){
		for(int j = 0; j < input; j++){
			scanf("%d", &input_num);
			matrix[i][j] = input_num;
		}
	}

	for(int i = 0; i < input - 1; i++){
		for(int j = i + 1; j < input; j++){
			if(matrix[i][j] != matrix[j][i]){
				//goto here;
				printf("No\n");
				return 0;
			}
		}
	}
	//here
	printf("Yes\n");
	
	return 0;
}
