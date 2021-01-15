#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define N 100

int addition(char str[]);

int main() {
    char str[N];
    scanf("%s", str);
    int sum = addition(str);
    printf("%d", sum);
    return 0;
}
// Your code goes here
int addition(char str[]){
	char *plus = "+", *num;
	int sum1 = 0, val;
	num = strtok(str, plus);
	while(num != NULL){
		val = atoi(num);
		sum1 = sum1 + val;
		num = strtok(NULL, plus);
	}
	return sum1;
}
