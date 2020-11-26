#include <stdio.h>

int main(){
	int input1, input2, j, i;
	scanf("%d%d", &input1, &input2);
	for(i = input1; i <= input2; i++){
		for(j = 2; j < i; j++){
			//if(i == 2) j = 1;
			if(i % j == 0) {
				break;
			}
		}
		if(j == i) printf("%d ", i);
	}

	return 0;
}
