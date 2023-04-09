#include <stdio.h>

#define ll long long

ll gcd(ll a, ll b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

ll lcm(ll a, ll b)
{
    return a * b / gcd(a, b);
}

ll lcmSum(int n)
{
    ll res = 0;
    for (int i = 1; i <= n; i++)
    {
        res += lcm(i, n);
    }
    return res;
}

ll p[1000001];
ll res[1000001];

// Sang tinh phi ham euler cua n
void seive()
{
    for (int i = 1; i <= 1000000; i++)
    {
        p[i] = i;
    }

    for (int i = 2; i <= 1000000; i++)
    {
        if (p[i] == i)
        {
            p[i] = i - 1;
            for (int j = 2 * i; j <= 1000000; j += i)
            {
                p[j] -= p[j] / i;
            }
        }
    }
}

// Tinh tong d * p[d]

void seive2()
{
    for (int i = 1; i <= 1000000; i++)
    {
        for (int j = i; j <= 1000000; j += i)
        {
            res[j] += i * p[i];
        }
    }
}

int main()
{
    seive();
    seive2();

    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n;
        scanf("%d", &n);
        printf("%lld %lld \n", 1ll * (res[n] + 1) * n / 2, 1ll * lcmSum(n));
    }
    return 0;
}