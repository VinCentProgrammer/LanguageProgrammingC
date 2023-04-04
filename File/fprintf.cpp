#include <stdio.h>
#include <stdlib.h>

int main()
{
    // 1. Tao file
    // 2. Mo file
    FILE *f;
    f = fopen("fprintf.txt", "w");
    if (f == NULL)
    {
        printf("Loi tao hoac mo file");
        exit(1);
    }
    // 3. Ghi file
    int n;
    printf("Nhap vao gia tri cua n = ");
    scanf("%d", &n);

    fprintf(f, "%d", n);
    // 4. Dong file
    fclose(f);
    return 0;
}