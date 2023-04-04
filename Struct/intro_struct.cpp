#include <stdio.h>

struct Date
{
    int day;
    int month;
    int year;
};

struct Person
{
    char name[50];
    char gender[6];
    struct Date;
};

int main()
{
    struct Date myDate;
    struct Person person;
    printf("Nhap vao ngay sinh cua ban: ");
    scanf("%d %d %d", &myDate.day, &myDate.month, &myDate.year);
    printf("%d/%d/%d", myDate.day, myDate.month, myDate.year);
    return 0;
}
