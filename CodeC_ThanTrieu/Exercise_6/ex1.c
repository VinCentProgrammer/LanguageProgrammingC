
// #include <stdio.h>
// #include <math.h>

// typedef struct fraction
// {
//     int numerator;
//     int denominator;
// } Fraction;

// void enterFraction(Fraction *fraction)
// {
//     do
//     {
//         printf("ENTER FRACTION: \n");
//         printf("Enter numerator: ");
//         scanf("%d", &fraction->numerator);
//         printf("Enter demoninator: ");
//         scanf("%d", &fraction->denominator);
//     } while (fraction->numerator == 0 && fraction->denominator == 0 || fraction->numerator != 0 && fraction->denominator == 0);
// }

// void fixFraction(Fraction *fraction)
// {
//     if (fraction->denominator < 0)
//     {
//         fraction->denominator *= (-1);
//         fraction->numerator *= (-1);
//     }
// }

// void reduceFractions(Fraction *fraction)
// {
//     int a = abs(fraction->numerator), b = abs(fraction->denominator);

//     int UCLN = 1;

//     if (a == 0 || b == 0)
//         UCLN = (a + b);
//     else
//     {
//         while (a != b)
//         {
//             if (a > b)
//                 a = a - b;
//             else
//                 b = b - a;
//         }
//         UCLN = a;
//     }
//     fraction->numerator /= UCLN;
//     fraction->denominator /= UCLN;
// }

// void showFraction(Fraction fraction)
// {
//     fixFraction(&fraction);
//     reduceFractions(&fraction);
//     if (fraction.numerator == 0)
//         printf("0");
//     else if (fraction.numerator == 1 && fraction.denominator == 1)
//         printf("1");
//     else if (fraction.denominator == 1)
//         printf("%d", fraction.numerator);
//     else
//         printf("%d/%d", fraction.numerator, fraction.denominator);
// }

// Fraction sumFractions(Fraction fraction1, Fraction fraction2)
// {
//     Fraction res;
//     res.numerator = (fraction1.numerator * fraction2.denominator + fraction2.numerator * fraction1.denominator);
//     res.denominator = fraction1.denominator * fraction2.denominator;
//     return res;
// }

// Fraction subFractions(Fraction fraction1, Fraction fraction2)
// {
//     Fraction res;
//     res.numerator = (fraction1.numerator * fraction2.denominator - fraction2.numerator * fraction1.denominator);
//     res.denominator = fraction1.denominator * fraction2.denominator;
//     return res;
// }

// Fraction multiplyFractions(Fraction fraction1, Fraction fraction2)
// {
//     Fraction res;
//     res.numerator = (fraction1.numerator * fraction2.numerator);
//     res.denominator = fraction1.denominator * fraction2.denominator;
//     return res;
// }

// Fraction devideFractions(Fraction fraction1, Fraction fraction2)
// {
//     Fraction res;
//     res.numerator = (fraction1.numerator * fraction2.denominator);
//     res.denominator = fraction1.denominator * fraction2.numerator;
//     return res;
// }

// int Menu()
// {
//     int choice;
//     printf("\n=============MENU============\n");
//     printf("1. Nhap vao 2 phan so\n");
//     printf("2. Rut gon phan so\n");
//     printf("3. Tong 2 phan so.\n");
//     printf("4. Hieu 2 phan so.\n");
//     printf("5. Tich 2 phan so.\n");
//     printf("6. Thuong 2 phan so.\n");
//     printf("7. Thoat.\n");
//     scanf("%d", &choice);
//     return choice;
// }

// int main()
// {
//     Fraction fr1, fr2;

//     while (1)
//     {
//         int choice = Menu();
//         switch (choice)
//         {
//         case 1:
//             enterFraction(&fr1);
//             showFraction(fr1);
//             printf("\n");
//             enterFraction(&fr2);
//             showFraction(fr2);
//             break;
//         case 2:
//             showFraction(fr1);
//             printf("\n");
//             showFraction(fr2);
//             break;
//         case 3:
//             printf("Tong 2 phan so la: ");
//             showFraction(sumFractions(fr1, fr2));
//             break;
//         case 4:
//             printf("Hieu 2 phan so la: ");
//             showFraction(subFractions(fr1, fr2));
//             break;
//         case 5:
//             printf("Tich 2 phan so la: ");
//             showFraction(multiplyFractions(fr1, fr2));
//             break;
//         case 6:
//             printf("Thuong 2 phan so la: ");
//             showFraction(devideFractions(fr1, fr2));
//             break;
//         default:
//             return 0;
//         }
//     }
//     return 0;
// }

