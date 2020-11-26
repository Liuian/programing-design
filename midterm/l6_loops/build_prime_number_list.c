#include <stdio.h>

int main(){
	int x, y, temp, i;
	scanf("%d %d", &x, & y);

	temp = x;
	for(int temp = x; temp <= y; temp++){
		for(i = 2; i <= temp; i++){
			if(temp % i == 0){
				break;
			}
		}
		if(i == temp) printf("%d ", temp);
	}
	
	return 0;
}
