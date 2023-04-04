
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

typedef struct FullName
{
    char firstName[10];
    char middleName[20];
    char lastName[10];
} FN;

typedef struct Mark
{
    float math;
    float literature;
    float english;
} M;

typedef struct Student
{
    char code[5];
    FN fullName;
    int age;
    char gender[7];
    M mark;
} ST;

int checkCodeStudent(char *str);
int checkNameStudent(char *str);
int checkGenderStudent(char *str);
int checkMarkStudent(float mark1, float mark2, float mark3);

ST enterInfoStudent();
void showInfoStudent(ST st);
void showListInfoStudent(ST st[], int num);
void sortStudentByNameAtoZ(ST st[], int num);
void sortStudentByGpaDecrease(ST st[], int num);
ST searchStudentByName(ST st[], char *lastName, int num);
void writeStudentForFile(ST st[], int num);
int menu();



int main()
{
    ST st[100];
    int num = 0;
    char str[10];

    ST resByName[100];
    while (1)
    {
        int choice = menu();
        switch (choice)
        {
        case 1:
            st[num++] = enterInfoStudent();
            break;
        case 2:
            printf("---------------\n");
            showListInfoStudent(st, num);
            printf("---------------\n");
            break;
        case 3:
            sortStudentByNameAtoZ(st, num);
            printf("---------------\n");
            showListInfoStudent(st, num);
            printf("---------------\n");
            break;
        case 4:
            sortStudentByGpaDecrease(st, num);
            printf("---------------\n");
            showListInfoStudent(st, num);
            printf("---------------\n");
            break;
        case 5:
            printf("Nhap vao ten sinh vien muon tim: ");
            fflush(stdin);
            gets(str);
            for (int i = 0; i < num; i++)
            {
                resByName[i] = searchStudentByName(st, str, num);
                printf("---------------\n");
                showInfoStudent(resByName[i]);
                printf("---------------\n");
            }
            break;
        case 6:
            writeStudentForFile(st, num);
            break;
        default:
            return 0;
            break;
        }
    }

    return 0;
}




int checkCodeStudent(char *str)
{
    int cnt = 0;
    for (int i = 0; i < strlen(str); i++)
    {
        cnt++;
        if (!isdigit(str[i]))
            return 0;
    }
    if (cnt == 4)
        return 1;
    return 0;
}
int checkNameStudent(char *str)
{
    for (int i = 0; i < strlen(str); i++)
    {
        if (!isalpha(str[i]))
            return 0;
    }
    return 1;
}
int checkGenderStudent(char *str)
{
    if (strcmp(str, "Male") == 0 || strcmp(str, "Female") == 0 || strcmp(str, "Other") == 0)
        return 1;
    return 0;
}
int checkMarkStudent(float mark1, float mark2, float mark3)
{
    if (mark1 < 0 && mark1 > 10 || mark2 < 0 && mark2 > 10 || mark3 < 0 && mark3 > 10)
        return 0;
    return 1;
}

ST enterInfoStudent()
{
    ST st;
    printf("ENTER INFO FOR STUDENT: \n");

    // Nhap ma sinh vien
    do
    {
        printf("Enter code for student: ");
        fflush(stdin);
        gets(st.code);
    } while (checkCodeStudent(st.code) == 0);

    // Nhap ho va ten sinh vien

    printf("Enter fullname for student: \n");
    do
    {
        printf("Enter first name: ");
        fflush(stdin);
        gets(st.fullName.firstName);
    } while (!checkNameStudent(st.fullName.firstName));

    do
    {
        printf("Enter middle name: ");
        fflush(stdin);
        gets(st.fullName.middleName);
    } while (!checkNameStudent(st.fullName.middleName));

    do
    {
        printf("Enter last name: ");
        fflush(stdin);
        gets(st.fullName.lastName);
    } while (!checkNameStudent(st.fullName.lastName));

    // Nhap tuoi sinh vien
    do
    {
        printf("Enter age for student: ");
        scanf("%d", &st.age);
    } while (st.age <= 0);

    // Nhap gioi tinh
    do
    {
        printf("Enter genter for student (Male/Female/Other) : ");
        fflush(stdin);
        gets(st.gender);
    } while (!checkGenderStudent(st.gender));

    // Nhap diem
    do
    {
        printf("Enter mark for student : \n");
        printf("Enter mark math: ");
        scanf("%f", &st.mark.math);
        printf("Enter mark literature: ");
        scanf("%f", &st.mark.literature);
        printf("Enter mark english: ");
        scanf("%f", &st.mark.english);
    } while (!checkMarkStudent(st.mark.english, st.mark.literature, st.mark.math));

    return st;
}

