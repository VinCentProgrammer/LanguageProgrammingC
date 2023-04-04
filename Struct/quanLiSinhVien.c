#include <stdio.h>
#include <string.h>
#include <time.h>

struct date
{
    int day;
    int month;
    int year;
};

struct Student
{
    int id;
    char name[50];
    char gender[6];
    struct date dateOfBirth;
    int age;
    float mark1;
    float mark2;
    float mark3;
    float gpa;
    char rank[50];
    char code[10];
};

typedef struct Student ST;

void deleteDownTheLine(char x[]);
void enterStudent(ST *st);
void printStudent(ST st);
void countAge(ST *st);
void countGPA(ST *st);
void rank(ST *st);
void updateStudent(ST *st);
void enterListStudent(ST list[], int *n);
void printListStudent(ST list[], int n);
float searchMaxGpa(ST list[], int n);
int searchMinAge(ST list[], int n);
void showListStudentRankGood(ST list, int n);
void showListStudentFollowCode(ST list, int n, char code[]);
int searchStudentFollowName(ST list, int n, char name[]);
void deleteStudentFollowId(ST list, int &n, int id);
void sortListStudentFollowGpa(ST list, int n);
void sortListStudentFollowName(ST list, int n);

int main()
{
    ST list[100];
    int n;
    enterListStudent(list, &n);
    printListStudent(list, n);
    printf("\n GPA Max is : %.2f", searchMaxGpa(list, n));
    printf("\n Age min is : %d", searchMinAge(list, n));
    return 0;
}

void deleteDownTheLine(char x[])
{
    size_t len = strlen(x);
    if (x[len - 1] == '\n')
    {
        x[len - 1] = '\0';
    }
}

void enterStudent(ST *st)
{
    printf("ID: ");
    scanf("%d", &st->id);
    printf("Name: ");
    fflush(stdin);
    fgets(st->name, sizeof(st->name), stdin);
    deleteDownTheLine(st->name);
    printf("Gender: ");
    fflush(stdin);
    fgets(st->gender, sizeof(st->gender), stdin);
    deleteDownTheLine(st->gender);
    printf("Date Of Birth: ");
    scanf("%d %d %d", &st->dateOfBirth.day, &st->dateOfBirth.month, &st->dateOfBirth.year);
    printf("Mark 1: ");
    scanf("%f", &st->mark1);
    printf("Mark 2: ");
    scanf("%f", &st->mark2);
    printf("Mark 3: ");
    scanf("%f", &st->mark3);
    printf("My Code: ");
    fflush(stdin);
    fgets(st->code, sizeof(st->code), stdin);
    deleteDownTheLine(st->code);
}

void printStudent(ST st)
{
    printf("%5d \t %10s \t %5s \t\t %d/%d/%d \t %5d \t %5.2f \t %5.2f \t %5.2f \t %5.2f \t %5s \t\t %5s", st.id, st.name, st.gender, st.dateOfBirth.day, st.dateOfBirth.month, st.dateOfBirth.year, st.age, st.mark1, st.mark2, st.mark3, st.gpa, st.rank, st.code);
}

void countAge(ST *st)
{
    time_t TTIME = time(NULL);
    struct tm *Now = localtime(&TTIME);
    int yearNow = Now->tm_year + 1900;
    st->age = yearNow - st->dateOfBirth.year;
}

void countGPA(ST *st)
{
    st->gpa = (st->mark1 + st->mark2 + st->mark3) / 3;
}

void rank(ST *st)
{
    int res = st->gpa;
    if (res >= 9)
        strcpy(st->rank, "Excellent");
    else if (res >= 8)
        strcpy(st->rank, "Good");
    else if (res >= 6.5)
        strcpy(st->rank, "Rather");
    else if (res >= 5)
        strcpy(st->rank, "Medium");
    else
        strcpy(st->rank, "Weak");
}

void updateStudent(ST *st)
{
    enterStudent(st);
    countAge(st);
    countGPA(st);
    rank(st);
}

void enterListStudent(ST list[], int *n)
{
    do
    {
        printf("Enter number of student: ");
        scanf("%d", n);
    } while (*n <= 0);

    for (int i = 0; i < *n; i++)
    {
        printf("Enter student %d: \n", i + 1);
        updateStudent(&list[i]);
    }
}

void printListStudent(ST list[], int n)
{
    printf("%5s \t %10s \t %5s \t %5s \t %5s \t %5s \t %5s \t %5s \t %5s \t %5s \t\t %5s", "ID", "Name", "Gender", "Date Of Birth", "Age", "Mark1", "Mark2", "Mark3", "GPA", "Rank", "My Code");
    printf("\n");
    for (int i = 0; i <= n - 1; i++)
    {
        printStudent(list[i]);
        printf("\n");
    }
}

float searchMaxGpa(ST list[], int n)
{
    float max = list[0].gpa;
    for (int i = 0; i < n; i++)
    {
        if (list[i].gpa > max)
            max = list[i].gpa;
    }
    return max;
}
int searchMinAge(ST list[], int n)
{
    int min = list[0].age;
    for (int i = 0; i < n; i++)
    {
        if (list[i].age < min)
            min = list[i].age;
    }
    return min;
}

void showListStudentRankGood(ST list, int n)
{
    printf("List Student Rank Good : \n");
    printf("%5s \t %10s \t %5s \t %5s \t %5s \t %5s \t %5s \t %5s \t %5s \t %5s \t\t %5s", "ID", "Name", "Gender", "Date Of Birth", "Age", "Mark1", "Mark2", "Mark3", "GPA", "Rank", "My Code");
    printf("\n");
    for (int i = 0; i < n; i++)
    {
        if (strcmp(list[i].rank, "Good") == 0)
            printStudent(list[i]);
        printf("\n");
    }
}
void showListStudentFollowCode(ST list, int n, char code[])
{
    printf("List Student Follow Code : \n");
    printf("%5s \t %10s \t %5s \t %5s \t %5s \t %5s \t %5s \t %5s \t %5s \t %5s \t\t %5s", "ID", "Name", "Gender", "Date Of Birth", "Age", "Mark1", "Mark2", "Mark3", "GPA", "Rank", "My Code");
    printf("\n");
    for (int i = 0; i < n; i++)
    {
        if (strcmp(list[i].code, code) == 0)
            printStudent(list[i]);
        printf("\n");
    }
}
int searchStudentFollowName(ST list, int n, char name[])
{
    for (int i = 0; i < n; i++)
    {
        if (strcmp(list[i].name, name) == 0)
            return 1;
    }
    return 0;
}
void deleteStudentFollowId(ST list, int &n, int id)
{
    for(int i = 0; i < n; i++){
        if()
    }
}
void sortListStudentFollowGpa(ST list, int n)
{
}
void sortListStudentFollowName(ST list, int n)
{
}