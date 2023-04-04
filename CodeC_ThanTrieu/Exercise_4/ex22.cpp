#include <stdio.h>

void enterMatrix(int arr[][100], int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }
}

void enterRowCol(int &row, int &col)
{
    do
    {
        printf("Nhap vao so hang va so cot cua ma tran: ");
        scanf("%d %d", &row, &col);
    } while (row <= 0 || col <= 0);
}

void resMatrix(int arr1[][100], int arr2[][100], int res[][100], int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            res[i][j] = arr1[i][j] + arr2[i][j];
        }
    }
}

void show(int arr[][100], int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int arr1[50][100], arr2[50][100], res[50][100];
    int row, col;
    enterRowCol(row, col);

    printf("Nhap vao ma tran 1: \n");
    enterMatrix(arr1, row, col);

    printf("Nhap vao ma tran 2: \n");
    enterMatrix(arr2, row, col);

    resMatrix(arr1, arr2, res, row, col);
    printf("Tong ma tran 1 va ma tran 2 la: \n");
    show(res, row, col);

    return 0;
}