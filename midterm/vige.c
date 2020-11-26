#include <stdio.h>

int main(){
	int input1, input  = 0;
	char word, count;
	scanf("%d", &input1);
	scanf("%c", &word);
	int matr[input1];
	for(int i = 0; i < input1; i++){
		scanf("%c", &word);
		//word = word - 'a' + 1;
		matr[i] = word - 'a' ;
	}

	int count2 = 0, count3;
	scanf("%c", &count);
	scanf("%c", &count);
	while(count != '\n'){
		//if(count == ' ') scanf("%c", &count);
		count3 = count2;
		count3 = count3 % input1;
			input =count; 
		
		if(input >= 'a' && input <= 'z'){
			input = (input - 'a' + 1 + matr[count3]) % 26; 
			if(input == 0) input = 26;
			input = input + ('a' - 1);
			printf("%c", input);
		}
		else if(input >= 65 && input <= 90){
			input = (input - 'A' + 1 + matr[count3]) % 26;
			if(input == 0) input = 26;
			input = input + ('A' - 1);
			printf("%c", input);
		}
		else{
			printf("%c", input);
		}
		scanf("%c", &count);
		if(count == ' '){
			//printf("_____________");
			count2 = count2 -1;
			printf("%c", count);
			scanf("%c", &count);
			
		}
		
			count2 = count2 + 1;
	}

	return 0;
}
