#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

// int tn(char *str)
// {
//     int l = 0, r = strlen(str) - 1;
//     while (l <= r)
//     {
//         if (str[l] != str[r])
//             return 0;
//         l++;
//         r--;
//     }

//     return 1;
// }

int tn(long long n)
{
    long long rev = 0, tmp = n;
    
    while (n != 0)
    {
        rev = (rev * 10) + (n % 10);
        n /= 10;
    }

    if (rev == tmp)
        return 1;
    else
        return 0;
}


int main()
{
    int t;
    scanf("%d", &t);

    while (t--)
    {
        // char n[19];
        // fflush(stdin);
        // gets(n);

        long long n;
        scanf("%lld", &n);

        if (tn(n))
            printf("YES \n");
        else
            printf("NO \n");
    }
    return 0;
}