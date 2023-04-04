// #include <stdio.h>

// // Ham sap xep cac phan tu cua mang theo thu tu tang dan tu trai sang phai
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

// // Ham sap xep cac phan tu cua mang theo thu tu giam dan tu trai sang phai
// void sortArrDecrease(int *a, int n)
// {
//     for (int i = 0; i <= n - 1; i++)
//     {
//         for (int j = 0; j < i; j++)
//         {
//             if (a[i] > a[j])
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
//         printf("Nhap vao so luong phan tu cua mang n = ");
//         scanf("%d", &n);
//     } while (n <= 0);

//     int arr[n];
//     printf("Nhap vao cac phan tu cua mang : ");
//     for (int i = 0; i <= n - 1; i++)
//     {
//         scanf("%d", &arr[i]);
//     }

//     sortArrIncrease(arr, n);
//     for (int i = 0; i <= n - 1; i++)
//     {
//         printf("%d ", arr[i]);
//     }
//     printf("\n");
//     sortArrDecrease(arr, n);
//     for (int i = 0; i <= n - 1; i++)
//     {
//         printf("%d ", arr[i]);
//     }
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
    for (int i = 0; i < *n; i++)
    {
        scanf("%d", &arr[i]);
    }
}

void sortArrIncrease(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (arr[i] < arr[j])
            {
                int tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
            }
        }
    }
}

void sortArrDecrease(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (arr[i] > arr[j])
            {
                int tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
            }
        }
    }
}

void showArr(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}
int main()
{
    int a[100];
    int n;
    enterArr(a, &n);
    printf("Mang truoc khi sap xep la: ");
    showArr(a, n);
    printf("\n");

    printf("Mang sau khi sap xep tang la: ");
    sortArrIncrease(a, n);
    showArr(a, n);
    printf("\n");

    printf("Mang sau khi sap xep giam la: ");
    sortArrDecrease(a, n);
    showArr(a, n);
    printf("\n");

    return 0;
}