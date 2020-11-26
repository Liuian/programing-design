#include <stdio.h>

int main(){
	int input;
	char input3, ch_line;
	scanf("%d", &input);
	char input2[input];
	scanf("%c", &ch_line);
	for(int i = 0; i < input; i++){
		scanf("%c", &input2[i]);
		input2[i] = input2[i] - 'a';
		printf("%d", input2[i]);
	}
	//printf("test_______\n");
	scanf("%c", &ch_line);
	int count = 0;
	//while(scanf("%c", &input3) != 1){
	while((input3 = getchar()) != '\n'){ 
		//printf("test\n");
		if(input3 >= 'A' && input3 <= 'Z'){
			input3 = ((input3 - 'A') + input2[count % input]) % 26 + 'A';
			printf("%c", input3);
			count = count + 1;
		}
		else if(input3 >= 'a' && input3 <= 'z'){
			input3 = ((input3 - 'a') + input2[count % input]) % 26 + 'a';
			printf("%c", input3);
			count = count + 1;
		}
		else{
			printf("%c", input3);
		}
	}
	return 0;
}
