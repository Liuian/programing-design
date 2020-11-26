#include <stdio.h>

int main(){
	int input;
	scanf("%d", &input);
	char input2;
	char stri[input];
	
	scanf("%c", &input2);
	for(int i = 0; i < input; i++){
		scanf("%c", &input2);
		stri[i] = input2;
		//printf("%c\n", stri[i]);
	}
	for(int i = input - 1; i >= 0; i--){
		printf("%c", stri[i]);
	}
	return 0;
}
