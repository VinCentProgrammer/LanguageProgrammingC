/*
Ex5.15. Hãy thực hiện tính:
a) Tổng hai số nguyên lớn
b) Hiệu hai số nguyên lớn
c) Tích hai số nguyên lớn
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int checkBigInteger(char *str)
{
    for (int i = 0; i < strlen(str) - 1; i++)
    {
        if (!isdigit(str[i]))
            return 0;
    }

    return 1;
}

long long sum(long val1, long val2)
{
    return val1 + val2;
}

long long sub(long val1, long val2)
{
    return val1 - val2;
}

long long mul(long val1, long val2)
{
    return val1 * val2;
}

int main()
{
    char str1[10], str2[10];

    do
    {
        printf("Nhap vao chuoi so 1: ");
        fflush(stdin);
        fgets(str1, sizeof(str1) - 1, stdin);
    } while (!checkBigInteger(str1));

    do
    {
        printf("Nhap vao chuoi so 2: ");
        fflush(stdin);
        fgets(str2, sizeof(str2) - 1, stdin);
    } while (!checkBigInteger(str2));

    long val1 = atol(str1);
    long val2 = atol(str2);

    printf("Tong 2 so nguyen lon la: %lld \n", sum(val1, val2));
    printf("Hieu 2 so nguyen lon la: %lld \n", sub(val1, val2));
    printf("Tich 2 so nguyen lon la: %lld \n", mul(val1, val2));

    return 0;
}