/*
Ex5.9. Cho một chuỗi ký tự đầu vào, hãy cho biết nó có bao nhiêu ký tự là nguyên âm, phụ âm, ký tự số và ký tự khác.

*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int checkVowel(char c)
{
    c = tolower(c);
    return (c == 'u' || c == 'e' || c == 'o' || c == 'a' || c == 'i');
}

int checkConsanant(char c)
{
    c = tolower(c);
    return (c == 'b' || c == 'c' || c == 'd' || c == 'f' || c == 'g' || c == 'h' || c == 'j' || c == 'k' || c == 'l' || c == 'm' || c == 'n' || c == 'p' || c == 'q' || c == 'r' || c == 's' || c == 't' || c == 'v' || c == 'w' || c == 'x' || c == 'y' || c == 'z');
}

int main()
{
    char str[100];
    printf("Nhap xau: ");
    fflush(stdin);
    fgets(str, sizeof(str) - 1, stdin);

    int cntV = 0, cntC = 0, cntD = 0;
    for (int i = 0; i < strlen(str) - 1; i++)
    {
        if (checkVowel(str[i]))
            cntV++;
        else if (checkConsanant(str[i]))
            cntC++;
        else if (isdigit(str[i]))
            cntD++;
    }

    printf("%d %d %d %d", cntV, cntC, cntD, strlen(str) - cntC - cntD - cntV - 1);
    return 0;
}