// #include <stdio.h>
// #include <math.h>

// int main()
// {
//     int n;
//     printf("Nhap vao bac cua bieu thuc n = ");
//     scanf("%d", &n);
//     int k = n + 1;
//     int a[k];

//     printf("Nhap vao he so cho tung bac cua bieu thuc tu cao xuong thap: ");
//     for (int i = k - 1; i >= 0; i--)
//     {
//         scanf("%d", &a[i]);
//     }

//     int x;
//     printf("Nhap vao gia tri tai x = ");
//     scanf("%d", &x);

//     int P = 0;
//     for (int i = 0; i <= k - 1; i++)
//     {
//         P += a[i] * i * pow(x, i - 1);
//     }

//     printf("Gia tri dao ham cua bieu thuc P(%d) = %d", x, P);
//     return 0;
// }

#include <stdio.h>
#include <math.h>

void enterExperession(int *arr, int *p)
{
    do
    {
        printf("Nhap vao bac cao nhat cua bieu thuc: ");
        scanf("%d", p);
    } while (*p <= 0);

    printf("Nhap vao he so cua da thuc: \n");
    for (int i = *p; i >= 0; i--)
    {
        printf("He so cua bac %d la: ", i);
        scanf("%d", &arr[i]);
    }
}

double res(int *arr, int p, int x)
{
    int res = 0;
    for (int i = p; i >= 1; i--)
    {
        res += i * arr[i] * pow(x, i - 1);
    }
    return res;
}

int main()
{
    int a[100];
    int p;
    enterExperession(a, &p);

    float x;
    printf("Nhap vao gia tri x muon tinh dao ham P': ");
    scanf("%f", &x);

    printf("Gia tri P'(%d) = %.2lf", x, res(a, p, x));
    return 0;
}
