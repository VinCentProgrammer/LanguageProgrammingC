#include <stdio.h>

int main()
{
    int m, n;
    scanf("%d%d", &m, &n);
    if (m <= 0 || n <= 0)
    {
        printf("Nhap m > 0 va n > 0");
    }
    else
    {
        for (int i = 1; i <= m; i++)
        {
            // Cach 1: 
            // for (int j = 1; j <= n; j++)
            //     printf("%d ", j);
            // printf("\n");
            // Cach 2: 
            for (int j = n; j > 0; j--)
                printf("%d ", n + 1 - j);
            printf("\n");
        }
    }
    return 0;
}