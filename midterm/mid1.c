//mid1
#include <stdio.h>

int main(){
	int n, ouput2;
	double r, ouput = 1;

	scanf("%lf%d", &r, &n);
	//n = n -1;
	for(int i = 0; i < n; i++){
		ouput = ouput * r;
	}
	ouput2 = ouput;
	printf("%d", ouput2);
	return 0;
}
