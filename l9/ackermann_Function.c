#include <stdio.h>

int function(int a, int b){
	if(a == 0){
		return b + 1;
	}
	else if(b == 0){
		return function(a - 1, 1);
	}
	else{
		return function(a - 1, function(a, b - 1));
	}
}


int main(){
	int m, n;
	scanf("%d%d", &m, &n);

	printf("%d", function(m, n));
	return 0;
}
