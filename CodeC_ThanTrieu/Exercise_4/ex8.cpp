// #include <stdio.h>

// void enterArr(int *arr, int &n)
// {
//     do
//     {
//         printf("Nhap vao so luong phan tu cua mang n = ");
//         scanf("%d", &n);
//     } while (n <= 0);

//     printf("Nhap vao gia tri cho tung phan tu trong mang : ");
//     for (int i = 0; i <= n - 1; i++)
//     {
//         scanf("%d", &arr[i]);
//     }
// }

// int checkReverseArr(int *arr, int n)
// {
//     int l = 0, r = n - 1;
//     for (int i = 0; i <= n - 1; i++)
//     {
//         if (arr[l] != arr[r])
//             return 0;
//     }
//     return 1;
// }

// int main()
// {
//     int a[100];
//     int n;
//     enterArr(a, n);

//     if (checkReverseArr(a, n))
//         printf("Mang da cho doi xung");
//     else
//         printf("Mang da cho khong doi xung");
//     return 0;
// }

#include <stdio.h>

void enterArr(int *arr, int *n)
{
    do
    {
        printf("Nhap vao so luong phan tu cua mang n = ");
        scanf("%d", n);
    } while (*n <= 0);

    printf("Nhap vao gia tri cho tung phan tu trong mang : ");
    for (int i = 0; i <= *n - 1; i++)
    {
        scanf("%d", &arr[i]);
    }
}

int checkArrReverse(int *arr, int n)
{
    for (int i = 0; i <= n / 2; i++)
    {
        if (arr[i] != arr[n - 1 - i])
            return 0;
    }
    return 1;
}
int main()
{
    int a[100];
    int n;
    enterArr(a, &n);

    if (checkArrReverse(a, n))
        printf("Mang doi xung");
    else
        printf("Mang khong doi xung");
    return 0;
}