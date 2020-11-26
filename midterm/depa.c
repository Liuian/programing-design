#include <stdio.h>

int main(){
	int m , n, input;
	scanf("%d%d", &m, &n);

	int array1[m], array2[n], array3[m+n];
	for(int i =0;i < m; i++){
		scanf("%d", &input); 
		array1[i] = input;
	}
	for(int i =0;i < n; i++){
		scanf("%d", &input); 
		array2[i] = input;
	}
	if(m == 0){
		for(int i = 0; i < n; i++){
			printf("%d", array2[i]);
		}
	}
	else if(n == 0){
		for(int i = 0; i < m; i++){
			printf("%d", array1[i]);
		}
	}
	else{
		int x = 0, y = 0;
		for(int i = 0; i < m + n; i++){
			if(array1[x] > array2[y]) {
				printf("%d ", array2[y]);
				y = y + 1;
				if(y == n ) break;
			}
			else if(array1[x] < array2[y]){
				printf("%d ", array1[x]);
				x = x + 1;
				if(x == m ) break;
			}
		}
		if(y == n ){
			for(int i = x; i < m; i++){
				printf("%d ", array1[i]);
			}
		}
		if(x == m ){
			for(int i = y; i < n; i++){
				printf("%d ", array2[i]);
			}
		}
	}
	
	return 0;
}
