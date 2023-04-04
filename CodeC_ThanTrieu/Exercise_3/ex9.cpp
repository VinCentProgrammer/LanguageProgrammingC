#include <stdio.h>

// Ham nhap 1 so nguyen duong n
int enterNumInteger()
{
    int n;
    printf("Nhap vao so nguyen duong n = ");
    scanf("%d", &n);
    if (n < 0)
        printf("Nhap so nguyen duong n > 0");
}
// Ham tinh tong tung chu so trong 1 so
int sumDigit(int n)
{
    int s = 0;
    while (n != 0)
    {
        s += n % 10;
        n /= 10;
    }
    return s;
}
// Ham phan tich thua so nguyen to cua n
void analyzeNumToPrime(int n)
{
    int k = 2;
    printf("Tich cac thua so nguyen to cua %d la:  ", n);
    while (n != 1)
    {
        if (n % k == 0)
        {
            printf("%d", k);
            if (n != k)
                printf("x");
        }
        else
            k++;
        n /= k;
    }
}
int main()
{
    int n = enterNumInteger();
    printf("Tong cac chu so cua n la %d\n", sumDigit(n));
    analyzeNumToPrime(n);
    return 0;
}