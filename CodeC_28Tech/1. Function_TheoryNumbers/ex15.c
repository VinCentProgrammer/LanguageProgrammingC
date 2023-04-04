#include <stdio.h>
#include <math.h>

int prime[100001];

void seive()
{
    for (int i = 1; i <= 100000; i++)
    {
        prime[i] = i;
    }

    for (int i = 2; i <= sqrt(100000); i++)
    {
        if (prime[i])
        {
            for (int j = i * i; j <= 100000; j += i)
            {
                if (prime[j] == j)
                    prime[j] = i;
            }
        }
    }
}

void analyze(int n)
{
    while (n != 1)
    {
        int cnt = 0;
        int tmp = prime[n];

        while (n % tmp == 0)
        {
            cnt++;
            n /= tmp;
        }

        printf("%d(%d) ", tmp, cnt);
    }
}

int main()
{
    seive();
    int t;
    printf("Nhap vao so luong test case t = ");
    scanf("%d", &t);

    for (int i = 1; i <= t; i++)
    {
        int n;
        printf("Nhap vao n = ");
        scanf("%d", &n);

        printf("#TC%d: ", i);
        analyze(n);
        printf("\n");
    }
    return 0;
}