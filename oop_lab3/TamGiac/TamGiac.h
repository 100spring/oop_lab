#include <string>
#include <algorithm>
#include <vector>
#include "Diem.cpp"
using namespace std;

class TamGiac : public Diem{
    protected:
        Diem A, B, C;
    public:
        TamGiac();
        TamGiac(Diem m, Diem n, Diem p);
        ~TamGiac();
        void Nhap();
        void Xuat();
        string KiemTraLoai();
        double ChuVi();
        double DienTich();
        void TinhTien();
        void PhongTo();
        void Quay();
};