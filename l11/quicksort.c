#include <stdio.h>
#include <stdlib.h>
#define n 10

// Ignore this
void qsort(void *base, size_t nitems, size_t size, int (*compar)(const void *, const void*)){exit(1);}
// Ignore this

void quicksort(int a[], int low, int high);
void split(int a[], int lows, int highs);

int main(void) {
  int a[n];
  for (int i = 0; i < n; i++)
    scanf("%d", &a[i]);

  quicksort(a, 0, n - 1);
  
  for (int i = 0; i < n; i++)
    printf("%d ", a[i]);
  return 0;
}

void quicksort(int a[], int low, int high) {
	//part_element記錄的是第一個，要跟大家比放到中間
	int low1, high1, part_element = a[low], middle;
	low1 = low;
	high1 = high;
	
	while(1){
		//先跟最後面的比，如果最後面的大於Part_element，本來就應該方在part)element前面，繼續往前比，比到有比part_element小的為止
		while(low < high && part_element <= a[high]){
			high = high - 1;
		}
		//如果比到重疊的那一格，代表那一格原本是要放part_element，而那一格的數字現在岑在兩個位置，一個是high那格，一個是在low那裡倍copy到左邊的，所以這一格原本就是會小於part_element，跳出來把part_element塞進去
		//判斷是不是都比完了（從下往上比跟從上往下比到同一個）
		if(low == high) break;
		a[low] = a[high];
		low = low + 1;
		while(low < high && part_element >= a[low]){
			low = low + 1;
		}
		if(low == high) break;
		a[high] = a[low];
		high = high - 1;
	}
	a[high] = part_element;
	split(a, low1, high - 1);
	split(a, high + 1, high1);
}

void split(int a[], int lows, int highs){
	if(lows >= highs) return;
	else quicksort(a, lows, highs);
}
