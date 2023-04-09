// #include <stdio.h>

// int powMod(int a, int b)
// {
//     int res = 1;
//     while (b)
//     {
//         if (b % 2 == 1)
//         {
//             res *= a;
//             res %= 10;
//         }
//         a *= a;
//         a %= 10;
//         b /= 2;
//     }
//     return res;
// }

// int main()
// {
//     int n;
//     scanf("%d", &n);
//     if (n % 4 == 0)
//         printf("6");
//     else if (n % 4 == 1)
//         printf("8");
//     else if (n % 4 == 2)
//         printf("4");
//     else
//         printf("2");
//     return 0;
// }

#include <stdio.h>
#include <string.h>

int main()
{
    char c[1000005];
    scanf("%s", &c);
    int r;
    if (strlen(c) == 1)
        r = (c[0] - '0') % 4;
    else
    {
        r = ((c[strlen(c) - 2] - '0') * 10 + c[strlen(c) - 1] - '0');
        r %= 4;
    }
    if (r == 0)
        printf("4");
    else
        printf("0");
    return 0;
}