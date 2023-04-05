#include <stdio.h>
#include <math.h>

int count(int n)
{
    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        if (n % i == 0)
            cnt++;
    }
    return cnt;
}

int count1(int n)
{
    int cnt = 0;
    for (int i = 1; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            cnt += 2;
        }
    }

    int c = sqrt(n);
    if (c * c == n)
        --cnt;
    return cnt;
}

int count2(int n)
{
    int res = 1;
    for (int i = 2; i <= sqrt(n); i++)
    {
        int cnt = 0;
        while (n % i == 0)
        {
            cnt++;
            n /= i;
        }
        res *= (cnt + 1);
    }

    if (n != 1)
        res *= 2;
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

        printf("%d %d %d\n", count(n), count1(n), count2(n));
    }
    return 0;
}