#include <stdio.h>
#include <math.h>

int prime[100001];

void seive()
{
    for (int i = 0; i <= 100000; i++)
    {
        prime[i] = i;
    }

    for (int i = 2; i <= sqrt(100000); i++)
    {
        for (int j = i * i; j <= 100000; j += i)
        {
            if (prime[j] == j)
                prime[j] = i;
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
            printf("%d ", prime[i]);
        }
        printf("\n");
    }
    return 0;
}