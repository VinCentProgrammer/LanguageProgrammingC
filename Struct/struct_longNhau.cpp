#include <stdio.h>

struct date
{
    int day;
    int month;
    int year;
};

struct Person
{
    char name[50];
    date dateOfBirth;
    float weight;
};

struct point
{
    float x;
    float y;
};

struct triangle
{
    point a, b, c;
};

struct circle
{
    point c;
    float r;
};

struct rectangle
{
    point a, b, c, d;
};

int main()
{

    return 0;
}