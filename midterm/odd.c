#include <stdio.h>

int main(){
	int num;
	scanf("%d", &num);
	int matr[num][num];
	int m = 0, n = 0, m1,n1;
	n = (num - 1) / 2;
	for(int i = 0; i < num; i++){
		for(int j = 0; j < num; j++){
			matr[i][j] = 0;
		}
	}
	matr[m][n] = 1;
	

	for(int i = 2; i <= num*num; i++){
		m1 = m;
		n1 = n;

		m = m - 1;
		n = n + 1;
		if(m < 0){
			m = m + num;
		}
		if(m >= num){
			m = m - num;
		}
		if(n < 0){
			n = n + num;
		}
		if(n >= num){
			n = n - num;
		}

		if(matr[m][n] == 0){
			matr[m][n] = i;
		}
		else{
			m = m1;
			n = n1;
			m = m + 1;
			matr[m][n] = i;
		}
	}

	for(int i = 0; i < num; i++){
		for(int j = 0; j < num; j++){
			printf("%d ", matr[i][j]);
		}
		printf("\n");
	}
	//printf("\n");
	return 0;
}
