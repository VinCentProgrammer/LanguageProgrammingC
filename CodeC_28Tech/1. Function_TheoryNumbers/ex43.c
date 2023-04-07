#include <stdio.h>

int phi[1000001];
void seive()
{
    for (int i = 1; i <= 1000000; i++)
    {
        phi[i] = i;
    }

    for (int i = 2; i <= 1000000; i++)
    {
        if (phi[i] == i)
        {
            phi[i] = i - 1;
            for (int j = 2 * i; j <= 1000000; j += i)
            {
                phi[j] -= phi[j] / i;
            }
        }
    }
}

int main()
{
    seive();
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n;
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
        {
            printf("%d ", phi[i]);
        }
    }
    return 0;
}