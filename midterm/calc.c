#include <stdio.h>
#include <math.h>

int main(){
	int mode;
	scanf("%d", &mode);
	double a, b, c;

	if(mode == 1){
		scanf("%lf", &a);
		printf("%.2lf", pow(a, 3));
	}
	else if(mode == 2){
		scanf("%lf%lf%lf", &a,&b ,&c);
		printf("%.2lf", a * b * c);
	}
	else if(mode == 3){
		scanf("%lf%lf", &a, &b);
		printf("%.2lf", 3.14 * a * a * b);
	}
	else if(mode == 4){
		scanf("%lf", &a);
		printf("%.2lf", pow(2, 0.5) / 12 * pow(a,3));
	}
	
	return 0;
}
