#include <stdio.h>

int tn(int n)
{
    int tmp1 = n, tmp2 = n, tmp3 = n;
    int s = 0, cnt = 0, dem = 1, k = 1;
    while (tmp1 != 0)
    {
        cnt++;
        tmp1 /= 10;
    }
    while (dem < cnt)
    {
        k *= 10;
        dem++;
    }
    while (tmp2 != 0)
    {
        s += (tmp2 % 10) * k;
        tmp2 /= 10;
        k /= 10;
    }
    if (tmp3 == s)
        return 1;
    return 0;
}
int main()
{
    int k;
    printf("Nhap so k = ");
    scanf("%d", &k);
    if (k <= 0)
        printf("Nhap so k lon hon 0");
    else
    {
        for (int i = 10000000; i < 100000000; i += k)
        {
            if (tn(i))
                printf("%d ", i);
        }
    }

    return 0;
}