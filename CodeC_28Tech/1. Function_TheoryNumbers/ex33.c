// #include <stdio.h>

// int main()
// {
//     int n;
//     scanf("%d", &n);

//     int cntOdd = 0, cntEven = 0;
//     while (n != 0)
//     {
//         int tmp = n % 10;
//         if (tmp % 2 == 0)
//             cntEven++;
//         else
//             cntOdd++;
//         n /= 10;
//     }

//     if (cntEven != 0 || cntOdd != 0)
//         printf("%d %d \n", cntEven, cntOdd);
//     else
//         printf("0 \n");
//     return 0;
// }

#include <stdio.h>

int gt(int n)
{
    int res = 1;
    for (int i = n; i >= 1; i--)
    {
        res *= i;
    }

    return res;
}

int check(int n)
{
    int tmp = n;
    int res = 0;
    while (n != 0)
    {
        res += gt(n % 10);
        n /= 10;
    }
    return res == tmp;
}

int main()
{
    int a, b;
    scanf("%d%d", &a, &b);

    int ok = 0;
    for (int i = a; i <= b; i++)
    {
        if (check(i))
        {
            printf("%d ", i);
            ok = 1;
        }
    }
    if (!ok)
        printf("0");
    return 0;
}