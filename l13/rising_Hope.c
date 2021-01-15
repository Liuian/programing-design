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
	int count = 0, i = 0;
	while(R[i] != '\0'){
		if(strncmp(&R[i], "P", 1) == 0) count = count + 1;
		if(strncmp(&R[i], "N", 1) == 0) count = count - 1;
		i = i + 1;
	}
	return count;
}
