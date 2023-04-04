#include <stdio.h>
#include <stdlib.h>

struct NgaySinh
{
    int day;
    int month;
    int year;
};

int main()
{

    // 1, 2: Tao hoac mo file
    FILE *f;
    f = fopen("fwrite.bin", "wb");
    if (f == NULL)
    {
        printf("Loi tao hoac mo file !");
        exit(1);
    }
    // 3. Ghi file nhi phan
    NgaySinh n1;
    n1.day = 20;
    n1.month = 2;
    n1.year = 2004;

    fwrite(&n1, sizeof(struct NgaySinh), 1, f);
    // 4. Dong file
    fclose(f);
    return 0;
}