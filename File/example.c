#include <stdio.h>
#include <stdlib.h>

int main()
{
    int c;
    FILE *fp;
    char name[80];
    printf("Nhap ten tep can doc: ");
    scanf("%s", name);
    if (fp = fopen(name, "r") == NULL)
    {
        fprintf(stderr, "Khong the mo tep: %s \n", name);
        perror("Li do: ");
        exit(1);
    }

    while (c = fgetc(fp) != EOF)
    {
        putchar(c);
    }
    fclose(fp);
    return 0;
}