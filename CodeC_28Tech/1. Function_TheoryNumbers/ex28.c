#include <stdio.h>
#include <math.h>

// int check(long long n)
// {
//     int sum = 0;
//     for (int i = 1; i <= sqrt(n); i++)
//     {
//         if (n % i == 0)
//         {
//             if (i != n / i)
//                 sum += (i + (n / i));
//             else
//                 sum += i;
//         }
//     }

//     return n == sum - n;
// }

int isPrime(long long n)
{
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
            return 0;
    }
    return n > 1;
}

long long hh[10];
int n = 0;

void init()
{
    for (int i = 1; i <= 32; i++)
    {
        if (isPrime(i))
        {
            int tmp = (int)pow(2, i) - 1;
            if (isPrime(tmp))
            {
                hh[n++] = 1ll * tmp * (int)pow(2, i - 1);
            }
        }
    }
}
int main()
{
    init();
    int t;
    scanf("%d", &t);

    while (t--)
    {
        long long n;
        scanf("%lld", &n);
        for (int i = 0; i <= 10; i++)
        {
            if (hh[i] == n)
                printf("YES \n");
        }
    }
    return 0;
}