// /*
// Ex5.11: Nhập vào một chuỗi ký tự và in ra các từ theo thứ tự ngược lại. Ví dụ: “I love learning C programming” -> “programming C learning love I”.

// */

// #include <stdio.h>
// #include <string.h>
// #include <stdlib.h>
// #include <ctype.h>

// int main()
// {
//     char str[1000];
//     printf("Nhap vao chuoi ki tu can dao nguoc: ");
//     fflush(stdin);
//     fgets(str, sizeof(str) - 1, stdin);

//     int cnt = 0;
//     for (int i = strlen(str) - 2; i >= 0; i--)
//     {
//         int idx = 0;

//         if (str[i] == ' ')
//         {
//             idx = i + 1;
//             for (int k = idx; k <= idx + cnt; k++)
//             {
//                 printf("%c", str[k]);
//             }
//             cnt = 0;
//         }
//         else
//             cnt++;

//     }
//     return 0;
// }

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

char res[100][50];

void reverseString(char *str)
{
    // Tach cac tu trong xau
    char *token;
    const char *delim = " ,.-\t\n";

    int i = 0;

    for (token = strtok(str, delim); token != NULL; token = strtok(NULL, delim))
    {
        strcpy(res[i++], token);
    }

    show(res, i);
}

void show(char res[100][50], int size)
{
    for (int i = size - 1; i >= 0; i--)
    {
        printf("%s ", res[i]);
    }
}

int main()
{
    char str[1000];
    printf("Nhap vao chuoi ki tu can dao nguoc: ");
    fflush(stdin);
    fgets(str, sizeof(str) - 1, stdin);

    reverseString(str);

    return 0;
}