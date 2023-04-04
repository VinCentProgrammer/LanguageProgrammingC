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
    return 1;
}
// Ham nhap so nguyen duong n
int enterInteger()
{
    int n;
    do
    {
        printf("Nhap vao so nguyen duong n = ");
        scanf("%d", &n);
    } while (n < 0);
}
// Ham liet ke cac uoc cua n
int listGcdOfNum(int n)
{
    for (int i = 1; i <= n; i++)
    {
        if (n % i == 0)
            printf("%d ", i);
    }
}

// Ham liet ke cac uoc nguyen cua n
int listGcdPrimeOfNum(int n)
{
    for (int i = 1; i <= n; i++)
    {
        if (n % i == 0 && prime(i))
            printf("%d ", i);
    }
}

// Ham dem so uoc cua n
int cntGcdOfNum(int n)
{
    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        if (n % i == 0)
            ++cnt;
    }
    return cnt;
}
int main()
{
    int k = enterInteger();
    printf("Liet ke cac uoc cua %d la ", k);
    listGcdOfNum(k);
    printf("\n");
    
    printf("Liet ke cac uoc nguyen to cua %d la ", k);
    listGcdPrimeOfNum(k);
    printf("\n");
    
    printf("Tong cac uoc cua %d la %d", k, cntGcdOfNum(k));
    return 0;
}