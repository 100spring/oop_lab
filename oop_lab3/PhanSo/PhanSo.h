#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

class PhanSo{
    protected:
        int tu, mau;
    public:
        PhanSo();
        PhanSo(int x, int y);
        ~PhanSo();
        void Nhap();
        void Xuat();
        int getTu();
        int getMau();
        PhanSo Cong(PhanSo a);
        void RutGon();
        bool SoSanhLonHon(PhanSo a);
};