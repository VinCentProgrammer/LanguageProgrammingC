#include <stdio.h>

// Ham kiem tra cac chu so cua 1 so khong tang
int checkDigitZeroIncrease(int n)
{
    while (n != 0)
    {
        int s1 = n % 10;
        n /= 10;
        int s2 = n % 10;
        n /= 10;
        if (s1 > s2)
            return 0;
    }
    return 1;
}

// Ham kiem tra cac chu so cua 1 so khong giam
int checkDigitZeroDecrease(int n)
{
    while (n != 0)
    {
        int s1 = n % 10;
        n /= 10;
        int s2 = n % 10;
        n /= 10;
        if (s1 < s2)
            return 0;
    }
    return 1;
}

// Ham kiem tra tong chu so chan bang tong chu so le
int checkTotalDigitEvenEqualTotalDigitOdd(int n)
{
    int totalEven = 0, totalOdd = 0;
    while (n != 0)
    {
        if ((n % 10) % 2 == 0)
            totalEven += (n % 10);
        else
            totalOdd += (n % 10);
        n /= 10;
    }
    if (totalEven == totalOdd)
        return 1;
    return 0;
}
int main()
{
    printf("Cac so khong tang la: \n");
    for (int i = 10000; i < 100000; i++)
    {
        if (checkDigitZeroIncrease(i))
            printf("%d ", i);
    }
    printf("\n");

    printf("Cac so khong giam la: \n");
    for (int i = 10000; i < 100000; i++)
    {
        if (checkDigitZeroDecrease(i))
            printf("%d ", i);
    }
    printf("\n");

    printf("Cac so co tong chu so chan bang tong chu so le la: \n");
    for (int i = 10000; i < 100000; i++)
    {
        if (checkTotalDigitEvenEqualTotalDigitOdd(i))
            printf("%d ", i);
    }
    printf("\n");
    return 0;
}