#include <stdio.h>
#include <math.h>

// Ham tinh giai thua
int factorial(int n)
{
    if (n == 0)
        return 1;
    return n * factorial(n - 1);
}

// Ham tinh to hop chap k cua n
int combination(int n, int k)
{
    return factorial(n) / (factorial(k) * factorial(n - k));
}


int main()
{
    
    return 0;
}