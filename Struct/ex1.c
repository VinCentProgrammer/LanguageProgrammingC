#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char tenSach[50];
    char tacGia[50];
    int namXB;
} Sach;

void Nhap(int *n, Sach **A)
{
    printf("Nhap so cuon sach: ");
    scanf("%d", n);

    // Cap phat bo nho cho mang Sach A
    *A = (Sach *)malloc((*n) * sizeof(Sach));

    for (int i = 0; i < *n; i++)
    {
        printf("\nNhap thong tin cho cuon sach thu %d:\n", i + 1);
        printf("Ten sach: ");
        scanf(" %[^\n]%*c", (*A)[i].tenSach);
        printf("Tac gia: ");
        scanf(" %[^\n]%*c", (*A)[i].tacGia);
        printf("Nam xuat ban: ");
        scanf("%d", &(*A)[i].namXB);
    }
}

void Xuat(int n, Sach A[])
{
    printf("\nDanh sach %d cuon sach:\n", n);
    for (int i = 0; i < n; i++)
    {
        printf("\nThong tin cuon sach thu %d:\n", i + 1);
        printf("Ten sach: %s\n", A[i].tenSach);
        printf("Tac gia: %s\n", A[i].tacGia);
        printf("Nam xuat ban: %d\n", A[i].namXB);
    }
}

int DemSach(int n, Sach *A)
{
    char tacGia[50];
    int dem = 0;
    printf("Nhap ten tac gia can dem: ");
    fflush(stdin);
    gets(tacGia);
    for (int i = 0; i < n; i++)
    {
        if (strcmp(A[i].tacGia, tacGia) == 0)
        {
            dem++;
        }
    }
    return dem;
}

void Thongke(int n, Sach *A)
{
    int max_year = 0;
    int *year_count = (int *)calloc(10000, sizeof(int)); // Khoi tao giá tri ban dau cua mang year_count là 0.
    for (int i = 0; i < n; i++)
    {
        int year = A[i].namXB;
        year_count[year]++; // Tang bien dem cho nam xuat ban cua cuon sách hien tai.
        if (year > max_year)
        {
            max_year = year; // Cap nhat nam xuat ban lon nhat.
        }
    }

    for (int i = 0; i <= max_year; i++)
    {
        if (year_count[i] > 0)
        {
            printf("%d : %d cuon\n", i, year_count[i]);
        }
    }

    free(year_count);
}

int Menu()
{
    int choice;
    printf("\n====== MENU ======\n");
    printf("1. Nhap danh sach sach\n");
    printf("2. Xuat danh sach sach\n");
    printf("3. Dem sach theo tac gia\n");
    printf("4. Thong ke theo nam xuat ban\n");
    printf("5. Thoat chuong trinh\n");
    printf("Nhap lua chon cua ban: ");
    scanf("%d", &choice);
    return choice;
}

int main()
{
    int n = 0, dem = 0;
    Sach *A;

    while (1)
    {
        int choice = Menu();

        switch (choice)
        {
        case 1:
            Nhap(&n, &A);
            break;
        case 2:
            Xuat(n, A);
            break;
        case 3:
            printf("So cuon sach theo ten tac gia la: %d", DemSach(n, A));
            break;
        case 4:
            Thongke(n, A);
            break;
        default:
            return 0;
        }
    }
}