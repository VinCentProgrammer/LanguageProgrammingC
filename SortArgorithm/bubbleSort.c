#include <stdio.h>

void bubbleSortIncrease(int arr[], int n);

void bubbleSortDecrease(int arr[], int n);

void enterArr(int arr[], int *n);

void showArr(int arr[], int n);

int main()
{
    int a[100];
    int n;
    printf("Nhap vao so phan tu cua mang: ");
    scanf("%d", &n);

    printf("Nhap cac phan tu cho mang: ");
    enterArr(a, &n);

    printf("Sap xep mang ban dau tang dan: ");
    bubbleSortIncrease(a, n);
    showArr(a, n);
    printf("\n");

    printf("Sap xep mang ban dau giam dan: ");
    bubbleSortDecrease(a, n);
    showArr(a, n);
    printf("\n");

    return 0;
}

void bubbleSortIncrease(int arr[], int n)
{
    for (int i = 0; i <= n - 2; i++)
    {
        for (int j = n - 2; j >= i ; j--)
        {
            if (arr[j] > arr[j + 1])
            {
                int tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
        }
    }
}

void bubbleSortDecrease(int arr[], int n)
{
    for (int i = 0; i <= n - 2; i++)
    {
        for (int j = n - 2; j >= i ; j--)
        {
            if (arr[j] < arr[j + 1])
            {
                int tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
        }
    }
}

void enterArr(int arr[], int *n)
{
    for (int i = 0; i <= *n - 1; i++)
    {
        scanf("%d", &arr[i]);
    }
}

void showArr(int arr[], int n)
{
    for (int i = 0; i <= n - 1; i++)
    {
        printf("%d ", arr[i]);
    }
}