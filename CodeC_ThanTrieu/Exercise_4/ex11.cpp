// #include <stdio.h>

// void enterArr(int *arr, int &n)
// {
//     do
//     {
//         printf("Nhap vao so luong phan tu cho mang n = ");
//         scanf("%d", &n);
//     } while (n <= 0);

//     printf("Nhap vao gia tri cho tung phan tu trong mang: ");
//     for (int i = 0; i < n - 1; i++)
//     {
//         scanf("%d", &arr[i]);
//     }
// }

// int main()
// {
//     int a[100];
//     int n;
//     enterArr(a, n);

//     int k, x;
//     do
//     {
//         printf("Nhap vao chi so cho k = ");
//         scanf("%d", &k);
//     } while (k < 0 || k >= n);

//     printf("Nhap vao gia tri cua x tai vi tri %d muon them vao mang : ", k);
//     scanf("%d", &x);

//     if (k == n - 1)
//     {
//         a[k] = x;
//     }
//     else
//     {
//         for (int i = n - 2; i >= k; i--)
//         {
//             a[i + 1] = a[i];
//         }
//         a[k] = x;
//     }

//     printf("Gia tri cua tung phan tu mang sau khi duoc them vao la : ");
//     for (int i = 0; i <= n - 1; i++)
//     {
//         printf("%d ", a[i]);
//     }

//     return 0;
// }

#include <stdio.h>

void enterArr(int *arr, int *n)
{
    do
    {
        printf("Nhap vao so luong phan tu cho mang n = ");
        scanf("%d", n);
    } while (*n <= 0);

    printf("Nhap vao gia tri cho tung phan tu trong mang: ");
    for (int i = 0; i < *n - 1; i++)
    {
        scanf("%d", &arr[i]);
    }
}

void enterIndex(int *k, int n)
{
    do
    {
        printf("Nhap vao chi so k = ");
        scanf("%d", k);
    } while (*k < 0 || *k >= n);
}

void addVal(int *arr, int n, int k, int x)
{
    for (int i = n - 1; i >= k; i--)
    {
        arr[i] = arr[i - 1];
    }
    arr[k] = x;
}

void show(int *arr, int n)
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

    int k;
    enterIndex(&k, n);

    int x;
    printf("Nhap vao gia tri x tai vi tri thu %d : ", k);
    scanf("%d", &x);

    addVal(a, n, k, x);

    show(a, n);
    return 0;
}