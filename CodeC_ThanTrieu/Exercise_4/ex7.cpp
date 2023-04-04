// #include <stdio.h>

// // Ham nhap mang
// void enterArr(int *arr, int &n)
// {
//     do
//     {
//         printf("Nhap so luong phan tu cua mang n = ");
//         scanf("%d", &n);
//     } while (n <= 0);

//     printf("Nhap vao cac gia tri cua mang : ");
//     for (int i = 0; i <= n - 1; i++)
//     {
//         scanf("%d", &arr[i]);
//     }
// }

// int main()
// {
//     int n;
//     int arr[100];
//     enterArr(arr, n);

//     int a, b;
//     do
//     {
//         printf("Nhap vao 2 gia tri a, b (a < b) : ");
//         scanf("%d%d", &a, &b);
//     } while (a >= b);

//     int aIdx, bIdx;
//     for (int i = 0; i <= n - 1; i++)
//     {
//         if (a == arr[i])
//             aIdx = i;
//         if (b == arr[i])
//             bIdx = i;
//     }

//     int res = 0;
//     for (int i = aIdx; i <= bIdx; i++)
//     {
//         res += arr[i];
//     }

//     printf("Tong cac gia tri tu %d den %d la : %d", a, b, res);
//     return 0;
// }

#include <stdio.h>

void enterArr(int *arr, int *n)
{
    do
    {
        printf("Nhap so luong phan tu cua mang n = ");
        scanf("%d", n);
    } while (*n <= 0);

    printf("Nhap vao cac gia tri cua mang : ");
    for (int i = 0; i <= *n - 1; i++)
    {
        scanf("%d", &arr[i]);
    }
}

void enterA_B(int *a, int *b)
{
    do
    {
        printf("Nhap vao a < b: ");
        scanf("%d %d", a, b);
    } while (*a >= *b);
}

int res(int *arr, int n, int a, int b)
{
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] >= a && arr[i] <= b)
            res += arr[i];
    }
    return res;
}
int main()
{
    int arr[100];
    int n;
    enterArr(arr, &n);
    int a, b;
    enterA_B(&a, &b);

    printf("Tong tu phan tu co gia tri %d den phan tu co gia tri %d trong mang la: %d", a, b, res(arr, n, a, b));
    return 0;
}