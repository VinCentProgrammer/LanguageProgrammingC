#include <stdio.h>

#define ll long long

int powMod1(int a, int b, int m)
{
    ll res = 1;
    for (int i = 1; i <= b; i++)
    {
        res *= a;
        res %= m;
    }
    return res;
}

int powMod2(int a, int b, int m)
{
    ll res = 1;
    while (b)
    {
        if (b % 2 == 1)
        {
            res *= b;
            res %= m;
        }
        a *= a;
        a %= m;
        b /= 2;
    }

    return res;
}

int powMod3(int a, int b, int m)
{
    if (b == 0)
        return 1;
    ll tmp = powMod3(a, b / 2, m);
    if (b % 2 == 1)
        return (a % m * ((tmp % m) * (tmp % m) % m)) % m;
    return (tmp % m) * (tmp % m) % m;
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int x, y, m;
        scanf("%d%d%d", &x, &y, &m);
        printf("%d %d %d \n", powMod1(x, y, m), powMod2(x, y, m), powMod3(x, y, m));
    }
    return 0;
}