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

// Ham kiem tra cac chu so cua 1 so la so nguyen to
int checkDigitIsPrime(int n)
{
    while (n != 0)
    {
        int s = n % 10;
        if (!checkPrime(s))
            return 0;
        n /= 10;
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
        if (checkPrime(i))
            if (checkDigitIsPrime(i))
                if (checkSumDigitIsPrime(i))
                    printf("%d ", i);
    }
    return 0;
}