#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int rising_hope(char *R);

int main(int argc, char *argv[])
{
    char in[1005];

    scanf("%s", in);
    int hope = rising_hope(in);
    printf("%d\n", hope);

    return 0;
}

// Your code goes here
int rising_hope(char *R){
	int i = 0, result = 0;
	while(R[i] != '\0'){
		if(R[i] == 'P') result += 1;
		if(R[i] == 'N') result -= 1;
		i += 1;
	}
	return result;
}
