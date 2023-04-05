#include <stdio.h>
#include <math.h>

int main()
{
    int t;
    scanf("%d", &t);

    while (t--)
    {
        int a, b;
        scanf("%d%d", &a, &b);

        int c1 = sqrt(a), c2 = sqrt(b);
        if (c1 * c1 != a)
            ++c1;
        for (int i = c1; i <= c2; i++)
        {
            printf("%d ", i * i);
        }
        printf("\n");
    }
    return 0;
}