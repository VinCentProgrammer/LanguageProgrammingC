/*
Ex5.13. Cho một chuỗi kí tự, nhập thêm chuỗi s1, s2 và thực hiện việc tìm và thay thế s1 bởi s2 trong chuỗi s. Xuất kết quả ra màn hình hoặc file.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main()
{
    char str[100], str1[100], str2[100];

    printf("Nhap vao xau s: ");
    fflush(stdin);
    fgets(str, sizeof(str) - 1, stdin);

    printf("Nhap vao xau s1: ");
    fflush(stdin);
    scanf("%s", str1);

    printf("Nhap vao xau s2: ");
    fflush(stdin);
    scanf("%s", str2);

    char res[100][50];
    char *token;
    const char *delim = " ,.-\t\n";
    int i = 0;
    for (token = strtok(str, delim); token != NULL; token = strtok(NULL, delim))
        strcpy(res[i++], token);

    for (int k = 0; k < i; k++)
    {
        if (strcmp(res[k], str1) == 0)
            strcpy(res[k], str2);
    }

    for (int k = 0; k < i; k++)
    {
        printf("%s ", res[k]);
    }

    return 0;
}
