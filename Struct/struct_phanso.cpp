#include <stdio.h>
#include <math.h>

struct PhanSo
{
    int tuSo;
    int mauSo;
};

void rutGonPhanSo(struct PhanSo *ps)
{
    int a = abs(ps->tuSo);
    int b = abs(ps->mauSo);

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
    ps->tuSo /= UCLN;
    ps->mauSo /= UCLN;
}

void nhapPhanSo(struct PhanSo *ps)
{
    printf("Nhap vao tu so: ");
    scanf("%d", &ps->tuSo);

    do
    {
        printf("Nhap vao mau so: ");
        scanf("%d", &ps->mauSo);
    } while (ps->mauSo == 0);
}

void inPhanSo(struct PhanSo ps)
{
    if (ps.mauSo < 0)
    {
        ps.tuSo *= (-1);
        ps.mauSo *= (-1);
    }
    rutGonPhanSo(&ps);
    if (ps.mauSo == 1)
        printf("%d", ps.tuSo);
    else
        printf("%d/%d", ps.tuSo, ps.mauSo);
}

PhanSo congHaiPhanSo(PhanSo ps1, PhanSo ps2)
{
    PhanSo ketQua;
    ketQua.tuSo = ps1.tuSo * ps2.mauSo + ps1.mauSo * ps2.tuSo;
    ketQua.mauSo = ps1.mauSo * ps2.mauSo;
    return ketQua;
}

PhanSo truHaiPhanSo(PhanSo ps1, PhanSo ps2)
{
    PhanSo ketQua;
    ketQua.tuSo = ps1.tuSo * ps2.mauSo - ps1.mauSo * ps2.tuSo;
    ketQua.mauSo = ps1.mauSo * ps2.mauSo;
    return ketQua;
}

PhanSo nhanHaiPhanSo(PhanSo ps1, PhanSo ps2)
{
    PhanSo ketQua;
    ketQua.tuSo = ps1.tuSo * ps2.tuSo;
    ketQua.mauSo = ps1.mauSo * ps2.mauSo;
    return ketQua;
}

PhanSo chiaHaiPhanSo(PhanSo ps1, PhanSo ps2)
{
    PhanSo ketQua;
    ketQua.tuSo = ps1.tuSo * ps2.mauSo;
    ketQua.mauSo = ps1.mauSo * ps2.tuSo;
    return ketQua;
}



int main()
{
    struct PhanSo ps1, ps2;
    printf("Nhap vao phan so thu nhat: \n");
    nhapPhanSo(&ps1);
    printf("Nhap vao phan so thu hai: \n");
    nhapPhanSo(&ps2);
    printf("Phep toan 2 phan so: \n");
    printf("Cong 2 phan so: ");
    inPhanSo(ps1);
    printf(" + ");
    inPhanSo(ps2);
    printf(" = ");
    inPhanSo(congHaiPhanSo(ps1, ps2));
    printf("\n");
    printf("Tru 2 phan so: ");
    inPhanSo(ps1);
    printf(" - ");
    inPhanSo(ps2);
    printf(" = ");
    inPhanSo(truHaiPhanSo(ps1, ps2));
    printf("\n");
    printf("Nhan 2 phan so: ");
    inPhanSo(ps1);
    printf(" * ");
    inPhanSo(ps2);
    printf(" = ");
    inPhanSo(nhanHaiPhanSo(ps1, ps2));
    printf("\n");
    printf("Chia 2 phan so: ");
    inPhanSo(ps1);
    printf(" : ");
    inPhanSo(ps2);
    printf(" = ");
    inPhanSo(chiaHaiPhanSo(ps1, ps2));
    return 0;
}