#include <stdio.h>
/*
- Ki tu
+ Bang ma ASCII: a-> 97; A -> 65
+ Cach nhap ki tu tu ban phim
> scanf("%c", str);
> getchar();

- Xau ki tu
+ Ki tu cuoi cung cua xau ki tu la NULL ("\0")
+ Khai bao xau ki tu:
> Khai bao theo mang. Vd: char hello[13] = "Hello World!";
> Khai bao theo con tro. Vd: const *str = "Ha Van Dung";
+ Cach nhap xau ki tu tu ban phim
gets();
> Xoa bo dem ban phim: fflush(stdin);
*/
int main()
{
    // char character;
    // scanf("%c", &character);

    char character = getchar();

    // printf("%d \n", character); // In ra so tuong ung vs ki tu trong bang ma ASCII
    // printf("%c", character); // In ra ki tu

    // char hello[13] = "Hello World";
    // const *str = "Ha Van Dung";

    char hello[13];
    fflush(stdin); // Xoa bo dem ban phim
    gets(hello);

    printf("%s", hello);

    return 0;
}