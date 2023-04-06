// #include <stdio.h>

// int check(int n)
// {
//     while (n)
//     {
//         int tmp = n % 10;
//         if (tmp != 0 && tmp != 6 && tmp != 8)
//             return 0;
//         n /= 10;
//     }

//     return 1;
// }
// int main()
// {
//     int n;
//     scanf("%d", &n);
//     if (check(n))
//         printf("1\n");
//     else
//         printf("0 \n");
//     return 0;
// }

#include <stdio.h>

int check(int n)
{
    int tmp = n;
    int rev = 0, sum = 0, cnt = 0;

    while (n != 0)
    {
        int r = n % 10;
        if (r == 6)
            ++cnt;
        sum += r;
        rev = rev * 10 + r;
        n /= 10;
    }

    if (sum % 10 == 8 && cnt >= 1 && rev == tmp)
        return 1;
    else
        return 0;
}


int main()
{
    int a, b;
    scanf("%d%d", &a, &b);

    for (int i = a; i <= b; i++)
    {
        if (check(i))
            printf("%d ", i);
    }
    return 0;
}