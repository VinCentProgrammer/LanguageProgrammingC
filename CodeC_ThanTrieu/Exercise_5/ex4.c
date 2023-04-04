/*
Ex5.4: Nhập vào một xâu ký tự bất kỳ, thực hiện:
a. Viết hoa toàn bộ xâu
b. Viết thường toàn bộ xâu

*/

// #include <stdio.h>
// #include <string.h>
// #include <stdlib.h>
// #include <ctype.h>

// char toStringUpper(char *str)
// {
//     for (int i = 0; i < strlen(str) - 1; i++)
//     {
//         if (str[i] >= 'a' && str[i] <= 'z')
//             str[i] -= 32;
//     }
// }

// char toStringLower(char *str)
// {
//     for (int i = 0; i < strlen(str) - 1; i++)
//     {
//         if (str[i] >= 'A' && str[i] <= 'Z')
//             str[i] += 32;
//     }
// }

// int main()
// {
//     char str[100];
//     printf("Nhap vao chuoi can chuyen: ");
//     fflush(stdin);
//     fgets(str, sizeof(str) - 1, stdin);

//     // toStringLower(str);

//     toStringUpper(str);

//     puts(str);

//     return 0;
// }

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

char toStringUpper(char *str)
{
    for (int i = 0; i < strlen(str) - 1; i++)
    {
        str[i] = toupper(str[i]);
    }
}

char toStringLower(char *str)
{
    for (int i = 0; i < strlen(str) - 1; i++)
    {
        str[i] = tolower(str[i]);
    }
}

int main()
{
    char str[100];
    printf("Nhap vao chuoi can chuyen: ");
    fflush(stdin);
    fgets(str, sizeof(str) - 1, stdin);

    // toStringLower(str);

    toStringUpper(str);

    puts(str);

    return 0;
}