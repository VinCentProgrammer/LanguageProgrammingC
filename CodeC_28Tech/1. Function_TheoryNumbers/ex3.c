#include <stdio.h>
#include <math.h>

int max(int a, int b)
{
    return a > b ? a : b;
}
// Sang so nguyen to tren doan [l; r]

void sieve(int l, int r)
{
    int prime[r - l + 1];

    for (int i = 0; i <= r - l + 1; i++)
        prime[i] = 1;

    for (int i = 2; i <= sqrt(r - l + 1); i++)
    {
        for (int j = max(i * i, (l + i - 1) / i * i); j <= r; j += i)
        {
            prime[j - l] = 0;
        }
    }

    for (int i = max(2, l); i <= r; i++)
    {
        if (prime[i - l])
            printf("%d ", i);
    }
}


int main()
{
    int l, r;
    scanf("%d %d", &l, &r);
    sieve(l, r);
    return 0;
}