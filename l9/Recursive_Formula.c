#include <stdio.h>

int coculate(int x1, int x2){
	int x3;
	x3 = x1 + x2;
	return x3;
}

int main(){
	
	
	int count, x1, x2, n;
	scanf("%d%d%d", &x1, &x2, &n);
	while(x1 != '\n'){
	int sequence[20] = {x1, x2};

	if(n <= 2 || n > 20){
		printf(" ");
		return 0;
	}

	for(count = 2; count < n; count++){
		sequence[count] = coculate(sequence[count - 1], sequence[count - 2]);
	}

	printf("%d\n", sequence[n - 1]);
	scanf("%d%d%d", &x1, &x2, &n);
	}
	return 0;
}
