#include<stdio.h>
#include<string.h>

char* reference(char author[], char title[], char conference[], char location[], char date[], char ppdoi[]);

int main(){
    char author[100], title[150], conference[150], location[30], date[5], ppdoi[60];
    scanf("%[^\n]\n%[^\n]\n%[^\n]\n%[^\n]\n%[^\n]\n%[^\n]", author, title, conference, location, date, ppdoi);
    printf("%s", reference(author, title, conference, location, date, ppdoi));
    return 0;
}

// Your code goes here
char* reference(char author[], char title[], char conference[], char location[], char date[], char ppdoi[]){
	char result[300];
	strcat(&author, &title);
	strcat(

}
