#include <stdio.h>
#include <math.h>
#include <string.h>

int tn(int n)
{
    int tmp = n;
    int rev = 0;
    while (n != 0)
    {
        rev = rev * 10 + n % 10;
        n /= 10;
    }
    return rev == tmp;
}

int tn2(char str[])
{
    int l = 0, r = strlen(str) - 1;
    while (l < r)
    {
        if (str[l] != str[r])
            return 0;
    }

    return 1;
}

int check(int n)
{
    int tmp = n;
    int cnt = 0;
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            cnt++;
            n /= i;
        }
    }

    if (n != 1)
        ++cnt;

    if (cnt < 3)
        return 0;
    else
        return (cnt >= 3) && tn(tmp);
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
    if (!ok)
        printf("-1\n");
    return 0;
}