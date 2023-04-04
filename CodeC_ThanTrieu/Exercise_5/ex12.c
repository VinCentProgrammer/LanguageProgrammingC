/*
Ex5.12. Viết chương trình tách các từ trong một chuỗi kí tự cho trước và in chúng ra theo thứ tự bảng chữ cái.

*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main()
{
    char str[100];
    printf("Nhap vao xau can in theo ki tu bang chu cai: ");
    fflush(stdin);
    fgets(str, sizeof(str) - 1, stdin);

    char res[50][100];
    char res2[50][100];
    char *token;
    const char *delim = " ,.-\t\n";

    int size = 0;
    for (token = strtok(str, delim); token != NULL; token = strtok(NULL, delim))
    {
        strcpy(res[size++], token);
    }

    int k = 0;

    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (strcmp(res[j], res[j + 1]) < 0)
            {
                char *p = (char *)malloc(50);
                strcpy(p, res[j]);
                strcpy(res[j], res[j + 1]);
                strcpy(res[j + 1], p);
            }
        }
    }

    for (int i = size - 1; i >= 0; i--)
        printf("%s ", res[i]);
    return 0;
}