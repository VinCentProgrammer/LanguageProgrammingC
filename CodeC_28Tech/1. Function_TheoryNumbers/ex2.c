#include <stdio.h>
#include <math.h>

// Thuat toan sang so nguyen to
int prime[1000001];

void seive()
{
    // Coi tat cac cac so nguyen to tu 0 -> n la so nguyen to
    // prime[i] = 1: la so nguyen to
    // prime[i] = 0: khong la so nguyen to
    for (int i = 0; i <= 1000000; i++)
    {
        prime[i] = 1;
    }
    // Loai bo thu cong 2 thang dau
    prime[0] = prime[1] = 0;
    // Duyet qua tu 2 -> sqrt(n): Kiem tra -> La so nguyen to -> Duyet qua tat cac boi cua no va loai bo
    for (int i = 2; i <= sqrt(1000000); i++)
    {
        if (prime[i])
        {
            for (int j = i * i; j <= 1000001; j += i)
            {
                prime[j] = 0;
            }
        }
    }
}

int main()
{
    seive();
    int n;
    printf("Nhap n = ");
    scanf("%d", &n);

    for (int i = 0; i <= n; i++)
    {
        if (prime[i])
            printf("%d ", i);
    }
    return 0;
}