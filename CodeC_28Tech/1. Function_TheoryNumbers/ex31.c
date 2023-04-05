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

int fibo[11];
void creaseFibo()
{
    fibo[0] = 0;
    fibo[1] = 1;
    for (int i = 2; i <= 10; i++)
    {
        fibo[i] = fibo[i - 1] + fibo[i - 2];
    }
}

int check(int n)
{
    if (checkPrime(n))
    {
        for (int i = 0; i <= 10; i++)
        {
            if (fibo[i] == sumDigit(n))
                return 1;
        }
    }

    return 0;
}

int main()
{
    int a, b;
    scanf("%d%d", &a, &b);

    int ok = 0;
    for (int i = a; i <= b; i++)
    {
        if (check(i))
        {
            printf("%d ", i);
            ok = 1;
        }
    }


    if (ok)
        printf("-1 \n");

    return 0;
}