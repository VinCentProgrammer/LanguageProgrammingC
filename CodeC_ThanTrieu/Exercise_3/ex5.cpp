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
            // In phan ben trai
            int cnt = 1;
            for (int j = 1; j <= h; j++)
            {
                if (j < h + 1 - i)
                    printf(" ");
                else
                    printf("%d", cnt++);
            }
            cnt = 1;
            // In phan ben phai
            int k = i - 1;
            for (int j = 1; j <= i - 1; j++)
            {
                printf("%d", k--);
            }
            printf("\n");
        }
    }
    return 0;
}