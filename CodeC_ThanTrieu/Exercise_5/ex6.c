// /*
// Hãy chuẩn hoá một xâu ký tự cho trước: loại bỏ các dấu cách thừa, chuyển ký tự đầu mỗi từ thành chữ hoa, các ký tự khác thành chữ thường.

// vd: * & % ha              van        ()  dung. +   +     +
// -> *&% Ha Van () Dung.+++

// #B1: Nhap xau can chuan hoa
// #B2: Duyet qua xau tu dau den cuoi
// - Su dung mang chua ki tu: store[chieu dai cua chuoi ban dau], cnt = 0, store[cnt++] = ki tu;
// - Kiem tra:
// + i: KTDB & i+1: DC -> them
// + i: DC & i+1: KTDB -> bo qua
// + i: DC & i+1: CC -> them
// + i: CC & i+1: CC -> them
// + i: CC & i+1: DC -> them
// + i: DC & i+1: DC -> bo qua
// + i: KTDB & i+1: KTDB -> them

// - isSpCher(): Ham kiem tra ki tu dac biet
// - isSpace(): Ham kiem tra dau cach
// - isAlpha(): Ham kiem tra ki tu la chu cai

// - Duyet qua mang store[] -> Kiem tra:
// i: DC & i+1: CC -> chuyen chu cai thanh chu chu in hoa

// */

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int isSpCher(char c)
{
    if (isalpha(c) || c == ' ')
        return 0;
    return 1;
}

int isSpace(char c)
{
    return c == ' ';
}

void validation(char *str)
{
    int store[100];
    int cnt = 0;

    for (int i = 0; i < strlen(str) - 1; i++)
    {
        str[i] = tolower(str[i]);
        if (isSpCher(str[i]) && isSpace(str[i + 1]) || isSpace(str[i]) && isalpha(str[i + 1]) || isalpha(str[i]) && isalpha(str[i + 1]) || isalpha(str[i]) && isSpace(str[i + 1]) || isSpCher(str[i]) && isSpCher(str[i + 1]) || isalpha(str[i]) && isSpCher(str[i + 1]))
        {
            store[cnt++] = str[i];
        }
    }

    for (int i = 0; i < strlen(str) - 1; i++)
    {
        if (isSpace(store[i]) && isalpha(store[i + 1]))
            store[i + 1] = toupper(store[i + 1]);
        else if (isalpha(store[0]))
            store[0] = toupper(store[0]);
    }

    for (int i = 0; i <= cnt; i++)
    {
        printf("%c", store[i]);-
    }
}

int main()
{
    char str[100];
    printf("Nhap vao xau can chuan hoa: ");
    fflush(stdin);
    fgets(str, sizeof(str) - 1, stdin);

    validation(str);

    return 0;
}

//================Xoa khoang trang o cuoi xau=====================
// #include <stdio.h>
// #include <string.h>
// #include <stdlib.h>
// #include <ctype.h>

// int isWhiteSpace(char c)
// {
//     return (c == ' ' || c == '\t' || c == '\n');
// }

// void removeWhiteSpaceTail(char *str)
// {
//     int i = strlen(str) - 1;
//     while (isWhiteSpace(str[i]))
//     {
//         str[i] = '\0';
//         i--;
//     }
// }

// int main()
// {
//     char str[100];
//     printf("Nhap vao xau ki tu: ");
//     fflush(stdin);
//     fgets(str, sizeof(str) - 1, stdin);
//     printf("%d\n", strlen(str));
//     removeWhiteSpaceTail(str);

//     puts(str);
//     printf("%d\n", strlen(str));

//     return 0;
// }

//=======================Xoa ki tu khoang trang o dau xau ===============
// #include <stdio.h>
// #include <string.h>
// #include <stdlib.h>
// #include <ctype.h>

// int isWhiteSpace(char c)
// {
//     return (c == ' ' || c == '\t' || c == '\n');
// }

// void removeWhiteSpaceHead(char *str)
// {
//     // Dem cac ki tu khoang trang o dau
//     int cnt = 0;
//     for (int i = 0; i < strlen(str) - 1; i++)
//     {
//         if (isWhiteSpace(str[i]))
//             cnt++;
//         else
//             break;
//     }
//     // Xoa ki tu khoang trang o dau bang cach dich chuyen cac ki tu sang ben trai
//     for (int i = 0; i <= strlen(str) - cnt; i++)
//     {
//         str[i] = str[i + cnt];
//     }
// }

// int main()
// {
//     char str[100];
//     printf("Nhap vao xau ki tu: ");
//     fflush(stdin);
//     fgets(str, sizeof(str) - 1, stdin);
//     printf("%d\n", strlen(str));
//     removeWhiteSpaceHead(str);

//     puts(str);
//     printf("%d\n", strlen(str));

//     return 0;
// }


//==================Xoa dau cach thua o giua xau ki tu=================
