#include <stdio.h>
#include <math.h>

// Ham kiem tra so nguyen to
int checkPrime(int n)
{
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
            return 0;
    }
    return n > 1;
}

// Ham kiem tra so n la so thuan nghich
int checkReverse(int n)
{
    int tmp1 = n, tmp2 = n, tmp3 = n;
    int cnt = 0, dem = 1, k = 1, s = 0;
    while (tmp1 != 0)
    {
        ++cnt;
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
    if (s == tmp3)
        return 1;
    else
        return 0;
}
// Ham kiem tra khong cho chu so 6
int checkNotNum6(int n)
{
    while (n != 0)
    {
        int s = n % 10;
        if (s == 6)
            return 0;
    }
    return 1;
}
// Ham kiem tra tong cua 1 so la so nguyen to
int checkSumDigitIsPrime(int n)
{
    int s = 0;
    while (n != 0)
    {
        s += n % 10;
        n /= 10;
    }
    if (checkPrime(s))
        return 1;
    return 0;
}

int main()
{
    for (int i = 10000000; i < 100000000; i++)
    {
        if (checkReverse(i))
            if (checkSumDigitIsPrime(i))
                if (checkNotNum6(i))
                    printf("%d ", i);
    }
    return 0;
}