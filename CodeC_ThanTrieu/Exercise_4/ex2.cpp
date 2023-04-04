// #include <stdio.h>
// #include <limits.h>

// // Sap xep cac phan tu cua mang theo thu tu tang dan
// void sortArrIncrease(int *a, int n)
// {
//     for (int i = 0; i <= n - 1; i++)
//     {
//         for (int j = 0; j < i; j++)
//         {
//             if (a[i] < a[j])
//             {
//                 int tmp = a[i];
//                 a[i] = a[j];
//                 a[j] = tmp;
//             }
//         }
//     }
// }
// int main()
// {
//     int n;
//     do
//     {
//         printf("Nhap so phan tu cho mang n = ");
//         scanf("%d", &n);
//     } while (n <= 0);

//     printf("Nhap cac phan tu cua mang: ");
//     int arr[n];
//     for (int i = 0; i <= n - 1; i++)
//         scanf("%d", &arr[i]);

//     sortArrIncrease(arr, n);
//     int max1, min1;
//     for (int i = 0; i <= n - 1; i++)
//     {
//         if (arr[i] < arr[n - 1])
//             max1 = arr[i];
//     }
//     for (int i = n - 1; i >= 0; i--)
//     {
//         if (arr[i] > arr[0])
//             min1 = arr[i];
//     }
//     if (arr[n - 1] == arr[0] || max1 == min1)
//     {
//         printf("Khong co gia tri thoa man");
//     }
//     else
//     {
//         printf("Gia tri lon thu 2 trong mang la : %d \n", max1);
//         printf("Gia tri nho thu 2 trong mang la : %d \n", min1);
//     }
//     return 0;
// }

#include <stdio.h>

void enterArr(int *arr, int *n);
void max_min(int *arr, int n, int *max, int *min);
void max_min2(int *arr, int n, int *max2, int *min2);
void print(int min2, int max2);

int main()
{
    int a[100];
    int n;
    int min2, max2;
    enterArr(a, &n);
    max_min2(a, n, &max2, &min2);
    return 0;
}

void enterArr(int *arr, int *n)
{
    do
    {
        printf("Nhap vao so luong phan tu cua mang: ");
        scanf("%d", n);
    } while (*n <= 0);

    printf("Nhap vao gia tri cho phan tu trong mang: ");
    for (int i = 0; i < *n; i++)
    {
        scanf("%d", &arr[i]);
    }
}

void max_min(int *arr, int n, int *max, int *min)
{
    *min = *max = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > *max)
            *max = arr[i];
        if (arr[i] < *min)
            *min = arr[i];
    }
}

void max_min2(int *arr, int n, int *max2, int *min2)
{
    int min, max;
    max_min(arr, n, &max, &min);
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > *max2 && arr[i] != max)
            *max2 = arr[i];
        if (arr[i] < *min2 && arr[i] != min)
            *min2 = arr[i];
    }

    if (min != *min2 && max != *max2)
        print(*min2, *max2);
    else
        printf("Khong co gia tri thoa man");
}

void print(int min2, int max2)
{
    if (min2 == max2)
        printf("Khong co gia tri thoa man");
    else
    {
        printf("Min2 = %d \n Max2 = %d", min2, max2);
    }
}