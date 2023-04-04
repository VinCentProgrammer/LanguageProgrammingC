// #include <stdio.h>
// #include <math.h>

// int main()
// {
//     int n;
//     printf("Nhap vao bac cao nhat cua bieu thuc n = ");
//     scanf("%d", &n);
//     int k = n + 1;
//     int a[k];

//     printf("Nhap vao gia tri cho he so cua bieu thuc : ");
//     for (int i = k - 1; i >= 0; i--)
//     {
//         scanf("%d", &a[i]);
//     }

//     int x;
//     printf("Nhap vao gia tri cua x muon tinh x = \n");
//     scanf("%d", &x);

//     int P = 0;
//     for (int i = 0; i <= k - 1; i++)
//     {
//         P += a[i] * pow(x, i);
//     }

//     printf("Gia tri cua P(%d) la : %d", x, P);
//     return 0;
// }

#include <stdio.h>
#include <math.h>

void enterExperession(int *arr, int *p)
{
    do
    {
        printf("Nhap vao bac cao nhat cua bieu thuc n = ");
        scanf("%d", p);
    } while (*p <= 0);

    printf("Nhap vao he so cho bieu thuc tu bac cao den bac thap: \n");
    for (int i = *p; i >= 0; i--)
    {
        printf("He so cua bac %d la:", i);
        scanf("%d", &arr[i]);
    }
}

int res(int *arr, int p, int x)
{
    int res = arr[0];
    for (int i = p; i >= 1; i--)
    {
        res += arr[i] * pow(x, i);
    }
    return res;
}

int main()
{
    int a[100];
    int p;
    enterExperession(a, &p);

    int x;
    printf("Nhap vao gia tri cua x = ");
    scanf("%d", &x);

    printf("Gia tri cua bieu thuc tai vi tri x la: %d", res(a, p, x));
    return 0;
}