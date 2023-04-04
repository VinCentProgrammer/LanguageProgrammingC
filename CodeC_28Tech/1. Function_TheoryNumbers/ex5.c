#include <stdio.h>
#include <math.h>

int checkPrime(int n)
{
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
            return 0;
    }
    return n > 1;
}

int checkDigitPrime(int n)
{
    while (n)
    {
        int tmp = n % 10;
        if (!checkPrime(tmp))
            return 0;
        n /= 10;
    }

    return 1;
}

int max(int a, int b)
{
    return a > b ? a : b;
}


int sieve(int l, int r)
{
    int prime[r - l + 1];
    for (int i = 0; i <= r - l + 1; i++)
    {
        prime[i] = 1;
    }

    for (int i = 2; i <= sqrt(r - l + 1); i++)
    {
        for (int j = max(i * i, (l + i - 1) / i * i); j <= r; j += i)
        {
            prime[j - l] = 0;
        }
    }
    
    int cnt = 0;
    for (int i = max(2, l); i <= r; i++)
    {
        if (prime[i - l] && checkDigitPrime(i))
            cnt++;
    }

    return cnt;
}

int main()
{
    int t;
    printf("t = ");
    scanf("%d", &t);

    while (t--)
    {
        int l, r;
        scanf("%d %d", &l, &r);
        printf("%d \n", sieve(l, r));
    }
    return 0;
}