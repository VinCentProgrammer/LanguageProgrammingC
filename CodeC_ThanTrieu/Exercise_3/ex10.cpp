#include <stdio.h>

// Ham nhap so nguyen duong n > 0
int enterInteger()
{
    int n;
    printf("Nhap so nguyen duong n = ");
    scanf("%d", &n);
    if (n <= 0)
        printf("Nhap so nguyen duong n > 0");
}
// Ham tinh tong cac chu so cua 1 so nguyen n
int cntSumDigit(int n)
{
    int cnt = 0;
    while (n != 0)
    {
        ++cnt;
        n /= 10;
    }
    return cnt;
}
// Ham tinh tong cac chu so le cua 1 so
int cntSumOddDigit(int n)
{
    int s, cnt = 0;
    while (n != 0)
    {
        s = n % 10;
        if (s % 2 != 0)
            ++cnt;
        n /= 10;
    }
    return cnt;
}
// Ham tinh trung binh cong cua cac chu so cua 1 so
int averageDigit(int n)
{
    int k = cntSumDigit(n);
    int s = 0;
    while (n != 0)
    {
        s += n % 10;
        n /= 10;
    }
    return s / k;
}
int main()
{

    int k = enterInteger();
    printf("Tong cac chu so cua %d so la : %d \n", k, cntSumDigit(k));
    printf("Tong cac chu so le cua %d so la : %d \n", k, cntSumOddDigit(k));
    printf("Tong trung binh cong cac chu so cua %d so la : %d", k, cntSumOddDigit(k));
    return 0;
}