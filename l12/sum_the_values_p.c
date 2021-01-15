#include <stdio.h>

void star(int*, int*);

int main()
{
    int arr[5], result;
    for(int i=0; i<5; i++)
        scanf("%d", &arr[i]);
    
    star(arr, &result);

    printf("%d", result);

    return 0;
}
// Your code goes here
void star(int *a, int* result){
	*result = 0;
	for(int i = 0; i < 5; i++){
		*result += a[i];
	}
}
