#include<stdio.h>

int main(){
	int a, b, c, d, e, f, g, h, i, j, k, l;
	scanf("%1d %1d%1d%1d%1d%1d%1d %1d%1d%1d%1d%1d", &a, &b, &c, &d, &e, &f, &g, &h, &i, &j, &k, &l);
	int sum = 0;
	sum = (a + c + e + g + i + k) + (b + d + f + h + j + l) * 3;
	
	printf("%d", (sum - 1) / 10 * 10 + 10 - sum);
	return 0;
}
