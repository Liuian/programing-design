#include <stdio.h>
#include <stdlib.h>

int main(){
	int sis_num[10];
	int noise[10][10];
	int loudest = 0;
	for(int i = 0; i < 10; i++){
		scanf("%d", &sis_num[i]);
	}

	for(int i= 0; i < 10; i++){
		for(int j = 0; j < 10; j++){
			noise[i][j] = (sis_num[i] + sis_num[j]) * abs(i - j);
		}
	}
	
	for(int i= 0; i < 10; i++){
		for(int j = 0; j < 10; j++){
			if(noise[i][j] > loudest) loudest = noise[i][j];
		}
	}

	printf("%d", loudest);

	return 0;
}
