#include <stdio.h>
#include <stdlib.h>

void enterArr(int *arr, int &n, int &m)
{
    for (int i = 0; i <= n - 1; i++)
    {
        for (int j = 0; j <= m - 1; j++)
        {
            scanf("%d", (arr + n * i + j));
        }
    }
}

void outputArr(int *arr, int &n, int &m)
{
    for (int i = 0; i <= n - 1; i++)
    {
        for (int j = 0; j <= m - 1; j++)
        {
            printf("%d ", *(arr + n * i + j));
        }
        printf("\n");
    }
}

int main()
{
    int n, m;
    printf("Nhap vao so luong hang va so luong cot cua mang: ");
    scanf("%d %d", &n, &m);

    int *a;

    a = (int *)malloc((m + n) * sizeof(n));

    enterArr(a, n, m);
    outputArr(a, n, m);

    free(a);

    return 0;
}