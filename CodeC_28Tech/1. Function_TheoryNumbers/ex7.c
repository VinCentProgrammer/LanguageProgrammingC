#include <stdio.h>
#include <math.h>

int prime[10001];
void seive()
{
    for (int i = 0; i <= 10000; i++)
    {
        prime[i] = 1;
    }

    prime[0] = prime[1] = 0;

    for (int i = 2; i <= sqrt(10000); i++)
    {
        if (prime[i])
        {
            for (int j = i * i; j <= 10000; j += i)
            {
                prime[j] = 0;
            }
        }
    }
}

int main()
{
    seive();

    int t;
    printf("t = ");
    scanf("%d", &t);

    while (t--)
    {
        int n;
        printf("n = ");
        scanf("%d", &n);

        for (int i = 2; i <= n / 2; i++)
        {
            if (prime[i] && prime[n - i]){
                printf("%d %d \n", i, n - i);
            }
        }
    }

    return 0;
}
