#include <stdio.h>
#include <stdlib.h>

// Ham nhap mang
void enterArr(int *arr, int &n)
{
    do
    {
        printf("Nhap so luong phan tu cua mang n = ");
        scanf("%d", &n);
    } while (n <= 0);

    printf("Nhap vao tung phan tu cho mang: ");
    for (int i = 0; i <= n - 1; i++)
    {
        scanf("%d", &arr[i]);
    }
}

// Ham xuat mang
void outputrArr(int *arr, int n)
{
    printf("Xuat cac phan tu cua mang: \n");
    for (int i = 0; i <= n - 1; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Ghi du lieu cua mang vao file *truong hop co so luong phan tu cua mang
void writeArrToFile1(int *arr, int n, char nameFile[50])
{
    FILE *f;
    f = fopen(nameFile, "w");
    if (f == NULL)
    {
        printf("Loi tao hoac mo file !");
        return;
    }

    fprintf(f, "%d ", n);
    for (int i = 0; i <= n - 1; i++)
    {
        fprintf(f, "%d ", arr[i]);
    }

    fclose(f);
}

// Ghi du lieu cua mang vao file *truong hop khong co so luong phan tu cua mang
void writeArrToFile2(int *arr, int n, char nameFile[50])
{
    FILE *f;
    f = fopen(nameFile, "w");
    if (f == NULL)
    {
        printf("Loi tao hoac mo file !");
        return;
    }

    for (int i = 0; i <= n - 1; i++)
    {
        fprintf(f, "%d ", arr[i]);
    }

    fclose(f);
}
// Doc du lieu cua mang ra file *truong hop co so luong phan tu cua mang
void readArrFromFile1(int *arr, int n, char nameFile[50])
{
    FILE *f;
    f = fopen(nameFile, "r");
    if (f == NULL)
    {
        printf("Loi tao hoac mo file !");
        return;
    }

    fscanf(f, "%d ", &n);
    printf("%d ", n);
    for (int i = 0; i <= n - 1; i++)
    {
        fscanf(f, "%d ", &arr[i]);
        printf("%d ", arr[i]);
    }

    fclose(f);
}

// Doc du lieu cua mang ra file *truong hop khong co so luong phan tu cua mang
void readArrFromFile2(int *arr, int n, char nameFile[50])
{
    FILE *f;
    f = fopen(nameFile, "r");
    if (f == NULL)
    {
        printf("Loi tao hoac mo file !");
        return;
    }

    int i = 0;
    while (!feof(f))
    {
        fscanf(f, "%d ", &arr[i]);
        printf("%d ", arr[i]);
        i++;
    }
    n = i;

    fclose(f);
}

int main()
{
    int a[100];
    int n;

    // enterArr(a, n);
    // outputrArr(a, n);
    // writeArrToFile1(a, n, "file_data_arr1.txt");
    // writeArrToFile2(a, n, "file_data_arr2.txt");

    readArrFromFile1(a, n, "file_data_arr1.txt");
    printf("\n");
    readArrFromFile2(a, n, "file_data_arr2.txt");

    return 0;
}