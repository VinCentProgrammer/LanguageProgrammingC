// #include <stdio.h>

// int solve(int a, int b)
// {
//     int r = a % b;
//     if (r == 0)
//         return 0;
//     return b - r;
// }

// int main()
// {
//     int t;
//     scanf("%d", &t);

//     while (t--)
//     {
//         int a, b;
//         scanf("%d%d", &a, &b);
//         printf("%d", solve(a, b));
//     }
//     return 0;
// }

#include <stdio.h>

#define ll long long
ll solve(int n, int k)
{
    int x = (k) / (n - 1);
    int r = k % (n - 1);
    if (r == 0)
        return 1ll * x * n - 1;
    return 1ll * n * x + r;
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n, k;
        scanf("%d%d", &n, &k);
        printf("%lld \n", solve(n, k));
    }
    return 0;
}