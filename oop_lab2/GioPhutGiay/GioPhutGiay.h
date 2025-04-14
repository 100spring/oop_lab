#include <iostream>
using namespace std;

class gioPhutGiay{
    private:
        int iGio, iPhut, iGiay;
    public:
        void Nhap();
        void Xuat();
        gioPhutGiay TinhCongThemMotGiay();
        bool KiemTra();
};