#include <stdio.h>
#include <limits.h>

long long fibo[92];
void creaseFibo()
{
    fibo[0] = 0;
    fibo[1] = 1;
    for (int i = 2; i <= 92; i++)
        fibo[i] = fibo[i - 2] + fibo[i - 1];
}

int main()
{
    creaseFibo();
    int n;
    scanf("%d", &n);
    for (int i = 0; i <= n - 1; i++)
    {
        printf("%lld ", fibo[i]);
    }
    return 0;
}
/*
#include <stdio.h>

long long fibo[93];
void creaseFibo()
{
    fibo[0] = 0;
    fibo[1] = 1;
    for (int i = 2; i <= 92; i++)
    {
        fibo[i] = fibo[i - 2] + fibo[i - 1];
    }
}

int main()
{
    creaseFibo();
    int t;
    scanf("%d", &t);

    while (t--)
    {
        long long n;
        scanf("%lld", &n);

        int ok = 0;
        for (int i = 0; i <= 92; i++)
        {
            if (fibo[i] == n){
                ok = 1;
                break;
            }
        }

        if (ok == 1)
            printf("YES \n");
        else
            printf("NO \n");
    }
    return 0;
}

*/