#include <iostream>
using namespace std;

class phanSo{
    private:
        int iTu, iMau;
    public:
        void Nhap();
        void Xuat();
        phanSo Tong(phanSo a, phanSo b);
        phanSo Hieu(phanSo a, phanSo b);
        phanSo Tich(phanSo a, phanSo b);
        phanSo Thuong(phanSo a, phanSo b);
        void RutGon();
        void SoSanh(phanSo a);
};