#include <stdio.h>
#include <math.h>

int sum(int n)
{
    int res = 0;
    for (int i = 1; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            res += (i + (n / i));
        }
    }

    int c = sqrt(n);
    if (c * c == n)
        res -= c;
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
        printf("%d \n", sum(n));
    }
    return 0;
}