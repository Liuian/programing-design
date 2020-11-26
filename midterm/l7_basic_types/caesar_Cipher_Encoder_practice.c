//為什麼變數用ｋ就不行
#include <stdio.h>

int main(){
	int move;
	char input;
	scanf("%d", &move);
	move = move % 26;
	if(move < 0) move = move + 26;

	scanf("%c", &input);
	scanf("%c", &input);
	while(input != '\n'){
		if(input >= 'a' && input <= 'z'){
			//int k = k;
			input = (input - 'a' + 1 + move) % 26;
			if(input == 0) input = 26;
			input = 'a' + input - 1;
		}
		else if(input >= 'A' && input <= 'Z'){
			//int k = k;
			input = (input - 'A' + 1 + move) % 26;
			if(input == 0) input = 26;
			input = 'A' + input - 1;
		}
		printf("%c", input);
		scanf("%c", &input);
	}

	return 0;
}
