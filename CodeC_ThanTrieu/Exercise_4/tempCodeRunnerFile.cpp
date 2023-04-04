#include <stdio.h>

void enterMatrix(int arr[][100], int &m, int &n)
{
    do
    {
        printf("Nhap vao so hang cua ma tran m = ");
        scanf("%d", &m);
        printf("Nhap vao so cot cua ma tran n = ");
        scanf("%d", &n);

    } while (n < 0 || m < 0);

    printf("Nhap vao gia tri cho mang : \n");
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            scanf("%d ", &arr[i][j]);
        }
    }
}

int main()
{
    int m1, n1, m2, n2;
    int matrix1[100][100], matrix2[100][100];
    printf("Nhap vao cho ma tran thu nhat: \n");
    enterMatrix(matrix1, m1, n1);
    printf("Nhap vao cho ma tran thu hai: \n");
    enterMatrix(matrix2, m2, n2);

    int res[100][100];
    for (int i = 1; i <= m1; i++)
    {
        for (int j = 1; j <= n1; j++)
        {
            res[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }

    for (int i = 1; i <= m1; i++)
    {
        for (int j = 1; j <= n1; j++)
        {
            printf("%d ", res[i][j]);
        }
        printf("\n");
    }
    return 0;
}