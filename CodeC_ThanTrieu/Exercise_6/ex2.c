/*
Ex 6.2. Số phức:
a) Tạo struct số phức với phần thực và phần ảo.
b) Viết hàm nhập vào thông số của số phức và trả về một số phức.
c) Viết hàm tính tổng, hiệu, tích, thương của 2 số phức và trả về kết quả là số phức.
d) Tạo menu cho phép người dùng lựa chọn các chức năng. Trong đó nhấn ESC sẽ kết
thúc chương trình.
*/

#include <stdio.h>
#include <math.h>

typedef struct Complex
{
    float real;
    float imag;
} Complex;

Complex enterComplex()
{
    Complex cpl;
    printf("ENTER COMPLEX NUMBER: \n");
    printf("Enter real num: ");
    scanf("%f", &cpl.real);
    printf("Enter imag num: ");
    scanf("%f", &cpl.imag);
    return cpl;
}

void showComplex(Complex cpl)
{
    if (cpl.imag < 0)
        printf("%2.f%2.f*i", cpl.real, cpl.imag);
    else if (cpl.real != 0)
        printf("%2.f +%2.f*i", cpl.real, cpl.imag);
    else if (cpl.real == 0 && cpl.imag != 0)
        printf("%2.f*i", cpl.imag);
    else if (cpl.imag == 0 && cpl.real != 0)
        printf("%.2f", cpl.real);
    else if (cpl.real == 0 && cpl.imag == 0)
        printf("0");
    else if (cpl.imag == 1 && cpl.real != 0)
        printf("i");
}

Complex sumComplex(Complex cpl1, Complex cpl2)
{
    Complex res;
    res.real = cpl1.real + cpl2.real;
    res.imag = cpl1.imag + cpl2.imag;
    return res;
}
Complex subComplex(Complex cpl1, Complex cpl2)
{
    Complex res;
    res.real = cpl1.real - cpl2.real;
    res.imag = cpl1.imag - cpl2.imag;
    return res;
}
Complex mulComplex(Complex cpl1, Complex cpl2)
{
    Complex res;
    res.real = cpl1.real * cpl2.real - cpl1.imag * cpl2.imag;
    res.imag = cpl1.real * cpl2.imag + cpl2.real * cpl1.imag;
    return res;
}

Complex devideComplex(Complex cpl1, Complex cpl2)
{
    Complex res;
    res.real = (cpl1.real * cpl2.real + cpl1.imag * cpl2.imag) / (pow(cpl2.real, 2) + pow(cpl2.imag, 2));
    res.imag = (cpl1.imag * cpl2.real - cpl1.real * cpl2.imag) / (pow(cpl2.real, 2) + pow(cpl2.imag, 2));
    return res;
}

int menu()
{
    int choice;
    printf("=========== MENU ==========\n");
    printf("1. Nhap 2 so phuc \n");
    printf("2. Tong 2 so phuc \n");
    printf("3. Hieu 2 so phuc \n");
    printf("4. Tich 2 so phuc \n");
    printf("5. Thuong 2 so phuc \n");
    printf("Nhap phim bat ki de thoat chuong trinh \n");
    printf("?");
    scanf("%d", &choice);
    return choice;
}

int main()
{
    Complex cpl1, cpl2, cpl;
    while (1)
    {
        int choice = menu();
        switch (choice)
        {
        case 1:
            cpl1 = enterComplex();
            showComplex(cpl1);
            printf("\n");
            cpl2 = enterComplex();
            showComplex(cpl2);
            printf("\n\n");
            break;
        case 2:
            cpl = sumComplex(cpl1, cpl2);
            showComplex(cpl);
            printf("\n");
            break;
        case 3:
            cpl = subComplex(cpl1, cpl2);
            showComplex(cpl);
            printf("\n");
            break;
        case 4:
            cpl = mulComplex(cpl1, cpl2);
            showComplex(cpl);
            printf("\n");
            break;
        case 5:
            cpl = devideComplex(cpl1, cpl2);
            showComplex(cpl);
            printf("\n");
            break;
        default:
            return 0;
        }
    }
    return 0;
}
