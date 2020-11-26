#include <stdio.h>

int main(){
	int r, m,n, input;
	scanf("%d%d%d", &r,&m,&n);
	int matr[m][n];
	for(int i = 0; i < m; i++){
		for(int j = 0; j < n; j++){
			scanf("%d", &input);
			matr[i][j] = input;
		}
	}
	
	if(r == 270){
		for(int j = n - 1; j >= 0; j--){
			for(int i = 0; i < m; i++){
				printf("%d ",matr[i][j]);
			}
			printf("\n");
		}
	}
	else if(r == 90){
		for(int i = 0; i < n; i++){
			for(int j = m -1; j >=0; j--){
				printf("%d ",matr[j][i]);
			}
			printf("\n");
		}
	}
	else if(r == 180){
	for(int i = m - 1; i >= 0; i--){
		for(int j = n - 1; j >=0; j--){
			printf("%d ",matr[i][j]);
		}
		printf("\n");
	}
	}
	return 0;
}
