#include <stdio.h>
#include <math.h>

int isPrime(int n)
{
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
            return 0;
    }

    return n > 1;
}

int sumDigit(int n)
{
    int res = 0;
    while (n != 0)
    {
        res += n % 10;
        n /= 10;
    }

    return res;
}

int checkSmith(int n)
{
    int tmp = n;

    int sumPrime = 0;

    for (int i = 2; i <= n; i++)
    {
        while (n % i == 0)
        {
            sumPrime += sumDigit(i);
            n /= i;
        }
    }

    if (sumPrime == sumDigit(tmp))
        return 1;
    else
        return 0;
}

int main()
{
    int t;
    scanf("%d", &t);

    while (t--)
    {
        int n;
        scanf("%d", &n);

        if (!isPrime(n) && checkSmith(n))
            printf("YES \n");
        else
            printf("NO \n");
    }
    return 0;
}