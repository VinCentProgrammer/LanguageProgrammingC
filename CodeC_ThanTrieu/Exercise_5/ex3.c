// /*
// Viết hàm kiểm tra số thuận nghịch sử dụng xâu kí tự. Áp dụng để hiển thị các số thuận nghịch có 9 chữ số.
// 123454321 -> la so thuan nghich
// 123456789 -> khong la so thuan nghich

// */

// #include <stdio.h>
// #include <string.h>
// #include <ctype.h>

// int checkNumberReverse(char *str)
// {
//     int l = 0, r = strlen(str) - 2;

//     while (l < r)
//     {
//         if (str[l] != str[r])
//             return 0;
//         l++;
//         r--;
//     }
//     return 1;
// }

// int main()
// {
//     char str[100];
//     printf("Nhap vao so can kiem tra: ");
//     fflush(stdin);
//     fgets(str, sizeof(str) - 1, stdin);

//     if (checkNumberReverse(str))
//         printf("La so thuan nghich");
//     else
//         printf("Khong la so thuan nghich");

//     return 0;
// }

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

// int isReverse(char *str)
// {
//     char strTmp[10];
//     strcpy(strTmp, str);
//     strrev(str);
//     return strcmp(str, strTmp) == 0;
// }

int isReverse(long number)
{
    char str[10];                    // Luu kieu so thanh kieu chuoi
    char strTmp[10];                 // Luu chuoi ban dau
    ltoa(number, str, 10);           // Chuyen so thanh chuoi
    strcpy(strTmp, str);             // Luu chuoi ban dau de so sanh
    strrev(str);                     // Dao nguoc chuoi ban dau
    return strcmp(str, strTmp) == 0; // So sanh chuoi ban dau va chuoi tam
}

int main()
{
    for (int i = 100000000; i <= 999999999; i++)
    {
        if (isReverse(i))
            printf("%d ", i);
    }

    return 0;
}