#include <stdio.h>

int main(){
	int a, b, input;
	scanf("%d%d", &a, &b);
	scanf("%d", &input);
	while(input != '\n'){
		b = b - input;
		if(b <= 0){
			printf("A");
			break;
		}
		scanf("%d", &input);
		a = a - input;
		if(a <= 0) {
			printf("B");
			break;
		}
		scanf("%d", &input);
	}
	return 0;
}
