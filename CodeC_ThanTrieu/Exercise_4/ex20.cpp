// #include <stdio.h>

// void enterMatrix(int arr[][50], int &m, int &n)
// {
//     do
//     {
//         printf("Nhap vao so hang cua ma tran m = ");
//         scanf("%d", &m);
//         printf("Nhap vao so cot cua ma tran n = ");
//         scanf("%d", &n);
//     } while (n < 0 || m < 0);

//     printf("Nhap vao gia tri cho ma tran: \n");
//     for (int i = 1; i <= m; i++)
//     {
//         for (int j = 1; j <= n; j++)
//         {
//             scanf("%d ", &arr[i][j]);
//         }
//     }
// }
// int main()
// {
//     int m, n;
//     int a[50][50];
//     enterMatrix(a, m, n);

//     for (int i = 1; i <= m; i++)
//     // {
//         int max = a[i][1];
//         for (int j = 1; j <= n; j++)
//         {
//             if (a[i][j] >= max)
//                 max = a[i][j];
//         }
//         printf("%d ", max);
//     }

//     return 0;
// }

#include <stdio.h>

void enterArr2Demension(int arr[][100], int *row, int *col)
{
    do
    {
        printf("Nhap vao so hang va so cot cua mang ma tran: ");
        scanf("%d %d", row, col);
    } while (*row <= 0 || *col <= 0);

    printf("Nhap vao tung gia tri cho mang: \n");
    for (int i = 0; i < *row; i++)
    {
        for (int j = 0; j < *col; j++)
        {
            scanf("%d ", &arr[i][j]);
        }
    }
}

void showArr2Demension(int arr[][100], int row, int col)
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

void searchValMaxRowMatrix(int arr[][100], int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        int max = arr[i][0];
        for (int j = 0; j < col; j++)
        {
            if (arr[i][j] > max)
                max = arr[i][j];
        }
        printf("Gia tri lon nhat tren hang thu %d cua ma tran la: %d \n", i, max);
    }
}
int main()
{
    int a[100][100];
    int row, col;
    enterArr2Demension(a, &row, &col);

    searchValMaxRowMatrix(a, row, col);
    return 0;
}