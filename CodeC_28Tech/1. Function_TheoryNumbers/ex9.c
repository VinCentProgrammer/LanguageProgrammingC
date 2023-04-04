#include <stdio.h>
#include <math.h>

int gcd(int a, int b)
{
    if (a == 0 || b == 0)
        return a + b;
    else
    {
        while (a != b)
        {
            if (a > b)
                a = a - b;
            else
                b = b - a;
        }
    }

    return a;
}

int main()
{
    int a, b;
    scanf("%d %d", &a, &b);

    for (int i = a; i < b; i++)
    {
        for (int j = i + 1; j <= b; j++)
        {
            if (gcd(i, j) == 1)
                printf("(%d,%d) \n", i, j);
        }
    }
    return 0;
}
