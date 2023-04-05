#include <stdio.h>

int count(int n)
{
    int res = 0;

    for (int i = 5; i <= n; i += 5)
    {
        int tmp = i;
        while (tmp % 5 == 0)
        {
            res++;
            tmp /= 5;
        }
    }

    return res;
}

int count2(int n)
{
    int ans = 0;
    for (int i = 5; i <= n; i *= 5)
    {
        ans += n / i;
    }
    return ans;
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n;
        scanf("%d", &n);
        printf("%d %d\n", count(n), count2(n));
    }
    return 0;
}