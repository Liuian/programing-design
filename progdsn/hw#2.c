#include<stdio.h>

int main(){
    int x, y;
    scanf("%d %d", &x, &y);
    float c;
    c =(float) x/y;
    printf("%.1f %.2f", c, c);
    return 0;
}
