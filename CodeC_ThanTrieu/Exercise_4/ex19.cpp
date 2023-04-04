#include <stdio.h>
#include <math.h>

void nhap(int &n, int *arr)
{
    do
    {
        printf("Nhap vao bac cao nhat cua bieu thuc: ");
        scanf("%d", &n);
    } while (n <= 0);

    int k = n + 1;
    printf("Nhap vao he so cua bieu thuc: ");
    for (int i = k - 1; i >= 0; i--)
    {
        scanf("%d", &arr[i]);
    }
}

int max(int a, int b)
{
    return a > b ? a : b;
}


int main()
{
    int n1, n2;
    int a1[100] = {0}, a2[100] = {0};
    nhap(n1, a1);
    nhap(n2, a2);
    // Tinh tong 2 bieu thuc
    int res[max(n1, n2)];
    for (int i = 0; i <= max(n1, n2); i++)
    {
        res[i] = a1[i] + a2[i];
    }

    printf("Bieu thuc sau khi tinh tong bieu thuc 1 va bieu thuc 2 la : ");
    for (int i = max(n1, n2); i >= 0; i--)
    {
        if (res[i] != 0)
        {
            printf("%d", res[i]);
            if (i != 0)
                printf("*x^%d + ", i);
        }
    }
    return 0;
}
