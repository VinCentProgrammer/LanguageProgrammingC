#include <stdio.h>

int main()
{
    int h;
    scanf("%d", &h);
    if (h <= 0)
        printf("Nhap h > 0");
    else
    {
        for (int i = 1; i <= h; i++)
        {
            // In ben trai
            for (int j = 1; j <= h; j++)
            {
                if (j < h + 1 - i)
                    printf(" ");
                else
                    printf("*");
            }
            // In ben phai
            for (int j = 1; j <= i - 1; j++)
                printf("*");
            printf("\n");
        }
    }
    return 0;
}