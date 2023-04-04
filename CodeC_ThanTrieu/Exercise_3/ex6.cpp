#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    if (n % 2 == 1 && n >= 7)
    {
        // Phan tren

        for (int i = 1; i <= n / 3; i++)
        {
            for (int k = 1; k <= n / 3; k++)
            {
                if (k < n / 3 + 1 - i)
                    printf(" ");
                else
                    printf("*");

                if (k <= i)
                    printf("*");
                else
                    printf(" ");
            }

            for (int k = 1; k <= n / 3; k++)
            {
                if (k < n / 3 + 1 - i)
                    printf(" ");
                else
                    printf("*");

                if (k <= i)
                    printf("*");
                else
                    printf(" ");
            }
            printf("\n");
        }
        // Phan duoi

        for (int i = 1; i <= n / 2 + 1; i++)
        {
            for (int k = 1; k <= n / 2 + 1; k++)
            {
                if (k < i)
                    printf(" ");
                else
                    printf("*");
            }

            for (int k = n / 2 + 1; k >= 1; k--)
            {
                if (k >= i)
                    printf("*");
                else
                    printf(" ");
            }

            printf("\n");
        }
    }
    else
        printf("Nhap n le va lon hon 7");
    return 0;
}