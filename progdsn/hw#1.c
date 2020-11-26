#include<stdio.h>
int main(){
    int a, b, c;
    scanf("%d %d", &a, &b);
    c = a;
    a = b;
    b = c;
    printf("a=%d\nb=%d\n", a, b);
    return 0;
}
