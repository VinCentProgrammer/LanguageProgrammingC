#include <stdio.h>
#include <stdlib.h>

void enterArr(int *arr, int &n)
{
    for (int i = 0; i <= n - 1; i++)
    {
        scanf("%d", (arr + i));
    }
}

void outputArr(int *arr, int &n)
{
    for (int i = 0; i <= n - 1; i++)
    {
        printf("%d ", *(arr + i));
    }
}

int main()
{
    int n;
    printf("Nhap so luong phan tu cho mang n = ");
    scanf("%d", &n);

    int *a;

    a = (int *)malloc(n * sizeof(int));

    enterArr(a, n);
    outputArr(a, n);

    free(a);

    return 0;
}