#include <stdio.h>
#include <math.h>

#define ll long long
// Tim bac cua so nguyen so p trong n!

int degree1(int n, int p)
{
    int ans = 0;
    for (int i = p; i <= n; i += p)
    {
        int tmp = i;
        while (tmp % p == 0)
        {
            ans++;
            tmp /= p;
        }
    }
    return ans;
}

int degree2(int n, int p)
{
    int ans = 0;
    for (int i = p; i <= n; i *= p)
    {
        ans += n / i;
    }
    return ans;
}

int nt(int n)
{
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
            return 0;
    }
    return n > 1;
}

ll countDivisor(int n)
{
    ll res = 1;
    for (int i = 1; i <= n; i++)
    {
        if (nt(i))
        {
            res *= (degree1(n, i) + 1);
        }
    }
    return res;
}
int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n;
        scanf("%d", &n);
        printf("%lld \n", countDivisor(n));
    }
    return 0;
}