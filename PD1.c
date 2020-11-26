#include<stdio.h>

int main(){
	int x1, x2, x3, x4;
	
	int x;
	scanf("%d", &x);
	x4 = x / 1000;
	if(x4 ==3) printf("MMM");
	if(x4 == 2) printf("MM");
	if(x4 == 1) printf("M");
	
	x3 = (x % 1000) / 100;
	if(x3 == 9) printf("CM");
	if(x3 == 8) printf("DCCC");
	if(x3 == 7) printf("DCC");
	if(x3 == 6) printf("DC");
	if(x3 == 5) printf("D");
	if(x3 == 4) printf("CD");
	if(x3 == 3) printf("CCC");
	if(x3 == 2) printf("CC");
	if(x3 == 1) printf("C ");
	
	x2 = ((x % 1000) % 100) / 10;
	if(x3 == 9) printf("XC");
	if(x3 == 8) printf("LXXX");
	if(x3 == 7) printf("LXX");
	if(x3 == 6) printf("LX");
	if(x3 == 5) printf("L");
	if(x3 == 4) printf("XL");
	if(x3 == 3) printf("XXX");
	if(x3 == 2) printf("XX");
	if(x3 == 1) printf("X");
	
	x1 = (((x % 1000) % 100) % 10) /1; 
	if(x1 == 9) printf("IX");
	if(x1 == 8) printf("VIII");
	if(x1 == 7) printf("VII");
	if(x1 == 6) printf("VI");
	if(x1 == 5) printf("V");
	if(x1 == 4) printf("IV");
	if(x1 == 3) printf("III");
	if(x1 == 2) printf("II");
	if(x1 == 1) printf("I");
	
printf("%d %d %d %d", x1, x2, x3, x4);
	return 0;
}
