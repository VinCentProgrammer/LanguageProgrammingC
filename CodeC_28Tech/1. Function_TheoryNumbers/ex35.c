// #include <stdio.h>

// long long gt(int n)
// {
//     long long res = 1;
//     for (int i = 1; i <= n; i++)
//     {
//         res *= i;
//     }

//     return res;
// }

// long long gt2(int n)
// {
//     if (n == 1)
//         return 1;
//     return n * gt2(n - 1);
// }

// int main()
// {
//     int n;
//     scanf("%d", &n);
//     printf("%lld \n", gt2(n));
//     return 0;
// }

#include <stdio.h>
#include <math.h>

int sumInit(int n)
{
    int cnt = 0;
    while (n)
    {
        cnt++;
        n /= 10;
    }

    return cnt;
}

int checkArmstrong(int n)
{
    int tmp = n;
    int mu = sumInit(n);
    int res = 0;
    while (n)
    {
        int r = n % 10;
        res += pow(r, mu);
        n /= 10;
    }

    return res == tmp;
}


int main()
{
    int a;
    scanf("%d", &a);
    if (checkArmstrong(a))
        printf("1");
    else
        printf("0");
    return 0;
}