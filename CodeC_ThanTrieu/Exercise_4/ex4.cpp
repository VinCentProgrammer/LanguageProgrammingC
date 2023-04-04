// #include <stdio.h>

// // Ham nhap mang
// void enterArr(int *arr, int &n)
// {
//     do
//     {
//         printf("Nhap vao so luong phan tu cua mang n = ");
//         scanf("%d", &n);
//     } while (n <= 0);

//     printf("Nhap tung phan tu cho mang: ");
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

//     int x;
//     printf("Nhap vao gia tri can them vao mang x = ");
//     scanf("%d", &x);

//     int cnt = 1;
//     for (int i = 0; i <= n - 1; i++)
//     {
//         if (a[i] == x)
//             ++cnt;
//     }
//     printf("So lan xuat hien cua %d trong mang la %d ", x, cnt);
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

    printf("Nhap vao gia tri cho cac phan tu trong mang: ");
    for (int i = 0; i < *n; i++)
    {
        scanf("%d", &arr[i]);
    }
}

int countX(int *arr, int n, int x)
{
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == x)
            cnt++;
    }
    return cnt;
}

int main()
{
    int a[100];
    int n;
    enterArr(a, &n);

    int x;
    printf("Nhap vao so nguyen x = ");
    scanf("%d", &x);

    printf("So lan xuat hien cua %d trong mang la: %d", x, countX(a, n, x));
    return 0;
}