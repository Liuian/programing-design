#include <stdio.h>

int main(){
	int input_matrix, input_num;
	scanf("%d", &input_matrix);

	int matrix[input_matrix][input_matrix];
	for(int i = 0; i < input_matrix; i++){
		for(int j = 0; j < input_matrix; j++){
			scanf("%d", &input_num);
		//	printf("%d\n", input);
			matrix[i][j] = input_num;
		}
	}

	
	int i, j;
	for(i = 0; i < input_matrix - 1; i++){
		for(int j = i + 1; j < input_matrix; j++){
			if(matrix[i][j] != matrix[j][i]) {
				//goto here;
				printf("No\n");
				return 0;
			}
		}

	}
//here:
	//printf("%d %d\n", i, j);
	//if (i == j && j == (input_matrix - 1)) 
	printf("Yes\n");
	//else printf("NO");

	return 0;
}
