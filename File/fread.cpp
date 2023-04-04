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

    FILE *f;

    f = fopen("fwrite.bin", "rb");
    if (f == NULL)
    {
        printf("Loi tao hoac mo file !");
        exit(1);
    }

    NgaySinh n1;
    fread(&n1, sizeof(struct NgaySinh), 1, f);

    printf("Ngay sinh: %d/%d/%d", n1.day, n1.month, n1.year);

    fclose(f);
    return 0;
}
