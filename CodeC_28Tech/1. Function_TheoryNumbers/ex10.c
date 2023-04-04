#include <stdio.h>
#include <math.h>

// So co 3 uoc so la binh phuong cua 1 so nguyen to

int prime[1001];
void seive()
{
    for (int i = 0; i <= 1000; i++)
    {
        prime[i] = 1;
    }

    prime[0] = prime[1] = 0;

    for (int i = 2; i <= sqrt(1000); i++)
    {
        if (prime[i])
        {
            for (int j = i * i; j <= 1000; j += i)
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
    scanf("%d", &t);
    while (t--)
    {
        int n;
        scanf("%d", &n);
        for (int i = 0; i <= sqrt(n); i++)
        {
            if (prime[i])
                printf("%d ", i * i);
        }
        printf("\n");
    }
    return 0;
}