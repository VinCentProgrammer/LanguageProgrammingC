#include <stdio.h>
#include <string.h>

#define ll long long

int check(char c[])
{
    int head = c[0] - '0', tail = c[strlen(c) - 1] - '0';
    if (head != 2 * tail && tail != 2 * head)
        return 0;
    int l = 1, r = strlen(c) - 2;
    while (l < r)
    {
        if (c[l] != c[r])
            return 0;
        l++;
        r--;
    }
    return 1;
}

int tn(ll n)
{
    ll tmp = n, rev = 0;
    while (n)
    {
        rev = rev * 10 + n % 10;
        n /= 10;
    }

    return rev == tmp;
}

int check2(ll n)
{
    ll c = n % 10; n /= 10;
    ll rev = 0;
    while (n >= 10)
    {
        rev = rev * 10 + n % 10;
        n /= 10;
    }

    if (c != 2 * n && n != 2 * c)
        return 0;
    return tn(rev);
}
int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        ll n;
        scanf("%lld", &n);
        if (check2(n))
            printf("YES \n");
        else
            printf("NO \n");
    }
    return 0;
}