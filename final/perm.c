#include <stdio.h>

void sort(char *arr, int n);

int main(void){
char stor[10];
char c = getchar();
int i = 0;
while(c != '\0'){
	scanf("%c", &stor[i]);
	i +=1;
	c = getchar();
}

return 0;
}
