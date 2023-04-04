#include <stdio.h>

int main()
{
    int m, n;
    scanf("%d%d", &m, &n);
    if (m <= 0 || n <= 0)
        printf("Nhap m > 0 va n > 0");
    else
    {
        // Cach 1: 
        // for (int i = 1; i <= m; i++)
        // {
        //     for (int j = 1; j <= n; j++)
        //         printf("x ");
        //     printf("\n");
        // }
        // Cach 2:
        for (int i = m; i > 0; i--)
        {
            for (int j = n; j > 0; j--)
                printf("x ");
            printf("\n");
        }
    }
    return 0;
}