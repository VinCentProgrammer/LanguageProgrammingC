// #include <stdio.h>
// #include <string.h>

// /*
// Hãy chuyển một số ở hệ 10 thành số ở hệ cơ số b bất kì (1 < b ≤ 36).
// */

// const char compare[] = {
//     '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'X', 'Y', 'Z', 'W'};

// int main()
// {
//     int n, k, b;
//     char s[100];
//     scanf("%d", &n);
//     while (n--)
//     {
//         scanf("%d %d", &k, &b);
//         if (k == 0)
//             printf("0\n");
//         else
//         {
//             int i = 0;
//             while (k)
//             {
//                 int tmp = k % b;
//                 k /= b;
//                 s[i++] = compare[tmp];
//             }
//             s[i] = '\0';
//             strrev(s);
//             puts(s);
//         }
//     }
//     return 0;
// }

#include <stdio.h>
#include <string.h>

const char compare[] = {
    '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'X', 'Y', 'Z', 'W'};

int main()
{
    int n, k, b;
    char res[100];
    printf("Nhap vao so luong bo test: ");
    scanf("%d", &n);
    while (n--)
    {
        printf("Nhap vao lan luot la so can chuyen & co so can chuyen: ");
        scanf("%d %d", &k, &b);
        if (k == 0)
            printf("0 \n");
        else
        {
            int i = 0;
            while (k)
            {
                int tmp = k % b;
                k /= b;
                res[i++] = compare[tmp];
            }
            res[i] = '\0';
            strrev(res);
            puts(res);
        }
    }
    return 0;
}