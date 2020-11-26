#include<stdio.h>
#include<math.h>

int main(){
	float x = 0;
	scanf("%f",&x);
	printf("%.1f\n", 7*pow(x, 4) - 8*pow(x, 3) - pow(x, 2) + 6*pow(x, 1) -22);
	return 0;
}