void showInfoStudent(ST st)
{
    printf("Code: %s\n", st.code);
    printf("Fullname: %s %s %s \n", st.fullName.firstName, st.fullName.middleName, st.fullName.lastName);
    printf("Age: %d\n", st.age);
    printf("Gender: %s \n", st.gender);
    printf("Mark math: %.2f \n", st.mark.math);
    printf("Mark literature: %.2f \n", st.mark.literature);
    printf("Mark english: %.2f \n", st.mark.english);
    printf("GPA: %.2f \n", (st.mark.math + st.mark.english + st.mark.literature) / 3);
}

void showListInfoStudent(ST st[], int num)
{
    printf("%-10s %-10s %-10s %-10s %-10s %-10s %-10s %-10s %-10s %-10s \n", "CODE", "FIRSTNAME", "MIDDLENAME", "LASTNAME", "AGE", "GENDER", "MARK MATH", "MARK LITERATURE", "MARK ENGLISH", "GPA");
    for (int i = 0; i < num; i++)
    {
        printf("%-10s %-10s %-10s %-10s %-10d %-10s %-10.2f %-10.2f %-10.2f %-10.2f \n", st[i].code, st[i].fullName.firstName, st[i].fullName.middleName, st[i].fullName.lastName, st[i].age, st[i].gender, st[i].mark.math, st[i].mark.literature, st[i].mark.english, (st[i].mark.math + st[i].mark.english + st[i].mark.literature) / 3);
    }
}

void sortStudentByNameAtoZ(ST st[], int num)
{
    for (int i = 0; i < num - 1; i++)
    {
        for (int j = i; j < num; j++)
        {
            if (strcmp(st[j].fullName.lastName, st[j + 1].fullName.lastName) > 0)
            {
                ST tmp;
                tmp = st[j + 1];
                st[j + 1] = st[j];
                st[j] = tmp;
            }
        }
    }
}

void sortStudentByGpaDecrease(ST st[], int num)
{
    for (int i = 0; i < num - 1; i++)
    {
        for (int j = i; j < num; j++)
        {
            float gpaPre = ((st[j].mark.math + st[j].mark.english + st[j].mark.literature) / 3);
            float gpaNext = ((st[j + 1].mark.math + st[j + 1].mark.english + st[j + 1].mark.literature) / 3);

            if (gpaPre < gpaNext)
            {
                ST tmp;
                tmp = st[j + 1];
                st[j + 1] = st[j];
                st[j] = tmp;
            }
        }
    }
}

ST searchStudentByName(ST st[], char *lastName, int num)
{
    for (int i = 0; i < num; i++)
    {
        if (strcmp(st[i].fullName.lastName, lastName) == 0)
            return st[i];
    }
}

void writeStudentForFile(ST st[], int num)
{
    FILE *fptr;
    fptr = fopen("listStudentEx4.txt", "a");

    if (fptr == NULL)
    {
        printf("Create or open file error!");
        exit(1);
    }

    for (int i = 0; i < num; i++)
    {
        fprintf(fptr, "%-10s %-10s %-10s %-10s %-10d %-10s %-10.2f %-10.2f %-10.2f %-10.2f \n", st[i].code, st[i].fullName.firstName, st[i].fullName.middleName, st[i].fullName.lastName, st[i].age, st[i].gender, st[i].mark.math, st[i].mark.english, st[i].mark.literature, ((st[i].mark.math + st[i].mark.english + st[i].mark.literature) / 3));
    }

    fclose(fptr);
}

int menu()
{
    int choice;
    printf("=================== MENU =================\n");
    printf("1. Nhap thong tin sinh vien va in thong tin sinh vien vua nhap\n");
    printf("2. Liet ke danh sach cac sinh vien hien co trong danh sach. \n");
    printf("3. Sap xep danh sach sinh vien tu a -> z. \n");
    printf("4. Sap xep danh sach sinh vien theo GPA giam dan.\n");
    printf("5. Tim sinh vien co ten nhap tu ban phim. \n");
    printf("6. Ghi thong tin sinh vien vao file. \n");
    printf("0. Thoat chuong trinh \n");
    printf("? \t");
    scanf("%d", &choice);
    return choice;
}