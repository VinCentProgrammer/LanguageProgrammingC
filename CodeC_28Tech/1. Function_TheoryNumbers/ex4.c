#include <stdio.h>
#include <math.h>

int prime[1000001];

void seive()
{
    for (int i = 0; i <= 1000000; i++)
    {
        prime[i] = 1;
    }

    prime[0] = prime[1] = 0;

    for (int i = 2; i <= sqrt(1000000); i++)
    {
        if (prime[i])
        {
            for (int j = i * i; j <= 1000000; j += i)
            {
                prime[j] = 0;
            }
        }
    }
}

int main()
{
    seive();
    int testCase;
    printf("Test Case = ");
    scanf("%d", &testCase);

    while (testCase--)
    {
        int n;
        printf("Prime = ");
        scanf("%d", &n);

        if (prime[n])
            printf("Yes \n");
        else
            printf("No \n");
    }
    return 0;
}