#include <stdio.h>
#include <limits.h>
#include <math.h>

// Ham nhap mang
void enterArr(int *arr, int &n)
{
    do
    {
        printf("Nhap vao so luong phan tu cua mang n = ");
        scanf("%d", &n);
    } while (n <= 0);

    printf("Nhap tung phan tu cho mang: ");
    for (int i = 0; i <= n - 1; i++)
    {
        scanf("%d", &arr[i]);
    }
}

// Ham sx mang theo thu tu tang dan
void sortArrIncrease(int *arr, int n)
{
    for (int i = 0; i <= n - 1; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (arr[i] < arr[j])
            {
                int tmp = arr[i];
                arr[j] = arr[i];
                arr[i] = tmp;
            }
        }
    }
}
int main()
{

    int n;
    int a[100];
    enterArr(a, n);

    int x;
    printf("Nhap vao gia tri can so sanh voi mang x = ");
    scanf("%d", &x);

    int cpr = 10000;
    int val;

    for (int i = 0; i <= n - 1; i++)
    {
        int dis = abs(x - a[i]);
        if (dis <= cpr)
        {
            cpr = dis;
            val = a[i];
        }
    }
    
    printf("Gia tri phan tu cua mang gan voi %d la %d", x, val);
    return 0;
}