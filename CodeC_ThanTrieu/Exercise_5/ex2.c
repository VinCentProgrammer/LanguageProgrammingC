// #include <stdio.h>
// #include <string.h>
// #include <ctype.h>

// /*
// Đếm số từ của xâu ký tự nhập vào từ bàn phím. Ví dụ xâu “I can’t speak English” gồm 4 từ.

// -B1: Khai bao kieu du lieu cua xau
// -B2: Doc xau vao ban phim
// -B3: In ra chieu dai cua xau bang ham strlen();
// */
// int main()
// {
//     // char str[100];
//     printf("Nhap vao xau can dem so tu: ");
//     fflush(stdin);
//     fgets(str, sizeof(str), stdin);
//     int cnt = 0;
//     for (int i = 1; i < strlen(str); i++)
//     {
//         if (isspace(str[i]))
//             cnt++;
//     }
//     printf("So tu cua xua vua nhap la: %d", cnt);
//     return 0;
// }

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int isWhiteSpace(char c)
{
    return (c == ' ' || c == '\t');
}

int cntWords(char *str)
{
    int cnt = 0;
    for (int i = 1; i < strlen(str); i++)
    {
        if (!isWhiteSpace(str[i]) && isWhiteSpace(str[i + 1]) || !isWhiteSpace(str[i]) && !isWhiteSpace(str[i]) && i + 1 == strlen(str) - 1)
            cnt++;
    }
    return cnt;
}

int main()
{
    char str[100];
    printf("Nhap vao xau muon dem tu: ");
    fflush(stdin);
    fgets(str, sizeof(str) - 1, stdin);

    printf("So luong tu trong xau la: %d", cntWords(str));

    return 0;
}