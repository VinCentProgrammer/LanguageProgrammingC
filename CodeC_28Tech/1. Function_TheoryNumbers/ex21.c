#include <stdio.h>

int ntMax(int n)
{
    int res = 0;

    for (int i = 2; i <= n; i++)
    {
        if (n % i == 0)
        {
            res = i;
            n /= i;
        }
    }
    return res;
}
int main()
{
    int t;
    scanf("%d", &t);

    while (t--)
    {
        int n;
        scanf("%d", &n);

        printf("%d\n", ntMax(n));
    }
    return 0;
}