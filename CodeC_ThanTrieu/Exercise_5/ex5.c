/*
Ex5.5.Nhập vào một chuỗi ký tự, hãy đếm số lần xuất hiện của các ký tự chữ cái
theo hai cách:
a. Có phân biệt chữ hoa và chữ thường.
b. Không phân biệt chữ hoa và chữ thường.

Ha Van Dung

ha van dung

#B1: Nhap chuoi tu ban phim
#B2: Viet ham dem so luong chu cai co phan biet hoa thuong
- Duyet qua chuoi -> Dung mang dem count[128] = {0}; index = chu cai cua chuoi;
- cau b: truoc khi dem -> chuyen chuoi thanh chu thuong het -> Viet ham chuyen chuoi thanh chu thuong
#B3: Viet ham dem so luong chu cai khong phan biet hoa thuong
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int cnt[128] = {0};

void cntCharacterDistinction(char *str)
{
    for (int i = 0; i < strlen(str) - 1; i++)
    {
        if (isalpha(str[i]))
            cnt[str[i]]++;
    }

    for (int i = 0; i <= 128; i++)
    {
        if (cnt[str[i]] != 0)
        {
            printf("%c %d \n", str[i], cnt[str[i]]);
            cnt[str[i]] = 0;
        }
    }
}

void cntCharacterNotDistinction(char *str)
{
    for (int i = 0; i < strlen(str) - 1; i++)
    {
        str[i] = tolower(str[i]);
        if (isalpha(str[i]))
            cnt[str[i]]++;
    }

    for (int i = 0; i <= 128; i++)
    {
        if (cnt[str[i]] != 0)
        {
            printf("%c %d \n", str[i], cnt[str[i]]);
            cnt[str[i]] = 0;
        }
    }
}
int main()
{
    char str[100];
    printf("Nhap chuoi can dem so luong chu cai: ");
    fflush(stdin);
    fgets(str, sizeof(str) - 1, stdin);

    cntCharacterDistinction(str);
    printf("\n");
    cntCharacterNotDistinction(str);

    return 0;
}