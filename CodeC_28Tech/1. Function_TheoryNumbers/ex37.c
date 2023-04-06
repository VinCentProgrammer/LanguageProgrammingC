#include <stdio.h>
#include <math.h>
#include <limits.h>

// int gcd(long long a, long long b)
// {
//     if (a == 0 || b == 0)
//         return a + b;
//     else
//     {
//         while (a != b)
//         {
//             if (a > b)
//                 a -= b;
//             else
//                 b -= a;
//         }
//         return a;
//     }
// }

// int main()
// {
//     long long a, b;
//     scanf("%lld%lld", &a, &b);
//     if (gcd(a, b) == 1)
//         printf("YES \n");
//     else
//         printf("NO \n");
//     return 0;
// }

#define ll long long

ll phi(ll n)
{
    ll res = n;
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            while (n % i == 0)
                n /= i;
            res -= res / i;
        }
    }
    return res;
}

int main()
{
    ll n;
    scanf("%lld", &n);

    printf("%lld \n", phi(n));
    return 0;
}