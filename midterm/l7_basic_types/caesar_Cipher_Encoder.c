#include <stdio.h>
#include <stdlib.h>

int main(){
	char input, temp; 
	int input_move;

	scanf("%d", &input_move);
	scanf("%c", &input);
	scanf("%c", &input);
	if(input_move < 0){
		input_move = (input_move % 26) + 26;
	}
	else{
		input_move = input_move % 26;
	}
	while(input != '\n'){
		//if(input < 1) input = input + 26;
		if(input >= 'a' && input <= 'z'){
			input = (input - 'a' + 1 + input_move) % 26; 
			if(input == 0) input = 26;
			input = input + ('a' - 1);
			printf("%c", input);
		}
		else if(input >= 65 && input <= 90){
			input = (input - 'A' + 1 + input_move) % 26;
			if(input == 0) input = 26;
			input = input + ('A' - 1);
			printf("%c", input);
		}
		else{
			printf("%c", input);
		}
		scanf("%c", &input);
	}

	return 0;
}
