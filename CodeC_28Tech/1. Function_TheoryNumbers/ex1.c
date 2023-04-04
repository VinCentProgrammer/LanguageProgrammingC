#include <stdio.h>
#include <math.h>

// C1: O(n)
int isPrime1(int n)
{
    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        if (n % i == 0)
            cnt++;
    }
    if (cnt == 2)
        return 1;
    else
        return 0;
}

// C2: O(n)
int isPrime2(int n)
{
    int cnt = 1;
    for (int i = 1; i <= n / 2; i++)
    {
        if (n % i == 0)
            ++cnt;
    }
    if (cnt == 2)
        return 1;
    else
        return 0;
}

// C3: O(logn)
int isPrime3(int n)
{
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
            return 0;
    }
    return n > 1;
}

int main()
{
    int n;
    scanf("%d", &n);
    if (isPrime3(n))
        printf("Yes \n");
    else
        printf("No \n");
    return 0;
}