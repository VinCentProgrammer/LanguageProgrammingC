#include <stdio.h>
#include <math.h>

// Ham nguyen to
int prime(int n)
{
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
            return 0;
    }
    return n > 1;
}
int main()
{
    int a, b;
    scanf("%d%d", &a, &b);
    if (a > 0 && b > 0 && b > a)
    {
        for (int i = a; i <= b; i++)
        {
            if (prime(i))
                printf("%d ", i);
        }
    }
    else
        printf("Nhap vao 2 so a,b > 0 va b > a");
    return 0;
}