#include <stdio.h>

int main(){
	int a, b, c, d;
	char input;
	scanf("%d%c%d%c%c%d%c%c%d", &a, &input, &b, &input, &input, &c, &input, &input, &d);
	printf("%d", a + b + c + d);

	return 0;
}
