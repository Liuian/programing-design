#include <stdio.h>

int main(){
	int input1, input2, input3;
	char input0;
	scanf("%c", &input0);
	scanf("%2x", &input1);
	scanf("%2x", &input2);
	scanf("%2x", &input3);

	printf("rgb(%d,%d,%d)", input1, input2, input3);
	return 0;
}
