
#include <stdio.h>
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

int main()
{
    int n;
    int a[100];
    enterArr(a, n);

    int s1 = 0, s2 = 0, cnt1 = 0, cnt2 = 0;
    for (int i = 0; i <= n - 1; i++)
    {
        if (a[i] % 2 == 0)
        {
            s1 += a[i];
            cnt1++;
        }
        else
        {
            s2 += a[i];
            cnt2++;
        }
    }

    printf("Trung binh cong cac so chan trong mang la %d \n", s1 / cnt1);
    printf("Trung binh cong cac so le trong mang la %d \n", s2 / cnt2);
}