#include <iostream>
#include <string>
#include <cmath>
using namespace std;

class Diem{
    protected:
        double dx, dy;
    public:
        Diem();
        Diem(double x, double y);
        ~Diem();
        void Nhap();
        void Xuat();
        void TinhTien(double x, double y);
        double KhoangCach(Diem A);
        double xTrongTam(Diem a, Diem b, Diem c);
        double yTrongTam(Diem a, Diem b, Diem c);
        double getX();
        double getY();
};