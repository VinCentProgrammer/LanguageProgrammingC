/*
Nhập họ và tên theo cấu trúc: họ-đệm-tên và chuyển xâu đó sang biểu diễn theo cấu trúc tên-đệm-họ.
vd: Ha Van Dung -> Dung Van Ha
vd: Ha Thi Thanh Bich -> Bich Thi Thanh Ha
#B1: Nhap vao ten theo mau ho-dem-ten
#B2: Dung 2 bien l = 0; r = strlen(str) - 2;
#B3:
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

void execute(char *str)
{
    int l = 0, r = strlen(str) - 2;

    int cntLastName = 0;
    while (str[r] != ' ')
    {
        r--;
        cntLastName++;
    }

    int cntFirstName = 0;
    while (str[l] != ' ')
    {
        l++;
        cntFirstName++;
    }

    // In Last Name
    for (int i = r + 1; i <= r + cntLastName; i++)
    {
        printf("%c", str[i]);
    }

    // In Middle Name
    for (int i = l; i <= r; i++)
    {
        printf("%c", str[i]);
    }

    // In First Name
    for (int i = 0; i <= l; i++)
    {
        printf("%c", str[i]);
    }
    
}
int main()
{
    char str[100];
    printf("Nhap ho van ten theo thu tu ho-dem-ten: ");
    fflush(stdin);
    fgets(str, sizeof(str) - 1, stdin);

    execute(str);

    return 0;
}