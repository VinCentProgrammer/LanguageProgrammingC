// #include <stdio.h>
// #include <math.h>

// int ans(int n, int k)
// {
//     int cnt = 0;
//     for (int i = 2; i <= sqrt(n); i++)
//     {
//         if (n % i == 0)
//         {
//             while (n % i == 0)
//             {
//                 ++cnt;
//                 if (cnt == k)
//                     return i;
//                 n /= i;
//             }
//         }
//     }
//     if (n != 1)
//         return n;
//     return -1;
// }
// int main()
// {
//     int n, k;
//     scanf("%d%d", &n, &k);
//     printf("%d\n", ans(n, k));
//     return 0;
// }

#include <stdio.h>
#include <math.h>
#include <limits.h>

void solve(long long n)
{
    int c2 = 0, c3 = 0, c5 = 0, c7 = 0;
    while (n)
    {
        int tmp = n % 10;
        if (tmp == 2)
            c2++;
        else if (tmp == 3)
            c3++;
        else if (tmp == 5)
            c5++;
        else if (tmp == 7)
            c7++;
        n /= 10;
    }

    if (c2 != 0)
        printf("2 %d\n", c2);
    if (c3 != 0)
        printf("3 %d\n", c3);
    if (c5 != 0)
        printf("5 %d\n", c5);
    if (c7 != 0)
        printf("7 %d\n", c7);
}
int main()
{
    long long n;
    scanf("%lld", &n);
    solve(n);
    return 0;
}