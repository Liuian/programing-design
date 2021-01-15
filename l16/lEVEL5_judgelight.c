#include <stdio.h>
#include <stdlib.h>

struct ESPer {
    char name[64];
    int level;
};

int cmp(const void *a, const void *b);
void sort_level(struct ESPer *arr, int length);

int main()
{
    int n;
    struct ESPer tokiwadai[100];

    scanf("%d", &n);
    for(int i = 0; i < n; ++i) {
        scanf("%d %s", &(tokiwadai[i].level), tokiwadai[i].name);
    }

    sort_level(tokiwadai, n);

    for(int i = 0;i < n;++i) {
        printf("%d %s\n", tokiwadai[i].level, tokiwadai[i].name);
    }

    return 0;
}
// Your code goes here
int cmp(const void *a, const void *b){
	int i = (*(struct ESPer*)a).level;
	int j = (*(struct ESPer*)b).level;
	if(i > j) return 1;
	else if(i == j) return 0;
	else return -1;
}
void sort_level(struct ESPer *arr, int length){
	//sizeof那為什麼這樣放
	qsort((void*)arr, length, sizeof(struct ESPer), cmp);
}
