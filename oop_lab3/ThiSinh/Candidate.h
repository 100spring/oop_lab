#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Candidate{
    protected:
        string id, ten, ngaysinh;
        double diemToan, diemVan, diemAnh, diemTB;
    public:
        Candidate();
        ~Candidate();
        void Nhap();
        void Xuat();
        double getDiemTB();
};