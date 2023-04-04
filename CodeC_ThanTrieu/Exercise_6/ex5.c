/*
Ex 6.5. Mỗi học sinh có mã(dãy 5 kí tự chữ và số liên tiếp, VD: 10A11, 12A30) họ tên đầy đủ(tối đa 50 kí tự), ngày sinh(dạng chuỗi ví dụ 20/11/2005),điểm trung bình môn, lớp, xếp loại học lực. Bạn hãy thực hiện các hành động phù hợp để:
a) Nhập mới học sinh vào danh sách.
b) Hiển thị danh sách học sinh hiện có, mỗi học sinh hiện thông tin trên 1 dòng.
c) Tìm học sinh theo mã.
d) Tìm học sinh theo tên.
e) Tìm học sinh theo điểm trung bình.
f) Xóa học sinh theo mã cho trước.
g) Sắp xếp danh sách học sinh theo điểm trung bình môn giảm dần.
h) Sắp xếp học sinh theo tên tăng dần a->z.
i) Xếp loại học lực cho học sinh và hiển thị ra màn hình theo tiêu chí:
 Xuất sắc: điểm tb từ 9.0 trở lên.
 Giỏi: điểm tb từ 8.0 đến dưới 9.0.
 Khá: điểm tb từ 6.5 đến dưới 8.0.
 TB: điểm tb từ 4.0 đến dưới 6.5.
 Yếu: điểm tb dưới 4.0.
j) Ghi thông tin danh sách học sinh vào file.
Viết menu cho phép quản lý chương trình theo chỉ mục chức năng bắt đầu từ 1. Chỉ mục 0 dùng để kết thúc chương trình.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct Student
{
    char code[6];
    char fullName[50];
    char dateOfBirth[11];
    float gpa;
    char class[50];
} ST;

char *separateFullNameToLastName(char *strName);
int checkCode(char *str);
int checkFullName(char *str);
int checkDateOfBirth(char *str);
int checkGpa(float mark);
int checkClass(char *str);

ST enterInfoStudent();
void printListStudent(ST st[], int numStudent);
void searchStudentByCode(ST st[], int numStudent, char *strCode);
void searchStudentByName(ST st[], int numStudent, char *fullname);
void searchStudentByGpa(ST st[], int numStudent, float gpa);
void deleteStudentByCode(ST st[], int numStudent, char *strCode);
void sortStudentByGpaDecrease(ST st[], int numStudent);
void sortStudentByNameIncrease(ST st[], int numStudent);
void rankedAcademicByGpa(ST st[], int numStudent);
void writeInfoStudentForFile(ST st[], int numStudent, char *nameFile);
int menu();

int main()
{
    ST st[1000];
    int num = 0;
    while (1)
    {
        int choice = menu();
        switch (choice)
        {
        case 1:
            printf("---------------------------\n");
            st[num++] = enterInfoStudent();
            printf("---------------------------\n");
            break;
        case 2:
            printf("---------------------------\n");
            printListStudent(st, num);
            printf("---------------------------\n");
            break;
        case 3:
            printf("---------------------------\n");
            char strCode[5];
            do
            {
                printf("Nhap vao ma hoc sinh can tim (vd: 12H12): ");
                fflush(stdin);
                gets(strCode);
            } while (!checkCode(strCode));

            searchStudentByCode(st, num, strCode);

            printf("---------------------------\n");
            break;
        case 4:
            printf("---------------------------\n");
            char strName[10];

            printf("Nhap vao ten hoc sinh can tim (vd: Dung): ");
            fflush(stdin);
            gets(strName);

            searchStudentByName(st, num, strName);

            printf("---------------------------\n");
            break;
        case 5:
            printf("---------------------------\n");
            float gpa;
            do
            {
                printf("Nhap vao gpa hoc sinh can tim (0<=gpa<=10): ");
                scanf("%f", &gpa);
            } while (!checkGpa(gpa));

            searchStudentByGpa(st, num, gpa);

            printf("---------------------------\n");
            break;
        case 6:
            printf("---------------------------\n");
            char strCodeDelete[5];
            do
            {
                printf("Nhap vao ma hoc sinh can xoa (vd: 12H12): ");
                fflush(stdin);
                gets(strCodeDelete);
            } while (!checkCode(strCodeDelete));

            deleteStudentByCode(st, num, strCodeDelete);

            printf("---------------------------\n");
            break;
        case 7:
            printf("---------------------------\n");

            printf("Truoc khi sap xep: \n");
            printListStudent(st, num);

            printf("Sau khi sap xep: \n");
            sortStudentByGpaDecrease(st, num);

            printf("---------------------------\n");
            break;
        case 8:
            printf("---------------------------\n");

            printf("Truoc khi sap xep: \n");
            printListStudent(st, num);

            printf("Sau khi sap xep: \n");
            sortStudentByNameIncrease(st, num);

            printf("---------------------------\n");
            break;
        case 9:
            printf("---------------------------\n");
            rankedAcademicByGpa(st, num);
            printf("---------------------------\n");
            break;
        case 10:
            printf("---------------------------\n");
            char strNameFile[100];
            printf("Nhap vao ten file can luu tru: ");
            fflush(stdin);
            gets(strNameFile);
            writeInfoStudentForFile(st, num, strNameFile);
            printf("---------------------------\n");
            break;
        default:
            return 0;
            break;
        }
    }

    return 0;
}

int checkCode(char *str)
{
    int cntDigit = 1, cntAlpha = 0, ok = 0;
    for (int i = 0; i < strlen(str) - 1; i++)
    {
        if (((str[i] >= 'A' && str[i] <= 'Z') && isdigit(str[i + 1])) || ((str[i + 1] >= 'A' && str[i + 1] <= 'Z') && isdigit(str[i])) || (isdigit(str[i]) && isdigit(str[i + 1])))
        {
            ok = 1;
            if (isdigit(str[i]))
                cntDigit++;
            else
                cntAlpha++;
        }
        else
        {
            ok = 0;
            break;
        }
    }
    if (cntAlpha == 1 && cntDigit == 4 && ok == 1)
        return 1;
    else
        return 0;
}

int checkFullName(char *str)
{
    int ok = 0;
    if ((str[0] >= 'A' && str[0] <= 'Z'))
    {
        for (int i = 0; i < strlen(str) - 1; i++)
        {
            if (((isblank(str[i])) && (str[i + 1] >= 'A' && str[i + 1] <= 'Z')) || ((str[i] >= 'A' && str[i] <= 'Z') && (str[i + 1] >= 'a' && str[i + 1] <= 'z')) || ((str[i] >= 'a' && str[i] <= 'z') && (str[i + 1] >= 'a' && str[i + 1] <= 'z')) || ((isblank(str[i + 1])) && (str[i] >= 'a' && str[i + 1] <= 'z')))
            {
                ok = 1;
            }
            else
            {
                ok = 0;
                break;
            }
        }
    }
    else
        ok = 0;

    if (!ok)
        return 0;
    else
        return 1;
}

int checkDateOfBirth(char *str)
{
    int ok = 0, cntSlash = 0, cntDigit = 1;
    for (int i = 0; i < strlen(str) - 1; i++)
    {
        if (isdigit(str[i]) && isdigit(str[i + 1]) || isdigit(str[i]) && str[i + 1] == '/' || isdigit(str[i + 1]) && str[i] == '/')
        {
            ok = 1;
            if (isdigit(str[i]))
                cntDigit++;
            else
                cntSlash++;
        }
        else
        {
            ok = 0;
            break;
        }
    }
    if (ok == 1 && cntDigit == 8 && cntSlash == 2)
        return 1;
    else
        return 0;
}

int checkGpa(float mark)
{
    if (mark >= 0 && mark <= 10)
        return 1;
    else
        return 0;
}

int checkClass(char *str)
{
    if (strcmp(str, "CNTT") == 0 || strcmp(str, "DK-TDH") == 0 || strcmp(str, "LOGISTIC") == 0)
        return 1;
    else
        return 0;
}

ST enterInfoStudent()
{
    ST st;
    // Nhap ma sinh vien
    do
    {
        printf("Nhap ma sinh vien (Vd: 12D43): ");
        fflush(stdin);
        gets(st.code);
    } while (!checkCode(st.code));

    // Nhap ho va ten

    do
    {
        printf("Nhap ho va ten sinh vien (Vd: Nguyen Van A): ");
        fflush(stdin);
        gets(st.fullName);
    } while (!checkFullName(st.fullName));

    // Nhap ngay thang nam sinh

    do
    {
        printf("Nhap ngay thang nam sinh (Vd: 21/12/2004): ");
        fflush(stdin);
        gets(st.dateOfBirth);
    } while (!checkDateOfBirth(st.dateOfBirth));

    // Nhap gpa
    do
    {
        printf("Nhap GPA hoc sinh: ");
        scanf("%f", &st.gpa);
    } while (!checkGpa(st.gpa));

    // Nhap lop

    do
    {
        printf("Nhap lop hoc (CNTT/DK-TDH/LOGISTIC): ");
        fflush(stdin);
        gets(st.class);
    } while (!checkClass(st.class));

    return st;
}

void printListStudent(ST st[], int numStudent)
{
    printf("%-10s %-20s %-15s %-10s %-15s \n", "Code", "Full name ", "Date Of Birth", "Gpa", "Class");
    for (int i = 0; i < numStudent; i++)
    {
        printf("%-10s %-20s %-15s %-10.2f %-15s \n", st[i].code, st[i].fullName, st[i].dateOfBirth, st[i].gpa, st[i].class);
    }
}

void searchStudentByCode(ST st[], int numStudent, char *strCode)
{
    ST stCode[numStudent];
    int ok = 0, k = 0;

    for (int i = 0; i < numStudent; i++)
    {
        if (strcmp(st[i].code, strCode) == 0)
        {
            stCode[k++] = st[i];
            ok = 1;
        }
    }
    if (ok == 1)
    {
        printListStudent(stCode, k);
    }
    else
        printf("Khong co sinh vien co ma %s\n", strCode);
}

char *separateFullNameToLastName(char strName[])
{
    char oganizeName[50][50];
    char *token;
    const char *delim = " ";
    int h = 0;

    for (token = strtok(strName, delim); token != NULL; token = strtok(NULL, delim))
    {
        strcpy(oganizeName[h++], token);
    }

    char *str = oganizeName[h - 1];
    return str;
}

void searchStudentByName(ST st[], int numStudent, char *name)
{
    ST stName[numStudent];
    int ok = 0, k = 0;

    for (int i = 0; i < numStudent; i++)
    {
        char str1[50];
        strcpy(str1, st[i].fullName);

        if (strcmp(separateFullNameToLastName(st[i].fullName), name) == 0)
        {
            strcpy(st[i].fullName, str1);
            stName[k++] = st[i];
            ok = 1;
        }
    }
    if (ok == 1)
    {
        printListStudent(stName, k);
    }
    else
        printf("Khong co sinh vien co ten %s\n", name);
}

void searchStudentByGpa(ST st[], int numStudent, float gpa)
{
    ST stGPA[numStudent];
    int ok = 0, k = 0;

    for (int i = 0; i < numStudent; i++)
    {
        if (st[i].gpa == gpa)
        {
            stGPA[k++] = st[i];
            ok = 1;
        }
    }
    if (ok == 1)
    {
        printListStudent(stGPA, k);
    }
    else
        printf("Khong co sinh vien co diem gpa la %.2f\n", gpa);
}

void deleteStudentByCode(ST st[], int numStudent, char *strCode)
{
    ST stDelete[numStudent];

    int h = 0, ok = 0;

    for (int i = 0; i < numStudent; i++)
    {
        if (strcmp(st[i].code, strCode) != 0)
        {
            printf("Da xoa thanh cong! \n");
            stDelete[h++] = st[i];
            ok = 1;
        }
    }
    if (ok == 1)
    {
        printListStudent(stDelete, h);
    }
    else
        printf("Khong tim thay sinh vien co ma %s can xoa hoac da xoa. \n", strCode);
}

void sortStudentByGpaDecrease(ST st[], int numStudent)
{
    for (int i = 0; i < numStudent - 1; i++)
    {
        for (int j = i; j < numStudent - 1; j++)
        {
            if (st[j].gpa < st[j + 1].gpa)
            {
                ST stTmp;
                stTmp = st[j];
                st[j] = st[j + 1];
                st[j + 1] = stTmp;
            }
        }
    }

    printListStudent(st, numStudent);
}

void sortStudentByNameIncrease(ST st[], int numStudent)
{
    for (int i = 0; i < numStudent - 1; i++)
    {
        for (int j = i; j < numStudent - 1; j++)
        {
            ST stPre = st[j];
            char cPre;
            for (int k = strlen(stPre.fullName) - 1; k >= 0; k--)
            {
                if (stPre.fullName[k] == ' ')
                {
                    cPre = stPre.fullName[k + 1];
                    break;
                }
            }

            ST stNext = st[j + 1];
            char cNext;

            for (int k = strlen(stNext.fullName) - 1; k >= 0; k--)
            {
                if (stNext.fullName[k] == ' ')
                {
                    cNext = stNext.fullName[k + 1];
                    break;
                }
            }

            printf("%c \n", cPre);
            printf("%c \n", cNext);

            if (cPre > cNext)
            {
                ST stTmp;
                stTmp = st[j];
                st[j] = st[j + 1];
                st[j + 1] = stTmp;
            }
        }
    }

    printListStudent(st, numStudent);
}

void rankedAcademicByGpa(ST st[], int numStudent)
{
    for (int i = 0; i < numStudent; i++)
    {
        if (st[i].gpa > 9)
            printf("%s (%.2f) -> Xuat sac \n", st[i].fullName, st[i].gpa);
        else if (st[i].gpa >= 8)
            printf("%s (%.2f) -> Gioi \n", st[i].fullName, st[i].gpa);
        else if (st[i].gpa >= 6.5)
            printf("%s (%.2f) -> Kha \n", st[i].fullName, st[i].gpa);
        else if (st[i].gpa >= 4)
            printf("%s (%.2f) -> Trung Binh \n", st[i].fullName, st[i].gpa);
        else
            printf("%s (%.2f) -> Yeu \n", st[i].fullName, st[i].gpa);
    }
}

void writeInfoStudentForFile(ST st[], int numStudent, char *nameFile)
{
    FILE *fptr;

    fptr = fopen(nameFile, "a");

    if (fptr == NULL)
    {
        printf("Loi mo hoac tao file! \n");
        exit(1);
    }

    for (int i = 0; i < numStudent; i++)
    {
        fprintf(fptr, "%-10s %-20s %-15s %-10.2f %-15s \n", st[i].code, st[i].fullName, st[i].dateOfBirth, st[i].gpa, st[i].class);
    }

    fclose(fptr);
}

int menu()
{
    int choice;
    printf("=============== MENU ============== \n");
    printf("0. Thoat chuong trinh. \n");
    printf("1. Nhap moi hoc sinh vao danh sach. \n");
    printf("2. Hien thi hoc sinh hien co. \n");
    printf("3. Tim hoc sinh theo ma. \n");
    printf("4. Tim hoc sinh theo ten. \n");
    printf("5. Tim hoc sinh theo diem trung binh. \n");
    printf("6. Xoa hoc sinh theo ma. \n");
    printf("7. Sap xep danh sach hoc sinh theo diem trung binh giam dan. \n");
    printf("8. Sap xep hoc sinh theo ten tang dan a -> z. \n");
    printf("9. Xep loai hoc luc cho hoc sinh. \n");
    printf("10. Ghi thong tin hoc sinh vao file. \n");
    printf("? \t");
    scanf("%d", &choice);

    return choice;
}
