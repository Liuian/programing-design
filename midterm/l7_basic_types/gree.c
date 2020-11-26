#include <stdio.h>

int main(){
	char input, output;
	
	//while(scanf("%c", &input) != EOF){

	for(int i = 0; i < 20; i++){
		scanf("%c", &input);

		if(input == 'A') output = 'C';
		if(input == 'B') output = 'R';
		if(input == 'C') output = 'W';
		if(input == 'D') output = 'Z';
		if(input == 'E') output = 'G';

		printf("%c", output);
	}
	return 0;
}
