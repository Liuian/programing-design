#include<stdio.h>

int main(){
	int H = 0, M = 0;
	scanf("%d %d", &H, &M);
	printf("%.2d:%.2d", ((60 * H + M +50) / 60) % 24, (60 * H + M +50) % 60);
	return 0;
}
