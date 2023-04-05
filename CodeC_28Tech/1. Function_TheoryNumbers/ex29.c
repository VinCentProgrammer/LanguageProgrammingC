#include <stdio.h>

int sum(long long n)
{
    int res = 0;
    while (n != 0)
    {
        res += n % 10;
        n /= 10;
    }
    return res;
}
int main()
{
    int t;
    scanf("%d", &t);

    while (t--)
    {
        long long n;
        scanf("%lld", &n);
        printf("%d \n", sum(n));
    }
    return 0;
}