// #include <stdio.h>
// #include <limits.h>

// // Ham sap xep cac phan tu cua mang theo thu tu tang dan
// void sortArrIncrease(int *arr, int n)
// {
//     for (int i = 0; i <= n - 1; i++)
//     {
//         for (int j = 0; j < i; j++)
//         {
//             if (arr[i] < arr[j])
//             {
//                 int tmp = arr[i];
//                 arr[j] = arr[i];
//                 arr[i] = tmp;
//             }
//         }
//     }
// }

// // Ham sap xep cac phan tu cua mang theo thu tu giam dan
// void sortArrDecrease(int *arr, int n)
// {
//     for (int i = 0; i <= n - 1; i++)
//     {
//         for (int j = 0; j < i; j++)
//         {
//             if (arr[i] > arr[j])
//             {
//                 int tmp = arr[i];
//                 arr[j] = arr[i];
//                 arr[i] = tmp;
//             }
//         }
//     }
// }

// int main()
// {
//     int n;
//     do
//     {
//         printf("Nhap vao so luong phan tu cua mang : ");
//         scanf("%d", &n);
//     } while (n <= 0);

//     int arr[n];
//     printf("Nhap vao cac phan tu cua mang: ");
//     for (int i = 0; i <= n - 1; i++)
//     {
//         scanf("%d", &arr[i]);
//     }

//     // int max = INT_MIN, min = INT_MAX;
//     // for (int i = 0; i <= n - 1; i++)
//     // {
//     //     if (max < arr[i])
//     //         max = arr[i];
//     //     if (min > arr[i])
//     //         min = arr[i];
//     // }

//     sortArrIncrease(arr, n);

//     printf("Phan tu lon nhat trong mang la %d \n", arr[n - 1]);
//     printf("Phan tu nho nhat trong mang la %d \n", arr[0]);
//     return 0;
// }

#include <stdio.h>

void enterArr(int *arr, int *n)
{
    do
    {
        printf("Nhap vao so luong phan tu cua mang: ");
        scanf("%d", n);
    } while (*n <= 0);

    printf("Nhap vao gia tri cho tung phan tu trong mang: ");
    for (int i = 0; i <= *n - 1; i++)
    {
        printf("arr[%d] = ", i);
        scanf("%d", &arr[i]);
    }
}

void min_max(int *arr, int n, int *min, int *max)
{
    for (int i = 0; i <= n - 1; i++)
    {
        if (arr[i] > *max)
            *max = arr[i];
        if (arr[i] < *min)
            *min = arr[i];
    }
}

void print(int min, int max)
{
    if (max == min)
        printf("Khong co gia tri min va max vi max = min");
    else
    {
        printf("\nMax = %d\nMin = %d", max, min);
    }
}
int main()
{
    int a[100];
    int n;
    enterArr(a, &n);
    int min = a[0], max = a[0];
    min_max(a, n, &min, &max);
    print(min, max);
    return 0;
}