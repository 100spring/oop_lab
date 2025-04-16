#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

class DonThuc{
    protected:
        int bac;
        double heso;
    public:
        DonThuc();
        DonThuc(int b, double h);
        ~DonThuc();
        void Nhap();
        void Xuat();
        int getBac();
        double getHeSo();
        void setBac(int b);
        void setHeSo(double h);
};
