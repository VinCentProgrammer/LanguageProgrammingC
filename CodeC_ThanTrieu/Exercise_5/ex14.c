/*
Ex5.14. Nhập hai chuỗi kí tự s1 và s2. Tìm và loại bỏ toàn bộ s2 trong s1

*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

void deleteDownTheLine(char x[])
{
    size_t len = strlen(x);
    if (x[len - 1] == '\n')
    {
        x[len - 1] = '\0';
    }
}

int main()
{
    char str1[100], str2[100];
    printf("Nhap vao chuoi s1: ");
    fflush(stdin);
    fgets(str1, sizeof(str1) - 1, stdin);
    deleteDownTheLine(str1);

    printf("Nhap vao chuoi s2: ");
    fflush(stdin);
    fgets(str2, sizeof(str2) - 1, stdin);
    deleteDownTheLine(str2);

    char res[100][50];
    char *token;
    const char *delim = " ,.-\t\n";
    int i = 0;
    for (token = strtok(str1, delim); token != NULL; token = strtok(NULL, delim))
        strcpy(res[i++], token);

    for (int k = 0; k < i; k++)
    {
        if (strcmp(res[k], str2) != 0)
            printf("%s ", res[k]);
    }

    return 0;
}