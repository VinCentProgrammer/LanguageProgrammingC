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
            c1++;

        int cnt = 0;   
        for (int i = c1; i <= c2; i++)
            cnt++;
        printf("%d \n", cnt);
    }
    return 0;
}