// #include <stdio.h>

// int main()
// {
//     long long n;
//     scanf("%lld", &n);
//     if (n % 2 == 0)
//         printf("%lld ", n / 2);
//     else
//         printf("%lld ", n / 2 - n);
//     return 0;
// }

// #include <stdio.h>

// // Tim uoc nguyen duong nho nhat cua n

// int find(int n)
// {
//     for (int i = 3; i <= n; i += 2)
//         if (n % i == 0)
//             return i;
// }
// int main()
// {
//     long long n, k;
//     scanf("%lld%lld", &n, &k);
//     if (n % 2 == 0)
//         printf("%lld ", n + 2ll * k);
//     else
//         printf("%lld", (n + find(n)) + 2ll * (k - 1));
//     return 0;
// }

#include <stdio.h>

int main()
{
    int t;
    scanf("%d", &t);

    while (t--)
    {
        long long x, y;
        scanf("%lld%lld", &x, &y);

        if (x - y != 1)
            printf("YES \n");
        else
            printf("NO \n");
    }
    return 0;
}