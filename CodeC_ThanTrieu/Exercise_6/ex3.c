/*
Ex 6.3. Cho đa thức Pn(x) và Qm(x). Hãy:
a) Tạo struct đa thức.
b) Viết hàm nhập vào các hệ số và số mũ của đa thức, kết quả trả về đa thức.
c) Viết hàm tính giá trị Pn(𝑥0) và Qm(𝑥0) với 𝑥0 tùy ý nhập vào từ bàn phím.
d) Viết hàm tìm đạo hàm bậc 1 của đa thức. Kết quả trả về đa thức.
e) Tính tổng Pn(x) + Qm(x), kết quả trả về là đa thức.
f) Tính hiệu Pn(x) - Qm(x), kết quả trả về là đa thức.
g) Tính tích Pn(x) * Qm(x), kết quả trả về đa thức.
h) Tính thương Pn(x) / Qm(x) và đa thức dư còn lại.
i) Viết menu cho phép thực hiện tùy chọn các chức năng.
*/

#include <stdio.h>
#include <math.h>

typedef struct Polynomial
{
    int step;          /// Bac cua da thuc
    float arrPoly[40]; // He so cua moi bac
} Polynomial;

Polynomial enterPolynomial()
{
    Polynomial pln;
    printf("Enter step of polynomial: ");
    scanf("%d", &pln.step);
    for (int i = 0; i <= pln.step; i++)
    {
        printf("Factor of step %d is: ", i);
        scanf("%f", &pln.arrPoly[i]);
    }
    return pln;
}
void showPolynomial(Polynomial pln)
{
    for (int i = pln.step; i >= 0; i--)
    {
        printf("%.2f", pln.arrPoly[i]);
        if (i != 0)
            printf("x^%d + ", i);
    }
}

float calValPolynomialAtIndex(Polynomial pln, float index)
{
    float res = 0;
    for (int i = 0; i <= pln.step; i++)
    {
        res += pln.arrPoly[i] * pow(index, i);
    }
    return res;
}

Polynomial derivativeStepOnePoly(Polynomial pln)
{
    Polynomial DePln;

    DePln.step = pln.step - 1;

    for (int i = pln.step; i >= 1; i--)
    {
        DePln.arrPoly[i - 1] = pln.arrPoly[i] * i;
    }

    return DePln;
}

int max(int a, int b)
{
    return a > b ? a : b;
}

Polynomial sum2Poly(Polynomial pln1, Polynomial pln2)
{
    Polynomial pln;

    float arrPoly[100] = {0};

    pln.step = max(pln1.step, pln2.step);

    for (int i = 0; i <= pln.step; i++)
    {
        pln.arrPoly[i] = pln1.arrPoly[i] + pln2.arrPoly[i];
    }

    return pln;
}

Polynomial sub2Poly(Polynomial pln1, Polynomial pln2)
{
    Polynomial pln;

    float arrPoly[100] = {0};

    pln.step = max(pln1.step, pln2.step);

    for (int i = 0; i <= pln.step; i++)
    {
        pln.arrPoly[i] = pln1.arrPoly[i] - pln2.arrPoly[i];
    }

    return pln;
}

Polynomial mul2Poly(Polynomial pln1, Polynomial pln2)
{
    Polynomial pln;

    float arrPoly[100] = {0};

    pln.step = max(pln1.step, pln2.step);

    for (int i = 0; i <= pln.step; i++)
    {
        pln.arrPoly[i] = pln1.arrPoly[i] * pln2.arrPoly[i];
    }

    return pln;
}

Polynomial devide2Poly(Polynomial pln1, Polynomial pln2)
{
    Polynomial pln;

    float arrPoly[100] = {0};

    pln.step = max(pln1.step, pln2.step);

    for (int i = 0; i <= pln.step; i++)
    {
        pln.arrPoly[i] = pln1.arrPoly[i] / pln2.arrPoly[i];
    }

    return pln;
}

int menu()
{
    int choice;
    printf("============= MENU ============\n");
    printf("1. Nhap 2 da thuc. \n");
    printf("2. Tinh gia tri cua 2 da thuc tai vi tri x. \n");
    printf("3. Tinh dao ham cua 2 da thuc. \n");
    printf("4. Tinh tong 2 da thuc. \n");
    printf("5. Tinh hieu 2 da thuc. \n");
    printf("6. Tinh tich 2 da thuc. \n");
    printf("7. Tinh thuong 2 da thuc. \n");
    printf("0. Nhan phim bat ki de thoat. \n");
    printf("?");
    scanf("%d", &choice);

    return choice;
}

int main()
{
    Polynomial pln1, pln2, plnDe1, plnDe2, pln;

    while (1)
    {
        int choice = menu();

        switch (choice)
        {
        case 1:
            pln1 = enterPolynomial();
            showPolynomial(pln1);
            printf("\n");

            pln2 = enterPolynomial();
            showPolynomial(pln2);
            printf("\n");
            break;
        case 2:
            printf("\n");
            float index;
            printf("Enter index = ");
            scanf("%f", &index);
            printf("Value of Polynomial 1 at %.2f is: %2.f \n", index, calValPolynomialAtIndex(pln1, index));
            printf("Value of Polynomial 2 at %.2f is: %2.f \n", index, calValPolynomialAtIndex(pln2, index));
            break;
        case 3:
            plnDe1 = derivativeStepOnePoly(pln1);
            showPolynomial(plnDe1);
            printf("\n");

            plnDe2 = derivativeStepOnePoly(pln2);
            showPolynomial(plnDe2);
            printf("\n");
            break;
        case 4:
            pln = sum2Poly(pln1, pln2);
            showPolynomial(pln);
            printf("\n");
            break;
        case 5:
            pln = sub2Poly(pln1, pln2);
            showPolynomial(pln);
            printf("\n");
            break;
        case 6:
            pln = mul2Poly(pln1, pln2);
            showPolynomial(pln);
            printf("\n");
            break;
        case 7:
            pln = devide2Poly(pln1, pln2);
            showPolynomial(pln);
            printf("\n");
            break;
        default:
            return 0;
            break;
        }
    }

    return 0;
}