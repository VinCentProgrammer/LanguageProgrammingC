#include <stdio.h>
#include <math.h>

int check(int n)
{
    int res = 0;
    for (int i = 2; i <= sqrt(n); i++)
    {
        int cnt = 0;
        while (n % i == 0)
        {
            cnt++;
            n /= i;
        }
        if (cnt >= 2)
            return 0;
        if (cnt == 1)
            ++res;
    }

    if (n != 1)
        ++res;
    return res == 3;
}

int main()
{
    int t;
    scanf("%d ", &t);

    while (t--)
    {
        int n;
        scanf("%d ", &n);
        
        if (check(n))
            printf("1 \n");
        else
            printf("0 \n");
    }

    return 0;
}