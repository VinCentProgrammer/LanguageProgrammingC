// #include <stdio.h>

// void enterArr(int *arr, int &n)
// {
//     do
//     {
//         printf("Nhap vao so luong phan tu cua mang n = ");
//         scanf("%d", &n);
//     } while (n <= 0);

//     printf("Nhap vao gia tri cho tung phan tu trong mang : ");
//     for (int i = 0; i <= n - 2; i++)
//     {
//         scanf("%d", &arr[i]);
//     }
// }

// void sortArrIncrease(int *arr, int n)
// {
//     for (int i = 1; i <= n - 2; i++)
//     {
//         for (int j = 0; j <= i - 1; j++)
//         {
//             if (arr[i] <= arr[j])
//             {
//                 // Doi cho
//                 int tmp = arr[i];
//                 arr[i] = arr[j];
//                 arr[j] = tmp;
//             }
//         }
//     }
// }

// int main()
// {
//     int a[100];
//     int n;
//     enterArr(a, n);
//     sortArrIncrease(a, n);

//     printf("Mang sau khi sap xep tang dan la: ");
//     for (int i = 0; i <= n - 2; i++)
//         printf("%d ", a[i]);

//     int x;
//     printf("Nhap vao gia tri cua x = ");
//     scanf("%d", &x);

//     if (x > a[n - 2])
//         a[n - 1] = x;
//     else
//     {
//         int k;
//         for (int i = 0; i <= n - 2; i++)
//         {
//             if (x > a[i])
//                 k = i + 1;
//         }

//         for (int i = n - 1; i >= k; i--)
//         {
//             a[i] = a[i - 1];
//         }
//         a[k] = x;
//     }
//     printf("Cac phan tu cua mang sau khi them %d vao la : ", x);
//     for (int i = 0; i <= n - 1; i++)
//     {
//         printf("%d ", a[i]);
//     }
//     return 0;
// }

#include <stdio.h>

void enterArr(int *arr, int *n);
void show(int *arr, int n);
void enterIndex(int *index, int n);
void sortArrIncrease(int *arr, int n);
void addValueForArr(int *arr, int n, int val);

int main()
{
    int a[100];
    int n;
    enterArr(a, &n);

    sortArrIncrease(a, n);

    int x;
    printf("Nhap vao gia tri x la: ");
    scanf("%d", &x);

    addValueForArr(a, n, x);

    show(a, n);

    return 0;
}

void enterArr(int *arr, int *n)
{
    do
    {
        printf("Nhap vao so luong phan tu cua mang n = ");
        scanf("%d", n);
    } while (*n <= 0);

    printf("Nhap vao gia tri cho tung phan tu trong mang: ");
    for (int i = 0; i <= *n - 2; i++)
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

void addValueForArr(int *arr, int n, int val)
{
    if (val > arr[n - 2])
        arr[n - 1] = val;
    else
    {
        int index;
        for (int i = n - 2; i >= 0; i--)
        {
            if (val > arr[i])
            {
                index = i + 1;
            }
            else if (val < arr[0])
                index = 0;
        }

        for (int i = n - 1; i >= index; i--)
        {
            arr[i] = arr[i - 1];
        }

        arr[index] = val;
    }
}