#include <stdio.h>

int comb(int n, int m){
	if(m == 0 || m == n){
		return 1;
	}
	else{
		return comb(n - 1, m - 1) + comb(n - 1, m);
	}
}

int main(){
	int n, m;
	scanf("%d%d", &n, &m);

	printf("%d", comb(n, m));
}
