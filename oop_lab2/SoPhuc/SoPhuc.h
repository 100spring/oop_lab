#include <iostream>
#include <cmath>
using namespace std;

class soPhuc{
    private:
        float iThuc, iAo;
    public:
        void Nhap();
        void Xuat();
        soPhuc Tong(soPhuc a, soPhuc b);
        soPhuc Hieu(soPhuc a, soPhuc b);
        soPhuc Tich(soPhuc a, soPhuc b);
        soPhuc Thuong(soPhuc a, soPhuc b);
};