#include <stdio.h>
#include <string.h>

int main(){
	int ch;

	while((ch = getchar()) != '\n'){
		//ch = getchar();
		putchar(ch);
		if(ch == ' '){
			while((ch = getchar()) == ' '){
			};
			if(ch == '\n')return 0;
			else putchar(ch);
			}
		}
	return 0;
}
