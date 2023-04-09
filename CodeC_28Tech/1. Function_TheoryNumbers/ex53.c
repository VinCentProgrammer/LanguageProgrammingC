#include <stdio.h>

int fibo[1001];
void solve()
{
    fibo[0] = 0;
    fibo[1] = 1;
    for (int i = 2; i <= 1000; i++)
    {
        fibo[i] = fibo[i - 1] + fibo[i - 2];
        fibo[i] %= (int)(10e9 + 7);
    }
}

int main()
{
    solve();
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n;
        scanf("%d", &n);
        printf("%d", fibo[n]);
    }
    return 0;
}