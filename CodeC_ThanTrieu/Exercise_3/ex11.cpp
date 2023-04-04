#include <stdio.h>

// Ham nhap so nguyen duong n > 0
int enterInteger()
{
    int n;
    printf("Nhap so nguyen n = ");
    scanf("%d", &n);
    if (n <= 0)
        printf("Nhap so n > 0");
}
// Ham kiem tra day chu so cua 1 so co tang hay khong
int checkIncreaseDigit(int n)
{
    while (n != 0)
    {
        int tmp1 = n % 10;
        n /= 10;
        int tmp2 = n % 10;
        n /= 10;
        if (tmp2 > tmp1)
            return 0;
    }
    return 1;
}
// Ham tim chu so dau cua 1 so
int findDigitHead(int n)
{
    int s;
    while (n != 0)
    {
        s = n % 10;
        n /= 10;
    }
    return s;
}
// Ham tan xuat xuat hien cua chu so dau tien cua 1 so
int freNumHead(int n)
{
    int digitHead = findDigitHead(n);
    int cnt = 0;
    while (n != 0)
    {
        int tmp = n % 10;
        if (tmp == digitHead)
            ++cnt;
        n /= 10;
    }
    return cnt;
}
int main()
{
    int k = enterInteger();

    if (checkIncreaseDigit(k))
        printf("Day so tang dan \n");
    else
        printf("Day so khong tang dan\n");

    printf("Chu so dau tien cua so %d la %d\n", k, findDigitHead(k));

    printf("Tan suat xuat hien cua chu so dau cua so %d la %d\n", k, freNumHead(k));

    return 0;
}