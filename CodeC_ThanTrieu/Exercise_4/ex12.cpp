// #include <stdio.h>

// void enterArr(int *arr, int &n)
// {
//     do
//     {
//         printf("Nhap vao so luong cua mang n = ");
//         scanf("%d", &n);
//     } while (n <= 0);

//     printf("Nhap vao gia tri cho tung phan tu trong mang: ");
//     for (int i = 0; i <= n - 1; i++)
//     {
//         scanf("%d", &arr[i]);
//     }
// }

// int main()
// {
//     int a[100];
//     int n;
//     enterArr(a, n);

//     int k;
//     do
//     {
//         printf("Nhap vao chi so k muon xoa, k = ");
//         scanf("%d", &k);
//     } while (k < 0 || k >= n);

//     printf("Cac gia tri cua mang sau khi xoa phan tu thu %d la: ", k);
//     for (int i = 0; i < n; i++)
//     {
//         if (i != k)
//             printf("%d ", a[i]);
//     }
//     return 0;
// }

#include <stdio.h>

void enterArr(int *arr, int *n)
{
    do
    {
        printf("Nhap vao so luong cua mang n = ");
        scanf("%d", n);
    } while (*n <= 0);

    printf("Nhap vao gia tri cho tung phan tu trong mang: ");
    for (int i = 0; i <= *n - 1; i++)
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

void deleteVal(int *arr, int *n, int k)
{
    for (int i = k; i < *n - 1; i++)
    {
        arr[i] = arr[i + 1];
    }
    *n -= 1;
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

    deleteVal(a, &n, k);

    show(a, n);
    return 0;
}