#include <stdio.h>

int solve(int n, long long k)
{
    int x = n / k;
    int r = n % k;
    long long tong1 = (k - 1) * k / 2;
    long long tong2 = r * (r + 1) / 2;
    return (tong1 * x + tong2);
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n;
        long long k;
        scanf("%d%lld", &n, &k);
        printf("%d \n", solve(n, k));
    }
    return 0;
}