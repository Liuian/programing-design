#include <stdio.h>

int main(){
	char input, output;

	scanf("%c", &input);
	while(input != '\n'){
		if(input == 'A') output = 'C';
		if(input == 'B') output = 'R';
		if(input == 'C') output = 'W';
		if(input == 'D') output = 'Z';
		if(input == 'E') output = 'G';
		printf("%c", output);
		scanf("%c", &input);
		
	}
	return 0;
}
