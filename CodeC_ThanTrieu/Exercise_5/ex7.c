/*
Ex5.7. Nhập một xâu ký tự và tìm từ dài nhất, chỉ rõ vị trí của nó trong xâu đó. Nếu có nhiều từ có độ dài giống nhau thì chọn từ đầu tiên.
vd: ha van dung coderNULL -> chi ra: tu dai nhat la: dung & code, vi tri tu thu 3, 4; => chon tu dung
#B1: Nhap vao xau ki tu
#B2: Duyet qua xau do -> Dung bien dem
#B3: Xuat-> Tu dai nhat : vi tri tu do
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int checkString(char *str)
{
    for (int i = 0; i < strlen(str) - 1; i++)
    {
        if (str[i] == ' ')
            return 1;
    }
    return 0;
}

int checkWhileSpace(char c)
{
    return (c == ' ' || c == '\0' || c == '\t');
}

void showString(char *str, int idxStart, int idxEnd)
{
    printf("Tu dai nhat trong xau la : ");
    for (int i = idxStart; i <= idxEnd; i++)
    {
        printf("%c", str[i]);
    }
}

void showPosition(char *str, int idxStart, int idxEnd)
{
    int pos = 1;
    for (int i = idxStart; i <= idxEnd; i++)
    {
        if (str[i] == ' ')
            pos++;
    }
    printf("\nO vi tri thu : %d", pos);
}

void execute(char *str)
{
    if (!checkString(str))
    {
        showString(str, 0, strlen(str) - 2);
        printf("\nO vi tri thu : 1");
    }
    else
    {
        int cnt = 0, cntMax = 0, index = 0;
        for (int i = 0; i < strlen(str) - 1; i++)
        {
            if (isalpha(str[i]) && isalpha(str[i + 1]))
                cnt++;
            else
            {
                if (cnt > cntMax)
                {
                    index = i - cnt + 1;
                    cntMax = cnt;
                    cnt = 0;
                }
            }
        }

        showString(str, index - 1, cntMax + index - 1);
        showPosition(str, 0, index - 1);
    }
}


int main()
{
    char str[100];
    printf("Nhap xau: ");
    fflush(stdin);
    fgets(str, sizeof(str) - 1, stdin);

    execute(str);

    return 0;
}