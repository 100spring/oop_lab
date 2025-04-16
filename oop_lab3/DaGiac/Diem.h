#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

class Diem{
    protected:
        double dx, dy;
    public:
        Diem();
        Diem(double x, double y){dx = x, dy = y;}
        ~Diem();
        void Nhap();
        void Xuat();
        void TinhTien(double x, double y);
        double KhoangCach(Diem a);
        double getX();
        double getY();
};