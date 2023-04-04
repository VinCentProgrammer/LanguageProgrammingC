// #include <stdio.h>

// void enterArr(int *arr, int &n)
// {
//     do
//     {
//         printf("Nhap vao so luong phan tu cho mang: ");
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
//     int a[100], b[100];
//     int n;
//     printf("Thao tac mang thu nhat\n");
//     enterArr(a, n);

//     int m;
//     printf("Thao tac mang thu hai\n");
//     enterArr(b, m);

//     int k;
//     do
//     {
//         printf("Nhap vao chi so muon them mang thu 2 vao mang thu nhat k = ");
//         scanf("%d", &k);
//     } while (k < 0 || k >= n);

//     for (int i = n + m - 1; i >= k + m; i--)
//     {
//         a[i] = a[i - m];
//     }

//     for (int i = k; i <= k + m - 1; i++)
//     {
//         a[i] = b[i - k];
//     }

//     printf("Cac gia tri cua mang sau khi them mang 2 vao mang 1 la: ");
//     for (int i = 0; i <= n + m - 1; i++)
//     {
//         printf("%d ", a[i]);
//     }
//     return 0;
// }

#include <stdio.h>

void enterArr(int *arr, int *n);
void show(int *arr, int n);
void enterIndex(int *k, int n);
void insert(int *a, int *b, int index, int n, int m);

int main()
{
    int a[100], b[100];
    int n, m;
    printf("Thao tac voi mang A: \n");
    enterArr(a, &n);

    printf("Thao tac voi mang B: \n");
    enterArr(b, &m);

    int k;
    enterIndex(&k, n);

    printf("Sau khi them mang B vao mang A: ");
    insert(a, b, k, n, m);

    show(a, n + m);
    return 0;
}

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

void show(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}

void enterIndex(int *k, int n)
{
    do
    {
        printf("Nhap vao vi tri muon them mang B vao mang A, k = ");
        scanf("%d", k);
    } while (*k < 0 || *k > n);
}

void insert(int *a, int *b, int index, int n, int m)
{
    if (index > n - 1)
    {
        for (int i = index; i <= m + n - 1; i++)
            a[i] = b[i - n];
    }
    else
    {
        for (int i = n + m - 1; i >= index + m; i--)
            a[i] = a[i - m];

        for (int i = index; i < index + m; i++)
            a[i] = b[i - index];
    }
}