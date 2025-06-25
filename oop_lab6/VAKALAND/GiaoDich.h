#pragma once
#include <iostream>
#include <string>
using namespace std;

class GiaoDich {
    protected:
        string maGD;
        string ngayGD;
        double donGia;
        double dienTich;
    public:
        virtual void Nhap();
        virtual void Xuat();
        virtual double TinhTien() = 0;
        string getNgayGD() {return ngayGD;}
};