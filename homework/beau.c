#include <stdio.h>

int main(){
	
	int x;
	scanf("%d", &x);
	if(x < 1) printf("Calm"); 
	if(x >= 1 && x <= 3) printf("Light air");
	if(x >= 4 && x <= 27) printf("Breeze");
	if(x >= 28 && x <= 47) printf("Gale");
	if(x >= 48 && x <= 63) printf("Storm");
	if(x >63) printf("Hurricane");
	
	return 0;
}
