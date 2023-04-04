#include <stdio.h>
#include "decleare.h"

int main()
{
    int a, b;
    scanf("%d %d", &a, &b);
    printf("Tong a + b = %d\n", sum(a, b));
    printf("Hieu a - b = %d", sub(a, b));
    return 0;
}