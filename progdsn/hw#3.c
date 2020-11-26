#include <stdio.h>
#define pi 3.14f

int main(){
    int rad;
    float area, length;
    scanf("%d", &rad);
    area = pi *rad *rad;
    length = 2 * pi * rad;
    printf("%.2f %.2f", area, length);
    return 0;
}
