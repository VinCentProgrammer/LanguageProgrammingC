// #include <stdio.h>

// int check(int n)
// {
//     int rev = 0, tmp = n;
//     while (n)
//     {
//         int r = n % 10;
//         if (r == 9)
//             return 0;
//         rev = rev * 10 + r;
//         n /= 10;
//     }
//     return rev == tmp;
// }

// int main()
// {
//     int n;
//     scanf("%d", &n);

//     int cnt = 0;
//     for (int i = 2; i < n; i++)
//     {
//         if (check(i)){
//             printf("%d ", i);
//             cnt++;
//         }
//     }
//     printf("\n%d", cnt);
//     return 0;
// }

#include <stdio.h>
#include <math.h>

int prime(int n)
{
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
            return 0;
    }

    return 1;
}

int check(int n)
{
    if (prime(n))
    {
        int max = n % 10;
        while (n)
        {
            int tmp = n % 10;
            if (tmp > max)
                return 0;
            n /= 10;
        }
        return 1;
    }
    else
        return 0;
}


int main()
{
    int n;
    scanf("%d", &n);

    int cnt = 0;
    for (int i = 2; i < n; i++)
    {
        if (check(i))
        {
            printf("%d ", i);
            cnt++;
        }
    }
    printf("\n %d", cnt);
    return 0;
}