#include <stdio.h>
#include <math.h>

typedef struct PhanSo
{
    int tu;
    int mau;
} PhanSo;

PhanSo nhap()
{
    PhanSo ps;
    printf("Nhap tu so: ");
    scanf("%d", &ps.tu);
    do
    {
        printf("Nhap mau so (khac 0):");
        scanf("%d", &ps.mau);
    } while (ps.mau == 0);

    return ps;
}

PhanSo rutGonPhanSo(PhanSo ps)
{
    int a = abs(ps.tu), b = abs(ps.mau);
    int UCLN = 1;

    if (a == 0 || b == 0)
        UCLN = (a + b);
    else
    {
        while (a != b)
        {
            if (a > b)
                a = a - b;
            else
                b = b - a;
        }
        UCLN = a;
    }
    ps.tu /= UCLN;
    ps.mau /= UCLN;

    return ps;
}

PhanSo tong(PhanSo ps1, PhanSo ps2)
{
    PhanSo ps;
    ps.tu = ps1.tu * ps2.mau + ps1.mau * ps2.tu;
    ps.mau = ps1.mau * ps2.mau;
    return ps;
}
PhanSo hieu(PhanSo ps1, PhanSo ps2)
{
    PhanSo ps;
    ps.tu = ps1.tu * ps2.mau - ps1.mau * ps2.tu;
    ps.mau = ps1.mau * ps2.mau;
    return ps;
}
PhanSo tich(PhanSo ps1, PhanSo ps2)
{
    PhanSo ps;
    ps.tu = ps1.tu * ps2.tu;
    ps.mau = ps1.mau * ps2.mau;
    return ps;
}
PhanSo thuong(PhanSo ps1, PhanSo ps2)
{
    PhanSo ps;
    ps.tu = ps1.tu * ps2.mau;
    ps.mau = ps1.mau * ps2.tu;
    return ps;
}

void hienThi(PhanSo ps)
{
    printf("%d/%d", ps.tu, ps.mau);
}

int menu()
{
    int choice;
    printf("\n=============MENU============\n");
    printf("1. Nhap vao 2 phan so\n");
    printf("2. Rut gon phan so\n");
    printf("3. Tong 2 phan so.\n");
    printf("4. Hieu 2 phan so.\n");
    printf("5. Tich 2 phan so.\n");
    printf("6. Thuong 2 phan so.\n");
    printf("0. Thoat.\n");
    scanf("%d", &choice);
    return choice;
}

int main()
{
    while (1)
    {
        int choice = menu();
        PhanSo ps1, ps2, psTong, psHieu, psTich, psThuong;

        switch (choice)
        {
        case 1:
            printf("Nhap vao 2 phan so: \n");
            printf("Phan so thu nhat: ");
            ps1 = nhap();
            printf("\n");

            printf("Phan so thu hai: ");
            ps2 = nhap();
            printf("\n");

            hienThi(ps1);
            printf("\n");
            hienThi(ps2);
            break;
        case 2:
            ps1 = rutGonPhanSo(ps1);
            ps2 = rutGonPhanSo(ps2);
            hienThi(ps1);
            printf("\n");
            hienThi(ps2);
            break;
        case 3:
            psTong = tong(ps1, ps2);
            hienThi(psTong);
            break;
        case 4:
            psHieu = hieu(ps1, ps2);
            hienThi(psHieu);
            break;
        case 5:
            psTich = tich(ps1, ps2);
            hienThi(psTich);
            break;
        case 6:
            psThuong = thuong(ps1, ps2);
            hienThi(psThuong);
            break;
        default:
            return 0;
        }
    }

    return 0;
}