#include<stdio.h>
#include<string.h>
//#include <stdlib.h>
void add(char a[], char b[], char res[]);

int main(){
    char a[100], b[100], res[105];
    scanf("%s %s", a, b);
    add(a, b, res);
    printf("%s", res);
    return 0;
}

// Your code goes here
void add(char a[], char b[], char res[]){
	int lena, lenb, lenres, ans, car = 0;
	lena = strlen(a);
	lenb = strlen(b);
	if(lena > lenb) lenres = lena;
	else lenres = lenb;
	for(int i = 0; i < lenres; i++){
		lena = lena - 1;
		lenb = lenb - 1;
		if(lena >= 0 && lenb >= 0){
			//ans = (atoi(a[lena]) + atoi(b[lenb]) + car) % 10;
			ans = ((a[lena] - 48) + (b[lenb] - 48) + car) % 10;
			//car = (a[lena] + b[lenb] + car) - (a[lena] + b[lenb] + car) % 10; 
			//if((atoi(a[lena]) + atoi(b[lenb]) + car) >9) car = 1;
			if(((a[lena] - 48) + (b[lenb] - 48) + car) > 9) car = 1;
			else car = 0;
		}
		else if(lena < 0 && lenb >= 0){
			ans = ((b[lenb] - 48) + car) % 10;
			//car = (b[lenb] + car) - (b[lenb] + car) % 10; 
			if(((b[lenb] - 48) + car) > 9) car = 1;
			else car = 0;
		}
		else if(lena >= 0 && lenb < 0){
			ans = ((a[lena] - 48) + car) % 10;
			//car = (a[lena] + car) - (a[lena] + car) % 10; 
			if(((a[lena] - 48) + car) > 9) car = 1;
			else car = 0;
		}
		res[lenres - i] = ans + 48;
		//lenres = lenres - 1;
	}
	res[lenres + 1] = '\0';
	if(car == 0){
		for(int i = 0; i < lenres + 1; i++){
			res[i] = res[i + 1];
		}
	}
	if(car == 1){
		res[0] = 1;
	}
}
