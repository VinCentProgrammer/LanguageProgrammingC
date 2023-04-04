#include <stdio.h>

void enterArr(int *arr, int &n)
{
    do
    {
        printf("Nhap vao so luong phan tu cua mang n = ");
        scanf("%d", &n);
    } while (n <= 0);

    printf("Nhap vao gia tri cho tung phan tu trong mang : ");
    for (int i = 0; i <= n - 1; i++)
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

int main()
{
    int a[100];
    int n;
    enterArr(a, n);

    sortArrIncrease(a, n);

    int max = a[n - 1];
    int fre[max + 1] = {0};

    for (int i = 0; i <= n - 1; i++)
    {
        fre[a[i]]++;
    }

    for (int i = 0; i <= n - 1; i++)
    {
        if (fre[a[i]] != 0)
        {
            printf("So lan xuat hien cua phan tu %d trong mang la: %d \n", a[i], fre[a[i]]);
            fre[a[i]] = 0;
        }
    }
    return 0;
}