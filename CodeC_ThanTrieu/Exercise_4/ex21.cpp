// #include <stdio.h>

// void enterMatrix(int arr[][100], int &m, int &n)
// {
//     do
//     {
//         printf("Nhap vao so hang cua ma tran m = ");
//         scanf("%d", &m);S
//         printf("Nhap vao so cot cua ma tran m = ");
//         scanf("%d", &n);

//     } while (n < 0 || m < 0);

//     printf("Nhap vao gia tri cho mang : \n");
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
//     int a[100][100];
//     int m, n;
//     enterMatrix(a, m, n);

//     for (int i = 1; i <= m; i++)
//     {
//         for (int j = i; j <= n; j++)
//         {
//             int tmp = a[i][j + 1];
//             a[i][j + 1] = a[j + 1][i];
//             a[j + 1][i] = tmp;
//         }
//     }

//     for (int i = 1; i <= m; i++)
//     {
//         for (int j = 1; j <= n; j++)
//         {
//             printf("%d ", a[i][j]);
//         }
//         printf("\n");
//     }
//     return 0;
// }

/*
  0 1 2 3
0 1 2 3 4
1 5 6 7 8
2 9 8 7 9
3 9 1 7 3

a[0][1] = a[1][0]
a[0][2] = a[2][0]
a[0][3] = a[3][0]

a[1][2] = a[2][1]
a[1][3] = a[3][1]


  0 1 2 3
0 1 5 9 9
1 2 6 7 8
2 3 8 7 9
3 4 1 7 3

1
2 6 8 1
3 7 7 7
4 8 9 3

*/

#include <stdio.h>

void enterMatrix(int arr[][100], int *row, int *col)
{
  do
  {
    printf("Nhap vao so hang va so cot cua ma tran: ");
    scanf("%d %d", row, col);
  } while (*row <= 0 || *col <= 0);

  printf("Nhap vao gia tri cho phan tu trong mang: \n");
  for (int i = 0; i < *row; i++)
  {
    for (int j = 0; j < *col; j++)
    {
      scanf("%d", &arr[i][j]);
    }
  }
}

void transpositionMatrix(int arr1[][100], int row, int col, int arr2[][100])
{
  for (int i = 0; i < col; i++)
  {
    for (int j = 0; j < row; j++)
    {
      arr2[i][j] = arr1[j][i];
    }
  }
}

void showMatrix(int arr[][100], int row, int col)
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
  int a[100][100], b[100][100];
  int row, col;
  enterMatrix(a, &row, &col);

  transpositionMatrix(a, row, col, b);

  printf("Ma tran sau khi chuyen vi la: \n");
  showMatrix(b, col, row);

  return 0;
}