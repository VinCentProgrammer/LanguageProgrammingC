#include <stdio.h>
#include <stdlib.h>

int main()
{
    // 1, 2: Tao hoac mo file
    FILE *f;
    f = fopen("fprintf.txt", "r");
    if (f == NULL)
    {
        printf("Loi tao hoac mo file!");
        exit(1);
    }
    // 3: Doc file
    int n;
    fscanf(f, "%d", &n);

    printf("Gia tri cua n = %d", n);
    // 4. Dong file
    fclose(f);
    return 0;
}