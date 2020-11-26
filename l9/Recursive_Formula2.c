#include <stdio.h>

//count = 3;
int n;

int function(int x1, int x2){
	int x3;
	x3 = x1 + x2;
	if(n > 3){
		//count = count + 1;
		n = n - 1;
		return function(x2, x3);
	}
	else{
		return x3;
	}
}

int main(){
	int x1, x2;
	while(scanf("%d%d%d", &x1, &x2, &n) != EOF){
		//scanf("%d%d%d", &x1, &x2, &n);
		if(n < 3){
			;
			//return 0;
			//printf("\n");
		}
		else{
			printf("%d\n", function(x1, x2));
		}
		//count = 3;
	}
	return 0;
}
