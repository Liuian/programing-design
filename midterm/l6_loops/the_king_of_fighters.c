#include <stdio.h>

int main(){
	int a, b, atta;
	scanf("%d %d", &a , &b);
		
	scanf("%d", &atta);
	//scanf("%d", &atta);
	while(1){
		b = b - atta;
		if(b - atta < 0){
			printf("A");
			break;
		}
		scanf("%d", &atta);
		a = a - atta;
		if(a - atta < 0){
			printf("B");
			break;
		}
		scanf("%d", &atta);
	}
	return 0;
}
