#include <stdio.h>

void enterArr(int *arr, int &n)
{
    do
    {
        printf("Nhap vao so luong phan tu cua mang : ");
        scanf("%d", &n);
    } while (n <= 0);

    printf("Nhap vao gia tri cua phan tu cua mang: ");
    for (int i = 0; i <= n - 1; i++)
    {
        scanf("%d", &arr[i]);
    }
}

void sortArrIncrease(int *arr, int &n)
{
    for (int i = 0; i <= n - 1; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (arr[j] > arr[i])
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

    int cnt[n] = {0};
    for (int i = 0; i <= n - 1; i++)
    {
        if (a[i + 1] > a[i])
            cnt[a[i]] = 1;
        else
            cnt[a[i]] = 0;
    }

    int dem = 0;
    for (int i = 0; i <= n - 1; i++)
    {
        if (cnt[a[i]])
            dem++;
        else
            dem = 0;
    }

    return 0;
}