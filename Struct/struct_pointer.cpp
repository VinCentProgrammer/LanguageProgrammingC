#include <stdio.h>

struct Person
{
    char name[50];
    int age;
    float weight;
};

int main()
{
    struct Person *personPtr, person1;
    personPtr = &person1;
    printf("Enter name: ");
    scanf("%s", &personPtr->name);
    printf("Enter age: ");
    scanf("%d\n", &personPtr->age);
    printf("Enter weight: ");
    scanf("%f\n", &personPtr->weight);

    printf("%s --- %d --- %f ", personPtr->name, personPtr->age, personPtr->weight);
    return 0;
}