#include <stdio.h>
#include <math.h>

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
// Ham kiem tra so nguyen to
int prime(int n)
{
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
            return 0;
    }
    return n > 1;
}
// Ham liet ke n so nguyen to dau tien
void listPrime(int n)
{
    for (int i = 2; i <= n; i++)
    {
        if (prime(i))
            printf("%d ", i);
    }
}
// Ham liet ke n so fibonacci dau tien
void listFibo(int n)
{
    long long fibo[n];
    fibo[1] = 1;
    fibo[2] = 1;
    for (int i = 3; i <= n; i++)
    {
        fibo[i] = fibo[i - 1] + fibo[i - 2];
    }
    for (int i = 1; i <= n; i++)
    {
        printf("%lld ", fibo[i]);
    }
}
// Ham kiem tra so chinh phuong
int principal(int n)
{
    if (sqrt(n) * sqrt(n) == n)
        return 1;
    return 0;
}
// Ham liet ke n so chinh phuong dau tien
void listPrincipal(int n)
{
    for (int i = 4; i <= n; i++)
    {
        if (principal(i))
            printf("%d ", i);
    }
}
int main()
{
    int k = enterInteger();
    printf("Liet ke cac so nguyen to dau tien cua %d la ", k);
    listPrime(k);
    printf("\n");

    printf("Liet ke cac so fibo dau tien cua %d la ", k);
    listFibo(k);
    printf("\n");

    printf("Liet ke cac so chinh phuong dau tien cua %d la ", k);
    listPrincipal(k);
    printf("\n");
    return 0;
}