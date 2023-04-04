#include <stdio.h>
/*
So cot cua ma tran 1 = So cot hang cua ma tran 2
(2 x 3) * (3 x 2) = (2 x 2)

1 2 3
4 5 6

1 2
3 4
5 6

22 28
49 64

*/

void enterRow1Col1Col2(int *row1, int *col1, int *col2)
{
    printf("Nhap vao so hang cua ma tran 1: ");
    scanf("%d", row1);
    printf("Nhap vao so cot cua ma tran 1 (so hang cua ma tran 2): ");
    scanf("%d", col1);
    printf("Nhap vao so cot cua ma tran 2: ");
    scanf("%d", col2);
}

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

void mulMatrix(int arr1[][100], int arr2[][100], int res[][100], int row1, int col1, int col2)
{
    for (int i = 0; i < row1; i++)
    {
        for (int j = 0; j < col1; j++)
        {
            for (int k = 0; k < col2; k++)
            {
                res[i][k] += arr1[i][j] * arr2[j][k];
            }
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
    int row1, col1, col2;
    enterRow1Col1Col2(&row1, &col1, &col2);

    int arr1[100][100], arr2[100][100], res[100][100];
    printf("Nhap vao ma tran 1: \n");
    enterMatrix(arr1, row1, col1);

    printf("Nhap vao ma tran 2: \n");
    enterMatrix(arr2, col1, col2);

    mulMatrix(arr1, arr2, res, row1, col1, col2);

    printf("Ma tran 1 x Ma tran 2: \n");
    show(res, row1, col2);

    return 0;
}