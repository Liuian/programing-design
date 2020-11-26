#include <stdio.h>
#include <string.h>

int main(){
	int init = 0, day_num;
	char input[2];
	
	scanf("%s", input);

	if(strncmp(input, "10", 2) == 0) {
		init = 5;
		day_num = 31;
	}
	else if(strncmp(input, "11", 2) == 0) {
		init = 1;
		day_num = 30;
	}
	else if(strncmp(input, "12", 2) == 0) {
		init = 3;
		day_num = 31;
	}
	else if(strncmp(input, "1", 1) == 0) {
		init = 4;
		day_num = 31;
	}
	else if(strncmp(input, "2", 1) == 0) {
		init = 7;
		day_num = 29;
	}
	else if(strncmp(input, "3", 1) == 0) {
		init = 1;
		day_num = 31;
	}
	else if(strncmp(input, "4", 1) == 0) {
		init = 4;
		day_num = 30;
	}
	else if(strncmp(input, "5", 1) == 0) {
		init = 6;
		day_num = 31;
	}
	else if(strncmp(input, "6", 1) == 0) {
		init = 2;
		day_num = 30;
	}
	else if(strncmp(input, "7", 1) == 0) {
		init = 4;
		day_num = 31;
	}
	else if(strncmp(input, "8", 1) == 0) {
		init = 7;
		day_num = 31;
	}
	else if(strncmp(input, "9", 1) == 0) {
		init = 3;
		day_num = 30;
	}
	
	//printf("%d %d\n\n", init, day_num);
	
	printf("Sun Mon Tue Wed Thu Fri Sat \n");
	//印出第一週空白的天數
	for(int i= 0; i < init - 1; i++){
		printf("    ");
	}

	for(int i = 1; i <= day_num; i++){
		if((i + init - 1) % 7 != 0 ){
			printf(" %2d ", i);
		}
		else if((i + init - 1) % 7 == 0 && i == day_num){
			printf(" %2d ", i);
		}
		else{
			printf(" %2d \n",i);
		}
	}
	/*
	for(int i = 0; i < 8 - (day_num % 7) - init; i++){
		printf("    ");
	}
	*/
	return 0;
}
