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


int main()
{
    int a[100];
    int n;
    enterArr(a, n);

    int cnt = 0, cntMax = 0, idx = 0;
    for (int i = 0; i <= n - 2; i++)
    {   
        if (a[i] > a[i + 1])
        {
            if (cnt > cntMax)
            {
                idx = i;
                cntMax = cnt;
                cnt = 0;
            }
        }
        else
            cnt++;
    }

    printf("Day tang dai nhat la: ");
    for (int i = idx - cntMax; i <= idx; i++)
    {
        printf("%d ", a[i]);
    }
    return 0;
}