#include <stdio.h>
#include <math.h>
#include <string.h>

void solve(char str[])
{
    int k1 = 0, k2 = 0, k3 = 0, k4 = 0, ok1 = 1, ok2 = 1, ok3 = 1, ok4 = 1;
    int c2 = 0, c3 = 0, c5 = 0, c7 = 0;
    for (int i = 0; i < strlen(str); i++)
    {
        if (str[i] == '2' && ok1)
        {
            while (k1 < strlen(str))
            {
                if (str[k1++] == '2')
                    c2++;
            }
            ok1 = 0;
            printf("2 %d\n", c2);
        }

        if (str[i] == '3' && ok2)
        {
            while (k2 < strlen(str))
            {
                if (str[k2++] == '3')
                    c3++;
            }
            ok2 = 0;
            printf("3 %d\n", c3);
        }

        if (str[i] == '5' && ok3)
        {
            while (k3 < strlen(str))
            {
                if (str[k3++] == '5')
                    c5++;
            }
            ok3 = 0;
            printf("5 %d\n", c5);
        }
        
        if (str[i] == '7' && ok4)
        {
            while (k4 < strlen(str))
            {
                if (str[k4++] == '7')
                    c7++;
            }
            ok4 = 0;
            printf("7 %d\n", c7);
        }
    }
}
int main()
{
    char n[19];
    fflush(stdin);
    gets(n);
    solve(n);
    return 0;
}