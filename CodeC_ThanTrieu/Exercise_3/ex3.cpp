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
            for (int j = 1; j <= i; j++)
                printf("* ");
            printf("\n");
        }
    }
    return 0;
}