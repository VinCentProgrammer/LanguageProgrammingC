#include <stdio.h>
#include <math.h>

void pt1(int n)
{
    for (int i = 2; i <= sqrt(n); i++)
    {
        while (n % i == 0)
        {
            printf("%d ", i);
            n /= i;
        }
    }

    if (n != 1)
        printf("%d", n);
}

void pt2(int n)
{
    int cnt = 0;
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            printf("%d", i);
            while (n % i == 0)
            {
                cnt++;
                n /= i;
            }
            printf("(%d) ", cnt);
        }
    }

    if (n != 1)
        printf("%d(1)", n);
}

void pt3(int n)
{
    for (int i = 2; i <= sqrt(n); i++)
    {
        while (n % i == 0)
        {
            printf("%d", i);
            n /= i;
            if (n != 1)
                printf("x");
        }
    }
    if (n != 1)
        printf("%d", n);
}

void pt4(int n)
{
    printf("%d = ", n);
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            int cnt = 0;
            while (n % i == 0)
            {
                cnt++;
                n /= i;
            }
            printf("%d^%d ", i, cnt);
            if (n != 1)
                printf("*");
        }
    }

    if (n != 1)
        printf("%d^1", n);
}


int main()
{
    int n;
    printf("n = ");
    scanf("%d", &n);

    pt4(n);

    return 0;
}